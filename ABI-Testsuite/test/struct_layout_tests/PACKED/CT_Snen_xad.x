// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
// RUN: c_compiler -c -o %t1.o -I "common" "common/testsuite.c"
// RUN: c_compiler -c %s -I "common" -o %t2.o
// RUN: linker -o %t1%exeext  %t1.o %t2.o
// RUN: runtool %t1%exeext | checker "TEST PASSED"
#include "testsuite.h"
typedef struct empty {} empty;
#pragma pack(1)
struct Sf_BFu9ll_L { empty v1; unsigned long long v2:9; long long v3; };
struct Sf_BFu9ll_S { empty v1; unsigned long long v2:9; short v3; };
struct Sf_BFu9ll_Sf { empty v1; unsigned long long v2:9; empty v3; };
struct Sf_BFu9ll_Uc { empty v1; unsigned long long v2:9; unsigned char v3; };
struct Sf_BFu9ll_Ui { empty v1; unsigned long long v2:9; unsigned int v3; };
struct Sf_BFu9ll_Ul { empty v1; unsigned long long v2:9; unsigned long long v3; };
struct Sf_BFu9ll_Us { empty v1; unsigned long long v2:9; unsigned short v3; };
struct Sf_BFu9ll_Vp { empty v1; unsigned long long v2:9; void * v3; };
struct Sf_BFu9s { empty v1; unsigned short v2:9; };
struct Sf_BFu9s_BFu15i { empty v1; unsigned short v2:9; unsigned int v3:15; };
struct Sf_BFu9s_BFu15ll { empty v1; unsigned short v2:9; unsigned long long v3:15; };
struct Sf_BFu9s_BFu15s { empty v1; unsigned short v2:9; unsigned short v3:15; };
struct Sf_BFu9s_BFu16i { empty v1; unsigned short v2:9; unsigned int v3:16; };
struct Sf_BFu9s_BFu16ll { empty v1; unsigned short v2:9; unsigned long long v3:16; };
struct Sf_BFu9s_BFu16s { empty v1; unsigned short v2:9; unsigned short v3:16; };
struct Sf_BFu9s_BFu17i { empty v1; unsigned short v2:9; unsigned int v3:17; };
struct Sf_BFu9s_BFu17ll { empty v1; unsigned short v2:9; unsigned long long v3:17; };
struct Sf_BFu9s_BFu1c { empty v1; unsigned short v2:9; unsigned char v3:1; };
struct Sf_BFu9s_BFu1i { empty v1; unsigned short v2:9; unsigned int v3:1; };
struct Sf_BFu9s_BFu1ll { empty v1; unsigned short v2:9; unsigned long long v3:1; };
struct Sf_BFu9s_BFu1s { empty v1; unsigned short v2:9; unsigned short v3:1; };
struct Sf_BFu9s_BFu31i { empty v1; unsigned short v2:9; unsigned int v3:31; };
struct Sf_BFu9s_BFu31ll { empty v1; unsigned short v2:9; unsigned long long v3:31; };
struct Sf_BFu9s_BFu32i { empty v1; unsigned short v2:9; unsigned int v3:32; };
struct Sf_BFu9s_BFu32ll { empty v1; unsigned short v2:9; unsigned long long v3:32; };
struct Sf_BFu9s_BFu33 { empty v1; unsigned short v2:9; unsigned long long v3:33; };
struct Sf_BFu9s_BFu7c { empty v1; unsigned short v2:9; unsigned char v3:7; };
struct Sf_BFu9s_BFu7i { empty v1; unsigned short v2:9; unsigned int v3:7; };
struct Sf_BFu9s_BFu7ll { empty v1; unsigned short v2:9; unsigned long long v3:7; };
struct Sf_BFu9s_BFu7s { empty v1; unsigned short v2:9; unsigned short v3:7; };
struct Sf_BFu9s_BFu8c { empty v1; unsigned short v2:9; unsigned char v3:8; };
struct Sf_BFu9s_BFu8i { empty v1; unsigned short v2:9; unsigned int v3:8; };
struct Sf_BFu9s_BFu8ll { empty v1; unsigned short v2:9; unsigned long long v3:8; };
struct Sf_BFu9s_BFu8s { empty v1; unsigned short v2:9; unsigned short v3:8; };
struct Sf_BFu9s_BFu9i { empty v1; unsigned short v2:9; unsigned int v3:9; };
struct Sf_BFu9s_BFu9ll { empty v1; unsigned short v2:9; unsigned long long v3:9; };
struct Sf_BFu9s_BFu9s { empty v1; unsigned short v2:9; unsigned short v3:9; };
struct Sf_BFu9s_C { empty v1; unsigned short v2:9; char v3; };
struct Sf_BFu9s_D { empty v1; unsigned short v2:9; double v3; };
struct Sf_BFu9s_F { empty v1; unsigned short v2:9; float v3; };
struct Sf_BFu9s_I { empty v1; unsigned short v2:9; int v3; };
struct Sf_BFu9s_Ip { empty v1; unsigned short v2:9; int * v3; };
struct Sf_BFu9s_L { empty v1; unsigned short v2:9; long long v3; };
struct Sf_BFu9s_S { empty v1; unsigned short v2:9; short v3; };
struct Sf_BFu9s_Sf { empty v1; unsigned short v2:9; empty v3; };
struct Sf_BFu9s_Uc { empty v1; unsigned short v2:9; unsigned char v3; };
struct Sf_BFu9s_Ui { empty v1; unsigned short v2:9; unsigned int v3; };
struct Sf_BFu9s_Ul { empty v1; unsigned short v2:9; unsigned long long v3; };
struct Sf_BFu9s_Us { empty v1; unsigned short v2:9; unsigned short v3; };
struct Sf_BFu9s_Vp { empty v1; unsigned short v2:9; void * v3; };
struct Sf_C { empty v1; char v2; };
struct Sf_C_BFu15i { empty v1; char v2; unsigned int v3:15; };
struct Sf_C_BFu15ll { empty v1; char v2; unsigned long long v3:15; };
struct Sf_C_BFu15s { empty v1; char v2; unsigned short v3:15; };
struct Sf_C_BFu16i { empty v1; char v2; unsigned int v3:16; };
struct Sf_C_BFu16ll { empty v1; char v2; unsigned long long v3:16; };
struct Sf_C_BFu16s { empty v1; char v2; unsigned short v3:16; };
struct Sf_C_BFu17i { empty v1; char v2; unsigned int v3:17; };
struct Sf_C_BFu17ll { empty v1; char v2; unsigned long long v3:17; };
struct Sf_C_BFu1c { empty v1; char v2; unsigned char v3:1; };
struct Sf_C_BFu1i { empty v1; char v2; unsigned int v3:1; };
struct Sf_C_BFu1ll { empty v1; char v2; unsigned long long v3:1; };
struct Sf_C_BFu1s { empty v1; char v2; unsigned short v3:1; };
struct Sf_C_BFu31i { empty v1; char v2; unsigned int v3:31; };
struct Sf_C_BFu31ll { empty v1; char v2; unsigned long long v3:31; };
struct Sf_C_BFu32i { empty v1; char v2; unsigned int v3:32; };
struct Sf_C_BFu32ll { empty v1; char v2; unsigned long long v3:32; };
struct Sf_C_BFu33 { empty v1; char v2; unsigned long long v3:33; };
struct Sf_C_BFu7c { empty v1; char v2; unsigned char v3:7; };
struct Sf_C_BFu7i { empty v1; char v2; unsigned int v3:7; };
struct Sf_C_BFu7ll { empty v1; char v2; unsigned long long v3:7; };
struct Sf_C_BFu7s { empty v1; char v2; unsigned short v3:7; };
struct Sf_C_BFu8c { empty v1; char v2; unsigned char v3:8; };
struct Sf_C_BFu8i { empty v1; char v2; unsigned int v3:8; };
struct Sf_C_BFu8ll { empty v1; char v2; unsigned long long v3:8; };
struct Sf_C_BFu8s { empty v1; char v2; unsigned short v3:8; };
struct Sf_C_BFu9i { empty v1; char v2; unsigned int v3:9; };
struct Sf_C_BFu9ll { empty v1; char v2; unsigned long long v3:9; };
struct Sf_C_BFu9s { empty v1; char v2; unsigned short v3:9; };
struct Sf_C_C { empty v1; char v2; char v3; };
struct Sf_C_D { empty v1; char v2; double v3; };
struct Sf_C_F { empty v1; char v2; float v3; };
struct Sf_C_I { empty v1; char v2; int v3; };
struct Sf_C_Ip { empty v1; char v2; int * v3; };
struct Sf_C_L { empty v1; char v2; long long v3; };
struct Sf_C_S { empty v1; char v2; short v3; };
struct Sf_C_Sf { empty v1; char v2; empty v3; };
struct Sf_C_Uc { empty v1; char v2; unsigned char v3; };
struct Sf_C_Ui { empty v1; char v2; unsigned int v3; };
struct Sf_C_Ul { empty v1; char v2; unsigned long long v3; };
struct Sf_C_Us { empty v1; char v2; unsigned short v3; };
struct Sf_C_Vp { empty v1; char v2; void * v3; };
struct Sf_D { empty v1; double v2; };
struct Sf_D_BFu15i { empty v1; double v2; unsigned int v3:15; };
struct Sf_D_BFu15ll { empty v1; double v2; unsigned long long v3:15; };
struct Sf_D_BFu15s { empty v1; double v2; unsigned short v3:15; };
struct Sf_D_BFu16i { empty v1; double v2; unsigned int v3:16; };
struct Sf_D_BFu16ll { empty v1; double v2; unsigned long long v3:16; };
struct Sf_D_BFu16s { empty v1; double v2; unsigned short v3:16; };
struct Sf_D_BFu17i { empty v1; double v2; unsigned int v3:17; };
struct Sf_D_BFu17ll { empty v1; double v2; unsigned long long v3:17; };
struct Sf_D_BFu1c { empty v1; double v2; unsigned char v3:1; };
struct Sf_D_BFu1i { empty v1; double v2; unsigned int v3:1; };
struct Sf_D_BFu1ll { empty v1; double v2; unsigned long long v3:1; };
struct Sf_D_BFu1s { empty v1; double v2; unsigned short v3:1; };
struct Sf_D_BFu31i { empty v1; double v2; unsigned int v3:31; };
struct Sf_D_BFu31ll { empty v1; double v2; unsigned long long v3:31; };
struct Sf_D_BFu32i { empty v1; double v2; unsigned int v3:32; };
struct Sf_D_BFu32ll { empty v1; double v2; unsigned long long v3:32; };
struct Sf_D_BFu33 { empty v1; double v2; unsigned long long v3:33; };
struct Sf_D_BFu7c { empty v1; double v2; unsigned char v3:7; };
struct Sf_D_BFu7i { empty v1; double v2; unsigned int v3:7; };
struct Sf_D_BFu7ll { empty v1; double v2; unsigned long long v3:7; };
struct Sf_D_BFu7s { empty v1; double v2; unsigned short v3:7; };
struct Sf_D_BFu8c { empty v1; double v2; unsigned char v3:8; };
struct Sf_D_BFu8i { empty v1; double v2; unsigned int v3:8; };
struct Sf_D_BFu8ll { empty v1; double v2; unsigned long long v3:8; };
struct Sf_D_BFu8s { empty v1; double v2; unsigned short v3:8; };
struct Sf_D_BFu9i { empty v1; double v2; unsigned int v3:9; };
struct Sf_D_BFu9ll { empty v1; double v2; unsigned long long v3:9; };
struct Sf_D_BFu9s { empty v1; double v2; unsigned short v3:9; };
struct Sf_D_C { empty v1; double v2; char v3; };
struct Sf_D_D { empty v1; double v2; double v3; };
struct Sf_D_F { empty v1; double v2; float v3; };
struct Sf_D_I { empty v1; double v2; int v3; };
struct Sf_D_Ip { empty v1; double v2; int * v3; };
struct Sf_D_L { empty v1; double v2; long long v3; };
struct Sf_D_S { empty v1; double v2; short v3; };
struct Sf_D_Sf { empty v1; double v2; empty v3; };
struct Sf_D_Uc { empty v1; double v2; unsigned char v3; };
struct Sf_D_Ui { empty v1; double v2; unsigned int v3; };
struct Sf_D_Ul { empty v1; double v2; unsigned long long v3; };
struct Sf_D_Us { empty v1; double v2; unsigned short v3; };
struct Sf_D_Vp { empty v1; double v2; void * v3; };
struct Sf_F { empty v1; float v2; };
struct Sf_F_BFu15i { empty v1; float v2; unsigned int v3:15; };
struct Sf_F_BFu15ll { empty v1; float v2; unsigned long long v3:15; };
struct Sf_F_BFu15s { empty v1; float v2; unsigned short v3:15; };
struct Sf_F_BFu16i { empty v1; float v2; unsigned int v3:16; };
struct Sf_F_BFu16ll { empty v1; float v2; unsigned long long v3:16; };
struct Sf_F_BFu16s { empty v1; float v2; unsigned short v3:16; };
struct Sf_F_BFu17i { empty v1; float v2; unsigned int v3:17; };
struct Sf_F_BFu17ll { empty v1; float v2; unsigned long long v3:17; };
struct Sf_F_BFu1c { empty v1; float v2; unsigned char v3:1; };
struct Sf_F_BFu1i { empty v1; float v2; unsigned int v3:1; };
struct Sf_F_BFu1ll { empty v1; float v2; unsigned long long v3:1; };
struct Sf_F_BFu1s { empty v1; float v2; unsigned short v3:1; };
struct Sf_F_BFu31i { empty v1; float v2; unsigned int v3:31; };
struct Sf_F_BFu31ll { empty v1; float v2; unsigned long long v3:31; };
struct Sf_F_BFu32i { empty v1; float v2; unsigned int v3:32; };
struct Sf_F_BFu32ll { empty v1; float v2; unsigned long long v3:32; };
struct Sf_F_BFu33 { empty v1; float v2; unsigned long long v3:33; };
struct Sf_F_BFu7c { empty v1; float v2; unsigned char v3:7; };
struct Sf_F_BFu7i { empty v1; float v2; unsigned int v3:7; };
struct Sf_F_BFu7ll { empty v1; float v2; unsigned long long v3:7; };
struct Sf_F_BFu7s { empty v1; float v2; unsigned short v3:7; };
struct Sf_F_BFu8c { empty v1; float v2; unsigned char v3:8; };
struct Sf_F_BFu8i { empty v1; float v2; unsigned int v3:8; };
struct Sf_F_BFu8ll { empty v1; float v2; unsigned long long v3:8; };
struct Sf_F_BFu8s { empty v1; float v2; unsigned short v3:8; };
struct Sf_F_BFu9i { empty v1; float v2; unsigned int v3:9; };
struct Sf_F_BFu9ll { empty v1; float v2; unsigned long long v3:9; };
struct Sf_F_BFu9s { empty v1; float v2; unsigned short v3:9; };
struct Sf_F_C { empty v1; float v2; char v3; };
struct Sf_F_D { empty v1; float v2; double v3; };
struct Sf_F_F { empty v1; float v2; float v3; };
struct Sf_F_I { empty v1; float v2; int v3; };
struct Sf_F_Ip { empty v1; float v2; int * v3; };
struct Sf_F_L { empty v1; float v2; long long v3; };
struct Sf_F_S { empty v1; float v2; short v3; };
struct Sf_F_Sf { empty v1; float v2; empty v3; };
struct Sf_F_Uc { empty v1; float v2; unsigned char v3; };
struct Sf_F_Ui { empty v1; float v2; unsigned int v3; };
struct Sf_F_Ul { empty v1; float v2; unsigned long long v3; };
struct Sf_F_Us { empty v1; float v2; unsigned short v3; };
struct Sf_F_Vp { empty v1; float v2; void * v3; };
struct Sf_I { empty v1; int v2; };
struct Sf_I_BFu15i { empty v1; int v2; unsigned int v3:15; };
struct Sf_I_BFu15ll { empty v1; int v2; unsigned long long v3:15; };
struct Sf_I_BFu15s { empty v1; int v2; unsigned short v3:15; };
struct Sf_I_BFu16i { empty v1; int v2; unsigned int v3:16; };
struct Sf_I_BFu16ll { empty v1; int v2; unsigned long long v3:16; };
struct Sf_I_BFu16s { empty v1; int v2; unsigned short v3:16; };
struct Sf_I_BFu17i { empty v1; int v2; unsigned int v3:17; };
struct Sf_I_BFu17ll { empty v1; int v2; unsigned long long v3:17; };
struct Sf_I_BFu1c { empty v1; int v2; unsigned char v3:1; };
struct Sf_I_BFu1i { empty v1; int v2; unsigned int v3:1; };
struct Sf_I_BFu1ll { empty v1; int v2; unsigned long long v3:1; };
struct Sf_I_BFu1s { empty v1; int v2; unsigned short v3:1; };
struct Sf_I_BFu31i { empty v1; int v2; unsigned int v3:31; };
struct Sf_I_BFu31ll { empty v1; int v2; unsigned long long v3:31; };
struct Sf_I_BFu32i { empty v1; int v2; unsigned int v3:32; };
struct Sf_I_BFu32ll { empty v1; int v2; unsigned long long v3:32; };
struct Sf_I_BFu33 { empty v1; int v2; unsigned long long v3:33; };
struct Sf_I_BFu7c { empty v1; int v2; unsigned char v3:7; };
struct Sf_I_BFu7i { empty v1; int v2; unsigned int v3:7; };
struct Sf_I_BFu7ll { empty v1; int v2; unsigned long long v3:7; };
struct Sf_I_BFu7s { empty v1; int v2; unsigned short v3:7; };
struct Sf_I_BFu8c { empty v1; int v2; unsigned char v3:8; };
struct Sf_I_BFu8i { empty v1; int v2; unsigned int v3:8; };
struct Sf_I_BFu8ll { empty v1; int v2; unsigned long long v3:8; };
struct Sf_I_BFu8s { empty v1; int v2; unsigned short v3:8; };
struct Sf_I_BFu9i { empty v1; int v2; unsigned int v3:9; };
struct Sf_I_BFu9ll { empty v1; int v2; unsigned long long v3:9; };
struct Sf_I_BFu9s { empty v1; int v2; unsigned short v3:9; };
struct Sf_I_C { empty v1; int v2; char v3; };
struct Sf_I_D { empty v1; int v2; double v3; };
struct Sf_I_F { empty v1; int v2; float v3; };
struct Sf_I_I { empty v1; int v2; int v3; };
struct Sf_I_Ip { empty v1; int v2; int * v3; };
struct Sf_I_L { empty v1; int v2; long long v3; };
struct Sf_I_S { empty v1; int v2; short v3; };
struct Sf_I_Sf { empty v1; int v2; empty v3; };
struct Sf_I_Uc { empty v1; int v2; unsigned char v3; };
struct Sf_I_Ui { empty v1; int v2; unsigned int v3; };
struct Sf_I_Ul { empty v1; int v2; unsigned long long v3; };
struct Sf_I_Us { empty v1; int v2; unsigned short v3; };
struct Sf_I_Vp { empty v1; int v2; void * v3; };
struct Sf_Ip { empty v1; int * v2; };
struct Sf_Ip_BFu15i { empty v1; int * v2; unsigned int v3:15; };
struct Sf_Ip_BFu15ll { empty v1; int * v2; unsigned long long v3:15; };
struct Sf_Ip_BFu15s { empty v1; int * v2; unsigned short v3:15; };
struct Sf_Ip_BFu16i { empty v1; int * v2; unsigned int v3:16; };
struct Sf_Ip_BFu16ll { empty v1; int * v2; unsigned long long v3:16; };
struct Sf_Ip_BFu16s { empty v1; int * v2; unsigned short v3:16; };
struct Sf_Ip_BFu17i { empty v1; int * v2; unsigned int v3:17; };
struct Sf_Ip_BFu17ll { empty v1; int * v2; unsigned long long v3:17; };
struct Sf_Ip_BFu1c { empty v1; int * v2; unsigned char v3:1; };
struct Sf_Ip_BFu1i { empty v1; int * v2; unsigned int v3:1; };
struct Sf_Ip_BFu1ll { empty v1; int * v2; unsigned long long v3:1; };
struct Sf_Ip_BFu1s { empty v1; int * v2; unsigned short v3:1; };
struct Sf_Ip_BFu31i { empty v1; int * v2; unsigned int v3:31; };
struct Sf_Ip_BFu31ll { empty v1; int * v2; unsigned long long v3:31; };
struct Sf_Ip_BFu32i { empty v1; int * v2; unsigned int v3:32; };
struct Sf_Ip_BFu32ll { empty v1; int * v2; unsigned long long v3:32; };
struct Sf_Ip_BFu33 { empty v1; int * v2; unsigned long long v3:33; };
struct Sf_Ip_BFu7c { empty v1; int * v2; unsigned char v3:7; };
struct Sf_Ip_BFu7i { empty v1; int * v2; unsigned int v3:7; };
struct Sf_Ip_BFu7ll { empty v1; int * v2; unsigned long long v3:7; };
struct Sf_Ip_BFu7s { empty v1; int * v2; unsigned short v3:7; };
struct Sf_Ip_BFu8c { empty v1; int * v2; unsigned char v3:8; };
struct Sf_Ip_BFu8i { empty v1; int * v2; unsigned int v3:8; };
struct Sf_Ip_BFu8ll { empty v1; int * v2; unsigned long long v3:8; };
struct Sf_Ip_BFu8s { empty v1; int * v2; unsigned short v3:8; };
struct Sf_Ip_BFu9i { empty v1; int * v2; unsigned int v3:9; };
struct Sf_Ip_BFu9ll { empty v1; int * v2; unsigned long long v3:9; };
struct Sf_Ip_BFu9s { empty v1; int * v2; unsigned short v3:9; };
struct Sf_Ip_C { empty v1; int * v2; char v3; };
struct Sf_Ip_D { empty v1; int * v2; double v3; };
struct Sf_Ip_F { empty v1; int * v2; float v3; };
struct Sf_Ip_I { empty v1; int * v2; int v3; };
struct Sf_Ip_Ip { empty v1; int * v2; int * v3; };
struct Sf_Ip_L { empty v1; int * v2; long long v3; };
struct Sf_Ip_S { empty v1; int * v2; short v3; };
struct Sf_Ip_Sf { empty v1; int * v2; empty v3; };
struct Sf_Ip_Uc { empty v1; int * v2; unsigned char v3; };
struct Sf_Ip_Ui { empty v1; int * v2; unsigned int v3; };
struct Sf_Ip_Ul { empty v1; int * v2; unsigned long long v3; };
struct Sf_Ip_Us { empty v1; int * v2; unsigned short v3; };
struct Sf_Ip_Vp { empty v1; int * v2; void * v3; };
struct Sf_L { empty v1; long long v2; };
struct Sf_L_BFu15i { empty v1; long long v2; unsigned int v3:15; };
struct Sf_L_BFu15ll { empty v1; long long v2; unsigned long long v3:15; };
struct Sf_L_BFu15s { empty v1; long long v2; unsigned short v3:15; };
struct Sf_L_BFu16i { empty v1; long long v2; unsigned int v3:16; };
struct Sf_L_BFu16ll { empty v1; long long v2; unsigned long long v3:16; };
struct Sf_L_BFu16s { empty v1; long long v2; unsigned short v3:16; };
struct Sf_L_BFu17i { empty v1; long long v2; unsigned int v3:17; };
struct Sf_L_BFu17ll { empty v1; long long v2; unsigned long long v3:17; };
struct Sf_L_BFu1c { empty v1; long long v2; unsigned char v3:1; };
struct Sf_L_BFu1i { empty v1; long long v2; unsigned int v3:1; };
struct Sf_L_BFu1ll { empty v1; long long v2; unsigned long long v3:1; };
struct Sf_L_BFu1s { empty v1; long long v2; unsigned short v3:1; };
struct Sf_L_BFu31i { empty v1; long long v2; unsigned int v3:31; };
struct Sf_L_BFu31ll { empty v1; long long v2; unsigned long long v3:31; };
struct Sf_L_BFu32i { empty v1; long long v2; unsigned int v3:32; };
struct Sf_L_BFu32ll { empty v1; long long v2; unsigned long long v3:32; };
struct Sf_L_BFu33 { empty v1; long long v2; unsigned long long v3:33; };
struct Sf_L_BFu7c { empty v1; long long v2; unsigned char v3:7; };
struct Sf_L_BFu7i { empty v1; long long v2; unsigned int v3:7; };
struct Sf_L_BFu7ll { empty v1; long long v2; unsigned long long v3:7; };
struct Sf_L_BFu7s { empty v1; long long v2; unsigned short v3:7; };
struct Sf_L_BFu8c { empty v1; long long v2; unsigned char v3:8; };
struct Sf_L_BFu8i { empty v1; long long v2; unsigned int v3:8; };
struct Sf_L_BFu8ll { empty v1; long long v2; unsigned long long v3:8; };
struct Sf_L_BFu8s { empty v1; long long v2; unsigned short v3:8; };
struct Sf_L_BFu9i { empty v1; long long v2; unsigned int v3:9; };
struct Sf_L_BFu9ll { empty v1; long long v2; unsigned long long v3:9; };
struct Sf_L_BFu9s { empty v1; long long v2; unsigned short v3:9; };
struct Sf_L_C { empty v1; long long v2; char v3; };
struct Sf_L_D { empty v1; long long v2; double v3; };
struct Sf_L_F { empty v1; long long v2; float v3; };
struct Sf_L_I { empty v1; long long v2; int v3; };
struct Sf_L_Ip { empty v1; long long v2; int * v3; };
struct Sf_L_L { empty v1; long long v2; long long v3; };
struct Sf_L_S { empty v1; long long v2; short v3; };
struct Sf_L_Sf { empty v1; long long v2; empty v3; };
struct Sf_L_Uc { empty v1; long long v2; unsigned char v3; };
struct Sf_L_Ui { empty v1; long long v2; unsigned int v3; };
struct Sf_L_Ul { empty v1; long long v2; unsigned long long v3; };
struct Sf_L_Us { empty v1; long long v2; unsigned short v3; };
struct Sf_L_Vp { empty v1; long long v2; void * v3; };
struct Sf_S { empty v1; short v2; };
struct Sf_S_BFu15i { empty v1; short v2; unsigned int v3:15; };
struct Sf_S_BFu15ll { empty v1; short v2; unsigned long long v3:15; };
struct Sf_S_BFu15s { empty v1; short v2; unsigned short v3:15; };
struct Sf_S_BFu16i { empty v1; short v2; unsigned int v3:16; };
struct Sf_S_BFu16ll { empty v1; short v2; unsigned long long v3:16; };
struct Sf_S_BFu16s { empty v1; short v2; unsigned short v3:16; };
struct Sf_S_BFu17i { empty v1; short v2; unsigned int v3:17; };
struct Sf_S_BFu17ll { empty v1; short v2; unsigned long long v3:17; };
struct Sf_S_BFu1c { empty v1; short v2; unsigned char v3:1; };
struct Sf_S_BFu1i { empty v1; short v2; unsigned int v3:1; };
struct Sf_S_BFu1ll { empty v1; short v2; unsigned long long v3:1; };
struct Sf_S_BFu1s { empty v1; short v2; unsigned short v3:1; };
struct Sf_S_BFu31i { empty v1; short v2; unsigned int v3:31; };
struct Sf_S_BFu31ll { empty v1; short v2; unsigned long long v3:31; };
struct Sf_S_BFu32i { empty v1; short v2; unsigned int v3:32; };
struct Sf_S_BFu32ll { empty v1; short v2; unsigned long long v3:32; };
struct Sf_S_BFu33 { empty v1; short v2; unsigned long long v3:33; };
struct Sf_S_BFu7c { empty v1; short v2; unsigned char v3:7; };
struct Sf_S_BFu7i { empty v1; short v2; unsigned int v3:7; };
struct Sf_S_BFu7ll { empty v1; short v2; unsigned long long v3:7; };
struct Sf_S_BFu7s { empty v1; short v2; unsigned short v3:7; };
struct Sf_S_BFu8c { empty v1; short v2; unsigned char v3:8; };
struct Sf_S_BFu8i { empty v1; short v2; unsigned int v3:8; };
struct Sf_S_BFu8ll { empty v1; short v2; unsigned long long v3:8; };
struct Sf_S_BFu8s { empty v1; short v2; unsigned short v3:8; };
struct Sf_S_BFu9i { empty v1; short v2; unsigned int v3:9; };
struct Sf_S_BFu9ll { empty v1; short v2; unsigned long long v3:9; };
struct Sf_S_BFu9s { empty v1; short v2; unsigned short v3:9; };
struct Sf_S_C { empty v1; short v2; char v3; };
struct Sf_S_D { empty v1; short v2; double v3; };
struct Sf_S_F { empty v1; short v2; float v3; };
struct Sf_S_I { empty v1; short v2; int v3; };
struct Sf_S_Ip { empty v1; short v2; int * v3; };
struct Sf_S_L { empty v1; short v2; long long v3; };
struct Sf_S_S { empty v1; short v2; short v3; };
struct Sf_S_Sf { empty v1; short v2; empty v3; };
struct Sf_S_Uc { empty v1; short v2; unsigned char v3; };
struct Sf_S_Ui { empty v1; short v2; unsigned int v3; };
struct Sf_S_Ul { empty v1; short v2; unsigned long long v3; };
struct Sf_S_Us { empty v1; short v2; unsigned short v3; };
struct Sf_S_Vp { empty v1; short v2; void * v3; };
struct Sf_Sf { empty v1; empty v2; };
struct Sf_Sf_BFu15i { empty v1; empty v2; unsigned int v3:15; };
struct Sf_Sf_BFu15ll { empty v1; empty v2; unsigned long long v3:15; };
struct Sf_Sf_BFu15s { empty v1; empty v2; unsigned short v3:15; };
struct Sf_Sf_BFu16i { empty v1; empty v2; unsigned int v3:16; };
struct Sf_Sf_BFu16ll { empty v1; empty v2; unsigned long long v3:16; };
struct Sf_Sf_BFu16s { empty v1; empty v2; unsigned short v3:16; };
struct Sf_Sf_BFu17i { empty v1; empty v2; unsigned int v3:17; };
struct Sf_Sf_BFu17ll { empty v1; empty v2; unsigned long long v3:17; };
struct Sf_Sf_BFu1c { empty v1; empty v2; unsigned char v3:1; };
struct Sf_Sf_BFu1i { empty v1; empty v2; unsigned int v3:1; };
struct Sf_Sf_BFu1ll { empty v1; empty v2; unsigned long long v3:1; };
struct Sf_Sf_BFu1s { empty v1; empty v2; unsigned short v3:1; };
struct Sf_Sf_BFu31i { empty v1; empty v2; unsigned int v3:31; };
struct Sf_Sf_BFu31ll { empty v1; empty v2; unsigned long long v3:31; };
struct Sf_Sf_BFu32i { empty v1; empty v2; unsigned int v3:32; };
struct Sf_Sf_BFu32ll { empty v1; empty v2; unsigned long long v3:32; };
struct Sf_Sf_BFu33 { empty v1; empty v2; unsigned long long v3:33; };
struct Sf_Sf_BFu7c { empty v1; empty v2; unsigned char v3:7; };
struct Sf_Sf_BFu7i { empty v1; empty v2; unsigned int v3:7; };
struct Sf_Sf_BFu7ll { empty v1; empty v2; unsigned long long v3:7; };
struct Sf_Sf_BFu7s { empty v1; empty v2; unsigned short v3:7; };
struct Sf_Sf_BFu8c { empty v1; empty v2; unsigned char v3:8; };
struct Sf_Sf_BFu8i { empty v1; empty v2; unsigned int v3:8; };
struct Sf_Sf_BFu8ll { empty v1; empty v2; unsigned long long v3:8; };
struct Sf_Sf_BFu8s { empty v1; empty v2; unsigned short v3:8; };
struct Sf_Sf_BFu9i { empty v1; empty v2; unsigned int v3:9; };
struct Sf_Sf_BFu9ll { empty v1; empty v2; unsigned long long v3:9; };
struct Sf_Sf_BFu9s { empty v1; empty v2; unsigned short v3:9; };
struct Sf_Sf_C { empty v1; empty v2; char v3; };
struct Sf_Sf_D { empty v1; empty v2; double v3; };
struct Sf_Sf_F { empty v1; empty v2; float v3; };
struct Sf_Sf_I { empty v1; empty v2; int v3; };
struct Sf_Sf_Ip { empty v1; empty v2; int * v3; };
struct Sf_Sf_L { empty v1; empty v2; long long v3; };
struct Sf_Sf_S { empty v1; empty v2; short v3; };
struct Sf_Sf_Sf { empty v1; empty v2; empty v3; };
struct Sf_Sf_Uc { empty v1; empty v2; unsigned char v3; };
struct Sf_Sf_Ui { empty v1; empty v2; unsigned int v3; };
struct Sf_Sf_Ul { empty v1; empty v2; unsigned long long v3; };
struct Sf_Sf_Us { empty v1; empty v2; unsigned short v3; };
struct Sf_Sf_Vp { empty v1; empty v2; void * v3; };
struct Sf_Uc { empty v1; unsigned char v2; };
struct Sf_Uc_BFu15i { empty v1; unsigned char v2; unsigned int v3:15; };
struct Sf_Uc_BFu15ll { empty v1; unsigned char v2; unsigned long long v3:15; };
struct Sf_Uc_BFu15s { empty v1; unsigned char v2; unsigned short v3:15; };
struct Sf_Uc_BFu16i { empty v1; unsigned char v2; unsigned int v3:16; };
struct Sf_Uc_BFu16ll { empty v1; unsigned char v2; unsigned long long v3:16; };
struct Sf_Uc_BFu16s { empty v1; unsigned char v2; unsigned short v3:16; };
struct Sf_Uc_BFu17i { empty v1; unsigned char v2; unsigned int v3:17; };
struct Sf_Uc_BFu17ll { empty v1; unsigned char v2; unsigned long long v3:17; };
struct Sf_Uc_BFu1c { empty v1; unsigned char v2; unsigned char v3:1; };
struct Sf_Uc_BFu1i { empty v1; unsigned char v2; unsigned int v3:1; };
struct Sf_Uc_BFu1ll { empty v1; unsigned char v2; unsigned long long v3:1; };
struct Sf_Uc_BFu1s { empty v1; unsigned char v2; unsigned short v3:1; };
struct Sf_Uc_BFu31i { empty v1; unsigned char v2; unsigned int v3:31; };
struct Sf_Uc_BFu31ll { empty v1; unsigned char v2; unsigned long long v3:31; };
struct Sf_Uc_BFu32i { empty v1; unsigned char v2; unsigned int v3:32; };
struct Sf_Uc_BFu32ll { empty v1; unsigned char v2; unsigned long long v3:32; };
struct Sf_Uc_BFu33 { empty v1; unsigned char v2; unsigned long long v3:33; };
struct Sf_Uc_BFu7c { empty v1; unsigned char v2; unsigned char v3:7; };
struct Sf_Uc_BFu7i { empty v1; unsigned char v2; unsigned int v3:7; };
struct Sf_Uc_BFu7ll { empty v1; unsigned char v2; unsigned long long v3:7; };
struct Sf_Uc_BFu7s { empty v1; unsigned char v2; unsigned short v3:7; };
struct Sf_Uc_BFu8c { empty v1; unsigned char v2; unsigned char v3:8; };
struct Sf_Uc_BFu8i { empty v1; unsigned char v2; unsigned int v3:8; };
struct Sf_Uc_BFu8ll { empty v1; unsigned char v2; unsigned long long v3:8; };
struct Sf_Uc_BFu8s { empty v1; unsigned char v2; unsigned short v3:8; };
struct Sf_Uc_BFu9i { empty v1; unsigned char v2; unsigned int v3:9; };
struct Sf_Uc_BFu9ll { empty v1; unsigned char v2; unsigned long long v3:9; };
struct Sf_Uc_BFu9s { empty v1; unsigned char v2; unsigned short v3:9; };
struct Sf_Uc_C { empty v1; unsigned char v2; char v3; };
struct Sf_Uc_D { empty v1; unsigned char v2; double v3; };
struct Sf_Uc_F { empty v1; unsigned char v2; float v3; };
struct Sf_Uc_I { empty v1; unsigned char v2; int v3; };
struct Sf_Uc_Ip { empty v1; unsigned char v2; int * v3; };
struct Sf_Uc_L { empty v1; unsigned char v2; long long v3; };
struct Sf_Uc_S { empty v1; unsigned char v2; short v3; };
struct Sf_Uc_Sf { empty v1; unsigned char v2; empty v3; };
struct Sf_Uc_Uc { empty v1; unsigned char v2; unsigned char v3; };
struct Sf_Uc_Ui { empty v1; unsigned char v2; unsigned int v3; };
struct Sf_Uc_Ul { empty v1; unsigned char v2; unsigned long long v3; };
struct Sf_Uc_Us { empty v1; unsigned char v2; unsigned short v3; };
struct Sf_Uc_Vp { empty v1; unsigned char v2; void * v3; };
struct Sf_Ui { empty v1; unsigned int v2; };
struct Sf_Ui_BFu15i { empty v1; unsigned int v2; unsigned int v3:15; };
struct Sf_Ui_BFu15ll { empty v1; unsigned int v2; unsigned long long v3:15; };
struct Sf_Ui_BFu15s { empty v1; unsigned int v2; unsigned short v3:15; };
struct Sf_Ui_BFu16i { empty v1; unsigned int v2; unsigned int v3:16; };
struct Sf_Ui_BFu16ll { empty v1; unsigned int v2; unsigned long long v3:16; };
struct Sf_Ui_BFu16s { empty v1; unsigned int v2; unsigned short v3:16; };
struct Sf_Ui_BFu17i { empty v1; unsigned int v2; unsigned int v3:17; };
struct Sf_Ui_BFu17ll { empty v1; unsigned int v2; unsigned long long v3:17; };
struct Sf_Ui_BFu1c { empty v1; unsigned int v2; unsigned char v3:1; };
struct Sf_Ui_BFu1i { empty v1; unsigned int v2; unsigned int v3:1; };
struct Sf_Ui_BFu1ll { empty v1; unsigned int v2; unsigned long long v3:1; };
struct Sf_Ui_BFu1s { empty v1; unsigned int v2; unsigned short v3:1; };
struct Sf_Ui_BFu31i { empty v1; unsigned int v2; unsigned int v3:31; };
struct Sf_Ui_BFu31ll { empty v1; unsigned int v2; unsigned long long v3:31; };
struct Sf_Ui_BFu32i { empty v1; unsigned int v2; unsigned int v3:32; };
struct Sf_Ui_BFu32ll { empty v1; unsigned int v2; unsigned long long v3:32; };
struct Sf_Ui_BFu33 { empty v1; unsigned int v2; unsigned long long v3:33; };
struct Sf_Ui_BFu7c { empty v1; unsigned int v2; unsigned char v3:7; };
struct Sf_Ui_BFu7i { empty v1; unsigned int v2; unsigned int v3:7; };
struct Sf_Ui_BFu7ll { empty v1; unsigned int v2; unsigned long long v3:7; };
struct Sf_Ui_BFu7s { empty v1; unsigned int v2; unsigned short v3:7; };
struct Sf_Ui_BFu8c { empty v1; unsigned int v2; unsigned char v3:8; };
struct Sf_Ui_BFu8i { empty v1; unsigned int v2; unsigned int v3:8; };
struct Sf_Ui_BFu8ll { empty v1; unsigned int v2; unsigned long long v3:8; };
struct Sf_Ui_BFu8s { empty v1; unsigned int v2; unsigned short v3:8; };
struct Sf_Ui_BFu9i { empty v1; unsigned int v2; unsigned int v3:9; };
struct Sf_Ui_BFu9ll { empty v1; unsigned int v2; unsigned long long v3:9; };
struct Sf_Ui_BFu9s { empty v1; unsigned int v2; unsigned short v3:9; };
struct Sf_Ui_C { empty v1; unsigned int v2; char v3; };
struct Sf_Ui_D { empty v1; unsigned int v2; double v3; };
struct Sf_Ui_F { empty v1; unsigned int v2; float v3; };
struct Sf_Ui_I { empty v1; unsigned int v2; int v3; };
struct Sf_Ui_Ip { empty v1; unsigned int v2; int * v3; };
struct Sf_Ui_L { empty v1; unsigned int v2; long long v3; };
struct Sf_Ui_S { empty v1; unsigned int v2; short v3; };
struct Sf_Ui_Sf { empty v1; unsigned int v2; empty v3; };
struct Sf_Ui_Uc { empty v1; unsigned int v2; unsigned char v3; };
struct Sf_Ui_Ui { empty v1; unsigned int v2; unsigned int v3; };
struct Sf_Ui_Ul { empty v1; unsigned int v2; unsigned long long v3; };
struct Sf_Ui_Us { empty v1; unsigned int v2; unsigned short v3; };
struct Sf_Ui_Vp { empty v1; unsigned int v2; void * v3; };
struct Sf_Ul { empty v1; unsigned long long v2; };
struct Sf_Ul_BFu15i { empty v1; unsigned long long v2; unsigned int v3:15; };
struct Sf_Ul_BFu15ll { empty v1; unsigned long long v2; unsigned long long v3:15; };
struct Sf_Ul_BFu15s { empty v1; unsigned long long v2; unsigned short v3:15; };
struct Sf_Ul_BFu16i { empty v1; unsigned long long v2; unsigned int v3:16; };
struct Sf_Ul_BFu16ll { empty v1; unsigned long long v2; unsigned long long v3:16; };
struct Sf_Ul_BFu16s { empty v1; unsigned long long v2; unsigned short v3:16; };
struct Sf_Ul_BFu17i { empty v1; unsigned long long v2; unsigned int v3:17; };
struct Sf_Ul_BFu17ll { empty v1; unsigned long long v2; unsigned long long v3:17; };
struct Sf_Ul_BFu1c { empty v1; unsigned long long v2; unsigned char v3:1; };
struct Sf_Ul_BFu1i { empty v1; unsigned long long v2; unsigned int v3:1; };
struct Sf_Ul_BFu1ll { empty v1; unsigned long long v2; unsigned long long v3:1; };
struct Sf_Ul_BFu1s { empty v1; unsigned long long v2; unsigned short v3:1; };
struct Sf_Ul_BFu31i { empty v1; unsigned long long v2; unsigned int v3:31; };
struct Sf_Ul_BFu31ll { empty v1; unsigned long long v2; unsigned long long v3:31; };
struct Sf_Ul_BFu32i { empty v1; unsigned long long v2; unsigned int v3:32; };
struct Sf_Ul_BFu32ll { empty v1; unsigned long long v2; unsigned long long v3:32; };
struct Sf_Ul_BFu33 { empty v1; unsigned long long v2; unsigned long long v3:33; };
struct Sf_Ul_BFu7c { empty v1; unsigned long long v2; unsigned char v3:7; };
struct Sf_Ul_BFu7i { empty v1; unsigned long long v2; unsigned int v3:7; };
struct Sf_Ul_BFu7ll { empty v1; unsigned long long v2; unsigned long long v3:7; };
struct Sf_Ul_BFu7s { empty v1; unsigned long long v2; unsigned short v3:7; };
struct Sf_Ul_BFu8c { empty v1; unsigned long long v2; unsigned char v3:8; };
struct Sf_Ul_BFu8i { empty v1; unsigned long long v2; unsigned int v3:8; };
struct Sf_Ul_BFu8ll { empty v1; unsigned long long v2; unsigned long long v3:8; };
struct Sf_Ul_BFu8s { empty v1; unsigned long long v2; unsigned short v3:8; };
struct Sf_Ul_BFu9i { empty v1; unsigned long long v2; unsigned int v3:9; };
struct Sf_Ul_BFu9ll { empty v1; unsigned long long v2; unsigned long long v3:9; };
struct Sf_Ul_BFu9s { empty v1; unsigned long long v2; unsigned short v3:9; };
struct Sf_Ul_C { empty v1; unsigned long long v2; char v3; };
struct Sf_Ul_D { empty v1; unsigned long long v2; double v3; };
struct Sf_Ul_F { empty v1; unsigned long long v2; float v3; };
struct Sf_Ul_I { empty v1; unsigned long long v2; int v3; };
struct Sf_Ul_Ip { empty v1; unsigned long long v2; int * v3; };
struct Sf_Ul_L { empty v1; unsigned long long v2; long long v3; };
struct Sf_Ul_S { empty v1; unsigned long long v2; short v3; };
struct Sf_Ul_Sf { empty v1; unsigned long long v2; empty v3; };
struct Sf_Ul_Uc { empty v1; unsigned long long v2; unsigned char v3; };
struct Sf_Ul_Ui { empty v1; unsigned long long v2; unsigned int v3; };
struct Sf_Ul_Ul { empty v1; unsigned long long v2; unsigned long long v3; };
struct Sf_Ul_Us { empty v1; unsigned long long v2; unsigned short v3; };
struct Sf_Ul_Vp { empty v1; unsigned long long v2; void * v3; };
struct Sf_Us { empty v1; unsigned short v2; };
struct Sf_Us_BFu15i { empty v1; unsigned short v2; unsigned int v3:15; };
struct Sf_Us_BFu15ll { empty v1; unsigned short v2; unsigned long long v3:15; };
struct Sf_Us_BFu15s { empty v1; unsigned short v2; unsigned short v3:15; };
struct Sf_Us_BFu16i { empty v1; unsigned short v2; unsigned int v3:16; };
struct Sf_Us_BFu16ll { empty v1; unsigned short v2; unsigned long long v3:16; };
struct Sf_Us_BFu16s { empty v1; unsigned short v2; unsigned short v3:16; };
struct Sf_Us_BFu17i { empty v1; unsigned short v2; unsigned int v3:17; };
struct Sf_Us_BFu17ll { empty v1; unsigned short v2; unsigned long long v3:17; };
struct Sf_Us_BFu1c { empty v1; unsigned short v2; unsigned char v3:1; };
struct Sf_Us_BFu1i { empty v1; unsigned short v2; unsigned int v3:1; };
struct Sf_Us_BFu1ll { empty v1; unsigned short v2; unsigned long long v3:1; };
struct Sf_Us_BFu1s { empty v1; unsigned short v2; unsigned short v3:1; };
struct Sf_Us_BFu31i { empty v1; unsigned short v2; unsigned int v3:31; };
struct Sf_Us_BFu31ll { empty v1; unsigned short v2; unsigned long long v3:31; };
struct Sf_Us_BFu32i { empty v1; unsigned short v2; unsigned int v3:32; };
struct Sf_Us_BFu32ll { empty v1; unsigned short v2; unsigned long long v3:32; };
struct Sf_Us_BFu33 { empty v1; unsigned short v2; unsigned long long v3:33; };
struct Sf_Us_BFu7c { empty v1; unsigned short v2; unsigned char v3:7; };
struct Sf_Us_BFu7i { empty v1; unsigned short v2; unsigned int v3:7; };
struct Sf_Us_BFu7ll { empty v1; unsigned short v2; unsigned long long v3:7; };
struct Sf_Us_BFu7s { empty v1; unsigned short v2; unsigned short v3:7; };
struct Sf_Us_BFu8c { empty v1; unsigned short v2; unsigned char v3:8; };
struct Sf_Us_BFu8i { empty v1; unsigned short v2; unsigned int v3:8; };
struct Sf_Us_BFu8ll { empty v1; unsigned short v2; unsigned long long v3:8; };
struct Sf_Us_BFu8s { empty v1; unsigned short v2; unsigned short v3:8; };
struct Sf_Us_BFu9i { empty v1; unsigned short v2; unsigned int v3:9; };
struct Sf_Us_BFu9ll { empty v1; unsigned short v2; unsigned long long v3:9; };
struct Sf_Us_BFu9s { empty v1; unsigned short v2; unsigned short v3:9; };
struct Sf_Us_C { empty v1; unsigned short v2; char v3; };
struct Sf_Us_D { empty v1; unsigned short v2; double v3; };
struct Sf_Us_F { empty v1; unsigned short v2; float v3; };
struct Sf_Us_I { empty v1; unsigned short v2; int v3; };
struct Sf_Us_Ip { empty v1; unsigned short v2; int * v3; };
struct Sf_Us_L { empty v1; unsigned short v2; long long v3; };
struct Sf_Us_S { empty v1; unsigned short v2; short v3; };
struct Sf_Us_Sf { empty v1; unsigned short v2; empty v3; };
struct Sf_Us_Uc { empty v1; unsigned short v2; unsigned char v3; };
struct Sf_Us_Ui { empty v1; unsigned short v2; unsigned int v3; };
struct Sf_Us_Ul { empty v1; unsigned short v2; unsigned long long v3; };
struct Sf_Us_Us { empty v1; unsigned short v2; unsigned short v3; };
struct Sf_Us_Vp { empty v1; unsigned short v2; void * v3; };
struct Sf_Vp { empty v1; void * v2; };
struct Sf_Vp_BFu15i { empty v1; void * v2; unsigned int v3:15; };
struct Sf_Vp_BFu15ll { empty v1; void * v2; unsigned long long v3:15; };
struct Sf_Vp_BFu15s { empty v1; void * v2; unsigned short v3:15; };
struct Sf_Vp_BFu16i { empty v1; void * v2; unsigned int v3:16; };
struct Sf_Vp_BFu16ll { empty v1; void * v2; unsigned long long v3:16; };
struct Sf_Vp_BFu16s { empty v1; void * v2; unsigned short v3:16; };
struct Sf_Vp_BFu17i { empty v1; void * v2; unsigned int v3:17; };
struct Sf_Vp_BFu17ll { empty v1; void * v2; unsigned long long v3:17; };
struct Sf_Vp_BFu1c { empty v1; void * v2; unsigned char v3:1; };
struct Sf_Vp_BFu1i { empty v1; void * v2; unsigned int v3:1; };
struct Sf_Vp_BFu1ll { empty v1; void * v2; unsigned long long v3:1; };
struct Sf_Vp_BFu1s { empty v1; void * v2; unsigned short v3:1; };
struct Sf_Vp_BFu31i { empty v1; void * v2; unsigned int v3:31; };
struct Sf_Vp_BFu31ll { empty v1; void * v2; unsigned long long v3:31; };
struct Sf_Vp_BFu32i { empty v1; void * v2; unsigned int v3:32; };
struct Sf_Vp_BFu32ll { empty v1; void * v2; unsigned long long v3:32; };
struct Sf_Vp_BFu33 { empty v1; void * v2; unsigned long long v3:33; };
struct Sf_Vp_BFu7c { empty v1; void * v2; unsigned char v3:7; };
struct Sf_Vp_BFu7i { empty v1; void * v2; unsigned int v3:7; };
struct Sf_Vp_BFu7ll { empty v1; void * v2; unsigned long long v3:7; };
struct Sf_Vp_BFu7s { empty v1; void * v2; unsigned short v3:7; };
struct Sf_Vp_BFu8c { empty v1; void * v2; unsigned char v3:8; };
struct Sf_Vp_BFu8i { empty v1; void * v2; unsigned int v3:8; };
struct Sf_Vp_BFu8ll { empty v1; void * v2; unsigned long long v3:8; };
struct Sf_Vp_BFu8s { empty v1; void * v2; unsigned short v3:8; };
struct Sf_Vp_BFu9i { empty v1; void * v2; unsigned int v3:9; };
struct Sf_Vp_BFu9ll { empty v1; void * v2; unsigned long long v3:9; };
struct Sf_Vp_BFu9s { empty v1; void * v2; unsigned short v3:9; };
struct Sf_Vp_C { empty v1; void * v2; char v3; };
struct Sf_Vp_D { empty v1; void * v2; double v3; };
struct Sf_Vp_F { empty v1; void * v2; float v3; };
struct Sf_Vp_I { empty v1; void * v2; int v3; };
struct Sf_Vp_Ip { empty v1; void * v2; int * v3; };
struct Sf_Vp_L { empty v1; void * v2; long long v3; };
struct Sf_Vp_S { empty v1; void * v2; short v3; };
struct Sf_Vp_Sf { empty v1; void * v2; empty v3; };
struct Sf_Vp_Uc { empty v1; void * v2; unsigned char v3; };
struct Sf_Vp_Ui { empty v1; void * v2; unsigned int v3; };
struct Sf_Vp_Ul { empty v1; void * v2; unsigned long long v3; };
struct Sf_Vp_Us { empty v1; void * v2; unsigned short v3; };
struct Sf_Vp_Vp { empty v1; void * v2; void * v3; };
struct Uc_BFu15i_Sf { unsigned char v1; unsigned int v2:15; empty v3; };
struct Uc_BFu15ll_Sf { unsigned char v1; unsigned long long v2:15; empty v3; };
struct Uc_BFu15s_Sf { unsigned char v1; unsigned short v2:15; empty v3; };
struct Uc_BFu16i_Sf { unsigned char v1; unsigned int v2:16; empty v3; };
struct Uc_BFu16ll_Sf { unsigned char v1; unsigned long long v2:16; empty v3; };
struct Uc_BFu16s_Sf { unsigned char v1; unsigned short v2:16; empty v3; };
struct Uc_BFu17i_Sf { unsigned char v1; unsigned int v2:17; empty v3; };
struct Uc_BFu17ll_Sf { unsigned char v1; unsigned long long v2:17; empty v3; };
struct Uc_BFu1c_Sf { unsigned char v1; unsigned char v2:1; empty v3; };
struct Uc_BFu1i_Sf { unsigned char v1; unsigned int v2:1; empty v3; };
struct Uc_BFu1ll_Sf { unsigned char v1; unsigned long long v2:1; empty v3; };
struct Uc_BFu1s_Sf { unsigned char v1; unsigned short v2:1; empty v3; };
struct Uc_BFu31i_Sf { unsigned char v1; unsigned int v2:31; empty v3; };
struct Uc_BFu31ll_Sf { unsigned char v1; unsigned long long v2:31; empty v3; };
struct Uc_BFu32i_Sf { unsigned char v1; unsigned int v2:32; empty v3; };
struct Uc_BFu32ll_Sf { unsigned char v1; unsigned long long v2:32; empty v3; };
struct Uc_BFu33_Sf { unsigned char v1; unsigned long long v2:33; empty v3; };
struct Uc_BFu7c_Sf { unsigned char v1; unsigned char v2:7; empty v3; };
struct Uc_BFu7i_Sf { unsigned char v1; unsigned int v2:7; empty v3; };
struct Uc_BFu7ll_Sf { unsigned char v1; unsigned long long v2:7; empty v3; };
struct Uc_BFu7s_Sf { unsigned char v1; unsigned short v2:7; empty v3; };
struct Uc_BFu8c_Sf { unsigned char v1; unsigned char v2:8; empty v3; };
struct Uc_BFu8i_Sf { unsigned char v1; unsigned int v2:8; empty v3; };
struct Uc_BFu8ll_Sf { unsigned char v1; unsigned long long v2:8; empty v3; };
struct Uc_BFu8s_Sf { unsigned char v1; unsigned short v2:8; empty v3; };
struct Uc_BFu9i_Sf { unsigned char v1; unsigned int v2:9; empty v3; };
struct Uc_BFu9ll_Sf { unsigned char v1; unsigned long long v2:9; empty v3; };
struct Uc_BFu9s_Sf { unsigned char v1; unsigned short v2:9; empty v3; };
struct Uc_C_Sf { unsigned char v1; char v2; empty v3; };
struct Uc_D_Sf { unsigned char v1; double v2; empty v3; };
struct Uc_F_Sf { unsigned char v1; float v2; empty v3; };
struct Uc_I_Sf { unsigned char v1; int v2; empty v3; };
struct Uc_Ip_Sf { unsigned char v1; int * v2; empty v3; };
struct Uc_L_Sf { unsigned char v1; long long v2; empty v3; };
struct Uc_S_Sf { unsigned char v1; short v2; empty v3; };
struct Uc_Sf { unsigned char v1; empty v2; };
struct Uc_Sf_BFu15i { unsigned char v1; empty v2; unsigned int v3:15; };
struct Uc_Sf_BFu15ll { unsigned char v1; empty v2; unsigned long long v3:15; };
struct Uc_Sf_BFu15s { unsigned char v1; empty v2; unsigned short v3:15; };
struct Uc_Sf_BFu16i { unsigned char v1; empty v2; unsigned int v3:16; };
struct Uc_Sf_BFu16ll { unsigned char v1; empty v2; unsigned long long v3:16; };
struct Uc_Sf_BFu16s { unsigned char v1; empty v2; unsigned short v3:16; };
struct Uc_Sf_BFu17i { unsigned char v1; empty v2; unsigned int v3:17; };
struct Uc_Sf_BFu17ll { unsigned char v1; empty v2; unsigned long long v3:17; };
struct Uc_Sf_BFu1c { unsigned char v1; empty v2; unsigned char v3:1; };
struct Uc_Sf_BFu1i { unsigned char v1; empty v2; unsigned int v3:1; };
struct Uc_Sf_BFu1ll { unsigned char v1; empty v2; unsigned long long v3:1; };
struct Uc_Sf_BFu1s { unsigned char v1; empty v2; unsigned short v3:1; };
struct Uc_Sf_BFu31i { unsigned char v1; empty v2; unsigned int v3:31; };
struct Uc_Sf_BFu31ll { unsigned char v1; empty v2; unsigned long long v3:31; };
struct Uc_Sf_BFu32i { unsigned char v1; empty v2; unsigned int v3:32; };
struct Uc_Sf_BFu32ll { unsigned char v1; empty v2; unsigned long long v3:32; };
struct Uc_Sf_BFu33 { unsigned char v1; empty v2; unsigned long long v3:33; };
struct Uc_Sf_BFu7c { unsigned char v1; empty v2; unsigned char v3:7; };
struct Uc_Sf_BFu7i { unsigned char v1; empty v2; unsigned int v3:7; };
struct Uc_Sf_BFu7ll { unsigned char v1; empty v2; unsigned long long v3:7; };
struct Uc_Sf_BFu7s { unsigned char v1; empty v2; unsigned short v3:7; };
struct Uc_Sf_BFu8c { unsigned char v1; empty v2; unsigned char v3:8; };
struct Uc_Sf_BFu8i { unsigned char v1; empty v2; unsigned int v3:8; };
struct Uc_Sf_BFu8ll { unsigned char v1; empty v2; unsigned long long v3:8; };
struct Uc_Sf_BFu8s { unsigned char v1; empty v2; unsigned short v3:8; };
struct Uc_Sf_BFu9i { unsigned char v1; empty v2; unsigned int v3:9; };
struct Uc_Sf_BFu9ll { unsigned char v1; empty v2; unsigned long long v3:9; };
struct Uc_Sf_BFu9s { unsigned char v1; empty v2; unsigned short v3:9; };
struct Uc_Sf_C { unsigned char v1; empty v2; char v3; };
struct Uc_Sf_D { unsigned char v1; empty v2; double v3; };
struct Uc_Sf_F { unsigned char v1; empty v2; float v3; };
struct Uc_Sf_I { unsigned char v1; empty v2; int v3; };
struct Uc_Sf_Ip { unsigned char v1; empty v2; int * v3; };
struct Uc_Sf_L { unsigned char v1; empty v2; long long v3; };
struct Uc_Sf_S { unsigned char v1; empty v2; short v3; };
struct Uc_Sf_Sf { unsigned char v1; empty v2; empty v3; };
struct Uc_Sf_Uc { unsigned char v1; empty v2; unsigned char v3; };
struct Uc_Sf_Ui { unsigned char v1; empty v2; unsigned int v3; };
struct Uc_Sf_Ul { unsigned char v1; empty v2; unsigned long long v3; };
struct Uc_Sf_Us { unsigned char v1; empty v2; unsigned short v3; };
struct Uc_Sf_Vp { unsigned char v1; empty v2; void * v3; };
struct Uc_Uc_Sf { unsigned char v1; unsigned char v2; empty v3; };
struct Uc_Ui_Sf { unsigned char v1; unsigned int v2; empty v3; };
struct Uc_Ul_Sf { unsigned char v1; unsigned long long v2; empty v3; };
struct Uc_Us_Sf { unsigned char v1; unsigned short v2; empty v3; };
struct Uc_Vp_Sf { unsigned char v1; void * v2; empty v3; };
struct Ui_BFu15i_Sf { unsigned int v1; unsigned int v2:15; empty v3; };
struct Ui_BFu15ll_Sf { unsigned int v1; unsigned long long v2:15; empty v3; };
struct Ui_BFu15s_Sf { unsigned int v1; unsigned short v2:15; empty v3; };
struct Ui_BFu16i_Sf { unsigned int v1; unsigned int v2:16; empty v3; };
struct Ui_BFu16ll_Sf { unsigned int v1; unsigned long long v2:16; empty v3; };
struct Ui_BFu16s_Sf { unsigned int v1; unsigned short v2:16; empty v3; };
struct Ui_BFu17i_Sf { unsigned int v1; unsigned int v2:17; empty v3; };
struct Ui_BFu17ll_Sf { unsigned int v1; unsigned long long v2:17; empty v3; };
struct Ui_BFu1c_Sf { unsigned int v1; unsigned char v2:1; empty v3; };
struct Ui_BFu1i_Sf { unsigned int v1; unsigned int v2:1; empty v3; };
struct Ui_BFu1ll_Sf { unsigned int v1; unsigned long long v2:1; empty v3; };
struct Ui_BFu1s_Sf { unsigned int v1; unsigned short v2:1; empty v3; };
struct Ui_BFu31i_Sf { unsigned int v1; unsigned int v2:31; empty v3; };
struct Ui_BFu31ll_Sf { unsigned int v1; unsigned long long v2:31; empty v3; };
struct Ui_BFu32i_Sf { unsigned int v1; unsigned int v2:32; empty v3; };
struct Ui_BFu32ll_Sf { unsigned int v1; unsigned long long v2:32; empty v3; };
struct Ui_BFu33_Sf { unsigned int v1; unsigned long long v2:33; empty v3; };
struct Ui_BFu7c_Sf { unsigned int v1; unsigned char v2:7; empty v3; };
struct Ui_BFu7i_Sf { unsigned int v1; unsigned int v2:7; empty v3; };
struct Ui_BFu7ll_Sf { unsigned int v1; unsigned long long v2:7; empty v3; };
struct Ui_BFu7s_Sf { unsigned int v1; unsigned short v2:7; empty v3; };
struct Ui_BFu8c_Sf { unsigned int v1; unsigned char v2:8; empty v3; };
struct Ui_BFu8i_Sf { unsigned int v1; unsigned int v2:8; empty v3; };
struct Ui_BFu8ll_Sf { unsigned int v1; unsigned long long v2:8; empty v3; };
struct Ui_BFu8s_Sf { unsigned int v1; unsigned short v2:8; empty v3; };
struct Ui_BFu9i_Sf { unsigned int v1; unsigned int v2:9; empty v3; };
struct Ui_BFu9ll_Sf { unsigned int v1; unsigned long long v2:9; empty v3; };
struct Ui_BFu9s_Sf { unsigned int v1; unsigned short v2:9; empty v3; };
struct Ui_C_Sf { unsigned int v1; char v2; empty v3; };
struct Ui_D_Sf { unsigned int v1; double v2; empty v3; };
struct Ui_F_Sf { unsigned int v1; float v2; empty v3; };
struct Ui_I_Sf { unsigned int v1; int v2; empty v3; };
struct Ui_Ip_Sf { unsigned int v1; int * v2; empty v3; };
struct Ui_L_Sf { unsigned int v1; long long v2; empty v3; };
struct Ui_S_Sf { unsigned int v1; short v2; empty v3; };
struct Ui_Sf { unsigned int v1; empty v2; };
struct Ui_Sf_BFu15i { unsigned int v1; empty v2; unsigned int v3:15; };
struct Ui_Sf_BFu15ll { unsigned int v1; empty v2; unsigned long long v3:15; };
struct Ui_Sf_BFu15s { unsigned int v1; empty v2; unsigned short v3:15; };
struct Ui_Sf_BFu16i { unsigned int v1; empty v2; unsigned int v3:16; };
struct Ui_Sf_BFu16ll { unsigned int v1; empty v2; unsigned long long v3:16; };
struct Ui_Sf_BFu16s { unsigned int v1; empty v2; unsigned short v3:16; };
struct Ui_Sf_BFu17i { unsigned int v1; empty v2; unsigned int v3:17; };
struct Ui_Sf_BFu17ll { unsigned int v1; empty v2; unsigned long long v3:17; };
struct Ui_Sf_BFu1c { unsigned int v1; empty v2; unsigned char v3:1; };
struct Ui_Sf_BFu1i { unsigned int v1; empty v2; unsigned int v3:1; };
struct Ui_Sf_BFu1ll { unsigned int v1; empty v2; unsigned long long v3:1; };
struct Ui_Sf_BFu1s { unsigned int v1; empty v2; unsigned short v3:1; };
struct Ui_Sf_BFu31i { unsigned int v1; empty v2; unsigned int v3:31; };
struct Ui_Sf_BFu31ll { unsigned int v1; empty v2; unsigned long long v3:31; };
struct Ui_Sf_BFu32i { unsigned int v1; empty v2; unsigned int v3:32; };
struct Ui_Sf_BFu32ll { unsigned int v1; empty v2; unsigned long long v3:32; };
struct Ui_Sf_BFu33 { unsigned int v1; empty v2; unsigned long long v3:33; };
struct Ui_Sf_BFu7c { unsigned int v1; empty v2; unsigned char v3:7; };
struct Ui_Sf_BFu7i { unsigned int v1; empty v2; unsigned int v3:7; };
struct Ui_Sf_BFu7ll { unsigned int v1; empty v2; unsigned long long v3:7; };
struct Ui_Sf_BFu7s { unsigned int v1; empty v2; unsigned short v3:7; };
struct Ui_Sf_BFu8c { unsigned int v1; empty v2; unsigned char v3:8; };
struct Ui_Sf_BFu8i { unsigned int v1; empty v2; unsigned int v3:8; };
struct Ui_Sf_BFu8ll { unsigned int v1; empty v2; unsigned long long v3:8; };
struct Ui_Sf_BFu8s { unsigned int v1; empty v2; unsigned short v3:8; };
struct Ui_Sf_BFu9i { unsigned int v1; empty v2; unsigned int v3:9; };
struct Ui_Sf_BFu9ll { unsigned int v1; empty v2; unsigned long long v3:9; };
struct Ui_Sf_BFu9s { unsigned int v1; empty v2; unsigned short v3:9; };
struct Ui_Sf_C { unsigned int v1; empty v2; char v3; };
struct Ui_Sf_D { unsigned int v1; empty v2; double v3; };
struct Ui_Sf_F { unsigned int v1; empty v2; float v3; };
struct Ui_Sf_I { unsigned int v1; empty v2; int v3; };
struct Ui_Sf_Ip { unsigned int v1; empty v2; int * v3; };
struct Ui_Sf_L { unsigned int v1; empty v2; long long v3; };
struct Ui_Sf_S { unsigned int v1; empty v2; short v3; };
struct Ui_Sf_Sf { unsigned int v1; empty v2; empty v3; };
struct Ui_Sf_Uc { unsigned int v1; empty v2; unsigned char v3; };
struct Ui_Sf_Ui { unsigned int v1; empty v2; unsigned int v3; };
struct Ui_Sf_Ul { unsigned int v1; empty v2; unsigned long long v3; };
struct Ui_Sf_Us { unsigned int v1; empty v2; unsigned short v3; };
struct Ui_Sf_Vp { unsigned int v1; empty v2; void * v3; };
struct Ui_Uc_Sf { unsigned int v1; unsigned char v2; empty v3; };
struct Ui_Ui_Sf { unsigned int v1; unsigned int v2; empty v3; };
struct Ui_Ul_Sf { unsigned int v1; unsigned long long v2; empty v3; };
struct Ui_Us_Sf { unsigned int v1; unsigned short v2; empty v3; };
struct Ui_Vp_Sf { unsigned int v1; void * v2; empty v3; };
struct Ul_BFu15i_Sf { unsigned long long v1; unsigned int v2:15; empty v3; };
struct Ul_BFu15ll_Sf { unsigned long long v1; unsigned long long v2:15; empty v3; };
struct Ul_BFu15s_Sf { unsigned long long v1; unsigned short v2:15; empty v3; };
struct Ul_BFu16i_Sf { unsigned long long v1; unsigned int v2:16; empty v3; };
struct Ul_BFu16ll_Sf { unsigned long long v1; unsigned long long v2:16; empty v3; };
struct Ul_BFu16s_Sf { unsigned long long v1; unsigned short v2:16; empty v3; };
struct Ul_BFu17i_Sf { unsigned long long v1; unsigned int v2:17; empty v3; };
struct Ul_BFu17ll_Sf { unsigned long long v1; unsigned long long v2:17; empty v3; };
struct Ul_BFu1c_Sf { unsigned long long v1; unsigned char v2:1; empty v3; };
struct Ul_BFu1i_Sf { unsigned long long v1; unsigned int v2:1; empty v3; };
struct Ul_BFu1ll_Sf { unsigned long long v1; unsigned long long v2:1; empty v3; };
struct Ul_BFu1s_Sf { unsigned long long v1; unsigned short v2:1; empty v3; };
struct Ul_BFu31i_Sf { unsigned long long v1; unsigned int v2:31; empty v3; };
struct Ul_BFu31ll_Sf { unsigned long long v1; unsigned long long v2:31; empty v3; };
struct Ul_BFu32i_Sf { unsigned long long v1; unsigned int v2:32; empty v3; };
struct Ul_BFu32ll_Sf { unsigned long long v1; unsigned long long v2:32; empty v3; };
struct Ul_BFu33_Sf { unsigned long long v1; unsigned long long v2:33; empty v3; };
struct Ul_BFu7c_Sf { unsigned long long v1; unsigned char v2:7; empty v3; };
struct Ul_BFu7i_Sf { unsigned long long v1; unsigned int v2:7; empty v3; };
struct Ul_BFu7ll_Sf { unsigned long long v1; unsigned long long v2:7; empty v3; };
struct Ul_BFu7s_Sf { unsigned long long v1; unsigned short v2:7; empty v3; };
struct Ul_BFu8c_Sf { unsigned long long v1; unsigned char v2:8; empty v3; };
struct Ul_BFu8i_Sf { unsigned long long v1; unsigned int v2:8; empty v3; };
struct Ul_BFu8ll_Sf { unsigned long long v1; unsigned long long v2:8; empty v3; };
struct Ul_BFu8s_Sf { unsigned long long v1; unsigned short v2:8; empty v3; };
struct Ul_BFu9i_Sf { unsigned long long v1; unsigned int v2:9; empty v3; };
struct Ul_BFu9ll_Sf { unsigned long long v1; unsigned long long v2:9; empty v3; };
struct Ul_BFu9s_Sf { unsigned long long v1; unsigned short v2:9; empty v3; };
struct Ul_C_Sf { unsigned long long v1; char v2; empty v3; };
struct Ul_D_Sf { unsigned long long v1; double v2; empty v3; };
struct Ul_F_Sf { unsigned long long v1; float v2; empty v3; };
struct Ul_I_Sf { unsigned long long v1; int v2; empty v3; };
struct Ul_Ip_Sf { unsigned long long v1; int * v2; empty v3; };
struct Ul_L_Sf { unsigned long long v1; long long v2; empty v3; };
struct Ul_S_Sf { unsigned long long v1; short v2; empty v3; };
struct Ul_Sf { unsigned long long v1; empty v2; };
struct Ul_Sf_BFu15i { unsigned long long v1; empty v2; unsigned int v3:15; };
struct Ul_Sf_BFu15ll { unsigned long long v1; empty v2; unsigned long long v3:15; };
struct Ul_Sf_BFu15s { unsigned long long v1; empty v2; unsigned short v3:15; };
struct Ul_Sf_BFu16i { unsigned long long v1; empty v2; unsigned int v3:16; };
struct Ul_Sf_BFu16ll { unsigned long long v1; empty v2; unsigned long long v3:16; };
struct Ul_Sf_BFu16s { unsigned long long v1; empty v2; unsigned short v3:16; };
struct Ul_Sf_BFu17i { unsigned long long v1; empty v2; unsigned int v3:17; };
struct Ul_Sf_BFu17ll { unsigned long long v1; empty v2; unsigned long long v3:17; };
struct Ul_Sf_BFu1c { unsigned long long v1; empty v2; unsigned char v3:1; };
struct Ul_Sf_BFu1i { unsigned long long v1; empty v2; unsigned int v3:1; };
struct Ul_Sf_BFu1ll { unsigned long long v1; empty v2; unsigned long long v3:1; };
struct Ul_Sf_BFu1s { unsigned long long v1; empty v2; unsigned short v3:1; };
struct Ul_Sf_BFu31i { unsigned long long v1; empty v2; unsigned int v3:31; };
struct Ul_Sf_BFu31ll { unsigned long long v1; empty v2; unsigned long long v3:31; };
struct Ul_Sf_BFu32i { unsigned long long v1; empty v2; unsigned int v3:32; };
struct Ul_Sf_BFu32ll { unsigned long long v1; empty v2; unsigned long long v3:32; };
struct Ul_Sf_BFu33 { unsigned long long v1; empty v2; unsigned long long v3:33; };
struct Ul_Sf_BFu7c { unsigned long long v1; empty v2; unsigned char v3:7; };
struct Ul_Sf_BFu7i { unsigned long long v1; empty v2; unsigned int v3:7; };
struct Ul_Sf_BFu7ll { unsigned long long v1; empty v2; unsigned long long v3:7; };
struct Ul_Sf_BFu7s { unsigned long long v1; empty v2; unsigned short v3:7; };
struct Ul_Sf_BFu8c { unsigned long long v1; empty v2; unsigned char v3:8; };
struct Ul_Sf_BFu8i { unsigned long long v1; empty v2; unsigned int v3:8; };
struct Ul_Sf_BFu8ll { unsigned long long v1; empty v2; unsigned long long v3:8; };
struct Ul_Sf_BFu8s { unsigned long long v1; empty v2; unsigned short v3:8; };
struct Ul_Sf_BFu9i { unsigned long long v1; empty v2; unsigned int v3:9; };
struct Ul_Sf_BFu9ll { unsigned long long v1; empty v2; unsigned long long v3:9; };
struct Ul_Sf_BFu9s { unsigned long long v1; empty v2; unsigned short v3:9; };
struct Ul_Sf_C { unsigned long long v1; empty v2; char v3; };
struct Ul_Sf_D { unsigned long long v1; empty v2; double v3; };
struct Ul_Sf_F { unsigned long long v1; empty v2; float v3; };
struct Ul_Sf_I { unsigned long long v1; empty v2; int v3; };
struct Ul_Sf_Ip { unsigned long long v1; empty v2; int * v3; };
struct Ul_Sf_L { unsigned long long v1; empty v2; long long v3; };
struct Ul_Sf_S { unsigned long long v1; empty v2; short v3; };
struct Ul_Sf_Sf { unsigned long long v1; empty v2; empty v3; };
struct Ul_Sf_Uc { unsigned long long v1; empty v2; unsigned char v3; };
struct Ul_Sf_Ui { unsigned long long v1; empty v2; unsigned int v3; };
struct Ul_Sf_Ul { unsigned long long v1; empty v2; unsigned long long v3; };
struct Ul_Sf_Us { unsigned long long v1; empty v2; unsigned short v3; };
struct Ul_Sf_Vp { unsigned long long v1; empty v2; void * v3; };
struct Ul_Uc_Sf { unsigned long long v1; unsigned char v2; empty v3; };
struct Ul_Ui_Sf { unsigned long long v1; unsigned int v2; empty v3; };
struct Ul_Ul_Sf { unsigned long long v1; unsigned long long v2; empty v3; };
struct Ul_Us_Sf { unsigned long long v1; unsigned short v2; empty v3; };
struct Ul_Vp_Sf { unsigned long long v1; void * v2; empty v3; };
struct Us_BFu15i_Sf { unsigned short v1; unsigned int v2:15; empty v3; };
struct Us_BFu15ll_Sf { unsigned short v1; unsigned long long v2:15; empty v3; };
struct Us_BFu15s_Sf { unsigned short v1; unsigned short v2:15; empty v3; };
struct Us_BFu16i_Sf { unsigned short v1; unsigned int v2:16; empty v3; };
struct Us_BFu16ll_Sf { unsigned short v1; unsigned long long v2:16; empty v3; };
struct Us_BFu16s_Sf { unsigned short v1; unsigned short v2:16; empty v3; };
struct Us_BFu17i_Sf { unsigned short v1; unsigned int v2:17; empty v3; };
struct Us_BFu17ll_Sf { unsigned short v1; unsigned long long v2:17; empty v3; };
struct Us_BFu1c_Sf { unsigned short v1; unsigned char v2:1; empty v3; };
struct Us_BFu1i_Sf { unsigned short v1; unsigned int v2:1; empty v3; };
struct Us_BFu1ll_Sf { unsigned short v1; unsigned long long v2:1; empty v3; };
struct Us_BFu1s_Sf { unsigned short v1; unsigned short v2:1; empty v3; };
struct Us_BFu31i_Sf { unsigned short v1; unsigned int v2:31; empty v3; };
struct Us_BFu31ll_Sf { unsigned short v1; unsigned long long v2:31; empty v3; };
struct Us_BFu32i_Sf { unsigned short v1; unsigned int v2:32; empty v3; };
struct Us_BFu32ll_Sf { unsigned short v1; unsigned long long v2:32; empty v3; };
struct Us_BFu33_Sf { unsigned short v1; unsigned long long v2:33; empty v3; };
struct Us_BFu7c_Sf { unsigned short v1; unsigned char v2:7; empty v3; };
struct Us_BFu7i_Sf { unsigned short v1; unsigned int v2:7; empty v3; };
struct Us_BFu7ll_Sf { unsigned short v1; unsigned long long v2:7; empty v3; };
struct Us_BFu7s_Sf { unsigned short v1; unsigned short v2:7; empty v3; };
struct Us_BFu8c_Sf { unsigned short v1; unsigned char v2:8; empty v3; };
struct Us_BFu8i_Sf { unsigned short v1; unsigned int v2:8; empty v3; };
struct Us_BFu8ll_Sf { unsigned short v1; unsigned long long v2:8; empty v3; };
struct Us_BFu8s_Sf { unsigned short v1; unsigned short v2:8; empty v3; };
struct Us_BFu9i_Sf { unsigned short v1; unsigned int v2:9; empty v3; };
struct Us_BFu9ll_Sf { unsigned short v1; unsigned long long v2:9; empty v3; };
struct Us_BFu9s_Sf { unsigned short v1; unsigned short v2:9; empty v3; };
struct Us_C_Sf { unsigned short v1; char v2; empty v3; };
struct Us_D_Sf { unsigned short v1; double v2; empty v3; };
struct Us_F_Sf { unsigned short v1; float v2; empty v3; };
struct Us_I_Sf { unsigned short v1; int v2; empty v3; };
struct Us_Ip_Sf { unsigned short v1; int * v2; empty v3; };
struct Us_L_Sf { unsigned short v1; long long v2; empty v3; };
struct Us_S_Sf { unsigned short v1; short v2; empty v3; };
struct Us_Sf { unsigned short v1; empty v2; };
struct Us_Sf_BFu15i { unsigned short v1; empty v2; unsigned int v3:15; };
struct Us_Sf_BFu15ll { unsigned short v1; empty v2; unsigned long long v3:15; };
struct Us_Sf_BFu15s { unsigned short v1; empty v2; unsigned short v3:15; };
struct Us_Sf_BFu16i { unsigned short v1; empty v2; unsigned int v3:16; };
struct Us_Sf_BFu16ll { unsigned short v1; empty v2; unsigned long long v3:16; };
struct Us_Sf_BFu16s { unsigned short v1; empty v2; unsigned short v3:16; };
struct Us_Sf_BFu17i { unsigned short v1; empty v2; unsigned int v3:17; };
struct Us_Sf_BFu17ll { unsigned short v1; empty v2; unsigned long long v3:17; };
struct Us_Sf_BFu1c { unsigned short v1; empty v2; unsigned char v3:1; };
struct Us_Sf_BFu1i { unsigned short v1; empty v2; unsigned int v3:1; };
struct Us_Sf_BFu1ll { unsigned short v1; empty v2; unsigned long long v3:1; };
struct Us_Sf_BFu1s { unsigned short v1; empty v2; unsigned short v3:1; };
struct Us_Sf_BFu31i { unsigned short v1; empty v2; unsigned int v3:31; };
struct Us_Sf_BFu31ll { unsigned short v1; empty v2; unsigned long long v3:31; };
struct Us_Sf_BFu32i { unsigned short v1; empty v2; unsigned int v3:32; };
struct Us_Sf_BFu32ll { unsigned short v1; empty v2; unsigned long long v3:32; };
struct Us_Sf_BFu33 { unsigned short v1; empty v2; unsigned long long v3:33; };
struct Us_Sf_BFu7c { unsigned short v1; empty v2; unsigned char v3:7; };
struct Us_Sf_BFu7i { unsigned short v1; empty v2; unsigned int v3:7; };
struct Us_Sf_BFu7ll { unsigned short v1; empty v2; unsigned long long v3:7; };
struct Us_Sf_BFu7s { unsigned short v1; empty v2; unsigned short v3:7; };
struct Us_Sf_BFu8c { unsigned short v1; empty v2; unsigned char v3:8; };
struct Us_Sf_BFu8i { unsigned short v1; empty v2; unsigned int v3:8; };
struct Us_Sf_BFu8ll { unsigned short v1; empty v2; unsigned long long v3:8; };
struct Us_Sf_BFu8s { unsigned short v1; empty v2; unsigned short v3:8; };
struct Us_Sf_BFu9i { unsigned short v1; empty v2; unsigned int v3:9; };
struct Us_Sf_BFu9ll { unsigned short v1; empty v2; unsigned long long v3:9; };
struct Us_Sf_BFu9s { unsigned short v1; empty v2; unsigned short v3:9; };
struct Us_Sf_C { unsigned short v1; empty v2; char v3; };
struct Us_Sf_D { unsigned short v1; empty v2; double v3; };
struct Us_Sf_F { unsigned short v1; empty v2; float v3; };
struct Us_Sf_I { unsigned short v1; empty v2; int v3; };
struct Us_Sf_Ip { unsigned short v1; empty v2; int * v3; };
struct Us_Sf_L { unsigned short v1; empty v2; long long v3; };
struct Us_Sf_S { unsigned short v1; empty v2; short v3; };
struct Us_Sf_Sf { unsigned short v1; empty v2; empty v3; };
struct Us_Sf_Uc { unsigned short v1; empty v2; unsigned char v3; };
struct Us_Sf_Ui { unsigned short v1; empty v2; unsigned int v3; };
struct Us_Sf_Ul { unsigned short v1; empty v2; unsigned long long v3; };
struct Us_Sf_Us { unsigned short v1; empty v2; unsigned short v3; };
struct Us_Sf_Vp { unsigned short v1; empty v2; void * v3; };
struct Us_Uc_Sf { unsigned short v1; unsigned char v2; empty v3; };
struct Us_Ui_Sf { unsigned short v1; unsigned int v2; empty v3; };
struct Us_Ul_Sf { unsigned short v1; unsigned long long v2; empty v3; };
struct Us_Us_Sf { unsigned short v1; unsigned short v2; empty v3; };
struct Us_Vp_Sf { unsigned short v1; void * v2; empty v3; };
struct Vp_BFu15i_Sf { void * v1; unsigned int v2:15; empty v3; };
struct Vp_BFu15ll_Sf { void * v1; unsigned long long v2:15; empty v3; };
struct Vp_BFu15s_Sf { void * v1; unsigned short v2:15; empty v3; };
struct Vp_BFu16i_Sf { void * v1; unsigned int v2:16; empty v3; };
struct Vp_BFu16ll_Sf { void * v1; unsigned long long v2:16; empty v3; };
struct Vp_BFu16s_Sf { void * v1; unsigned short v2:16; empty v3; };
struct Vp_BFu17i_Sf { void * v1; unsigned int v2:17; empty v3; };
struct Vp_BFu17ll_Sf { void * v1; unsigned long long v2:17; empty v3; };
struct Vp_BFu1c_Sf { void * v1; unsigned char v2:1; empty v3; };
struct Vp_BFu1i_Sf { void * v1; unsigned int v2:1; empty v3; };
struct Vp_BFu1ll_Sf { void * v1; unsigned long long v2:1; empty v3; };
struct Vp_BFu1s_Sf { void * v1; unsigned short v2:1; empty v3; };
struct Vp_BFu31i_Sf { void * v1; unsigned int v2:31; empty v3; };
struct Vp_BFu31ll_Sf { void * v1; unsigned long long v2:31; empty v3; };
struct Vp_BFu32i_Sf { void * v1; unsigned int v2:32; empty v3; };
struct Vp_BFu32ll_Sf { void * v1; unsigned long long v2:32; empty v3; };
struct Vp_BFu33_Sf { void * v1; unsigned long long v2:33; empty v3; };
struct Vp_BFu7c_Sf { void * v1; unsigned char v2:7; empty v3; };
struct Vp_BFu7i_Sf { void * v1; unsigned int v2:7; empty v3; };
struct Vp_BFu7ll_Sf { void * v1; unsigned long long v2:7; empty v3; };
struct Vp_BFu7s_Sf { void * v1; unsigned short v2:7; empty v3; };
struct Vp_BFu8c_Sf { void * v1; unsigned char v2:8; empty v3; };
struct Vp_BFu8i_Sf { void * v1; unsigned int v2:8; empty v3; };
struct Vp_BFu8ll_Sf { void * v1; unsigned long long v2:8; empty v3; };
struct Vp_BFu8s_Sf { void * v1; unsigned short v2:8; empty v3; };
struct Vp_BFu9i_Sf { void * v1; unsigned int v2:9; empty v3; };
struct Vp_BFu9ll_Sf { void * v1; unsigned long long v2:9; empty v3; };
struct Vp_BFu9s_Sf { void * v1; unsigned short v2:9; empty v3; };
struct Vp_C_Sf { void * v1; char v2; empty v3; };
struct Vp_D_Sf { void * v1; double v2; empty v3; };
struct Vp_F_Sf { void * v1; float v2; empty v3; };
struct Vp_I_Sf { void * v1; int v2; empty v3; };
struct Vp_Ip_Sf { void * v1; int * v2; empty v3; };
struct Vp_L_Sf { void * v1; long long v2; empty v3; };
struct Vp_S_Sf { void * v1; short v2; empty v3; };
struct Vp_Sf { void * v1; empty v2; };
struct Vp_Sf_BFu15i { void * v1; empty v2; unsigned int v3:15; };
struct Vp_Sf_BFu15ll { void * v1; empty v2; unsigned long long v3:15; };
struct Vp_Sf_BFu15s { void * v1; empty v2; unsigned short v3:15; };
struct Vp_Sf_BFu16i { void * v1; empty v2; unsigned int v3:16; };
struct Vp_Sf_BFu16ll { void * v1; empty v2; unsigned long long v3:16; };
struct Vp_Sf_BFu16s { void * v1; empty v2; unsigned short v3:16; };
struct Vp_Sf_BFu17i { void * v1; empty v2; unsigned int v3:17; };
struct Vp_Sf_BFu17ll { void * v1; empty v2; unsigned long long v3:17; };
struct Vp_Sf_BFu1c { void * v1; empty v2; unsigned char v3:1; };
struct Vp_Sf_BFu1i { void * v1; empty v2; unsigned int v3:1; };
struct Vp_Sf_BFu1ll { void * v1; empty v2; unsigned long long v3:1; };
struct Vp_Sf_BFu1s { void * v1; empty v2; unsigned short v3:1; };
struct Vp_Sf_BFu31i { void * v1; empty v2; unsigned int v3:31; };
struct Vp_Sf_BFu31ll { void * v1; empty v2; unsigned long long v3:31; };
struct Vp_Sf_BFu32i { void * v1; empty v2; unsigned int v3:32; };
struct Vp_Sf_BFu32ll { void * v1; empty v2; unsigned long long v3:32; };
struct Vp_Sf_BFu33 { void * v1; empty v2; unsigned long long v3:33; };
struct Vp_Sf_BFu7c { void * v1; empty v2; unsigned char v3:7; };
struct Vp_Sf_BFu7i { void * v1; empty v2; unsigned int v3:7; };
struct Vp_Sf_BFu7ll { void * v1; empty v2; unsigned long long v3:7; };
struct Vp_Sf_BFu7s { void * v1; empty v2; unsigned short v3:7; };
struct Vp_Sf_BFu8c { void * v1; empty v2; unsigned char v3:8; };
struct Vp_Sf_BFu8i { void * v1; empty v2; unsigned int v3:8; };
struct Vp_Sf_BFu8ll { void * v1; empty v2; unsigned long long v3:8; };
struct Vp_Sf_BFu8s { void * v1; empty v2; unsigned short v3:8; };
struct Vp_Sf_BFu9i { void * v1; empty v2; unsigned int v3:9; };
struct Vp_Sf_BFu9ll { void * v1; empty v2; unsigned long long v3:9; };
struct Vp_Sf_BFu9s { void * v1; empty v2; unsigned short v3:9; };
struct Vp_Sf_C { void * v1; empty v2; char v3; };
struct Vp_Sf_D { void * v1; empty v2; double v3; };
struct Vp_Sf_F { void * v1; empty v2; float v3; };
struct Vp_Sf_I { void * v1; empty v2; int v3; };
struct Vp_Sf_Ip { void * v1; empty v2; int * v3; };
struct Vp_Sf_L { void * v1; empty v2; long long v3; };
struct Vp_Sf_S { void * v1; empty v2; short v3; };
struct Vp_Sf_Sf { void * v1; empty v2; empty v3; };
struct Vp_Sf_Uc { void * v1; empty v2; unsigned char v3; };
struct Vp_Sf_Ui { void * v1; empty v2; unsigned int v3; };
struct Vp_Sf_Ul { void * v1; empty v2; unsigned long long v3; };
struct Vp_Sf_Us { void * v1; empty v2; unsigned short v3; };
struct Vp_Sf_Vp { void * v1; empty v2; void * v3; };
struct Vp_Uc_Sf { void * v1; unsigned char v2; empty v3; };
struct Vp_Ui_Sf { void * v1; unsigned int v2; empty v3; };
struct Vp_Ul_Sf { void * v1; unsigned long long v2; empty v3; };
struct Vp_Us_Sf { void * v1; unsigned short v2; empty v3; };
struct Vp_Vp_Sf { void * v1; void * v2; empty v3; };


static void Test_empty()
{
  {
    init_simple_test("empty");
    STRUCT_IF_C empty lv;
    check2(sizeof(lv), 0, "sizeof(empty)");
    check2(__alignof__(lv), 1, "__alignof__(empty)");
  }
}
ARRANGE_TO_CALL_ME(Test_empty, empty)
//============================================================================



static void Test_Sf_BFu9ll_L()
{
  {
    init_simple_test("Sf_BFu9ll_L");
    static STRUCT_IF_C Sf_BFu9ll_L lv;
    check2(sizeof(lv), 10, "sizeof(Sf_BFu9ll_L)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9ll_L)");
    check_field_offset(lv, v1, 0, "Sf_BFu9ll_L.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9ll_L");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9ll_L");
    check_field_offset(lv, v3, 2, "Sf_BFu9ll_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9ll_L, Sf_BFu9ll_L)
//============================================================================



static void Test_Sf_BFu9ll_S()
{
  {
    init_simple_test("Sf_BFu9ll_S");
    static STRUCT_IF_C Sf_BFu9ll_S lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu9ll_S)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9ll_S)");
    check_field_offset(lv, v1, 0, "Sf_BFu9ll_S.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9ll_S");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9ll_S");
    check_field_offset(lv, v3, 2, "Sf_BFu9ll_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9ll_S, Sf_BFu9ll_S)
//============================================================================



static void Test_Sf_BFu9ll_Sf()
{
  {
    init_simple_test("Sf_BFu9ll_Sf");
    static STRUCT_IF_C Sf_BFu9ll_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu9ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9ll_Sf)");
    check_field_offset(lv, v1, 0, "Sf_BFu9ll_Sf.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9ll_Sf");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9ll_Sf");
    check_field_offset(lv, v3, 2, "Sf_BFu9ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9ll_Sf, Sf_BFu9ll_Sf)
//============================================================================



static void Test_Sf_BFu9ll_Uc()
{
  {
    init_simple_test("Sf_BFu9ll_Uc");
    static STRUCT_IF_C Sf_BFu9ll_Uc lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu9ll_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9ll_Uc)");
    check_field_offset(lv, v1, 0, "Sf_BFu9ll_Uc.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9ll_Uc");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9ll_Uc");
    check_field_offset(lv, v3, 2, "Sf_BFu9ll_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9ll_Uc, Sf_BFu9ll_Uc)
//============================================================================



static void Test_Sf_BFu9ll_Ui()
{
  {
    init_simple_test("Sf_BFu9ll_Ui");
    static STRUCT_IF_C Sf_BFu9ll_Ui lv;
    check2(sizeof(lv), 6, "sizeof(Sf_BFu9ll_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9ll_Ui)");
    check_field_offset(lv, v1, 0, "Sf_BFu9ll_Ui.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9ll_Ui");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9ll_Ui");
    check_field_offset(lv, v3, 2, "Sf_BFu9ll_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9ll_Ui, Sf_BFu9ll_Ui)
//============================================================================



static void Test_Sf_BFu9ll_Ul()
{
  {
    init_simple_test("Sf_BFu9ll_Ul");
    static STRUCT_IF_C Sf_BFu9ll_Ul lv;
    check2(sizeof(lv), 10, "sizeof(Sf_BFu9ll_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9ll_Ul)");
    check_field_offset(lv, v1, 0, "Sf_BFu9ll_Ul.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9ll_Ul");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9ll_Ul");
    check_field_offset(lv, v3, 2, "Sf_BFu9ll_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9ll_Ul, Sf_BFu9ll_Ul)
//============================================================================



static void Test_Sf_BFu9ll_Us()
{
  {
    init_simple_test("Sf_BFu9ll_Us");
    static STRUCT_IF_C Sf_BFu9ll_Us lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu9ll_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9ll_Us)");
    check_field_offset(lv, v1, 0, "Sf_BFu9ll_Us.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9ll_Us");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9ll_Us");
    check_field_offset(lv, v3, 2, "Sf_BFu9ll_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9ll_Us, Sf_BFu9ll_Us)
//============================================================================



static void Test_Sf_BFu9ll_Vp()
{
  {
    init_simple_test("Sf_BFu9ll_Vp");
    static STRUCT_IF_C Sf_BFu9ll_Vp lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_BFu9ll_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9ll_Vp)");
    check_field_offset(lv, v1, 0, "Sf_BFu9ll_Vp.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9ll_Vp");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9ll_Vp");
    check_field_offset(lv, v3, 2, "Sf_BFu9ll_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9ll_Vp, Sf_BFu9ll_Vp)
//============================================================================



static void Test_Sf_BFu9s()
{
  {
    init_simple_test("Sf_BFu9s");
    static STRUCT_IF_C Sf_BFu9s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s, Sf_BFu9s)
//============================================================================



static void Test_Sf_BFu9s_BFu15i()
{
  {
    init_simple_test("Sf_BFu9s_BFu15i");
    static STRUCT_IF_C Sf_BFu9s_BFu15i lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu9s_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu15i)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu15i.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu15i");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu15i");
    set_bf_and_test(lv, v3, 1, 1, 15, 1, "Sf_BFu9s_BFu15i");
    set_bf_and_test(lv, v3, 1, 1, 15, hide_ull(1LL<<14), "Sf_BFu9s_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu15i, Sf_BFu9s_BFu15i)
//============================================================================



static void Test_Sf_BFu9s_BFu15ll()
{
  {
    init_simple_test("Sf_BFu9s_BFu15ll");
    static STRUCT_IF_C Sf_BFu9s_BFu15ll lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu9s_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu15ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu15ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu15ll");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu15ll");
    set_bf_and_test(lv, v3, 1, 1, 15, 1, "Sf_BFu9s_BFu15ll");
    set_bf_and_test(lv, v3, 1, 1, 15, hide_ull(1LL<<14), "Sf_BFu9s_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu15ll, Sf_BFu9s_BFu15ll)
//============================================================================



static void Test_Sf_BFu9s_BFu15s()
{
  {
    init_simple_test("Sf_BFu9s_BFu15s");
    static STRUCT_IF_C Sf_BFu9s_BFu15s lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu9s_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu15s)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu15s.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu15s");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu15s");
    set_bf_and_test(lv, v3, 1, 1, 15, 1, "Sf_BFu9s_BFu15s");
    set_bf_and_test(lv, v3, 1, 1, 15, hide_ull(1LL<<14), "Sf_BFu9s_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu15s, Sf_BFu9s_BFu15s)
//============================================================================



static void Test_Sf_BFu9s_BFu16i()
{
  {
    init_simple_test("Sf_BFu9s_BFu16i");
    static STRUCT_IF_C Sf_BFu9s_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu9s_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu16i)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu16i.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu16i");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu16i");
    set_bf_and_test(lv, v3, 1, 1, 16, 1, "Sf_BFu9s_BFu16i");
    set_bf_and_test(lv, v3, 1, 1, 16, hide_ull(1LL<<15), "Sf_BFu9s_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu16i, Sf_BFu9s_BFu16i)
//============================================================================



static void Test_Sf_BFu9s_BFu16ll()
{
  {
    init_simple_test("Sf_BFu9s_BFu16ll");
    static STRUCT_IF_C Sf_BFu9s_BFu16ll lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu9s_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu16ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu16ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu16ll");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu16ll");
    set_bf_and_test(lv, v3, 1, 1, 16, 1, "Sf_BFu9s_BFu16ll");
    set_bf_and_test(lv, v3, 1, 1, 16, hide_ull(1LL<<15), "Sf_BFu9s_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu16ll, Sf_BFu9s_BFu16ll)
//============================================================================



static void Test_Sf_BFu9s_BFu16s()
{
  {
    init_simple_test("Sf_BFu9s_BFu16s");
    static STRUCT_IF_C Sf_BFu9s_BFu16s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu9s_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu16s)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu16s.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu16s");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu16s");
    set_bf_and_test(lv, v3, 1, 1, 16, 1, "Sf_BFu9s_BFu16s");
    set_bf_and_test(lv, v3, 1, 1, 16, hide_ull(1LL<<15), "Sf_BFu9s_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu16s, Sf_BFu9s_BFu16s)
//============================================================================



static void Test_Sf_BFu9s_BFu17i()
{
  {
    init_simple_test("Sf_BFu9s_BFu17i");
    static STRUCT_IF_C Sf_BFu9s_BFu17i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu9s_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu17i)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu17i.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu17i");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu17i");
    set_bf_and_test(lv, v3, 1, 1, 17, 1, "Sf_BFu9s_BFu17i");
    set_bf_and_test(lv, v3, 1, 1, 17, hide_ull(1LL<<16), "Sf_BFu9s_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu17i, Sf_BFu9s_BFu17i)
//============================================================================



static void Test_Sf_BFu9s_BFu17ll()
{
  {
    init_simple_test("Sf_BFu9s_BFu17ll");
    static STRUCT_IF_C Sf_BFu9s_BFu17ll lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu9s_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu17ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu17ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu17ll");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu17ll");
    set_bf_and_test(lv, v3, 1, 1, 17, 1, "Sf_BFu9s_BFu17ll");
    set_bf_and_test(lv, v3, 1, 1, 17, hide_ull(1LL<<16), "Sf_BFu9s_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu17ll, Sf_BFu9s_BFu17ll)
//============================================================================



static void Test_Sf_BFu9s_BFu1c()
{
  {
    init_simple_test("Sf_BFu9s_BFu1c");
    static STRUCT_IF_C Sf_BFu9s_BFu1c lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu9s_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu1c)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu1c.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu1c");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu1c");
    set_bf_and_test(lv, v3, 1, 1, 1, 1, "Sf_BFu9s_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu1c, Sf_BFu9s_BFu1c)
//============================================================================



static void Test_Sf_BFu9s_BFu1i()
{
  {
    init_simple_test("Sf_BFu9s_BFu1i");
    static STRUCT_IF_C Sf_BFu9s_BFu1i lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu9s_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu1i)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu1i.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu1i");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu1i");
    set_bf_and_test(lv, v3, 1, 1, 1, 1, "Sf_BFu9s_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu1i, Sf_BFu9s_BFu1i)
//============================================================================



static void Test_Sf_BFu9s_BFu1ll()
{
  {
    init_simple_test("Sf_BFu9s_BFu1ll");
    static STRUCT_IF_C Sf_BFu9s_BFu1ll lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu9s_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu1ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu1ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu1ll");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu1ll");
    set_bf_and_test(lv, v3, 1, 1, 1, 1, "Sf_BFu9s_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu1ll, Sf_BFu9s_BFu1ll)
//============================================================================



static void Test_Sf_BFu9s_BFu1s()
{
  {
    init_simple_test("Sf_BFu9s_BFu1s");
    static STRUCT_IF_C Sf_BFu9s_BFu1s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu9s_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu1s)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu1s.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu1s");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu1s");
    set_bf_and_test(lv, v3, 1, 1, 1, 1, "Sf_BFu9s_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu1s, Sf_BFu9s_BFu1s)
//============================================================================



static void Test_Sf_BFu9s_BFu31i()
{
  {
    init_simple_test("Sf_BFu9s_BFu31i");
    static STRUCT_IF_C Sf_BFu9s_BFu31i lv;
    check2(sizeof(lv), 5, "sizeof(Sf_BFu9s_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu31i)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu31i.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu31i");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu31i");
    set_bf_and_test(lv, v3, 1, 1, 31, 1, "Sf_BFu9s_BFu31i");
    set_bf_and_test(lv, v3, 1, 1, 31, hide_ull(1LL<<30), "Sf_BFu9s_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu31i, Sf_BFu9s_BFu31i)
//============================================================================



static void Test_Sf_BFu9s_BFu31ll()
{
  {
    init_simple_test("Sf_BFu9s_BFu31ll");
    static STRUCT_IF_C Sf_BFu9s_BFu31ll lv;
    check2(sizeof(lv), 5, "sizeof(Sf_BFu9s_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu31ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu31ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu31ll");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu31ll");
    set_bf_and_test(lv, v3, 1, 1, 31, 1, "Sf_BFu9s_BFu31ll");
    set_bf_and_test(lv, v3, 1, 1, 31, hide_ull(1LL<<30), "Sf_BFu9s_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu31ll, Sf_BFu9s_BFu31ll)
//============================================================================



static void Test_Sf_BFu9s_BFu32i()
{
  {
    init_simple_test("Sf_BFu9s_BFu32i");
    static STRUCT_IF_C Sf_BFu9s_BFu32i lv;
    check2(sizeof(lv), 6, "sizeof(Sf_BFu9s_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu32i)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu32i.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu32i");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu32i");
    set_bf_and_test(lv, v3, 1, 1, 32, 1, "Sf_BFu9s_BFu32i");
    set_bf_and_test(lv, v3, 1, 1, 32, hide_ull(1LL<<31), "Sf_BFu9s_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu32i, Sf_BFu9s_BFu32i)
//============================================================================



static void Test_Sf_BFu9s_BFu32ll()
{
  {
    init_simple_test("Sf_BFu9s_BFu32ll");
    static STRUCT_IF_C Sf_BFu9s_BFu32ll lv;
    check2(sizeof(lv), 6, "sizeof(Sf_BFu9s_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu32ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu32ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu32ll");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu32ll");
    set_bf_and_test(lv, v3, 1, 1, 32, 1, "Sf_BFu9s_BFu32ll");
    set_bf_and_test(lv, v3, 1, 1, 32, hide_ull(1LL<<31), "Sf_BFu9s_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu32ll, Sf_BFu9s_BFu32ll)
//============================================================================



static void Test_Sf_BFu9s_BFu33()
{
  {
    init_simple_test("Sf_BFu9s_BFu33");
    static STRUCT_IF_C Sf_BFu9s_BFu33 lv;
    check2(sizeof(lv), 6, "sizeof(Sf_BFu9s_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu33)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu33.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu33");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu33");
    set_bf_and_test(lv, v3, 1, 1, 33, 1, "Sf_BFu9s_BFu33");
    set_bf_and_test(lv, v3, 1, 1, 33, hide_ull(1LL<<32), "Sf_BFu9s_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu33, Sf_BFu9s_BFu33)
//============================================================================



static void Test_Sf_BFu9s_BFu7c()
{
  {
    init_simple_test("Sf_BFu9s_BFu7c");
    static STRUCT_IF_C Sf_BFu9s_BFu7c lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu9s_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu7c)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu7c.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu7c");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu7c");
    set_bf_and_test(lv, v3, 1, 1, 7, 1, "Sf_BFu9s_BFu7c");
    set_bf_and_test(lv, v3, 1, 1, 7, hide_ull(1LL<<6), "Sf_BFu9s_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu7c, Sf_BFu9s_BFu7c)
//============================================================================



static void Test_Sf_BFu9s_BFu7i()
{
  {
    init_simple_test("Sf_BFu9s_BFu7i");
    static STRUCT_IF_C Sf_BFu9s_BFu7i lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu9s_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu7i)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu7i.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu7i");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu7i");
    set_bf_and_test(lv, v3, 1, 1, 7, 1, "Sf_BFu9s_BFu7i");
    set_bf_and_test(lv, v3, 1, 1, 7, hide_ull(1LL<<6), "Sf_BFu9s_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu7i, Sf_BFu9s_BFu7i)
//============================================================================



static void Test_Sf_BFu9s_BFu7ll()
{
  {
    init_simple_test("Sf_BFu9s_BFu7ll");
    static STRUCT_IF_C Sf_BFu9s_BFu7ll lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu9s_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu7ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu7ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu7ll");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu7ll");
    set_bf_and_test(lv, v3, 1, 1, 7, 1, "Sf_BFu9s_BFu7ll");
    set_bf_and_test(lv, v3, 1, 1, 7, hide_ull(1LL<<6), "Sf_BFu9s_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu7ll, Sf_BFu9s_BFu7ll)
//============================================================================



static void Test_Sf_BFu9s_BFu7s()
{
  {
    init_simple_test("Sf_BFu9s_BFu7s");
    static STRUCT_IF_C Sf_BFu9s_BFu7s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu9s_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu7s)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu7s.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu7s");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu7s");
    set_bf_and_test(lv, v3, 1, 1, 7, 1, "Sf_BFu9s_BFu7s");
    set_bf_and_test(lv, v3, 1, 1, 7, hide_ull(1LL<<6), "Sf_BFu9s_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu7s, Sf_BFu9s_BFu7s)
//============================================================================



static void Test_Sf_BFu9s_BFu8c()
{
  {
    init_simple_test("Sf_BFu9s_BFu8c");
    static STRUCT_IF_C Sf_BFu9s_BFu8c lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu9s_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu8c)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu8c.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu8c");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu8c");
    set_bf_and_test(lv, v3, 1, 1, 8, 1, "Sf_BFu9s_BFu8c");
    set_bf_and_test(lv, v3, 1, 1, 8, hide_ull(1LL<<7), "Sf_BFu9s_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu8c, Sf_BFu9s_BFu8c)
//============================================================================



static void Test_Sf_BFu9s_BFu8i()
{
  {
    init_simple_test("Sf_BFu9s_BFu8i");
    static STRUCT_IF_C Sf_BFu9s_BFu8i lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu9s_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu8i)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu8i.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu8i");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu8i");
    set_bf_and_test(lv, v3, 1, 1, 8, 1, "Sf_BFu9s_BFu8i");
    set_bf_and_test(lv, v3, 1, 1, 8, hide_ull(1LL<<7), "Sf_BFu9s_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu8i, Sf_BFu9s_BFu8i)
//============================================================================



static void Test_Sf_BFu9s_BFu8ll()
{
  {
    init_simple_test("Sf_BFu9s_BFu8ll");
    static STRUCT_IF_C Sf_BFu9s_BFu8ll lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu9s_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu8ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu8ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu8ll");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu8ll");
    set_bf_and_test(lv, v3, 1, 1, 8, 1, "Sf_BFu9s_BFu8ll");
    set_bf_and_test(lv, v3, 1, 1, 8, hide_ull(1LL<<7), "Sf_BFu9s_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu8ll, Sf_BFu9s_BFu8ll)
//============================================================================



static void Test_Sf_BFu9s_BFu8s()
{
  {
    init_simple_test("Sf_BFu9s_BFu8s");
    static STRUCT_IF_C Sf_BFu9s_BFu8s lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu9s_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu8s)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu8s.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu8s");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu8s");
    set_bf_and_test(lv, v3, 1, 1, 8, 1, "Sf_BFu9s_BFu8s");
    set_bf_and_test(lv, v3, 1, 1, 8, hide_ull(1LL<<7), "Sf_BFu9s_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu8s, Sf_BFu9s_BFu8s)
//============================================================================



static void Test_Sf_BFu9s_BFu9i()
{
  {
    init_simple_test("Sf_BFu9s_BFu9i");
    static STRUCT_IF_C Sf_BFu9s_BFu9i lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu9s_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu9i)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu9i.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu9i");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu9i");
    set_bf_and_test(lv, v3, 1, 1, 9, 1, "Sf_BFu9s_BFu9i");
    set_bf_and_test(lv, v3, 1, 1, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu9i, Sf_BFu9s_BFu9i)
//============================================================================



static void Test_Sf_BFu9s_BFu9ll()
{
  {
    init_simple_test("Sf_BFu9s_BFu9ll");
    static STRUCT_IF_C Sf_BFu9s_BFu9ll lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu9s_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu9ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu9ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu9ll");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu9ll");
    set_bf_and_test(lv, v3, 1, 1, 9, 1, "Sf_BFu9s_BFu9ll");
    set_bf_and_test(lv, v3, 1, 1, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu9ll, Sf_BFu9s_BFu9ll)
//============================================================================



static void Test_Sf_BFu9s_BFu9s()
{
  {
    init_simple_test("Sf_BFu9s_BFu9s");
    static STRUCT_IF_C Sf_BFu9s_BFu9s lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu9s_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_BFu9s)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu9s.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu9s");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu9s");
    set_bf_and_test(lv, v3, 1, 1, 9, 1, "Sf_BFu9s_BFu9s");
    set_bf_and_test(lv, v3, 1, 1, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu9s, Sf_BFu9s_BFu9s)
//============================================================================



static void Test_Sf_BFu9s_C()
{
  {
    init_simple_test("Sf_BFu9s_C");
    static STRUCT_IF_C Sf_BFu9s_C lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu9s_C)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_C)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_C.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_C");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_C");
    check_field_offset(lv, v3, 2, "Sf_BFu9s_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_C, Sf_BFu9s_C)
//============================================================================



static void Test_Sf_BFu9s_D()
{
  {
    init_simple_test("Sf_BFu9s_D");
    static STRUCT_IF_C Sf_BFu9s_D lv;
    check2(sizeof(lv), 10, "sizeof(Sf_BFu9s_D)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_D)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_D.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_D");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_D");
    check_field_offset(lv, v3, 2, "Sf_BFu9s_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_D, Sf_BFu9s_D)
//============================================================================



static void Test_Sf_BFu9s_F()
{
  {
    init_simple_test("Sf_BFu9s_F");
    static STRUCT_IF_C Sf_BFu9s_F lv;
    check2(sizeof(lv), 6, "sizeof(Sf_BFu9s_F)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_F)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_F.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_F");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_F");
    check_field_offset(lv, v3, 2, "Sf_BFu9s_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_F, Sf_BFu9s_F)
//============================================================================



static void Test_Sf_BFu9s_I()
{
  {
    init_simple_test("Sf_BFu9s_I");
    static STRUCT_IF_C Sf_BFu9s_I lv;
    check2(sizeof(lv), 6, "sizeof(Sf_BFu9s_I)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_I)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_I.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_I");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_I");
    check_field_offset(lv, v3, 2, "Sf_BFu9s_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_I, Sf_BFu9s_I)
//============================================================================



static void Test_Sf_BFu9s_Ip()
{
  {
    init_simple_test("Sf_BFu9s_Ip");
    static STRUCT_IF_C Sf_BFu9s_Ip lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_BFu9s_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_Ip)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_Ip.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_Ip");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_Ip");
    check_field_offset(lv, v3, 2, "Sf_BFu9s_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_Ip, Sf_BFu9s_Ip)
//============================================================================



static void Test_Sf_BFu9s_L()
{
  {
    init_simple_test("Sf_BFu9s_L");
    static STRUCT_IF_C Sf_BFu9s_L lv;
    check2(sizeof(lv), 10, "sizeof(Sf_BFu9s_L)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_L)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_L.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_L");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_L");
    check_field_offset(lv, v3, 2, "Sf_BFu9s_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_L, Sf_BFu9s_L)
//============================================================================



static void Test_Sf_BFu9s_S()
{
  {
    init_simple_test("Sf_BFu9s_S");
    static STRUCT_IF_C Sf_BFu9s_S lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu9s_S)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_S)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_S.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_S");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_S");
    check_field_offset(lv, v3, 2, "Sf_BFu9s_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_S, Sf_BFu9s_S)
//============================================================================



static void Test_Sf_BFu9s_Sf()
{
  {
    init_simple_test("Sf_BFu9s_Sf");
    static STRUCT_IF_C Sf_BFu9s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu9s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_Sf)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_Sf.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_Sf");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_Sf");
    check_field_offset(lv, v3, 2, "Sf_BFu9s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_Sf, Sf_BFu9s_Sf)
//============================================================================



static void Test_Sf_BFu9s_Uc()
{
  {
    init_simple_test("Sf_BFu9s_Uc");
    static STRUCT_IF_C Sf_BFu9s_Uc lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu9s_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_Uc)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_Uc.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_Uc");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_Uc");
    check_field_offset(lv, v3, 2, "Sf_BFu9s_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_Uc, Sf_BFu9s_Uc)
//============================================================================



static void Test_Sf_BFu9s_Ui()
{
  {
    init_simple_test("Sf_BFu9s_Ui");
    static STRUCT_IF_C Sf_BFu9s_Ui lv;
    check2(sizeof(lv), 6, "sizeof(Sf_BFu9s_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_Ui)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_Ui.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_Ui");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_Ui");
    check_field_offset(lv, v3, 2, "Sf_BFu9s_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_Ui, Sf_BFu9s_Ui)
//============================================================================



static void Test_Sf_BFu9s_Ul()
{
  {
    init_simple_test("Sf_BFu9s_Ul");
    static STRUCT_IF_C Sf_BFu9s_Ul lv;
    check2(sizeof(lv), 10, "sizeof(Sf_BFu9s_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_Ul)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_Ul.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_Ul");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_Ul");
    check_field_offset(lv, v3, 2, "Sf_BFu9s_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_Ul, Sf_BFu9s_Ul)
//============================================================================



static void Test_Sf_BFu9s_Us()
{
  {
    init_simple_test("Sf_BFu9s_Us");
    static STRUCT_IF_C Sf_BFu9s_Us lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu9s_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_Us)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_Us.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_Us");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_Us");
    check_field_offset(lv, v3, 2, "Sf_BFu9s_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_Us, Sf_BFu9s_Us)
//============================================================================



static void Test_Sf_BFu9s_Vp()
{
  {
    init_simple_test("Sf_BFu9s_Vp");
    static STRUCT_IF_C Sf_BFu9s_Vp lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_BFu9s_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_Vp)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_Vp.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_Vp");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_Vp");
    check_field_offset(lv, v3, 2, "Sf_BFu9s_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_Vp, Sf_BFu9s_Vp)
//============================================================================



static void Test_Sf_C()
{
  {
    init_simple_test("Sf_C");
    STRUCT_IF_C Sf_C lv;
    check2(sizeof(lv), 1, "sizeof(Sf_C)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C)");
    check_field_offset(lv, v1, 0, "Sf_C.v1");
    check_field_offset(lv, v2, 0, "Sf_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C, Sf_C)
//============================================================================



static void Test_Sf_C_BFu15i()
{
  {
    init_simple_test("Sf_C_BFu15i");
    static STRUCT_IF_C Sf_C_BFu15i lv;
    check2(sizeof(lv), 3, "sizeof(Sf_C_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu15i)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu15i.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu15i.v2");
    set_bf_and_test(lv, v3, 1, 0, 15, 1, "Sf_C_BFu15i");
    set_bf_and_test(lv, v3, 1, 0, 15, hide_ull(1LL<<14), "Sf_C_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu15i, Sf_C_BFu15i)
//============================================================================



static void Test_Sf_C_BFu15ll()
{
  {
    init_simple_test("Sf_C_BFu15ll");
    static STRUCT_IF_C Sf_C_BFu15ll lv;
    check2(sizeof(lv), 3, "sizeof(Sf_C_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu15ll)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu15ll.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu15ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 15, 1, "Sf_C_BFu15ll");
    set_bf_and_test(lv, v3, 1, 0, 15, hide_ull(1LL<<14), "Sf_C_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu15ll, Sf_C_BFu15ll)
//============================================================================



static void Test_Sf_C_BFu15s()
{
  {
    init_simple_test("Sf_C_BFu15s");
    static STRUCT_IF_C Sf_C_BFu15s lv;
    check2(sizeof(lv), 3, "sizeof(Sf_C_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu15s)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu15s.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu15s.v2");
    set_bf_and_test(lv, v3, 1, 0, 15, 1, "Sf_C_BFu15s");
    set_bf_and_test(lv, v3, 1, 0, 15, hide_ull(1LL<<14), "Sf_C_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu15s, Sf_C_BFu15s)
//============================================================================



static void Test_Sf_C_BFu16i()
{
  {
    init_simple_test("Sf_C_BFu16i");
    static STRUCT_IF_C Sf_C_BFu16i lv;
    check2(sizeof(lv), 3, "sizeof(Sf_C_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu16i)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu16i.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu16i.v2");
    set_bf_and_test(lv, v3, 1, 0, 16, 1, "Sf_C_BFu16i");
    set_bf_and_test(lv, v3, 1, 0, 16, hide_ull(1LL<<15), "Sf_C_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu16i, Sf_C_BFu16i)
//============================================================================



static void Test_Sf_C_BFu16ll()
{
  {
    init_simple_test("Sf_C_BFu16ll");
    static STRUCT_IF_C Sf_C_BFu16ll lv;
    check2(sizeof(lv), 3, "sizeof(Sf_C_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu16ll)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu16ll.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu16ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 16, 1, "Sf_C_BFu16ll");
    set_bf_and_test(lv, v3, 1, 0, 16, hide_ull(1LL<<15), "Sf_C_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu16ll, Sf_C_BFu16ll)
//============================================================================



static void Test_Sf_C_BFu16s()
{
  {
    init_simple_test("Sf_C_BFu16s");
    static STRUCT_IF_C Sf_C_BFu16s lv;
    check2(sizeof(lv), 3, "sizeof(Sf_C_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu16s)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu16s.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu16s.v2");
    set_bf_and_test(lv, v3, 1, 0, 16, 1, "Sf_C_BFu16s");
    set_bf_and_test(lv, v3, 1, 0, 16, hide_ull(1LL<<15), "Sf_C_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu16s, Sf_C_BFu16s)
//============================================================================



static void Test_Sf_C_BFu17i()
{
  {
    init_simple_test("Sf_C_BFu17i");
    static STRUCT_IF_C Sf_C_BFu17i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_C_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu17i)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu17i.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu17i.v2");
    set_bf_and_test(lv, v3, 1, 0, 17, 1, "Sf_C_BFu17i");
    set_bf_and_test(lv, v3, 1, 0, 17, hide_ull(1LL<<16), "Sf_C_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu17i, Sf_C_BFu17i)
//============================================================================



static void Test_Sf_C_BFu17ll()
{
  {
    init_simple_test("Sf_C_BFu17ll");
    static STRUCT_IF_C Sf_C_BFu17ll lv;
    check2(sizeof(lv), 4, "sizeof(Sf_C_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu17ll)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu17ll.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu17ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 17, 1, "Sf_C_BFu17ll");
    set_bf_and_test(lv, v3, 1, 0, 17, hide_ull(1LL<<16), "Sf_C_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu17ll, Sf_C_BFu17ll)
//============================================================================



static void Test_Sf_C_BFu1c()
{
  {
    init_simple_test("Sf_C_BFu1c");
    static STRUCT_IF_C Sf_C_BFu1c lv;
    check2(sizeof(lv), 2, "sizeof(Sf_C_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu1c)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu1c.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu1c.v2");
    set_bf_and_test(lv, v3, 1, 0, 1, 1, "Sf_C_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu1c, Sf_C_BFu1c)
//============================================================================



static void Test_Sf_C_BFu1i()
{
  {
    init_simple_test("Sf_C_BFu1i");
    static STRUCT_IF_C Sf_C_BFu1i lv;
    check2(sizeof(lv), 2, "sizeof(Sf_C_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu1i)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu1i.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu1i.v2");
    set_bf_and_test(lv, v3, 1, 0, 1, 1, "Sf_C_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu1i, Sf_C_BFu1i)
//============================================================================



static void Test_Sf_C_BFu1ll()
{
  {
    init_simple_test("Sf_C_BFu1ll");
    static STRUCT_IF_C Sf_C_BFu1ll lv;
    check2(sizeof(lv), 2, "sizeof(Sf_C_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu1ll)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu1ll.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu1ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 1, 1, "Sf_C_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu1ll, Sf_C_BFu1ll)
//============================================================================



static void Test_Sf_C_BFu1s()
{
  {
    init_simple_test("Sf_C_BFu1s");
    static STRUCT_IF_C Sf_C_BFu1s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_C_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu1s)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu1s.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu1s.v2");
    set_bf_and_test(lv, v3, 1, 0, 1, 1, "Sf_C_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu1s, Sf_C_BFu1s)
//============================================================================



static void Test_Sf_C_BFu31i()
{
  {
    init_simple_test("Sf_C_BFu31i");
    static STRUCT_IF_C Sf_C_BFu31i lv;
    check2(sizeof(lv), 5, "sizeof(Sf_C_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu31i)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu31i.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu31i.v2");
    set_bf_and_test(lv, v3, 1, 0, 31, 1, "Sf_C_BFu31i");
    set_bf_and_test(lv, v3, 1, 0, 31, hide_ull(1LL<<30), "Sf_C_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu31i, Sf_C_BFu31i)
//============================================================================



static void Test_Sf_C_BFu31ll()
{
  {
    init_simple_test("Sf_C_BFu31ll");
    static STRUCT_IF_C Sf_C_BFu31ll lv;
    check2(sizeof(lv), 5, "sizeof(Sf_C_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu31ll)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu31ll.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu31ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 31, 1, "Sf_C_BFu31ll");
    set_bf_and_test(lv, v3, 1, 0, 31, hide_ull(1LL<<30), "Sf_C_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu31ll, Sf_C_BFu31ll)
//============================================================================



static void Test_Sf_C_BFu32i()
{
  {
    init_simple_test("Sf_C_BFu32i");
    static STRUCT_IF_C Sf_C_BFu32i lv;
    check2(sizeof(lv), 5, "sizeof(Sf_C_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu32i)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu32i.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu32i.v2");
    set_bf_and_test(lv, v3, 1, 0, 32, 1, "Sf_C_BFu32i");
    set_bf_and_test(lv, v3, 1, 0, 32, hide_ull(1LL<<31), "Sf_C_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu32i, Sf_C_BFu32i)
//============================================================================



static void Test_Sf_C_BFu32ll()
{
  {
    init_simple_test("Sf_C_BFu32ll");
    static STRUCT_IF_C Sf_C_BFu32ll lv;
    check2(sizeof(lv), 5, "sizeof(Sf_C_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu32ll)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu32ll.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu32ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 32, 1, "Sf_C_BFu32ll");
    set_bf_and_test(lv, v3, 1, 0, 32, hide_ull(1LL<<31), "Sf_C_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu32ll, Sf_C_BFu32ll)
//============================================================================



static void Test_Sf_C_BFu33()
{
  {
    init_simple_test("Sf_C_BFu33");
    static STRUCT_IF_C Sf_C_BFu33 lv;
    check2(sizeof(lv), 6, "sizeof(Sf_C_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu33)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu33.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu33.v2");
    set_bf_and_test(lv, v3, 1, 0, 33, 1, "Sf_C_BFu33");
    set_bf_and_test(lv, v3, 1, 0, 33, hide_ull(1LL<<32), "Sf_C_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu33, Sf_C_BFu33)
//============================================================================



static void Test_Sf_C_BFu7c()
{
  {
    init_simple_test("Sf_C_BFu7c");
    static STRUCT_IF_C Sf_C_BFu7c lv;
    check2(sizeof(lv), 2, "sizeof(Sf_C_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu7c)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu7c.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu7c.v2");
    set_bf_and_test(lv, v3, 1, 0, 7, 1, "Sf_C_BFu7c");
    set_bf_and_test(lv, v3, 1, 0, 7, hide_ull(1LL<<6), "Sf_C_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu7c, Sf_C_BFu7c)
//============================================================================



static void Test_Sf_C_BFu7i()
{
  {
    init_simple_test("Sf_C_BFu7i");
    static STRUCT_IF_C Sf_C_BFu7i lv;
    check2(sizeof(lv), 2, "sizeof(Sf_C_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu7i)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu7i.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu7i.v2");
    set_bf_and_test(lv, v3, 1, 0, 7, 1, "Sf_C_BFu7i");
    set_bf_and_test(lv, v3, 1, 0, 7, hide_ull(1LL<<6), "Sf_C_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu7i, Sf_C_BFu7i)
//============================================================================



static void Test_Sf_C_BFu7ll()
{
  {
    init_simple_test("Sf_C_BFu7ll");
    static STRUCT_IF_C Sf_C_BFu7ll lv;
    check2(sizeof(lv), 2, "sizeof(Sf_C_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu7ll)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu7ll.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu7ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 7, 1, "Sf_C_BFu7ll");
    set_bf_and_test(lv, v3, 1, 0, 7, hide_ull(1LL<<6), "Sf_C_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu7ll, Sf_C_BFu7ll)
//============================================================================



static void Test_Sf_C_BFu7s()
{
  {
    init_simple_test("Sf_C_BFu7s");
    static STRUCT_IF_C Sf_C_BFu7s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_C_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu7s)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu7s.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu7s.v2");
    set_bf_and_test(lv, v3, 1, 0, 7, 1, "Sf_C_BFu7s");
    set_bf_and_test(lv, v3, 1, 0, 7, hide_ull(1LL<<6), "Sf_C_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu7s, Sf_C_BFu7s)
//============================================================================



static void Test_Sf_C_BFu8c()
{
  {
    init_simple_test("Sf_C_BFu8c");
    static STRUCT_IF_C Sf_C_BFu8c lv;
    check2(sizeof(lv), 2, "sizeof(Sf_C_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu8c)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu8c.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu8c.v2");
    set_bf_and_test(lv, v3, 1, 0, 8, 1, "Sf_C_BFu8c");
    set_bf_and_test(lv, v3, 1, 0, 8, hide_ull(1LL<<7), "Sf_C_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu8c, Sf_C_BFu8c)
//============================================================================



static void Test_Sf_C_BFu8i()
{
  {
    init_simple_test("Sf_C_BFu8i");
    static STRUCT_IF_C Sf_C_BFu8i lv;
    check2(sizeof(lv), 2, "sizeof(Sf_C_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu8i)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu8i.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu8i.v2");
    set_bf_and_test(lv, v3, 1, 0, 8, 1, "Sf_C_BFu8i");
    set_bf_and_test(lv, v3, 1, 0, 8, hide_ull(1LL<<7), "Sf_C_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu8i, Sf_C_BFu8i)
//============================================================================



static void Test_Sf_C_BFu8ll()
{
  {
    init_simple_test("Sf_C_BFu8ll");
    static STRUCT_IF_C Sf_C_BFu8ll lv;
    check2(sizeof(lv), 2, "sizeof(Sf_C_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu8ll)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu8ll.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu8ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 8, 1, "Sf_C_BFu8ll");
    set_bf_and_test(lv, v3, 1, 0, 8, hide_ull(1LL<<7), "Sf_C_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu8ll, Sf_C_BFu8ll)
//============================================================================



static void Test_Sf_C_BFu8s()
{
  {
    init_simple_test("Sf_C_BFu8s");
    static STRUCT_IF_C Sf_C_BFu8s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_C_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu8s)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu8s.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu8s.v2");
    set_bf_and_test(lv, v3, 1, 0, 8, 1, "Sf_C_BFu8s");
    set_bf_and_test(lv, v3, 1, 0, 8, hide_ull(1LL<<7), "Sf_C_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu8s, Sf_C_BFu8s)
//============================================================================



static void Test_Sf_C_BFu9i()
{
  {
    init_simple_test("Sf_C_BFu9i");
    static STRUCT_IF_C Sf_C_BFu9i lv;
    check2(sizeof(lv), 3, "sizeof(Sf_C_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu9i)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu9i.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu9i.v2");
    set_bf_and_test(lv, v3, 1, 0, 9, 1, "Sf_C_BFu9i");
    set_bf_and_test(lv, v3, 1, 0, 9, hide_ull(1LL<<8), "Sf_C_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu9i, Sf_C_BFu9i)
//============================================================================



static void Test_Sf_C_BFu9ll()
{
  {
    init_simple_test("Sf_C_BFu9ll");
    static STRUCT_IF_C Sf_C_BFu9ll lv;
    check2(sizeof(lv), 3, "sizeof(Sf_C_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu9ll)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu9ll.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu9ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 9, 1, "Sf_C_BFu9ll");
    set_bf_and_test(lv, v3, 1, 0, 9, hide_ull(1LL<<8), "Sf_C_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu9ll, Sf_C_BFu9ll)
//============================================================================



static void Test_Sf_C_BFu9s()
{
  {
    init_simple_test("Sf_C_BFu9s");
    static STRUCT_IF_C Sf_C_BFu9s lv;
    check2(sizeof(lv), 3, "sizeof(Sf_C_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu9s)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu9s.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu9s.v2");
    set_bf_and_test(lv, v3, 1, 0, 9, 1, "Sf_C_BFu9s");
    set_bf_and_test(lv, v3, 1, 0, 9, hide_ull(1LL<<8), "Sf_C_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu9s, Sf_C_BFu9s)
//============================================================================



static void Test_Sf_C_C()
{
  {
    init_simple_test("Sf_C_C");
    STRUCT_IF_C Sf_C_C lv;
    check2(sizeof(lv), 2, "sizeof(Sf_C_C)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_C)");
    check_field_offset(lv, v1, 0, "Sf_C_C.v1");
    check_field_offset(lv, v2, 0, "Sf_C_C.v2");
    check_field_offset(lv, v3, 1, "Sf_C_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_C, Sf_C_C)
//============================================================================



static void Test_Sf_C_D()
{
  {
    init_simple_test("Sf_C_D");
    STRUCT_IF_C Sf_C_D lv;
    check2(sizeof(lv), 9, "sizeof(Sf_C_D)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_D)");
    check_field_offset(lv, v1, 0, "Sf_C_D.v1");
    check_field_offset(lv, v2, 0, "Sf_C_D.v2");
    check_field_offset(lv, v3, 1, "Sf_C_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_D, Sf_C_D)
//============================================================================



static void Test_Sf_C_F()
{
  {
    init_simple_test("Sf_C_F");
    STRUCT_IF_C Sf_C_F lv;
    check2(sizeof(lv), 5, "sizeof(Sf_C_F)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_F)");
    check_field_offset(lv, v1, 0, "Sf_C_F.v1");
    check_field_offset(lv, v2, 0, "Sf_C_F.v2");
    check_field_offset(lv, v3, 1, "Sf_C_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_F, Sf_C_F)
//============================================================================



static void Test_Sf_C_I()
{
  {
    init_simple_test("Sf_C_I");
    STRUCT_IF_C Sf_C_I lv;
    check2(sizeof(lv), 5, "sizeof(Sf_C_I)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_I)");
    check_field_offset(lv, v1, 0, "Sf_C_I.v1");
    check_field_offset(lv, v2, 0, "Sf_C_I.v2");
    check_field_offset(lv, v3, 1, "Sf_C_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_I, Sf_C_I)
//============================================================================



static void Test_Sf_C_Ip()
{
  {
    init_simple_test("Sf_C_Ip");
    STRUCT_IF_C Sf_C_Ip lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_C_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_Ip)");
    check_field_offset(lv, v1, 0, "Sf_C_Ip.v1");
    check_field_offset(lv, v2, 0, "Sf_C_Ip.v2");
    check_field_offset(lv, v3, 1, "Sf_C_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_Ip, Sf_C_Ip)
//============================================================================



static void Test_Sf_C_L()
{
  {
    init_simple_test("Sf_C_L");
    STRUCT_IF_C Sf_C_L lv;
    check2(sizeof(lv), 9, "sizeof(Sf_C_L)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_L)");
    check_field_offset(lv, v1, 0, "Sf_C_L.v1");
    check_field_offset(lv, v2, 0, "Sf_C_L.v2");
    check_field_offset(lv, v3, 1, "Sf_C_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_L, Sf_C_L)
//============================================================================



static void Test_Sf_C_S()
{
  {
    init_simple_test("Sf_C_S");
    STRUCT_IF_C Sf_C_S lv;
    check2(sizeof(lv), 3, "sizeof(Sf_C_S)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_S)");
    check_field_offset(lv, v1, 0, "Sf_C_S.v1");
    check_field_offset(lv, v2, 0, "Sf_C_S.v2");
    check_field_offset(lv, v3, 1, "Sf_C_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_S, Sf_C_S)
//============================================================================



static void Test_Sf_C_Sf()
{
  {
    init_simple_test("Sf_C_Sf");
    STRUCT_IF_C Sf_C_Sf lv;
    check2(sizeof(lv), 1, "sizeof(Sf_C_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_Sf)");
    check_field_offset(lv, v1, 0, "Sf_C_Sf.v1");
    check_field_offset(lv, v2, 0, "Sf_C_Sf.v2");
    check_field_offset(lv, v3, 1, "Sf_C_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_Sf, Sf_C_Sf)
//============================================================================



static void Test_Sf_C_Uc()
{
  {
    init_simple_test("Sf_C_Uc");
    STRUCT_IF_C Sf_C_Uc lv;
    check2(sizeof(lv), 2, "sizeof(Sf_C_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_Uc)");
    check_field_offset(lv, v1, 0, "Sf_C_Uc.v1");
    check_field_offset(lv, v2, 0, "Sf_C_Uc.v2");
    check_field_offset(lv, v3, 1, "Sf_C_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_Uc, Sf_C_Uc)
//============================================================================



static void Test_Sf_C_Ui()
{
  {
    init_simple_test("Sf_C_Ui");
    STRUCT_IF_C Sf_C_Ui lv;
    check2(sizeof(lv), 5, "sizeof(Sf_C_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_Ui)");
    check_field_offset(lv, v1, 0, "Sf_C_Ui.v1");
    check_field_offset(lv, v2, 0, "Sf_C_Ui.v2");
    check_field_offset(lv, v3, 1, "Sf_C_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_Ui, Sf_C_Ui)
//============================================================================



static void Test_Sf_C_Ul()
{
  {
    init_simple_test("Sf_C_Ul");
    STRUCT_IF_C Sf_C_Ul lv;
    check2(sizeof(lv), 9, "sizeof(Sf_C_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_Ul)");
    check_field_offset(lv, v1, 0, "Sf_C_Ul.v1");
    check_field_offset(lv, v2, 0, "Sf_C_Ul.v2");
    check_field_offset(lv, v3, 1, "Sf_C_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_Ul, Sf_C_Ul)
//============================================================================



static void Test_Sf_C_Us()
{
  {
    init_simple_test("Sf_C_Us");
    STRUCT_IF_C Sf_C_Us lv;
    check2(sizeof(lv), 3, "sizeof(Sf_C_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_Us)");
    check_field_offset(lv, v1, 0, "Sf_C_Us.v1");
    check_field_offset(lv, v2, 0, "Sf_C_Us.v2");
    check_field_offset(lv, v3, 1, "Sf_C_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_Us, Sf_C_Us)
//============================================================================



static void Test_Sf_C_Vp()
{
  {
    init_simple_test("Sf_C_Vp");
    STRUCT_IF_C Sf_C_Vp lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_C_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_Vp)");
    check_field_offset(lv, v1, 0, "Sf_C_Vp.v1");
    check_field_offset(lv, v2, 0, "Sf_C_Vp.v2");
    check_field_offset(lv, v3, 1, "Sf_C_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_Vp, Sf_C_Vp)
//============================================================================



static void Test_Sf_D()
{
  {
    init_simple_test("Sf_D");
    STRUCT_IF_C Sf_D lv;
    check2(sizeof(lv), 8, "sizeof(Sf_D)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D)");
    check_field_offset(lv, v1, 0, "Sf_D.v1");
    check_field_offset(lv, v2, 0, "Sf_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D, Sf_D)
//============================================================================



static void Test_Sf_D_BFu15i()
{
  {
    init_simple_test("Sf_D_BFu15i");
    static STRUCT_IF_C Sf_D_BFu15i lv;
    check2(sizeof(lv), 10, "sizeof(Sf_D_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu15i)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu15i.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu15i.v2");
    set_bf_and_test(lv, v3, 8, 0, 15, 1, "Sf_D_BFu15i");
    set_bf_and_test(lv, v3, 8, 0, 15, hide_ull(1LL<<14), "Sf_D_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu15i, Sf_D_BFu15i)
//============================================================================



static void Test_Sf_D_BFu15ll()
{
  {
    init_simple_test("Sf_D_BFu15ll");
    static STRUCT_IF_C Sf_D_BFu15ll lv;
    check2(sizeof(lv), 10, "sizeof(Sf_D_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu15ll)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu15ll.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu15ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 15, 1, "Sf_D_BFu15ll");
    set_bf_and_test(lv, v3, 8, 0, 15, hide_ull(1LL<<14), "Sf_D_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu15ll, Sf_D_BFu15ll)
//============================================================================



static void Test_Sf_D_BFu15s()
{
  {
    init_simple_test("Sf_D_BFu15s");
    static STRUCT_IF_C Sf_D_BFu15s lv;
    check2(sizeof(lv), 10, "sizeof(Sf_D_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu15s)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu15s.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu15s.v2");
    set_bf_and_test(lv, v3, 8, 0, 15, 1, "Sf_D_BFu15s");
    set_bf_and_test(lv, v3, 8, 0, 15, hide_ull(1LL<<14), "Sf_D_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu15s, Sf_D_BFu15s)
//============================================================================



static void Test_Sf_D_BFu16i()
{
  {
    init_simple_test("Sf_D_BFu16i");
    static STRUCT_IF_C Sf_D_BFu16i lv;
    check2(sizeof(lv), 10, "sizeof(Sf_D_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu16i)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu16i.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu16i.v2");
    set_bf_and_test(lv, v3, 8, 0, 16, 1, "Sf_D_BFu16i");
    set_bf_and_test(lv, v3, 8, 0, 16, hide_ull(1LL<<15), "Sf_D_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu16i, Sf_D_BFu16i)
//============================================================================



static void Test_Sf_D_BFu16ll()
{
  {
    init_simple_test("Sf_D_BFu16ll");
    static STRUCT_IF_C Sf_D_BFu16ll lv;
    check2(sizeof(lv), 10, "sizeof(Sf_D_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu16ll)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu16ll.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu16ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 16, 1, "Sf_D_BFu16ll");
    set_bf_and_test(lv, v3, 8, 0, 16, hide_ull(1LL<<15), "Sf_D_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu16ll, Sf_D_BFu16ll)
//============================================================================



static void Test_Sf_D_BFu16s()
{
  {
    init_simple_test("Sf_D_BFu16s");
    static STRUCT_IF_C Sf_D_BFu16s lv;
    check2(sizeof(lv), 10, "sizeof(Sf_D_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu16s)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu16s.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu16s.v2");
    set_bf_and_test(lv, v3, 8, 0, 16, 1, "Sf_D_BFu16s");
    set_bf_and_test(lv, v3, 8, 0, 16, hide_ull(1LL<<15), "Sf_D_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu16s, Sf_D_BFu16s)
//============================================================================



static void Test_Sf_D_BFu17i()
{
  {
    init_simple_test("Sf_D_BFu17i");
    static STRUCT_IF_C Sf_D_BFu17i lv;
    check2(sizeof(lv), 11, "sizeof(Sf_D_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu17i)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu17i.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu17i.v2");
    set_bf_and_test(lv, v3, 8, 0, 17, 1, "Sf_D_BFu17i");
    set_bf_and_test(lv, v3, 8, 0, 17, hide_ull(1LL<<16), "Sf_D_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu17i, Sf_D_BFu17i)
//============================================================================



static void Test_Sf_D_BFu17ll()
{
  {
    init_simple_test("Sf_D_BFu17ll");
    static STRUCT_IF_C Sf_D_BFu17ll lv;
    check2(sizeof(lv), 11, "sizeof(Sf_D_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu17ll)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu17ll.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu17ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 17, 1, "Sf_D_BFu17ll");
    set_bf_and_test(lv, v3, 8, 0, 17, hide_ull(1LL<<16), "Sf_D_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu17ll, Sf_D_BFu17ll)
//============================================================================



static void Test_Sf_D_BFu1c()
{
  {
    init_simple_test("Sf_D_BFu1c");
    static STRUCT_IF_C Sf_D_BFu1c lv;
    check2(sizeof(lv), 9, "sizeof(Sf_D_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu1c)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu1c.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu1c.v2");
    set_bf_and_test(lv, v3, 8, 0, 1, 1, "Sf_D_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu1c, Sf_D_BFu1c)
//============================================================================



static void Test_Sf_D_BFu1i()
{
  {
    init_simple_test("Sf_D_BFu1i");
    static STRUCT_IF_C Sf_D_BFu1i lv;
    check2(sizeof(lv), 9, "sizeof(Sf_D_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu1i)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu1i.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu1i.v2");
    set_bf_and_test(lv, v3, 8, 0, 1, 1, "Sf_D_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu1i, Sf_D_BFu1i)
//============================================================================



static void Test_Sf_D_BFu1ll()
{
  {
    init_simple_test("Sf_D_BFu1ll");
    static STRUCT_IF_C Sf_D_BFu1ll lv;
    check2(sizeof(lv), 9, "sizeof(Sf_D_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu1ll)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu1ll.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu1ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 1, 1, "Sf_D_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu1ll, Sf_D_BFu1ll)
//============================================================================



static void Test_Sf_D_BFu1s()
{
  {
    init_simple_test("Sf_D_BFu1s");
    static STRUCT_IF_C Sf_D_BFu1s lv;
    check2(sizeof(lv), 9, "sizeof(Sf_D_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu1s)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu1s.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu1s.v2");
    set_bf_and_test(lv, v3, 8, 0, 1, 1, "Sf_D_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu1s, Sf_D_BFu1s)
//============================================================================



static void Test_Sf_D_BFu31i()
{
  {
    init_simple_test("Sf_D_BFu31i");
    static STRUCT_IF_C Sf_D_BFu31i lv;
    check2(sizeof(lv), 12, "sizeof(Sf_D_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu31i)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu31i.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu31i.v2");
    set_bf_and_test(lv, v3, 8, 0, 31, 1, "Sf_D_BFu31i");
    set_bf_and_test(lv, v3, 8, 0, 31, hide_ull(1LL<<30), "Sf_D_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu31i, Sf_D_BFu31i)
//============================================================================



static void Test_Sf_D_BFu31ll()
{
  {
    init_simple_test("Sf_D_BFu31ll");
    static STRUCT_IF_C Sf_D_BFu31ll lv;
    check2(sizeof(lv), 12, "sizeof(Sf_D_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu31ll)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu31ll.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu31ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 31, 1, "Sf_D_BFu31ll");
    set_bf_and_test(lv, v3, 8, 0, 31, hide_ull(1LL<<30), "Sf_D_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu31ll, Sf_D_BFu31ll)
//============================================================================



static void Test_Sf_D_BFu32i()
{
  {
    init_simple_test("Sf_D_BFu32i");
    static STRUCT_IF_C Sf_D_BFu32i lv;
    check2(sizeof(lv), 12, "sizeof(Sf_D_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu32i)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu32i.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu32i.v2");
    set_bf_and_test(lv, v3, 8, 0, 32, 1, "Sf_D_BFu32i");
    set_bf_and_test(lv, v3, 8, 0, 32, hide_ull(1LL<<31), "Sf_D_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu32i, Sf_D_BFu32i)
//============================================================================



static void Test_Sf_D_BFu32ll()
{
  {
    init_simple_test("Sf_D_BFu32ll");
    static STRUCT_IF_C Sf_D_BFu32ll lv;
    check2(sizeof(lv), 12, "sizeof(Sf_D_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu32ll)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu32ll.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu32ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 32, 1, "Sf_D_BFu32ll");
    set_bf_and_test(lv, v3, 8, 0, 32, hide_ull(1LL<<31), "Sf_D_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu32ll, Sf_D_BFu32ll)
//============================================================================



static void Test_Sf_D_BFu33()
{
  {
    init_simple_test("Sf_D_BFu33");
    static STRUCT_IF_C Sf_D_BFu33 lv;
    check2(sizeof(lv), 13, "sizeof(Sf_D_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu33)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu33.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu33.v2");
    set_bf_and_test(lv, v3, 8, 0, 33, 1, "Sf_D_BFu33");
    set_bf_and_test(lv, v3, 8, 0, 33, hide_ull(1LL<<32), "Sf_D_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu33, Sf_D_BFu33)
//============================================================================



static void Test_Sf_D_BFu7c()
{
  {
    init_simple_test("Sf_D_BFu7c");
    static STRUCT_IF_C Sf_D_BFu7c lv;
    check2(sizeof(lv), 9, "sizeof(Sf_D_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu7c)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu7c.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu7c.v2");
    set_bf_and_test(lv, v3, 8, 0, 7, 1, "Sf_D_BFu7c");
    set_bf_and_test(lv, v3, 8, 0, 7, hide_ull(1LL<<6), "Sf_D_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu7c, Sf_D_BFu7c)
//============================================================================



static void Test_Sf_D_BFu7i()
{
  {
    init_simple_test("Sf_D_BFu7i");
    static STRUCT_IF_C Sf_D_BFu7i lv;
    check2(sizeof(lv), 9, "sizeof(Sf_D_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu7i)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu7i.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu7i.v2");
    set_bf_and_test(lv, v3, 8, 0, 7, 1, "Sf_D_BFu7i");
    set_bf_and_test(lv, v3, 8, 0, 7, hide_ull(1LL<<6), "Sf_D_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu7i, Sf_D_BFu7i)
//============================================================================



static void Test_Sf_D_BFu7ll()
{
  {
    init_simple_test("Sf_D_BFu7ll");
    static STRUCT_IF_C Sf_D_BFu7ll lv;
    check2(sizeof(lv), 9, "sizeof(Sf_D_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu7ll)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu7ll.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu7ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 7, 1, "Sf_D_BFu7ll");
    set_bf_and_test(lv, v3, 8, 0, 7, hide_ull(1LL<<6), "Sf_D_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu7ll, Sf_D_BFu7ll)
//============================================================================



static void Test_Sf_D_BFu7s()
{
  {
    init_simple_test("Sf_D_BFu7s");
    static STRUCT_IF_C Sf_D_BFu7s lv;
    check2(sizeof(lv), 9, "sizeof(Sf_D_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu7s)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu7s.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu7s.v2");
    set_bf_and_test(lv, v3, 8, 0, 7, 1, "Sf_D_BFu7s");
    set_bf_and_test(lv, v3, 8, 0, 7, hide_ull(1LL<<6), "Sf_D_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu7s, Sf_D_BFu7s)
//============================================================================



static void Test_Sf_D_BFu8c()
{
  {
    init_simple_test("Sf_D_BFu8c");
    static STRUCT_IF_C Sf_D_BFu8c lv;
    check2(sizeof(lv), 9, "sizeof(Sf_D_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu8c)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu8c.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu8c.v2");
    set_bf_and_test(lv, v3, 8, 0, 8, 1, "Sf_D_BFu8c");
    set_bf_and_test(lv, v3, 8, 0, 8, hide_ull(1LL<<7), "Sf_D_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu8c, Sf_D_BFu8c)
//============================================================================



static void Test_Sf_D_BFu8i()
{
  {
    init_simple_test("Sf_D_BFu8i");
    static STRUCT_IF_C Sf_D_BFu8i lv;
    check2(sizeof(lv), 9, "sizeof(Sf_D_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu8i)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu8i.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu8i.v2");
    set_bf_and_test(lv, v3, 8, 0, 8, 1, "Sf_D_BFu8i");
    set_bf_and_test(lv, v3, 8, 0, 8, hide_ull(1LL<<7), "Sf_D_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu8i, Sf_D_BFu8i)
//============================================================================



static void Test_Sf_D_BFu8ll()
{
  {
    init_simple_test("Sf_D_BFu8ll");
    static STRUCT_IF_C Sf_D_BFu8ll lv;
    check2(sizeof(lv), 9, "sizeof(Sf_D_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu8ll)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu8ll.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu8ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 8, 1, "Sf_D_BFu8ll");
    set_bf_and_test(lv, v3, 8, 0, 8, hide_ull(1LL<<7), "Sf_D_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu8ll, Sf_D_BFu8ll)
//============================================================================



static void Test_Sf_D_BFu8s()
{
  {
    init_simple_test("Sf_D_BFu8s");
    static STRUCT_IF_C Sf_D_BFu8s lv;
    check2(sizeof(lv), 9, "sizeof(Sf_D_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu8s)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu8s.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu8s.v2");
    set_bf_and_test(lv, v3, 8, 0, 8, 1, "Sf_D_BFu8s");
    set_bf_and_test(lv, v3, 8, 0, 8, hide_ull(1LL<<7), "Sf_D_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu8s, Sf_D_BFu8s)
//============================================================================



static void Test_Sf_D_BFu9i()
{
  {
    init_simple_test("Sf_D_BFu9i");
    static STRUCT_IF_C Sf_D_BFu9i lv;
    check2(sizeof(lv), 10, "sizeof(Sf_D_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu9i)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu9i.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu9i.v2");
    set_bf_and_test(lv, v3, 8, 0, 9, 1, "Sf_D_BFu9i");
    set_bf_and_test(lv, v3, 8, 0, 9, hide_ull(1LL<<8), "Sf_D_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu9i, Sf_D_BFu9i)
//============================================================================



static void Test_Sf_D_BFu9ll()
{
  {
    init_simple_test("Sf_D_BFu9ll");
    static STRUCT_IF_C Sf_D_BFu9ll lv;
    check2(sizeof(lv), 10, "sizeof(Sf_D_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu9ll)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu9ll.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu9ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 9, 1, "Sf_D_BFu9ll");
    set_bf_and_test(lv, v3, 8, 0, 9, hide_ull(1LL<<8), "Sf_D_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu9ll, Sf_D_BFu9ll)
//============================================================================



static void Test_Sf_D_BFu9s()
{
  {
    init_simple_test("Sf_D_BFu9s");
    static STRUCT_IF_C Sf_D_BFu9s lv;
    check2(sizeof(lv), 10, "sizeof(Sf_D_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_BFu9s)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu9s.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu9s.v2");
    set_bf_and_test(lv, v3, 8, 0, 9, 1, "Sf_D_BFu9s");
    set_bf_and_test(lv, v3, 8, 0, 9, hide_ull(1LL<<8), "Sf_D_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu9s, Sf_D_BFu9s)
//============================================================================



static void Test_Sf_D_C()
{
  {
    init_simple_test("Sf_D_C");
    STRUCT_IF_C Sf_D_C lv;
    check2(sizeof(lv), 9, "sizeof(Sf_D_C)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_C)");
    check_field_offset(lv, v1, 0, "Sf_D_C.v1");
    check_field_offset(lv, v2, 0, "Sf_D_C.v2");
    check_field_offset(lv, v3, 8, "Sf_D_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_C, Sf_D_C)
//============================================================================



static void Test_Sf_D_D()
{
  {
    init_simple_test("Sf_D_D");
    STRUCT_IF_C Sf_D_D lv;
    check2(sizeof(lv), 16, "sizeof(Sf_D_D)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_D)");
    check_field_offset(lv, v1, 0, "Sf_D_D.v1");
    check_field_offset(lv, v2, 0, "Sf_D_D.v2");
    check_field_offset(lv, v3, 8, "Sf_D_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_D, Sf_D_D)
//============================================================================



static void Test_Sf_D_F()
{
  {
    init_simple_test("Sf_D_F");
    STRUCT_IF_C Sf_D_F lv;
    check2(sizeof(lv), 12, "sizeof(Sf_D_F)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_F)");
    check_field_offset(lv, v1, 0, "Sf_D_F.v1");
    check_field_offset(lv, v2, 0, "Sf_D_F.v2");
    check_field_offset(lv, v3, 8, "Sf_D_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_F, Sf_D_F)
//============================================================================



static void Test_Sf_D_I()
{
  {
    init_simple_test("Sf_D_I");
    STRUCT_IF_C Sf_D_I lv;
    check2(sizeof(lv), 12, "sizeof(Sf_D_I)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_I)");
    check_field_offset(lv, v1, 0, "Sf_D_I.v1");
    check_field_offset(lv, v2, 0, "Sf_D_I.v2");
    check_field_offset(lv, v3, 8, "Sf_D_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_I, Sf_D_I)
//============================================================================



static void Test_Sf_D_Ip()
{
  {
    init_simple_test("Sf_D_Ip");
    STRUCT_IF_C Sf_D_Ip lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Sf_D_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_Ip)");
    check_field_offset(lv, v1, 0, "Sf_D_Ip.v1");
    check_field_offset(lv, v2, 0, "Sf_D_Ip.v2");
    check_field_offset(lv, v3, 8, "Sf_D_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_Ip, Sf_D_Ip)
//============================================================================



static void Test_Sf_D_L()
{
  {
    init_simple_test("Sf_D_L");
    STRUCT_IF_C Sf_D_L lv;
    check2(sizeof(lv), 16, "sizeof(Sf_D_L)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_L)");
    check_field_offset(lv, v1, 0, "Sf_D_L.v1");
    check_field_offset(lv, v2, 0, "Sf_D_L.v2");
    check_field_offset(lv, v3, 8, "Sf_D_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_L, Sf_D_L)
//============================================================================



static void Test_Sf_D_S()
{
  {
    init_simple_test("Sf_D_S");
    STRUCT_IF_C Sf_D_S lv;
    check2(sizeof(lv), 10, "sizeof(Sf_D_S)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_S)");
    check_field_offset(lv, v1, 0, "Sf_D_S.v1");
    check_field_offset(lv, v2, 0, "Sf_D_S.v2");
    check_field_offset(lv, v3, 8, "Sf_D_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_S, Sf_D_S)
//============================================================================



static void Test_Sf_D_Sf()
{
  {
    init_simple_test("Sf_D_Sf");
    STRUCT_IF_C Sf_D_Sf lv;
    check2(sizeof(lv), 8, "sizeof(Sf_D_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_Sf)");
    check_field_offset(lv, v1, 0, "Sf_D_Sf.v1");
    check_field_offset(lv, v2, 0, "Sf_D_Sf.v2");
    check_field_offset(lv, v3, 8, "Sf_D_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_Sf, Sf_D_Sf)
//============================================================================



static void Test_Sf_D_Uc()
{
  {
    init_simple_test("Sf_D_Uc");
    STRUCT_IF_C Sf_D_Uc lv;
    check2(sizeof(lv), 9, "sizeof(Sf_D_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_Uc)");
    check_field_offset(lv, v1, 0, "Sf_D_Uc.v1");
    check_field_offset(lv, v2, 0, "Sf_D_Uc.v2");
    check_field_offset(lv, v3, 8, "Sf_D_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_Uc, Sf_D_Uc)
//============================================================================



static void Test_Sf_D_Ui()
{
  {
    init_simple_test("Sf_D_Ui");
    STRUCT_IF_C Sf_D_Ui lv;
    check2(sizeof(lv), 12, "sizeof(Sf_D_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_Ui)");
    check_field_offset(lv, v1, 0, "Sf_D_Ui.v1");
    check_field_offset(lv, v2, 0, "Sf_D_Ui.v2");
    check_field_offset(lv, v3, 8, "Sf_D_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_Ui, Sf_D_Ui)
//============================================================================



static void Test_Sf_D_Ul()
{
  {
    init_simple_test("Sf_D_Ul");
    STRUCT_IF_C Sf_D_Ul lv;
    check2(sizeof(lv), 16, "sizeof(Sf_D_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_Ul)");
    check_field_offset(lv, v1, 0, "Sf_D_Ul.v1");
    check_field_offset(lv, v2, 0, "Sf_D_Ul.v2");
    check_field_offset(lv, v3, 8, "Sf_D_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_Ul, Sf_D_Ul)
//============================================================================



static void Test_Sf_D_Us()
{
  {
    init_simple_test("Sf_D_Us");
    STRUCT_IF_C Sf_D_Us lv;
    check2(sizeof(lv), 10, "sizeof(Sf_D_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_Us)");
    check_field_offset(lv, v1, 0, "Sf_D_Us.v1");
    check_field_offset(lv, v2, 0, "Sf_D_Us.v2");
    check_field_offset(lv, v3, 8, "Sf_D_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_Us, Sf_D_Us)
//============================================================================



static void Test_Sf_D_Vp()
{
  {
    init_simple_test("Sf_D_Vp");
    STRUCT_IF_C Sf_D_Vp lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Sf_D_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_Vp)");
    check_field_offset(lv, v1, 0, "Sf_D_Vp.v1");
    check_field_offset(lv, v2, 0, "Sf_D_Vp.v2");
    check_field_offset(lv, v3, 8, "Sf_D_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_Vp, Sf_D_Vp)
//============================================================================



static void Test_Sf_F()
{
  {
    init_simple_test("Sf_F");
    STRUCT_IF_C Sf_F lv;
    check2(sizeof(lv), 4, "sizeof(Sf_F)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F)");
    check_field_offset(lv, v1, 0, "Sf_F.v1");
    check_field_offset(lv, v2, 0, "Sf_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F, Sf_F)
//============================================================================



static void Test_Sf_F_BFu15i()
{
  {
    init_simple_test("Sf_F_BFu15i");
    static STRUCT_IF_C Sf_F_BFu15i lv;
    check2(sizeof(lv), 6, "sizeof(Sf_F_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu15i)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu15i.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu15i.v2");
    set_bf_and_test(lv, v3, 4, 0, 15, 1, "Sf_F_BFu15i");
    set_bf_and_test(lv, v3, 4, 0, 15, hide_ull(1LL<<14), "Sf_F_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu15i, Sf_F_BFu15i)
//============================================================================



static void Test_Sf_F_BFu15ll()
{
  {
    init_simple_test("Sf_F_BFu15ll");
    static STRUCT_IF_C Sf_F_BFu15ll lv;
    check2(sizeof(lv), 6, "sizeof(Sf_F_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu15ll)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu15ll.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu15ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 15, 1, "Sf_F_BFu15ll");
    set_bf_and_test(lv, v3, 4, 0, 15, hide_ull(1LL<<14), "Sf_F_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu15ll, Sf_F_BFu15ll)
//============================================================================



static void Test_Sf_F_BFu15s()
{
  {
    init_simple_test("Sf_F_BFu15s");
    static STRUCT_IF_C Sf_F_BFu15s lv;
    check2(sizeof(lv), 6, "sizeof(Sf_F_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu15s)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu15s.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu15s.v2");
    set_bf_and_test(lv, v3, 4, 0, 15, 1, "Sf_F_BFu15s");
    set_bf_and_test(lv, v3, 4, 0, 15, hide_ull(1LL<<14), "Sf_F_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu15s, Sf_F_BFu15s)
//============================================================================



static void Test_Sf_F_BFu16i()
{
  {
    init_simple_test("Sf_F_BFu16i");
    static STRUCT_IF_C Sf_F_BFu16i lv;
    check2(sizeof(lv), 6, "sizeof(Sf_F_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu16i)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu16i.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu16i.v2");
    set_bf_and_test(lv, v3, 4, 0, 16, 1, "Sf_F_BFu16i");
    set_bf_and_test(lv, v3, 4, 0, 16, hide_ull(1LL<<15), "Sf_F_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu16i, Sf_F_BFu16i)
//============================================================================



static void Test_Sf_F_BFu16ll()
{
  {
    init_simple_test("Sf_F_BFu16ll");
    static STRUCT_IF_C Sf_F_BFu16ll lv;
    check2(sizeof(lv), 6, "sizeof(Sf_F_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu16ll)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu16ll.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu16ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 16, 1, "Sf_F_BFu16ll");
    set_bf_and_test(lv, v3, 4, 0, 16, hide_ull(1LL<<15), "Sf_F_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu16ll, Sf_F_BFu16ll)
//============================================================================



static void Test_Sf_F_BFu16s()
{
  {
    init_simple_test("Sf_F_BFu16s");
    static STRUCT_IF_C Sf_F_BFu16s lv;
    check2(sizeof(lv), 6, "sizeof(Sf_F_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu16s)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu16s.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu16s.v2");
    set_bf_and_test(lv, v3, 4, 0, 16, 1, "Sf_F_BFu16s");
    set_bf_and_test(lv, v3, 4, 0, 16, hide_ull(1LL<<15), "Sf_F_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu16s, Sf_F_BFu16s)
//============================================================================



static void Test_Sf_F_BFu17i()
{
  {
    init_simple_test("Sf_F_BFu17i");
    static STRUCT_IF_C Sf_F_BFu17i lv;
    check2(sizeof(lv), 7, "sizeof(Sf_F_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu17i)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu17i.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu17i.v2");
    set_bf_and_test(lv, v3, 4, 0, 17, 1, "Sf_F_BFu17i");
    set_bf_and_test(lv, v3, 4, 0, 17, hide_ull(1LL<<16), "Sf_F_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu17i, Sf_F_BFu17i)
//============================================================================



static void Test_Sf_F_BFu17ll()
{
  {
    init_simple_test("Sf_F_BFu17ll");
    static STRUCT_IF_C Sf_F_BFu17ll lv;
    check2(sizeof(lv), 7, "sizeof(Sf_F_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu17ll)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu17ll.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu17ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 17, 1, "Sf_F_BFu17ll");
    set_bf_and_test(lv, v3, 4, 0, 17, hide_ull(1LL<<16), "Sf_F_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu17ll, Sf_F_BFu17ll)
//============================================================================



static void Test_Sf_F_BFu1c()
{
  {
    init_simple_test("Sf_F_BFu1c");
    static STRUCT_IF_C Sf_F_BFu1c lv;
    check2(sizeof(lv), 5, "sizeof(Sf_F_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu1c)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu1c.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu1c.v2");
    set_bf_and_test(lv, v3, 4, 0, 1, 1, "Sf_F_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu1c, Sf_F_BFu1c)
//============================================================================



static void Test_Sf_F_BFu1i()
{
  {
    init_simple_test("Sf_F_BFu1i");
    static STRUCT_IF_C Sf_F_BFu1i lv;
    check2(sizeof(lv), 5, "sizeof(Sf_F_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu1i)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu1i.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu1i.v2");
    set_bf_and_test(lv, v3, 4, 0, 1, 1, "Sf_F_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu1i, Sf_F_BFu1i)
//============================================================================



static void Test_Sf_F_BFu1ll()
{
  {
    init_simple_test("Sf_F_BFu1ll");
    static STRUCT_IF_C Sf_F_BFu1ll lv;
    check2(sizeof(lv), 5, "sizeof(Sf_F_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu1ll)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu1ll.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu1ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 1, 1, "Sf_F_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu1ll, Sf_F_BFu1ll)
//============================================================================



static void Test_Sf_F_BFu1s()
{
  {
    init_simple_test("Sf_F_BFu1s");
    static STRUCT_IF_C Sf_F_BFu1s lv;
    check2(sizeof(lv), 5, "sizeof(Sf_F_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu1s)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu1s.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu1s.v2");
    set_bf_and_test(lv, v3, 4, 0, 1, 1, "Sf_F_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu1s, Sf_F_BFu1s)
//============================================================================



static void Test_Sf_F_BFu31i()
{
  {
    init_simple_test("Sf_F_BFu31i");
    static STRUCT_IF_C Sf_F_BFu31i lv;
    check2(sizeof(lv), 8, "sizeof(Sf_F_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu31i)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu31i.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu31i.v2");
    set_bf_and_test(lv, v3, 4, 0, 31, 1, "Sf_F_BFu31i");
    set_bf_and_test(lv, v3, 4, 0, 31, hide_ull(1LL<<30), "Sf_F_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu31i, Sf_F_BFu31i)
//============================================================================



static void Test_Sf_F_BFu31ll()
{
  {
    init_simple_test("Sf_F_BFu31ll");
    static STRUCT_IF_C Sf_F_BFu31ll lv;
    check2(sizeof(lv), 8, "sizeof(Sf_F_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu31ll)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu31ll.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu31ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 31, 1, "Sf_F_BFu31ll");
    set_bf_and_test(lv, v3, 4, 0, 31, hide_ull(1LL<<30), "Sf_F_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu31ll, Sf_F_BFu31ll)
//============================================================================



static void Test_Sf_F_BFu32i()
{
  {
    init_simple_test("Sf_F_BFu32i");
    static STRUCT_IF_C Sf_F_BFu32i lv;
    check2(sizeof(lv), 8, "sizeof(Sf_F_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu32i)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu32i.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu32i.v2");
    set_bf_and_test(lv, v3, 4, 0, 32, 1, "Sf_F_BFu32i");
    set_bf_and_test(lv, v3, 4, 0, 32, hide_ull(1LL<<31), "Sf_F_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu32i, Sf_F_BFu32i)
//============================================================================



static void Test_Sf_F_BFu32ll()
{
  {
    init_simple_test("Sf_F_BFu32ll");
    static STRUCT_IF_C Sf_F_BFu32ll lv;
    check2(sizeof(lv), 8, "sizeof(Sf_F_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu32ll)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu32ll.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu32ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 32, 1, "Sf_F_BFu32ll");
    set_bf_and_test(lv, v3, 4, 0, 32, hide_ull(1LL<<31), "Sf_F_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu32ll, Sf_F_BFu32ll)
//============================================================================



static void Test_Sf_F_BFu33()
{
  {
    init_simple_test("Sf_F_BFu33");
    static STRUCT_IF_C Sf_F_BFu33 lv;
    check2(sizeof(lv), 9, "sizeof(Sf_F_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu33)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu33.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu33.v2");
    set_bf_and_test(lv, v3, 4, 0, 33, 1, "Sf_F_BFu33");
    set_bf_and_test(lv, v3, 4, 0, 33, hide_ull(1LL<<32), "Sf_F_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu33, Sf_F_BFu33)
//============================================================================



static void Test_Sf_F_BFu7c()
{
  {
    init_simple_test("Sf_F_BFu7c");
    static STRUCT_IF_C Sf_F_BFu7c lv;
    check2(sizeof(lv), 5, "sizeof(Sf_F_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu7c)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu7c.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu7c.v2");
    set_bf_and_test(lv, v3, 4, 0, 7, 1, "Sf_F_BFu7c");
    set_bf_and_test(lv, v3, 4, 0, 7, hide_ull(1LL<<6), "Sf_F_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu7c, Sf_F_BFu7c)
//============================================================================



static void Test_Sf_F_BFu7i()
{
  {
    init_simple_test("Sf_F_BFu7i");
    static STRUCT_IF_C Sf_F_BFu7i lv;
    check2(sizeof(lv), 5, "sizeof(Sf_F_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu7i)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu7i.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu7i.v2");
    set_bf_and_test(lv, v3, 4, 0, 7, 1, "Sf_F_BFu7i");
    set_bf_and_test(lv, v3, 4, 0, 7, hide_ull(1LL<<6), "Sf_F_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu7i, Sf_F_BFu7i)
//============================================================================



static void Test_Sf_F_BFu7ll()
{
  {
    init_simple_test("Sf_F_BFu7ll");
    static STRUCT_IF_C Sf_F_BFu7ll lv;
    check2(sizeof(lv), 5, "sizeof(Sf_F_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu7ll)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu7ll.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu7ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 7, 1, "Sf_F_BFu7ll");
    set_bf_and_test(lv, v3, 4, 0, 7, hide_ull(1LL<<6), "Sf_F_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu7ll, Sf_F_BFu7ll)
//============================================================================



static void Test_Sf_F_BFu7s()
{
  {
    init_simple_test("Sf_F_BFu7s");
    static STRUCT_IF_C Sf_F_BFu7s lv;
    check2(sizeof(lv), 5, "sizeof(Sf_F_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu7s)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu7s.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu7s.v2");
    set_bf_and_test(lv, v3, 4, 0, 7, 1, "Sf_F_BFu7s");
    set_bf_and_test(lv, v3, 4, 0, 7, hide_ull(1LL<<6), "Sf_F_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu7s, Sf_F_BFu7s)
//============================================================================



static void Test_Sf_F_BFu8c()
{
  {
    init_simple_test("Sf_F_BFu8c");
    static STRUCT_IF_C Sf_F_BFu8c lv;
    check2(sizeof(lv), 5, "sizeof(Sf_F_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu8c)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu8c.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu8c.v2");
    set_bf_and_test(lv, v3, 4, 0, 8, 1, "Sf_F_BFu8c");
    set_bf_and_test(lv, v3, 4, 0, 8, hide_ull(1LL<<7), "Sf_F_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu8c, Sf_F_BFu8c)
//============================================================================



static void Test_Sf_F_BFu8i()
{
  {
    init_simple_test("Sf_F_BFu8i");
    static STRUCT_IF_C Sf_F_BFu8i lv;
    check2(sizeof(lv), 5, "sizeof(Sf_F_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu8i)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu8i.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu8i.v2");
    set_bf_and_test(lv, v3, 4, 0, 8, 1, "Sf_F_BFu8i");
    set_bf_and_test(lv, v3, 4, 0, 8, hide_ull(1LL<<7), "Sf_F_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu8i, Sf_F_BFu8i)
//============================================================================



static void Test_Sf_F_BFu8ll()
{
  {
    init_simple_test("Sf_F_BFu8ll");
    static STRUCT_IF_C Sf_F_BFu8ll lv;
    check2(sizeof(lv), 5, "sizeof(Sf_F_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu8ll)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu8ll.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu8ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 8, 1, "Sf_F_BFu8ll");
    set_bf_and_test(lv, v3, 4, 0, 8, hide_ull(1LL<<7), "Sf_F_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu8ll, Sf_F_BFu8ll)
//============================================================================



static void Test_Sf_F_BFu8s()
{
  {
    init_simple_test("Sf_F_BFu8s");
    static STRUCT_IF_C Sf_F_BFu8s lv;
    check2(sizeof(lv), 5, "sizeof(Sf_F_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu8s)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu8s.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu8s.v2");
    set_bf_and_test(lv, v3, 4, 0, 8, 1, "Sf_F_BFu8s");
    set_bf_and_test(lv, v3, 4, 0, 8, hide_ull(1LL<<7), "Sf_F_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu8s, Sf_F_BFu8s)
//============================================================================



static void Test_Sf_F_BFu9i()
{
  {
    init_simple_test("Sf_F_BFu9i");
    static STRUCT_IF_C Sf_F_BFu9i lv;
    check2(sizeof(lv), 6, "sizeof(Sf_F_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu9i)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu9i.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu9i.v2");
    set_bf_and_test(lv, v3, 4, 0, 9, 1, "Sf_F_BFu9i");
    set_bf_and_test(lv, v3, 4, 0, 9, hide_ull(1LL<<8), "Sf_F_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu9i, Sf_F_BFu9i)
//============================================================================



static void Test_Sf_F_BFu9ll()
{
  {
    init_simple_test("Sf_F_BFu9ll");
    static STRUCT_IF_C Sf_F_BFu9ll lv;
    check2(sizeof(lv), 6, "sizeof(Sf_F_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu9ll)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu9ll.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu9ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 9, 1, "Sf_F_BFu9ll");
    set_bf_and_test(lv, v3, 4, 0, 9, hide_ull(1LL<<8), "Sf_F_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu9ll, Sf_F_BFu9ll)
//============================================================================



static void Test_Sf_F_BFu9s()
{
  {
    init_simple_test("Sf_F_BFu9s");
    static STRUCT_IF_C Sf_F_BFu9s lv;
    check2(sizeof(lv), 6, "sizeof(Sf_F_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_BFu9s)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu9s.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu9s.v2");
    set_bf_and_test(lv, v3, 4, 0, 9, 1, "Sf_F_BFu9s");
    set_bf_and_test(lv, v3, 4, 0, 9, hide_ull(1LL<<8), "Sf_F_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu9s, Sf_F_BFu9s)
//============================================================================



static void Test_Sf_F_C()
{
  {
    init_simple_test("Sf_F_C");
    STRUCT_IF_C Sf_F_C lv;
    check2(sizeof(lv), 5, "sizeof(Sf_F_C)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_C)");
    check_field_offset(lv, v1, 0, "Sf_F_C.v1");
    check_field_offset(lv, v2, 0, "Sf_F_C.v2");
    check_field_offset(lv, v3, 4, "Sf_F_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_C, Sf_F_C)
//============================================================================



static void Test_Sf_F_D()
{
  {
    init_simple_test("Sf_F_D");
    STRUCT_IF_C Sf_F_D lv;
    check2(sizeof(lv), 12, "sizeof(Sf_F_D)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_D)");
    check_field_offset(lv, v1, 0, "Sf_F_D.v1");
    check_field_offset(lv, v2, 0, "Sf_F_D.v2");
    check_field_offset(lv, v3, 4, "Sf_F_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_D, Sf_F_D)
//============================================================================



static void Test_Sf_F_F()
{
  {
    init_simple_test("Sf_F_F");
    STRUCT_IF_C Sf_F_F lv;
    check2(sizeof(lv), 8, "sizeof(Sf_F_F)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_F)");
    check_field_offset(lv, v1, 0, "Sf_F_F.v1");
    check_field_offset(lv, v2, 0, "Sf_F_F.v2");
    check_field_offset(lv, v3, 4, "Sf_F_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_F, Sf_F_F)
//============================================================================



static void Test_Sf_F_I()
{
  {
    init_simple_test("Sf_F_I");
    STRUCT_IF_C Sf_F_I lv;
    check2(sizeof(lv), 8, "sizeof(Sf_F_I)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_I)");
    check_field_offset(lv, v1, 0, "Sf_F_I.v1");
    check_field_offset(lv, v2, 0, "Sf_F_I.v2");
    check_field_offset(lv, v3, 4, "Sf_F_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_I, Sf_F_I)
//============================================================================



static void Test_Sf_F_Ip()
{
  {
    init_simple_test("Sf_F_Ip");
    STRUCT_IF_C Sf_F_Ip lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Sf_F_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_Ip)");
    check_field_offset(lv, v1, 0, "Sf_F_Ip.v1");
    check_field_offset(lv, v2, 0, "Sf_F_Ip.v2");
    check_field_offset(lv, v3, 4, "Sf_F_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_Ip, Sf_F_Ip)
//============================================================================



static void Test_Sf_F_L()
{
  {
    init_simple_test("Sf_F_L");
    STRUCT_IF_C Sf_F_L lv;
    check2(sizeof(lv), 12, "sizeof(Sf_F_L)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_L)");
    check_field_offset(lv, v1, 0, "Sf_F_L.v1");
    check_field_offset(lv, v2, 0, "Sf_F_L.v2");
    check_field_offset(lv, v3, 4, "Sf_F_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_L, Sf_F_L)
//============================================================================



static void Test_Sf_F_S()
{
  {
    init_simple_test("Sf_F_S");
    STRUCT_IF_C Sf_F_S lv;
    check2(sizeof(lv), 6, "sizeof(Sf_F_S)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_S)");
    check_field_offset(lv, v1, 0, "Sf_F_S.v1");
    check_field_offset(lv, v2, 0, "Sf_F_S.v2");
    check_field_offset(lv, v3, 4, "Sf_F_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_S, Sf_F_S)
//============================================================================



static void Test_Sf_F_Sf()
{
  {
    init_simple_test("Sf_F_Sf");
    STRUCT_IF_C Sf_F_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Sf_F_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_Sf)");
    check_field_offset(lv, v1, 0, "Sf_F_Sf.v1");
    check_field_offset(lv, v2, 0, "Sf_F_Sf.v2");
    check_field_offset(lv, v3, 4, "Sf_F_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_Sf, Sf_F_Sf)
//============================================================================



static void Test_Sf_F_Uc()
{
  {
    init_simple_test("Sf_F_Uc");
    STRUCT_IF_C Sf_F_Uc lv;
    check2(sizeof(lv), 5, "sizeof(Sf_F_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_Uc)");
    check_field_offset(lv, v1, 0, "Sf_F_Uc.v1");
    check_field_offset(lv, v2, 0, "Sf_F_Uc.v2");
    check_field_offset(lv, v3, 4, "Sf_F_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_Uc, Sf_F_Uc)
//============================================================================



static void Test_Sf_F_Ui()
{
  {
    init_simple_test("Sf_F_Ui");
    STRUCT_IF_C Sf_F_Ui lv;
    check2(sizeof(lv), 8, "sizeof(Sf_F_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_Ui)");
    check_field_offset(lv, v1, 0, "Sf_F_Ui.v1");
    check_field_offset(lv, v2, 0, "Sf_F_Ui.v2");
    check_field_offset(lv, v3, 4, "Sf_F_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_Ui, Sf_F_Ui)
//============================================================================



static void Test_Sf_F_Ul()
{
  {
    init_simple_test("Sf_F_Ul");
    STRUCT_IF_C Sf_F_Ul lv;
    check2(sizeof(lv), 12, "sizeof(Sf_F_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_Ul)");
    check_field_offset(lv, v1, 0, "Sf_F_Ul.v1");
    check_field_offset(lv, v2, 0, "Sf_F_Ul.v2");
    check_field_offset(lv, v3, 4, "Sf_F_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_Ul, Sf_F_Ul)
//============================================================================



static void Test_Sf_F_Us()
{
  {
    init_simple_test("Sf_F_Us");
    STRUCT_IF_C Sf_F_Us lv;
    check2(sizeof(lv), 6, "sizeof(Sf_F_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_Us)");
    check_field_offset(lv, v1, 0, "Sf_F_Us.v1");
    check_field_offset(lv, v2, 0, "Sf_F_Us.v2");
    check_field_offset(lv, v3, 4, "Sf_F_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_Us, Sf_F_Us)
//============================================================================



static void Test_Sf_F_Vp()
{
  {
    init_simple_test("Sf_F_Vp");
    STRUCT_IF_C Sf_F_Vp lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Sf_F_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_Vp)");
    check_field_offset(lv, v1, 0, "Sf_F_Vp.v1");
    check_field_offset(lv, v2, 0, "Sf_F_Vp.v2");
    check_field_offset(lv, v3, 4, "Sf_F_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_Vp, Sf_F_Vp)
//============================================================================



static void Test_Sf_I()
{
  {
    init_simple_test("Sf_I");
    STRUCT_IF_C Sf_I lv;
    check2(sizeof(lv), 4, "sizeof(Sf_I)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I)");
    check_field_offset(lv, v1, 0, "Sf_I.v1");
    check_field_offset(lv, v2, 0, "Sf_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I, Sf_I)
//============================================================================



static void Test_Sf_I_BFu15i()
{
  {
    init_simple_test("Sf_I_BFu15i");
    static STRUCT_IF_C Sf_I_BFu15i lv;
    check2(sizeof(lv), 6, "sizeof(Sf_I_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu15i)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu15i.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu15i.v2");
    set_bf_and_test(lv, v3, 4, 0, 15, 1, "Sf_I_BFu15i");
    set_bf_and_test(lv, v3, 4, 0, 15, hide_ull(1LL<<14), "Sf_I_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu15i, Sf_I_BFu15i)
//============================================================================



static void Test_Sf_I_BFu15ll()
{
  {
    init_simple_test("Sf_I_BFu15ll");
    static STRUCT_IF_C Sf_I_BFu15ll lv;
    check2(sizeof(lv), 6, "sizeof(Sf_I_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu15ll)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu15ll.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu15ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 15, 1, "Sf_I_BFu15ll");
    set_bf_and_test(lv, v3, 4, 0, 15, hide_ull(1LL<<14), "Sf_I_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu15ll, Sf_I_BFu15ll)
//============================================================================



static void Test_Sf_I_BFu15s()
{
  {
    init_simple_test("Sf_I_BFu15s");
    static STRUCT_IF_C Sf_I_BFu15s lv;
    check2(sizeof(lv), 6, "sizeof(Sf_I_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu15s)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu15s.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu15s.v2");
    set_bf_and_test(lv, v3, 4, 0, 15, 1, "Sf_I_BFu15s");
    set_bf_and_test(lv, v3, 4, 0, 15, hide_ull(1LL<<14), "Sf_I_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu15s, Sf_I_BFu15s)
//============================================================================



static void Test_Sf_I_BFu16i()
{
  {
    init_simple_test("Sf_I_BFu16i");
    static STRUCT_IF_C Sf_I_BFu16i lv;
    check2(sizeof(lv), 6, "sizeof(Sf_I_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu16i)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu16i.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu16i.v2");
    set_bf_and_test(lv, v3, 4, 0, 16, 1, "Sf_I_BFu16i");
    set_bf_and_test(lv, v3, 4, 0, 16, hide_ull(1LL<<15), "Sf_I_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu16i, Sf_I_BFu16i)
//============================================================================



static void Test_Sf_I_BFu16ll()
{
  {
    init_simple_test("Sf_I_BFu16ll");
    static STRUCT_IF_C Sf_I_BFu16ll lv;
    check2(sizeof(lv), 6, "sizeof(Sf_I_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu16ll)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu16ll.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu16ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 16, 1, "Sf_I_BFu16ll");
    set_bf_and_test(lv, v3, 4, 0, 16, hide_ull(1LL<<15), "Sf_I_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu16ll, Sf_I_BFu16ll)
//============================================================================



static void Test_Sf_I_BFu16s()
{
  {
    init_simple_test("Sf_I_BFu16s");
    static STRUCT_IF_C Sf_I_BFu16s lv;
    check2(sizeof(lv), 6, "sizeof(Sf_I_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu16s)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu16s.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu16s.v2");
    set_bf_and_test(lv, v3, 4, 0, 16, 1, "Sf_I_BFu16s");
    set_bf_and_test(lv, v3, 4, 0, 16, hide_ull(1LL<<15), "Sf_I_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu16s, Sf_I_BFu16s)
//============================================================================



static void Test_Sf_I_BFu17i()
{
  {
    init_simple_test("Sf_I_BFu17i");
    static STRUCT_IF_C Sf_I_BFu17i lv;
    check2(sizeof(lv), 7, "sizeof(Sf_I_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu17i)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu17i.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu17i.v2");
    set_bf_and_test(lv, v3, 4, 0, 17, 1, "Sf_I_BFu17i");
    set_bf_and_test(lv, v3, 4, 0, 17, hide_ull(1LL<<16), "Sf_I_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu17i, Sf_I_BFu17i)
//============================================================================



static void Test_Sf_I_BFu17ll()
{
  {
    init_simple_test("Sf_I_BFu17ll");
    static STRUCT_IF_C Sf_I_BFu17ll lv;
    check2(sizeof(lv), 7, "sizeof(Sf_I_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu17ll)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu17ll.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu17ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 17, 1, "Sf_I_BFu17ll");
    set_bf_and_test(lv, v3, 4, 0, 17, hide_ull(1LL<<16), "Sf_I_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu17ll, Sf_I_BFu17ll)
//============================================================================



static void Test_Sf_I_BFu1c()
{
  {
    init_simple_test("Sf_I_BFu1c");
    static STRUCT_IF_C Sf_I_BFu1c lv;
    check2(sizeof(lv), 5, "sizeof(Sf_I_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu1c)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu1c.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu1c.v2");
    set_bf_and_test(lv, v3, 4, 0, 1, 1, "Sf_I_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu1c, Sf_I_BFu1c)
//============================================================================



static void Test_Sf_I_BFu1i()
{
  {
    init_simple_test("Sf_I_BFu1i");
    static STRUCT_IF_C Sf_I_BFu1i lv;
    check2(sizeof(lv), 5, "sizeof(Sf_I_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu1i)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu1i.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu1i.v2");
    set_bf_and_test(lv, v3, 4, 0, 1, 1, "Sf_I_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu1i, Sf_I_BFu1i)
//============================================================================



static void Test_Sf_I_BFu1ll()
{
  {
    init_simple_test("Sf_I_BFu1ll");
    static STRUCT_IF_C Sf_I_BFu1ll lv;
    check2(sizeof(lv), 5, "sizeof(Sf_I_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu1ll)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu1ll.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu1ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 1, 1, "Sf_I_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu1ll, Sf_I_BFu1ll)
//============================================================================



static void Test_Sf_I_BFu1s()
{
  {
    init_simple_test("Sf_I_BFu1s");
    static STRUCT_IF_C Sf_I_BFu1s lv;
    check2(sizeof(lv), 5, "sizeof(Sf_I_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu1s)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu1s.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu1s.v2");
    set_bf_and_test(lv, v3, 4, 0, 1, 1, "Sf_I_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu1s, Sf_I_BFu1s)
//============================================================================



static void Test_Sf_I_BFu31i()
{
  {
    init_simple_test("Sf_I_BFu31i");
    static STRUCT_IF_C Sf_I_BFu31i lv;
    check2(sizeof(lv), 8, "sizeof(Sf_I_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu31i)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu31i.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu31i.v2");
    set_bf_and_test(lv, v3, 4, 0, 31, 1, "Sf_I_BFu31i");
    set_bf_and_test(lv, v3, 4, 0, 31, hide_ull(1LL<<30), "Sf_I_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu31i, Sf_I_BFu31i)
//============================================================================



static void Test_Sf_I_BFu31ll()
{
  {
    init_simple_test("Sf_I_BFu31ll");
    static STRUCT_IF_C Sf_I_BFu31ll lv;
    check2(sizeof(lv), 8, "sizeof(Sf_I_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu31ll)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu31ll.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu31ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 31, 1, "Sf_I_BFu31ll");
    set_bf_and_test(lv, v3, 4, 0, 31, hide_ull(1LL<<30), "Sf_I_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu31ll, Sf_I_BFu31ll)
//============================================================================



static void Test_Sf_I_BFu32i()
{
  {
    init_simple_test("Sf_I_BFu32i");
    static STRUCT_IF_C Sf_I_BFu32i lv;
    check2(sizeof(lv), 8, "sizeof(Sf_I_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu32i)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu32i.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu32i.v2");
    set_bf_and_test(lv, v3, 4, 0, 32, 1, "Sf_I_BFu32i");
    set_bf_and_test(lv, v3, 4, 0, 32, hide_ull(1LL<<31), "Sf_I_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu32i, Sf_I_BFu32i)
//============================================================================



static void Test_Sf_I_BFu32ll()
{
  {
    init_simple_test("Sf_I_BFu32ll");
    static STRUCT_IF_C Sf_I_BFu32ll lv;
    check2(sizeof(lv), 8, "sizeof(Sf_I_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu32ll)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu32ll.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu32ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 32, 1, "Sf_I_BFu32ll");
    set_bf_and_test(lv, v3, 4, 0, 32, hide_ull(1LL<<31), "Sf_I_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu32ll, Sf_I_BFu32ll)
//============================================================================



static void Test_Sf_I_BFu33()
{
  {
    init_simple_test("Sf_I_BFu33");
    static STRUCT_IF_C Sf_I_BFu33 lv;
    check2(sizeof(lv), 9, "sizeof(Sf_I_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu33)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu33.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu33.v2");
    set_bf_and_test(lv, v3, 4, 0, 33, 1, "Sf_I_BFu33");
    set_bf_and_test(lv, v3, 4, 0, 33, hide_ull(1LL<<32), "Sf_I_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu33, Sf_I_BFu33)
//============================================================================



static void Test_Sf_I_BFu7c()
{
  {
    init_simple_test("Sf_I_BFu7c");
    static STRUCT_IF_C Sf_I_BFu7c lv;
    check2(sizeof(lv), 5, "sizeof(Sf_I_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu7c)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu7c.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu7c.v2");
    set_bf_and_test(lv, v3, 4, 0, 7, 1, "Sf_I_BFu7c");
    set_bf_and_test(lv, v3, 4, 0, 7, hide_ull(1LL<<6), "Sf_I_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu7c, Sf_I_BFu7c)
//============================================================================



static void Test_Sf_I_BFu7i()
{
  {
    init_simple_test("Sf_I_BFu7i");
    static STRUCT_IF_C Sf_I_BFu7i lv;
    check2(sizeof(lv), 5, "sizeof(Sf_I_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu7i)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu7i.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu7i.v2");
    set_bf_and_test(lv, v3, 4, 0, 7, 1, "Sf_I_BFu7i");
    set_bf_and_test(lv, v3, 4, 0, 7, hide_ull(1LL<<6), "Sf_I_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu7i, Sf_I_BFu7i)
//============================================================================



static void Test_Sf_I_BFu7ll()
{
  {
    init_simple_test("Sf_I_BFu7ll");
    static STRUCT_IF_C Sf_I_BFu7ll lv;
    check2(sizeof(lv), 5, "sizeof(Sf_I_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu7ll)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu7ll.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu7ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 7, 1, "Sf_I_BFu7ll");
    set_bf_and_test(lv, v3, 4, 0, 7, hide_ull(1LL<<6), "Sf_I_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu7ll, Sf_I_BFu7ll)
//============================================================================



static void Test_Sf_I_BFu7s()
{
  {
    init_simple_test("Sf_I_BFu7s");
    static STRUCT_IF_C Sf_I_BFu7s lv;
    check2(sizeof(lv), 5, "sizeof(Sf_I_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu7s)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu7s.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu7s.v2");
    set_bf_and_test(lv, v3, 4, 0, 7, 1, "Sf_I_BFu7s");
    set_bf_and_test(lv, v3, 4, 0, 7, hide_ull(1LL<<6), "Sf_I_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu7s, Sf_I_BFu7s)
//============================================================================



static void Test_Sf_I_BFu8c()
{
  {
    init_simple_test("Sf_I_BFu8c");
    static STRUCT_IF_C Sf_I_BFu8c lv;
    check2(sizeof(lv), 5, "sizeof(Sf_I_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu8c)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu8c.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu8c.v2");
    set_bf_and_test(lv, v3, 4, 0, 8, 1, "Sf_I_BFu8c");
    set_bf_and_test(lv, v3, 4, 0, 8, hide_ull(1LL<<7), "Sf_I_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu8c, Sf_I_BFu8c)
//============================================================================



static void Test_Sf_I_BFu8i()
{
  {
    init_simple_test("Sf_I_BFu8i");
    static STRUCT_IF_C Sf_I_BFu8i lv;
    check2(sizeof(lv), 5, "sizeof(Sf_I_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu8i)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu8i.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu8i.v2");
    set_bf_and_test(lv, v3, 4, 0, 8, 1, "Sf_I_BFu8i");
    set_bf_and_test(lv, v3, 4, 0, 8, hide_ull(1LL<<7), "Sf_I_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu8i, Sf_I_BFu8i)
//============================================================================



static void Test_Sf_I_BFu8ll()
{
  {
    init_simple_test("Sf_I_BFu8ll");
    static STRUCT_IF_C Sf_I_BFu8ll lv;
    check2(sizeof(lv), 5, "sizeof(Sf_I_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu8ll)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu8ll.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu8ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 8, 1, "Sf_I_BFu8ll");
    set_bf_and_test(lv, v3, 4, 0, 8, hide_ull(1LL<<7), "Sf_I_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu8ll, Sf_I_BFu8ll)
//============================================================================



static void Test_Sf_I_BFu8s()
{
  {
    init_simple_test("Sf_I_BFu8s");
    static STRUCT_IF_C Sf_I_BFu8s lv;
    check2(sizeof(lv), 5, "sizeof(Sf_I_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu8s)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu8s.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu8s.v2");
    set_bf_and_test(lv, v3, 4, 0, 8, 1, "Sf_I_BFu8s");
    set_bf_and_test(lv, v3, 4, 0, 8, hide_ull(1LL<<7), "Sf_I_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu8s, Sf_I_BFu8s)
//============================================================================



static void Test_Sf_I_BFu9i()
{
  {
    init_simple_test("Sf_I_BFu9i");
    static STRUCT_IF_C Sf_I_BFu9i lv;
    check2(sizeof(lv), 6, "sizeof(Sf_I_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu9i)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu9i.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu9i.v2");
    set_bf_and_test(lv, v3, 4, 0, 9, 1, "Sf_I_BFu9i");
    set_bf_and_test(lv, v3, 4, 0, 9, hide_ull(1LL<<8), "Sf_I_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu9i, Sf_I_BFu9i)
//============================================================================



static void Test_Sf_I_BFu9ll()
{
  {
    init_simple_test("Sf_I_BFu9ll");
    static STRUCT_IF_C Sf_I_BFu9ll lv;
    check2(sizeof(lv), 6, "sizeof(Sf_I_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu9ll)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu9ll.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu9ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 9, 1, "Sf_I_BFu9ll");
    set_bf_and_test(lv, v3, 4, 0, 9, hide_ull(1LL<<8), "Sf_I_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu9ll, Sf_I_BFu9ll)
//============================================================================



static void Test_Sf_I_BFu9s()
{
  {
    init_simple_test("Sf_I_BFu9s");
    static STRUCT_IF_C Sf_I_BFu9s lv;
    check2(sizeof(lv), 6, "sizeof(Sf_I_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_BFu9s)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu9s.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu9s.v2");
    set_bf_and_test(lv, v3, 4, 0, 9, 1, "Sf_I_BFu9s");
    set_bf_and_test(lv, v3, 4, 0, 9, hide_ull(1LL<<8), "Sf_I_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu9s, Sf_I_BFu9s)
//============================================================================



static void Test_Sf_I_C()
{
  {
    init_simple_test("Sf_I_C");
    STRUCT_IF_C Sf_I_C lv;
    check2(sizeof(lv), 5, "sizeof(Sf_I_C)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_C)");
    check_field_offset(lv, v1, 0, "Sf_I_C.v1");
    check_field_offset(lv, v2, 0, "Sf_I_C.v2");
    check_field_offset(lv, v3, 4, "Sf_I_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_C, Sf_I_C)
//============================================================================



static void Test_Sf_I_D()
{
  {
    init_simple_test("Sf_I_D");
    STRUCT_IF_C Sf_I_D lv;
    check2(sizeof(lv), 12, "sizeof(Sf_I_D)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_D)");
    check_field_offset(lv, v1, 0, "Sf_I_D.v1");
    check_field_offset(lv, v2, 0, "Sf_I_D.v2");
    check_field_offset(lv, v3, 4, "Sf_I_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_D, Sf_I_D)
//============================================================================



static void Test_Sf_I_F()
{
  {
    init_simple_test("Sf_I_F");
    STRUCT_IF_C Sf_I_F lv;
    check2(sizeof(lv), 8, "sizeof(Sf_I_F)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_F)");
    check_field_offset(lv, v1, 0, "Sf_I_F.v1");
    check_field_offset(lv, v2, 0, "Sf_I_F.v2");
    check_field_offset(lv, v3, 4, "Sf_I_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_F, Sf_I_F)
//============================================================================



static void Test_Sf_I_I()
{
  {
    init_simple_test("Sf_I_I");
    STRUCT_IF_C Sf_I_I lv;
    check2(sizeof(lv), 8, "sizeof(Sf_I_I)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_I)");
    check_field_offset(lv, v1, 0, "Sf_I_I.v1");
    check_field_offset(lv, v2, 0, "Sf_I_I.v2");
    check_field_offset(lv, v3, 4, "Sf_I_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_I, Sf_I_I)
//============================================================================



static void Test_Sf_I_Ip()
{
  {
    init_simple_test("Sf_I_Ip");
    STRUCT_IF_C Sf_I_Ip lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Sf_I_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_Ip)");
    check_field_offset(lv, v1, 0, "Sf_I_Ip.v1");
    check_field_offset(lv, v2, 0, "Sf_I_Ip.v2");
    check_field_offset(lv, v3, 4, "Sf_I_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_Ip, Sf_I_Ip)
//============================================================================



static void Test_Sf_I_L()
{
  {
    init_simple_test("Sf_I_L");
    STRUCT_IF_C Sf_I_L lv;
    check2(sizeof(lv), 12, "sizeof(Sf_I_L)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_L)");
    check_field_offset(lv, v1, 0, "Sf_I_L.v1");
    check_field_offset(lv, v2, 0, "Sf_I_L.v2");
    check_field_offset(lv, v3, 4, "Sf_I_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_L, Sf_I_L)
//============================================================================



static void Test_Sf_I_S()
{
  {
    init_simple_test("Sf_I_S");
    STRUCT_IF_C Sf_I_S lv;
    check2(sizeof(lv), 6, "sizeof(Sf_I_S)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_S)");
    check_field_offset(lv, v1, 0, "Sf_I_S.v1");
    check_field_offset(lv, v2, 0, "Sf_I_S.v2");
    check_field_offset(lv, v3, 4, "Sf_I_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_S, Sf_I_S)
//============================================================================



static void Test_Sf_I_Sf()
{
  {
    init_simple_test("Sf_I_Sf");
    STRUCT_IF_C Sf_I_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Sf_I_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_Sf)");
    check_field_offset(lv, v1, 0, "Sf_I_Sf.v1");
    check_field_offset(lv, v2, 0, "Sf_I_Sf.v2");
    check_field_offset(lv, v3, 4, "Sf_I_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_Sf, Sf_I_Sf)
//============================================================================



static void Test_Sf_I_Uc()
{
  {
    init_simple_test("Sf_I_Uc");
    STRUCT_IF_C Sf_I_Uc lv;
    check2(sizeof(lv), 5, "sizeof(Sf_I_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_Uc)");
    check_field_offset(lv, v1, 0, "Sf_I_Uc.v1");
    check_field_offset(lv, v2, 0, "Sf_I_Uc.v2");
    check_field_offset(lv, v3, 4, "Sf_I_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_Uc, Sf_I_Uc)
//============================================================================



static void Test_Sf_I_Ui()
{
  {
    init_simple_test("Sf_I_Ui");
    STRUCT_IF_C Sf_I_Ui lv;
    check2(sizeof(lv), 8, "sizeof(Sf_I_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_Ui)");
    check_field_offset(lv, v1, 0, "Sf_I_Ui.v1");
    check_field_offset(lv, v2, 0, "Sf_I_Ui.v2");
    check_field_offset(lv, v3, 4, "Sf_I_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_Ui, Sf_I_Ui)
//============================================================================



static void Test_Sf_I_Ul()
{
  {
    init_simple_test("Sf_I_Ul");
    STRUCT_IF_C Sf_I_Ul lv;
    check2(sizeof(lv), 12, "sizeof(Sf_I_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_Ul)");
    check_field_offset(lv, v1, 0, "Sf_I_Ul.v1");
    check_field_offset(lv, v2, 0, "Sf_I_Ul.v2");
    check_field_offset(lv, v3, 4, "Sf_I_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_Ul, Sf_I_Ul)
//============================================================================



static void Test_Sf_I_Us()
{
  {
    init_simple_test("Sf_I_Us");
    STRUCT_IF_C Sf_I_Us lv;
    check2(sizeof(lv), 6, "sizeof(Sf_I_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_Us)");
    check_field_offset(lv, v1, 0, "Sf_I_Us.v1");
    check_field_offset(lv, v2, 0, "Sf_I_Us.v2");
    check_field_offset(lv, v3, 4, "Sf_I_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_Us, Sf_I_Us)
//============================================================================



static void Test_Sf_I_Vp()
{
  {
    init_simple_test("Sf_I_Vp");
    STRUCT_IF_C Sf_I_Vp lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Sf_I_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_Vp)");
    check_field_offset(lv, v1, 0, "Sf_I_Vp.v1");
    check_field_offset(lv, v2, 0, "Sf_I_Vp.v2");
    check_field_offset(lv, v3, 4, "Sf_I_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_Vp, Sf_I_Vp)
//============================================================================



static void Test_Sf_Ip()
{
  {
    init_simple_test("Sf_Ip");
    STRUCT_IF_C Sf_Ip lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip)");
    check_field_offset(lv, v1, 0, "Sf_Ip.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip, Sf_Ip)
//============================================================================



static void Test_Sf_Ip_BFu15i()
{
  {
    init_simple_test("Sf_Ip_BFu15i");
    static STRUCT_IF_C Sf_Ip_BFu15i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Ip_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu15i)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu15i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu15i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 15, 1, "Sf_Ip_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Sf_Ip_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu15i, Sf_Ip_BFu15i)
//============================================================================



static void Test_Sf_Ip_BFu15ll()
{
  {
    init_simple_test("Sf_Ip_BFu15ll");
    static STRUCT_IF_C Sf_Ip_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Ip_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu15ll)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu15ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu15ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 15, 1, "Sf_Ip_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Sf_Ip_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu15ll, Sf_Ip_BFu15ll)
//============================================================================



static void Test_Sf_Ip_BFu15s()
{
  {
    init_simple_test("Sf_Ip_BFu15s");
    static STRUCT_IF_C Sf_Ip_BFu15s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Ip_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu15s)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu15s.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu15s.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 15, 1, "Sf_Ip_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Sf_Ip_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu15s, Sf_Ip_BFu15s)
//============================================================================



static void Test_Sf_Ip_BFu16i()
{
  {
    init_simple_test("Sf_Ip_BFu16i");
    static STRUCT_IF_C Sf_Ip_BFu16i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Ip_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu16i)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu16i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu16i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 16, 1, "Sf_Ip_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Sf_Ip_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu16i, Sf_Ip_BFu16i)
//============================================================================



static void Test_Sf_Ip_BFu16ll()
{
  {
    init_simple_test("Sf_Ip_BFu16ll");
    static STRUCT_IF_C Sf_Ip_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Ip_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu16ll)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu16ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu16ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 16, 1, "Sf_Ip_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Sf_Ip_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu16ll, Sf_Ip_BFu16ll)
//============================================================================



static void Test_Sf_Ip_BFu16s()
{
  {
    init_simple_test("Sf_Ip_BFu16s");
    static STRUCT_IF_C Sf_Ip_BFu16s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Ip_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu16s)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu16s.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu16s.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 16, 1, "Sf_Ip_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Sf_Ip_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu16s, Sf_Ip_BFu16s)
//============================================================================



static void Test_Sf_Ip_BFu17i()
{
  {
    init_simple_test("Sf_Ip_BFu17i");
    static STRUCT_IF_C Sf_Ip_BFu17i lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Sf_Ip_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu17i)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu17i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu17i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 17, 1, "Sf_Ip_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Sf_Ip_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu17i, Sf_Ip_BFu17i)
//============================================================================



static void Test_Sf_Ip_BFu17ll()
{
  {
    init_simple_test("Sf_Ip_BFu17ll");
    static STRUCT_IF_C Sf_Ip_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Sf_Ip_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu17ll)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu17ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu17ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 17, 1, "Sf_Ip_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Sf_Ip_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu17ll, Sf_Ip_BFu17ll)
//============================================================================



static void Test_Sf_Ip_BFu1c()
{
  {
    init_simple_test("Sf_Ip_BFu1c");
    static STRUCT_IF_C Sf_Ip_BFu1c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Ip_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu1c)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu1c.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu1c.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 1, 1, "Sf_Ip_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu1c, Sf_Ip_BFu1c)
//============================================================================



static void Test_Sf_Ip_BFu1i()
{
  {
    init_simple_test("Sf_Ip_BFu1i");
    static STRUCT_IF_C Sf_Ip_BFu1i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Ip_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu1i)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu1i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu1i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 1, 1, "Sf_Ip_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu1i, Sf_Ip_BFu1i)
//============================================================================



static void Test_Sf_Ip_BFu1ll()
{
  {
    init_simple_test("Sf_Ip_BFu1ll");
    static STRUCT_IF_C Sf_Ip_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Ip_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu1ll)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu1ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu1ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 1, 1, "Sf_Ip_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu1ll, Sf_Ip_BFu1ll)
//============================================================================



static void Test_Sf_Ip_BFu1s()
{
  {
    init_simple_test("Sf_Ip_BFu1s");
    static STRUCT_IF_C Sf_Ip_BFu1s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Ip_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu1s)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu1s.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu1s.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 1, 1, "Sf_Ip_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu1s, Sf_Ip_BFu1s)
//============================================================================



static void Test_Sf_Ip_BFu31i()
{
  {
    init_simple_test("Sf_Ip_BFu31i");
    static STRUCT_IF_C Sf_Ip_BFu31i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Sf_Ip_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu31i)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu31i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu31i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 31, 1, "Sf_Ip_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Sf_Ip_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu31i, Sf_Ip_BFu31i)
//============================================================================



static void Test_Sf_Ip_BFu31ll()
{
  {
    init_simple_test("Sf_Ip_BFu31ll");
    static STRUCT_IF_C Sf_Ip_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Sf_Ip_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu31ll)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu31ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu31ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 31, 1, "Sf_Ip_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Sf_Ip_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu31ll, Sf_Ip_BFu31ll)
//============================================================================



static void Test_Sf_Ip_BFu32i()
{
  {
    init_simple_test("Sf_Ip_BFu32i");
    static STRUCT_IF_C Sf_Ip_BFu32i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Sf_Ip_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu32i)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu32i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu32i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 32, 1, "Sf_Ip_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Sf_Ip_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu32i, Sf_Ip_BFu32i)
//============================================================================



static void Test_Sf_Ip_BFu32ll()
{
  {
    init_simple_test("Sf_Ip_BFu32ll");
    static STRUCT_IF_C Sf_Ip_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Sf_Ip_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu32ll)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu32ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu32ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 32, 1, "Sf_Ip_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Sf_Ip_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu32ll, Sf_Ip_BFu32ll)
//============================================================================



static void Test_Sf_Ip_BFu33()
{
  {
    init_simple_test("Sf_Ip_BFu33");
    static STRUCT_IF_C Sf_Ip_BFu33 lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Sf_Ip_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu33)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu33.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu33.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 33, 1, "Sf_Ip_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Sf_Ip_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu33, Sf_Ip_BFu33)
//============================================================================



static void Test_Sf_Ip_BFu7c()
{
  {
    init_simple_test("Sf_Ip_BFu7c");
    static STRUCT_IF_C Sf_Ip_BFu7c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Ip_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu7c)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu7c.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu7c.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, 1, "Sf_Ip_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Sf_Ip_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu7c, Sf_Ip_BFu7c)
//============================================================================



static void Test_Sf_Ip_BFu7i()
{
  {
    init_simple_test("Sf_Ip_BFu7i");
    static STRUCT_IF_C Sf_Ip_BFu7i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Ip_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu7i)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu7i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu7i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, 1, "Sf_Ip_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Sf_Ip_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu7i, Sf_Ip_BFu7i)
//============================================================================



static void Test_Sf_Ip_BFu7ll()
{
  {
    init_simple_test("Sf_Ip_BFu7ll");
    static STRUCT_IF_C Sf_Ip_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Ip_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu7ll)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu7ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu7ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, 1, "Sf_Ip_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Sf_Ip_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu7ll, Sf_Ip_BFu7ll)
//============================================================================



static void Test_Sf_Ip_BFu7s()
{
  {
    init_simple_test("Sf_Ip_BFu7s");
    static STRUCT_IF_C Sf_Ip_BFu7s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Ip_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu7s)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu7s.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu7s.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, 1, "Sf_Ip_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Sf_Ip_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu7s, Sf_Ip_BFu7s)
//============================================================================



static void Test_Sf_Ip_BFu8c()
{
  {
    init_simple_test("Sf_Ip_BFu8c");
    static STRUCT_IF_C Sf_Ip_BFu8c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Ip_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu8c)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu8c.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu8c.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, 1, "Sf_Ip_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Sf_Ip_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu8c, Sf_Ip_BFu8c)
//============================================================================



static void Test_Sf_Ip_BFu8i()
{
  {
    init_simple_test("Sf_Ip_BFu8i");
    static STRUCT_IF_C Sf_Ip_BFu8i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Ip_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu8i)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu8i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu8i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, 1, "Sf_Ip_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Sf_Ip_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu8i, Sf_Ip_BFu8i)
//============================================================================



static void Test_Sf_Ip_BFu8ll()
{
  {
    init_simple_test("Sf_Ip_BFu8ll");
    static STRUCT_IF_C Sf_Ip_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Ip_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu8ll)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu8ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu8ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, 1, "Sf_Ip_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Sf_Ip_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu8ll, Sf_Ip_BFu8ll)
//============================================================================



static void Test_Sf_Ip_BFu8s()
{
  {
    init_simple_test("Sf_Ip_BFu8s");
    static STRUCT_IF_C Sf_Ip_BFu8s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Ip_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu8s)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu8s.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu8s.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, 1, "Sf_Ip_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Sf_Ip_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu8s, Sf_Ip_BFu8s)
//============================================================================



static void Test_Sf_Ip_BFu9i()
{
  {
    init_simple_test("Sf_Ip_BFu9i");
    static STRUCT_IF_C Sf_Ip_BFu9i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Ip_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu9i)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu9i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu9i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 9, 1, "Sf_Ip_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Sf_Ip_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu9i, Sf_Ip_BFu9i)
//============================================================================



static void Test_Sf_Ip_BFu9ll()
{
  {
    init_simple_test("Sf_Ip_BFu9ll");
    static STRUCT_IF_C Sf_Ip_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Ip_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu9ll)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu9ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu9ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 9, 1, "Sf_Ip_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Sf_Ip_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu9ll, Sf_Ip_BFu9ll)
//============================================================================



static void Test_Sf_Ip_BFu9s()
{
  {
    init_simple_test("Sf_Ip_BFu9s");
    static STRUCT_IF_C Sf_Ip_BFu9s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Ip_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_BFu9s)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu9s.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu9s.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 9, 1, "Sf_Ip_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Sf_Ip_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu9s, Sf_Ip_BFu9s)
//============================================================================



static void Test_Sf_Ip_C()
{
  {
    init_simple_test("Sf_Ip_C");
    STRUCT_IF_C Sf_Ip_C lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Ip_C)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_C)");
    check_field_offset(lv, v1, 0, "Sf_Ip_C.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_C.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Ip_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_C, Sf_Ip_C)
//============================================================================



static void Test_Sf_Ip_D()
{
  {
    init_simple_test("Sf_Ip_D");
    STRUCT_IF_C Sf_Ip_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Sf_Ip_D)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_D)");
    check_field_offset(lv, v1, 0, "Sf_Ip_D.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_D.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Ip_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_D, Sf_Ip_D)
//============================================================================



static void Test_Sf_Ip_F()
{
  {
    init_simple_test("Sf_Ip_F");
    STRUCT_IF_C Sf_Ip_F lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Sf_Ip_F)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_F)");
    check_field_offset(lv, v1, 0, "Sf_Ip_F.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_F.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Ip_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_F, Sf_Ip_F)
//============================================================================



static void Test_Sf_Ip_I()
{
  {
    init_simple_test("Sf_Ip_I");
    STRUCT_IF_C Sf_Ip_I lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Sf_Ip_I)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_I)");
    check_field_offset(lv, v1, 0, "Sf_Ip_I.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_I.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Ip_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_I, Sf_Ip_I)
//============================================================================



static void Test_Sf_Ip_Ip()
{
  {
    init_simple_test("Sf_Ip_Ip");
    STRUCT_IF_C Sf_Ip_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Sf_Ip_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_Ip)");
    check_field_offset(lv, v1, 0, "Sf_Ip_Ip.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_Ip.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Ip_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_Ip, Sf_Ip_Ip)
//============================================================================



static void Test_Sf_Ip_L()
{
  {
    init_simple_test("Sf_Ip_L");
    STRUCT_IF_C Sf_Ip_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Sf_Ip_L)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_L)");
    check_field_offset(lv, v1, 0, "Sf_Ip_L.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_L.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Ip_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_L, Sf_Ip_L)
//============================================================================



static void Test_Sf_Ip_S()
{
  {
    init_simple_test("Sf_Ip_S");
    STRUCT_IF_C Sf_Ip_S lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Ip_S)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_S)");
    check_field_offset(lv, v1, 0, "Sf_Ip_S.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_S.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Ip_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_S, Sf_Ip_S)
//============================================================================



static void Test_Sf_Ip_Sf()
{
  {
    init_simple_test("Sf_Ip_Sf");
    STRUCT_IF_C Sf_Ip_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_Ip_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_Sf)");
    check_field_offset(lv, v1, 0, "Sf_Ip_Sf.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Ip_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_Sf, Sf_Ip_Sf)
//============================================================================



static void Test_Sf_Ip_Uc()
{
  {
    init_simple_test("Sf_Ip_Uc");
    STRUCT_IF_C Sf_Ip_Uc lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Ip_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_Uc)");
    check_field_offset(lv, v1, 0, "Sf_Ip_Uc.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_Uc.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Ip_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_Uc, Sf_Ip_Uc)
//============================================================================



static void Test_Sf_Ip_Ui()
{
  {
    init_simple_test("Sf_Ip_Ui");
    STRUCT_IF_C Sf_Ip_Ui lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Sf_Ip_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_Ui)");
    check_field_offset(lv, v1, 0, "Sf_Ip_Ui.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_Ui.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Ip_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_Ui, Sf_Ip_Ui)
//============================================================================



static void Test_Sf_Ip_Ul()
{
  {
    init_simple_test("Sf_Ip_Ul");
    STRUCT_IF_C Sf_Ip_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Sf_Ip_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_Ul)");
    check_field_offset(lv, v1, 0, "Sf_Ip_Ul.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_Ul.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Ip_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_Ul, Sf_Ip_Ul)
//============================================================================



static void Test_Sf_Ip_Us()
{
  {
    init_simple_test("Sf_Ip_Us");
    STRUCT_IF_C Sf_Ip_Us lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Ip_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_Us)");
    check_field_offset(lv, v1, 0, "Sf_Ip_Us.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_Us.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Ip_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_Us, Sf_Ip_Us)
//============================================================================



static void Test_Sf_Ip_Vp()
{
  {
    init_simple_test("Sf_Ip_Vp");
    STRUCT_IF_C Sf_Ip_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Sf_Ip_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_Vp)");
    check_field_offset(lv, v1, 0, "Sf_Ip_Vp.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_Vp.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Ip_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_Vp, Sf_Ip_Vp)
//============================================================================



static void Test_Sf_L()
{
  {
    init_simple_test("Sf_L");
    STRUCT_IF_C Sf_L lv;
    check2(sizeof(lv), 8, "sizeof(Sf_L)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L)");
    check_field_offset(lv, v1, 0, "Sf_L.v1");
    check_field_offset(lv, v2, 0, "Sf_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L, Sf_L)
//============================================================================



static void Test_Sf_L_BFu15i()
{
  {
    init_simple_test("Sf_L_BFu15i");
    static STRUCT_IF_C Sf_L_BFu15i lv;
    check2(sizeof(lv), 10, "sizeof(Sf_L_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu15i)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu15i.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu15i.v2");
    set_bf_and_test(lv, v3, 8, 0, 15, 1, "Sf_L_BFu15i");
    set_bf_and_test(lv, v3, 8, 0, 15, hide_ull(1LL<<14), "Sf_L_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu15i, Sf_L_BFu15i)
//============================================================================



static void Test_Sf_L_BFu15ll()
{
  {
    init_simple_test("Sf_L_BFu15ll");
    static STRUCT_IF_C Sf_L_BFu15ll lv;
    check2(sizeof(lv), 10, "sizeof(Sf_L_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu15ll)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu15ll.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu15ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 15, 1, "Sf_L_BFu15ll");
    set_bf_and_test(lv, v3, 8, 0, 15, hide_ull(1LL<<14), "Sf_L_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu15ll, Sf_L_BFu15ll)
//============================================================================



static void Test_Sf_L_BFu15s()
{
  {
    init_simple_test("Sf_L_BFu15s");
    static STRUCT_IF_C Sf_L_BFu15s lv;
    check2(sizeof(lv), 10, "sizeof(Sf_L_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu15s)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu15s.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu15s.v2");
    set_bf_and_test(lv, v3, 8, 0, 15, 1, "Sf_L_BFu15s");
    set_bf_and_test(lv, v3, 8, 0, 15, hide_ull(1LL<<14), "Sf_L_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu15s, Sf_L_BFu15s)
//============================================================================



static void Test_Sf_L_BFu16i()
{
  {
    init_simple_test("Sf_L_BFu16i");
    static STRUCT_IF_C Sf_L_BFu16i lv;
    check2(sizeof(lv), 10, "sizeof(Sf_L_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu16i)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu16i.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu16i.v2");
    set_bf_and_test(lv, v3, 8, 0, 16, 1, "Sf_L_BFu16i");
    set_bf_and_test(lv, v3, 8, 0, 16, hide_ull(1LL<<15), "Sf_L_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu16i, Sf_L_BFu16i)
//============================================================================



static void Test_Sf_L_BFu16ll()
{
  {
    init_simple_test("Sf_L_BFu16ll");
    static STRUCT_IF_C Sf_L_BFu16ll lv;
    check2(sizeof(lv), 10, "sizeof(Sf_L_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu16ll)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu16ll.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu16ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 16, 1, "Sf_L_BFu16ll");
    set_bf_and_test(lv, v3, 8, 0, 16, hide_ull(1LL<<15), "Sf_L_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu16ll, Sf_L_BFu16ll)
//============================================================================



static void Test_Sf_L_BFu16s()
{
  {
    init_simple_test("Sf_L_BFu16s");
    static STRUCT_IF_C Sf_L_BFu16s lv;
    check2(sizeof(lv), 10, "sizeof(Sf_L_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu16s)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu16s.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu16s.v2");
    set_bf_and_test(lv, v3, 8, 0, 16, 1, "Sf_L_BFu16s");
    set_bf_and_test(lv, v3, 8, 0, 16, hide_ull(1LL<<15), "Sf_L_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu16s, Sf_L_BFu16s)
//============================================================================



static void Test_Sf_L_BFu17i()
{
  {
    init_simple_test("Sf_L_BFu17i");
    static STRUCT_IF_C Sf_L_BFu17i lv;
    check2(sizeof(lv), 11, "sizeof(Sf_L_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu17i)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu17i.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu17i.v2");
    set_bf_and_test(lv, v3, 8, 0, 17, 1, "Sf_L_BFu17i");
    set_bf_and_test(lv, v3, 8, 0, 17, hide_ull(1LL<<16), "Sf_L_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu17i, Sf_L_BFu17i)
//============================================================================



static void Test_Sf_L_BFu17ll()
{
  {
    init_simple_test("Sf_L_BFu17ll");
    static STRUCT_IF_C Sf_L_BFu17ll lv;
    check2(sizeof(lv), 11, "sizeof(Sf_L_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu17ll)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu17ll.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu17ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 17, 1, "Sf_L_BFu17ll");
    set_bf_and_test(lv, v3, 8, 0, 17, hide_ull(1LL<<16), "Sf_L_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu17ll, Sf_L_BFu17ll)
//============================================================================



static void Test_Sf_L_BFu1c()
{
  {
    init_simple_test("Sf_L_BFu1c");
    static STRUCT_IF_C Sf_L_BFu1c lv;
    check2(sizeof(lv), 9, "sizeof(Sf_L_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu1c)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu1c.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu1c.v2");
    set_bf_and_test(lv, v3, 8, 0, 1, 1, "Sf_L_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu1c, Sf_L_BFu1c)
//============================================================================



static void Test_Sf_L_BFu1i()
{
  {
    init_simple_test("Sf_L_BFu1i");
    static STRUCT_IF_C Sf_L_BFu1i lv;
    check2(sizeof(lv), 9, "sizeof(Sf_L_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu1i)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu1i.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu1i.v2");
    set_bf_and_test(lv, v3, 8, 0, 1, 1, "Sf_L_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu1i, Sf_L_BFu1i)
//============================================================================



static void Test_Sf_L_BFu1ll()
{
  {
    init_simple_test("Sf_L_BFu1ll");
    static STRUCT_IF_C Sf_L_BFu1ll lv;
    check2(sizeof(lv), 9, "sizeof(Sf_L_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu1ll)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu1ll.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu1ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 1, 1, "Sf_L_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu1ll, Sf_L_BFu1ll)
//============================================================================



static void Test_Sf_L_BFu1s()
{
  {
    init_simple_test("Sf_L_BFu1s");
    static STRUCT_IF_C Sf_L_BFu1s lv;
    check2(sizeof(lv), 9, "sizeof(Sf_L_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu1s)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu1s.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu1s.v2");
    set_bf_and_test(lv, v3, 8, 0, 1, 1, "Sf_L_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu1s, Sf_L_BFu1s)
//============================================================================



static void Test_Sf_L_BFu31i()
{
  {
    init_simple_test("Sf_L_BFu31i");
    static STRUCT_IF_C Sf_L_BFu31i lv;
    check2(sizeof(lv), 12, "sizeof(Sf_L_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu31i)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu31i.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu31i.v2");
    set_bf_and_test(lv, v3, 8, 0, 31, 1, "Sf_L_BFu31i");
    set_bf_and_test(lv, v3, 8, 0, 31, hide_ull(1LL<<30), "Sf_L_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu31i, Sf_L_BFu31i)
//============================================================================



static void Test_Sf_L_BFu31ll()
{
  {
    init_simple_test("Sf_L_BFu31ll");
    static STRUCT_IF_C Sf_L_BFu31ll lv;
    check2(sizeof(lv), 12, "sizeof(Sf_L_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu31ll)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu31ll.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu31ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 31, 1, "Sf_L_BFu31ll");
    set_bf_and_test(lv, v3, 8, 0, 31, hide_ull(1LL<<30), "Sf_L_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu31ll, Sf_L_BFu31ll)
//============================================================================



static void Test_Sf_L_BFu32i()
{
  {
    init_simple_test("Sf_L_BFu32i");
    static STRUCT_IF_C Sf_L_BFu32i lv;
    check2(sizeof(lv), 12, "sizeof(Sf_L_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu32i)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu32i.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu32i.v2");
    set_bf_and_test(lv, v3, 8, 0, 32, 1, "Sf_L_BFu32i");
    set_bf_and_test(lv, v3, 8, 0, 32, hide_ull(1LL<<31), "Sf_L_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu32i, Sf_L_BFu32i)
//============================================================================



static void Test_Sf_L_BFu32ll()
{
  {
    init_simple_test("Sf_L_BFu32ll");
    static STRUCT_IF_C Sf_L_BFu32ll lv;
    check2(sizeof(lv), 12, "sizeof(Sf_L_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu32ll)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu32ll.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu32ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 32, 1, "Sf_L_BFu32ll");
    set_bf_and_test(lv, v3, 8, 0, 32, hide_ull(1LL<<31), "Sf_L_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu32ll, Sf_L_BFu32ll)
//============================================================================



static void Test_Sf_L_BFu33()
{
  {
    init_simple_test("Sf_L_BFu33");
    static STRUCT_IF_C Sf_L_BFu33 lv;
    check2(sizeof(lv), 13, "sizeof(Sf_L_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu33)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu33.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu33.v2");
    set_bf_and_test(lv, v3, 8, 0, 33, 1, "Sf_L_BFu33");
    set_bf_and_test(lv, v3, 8, 0, 33, hide_ull(1LL<<32), "Sf_L_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu33, Sf_L_BFu33)
//============================================================================



static void Test_Sf_L_BFu7c()
{
  {
    init_simple_test("Sf_L_BFu7c");
    static STRUCT_IF_C Sf_L_BFu7c lv;
    check2(sizeof(lv), 9, "sizeof(Sf_L_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu7c)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu7c.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu7c.v2");
    set_bf_and_test(lv, v3, 8, 0, 7, 1, "Sf_L_BFu7c");
    set_bf_and_test(lv, v3, 8, 0, 7, hide_ull(1LL<<6), "Sf_L_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu7c, Sf_L_BFu7c)
//============================================================================



static void Test_Sf_L_BFu7i()
{
  {
    init_simple_test("Sf_L_BFu7i");
    static STRUCT_IF_C Sf_L_BFu7i lv;
    check2(sizeof(lv), 9, "sizeof(Sf_L_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu7i)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu7i.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu7i.v2");
    set_bf_and_test(lv, v3, 8, 0, 7, 1, "Sf_L_BFu7i");
    set_bf_and_test(lv, v3, 8, 0, 7, hide_ull(1LL<<6), "Sf_L_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu7i, Sf_L_BFu7i)
//============================================================================



static void Test_Sf_L_BFu7ll()
{
  {
    init_simple_test("Sf_L_BFu7ll");
    static STRUCT_IF_C Sf_L_BFu7ll lv;
    check2(sizeof(lv), 9, "sizeof(Sf_L_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu7ll)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu7ll.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu7ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 7, 1, "Sf_L_BFu7ll");
    set_bf_and_test(lv, v3, 8, 0, 7, hide_ull(1LL<<6), "Sf_L_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu7ll, Sf_L_BFu7ll)
//============================================================================



static void Test_Sf_L_BFu7s()
{
  {
    init_simple_test("Sf_L_BFu7s");
    static STRUCT_IF_C Sf_L_BFu7s lv;
    check2(sizeof(lv), 9, "sizeof(Sf_L_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu7s)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu7s.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu7s.v2");
    set_bf_and_test(lv, v3, 8, 0, 7, 1, "Sf_L_BFu7s");
    set_bf_and_test(lv, v3, 8, 0, 7, hide_ull(1LL<<6), "Sf_L_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu7s, Sf_L_BFu7s)
//============================================================================



static void Test_Sf_L_BFu8c()
{
  {
    init_simple_test("Sf_L_BFu8c");
    static STRUCT_IF_C Sf_L_BFu8c lv;
    check2(sizeof(lv), 9, "sizeof(Sf_L_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu8c)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu8c.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu8c.v2");
    set_bf_and_test(lv, v3, 8, 0, 8, 1, "Sf_L_BFu8c");
    set_bf_and_test(lv, v3, 8, 0, 8, hide_ull(1LL<<7), "Sf_L_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu8c, Sf_L_BFu8c)
//============================================================================



static void Test_Sf_L_BFu8i()
{
  {
    init_simple_test("Sf_L_BFu8i");
    static STRUCT_IF_C Sf_L_BFu8i lv;
    check2(sizeof(lv), 9, "sizeof(Sf_L_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu8i)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu8i.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu8i.v2");
    set_bf_and_test(lv, v3, 8, 0, 8, 1, "Sf_L_BFu8i");
    set_bf_and_test(lv, v3, 8, 0, 8, hide_ull(1LL<<7), "Sf_L_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu8i, Sf_L_BFu8i)
//============================================================================



static void Test_Sf_L_BFu8ll()
{
  {
    init_simple_test("Sf_L_BFu8ll");
    static STRUCT_IF_C Sf_L_BFu8ll lv;
    check2(sizeof(lv), 9, "sizeof(Sf_L_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu8ll)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu8ll.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu8ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 8, 1, "Sf_L_BFu8ll");
    set_bf_and_test(lv, v3, 8, 0, 8, hide_ull(1LL<<7), "Sf_L_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu8ll, Sf_L_BFu8ll)
//============================================================================



static void Test_Sf_L_BFu8s()
{
  {
    init_simple_test("Sf_L_BFu8s");
    static STRUCT_IF_C Sf_L_BFu8s lv;
    check2(sizeof(lv), 9, "sizeof(Sf_L_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu8s)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu8s.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu8s.v2");
    set_bf_and_test(lv, v3, 8, 0, 8, 1, "Sf_L_BFu8s");
    set_bf_and_test(lv, v3, 8, 0, 8, hide_ull(1LL<<7), "Sf_L_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu8s, Sf_L_BFu8s)
//============================================================================



static void Test_Sf_L_BFu9i()
{
  {
    init_simple_test("Sf_L_BFu9i");
    static STRUCT_IF_C Sf_L_BFu9i lv;
    check2(sizeof(lv), 10, "sizeof(Sf_L_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu9i)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu9i.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu9i.v2");
    set_bf_and_test(lv, v3, 8, 0, 9, 1, "Sf_L_BFu9i");
    set_bf_and_test(lv, v3, 8, 0, 9, hide_ull(1LL<<8), "Sf_L_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu9i, Sf_L_BFu9i)
//============================================================================



static void Test_Sf_L_BFu9ll()
{
  {
    init_simple_test("Sf_L_BFu9ll");
    static STRUCT_IF_C Sf_L_BFu9ll lv;
    check2(sizeof(lv), 10, "sizeof(Sf_L_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu9ll)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu9ll.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu9ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 9, 1, "Sf_L_BFu9ll");
    set_bf_and_test(lv, v3, 8, 0, 9, hide_ull(1LL<<8), "Sf_L_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu9ll, Sf_L_BFu9ll)
//============================================================================



static void Test_Sf_L_BFu9s()
{
  {
    init_simple_test("Sf_L_BFu9s");
    static STRUCT_IF_C Sf_L_BFu9s lv;
    check2(sizeof(lv), 10, "sizeof(Sf_L_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_BFu9s)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu9s.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu9s.v2");
    set_bf_and_test(lv, v3, 8, 0, 9, 1, "Sf_L_BFu9s");
    set_bf_and_test(lv, v3, 8, 0, 9, hide_ull(1LL<<8), "Sf_L_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu9s, Sf_L_BFu9s)
//============================================================================



static void Test_Sf_L_C()
{
  {
    init_simple_test("Sf_L_C");
    STRUCT_IF_C Sf_L_C lv;
    check2(sizeof(lv), 9, "sizeof(Sf_L_C)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_C)");
    check_field_offset(lv, v1, 0, "Sf_L_C.v1");
    check_field_offset(lv, v2, 0, "Sf_L_C.v2");
    check_field_offset(lv, v3, 8, "Sf_L_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_C, Sf_L_C)
//============================================================================



static void Test_Sf_L_D()
{
  {
    init_simple_test("Sf_L_D");
    STRUCT_IF_C Sf_L_D lv;
    check2(sizeof(lv), 16, "sizeof(Sf_L_D)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_D)");
    check_field_offset(lv, v1, 0, "Sf_L_D.v1");
    check_field_offset(lv, v2, 0, "Sf_L_D.v2");
    check_field_offset(lv, v3, 8, "Sf_L_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_D, Sf_L_D)
//============================================================================



static void Test_Sf_L_F()
{
  {
    init_simple_test("Sf_L_F");
    STRUCT_IF_C Sf_L_F lv;
    check2(sizeof(lv), 12, "sizeof(Sf_L_F)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_F)");
    check_field_offset(lv, v1, 0, "Sf_L_F.v1");
    check_field_offset(lv, v2, 0, "Sf_L_F.v2");
    check_field_offset(lv, v3, 8, "Sf_L_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_F, Sf_L_F)
//============================================================================



static void Test_Sf_L_I()
{
  {
    init_simple_test("Sf_L_I");
    STRUCT_IF_C Sf_L_I lv;
    check2(sizeof(lv), 12, "sizeof(Sf_L_I)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_I)");
    check_field_offset(lv, v1, 0, "Sf_L_I.v1");
    check_field_offset(lv, v2, 0, "Sf_L_I.v2");
    check_field_offset(lv, v3, 8, "Sf_L_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_I, Sf_L_I)
//============================================================================



static void Test_Sf_L_Ip()
{
  {
    init_simple_test("Sf_L_Ip");
    STRUCT_IF_C Sf_L_Ip lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Sf_L_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_Ip)");
    check_field_offset(lv, v1, 0, "Sf_L_Ip.v1");
    check_field_offset(lv, v2, 0, "Sf_L_Ip.v2");
    check_field_offset(lv, v3, 8, "Sf_L_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_Ip, Sf_L_Ip)
//============================================================================



static void Test_Sf_L_L()
{
  {
    init_simple_test("Sf_L_L");
    STRUCT_IF_C Sf_L_L lv;
    check2(sizeof(lv), 16, "sizeof(Sf_L_L)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_L)");
    check_field_offset(lv, v1, 0, "Sf_L_L.v1");
    check_field_offset(lv, v2, 0, "Sf_L_L.v2");
    check_field_offset(lv, v3, 8, "Sf_L_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_L, Sf_L_L)
//============================================================================



static void Test_Sf_L_S()
{
  {
    init_simple_test("Sf_L_S");
    STRUCT_IF_C Sf_L_S lv;
    check2(sizeof(lv), 10, "sizeof(Sf_L_S)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_S)");
    check_field_offset(lv, v1, 0, "Sf_L_S.v1");
    check_field_offset(lv, v2, 0, "Sf_L_S.v2");
    check_field_offset(lv, v3, 8, "Sf_L_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_S, Sf_L_S)
//============================================================================



static void Test_Sf_L_Sf()
{
  {
    init_simple_test("Sf_L_Sf");
    STRUCT_IF_C Sf_L_Sf lv;
    check2(sizeof(lv), 8, "sizeof(Sf_L_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_Sf)");
    check_field_offset(lv, v1, 0, "Sf_L_Sf.v1");
    check_field_offset(lv, v2, 0, "Sf_L_Sf.v2");
    check_field_offset(lv, v3, 8, "Sf_L_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_Sf, Sf_L_Sf)
//============================================================================



static void Test_Sf_L_Uc()
{
  {
    init_simple_test("Sf_L_Uc");
    STRUCT_IF_C Sf_L_Uc lv;
    check2(sizeof(lv), 9, "sizeof(Sf_L_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_Uc)");
    check_field_offset(lv, v1, 0, "Sf_L_Uc.v1");
    check_field_offset(lv, v2, 0, "Sf_L_Uc.v2");
    check_field_offset(lv, v3, 8, "Sf_L_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_Uc, Sf_L_Uc)
//============================================================================



static void Test_Sf_L_Ui()
{
  {
    init_simple_test("Sf_L_Ui");
    STRUCT_IF_C Sf_L_Ui lv;
    check2(sizeof(lv), 12, "sizeof(Sf_L_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_Ui)");
    check_field_offset(lv, v1, 0, "Sf_L_Ui.v1");
    check_field_offset(lv, v2, 0, "Sf_L_Ui.v2");
    check_field_offset(lv, v3, 8, "Sf_L_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_Ui, Sf_L_Ui)
//============================================================================



static void Test_Sf_L_Ul()
{
  {
    init_simple_test("Sf_L_Ul");
    STRUCT_IF_C Sf_L_Ul lv;
    check2(sizeof(lv), 16, "sizeof(Sf_L_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_Ul)");
    check_field_offset(lv, v1, 0, "Sf_L_Ul.v1");
    check_field_offset(lv, v2, 0, "Sf_L_Ul.v2");
    check_field_offset(lv, v3, 8, "Sf_L_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_Ul, Sf_L_Ul)
//============================================================================



static void Test_Sf_L_Us()
{
  {
    init_simple_test("Sf_L_Us");
    STRUCT_IF_C Sf_L_Us lv;
    check2(sizeof(lv), 10, "sizeof(Sf_L_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_Us)");
    check_field_offset(lv, v1, 0, "Sf_L_Us.v1");
    check_field_offset(lv, v2, 0, "Sf_L_Us.v2");
    check_field_offset(lv, v3, 8, "Sf_L_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_Us, Sf_L_Us)
//============================================================================



static void Test_Sf_L_Vp()
{
  {
    init_simple_test("Sf_L_Vp");
    STRUCT_IF_C Sf_L_Vp lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Sf_L_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_Vp)");
    check_field_offset(lv, v1, 0, "Sf_L_Vp.v1");
    check_field_offset(lv, v2, 0, "Sf_L_Vp.v2");
    check_field_offset(lv, v3, 8, "Sf_L_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_Vp, Sf_L_Vp)
//============================================================================



static void Test_Sf_S()
{
  {
    init_simple_test("Sf_S");
    STRUCT_IF_C Sf_S lv;
    check2(sizeof(lv), 2, "sizeof(Sf_S)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S)");
    check_field_offset(lv, v1, 0, "Sf_S.v1");
    check_field_offset(lv, v2, 0, "Sf_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S, Sf_S)
//============================================================================



static void Test_Sf_S_BFu15i()
{
  {
    init_simple_test("Sf_S_BFu15i");
    static STRUCT_IF_C Sf_S_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_S_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu15i)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu15i.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu15i.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "Sf_S_BFu15i");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "Sf_S_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu15i, Sf_S_BFu15i)
//============================================================================



static void Test_Sf_S_BFu15ll()
{
  {
    init_simple_test("Sf_S_BFu15ll");
    static STRUCT_IF_C Sf_S_BFu15ll lv;
    check2(sizeof(lv), 4, "sizeof(Sf_S_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu15ll)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu15ll.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu15ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "Sf_S_BFu15ll");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "Sf_S_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu15ll, Sf_S_BFu15ll)
//============================================================================



static void Test_Sf_S_BFu15s()
{
  {
    init_simple_test("Sf_S_BFu15s");
    static STRUCT_IF_C Sf_S_BFu15s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_S_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu15s)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu15s.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu15s.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "Sf_S_BFu15s");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "Sf_S_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu15s, Sf_S_BFu15s)
//============================================================================



static void Test_Sf_S_BFu16i()
{
  {
    init_simple_test("Sf_S_BFu16i");
    static STRUCT_IF_C Sf_S_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_S_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu16i)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu16i.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu16i.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "Sf_S_BFu16i");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "Sf_S_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu16i, Sf_S_BFu16i)
//============================================================================



static void Test_Sf_S_BFu16ll()
{
  {
    init_simple_test("Sf_S_BFu16ll");
    static STRUCT_IF_C Sf_S_BFu16ll lv;
    check2(sizeof(lv), 4, "sizeof(Sf_S_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu16ll)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu16ll.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu16ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "Sf_S_BFu16ll");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "Sf_S_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu16ll, Sf_S_BFu16ll)
//============================================================================



static void Test_Sf_S_BFu16s()
{
  {
    init_simple_test("Sf_S_BFu16s");
    static STRUCT_IF_C Sf_S_BFu16s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_S_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu16s)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu16s.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu16s.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "Sf_S_BFu16s");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "Sf_S_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu16s, Sf_S_BFu16s)
//============================================================================



static void Test_Sf_S_BFu17i()
{
  {
    init_simple_test("Sf_S_BFu17i");
    static STRUCT_IF_C Sf_S_BFu17i lv;
    check2(sizeof(lv), 5, "sizeof(Sf_S_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu17i)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu17i.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu17i.v2");
    set_bf_and_test(lv, v3, 2, 0, 17, 1, "Sf_S_BFu17i");
    set_bf_and_test(lv, v3, 2, 0, 17, hide_ull(1LL<<16), "Sf_S_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu17i, Sf_S_BFu17i)
//============================================================================



static void Test_Sf_S_BFu17ll()
{
  {
    init_simple_test("Sf_S_BFu17ll");
    static STRUCT_IF_C Sf_S_BFu17ll lv;
    check2(sizeof(lv), 5, "sizeof(Sf_S_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu17ll)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu17ll.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu17ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 17, 1, "Sf_S_BFu17ll");
    set_bf_and_test(lv, v3, 2, 0, 17, hide_ull(1LL<<16), "Sf_S_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu17ll, Sf_S_BFu17ll)
//============================================================================



static void Test_Sf_S_BFu1c()
{
  {
    init_simple_test("Sf_S_BFu1c");
    static STRUCT_IF_C Sf_S_BFu1c lv;
    check2(sizeof(lv), 3, "sizeof(Sf_S_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu1c)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu1c.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu1c.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Sf_S_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu1c, Sf_S_BFu1c)
//============================================================================



static void Test_Sf_S_BFu1i()
{
  {
    init_simple_test("Sf_S_BFu1i");
    static STRUCT_IF_C Sf_S_BFu1i lv;
    check2(sizeof(lv), 3, "sizeof(Sf_S_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu1i)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu1i.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu1i.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Sf_S_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu1i, Sf_S_BFu1i)
//============================================================================



static void Test_Sf_S_BFu1ll()
{
  {
    init_simple_test("Sf_S_BFu1ll");
    static STRUCT_IF_C Sf_S_BFu1ll lv;
    check2(sizeof(lv), 3, "sizeof(Sf_S_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu1ll)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu1ll.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu1ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Sf_S_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu1ll, Sf_S_BFu1ll)
//============================================================================



static void Test_Sf_S_BFu1s()
{
  {
    init_simple_test("Sf_S_BFu1s");
    static STRUCT_IF_C Sf_S_BFu1s lv;
    check2(sizeof(lv), 3, "sizeof(Sf_S_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu1s)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu1s.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu1s.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Sf_S_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu1s, Sf_S_BFu1s)
//============================================================================



static void Test_Sf_S_BFu31i()
{
  {
    init_simple_test("Sf_S_BFu31i");
    static STRUCT_IF_C Sf_S_BFu31i lv;
    check2(sizeof(lv), 6, "sizeof(Sf_S_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu31i)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu31i.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu31i.v2");
    set_bf_and_test(lv, v3, 2, 0, 31, 1, "Sf_S_BFu31i");
    set_bf_and_test(lv, v3, 2, 0, 31, hide_ull(1LL<<30), "Sf_S_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu31i, Sf_S_BFu31i)
//============================================================================



static void Test_Sf_S_BFu31ll()
{
  {
    init_simple_test("Sf_S_BFu31ll");
    static STRUCT_IF_C Sf_S_BFu31ll lv;
    check2(sizeof(lv), 6, "sizeof(Sf_S_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu31ll)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu31ll.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu31ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 31, 1, "Sf_S_BFu31ll");
    set_bf_and_test(lv, v3, 2, 0, 31, hide_ull(1LL<<30), "Sf_S_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu31ll, Sf_S_BFu31ll)
//============================================================================



static void Test_Sf_S_BFu32i()
{
  {
    init_simple_test("Sf_S_BFu32i");
    static STRUCT_IF_C Sf_S_BFu32i lv;
    check2(sizeof(lv), 6, "sizeof(Sf_S_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu32i)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu32i.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu32i.v2");
    set_bf_and_test(lv, v3, 2, 0, 32, 1, "Sf_S_BFu32i");
    set_bf_and_test(lv, v3, 2, 0, 32, hide_ull(1LL<<31), "Sf_S_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu32i, Sf_S_BFu32i)
//============================================================================



static void Test_Sf_S_BFu32ll()
{
  {
    init_simple_test("Sf_S_BFu32ll");
    static STRUCT_IF_C Sf_S_BFu32ll lv;
    check2(sizeof(lv), 6, "sizeof(Sf_S_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu32ll)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu32ll.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu32ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 32, 1, "Sf_S_BFu32ll");
    set_bf_and_test(lv, v3, 2, 0, 32, hide_ull(1LL<<31), "Sf_S_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu32ll, Sf_S_BFu32ll)
//============================================================================



static void Test_Sf_S_BFu33()
{
  {
    init_simple_test("Sf_S_BFu33");
    static STRUCT_IF_C Sf_S_BFu33 lv;
    check2(sizeof(lv), 7, "sizeof(Sf_S_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu33)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu33.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu33.v2");
    set_bf_and_test(lv, v3, 2, 0, 33, 1, "Sf_S_BFu33");
    set_bf_and_test(lv, v3, 2, 0, 33, hide_ull(1LL<<32), "Sf_S_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu33, Sf_S_BFu33)
//============================================================================



static void Test_Sf_S_BFu7c()
{
  {
    init_simple_test("Sf_S_BFu7c");
    static STRUCT_IF_C Sf_S_BFu7c lv;
    check2(sizeof(lv), 3, "sizeof(Sf_S_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu7c)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu7c.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu7c.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Sf_S_BFu7c");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Sf_S_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu7c, Sf_S_BFu7c)
//============================================================================



static void Test_Sf_S_BFu7i()
{
  {
    init_simple_test("Sf_S_BFu7i");
    static STRUCT_IF_C Sf_S_BFu7i lv;
    check2(sizeof(lv), 3, "sizeof(Sf_S_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu7i)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu7i.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu7i.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Sf_S_BFu7i");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Sf_S_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu7i, Sf_S_BFu7i)
//============================================================================



static void Test_Sf_S_BFu7ll()
{
  {
    init_simple_test("Sf_S_BFu7ll");
    static STRUCT_IF_C Sf_S_BFu7ll lv;
    check2(sizeof(lv), 3, "sizeof(Sf_S_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu7ll)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu7ll.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu7ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Sf_S_BFu7ll");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Sf_S_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu7ll, Sf_S_BFu7ll)
//============================================================================



static void Test_Sf_S_BFu7s()
{
  {
    init_simple_test("Sf_S_BFu7s");
    static STRUCT_IF_C Sf_S_BFu7s lv;
    check2(sizeof(lv), 3, "sizeof(Sf_S_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu7s)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu7s.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu7s.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Sf_S_BFu7s");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Sf_S_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu7s, Sf_S_BFu7s)
//============================================================================



static void Test_Sf_S_BFu8c()
{
  {
    init_simple_test("Sf_S_BFu8c");
    static STRUCT_IF_C Sf_S_BFu8c lv;
    check2(sizeof(lv), 3, "sizeof(Sf_S_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu8c)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu8c.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu8c.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Sf_S_BFu8c");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Sf_S_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu8c, Sf_S_BFu8c)
//============================================================================



static void Test_Sf_S_BFu8i()
{
  {
    init_simple_test("Sf_S_BFu8i");
    static STRUCT_IF_C Sf_S_BFu8i lv;
    check2(sizeof(lv), 3, "sizeof(Sf_S_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu8i)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu8i.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu8i.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Sf_S_BFu8i");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Sf_S_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu8i, Sf_S_BFu8i)
//============================================================================



static void Test_Sf_S_BFu8ll()
{
  {
    init_simple_test("Sf_S_BFu8ll");
    static STRUCT_IF_C Sf_S_BFu8ll lv;
    check2(sizeof(lv), 3, "sizeof(Sf_S_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu8ll)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu8ll.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu8ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Sf_S_BFu8ll");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Sf_S_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu8ll, Sf_S_BFu8ll)
//============================================================================



static void Test_Sf_S_BFu8s()
{
  {
    init_simple_test("Sf_S_BFu8s");
    static STRUCT_IF_C Sf_S_BFu8s lv;
    check2(sizeof(lv), 3, "sizeof(Sf_S_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu8s)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu8s.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu8s.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Sf_S_BFu8s");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Sf_S_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu8s, Sf_S_BFu8s)
//============================================================================



static void Test_Sf_S_BFu9i()
{
  {
    init_simple_test("Sf_S_BFu9i");
    static STRUCT_IF_C Sf_S_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_S_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu9i)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu9i.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu9i.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "Sf_S_BFu9i");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "Sf_S_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu9i, Sf_S_BFu9i)
//============================================================================



static void Test_Sf_S_BFu9ll()
{
  {
    init_simple_test("Sf_S_BFu9ll");
    static STRUCT_IF_C Sf_S_BFu9ll lv;
    check2(sizeof(lv), 4, "sizeof(Sf_S_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu9ll)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu9ll.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu9ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "Sf_S_BFu9ll");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "Sf_S_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu9ll, Sf_S_BFu9ll)
//============================================================================



static void Test_Sf_S_BFu9s()
{
  {
    init_simple_test("Sf_S_BFu9s");
    static STRUCT_IF_C Sf_S_BFu9s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_S_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_BFu9s)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu9s.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu9s.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "Sf_S_BFu9s");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "Sf_S_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu9s, Sf_S_BFu9s)
//============================================================================



static void Test_Sf_S_C()
{
  {
    init_simple_test("Sf_S_C");
    STRUCT_IF_C Sf_S_C lv;
    check2(sizeof(lv), 3, "sizeof(Sf_S_C)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_C)");
    check_field_offset(lv, v1, 0, "Sf_S_C.v1");
    check_field_offset(lv, v2, 0, "Sf_S_C.v2");
    check_field_offset(lv, v3, 2, "Sf_S_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_C, Sf_S_C)
//============================================================================



static void Test_Sf_S_D()
{
  {
    init_simple_test("Sf_S_D");
    STRUCT_IF_C Sf_S_D lv;
    check2(sizeof(lv), 10, "sizeof(Sf_S_D)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_D)");
    check_field_offset(lv, v1, 0, "Sf_S_D.v1");
    check_field_offset(lv, v2, 0, "Sf_S_D.v2");
    check_field_offset(lv, v3, 2, "Sf_S_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_D, Sf_S_D)
//============================================================================



static void Test_Sf_S_F()
{
  {
    init_simple_test("Sf_S_F");
    STRUCT_IF_C Sf_S_F lv;
    check2(sizeof(lv), 6, "sizeof(Sf_S_F)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_F)");
    check_field_offset(lv, v1, 0, "Sf_S_F.v1");
    check_field_offset(lv, v2, 0, "Sf_S_F.v2");
    check_field_offset(lv, v3, 2, "Sf_S_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_F, Sf_S_F)
//============================================================================



static void Test_Sf_S_I()
{
  {
    init_simple_test("Sf_S_I");
    STRUCT_IF_C Sf_S_I lv;
    check2(sizeof(lv), 6, "sizeof(Sf_S_I)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_I)");
    check_field_offset(lv, v1, 0, "Sf_S_I.v1");
    check_field_offset(lv, v2, 0, "Sf_S_I.v2");
    check_field_offset(lv, v3, 2, "Sf_S_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_I, Sf_S_I)
//============================================================================



static void Test_Sf_S_Ip()
{
  {
    init_simple_test("Sf_S_Ip");
    STRUCT_IF_C Sf_S_Ip lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_S_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_Ip)");
    check_field_offset(lv, v1, 0, "Sf_S_Ip.v1");
    check_field_offset(lv, v2, 0, "Sf_S_Ip.v2");
    check_field_offset(lv, v3, 2, "Sf_S_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_Ip, Sf_S_Ip)
//============================================================================



static void Test_Sf_S_L()
{
  {
    init_simple_test("Sf_S_L");
    STRUCT_IF_C Sf_S_L lv;
    check2(sizeof(lv), 10, "sizeof(Sf_S_L)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_L)");
    check_field_offset(lv, v1, 0, "Sf_S_L.v1");
    check_field_offset(lv, v2, 0, "Sf_S_L.v2");
    check_field_offset(lv, v3, 2, "Sf_S_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_L, Sf_S_L)
//============================================================================



static void Test_Sf_S_S()
{
  {
    init_simple_test("Sf_S_S");
    STRUCT_IF_C Sf_S_S lv;
    check2(sizeof(lv), 4, "sizeof(Sf_S_S)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_S)");
    check_field_offset(lv, v1, 0, "Sf_S_S.v1");
    check_field_offset(lv, v2, 0, "Sf_S_S.v2");
    check_field_offset(lv, v3, 2, "Sf_S_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_S, Sf_S_S)
//============================================================================



static void Test_Sf_S_Sf()
{
  {
    init_simple_test("Sf_S_Sf");
    STRUCT_IF_C Sf_S_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Sf_S_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_Sf)");
    check_field_offset(lv, v1, 0, "Sf_S_Sf.v1");
    check_field_offset(lv, v2, 0, "Sf_S_Sf.v2");
    check_field_offset(lv, v3, 2, "Sf_S_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_Sf, Sf_S_Sf)
//============================================================================



static void Test_Sf_S_Uc()
{
  {
    init_simple_test("Sf_S_Uc");
    STRUCT_IF_C Sf_S_Uc lv;
    check2(sizeof(lv), 3, "sizeof(Sf_S_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_Uc)");
    check_field_offset(lv, v1, 0, "Sf_S_Uc.v1");
    check_field_offset(lv, v2, 0, "Sf_S_Uc.v2");
    check_field_offset(lv, v3, 2, "Sf_S_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_Uc, Sf_S_Uc)
//============================================================================



static void Test_Sf_S_Ui()
{
  {
    init_simple_test("Sf_S_Ui");
    STRUCT_IF_C Sf_S_Ui lv;
    check2(sizeof(lv), 6, "sizeof(Sf_S_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_Ui)");
    check_field_offset(lv, v1, 0, "Sf_S_Ui.v1");
    check_field_offset(lv, v2, 0, "Sf_S_Ui.v2");
    check_field_offset(lv, v3, 2, "Sf_S_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_Ui, Sf_S_Ui)
//============================================================================



static void Test_Sf_S_Ul()
{
  {
    init_simple_test("Sf_S_Ul");
    STRUCT_IF_C Sf_S_Ul lv;
    check2(sizeof(lv), 10, "sizeof(Sf_S_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_Ul)");
    check_field_offset(lv, v1, 0, "Sf_S_Ul.v1");
    check_field_offset(lv, v2, 0, "Sf_S_Ul.v2");
    check_field_offset(lv, v3, 2, "Sf_S_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_Ul, Sf_S_Ul)
//============================================================================



static void Test_Sf_S_Us()
{
  {
    init_simple_test("Sf_S_Us");
    STRUCT_IF_C Sf_S_Us lv;
    check2(sizeof(lv), 4, "sizeof(Sf_S_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_Us)");
    check_field_offset(lv, v1, 0, "Sf_S_Us.v1");
    check_field_offset(lv, v2, 0, "Sf_S_Us.v2");
    check_field_offset(lv, v3, 2, "Sf_S_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_Us, Sf_S_Us)
//============================================================================



static void Test_Sf_S_Vp()
{
  {
    init_simple_test("Sf_S_Vp");
    STRUCT_IF_C Sf_S_Vp lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_S_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_Vp)");
    check_field_offset(lv, v1, 0, "Sf_S_Vp.v1");
    check_field_offset(lv, v2, 0, "Sf_S_Vp.v2");
    check_field_offset(lv, v3, 2, "Sf_S_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_Vp, Sf_S_Vp)
//============================================================================



static void Test_Sf_Sf()
{
  {
    init_simple_test("Sf_Sf");
    STRUCT_IF_C Sf_Sf lv;
    check2(sizeof(lv), 0, "sizeof(Sf_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf)");
    check_field_offset(lv, v1, 0, "Sf_Sf.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf, Sf_Sf)
//============================================================================



static void Test_Sf_Sf_BFu15i()
{
  {
    init_simple_test("Sf_Sf_BFu15i");
    static STRUCT_IF_C Sf_Sf_BFu15i lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Sf_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu15i)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu15i.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu15i.v2");
    set_bf_and_test(lv, v3, 0, 0, 15, 1, "Sf_Sf_BFu15i");
    set_bf_and_test(lv, v3, 0, 0, 15, hide_ull(1LL<<14), "Sf_Sf_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu15i, Sf_Sf_BFu15i)
//============================================================================



static void Test_Sf_Sf_BFu15ll()
{
  {
    init_simple_test("Sf_Sf_BFu15ll");
    static STRUCT_IF_C Sf_Sf_BFu15ll lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Sf_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu15ll)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu15ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu15ll.v2");
    set_bf_and_test(lv, v3, 0, 0, 15, 1, "Sf_Sf_BFu15ll");
    set_bf_and_test(lv, v3, 0, 0, 15, hide_ull(1LL<<14), "Sf_Sf_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu15ll, Sf_Sf_BFu15ll)
//============================================================================



static void Test_Sf_Sf_BFu15s()
{
  {
    init_simple_test("Sf_Sf_BFu15s");
    static STRUCT_IF_C Sf_Sf_BFu15s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Sf_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu15s)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu15s.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu15s.v2");
    set_bf_and_test(lv, v3, 0, 0, 15, 1, "Sf_Sf_BFu15s");
    set_bf_and_test(lv, v3, 0, 0, 15, hide_ull(1LL<<14), "Sf_Sf_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu15s, Sf_Sf_BFu15s)
//============================================================================



static void Test_Sf_Sf_BFu16i()
{
  {
    init_simple_test("Sf_Sf_BFu16i");
    static STRUCT_IF_C Sf_Sf_BFu16i lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Sf_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu16i)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu16i.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu16i.v2");
    set_bf_and_test(lv, v3, 0, 0, 16, 1, "Sf_Sf_BFu16i");
    set_bf_and_test(lv, v3, 0, 0, 16, hide_ull(1LL<<15), "Sf_Sf_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu16i, Sf_Sf_BFu16i)
//============================================================================



static void Test_Sf_Sf_BFu16ll()
{
  {
    init_simple_test("Sf_Sf_BFu16ll");
    static STRUCT_IF_C Sf_Sf_BFu16ll lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Sf_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu16ll)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu16ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu16ll.v2");
    set_bf_and_test(lv, v3, 0, 0, 16, 1, "Sf_Sf_BFu16ll");
    set_bf_and_test(lv, v3, 0, 0, 16, hide_ull(1LL<<15), "Sf_Sf_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu16ll, Sf_Sf_BFu16ll)
//============================================================================



static void Test_Sf_Sf_BFu16s()
{
  {
    init_simple_test("Sf_Sf_BFu16s");
    static STRUCT_IF_C Sf_Sf_BFu16s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Sf_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu16s)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu16s.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu16s.v2");
    set_bf_and_test(lv, v3, 0, 0, 16, 1, "Sf_Sf_BFu16s");
    set_bf_and_test(lv, v3, 0, 0, 16, hide_ull(1LL<<15), "Sf_Sf_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu16s, Sf_Sf_BFu16s)
//============================================================================



static void Test_Sf_Sf_BFu17i()
{
  {
    init_simple_test("Sf_Sf_BFu17i");
    static STRUCT_IF_C Sf_Sf_BFu17i lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Sf_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu17i)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu17i.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu17i.v2");
    set_bf_and_test(lv, v3, 0, 0, 17, 1, "Sf_Sf_BFu17i");
    set_bf_and_test(lv, v3, 0, 0, 17, hide_ull(1LL<<16), "Sf_Sf_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu17i, Sf_Sf_BFu17i)
//============================================================================



static void Test_Sf_Sf_BFu17ll()
{
  {
    init_simple_test("Sf_Sf_BFu17ll");
    static STRUCT_IF_C Sf_Sf_BFu17ll lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Sf_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu17ll)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu17ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu17ll.v2");
    set_bf_and_test(lv, v3, 0, 0, 17, 1, "Sf_Sf_BFu17ll");
    set_bf_and_test(lv, v3, 0, 0, 17, hide_ull(1LL<<16), "Sf_Sf_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu17ll, Sf_Sf_BFu17ll)
//============================================================================



static void Test_Sf_Sf_BFu1c()
{
  {
    init_simple_test("Sf_Sf_BFu1c");
    static STRUCT_IF_C Sf_Sf_BFu1c lv;
    check2(sizeof(lv), 1, "sizeof(Sf_Sf_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu1c)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu1c.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu1c.v2");
    set_bf_and_test(lv, v3, 0, 0, 1, 1, "Sf_Sf_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu1c, Sf_Sf_BFu1c)
//============================================================================



static void Test_Sf_Sf_BFu1i()
{
  {
    init_simple_test("Sf_Sf_BFu1i");
    static STRUCT_IF_C Sf_Sf_BFu1i lv;
    check2(sizeof(lv), 1, "sizeof(Sf_Sf_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu1i)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu1i.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu1i.v2");
    set_bf_and_test(lv, v3, 0, 0, 1, 1, "Sf_Sf_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu1i, Sf_Sf_BFu1i)
//============================================================================



static void Test_Sf_Sf_BFu1ll()
{
  {
    init_simple_test("Sf_Sf_BFu1ll");
    static STRUCT_IF_C Sf_Sf_BFu1ll lv;
    check2(sizeof(lv), 1, "sizeof(Sf_Sf_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu1ll)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu1ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu1ll.v2");
    set_bf_and_test(lv, v3, 0, 0, 1, 1, "Sf_Sf_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu1ll, Sf_Sf_BFu1ll)
//============================================================================



static void Test_Sf_Sf_BFu1s()
{
  {
    init_simple_test("Sf_Sf_BFu1s");
    static STRUCT_IF_C Sf_Sf_BFu1s lv;
    check2(sizeof(lv), 1, "sizeof(Sf_Sf_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu1s)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu1s.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu1s.v2");
    set_bf_and_test(lv, v3, 0, 0, 1, 1, "Sf_Sf_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu1s, Sf_Sf_BFu1s)
//============================================================================



static void Test_Sf_Sf_BFu31i()
{
  {
    init_simple_test("Sf_Sf_BFu31i");
    static STRUCT_IF_C Sf_Sf_BFu31i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Sf_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu31i)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu31i.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu31i.v2");
    set_bf_and_test(lv, v3, 0, 0, 31, 1, "Sf_Sf_BFu31i");
    set_bf_and_test(lv, v3, 0, 0, 31, hide_ull(1LL<<30), "Sf_Sf_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu31i, Sf_Sf_BFu31i)
//============================================================================



static void Test_Sf_Sf_BFu31ll()
{
  {
    init_simple_test("Sf_Sf_BFu31ll");
    static STRUCT_IF_C Sf_Sf_BFu31ll lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Sf_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu31ll)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu31ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu31ll.v2");
    set_bf_and_test(lv, v3, 0, 0, 31, 1, "Sf_Sf_BFu31ll");
    set_bf_and_test(lv, v3, 0, 0, 31, hide_ull(1LL<<30), "Sf_Sf_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu31ll, Sf_Sf_BFu31ll)
//============================================================================



static void Test_Sf_Sf_BFu32i()
{
  {
    init_simple_test("Sf_Sf_BFu32i");
    static STRUCT_IF_C Sf_Sf_BFu32i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Sf_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu32i)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu32i.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu32i.v2");
    set_bf_and_test(lv, v3, 0, 0, 32, 1, "Sf_Sf_BFu32i");
    set_bf_and_test(lv, v3, 0, 0, 32, hide_ull(1LL<<31), "Sf_Sf_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu32i, Sf_Sf_BFu32i)
//============================================================================



static void Test_Sf_Sf_BFu32ll()
{
  {
    init_simple_test("Sf_Sf_BFu32ll");
    static STRUCT_IF_C Sf_Sf_BFu32ll lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Sf_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu32ll)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu32ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu32ll.v2");
    set_bf_and_test(lv, v3, 0, 0, 32, 1, "Sf_Sf_BFu32ll");
    set_bf_and_test(lv, v3, 0, 0, 32, hide_ull(1LL<<31), "Sf_Sf_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu32ll, Sf_Sf_BFu32ll)
//============================================================================



static void Test_Sf_Sf_BFu33()
{
  {
    init_simple_test("Sf_Sf_BFu33");
    static STRUCT_IF_C Sf_Sf_BFu33 lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Sf_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu33)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu33.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu33.v2");
    set_bf_and_test(lv, v3, 0, 0, 33, 1, "Sf_Sf_BFu33");
    set_bf_and_test(lv, v3, 0, 0, 33, hide_ull(1LL<<32), "Sf_Sf_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu33, Sf_Sf_BFu33)
//============================================================================



static void Test_Sf_Sf_BFu7c()
{
  {
    init_simple_test("Sf_Sf_BFu7c");
    static STRUCT_IF_C Sf_Sf_BFu7c lv;
    check2(sizeof(lv), 1, "sizeof(Sf_Sf_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu7c)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu7c.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu7c.v2");
    set_bf_and_test(lv, v3, 0, 0, 7, 1, "Sf_Sf_BFu7c");
    set_bf_and_test(lv, v3, 0, 0, 7, hide_ull(1LL<<6), "Sf_Sf_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu7c, Sf_Sf_BFu7c)
//============================================================================



static void Test_Sf_Sf_BFu7i()
{
  {
    init_simple_test("Sf_Sf_BFu7i");
    static STRUCT_IF_C Sf_Sf_BFu7i lv;
    check2(sizeof(lv), 1, "sizeof(Sf_Sf_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu7i)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu7i.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu7i.v2");
    set_bf_and_test(lv, v3, 0, 0, 7, 1, "Sf_Sf_BFu7i");
    set_bf_and_test(lv, v3, 0, 0, 7, hide_ull(1LL<<6), "Sf_Sf_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu7i, Sf_Sf_BFu7i)
//============================================================================



static void Test_Sf_Sf_BFu7ll()
{
  {
    init_simple_test("Sf_Sf_BFu7ll");
    static STRUCT_IF_C Sf_Sf_BFu7ll lv;
    check2(sizeof(lv), 1, "sizeof(Sf_Sf_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu7ll)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu7ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu7ll.v2");
    set_bf_and_test(lv, v3, 0, 0, 7, 1, "Sf_Sf_BFu7ll");
    set_bf_and_test(lv, v3, 0, 0, 7, hide_ull(1LL<<6), "Sf_Sf_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu7ll, Sf_Sf_BFu7ll)
//============================================================================



static void Test_Sf_Sf_BFu7s()
{
  {
    init_simple_test("Sf_Sf_BFu7s");
    static STRUCT_IF_C Sf_Sf_BFu7s lv;
    check2(sizeof(lv), 1, "sizeof(Sf_Sf_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu7s)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu7s.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu7s.v2");
    set_bf_and_test(lv, v3, 0, 0, 7, 1, "Sf_Sf_BFu7s");
    set_bf_and_test(lv, v3, 0, 0, 7, hide_ull(1LL<<6), "Sf_Sf_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu7s, Sf_Sf_BFu7s)
//============================================================================



static void Test_Sf_Sf_BFu8c()
{
  {
    init_simple_test("Sf_Sf_BFu8c");
    static STRUCT_IF_C Sf_Sf_BFu8c lv;
    check2(sizeof(lv), 1, "sizeof(Sf_Sf_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu8c)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu8c.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu8c.v2");
    set_bf_and_test(lv, v3, 0, 0, 8, 1, "Sf_Sf_BFu8c");
    set_bf_and_test(lv, v3, 0, 0, 8, hide_ull(1LL<<7), "Sf_Sf_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu8c, Sf_Sf_BFu8c)
//============================================================================



static void Test_Sf_Sf_BFu8i()
{
  {
    init_simple_test("Sf_Sf_BFu8i");
    static STRUCT_IF_C Sf_Sf_BFu8i lv;
    check2(sizeof(lv), 1, "sizeof(Sf_Sf_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu8i)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu8i.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu8i.v2");
    set_bf_and_test(lv, v3, 0, 0, 8, 1, "Sf_Sf_BFu8i");
    set_bf_and_test(lv, v3, 0, 0, 8, hide_ull(1LL<<7), "Sf_Sf_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu8i, Sf_Sf_BFu8i)
//============================================================================



static void Test_Sf_Sf_BFu8ll()
{
  {
    init_simple_test("Sf_Sf_BFu8ll");
    static STRUCT_IF_C Sf_Sf_BFu8ll lv;
    check2(sizeof(lv), 1, "sizeof(Sf_Sf_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu8ll)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu8ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu8ll.v2");
    set_bf_and_test(lv, v3, 0, 0, 8, 1, "Sf_Sf_BFu8ll");
    set_bf_and_test(lv, v3, 0, 0, 8, hide_ull(1LL<<7), "Sf_Sf_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu8ll, Sf_Sf_BFu8ll)
//============================================================================



static void Test_Sf_Sf_BFu8s()
{
  {
    init_simple_test("Sf_Sf_BFu8s");
    static STRUCT_IF_C Sf_Sf_BFu8s lv;
    check2(sizeof(lv), 1, "sizeof(Sf_Sf_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu8s)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu8s.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu8s.v2");
    set_bf_and_test(lv, v3, 0, 0, 8, 1, "Sf_Sf_BFu8s");
    set_bf_and_test(lv, v3, 0, 0, 8, hide_ull(1LL<<7), "Sf_Sf_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu8s, Sf_Sf_BFu8s)
//============================================================================



static void Test_Sf_Sf_BFu9i()
{
  {
    init_simple_test("Sf_Sf_BFu9i");
    static STRUCT_IF_C Sf_Sf_BFu9i lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Sf_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu9i)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu9i.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu9i.v2");
    set_bf_and_test(lv, v3, 0, 0, 9, 1, "Sf_Sf_BFu9i");
    set_bf_and_test(lv, v3, 0, 0, 9, hide_ull(1LL<<8), "Sf_Sf_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu9i, Sf_Sf_BFu9i)
//============================================================================



static void Test_Sf_Sf_BFu9ll()
{
  {
    init_simple_test("Sf_Sf_BFu9ll");
    static STRUCT_IF_C Sf_Sf_BFu9ll lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Sf_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu9ll)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu9ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu9ll.v2");
    set_bf_and_test(lv, v3, 0, 0, 9, 1, "Sf_Sf_BFu9ll");
    set_bf_and_test(lv, v3, 0, 0, 9, hide_ull(1LL<<8), "Sf_Sf_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu9ll, Sf_Sf_BFu9ll)
//============================================================================



static void Test_Sf_Sf_BFu9s()
{
  {
    init_simple_test("Sf_Sf_BFu9s");
    static STRUCT_IF_C Sf_Sf_BFu9s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Sf_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu9s)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu9s.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu9s.v2");
    set_bf_and_test(lv, v3, 0, 0, 9, 1, "Sf_Sf_BFu9s");
    set_bf_and_test(lv, v3, 0, 0, 9, hide_ull(1LL<<8), "Sf_Sf_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu9s, Sf_Sf_BFu9s)
//============================================================================



static void Test_Sf_Sf_C()
{
  {
    init_simple_test("Sf_Sf_C");
    STRUCT_IF_C Sf_Sf_C lv;
    check2(sizeof(lv), 1, "sizeof(Sf_Sf_C)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_C)");
    check_field_offset(lv, v1, 0, "Sf_Sf_C.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_C.v2");
    check_field_offset(lv, v3, 0, "Sf_Sf_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_C, Sf_Sf_C)
//============================================================================



static void Test_Sf_Sf_D()
{
  {
    init_simple_test("Sf_Sf_D");
    STRUCT_IF_C Sf_Sf_D lv;
    check2(sizeof(lv), 8, "sizeof(Sf_Sf_D)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_D)");
    check_field_offset(lv, v1, 0, "Sf_Sf_D.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_D.v2");
    check_field_offset(lv, v3, 0, "Sf_Sf_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_D, Sf_Sf_D)
//============================================================================



static void Test_Sf_Sf_F()
{
  {
    init_simple_test("Sf_Sf_F");
    STRUCT_IF_C Sf_Sf_F lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Sf_F)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_F)");
    check_field_offset(lv, v1, 0, "Sf_Sf_F.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_F.v2");
    check_field_offset(lv, v3, 0, "Sf_Sf_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_F, Sf_Sf_F)
//============================================================================



static void Test_Sf_Sf_I()
{
  {
    init_simple_test("Sf_Sf_I");
    STRUCT_IF_C Sf_Sf_I lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Sf_I)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_I)");
    check_field_offset(lv, v1, 0, "Sf_Sf_I.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_I.v2");
    check_field_offset(lv, v3, 0, "Sf_Sf_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_I, Sf_Sf_I)
//============================================================================



static void Test_Sf_Sf_Ip()
{
  {
    init_simple_test("Sf_Sf_Ip");
    STRUCT_IF_C Sf_Sf_Ip lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_Sf_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_Ip)");
    check_field_offset(lv, v1, 0, "Sf_Sf_Ip.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_Ip.v2");
    check_field_offset(lv, v3, 0, "Sf_Sf_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_Ip, Sf_Sf_Ip)
//============================================================================



static void Test_Sf_Sf_L()
{
  {
    init_simple_test("Sf_Sf_L");
    STRUCT_IF_C Sf_Sf_L lv;
    check2(sizeof(lv), 8, "sizeof(Sf_Sf_L)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_L)");
    check_field_offset(lv, v1, 0, "Sf_Sf_L.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_L.v2");
    check_field_offset(lv, v3, 0, "Sf_Sf_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_L, Sf_Sf_L)
//============================================================================



static void Test_Sf_Sf_S()
{
  {
    init_simple_test("Sf_Sf_S");
    STRUCT_IF_C Sf_Sf_S lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Sf_S)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_S)");
    check_field_offset(lv, v1, 0, "Sf_Sf_S.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_S.v2");
    check_field_offset(lv, v3, 0, "Sf_Sf_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_S, Sf_Sf_S)
//============================================================================



static void Test_Sf_Sf_Sf()
{
  {
    init_simple_test("Sf_Sf_Sf");
    STRUCT_IF_C Sf_Sf_Sf lv;
    check2(sizeof(lv), 0, "sizeof(Sf_Sf_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_Sf)");
    check_field_offset(lv, v1, 0, "Sf_Sf_Sf.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_Sf.v2");
    check_field_offset(lv, v3, 0, "Sf_Sf_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_Sf, Sf_Sf_Sf)
//============================================================================



static void Test_Sf_Sf_Uc()
{
  {
    init_simple_test("Sf_Sf_Uc");
    STRUCT_IF_C Sf_Sf_Uc lv;
    check2(sizeof(lv), 1, "sizeof(Sf_Sf_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_Uc)");
    check_field_offset(lv, v1, 0, "Sf_Sf_Uc.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_Uc.v2");
    check_field_offset(lv, v3, 0, "Sf_Sf_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_Uc, Sf_Sf_Uc)
//============================================================================



static void Test_Sf_Sf_Ui()
{
  {
    init_simple_test("Sf_Sf_Ui");
    STRUCT_IF_C Sf_Sf_Ui lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Sf_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_Ui)");
    check_field_offset(lv, v1, 0, "Sf_Sf_Ui.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_Ui.v2");
    check_field_offset(lv, v3, 0, "Sf_Sf_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_Ui, Sf_Sf_Ui)
//============================================================================



static void Test_Sf_Sf_Ul()
{
  {
    init_simple_test("Sf_Sf_Ul");
    STRUCT_IF_C Sf_Sf_Ul lv;
    check2(sizeof(lv), 8, "sizeof(Sf_Sf_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_Ul)");
    check_field_offset(lv, v1, 0, "Sf_Sf_Ul.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_Ul.v2");
    check_field_offset(lv, v3, 0, "Sf_Sf_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_Ul, Sf_Sf_Ul)
//============================================================================



static void Test_Sf_Sf_Us()
{
  {
    init_simple_test("Sf_Sf_Us");
    STRUCT_IF_C Sf_Sf_Us lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Sf_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_Us)");
    check_field_offset(lv, v1, 0, "Sf_Sf_Us.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_Us.v2");
    check_field_offset(lv, v3, 0, "Sf_Sf_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_Us, Sf_Sf_Us)
//============================================================================



static void Test_Sf_Sf_Vp()
{
  {
    init_simple_test("Sf_Sf_Vp");
    STRUCT_IF_C Sf_Sf_Vp lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_Sf_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_Vp)");
    check_field_offset(lv, v1, 0, "Sf_Sf_Vp.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_Vp.v2");
    check_field_offset(lv, v3, 0, "Sf_Sf_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_Vp, Sf_Sf_Vp)
//============================================================================



static void Test_Sf_Uc()
{
  {
    init_simple_test("Sf_Uc");
    STRUCT_IF_C Sf_Uc lv;
    check2(sizeof(lv), 1, "sizeof(Sf_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc)");
    check_field_offset(lv, v1, 0, "Sf_Uc.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc, Sf_Uc)
//============================================================================



static void Test_Sf_Uc_BFu15i()
{
  {
    init_simple_test("Sf_Uc_BFu15i");
    static STRUCT_IF_C Sf_Uc_BFu15i lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Uc_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu15i)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu15i.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu15i.v2");
    set_bf_and_test(lv, v3, 1, 0, 15, 1, "Sf_Uc_BFu15i");
    set_bf_and_test(lv, v3, 1, 0, 15, hide_ull(1LL<<14), "Sf_Uc_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu15i, Sf_Uc_BFu15i)
//============================================================================



static void Test_Sf_Uc_BFu15ll()
{
  {
    init_simple_test("Sf_Uc_BFu15ll");
    static STRUCT_IF_C Sf_Uc_BFu15ll lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Uc_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu15ll)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu15ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu15ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 15, 1, "Sf_Uc_BFu15ll");
    set_bf_and_test(lv, v3, 1, 0, 15, hide_ull(1LL<<14), "Sf_Uc_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu15ll, Sf_Uc_BFu15ll)
//============================================================================



static void Test_Sf_Uc_BFu15s()
{
  {
    init_simple_test("Sf_Uc_BFu15s");
    static STRUCT_IF_C Sf_Uc_BFu15s lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Uc_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu15s)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu15s.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu15s.v2");
    set_bf_and_test(lv, v3, 1, 0, 15, 1, "Sf_Uc_BFu15s");
    set_bf_and_test(lv, v3, 1, 0, 15, hide_ull(1LL<<14), "Sf_Uc_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu15s, Sf_Uc_BFu15s)
//============================================================================



static void Test_Sf_Uc_BFu16i()
{
  {
    init_simple_test("Sf_Uc_BFu16i");
    static STRUCT_IF_C Sf_Uc_BFu16i lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Uc_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu16i)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu16i.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu16i.v2");
    set_bf_and_test(lv, v3, 1, 0, 16, 1, "Sf_Uc_BFu16i");
    set_bf_and_test(lv, v3, 1, 0, 16, hide_ull(1LL<<15), "Sf_Uc_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu16i, Sf_Uc_BFu16i)
//============================================================================



static void Test_Sf_Uc_BFu16ll()
{
  {
    init_simple_test("Sf_Uc_BFu16ll");
    static STRUCT_IF_C Sf_Uc_BFu16ll lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Uc_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu16ll)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu16ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu16ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 16, 1, "Sf_Uc_BFu16ll");
    set_bf_and_test(lv, v3, 1, 0, 16, hide_ull(1LL<<15), "Sf_Uc_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu16ll, Sf_Uc_BFu16ll)
//============================================================================



static void Test_Sf_Uc_BFu16s()
{
  {
    init_simple_test("Sf_Uc_BFu16s");
    static STRUCT_IF_C Sf_Uc_BFu16s lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Uc_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu16s)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu16s.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu16s.v2");
    set_bf_and_test(lv, v3, 1, 0, 16, 1, "Sf_Uc_BFu16s");
    set_bf_and_test(lv, v3, 1, 0, 16, hide_ull(1LL<<15), "Sf_Uc_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu16s, Sf_Uc_BFu16s)
//============================================================================



static void Test_Sf_Uc_BFu17i()
{
  {
    init_simple_test("Sf_Uc_BFu17i");
    static STRUCT_IF_C Sf_Uc_BFu17i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Uc_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu17i)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu17i.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu17i.v2");
    set_bf_and_test(lv, v3, 1, 0, 17, 1, "Sf_Uc_BFu17i");
    set_bf_and_test(lv, v3, 1, 0, 17, hide_ull(1LL<<16), "Sf_Uc_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu17i, Sf_Uc_BFu17i)
//============================================================================



static void Test_Sf_Uc_BFu17ll()
{
  {
    init_simple_test("Sf_Uc_BFu17ll");
    static STRUCT_IF_C Sf_Uc_BFu17ll lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Uc_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu17ll)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu17ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu17ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 17, 1, "Sf_Uc_BFu17ll");
    set_bf_and_test(lv, v3, 1, 0, 17, hide_ull(1LL<<16), "Sf_Uc_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu17ll, Sf_Uc_BFu17ll)
//============================================================================



static void Test_Sf_Uc_BFu1c()
{
  {
    init_simple_test("Sf_Uc_BFu1c");
    static STRUCT_IF_C Sf_Uc_BFu1c lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Uc_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu1c)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu1c.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu1c.v2");
    set_bf_and_test(lv, v3, 1, 0, 1, 1, "Sf_Uc_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu1c, Sf_Uc_BFu1c)
//============================================================================



static void Test_Sf_Uc_BFu1i()
{
  {
    init_simple_test("Sf_Uc_BFu1i");
    static STRUCT_IF_C Sf_Uc_BFu1i lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Uc_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu1i)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu1i.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu1i.v2");
    set_bf_and_test(lv, v3, 1, 0, 1, 1, "Sf_Uc_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu1i, Sf_Uc_BFu1i)
//============================================================================



static void Test_Sf_Uc_BFu1ll()
{
  {
    init_simple_test("Sf_Uc_BFu1ll");
    static STRUCT_IF_C Sf_Uc_BFu1ll lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Uc_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu1ll)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu1ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu1ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 1, 1, "Sf_Uc_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu1ll, Sf_Uc_BFu1ll)
//============================================================================



static void Test_Sf_Uc_BFu1s()
{
  {
    init_simple_test("Sf_Uc_BFu1s");
    static STRUCT_IF_C Sf_Uc_BFu1s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Uc_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu1s)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu1s.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu1s.v2");
    set_bf_and_test(lv, v3, 1, 0, 1, 1, "Sf_Uc_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu1s, Sf_Uc_BFu1s)
//============================================================================



static void Test_Sf_Uc_BFu31i()
{
  {
    init_simple_test("Sf_Uc_BFu31i");
    static STRUCT_IF_C Sf_Uc_BFu31i lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Uc_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu31i)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu31i.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu31i.v2");
    set_bf_and_test(lv, v3, 1, 0, 31, 1, "Sf_Uc_BFu31i");
    set_bf_and_test(lv, v3, 1, 0, 31, hide_ull(1LL<<30), "Sf_Uc_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu31i, Sf_Uc_BFu31i)
//============================================================================



static void Test_Sf_Uc_BFu31ll()
{
  {
    init_simple_test("Sf_Uc_BFu31ll");
    static STRUCT_IF_C Sf_Uc_BFu31ll lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Uc_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu31ll)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu31ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu31ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 31, 1, "Sf_Uc_BFu31ll");
    set_bf_and_test(lv, v3, 1, 0, 31, hide_ull(1LL<<30), "Sf_Uc_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu31ll, Sf_Uc_BFu31ll)
//============================================================================



static void Test_Sf_Uc_BFu32i()
{
  {
    init_simple_test("Sf_Uc_BFu32i");
    static STRUCT_IF_C Sf_Uc_BFu32i lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Uc_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu32i)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu32i.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu32i.v2");
    set_bf_and_test(lv, v3, 1, 0, 32, 1, "Sf_Uc_BFu32i");
    set_bf_and_test(lv, v3, 1, 0, 32, hide_ull(1LL<<31), "Sf_Uc_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu32i, Sf_Uc_BFu32i)
//============================================================================



static void Test_Sf_Uc_BFu32ll()
{
  {
    init_simple_test("Sf_Uc_BFu32ll");
    static STRUCT_IF_C Sf_Uc_BFu32ll lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Uc_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu32ll)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu32ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu32ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 32, 1, "Sf_Uc_BFu32ll");
    set_bf_and_test(lv, v3, 1, 0, 32, hide_ull(1LL<<31), "Sf_Uc_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu32ll, Sf_Uc_BFu32ll)
//============================================================================



static void Test_Sf_Uc_BFu33()
{
  {
    init_simple_test("Sf_Uc_BFu33");
    static STRUCT_IF_C Sf_Uc_BFu33 lv;
    check2(sizeof(lv), 6, "sizeof(Sf_Uc_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu33)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu33.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu33.v2");
    set_bf_and_test(lv, v3, 1, 0, 33, 1, "Sf_Uc_BFu33");
    set_bf_and_test(lv, v3, 1, 0, 33, hide_ull(1LL<<32), "Sf_Uc_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu33, Sf_Uc_BFu33)
//============================================================================



static void Test_Sf_Uc_BFu7c()
{
  {
    init_simple_test("Sf_Uc_BFu7c");
    static STRUCT_IF_C Sf_Uc_BFu7c lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Uc_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu7c)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu7c.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu7c.v2");
    set_bf_and_test(lv, v3, 1, 0, 7, 1, "Sf_Uc_BFu7c");
    set_bf_and_test(lv, v3, 1, 0, 7, hide_ull(1LL<<6), "Sf_Uc_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu7c, Sf_Uc_BFu7c)
//============================================================================



static void Test_Sf_Uc_BFu7i()
{
  {
    init_simple_test("Sf_Uc_BFu7i");
    static STRUCT_IF_C Sf_Uc_BFu7i lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Uc_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu7i)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu7i.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu7i.v2");
    set_bf_and_test(lv, v3, 1, 0, 7, 1, "Sf_Uc_BFu7i");
    set_bf_and_test(lv, v3, 1, 0, 7, hide_ull(1LL<<6), "Sf_Uc_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu7i, Sf_Uc_BFu7i)
//============================================================================



static void Test_Sf_Uc_BFu7ll()
{
  {
    init_simple_test("Sf_Uc_BFu7ll");
    static STRUCT_IF_C Sf_Uc_BFu7ll lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Uc_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu7ll)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu7ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu7ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 7, 1, "Sf_Uc_BFu7ll");
    set_bf_and_test(lv, v3, 1, 0, 7, hide_ull(1LL<<6), "Sf_Uc_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu7ll, Sf_Uc_BFu7ll)
//============================================================================



static void Test_Sf_Uc_BFu7s()
{
  {
    init_simple_test("Sf_Uc_BFu7s");
    static STRUCT_IF_C Sf_Uc_BFu7s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Uc_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu7s)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu7s.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu7s.v2");
    set_bf_and_test(lv, v3, 1, 0, 7, 1, "Sf_Uc_BFu7s");
    set_bf_and_test(lv, v3, 1, 0, 7, hide_ull(1LL<<6), "Sf_Uc_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu7s, Sf_Uc_BFu7s)
//============================================================================



static void Test_Sf_Uc_BFu8c()
{
  {
    init_simple_test("Sf_Uc_BFu8c");
    static STRUCT_IF_C Sf_Uc_BFu8c lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Uc_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu8c)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu8c.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu8c.v2");
    set_bf_and_test(lv, v3, 1, 0, 8, 1, "Sf_Uc_BFu8c");
    set_bf_and_test(lv, v3, 1, 0, 8, hide_ull(1LL<<7), "Sf_Uc_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu8c, Sf_Uc_BFu8c)
//============================================================================



static void Test_Sf_Uc_BFu8i()
{
  {
    init_simple_test("Sf_Uc_BFu8i");
    static STRUCT_IF_C Sf_Uc_BFu8i lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Uc_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu8i)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu8i.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu8i.v2");
    set_bf_and_test(lv, v3, 1, 0, 8, 1, "Sf_Uc_BFu8i");
    set_bf_and_test(lv, v3, 1, 0, 8, hide_ull(1LL<<7), "Sf_Uc_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu8i, Sf_Uc_BFu8i)
//============================================================================



static void Test_Sf_Uc_BFu8ll()
{
  {
    init_simple_test("Sf_Uc_BFu8ll");
    static STRUCT_IF_C Sf_Uc_BFu8ll lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Uc_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu8ll)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu8ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu8ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 8, 1, "Sf_Uc_BFu8ll");
    set_bf_and_test(lv, v3, 1, 0, 8, hide_ull(1LL<<7), "Sf_Uc_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu8ll, Sf_Uc_BFu8ll)
//============================================================================



static void Test_Sf_Uc_BFu8s()
{
  {
    init_simple_test("Sf_Uc_BFu8s");
    static STRUCT_IF_C Sf_Uc_BFu8s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Uc_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu8s)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu8s.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu8s.v2");
    set_bf_and_test(lv, v3, 1, 0, 8, 1, "Sf_Uc_BFu8s");
    set_bf_and_test(lv, v3, 1, 0, 8, hide_ull(1LL<<7), "Sf_Uc_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu8s, Sf_Uc_BFu8s)
//============================================================================



static void Test_Sf_Uc_BFu9i()
{
  {
    init_simple_test("Sf_Uc_BFu9i");
    static STRUCT_IF_C Sf_Uc_BFu9i lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Uc_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu9i)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu9i.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu9i.v2");
    set_bf_and_test(lv, v3, 1, 0, 9, 1, "Sf_Uc_BFu9i");
    set_bf_and_test(lv, v3, 1, 0, 9, hide_ull(1LL<<8), "Sf_Uc_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu9i, Sf_Uc_BFu9i)
//============================================================================



static void Test_Sf_Uc_BFu9ll()
{
  {
    init_simple_test("Sf_Uc_BFu9ll");
    static STRUCT_IF_C Sf_Uc_BFu9ll lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Uc_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu9ll)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu9ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu9ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 9, 1, "Sf_Uc_BFu9ll");
    set_bf_and_test(lv, v3, 1, 0, 9, hide_ull(1LL<<8), "Sf_Uc_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu9ll, Sf_Uc_BFu9ll)
//============================================================================



static void Test_Sf_Uc_BFu9s()
{
  {
    init_simple_test("Sf_Uc_BFu9s");
    static STRUCT_IF_C Sf_Uc_BFu9s lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Uc_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu9s)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu9s.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu9s.v2");
    set_bf_and_test(lv, v3, 1, 0, 9, 1, "Sf_Uc_BFu9s");
    set_bf_and_test(lv, v3, 1, 0, 9, hide_ull(1LL<<8), "Sf_Uc_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu9s, Sf_Uc_BFu9s)
//============================================================================



static void Test_Sf_Uc_C()
{
  {
    init_simple_test("Sf_Uc_C");
    STRUCT_IF_C Sf_Uc_C lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Uc_C)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_C)");
    check_field_offset(lv, v1, 0, "Sf_Uc_C.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_C.v2");
    check_field_offset(lv, v3, 1, "Sf_Uc_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_C, Sf_Uc_C)
//============================================================================



static void Test_Sf_Uc_D()
{
  {
    init_simple_test("Sf_Uc_D");
    STRUCT_IF_C Sf_Uc_D lv;
    check2(sizeof(lv), 9, "sizeof(Sf_Uc_D)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_D)");
    check_field_offset(lv, v1, 0, "Sf_Uc_D.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_D.v2");
    check_field_offset(lv, v3, 1, "Sf_Uc_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_D, Sf_Uc_D)
//============================================================================



static void Test_Sf_Uc_F()
{
  {
    init_simple_test("Sf_Uc_F");
    STRUCT_IF_C Sf_Uc_F lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Uc_F)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_F)");
    check_field_offset(lv, v1, 0, "Sf_Uc_F.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_F.v2");
    check_field_offset(lv, v3, 1, "Sf_Uc_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_F, Sf_Uc_F)
//============================================================================



static void Test_Sf_Uc_I()
{
  {
    init_simple_test("Sf_Uc_I");
    STRUCT_IF_C Sf_Uc_I lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Uc_I)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_I)");
    check_field_offset(lv, v1, 0, "Sf_Uc_I.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_I.v2");
    check_field_offset(lv, v3, 1, "Sf_Uc_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_I, Sf_Uc_I)
//============================================================================



static void Test_Sf_Uc_Ip()
{
  {
    init_simple_test("Sf_Uc_Ip");
    STRUCT_IF_C Sf_Uc_Ip lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Uc_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_Ip)");
    check_field_offset(lv, v1, 0, "Sf_Uc_Ip.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_Ip.v2");
    check_field_offset(lv, v3, 1, "Sf_Uc_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_Ip, Sf_Uc_Ip)
//============================================================================



static void Test_Sf_Uc_L()
{
  {
    init_simple_test("Sf_Uc_L");
    STRUCT_IF_C Sf_Uc_L lv;
    check2(sizeof(lv), 9, "sizeof(Sf_Uc_L)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_L)");
    check_field_offset(lv, v1, 0, "Sf_Uc_L.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_L.v2");
    check_field_offset(lv, v3, 1, "Sf_Uc_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_L, Sf_Uc_L)
//============================================================================



static void Test_Sf_Uc_S()
{
  {
    init_simple_test("Sf_Uc_S");
    STRUCT_IF_C Sf_Uc_S lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Uc_S)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_S)");
    check_field_offset(lv, v1, 0, "Sf_Uc_S.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_S.v2");
    check_field_offset(lv, v3, 1, "Sf_Uc_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_S, Sf_Uc_S)
//============================================================================



static void Test_Sf_Uc_Sf()
{
  {
    init_simple_test("Sf_Uc_Sf");
    STRUCT_IF_C Sf_Uc_Sf lv;
    check2(sizeof(lv), 1, "sizeof(Sf_Uc_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_Sf)");
    check_field_offset(lv, v1, 0, "Sf_Uc_Sf.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_Sf.v2");
    check_field_offset(lv, v3, 1, "Sf_Uc_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_Sf, Sf_Uc_Sf)
//============================================================================



static void Test_Sf_Uc_Uc()
{
  {
    init_simple_test("Sf_Uc_Uc");
    STRUCT_IF_C Sf_Uc_Uc lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Uc_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_Uc)");
    check_field_offset(lv, v1, 0, "Sf_Uc_Uc.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_Uc.v2");
    check_field_offset(lv, v3, 1, "Sf_Uc_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_Uc, Sf_Uc_Uc)
//============================================================================



static void Test_Sf_Uc_Ui()
{
  {
    init_simple_test("Sf_Uc_Ui");
    STRUCT_IF_C Sf_Uc_Ui lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Uc_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_Ui)");
    check_field_offset(lv, v1, 0, "Sf_Uc_Ui.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_Ui.v2");
    check_field_offset(lv, v3, 1, "Sf_Uc_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_Ui, Sf_Uc_Ui)
//============================================================================



static void Test_Sf_Uc_Ul()
{
  {
    init_simple_test("Sf_Uc_Ul");
    STRUCT_IF_C Sf_Uc_Ul lv;
    check2(sizeof(lv), 9, "sizeof(Sf_Uc_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_Ul)");
    check_field_offset(lv, v1, 0, "Sf_Uc_Ul.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_Ul.v2");
    check_field_offset(lv, v3, 1, "Sf_Uc_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_Ul, Sf_Uc_Ul)
//============================================================================



static void Test_Sf_Uc_Us()
{
  {
    init_simple_test("Sf_Uc_Us");
    STRUCT_IF_C Sf_Uc_Us lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Uc_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_Us)");
    check_field_offset(lv, v1, 0, "Sf_Uc_Us.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_Us.v2");
    check_field_offset(lv, v3, 1, "Sf_Uc_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_Us, Sf_Uc_Us)
//============================================================================



static void Test_Sf_Uc_Vp()
{
  {
    init_simple_test("Sf_Uc_Vp");
    STRUCT_IF_C Sf_Uc_Vp lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Uc_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_Vp)");
    check_field_offset(lv, v1, 0, "Sf_Uc_Vp.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_Vp.v2");
    check_field_offset(lv, v3, 1, "Sf_Uc_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_Vp, Sf_Uc_Vp)
//============================================================================



static void Test_Sf_Ui()
{
  {
    init_simple_test("Sf_Ui");
    STRUCT_IF_C Sf_Ui lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui)");
    check_field_offset(lv, v1, 0, "Sf_Ui.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui, Sf_Ui)
//============================================================================



static void Test_Sf_Ui_BFu15i()
{
  {
    init_simple_test("Sf_Ui_BFu15i");
    static STRUCT_IF_C Sf_Ui_BFu15i lv;
    check2(sizeof(lv), 6, "sizeof(Sf_Ui_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu15i)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu15i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu15i.v2");
    set_bf_and_test(lv, v3, 4, 0, 15, 1, "Sf_Ui_BFu15i");
    set_bf_and_test(lv, v3, 4, 0, 15, hide_ull(1LL<<14), "Sf_Ui_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu15i, Sf_Ui_BFu15i)
//============================================================================



static void Test_Sf_Ui_BFu15ll()
{
  {
    init_simple_test("Sf_Ui_BFu15ll");
    static STRUCT_IF_C Sf_Ui_BFu15ll lv;
    check2(sizeof(lv), 6, "sizeof(Sf_Ui_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu15ll)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu15ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu15ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 15, 1, "Sf_Ui_BFu15ll");
    set_bf_and_test(lv, v3, 4, 0, 15, hide_ull(1LL<<14), "Sf_Ui_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu15ll, Sf_Ui_BFu15ll)
//============================================================================



static void Test_Sf_Ui_BFu15s()
{
  {
    init_simple_test("Sf_Ui_BFu15s");
    static STRUCT_IF_C Sf_Ui_BFu15s lv;
    check2(sizeof(lv), 6, "sizeof(Sf_Ui_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu15s)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu15s.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu15s.v2");
    set_bf_and_test(lv, v3, 4, 0, 15, 1, "Sf_Ui_BFu15s");
    set_bf_and_test(lv, v3, 4, 0, 15, hide_ull(1LL<<14), "Sf_Ui_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu15s, Sf_Ui_BFu15s)
//============================================================================



static void Test_Sf_Ui_BFu16i()
{
  {
    init_simple_test("Sf_Ui_BFu16i");
    static STRUCT_IF_C Sf_Ui_BFu16i lv;
    check2(sizeof(lv), 6, "sizeof(Sf_Ui_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu16i)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu16i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu16i.v2");
    set_bf_and_test(lv, v3, 4, 0, 16, 1, "Sf_Ui_BFu16i");
    set_bf_and_test(lv, v3, 4, 0, 16, hide_ull(1LL<<15), "Sf_Ui_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu16i, Sf_Ui_BFu16i)
//============================================================================



static void Test_Sf_Ui_BFu16ll()
{
  {
    init_simple_test("Sf_Ui_BFu16ll");
    static STRUCT_IF_C Sf_Ui_BFu16ll lv;
    check2(sizeof(lv), 6, "sizeof(Sf_Ui_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu16ll)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu16ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu16ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 16, 1, "Sf_Ui_BFu16ll");
    set_bf_and_test(lv, v3, 4, 0, 16, hide_ull(1LL<<15), "Sf_Ui_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu16ll, Sf_Ui_BFu16ll)
//============================================================================



static void Test_Sf_Ui_BFu16s()
{
  {
    init_simple_test("Sf_Ui_BFu16s");
    static STRUCT_IF_C Sf_Ui_BFu16s lv;
    check2(sizeof(lv), 6, "sizeof(Sf_Ui_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu16s)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu16s.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu16s.v2");
    set_bf_and_test(lv, v3, 4, 0, 16, 1, "Sf_Ui_BFu16s");
    set_bf_and_test(lv, v3, 4, 0, 16, hide_ull(1LL<<15), "Sf_Ui_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu16s, Sf_Ui_BFu16s)
//============================================================================



static void Test_Sf_Ui_BFu17i()
{
  {
    init_simple_test("Sf_Ui_BFu17i");
    static STRUCT_IF_C Sf_Ui_BFu17i lv;
    check2(sizeof(lv), 7, "sizeof(Sf_Ui_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu17i)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu17i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu17i.v2");
    set_bf_and_test(lv, v3, 4, 0, 17, 1, "Sf_Ui_BFu17i");
    set_bf_and_test(lv, v3, 4, 0, 17, hide_ull(1LL<<16), "Sf_Ui_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu17i, Sf_Ui_BFu17i)
//============================================================================



static void Test_Sf_Ui_BFu17ll()
{
  {
    init_simple_test("Sf_Ui_BFu17ll");
    static STRUCT_IF_C Sf_Ui_BFu17ll lv;
    check2(sizeof(lv), 7, "sizeof(Sf_Ui_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu17ll)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu17ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu17ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 17, 1, "Sf_Ui_BFu17ll");
    set_bf_and_test(lv, v3, 4, 0, 17, hide_ull(1LL<<16), "Sf_Ui_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu17ll, Sf_Ui_BFu17ll)
//============================================================================



static void Test_Sf_Ui_BFu1c()
{
  {
    init_simple_test("Sf_Ui_BFu1c");
    static STRUCT_IF_C Sf_Ui_BFu1c lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Ui_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu1c)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu1c.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu1c.v2");
    set_bf_and_test(lv, v3, 4, 0, 1, 1, "Sf_Ui_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu1c, Sf_Ui_BFu1c)
//============================================================================



static void Test_Sf_Ui_BFu1i()
{
  {
    init_simple_test("Sf_Ui_BFu1i");
    static STRUCT_IF_C Sf_Ui_BFu1i lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Ui_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu1i)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu1i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu1i.v2");
    set_bf_and_test(lv, v3, 4, 0, 1, 1, "Sf_Ui_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu1i, Sf_Ui_BFu1i)
//============================================================================



static void Test_Sf_Ui_BFu1ll()
{
  {
    init_simple_test("Sf_Ui_BFu1ll");
    static STRUCT_IF_C Sf_Ui_BFu1ll lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Ui_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu1ll)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu1ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu1ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 1, 1, "Sf_Ui_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu1ll, Sf_Ui_BFu1ll)
//============================================================================



static void Test_Sf_Ui_BFu1s()
{
  {
    init_simple_test("Sf_Ui_BFu1s");
    static STRUCT_IF_C Sf_Ui_BFu1s lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Ui_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu1s)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu1s.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu1s.v2");
    set_bf_and_test(lv, v3, 4, 0, 1, 1, "Sf_Ui_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu1s, Sf_Ui_BFu1s)
//============================================================================



static void Test_Sf_Ui_BFu31i()
{
  {
    init_simple_test("Sf_Ui_BFu31i");
    static STRUCT_IF_C Sf_Ui_BFu31i lv;
    check2(sizeof(lv), 8, "sizeof(Sf_Ui_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu31i)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu31i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu31i.v2");
    set_bf_and_test(lv, v3, 4, 0, 31, 1, "Sf_Ui_BFu31i");
    set_bf_and_test(lv, v3, 4, 0, 31, hide_ull(1LL<<30), "Sf_Ui_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu31i, Sf_Ui_BFu31i)
//============================================================================



static void Test_Sf_Ui_BFu31ll()
{
  {
    init_simple_test("Sf_Ui_BFu31ll");
    static STRUCT_IF_C Sf_Ui_BFu31ll lv;
    check2(sizeof(lv), 8, "sizeof(Sf_Ui_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu31ll)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu31ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu31ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 31, 1, "Sf_Ui_BFu31ll");
    set_bf_and_test(lv, v3, 4, 0, 31, hide_ull(1LL<<30), "Sf_Ui_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu31ll, Sf_Ui_BFu31ll)
//============================================================================



static void Test_Sf_Ui_BFu32i()
{
  {
    init_simple_test("Sf_Ui_BFu32i");
    static STRUCT_IF_C Sf_Ui_BFu32i lv;
    check2(sizeof(lv), 8, "sizeof(Sf_Ui_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu32i)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu32i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu32i.v2");
    set_bf_and_test(lv, v3, 4, 0, 32, 1, "Sf_Ui_BFu32i");
    set_bf_and_test(lv, v3, 4, 0, 32, hide_ull(1LL<<31), "Sf_Ui_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu32i, Sf_Ui_BFu32i)
//============================================================================



static void Test_Sf_Ui_BFu32ll()
{
  {
    init_simple_test("Sf_Ui_BFu32ll");
    static STRUCT_IF_C Sf_Ui_BFu32ll lv;
    check2(sizeof(lv), 8, "sizeof(Sf_Ui_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu32ll)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu32ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu32ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 32, 1, "Sf_Ui_BFu32ll");
    set_bf_and_test(lv, v3, 4, 0, 32, hide_ull(1LL<<31), "Sf_Ui_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu32ll, Sf_Ui_BFu32ll)
//============================================================================



static void Test_Sf_Ui_BFu33()
{
  {
    init_simple_test("Sf_Ui_BFu33");
    static STRUCT_IF_C Sf_Ui_BFu33 lv;
    check2(sizeof(lv), 9, "sizeof(Sf_Ui_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu33)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu33.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu33.v2");
    set_bf_and_test(lv, v3, 4, 0, 33, 1, "Sf_Ui_BFu33");
    set_bf_and_test(lv, v3, 4, 0, 33, hide_ull(1LL<<32), "Sf_Ui_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu33, Sf_Ui_BFu33)
//============================================================================



static void Test_Sf_Ui_BFu7c()
{
  {
    init_simple_test("Sf_Ui_BFu7c");
    static STRUCT_IF_C Sf_Ui_BFu7c lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Ui_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu7c)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu7c.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu7c.v2");
    set_bf_and_test(lv, v3, 4, 0, 7, 1, "Sf_Ui_BFu7c");
    set_bf_and_test(lv, v3, 4, 0, 7, hide_ull(1LL<<6), "Sf_Ui_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu7c, Sf_Ui_BFu7c)
//============================================================================



static void Test_Sf_Ui_BFu7i()
{
  {
    init_simple_test("Sf_Ui_BFu7i");
    static STRUCT_IF_C Sf_Ui_BFu7i lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Ui_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu7i)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu7i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu7i.v2");
    set_bf_and_test(lv, v3, 4, 0, 7, 1, "Sf_Ui_BFu7i");
    set_bf_and_test(lv, v3, 4, 0, 7, hide_ull(1LL<<6), "Sf_Ui_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu7i, Sf_Ui_BFu7i)
//============================================================================



static void Test_Sf_Ui_BFu7ll()
{
  {
    init_simple_test("Sf_Ui_BFu7ll");
    static STRUCT_IF_C Sf_Ui_BFu7ll lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Ui_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu7ll)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu7ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu7ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 7, 1, "Sf_Ui_BFu7ll");
    set_bf_and_test(lv, v3, 4, 0, 7, hide_ull(1LL<<6), "Sf_Ui_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu7ll, Sf_Ui_BFu7ll)
//============================================================================



static void Test_Sf_Ui_BFu7s()
{
  {
    init_simple_test("Sf_Ui_BFu7s");
    static STRUCT_IF_C Sf_Ui_BFu7s lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Ui_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu7s)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu7s.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu7s.v2");
    set_bf_and_test(lv, v3, 4, 0, 7, 1, "Sf_Ui_BFu7s");
    set_bf_and_test(lv, v3, 4, 0, 7, hide_ull(1LL<<6), "Sf_Ui_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu7s, Sf_Ui_BFu7s)
//============================================================================



static void Test_Sf_Ui_BFu8c()
{
  {
    init_simple_test("Sf_Ui_BFu8c");
    static STRUCT_IF_C Sf_Ui_BFu8c lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Ui_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu8c)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu8c.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu8c.v2");
    set_bf_and_test(lv, v3, 4, 0, 8, 1, "Sf_Ui_BFu8c");
    set_bf_and_test(lv, v3, 4, 0, 8, hide_ull(1LL<<7), "Sf_Ui_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu8c, Sf_Ui_BFu8c)
//============================================================================



static void Test_Sf_Ui_BFu8i()
{
  {
    init_simple_test("Sf_Ui_BFu8i");
    static STRUCT_IF_C Sf_Ui_BFu8i lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Ui_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu8i)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu8i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu8i.v2");
    set_bf_and_test(lv, v3, 4, 0, 8, 1, "Sf_Ui_BFu8i");
    set_bf_and_test(lv, v3, 4, 0, 8, hide_ull(1LL<<7), "Sf_Ui_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu8i, Sf_Ui_BFu8i)
//============================================================================



static void Test_Sf_Ui_BFu8ll()
{
  {
    init_simple_test("Sf_Ui_BFu8ll");
    static STRUCT_IF_C Sf_Ui_BFu8ll lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Ui_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu8ll)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu8ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu8ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 8, 1, "Sf_Ui_BFu8ll");
    set_bf_and_test(lv, v3, 4, 0, 8, hide_ull(1LL<<7), "Sf_Ui_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu8ll, Sf_Ui_BFu8ll)
//============================================================================



static void Test_Sf_Ui_BFu8s()
{
  {
    init_simple_test("Sf_Ui_BFu8s");
    static STRUCT_IF_C Sf_Ui_BFu8s lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Ui_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu8s)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu8s.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu8s.v2");
    set_bf_and_test(lv, v3, 4, 0, 8, 1, "Sf_Ui_BFu8s");
    set_bf_and_test(lv, v3, 4, 0, 8, hide_ull(1LL<<7), "Sf_Ui_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu8s, Sf_Ui_BFu8s)
//============================================================================



static void Test_Sf_Ui_BFu9i()
{
  {
    init_simple_test("Sf_Ui_BFu9i");
    static STRUCT_IF_C Sf_Ui_BFu9i lv;
    check2(sizeof(lv), 6, "sizeof(Sf_Ui_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu9i)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu9i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu9i.v2");
    set_bf_and_test(lv, v3, 4, 0, 9, 1, "Sf_Ui_BFu9i");
    set_bf_and_test(lv, v3, 4, 0, 9, hide_ull(1LL<<8), "Sf_Ui_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu9i, Sf_Ui_BFu9i)
//============================================================================



static void Test_Sf_Ui_BFu9ll()
{
  {
    init_simple_test("Sf_Ui_BFu9ll");
    static STRUCT_IF_C Sf_Ui_BFu9ll lv;
    check2(sizeof(lv), 6, "sizeof(Sf_Ui_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu9ll)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu9ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu9ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 9, 1, "Sf_Ui_BFu9ll");
    set_bf_and_test(lv, v3, 4, 0, 9, hide_ull(1LL<<8), "Sf_Ui_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu9ll, Sf_Ui_BFu9ll)
//============================================================================



static void Test_Sf_Ui_BFu9s()
{
  {
    init_simple_test("Sf_Ui_BFu9s");
    static STRUCT_IF_C Sf_Ui_BFu9s lv;
    check2(sizeof(lv), 6, "sizeof(Sf_Ui_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_BFu9s)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu9s.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu9s.v2");
    set_bf_and_test(lv, v3, 4, 0, 9, 1, "Sf_Ui_BFu9s");
    set_bf_and_test(lv, v3, 4, 0, 9, hide_ull(1LL<<8), "Sf_Ui_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu9s, Sf_Ui_BFu9s)
//============================================================================



static void Test_Sf_Ui_C()
{
  {
    init_simple_test("Sf_Ui_C");
    STRUCT_IF_C Sf_Ui_C lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Ui_C)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_C)");
    check_field_offset(lv, v1, 0, "Sf_Ui_C.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_C.v2");
    check_field_offset(lv, v3, 4, "Sf_Ui_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_C, Sf_Ui_C)
//============================================================================



static void Test_Sf_Ui_D()
{
  {
    init_simple_test("Sf_Ui_D");
    STRUCT_IF_C Sf_Ui_D lv;
    check2(sizeof(lv), 12, "sizeof(Sf_Ui_D)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_D)");
    check_field_offset(lv, v1, 0, "Sf_Ui_D.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_D.v2");
    check_field_offset(lv, v3, 4, "Sf_Ui_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_D, Sf_Ui_D)
//============================================================================



static void Test_Sf_Ui_F()
{
  {
    init_simple_test("Sf_Ui_F");
    STRUCT_IF_C Sf_Ui_F lv;
    check2(sizeof(lv), 8, "sizeof(Sf_Ui_F)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_F)");
    check_field_offset(lv, v1, 0, "Sf_Ui_F.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_F.v2");
    check_field_offset(lv, v3, 4, "Sf_Ui_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_F, Sf_Ui_F)
//============================================================================



static void Test_Sf_Ui_I()
{
  {
    init_simple_test("Sf_Ui_I");
    STRUCT_IF_C Sf_Ui_I lv;
    check2(sizeof(lv), 8, "sizeof(Sf_Ui_I)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_I)");
    check_field_offset(lv, v1, 0, "Sf_Ui_I.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_I.v2");
    check_field_offset(lv, v3, 4, "Sf_Ui_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_I, Sf_Ui_I)
//============================================================================



static void Test_Sf_Ui_Ip()
{
  {
    init_simple_test("Sf_Ui_Ip");
    STRUCT_IF_C Sf_Ui_Ip lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Sf_Ui_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_Ip)");
    check_field_offset(lv, v1, 0, "Sf_Ui_Ip.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_Ip.v2");
    check_field_offset(lv, v3, 4, "Sf_Ui_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_Ip, Sf_Ui_Ip)
//============================================================================



static void Test_Sf_Ui_L()
{
  {
    init_simple_test("Sf_Ui_L");
    STRUCT_IF_C Sf_Ui_L lv;
    check2(sizeof(lv), 12, "sizeof(Sf_Ui_L)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_L)");
    check_field_offset(lv, v1, 0, "Sf_Ui_L.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_L.v2");
    check_field_offset(lv, v3, 4, "Sf_Ui_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_L, Sf_Ui_L)
//============================================================================



static void Test_Sf_Ui_S()
{
  {
    init_simple_test("Sf_Ui_S");
    STRUCT_IF_C Sf_Ui_S lv;
    check2(sizeof(lv), 6, "sizeof(Sf_Ui_S)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_S)");
    check_field_offset(lv, v1, 0, "Sf_Ui_S.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_S.v2");
    check_field_offset(lv, v3, 4, "Sf_Ui_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_S, Sf_Ui_S)
//============================================================================



static void Test_Sf_Ui_Sf()
{
  {
    init_simple_test("Sf_Ui_Sf");
    STRUCT_IF_C Sf_Ui_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Ui_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_Sf)");
    check_field_offset(lv, v1, 0, "Sf_Ui_Sf.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_Sf.v2");
    check_field_offset(lv, v3, 4, "Sf_Ui_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_Sf, Sf_Ui_Sf)
//============================================================================



static void Test_Sf_Ui_Uc()
{
  {
    init_simple_test("Sf_Ui_Uc");
    STRUCT_IF_C Sf_Ui_Uc lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Ui_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_Uc)");
    check_field_offset(lv, v1, 0, "Sf_Ui_Uc.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_Uc.v2");
    check_field_offset(lv, v3, 4, "Sf_Ui_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_Uc, Sf_Ui_Uc)
//============================================================================



static void Test_Sf_Ui_Ui()
{
  {
    init_simple_test("Sf_Ui_Ui");
    STRUCT_IF_C Sf_Ui_Ui lv;
    check2(sizeof(lv), 8, "sizeof(Sf_Ui_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_Ui)");
    check_field_offset(lv, v1, 0, "Sf_Ui_Ui.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_Ui.v2");
    check_field_offset(lv, v3, 4, "Sf_Ui_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_Ui, Sf_Ui_Ui)
//============================================================================



static void Test_Sf_Ui_Ul()
{
  {
    init_simple_test("Sf_Ui_Ul");
    STRUCT_IF_C Sf_Ui_Ul lv;
    check2(sizeof(lv), 12, "sizeof(Sf_Ui_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_Ul)");
    check_field_offset(lv, v1, 0, "Sf_Ui_Ul.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_Ul.v2");
    check_field_offset(lv, v3, 4, "Sf_Ui_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_Ul, Sf_Ui_Ul)
//============================================================================



static void Test_Sf_Ui_Us()
{
  {
    init_simple_test("Sf_Ui_Us");
    STRUCT_IF_C Sf_Ui_Us lv;
    check2(sizeof(lv), 6, "sizeof(Sf_Ui_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_Us)");
    check_field_offset(lv, v1, 0, "Sf_Ui_Us.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_Us.v2");
    check_field_offset(lv, v3, 4, "Sf_Ui_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_Us, Sf_Ui_Us)
//============================================================================



static void Test_Sf_Ui_Vp()
{
  {
    init_simple_test("Sf_Ui_Vp");
    STRUCT_IF_C Sf_Ui_Vp lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Sf_Ui_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_Vp)");
    check_field_offset(lv, v1, 0, "Sf_Ui_Vp.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_Vp.v2");
    check_field_offset(lv, v3, 4, "Sf_Ui_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_Vp, Sf_Ui_Vp)
//============================================================================



static void Test_Sf_Ul()
{
  {
    init_simple_test("Sf_Ul");
    STRUCT_IF_C Sf_Ul lv;
    check2(sizeof(lv), 8, "sizeof(Sf_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul)");
    check_field_offset(lv, v1, 0, "Sf_Ul.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul, Sf_Ul)
//============================================================================



static void Test_Sf_Ul_BFu15i()
{
  {
    init_simple_test("Sf_Ul_BFu15i");
    static STRUCT_IF_C Sf_Ul_BFu15i lv;
    check2(sizeof(lv), 10, "sizeof(Sf_Ul_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu15i)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu15i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu15i.v2");
    set_bf_and_test(lv, v3, 8, 0, 15, 1, "Sf_Ul_BFu15i");
    set_bf_and_test(lv, v3, 8, 0, 15, hide_ull(1LL<<14), "Sf_Ul_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu15i, Sf_Ul_BFu15i)
//============================================================================



static void Test_Sf_Ul_BFu15ll()
{
  {
    init_simple_test("Sf_Ul_BFu15ll");
    static STRUCT_IF_C Sf_Ul_BFu15ll lv;
    check2(sizeof(lv), 10, "sizeof(Sf_Ul_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu15ll)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu15ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu15ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 15, 1, "Sf_Ul_BFu15ll");
    set_bf_and_test(lv, v3, 8, 0, 15, hide_ull(1LL<<14), "Sf_Ul_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu15ll, Sf_Ul_BFu15ll)
//============================================================================



static void Test_Sf_Ul_BFu15s()
{
  {
    init_simple_test("Sf_Ul_BFu15s");
    static STRUCT_IF_C Sf_Ul_BFu15s lv;
    check2(sizeof(lv), 10, "sizeof(Sf_Ul_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu15s)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu15s.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu15s.v2");
    set_bf_and_test(lv, v3, 8, 0, 15, 1, "Sf_Ul_BFu15s");
    set_bf_and_test(lv, v3, 8, 0, 15, hide_ull(1LL<<14), "Sf_Ul_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu15s, Sf_Ul_BFu15s)
//============================================================================



static void Test_Sf_Ul_BFu16i()
{
  {
    init_simple_test("Sf_Ul_BFu16i");
    static STRUCT_IF_C Sf_Ul_BFu16i lv;
    check2(sizeof(lv), 10, "sizeof(Sf_Ul_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu16i)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu16i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu16i.v2");
    set_bf_and_test(lv, v3, 8, 0, 16, 1, "Sf_Ul_BFu16i");
    set_bf_and_test(lv, v3, 8, 0, 16, hide_ull(1LL<<15), "Sf_Ul_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu16i, Sf_Ul_BFu16i)
//============================================================================



static void Test_Sf_Ul_BFu16ll()
{
  {
    init_simple_test("Sf_Ul_BFu16ll");
    static STRUCT_IF_C Sf_Ul_BFu16ll lv;
    check2(sizeof(lv), 10, "sizeof(Sf_Ul_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu16ll)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu16ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu16ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 16, 1, "Sf_Ul_BFu16ll");
    set_bf_and_test(lv, v3, 8, 0, 16, hide_ull(1LL<<15), "Sf_Ul_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu16ll, Sf_Ul_BFu16ll)
//============================================================================



static void Test_Sf_Ul_BFu16s()
{
  {
    init_simple_test("Sf_Ul_BFu16s");
    static STRUCT_IF_C Sf_Ul_BFu16s lv;
    check2(sizeof(lv), 10, "sizeof(Sf_Ul_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu16s)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu16s.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu16s.v2");
    set_bf_and_test(lv, v3, 8, 0, 16, 1, "Sf_Ul_BFu16s");
    set_bf_and_test(lv, v3, 8, 0, 16, hide_ull(1LL<<15), "Sf_Ul_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu16s, Sf_Ul_BFu16s)
//============================================================================



static void Test_Sf_Ul_BFu17i()
{
  {
    init_simple_test("Sf_Ul_BFu17i");
    static STRUCT_IF_C Sf_Ul_BFu17i lv;
    check2(sizeof(lv), 11, "sizeof(Sf_Ul_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu17i)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu17i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu17i.v2");
    set_bf_and_test(lv, v3, 8, 0, 17, 1, "Sf_Ul_BFu17i");
    set_bf_and_test(lv, v3, 8, 0, 17, hide_ull(1LL<<16), "Sf_Ul_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu17i, Sf_Ul_BFu17i)
//============================================================================



static void Test_Sf_Ul_BFu17ll()
{
  {
    init_simple_test("Sf_Ul_BFu17ll");
    static STRUCT_IF_C Sf_Ul_BFu17ll lv;
    check2(sizeof(lv), 11, "sizeof(Sf_Ul_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu17ll)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu17ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu17ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 17, 1, "Sf_Ul_BFu17ll");
    set_bf_and_test(lv, v3, 8, 0, 17, hide_ull(1LL<<16), "Sf_Ul_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu17ll, Sf_Ul_BFu17ll)
//============================================================================



static void Test_Sf_Ul_BFu1c()
{
  {
    init_simple_test("Sf_Ul_BFu1c");
    static STRUCT_IF_C Sf_Ul_BFu1c lv;
    check2(sizeof(lv), 9, "sizeof(Sf_Ul_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu1c)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu1c.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu1c.v2");
    set_bf_and_test(lv, v3, 8, 0, 1, 1, "Sf_Ul_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu1c, Sf_Ul_BFu1c)
//============================================================================



static void Test_Sf_Ul_BFu1i()
{
  {
    init_simple_test("Sf_Ul_BFu1i");
    static STRUCT_IF_C Sf_Ul_BFu1i lv;
    check2(sizeof(lv), 9, "sizeof(Sf_Ul_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu1i)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu1i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu1i.v2");
    set_bf_and_test(lv, v3, 8, 0, 1, 1, "Sf_Ul_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu1i, Sf_Ul_BFu1i)
//============================================================================



static void Test_Sf_Ul_BFu1ll()
{
  {
    init_simple_test("Sf_Ul_BFu1ll");
    static STRUCT_IF_C Sf_Ul_BFu1ll lv;
    check2(sizeof(lv), 9, "sizeof(Sf_Ul_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu1ll)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu1ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu1ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 1, 1, "Sf_Ul_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu1ll, Sf_Ul_BFu1ll)
//============================================================================



static void Test_Sf_Ul_BFu1s()
{
  {
    init_simple_test("Sf_Ul_BFu1s");
    static STRUCT_IF_C Sf_Ul_BFu1s lv;
    check2(sizeof(lv), 9, "sizeof(Sf_Ul_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu1s)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu1s.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu1s.v2");
    set_bf_and_test(lv, v3, 8, 0, 1, 1, "Sf_Ul_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu1s, Sf_Ul_BFu1s)
//============================================================================



static void Test_Sf_Ul_BFu31i()
{
  {
    init_simple_test("Sf_Ul_BFu31i");
    static STRUCT_IF_C Sf_Ul_BFu31i lv;
    check2(sizeof(lv), 12, "sizeof(Sf_Ul_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu31i)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu31i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu31i.v2");
    set_bf_and_test(lv, v3, 8, 0, 31, 1, "Sf_Ul_BFu31i");
    set_bf_and_test(lv, v3, 8, 0, 31, hide_ull(1LL<<30), "Sf_Ul_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu31i, Sf_Ul_BFu31i)
//============================================================================



static void Test_Sf_Ul_BFu31ll()
{
  {
    init_simple_test("Sf_Ul_BFu31ll");
    static STRUCT_IF_C Sf_Ul_BFu31ll lv;
    check2(sizeof(lv), 12, "sizeof(Sf_Ul_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu31ll)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu31ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu31ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 31, 1, "Sf_Ul_BFu31ll");
    set_bf_and_test(lv, v3, 8, 0, 31, hide_ull(1LL<<30), "Sf_Ul_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu31ll, Sf_Ul_BFu31ll)
//============================================================================



static void Test_Sf_Ul_BFu32i()
{
  {
    init_simple_test("Sf_Ul_BFu32i");
    static STRUCT_IF_C Sf_Ul_BFu32i lv;
    check2(sizeof(lv), 12, "sizeof(Sf_Ul_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu32i)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu32i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu32i.v2");
    set_bf_and_test(lv, v3, 8, 0, 32, 1, "Sf_Ul_BFu32i");
    set_bf_and_test(lv, v3, 8, 0, 32, hide_ull(1LL<<31), "Sf_Ul_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu32i, Sf_Ul_BFu32i)
//============================================================================



static void Test_Sf_Ul_BFu32ll()
{
  {
    init_simple_test("Sf_Ul_BFu32ll");
    static STRUCT_IF_C Sf_Ul_BFu32ll lv;
    check2(sizeof(lv), 12, "sizeof(Sf_Ul_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu32ll)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu32ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu32ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 32, 1, "Sf_Ul_BFu32ll");
    set_bf_and_test(lv, v3, 8, 0, 32, hide_ull(1LL<<31), "Sf_Ul_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu32ll, Sf_Ul_BFu32ll)
//============================================================================



static void Test_Sf_Ul_BFu33()
{
  {
    init_simple_test("Sf_Ul_BFu33");
    static STRUCT_IF_C Sf_Ul_BFu33 lv;
    check2(sizeof(lv), 13, "sizeof(Sf_Ul_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu33)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu33.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu33.v2");
    set_bf_and_test(lv, v3, 8, 0, 33, 1, "Sf_Ul_BFu33");
    set_bf_and_test(lv, v3, 8, 0, 33, hide_ull(1LL<<32), "Sf_Ul_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu33, Sf_Ul_BFu33)
//============================================================================



static void Test_Sf_Ul_BFu7c()
{
  {
    init_simple_test("Sf_Ul_BFu7c");
    static STRUCT_IF_C Sf_Ul_BFu7c lv;
    check2(sizeof(lv), 9, "sizeof(Sf_Ul_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu7c)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu7c.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu7c.v2");
    set_bf_and_test(lv, v3, 8, 0, 7, 1, "Sf_Ul_BFu7c");
    set_bf_and_test(lv, v3, 8, 0, 7, hide_ull(1LL<<6), "Sf_Ul_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu7c, Sf_Ul_BFu7c)
//============================================================================



static void Test_Sf_Ul_BFu7i()
{
  {
    init_simple_test("Sf_Ul_BFu7i");
    static STRUCT_IF_C Sf_Ul_BFu7i lv;
    check2(sizeof(lv), 9, "sizeof(Sf_Ul_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu7i)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu7i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu7i.v2");
    set_bf_and_test(lv, v3, 8, 0, 7, 1, "Sf_Ul_BFu7i");
    set_bf_and_test(lv, v3, 8, 0, 7, hide_ull(1LL<<6), "Sf_Ul_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu7i, Sf_Ul_BFu7i)
//============================================================================



static void Test_Sf_Ul_BFu7ll()
{
  {
    init_simple_test("Sf_Ul_BFu7ll");
    static STRUCT_IF_C Sf_Ul_BFu7ll lv;
    check2(sizeof(lv), 9, "sizeof(Sf_Ul_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu7ll)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu7ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu7ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 7, 1, "Sf_Ul_BFu7ll");
    set_bf_and_test(lv, v3, 8, 0, 7, hide_ull(1LL<<6), "Sf_Ul_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu7ll, Sf_Ul_BFu7ll)
//============================================================================



static void Test_Sf_Ul_BFu7s()
{
  {
    init_simple_test("Sf_Ul_BFu7s");
    static STRUCT_IF_C Sf_Ul_BFu7s lv;
    check2(sizeof(lv), 9, "sizeof(Sf_Ul_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu7s)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu7s.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu7s.v2");
    set_bf_and_test(lv, v3, 8, 0, 7, 1, "Sf_Ul_BFu7s");
    set_bf_and_test(lv, v3, 8, 0, 7, hide_ull(1LL<<6), "Sf_Ul_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu7s, Sf_Ul_BFu7s)
//============================================================================



static void Test_Sf_Ul_BFu8c()
{
  {
    init_simple_test("Sf_Ul_BFu8c");
    static STRUCT_IF_C Sf_Ul_BFu8c lv;
    check2(sizeof(lv), 9, "sizeof(Sf_Ul_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu8c)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu8c.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu8c.v2");
    set_bf_and_test(lv, v3, 8, 0, 8, 1, "Sf_Ul_BFu8c");
    set_bf_and_test(lv, v3, 8, 0, 8, hide_ull(1LL<<7), "Sf_Ul_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu8c, Sf_Ul_BFu8c)
//============================================================================



static void Test_Sf_Ul_BFu8i()
{
  {
    init_simple_test("Sf_Ul_BFu8i");
    static STRUCT_IF_C Sf_Ul_BFu8i lv;
    check2(sizeof(lv), 9, "sizeof(Sf_Ul_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu8i)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu8i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu8i.v2");
    set_bf_and_test(lv, v3, 8, 0, 8, 1, "Sf_Ul_BFu8i");
    set_bf_and_test(lv, v3, 8, 0, 8, hide_ull(1LL<<7), "Sf_Ul_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu8i, Sf_Ul_BFu8i)
//============================================================================



static void Test_Sf_Ul_BFu8ll()
{
  {
    init_simple_test("Sf_Ul_BFu8ll");
    static STRUCT_IF_C Sf_Ul_BFu8ll lv;
    check2(sizeof(lv), 9, "sizeof(Sf_Ul_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu8ll)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu8ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu8ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 8, 1, "Sf_Ul_BFu8ll");
    set_bf_and_test(lv, v3, 8, 0, 8, hide_ull(1LL<<7), "Sf_Ul_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu8ll, Sf_Ul_BFu8ll)
//============================================================================



static void Test_Sf_Ul_BFu8s()
{
  {
    init_simple_test("Sf_Ul_BFu8s");
    static STRUCT_IF_C Sf_Ul_BFu8s lv;
    check2(sizeof(lv), 9, "sizeof(Sf_Ul_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu8s)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu8s.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu8s.v2");
    set_bf_and_test(lv, v3, 8, 0, 8, 1, "Sf_Ul_BFu8s");
    set_bf_and_test(lv, v3, 8, 0, 8, hide_ull(1LL<<7), "Sf_Ul_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu8s, Sf_Ul_BFu8s)
//============================================================================



static void Test_Sf_Ul_BFu9i()
{
  {
    init_simple_test("Sf_Ul_BFu9i");
    static STRUCT_IF_C Sf_Ul_BFu9i lv;
    check2(sizeof(lv), 10, "sizeof(Sf_Ul_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu9i)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu9i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu9i.v2");
    set_bf_and_test(lv, v3, 8, 0, 9, 1, "Sf_Ul_BFu9i");
    set_bf_and_test(lv, v3, 8, 0, 9, hide_ull(1LL<<8), "Sf_Ul_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu9i, Sf_Ul_BFu9i)
//============================================================================



static void Test_Sf_Ul_BFu9ll()
{
  {
    init_simple_test("Sf_Ul_BFu9ll");
    static STRUCT_IF_C Sf_Ul_BFu9ll lv;
    check2(sizeof(lv), 10, "sizeof(Sf_Ul_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu9ll)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu9ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu9ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 9, 1, "Sf_Ul_BFu9ll");
    set_bf_and_test(lv, v3, 8, 0, 9, hide_ull(1LL<<8), "Sf_Ul_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu9ll, Sf_Ul_BFu9ll)
//============================================================================



static void Test_Sf_Ul_BFu9s()
{
  {
    init_simple_test("Sf_Ul_BFu9s");
    static STRUCT_IF_C Sf_Ul_BFu9s lv;
    check2(sizeof(lv), 10, "sizeof(Sf_Ul_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_BFu9s)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu9s.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu9s.v2");
    set_bf_and_test(lv, v3, 8, 0, 9, 1, "Sf_Ul_BFu9s");
    set_bf_and_test(lv, v3, 8, 0, 9, hide_ull(1LL<<8), "Sf_Ul_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu9s, Sf_Ul_BFu9s)
//============================================================================



static void Test_Sf_Ul_C()
{
  {
    init_simple_test("Sf_Ul_C");
    STRUCT_IF_C Sf_Ul_C lv;
    check2(sizeof(lv), 9, "sizeof(Sf_Ul_C)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_C)");
    check_field_offset(lv, v1, 0, "Sf_Ul_C.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_C.v2");
    check_field_offset(lv, v3, 8, "Sf_Ul_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_C, Sf_Ul_C)
//============================================================================



static void Test_Sf_Ul_D()
{
  {
    init_simple_test("Sf_Ul_D");
    STRUCT_IF_C Sf_Ul_D lv;
    check2(sizeof(lv), 16, "sizeof(Sf_Ul_D)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_D)");
    check_field_offset(lv, v1, 0, "Sf_Ul_D.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_D.v2");
    check_field_offset(lv, v3, 8, "Sf_Ul_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_D, Sf_Ul_D)
//============================================================================



static void Test_Sf_Ul_F()
{
  {
    init_simple_test("Sf_Ul_F");
    STRUCT_IF_C Sf_Ul_F lv;
    check2(sizeof(lv), 12, "sizeof(Sf_Ul_F)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_F)");
    check_field_offset(lv, v1, 0, "Sf_Ul_F.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_F.v2");
    check_field_offset(lv, v3, 8, "Sf_Ul_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_F, Sf_Ul_F)
//============================================================================



static void Test_Sf_Ul_I()
{
  {
    init_simple_test("Sf_Ul_I");
    STRUCT_IF_C Sf_Ul_I lv;
    check2(sizeof(lv), 12, "sizeof(Sf_Ul_I)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_I)");
    check_field_offset(lv, v1, 0, "Sf_Ul_I.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_I.v2");
    check_field_offset(lv, v3, 8, "Sf_Ul_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_I, Sf_Ul_I)
//============================================================================



static void Test_Sf_Ul_Ip()
{
  {
    init_simple_test("Sf_Ul_Ip");
    STRUCT_IF_C Sf_Ul_Ip lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Sf_Ul_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_Ip)");
    check_field_offset(lv, v1, 0, "Sf_Ul_Ip.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_Ip.v2");
    check_field_offset(lv, v3, 8, "Sf_Ul_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_Ip, Sf_Ul_Ip)
//============================================================================



static void Test_Sf_Ul_L()
{
  {
    init_simple_test("Sf_Ul_L");
    STRUCT_IF_C Sf_Ul_L lv;
    check2(sizeof(lv), 16, "sizeof(Sf_Ul_L)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_L)");
    check_field_offset(lv, v1, 0, "Sf_Ul_L.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_L.v2");
    check_field_offset(lv, v3, 8, "Sf_Ul_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_L, Sf_Ul_L)
//============================================================================



static void Test_Sf_Ul_S()
{
  {
    init_simple_test("Sf_Ul_S");
    STRUCT_IF_C Sf_Ul_S lv;
    check2(sizeof(lv), 10, "sizeof(Sf_Ul_S)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_S)");
    check_field_offset(lv, v1, 0, "Sf_Ul_S.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_S.v2");
    check_field_offset(lv, v3, 8, "Sf_Ul_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_S, Sf_Ul_S)
//============================================================================



static void Test_Sf_Ul_Sf()
{
  {
    init_simple_test("Sf_Ul_Sf");
    STRUCT_IF_C Sf_Ul_Sf lv;
    check2(sizeof(lv), 8, "sizeof(Sf_Ul_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_Sf)");
    check_field_offset(lv, v1, 0, "Sf_Ul_Sf.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_Sf.v2");
    check_field_offset(lv, v3, 8, "Sf_Ul_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_Sf, Sf_Ul_Sf)
//============================================================================



static void Test_Sf_Ul_Uc()
{
  {
    init_simple_test("Sf_Ul_Uc");
    STRUCT_IF_C Sf_Ul_Uc lv;
    check2(sizeof(lv), 9, "sizeof(Sf_Ul_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_Uc)");
    check_field_offset(lv, v1, 0, "Sf_Ul_Uc.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_Uc.v2");
    check_field_offset(lv, v3, 8, "Sf_Ul_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_Uc, Sf_Ul_Uc)
//============================================================================



static void Test_Sf_Ul_Ui()
{
  {
    init_simple_test("Sf_Ul_Ui");
    STRUCT_IF_C Sf_Ul_Ui lv;
    check2(sizeof(lv), 12, "sizeof(Sf_Ul_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_Ui)");
    check_field_offset(lv, v1, 0, "Sf_Ul_Ui.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_Ui.v2");
    check_field_offset(lv, v3, 8, "Sf_Ul_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_Ui, Sf_Ul_Ui)
//============================================================================



static void Test_Sf_Ul_Ul()
{
  {
    init_simple_test("Sf_Ul_Ul");
    STRUCT_IF_C Sf_Ul_Ul lv;
    check2(sizeof(lv), 16, "sizeof(Sf_Ul_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_Ul)");
    check_field_offset(lv, v1, 0, "Sf_Ul_Ul.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_Ul.v2");
    check_field_offset(lv, v3, 8, "Sf_Ul_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_Ul, Sf_Ul_Ul)
//============================================================================



static void Test_Sf_Ul_Us()
{
  {
    init_simple_test("Sf_Ul_Us");
    STRUCT_IF_C Sf_Ul_Us lv;
    check2(sizeof(lv), 10, "sizeof(Sf_Ul_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_Us)");
    check_field_offset(lv, v1, 0, "Sf_Ul_Us.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_Us.v2");
    check_field_offset(lv, v3, 8, "Sf_Ul_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_Us, Sf_Ul_Us)
//============================================================================



static void Test_Sf_Ul_Vp()
{
  {
    init_simple_test("Sf_Ul_Vp");
    STRUCT_IF_C Sf_Ul_Vp lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Sf_Ul_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_Vp)");
    check_field_offset(lv, v1, 0, "Sf_Ul_Vp.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_Vp.v2");
    check_field_offset(lv, v3, 8, "Sf_Ul_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_Vp, Sf_Ul_Vp)
//============================================================================



static void Test_Sf_Us()
{
  {
    init_simple_test("Sf_Us");
    STRUCT_IF_C Sf_Us lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us)");
    check_field_offset(lv, v1, 0, "Sf_Us.v1");
    check_field_offset(lv, v2, 0, "Sf_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us, Sf_Us)
//============================================================================



static void Test_Sf_Us_BFu15i()
{
  {
    init_simple_test("Sf_Us_BFu15i");
    static STRUCT_IF_C Sf_Us_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Us_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu15i)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu15i.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu15i.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "Sf_Us_BFu15i");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "Sf_Us_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu15i, Sf_Us_BFu15i)
//============================================================================



static void Test_Sf_Us_BFu15ll()
{
  {
    init_simple_test("Sf_Us_BFu15ll");
    static STRUCT_IF_C Sf_Us_BFu15ll lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Us_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu15ll)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu15ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu15ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "Sf_Us_BFu15ll");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "Sf_Us_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu15ll, Sf_Us_BFu15ll)
//============================================================================



static void Test_Sf_Us_BFu15s()
{
  {
    init_simple_test("Sf_Us_BFu15s");
    static STRUCT_IF_C Sf_Us_BFu15s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Us_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu15s)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu15s.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu15s.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "Sf_Us_BFu15s");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "Sf_Us_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu15s, Sf_Us_BFu15s)
//============================================================================



static void Test_Sf_Us_BFu16i()
{
  {
    init_simple_test("Sf_Us_BFu16i");
    static STRUCT_IF_C Sf_Us_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Us_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu16i)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu16i.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu16i.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "Sf_Us_BFu16i");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "Sf_Us_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu16i, Sf_Us_BFu16i)
//============================================================================



static void Test_Sf_Us_BFu16ll()
{
  {
    init_simple_test("Sf_Us_BFu16ll");
    static STRUCT_IF_C Sf_Us_BFu16ll lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Us_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu16ll)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu16ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu16ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "Sf_Us_BFu16ll");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "Sf_Us_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu16ll, Sf_Us_BFu16ll)
//============================================================================



static void Test_Sf_Us_BFu16s()
{
  {
    init_simple_test("Sf_Us_BFu16s");
    static STRUCT_IF_C Sf_Us_BFu16s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Us_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu16s)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu16s.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu16s.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "Sf_Us_BFu16s");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "Sf_Us_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu16s, Sf_Us_BFu16s)
//============================================================================



static void Test_Sf_Us_BFu17i()
{
  {
    init_simple_test("Sf_Us_BFu17i");
    static STRUCT_IF_C Sf_Us_BFu17i lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Us_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu17i)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu17i.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu17i.v2");
    set_bf_and_test(lv, v3, 2, 0, 17, 1, "Sf_Us_BFu17i");
    set_bf_and_test(lv, v3, 2, 0, 17, hide_ull(1LL<<16), "Sf_Us_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu17i, Sf_Us_BFu17i)
//============================================================================



static void Test_Sf_Us_BFu17ll()
{
  {
    init_simple_test("Sf_Us_BFu17ll");
    static STRUCT_IF_C Sf_Us_BFu17ll lv;
    check2(sizeof(lv), 5, "sizeof(Sf_Us_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu17ll)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu17ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu17ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 17, 1, "Sf_Us_BFu17ll");
    set_bf_and_test(lv, v3, 2, 0, 17, hide_ull(1LL<<16), "Sf_Us_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu17ll, Sf_Us_BFu17ll)
//============================================================================



static void Test_Sf_Us_BFu1c()
{
  {
    init_simple_test("Sf_Us_BFu1c");
    static STRUCT_IF_C Sf_Us_BFu1c lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Us_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu1c)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu1c.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu1c.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Sf_Us_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu1c, Sf_Us_BFu1c)
//============================================================================



static void Test_Sf_Us_BFu1i()
{
  {
    init_simple_test("Sf_Us_BFu1i");
    static STRUCT_IF_C Sf_Us_BFu1i lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Us_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu1i)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu1i.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu1i.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Sf_Us_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu1i, Sf_Us_BFu1i)
//============================================================================



static void Test_Sf_Us_BFu1ll()
{
  {
    init_simple_test("Sf_Us_BFu1ll");
    static STRUCT_IF_C Sf_Us_BFu1ll lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Us_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu1ll)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu1ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu1ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Sf_Us_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu1ll, Sf_Us_BFu1ll)
//============================================================================



static void Test_Sf_Us_BFu1s()
{
  {
    init_simple_test("Sf_Us_BFu1s");
    static STRUCT_IF_C Sf_Us_BFu1s lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Us_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu1s)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu1s.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu1s.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Sf_Us_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu1s, Sf_Us_BFu1s)
//============================================================================



static void Test_Sf_Us_BFu31i()
{
  {
    init_simple_test("Sf_Us_BFu31i");
    static STRUCT_IF_C Sf_Us_BFu31i lv;
    check2(sizeof(lv), 6, "sizeof(Sf_Us_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu31i)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu31i.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu31i.v2");
    set_bf_and_test(lv, v3, 2, 0, 31, 1, "Sf_Us_BFu31i");
    set_bf_and_test(lv, v3, 2, 0, 31, hide_ull(1LL<<30), "Sf_Us_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu31i, Sf_Us_BFu31i)
//============================================================================



static void Test_Sf_Us_BFu31ll()
{
  {
    init_simple_test("Sf_Us_BFu31ll");
    static STRUCT_IF_C Sf_Us_BFu31ll lv;
    check2(sizeof(lv), 6, "sizeof(Sf_Us_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu31ll)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu31ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu31ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 31, 1, "Sf_Us_BFu31ll");
    set_bf_and_test(lv, v3, 2, 0, 31, hide_ull(1LL<<30), "Sf_Us_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu31ll, Sf_Us_BFu31ll)
//============================================================================



static void Test_Sf_Us_BFu32i()
{
  {
    init_simple_test("Sf_Us_BFu32i");
    static STRUCT_IF_C Sf_Us_BFu32i lv;
    check2(sizeof(lv), 6, "sizeof(Sf_Us_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu32i)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu32i.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu32i.v2");
    set_bf_and_test(lv, v3, 2, 0, 32, 1, "Sf_Us_BFu32i");
    set_bf_and_test(lv, v3, 2, 0, 32, hide_ull(1LL<<31), "Sf_Us_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu32i, Sf_Us_BFu32i)
//============================================================================



static void Test_Sf_Us_BFu32ll()
{
  {
    init_simple_test("Sf_Us_BFu32ll");
    static STRUCT_IF_C Sf_Us_BFu32ll lv;
    check2(sizeof(lv), 6, "sizeof(Sf_Us_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu32ll)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu32ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu32ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 32, 1, "Sf_Us_BFu32ll");
    set_bf_and_test(lv, v3, 2, 0, 32, hide_ull(1LL<<31), "Sf_Us_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu32ll, Sf_Us_BFu32ll)
//============================================================================



static void Test_Sf_Us_BFu33()
{
  {
    init_simple_test("Sf_Us_BFu33");
    static STRUCT_IF_C Sf_Us_BFu33 lv;
    check2(sizeof(lv), 7, "sizeof(Sf_Us_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu33)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu33.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu33.v2");
    set_bf_and_test(lv, v3, 2, 0, 33, 1, "Sf_Us_BFu33");
    set_bf_and_test(lv, v3, 2, 0, 33, hide_ull(1LL<<32), "Sf_Us_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu33, Sf_Us_BFu33)
//============================================================================



static void Test_Sf_Us_BFu7c()
{
  {
    init_simple_test("Sf_Us_BFu7c");
    static STRUCT_IF_C Sf_Us_BFu7c lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Us_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu7c)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu7c.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu7c.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Sf_Us_BFu7c");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Sf_Us_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu7c, Sf_Us_BFu7c)
//============================================================================



static void Test_Sf_Us_BFu7i()
{
  {
    init_simple_test("Sf_Us_BFu7i");
    static STRUCT_IF_C Sf_Us_BFu7i lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Us_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu7i)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu7i.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu7i.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Sf_Us_BFu7i");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Sf_Us_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu7i, Sf_Us_BFu7i)
//============================================================================



static void Test_Sf_Us_BFu7ll()
{
  {
    init_simple_test("Sf_Us_BFu7ll");
    static STRUCT_IF_C Sf_Us_BFu7ll lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Us_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu7ll)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu7ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu7ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Sf_Us_BFu7ll");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Sf_Us_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu7ll, Sf_Us_BFu7ll)
//============================================================================



static void Test_Sf_Us_BFu7s()
{
  {
    init_simple_test("Sf_Us_BFu7s");
    static STRUCT_IF_C Sf_Us_BFu7s lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Us_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu7s)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu7s.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu7s.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Sf_Us_BFu7s");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Sf_Us_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu7s, Sf_Us_BFu7s)
//============================================================================



static void Test_Sf_Us_BFu8c()
{
  {
    init_simple_test("Sf_Us_BFu8c");
    static STRUCT_IF_C Sf_Us_BFu8c lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Us_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu8c)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu8c.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu8c.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Sf_Us_BFu8c");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Sf_Us_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu8c, Sf_Us_BFu8c)
//============================================================================



static void Test_Sf_Us_BFu8i()
{
  {
    init_simple_test("Sf_Us_BFu8i");
    static STRUCT_IF_C Sf_Us_BFu8i lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Us_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu8i)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu8i.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu8i.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Sf_Us_BFu8i");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Sf_Us_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu8i, Sf_Us_BFu8i)
//============================================================================



static void Test_Sf_Us_BFu8ll()
{
  {
    init_simple_test("Sf_Us_BFu8ll");
    static STRUCT_IF_C Sf_Us_BFu8ll lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Us_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu8ll)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu8ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu8ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Sf_Us_BFu8ll");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Sf_Us_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu8ll, Sf_Us_BFu8ll)
//============================================================================



static void Test_Sf_Us_BFu8s()
{
  {
    init_simple_test("Sf_Us_BFu8s");
    static STRUCT_IF_C Sf_Us_BFu8s lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Us_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu8s)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu8s.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu8s.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Sf_Us_BFu8s");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Sf_Us_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu8s, Sf_Us_BFu8s)
//============================================================================



static void Test_Sf_Us_BFu9i()
{
  {
    init_simple_test("Sf_Us_BFu9i");
    static STRUCT_IF_C Sf_Us_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Us_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu9i)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu9i.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu9i.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "Sf_Us_BFu9i");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "Sf_Us_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu9i, Sf_Us_BFu9i)
//============================================================================



static void Test_Sf_Us_BFu9ll()
{
  {
    init_simple_test("Sf_Us_BFu9ll");
    static STRUCT_IF_C Sf_Us_BFu9ll lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Us_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu9ll)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu9ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu9ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "Sf_Us_BFu9ll");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "Sf_Us_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu9ll, Sf_Us_BFu9ll)
//============================================================================



static void Test_Sf_Us_BFu9s()
{
  {
    init_simple_test("Sf_Us_BFu9s");
    static STRUCT_IF_C Sf_Us_BFu9s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Us_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_BFu9s)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu9s.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu9s.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "Sf_Us_BFu9s");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "Sf_Us_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu9s, Sf_Us_BFu9s)
//============================================================================



static void Test_Sf_Us_C()
{
  {
    init_simple_test("Sf_Us_C");
    STRUCT_IF_C Sf_Us_C lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Us_C)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_C)");
    check_field_offset(lv, v1, 0, "Sf_Us_C.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_C.v2");
    check_field_offset(lv, v3, 2, "Sf_Us_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_C, Sf_Us_C)
//============================================================================



static void Test_Sf_Us_D()
{
  {
    init_simple_test("Sf_Us_D");
    STRUCT_IF_C Sf_Us_D lv;
    check2(sizeof(lv), 10, "sizeof(Sf_Us_D)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_D)");
    check_field_offset(lv, v1, 0, "Sf_Us_D.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_D.v2");
    check_field_offset(lv, v3, 2, "Sf_Us_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_D, Sf_Us_D)
//============================================================================



static void Test_Sf_Us_F()
{
  {
    init_simple_test("Sf_Us_F");
    STRUCT_IF_C Sf_Us_F lv;
    check2(sizeof(lv), 6, "sizeof(Sf_Us_F)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_F)");
    check_field_offset(lv, v1, 0, "Sf_Us_F.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_F.v2");
    check_field_offset(lv, v3, 2, "Sf_Us_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_F, Sf_Us_F)
//============================================================================



static void Test_Sf_Us_I()
{
  {
    init_simple_test("Sf_Us_I");
    STRUCT_IF_C Sf_Us_I lv;
    check2(sizeof(lv), 6, "sizeof(Sf_Us_I)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_I)");
    check_field_offset(lv, v1, 0, "Sf_Us_I.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_I.v2");
    check_field_offset(lv, v3, 2, "Sf_Us_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_I, Sf_Us_I)
//============================================================================



static void Test_Sf_Us_Ip()
{
  {
    init_simple_test("Sf_Us_Ip");
    STRUCT_IF_C Sf_Us_Ip lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Us_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_Ip)");
    check_field_offset(lv, v1, 0, "Sf_Us_Ip.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_Ip.v2");
    check_field_offset(lv, v3, 2, "Sf_Us_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_Ip, Sf_Us_Ip)
//============================================================================



static void Test_Sf_Us_L()
{
  {
    init_simple_test("Sf_Us_L");
    STRUCT_IF_C Sf_Us_L lv;
    check2(sizeof(lv), 10, "sizeof(Sf_Us_L)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_L)");
    check_field_offset(lv, v1, 0, "Sf_Us_L.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_L.v2");
    check_field_offset(lv, v3, 2, "Sf_Us_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_L, Sf_Us_L)
//============================================================================



static void Test_Sf_Us_S()
{
  {
    init_simple_test("Sf_Us_S");
    STRUCT_IF_C Sf_Us_S lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Us_S)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_S)");
    check_field_offset(lv, v1, 0, "Sf_Us_S.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_S.v2");
    check_field_offset(lv, v3, 2, "Sf_Us_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_S, Sf_Us_S)
//============================================================================



static void Test_Sf_Us_Sf()
{
  {
    init_simple_test("Sf_Us_Sf");
    STRUCT_IF_C Sf_Us_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Us_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_Sf)");
    check_field_offset(lv, v1, 0, "Sf_Us_Sf.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_Sf.v2");
    check_field_offset(lv, v3, 2, "Sf_Us_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_Sf, Sf_Us_Sf)
//============================================================================



static void Test_Sf_Us_Uc()
{
  {
    init_simple_test("Sf_Us_Uc");
    STRUCT_IF_C Sf_Us_Uc lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Us_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_Uc)");
    check_field_offset(lv, v1, 0, "Sf_Us_Uc.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_Uc.v2");
    check_field_offset(lv, v3, 2, "Sf_Us_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_Uc, Sf_Us_Uc)
//============================================================================



static void Test_Sf_Us_Ui()
{
  {
    init_simple_test("Sf_Us_Ui");
    STRUCT_IF_C Sf_Us_Ui lv;
    check2(sizeof(lv), 6, "sizeof(Sf_Us_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_Ui)");
    check_field_offset(lv, v1, 0, "Sf_Us_Ui.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_Ui.v2");
    check_field_offset(lv, v3, 2, "Sf_Us_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_Ui, Sf_Us_Ui)
//============================================================================



static void Test_Sf_Us_Ul()
{
  {
    init_simple_test("Sf_Us_Ul");
    STRUCT_IF_C Sf_Us_Ul lv;
    check2(sizeof(lv), 10, "sizeof(Sf_Us_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_Ul)");
    check_field_offset(lv, v1, 0, "Sf_Us_Ul.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_Ul.v2");
    check_field_offset(lv, v3, 2, "Sf_Us_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_Ul, Sf_Us_Ul)
//============================================================================



static void Test_Sf_Us_Us()
{
  {
    init_simple_test("Sf_Us_Us");
    STRUCT_IF_C Sf_Us_Us lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Us_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_Us)");
    check_field_offset(lv, v1, 0, "Sf_Us_Us.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_Us.v2");
    check_field_offset(lv, v3, 2, "Sf_Us_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_Us, Sf_Us_Us)
//============================================================================



static void Test_Sf_Us_Vp()
{
  {
    init_simple_test("Sf_Us_Vp");
    STRUCT_IF_C Sf_Us_Vp lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Us_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_Vp)");
    check_field_offset(lv, v1, 0, "Sf_Us_Vp.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_Vp.v2");
    check_field_offset(lv, v3, 2, "Sf_Us_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_Vp, Sf_Us_Vp)
//============================================================================



static void Test_Sf_Vp()
{
  {
    init_simple_test("Sf_Vp");
    STRUCT_IF_C Sf_Vp lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp)");
    check_field_offset(lv, v1, 0, "Sf_Vp.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp, Sf_Vp)
//============================================================================



static void Test_Sf_Vp_BFu15i()
{
  {
    init_simple_test("Sf_Vp_BFu15i");
    static STRUCT_IF_C Sf_Vp_BFu15i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Vp_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu15i)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu15i.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu15i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 15, 1, "Sf_Vp_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Sf_Vp_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu15i, Sf_Vp_BFu15i)
//============================================================================



static void Test_Sf_Vp_BFu15ll()
{
  {
    init_simple_test("Sf_Vp_BFu15ll");
    static STRUCT_IF_C Sf_Vp_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Vp_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu15ll)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu15ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu15ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 15, 1, "Sf_Vp_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Sf_Vp_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu15ll, Sf_Vp_BFu15ll)
//============================================================================



static void Test_Sf_Vp_BFu15s()
{
  {
    init_simple_test("Sf_Vp_BFu15s");
    static STRUCT_IF_C Sf_Vp_BFu15s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Vp_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu15s)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu15s.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu15s.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 15, 1, "Sf_Vp_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Sf_Vp_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu15s, Sf_Vp_BFu15s)
//============================================================================



static void Test_Sf_Vp_BFu16i()
{
  {
    init_simple_test("Sf_Vp_BFu16i");
    static STRUCT_IF_C Sf_Vp_BFu16i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Vp_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu16i)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu16i.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu16i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 16, 1, "Sf_Vp_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Sf_Vp_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu16i, Sf_Vp_BFu16i)
//============================================================================



static void Test_Sf_Vp_BFu16ll()
{
  {
    init_simple_test("Sf_Vp_BFu16ll");
    static STRUCT_IF_C Sf_Vp_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Vp_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu16ll)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu16ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu16ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 16, 1, "Sf_Vp_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Sf_Vp_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu16ll, Sf_Vp_BFu16ll)
//============================================================================



static void Test_Sf_Vp_BFu16s()
{
  {
    init_simple_test("Sf_Vp_BFu16s");
    static STRUCT_IF_C Sf_Vp_BFu16s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Vp_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu16s)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu16s.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu16s.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 16, 1, "Sf_Vp_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Sf_Vp_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu16s, Sf_Vp_BFu16s)
//============================================================================



static void Test_Sf_Vp_BFu17i()
{
  {
    init_simple_test("Sf_Vp_BFu17i");
    static STRUCT_IF_C Sf_Vp_BFu17i lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Sf_Vp_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu17i)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu17i.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu17i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 17, 1, "Sf_Vp_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Sf_Vp_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu17i, Sf_Vp_BFu17i)
//============================================================================



static void Test_Sf_Vp_BFu17ll()
{
  {
    init_simple_test("Sf_Vp_BFu17ll");
    static STRUCT_IF_C Sf_Vp_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Sf_Vp_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu17ll)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu17ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu17ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 17, 1, "Sf_Vp_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Sf_Vp_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu17ll, Sf_Vp_BFu17ll)
//============================================================================



static void Test_Sf_Vp_BFu1c()
{
  {
    init_simple_test("Sf_Vp_BFu1c");
    static STRUCT_IF_C Sf_Vp_BFu1c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Vp_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu1c)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu1c.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu1c.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 1, 1, "Sf_Vp_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu1c, Sf_Vp_BFu1c)
//============================================================================



static void Test_Sf_Vp_BFu1i()
{
  {
    init_simple_test("Sf_Vp_BFu1i");
    static STRUCT_IF_C Sf_Vp_BFu1i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Vp_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu1i)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu1i.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu1i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 1, 1, "Sf_Vp_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu1i, Sf_Vp_BFu1i)
//============================================================================



static void Test_Sf_Vp_BFu1ll()
{
  {
    init_simple_test("Sf_Vp_BFu1ll");
    static STRUCT_IF_C Sf_Vp_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Vp_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu1ll)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu1ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu1ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 1, 1, "Sf_Vp_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu1ll, Sf_Vp_BFu1ll)
//============================================================================



static void Test_Sf_Vp_BFu1s()
{
  {
    init_simple_test("Sf_Vp_BFu1s");
    static STRUCT_IF_C Sf_Vp_BFu1s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Vp_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu1s)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu1s.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu1s.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 1, 1, "Sf_Vp_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu1s, Sf_Vp_BFu1s)
//============================================================================



static void Test_Sf_Vp_BFu31i()
{
  {
    init_simple_test("Sf_Vp_BFu31i");
    static STRUCT_IF_C Sf_Vp_BFu31i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Sf_Vp_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu31i)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu31i.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu31i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 31, 1, "Sf_Vp_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Sf_Vp_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu31i, Sf_Vp_BFu31i)
//============================================================================



static void Test_Sf_Vp_BFu31ll()
{
  {
    init_simple_test("Sf_Vp_BFu31ll");
    static STRUCT_IF_C Sf_Vp_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Sf_Vp_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu31ll)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu31ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu31ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 31, 1, "Sf_Vp_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Sf_Vp_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu31ll, Sf_Vp_BFu31ll)
//============================================================================



static void Test_Sf_Vp_BFu32i()
{
  {
    init_simple_test("Sf_Vp_BFu32i");
    static STRUCT_IF_C Sf_Vp_BFu32i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Sf_Vp_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu32i)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu32i.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu32i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 32, 1, "Sf_Vp_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Sf_Vp_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu32i, Sf_Vp_BFu32i)
//============================================================================



static void Test_Sf_Vp_BFu32ll()
{
  {
    init_simple_test("Sf_Vp_BFu32ll");
    static STRUCT_IF_C Sf_Vp_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Sf_Vp_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu32ll)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu32ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu32ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 32, 1, "Sf_Vp_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Sf_Vp_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu32ll, Sf_Vp_BFu32ll)
//============================================================================



static void Test_Sf_Vp_BFu33()
{
  {
    init_simple_test("Sf_Vp_BFu33");
    static STRUCT_IF_C Sf_Vp_BFu33 lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Sf_Vp_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu33)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu33.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu33.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 33, 1, "Sf_Vp_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Sf_Vp_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu33, Sf_Vp_BFu33)
//============================================================================



static void Test_Sf_Vp_BFu7c()
{
  {
    init_simple_test("Sf_Vp_BFu7c");
    static STRUCT_IF_C Sf_Vp_BFu7c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Vp_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu7c)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu7c.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu7c.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, 1, "Sf_Vp_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Sf_Vp_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu7c, Sf_Vp_BFu7c)
//============================================================================



static void Test_Sf_Vp_BFu7i()
{
  {
    init_simple_test("Sf_Vp_BFu7i");
    static STRUCT_IF_C Sf_Vp_BFu7i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Vp_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu7i)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu7i.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu7i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, 1, "Sf_Vp_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Sf_Vp_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu7i, Sf_Vp_BFu7i)
//============================================================================



static void Test_Sf_Vp_BFu7ll()
{
  {
    init_simple_test("Sf_Vp_BFu7ll");
    static STRUCT_IF_C Sf_Vp_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Vp_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu7ll)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu7ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu7ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, 1, "Sf_Vp_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Sf_Vp_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu7ll, Sf_Vp_BFu7ll)
//============================================================================



static void Test_Sf_Vp_BFu7s()
{
  {
    init_simple_test("Sf_Vp_BFu7s");
    static STRUCT_IF_C Sf_Vp_BFu7s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Vp_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu7s)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu7s.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu7s.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, 1, "Sf_Vp_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Sf_Vp_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu7s, Sf_Vp_BFu7s)
//============================================================================



static void Test_Sf_Vp_BFu8c()
{
  {
    init_simple_test("Sf_Vp_BFu8c");
    static STRUCT_IF_C Sf_Vp_BFu8c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Vp_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu8c)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu8c.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu8c.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, 1, "Sf_Vp_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Sf_Vp_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu8c, Sf_Vp_BFu8c)
//============================================================================



static void Test_Sf_Vp_BFu8i()
{
  {
    init_simple_test("Sf_Vp_BFu8i");
    static STRUCT_IF_C Sf_Vp_BFu8i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Vp_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu8i)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu8i.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu8i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, 1, "Sf_Vp_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Sf_Vp_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu8i, Sf_Vp_BFu8i)
//============================================================================



static void Test_Sf_Vp_BFu8ll()
{
  {
    init_simple_test("Sf_Vp_BFu8ll");
    static STRUCT_IF_C Sf_Vp_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Vp_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu8ll)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu8ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu8ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, 1, "Sf_Vp_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Sf_Vp_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu8ll, Sf_Vp_BFu8ll)
//============================================================================



static void Test_Sf_Vp_BFu8s()
{
  {
    init_simple_test("Sf_Vp_BFu8s");
    static STRUCT_IF_C Sf_Vp_BFu8s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Vp_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu8s)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu8s.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu8s.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, 1, "Sf_Vp_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Sf_Vp_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu8s, Sf_Vp_BFu8s)
//============================================================================



static void Test_Sf_Vp_BFu9i()
{
  {
    init_simple_test("Sf_Vp_BFu9i");
    static STRUCT_IF_C Sf_Vp_BFu9i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Vp_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu9i)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu9i.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu9i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 9, 1, "Sf_Vp_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Sf_Vp_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu9i, Sf_Vp_BFu9i)
//============================================================================



static void Test_Sf_Vp_BFu9ll()
{
  {
    init_simple_test("Sf_Vp_BFu9ll");
    static STRUCT_IF_C Sf_Vp_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Vp_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu9ll)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu9ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu9ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 9, 1, "Sf_Vp_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Sf_Vp_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu9ll, Sf_Vp_BFu9ll)
//============================================================================



static void Test_Sf_Vp_BFu9s()
{
  {
    init_simple_test("Sf_Vp_BFu9s");
    static STRUCT_IF_C Sf_Vp_BFu9s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Vp_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_BFu9s)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu9s.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu9s.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 9, 1, "Sf_Vp_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Sf_Vp_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu9s, Sf_Vp_BFu9s)
//============================================================================



static void Test_Sf_Vp_C()
{
  {
    init_simple_test("Sf_Vp_C");
    STRUCT_IF_C Sf_Vp_C lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Vp_C)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_C)");
    check_field_offset(lv, v1, 0, "Sf_Vp_C.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_C.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Vp_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_C, Sf_Vp_C)
//============================================================================



static void Test_Sf_Vp_D()
{
  {
    init_simple_test("Sf_Vp_D");
    STRUCT_IF_C Sf_Vp_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Sf_Vp_D)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_D)");
    check_field_offset(lv, v1, 0, "Sf_Vp_D.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_D.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Vp_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_D, Sf_Vp_D)
//============================================================================



static void Test_Sf_Vp_F()
{
  {
    init_simple_test("Sf_Vp_F");
    STRUCT_IF_C Sf_Vp_F lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Sf_Vp_F)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_F)");
    check_field_offset(lv, v1, 0, "Sf_Vp_F.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_F.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Vp_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_F, Sf_Vp_F)
//============================================================================



static void Test_Sf_Vp_I()
{
  {
    init_simple_test("Sf_Vp_I");
    STRUCT_IF_C Sf_Vp_I lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Sf_Vp_I)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_I)");
    check_field_offset(lv, v1, 0, "Sf_Vp_I.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_I.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Vp_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_I, Sf_Vp_I)
//============================================================================



static void Test_Sf_Vp_Ip()
{
  {
    init_simple_test("Sf_Vp_Ip");
    STRUCT_IF_C Sf_Vp_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Sf_Vp_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_Ip)");
    check_field_offset(lv, v1, 0, "Sf_Vp_Ip.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_Ip.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Vp_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_Ip, Sf_Vp_Ip)
//============================================================================



static void Test_Sf_Vp_L()
{
  {
    init_simple_test("Sf_Vp_L");
    STRUCT_IF_C Sf_Vp_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Sf_Vp_L)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_L)");
    check_field_offset(lv, v1, 0, "Sf_Vp_L.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_L.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Vp_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_L, Sf_Vp_L)
//============================================================================



static void Test_Sf_Vp_S()
{
  {
    init_simple_test("Sf_Vp_S");
    STRUCT_IF_C Sf_Vp_S lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Vp_S)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_S)");
    check_field_offset(lv, v1, 0, "Sf_Vp_S.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_S.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Vp_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_S, Sf_Vp_S)
//============================================================================



static void Test_Sf_Vp_Sf()
{
  {
    init_simple_test("Sf_Vp_Sf");
    STRUCT_IF_C Sf_Vp_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_Vp_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_Sf)");
    check_field_offset(lv, v1, 0, "Sf_Vp_Sf.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Vp_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_Sf, Sf_Vp_Sf)
//============================================================================



static void Test_Sf_Vp_Uc()
{
  {
    init_simple_test("Sf_Vp_Uc");
    STRUCT_IF_C Sf_Vp_Uc lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_Vp_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_Uc)");
    check_field_offset(lv, v1, 0, "Sf_Vp_Uc.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_Uc.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Vp_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_Uc, Sf_Vp_Uc)
//============================================================================



static void Test_Sf_Vp_Ui()
{
  {
    init_simple_test("Sf_Vp_Ui");
    STRUCT_IF_C Sf_Vp_Ui lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Sf_Vp_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_Ui)");
    check_field_offset(lv, v1, 0, "Sf_Vp_Ui.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_Ui.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Vp_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_Ui, Sf_Vp_Ui)
//============================================================================



static void Test_Sf_Vp_Ul()
{
  {
    init_simple_test("Sf_Vp_Ul");
    STRUCT_IF_C Sf_Vp_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Sf_Vp_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_Ul)");
    check_field_offset(lv, v1, 0, "Sf_Vp_Ul.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_Ul.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Vp_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_Ul, Sf_Vp_Ul)
//============================================================================



static void Test_Sf_Vp_Us()
{
  {
    init_simple_test("Sf_Vp_Us");
    STRUCT_IF_C Sf_Vp_Us lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Vp_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_Us)");
    check_field_offset(lv, v1, 0, "Sf_Vp_Us.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_Us.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Vp_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_Us, Sf_Vp_Us)
//============================================================================



static void Test_Sf_Vp_Vp()
{
  {
    init_simple_test("Sf_Vp_Vp");
    STRUCT_IF_C Sf_Vp_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Sf_Vp_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_Vp)");
    check_field_offset(lv, v1, 0, "Sf_Vp_Vp.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_Vp.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_Vp_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_Vp, Sf_Vp_Vp)
//============================================================================



static void Test_Uc_BFu15i_Sf()
{
  {
    init_simple_test("Uc_BFu15i_Sf");
    static STRUCT_IF_C Uc_BFu15i_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Uc_BFu15i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu15i_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu15i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "Uc_BFu15i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "Uc_BFu15i_Sf");
    check_field_offset(lv, v3, 3, "Uc_BFu15i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu15i_Sf, Uc_BFu15i_Sf)
//============================================================================



static void Test_Uc_BFu15ll_Sf()
{
  {
    init_simple_test("Uc_BFu15ll_Sf");
    static STRUCT_IF_C Uc_BFu15ll_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Uc_BFu15ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu15ll_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu15ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "Uc_BFu15ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "Uc_BFu15ll_Sf");
    check_field_offset(lv, v3, 3, "Uc_BFu15ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu15ll_Sf, Uc_BFu15ll_Sf)
//============================================================================



static void Test_Uc_BFu15s_Sf()
{
  {
    init_simple_test("Uc_BFu15s_Sf");
    static STRUCT_IF_C Uc_BFu15s_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Uc_BFu15s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu15s_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu15s_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "Uc_BFu15s_Sf");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "Uc_BFu15s_Sf");
    check_field_offset(lv, v3, 3, "Uc_BFu15s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu15s_Sf, Uc_BFu15s_Sf)
//============================================================================



static void Test_Uc_BFu16i_Sf()
{
  {
    init_simple_test("Uc_BFu16i_Sf");
    static STRUCT_IF_C Uc_BFu16i_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Uc_BFu16i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu16i_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu16i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "Uc_BFu16i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "Uc_BFu16i_Sf");
    check_field_offset(lv, v3, 3, "Uc_BFu16i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu16i_Sf, Uc_BFu16i_Sf)
//============================================================================



static void Test_Uc_BFu16ll_Sf()
{
  {
    init_simple_test("Uc_BFu16ll_Sf");
    static STRUCT_IF_C Uc_BFu16ll_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Uc_BFu16ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu16ll_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu16ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "Uc_BFu16ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "Uc_BFu16ll_Sf");
    check_field_offset(lv, v3, 3, "Uc_BFu16ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu16ll_Sf, Uc_BFu16ll_Sf)
//============================================================================



static void Test_Uc_BFu16s_Sf()
{
  {
    init_simple_test("Uc_BFu16s_Sf");
    static STRUCT_IF_C Uc_BFu16s_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Uc_BFu16s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu16s_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu16s_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "Uc_BFu16s_Sf");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "Uc_BFu16s_Sf");
    check_field_offset(lv, v3, 3, "Uc_BFu16s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu16s_Sf, Uc_BFu16s_Sf)
//============================================================================



static void Test_Uc_BFu17i_Sf()
{
  {
    init_simple_test("Uc_BFu17i_Sf");
    static STRUCT_IF_C Uc_BFu17i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Uc_BFu17i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu17i_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu17i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "Uc_BFu17i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "Uc_BFu17i_Sf");
    check_field_offset(lv, v3, 4, "Uc_BFu17i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu17i_Sf, Uc_BFu17i_Sf)
//============================================================================



static void Test_Uc_BFu17ll_Sf()
{
  {
    init_simple_test("Uc_BFu17ll_Sf");
    static STRUCT_IF_C Uc_BFu17ll_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Uc_BFu17ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu17ll_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu17ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "Uc_BFu17ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "Uc_BFu17ll_Sf");
    check_field_offset(lv, v3, 4, "Uc_BFu17ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu17ll_Sf, Uc_BFu17ll_Sf)
//============================================================================



static void Test_Uc_BFu1c_Sf()
{
  {
    init_simple_test("Uc_BFu1c_Sf");
    static STRUCT_IF_C Uc_BFu1c_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Uc_BFu1c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu1c_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu1c_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "Uc_BFu1c_Sf");
    check_field_offset(lv, v3, 2, "Uc_BFu1c_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu1c_Sf, Uc_BFu1c_Sf)
//============================================================================



static void Test_Uc_BFu1i_Sf()
{
  {
    init_simple_test("Uc_BFu1i_Sf");
    static STRUCT_IF_C Uc_BFu1i_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Uc_BFu1i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu1i_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu1i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "Uc_BFu1i_Sf");
    check_field_offset(lv, v3, 2, "Uc_BFu1i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu1i_Sf, Uc_BFu1i_Sf)
//============================================================================



static void Test_Uc_BFu1ll_Sf()
{
  {
    init_simple_test("Uc_BFu1ll_Sf");
    static STRUCT_IF_C Uc_BFu1ll_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Uc_BFu1ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu1ll_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu1ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "Uc_BFu1ll_Sf");
    check_field_offset(lv, v3, 2, "Uc_BFu1ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu1ll_Sf, Uc_BFu1ll_Sf)
//============================================================================



static void Test_Uc_BFu1s_Sf()
{
  {
    init_simple_test("Uc_BFu1s_Sf");
    static STRUCT_IF_C Uc_BFu1s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Uc_BFu1s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu1s_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu1s_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "Uc_BFu1s_Sf");
    check_field_offset(lv, v3, 2, "Uc_BFu1s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu1s_Sf, Uc_BFu1s_Sf)
//============================================================================



static void Test_Uc_BFu31i_Sf()
{
  {
    init_simple_test("Uc_BFu31i_Sf");
    static STRUCT_IF_C Uc_BFu31i_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Uc_BFu31i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu31i_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu31i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "Uc_BFu31i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "Uc_BFu31i_Sf");
    check_field_offset(lv, v3, 5, "Uc_BFu31i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu31i_Sf, Uc_BFu31i_Sf)
//============================================================================



static void Test_Uc_BFu31ll_Sf()
{
  {
    init_simple_test("Uc_BFu31ll_Sf");
    static STRUCT_IF_C Uc_BFu31ll_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Uc_BFu31ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu31ll_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu31ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "Uc_BFu31ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "Uc_BFu31ll_Sf");
    check_field_offset(lv, v3, 5, "Uc_BFu31ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu31ll_Sf, Uc_BFu31ll_Sf)
//============================================================================



static void Test_Uc_BFu32i_Sf()
{
  {
    init_simple_test("Uc_BFu32i_Sf");
    static STRUCT_IF_C Uc_BFu32i_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Uc_BFu32i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu32i_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu32i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "Uc_BFu32i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "Uc_BFu32i_Sf");
    check_field_offset(lv, v3, 5, "Uc_BFu32i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu32i_Sf, Uc_BFu32i_Sf)
//============================================================================



static void Test_Uc_BFu32ll_Sf()
{
  {
    init_simple_test("Uc_BFu32ll_Sf");
    static STRUCT_IF_C Uc_BFu32ll_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Uc_BFu32ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu32ll_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu32ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "Uc_BFu32ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "Uc_BFu32ll_Sf");
    check_field_offset(lv, v3, 5, "Uc_BFu32ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu32ll_Sf, Uc_BFu32ll_Sf)
//============================================================================



static void Test_Uc_BFu33_Sf()
{
  {
    init_simple_test("Uc_BFu33_Sf");
    static STRUCT_IF_C Uc_BFu33_Sf lv;
    check2(sizeof(lv), 6, "sizeof(Uc_BFu33_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu33_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu33_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 33, 1, "Uc_BFu33_Sf");
    set_bf_and_test(lv, v2, 1, 0, 33, hide_ull(1LL<<32), "Uc_BFu33_Sf");
    check_field_offset(lv, v3, 6, "Uc_BFu33_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu33_Sf, Uc_BFu33_Sf)
//============================================================================



static void Test_Uc_BFu7c_Sf()
{
  {
    init_simple_test("Uc_BFu7c_Sf");
    static STRUCT_IF_C Uc_BFu7c_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Uc_BFu7c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu7c_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu7c_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "Uc_BFu7c_Sf");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "Uc_BFu7c_Sf");
    check_field_offset(lv, v3, 2, "Uc_BFu7c_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu7c_Sf, Uc_BFu7c_Sf)
//============================================================================



static void Test_Uc_BFu7i_Sf()
{
  {
    init_simple_test("Uc_BFu7i_Sf");
    static STRUCT_IF_C Uc_BFu7i_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Uc_BFu7i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu7i_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu7i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "Uc_BFu7i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "Uc_BFu7i_Sf");
    check_field_offset(lv, v3, 2, "Uc_BFu7i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu7i_Sf, Uc_BFu7i_Sf)
//============================================================================



static void Test_Uc_BFu7ll_Sf()
{
  {
    init_simple_test("Uc_BFu7ll_Sf");
    static STRUCT_IF_C Uc_BFu7ll_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Uc_BFu7ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu7ll_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu7ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "Uc_BFu7ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "Uc_BFu7ll_Sf");
    check_field_offset(lv, v3, 2, "Uc_BFu7ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu7ll_Sf, Uc_BFu7ll_Sf)
//============================================================================



static void Test_Uc_BFu7s_Sf()
{
  {
    init_simple_test("Uc_BFu7s_Sf");
    static STRUCT_IF_C Uc_BFu7s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Uc_BFu7s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu7s_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu7s_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "Uc_BFu7s_Sf");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "Uc_BFu7s_Sf");
    check_field_offset(lv, v3, 2, "Uc_BFu7s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu7s_Sf, Uc_BFu7s_Sf)
//============================================================================



static void Test_Uc_BFu8c_Sf()
{
  {
    init_simple_test("Uc_BFu8c_Sf");
    static STRUCT_IF_C Uc_BFu8c_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Uc_BFu8c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu8c_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu8c_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "Uc_BFu8c_Sf");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "Uc_BFu8c_Sf");
    check_field_offset(lv, v3, 2, "Uc_BFu8c_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu8c_Sf, Uc_BFu8c_Sf)
//============================================================================



static void Test_Uc_BFu8i_Sf()
{
  {
    init_simple_test("Uc_BFu8i_Sf");
    static STRUCT_IF_C Uc_BFu8i_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Uc_BFu8i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu8i_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu8i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "Uc_BFu8i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "Uc_BFu8i_Sf");
    check_field_offset(lv, v3, 2, "Uc_BFu8i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu8i_Sf, Uc_BFu8i_Sf)
//============================================================================



static void Test_Uc_BFu8ll_Sf()
{
  {
    init_simple_test("Uc_BFu8ll_Sf");
    static STRUCT_IF_C Uc_BFu8ll_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Uc_BFu8ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu8ll_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu8ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "Uc_BFu8ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "Uc_BFu8ll_Sf");
    check_field_offset(lv, v3, 2, "Uc_BFu8ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu8ll_Sf, Uc_BFu8ll_Sf)
//============================================================================



static void Test_Uc_BFu8s_Sf()
{
  {
    init_simple_test("Uc_BFu8s_Sf");
    static STRUCT_IF_C Uc_BFu8s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Uc_BFu8s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu8s_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu8s_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "Uc_BFu8s_Sf");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "Uc_BFu8s_Sf");
    check_field_offset(lv, v3, 2, "Uc_BFu8s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu8s_Sf, Uc_BFu8s_Sf)
//============================================================================



static void Test_Uc_BFu9i_Sf()
{
  {
    init_simple_test("Uc_BFu9i_Sf");
    static STRUCT_IF_C Uc_BFu9i_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Uc_BFu9i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu9i_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu9i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "Uc_BFu9i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "Uc_BFu9i_Sf");
    check_field_offset(lv, v3, 3, "Uc_BFu9i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu9i_Sf, Uc_BFu9i_Sf)
//============================================================================



static void Test_Uc_BFu9ll_Sf()
{
  {
    init_simple_test("Uc_BFu9ll_Sf");
    static STRUCT_IF_C Uc_BFu9ll_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Uc_BFu9ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu9ll_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu9ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "Uc_BFu9ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "Uc_BFu9ll_Sf");
    check_field_offset(lv, v3, 3, "Uc_BFu9ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu9ll_Sf, Uc_BFu9ll_Sf)
//============================================================================



static void Test_Uc_BFu9s_Sf()
{
  {
    init_simple_test("Uc_BFu9s_Sf");
    static STRUCT_IF_C Uc_BFu9s_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Uc_BFu9s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu9s_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu9s_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "Uc_BFu9s_Sf");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "Uc_BFu9s_Sf");
    check_field_offset(lv, v3, 3, "Uc_BFu9s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu9s_Sf, Uc_BFu9s_Sf)
//============================================================================



static void Test_Uc_C_Sf()
{
  {
    init_simple_test("Uc_C_Sf");
    STRUCT_IF_C Uc_C_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Uc_C_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_C_Sf)");
    check_field_offset(lv, v1, 0, "Uc_C_Sf.v1");
    check_field_offset(lv, v2, 1, "Uc_C_Sf.v2");
    check_field_offset(lv, v3, 2, "Uc_C_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_C_Sf, Uc_C_Sf)
//============================================================================



static void Test_Uc_D_Sf()
{
  {
    init_simple_test("Uc_D_Sf");
    STRUCT_IF_C Uc_D_Sf lv;
    check2(sizeof(lv), 9, "sizeof(Uc_D_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_D_Sf)");
    check_field_offset(lv, v1, 0, "Uc_D_Sf.v1");
    check_field_offset(lv, v2, 1, "Uc_D_Sf.v2");
    check_field_offset(lv, v3, 9, "Uc_D_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_D_Sf, Uc_D_Sf)
//============================================================================



static void Test_Uc_F_Sf()
{
  {
    init_simple_test("Uc_F_Sf");
    STRUCT_IF_C Uc_F_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Uc_F_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_F_Sf)");
    check_field_offset(lv, v1, 0, "Uc_F_Sf.v1");
    check_field_offset(lv, v2, 1, "Uc_F_Sf.v2");
    check_field_offset(lv, v3, 5, "Uc_F_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_F_Sf, Uc_F_Sf)
//============================================================================



static void Test_Uc_I_Sf()
{
  {
    init_simple_test("Uc_I_Sf");
    STRUCT_IF_C Uc_I_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Uc_I_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_I_Sf)");
    check_field_offset(lv, v1, 0, "Uc_I_Sf.v1");
    check_field_offset(lv, v2, 1, "Uc_I_Sf.v2");
    check_field_offset(lv, v3, 5, "Uc_I_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_I_Sf, Uc_I_Sf)
//============================================================================



static void Test_Uc_Ip_Sf()
{
  {
    init_simple_test("Uc_Ip_Sf");
    STRUCT_IF_C Uc_Ip_Sf lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Uc_Ip_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Ip_Sf)");
    check_field_offset(lv, v1, 0, "Uc_Ip_Sf.v1");
    check_field_offset(lv, v2, 1, "Uc_Ip_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Uc_Ip_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Ip_Sf, Uc_Ip_Sf)
//============================================================================



static void Test_Uc_L_Sf()
{
  {
    init_simple_test("Uc_L_Sf");
    STRUCT_IF_C Uc_L_Sf lv;
    check2(sizeof(lv), 9, "sizeof(Uc_L_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_L_Sf)");
    check_field_offset(lv, v1, 0, "Uc_L_Sf.v1");
    check_field_offset(lv, v2, 1, "Uc_L_Sf.v2");
    check_field_offset(lv, v3, 9, "Uc_L_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_L_Sf, Uc_L_Sf)
//============================================================================



static void Test_Uc_S_Sf()
{
  {
    init_simple_test("Uc_S_Sf");
    STRUCT_IF_C Uc_S_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Uc_S_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_S_Sf)");
    check_field_offset(lv, v1, 0, "Uc_S_Sf.v1");
    check_field_offset(lv, v2, 1, "Uc_S_Sf.v2");
    check_field_offset(lv, v3, 3, "Uc_S_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_S_Sf, Uc_S_Sf)
//============================================================================



static void Test_Uc_Sf()
{
  {
    init_simple_test("Uc_Sf");
    STRUCT_IF_C Uc_Sf lv;
    check2(sizeof(lv), 1, "sizeof(Uc_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf)");
    check_field_offset(lv, v1, 0, "Uc_Sf.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf, Uc_Sf)
//============================================================================



static void Test_Uc_Sf_BFu15i()
{
  {
    init_simple_test("Uc_Sf_BFu15i");
    static STRUCT_IF_C Uc_Sf_BFu15i lv;
    check2(sizeof(lv), 3, "sizeof(Uc_Sf_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu15i)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu15i.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu15i.v2");
    set_bf_and_test(lv, v3, 1, 0, 15, 1, "Uc_Sf_BFu15i");
    set_bf_and_test(lv, v3, 1, 0, 15, hide_ull(1LL<<14), "Uc_Sf_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu15i, Uc_Sf_BFu15i)
//============================================================================



static void Test_Uc_Sf_BFu15ll()
{
  {
    init_simple_test("Uc_Sf_BFu15ll");
    static STRUCT_IF_C Uc_Sf_BFu15ll lv;
    check2(sizeof(lv), 3, "sizeof(Uc_Sf_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu15ll)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu15ll.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu15ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 15, 1, "Uc_Sf_BFu15ll");
    set_bf_and_test(lv, v3, 1, 0, 15, hide_ull(1LL<<14), "Uc_Sf_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu15ll, Uc_Sf_BFu15ll)
//============================================================================



static void Test_Uc_Sf_BFu15s()
{
  {
    init_simple_test("Uc_Sf_BFu15s");
    static STRUCT_IF_C Uc_Sf_BFu15s lv;
    check2(sizeof(lv), 3, "sizeof(Uc_Sf_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu15s)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu15s.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu15s.v2");
    set_bf_and_test(lv, v3, 1, 0, 15, 1, "Uc_Sf_BFu15s");
    set_bf_and_test(lv, v3, 1, 0, 15, hide_ull(1LL<<14), "Uc_Sf_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu15s, Uc_Sf_BFu15s)
//============================================================================



static void Test_Uc_Sf_BFu16i()
{
  {
    init_simple_test("Uc_Sf_BFu16i");
    static STRUCT_IF_C Uc_Sf_BFu16i lv;
    check2(sizeof(lv), 3, "sizeof(Uc_Sf_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu16i)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu16i.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu16i.v2");
    set_bf_and_test(lv, v3, 1, 0, 16, 1, "Uc_Sf_BFu16i");
    set_bf_and_test(lv, v3, 1, 0, 16, hide_ull(1LL<<15), "Uc_Sf_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu16i, Uc_Sf_BFu16i)
//============================================================================



static void Test_Uc_Sf_BFu16ll()
{
  {
    init_simple_test("Uc_Sf_BFu16ll");
    static STRUCT_IF_C Uc_Sf_BFu16ll lv;
    check2(sizeof(lv), 3, "sizeof(Uc_Sf_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu16ll)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu16ll.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu16ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 16, 1, "Uc_Sf_BFu16ll");
    set_bf_and_test(lv, v3, 1, 0, 16, hide_ull(1LL<<15), "Uc_Sf_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu16ll, Uc_Sf_BFu16ll)
//============================================================================



static void Test_Uc_Sf_BFu16s()
{
  {
    init_simple_test("Uc_Sf_BFu16s");
    static STRUCT_IF_C Uc_Sf_BFu16s lv;
    check2(sizeof(lv), 3, "sizeof(Uc_Sf_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu16s)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu16s.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu16s.v2");
    set_bf_and_test(lv, v3, 1, 0, 16, 1, "Uc_Sf_BFu16s");
    set_bf_and_test(lv, v3, 1, 0, 16, hide_ull(1LL<<15), "Uc_Sf_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu16s, Uc_Sf_BFu16s)
//============================================================================



static void Test_Uc_Sf_BFu17i()
{
  {
    init_simple_test("Uc_Sf_BFu17i");
    static STRUCT_IF_C Uc_Sf_BFu17i lv;
    check2(sizeof(lv), 4, "sizeof(Uc_Sf_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu17i)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu17i.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu17i.v2");
    set_bf_and_test(lv, v3, 1, 0, 17, 1, "Uc_Sf_BFu17i");
    set_bf_and_test(lv, v3, 1, 0, 17, hide_ull(1LL<<16), "Uc_Sf_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu17i, Uc_Sf_BFu17i)
//============================================================================



static void Test_Uc_Sf_BFu17ll()
{
  {
    init_simple_test("Uc_Sf_BFu17ll");
    static STRUCT_IF_C Uc_Sf_BFu17ll lv;
    check2(sizeof(lv), 4, "sizeof(Uc_Sf_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu17ll)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu17ll.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu17ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 17, 1, "Uc_Sf_BFu17ll");
    set_bf_and_test(lv, v3, 1, 0, 17, hide_ull(1LL<<16), "Uc_Sf_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu17ll, Uc_Sf_BFu17ll)
//============================================================================



static void Test_Uc_Sf_BFu1c()
{
  {
    init_simple_test("Uc_Sf_BFu1c");
    static STRUCT_IF_C Uc_Sf_BFu1c lv;
    check2(sizeof(lv), 2, "sizeof(Uc_Sf_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu1c)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu1c.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu1c.v2");
    set_bf_and_test(lv, v3, 1, 0, 1, 1, "Uc_Sf_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu1c, Uc_Sf_BFu1c)
//============================================================================



static void Test_Uc_Sf_BFu1i()
{
  {
    init_simple_test("Uc_Sf_BFu1i");
    static STRUCT_IF_C Uc_Sf_BFu1i lv;
    check2(sizeof(lv), 2, "sizeof(Uc_Sf_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu1i)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu1i.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu1i.v2");
    set_bf_and_test(lv, v3, 1, 0, 1, 1, "Uc_Sf_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu1i, Uc_Sf_BFu1i)
//============================================================================



static void Test_Uc_Sf_BFu1ll()
{
  {
    init_simple_test("Uc_Sf_BFu1ll");
    static STRUCT_IF_C Uc_Sf_BFu1ll lv;
    check2(sizeof(lv), 2, "sizeof(Uc_Sf_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu1ll)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu1ll.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu1ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 1, 1, "Uc_Sf_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu1ll, Uc_Sf_BFu1ll)
//============================================================================



static void Test_Uc_Sf_BFu1s()
{
  {
    init_simple_test("Uc_Sf_BFu1s");
    static STRUCT_IF_C Uc_Sf_BFu1s lv;
    check2(sizeof(lv), 2, "sizeof(Uc_Sf_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu1s)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu1s.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu1s.v2");
    set_bf_and_test(lv, v3, 1, 0, 1, 1, "Uc_Sf_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu1s, Uc_Sf_BFu1s)
//============================================================================



static void Test_Uc_Sf_BFu31i()
{
  {
    init_simple_test("Uc_Sf_BFu31i");
    static STRUCT_IF_C Uc_Sf_BFu31i lv;
    check2(sizeof(lv), 5, "sizeof(Uc_Sf_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu31i)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu31i.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu31i.v2");
    set_bf_and_test(lv, v3, 1, 0, 31, 1, "Uc_Sf_BFu31i");
    set_bf_and_test(lv, v3, 1, 0, 31, hide_ull(1LL<<30), "Uc_Sf_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu31i, Uc_Sf_BFu31i)
//============================================================================



static void Test_Uc_Sf_BFu31ll()
{
  {
    init_simple_test("Uc_Sf_BFu31ll");
    static STRUCT_IF_C Uc_Sf_BFu31ll lv;
    check2(sizeof(lv), 5, "sizeof(Uc_Sf_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu31ll)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu31ll.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu31ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 31, 1, "Uc_Sf_BFu31ll");
    set_bf_and_test(lv, v3, 1, 0, 31, hide_ull(1LL<<30), "Uc_Sf_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu31ll, Uc_Sf_BFu31ll)
//============================================================================



static void Test_Uc_Sf_BFu32i()
{
  {
    init_simple_test("Uc_Sf_BFu32i");
    static STRUCT_IF_C Uc_Sf_BFu32i lv;
    check2(sizeof(lv), 5, "sizeof(Uc_Sf_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu32i)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu32i.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu32i.v2");
    set_bf_and_test(lv, v3, 1, 0, 32, 1, "Uc_Sf_BFu32i");
    set_bf_and_test(lv, v3, 1, 0, 32, hide_ull(1LL<<31), "Uc_Sf_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu32i, Uc_Sf_BFu32i)
//============================================================================



static void Test_Uc_Sf_BFu32ll()
{
  {
    init_simple_test("Uc_Sf_BFu32ll");
    static STRUCT_IF_C Uc_Sf_BFu32ll lv;
    check2(sizeof(lv), 5, "sizeof(Uc_Sf_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu32ll)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu32ll.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu32ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 32, 1, "Uc_Sf_BFu32ll");
    set_bf_and_test(lv, v3, 1, 0, 32, hide_ull(1LL<<31), "Uc_Sf_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu32ll, Uc_Sf_BFu32ll)
//============================================================================



static void Test_Uc_Sf_BFu33()
{
  {
    init_simple_test("Uc_Sf_BFu33");
    static STRUCT_IF_C Uc_Sf_BFu33 lv;
    check2(sizeof(lv), 6, "sizeof(Uc_Sf_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu33)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu33.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu33.v2");
    set_bf_and_test(lv, v3, 1, 0, 33, 1, "Uc_Sf_BFu33");
    set_bf_and_test(lv, v3, 1, 0, 33, hide_ull(1LL<<32), "Uc_Sf_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu33, Uc_Sf_BFu33)
//============================================================================



static void Test_Uc_Sf_BFu7c()
{
  {
    init_simple_test("Uc_Sf_BFu7c");
    static STRUCT_IF_C Uc_Sf_BFu7c lv;
    check2(sizeof(lv), 2, "sizeof(Uc_Sf_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu7c)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu7c.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu7c.v2");
    set_bf_and_test(lv, v3, 1, 0, 7, 1, "Uc_Sf_BFu7c");
    set_bf_and_test(lv, v3, 1, 0, 7, hide_ull(1LL<<6), "Uc_Sf_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu7c, Uc_Sf_BFu7c)
//============================================================================



static void Test_Uc_Sf_BFu7i()
{
  {
    init_simple_test("Uc_Sf_BFu7i");
    static STRUCT_IF_C Uc_Sf_BFu7i lv;
    check2(sizeof(lv), 2, "sizeof(Uc_Sf_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu7i)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu7i.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu7i.v2");
    set_bf_and_test(lv, v3, 1, 0, 7, 1, "Uc_Sf_BFu7i");
    set_bf_and_test(lv, v3, 1, 0, 7, hide_ull(1LL<<6), "Uc_Sf_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu7i, Uc_Sf_BFu7i)
//============================================================================



static void Test_Uc_Sf_BFu7ll()
{
  {
    init_simple_test("Uc_Sf_BFu7ll");
    static STRUCT_IF_C Uc_Sf_BFu7ll lv;
    check2(sizeof(lv), 2, "sizeof(Uc_Sf_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu7ll)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu7ll.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu7ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 7, 1, "Uc_Sf_BFu7ll");
    set_bf_and_test(lv, v3, 1, 0, 7, hide_ull(1LL<<6), "Uc_Sf_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu7ll, Uc_Sf_BFu7ll)
//============================================================================



static void Test_Uc_Sf_BFu7s()
{
  {
    init_simple_test("Uc_Sf_BFu7s");
    static STRUCT_IF_C Uc_Sf_BFu7s lv;
    check2(sizeof(lv), 2, "sizeof(Uc_Sf_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu7s)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu7s.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu7s.v2");
    set_bf_and_test(lv, v3, 1, 0, 7, 1, "Uc_Sf_BFu7s");
    set_bf_and_test(lv, v3, 1, 0, 7, hide_ull(1LL<<6), "Uc_Sf_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu7s, Uc_Sf_BFu7s)
//============================================================================



static void Test_Uc_Sf_BFu8c()
{
  {
    init_simple_test("Uc_Sf_BFu8c");
    static STRUCT_IF_C Uc_Sf_BFu8c lv;
    check2(sizeof(lv), 2, "sizeof(Uc_Sf_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu8c)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu8c.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu8c.v2");
    set_bf_and_test(lv, v3, 1, 0, 8, 1, "Uc_Sf_BFu8c");
    set_bf_and_test(lv, v3, 1, 0, 8, hide_ull(1LL<<7), "Uc_Sf_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu8c, Uc_Sf_BFu8c)
//============================================================================



static void Test_Uc_Sf_BFu8i()
{
  {
    init_simple_test("Uc_Sf_BFu8i");
    static STRUCT_IF_C Uc_Sf_BFu8i lv;
    check2(sizeof(lv), 2, "sizeof(Uc_Sf_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu8i)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu8i.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu8i.v2");
    set_bf_and_test(lv, v3, 1, 0, 8, 1, "Uc_Sf_BFu8i");
    set_bf_and_test(lv, v3, 1, 0, 8, hide_ull(1LL<<7), "Uc_Sf_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu8i, Uc_Sf_BFu8i)
//============================================================================



static void Test_Uc_Sf_BFu8ll()
{
  {
    init_simple_test("Uc_Sf_BFu8ll");
    static STRUCT_IF_C Uc_Sf_BFu8ll lv;
    check2(sizeof(lv), 2, "sizeof(Uc_Sf_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu8ll)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu8ll.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu8ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 8, 1, "Uc_Sf_BFu8ll");
    set_bf_and_test(lv, v3, 1, 0, 8, hide_ull(1LL<<7), "Uc_Sf_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu8ll, Uc_Sf_BFu8ll)
//============================================================================



static void Test_Uc_Sf_BFu8s()
{
  {
    init_simple_test("Uc_Sf_BFu8s");
    static STRUCT_IF_C Uc_Sf_BFu8s lv;
    check2(sizeof(lv), 2, "sizeof(Uc_Sf_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu8s)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu8s.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu8s.v2");
    set_bf_and_test(lv, v3, 1, 0, 8, 1, "Uc_Sf_BFu8s");
    set_bf_and_test(lv, v3, 1, 0, 8, hide_ull(1LL<<7), "Uc_Sf_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu8s, Uc_Sf_BFu8s)
//============================================================================



static void Test_Uc_Sf_BFu9i()
{
  {
    init_simple_test("Uc_Sf_BFu9i");
    static STRUCT_IF_C Uc_Sf_BFu9i lv;
    check2(sizeof(lv), 3, "sizeof(Uc_Sf_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu9i)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu9i.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu9i.v2");
    set_bf_and_test(lv, v3, 1, 0, 9, 1, "Uc_Sf_BFu9i");
    set_bf_and_test(lv, v3, 1, 0, 9, hide_ull(1LL<<8), "Uc_Sf_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu9i, Uc_Sf_BFu9i)
//============================================================================



static void Test_Uc_Sf_BFu9ll()
{
  {
    init_simple_test("Uc_Sf_BFu9ll");
    static STRUCT_IF_C Uc_Sf_BFu9ll lv;
    check2(sizeof(lv), 3, "sizeof(Uc_Sf_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu9ll)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu9ll.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu9ll.v2");
    set_bf_and_test(lv, v3, 1, 0, 9, 1, "Uc_Sf_BFu9ll");
    set_bf_and_test(lv, v3, 1, 0, 9, hide_ull(1LL<<8), "Uc_Sf_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu9ll, Uc_Sf_BFu9ll)
//============================================================================



static void Test_Uc_Sf_BFu9s()
{
  {
    init_simple_test("Uc_Sf_BFu9s");
    static STRUCT_IF_C Uc_Sf_BFu9s lv;
    check2(sizeof(lv), 3, "sizeof(Uc_Sf_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu9s)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu9s.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu9s.v2");
    set_bf_and_test(lv, v3, 1, 0, 9, 1, "Uc_Sf_BFu9s");
    set_bf_and_test(lv, v3, 1, 0, 9, hide_ull(1LL<<8), "Uc_Sf_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu9s, Uc_Sf_BFu9s)
//============================================================================



static void Test_Uc_Sf_C()
{
  {
    init_simple_test("Uc_Sf_C");
    STRUCT_IF_C Uc_Sf_C lv;
    check2(sizeof(lv), 2, "sizeof(Uc_Sf_C)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_C)");
    check_field_offset(lv, v1, 0, "Uc_Sf_C.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_C.v2");
    check_field_offset(lv, v3, 1, "Uc_Sf_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_C, Uc_Sf_C)
//============================================================================



static void Test_Uc_Sf_D()
{
  {
    init_simple_test("Uc_Sf_D");
    STRUCT_IF_C Uc_Sf_D lv;
    check2(sizeof(lv), 9, "sizeof(Uc_Sf_D)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_D)");
    check_field_offset(lv, v1, 0, "Uc_Sf_D.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_D.v2");
    check_field_offset(lv, v3, 1, "Uc_Sf_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_D, Uc_Sf_D)
//============================================================================



static void Test_Uc_Sf_F()
{
  {
    init_simple_test("Uc_Sf_F");
    STRUCT_IF_C Uc_Sf_F lv;
    check2(sizeof(lv), 5, "sizeof(Uc_Sf_F)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_F)");
    check_field_offset(lv, v1, 0, "Uc_Sf_F.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_F.v2");
    check_field_offset(lv, v3, 1, "Uc_Sf_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_F, Uc_Sf_F)
//============================================================================



static void Test_Uc_Sf_I()
{
  {
    init_simple_test("Uc_Sf_I");
    STRUCT_IF_C Uc_Sf_I lv;
    check2(sizeof(lv), 5, "sizeof(Uc_Sf_I)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_I)");
    check_field_offset(lv, v1, 0, "Uc_Sf_I.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_I.v2");
    check_field_offset(lv, v3, 1, "Uc_Sf_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_I, Uc_Sf_I)
//============================================================================



static void Test_Uc_Sf_Ip()
{
  {
    init_simple_test("Uc_Sf_Ip");
    STRUCT_IF_C Uc_Sf_Ip lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Uc_Sf_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_Ip)");
    check_field_offset(lv, v1, 0, "Uc_Sf_Ip.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_Ip.v2");
    check_field_offset(lv, v3, 1, "Uc_Sf_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_Ip, Uc_Sf_Ip)
//============================================================================



static void Test_Uc_Sf_L()
{
  {
    init_simple_test("Uc_Sf_L");
    STRUCT_IF_C Uc_Sf_L lv;
    check2(sizeof(lv), 9, "sizeof(Uc_Sf_L)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_L)");
    check_field_offset(lv, v1, 0, "Uc_Sf_L.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_L.v2");
    check_field_offset(lv, v3, 1, "Uc_Sf_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_L, Uc_Sf_L)
//============================================================================



static void Test_Uc_Sf_S()
{
  {
    init_simple_test("Uc_Sf_S");
    STRUCT_IF_C Uc_Sf_S lv;
    check2(sizeof(lv), 3, "sizeof(Uc_Sf_S)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_S)");
    check_field_offset(lv, v1, 0, "Uc_Sf_S.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_S.v2");
    check_field_offset(lv, v3, 1, "Uc_Sf_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_S, Uc_Sf_S)
//============================================================================



static void Test_Uc_Sf_Sf()
{
  {
    init_simple_test("Uc_Sf_Sf");
    STRUCT_IF_C Uc_Sf_Sf lv;
    check2(sizeof(lv), 1, "sizeof(Uc_Sf_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_Sf)");
    check_field_offset(lv, v1, 0, "Uc_Sf_Sf.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_Sf.v2");
    check_field_offset(lv, v3, 1, "Uc_Sf_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_Sf, Uc_Sf_Sf)
//============================================================================



static void Test_Uc_Sf_Uc()
{
  {
    init_simple_test("Uc_Sf_Uc");
    STRUCT_IF_C Uc_Sf_Uc lv;
    check2(sizeof(lv), 2, "sizeof(Uc_Sf_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_Uc)");
    check_field_offset(lv, v1, 0, "Uc_Sf_Uc.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_Uc.v2");
    check_field_offset(lv, v3, 1, "Uc_Sf_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_Uc, Uc_Sf_Uc)
//============================================================================



static void Test_Uc_Sf_Ui()
{
  {
    init_simple_test("Uc_Sf_Ui");
    STRUCT_IF_C Uc_Sf_Ui lv;
    check2(sizeof(lv), 5, "sizeof(Uc_Sf_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_Ui)");
    check_field_offset(lv, v1, 0, "Uc_Sf_Ui.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_Ui.v2");
    check_field_offset(lv, v3, 1, "Uc_Sf_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_Ui, Uc_Sf_Ui)
//============================================================================



static void Test_Uc_Sf_Ul()
{
  {
    init_simple_test("Uc_Sf_Ul");
    STRUCT_IF_C Uc_Sf_Ul lv;
    check2(sizeof(lv), 9, "sizeof(Uc_Sf_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_Ul)");
    check_field_offset(lv, v1, 0, "Uc_Sf_Ul.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_Ul.v2");
    check_field_offset(lv, v3, 1, "Uc_Sf_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_Ul, Uc_Sf_Ul)
//============================================================================



static void Test_Uc_Sf_Us()
{
  {
    init_simple_test("Uc_Sf_Us");
    STRUCT_IF_C Uc_Sf_Us lv;
    check2(sizeof(lv), 3, "sizeof(Uc_Sf_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_Us)");
    check_field_offset(lv, v1, 0, "Uc_Sf_Us.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_Us.v2");
    check_field_offset(lv, v3, 1, "Uc_Sf_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_Us, Uc_Sf_Us)
//============================================================================



static void Test_Uc_Sf_Vp()
{
  {
    init_simple_test("Uc_Sf_Vp");
    STRUCT_IF_C Uc_Sf_Vp lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Uc_Sf_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_Vp)");
    check_field_offset(lv, v1, 0, "Uc_Sf_Vp.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_Vp.v2");
    check_field_offset(lv, v3, 1, "Uc_Sf_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_Vp, Uc_Sf_Vp)
//============================================================================



static void Test_Uc_Uc_Sf()
{
  {
    init_simple_test("Uc_Uc_Sf");
    STRUCT_IF_C Uc_Uc_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Uc_Uc_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Uc_Sf)");
    check_field_offset(lv, v1, 0, "Uc_Uc_Sf.v1");
    check_field_offset(lv, v2, 1, "Uc_Uc_Sf.v2");
    check_field_offset(lv, v3, 2, "Uc_Uc_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Uc_Sf, Uc_Uc_Sf)
//============================================================================



static void Test_Uc_Ui_Sf()
{
  {
    init_simple_test("Uc_Ui_Sf");
    STRUCT_IF_C Uc_Ui_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Uc_Ui_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Ui_Sf)");
    check_field_offset(lv, v1, 0, "Uc_Ui_Sf.v1");
    check_field_offset(lv, v2, 1, "Uc_Ui_Sf.v2");
    check_field_offset(lv, v3, 5, "Uc_Ui_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Ui_Sf, Uc_Ui_Sf)
//============================================================================



static void Test_Uc_Ul_Sf()
{
  {
    init_simple_test("Uc_Ul_Sf");
    STRUCT_IF_C Uc_Ul_Sf lv;
    check2(sizeof(lv), 9, "sizeof(Uc_Ul_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Ul_Sf)");
    check_field_offset(lv, v1, 0, "Uc_Ul_Sf.v1");
    check_field_offset(lv, v2, 1, "Uc_Ul_Sf.v2");
    check_field_offset(lv, v3, 9, "Uc_Ul_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Ul_Sf, Uc_Ul_Sf)
//============================================================================



static void Test_Uc_Us_Sf()
{
  {
    init_simple_test("Uc_Us_Sf");
    STRUCT_IF_C Uc_Us_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Uc_Us_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Us_Sf)");
    check_field_offset(lv, v1, 0, "Uc_Us_Sf.v1");
    check_field_offset(lv, v2, 1, "Uc_Us_Sf.v2");
    check_field_offset(lv, v3, 3, "Uc_Us_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Us_Sf, Uc_Us_Sf)
//============================================================================



static void Test_Uc_Vp_Sf()
{
  {
    init_simple_test("Uc_Vp_Sf");
    STRUCT_IF_C Uc_Vp_Sf lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Uc_Vp_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Vp_Sf)");
    check_field_offset(lv, v1, 0, "Uc_Vp_Sf.v1");
    check_field_offset(lv, v2, 1, "Uc_Vp_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Uc_Vp_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Vp_Sf, Uc_Vp_Sf)
//============================================================================



static void Test_Ui_BFu15i_Sf()
{
  {
    init_simple_test("Ui_BFu15i_Sf");
    static STRUCT_IF_C Ui_BFu15i_Sf lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu15i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu15i_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu15i_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15i_Sf");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15i_Sf");
    check_field_offset(lv, v3, 6, "Ui_BFu15i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu15i_Sf, Ui_BFu15i_Sf)
//============================================================================



static void Test_Ui_BFu15ll_Sf()
{
  {
    init_simple_test("Ui_BFu15ll_Sf");
    static STRUCT_IF_C Ui_BFu15ll_Sf lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu15ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu15ll_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu15ll_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15ll_Sf");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15ll_Sf");
    check_field_offset(lv, v3, 6, "Ui_BFu15ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu15ll_Sf, Ui_BFu15ll_Sf)
//============================================================================



static void Test_Ui_BFu15s_Sf()
{
  {
    init_simple_test("Ui_BFu15s_Sf");
    static STRUCT_IF_C Ui_BFu15s_Sf lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu15s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu15s_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu15s_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15s_Sf");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15s_Sf");
    check_field_offset(lv, v3, 6, "Ui_BFu15s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu15s_Sf, Ui_BFu15s_Sf)
//============================================================================



static void Test_Ui_BFu16i_Sf()
{
  {
    init_simple_test("Ui_BFu16i_Sf");
    static STRUCT_IF_C Ui_BFu16i_Sf lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu16i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu16i_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu16i_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16i_Sf");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16i_Sf");
    check_field_offset(lv, v3, 6, "Ui_BFu16i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu16i_Sf, Ui_BFu16i_Sf)
//============================================================================



static void Test_Ui_BFu16ll_Sf()
{
  {
    init_simple_test("Ui_BFu16ll_Sf");
    static STRUCT_IF_C Ui_BFu16ll_Sf lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu16ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu16ll_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu16ll_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16ll_Sf");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16ll_Sf");
    check_field_offset(lv, v3, 6, "Ui_BFu16ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu16ll_Sf, Ui_BFu16ll_Sf)
//============================================================================



static void Test_Ui_BFu16s_Sf()
{
  {
    init_simple_test("Ui_BFu16s_Sf");
    static STRUCT_IF_C Ui_BFu16s_Sf lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu16s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu16s_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu16s_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16s_Sf");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16s_Sf");
    check_field_offset(lv, v3, 6, "Ui_BFu16s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu16s_Sf, Ui_BFu16s_Sf)
//============================================================================



static void Test_Ui_BFu17i_Sf()
{
  {
    init_simple_test("Ui_BFu17i_Sf");
    static STRUCT_IF_C Ui_BFu17i_Sf lv;
    check2(sizeof(lv), 7, "sizeof(Ui_BFu17i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu17i_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu17i_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu17i_Sf");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu17i_Sf");
    check_field_offset(lv, v3, 7, "Ui_BFu17i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu17i_Sf, Ui_BFu17i_Sf)
//============================================================================



static void Test_Ui_BFu17ll_Sf()
{
  {
    init_simple_test("Ui_BFu17ll_Sf");
    static STRUCT_IF_C Ui_BFu17ll_Sf lv;
    check2(sizeof(lv), 7, "sizeof(Ui_BFu17ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu17ll_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu17ll_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu17ll_Sf");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu17ll_Sf");
    check_field_offset(lv, v3, 7, "Ui_BFu17ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu17ll_Sf, Ui_BFu17ll_Sf)
//============================================================================



static void Test_Ui_BFu1c_Sf()
{
  {
    init_simple_test("Ui_BFu1c_Sf");
    static STRUCT_IF_C Ui_BFu1c_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu1c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu1c_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu1c_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1c_Sf");
    check_field_offset(lv, v3, 5, "Ui_BFu1c_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu1c_Sf, Ui_BFu1c_Sf)
//============================================================================



static void Test_Ui_BFu1i_Sf()
{
  {
    init_simple_test("Ui_BFu1i_Sf");
    static STRUCT_IF_C Ui_BFu1i_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu1i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu1i_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu1i_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1i_Sf");
    check_field_offset(lv, v3, 5, "Ui_BFu1i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu1i_Sf, Ui_BFu1i_Sf)
//============================================================================



static void Test_Ui_BFu1ll_Sf()
{
  {
    init_simple_test("Ui_BFu1ll_Sf");
    static STRUCT_IF_C Ui_BFu1ll_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu1ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu1ll_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu1ll_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1ll_Sf");
    check_field_offset(lv, v3, 5, "Ui_BFu1ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu1ll_Sf, Ui_BFu1ll_Sf)
//============================================================================



static void Test_Ui_BFu1s_Sf()
{
  {
    init_simple_test("Ui_BFu1s_Sf");
    static STRUCT_IF_C Ui_BFu1s_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu1s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu1s_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu1s_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1s_Sf");
    check_field_offset(lv, v3, 5, "Ui_BFu1s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu1s_Sf, Ui_BFu1s_Sf)
//============================================================================



static void Test_Ui_BFu31i_Sf()
{
  {
    init_simple_test("Ui_BFu31i_Sf");
    static STRUCT_IF_C Ui_BFu31i_Sf lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu31i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu31i_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu31i_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu31i_Sf");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu31i_Sf");
    check_field_offset(lv, v3, 8, "Ui_BFu31i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu31i_Sf, Ui_BFu31i_Sf)
//============================================================================



static void Test_Ui_BFu31ll_Sf()
{
  {
    init_simple_test("Ui_BFu31ll_Sf");
    static STRUCT_IF_C Ui_BFu31ll_Sf lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu31ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu31ll_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu31ll_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu31ll_Sf");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu31ll_Sf");
    check_field_offset(lv, v3, 8, "Ui_BFu31ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu31ll_Sf, Ui_BFu31ll_Sf)
//============================================================================



static void Test_Ui_BFu32i_Sf()
{
  {
    init_simple_test("Ui_BFu32i_Sf");
    static STRUCT_IF_C Ui_BFu32i_Sf lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu32i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu32i_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu32i_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu32i_Sf");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu32i_Sf");
    check_field_offset(lv, v3, 8, "Ui_BFu32i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu32i_Sf, Ui_BFu32i_Sf)
//============================================================================



static void Test_Ui_BFu32ll_Sf()
{
  {
    init_simple_test("Ui_BFu32ll_Sf");
    static STRUCT_IF_C Ui_BFu32ll_Sf lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu32ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu32ll_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu32ll_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu32ll_Sf");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu32ll_Sf");
    check_field_offset(lv, v3, 8, "Ui_BFu32ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu32ll_Sf, Ui_BFu32ll_Sf)
//============================================================================



static void Test_Ui_BFu33_Sf()
{
  {
    init_simple_test("Ui_BFu33_Sf");
    static STRUCT_IF_C Ui_BFu33_Sf lv;
    check2(sizeof(lv), 9, "sizeof(Ui_BFu33_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu33_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu33_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 33, 1, "Ui_BFu33_Sf");
    set_bf_and_test(lv, v2, 4, 0, 33, hide_ull(1LL<<32), "Ui_BFu33_Sf");
    check_field_offset(lv, v3, 9, "Ui_BFu33_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu33_Sf, Ui_BFu33_Sf)
//============================================================================



static void Test_Ui_BFu7c_Sf()
{
  {
    init_simple_test("Ui_BFu7c_Sf");
    static STRUCT_IF_C Ui_BFu7c_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu7c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu7c_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu7c_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7c_Sf");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7c_Sf");
    check_field_offset(lv, v3, 5, "Ui_BFu7c_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu7c_Sf, Ui_BFu7c_Sf)
//============================================================================



static void Test_Ui_BFu7i_Sf()
{
  {
    init_simple_test("Ui_BFu7i_Sf");
    static STRUCT_IF_C Ui_BFu7i_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu7i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu7i_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu7i_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7i_Sf");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7i_Sf");
    check_field_offset(lv, v3, 5, "Ui_BFu7i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu7i_Sf, Ui_BFu7i_Sf)
//============================================================================



static void Test_Ui_BFu7ll_Sf()
{
  {
    init_simple_test("Ui_BFu7ll_Sf");
    static STRUCT_IF_C Ui_BFu7ll_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu7ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu7ll_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu7ll_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7ll_Sf");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7ll_Sf");
    check_field_offset(lv, v3, 5, "Ui_BFu7ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu7ll_Sf, Ui_BFu7ll_Sf)
//============================================================================



static void Test_Ui_BFu7s_Sf()
{
  {
    init_simple_test("Ui_BFu7s_Sf");
    static STRUCT_IF_C Ui_BFu7s_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu7s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu7s_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu7s_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7s_Sf");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7s_Sf");
    check_field_offset(lv, v3, 5, "Ui_BFu7s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu7s_Sf, Ui_BFu7s_Sf)
//============================================================================



static void Test_Ui_BFu8c_Sf()
{
  {
    init_simple_test("Ui_BFu8c_Sf");
    static STRUCT_IF_C Ui_BFu8c_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu8c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu8c_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu8c_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8c_Sf");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8c_Sf");
    check_field_offset(lv, v3, 5, "Ui_BFu8c_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu8c_Sf, Ui_BFu8c_Sf)
//============================================================================



static void Test_Ui_BFu8i_Sf()
{
  {
    init_simple_test("Ui_BFu8i_Sf");
    static STRUCT_IF_C Ui_BFu8i_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu8i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu8i_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu8i_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8i_Sf");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8i_Sf");
    check_field_offset(lv, v3, 5, "Ui_BFu8i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu8i_Sf, Ui_BFu8i_Sf)
//============================================================================



static void Test_Ui_BFu8ll_Sf()
{
  {
    init_simple_test("Ui_BFu8ll_Sf");
    static STRUCT_IF_C Ui_BFu8ll_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu8ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu8ll_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu8ll_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8ll_Sf");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8ll_Sf");
    check_field_offset(lv, v3, 5, "Ui_BFu8ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu8ll_Sf, Ui_BFu8ll_Sf)
//============================================================================



static void Test_Ui_BFu8s_Sf()
{
  {
    init_simple_test("Ui_BFu8s_Sf");
    static STRUCT_IF_C Ui_BFu8s_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu8s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu8s_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu8s_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8s_Sf");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8s_Sf");
    check_field_offset(lv, v3, 5, "Ui_BFu8s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu8s_Sf, Ui_BFu8s_Sf)
//============================================================================



static void Test_Ui_BFu9i_Sf()
{
  {
    init_simple_test("Ui_BFu9i_Sf");
    static STRUCT_IF_C Ui_BFu9i_Sf lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu9i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu9i_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu9i_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9i_Sf");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9i_Sf");
    check_field_offset(lv, v3, 6, "Ui_BFu9i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu9i_Sf, Ui_BFu9i_Sf)
//============================================================================



static void Test_Ui_BFu9ll_Sf()
{
  {
    init_simple_test("Ui_BFu9ll_Sf");
    static STRUCT_IF_C Ui_BFu9ll_Sf lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu9ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu9ll_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu9ll_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9ll_Sf");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9ll_Sf");
    check_field_offset(lv, v3, 6, "Ui_BFu9ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu9ll_Sf, Ui_BFu9ll_Sf)
//============================================================================



static void Test_Ui_BFu9s_Sf()
{
  {
    init_simple_test("Ui_BFu9s_Sf");
    static STRUCT_IF_C Ui_BFu9s_Sf lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu9s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu9s_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu9s_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9s_Sf");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9s_Sf");
    check_field_offset(lv, v3, 6, "Ui_BFu9s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu9s_Sf, Ui_BFu9s_Sf)
//============================================================================



static void Test_Ui_C_Sf()
{
  {
    init_simple_test("Ui_C_Sf");
    STRUCT_IF_C Ui_C_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Ui_C_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_C_Sf)");
    check_field_offset(lv, v1, 0, "Ui_C_Sf.v1");
    check_field_offset(lv, v2, 4, "Ui_C_Sf.v2");
    check_field_offset(lv, v3, 5, "Ui_C_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_C_Sf, Ui_C_Sf)
//============================================================================



static void Test_Ui_D_Sf()
{
  {
    init_simple_test("Ui_D_Sf");
    STRUCT_IF_C Ui_D_Sf lv;
    check2(sizeof(lv), 12, "sizeof(Ui_D_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_D_Sf)");
    check_field_offset(lv, v1, 0, "Ui_D_Sf.v1");
    check_field_offset(lv, v2, 4, "Ui_D_Sf.v2");
    check_field_offset(lv, v3, 12, "Ui_D_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_D_Sf, Ui_D_Sf)
//============================================================================



static void Test_Ui_F_Sf()
{
  {
    init_simple_test("Ui_F_Sf");
    STRUCT_IF_C Ui_F_Sf lv;
    check2(sizeof(lv), 8, "sizeof(Ui_F_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_F_Sf)");
    check_field_offset(lv, v1, 0, "Ui_F_Sf.v1");
    check_field_offset(lv, v2, 4, "Ui_F_Sf.v2");
    check_field_offset(lv, v3, 8, "Ui_F_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_F_Sf, Ui_F_Sf)
//============================================================================



static void Test_Ui_I_Sf()
{
  {
    init_simple_test("Ui_I_Sf");
    STRUCT_IF_C Ui_I_Sf lv;
    check2(sizeof(lv), 8, "sizeof(Ui_I_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_I_Sf)");
    check_field_offset(lv, v1, 0, "Ui_I_Sf.v1");
    check_field_offset(lv, v2, 4, "Ui_I_Sf.v2");
    check_field_offset(lv, v3, 8, "Ui_I_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_I_Sf, Ui_I_Sf)
//============================================================================



static void Test_Ui_Ip_Sf()
{
  {
    init_simple_test("Ui_Ip_Sf");
    STRUCT_IF_C Ui_Ip_Sf lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_Ip_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Ip_Sf)");
    check_field_offset(lv, v1, 0, "Ui_Ip_Sf.v1");
    check_field_offset(lv, v2, 4, "Ui_Ip_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Ui_Ip_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Ip_Sf, Ui_Ip_Sf)
//============================================================================



static void Test_Ui_L_Sf()
{
  {
    init_simple_test("Ui_L_Sf");
    STRUCT_IF_C Ui_L_Sf lv;
    check2(sizeof(lv), 12, "sizeof(Ui_L_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_L_Sf)");
    check_field_offset(lv, v1, 0, "Ui_L_Sf.v1");
    check_field_offset(lv, v2, 4, "Ui_L_Sf.v2");
    check_field_offset(lv, v3, 12, "Ui_L_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_L_Sf, Ui_L_Sf)
//============================================================================



static void Test_Ui_S_Sf()
{
  {
    init_simple_test("Ui_S_Sf");
    STRUCT_IF_C Ui_S_Sf lv;
    check2(sizeof(lv), 6, "sizeof(Ui_S_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_S_Sf)");
    check_field_offset(lv, v1, 0, "Ui_S_Sf.v1");
    check_field_offset(lv, v2, 4, "Ui_S_Sf.v2");
    check_field_offset(lv, v3, 6, "Ui_S_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_S_Sf, Ui_S_Sf)
//============================================================================



static void Test_Ui_Sf()
{
  {
    init_simple_test("Ui_Sf");
    STRUCT_IF_C Ui_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Ui_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf)");
    check_field_offset(lv, v1, 0, "Ui_Sf.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf, Ui_Sf)
//============================================================================



static void Test_Ui_Sf_BFu15i()
{
  {
    init_simple_test("Ui_Sf_BFu15i");
    static STRUCT_IF_C Ui_Sf_BFu15i lv;
    check2(sizeof(lv), 6, "sizeof(Ui_Sf_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu15i)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu15i.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu15i.v2");
    set_bf_and_test(lv, v3, 4, 0, 15, 1, "Ui_Sf_BFu15i");
    set_bf_and_test(lv, v3, 4, 0, 15, hide_ull(1LL<<14), "Ui_Sf_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu15i, Ui_Sf_BFu15i)
//============================================================================



static void Test_Ui_Sf_BFu15ll()
{
  {
    init_simple_test("Ui_Sf_BFu15ll");
    static STRUCT_IF_C Ui_Sf_BFu15ll lv;
    check2(sizeof(lv), 6, "sizeof(Ui_Sf_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu15ll)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu15ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu15ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 15, 1, "Ui_Sf_BFu15ll");
    set_bf_and_test(lv, v3, 4, 0, 15, hide_ull(1LL<<14), "Ui_Sf_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu15ll, Ui_Sf_BFu15ll)
//============================================================================



static void Test_Ui_Sf_BFu15s()
{
  {
    init_simple_test("Ui_Sf_BFu15s");
    static STRUCT_IF_C Ui_Sf_BFu15s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_Sf_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu15s)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu15s.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu15s.v2");
    set_bf_and_test(lv, v3, 4, 0, 15, 1, "Ui_Sf_BFu15s");
    set_bf_and_test(lv, v3, 4, 0, 15, hide_ull(1LL<<14), "Ui_Sf_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu15s, Ui_Sf_BFu15s)
//============================================================================



static void Test_Ui_Sf_BFu16i()
{
  {
    init_simple_test("Ui_Sf_BFu16i");
    static STRUCT_IF_C Ui_Sf_BFu16i lv;
    check2(sizeof(lv), 6, "sizeof(Ui_Sf_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu16i)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu16i.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu16i.v2");
    set_bf_and_test(lv, v3, 4, 0, 16, 1, "Ui_Sf_BFu16i");
    set_bf_and_test(lv, v3, 4, 0, 16, hide_ull(1LL<<15), "Ui_Sf_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu16i, Ui_Sf_BFu16i)
//============================================================================



static void Test_Ui_Sf_BFu16ll()
{
  {
    init_simple_test("Ui_Sf_BFu16ll");
    static STRUCT_IF_C Ui_Sf_BFu16ll lv;
    check2(sizeof(lv), 6, "sizeof(Ui_Sf_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu16ll)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu16ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu16ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 16, 1, "Ui_Sf_BFu16ll");
    set_bf_and_test(lv, v3, 4, 0, 16, hide_ull(1LL<<15), "Ui_Sf_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu16ll, Ui_Sf_BFu16ll)
//============================================================================



static void Test_Ui_Sf_BFu16s()
{
  {
    init_simple_test("Ui_Sf_BFu16s");
    static STRUCT_IF_C Ui_Sf_BFu16s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_Sf_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu16s)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu16s.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu16s.v2");
    set_bf_and_test(lv, v3, 4, 0, 16, 1, "Ui_Sf_BFu16s");
    set_bf_and_test(lv, v3, 4, 0, 16, hide_ull(1LL<<15), "Ui_Sf_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu16s, Ui_Sf_BFu16s)
//============================================================================



static void Test_Ui_Sf_BFu17i()
{
  {
    init_simple_test("Ui_Sf_BFu17i");
    static STRUCT_IF_C Ui_Sf_BFu17i lv;
    check2(sizeof(lv), 7, "sizeof(Ui_Sf_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu17i)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu17i.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu17i.v2");
    set_bf_and_test(lv, v3, 4, 0, 17, 1, "Ui_Sf_BFu17i");
    set_bf_and_test(lv, v3, 4, 0, 17, hide_ull(1LL<<16), "Ui_Sf_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu17i, Ui_Sf_BFu17i)
//============================================================================



static void Test_Ui_Sf_BFu17ll()
{
  {
    init_simple_test("Ui_Sf_BFu17ll");
    static STRUCT_IF_C Ui_Sf_BFu17ll lv;
    check2(sizeof(lv), 7, "sizeof(Ui_Sf_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu17ll)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu17ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu17ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 17, 1, "Ui_Sf_BFu17ll");
    set_bf_and_test(lv, v3, 4, 0, 17, hide_ull(1LL<<16), "Ui_Sf_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu17ll, Ui_Sf_BFu17ll)
//============================================================================



static void Test_Ui_Sf_BFu1c()
{
  {
    init_simple_test("Ui_Sf_BFu1c");
    static STRUCT_IF_C Ui_Sf_BFu1c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_Sf_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu1c)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu1c.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu1c.v2");
    set_bf_and_test(lv, v3, 4, 0, 1, 1, "Ui_Sf_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu1c, Ui_Sf_BFu1c)
//============================================================================



static void Test_Ui_Sf_BFu1i()
{
  {
    init_simple_test("Ui_Sf_BFu1i");
    static STRUCT_IF_C Ui_Sf_BFu1i lv;
    check2(sizeof(lv), 5, "sizeof(Ui_Sf_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu1i)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu1i.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu1i.v2");
    set_bf_and_test(lv, v3, 4, 0, 1, 1, "Ui_Sf_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu1i, Ui_Sf_BFu1i)
//============================================================================



static void Test_Ui_Sf_BFu1ll()
{
  {
    init_simple_test("Ui_Sf_BFu1ll");
    static STRUCT_IF_C Ui_Sf_BFu1ll lv;
    check2(sizeof(lv), 5, "sizeof(Ui_Sf_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu1ll)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu1ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu1ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 1, 1, "Ui_Sf_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu1ll, Ui_Sf_BFu1ll)
//============================================================================



static void Test_Ui_Sf_BFu1s()
{
  {
    init_simple_test("Ui_Sf_BFu1s");
    static STRUCT_IF_C Ui_Sf_BFu1s lv;
    check2(sizeof(lv), 5, "sizeof(Ui_Sf_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu1s)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu1s.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu1s.v2");
    set_bf_and_test(lv, v3, 4, 0, 1, 1, "Ui_Sf_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu1s, Ui_Sf_BFu1s)
//============================================================================



static void Test_Ui_Sf_BFu31i()
{
  {
    init_simple_test("Ui_Sf_BFu31i");
    static STRUCT_IF_C Ui_Sf_BFu31i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_Sf_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu31i)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu31i.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu31i.v2");
    set_bf_and_test(lv, v3, 4, 0, 31, 1, "Ui_Sf_BFu31i");
    set_bf_and_test(lv, v3, 4, 0, 31, hide_ull(1LL<<30), "Ui_Sf_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu31i, Ui_Sf_BFu31i)
//============================================================================



static void Test_Ui_Sf_BFu31ll()
{
  {
    init_simple_test("Ui_Sf_BFu31ll");
    static STRUCT_IF_C Ui_Sf_BFu31ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_Sf_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu31ll)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu31ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu31ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 31, 1, "Ui_Sf_BFu31ll");
    set_bf_and_test(lv, v3, 4, 0, 31, hide_ull(1LL<<30), "Ui_Sf_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu31ll, Ui_Sf_BFu31ll)
//============================================================================



static void Test_Ui_Sf_BFu32i()
{
  {
    init_simple_test("Ui_Sf_BFu32i");
    static STRUCT_IF_C Ui_Sf_BFu32i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_Sf_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu32i)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu32i.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu32i.v2");
    set_bf_and_test(lv, v3, 4, 0, 32, 1, "Ui_Sf_BFu32i");
    set_bf_and_test(lv, v3, 4, 0, 32, hide_ull(1LL<<31), "Ui_Sf_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu32i, Ui_Sf_BFu32i)
//============================================================================



static void Test_Ui_Sf_BFu32ll()
{
  {
    init_simple_test("Ui_Sf_BFu32ll");
    static STRUCT_IF_C Ui_Sf_BFu32ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_Sf_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu32ll)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu32ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu32ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 32, 1, "Ui_Sf_BFu32ll");
    set_bf_and_test(lv, v3, 4, 0, 32, hide_ull(1LL<<31), "Ui_Sf_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu32ll, Ui_Sf_BFu32ll)
//============================================================================



static void Test_Ui_Sf_BFu33()
{
  {
    init_simple_test("Ui_Sf_BFu33");
    static STRUCT_IF_C Ui_Sf_BFu33 lv;
    check2(sizeof(lv), 9, "sizeof(Ui_Sf_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu33)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu33.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu33.v2");
    set_bf_and_test(lv, v3, 4, 0, 33, 1, "Ui_Sf_BFu33");
    set_bf_and_test(lv, v3, 4, 0, 33, hide_ull(1LL<<32), "Ui_Sf_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu33, Ui_Sf_BFu33)
//============================================================================



static void Test_Ui_Sf_BFu7c()
{
  {
    init_simple_test("Ui_Sf_BFu7c");
    static STRUCT_IF_C Ui_Sf_BFu7c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_Sf_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu7c)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu7c.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu7c.v2");
    set_bf_and_test(lv, v3, 4, 0, 7, 1, "Ui_Sf_BFu7c");
    set_bf_and_test(lv, v3, 4, 0, 7, hide_ull(1LL<<6), "Ui_Sf_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu7c, Ui_Sf_BFu7c)
//============================================================================



static void Test_Ui_Sf_BFu7i()
{
  {
    init_simple_test("Ui_Sf_BFu7i");
    static STRUCT_IF_C Ui_Sf_BFu7i lv;
    check2(sizeof(lv), 5, "sizeof(Ui_Sf_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu7i)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu7i.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu7i.v2");
    set_bf_and_test(lv, v3, 4, 0, 7, 1, "Ui_Sf_BFu7i");
    set_bf_and_test(lv, v3, 4, 0, 7, hide_ull(1LL<<6), "Ui_Sf_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu7i, Ui_Sf_BFu7i)
//============================================================================



static void Test_Ui_Sf_BFu7ll()
{
  {
    init_simple_test("Ui_Sf_BFu7ll");
    static STRUCT_IF_C Ui_Sf_BFu7ll lv;
    check2(sizeof(lv), 5, "sizeof(Ui_Sf_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu7ll)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu7ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu7ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 7, 1, "Ui_Sf_BFu7ll");
    set_bf_and_test(lv, v3, 4, 0, 7, hide_ull(1LL<<6), "Ui_Sf_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu7ll, Ui_Sf_BFu7ll)
//============================================================================



static void Test_Ui_Sf_BFu7s()
{
  {
    init_simple_test("Ui_Sf_BFu7s");
    static STRUCT_IF_C Ui_Sf_BFu7s lv;
    check2(sizeof(lv), 5, "sizeof(Ui_Sf_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu7s)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu7s.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu7s.v2");
    set_bf_and_test(lv, v3, 4, 0, 7, 1, "Ui_Sf_BFu7s");
    set_bf_and_test(lv, v3, 4, 0, 7, hide_ull(1LL<<6), "Ui_Sf_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu7s, Ui_Sf_BFu7s)
//============================================================================



static void Test_Ui_Sf_BFu8c()
{
  {
    init_simple_test("Ui_Sf_BFu8c");
    static STRUCT_IF_C Ui_Sf_BFu8c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_Sf_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu8c)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu8c.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu8c.v2");
    set_bf_and_test(lv, v3, 4, 0, 8, 1, "Ui_Sf_BFu8c");
    set_bf_and_test(lv, v3, 4, 0, 8, hide_ull(1LL<<7), "Ui_Sf_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu8c, Ui_Sf_BFu8c)
//============================================================================



static void Test_Ui_Sf_BFu8i()
{
  {
    init_simple_test("Ui_Sf_BFu8i");
    static STRUCT_IF_C Ui_Sf_BFu8i lv;
    check2(sizeof(lv), 5, "sizeof(Ui_Sf_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu8i)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu8i.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu8i.v2");
    set_bf_and_test(lv, v3, 4, 0, 8, 1, "Ui_Sf_BFu8i");
    set_bf_and_test(lv, v3, 4, 0, 8, hide_ull(1LL<<7), "Ui_Sf_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu8i, Ui_Sf_BFu8i)
//============================================================================



static void Test_Ui_Sf_BFu8ll()
{
  {
    init_simple_test("Ui_Sf_BFu8ll");
    static STRUCT_IF_C Ui_Sf_BFu8ll lv;
    check2(sizeof(lv), 5, "sizeof(Ui_Sf_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu8ll)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu8ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu8ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 8, 1, "Ui_Sf_BFu8ll");
    set_bf_and_test(lv, v3, 4, 0, 8, hide_ull(1LL<<7), "Ui_Sf_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu8ll, Ui_Sf_BFu8ll)
//============================================================================



static void Test_Ui_Sf_BFu8s()
{
  {
    init_simple_test("Ui_Sf_BFu8s");
    static STRUCT_IF_C Ui_Sf_BFu8s lv;
    check2(sizeof(lv), 5, "sizeof(Ui_Sf_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu8s)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu8s.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu8s.v2");
    set_bf_and_test(lv, v3, 4, 0, 8, 1, "Ui_Sf_BFu8s");
    set_bf_and_test(lv, v3, 4, 0, 8, hide_ull(1LL<<7), "Ui_Sf_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu8s, Ui_Sf_BFu8s)
//============================================================================



static void Test_Ui_Sf_BFu9i()
{
  {
    init_simple_test("Ui_Sf_BFu9i");
    static STRUCT_IF_C Ui_Sf_BFu9i lv;
    check2(sizeof(lv), 6, "sizeof(Ui_Sf_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu9i)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu9i.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu9i.v2");
    set_bf_and_test(lv, v3, 4, 0, 9, 1, "Ui_Sf_BFu9i");
    set_bf_and_test(lv, v3, 4, 0, 9, hide_ull(1LL<<8), "Ui_Sf_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu9i, Ui_Sf_BFu9i)
//============================================================================



static void Test_Ui_Sf_BFu9ll()
{
  {
    init_simple_test("Ui_Sf_BFu9ll");
    static STRUCT_IF_C Ui_Sf_BFu9ll lv;
    check2(sizeof(lv), 6, "sizeof(Ui_Sf_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu9ll)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu9ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu9ll.v2");
    set_bf_and_test(lv, v3, 4, 0, 9, 1, "Ui_Sf_BFu9ll");
    set_bf_and_test(lv, v3, 4, 0, 9, hide_ull(1LL<<8), "Ui_Sf_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu9ll, Ui_Sf_BFu9ll)
//============================================================================



static void Test_Ui_Sf_BFu9s()
{
  {
    init_simple_test("Ui_Sf_BFu9s");
    static STRUCT_IF_C Ui_Sf_BFu9s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_Sf_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_BFu9s)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu9s.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu9s.v2");
    set_bf_and_test(lv, v3, 4, 0, 9, 1, "Ui_Sf_BFu9s");
    set_bf_and_test(lv, v3, 4, 0, 9, hide_ull(1LL<<8), "Ui_Sf_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu9s, Ui_Sf_BFu9s)
//============================================================================



static void Test_Ui_Sf_C()
{
  {
    init_simple_test("Ui_Sf_C");
    STRUCT_IF_C Ui_Sf_C lv;
    check2(sizeof(lv), 5, "sizeof(Ui_Sf_C)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_C)");
    check_field_offset(lv, v1, 0, "Ui_Sf_C.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_C.v2");
    check_field_offset(lv, v3, 4, "Ui_Sf_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_C, Ui_Sf_C)
//============================================================================



static void Test_Ui_Sf_D()
{
  {
    init_simple_test("Ui_Sf_D");
    STRUCT_IF_C Ui_Sf_D lv;
    check2(sizeof(lv), 12, "sizeof(Ui_Sf_D)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_D)");
    check_field_offset(lv, v1, 0, "Ui_Sf_D.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_D.v2");
    check_field_offset(lv, v3, 4, "Ui_Sf_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_D, Ui_Sf_D)
//============================================================================



static void Test_Ui_Sf_F()
{
  {
    init_simple_test("Ui_Sf_F");
    STRUCT_IF_C Ui_Sf_F lv;
    check2(sizeof(lv), 8, "sizeof(Ui_Sf_F)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_F)");
    check_field_offset(lv, v1, 0, "Ui_Sf_F.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_F.v2");
    check_field_offset(lv, v3, 4, "Ui_Sf_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_F, Ui_Sf_F)
//============================================================================



static void Test_Ui_Sf_I()
{
  {
    init_simple_test("Ui_Sf_I");
    STRUCT_IF_C Ui_Sf_I lv;
    check2(sizeof(lv), 8, "sizeof(Ui_Sf_I)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_I)");
    check_field_offset(lv, v1, 0, "Ui_Sf_I.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_I.v2");
    check_field_offset(lv, v3, 4, "Ui_Sf_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_I, Ui_Sf_I)
//============================================================================



static void Test_Ui_Sf_Ip()
{
  {
    init_simple_test("Ui_Sf_Ip");
    STRUCT_IF_C Ui_Sf_Ip lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_Sf_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_Ip)");
    check_field_offset(lv, v1, 0, "Ui_Sf_Ip.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_Ip.v2");
    check_field_offset(lv, v3, 4, "Ui_Sf_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_Ip, Ui_Sf_Ip)
//============================================================================



static void Test_Ui_Sf_L()
{
  {
    init_simple_test("Ui_Sf_L");
    STRUCT_IF_C Ui_Sf_L lv;
    check2(sizeof(lv), 12, "sizeof(Ui_Sf_L)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_L)");
    check_field_offset(lv, v1, 0, "Ui_Sf_L.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_L.v2");
    check_field_offset(lv, v3, 4, "Ui_Sf_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_L, Ui_Sf_L)
//============================================================================



static void Test_Ui_Sf_S()
{
  {
    init_simple_test("Ui_Sf_S");
    STRUCT_IF_C Ui_Sf_S lv;
    check2(sizeof(lv), 6, "sizeof(Ui_Sf_S)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_S)");
    check_field_offset(lv, v1, 0, "Ui_Sf_S.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_S.v2");
    check_field_offset(lv, v3, 4, "Ui_Sf_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_S, Ui_Sf_S)
//============================================================================



static void Test_Ui_Sf_Sf()
{
  {
    init_simple_test("Ui_Sf_Sf");
    STRUCT_IF_C Ui_Sf_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Ui_Sf_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_Sf)");
    check_field_offset(lv, v1, 0, "Ui_Sf_Sf.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_Sf.v2");
    check_field_offset(lv, v3, 4, "Ui_Sf_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_Sf, Ui_Sf_Sf)
//============================================================================



static void Test_Ui_Sf_Uc()
{
  {
    init_simple_test("Ui_Sf_Uc");
    STRUCT_IF_C Ui_Sf_Uc lv;
    check2(sizeof(lv), 5, "sizeof(Ui_Sf_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_Uc)");
    check_field_offset(lv, v1, 0, "Ui_Sf_Uc.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_Uc.v2");
    check_field_offset(lv, v3, 4, "Ui_Sf_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_Uc, Ui_Sf_Uc)
//============================================================================



static void Test_Ui_Sf_Ui()
{
  {
    init_simple_test("Ui_Sf_Ui");
    STRUCT_IF_C Ui_Sf_Ui lv;
    check2(sizeof(lv), 8, "sizeof(Ui_Sf_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_Ui)");
    check_field_offset(lv, v1, 0, "Ui_Sf_Ui.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_Ui.v2");
    check_field_offset(lv, v3, 4, "Ui_Sf_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_Ui, Ui_Sf_Ui)
//============================================================================



static void Test_Ui_Sf_Ul()
{
  {
    init_simple_test("Ui_Sf_Ul");
    STRUCT_IF_C Ui_Sf_Ul lv;
    check2(sizeof(lv), 12, "sizeof(Ui_Sf_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_Ul)");
    check_field_offset(lv, v1, 0, "Ui_Sf_Ul.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_Ul.v2");
    check_field_offset(lv, v3, 4, "Ui_Sf_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_Ul, Ui_Sf_Ul)
//============================================================================



static void Test_Ui_Sf_Us()
{
  {
    init_simple_test("Ui_Sf_Us");
    STRUCT_IF_C Ui_Sf_Us lv;
    check2(sizeof(lv), 6, "sizeof(Ui_Sf_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_Us)");
    check_field_offset(lv, v1, 0, "Ui_Sf_Us.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_Us.v2");
    check_field_offset(lv, v3, 4, "Ui_Sf_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_Us, Ui_Sf_Us)
//============================================================================



static void Test_Ui_Sf_Vp()
{
  {
    init_simple_test("Ui_Sf_Vp");
    STRUCT_IF_C Ui_Sf_Vp lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_Sf_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_Vp)");
    check_field_offset(lv, v1, 0, "Ui_Sf_Vp.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_Vp.v2");
    check_field_offset(lv, v3, 4, "Ui_Sf_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_Vp, Ui_Sf_Vp)
//============================================================================



static void Test_Ui_Uc_Sf()
{
  {
    init_simple_test("Ui_Uc_Sf");
    STRUCT_IF_C Ui_Uc_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Ui_Uc_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Uc_Sf)");
    check_field_offset(lv, v1, 0, "Ui_Uc_Sf.v1");
    check_field_offset(lv, v2, 4, "Ui_Uc_Sf.v2");
    check_field_offset(lv, v3, 5, "Ui_Uc_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Uc_Sf, Ui_Uc_Sf)
//============================================================================



static void Test_Ui_Ui_Sf()
{
  {
    init_simple_test("Ui_Ui_Sf");
    STRUCT_IF_C Ui_Ui_Sf lv;
    check2(sizeof(lv), 8, "sizeof(Ui_Ui_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Ui_Sf)");
    check_field_offset(lv, v1, 0, "Ui_Ui_Sf.v1");
    check_field_offset(lv, v2, 4, "Ui_Ui_Sf.v2");
    check_field_offset(lv, v3, 8, "Ui_Ui_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Ui_Sf, Ui_Ui_Sf)
//============================================================================



static void Test_Ui_Ul_Sf()
{
  {
    init_simple_test("Ui_Ul_Sf");
    STRUCT_IF_C Ui_Ul_Sf lv;
    check2(sizeof(lv), 12, "sizeof(Ui_Ul_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Ul_Sf)");
    check_field_offset(lv, v1, 0, "Ui_Ul_Sf.v1");
    check_field_offset(lv, v2, 4, "Ui_Ul_Sf.v2");
    check_field_offset(lv, v3, 12, "Ui_Ul_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Ul_Sf, Ui_Ul_Sf)
//============================================================================



static void Test_Ui_Us_Sf()
{
  {
    init_simple_test("Ui_Us_Sf");
    STRUCT_IF_C Ui_Us_Sf lv;
    check2(sizeof(lv), 6, "sizeof(Ui_Us_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Us_Sf)");
    check_field_offset(lv, v1, 0, "Ui_Us_Sf.v1");
    check_field_offset(lv, v2, 4, "Ui_Us_Sf.v2");
    check_field_offset(lv, v3, 6, "Ui_Us_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Us_Sf, Ui_Us_Sf)
//============================================================================



static void Test_Ui_Vp_Sf()
{
  {
    init_simple_test("Ui_Vp_Sf");
    STRUCT_IF_C Ui_Vp_Sf lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_Vp_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Vp_Sf)");
    check_field_offset(lv, v1, 0, "Ui_Vp_Sf.v1");
    check_field_offset(lv, v2, 4, "Ui_Vp_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Ui_Vp_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Vp_Sf, Ui_Vp_Sf)
//============================================================================



static void Test_Ul_BFu15i_Sf()
{
  {
    init_simple_test("Ul_BFu15i_Sf");
    static STRUCT_IF_C Ul_BFu15i_Sf lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu15i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu15i_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu15i_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15i_Sf");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15i_Sf");
    check_field_offset(lv, v3, 10, "Ul_BFu15i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu15i_Sf, Ul_BFu15i_Sf)
//============================================================================



static void Test_Ul_BFu15ll_Sf()
{
  {
    init_simple_test("Ul_BFu15ll_Sf");
    static STRUCT_IF_C Ul_BFu15ll_Sf lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu15ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu15ll_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu15ll_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15ll_Sf");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15ll_Sf");
    check_field_offset(lv, v3, 10, "Ul_BFu15ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu15ll_Sf, Ul_BFu15ll_Sf)
//============================================================================



static void Test_Ul_BFu15s_Sf()
{
  {
    init_simple_test("Ul_BFu15s_Sf");
    static STRUCT_IF_C Ul_BFu15s_Sf lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu15s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu15s_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu15s_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15s_Sf");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15s_Sf");
    check_field_offset(lv, v3, 10, "Ul_BFu15s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu15s_Sf, Ul_BFu15s_Sf)
//============================================================================



static void Test_Ul_BFu16i_Sf()
{
  {
    init_simple_test("Ul_BFu16i_Sf");
    static STRUCT_IF_C Ul_BFu16i_Sf lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu16i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu16i_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu16i_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16i_Sf");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16i_Sf");
    check_field_offset(lv, v3, 10, "Ul_BFu16i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu16i_Sf, Ul_BFu16i_Sf)
//============================================================================



static void Test_Ul_BFu16ll_Sf()
{
  {
    init_simple_test("Ul_BFu16ll_Sf");
    static STRUCT_IF_C Ul_BFu16ll_Sf lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu16ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu16ll_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu16ll_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16ll_Sf");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16ll_Sf");
    check_field_offset(lv, v3, 10, "Ul_BFu16ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu16ll_Sf, Ul_BFu16ll_Sf)
//============================================================================



static void Test_Ul_BFu16s_Sf()
{
  {
    init_simple_test("Ul_BFu16s_Sf");
    static STRUCT_IF_C Ul_BFu16s_Sf lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu16s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu16s_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu16s_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16s_Sf");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16s_Sf");
    check_field_offset(lv, v3, 10, "Ul_BFu16s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu16s_Sf, Ul_BFu16s_Sf)
//============================================================================



static void Test_Ul_BFu17i_Sf()
{
  {
    init_simple_test("Ul_BFu17i_Sf");
    static STRUCT_IF_C Ul_BFu17i_Sf lv;
    check2(sizeof(lv), 11, "sizeof(Ul_BFu17i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu17i_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu17i_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu17i_Sf");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu17i_Sf");
    check_field_offset(lv, v3, 11, "Ul_BFu17i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu17i_Sf, Ul_BFu17i_Sf)
//============================================================================



static void Test_Ul_BFu17ll_Sf()
{
  {
    init_simple_test("Ul_BFu17ll_Sf");
    static STRUCT_IF_C Ul_BFu17ll_Sf lv;
    check2(sizeof(lv), 11, "sizeof(Ul_BFu17ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu17ll_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu17ll_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu17ll_Sf");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu17ll_Sf");
    check_field_offset(lv, v3, 11, "Ul_BFu17ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu17ll_Sf, Ul_BFu17ll_Sf)
//============================================================================



static void Test_Ul_BFu1c_Sf()
{
  {
    init_simple_test("Ul_BFu1c_Sf");
    static STRUCT_IF_C Ul_BFu1c_Sf lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu1c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu1c_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu1c_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1c_Sf");
    check_field_offset(lv, v3, 9, "Ul_BFu1c_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu1c_Sf, Ul_BFu1c_Sf)
//============================================================================



static void Test_Ul_BFu1i_Sf()
{
  {
    init_simple_test("Ul_BFu1i_Sf");
    static STRUCT_IF_C Ul_BFu1i_Sf lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu1i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu1i_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu1i_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1i_Sf");
    check_field_offset(lv, v3, 9, "Ul_BFu1i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu1i_Sf, Ul_BFu1i_Sf)
//============================================================================



static void Test_Ul_BFu1ll_Sf()
{
  {
    init_simple_test("Ul_BFu1ll_Sf");
    static STRUCT_IF_C Ul_BFu1ll_Sf lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu1ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu1ll_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu1ll_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1ll_Sf");
    check_field_offset(lv, v3, 9, "Ul_BFu1ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu1ll_Sf, Ul_BFu1ll_Sf)
//============================================================================



static void Test_Ul_BFu1s_Sf()
{
  {
    init_simple_test("Ul_BFu1s_Sf");
    static STRUCT_IF_C Ul_BFu1s_Sf lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu1s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu1s_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu1s_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1s_Sf");
    check_field_offset(lv, v3, 9, "Ul_BFu1s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu1s_Sf, Ul_BFu1s_Sf)
//============================================================================



static void Test_Ul_BFu31i_Sf()
{
  {
    init_simple_test("Ul_BFu31i_Sf");
    static STRUCT_IF_C Ul_BFu31i_Sf lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu31i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu31i_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu31i_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu31i_Sf");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu31i_Sf");
    check_field_offset(lv, v3, 12, "Ul_BFu31i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu31i_Sf, Ul_BFu31i_Sf)
//============================================================================



static void Test_Ul_BFu31ll_Sf()
{
  {
    init_simple_test("Ul_BFu31ll_Sf");
    static STRUCT_IF_C Ul_BFu31ll_Sf lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu31ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu31ll_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu31ll_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu31ll_Sf");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu31ll_Sf");
    check_field_offset(lv, v3, 12, "Ul_BFu31ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu31ll_Sf, Ul_BFu31ll_Sf)
//============================================================================



static void Test_Ul_BFu32i_Sf()
{
  {
    init_simple_test("Ul_BFu32i_Sf");
    static STRUCT_IF_C Ul_BFu32i_Sf lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu32i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu32i_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu32i_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu32i_Sf");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu32i_Sf");
    check_field_offset(lv, v3, 12, "Ul_BFu32i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu32i_Sf, Ul_BFu32i_Sf)
//============================================================================



static void Test_Ul_BFu32ll_Sf()
{
  {
    init_simple_test("Ul_BFu32ll_Sf");
    static STRUCT_IF_C Ul_BFu32ll_Sf lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu32ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu32ll_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu32ll_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu32ll_Sf");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu32ll_Sf");
    check_field_offset(lv, v3, 12, "Ul_BFu32ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu32ll_Sf, Ul_BFu32ll_Sf)
//============================================================================



static void Test_Ul_BFu33_Sf()
{
  {
    init_simple_test("Ul_BFu33_Sf");
    static STRUCT_IF_C Ul_BFu33_Sf lv;
    check2(sizeof(lv), 13, "sizeof(Ul_BFu33_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu33_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu33_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 33, 1, "Ul_BFu33_Sf");
    set_bf_and_test(lv, v2, 8, 0, 33, hide_ull(1LL<<32), "Ul_BFu33_Sf");
    check_field_offset(lv, v3, 13, "Ul_BFu33_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu33_Sf, Ul_BFu33_Sf)
//============================================================================



static void Test_Ul_BFu7c_Sf()
{
  {
    init_simple_test("Ul_BFu7c_Sf");
    static STRUCT_IF_C Ul_BFu7c_Sf lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu7c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu7c_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu7c_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7c_Sf");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7c_Sf");
    check_field_offset(lv, v3, 9, "Ul_BFu7c_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu7c_Sf, Ul_BFu7c_Sf)
//============================================================================



static void Test_Ul_BFu7i_Sf()
{
  {
    init_simple_test("Ul_BFu7i_Sf");
    static STRUCT_IF_C Ul_BFu7i_Sf lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu7i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu7i_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu7i_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7i_Sf");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7i_Sf");
    check_field_offset(lv, v3, 9, "Ul_BFu7i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu7i_Sf, Ul_BFu7i_Sf)
//============================================================================



static void Test_Ul_BFu7ll_Sf()
{
  {
    init_simple_test("Ul_BFu7ll_Sf");
    static STRUCT_IF_C Ul_BFu7ll_Sf lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu7ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu7ll_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu7ll_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7ll_Sf");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7ll_Sf");
    check_field_offset(lv, v3, 9, "Ul_BFu7ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu7ll_Sf, Ul_BFu7ll_Sf)
//============================================================================



static void Test_Ul_BFu7s_Sf()
{
  {
    init_simple_test("Ul_BFu7s_Sf");
    static STRUCT_IF_C Ul_BFu7s_Sf lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu7s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu7s_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu7s_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7s_Sf");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7s_Sf");
    check_field_offset(lv, v3, 9, "Ul_BFu7s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu7s_Sf, Ul_BFu7s_Sf)
//============================================================================



static void Test_Ul_BFu8c_Sf()
{
  {
    init_simple_test("Ul_BFu8c_Sf");
    static STRUCT_IF_C Ul_BFu8c_Sf lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu8c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu8c_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu8c_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8c_Sf");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8c_Sf");
    check_field_offset(lv, v3, 9, "Ul_BFu8c_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu8c_Sf, Ul_BFu8c_Sf)
//============================================================================



static void Test_Ul_BFu8i_Sf()
{
  {
    init_simple_test("Ul_BFu8i_Sf");
    static STRUCT_IF_C Ul_BFu8i_Sf lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu8i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu8i_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu8i_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8i_Sf");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8i_Sf");
    check_field_offset(lv, v3, 9, "Ul_BFu8i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu8i_Sf, Ul_BFu8i_Sf)
//============================================================================



static void Test_Ul_BFu8ll_Sf()
{
  {
    init_simple_test("Ul_BFu8ll_Sf");
    static STRUCT_IF_C Ul_BFu8ll_Sf lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu8ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu8ll_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu8ll_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8ll_Sf");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8ll_Sf");
    check_field_offset(lv, v3, 9, "Ul_BFu8ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu8ll_Sf, Ul_BFu8ll_Sf)
//============================================================================



static void Test_Ul_BFu8s_Sf()
{
  {
    init_simple_test("Ul_BFu8s_Sf");
    static STRUCT_IF_C Ul_BFu8s_Sf lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu8s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu8s_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu8s_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8s_Sf");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8s_Sf");
    check_field_offset(lv, v3, 9, "Ul_BFu8s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu8s_Sf, Ul_BFu8s_Sf)
//============================================================================



static void Test_Ul_BFu9i_Sf()
{
  {
    init_simple_test("Ul_BFu9i_Sf");
    static STRUCT_IF_C Ul_BFu9i_Sf lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu9i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu9i_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu9i_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9i_Sf");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9i_Sf");
    check_field_offset(lv, v3, 10, "Ul_BFu9i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu9i_Sf, Ul_BFu9i_Sf)
//============================================================================



static void Test_Ul_BFu9ll_Sf()
{
  {
    init_simple_test("Ul_BFu9ll_Sf");
    static STRUCT_IF_C Ul_BFu9ll_Sf lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu9ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu9ll_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu9ll_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9ll_Sf");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9ll_Sf");
    check_field_offset(lv, v3, 10, "Ul_BFu9ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu9ll_Sf, Ul_BFu9ll_Sf)
//============================================================================



static void Test_Ul_BFu9s_Sf()
{
  {
    init_simple_test("Ul_BFu9s_Sf");
    static STRUCT_IF_C Ul_BFu9s_Sf lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu9s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu9s_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu9s_Sf.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9s_Sf");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9s_Sf");
    check_field_offset(lv, v3, 10, "Ul_BFu9s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu9s_Sf, Ul_BFu9s_Sf)
//============================================================================



static void Test_Ul_C_Sf()
{
  {
    init_simple_test("Ul_C_Sf");
    STRUCT_IF_C Ul_C_Sf lv;
    check2(sizeof(lv), 9, "sizeof(Ul_C_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_C_Sf)");
    check_field_offset(lv, v1, 0, "Ul_C_Sf.v1");
    check_field_offset(lv, v2, 8, "Ul_C_Sf.v2");
    check_field_offset(lv, v3, 9, "Ul_C_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_C_Sf, Ul_C_Sf)
//============================================================================



static void Test_Ul_D_Sf()
{
  {
    init_simple_test("Ul_D_Sf");
    STRUCT_IF_C Ul_D_Sf lv;
    check2(sizeof(lv), 16, "sizeof(Ul_D_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_D_Sf)");
    check_field_offset(lv, v1, 0, "Ul_D_Sf.v1");
    check_field_offset(lv, v2, 8, "Ul_D_Sf.v2");
    check_field_offset(lv, v3, 16, "Ul_D_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_D_Sf, Ul_D_Sf)
//============================================================================



static void Test_Ul_F_Sf()
{
  {
    init_simple_test("Ul_F_Sf");
    STRUCT_IF_C Ul_F_Sf lv;
    check2(sizeof(lv), 12, "sizeof(Ul_F_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_F_Sf)");
    check_field_offset(lv, v1, 0, "Ul_F_Sf.v1");
    check_field_offset(lv, v2, 8, "Ul_F_Sf.v2");
    check_field_offset(lv, v3, 12, "Ul_F_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_F_Sf, Ul_F_Sf)
//============================================================================



static void Test_Ul_I_Sf()
{
  {
    init_simple_test("Ul_I_Sf");
    STRUCT_IF_C Ul_I_Sf lv;
    check2(sizeof(lv), 12, "sizeof(Ul_I_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_I_Sf)");
    check_field_offset(lv, v1, 0, "Ul_I_Sf.v1");
    check_field_offset(lv, v2, 8, "Ul_I_Sf.v2");
    check_field_offset(lv, v3, 12, "Ul_I_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_I_Sf, Ul_I_Sf)
//============================================================================



static void Test_Ul_Ip_Sf()
{
  {
    init_simple_test("Ul_Ip_Sf");
    STRUCT_IF_C Ul_Ip_Sf lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Ip_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Ip_Sf)");
    check_field_offset(lv, v1, 0, "Ul_Ip_Sf.v1");
    check_field_offset(lv, v2, 8, "Ul_Ip_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Ul_Ip_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Ip_Sf, Ul_Ip_Sf)
//============================================================================



static void Test_Ul_L_Sf()
{
  {
    init_simple_test("Ul_L_Sf");
    STRUCT_IF_C Ul_L_Sf lv;
    check2(sizeof(lv), 16, "sizeof(Ul_L_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_L_Sf)");
    check_field_offset(lv, v1, 0, "Ul_L_Sf.v1");
    check_field_offset(lv, v2, 8, "Ul_L_Sf.v2");
    check_field_offset(lv, v3, 16, "Ul_L_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_L_Sf, Ul_L_Sf)
//============================================================================



static void Test_Ul_S_Sf()
{
  {
    init_simple_test("Ul_S_Sf");
    STRUCT_IF_C Ul_S_Sf lv;
    check2(sizeof(lv), 10, "sizeof(Ul_S_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_S_Sf)");
    check_field_offset(lv, v1, 0, "Ul_S_Sf.v1");
    check_field_offset(lv, v2, 8, "Ul_S_Sf.v2");
    check_field_offset(lv, v3, 10, "Ul_S_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_S_Sf, Ul_S_Sf)
//============================================================================



static void Test_Ul_Sf()
{
  {
    init_simple_test("Ul_Sf");
    STRUCT_IF_C Ul_Sf lv;
    check2(sizeof(lv), 8, "sizeof(Ul_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf)");
    check_field_offset(lv, v1, 0, "Ul_Sf.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf, Ul_Sf)
//============================================================================



static void Test_Ul_Sf_BFu15i()
{
  {
    init_simple_test("Ul_Sf_BFu15i");
    static STRUCT_IF_C Ul_Sf_BFu15i lv;
    check2(sizeof(lv), 10, "sizeof(Ul_Sf_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu15i)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu15i.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu15i.v2");
    set_bf_and_test(lv, v3, 8, 0, 15, 1, "Ul_Sf_BFu15i");
    set_bf_and_test(lv, v3, 8, 0, 15, hide_ull(1LL<<14), "Ul_Sf_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu15i, Ul_Sf_BFu15i)
//============================================================================



static void Test_Ul_Sf_BFu15ll()
{
  {
    init_simple_test("Ul_Sf_BFu15ll");
    static STRUCT_IF_C Ul_Sf_BFu15ll lv;
    check2(sizeof(lv), 10, "sizeof(Ul_Sf_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu15ll)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu15ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu15ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 15, 1, "Ul_Sf_BFu15ll");
    set_bf_and_test(lv, v3, 8, 0, 15, hide_ull(1LL<<14), "Ul_Sf_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu15ll, Ul_Sf_BFu15ll)
//============================================================================



static void Test_Ul_Sf_BFu15s()
{
  {
    init_simple_test("Ul_Sf_BFu15s");
    static STRUCT_IF_C Ul_Sf_BFu15s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_Sf_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu15s)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu15s.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu15s.v2");
    set_bf_and_test(lv, v3, 8, 0, 15, 1, "Ul_Sf_BFu15s");
    set_bf_and_test(lv, v3, 8, 0, 15, hide_ull(1LL<<14), "Ul_Sf_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu15s, Ul_Sf_BFu15s)
//============================================================================



static void Test_Ul_Sf_BFu16i()
{
  {
    init_simple_test("Ul_Sf_BFu16i");
    static STRUCT_IF_C Ul_Sf_BFu16i lv;
    check2(sizeof(lv), 10, "sizeof(Ul_Sf_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu16i)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu16i.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu16i.v2");
    set_bf_and_test(lv, v3, 8, 0, 16, 1, "Ul_Sf_BFu16i");
    set_bf_and_test(lv, v3, 8, 0, 16, hide_ull(1LL<<15), "Ul_Sf_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu16i, Ul_Sf_BFu16i)
//============================================================================



static void Test_Ul_Sf_BFu16ll()
{
  {
    init_simple_test("Ul_Sf_BFu16ll");
    static STRUCT_IF_C Ul_Sf_BFu16ll lv;
    check2(sizeof(lv), 10, "sizeof(Ul_Sf_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu16ll)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu16ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu16ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 16, 1, "Ul_Sf_BFu16ll");
    set_bf_and_test(lv, v3, 8, 0, 16, hide_ull(1LL<<15), "Ul_Sf_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu16ll, Ul_Sf_BFu16ll)
//============================================================================



static void Test_Ul_Sf_BFu16s()
{
  {
    init_simple_test("Ul_Sf_BFu16s");
    static STRUCT_IF_C Ul_Sf_BFu16s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_Sf_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu16s)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu16s.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu16s.v2");
    set_bf_and_test(lv, v3, 8, 0, 16, 1, "Ul_Sf_BFu16s");
    set_bf_and_test(lv, v3, 8, 0, 16, hide_ull(1LL<<15), "Ul_Sf_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu16s, Ul_Sf_BFu16s)
//============================================================================



static void Test_Ul_Sf_BFu17i()
{
  {
    init_simple_test("Ul_Sf_BFu17i");
    static STRUCT_IF_C Ul_Sf_BFu17i lv;
    check2(sizeof(lv), 11, "sizeof(Ul_Sf_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu17i)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu17i.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu17i.v2");
    set_bf_and_test(lv, v3, 8, 0, 17, 1, "Ul_Sf_BFu17i");
    set_bf_and_test(lv, v3, 8, 0, 17, hide_ull(1LL<<16), "Ul_Sf_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu17i, Ul_Sf_BFu17i)
//============================================================================



static void Test_Ul_Sf_BFu17ll()
{
  {
    init_simple_test("Ul_Sf_BFu17ll");
    static STRUCT_IF_C Ul_Sf_BFu17ll lv;
    check2(sizeof(lv), 11, "sizeof(Ul_Sf_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu17ll)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu17ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu17ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 17, 1, "Ul_Sf_BFu17ll");
    set_bf_and_test(lv, v3, 8, 0, 17, hide_ull(1LL<<16), "Ul_Sf_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu17ll, Ul_Sf_BFu17ll)
//============================================================================



static void Test_Ul_Sf_BFu1c()
{
  {
    init_simple_test("Ul_Sf_BFu1c");
    static STRUCT_IF_C Ul_Sf_BFu1c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_Sf_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu1c)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu1c.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu1c.v2");
    set_bf_and_test(lv, v3, 8, 0, 1, 1, "Ul_Sf_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu1c, Ul_Sf_BFu1c)
//============================================================================



static void Test_Ul_Sf_BFu1i()
{
  {
    init_simple_test("Ul_Sf_BFu1i");
    static STRUCT_IF_C Ul_Sf_BFu1i lv;
    check2(sizeof(lv), 9, "sizeof(Ul_Sf_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu1i)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu1i.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu1i.v2");
    set_bf_and_test(lv, v3, 8, 0, 1, 1, "Ul_Sf_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu1i, Ul_Sf_BFu1i)
//============================================================================



static void Test_Ul_Sf_BFu1ll()
{
  {
    init_simple_test("Ul_Sf_BFu1ll");
    static STRUCT_IF_C Ul_Sf_BFu1ll lv;
    check2(sizeof(lv), 9, "sizeof(Ul_Sf_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu1ll)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu1ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu1ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 1, 1, "Ul_Sf_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu1ll, Ul_Sf_BFu1ll)
//============================================================================



static void Test_Ul_Sf_BFu1s()
{
  {
    init_simple_test("Ul_Sf_BFu1s");
    static STRUCT_IF_C Ul_Sf_BFu1s lv;
    check2(sizeof(lv), 9, "sizeof(Ul_Sf_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu1s)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu1s.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu1s.v2");
    set_bf_and_test(lv, v3, 8, 0, 1, 1, "Ul_Sf_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu1s, Ul_Sf_BFu1s)
//============================================================================



static void Test_Ul_Sf_BFu31i()
{
  {
    init_simple_test("Ul_Sf_BFu31i");
    static STRUCT_IF_C Ul_Sf_BFu31i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_Sf_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu31i)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu31i.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu31i.v2");
    set_bf_and_test(lv, v3, 8, 0, 31, 1, "Ul_Sf_BFu31i");
    set_bf_and_test(lv, v3, 8, 0, 31, hide_ull(1LL<<30), "Ul_Sf_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu31i, Ul_Sf_BFu31i)
//============================================================================



static void Test_Ul_Sf_BFu31ll()
{
  {
    init_simple_test("Ul_Sf_BFu31ll");
    static STRUCT_IF_C Ul_Sf_BFu31ll lv;
    check2(sizeof(lv), 12, "sizeof(Ul_Sf_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu31ll)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu31ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu31ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 31, 1, "Ul_Sf_BFu31ll");
    set_bf_and_test(lv, v3, 8, 0, 31, hide_ull(1LL<<30), "Ul_Sf_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu31ll, Ul_Sf_BFu31ll)
//============================================================================



static void Test_Ul_Sf_BFu32i()
{
  {
    init_simple_test("Ul_Sf_BFu32i");
    static STRUCT_IF_C Ul_Sf_BFu32i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_Sf_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu32i)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu32i.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu32i.v2");
    set_bf_and_test(lv, v3, 8, 0, 32, 1, "Ul_Sf_BFu32i");
    set_bf_and_test(lv, v3, 8, 0, 32, hide_ull(1LL<<31), "Ul_Sf_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu32i, Ul_Sf_BFu32i)
//============================================================================



static void Test_Ul_Sf_BFu32ll()
{
  {
    init_simple_test("Ul_Sf_BFu32ll");
    static STRUCT_IF_C Ul_Sf_BFu32ll lv;
    check2(sizeof(lv), 12, "sizeof(Ul_Sf_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu32ll)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu32ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu32ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 32, 1, "Ul_Sf_BFu32ll");
    set_bf_and_test(lv, v3, 8, 0, 32, hide_ull(1LL<<31), "Ul_Sf_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu32ll, Ul_Sf_BFu32ll)
//============================================================================



static void Test_Ul_Sf_BFu33()
{
  {
    init_simple_test("Ul_Sf_BFu33");
    static STRUCT_IF_C Ul_Sf_BFu33 lv;
    check2(sizeof(lv), 13, "sizeof(Ul_Sf_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu33)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu33.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu33.v2");
    set_bf_and_test(lv, v3, 8, 0, 33, 1, "Ul_Sf_BFu33");
    set_bf_and_test(lv, v3, 8, 0, 33, hide_ull(1LL<<32), "Ul_Sf_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu33, Ul_Sf_BFu33)
//============================================================================



static void Test_Ul_Sf_BFu7c()
{
  {
    init_simple_test("Ul_Sf_BFu7c");
    static STRUCT_IF_C Ul_Sf_BFu7c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_Sf_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu7c)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu7c.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu7c.v2");
    set_bf_and_test(lv, v3, 8, 0, 7, 1, "Ul_Sf_BFu7c");
    set_bf_and_test(lv, v3, 8, 0, 7, hide_ull(1LL<<6), "Ul_Sf_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu7c, Ul_Sf_BFu7c)
//============================================================================



static void Test_Ul_Sf_BFu7i()
{
  {
    init_simple_test("Ul_Sf_BFu7i");
    static STRUCT_IF_C Ul_Sf_BFu7i lv;
    check2(sizeof(lv), 9, "sizeof(Ul_Sf_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu7i)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu7i.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu7i.v2");
    set_bf_and_test(lv, v3, 8, 0, 7, 1, "Ul_Sf_BFu7i");
    set_bf_and_test(lv, v3, 8, 0, 7, hide_ull(1LL<<6), "Ul_Sf_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu7i, Ul_Sf_BFu7i)
//============================================================================



static void Test_Ul_Sf_BFu7ll()
{
  {
    init_simple_test("Ul_Sf_BFu7ll");
    static STRUCT_IF_C Ul_Sf_BFu7ll lv;
    check2(sizeof(lv), 9, "sizeof(Ul_Sf_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu7ll)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu7ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu7ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 7, 1, "Ul_Sf_BFu7ll");
    set_bf_and_test(lv, v3, 8, 0, 7, hide_ull(1LL<<6), "Ul_Sf_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu7ll, Ul_Sf_BFu7ll)
//============================================================================



static void Test_Ul_Sf_BFu7s()
{
  {
    init_simple_test("Ul_Sf_BFu7s");
    static STRUCT_IF_C Ul_Sf_BFu7s lv;
    check2(sizeof(lv), 9, "sizeof(Ul_Sf_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu7s)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu7s.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu7s.v2");
    set_bf_and_test(lv, v3, 8, 0, 7, 1, "Ul_Sf_BFu7s");
    set_bf_and_test(lv, v3, 8, 0, 7, hide_ull(1LL<<6), "Ul_Sf_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu7s, Ul_Sf_BFu7s)
//============================================================================



static void Test_Ul_Sf_BFu8c()
{
  {
    init_simple_test("Ul_Sf_BFu8c");
    static STRUCT_IF_C Ul_Sf_BFu8c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_Sf_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu8c)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu8c.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu8c.v2");
    set_bf_and_test(lv, v3, 8, 0, 8, 1, "Ul_Sf_BFu8c");
    set_bf_and_test(lv, v3, 8, 0, 8, hide_ull(1LL<<7), "Ul_Sf_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu8c, Ul_Sf_BFu8c)
//============================================================================



static void Test_Ul_Sf_BFu8i()
{
  {
    init_simple_test("Ul_Sf_BFu8i");
    static STRUCT_IF_C Ul_Sf_BFu8i lv;
    check2(sizeof(lv), 9, "sizeof(Ul_Sf_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu8i)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu8i.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu8i.v2");
    set_bf_and_test(lv, v3, 8, 0, 8, 1, "Ul_Sf_BFu8i");
    set_bf_and_test(lv, v3, 8, 0, 8, hide_ull(1LL<<7), "Ul_Sf_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu8i, Ul_Sf_BFu8i)
//============================================================================



static void Test_Ul_Sf_BFu8ll()
{
  {
    init_simple_test("Ul_Sf_BFu8ll");
    static STRUCT_IF_C Ul_Sf_BFu8ll lv;
    check2(sizeof(lv), 9, "sizeof(Ul_Sf_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu8ll)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu8ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu8ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 8, 1, "Ul_Sf_BFu8ll");
    set_bf_and_test(lv, v3, 8, 0, 8, hide_ull(1LL<<7), "Ul_Sf_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu8ll, Ul_Sf_BFu8ll)
//============================================================================



static void Test_Ul_Sf_BFu8s()
{
  {
    init_simple_test("Ul_Sf_BFu8s");
    static STRUCT_IF_C Ul_Sf_BFu8s lv;
    check2(sizeof(lv), 9, "sizeof(Ul_Sf_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu8s)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu8s.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu8s.v2");
    set_bf_and_test(lv, v3, 8, 0, 8, 1, "Ul_Sf_BFu8s");
    set_bf_and_test(lv, v3, 8, 0, 8, hide_ull(1LL<<7), "Ul_Sf_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu8s, Ul_Sf_BFu8s)
//============================================================================



static void Test_Ul_Sf_BFu9i()
{
  {
    init_simple_test("Ul_Sf_BFu9i");
    static STRUCT_IF_C Ul_Sf_BFu9i lv;
    check2(sizeof(lv), 10, "sizeof(Ul_Sf_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu9i)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu9i.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu9i.v2");
    set_bf_and_test(lv, v3, 8, 0, 9, 1, "Ul_Sf_BFu9i");
    set_bf_and_test(lv, v3, 8, 0, 9, hide_ull(1LL<<8), "Ul_Sf_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu9i, Ul_Sf_BFu9i)
//============================================================================



static void Test_Ul_Sf_BFu9ll()
{
  {
    init_simple_test("Ul_Sf_BFu9ll");
    static STRUCT_IF_C Ul_Sf_BFu9ll lv;
    check2(sizeof(lv), 10, "sizeof(Ul_Sf_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu9ll)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu9ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu9ll.v2");
    set_bf_and_test(lv, v3, 8, 0, 9, 1, "Ul_Sf_BFu9ll");
    set_bf_and_test(lv, v3, 8, 0, 9, hide_ull(1LL<<8), "Ul_Sf_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu9ll, Ul_Sf_BFu9ll)
//============================================================================



static void Test_Ul_Sf_BFu9s()
{
  {
    init_simple_test("Ul_Sf_BFu9s");
    static STRUCT_IF_C Ul_Sf_BFu9s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_Sf_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_BFu9s)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu9s.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu9s.v2");
    set_bf_and_test(lv, v3, 8, 0, 9, 1, "Ul_Sf_BFu9s");
    set_bf_and_test(lv, v3, 8, 0, 9, hide_ull(1LL<<8), "Ul_Sf_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu9s, Ul_Sf_BFu9s)
//============================================================================



static void Test_Ul_Sf_C()
{
  {
    init_simple_test("Ul_Sf_C");
    STRUCT_IF_C Ul_Sf_C lv;
    check2(sizeof(lv), 9, "sizeof(Ul_Sf_C)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_C)");
    check_field_offset(lv, v1, 0, "Ul_Sf_C.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_C.v2");
    check_field_offset(lv, v3, 8, "Ul_Sf_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_C, Ul_Sf_C)
//============================================================================



static void Test_Ul_Sf_D()
{
  {
    init_simple_test("Ul_Sf_D");
    STRUCT_IF_C Ul_Sf_D lv;
    check2(sizeof(lv), 16, "sizeof(Ul_Sf_D)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_D)");
    check_field_offset(lv, v1, 0, "Ul_Sf_D.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_D.v2");
    check_field_offset(lv, v3, 8, "Ul_Sf_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_D, Ul_Sf_D)
//============================================================================



static void Test_Ul_Sf_F()
{
  {
    init_simple_test("Ul_Sf_F");
    STRUCT_IF_C Ul_Sf_F lv;
    check2(sizeof(lv), 12, "sizeof(Ul_Sf_F)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_F)");
    check_field_offset(lv, v1, 0, "Ul_Sf_F.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_F.v2");
    check_field_offset(lv, v3, 8, "Ul_Sf_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_F, Ul_Sf_F)
//============================================================================



static void Test_Ul_Sf_I()
{
  {
    init_simple_test("Ul_Sf_I");
    STRUCT_IF_C Ul_Sf_I lv;
    check2(sizeof(lv), 12, "sizeof(Ul_Sf_I)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_I)");
    check_field_offset(lv, v1, 0, "Ul_Sf_I.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_I.v2");
    check_field_offset(lv, v3, 8, "Ul_Sf_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_I, Ul_Sf_I)
//============================================================================



static void Test_Ul_Sf_Ip()
{
  {
    init_simple_test("Ul_Sf_Ip");
    STRUCT_IF_C Ul_Sf_Ip lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Sf_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_Ip)");
    check_field_offset(lv, v1, 0, "Ul_Sf_Ip.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_Ip.v2");
    check_field_offset(lv, v3, 8, "Ul_Sf_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_Ip, Ul_Sf_Ip)
//============================================================================



static void Test_Ul_Sf_L()
{
  {
    init_simple_test("Ul_Sf_L");
    STRUCT_IF_C Ul_Sf_L lv;
    check2(sizeof(lv), 16, "sizeof(Ul_Sf_L)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_L)");
    check_field_offset(lv, v1, 0, "Ul_Sf_L.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_L.v2");
    check_field_offset(lv, v3, 8, "Ul_Sf_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_L, Ul_Sf_L)
//============================================================================



static void Test_Ul_Sf_S()
{
  {
    init_simple_test("Ul_Sf_S");
    STRUCT_IF_C Ul_Sf_S lv;
    check2(sizeof(lv), 10, "sizeof(Ul_Sf_S)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_S)");
    check_field_offset(lv, v1, 0, "Ul_Sf_S.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_S.v2");
    check_field_offset(lv, v3, 8, "Ul_Sf_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_S, Ul_Sf_S)
//============================================================================



static void Test_Ul_Sf_Sf()
{
  {
    init_simple_test("Ul_Sf_Sf");
    STRUCT_IF_C Ul_Sf_Sf lv;
    check2(sizeof(lv), 8, "sizeof(Ul_Sf_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_Sf)");
    check_field_offset(lv, v1, 0, "Ul_Sf_Sf.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_Sf.v2");
    check_field_offset(lv, v3, 8, "Ul_Sf_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_Sf, Ul_Sf_Sf)
//============================================================================



static void Test_Ul_Sf_Uc()
{
  {
    init_simple_test("Ul_Sf_Uc");
    STRUCT_IF_C Ul_Sf_Uc lv;
    check2(sizeof(lv), 9, "sizeof(Ul_Sf_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_Uc)");
    check_field_offset(lv, v1, 0, "Ul_Sf_Uc.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_Uc.v2");
    check_field_offset(lv, v3, 8, "Ul_Sf_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_Uc, Ul_Sf_Uc)
//============================================================================



static void Test_Ul_Sf_Ui()
{
  {
    init_simple_test("Ul_Sf_Ui");
    STRUCT_IF_C Ul_Sf_Ui lv;
    check2(sizeof(lv), 12, "sizeof(Ul_Sf_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_Ui)");
    check_field_offset(lv, v1, 0, "Ul_Sf_Ui.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_Ui.v2");
    check_field_offset(lv, v3, 8, "Ul_Sf_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_Ui, Ul_Sf_Ui)
//============================================================================



static void Test_Ul_Sf_Ul()
{
  {
    init_simple_test("Ul_Sf_Ul");
    STRUCT_IF_C Ul_Sf_Ul lv;
    check2(sizeof(lv), 16, "sizeof(Ul_Sf_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_Ul)");
    check_field_offset(lv, v1, 0, "Ul_Sf_Ul.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_Ul.v2");
    check_field_offset(lv, v3, 8, "Ul_Sf_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_Ul, Ul_Sf_Ul)
//============================================================================



static void Test_Ul_Sf_Us()
{
  {
    init_simple_test("Ul_Sf_Us");
    STRUCT_IF_C Ul_Sf_Us lv;
    check2(sizeof(lv), 10, "sizeof(Ul_Sf_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_Us)");
    check_field_offset(lv, v1, 0, "Ul_Sf_Us.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_Us.v2");
    check_field_offset(lv, v3, 8, "Ul_Sf_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_Us, Ul_Sf_Us)
//============================================================================



static void Test_Ul_Sf_Vp()
{
  {
    init_simple_test("Ul_Sf_Vp");
    STRUCT_IF_C Ul_Sf_Vp lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Sf_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_Vp)");
    check_field_offset(lv, v1, 0, "Ul_Sf_Vp.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_Vp.v2");
    check_field_offset(lv, v3, 8, "Ul_Sf_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_Vp, Ul_Sf_Vp)
//============================================================================



static void Test_Ul_Uc_Sf()
{
  {
    init_simple_test("Ul_Uc_Sf");
    STRUCT_IF_C Ul_Uc_Sf lv;
    check2(sizeof(lv), 9, "sizeof(Ul_Uc_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Uc_Sf)");
    check_field_offset(lv, v1, 0, "Ul_Uc_Sf.v1");
    check_field_offset(lv, v2, 8, "Ul_Uc_Sf.v2");
    check_field_offset(lv, v3, 9, "Ul_Uc_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Uc_Sf, Ul_Uc_Sf)
//============================================================================



static void Test_Ul_Ui_Sf()
{
  {
    init_simple_test("Ul_Ui_Sf");
    STRUCT_IF_C Ul_Ui_Sf lv;
    check2(sizeof(lv), 12, "sizeof(Ul_Ui_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Ui_Sf)");
    check_field_offset(lv, v1, 0, "Ul_Ui_Sf.v1");
    check_field_offset(lv, v2, 8, "Ul_Ui_Sf.v2");
    check_field_offset(lv, v3, 12, "Ul_Ui_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Ui_Sf, Ul_Ui_Sf)
//============================================================================



static void Test_Ul_Ul_Sf()
{
  {
    init_simple_test("Ul_Ul_Sf");
    STRUCT_IF_C Ul_Ul_Sf lv;
    check2(sizeof(lv), 16, "sizeof(Ul_Ul_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Ul_Sf)");
    check_field_offset(lv, v1, 0, "Ul_Ul_Sf.v1");
    check_field_offset(lv, v2, 8, "Ul_Ul_Sf.v2");
    check_field_offset(lv, v3, 16, "Ul_Ul_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Ul_Sf, Ul_Ul_Sf)
//============================================================================



static void Test_Ul_Us_Sf()
{
  {
    init_simple_test("Ul_Us_Sf");
    STRUCT_IF_C Ul_Us_Sf lv;
    check2(sizeof(lv), 10, "sizeof(Ul_Us_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Us_Sf)");
    check_field_offset(lv, v1, 0, "Ul_Us_Sf.v1");
    check_field_offset(lv, v2, 8, "Ul_Us_Sf.v2");
    check_field_offset(lv, v3, 10, "Ul_Us_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Us_Sf, Ul_Us_Sf)
//============================================================================



static void Test_Ul_Vp_Sf()
{
  {
    init_simple_test("Ul_Vp_Sf");
    STRUCT_IF_C Ul_Vp_Sf lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Vp_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Vp_Sf)");
    check_field_offset(lv, v1, 0, "Ul_Vp_Sf.v1");
    check_field_offset(lv, v2, 8, "Ul_Vp_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Ul_Vp_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Vp_Sf, Ul_Vp_Sf)
//============================================================================



static void Test_Us_BFu15i_Sf()
{
  {
    init_simple_test("Us_BFu15i_Sf");
    static STRUCT_IF_C Us_BFu15i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu15i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu15i_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu15i_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15i_Sf");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15i_Sf");
    check_field_offset(lv, v3, 4, "Us_BFu15i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu15i_Sf, Us_BFu15i_Sf)
//============================================================================



static void Test_Us_BFu15ll_Sf()
{
  {
    init_simple_test("Us_BFu15ll_Sf");
    static STRUCT_IF_C Us_BFu15ll_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu15ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu15ll_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu15ll_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15ll_Sf");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15ll_Sf");
    check_field_offset(lv, v3, 4, "Us_BFu15ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu15ll_Sf, Us_BFu15ll_Sf)
//============================================================================



static void Test_Us_BFu15s_Sf()
{
  {
    init_simple_test("Us_BFu15s_Sf");
    static STRUCT_IF_C Us_BFu15s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu15s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu15s_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu15s_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15s_Sf");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15s_Sf");
    check_field_offset(lv, v3, 4, "Us_BFu15s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu15s_Sf, Us_BFu15s_Sf)
//============================================================================



static void Test_Us_BFu16i_Sf()
{
  {
    init_simple_test("Us_BFu16i_Sf");
    static STRUCT_IF_C Us_BFu16i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu16i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu16i_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu16i_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16i_Sf");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16i_Sf");
    check_field_offset(lv, v3, 4, "Us_BFu16i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu16i_Sf, Us_BFu16i_Sf)
//============================================================================



static void Test_Us_BFu16ll_Sf()
{
  {
    init_simple_test("Us_BFu16ll_Sf");
    static STRUCT_IF_C Us_BFu16ll_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu16ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu16ll_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu16ll_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16ll_Sf");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16ll_Sf");
    check_field_offset(lv, v3, 4, "Us_BFu16ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu16ll_Sf, Us_BFu16ll_Sf)
//============================================================================



static void Test_Us_BFu16s_Sf()
{
  {
    init_simple_test("Us_BFu16s_Sf");
    static STRUCT_IF_C Us_BFu16s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu16s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu16s_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu16s_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16s_Sf");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16s_Sf");
    check_field_offset(lv, v3, 4, "Us_BFu16s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu16s_Sf, Us_BFu16s_Sf)
//============================================================================



static void Test_Us_BFu17i_Sf()
{
  {
    init_simple_test("Us_BFu17i_Sf");
    static STRUCT_IF_C Us_BFu17i_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Us_BFu17i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu17i_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu17i_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu17i_Sf");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu17i_Sf");
    check_field_offset(lv, v3, 5, "Us_BFu17i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu17i_Sf, Us_BFu17i_Sf)
//============================================================================



static void Test_Us_BFu17ll_Sf()
{
  {
    init_simple_test("Us_BFu17ll_Sf");
    static STRUCT_IF_C Us_BFu17ll_Sf lv;
    check2(sizeof(lv), 5, "sizeof(Us_BFu17ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu17ll_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu17ll_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu17ll_Sf");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu17ll_Sf");
    check_field_offset(lv, v3, 5, "Us_BFu17ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu17ll_Sf, Us_BFu17ll_Sf)
//============================================================================



static void Test_Us_BFu1c_Sf()
{
  {
    init_simple_test("Us_BFu1c_Sf");
    static STRUCT_IF_C Us_BFu1c_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu1c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu1c_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu1c_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1c_Sf");
    check_field_offset(lv, v3, 3, "Us_BFu1c_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu1c_Sf, Us_BFu1c_Sf)
//============================================================================



static void Test_Us_BFu1i_Sf()
{
  {
    init_simple_test("Us_BFu1i_Sf");
    static STRUCT_IF_C Us_BFu1i_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu1i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu1i_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu1i_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1i_Sf");
    check_field_offset(lv, v3, 3, "Us_BFu1i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu1i_Sf, Us_BFu1i_Sf)
//============================================================================



static void Test_Us_BFu1ll_Sf()
{
  {
    init_simple_test("Us_BFu1ll_Sf");
    static STRUCT_IF_C Us_BFu1ll_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu1ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu1ll_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu1ll_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1ll_Sf");
    check_field_offset(lv, v3, 3, "Us_BFu1ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu1ll_Sf, Us_BFu1ll_Sf)
//============================================================================



static void Test_Us_BFu1s_Sf()
{
  {
    init_simple_test("Us_BFu1s_Sf");
    static STRUCT_IF_C Us_BFu1s_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu1s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu1s_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu1s_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1s_Sf");
    check_field_offset(lv, v3, 3, "Us_BFu1s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu1s_Sf, Us_BFu1s_Sf)
//============================================================================



static void Test_Us_BFu31i_Sf()
{
  {
    init_simple_test("Us_BFu31i_Sf");
    static STRUCT_IF_C Us_BFu31i_Sf lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu31i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu31i_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu31i_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu31i_Sf");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu31i_Sf");
    check_field_offset(lv, v3, 6, "Us_BFu31i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu31i_Sf, Us_BFu31i_Sf)
//============================================================================



static void Test_Us_BFu31ll_Sf()
{
  {
    init_simple_test("Us_BFu31ll_Sf");
    static STRUCT_IF_C Us_BFu31ll_Sf lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu31ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu31ll_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu31ll_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu31ll_Sf");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu31ll_Sf");
    check_field_offset(lv, v3, 6, "Us_BFu31ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu31ll_Sf, Us_BFu31ll_Sf)
//============================================================================



static void Test_Us_BFu32i_Sf()
{
  {
    init_simple_test("Us_BFu32i_Sf");
    static STRUCT_IF_C Us_BFu32i_Sf lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu32i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu32i_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu32i_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu32i_Sf");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu32i_Sf");
    check_field_offset(lv, v3, 6, "Us_BFu32i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu32i_Sf, Us_BFu32i_Sf)
//============================================================================



static void Test_Us_BFu32ll_Sf()
{
  {
    init_simple_test("Us_BFu32ll_Sf");
    static STRUCT_IF_C Us_BFu32ll_Sf lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu32ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu32ll_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu32ll_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu32ll_Sf");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu32ll_Sf");
    check_field_offset(lv, v3, 6, "Us_BFu32ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu32ll_Sf, Us_BFu32ll_Sf)
//============================================================================



static void Test_Us_BFu33_Sf()
{
  {
    init_simple_test("Us_BFu33_Sf");
    static STRUCT_IF_C Us_BFu33_Sf lv;
    check2(sizeof(lv), 7, "sizeof(Us_BFu33_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu33_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu33_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 33, 1, "Us_BFu33_Sf");
    set_bf_and_test(lv, v2, 2, 0, 33, hide_ull(1LL<<32), "Us_BFu33_Sf");
    check_field_offset(lv, v3, 7, "Us_BFu33_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu33_Sf, Us_BFu33_Sf)
//============================================================================



static void Test_Us_BFu7c_Sf()
{
  {
    init_simple_test("Us_BFu7c_Sf");
    static STRUCT_IF_C Us_BFu7c_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu7c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu7c_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu7c_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7c_Sf");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7c_Sf");
    check_field_offset(lv, v3, 3, "Us_BFu7c_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu7c_Sf, Us_BFu7c_Sf)
//============================================================================



static void Test_Us_BFu7i_Sf()
{
  {
    init_simple_test("Us_BFu7i_Sf");
    static STRUCT_IF_C Us_BFu7i_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu7i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu7i_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu7i_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7i_Sf");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7i_Sf");
    check_field_offset(lv, v3, 3, "Us_BFu7i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu7i_Sf, Us_BFu7i_Sf)
//============================================================================



static void Test_Us_BFu7ll_Sf()
{
  {
    init_simple_test("Us_BFu7ll_Sf");
    static STRUCT_IF_C Us_BFu7ll_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu7ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu7ll_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu7ll_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7ll_Sf");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7ll_Sf");
    check_field_offset(lv, v3, 3, "Us_BFu7ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu7ll_Sf, Us_BFu7ll_Sf)
//============================================================================



static void Test_Us_BFu7s_Sf()
{
  {
    init_simple_test("Us_BFu7s_Sf");
    static STRUCT_IF_C Us_BFu7s_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu7s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu7s_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu7s_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7s_Sf");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7s_Sf");
    check_field_offset(lv, v3, 3, "Us_BFu7s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu7s_Sf, Us_BFu7s_Sf)
//============================================================================



static void Test_Us_BFu8c_Sf()
{
  {
    init_simple_test("Us_BFu8c_Sf");
    static STRUCT_IF_C Us_BFu8c_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu8c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu8c_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu8c_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8c_Sf");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8c_Sf");
    check_field_offset(lv, v3, 3, "Us_BFu8c_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu8c_Sf, Us_BFu8c_Sf)
//============================================================================



static void Test_Us_BFu8i_Sf()
{
  {
    init_simple_test("Us_BFu8i_Sf");
    static STRUCT_IF_C Us_BFu8i_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu8i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu8i_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu8i_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8i_Sf");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8i_Sf");
    check_field_offset(lv, v3, 3, "Us_BFu8i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu8i_Sf, Us_BFu8i_Sf)
//============================================================================



static void Test_Us_BFu8ll_Sf()
{
  {
    init_simple_test("Us_BFu8ll_Sf");
    static STRUCT_IF_C Us_BFu8ll_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu8ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu8ll_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu8ll_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8ll_Sf");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8ll_Sf");
    check_field_offset(lv, v3, 3, "Us_BFu8ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu8ll_Sf, Us_BFu8ll_Sf)
//============================================================================



static void Test_Us_BFu8s_Sf()
{
  {
    init_simple_test("Us_BFu8s_Sf");
    static STRUCT_IF_C Us_BFu8s_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu8s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu8s_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu8s_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8s_Sf");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8s_Sf");
    check_field_offset(lv, v3, 3, "Us_BFu8s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu8s_Sf, Us_BFu8s_Sf)
//============================================================================



static void Test_Us_BFu9i_Sf()
{
  {
    init_simple_test("Us_BFu9i_Sf");
    static STRUCT_IF_C Us_BFu9i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu9i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu9i_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu9i_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9i_Sf");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9i_Sf");
    check_field_offset(lv, v3, 4, "Us_BFu9i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu9i_Sf, Us_BFu9i_Sf)
//============================================================================



static void Test_Us_BFu9ll_Sf()
{
  {
    init_simple_test("Us_BFu9ll_Sf");
    static STRUCT_IF_C Us_BFu9ll_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu9ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu9ll_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu9ll_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9ll_Sf");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9ll_Sf");
    check_field_offset(lv, v3, 4, "Us_BFu9ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu9ll_Sf, Us_BFu9ll_Sf)
//============================================================================



static void Test_Us_BFu9s_Sf()
{
  {
    init_simple_test("Us_BFu9s_Sf");
    static STRUCT_IF_C Us_BFu9s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu9s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu9s_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu9s_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9s_Sf");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9s_Sf");
    check_field_offset(lv, v3, 4, "Us_BFu9s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu9s_Sf, Us_BFu9s_Sf)
//============================================================================



static void Test_Us_C_Sf()
{
  {
    init_simple_test("Us_C_Sf");
    STRUCT_IF_C Us_C_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Us_C_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_C_Sf)");
    check_field_offset(lv, v1, 0, "Us_C_Sf.v1");
    check_field_offset(lv, v2, 2, "Us_C_Sf.v2");
    check_field_offset(lv, v3, 3, "Us_C_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_C_Sf, Us_C_Sf)
//============================================================================



static void Test_Us_D_Sf()
{
  {
    init_simple_test("Us_D_Sf");
    STRUCT_IF_C Us_D_Sf lv;
    check2(sizeof(lv), 10, "sizeof(Us_D_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_D_Sf)");
    check_field_offset(lv, v1, 0, "Us_D_Sf.v1");
    check_field_offset(lv, v2, 2, "Us_D_Sf.v2");
    check_field_offset(lv, v3, 10, "Us_D_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_D_Sf, Us_D_Sf)
//============================================================================



static void Test_Us_F_Sf()
{
  {
    init_simple_test("Us_F_Sf");
    STRUCT_IF_C Us_F_Sf lv;
    check2(sizeof(lv), 6, "sizeof(Us_F_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_F_Sf)");
    check_field_offset(lv, v1, 0, "Us_F_Sf.v1");
    check_field_offset(lv, v2, 2, "Us_F_Sf.v2");
    check_field_offset(lv, v3, 6, "Us_F_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_F_Sf, Us_F_Sf)
//============================================================================



static void Test_Us_I_Sf()
{
  {
    init_simple_test("Us_I_Sf");
    STRUCT_IF_C Us_I_Sf lv;
    check2(sizeof(lv), 6, "sizeof(Us_I_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_I_Sf)");
    check_field_offset(lv, v1, 0, "Us_I_Sf.v1");
    check_field_offset(lv, v2, 2, "Us_I_Sf.v2");
    check_field_offset(lv, v3, 6, "Us_I_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_I_Sf, Us_I_Sf)
//============================================================================



static void Test_Us_Ip_Sf()
{
  {
    init_simple_test("Us_Ip_Sf");
    STRUCT_IF_C Us_Ip_Sf lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_Ip_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Ip_Sf)");
    check_field_offset(lv, v1, 0, "Us_Ip_Sf.v1");
    check_field_offset(lv, v2, 2, "Us_Ip_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Us_Ip_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Ip_Sf, Us_Ip_Sf)
//============================================================================



static void Test_Us_L_Sf()
{
  {
    init_simple_test("Us_L_Sf");
    STRUCT_IF_C Us_L_Sf lv;
    check2(sizeof(lv), 10, "sizeof(Us_L_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_L_Sf)");
    check_field_offset(lv, v1, 0, "Us_L_Sf.v1");
    check_field_offset(lv, v2, 2, "Us_L_Sf.v2");
    check_field_offset(lv, v3, 10, "Us_L_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_L_Sf, Us_L_Sf)
//============================================================================



static void Test_Us_S_Sf()
{
  {
    init_simple_test("Us_S_Sf");
    STRUCT_IF_C Us_S_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Us_S_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_S_Sf)");
    check_field_offset(lv, v1, 0, "Us_S_Sf.v1");
    check_field_offset(lv, v2, 2, "Us_S_Sf.v2");
    check_field_offset(lv, v3, 4, "Us_S_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_S_Sf, Us_S_Sf)
//============================================================================



static void Test_Us_Sf()
{
  {
    init_simple_test("Us_Sf");
    STRUCT_IF_C Us_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Us_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf)");
    check_field_offset(lv, v1, 0, "Us_Sf.v1");
    check_field_offset(lv, v2, 2, "Us_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf, Us_Sf)
//============================================================================



static void Test_Us_Sf_BFu15i()
{
  {
    init_simple_test("Us_Sf_BFu15i");
    static STRUCT_IF_C Us_Sf_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(Us_Sf_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu15i)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu15i.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu15i.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "Us_Sf_BFu15i");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "Us_Sf_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu15i, Us_Sf_BFu15i)
//============================================================================



static void Test_Us_Sf_BFu15ll()
{
  {
    init_simple_test("Us_Sf_BFu15ll");
    static STRUCT_IF_C Us_Sf_BFu15ll lv;
    check2(sizeof(lv), 4, "sizeof(Us_Sf_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu15ll)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu15ll.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu15ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "Us_Sf_BFu15ll");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "Us_Sf_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu15ll, Us_Sf_BFu15ll)
//============================================================================



static void Test_Us_Sf_BFu15s()
{
  {
    init_simple_test("Us_Sf_BFu15s");
    static STRUCT_IF_C Us_Sf_BFu15s lv;
    check2(sizeof(lv), 4, "sizeof(Us_Sf_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu15s)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu15s.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu15s.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "Us_Sf_BFu15s");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "Us_Sf_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu15s, Us_Sf_BFu15s)
//============================================================================



static void Test_Us_Sf_BFu16i()
{
  {
    init_simple_test("Us_Sf_BFu16i");
    static STRUCT_IF_C Us_Sf_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(Us_Sf_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu16i)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu16i.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu16i.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "Us_Sf_BFu16i");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "Us_Sf_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu16i, Us_Sf_BFu16i)
//============================================================================



static void Test_Us_Sf_BFu16ll()
{
  {
    init_simple_test("Us_Sf_BFu16ll");
    static STRUCT_IF_C Us_Sf_BFu16ll lv;
    check2(sizeof(lv), 4, "sizeof(Us_Sf_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu16ll)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu16ll.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu16ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "Us_Sf_BFu16ll");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "Us_Sf_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu16ll, Us_Sf_BFu16ll)
//============================================================================



static void Test_Us_Sf_BFu16s()
{
  {
    init_simple_test("Us_Sf_BFu16s");
    static STRUCT_IF_C Us_Sf_BFu16s lv;
    check2(sizeof(lv), 4, "sizeof(Us_Sf_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu16s)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu16s.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu16s.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "Us_Sf_BFu16s");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "Us_Sf_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu16s, Us_Sf_BFu16s)
//============================================================================



static void Test_Us_Sf_BFu17i()
{
  {
    init_simple_test("Us_Sf_BFu17i");
    static STRUCT_IF_C Us_Sf_BFu17i lv;
    check2(sizeof(lv), 5, "sizeof(Us_Sf_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu17i)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu17i.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu17i.v2");
    set_bf_and_test(lv, v3, 2, 0, 17, 1, "Us_Sf_BFu17i");
    set_bf_and_test(lv, v3, 2, 0, 17, hide_ull(1LL<<16), "Us_Sf_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu17i, Us_Sf_BFu17i)
//============================================================================



static void Test_Us_Sf_BFu17ll()
{
  {
    init_simple_test("Us_Sf_BFu17ll");
    static STRUCT_IF_C Us_Sf_BFu17ll lv;
    check2(sizeof(lv), 5, "sizeof(Us_Sf_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu17ll)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu17ll.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu17ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 17, 1, "Us_Sf_BFu17ll");
    set_bf_and_test(lv, v3, 2, 0, 17, hide_ull(1LL<<16), "Us_Sf_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu17ll, Us_Sf_BFu17ll)
//============================================================================



static void Test_Us_Sf_BFu1c()
{
  {
    init_simple_test("Us_Sf_BFu1c");
    static STRUCT_IF_C Us_Sf_BFu1c lv;
    check2(sizeof(lv), 3, "sizeof(Us_Sf_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu1c)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu1c.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu1c.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Us_Sf_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu1c, Us_Sf_BFu1c)
//============================================================================



static void Test_Us_Sf_BFu1i()
{
  {
    init_simple_test("Us_Sf_BFu1i");
    static STRUCT_IF_C Us_Sf_BFu1i lv;
    check2(sizeof(lv), 3, "sizeof(Us_Sf_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu1i)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu1i.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu1i.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Us_Sf_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu1i, Us_Sf_BFu1i)
//============================================================================



static void Test_Us_Sf_BFu1ll()
{
  {
    init_simple_test("Us_Sf_BFu1ll");
    static STRUCT_IF_C Us_Sf_BFu1ll lv;
    check2(sizeof(lv), 3, "sizeof(Us_Sf_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu1ll)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu1ll.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu1ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Us_Sf_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu1ll, Us_Sf_BFu1ll)
//============================================================================



static void Test_Us_Sf_BFu1s()
{
  {
    init_simple_test("Us_Sf_BFu1s");
    static STRUCT_IF_C Us_Sf_BFu1s lv;
    check2(sizeof(lv), 3, "sizeof(Us_Sf_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu1s)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu1s.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu1s.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Us_Sf_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu1s, Us_Sf_BFu1s)
//============================================================================



static void Test_Us_Sf_BFu31i()
{
  {
    init_simple_test("Us_Sf_BFu31i");
    static STRUCT_IF_C Us_Sf_BFu31i lv;
    check2(sizeof(lv), 6, "sizeof(Us_Sf_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu31i)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu31i.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu31i.v2");
    set_bf_and_test(lv, v3, 2, 0, 31, 1, "Us_Sf_BFu31i");
    set_bf_and_test(lv, v3, 2, 0, 31, hide_ull(1LL<<30), "Us_Sf_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu31i, Us_Sf_BFu31i)
//============================================================================



static void Test_Us_Sf_BFu31ll()
{
  {
    init_simple_test("Us_Sf_BFu31ll");
    static STRUCT_IF_C Us_Sf_BFu31ll lv;
    check2(sizeof(lv), 6, "sizeof(Us_Sf_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu31ll)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu31ll.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu31ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 31, 1, "Us_Sf_BFu31ll");
    set_bf_and_test(lv, v3, 2, 0, 31, hide_ull(1LL<<30), "Us_Sf_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu31ll, Us_Sf_BFu31ll)
//============================================================================



static void Test_Us_Sf_BFu32i()
{
  {
    init_simple_test("Us_Sf_BFu32i");
    static STRUCT_IF_C Us_Sf_BFu32i lv;
    check2(sizeof(lv), 6, "sizeof(Us_Sf_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu32i)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu32i.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu32i.v2");
    set_bf_and_test(lv, v3, 2, 0, 32, 1, "Us_Sf_BFu32i");
    set_bf_and_test(lv, v3, 2, 0, 32, hide_ull(1LL<<31), "Us_Sf_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu32i, Us_Sf_BFu32i)
//============================================================================



static void Test_Us_Sf_BFu32ll()
{
  {
    init_simple_test("Us_Sf_BFu32ll");
    static STRUCT_IF_C Us_Sf_BFu32ll lv;
    check2(sizeof(lv), 6, "sizeof(Us_Sf_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu32ll)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu32ll.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu32ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 32, 1, "Us_Sf_BFu32ll");
    set_bf_and_test(lv, v3, 2, 0, 32, hide_ull(1LL<<31), "Us_Sf_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu32ll, Us_Sf_BFu32ll)
//============================================================================



static void Test_Us_Sf_BFu33()
{
  {
    init_simple_test("Us_Sf_BFu33");
    static STRUCT_IF_C Us_Sf_BFu33 lv;
    check2(sizeof(lv), 7, "sizeof(Us_Sf_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu33)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu33.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu33.v2");
    set_bf_and_test(lv, v3, 2, 0, 33, 1, "Us_Sf_BFu33");
    set_bf_and_test(lv, v3, 2, 0, 33, hide_ull(1LL<<32), "Us_Sf_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu33, Us_Sf_BFu33)
//============================================================================



static void Test_Us_Sf_BFu7c()
{
  {
    init_simple_test("Us_Sf_BFu7c");
    static STRUCT_IF_C Us_Sf_BFu7c lv;
    check2(sizeof(lv), 3, "sizeof(Us_Sf_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu7c)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu7c.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu7c.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Us_Sf_BFu7c");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Us_Sf_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu7c, Us_Sf_BFu7c)
//============================================================================



static void Test_Us_Sf_BFu7i()
{
  {
    init_simple_test("Us_Sf_BFu7i");
    static STRUCT_IF_C Us_Sf_BFu7i lv;
    check2(sizeof(lv), 3, "sizeof(Us_Sf_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu7i)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu7i.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu7i.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Us_Sf_BFu7i");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Us_Sf_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu7i, Us_Sf_BFu7i)
//============================================================================



static void Test_Us_Sf_BFu7ll()
{
  {
    init_simple_test("Us_Sf_BFu7ll");
    static STRUCT_IF_C Us_Sf_BFu7ll lv;
    check2(sizeof(lv), 3, "sizeof(Us_Sf_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu7ll)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu7ll.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu7ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Us_Sf_BFu7ll");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Us_Sf_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu7ll, Us_Sf_BFu7ll)
//============================================================================



static void Test_Us_Sf_BFu7s()
{
  {
    init_simple_test("Us_Sf_BFu7s");
    static STRUCT_IF_C Us_Sf_BFu7s lv;
    check2(sizeof(lv), 3, "sizeof(Us_Sf_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu7s)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu7s.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu7s.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Us_Sf_BFu7s");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Us_Sf_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu7s, Us_Sf_BFu7s)
//============================================================================



static void Test_Us_Sf_BFu8c()
{
  {
    init_simple_test("Us_Sf_BFu8c");
    static STRUCT_IF_C Us_Sf_BFu8c lv;
    check2(sizeof(lv), 3, "sizeof(Us_Sf_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu8c)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu8c.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu8c.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Us_Sf_BFu8c");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Us_Sf_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu8c, Us_Sf_BFu8c)
//============================================================================



static void Test_Us_Sf_BFu8i()
{
  {
    init_simple_test("Us_Sf_BFu8i");
    static STRUCT_IF_C Us_Sf_BFu8i lv;
    check2(sizeof(lv), 3, "sizeof(Us_Sf_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu8i)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu8i.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu8i.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Us_Sf_BFu8i");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Us_Sf_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu8i, Us_Sf_BFu8i)
//============================================================================



static void Test_Us_Sf_BFu8ll()
{
  {
    init_simple_test("Us_Sf_BFu8ll");
    static STRUCT_IF_C Us_Sf_BFu8ll lv;
    check2(sizeof(lv), 3, "sizeof(Us_Sf_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu8ll)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu8ll.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu8ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Us_Sf_BFu8ll");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Us_Sf_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu8ll, Us_Sf_BFu8ll)
//============================================================================



static void Test_Us_Sf_BFu8s()
{
  {
    init_simple_test("Us_Sf_BFu8s");
    static STRUCT_IF_C Us_Sf_BFu8s lv;
    check2(sizeof(lv), 3, "sizeof(Us_Sf_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu8s)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu8s.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu8s.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Us_Sf_BFu8s");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Us_Sf_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu8s, Us_Sf_BFu8s)
//============================================================================



static void Test_Us_Sf_BFu9i()
{
  {
    init_simple_test("Us_Sf_BFu9i");
    static STRUCT_IF_C Us_Sf_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(Us_Sf_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu9i)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu9i.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu9i.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "Us_Sf_BFu9i");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "Us_Sf_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu9i, Us_Sf_BFu9i)
//============================================================================



static void Test_Us_Sf_BFu9ll()
{
  {
    init_simple_test("Us_Sf_BFu9ll");
    static STRUCT_IF_C Us_Sf_BFu9ll lv;
    check2(sizeof(lv), 4, "sizeof(Us_Sf_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu9ll)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu9ll.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu9ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "Us_Sf_BFu9ll");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "Us_Sf_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu9ll, Us_Sf_BFu9ll)
//============================================================================



static void Test_Us_Sf_BFu9s()
{
  {
    init_simple_test("Us_Sf_BFu9s");
    static STRUCT_IF_C Us_Sf_BFu9s lv;
    check2(sizeof(lv), 4, "sizeof(Us_Sf_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_BFu9s)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu9s.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu9s.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "Us_Sf_BFu9s");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "Us_Sf_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu9s, Us_Sf_BFu9s)
//============================================================================



static void Test_Us_Sf_C()
{
  {
    init_simple_test("Us_Sf_C");
    STRUCT_IF_C Us_Sf_C lv;
    check2(sizeof(lv), 3, "sizeof(Us_Sf_C)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_C)");
    check_field_offset(lv, v1, 0, "Us_Sf_C.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_C.v2");
    check_field_offset(lv, v3, 2, "Us_Sf_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_C, Us_Sf_C)
//============================================================================



static void Test_Us_Sf_D()
{
  {
    init_simple_test("Us_Sf_D");
    STRUCT_IF_C Us_Sf_D lv;
    check2(sizeof(lv), 10, "sizeof(Us_Sf_D)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_D)");
    check_field_offset(lv, v1, 0, "Us_Sf_D.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_D.v2");
    check_field_offset(lv, v3, 2, "Us_Sf_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_D, Us_Sf_D)
//============================================================================



static void Test_Us_Sf_F()
{
  {
    init_simple_test("Us_Sf_F");
    STRUCT_IF_C Us_Sf_F lv;
    check2(sizeof(lv), 6, "sizeof(Us_Sf_F)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_F)");
    check_field_offset(lv, v1, 0, "Us_Sf_F.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_F.v2");
    check_field_offset(lv, v3, 2, "Us_Sf_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_F, Us_Sf_F)
//============================================================================



static void Test_Us_Sf_I()
{
  {
    init_simple_test("Us_Sf_I");
    STRUCT_IF_C Us_Sf_I lv;
    check2(sizeof(lv), 6, "sizeof(Us_Sf_I)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_I)");
    check_field_offset(lv, v1, 0, "Us_Sf_I.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_I.v2");
    check_field_offset(lv, v3, 2, "Us_Sf_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_I, Us_Sf_I)
//============================================================================



static void Test_Us_Sf_Ip()
{
  {
    init_simple_test("Us_Sf_Ip");
    STRUCT_IF_C Us_Sf_Ip lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_Sf_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_Ip)");
    check_field_offset(lv, v1, 0, "Us_Sf_Ip.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_Ip.v2");
    check_field_offset(lv, v3, 2, "Us_Sf_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_Ip, Us_Sf_Ip)
//============================================================================



static void Test_Us_Sf_L()
{
  {
    init_simple_test("Us_Sf_L");
    STRUCT_IF_C Us_Sf_L lv;
    check2(sizeof(lv), 10, "sizeof(Us_Sf_L)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_L)");
    check_field_offset(lv, v1, 0, "Us_Sf_L.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_L.v2");
    check_field_offset(lv, v3, 2, "Us_Sf_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_L, Us_Sf_L)
//============================================================================



static void Test_Us_Sf_S()
{
  {
    init_simple_test("Us_Sf_S");
    STRUCT_IF_C Us_Sf_S lv;
    check2(sizeof(lv), 4, "sizeof(Us_Sf_S)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_S)");
    check_field_offset(lv, v1, 0, "Us_Sf_S.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_S.v2");
    check_field_offset(lv, v3, 2, "Us_Sf_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_S, Us_Sf_S)
//============================================================================



static void Test_Us_Sf_Sf()
{
  {
    init_simple_test("Us_Sf_Sf");
    STRUCT_IF_C Us_Sf_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Us_Sf_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_Sf)");
    check_field_offset(lv, v1, 0, "Us_Sf_Sf.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_Sf.v2");
    check_field_offset(lv, v3, 2, "Us_Sf_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_Sf, Us_Sf_Sf)
//============================================================================



static void Test_Us_Sf_Uc()
{
  {
    init_simple_test("Us_Sf_Uc");
    STRUCT_IF_C Us_Sf_Uc lv;
    check2(sizeof(lv), 3, "sizeof(Us_Sf_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_Uc)");
    check_field_offset(lv, v1, 0, "Us_Sf_Uc.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_Uc.v2");
    check_field_offset(lv, v3, 2, "Us_Sf_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_Uc, Us_Sf_Uc)
//============================================================================



static void Test_Us_Sf_Ui()
{
  {
    init_simple_test("Us_Sf_Ui");
    STRUCT_IF_C Us_Sf_Ui lv;
    check2(sizeof(lv), 6, "sizeof(Us_Sf_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_Ui)");
    check_field_offset(lv, v1, 0, "Us_Sf_Ui.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_Ui.v2");
    check_field_offset(lv, v3, 2, "Us_Sf_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_Ui, Us_Sf_Ui)
//============================================================================



static void Test_Us_Sf_Ul()
{
  {
    init_simple_test("Us_Sf_Ul");
    STRUCT_IF_C Us_Sf_Ul lv;
    check2(sizeof(lv), 10, "sizeof(Us_Sf_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_Ul)");
    check_field_offset(lv, v1, 0, "Us_Sf_Ul.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_Ul.v2");
    check_field_offset(lv, v3, 2, "Us_Sf_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_Ul, Us_Sf_Ul)
//============================================================================



static void Test_Us_Sf_Us()
{
  {
    init_simple_test("Us_Sf_Us");
    STRUCT_IF_C Us_Sf_Us lv;
    check2(sizeof(lv), 4, "sizeof(Us_Sf_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_Us)");
    check_field_offset(lv, v1, 0, "Us_Sf_Us.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_Us.v2");
    check_field_offset(lv, v3, 2, "Us_Sf_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_Us, Us_Sf_Us)
//============================================================================



static void Test_Us_Sf_Vp()
{
  {
    init_simple_test("Us_Sf_Vp");
    STRUCT_IF_C Us_Sf_Vp lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_Sf_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_Vp)");
    check_field_offset(lv, v1, 0, "Us_Sf_Vp.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_Vp.v2");
    check_field_offset(lv, v3, 2, "Us_Sf_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_Vp, Us_Sf_Vp)
//============================================================================



static void Test_Us_Uc_Sf()
{
  {
    init_simple_test("Us_Uc_Sf");
    STRUCT_IF_C Us_Uc_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Us_Uc_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Uc_Sf)");
    check_field_offset(lv, v1, 0, "Us_Uc_Sf.v1");
    check_field_offset(lv, v2, 2, "Us_Uc_Sf.v2");
    check_field_offset(lv, v3, 3, "Us_Uc_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Uc_Sf, Us_Uc_Sf)
//============================================================================



static void Test_Us_Ui_Sf()
{
  {
    init_simple_test("Us_Ui_Sf");
    STRUCT_IF_C Us_Ui_Sf lv;
    check2(sizeof(lv), 6, "sizeof(Us_Ui_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Ui_Sf)");
    check_field_offset(lv, v1, 0, "Us_Ui_Sf.v1");
    check_field_offset(lv, v2, 2, "Us_Ui_Sf.v2");
    check_field_offset(lv, v3, 6, "Us_Ui_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Ui_Sf, Us_Ui_Sf)
//============================================================================



static void Test_Us_Ul_Sf()
{
  {
    init_simple_test("Us_Ul_Sf");
    STRUCT_IF_C Us_Ul_Sf lv;
    check2(sizeof(lv), 10, "sizeof(Us_Ul_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Ul_Sf)");
    check_field_offset(lv, v1, 0, "Us_Ul_Sf.v1");
    check_field_offset(lv, v2, 2, "Us_Ul_Sf.v2");
    check_field_offset(lv, v3, 10, "Us_Ul_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Ul_Sf, Us_Ul_Sf)
//============================================================================



static void Test_Us_Us_Sf()
{
  {
    init_simple_test("Us_Us_Sf");
    STRUCT_IF_C Us_Us_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Us_Us_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Us_Sf)");
    check_field_offset(lv, v1, 0, "Us_Us_Sf.v1");
    check_field_offset(lv, v2, 2, "Us_Us_Sf.v2");
    check_field_offset(lv, v3, 4, "Us_Us_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Us_Sf, Us_Us_Sf)
//============================================================================



static void Test_Us_Vp_Sf()
{
  {
    init_simple_test("Us_Vp_Sf");
    STRUCT_IF_C Us_Vp_Sf lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_Vp_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Vp_Sf)");
    check_field_offset(lv, v1, 0, "Us_Vp_Sf.v1");
    check_field_offset(lv, v2, 2, "Us_Vp_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Us_Vp_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Vp_Sf, Us_Vp_Sf)
//============================================================================



static void Test_Vp_BFu15i_Sf()
{
  {
    init_simple_test("Vp_BFu15i_Sf");
    static STRUCT_IF_C Vp_BFu15i_Sf lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu15i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu15i_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu15i_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15i_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15i_Sf");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu15i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu15i_Sf, Vp_BFu15i_Sf)
//============================================================================



static void Test_Vp_BFu15ll_Sf()
{
  {
    init_simple_test("Vp_BFu15ll_Sf");
    static STRUCT_IF_C Vp_BFu15ll_Sf lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu15ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu15ll_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu15ll_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15ll_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15ll_Sf");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu15ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu15ll_Sf, Vp_BFu15ll_Sf)
//============================================================================



static void Test_Vp_BFu15s_Sf()
{
  {
    init_simple_test("Vp_BFu15s_Sf");
    static STRUCT_IF_C Vp_BFu15s_Sf lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu15s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu15s_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu15s_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15s_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15s_Sf");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu15s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu15s_Sf, Vp_BFu15s_Sf)
//============================================================================



static void Test_Vp_BFu16i_Sf()
{
  {
    init_simple_test("Vp_BFu16i_Sf");
    static STRUCT_IF_C Vp_BFu16i_Sf lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu16i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu16i_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu16i_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16i_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16i_Sf");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu16i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu16i_Sf, Vp_BFu16i_Sf)
//============================================================================



static void Test_Vp_BFu16ll_Sf()
{
  {
    init_simple_test("Vp_BFu16ll_Sf");
    static STRUCT_IF_C Vp_BFu16ll_Sf lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu16ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu16ll_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu16ll_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16ll_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16ll_Sf");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu16ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu16ll_Sf, Vp_BFu16ll_Sf)
//============================================================================



static void Test_Vp_BFu16s_Sf()
{
  {
    init_simple_test("Vp_BFu16s_Sf");
    static STRUCT_IF_C Vp_BFu16s_Sf lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu16s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu16s_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu16s_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16s_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16s_Sf");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu16s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu16s_Sf, Vp_BFu16s_Sf)
//============================================================================



static void Test_Vp_BFu17i_Sf()
{
  {
    init_simple_test("Vp_BFu17i_Sf");
    static STRUCT_IF_C Vp_BFu17i_Sf lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu17i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu17i_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu17i_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu17i_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu17i_Sf");
    check_field_offset(lv, v3, ABISELECT(11,7), "Vp_BFu17i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu17i_Sf, Vp_BFu17i_Sf)
//============================================================================



static void Test_Vp_BFu17ll_Sf()
{
  {
    init_simple_test("Vp_BFu17ll_Sf");
    static STRUCT_IF_C Vp_BFu17ll_Sf lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu17ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu17ll_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu17ll_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu17ll_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu17ll_Sf");
    check_field_offset(lv, v3, ABISELECT(11,7), "Vp_BFu17ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu17ll_Sf, Vp_BFu17ll_Sf)
//============================================================================



static void Test_Vp_BFu1c_Sf()
{
  {
    init_simple_test("Vp_BFu1c_Sf");
    static STRUCT_IF_C Vp_BFu1c_Sf lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu1c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu1c_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu1c_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1c_Sf");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu1c_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu1c_Sf, Vp_BFu1c_Sf)
//============================================================================



static void Test_Vp_BFu1i_Sf()
{
  {
    init_simple_test("Vp_BFu1i_Sf");
    static STRUCT_IF_C Vp_BFu1i_Sf lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu1i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu1i_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu1i_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1i_Sf");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu1i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu1i_Sf, Vp_BFu1i_Sf)
//============================================================================



static void Test_Vp_BFu1ll_Sf()
{
  {
    init_simple_test("Vp_BFu1ll_Sf");
    static STRUCT_IF_C Vp_BFu1ll_Sf lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu1ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu1ll_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu1ll_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1ll_Sf");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu1ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu1ll_Sf, Vp_BFu1ll_Sf)
//============================================================================



static void Test_Vp_BFu1s_Sf()
{
  {
    init_simple_test("Vp_BFu1s_Sf");
    static STRUCT_IF_C Vp_BFu1s_Sf lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu1s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu1s_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu1s_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1s_Sf");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu1s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu1s_Sf, Vp_BFu1s_Sf)
//============================================================================



static void Test_Vp_BFu31i_Sf()
{
  {
    init_simple_test("Vp_BFu31i_Sf");
    static STRUCT_IF_C Vp_BFu31i_Sf lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu31i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu31i_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu31i_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu31i_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu31i_Sf");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu31i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu31i_Sf, Vp_BFu31i_Sf)
//============================================================================



static void Test_Vp_BFu31ll_Sf()
{
  {
    init_simple_test("Vp_BFu31ll_Sf");
    static STRUCT_IF_C Vp_BFu31ll_Sf lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu31ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu31ll_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu31ll_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu31ll_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu31ll_Sf");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu31ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu31ll_Sf, Vp_BFu31ll_Sf)
//============================================================================



static void Test_Vp_BFu32i_Sf()
{
  {
    init_simple_test("Vp_BFu32i_Sf");
    static STRUCT_IF_C Vp_BFu32i_Sf lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu32i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu32i_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu32i_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32i_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32i_Sf");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu32i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32i_Sf, Vp_BFu32i_Sf)
//============================================================================



static void Test_Vp_BFu32ll_Sf()
{
  {
    init_simple_test("Vp_BFu32ll_Sf");
    static STRUCT_IF_C Vp_BFu32ll_Sf lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu32ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu32ll_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_Sf");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu32ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_Sf, Vp_BFu32ll_Sf)
//============================================================================



static void Test_Vp_BFu33_Sf()
{
  {
    init_simple_test("Vp_BFu33_Sf");
    static STRUCT_IF_C Vp_BFu33_Sf lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_BFu33_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu33_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_Sf");
    check_field_offset(lv, v3, ABISELECT(13,9), "Vp_BFu33_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_Sf, Vp_BFu33_Sf)
//============================================================================



static void Test_Vp_BFu7c_Sf()
{
  {
    init_simple_test("Vp_BFu7c_Sf");
    static STRUCT_IF_C Vp_BFu7c_Sf lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu7c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu7c_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_Sf");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu7c_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_Sf, Vp_BFu7c_Sf)
//============================================================================



static void Test_Vp_BFu7i_Sf()
{
  {
    init_simple_test("Vp_BFu7i_Sf");
    static STRUCT_IF_C Vp_BFu7i_Sf lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu7i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu7i_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_Sf");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu7i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_Sf, Vp_BFu7i_Sf)
//============================================================================



static void Test_Vp_BFu7ll_Sf()
{
  {
    init_simple_test("Vp_BFu7ll_Sf");
    static STRUCT_IF_C Vp_BFu7ll_Sf lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu7ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu7ll_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_Sf");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu7ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_Sf, Vp_BFu7ll_Sf)
//============================================================================



static void Test_Vp_BFu7s_Sf()
{
  {
    init_simple_test("Vp_BFu7s_Sf");
    static STRUCT_IF_C Vp_BFu7s_Sf lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu7s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu7s_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_Sf");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu7s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_Sf, Vp_BFu7s_Sf)
//============================================================================



static void Test_Vp_BFu8c_Sf()
{
  {
    init_simple_test("Vp_BFu8c_Sf");
    static STRUCT_IF_C Vp_BFu8c_Sf lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu8c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu8c_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_Sf");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu8c_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_Sf, Vp_BFu8c_Sf)
//============================================================================



static void Test_Vp_BFu8i_Sf()
{
  {
    init_simple_test("Vp_BFu8i_Sf");
    static STRUCT_IF_C Vp_BFu8i_Sf lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu8i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu8i_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_Sf");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu8i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_Sf, Vp_BFu8i_Sf)
//============================================================================



static void Test_Vp_BFu8ll_Sf()
{
  {
    init_simple_test("Vp_BFu8ll_Sf");
    static STRUCT_IF_C Vp_BFu8ll_Sf lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu8ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu8ll_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_Sf");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu8ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_Sf, Vp_BFu8ll_Sf)
//============================================================================



static void Test_Vp_BFu8s_Sf()
{
  {
    init_simple_test("Vp_BFu8s_Sf");
    static STRUCT_IF_C Vp_BFu8s_Sf lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu8s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu8s_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_Sf");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu8s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_Sf, Vp_BFu8s_Sf)
//============================================================================



static void Test_Vp_BFu9i_Sf()
{
  {
    init_simple_test("Vp_BFu9i_Sf");
    static STRUCT_IF_C Vp_BFu9i_Sf lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu9i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu9i_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_Sf");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu9i_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_Sf, Vp_BFu9i_Sf)
//============================================================================



static void Test_Vp_BFu9ll_Sf()
{
  {
    init_simple_test("Vp_BFu9ll_Sf");
    static STRUCT_IF_C Vp_BFu9ll_Sf lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu9ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu9ll_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_Sf");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu9ll_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_Sf, Vp_BFu9ll_Sf)
//============================================================================



static void Test_Vp_BFu9s_Sf()
{
  {
    init_simple_test("Vp_BFu9s_Sf");
    static STRUCT_IF_C Vp_BFu9s_Sf lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu9s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu9s_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_Sf.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_Sf");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_Sf");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu9s_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_Sf, Vp_BFu9s_Sf)
//============================================================================



static void Test_Vp_C_Sf()
{
  {
    init_simple_test("Vp_C_Sf");
    STRUCT_IF_C Vp_C_Sf lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_C_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_C_Sf)");
    check_field_offset(lv, v1, 0, "Vp_C_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_C_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_Sf, Vp_C_Sf)
//============================================================================



static void Test_Vp_D_Sf()
{
  {
    init_simple_test("Vp_D_Sf");
    STRUCT_IF_C Vp_D_Sf lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_D_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_D_Sf)");
    check_field_offset(lv, v1, 0, "Vp_D_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_D_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_Sf, Vp_D_Sf)
//============================================================================



static void Test_Vp_F_Sf()
{
  {
    init_simple_test("Vp_F_Sf");
    STRUCT_IF_C Vp_F_Sf lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_F_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_F_Sf)");
    check_field_offset(lv, v1, 0, "Vp_F_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_F_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_Sf, Vp_F_Sf)
//============================================================================



static void Test_Vp_I_Sf()
{
  {
    init_simple_test("Vp_I_Sf");
    STRUCT_IF_C Vp_I_Sf lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_I_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_I_Sf)");
    check_field_offset(lv, v1, 0, "Vp_I_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_I_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_Sf, Vp_I_Sf)
//============================================================================



static void Test_Vp_Ip_Sf()
{
  {
    init_simple_test("Vp_Ip_Sf");
    STRUCT_IF_C Vp_Ip_Sf lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Ip_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Ip_Sf)");
    check_field_offset(lv, v1, 0, "Vp_Ip_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Ip_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_Sf, Vp_Ip_Sf)
//============================================================================



static void Test_Vp_L_Sf()
{
  {
    init_simple_test("Vp_L_Sf");
    STRUCT_IF_C Vp_L_Sf lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_L_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_L_Sf)");
    check_field_offset(lv, v1, 0, "Vp_L_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_L_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_Sf, Vp_L_Sf)
//============================================================================



static void Test_Vp_S_Sf()
{
  {
    init_simple_test("Vp_S_Sf");
    STRUCT_IF_C Vp_S_Sf lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_S_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_S_Sf)");
    check_field_offset(lv, v1, 0, "Vp_S_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_S_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_Sf, Vp_S_Sf)
//============================================================================



static void Test_Vp_Sf()
{
  {
    init_simple_test("Vp_Sf");
    STRUCT_IF_C Vp_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf)");
    check_field_offset(lv, v1, 0, "Vp_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf, Vp_Sf)
//============================================================================



static void Test_Vp_Sf_BFu15i()
{
  {
    init_simple_test("Vp_Sf_BFu15i");
    static STRUCT_IF_C Vp_Sf_BFu15i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_Sf_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu15i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu15i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 15, 1, "Vp_Sf_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_Sf_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu15i, Vp_Sf_BFu15i)
//============================================================================



static void Test_Vp_Sf_BFu15ll()
{
  {
    init_simple_test("Vp_Sf_BFu15ll");
    static STRUCT_IF_C Vp_Sf_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_Sf_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu15ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu15ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 15, 1, "Vp_Sf_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_Sf_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu15ll, Vp_Sf_BFu15ll)
//============================================================================



static void Test_Vp_Sf_BFu15s()
{
  {
    init_simple_test("Vp_Sf_BFu15s");
    static STRUCT_IF_C Vp_Sf_BFu15s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_Sf_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu15s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu15s.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 15, 1, "Vp_Sf_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_Sf_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu15s, Vp_Sf_BFu15s)
//============================================================================



static void Test_Vp_Sf_BFu16i()
{
  {
    init_simple_test("Vp_Sf_BFu16i");
    static STRUCT_IF_C Vp_Sf_BFu16i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_Sf_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu16i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu16i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 16, 1, "Vp_Sf_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_Sf_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu16i, Vp_Sf_BFu16i)
//============================================================================



static void Test_Vp_Sf_BFu16ll()
{
  {
    init_simple_test("Vp_Sf_BFu16ll");
    static STRUCT_IF_C Vp_Sf_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_Sf_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu16ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu16ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 16, 1, "Vp_Sf_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_Sf_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu16ll, Vp_Sf_BFu16ll)
//============================================================================



static void Test_Vp_Sf_BFu16s()
{
  {
    init_simple_test("Vp_Sf_BFu16s");
    static STRUCT_IF_C Vp_Sf_BFu16s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_Sf_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu16s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu16s.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 16, 1, "Vp_Sf_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_Sf_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu16s, Vp_Sf_BFu16s)
//============================================================================



static void Test_Vp_Sf_BFu17i()
{
  {
    init_simple_test("Vp_Sf_BFu17i");
    static STRUCT_IF_C Vp_Sf_BFu17i lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_Sf_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu17i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu17i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 17, 1, "Vp_Sf_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_Sf_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu17i, Vp_Sf_BFu17i)
//============================================================================



static void Test_Vp_Sf_BFu17ll()
{
  {
    init_simple_test("Vp_Sf_BFu17ll");
    static STRUCT_IF_C Vp_Sf_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_Sf_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu17ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu17ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 17, 1, "Vp_Sf_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_Sf_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu17ll, Vp_Sf_BFu17ll)
//============================================================================



static void Test_Vp_Sf_BFu1c()
{
  {
    init_simple_test("Vp_Sf_BFu1c");
    static STRUCT_IF_C Vp_Sf_BFu1c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_Sf_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu1c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu1c.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 1, 1, "Vp_Sf_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu1c, Vp_Sf_BFu1c)
//============================================================================



static void Test_Vp_Sf_BFu1i()
{
  {
    init_simple_test("Vp_Sf_BFu1i");
    static STRUCT_IF_C Vp_Sf_BFu1i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_Sf_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu1i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu1i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 1, 1, "Vp_Sf_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu1i, Vp_Sf_BFu1i)
//============================================================================



static void Test_Vp_Sf_BFu1ll()
{
  {
    init_simple_test("Vp_Sf_BFu1ll");
    static STRUCT_IF_C Vp_Sf_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_Sf_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu1ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu1ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 1, 1, "Vp_Sf_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu1ll, Vp_Sf_BFu1ll)
//============================================================================



static void Test_Vp_Sf_BFu1s()
{
  {
    init_simple_test("Vp_Sf_BFu1s");
    static STRUCT_IF_C Vp_Sf_BFu1s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_Sf_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu1s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu1s.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 1, 1, "Vp_Sf_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu1s, Vp_Sf_BFu1s)
//============================================================================



static void Test_Vp_Sf_BFu31i()
{
  {
    init_simple_test("Vp_Sf_BFu31i");
    static STRUCT_IF_C Vp_Sf_BFu31i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_Sf_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu31i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu31i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 31, 1, "Vp_Sf_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_Sf_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu31i, Vp_Sf_BFu31i)
//============================================================================



static void Test_Vp_Sf_BFu31ll()
{
  {
    init_simple_test("Vp_Sf_BFu31ll");
    static STRUCT_IF_C Vp_Sf_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_Sf_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu31ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu31ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 31, 1, "Vp_Sf_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_Sf_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu31ll, Vp_Sf_BFu31ll)
//============================================================================



static void Test_Vp_Sf_BFu32i()
{
  {
    init_simple_test("Vp_Sf_BFu32i");
    static STRUCT_IF_C Vp_Sf_BFu32i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_Sf_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu32i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu32i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 32, 1, "Vp_Sf_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_Sf_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu32i, Vp_Sf_BFu32i)
//============================================================================



static void Test_Vp_Sf_BFu32ll()
{
  {
    init_simple_test("Vp_Sf_BFu32ll");
    static STRUCT_IF_C Vp_Sf_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_Sf_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu32ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu32ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 32, 1, "Vp_Sf_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_Sf_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu32ll, Vp_Sf_BFu32ll)
//============================================================================



static void Test_Vp_Sf_BFu33()
{
  {
    init_simple_test("Vp_Sf_BFu33");
    static STRUCT_IF_C Vp_Sf_BFu33 lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_Sf_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu33.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu33.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 33, 1, "Vp_Sf_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_Sf_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu33, Vp_Sf_BFu33)
//============================================================================



static void Test_Vp_Sf_BFu7c()
{
  {
    init_simple_test("Vp_Sf_BFu7c");
    static STRUCT_IF_C Vp_Sf_BFu7c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_Sf_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu7c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu7c.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, 1, "Vp_Sf_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_Sf_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu7c, Vp_Sf_BFu7c)
//============================================================================



static void Test_Vp_Sf_BFu7i()
{
  {
    init_simple_test("Vp_Sf_BFu7i");
    static STRUCT_IF_C Vp_Sf_BFu7i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_Sf_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu7i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu7i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, 1, "Vp_Sf_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_Sf_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu7i, Vp_Sf_BFu7i)
//============================================================================



static void Test_Vp_Sf_BFu7ll()
{
  {
    init_simple_test("Vp_Sf_BFu7ll");
    static STRUCT_IF_C Vp_Sf_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_Sf_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu7ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu7ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, 1, "Vp_Sf_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_Sf_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu7ll, Vp_Sf_BFu7ll)
//============================================================================



static void Test_Vp_Sf_BFu7s()
{
  {
    init_simple_test("Vp_Sf_BFu7s");
    static STRUCT_IF_C Vp_Sf_BFu7s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_Sf_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu7s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu7s.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, 1, "Vp_Sf_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_Sf_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu7s, Vp_Sf_BFu7s)
//============================================================================



static void Test_Vp_Sf_BFu8c()
{
  {
    init_simple_test("Vp_Sf_BFu8c");
    static STRUCT_IF_C Vp_Sf_BFu8c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_Sf_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu8c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu8c.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, 1, "Vp_Sf_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_Sf_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu8c, Vp_Sf_BFu8c)
//============================================================================



static void Test_Vp_Sf_BFu8i()
{
  {
    init_simple_test("Vp_Sf_BFu8i");
    static STRUCT_IF_C Vp_Sf_BFu8i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_Sf_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu8i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu8i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, 1, "Vp_Sf_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_Sf_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu8i, Vp_Sf_BFu8i)
//============================================================================



static void Test_Vp_Sf_BFu8ll()
{
  {
    init_simple_test("Vp_Sf_BFu8ll");
    static STRUCT_IF_C Vp_Sf_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_Sf_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu8ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu8ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, 1, "Vp_Sf_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_Sf_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu8ll, Vp_Sf_BFu8ll)
//============================================================================



static void Test_Vp_Sf_BFu8s()
{
  {
    init_simple_test("Vp_Sf_BFu8s");
    static STRUCT_IF_C Vp_Sf_BFu8s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_Sf_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu8s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu8s.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, 1, "Vp_Sf_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_Sf_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu8s, Vp_Sf_BFu8s)
//============================================================================



static void Test_Vp_Sf_BFu9i()
{
  {
    init_simple_test("Vp_Sf_BFu9i");
    static STRUCT_IF_C Vp_Sf_BFu9i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_Sf_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu9i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu9i.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 9, 1, "Vp_Sf_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_Sf_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu9i, Vp_Sf_BFu9i)
//============================================================================



static void Test_Vp_Sf_BFu9ll()
{
  {
    init_simple_test("Vp_Sf_BFu9ll");
    static STRUCT_IF_C Vp_Sf_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_Sf_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu9ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu9ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 9, 1, "Vp_Sf_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_Sf_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu9ll, Vp_Sf_BFu9ll)
//============================================================================



static void Test_Vp_Sf_BFu9s()
{
  {
    init_simple_test("Vp_Sf_BFu9s");
    static STRUCT_IF_C Vp_Sf_BFu9s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_Sf_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu9s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu9s.v2");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 9, 1, "Vp_Sf_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_Sf_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu9s, Vp_Sf_BFu9s)
//============================================================================



static void Test_Vp_Sf_C()
{
  {
    init_simple_test("Vp_Sf_C");
    STRUCT_IF_C Vp_Sf_C lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_Sf_C)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_C)");
    check_field_offset(lv, v1, 0, "Vp_Sf_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_C.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Vp_Sf_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_C, Vp_Sf_C)
//============================================================================



static void Test_Vp_Sf_D()
{
  {
    init_simple_test("Vp_Sf_D");
    STRUCT_IF_C Vp_Sf_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Sf_D)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_D)");
    check_field_offset(lv, v1, 0, "Vp_Sf_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_D.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Vp_Sf_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_D, Vp_Sf_D)
//============================================================================



static void Test_Vp_Sf_F()
{
  {
    init_simple_test("Vp_Sf_F");
    STRUCT_IF_C Vp_Sf_F lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_Sf_F)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_F)");
    check_field_offset(lv, v1, 0, "Vp_Sf_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_F.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Vp_Sf_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_F, Vp_Sf_F)
//============================================================================



static void Test_Vp_Sf_I()
{
  {
    init_simple_test("Vp_Sf_I");
    STRUCT_IF_C Vp_Sf_I lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_Sf_I)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_I)");
    check_field_offset(lv, v1, 0, "Vp_Sf_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_I.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Vp_Sf_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_I, Vp_Sf_I)
//============================================================================



static void Test_Vp_Sf_Ip()
{
  {
    init_simple_test("Vp_Sf_Ip");
    STRUCT_IF_C Vp_Sf_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Sf_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_Ip)");
    check_field_offset(lv, v1, 0, "Vp_Sf_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_Ip.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Vp_Sf_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_Ip, Vp_Sf_Ip)
//============================================================================



static void Test_Vp_Sf_L()
{
  {
    init_simple_test("Vp_Sf_L");
    STRUCT_IF_C Vp_Sf_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Sf_L)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_L)");
    check_field_offset(lv, v1, 0, "Vp_Sf_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_L.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Vp_Sf_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_L, Vp_Sf_L)
//============================================================================



static void Test_Vp_Sf_S()
{
  {
    init_simple_test("Vp_Sf_S");
    STRUCT_IF_C Vp_Sf_S lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_Sf_S)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_S)");
    check_field_offset(lv, v1, 0, "Vp_Sf_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_S.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Vp_Sf_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_S, Vp_Sf_S)
//============================================================================



static void Test_Vp_Sf_Sf()
{
  {
    init_simple_test("Vp_Sf_Sf");
    STRUCT_IF_C Vp_Sf_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_Sf_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_Sf)");
    check_field_offset(lv, v1, 0, "Vp_Sf_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Vp_Sf_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_Sf, Vp_Sf_Sf)
//============================================================================



static void Test_Vp_Sf_Uc()
{
  {
    init_simple_test("Vp_Sf_Uc");
    STRUCT_IF_C Vp_Sf_Uc lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_Sf_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_Uc)");
    check_field_offset(lv, v1, 0, "Vp_Sf_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_Uc.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Vp_Sf_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_Uc, Vp_Sf_Uc)
//============================================================================



static void Test_Vp_Sf_Ui()
{
  {
    init_simple_test("Vp_Sf_Ui");
    STRUCT_IF_C Vp_Sf_Ui lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_Sf_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_Ui)");
    check_field_offset(lv, v1, 0, "Vp_Sf_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_Ui.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Vp_Sf_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_Ui, Vp_Sf_Ui)
//============================================================================



static void Test_Vp_Sf_Ul()
{
  {
    init_simple_test("Vp_Sf_Ul");
    STRUCT_IF_C Vp_Sf_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Sf_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_Ul)");
    check_field_offset(lv, v1, 0, "Vp_Sf_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_Ul.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Vp_Sf_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_Ul, Vp_Sf_Ul)
//============================================================================



static void Test_Vp_Sf_Us()
{
  {
    init_simple_test("Vp_Sf_Us");
    STRUCT_IF_C Vp_Sf_Us lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_Sf_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_Us)");
    check_field_offset(lv, v1, 0, "Vp_Sf_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_Us.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Vp_Sf_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_Us, Vp_Sf_Us)
//============================================================================



static void Test_Vp_Sf_Vp()
{
  {
    init_simple_test("Vp_Sf_Vp");
    STRUCT_IF_C Vp_Sf_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Sf_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_Vp)");
    check_field_offset(lv, v1, 0, "Vp_Sf_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_Vp.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Vp_Sf_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_Vp, Vp_Sf_Vp)
//============================================================================



static void Test_Vp_Uc_Sf()
{
  {
    init_simple_test("Vp_Uc_Sf");
    STRUCT_IF_C Vp_Uc_Sf lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_Uc_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Uc_Sf)");
    check_field_offset(lv, v1, 0, "Vp_Uc_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_Uc_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_Sf, Vp_Uc_Sf)
//============================================================================



static void Test_Vp_Ui_Sf()
{
  {
    init_simple_test("Vp_Ui_Sf");
    STRUCT_IF_C Vp_Ui_Sf lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_Ui_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Ui_Sf)");
    check_field_offset(lv, v1, 0, "Vp_Ui_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_Ui_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_Sf, Vp_Ui_Sf)
//============================================================================



static void Test_Vp_Ul_Sf()
{
  {
    init_simple_test("Vp_Ul_Sf");
    STRUCT_IF_C Vp_Ul_Sf lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ul_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Ul_Sf)");
    check_field_offset(lv, v1, 0, "Vp_Ul_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_Ul_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_Sf, Vp_Ul_Sf)
//============================================================================



static void Test_Vp_Us_Sf()
{
  {
    init_simple_test("Vp_Us_Sf");
    STRUCT_IF_C Vp_Us_Sf lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_Us_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Us_Sf)");
    check_field_offset(lv, v1, 0, "Vp_Us_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_Us_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_Sf, Vp_Us_Sf)
//============================================================================



static void Test_Vp_Vp_Sf()
{
  {
    init_simple_test("Vp_Vp_Sf");
    STRUCT_IF_C Vp_Vp_Sf lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Vp_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Vp_Sf)");
    check_field_offset(lv, v1, 0, "Vp_Vp_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Vp_Sf.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_Sf, Vp_Vp_Sf)
//============================================================================

