// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
// RUN: c_compiler -c -o %t1.o -I "common" "common/testsuite.c"
// RUN: cxx_compiler cxx_rtti -c %s -I "common" -o %t2.o
// RUN: linker -o %t2%exeext  %t1.o %t2.o
// RUN: runtool %t2%exeext | checker "TEST PASSED"
#include "testsuite.h"
#ifdef __cplusplus
typedef struct empty {} empty;
struct __attribute__((packed)) aB_B_Sf { bool v1; bool v2; empty v3; };
struct __attribute__((packed)) aB_BFu15i_Sf { bool v1; unsigned int v2:15; empty v3; };
struct __attribute__((packed)) aB_BFu15ll_Sf { bool v1; unsigned long long v2:15; empty v3; };
struct __attribute__((packed)) aB_BFu15s_Sf { bool v1; unsigned short v2:15; empty v3; };
struct __attribute__((packed)) aB_BFu16i_Sf { bool v1; unsigned int v2:16; empty v3; };
struct __attribute__((packed)) aB_BFu16ll_Sf { bool v1; unsigned long long v2:16; empty v3; };
struct __attribute__((packed)) aB_BFu16s_Sf { bool v1; unsigned short v2:16; empty v3; };
struct __attribute__((packed)) aB_BFu17i_Sf { bool v1; unsigned int v2:17; empty v3; };
struct __attribute__((packed)) aB_BFu17ll_Sf { bool v1; unsigned long long v2:17; empty v3; };
struct __attribute__((packed)) aB_BFu1c_Sf { bool v1; unsigned char v2:1; empty v3; };
struct __attribute__((packed)) aB_BFu1i_Sf { bool v1; unsigned int v2:1; empty v3; };
struct __attribute__((packed)) aB_BFu1ll_Sf { bool v1; unsigned long long v2:1; empty v3; };
struct __attribute__((packed)) aB_BFu1s_Sf { bool v1; unsigned short v2:1; empty v3; };
struct __attribute__((packed)) aB_BFu31i_Sf { bool v1; unsigned int v2:31; empty v3; };
struct __attribute__((packed)) aB_BFu31ll_Sf { bool v1; unsigned long long v2:31; empty v3; };
struct __attribute__((packed)) aB_BFu32i_Sf { bool v1; unsigned int v2:32; empty v3; };
struct __attribute__((packed)) aB_BFu32ll_Sf { bool v1; unsigned long long v2:32; empty v3; };
struct __attribute__((packed)) aB_BFu33_Sf { bool v1; unsigned long long v2:33; empty v3; };
struct __attribute__((packed)) aB_BFu7c_Sf { bool v1; unsigned char v2:7; empty v3; };
struct __attribute__((packed)) aB_BFu7i_Sf { bool v1; unsigned int v2:7; empty v3; };
struct __attribute__((packed)) aB_BFu7ll_Sf { bool v1; unsigned long long v2:7; empty v3; };
struct __attribute__((packed)) aB_BFu7s_Sf { bool v1; unsigned short v2:7; empty v3; };
struct __attribute__((packed)) aB_BFu8c_Sf { bool v1; unsigned char v2:8; empty v3; };
struct __attribute__((packed)) aB_BFu8i_Sf { bool v1; unsigned int v2:8; empty v3; };
struct __attribute__((packed)) aB_BFu8ll_Sf { bool v1; unsigned long long v2:8; empty v3; };
struct __attribute__((packed)) aB_BFu8s_Sf { bool v1; unsigned short v2:8; empty v3; };
struct __attribute__((packed)) aB_BFu9i_Sf { bool v1; unsigned int v2:9; empty v3; };
struct __attribute__((packed)) aB_BFu9ll_Sf { bool v1; unsigned long long v2:9; empty v3; };
struct __attribute__((packed)) aB_BFu9s_Sf { bool v1; unsigned short v2:9; empty v3; };
struct __attribute__((packed)) aB_C_Sf { bool v1; char v2; empty v3; };
struct __attribute__((packed)) aB_D_Sf { bool v1; double v2; empty v3; };
struct __attribute__((packed)) aB_F_Sf { bool v1; float v2; empty v3; };
struct __attribute__((packed)) aB_I_Sf { bool v1; int v2; empty v3; };
struct __attribute__((packed)) aB_Ip_Sf { bool v1; int * v2; empty v3; };
struct __attribute__((packed)) aB_L_Sf { bool v1; long long v2; empty v3; };
struct __attribute__((packed)) aB_S_Sf { bool v1; short v2; empty v3; };
struct __attribute__((packed)) aB_Sf { bool v1; empty v2; };
struct __attribute__((packed)) aB_Sf_B { bool v1; empty v2; bool v3; };
struct __attribute__((packed)) aB_Sf_BFu15i { bool v1; empty v2; unsigned int v3:15; };
struct __attribute__((packed)) aB_Sf_BFu15ll { bool v1; empty v2; unsigned long long v3:15; };
struct __attribute__((packed)) aB_Sf_BFu15s { bool v1; empty v2; unsigned short v3:15; };
struct __attribute__((packed)) aB_Sf_BFu16i { bool v1; empty v2; unsigned int v3:16; };
struct __attribute__((packed)) aB_Sf_BFu16ll { bool v1; empty v2; unsigned long long v3:16; };
struct __attribute__((packed)) aB_Sf_BFu16s { bool v1; empty v2; unsigned short v3:16; };
struct __attribute__((packed)) aB_Sf_BFu17i { bool v1; empty v2; unsigned int v3:17; };
struct __attribute__((packed)) aB_Sf_BFu17ll { bool v1; empty v2; unsigned long long v3:17; };
struct __attribute__((packed)) aB_Sf_BFu1c { bool v1; empty v2; unsigned char v3:1; };
struct __attribute__((packed)) aB_Sf_BFu1i { bool v1; empty v2; unsigned int v3:1; };
struct __attribute__((packed)) aB_Sf_BFu1ll { bool v1; empty v2; unsigned long long v3:1; };
struct __attribute__((packed)) aB_Sf_BFu1s { bool v1; empty v2; unsigned short v3:1; };
struct __attribute__((packed)) aB_Sf_BFu31i { bool v1; empty v2; unsigned int v3:31; };
struct __attribute__((packed)) aB_Sf_BFu31ll { bool v1; empty v2; unsigned long long v3:31; };
struct __attribute__((packed)) aB_Sf_BFu32i { bool v1; empty v2; unsigned int v3:32; };
struct __attribute__((packed)) aB_Sf_BFu32ll { bool v1; empty v2; unsigned long long v3:32; };
struct __attribute__((packed)) aB_Sf_BFu33 { bool v1; empty v2; unsigned long long v3:33; };
struct __attribute__((packed)) aB_Sf_BFu7c { bool v1; empty v2; unsigned char v3:7; };
struct __attribute__((packed)) aB_Sf_BFu7i { bool v1; empty v2; unsigned int v3:7; };
struct __attribute__((packed)) aB_Sf_BFu7ll { bool v1; empty v2; unsigned long long v3:7; };
struct __attribute__((packed)) aB_Sf_BFu7s { bool v1; empty v2; unsigned short v3:7; };
struct __attribute__((packed)) aB_Sf_BFu8c { bool v1; empty v2; unsigned char v3:8; };
struct __attribute__((packed)) aB_Sf_BFu8i { bool v1; empty v2; unsigned int v3:8; };
struct __attribute__((packed)) aB_Sf_BFu8ll { bool v1; empty v2; unsigned long long v3:8; };
struct __attribute__((packed)) aB_Sf_BFu8s { bool v1; empty v2; unsigned short v3:8; };
struct __attribute__((packed)) aB_Sf_BFu9i { bool v1; empty v2; unsigned int v3:9; };
struct __attribute__((packed)) aB_Sf_BFu9ll { bool v1; empty v2; unsigned long long v3:9; };
struct __attribute__((packed)) aB_Sf_BFu9s { bool v1; empty v2; unsigned short v3:9; };
struct __attribute__((packed)) aB_Sf_C { bool v1; empty v2; char v3; };
struct __attribute__((packed)) aB_Sf_D { bool v1; empty v2; double v3; };
struct __attribute__((packed)) aB_Sf_F { bool v1; empty v2; float v3; };
struct __attribute__((packed)) aB_Sf_I { bool v1; empty v2; int v3; };
struct __attribute__((packed)) aB_Sf_Ip { bool v1; empty v2; int * v3; };
struct __attribute__((packed)) aB_Sf_L { bool v1; empty v2; long long v3; };
struct __attribute__((packed)) aB_Sf_S { bool v1; empty v2; short v3; };
struct __attribute__((packed)) aB_Sf_Sf { bool v1; empty v2; empty v3; };
struct __attribute__((packed)) aB_Sf_Uc { bool v1; empty v2; unsigned char v3; };
struct __attribute__((packed)) aB_Sf_Ui { bool v1; empty v2; unsigned int v3; };
struct __attribute__((packed)) aB_Sf_Ul { bool v1; empty v2; unsigned long long v3; };
struct __attribute__((packed)) aB_Sf_Us { bool v1; empty v2; unsigned short v3; };
struct __attribute__((packed)) aB_Sf_Vp { bool v1; empty v2; void * v3; };
struct __attribute__((packed)) aB_Uc_Sf { bool v1; unsigned char v2; empty v3; };
struct __attribute__((packed)) aB_Ui_Sf { bool v1; unsigned int v2; empty v3; };
struct __attribute__((packed)) aB_Ul_Sf { bool v1; unsigned long long v2; empty v3; };
struct __attribute__((packed)) aB_Us_Sf { bool v1; unsigned short v2; empty v3; };
struct __attribute__((packed)) aB_Vp_Sf { bool v1; void * v2; empty v3; };
struct __attribute__((packed)) aBFu15i_B_Sf { unsigned int v1:15; bool v2; empty v3; };
struct __attribute__((packed)) aBFu15i_Sf_B { unsigned int v1:15; empty v2; bool v3; };
struct __attribute__((packed)) aBFu15ll_B_Sf { unsigned long long v1:15; bool v2; empty v3; };
struct __attribute__((packed)) aBFu15ll_Sf_B { unsigned long long v1:15; empty v2; bool v3; };
struct __attribute__((packed)) aBFu15s_B_Sf { unsigned short v1:15; bool v2; empty v3; };
struct __attribute__((packed)) aBFu15s_Sf_B { unsigned short v1:15; empty v2; bool v3; };
struct __attribute__((packed)) aBFu16i_B_Sf { unsigned int v1:16; bool v2; empty v3; };
struct __attribute__((packed)) aBFu16i_Sf_B { unsigned int v1:16; empty v2; bool v3; };
struct __attribute__((packed)) aBFu16ll_B_Sf { unsigned long long v1:16; bool v2; empty v3; };
struct __attribute__((packed)) aBFu16ll_Sf_B { unsigned long long v1:16; empty v2; bool v3; };
struct __attribute__((packed)) aBFu16s_B_Sf { unsigned short v1:16; bool v2; empty v3; };
struct __attribute__((packed)) aBFu16s_Sf_B { unsigned short v1:16; empty v2; bool v3; };
struct __attribute__((packed)) aBFu17i_B_Sf { unsigned int v1:17; bool v2; empty v3; };
struct __attribute__((packed)) aBFu17i_Sf_B { unsigned int v1:17; empty v2; bool v3; };
struct __attribute__((packed)) aBFu17ll_B_Sf { unsigned long long v1:17; bool v2; empty v3; };
struct __attribute__((packed)) aBFu17ll_Sf_B { unsigned long long v1:17; empty v2; bool v3; };
struct __attribute__((packed)) aBFu1c_B_Sf { unsigned char v1:1; bool v2; empty v3; };
struct __attribute__((packed)) aBFu1c_Sf_B { unsigned char v1:1; empty v2; bool v3; };
struct __attribute__((packed)) aBFu1i_B_Sf { unsigned int v1:1; bool v2; empty v3; };
struct __attribute__((packed)) aBFu1i_Sf_B { unsigned int v1:1; empty v2; bool v3; };
struct __attribute__((packed)) aBFu1ll_B_Sf { unsigned long long v1:1; bool v2; empty v3; };
struct __attribute__((packed)) aBFu1ll_Sf_B { unsigned long long v1:1; empty v2; bool v3; };
struct __attribute__((packed)) aBFu1s_B_Sf { unsigned short v1:1; bool v2; empty v3; };
struct __attribute__((packed)) aBFu1s_Sf_B { unsigned short v1:1; empty v2; bool v3; };
struct __attribute__((packed)) aBFu31i_B_Sf { unsigned int v1:31; bool v2; empty v3; };
struct __attribute__((packed)) aBFu31i_Sf_B { unsigned int v1:31; empty v2; bool v3; };
struct __attribute__((packed)) aBFu31ll_B_Sf { unsigned long long v1:31; bool v2; empty v3; };
struct __attribute__((packed)) aBFu31ll_Sf_B { unsigned long long v1:31; empty v2; bool v3; };
struct __attribute__((packed)) aBFu32i_B_Sf { unsigned int v1:32; bool v2; empty v3; };
struct __attribute__((packed)) aBFu32i_Sf_B { unsigned int v1:32; empty v2; bool v3; };
struct __attribute__((packed)) aBFu32ll_B_Sf { unsigned long long v1:32; bool v2; empty v3; };
struct __attribute__((packed)) aBFu32ll_Sf_B { unsigned long long v1:32; empty v2; bool v3; };
struct __attribute__((packed)) aBFu33_B_Sf { unsigned long long v1:33; bool v2; empty v3; };
struct __attribute__((packed)) aBFu33_Sf_B { unsigned long long v1:33; empty v2; bool v3; };
struct __attribute__((packed)) aBFu7c_B_Sf { unsigned char v1:7; bool v2; empty v3; };
struct __attribute__((packed)) aBFu7c_Sf_B { unsigned char v1:7; empty v2; bool v3; };
struct __attribute__((packed)) aBFu7i_B_Sf { unsigned int v1:7; bool v2; empty v3; };
struct __attribute__((packed)) aBFu7i_Sf_B { unsigned int v1:7; empty v2; bool v3; };
struct __attribute__((packed)) aBFu7ll_B_Sf { unsigned long long v1:7; bool v2; empty v3; };
struct __attribute__((packed)) aBFu7ll_Sf_B { unsigned long long v1:7; empty v2; bool v3; };
struct __attribute__((packed)) aBFu7s_B_Sf { unsigned short v1:7; bool v2; empty v3; };
struct __attribute__((packed)) aBFu7s_Sf_B { unsigned short v1:7; empty v2; bool v3; };
struct __attribute__((packed)) aBFu8c_B_Sf { unsigned char v1:8; bool v2; empty v3; };
struct __attribute__((packed)) aBFu8c_Sf_B { unsigned char v1:8; empty v2; bool v3; };
struct __attribute__((packed)) aBFu8i_B_Sf { unsigned int v1:8; bool v2; empty v3; };
struct __attribute__((packed)) aBFu8i_Sf_B { unsigned int v1:8; empty v2; bool v3; };
struct __attribute__((packed)) aBFu8ll_B_Sf { unsigned long long v1:8; bool v2; empty v3; };
struct __attribute__((packed)) aBFu8ll_Sf_B { unsigned long long v1:8; empty v2; bool v3; };
struct __attribute__((packed)) aBFu8s_B_Sf { unsigned short v1:8; bool v2; empty v3; };
struct __attribute__((packed)) aBFu8s_Sf_B { unsigned short v1:8; empty v2; bool v3; };
struct __attribute__((packed)) aBFu9i_B_Sf { unsigned int v1:9; bool v2; empty v3; };
struct __attribute__((packed)) aBFu9i_Sf_B { unsigned int v1:9; empty v2; bool v3; };
struct __attribute__((packed)) aBFu9ll_B_Sf { unsigned long long v1:9; bool v2; empty v3; };
struct __attribute__((packed)) aBFu9ll_Sf_B { unsigned long long v1:9; empty v2; bool v3; };
struct __attribute__((packed)) aBFu9s_B_Sf { unsigned short v1:9; bool v2; empty v3; };
struct __attribute__((packed)) aBFu9s_Sf_B { unsigned short v1:9; empty v2; bool v3; };
struct __attribute__((packed)) aC_B_Sf { char v1; bool v2; empty v3; };
struct __attribute__((packed)) aC_Sf_B { char v1; empty v2; bool v3; };
struct __attribute__((packed)) aD_B_Sf { double v1; bool v2; empty v3; };
struct __attribute__((packed)) aD_Sf_B { double v1; empty v2; bool v3; };
struct __attribute__((packed)) aF_B_Sf { float v1; bool v2; empty v3; };
struct __attribute__((packed)) aF_Sf_B { float v1; empty v2; bool v3; };
struct __attribute__((packed)) aI_B_Sf { int v1; bool v2; empty v3; };
struct __attribute__((packed)) aI_Sf_B { int v1; empty v2; bool v3; };
struct __attribute__((packed)) aIp_B_Sf { int * v1; bool v2; empty v3; };
struct __attribute__((packed)) aIp_Sf_B { int * v1; empty v2; bool v3; };
struct __attribute__((packed)) aL_B_Sf { long long v1; bool v2; empty v3; };
struct __attribute__((packed)) aL_Sf_B { long long v1; empty v2; bool v3; };
struct __attribute__((packed)) aS_B_Sf { short v1; bool v2; empty v3; };
struct __attribute__((packed)) aS_Sf_B { short v1; empty v2; bool v3; };
struct __attribute__((packed)) aSf_B { empty v1; bool v2; };
struct __attribute__((packed)) aSf_B_B { empty v1; bool v2; bool v3; };
struct __attribute__((packed)) aSf_B_BFu15i { empty v1; bool v2; unsigned int v3:15; };
struct __attribute__((packed)) aSf_B_BFu15ll { empty v1; bool v2; unsigned long long v3:15; };
struct __attribute__((packed)) aSf_B_BFu15s { empty v1; bool v2; unsigned short v3:15; };
struct __attribute__((packed)) aSf_B_BFu16i { empty v1; bool v2; unsigned int v3:16; };
struct __attribute__((packed)) aSf_B_BFu16ll { empty v1; bool v2; unsigned long long v3:16; };
struct __attribute__((packed)) aSf_B_BFu16s { empty v1; bool v2; unsigned short v3:16; };
struct __attribute__((packed)) aSf_B_BFu17i { empty v1; bool v2; unsigned int v3:17; };
struct __attribute__((packed)) aSf_B_BFu17ll { empty v1; bool v2; unsigned long long v3:17; };
struct __attribute__((packed)) aSf_B_BFu1c { empty v1; bool v2; unsigned char v3:1; };
struct __attribute__((packed)) aSf_B_BFu1i { empty v1; bool v2; unsigned int v3:1; };
struct __attribute__((packed)) aSf_B_BFu1ll { empty v1; bool v2; unsigned long long v3:1; };
struct __attribute__((packed)) aSf_B_BFu1s { empty v1; bool v2; unsigned short v3:1; };
struct __attribute__((packed)) aSf_B_BFu31i { empty v1; bool v2; unsigned int v3:31; };
struct __attribute__((packed)) aSf_B_BFu31ll { empty v1; bool v2; unsigned long long v3:31; };
struct __attribute__((packed)) aSf_B_BFu32i { empty v1; bool v2; unsigned int v3:32; };
struct __attribute__((packed)) aSf_B_BFu32ll { empty v1; bool v2; unsigned long long v3:32; };
struct __attribute__((packed)) aSf_B_BFu33 { empty v1; bool v2; unsigned long long v3:33; };
struct __attribute__((packed)) aSf_B_BFu7c { empty v1; bool v2; unsigned char v3:7; };
struct __attribute__((packed)) aSf_B_BFu7i { empty v1; bool v2; unsigned int v3:7; };
struct __attribute__((packed)) aSf_B_BFu7ll { empty v1; bool v2; unsigned long long v3:7; };
struct __attribute__((packed)) aSf_B_BFu7s { empty v1; bool v2; unsigned short v3:7; };
struct __attribute__((packed)) aSf_B_BFu8c { empty v1; bool v2; unsigned char v3:8; };
struct __attribute__((packed)) aSf_B_BFu8i { empty v1; bool v2; unsigned int v3:8; };
struct __attribute__((packed)) aSf_B_BFu8ll { empty v1; bool v2; unsigned long long v3:8; };
struct __attribute__((packed)) aSf_B_BFu8s { empty v1; bool v2; unsigned short v3:8; };
struct __attribute__((packed)) aSf_B_BFu9i { empty v1; bool v2; unsigned int v3:9; };
struct __attribute__((packed)) aSf_B_BFu9ll { empty v1; bool v2; unsigned long long v3:9; };
struct __attribute__((packed)) aSf_B_BFu9s { empty v1; bool v2; unsigned short v3:9; };
struct __attribute__((packed)) aSf_B_C { empty v1; bool v2; char v3; };
struct __attribute__((packed)) aSf_B_D { empty v1; bool v2; double v3; };
struct __attribute__((packed)) aSf_B_F { empty v1; bool v2; float v3; };
struct __attribute__((packed)) aSf_B_I { empty v1; bool v2; int v3; };
struct __attribute__((packed)) aSf_B_Ip { empty v1; bool v2; int * v3; };
struct __attribute__((packed)) aSf_B_L { empty v1; bool v2; long long v3; };
struct __attribute__((packed)) aSf_B_S { empty v1; bool v2; short v3; };
struct __attribute__((packed)) aSf_B_Sf { empty v1; bool v2; empty v3; };
struct __attribute__((packed)) aSf_B_Uc { empty v1; bool v2; unsigned char v3; };
struct __attribute__((packed)) aSf_B_Ui { empty v1; bool v2; unsigned int v3; };
struct __attribute__((packed)) aSf_B_Ul { empty v1; bool v2; unsigned long long v3; };
struct __attribute__((packed)) aSf_B_Us { empty v1; bool v2; unsigned short v3; };
struct __attribute__((packed)) aSf_B_Vp { empty v1; bool v2; void * v3; };
struct __attribute__((packed)) aSf_BFu15i_B { empty v1; unsigned int v2:15; bool v3; };
struct __attribute__((packed)) aSf_BFu15ll_B { empty v1; unsigned long long v2:15; bool v3; };
struct __attribute__((packed)) aSf_BFu15s_B { empty v1; unsigned short v2:15; bool v3; };
struct __attribute__((packed)) aSf_BFu16i_B { empty v1; unsigned int v2:16; bool v3; };
struct __attribute__((packed)) aSf_BFu16ll_B { empty v1; unsigned long long v2:16; bool v3; };
struct __attribute__((packed)) aSf_BFu16s_B { empty v1; unsigned short v2:16; bool v3; };
struct __attribute__((packed)) aSf_BFu17i_B { empty v1; unsigned int v2:17; bool v3; };
struct __attribute__((packed)) aSf_BFu17ll_B { empty v1; unsigned long long v2:17; bool v3; };
struct __attribute__((packed)) aSf_BFu1c_B { empty v1; unsigned char v2:1; bool v3; };
struct __attribute__((packed)) aSf_BFu1i_B { empty v1; unsigned int v2:1; bool v3; };
struct __attribute__((packed)) aSf_BFu1ll_B { empty v1; unsigned long long v2:1; bool v3; };
struct __attribute__((packed)) aSf_BFu1s_B { empty v1; unsigned short v2:1; bool v3; };
struct __attribute__((packed)) aSf_BFu31i_B { empty v1; unsigned int v2:31; bool v3; };
struct __attribute__((packed)) aSf_BFu31ll_B { empty v1; unsigned long long v2:31; bool v3; };
struct __attribute__((packed)) aSf_BFu32i_B { empty v1; unsigned int v2:32; bool v3; };
struct __attribute__((packed)) aSf_BFu32ll_B { empty v1; unsigned long long v2:32; bool v3; };
struct __attribute__((packed)) aSf_BFu33_B { empty v1; unsigned long long v2:33; bool v3; };
struct __attribute__((packed)) aSf_BFu7c_B { empty v1; unsigned char v2:7; bool v3; };
struct __attribute__((packed)) aSf_BFu7i_B { empty v1; unsigned int v2:7; bool v3; };
struct __attribute__((packed)) aSf_BFu7ll_B { empty v1; unsigned long long v2:7; bool v3; };
struct __attribute__((packed)) aSf_BFu7s_B { empty v1; unsigned short v2:7; bool v3; };
struct __attribute__((packed)) aSf_BFu8c_B { empty v1; unsigned char v2:8; bool v3; };
struct __attribute__((packed)) aSf_BFu8i_B { empty v1; unsigned int v2:8; bool v3; };
struct __attribute__((packed)) aSf_BFu8ll_B { empty v1; unsigned long long v2:8; bool v3; };
struct __attribute__((packed)) aSf_BFu8s_B { empty v1; unsigned short v2:8; bool v3; };
struct __attribute__((packed)) aSf_BFu9i_B { empty v1; unsigned int v2:9; bool v3; };
struct __attribute__((packed)) aSf_BFu9ll_B { empty v1; unsigned long long v2:9; bool v3; };
struct __attribute__((packed)) aSf_BFu9s_B { empty v1; unsigned short v2:9; bool v3; };
struct __attribute__((packed)) aSf_C_B { empty v1; char v2; bool v3; };
struct __attribute__((packed)) aSf_D_B { empty v1; double v2; bool v3; };
struct __attribute__((packed)) aSf_F_B { empty v1; float v2; bool v3; };
struct __attribute__((packed)) aSf_I_B { empty v1; int v2; bool v3; };
struct __attribute__((packed)) aSf_Ip_B { empty v1; int * v2; bool v3; };
struct __attribute__((packed)) aSf_L_B { empty v1; long long v2; bool v3; };
struct __attribute__((packed)) aSf_S_B { empty v1; short v2; bool v3; };
struct __attribute__((packed)) aSf_Sf_B { empty v1; empty v2; bool v3; };
struct __attribute__((packed)) aSf_Uc_B { empty v1; unsigned char v2; bool v3; };
struct __attribute__((packed)) aSf_Ui_B { empty v1; unsigned int v2; bool v3; };
struct __attribute__((packed)) aSf_Ul_B { empty v1; unsigned long long v2; bool v3; };
struct __attribute__((packed)) aSf_Us_B { empty v1; unsigned short v2; bool v3; };
struct __attribute__((packed)) aSf_Vp_B { empty v1; void * v2; bool v3; };
struct __attribute__((packed)) aUc_B_Sf { unsigned char v1; bool v2; empty v3; };
struct __attribute__((packed)) aUc_Sf_B { unsigned char v1; empty v2; bool v3; };
struct __attribute__((packed)) aUi_B_Sf { unsigned int v1; bool v2; empty v3; };
struct __attribute__((packed)) aUi_Sf_B { unsigned int v1; empty v2; bool v3; };
struct __attribute__((packed)) aUl_B_Sf { unsigned long long v1; bool v2; empty v3; };
struct __attribute__((packed)) aUl_Sf_B { unsigned long long v1; empty v2; bool v3; };
struct __attribute__((packed)) aUs_B_Sf { unsigned short v1; bool v2; empty v3; };
struct __attribute__((packed)) aUs_Sf_B { unsigned short v1; empty v2; bool v3; };
struct __attribute__((packed)) aVp_B_Sf { void * v1; bool v2; empty v3; };
struct __attribute__((packed)) aVp_Sf_B { void * v1; empty v2; bool v3; };
#pragma pack(1)
struct B_B_Sf { bool v1; bool v2; empty v3; };
struct B_BFu15i_Sf { bool v1; unsigned int v2:15; empty v3; };
struct B_BFu15ll_Sf { bool v1; unsigned long long v2:15; empty v3; };
struct B_BFu15s_Sf { bool v1; unsigned short v2:15; empty v3; };
struct B_BFu16i_Sf { bool v1; unsigned int v2:16; empty v3; };
struct B_BFu16ll_Sf { bool v1; unsigned long long v2:16; empty v3; };
struct B_BFu16s_Sf { bool v1; unsigned short v2:16; empty v3; };
struct B_BFu17i_Sf { bool v1; unsigned int v2:17; empty v3; };
struct B_BFu17ll_Sf { bool v1; unsigned long long v2:17; empty v3; };
struct B_BFu1c_Sf { bool v1; unsigned char v2:1; empty v3; };
struct B_BFu1i_Sf { bool v1; unsigned int v2:1; empty v3; };
struct B_BFu1ll_Sf { bool v1; unsigned long long v2:1; empty v3; };
struct B_BFu1s_Sf { bool v1; unsigned short v2:1; empty v3; };
struct B_BFu31i_Sf { bool v1; unsigned int v2:31; empty v3; };
struct B_BFu31ll_Sf { bool v1; unsigned long long v2:31; empty v3; };
struct B_BFu32i_Sf { bool v1; unsigned int v2:32; empty v3; };
struct B_BFu32ll_Sf { bool v1; unsigned long long v2:32; empty v3; };
struct B_BFu33_Sf { bool v1; unsigned long long v2:33; empty v3; };
struct B_BFu7c_Sf { bool v1; unsigned char v2:7; empty v3; };
struct B_BFu7i_Sf { bool v1; unsigned int v2:7; empty v3; };
struct B_BFu7ll_Sf { bool v1; unsigned long long v2:7; empty v3; };
struct B_BFu7s_Sf { bool v1; unsigned short v2:7; empty v3; };
struct B_BFu8c_Sf { bool v1; unsigned char v2:8; empty v3; };
struct B_BFu8i_Sf { bool v1; unsigned int v2:8; empty v3; };
struct B_BFu8ll_Sf { bool v1; unsigned long long v2:8; empty v3; };
struct B_BFu8s_Sf { bool v1; unsigned short v2:8; empty v3; };
struct B_BFu9i_Sf { bool v1; unsigned int v2:9; empty v3; };
struct B_BFu9ll_Sf { bool v1; unsigned long long v2:9; empty v3; };
struct B_BFu9s_Sf { bool v1; unsigned short v2:9; empty v3; };
struct B_C_Sf { bool v1; char v2; empty v3; };
struct B_D_Sf { bool v1; double v2; empty v3; };
struct B_F_Sf { bool v1; float v2; empty v3; };
struct B_I_Sf { bool v1; int v2; empty v3; };
struct B_Ip_Sf { bool v1; int * v2; empty v3; };
struct B_L_Sf { bool v1; long long v2; empty v3; };
struct B_S_Sf { bool v1; short v2; empty v3; };
struct B_Sf { bool v1; empty v2; };
struct B_Sf_B { bool v1; empty v2; bool v3; };
struct B_Sf_BFu15i { bool v1; empty v2; unsigned int v3:15; };
struct B_Sf_BFu15ll { bool v1; empty v2; unsigned long long v3:15; };
struct B_Sf_BFu15s { bool v1; empty v2; unsigned short v3:15; };
struct B_Sf_BFu16i { bool v1; empty v2; unsigned int v3:16; };
struct B_Sf_BFu16ll { bool v1; empty v2; unsigned long long v3:16; };
struct B_Sf_BFu16s { bool v1; empty v2; unsigned short v3:16; };
struct B_Sf_BFu17i { bool v1; empty v2; unsigned int v3:17; };
struct B_Sf_BFu17ll { bool v1; empty v2; unsigned long long v3:17; };
struct B_Sf_BFu1c { bool v1; empty v2; unsigned char v3:1; };
struct B_Sf_BFu1i { bool v1; empty v2; unsigned int v3:1; };
struct B_Sf_BFu1ll { bool v1; empty v2; unsigned long long v3:1; };
struct B_Sf_BFu1s { bool v1; empty v2; unsigned short v3:1; };
struct B_Sf_BFu31i { bool v1; empty v2; unsigned int v3:31; };
struct B_Sf_BFu31ll { bool v1; empty v2; unsigned long long v3:31; };
struct B_Sf_BFu32i { bool v1; empty v2; unsigned int v3:32; };
struct B_Sf_BFu32ll { bool v1; empty v2; unsigned long long v3:32; };
struct B_Sf_BFu33 { bool v1; empty v2; unsigned long long v3:33; };
struct B_Sf_BFu7c { bool v1; empty v2; unsigned char v3:7; };
struct B_Sf_BFu7i { bool v1; empty v2; unsigned int v3:7; };
struct B_Sf_BFu7ll { bool v1; empty v2; unsigned long long v3:7; };
struct B_Sf_BFu7s { bool v1; empty v2; unsigned short v3:7; };
struct B_Sf_BFu8c { bool v1; empty v2; unsigned char v3:8; };
struct B_Sf_BFu8i { bool v1; empty v2; unsigned int v3:8; };
struct B_Sf_BFu8ll { bool v1; empty v2; unsigned long long v3:8; };
struct B_Sf_BFu8s { bool v1; empty v2; unsigned short v3:8; };
struct B_Sf_BFu9i { bool v1; empty v2; unsigned int v3:9; };
struct B_Sf_BFu9ll { bool v1; empty v2; unsigned long long v3:9; };
struct B_Sf_BFu9s { bool v1; empty v2; unsigned short v3:9; };
struct B_Sf_C { bool v1; empty v2; char v3; };
struct B_Sf_D { bool v1; empty v2; double v3; };
struct B_Sf_F { bool v1; empty v2; float v3; };
struct B_Sf_I { bool v1; empty v2; int v3; };
struct B_Sf_Ip { bool v1; empty v2; int * v3; };
struct B_Sf_L { bool v1; empty v2; long long v3; };
struct B_Sf_S { bool v1; empty v2; short v3; };
struct B_Sf_Sf { bool v1; empty v2; empty v3; };
struct B_Sf_Uc { bool v1; empty v2; unsigned char v3; };
struct B_Sf_Ui { bool v1; empty v2; unsigned int v3; };
struct B_Sf_Ul { bool v1; empty v2; unsigned long long v3; };
struct B_Sf_Us { bool v1; empty v2; unsigned short v3; };
struct B_Sf_Vp { bool v1; empty v2; void * v3; };
struct B_Uc_Sf { bool v1; unsigned char v2; empty v3; };
struct B_Ui_Sf { bool v1; unsigned int v2; empty v3; };
struct B_Ul_Sf { bool v1; unsigned long long v2; empty v3; };
struct B_Us_Sf { bool v1; unsigned short v2; empty v3; };
struct B_Vp_Sf { bool v1; void * v2; empty v3; };
struct BFu15i_B_Sf { unsigned int v1:15; bool v2; empty v3; };
struct BFu15i_Sf_B { unsigned int v1:15; empty v2; bool v3; };
struct BFu15ll_B_Sf { unsigned long long v1:15; bool v2; empty v3; };
struct BFu15ll_Sf_B { unsigned long long v1:15; empty v2; bool v3; };
struct BFu15s_B_Sf { unsigned short v1:15; bool v2; empty v3; };
struct BFu15s_Sf_B { unsigned short v1:15; empty v2; bool v3; };
struct BFu16i_B_Sf { unsigned int v1:16; bool v2; empty v3; };
struct BFu16i_Sf_B { unsigned int v1:16; empty v2; bool v3; };
struct BFu16ll_B_Sf { unsigned long long v1:16; bool v2; empty v3; };
struct BFu16ll_Sf_B { unsigned long long v1:16; empty v2; bool v3; };
struct BFu16s_B_Sf { unsigned short v1:16; bool v2; empty v3; };
struct BFu16s_Sf_B { unsigned short v1:16; empty v2; bool v3; };
struct BFu17i_B_Sf { unsigned int v1:17; bool v2; empty v3; };
struct BFu17i_Sf_B { unsigned int v1:17; empty v2; bool v3; };
struct BFu17ll_B_Sf { unsigned long long v1:17; bool v2; empty v3; };
struct BFu17ll_Sf_B { unsigned long long v1:17; empty v2; bool v3; };
struct BFu1c_B_Sf { unsigned char v1:1; bool v2; empty v3; };
struct BFu1c_Sf_B { unsigned char v1:1; empty v2; bool v3; };
struct BFu1i_B_Sf { unsigned int v1:1; bool v2; empty v3; };
struct BFu1i_Sf_B { unsigned int v1:1; empty v2; bool v3; };
struct BFu1ll_B_Sf { unsigned long long v1:1; bool v2; empty v3; };
struct BFu1ll_Sf_B { unsigned long long v1:1; empty v2; bool v3; };
struct BFu1s_B_Sf { unsigned short v1:1; bool v2; empty v3; };
struct BFu1s_Sf_B { unsigned short v1:1; empty v2; bool v3; };
struct BFu31i_B_Sf { unsigned int v1:31; bool v2; empty v3; };
struct BFu31i_Sf_B { unsigned int v1:31; empty v2; bool v3; };
struct BFu31ll_B_Sf { unsigned long long v1:31; bool v2; empty v3; };
struct BFu31ll_Sf_B { unsigned long long v1:31; empty v2; bool v3; };
struct BFu32i_B_Sf { unsigned int v1:32; bool v2; empty v3; };
struct BFu32i_Sf_B { unsigned int v1:32; empty v2; bool v3; };
struct BFu32ll_B_Sf { unsigned long long v1:32; bool v2; empty v3; };
struct BFu32ll_Sf_B { unsigned long long v1:32; empty v2; bool v3; };
struct BFu33_B_Sf { unsigned long long v1:33; bool v2; empty v3; };
struct BFu33_Sf_B { unsigned long long v1:33; empty v2; bool v3; };
struct BFu7c_B_Sf { unsigned char v1:7; bool v2; empty v3; };
struct BFu7c_Sf_B { unsigned char v1:7; empty v2; bool v3; };
struct BFu7i_B_Sf { unsigned int v1:7; bool v2; empty v3; };
struct BFu7i_Sf_B { unsigned int v1:7; empty v2; bool v3; };
struct BFu7ll_B_Sf { unsigned long long v1:7; bool v2; empty v3; };
struct BFu7ll_Sf_B { unsigned long long v1:7; empty v2; bool v3; };
struct BFu7s_B_Sf { unsigned short v1:7; bool v2; empty v3; };
struct BFu7s_Sf_B { unsigned short v1:7; empty v2; bool v3; };
struct BFu8c_B_Sf { unsigned char v1:8; bool v2; empty v3; };
struct BFu8c_Sf_B { unsigned char v1:8; empty v2; bool v3; };
struct BFu8i_B_Sf { unsigned int v1:8; bool v2; empty v3; };
struct BFu8i_Sf_B { unsigned int v1:8; empty v2; bool v3; };
struct BFu8ll_B_Sf { unsigned long long v1:8; bool v2; empty v3; };
struct BFu8ll_Sf_B { unsigned long long v1:8; empty v2; bool v3; };
struct BFu8s_B_Sf { unsigned short v1:8; bool v2; empty v3; };
struct BFu8s_Sf_B { unsigned short v1:8; empty v2; bool v3; };
struct BFu9i_B_Sf { unsigned int v1:9; bool v2; empty v3; };
struct BFu9i_Sf_B { unsigned int v1:9; empty v2; bool v3; };
struct BFu9ll_B_Sf { unsigned long long v1:9; bool v2; empty v3; };
struct BFu9ll_Sf_B { unsigned long long v1:9; empty v2; bool v3; };
struct BFu9s_B_Sf { unsigned short v1:9; bool v2; empty v3; };
struct BFu9s_Sf_B { unsigned short v1:9; empty v2; bool v3; };
struct C_B_Sf { char v1; bool v2; empty v3; };
struct C_Sf_B { char v1; empty v2; bool v3; };
struct D_B_Sf { double v1; bool v2; empty v3; };
struct D_Sf_B { double v1; empty v2; bool v3; };
struct F_B_Sf { float v1; bool v2; empty v3; };
struct F_Sf_B { float v1; empty v2; bool v3; };
struct I_B_Sf { int v1; bool v2; empty v3; };
struct I_Sf_B { int v1; empty v2; bool v3; };
struct Ip_B_Sf { int * v1; bool v2; empty v3; };
struct Ip_Sf_B { int * v1; empty v2; bool v3; };
struct L_B_Sf { long long v1; bool v2; empty v3; };
struct L_Sf_B { long long v1; empty v2; bool v3; };
struct S_B_Sf { short v1; bool v2; empty v3; };
struct S_Sf_B { short v1; empty v2; bool v3; };
struct Sf_B { empty v1; bool v2; };
struct Sf_B_B { empty v1; bool v2; bool v3; };
struct Sf_B_BFu15i { empty v1; bool v2; unsigned int v3:15; };
struct Sf_B_BFu15ll { empty v1; bool v2; unsigned long long v3:15; };
struct Sf_B_BFu15s { empty v1; bool v2; unsigned short v3:15; };
struct Sf_B_BFu16i { empty v1; bool v2; unsigned int v3:16; };
struct Sf_B_BFu16ll { empty v1; bool v2; unsigned long long v3:16; };
struct Sf_B_BFu16s { empty v1; bool v2; unsigned short v3:16; };
struct Sf_B_BFu17i { empty v1; bool v2; unsigned int v3:17; };
struct Sf_B_BFu17ll { empty v1; bool v2; unsigned long long v3:17; };
struct Sf_B_BFu1c { empty v1; bool v2; unsigned char v3:1; };
struct Sf_B_BFu1i { empty v1; bool v2; unsigned int v3:1; };
struct Sf_B_BFu1ll { empty v1; bool v2; unsigned long long v3:1; };
struct Sf_B_BFu1s { empty v1; bool v2; unsigned short v3:1; };
struct Sf_B_BFu31i { empty v1; bool v2; unsigned int v3:31; };
struct Sf_B_BFu31ll { empty v1; bool v2; unsigned long long v3:31; };
struct Sf_B_BFu32i { empty v1; bool v2; unsigned int v3:32; };
struct Sf_B_BFu32ll { empty v1; bool v2; unsigned long long v3:32; };
struct Sf_B_BFu33 { empty v1; bool v2; unsigned long long v3:33; };
struct Sf_B_BFu7c { empty v1; bool v2; unsigned char v3:7; };
struct Sf_B_BFu7i { empty v1; bool v2; unsigned int v3:7; };
struct Sf_B_BFu7ll { empty v1; bool v2; unsigned long long v3:7; };
struct Sf_B_BFu7s { empty v1; bool v2; unsigned short v3:7; };
struct Sf_B_BFu8c { empty v1; bool v2; unsigned char v3:8; };
struct Sf_B_BFu8i { empty v1; bool v2; unsigned int v3:8; };
struct Sf_B_BFu8ll { empty v1; bool v2; unsigned long long v3:8; };
struct Sf_B_BFu8s { empty v1; bool v2; unsigned short v3:8; };
struct Sf_B_BFu9i { empty v1; bool v2; unsigned int v3:9; };
struct Sf_B_BFu9ll { empty v1; bool v2; unsigned long long v3:9; };
struct Sf_B_BFu9s { empty v1; bool v2; unsigned short v3:9; };
struct Sf_B_C { empty v1; bool v2; char v3; };
struct Sf_B_D { empty v1; bool v2; double v3; };
struct Sf_B_F { empty v1; bool v2; float v3; };
struct Sf_B_I { empty v1; bool v2; int v3; };
struct Sf_B_Ip { empty v1; bool v2; int * v3; };
struct Sf_B_L { empty v1; bool v2; long long v3; };
struct Sf_B_S { empty v1; bool v2; short v3; };
struct Sf_B_Sf { empty v1; bool v2; empty v3; };
struct Sf_B_Uc { empty v1; bool v2; unsigned char v3; };
struct Sf_B_Ui { empty v1; bool v2; unsigned int v3; };
struct Sf_B_Ul { empty v1; bool v2; unsigned long long v3; };
struct Sf_B_Us { empty v1; bool v2; unsigned short v3; };
struct Sf_B_Vp { empty v1; bool v2; void * v3; };
struct Sf_BFu15i_B { empty v1; unsigned int v2:15; bool v3; };
struct Sf_BFu15ll_B { empty v1; unsigned long long v2:15; bool v3; };
struct Sf_BFu15s_B { empty v1; unsigned short v2:15; bool v3; };
struct Sf_BFu16i_B { empty v1; unsigned int v2:16; bool v3; };
struct Sf_BFu16ll_B { empty v1; unsigned long long v2:16; bool v3; };
struct Sf_BFu16s_B { empty v1; unsigned short v2:16; bool v3; };
struct Sf_BFu17i_B { empty v1; unsigned int v2:17; bool v3; };
struct Sf_BFu17ll_B { empty v1; unsigned long long v2:17; bool v3; };
struct Sf_BFu1c_B { empty v1; unsigned char v2:1; bool v3; };
struct Sf_BFu1i_B { empty v1; unsigned int v2:1; bool v3; };
struct Sf_BFu1ll_B { empty v1; unsigned long long v2:1; bool v3; };
struct Sf_BFu1s_B { empty v1; unsigned short v2:1; bool v3; };
struct Sf_BFu31i_B { empty v1; unsigned int v2:31; bool v3; };
struct Sf_BFu31ll_B { empty v1; unsigned long long v2:31; bool v3; };
struct Sf_BFu32i_B { empty v1; unsigned int v2:32; bool v3; };
struct Sf_BFu32ll_B { empty v1; unsigned long long v2:32; bool v3; };
struct Sf_BFu33_B { empty v1; unsigned long long v2:33; bool v3; };
struct Sf_BFu7c_B { empty v1; unsigned char v2:7; bool v3; };
struct Sf_BFu7i_B { empty v1; unsigned int v2:7; bool v3; };
struct Sf_BFu7ll_B { empty v1; unsigned long long v2:7; bool v3; };
struct Sf_BFu7s_B { empty v1; unsigned short v2:7; bool v3; };
struct Sf_BFu8c_B { empty v1; unsigned char v2:8; bool v3; };
struct Sf_BFu8i_B { empty v1; unsigned int v2:8; bool v3; };
struct Sf_BFu8ll_B { empty v1; unsigned long long v2:8; bool v3; };
struct Sf_BFu8s_B { empty v1; unsigned short v2:8; bool v3; };
struct Sf_BFu9i_B { empty v1; unsigned int v2:9; bool v3; };
struct Sf_BFu9ll_B { empty v1; unsigned long long v2:9; bool v3; };
struct Sf_BFu9s_B { empty v1; unsigned short v2:9; bool v3; };
struct Sf_C_B { empty v1; char v2; bool v3; };
struct Sf_D_B { empty v1; double v2; bool v3; };
struct Sf_F_B { empty v1; float v2; bool v3; };
struct Sf_I_B { empty v1; int v2; bool v3; };
struct Sf_Ip_B { empty v1; int * v2; bool v3; };
struct Sf_L_B { empty v1; long long v2; bool v3; };
struct Sf_S_B { empty v1; short v2; bool v3; };
struct Sf_Sf_B { empty v1; empty v2; bool v3; };
struct Sf_Uc_B { empty v1; unsigned char v2; bool v3; };
struct Sf_Ui_B { empty v1; unsigned int v2; bool v3; };
struct Sf_Ul_B { empty v1; unsigned long long v2; bool v3; };
struct Sf_Us_B { empty v1; unsigned short v2; bool v3; };
struct Sf_Vp_B { empty v1; void * v2; bool v3; };
struct Uc_B_Sf { unsigned char v1; bool v2; empty v3; };
struct Uc_Sf_B { unsigned char v1; empty v2; bool v3; };
struct Ui_B_Sf { unsigned int v1; bool v2; empty v3; };
struct Ui_Sf_B { unsigned int v1; empty v2; bool v3; };
struct Ul_B_Sf { unsigned long long v1; bool v2; empty v3; };
struct Ul_Sf_B { unsigned long long v1; empty v2; bool v3; };
struct Us_B_Sf { unsigned short v1; bool v2; empty v3; };
struct Us_Sf_B { unsigned short v1; empty v2; bool v3; };
struct Vp_B_Sf { void * v1; bool v2; empty v3; };
struct Vp_Sf_B { void * v1; empty v2; bool v3; };
#endif // __cplusplus
#ifdef __cplusplus


static void Test_empty()
{
  {
    init_simple_test("empty");
    empty lv;
    check2(sizeof(lv), 1, "sizeof(empty)");
    check2(__alignof__(lv), 1, "__alignof__(empty)");
  }
}
static Arrange_To_Call_Me vempty(Test_empty, "empty", 1);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_B_Sf()
{
  {
    init_simple_test("aB_B_Sf");
    aB_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aB_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_B_Sf)");
    check_field_offset(lv, v1, 0, "aB_B_Sf.v1");
    check_field_offset(lv, v2, 1, "aB_B_Sf.v2");
    check_field_offset(lv, v3, 2, "aB_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_B_Sf(Test_aB_B_Sf, "aB_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu15i_Sf()
{
  {
    init_simple_test("aB_BFu15i_Sf");
    static aB_BFu15i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aB_BFu15i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu15i_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu15i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "aB_BFu15i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "aB_BFu15i_Sf");
    check_field_offset(lv, v3, 3, "aB_BFu15i_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu15i_Sf(Test_aB_BFu15i_Sf, "aB_BFu15i_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu15ll_Sf()
{
  {
    init_simple_test("aB_BFu15ll_Sf");
    static aB_BFu15ll_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aB_BFu15ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu15ll_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu15ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "aB_BFu15ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "aB_BFu15ll_Sf");
    check_field_offset(lv, v3, 3, "aB_BFu15ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu15ll_Sf(Test_aB_BFu15ll_Sf, "aB_BFu15ll_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu15s_Sf()
{
  {
    init_simple_test("aB_BFu15s_Sf");
    static aB_BFu15s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aB_BFu15s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu15s_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu15s_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "aB_BFu15s_Sf");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "aB_BFu15s_Sf");
    check_field_offset(lv, v3, 3, "aB_BFu15s_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu15s_Sf(Test_aB_BFu15s_Sf, "aB_BFu15s_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu16i_Sf()
{
  {
    init_simple_test("aB_BFu16i_Sf");
    static aB_BFu16i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aB_BFu16i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu16i_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu16i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "aB_BFu16i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "aB_BFu16i_Sf");
    check_field_offset(lv, v3, 3, "aB_BFu16i_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu16i_Sf(Test_aB_BFu16i_Sf, "aB_BFu16i_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu16ll_Sf()
{
  {
    init_simple_test("aB_BFu16ll_Sf");
    static aB_BFu16ll_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aB_BFu16ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu16ll_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu16ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "aB_BFu16ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "aB_BFu16ll_Sf");
    check_field_offset(lv, v3, 3, "aB_BFu16ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu16ll_Sf(Test_aB_BFu16ll_Sf, "aB_BFu16ll_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu16s_Sf()
{
  {
    init_simple_test("aB_BFu16s_Sf");
    static aB_BFu16s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aB_BFu16s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu16s_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu16s_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "aB_BFu16s_Sf");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "aB_BFu16s_Sf");
    check_field_offset(lv, v3, 3, "aB_BFu16s_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu16s_Sf(Test_aB_BFu16s_Sf, "aB_BFu16s_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu17i_Sf()
{
  {
    init_simple_test("aB_BFu17i_Sf");
    static aB_BFu17i_Sf lv;
    check2(sizeof(lv), 5, "sizeof(aB_BFu17i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu17i_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu17i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "aB_BFu17i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "aB_BFu17i_Sf");
    check_field_offset(lv, v3, 4, "aB_BFu17i_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu17i_Sf(Test_aB_BFu17i_Sf, "aB_BFu17i_Sf", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu17ll_Sf()
{
  {
    init_simple_test("aB_BFu17ll_Sf");
    static aB_BFu17ll_Sf lv;
    check2(sizeof(lv), 5, "sizeof(aB_BFu17ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu17ll_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu17ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "aB_BFu17ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "aB_BFu17ll_Sf");
    check_field_offset(lv, v3, 4, "aB_BFu17ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu17ll_Sf(Test_aB_BFu17ll_Sf, "aB_BFu17ll_Sf", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu1c_Sf()
{
  {
    init_simple_test("aB_BFu1c_Sf");
    static aB_BFu1c_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aB_BFu1c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu1c_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu1c_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "aB_BFu1c_Sf");
    check_field_offset(lv, v3, 2, "aB_BFu1c_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu1c_Sf(Test_aB_BFu1c_Sf, "aB_BFu1c_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu1i_Sf()
{
  {
    init_simple_test("aB_BFu1i_Sf");
    static aB_BFu1i_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aB_BFu1i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu1i_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu1i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "aB_BFu1i_Sf");
    check_field_offset(lv, v3, 2, "aB_BFu1i_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu1i_Sf(Test_aB_BFu1i_Sf, "aB_BFu1i_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu1ll_Sf()
{
  {
    init_simple_test("aB_BFu1ll_Sf");
    static aB_BFu1ll_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aB_BFu1ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu1ll_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu1ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "aB_BFu1ll_Sf");
    check_field_offset(lv, v3, 2, "aB_BFu1ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu1ll_Sf(Test_aB_BFu1ll_Sf, "aB_BFu1ll_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu1s_Sf()
{
  {
    init_simple_test("aB_BFu1s_Sf");
    static aB_BFu1s_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aB_BFu1s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu1s_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu1s_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "aB_BFu1s_Sf");
    check_field_offset(lv, v3, 2, "aB_BFu1s_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu1s_Sf(Test_aB_BFu1s_Sf, "aB_BFu1s_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu31i_Sf()
{
  {
    init_simple_test("aB_BFu31i_Sf");
    static aB_BFu31i_Sf lv;
    check2(sizeof(lv), 6, "sizeof(aB_BFu31i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu31i_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu31i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "aB_BFu31i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "aB_BFu31i_Sf");
    check_field_offset(lv, v3, 5, "aB_BFu31i_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu31i_Sf(Test_aB_BFu31i_Sf, "aB_BFu31i_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu31ll_Sf()
{
  {
    init_simple_test("aB_BFu31ll_Sf");
    static aB_BFu31ll_Sf lv;
    check2(sizeof(lv), 6, "sizeof(aB_BFu31ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu31ll_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu31ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "aB_BFu31ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "aB_BFu31ll_Sf");
    check_field_offset(lv, v3, 5, "aB_BFu31ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu31ll_Sf(Test_aB_BFu31ll_Sf, "aB_BFu31ll_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu32i_Sf()
{
  {
    init_simple_test("aB_BFu32i_Sf");
    static aB_BFu32i_Sf lv;
    check2(sizeof(lv), 6, "sizeof(aB_BFu32i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu32i_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu32i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "aB_BFu32i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "aB_BFu32i_Sf");
    check_field_offset(lv, v3, 5, "aB_BFu32i_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu32i_Sf(Test_aB_BFu32i_Sf, "aB_BFu32i_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu32ll_Sf()
{
  {
    init_simple_test("aB_BFu32ll_Sf");
    static aB_BFu32ll_Sf lv;
    check2(sizeof(lv), 6, "sizeof(aB_BFu32ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu32ll_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu32ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "aB_BFu32ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "aB_BFu32ll_Sf");
    check_field_offset(lv, v3, 5, "aB_BFu32ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu32ll_Sf(Test_aB_BFu32ll_Sf, "aB_BFu32ll_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu33_Sf()
{
  {
    init_simple_test("aB_BFu33_Sf");
    static aB_BFu33_Sf lv;
    check2(sizeof(lv), 7, "sizeof(aB_BFu33_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu33_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu33_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 33, 1, "aB_BFu33_Sf");
    set_bf_and_test(lv, v2, 1, 0, 33, hide_ull(1LL<<32), "aB_BFu33_Sf");
    check_field_offset(lv, v3, 6, "aB_BFu33_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu33_Sf(Test_aB_BFu33_Sf, "aB_BFu33_Sf", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu7c_Sf()
{
  {
    init_simple_test("aB_BFu7c_Sf");
    static aB_BFu7c_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aB_BFu7c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu7c_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu7c_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "aB_BFu7c_Sf");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "aB_BFu7c_Sf");
    check_field_offset(lv, v3, 2, "aB_BFu7c_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu7c_Sf(Test_aB_BFu7c_Sf, "aB_BFu7c_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu7i_Sf()
{
  {
    init_simple_test("aB_BFu7i_Sf");
    static aB_BFu7i_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aB_BFu7i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu7i_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu7i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "aB_BFu7i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "aB_BFu7i_Sf");
    check_field_offset(lv, v3, 2, "aB_BFu7i_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu7i_Sf(Test_aB_BFu7i_Sf, "aB_BFu7i_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu7ll_Sf()
{
  {
    init_simple_test("aB_BFu7ll_Sf");
    static aB_BFu7ll_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aB_BFu7ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu7ll_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu7ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "aB_BFu7ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "aB_BFu7ll_Sf");
    check_field_offset(lv, v3, 2, "aB_BFu7ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu7ll_Sf(Test_aB_BFu7ll_Sf, "aB_BFu7ll_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu7s_Sf()
{
  {
    init_simple_test("aB_BFu7s_Sf");
    static aB_BFu7s_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aB_BFu7s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu7s_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu7s_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "aB_BFu7s_Sf");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "aB_BFu7s_Sf");
    check_field_offset(lv, v3, 2, "aB_BFu7s_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu7s_Sf(Test_aB_BFu7s_Sf, "aB_BFu7s_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu8c_Sf()
{
  {
    init_simple_test("aB_BFu8c_Sf");
    static aB_BFu8c_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aB_BFu8c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu8c_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu8c_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "aB_BFu8c_Sf");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "aB_BFu8c_Sf");
    check_field_offset(lv, v3, 2, "aB_BFu8c_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu8c_Sf(Test_aB_BFu8c_Sf, "aB_BFu8c_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu8i_Sf()
{
  {
    init_simple_test("aB_BFu8i_Sf");
    static aB_BFu8i_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aB_BFu8i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu8i_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu8i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "aB_BFu8i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "aB_BFu8i_Sf");
    check_field_offset(lv, v3, 2, "aB_BFu8i_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu8i_Sf(Test_aB_BFu8i_Sf, "aB_BFu8i_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu8ll_Sf()
{
  {
    init_simple_test("aB_BFu8ll_Sf");
    static aB_BFu8ll_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aB_BFu8ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu8ll_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu8ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "aB_BFu8ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "aB_BFu8ll_Sf");
    check_field_offset(lv, v3, 2, "aB_BFu8ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu8ll_Sf(Test_aB_BFu8ll_Sf, "aB_BFu8ll_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu8s_Sf()
{
  {
    init_simple_test("aB_BFu8s_Sf");
    static aB_BFu8s_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aB_BFu8s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu8s_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu8s_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "aB_BFu8s_Sf");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "aB_BFu8s_Sf");
    check_field_offset(lv, v3, 2, "aB_BFu8s_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu8s_Sf(Test_aB_BFu8s_Sf, "aB_BFu8s_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu9i_Sf()
{
  {
    init_simple_test("aB_BFu9i_Sf");
    static aB_BFu9i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aB_BFu9i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu9i_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu9i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "aB_BFu9i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "aB_BFu9i_Sf");
    check_field_offset(lv, v3, 3, "aB_BFu9i_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu9i_Sf(Test_aB_BFu9i_Sf, "aB_BFu9i_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu9ll_Sf()
{
  {
    init_simple_test("aB_BFu9ll_Sf");
    static aB_BFu9ll_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aB_BFu9ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu9ll_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu9ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "aB_BFu9ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "aB_BFu9ll_Sf");
    check_field_offset(lv, v3, 3, "aB_BFu9ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu9ll_Sf(Test_aB_BFu9ll_Sf, "aB_BFu9ll_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_BFu9s_Sf()
{
  {
    init_simple_test("aB_BFu9s_Sf");
    static aB_BFu9s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aB_BFu9s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_BFu9s_Sf)");
    check_field_offset(lv, v1, 0, "aB_BFu9s_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "aB_BFu9s_Sf");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "aB_BFu9s_Sf");
    check_field_offset(lv, v3, 3, "aB_BFu9s_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_BFu9s_Sf(Test_aB_BFu9s_Sf, "aB_BFu9s_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_C_Sf()
{
  {
    init_simple_test("aB_C_Sf");
    aB_C_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aB_C_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_C_Sf)");
    check_field_offset(lv, v1, 0, "aB_C_Sf.v1");
    check_field_offset(lv, v2, 1, "aB_C_Sf.v2");
    check_field_offset(lv, v3, 2, "aB_C_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_C_Sf(Test_aB_C_Sf, "aB_C_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_D_Sf()
{
  {
    init_simple_test("aB_D_Sf");
    aB_D_Sf lv;
    check2(sizeof(lv), 10, "sizeof(aB_D_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_D_Sf)");
    check_field_offset(lv, v1, 0, "aB_D_Sf.v1");
    check_field_offset(lv, v2, 1, "aB_D_Sf.v2");
    check_field_offset(lv, v3, 9, "aB_D_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_D_Sf(Test_aB_D_Sf, "aB_D_Sf", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_F_Sf()
{
  {
    init_simple_test("aB_F_Sf");
    aB_F_Sf lv;
    check2(sizeof(lv), 6, "sizeof(aB_F_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_F_Sf)");
    check_field_offset(lv, v1, 0, "aB_F_Sf.v1");
    check_field_offset(lv, v2, 1, "aB_F_Sf.v2");
    check_field_offset(lv, v3, 5, "aB_F_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_F_Sf(Test_aB_F_Sf, "aB_F_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_I_Sf()
{
  {
    init_simple_test("aB_I_Sf");
    aB_I_Sf lv;
    check2(sizeof(lv), 6, "sizeof(aB_I_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_I_Sf)");
    check_field_offset(lv, v1, 0, "aB_I_Sf.v1");
    check_field_offset(lv, v2, 1, "aB_I_Sf.v2");
    check_field_offset(lv, v3, 5, "aB_I_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_I_Sf(Test_aB_I_Sf, "aB_I_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Ip_Sf()
{
  {
    init_simple_test("aB_Ip_Sf");
    aB_Ip_Sf lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(aB_Ip_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Ip_Sf)");
    check_field_offset(lv, v1, 0, "aB_Ip_Sf.v1");
    check_field_offset(lv, v2, 1, "aB_Ip_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "aB_Ip_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_Ip_Sf(Test_aB_Ip_Sf, "aB_Ip_Sf", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_L_Sf()
{
  {
    init_simple_test("aB_L_Sf");
    aB_L_Sf lv;
    check2(sizeof(lv), 10, "sizeof(aB_L_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_L_Sf)");
    check_field_offset(lv, v1, 0, "aB_L_Sf.v1");
    check_field_offset(lv, v2, 1, "aB_L_Sf.v2");
    check_field_offset(lv, v3, 9, "aB_L_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_L_Sf(Test_aB_L_Sf, "aB_L_Sf", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_S_Sf()
{
  {
    init_simple_test("aB_S_Sf");
    aB_S_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aB_S_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_S_Sf)");
    check_field_offset(lv, v1, 0, "aB_S_Sf.v1");
    check_field_offset(lv, v2, 1, "aB_S_Sf.v2");
    check_field_offset(lv, v3, 3, "aB_S_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_S_Sf(Test_aB_S_Sf, "aB_S_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf()
{
  {
    init_simple_test("aB_Sf");
    aB_Sf lv;
    check2(sizeof(lv), 2, "sizeof(aB_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf)");
    check_field_offset(lv, v1, 0, "aB_Sf.v1");
    check_field_offset(lv, v2, 1, "aB_Sf.v2");
  }
}
static Arrange_To_Call_Me vaB_Sf(Test_aB_Sf, "aB_Sf", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_B()
{
  {
    init_simple_test("aB_Sf_B");
    aB_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(aB_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_B)");
    check_field_offset(lv, v1, 0, "aB_Sf_B.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_B.v2");
    check_field_offset(lv, v3, 2, "aB_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaB_Sf_B(Test_aB_Sf_B, "aB_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu15i()
{
  {
    init_simple_test("aB_Sf_BFu15i");
    static aB_Sf_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(aB_Sf_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu15i)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu15i.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu15i.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "aB_Sf_BFu15i");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "aB_Sf_BFu15i");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu15i(Test_aB_Sf_BFu15i, "aB_Sf_BFu15i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu15ll()
{
  {
    init_simple_test("aB_Sf_BFu15ll");
    static aB_Sf_BFu15ll lv;
    check2(sizeof(lv), 4, "sizeof(aB_Sf_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu15ll)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu15ll.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu15ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "aB_Sf_BFu15ll");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "aB_Sf_BFu15ll");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu15ll(Test_aB_Sf_BFu15ll, "aB_Sf_BFu15ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu15s()
{
  {
    init_simple_test("aB_Sf_BFu15s");
    static aB_Sf_BFu15s lv;
    check2(sizeof(lv), 4, "sizeof(aB_Sf_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu15s)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu15s.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu15s.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "aB_Sf_BFu15s");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "aB_Sf_BFu15s");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu15s(Test_aB_Sf_BFu15s, "aB_Sf_BFu15s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu16i()
{
  {
    init_simple_test("aB_Sf_BFu16i");
    static aB_Sf_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(aB_Sf_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu16i)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu16i.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu16i.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "aB_Sf_BFu16i");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "aB_Sf_BFu16i");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu16i(Test_aB_Sf_BFu16i, "aB_Sf_BFu16i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu16ll()
{
  {
    init_simple_test("aB_Sf_BFu16ll");
    static aB_Sf_BFu16ll lv;
    check2(sizeof(lv), 4, "sizeof(aB_Sf_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu16ll)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu16ll.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu16ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "aB_Sf_BFu16ll");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "aB_Sf_BFu16ll");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu16ll(Test_aB_Sf_BFu16ll, "aB_Sf_BFu16ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu16s()
{
  {
    init_simple_test("aB_Sf_BFu16s");
    static aB_Sf_BFu16s lv;
    check2(sizeof(lv), 4, "sizeof(aB_Sf_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu16s)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu16s.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu16s.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "aB_Sf_BFu16s");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "aB_Sf_BFu16s");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu16s(Test_aB_Sf_BFu16s, "aB_Sf_BFu16s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu17i()
{
  {
    init_simple_test("aB_Sf_BFu17i");
    static aB_Sf_BFu17i lv;
    check2(sizeof(lv), 5, "sizeof(aB_Sf_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu17i)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu17i.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu17i.v2");
    set_bf_and_test(lv, v3, 2, 0, 17, 1, "aB_Sf_BFu17i");
    set_bf_and_test(lv, v3, 2, 0, 17, hide_ull(1LL<<16), "aB_Sf_BFu17i");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu17i(Test_aB_Sf_BFu17i, "aB_Sf_BFu17i", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu17ll()
{
  {
    init_simple_test("aB_Sf_BFu17ll");
    static aB_Sf_BFu17ll lv;
    check2(sizeof(lv), 5, "sizeof(aB_Sf_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu17ll)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu17ll.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu17ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 17, 1, "aB_Sf_BFu17ll");
    set_bf_and_test(lv, v3, 2, 0, 17, hide_ull(1LL<<16), "aB_Sf_BFu17ll");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu17ll(Test_aB_Sf_BFu17ll, "aB_Sf_BFu17ll", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu1c()
{
  {
    init_simple_test("aB_Sf_BFu1c");
    static aB_Sf_BFu1c lv;
    check2(sizeof(lv), 3, "sizeof(aB_Sf_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu1c)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu1c.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu1c.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "aB_Sf_BFu1c");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu1c(Test_aB_Sf_BFu1c, "aB_Sf_BFu1c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu1i()
{
  {
    init_simple_test("aB_Sf_BFu1i");
    static aB_Sf_BFu1i lv;
    check2(sizeof(lv), 3, "sizeof(aB_Sf_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu1i)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu1i.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu1i.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "aB_Sf_BFu1i");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu1i(Test_aB_Sf_BFu1i, "aB_Sf_BFu1i", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu1ll()
{
  {
    init_simple_test("aB_Sf_BFu1ll");
    static aB_Sf_BFu1ll lv;
    check2(sizeof(lv), 3, "sizeof(aB_Sf_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu1ll)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu1ll.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu1ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "aB_Sf_BFu1ll");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu1ll(Test_aB_Sf_BFu1ll, "aB_Sf_BFu1ll", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu1s()
{
  {
    init_simple_test("aB_Sf_BFu1s");
    static aB_Sf_BFu1s lv;
    check2(sizeof(lv), 3, "sizeof(aB_Sf_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu1s)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu1s.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu1s.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "aB_Sf_BFu1s");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu1s(Test_aB_Sf_BFu1s, "aB_Sf_BFu1s", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu31i()
{
  {
    init_simple_test("aB_Sf_BFu31i");
    static aB_Sf_BFu31i lv;
    check2(sizeof(lv), 6, "sizeof(aB_Sf_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu31i)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu31i.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu31i.v2");
    set_bf_and_test(lv, v3, 2, 0, 31, 1, "aB_Sf_BFu31i");
    set_bf_and_test(lv, v3, 2, 0, 31, hide_ull(1LL<<30), "aB_Sf_BFu31i");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu31i(Test_aB_Sf_BFu31i, "aB_Sf_BFu31i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu31ll()
{
  {
    init_simple_test("aB_Sf_BFu31ll");
    static aB_Sf_BFu31ll lv;
    check2(sizeof(lv), 6, "sizeof(aB_Sf_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu31ll)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu31ll.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu31ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 31, 1, "aB_Sf_BFu31ll");
    set_bf_and_test(lv, v3, 2, 0, 31, hide_ull(1LL<<30), "aB_Sf_BFu31ll");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu31ll(Test_aB_Sf_BFu31ll, "aB_Sf_BFu31ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu32i()
{
  {
    init_simple_test("aB_Sf_BFu32i");
    static aB_Sf_BFu32i lv;
    check2(sizeof(lv), 6, "sizeof(aB_Sf_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu32i)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu32i.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu32i.v2");
    set_bf_and_test(lv, v3, 2, 0, 32, 1, "aB_Sf_BFu32i");
    set_bf_and_test(lv, v3, 2, 0, 32, hide_ull(1LL<<31), "aB_Sf_BFu32i");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu32i(Test_aB_Sf_BFu32i, "aB_Sf_BFu32i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu32ll()
{
  {
    init_simple_test("aB_Sf_BFu32ll");
    static aB_Sf_BFu32ll lv;
    check2(sizeof(lv), 6, "sizeof(aB_Sf_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu32ll)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu32ll.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu32ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 32, 1, "aB_Sf_BFu32ll");
    set_bf_and_test(lv, v3, 2, 0, 32, hide_ull(1LL<<31), "aB_Sf_BFu32ll");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu32ll(Test_aB_Sf_BFu32ll, "aB_Sf_BFu32ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu33()
{
  {
    init_simple_test("aB_Sf_BFu33");
    static aB_Sf_BFu33 lv;
    check2(sizeof(lv), 7, "sizeof(aB_Sf_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu33)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu33.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu33.v2");
    set_bf_and_test(lv, v3, 2, 0, 33, 1, "aB_Sf_BFu33");
    set_bf_and_test(lv, v3, 2, 0, 33, hide_ull(1LL<<32), "aB_Sf_BFu33");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu33(Test_aB_Sf_BFu33, "aB_Sf_BFu33", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu7c()
{
  {
    init_simple_test("aB_Sf_BFu7c");
    static aB_Sf_BFu7c lv;
    check2(sizeof(lv), 3, "sizeof(aB_Sf_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu7c)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu7c.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu7c.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "aB_Sf_BFu7c");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "aB_Sf_BFu7c");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu7c(Test_aB_Sf_BFu7c, "aB_Sf_BFu7c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu7i()
{
  {
    init_simple_test("aB_Sf_BFu7i");
    static aB_Sf_BFu7i lv;
    check2(sizeof(lv), 3, "sizeof(aB_Sf_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu7i)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu7i.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu7i.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "aB_Sf_BFu7i");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "aB_Sf_BFu7i");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu7i(Test_aB_Sf_BFu7i, "aB_Sf_BFu7i", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu7ll()
{
  {
    init_simple_test("aB_Sf_BFu7ll");
    static aB_Sf_BFu7ll lv;
    check2(sizeof(lv), 3, "sizeof(aB_Sf_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu7ll)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu7ll.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu7ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "aB_Sf_BFu7ll");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "aB_Sf_BFu7ll");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu7ll(Test_aB_Sf_BFu7ll, "aB_Sf_BFu7ll", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu7s()
{
  {
    init_simple_test("aB_Sf_BFu7s");
    static aB_Sf_BFu7s lv;
    check2(sizeof(lv), 3, "sizeof(aB_Sf_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu7s)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu7s.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu7s.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "aB_Sf_BFu7s");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "aB_Sf_BFu7s");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu7s(Test_aB_Sf_BFu7s, "aB_Sf_BFu7s", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu8c()
{
  {
    init_simple_test("aB_Sf_BFu8c");
    static aB_Sf_BFu8c lv;
    check2(sizeof(lv), 3, "sizeof(aB_Sf_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu8c)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu8c.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu8c.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "aB_Sf_BFu8c");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "aB_Sf_BFu8c");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu8c(Test_aB_Sf_BFu8c, "aB_Sf_BFu8c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu8i()
{
  {
    init_simple_test("aB_Sf_BFu8i");
    static aB_Sf_BFu8i lv;
    check2(sizeof(lv), 3, "sizeof(aB_Sf_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu8i)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu8i.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu8i.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "aB_Sf_BFu8i");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "aB_Sf_BFu8i");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu8i(Test_aB_Sf_BFu8i, "aB_Sf_BFu8i", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu8ll()
{
  {
    init_simple_test("aB_Sf_BFu8ll");
    static aB_Sf_BFu8ll lv;
    check2(sizeof(lv), 3, "sizeof(aB_Sf_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu8ll)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu8ll.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu8ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "aB_Sf_BFu8ll");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "aB_Sf_BFu8ll");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu8ll(Test_aB_Sf_BFu8ll, "aB_Sf_BFu8ll", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu8s()
{
  {
    init_simple_test("aB_Sf_BFu8s");
    static aB_Sf_BFu8s lv;
    check2(sizeof(lv), 3, "sizeof(aB_Sf_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu8s)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu8s.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu8s.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "aB_Sf_BFu8s");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "aB_Sf_BFu8s");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu8s(Test_aB_Sf_BFu8s, "aB_Sf_BFu8s", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu9i()
{
  {
    init_simple_test("aB_Sf_BFu9i");
    static aB_Sf_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(aB_Sf_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu9i)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu9i.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu9i.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "aB_Sf_BFu9i");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "aB_Sf_BFu9i");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu9i(Test_aB_Sf_BFu9i, "aB_Sf_BFu9i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu9ll()
{
  {
    init_simple_test("aB_Sf_BFu9ll");
    static aB_Sf_BFu9ll lv;
    check2(sizeof(lv), 4, "sizeof(aB_Sf_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu9ll)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu9ll.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu9ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "aB_Sf_BFu9ll");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "aB_Sf_BFu9ll");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu9ll(Test_aB_Sf_BFu9ll, "aB_Sf_BFu9ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_BFu9s()
{
  {
    init_simple_test("aB_Sf_BFu9s");
    static aB_Sf_BFu9s lv;
    check2(sizeof(lv), 4, "sizeof(aB_Sf_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_BFu9s)");
    check_field_offset(lv, v1, 0, "aB_Sf_BFu9s.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_BFu9s.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "aB_Sf_BFu9s");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "aB_Sf_BFu9s");
  }
}
static Arrange_To_Call_Me vaB_Sf_BFu9s(Test_aB_Sf_BFu9s, "aB_Sf_BFu9s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_C()
{
  {
    init_simple_test("aB_Sf_C");
    aB_Sf_C lv;
    check2(sizeof(lv), 3, "sizeof(aB_Sf_C)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_C)");
    check_field_offset(lv, v1, 0, "aB_Sf_C.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_C.v2");
    check_field_offset(lv, v3, 2, "aB_Sf_C.v3");
  }
}
static Arrange_To_Call_Me vaB_Sf_C(Test_aB_Sf_C, "aB_Sf_C", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_D()
{
  {
    init_simple_test("aB_Sf_D");
    aB_Sf_D lv;
    check2(sizeof(lv), 10, "sizeof(aB_Sf_D)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_D)");
    check_field_offset(lv, v1, 0, "aB_Sf_D.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_D.v2");
    check_field_offset(lv, v3, 2, "aB_Sf_D.v3");
  }
}
static Arrange_To_Call_Me vaB_Sf_D(Test_aB_Sf_D, "aB_Sf_D", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_F()
{
  {
    init_simple_test("aB_Sf_F");
    aB_Sf_F lv;
    check2(sizeof(lv), 6, "sizeof(aB_Sf_F)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_F)");
    check_field_offset(lv, v1, 0, "aB_Sf_F.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_F.v2");
    check_field_offset(lv, v3, 2, "aB_Sf_F.v3");
  }
}
static Arrange_To_Call_Me vaB_Sf_F(Test_aB_Sf_F, "aB_Sf_F", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_I()
{
  {
    init_simple_test("aB_Sf_I");
    aB_Sf_I lv;
    check2(sizeof(lv), 6, "sizeof(aB_Sf_I)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_I)");
    check_field_offset(lv, v1, 0, "aB_Sf_I.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_I.v2");
    check_field_offset(lv, v3, 2, "aB_Sf_I.v3");
  }
}
static Arrange_To_Call_Me vaB_Sf_I(Test_aB_Sf_I, "aB_Sf_I", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_Ip()
{
  {
    init_simple_test("aB_Sf_Ip");
    aB_Sf_Ip lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(aB_Sf_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_Ip)");
    check_field_offset(lv, v1, 0, "aB_Sf_Ip.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_Ip.v2");
    check_field_offset(lv, v3, 2, "aB_Sf_Ip.v3");
  }
}
static Arrange_To_Call_Me vaB_Sf_Ip(Test_aB_Sf_Ip, "aB_Sf_Ip", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_L()
{
  {
    init_simple_test("aB_Sf_L");
    aB_Sf_L lv;
    check2(sizeof(lv), 10, "sizeof(aB_Sf_L)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_L)");
    check_field_offset(lv, v1, 0, "aB_Sf_L.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_L.v2");
    check_field_offset(lv, v3, 2, "aB_Sf_L.v3");
  }
}
static Arrange_To_Call_Me vaB_Sf_L(Test_aB_Sf_L, "aB_Sf_L", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_S()
{
  {
    init_simple_test("aB_Sf_S");
    aB_Sf_S lv;
    check2(sizeof(lv), 4, "sizeof(aB_Sf_S)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_S)");
    check_field_offset(lv, v1, 0, "aB_Sf_S.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_S.v2");
    check_field_offset(lv, v3, 2, "aB_Sf_S.v3");
  }
}
static Arrange_To_Call_Me vaB_Sf_S(Test_aB_Sf_S, "aB_Sf_S", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_Sf()
{
  {
    init_simple_test("aB_Sf_Sf");
    aB_Sf_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aB_Sf_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_Sf)");
    check_field_offset(lv, v1, 0, "aB_Sf_Sf.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_Sf.v2");
    check_field_offset(lv, v3, 2, "aB_Sf_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_Sf_Sf(Test_aB_Sf_Sf, "aB_Sf_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_Uc()
{
  {
    init_simple_test("aB_Sf_Uc");
    aB_Sf_Uc lv;
    check2(sizeof(lv), 3, "sizeof(aB_Sf_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_Uc)");
    check_field_offset(lv, v1, 0, "aB_Sf_Uc.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_Uc.v2");
    check_field_offset(lv, v3, 2, "aB_Sf_Uc.v3");
  }
}
static Arrange_To_Call_Me vaB_Sf_Uc(Test_aB_Sf_Uc, "aB_Sf_Uc", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_Ui()
{
  {
    init_simple_test("aB_Sf_Ui");
    aB_Sf_Ui lv;
    check2(sizeof(lv), 6, "sizeof(aB_Sf_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_Ui)");
    check_field_offset(lv, v1, 0, "aB_Sf_Ui.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_Ui.v2");
    check_field_offset(lv, v3, 2, "aB_Sf_Ui.v3");
  }
}
static Arrange_To_Call_Me vaB_Sf_Ui(Test_aB_Sf_Ui, "aB_Sf_Ui", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_Ul()
{
  {
    init_simple_test("aB_Sf_Ul");
    aB_Sf_Ul lv;
    check2(sizeof(lv), 10, "sizeof(aB_Sf_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_Ul)");
    check_field_offset(lv, v1, 0, "aB_Sf_Ul.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_Ul.v2");
    check_field_offset(lv, v3, 2, "aB_Sf_Ul.v3");
  }
}
static Arrange_To_Call_Me vaB_Sf_Ul(Test_aB_Sf_Ul, "aB_Sf_Ul", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_Us()
{
  {
    init_simple_test("aB_Sf_Us");
    aB_Sf_Us lv;
    check2(sizeof(lv), 4, "sizeof(aB_Sf_Us)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_Us)");
    check_field_offset(lv, v1, 0, "aB_Sf_Us.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_Us.v2");
    check_field_offset(lv, v3, 2, "aB_Sf_Us.v3");
  }
}
static Arrange_To_Call_Me vaB_Sf_Us(Test_aB_Sf_Us, "aB_Sf_Us", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Sf_Vp()
{
  {
    init_simple_test("aB_Sf_Vp");
    aB_Sf_Vp lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(aB_Sf_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Sf_Vp)");
    check_field_offset(lv, v1, 0, "aB_Sf_Vp.v1");
    check_field_offset(lv, v2, 1, "aB_Sf_Vp.v2");
    check_field_offset(lv, v3, 2, "aB_Sf_Vp.v3");
  }
}
static Arrange_To_Call_Me vaB_Sf_Vp(Test_aB_Sf_Vp, "aB_Sf_Vp", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Uc_Sf()
{
  {
    init_simple_test("aB_Uc_Sf");
    aB_Uc_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aB_Uc_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Uc_Sf)");
    check_field_offset(lv, v1, 0, "aB_Uc_Sf.v1");
    check_field_offset(lv, v2, 1, "aB_Uc_Sf.v2");
    check_field_offset(lv, v3, 2, "aB_Uc_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_Uc_Sf(Test_aB_Uc_Sf, "aB_Uc_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Ui_Sf()
{
  {
    init_simple_test("aB_Ui_Sf");
    aB_Ui_Sf lv;
    check2(sizeof(lv), 6, "sizeof(aB_Ui_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Ui_Sf)");
    check_field_offset(lv, v1, 0, "aB_Ui_Sf.v1");
    check_field_offset(lv, v2, 1, "aB_Ui_Sf.v2");
    check_field_offset(lv, v3, 5, "aB_Ui_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_Ui_Sf(Test_aB_Ui_Sf, "aB_Ui_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Ul_Sf()
{
  {
    init_simple_test("aB_Ul_Sf");
    aB_Ul_Sf lv;
    check2(sizeof(lv), 10, "sizeof(aB_Ul_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Ul_Sf)");
    check_field_offset(lv, v1, 0, "aB_Ul_Sf.v1");
    check_field_offset(lv, v2, 1, "aB_Ul_Sf.v2");
    check_field_offset(lv, v3, 9, "aB_Ul_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_Ul_Sf(Test_aB_Ul_Sf, "aB_Ul_Sf", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Us_Sf()
{
  {
    init_simple_test("aB_Us_Sf");
    aB_Us_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aB_Us_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Us_Sf)");
    check_field_offset(lv, v1, 0, "aB_Us_Sf.v1");
    check_field_offset(lv, v2, 1, "aB_Us_Sf.v2");
    check_field_offset(lv, v3, 3, "aB_Us_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_Us_Sf(Test_aB_Us_Sf, "aB_Us_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aB_Vp_Sf()
{
  {
    init_simple_test("aB_Vp_Sf");
    aB_Vp_Sf lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(aB_Vp_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aB_Vp_Sf)");
    check_field_offset(lv, v1, 0, "aB_Vp_Sf.v1");
    check_field_offset(lv, v2, 1, "aB_Vp_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "aB_Vp_Sf.v3");
  }
}
static Arrange_To_Call_Me vaB_Vp_Sf(Test_aB_Vp_Sf, "aB_Vp_Sf", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu15i_B_Sf()
{
  {
    init_simple_test("aBFu15i_B_Sf");
    static aBFu15i_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aBFu15i_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu15i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "aBFu15i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "aBFu15i_B_Sf");
    check_field_offset(lv, v2, 2, "aBFu15i_B_Sf.v2");
    check_field_offset(lv, v3, 3, "aBFu15i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu15i_B_Sf(Test_aBFu15i_B_Sf, "aBFu15i_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu15i_Sf_B()
{
  {
    init_simple_test("aBFu15i_Sf_B");
    static aBFu15i_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(aBFu15i_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu15i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "aBFu15i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "aBFu15i_Sf_B");
    check_field_offset(lv, v2, 2, "aBFu15i_Sf_B.v2");
    check_field_offset(lv, v3, 3, "aBFu15i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu15i_Sf_B(Test_aBFu15i_Sf_B, "aBFu15i_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu15ll_B_Sf()
{
  {
    init_simple_test("aBFu15ll_B_Sf");
    static aBFu15ll_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aBFu15ll_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu15ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "aBFu15ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "aBFu15ll_B_Sf");
    check_field_offset(lv, v2, 2, "aBFu15ll_B_Sf.v2");
    check_field_offset(lv, v3, 3, "aBFu15ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu15ll_B_Sf(Test_aBFu15ll_B_Sf, "aBFu15ll_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu15ll_Sf_B()
{
  {
    init_simple_test("aBFu15ll_Sf_B");
    static aBFu15ll_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(aBFu15ll_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu15ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "aBFu15ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "aBFu15ll_Sf_B");
    check_field_offset(lv, v2, 2, "aBFu15ll_Sf_B.v2");
    check_field_offset(lv, v3, 3, "aBFu15ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu15ll_Sf_B(Test_aBFu15ll_Sf_B, "aBFu15ll_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu15s_B_Sf()
{
  {
    init_simple_test("aBFu15s_B_Sf");
    static aBFu15s_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aBFu15s_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu15s_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "aBFu15s_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "aBFu15s_B_Sf");
    check_field_offset(lv, v2, 2, "aBFu15s_B_Sf.v2");
    check_field_offset(lv, v3, 3, "aBFu15s_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu15s_B_Sf(Test_aBFu15s_B_Sf, "aBFu15s_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu15s_Sf_B()
{
  {
    init_simple_test("aBFu15s_Sf_B");
    static aBFu15s_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(aBFu15s_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu15s_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "aBFu15s_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "aBFu15s_Sf_B");
    check_field_offset(lv, v2, 2, "aBFu15s_Sf_B.v2");
    check_field_offset(lv, v3, 3, "aBFu15s_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu15s_Sf_B(Test_aBFu15s_Sf_B, "aBFu15s_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu16i_B_Sf()
{
  {
    init_simple_test("aBFu16i_B_Sf");
    static aBFu16i_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aBFu16i_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu16i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "aBFu16i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "aBFu16i_B_Sf");
    check_field_offset(lv, v2, 2, "aBFu16i_B_Sf.v2");
    check_field_offset(lv, v3, 3, "aBFu16i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu16i_B_Sf(Test_aBFu16i_B_Sf, "aBFu16i_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu16i_Sf_B()
{
  {
    init_simple_test("aBFu16i_Sf_B");
    static aBFu16i_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(aBFu16i_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu16i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "aBFu16i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "aBFu16i_Sf_B");
    check_field_offset(lv, v2, 2, "aBFu16i_Sf_B.v2");
    check_field_offset(lv, v3, 3, "aBFu16i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu16i_Sf_B(Test_aBFu16i_Sf_B, "aBFu16i_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu16ll_B_Sf()
{
  {
    init_simple_test("aBFu16ll_B_Sf");
    static aBFu16ll_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aBFu16ll_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu16ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "aBFu16ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "aBFu16ll_B_Sf");
    check_field_offset(lv, v2, 2, "aBFu16ll_B_Sf.v2");
    check_field_offset(lv, v3, 3, "aBFu16ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu16ll_B_Sf(Test_aBFu16ll_B_Sf, "aBFu16ll_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu16ll_Sf_B()
{
  {
    init_simple_test("aBFu16ll_Sf_B");
    static aBFu16ll_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(aBFu16ll_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu16ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "aBFu16ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "aBFu16ll_Sf_B");
    check_field_offset(lv, v2, 2, "aBFu16ll_Sf_B.v2");
    check_field_offset(lv, v3, 3, "aBFu16ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu16ll_Sf_B(Test_aBFu16ll_Sf_B, "aBFu16ll_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu16s_B_Sf()
{
  {
    init_simple_test("aBFu16s_B_Sf");
    static aBFu16s_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aBFu16s_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu16s_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "aBFu16s_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "aBFu16s_B_Sf");
    check_field_offset(lv, v2, 2, "aBFu16s_B_Sf.v2");
    check_field_offset(lv, v3, 3, "aBFu16s_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu16s_B_Sf(Test_aBFu16s_B_Sf, "aBFu16s_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu16s_Sf_B()
{
  {
    init_simple_test("aBFu16s_Sf_B");
    static aBFu16s_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(aBFu16s_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu16s_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "aBFu16s_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "aBFu16s_Sf_B");
    check_field_offset(lv, v2, 2, "aBFu16s_Sf_B.v2");
    check_field_offset(lv, v3, 3, "aBFu16s_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu16s_Sf_B(Test_aBFu16s_Sf_B, "aBFu16s_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu17i_B_Sf()
{
  {
    init_simple_test("aBFu17i_B_Sf");
    static aBFu17i_B_Sf lv;
    check2(sizeof(lv), 5, "sizeof(aBFu17i_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu17i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "aBFu17i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "aBFu17i_B_Sf");
    check_field_offset(lv, v2, 3, "aBFu17i_B_Sf.v2");
    check_field_offset(lv, v3, 4, "aBFu17i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu17i_B_Sf(Test_aBFu17i_B_Sf, "aBFu17i_B_Sf", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu17i_Sf_B()
{
  {
    init_simple_test("aBFu17i_Sf_B");
    static aBFu17i_Sf_B lv;
    check2(sizeof(lv), 5, "sizeof(aBFu17i_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu17i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "aBFu17i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "aBFu17i_Sf_B");
    check_field_offset(lv, v2, 3, "aBFu17i_Sf_B.v2");
    check_field_offset(lv, v3, 4, "aBFu17i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu17i_Sf_B(Test_aBFu17i_Sf_B, "aBFu17i_Sf_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu17ll_B_Sf()
{
  {
    init_simple_test("aBFu17ll_B_Sf");
    static aBFu17ll_B_Sf lv;
    check2(sizeof(lv), 5, "sizeof(aBFu17ll_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu17ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "aBFu17ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "aBFu17ll_B_Sf");
    check_field_offset(lv, v2, 3, "aBFu17ll_B_Sf.v2");
    check_field_offset(lv, v3, 4, "aBFu17ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu17ll_B_Sf(Test_aBFu17ll_B_Sf, "aBFu17ll_B_Sf", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu17ll_Sf_B()
{
  {
    init_simple_test("aBFu17ll_Sf_B");
    static aBFu17ll_Sf_B lv;
    check2(sizeof(lv), 5, "sizeof(aBFu17ll_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu17ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "aBFu17ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "aBFu17ll_Sf_B");
    check_field_offset(lv, v2, 3, "aBFu17ll_Sf_B.v2");
    check_field_offset(lv, v3, 4, "aBFu17ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu17ll_Sf_B(Test_aBFu17ll_Sf_B, "aBFu17ll_Sf_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu1c_B_Sf()
{
  {
    init_simple_test("aBFu1c_B_Sf");
    static aBFu1c_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aBFu1c_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu1c_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "aBFu1c_B_Sf");
    check_field_offset(lv, v2, 1, "aBFu1c_B_Sf.v2");
    check_field_offset(lv, v3, 2, "aBFu1c_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu1c_B_Sf(Test_aBFu1c_B_Sf, "aBFu1c_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu1c_Sf_B()
{
  {
    init_simple_test("aBFu1c_Sf_B");
    static aBFu1c_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(aBFu1c_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu1c_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "aBFu1c_Sf_B");
    check_field_offset(lv, v2, 1, "aBFu1c_Sf_B.v2");
    check_field_offset(lv, v3, 2, "aBFu1c_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu1c_Sf_B(Test_aBFu1c_Sf_B, "aBFu1c_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu1i_B_Sf()
{
  {
    init_simple_test("aBFu1i_B_Sf");
    static aBFu1i_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aBFu1i_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu1i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "aBFu1i_B_Sf");
    check_field_offset(lv, v2, 1, "aBFu1i_B_Sf.v2");
    check_field_offset(lv, v3, 2, "aBFu1i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu1i_B_Sf(Test_aBFu1i_B_Sf, "aBFu1i_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu1i_Sf_B()
{
  {
    init_simple_test("aBFu1i_Sf_B");
    static aBFu1i_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(aBFu1i_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu1i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "aBFu1i_Sf_B");
    check_field_offset(lv, v2, 1, "aBFu1i_Sf_B.v2");
    check_field_offset(lv, v3, 2, "aBFu1i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu1i_Sf_B(Test_aBFu1i_Sf_B, "aBFu1i_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu1ll_B_Sf()
{
  {
    init_simple_test("aBFu1ll_B_Sf");
    static aBFu1ll_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aBFu1ll_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu1ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "aBFu1ll_B_Sf");
    check_field_offset(lv, v2, 1, "aBFu1ll_B_Sf.v2");
    check_field_offset(lv, v3, 2, "aBFu1ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu1ll_B_Sf(Test_aBFu1ll_B_Sf, "aBFu1ll_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu1ll_Sf_B()
{
  {
    init_simple_test("aBFu1ll_Sf_B");
    static aBFu1ll_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(aBFu1ll_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu1ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "aBFu1ll_Sf_B");
    check_field_offset(lv, v2, 1, "aBFu1ll_Sf_B.v2");
    check_field_offset(lv, v3, 2, "aBFu1ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu1ll_Sf_B(Test_aBFu1ll_Sf_B, "aBFu1ll_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu1s_B_Sf()
{
  {
    init_simple_test("aBFu1s_B_Sf");
    static aBFu1s_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aBFu1s_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu1s_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "aBFu1s_B_Sf");
    check_field_offset(lv, v2, 1, "aBFu1s_B_Sf.v2");
    check_field_offset(lv, v3, 2, "aBFu1s_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu1s_B_Sf(Test_aBFu1s_B_Sf, "aBFu1s_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu1s_Sf_B()
{
  {
    init_simple_test("aBFu1s_Sf_B");
    static aBFu1s_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(aBFu1s_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu1s_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "aBFu1s_Sf_B");
    check_field_offset(lv, v2, 1, "aBFu1s_Sf_B.v2");
    check_field_offset(lv, v3, 2, "aBFu1s_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu1s_Sf_B(Test_aBFu1s_Sf_B, "aBFu1s_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu31i_B_Sf()
{
  {
    init_simple_test("aBFu31i_B_Sf");
    static aBFu31i_B_Sf lv;
    check2(sizeof(lv), 6, "sizeof(aBFu31i_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu31i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "aBFu31i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "aBFu31i_B_Sf");
    check_field_offset(lv, v2, 4, "aBFu31i_B_Sf.v2");
    check_field_offset(lv, v3, 5, "aBFu31i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu31i_B_Sf(Test_aBFu31i_B_Sf, "aBFu31i_B_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu31i_Sf_B()
{
  {
    init_simple_test("aBFu31i_Sf_B");
    static aBFu31i_Sf_B lv;
    check2(sizeof(lv), 6, "sizeof(aBFu31i_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu31i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "aBFu31i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "aBFu31i_Sf_B");
    check_field_offset(lv, v2, 4, "aBFu31i_Sf_B.v2");
    check_field_offset(lv, v3, 5, "aBFu31i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu31i_Sf_B(Test_aBFu31i_Sf_B, "aBFu31i_Sf_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu31ll_B_Sf()
{
  {
    init_simple_test("aBFu31ll_B_Sf");
    static aBFu31ll_B_Sf lv;
    check2(sizeof(lv), 6, "sizeof(aBFu31ll_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu31ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "aBFu31ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "aBFu31ll_B_Sf");
    check_field_offset(lv, v2, 4, "aBFu31ll_B_Sf.v2");
    check_field_offset(lv, v3, 5, "aBFu31ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu31ll_B_Sf(Test_aBFu31ll_B_Sf, "aBFu31ll_B_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu31ll_Sf_B()
{
  {
    init_simple_test("aBFu31ll_Sf_B");
    static aBFu31ll_Sf_B lv;
    check2(sizeof(lv), 6, "sizeof(aBFu31ll_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu31ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "aBFu31ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "aBFu31ll_Sf_B");
    check_field_offset(lv, v2, 4, "aBFu31ll_Sf_B.v2");
    check_field_offset(lv, v3, 5, "aBFu31ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu31ll_Sf_B(Test_aBFu31ll_Sf_B, "aBFu31ll_Sf_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu32i_B_Sf()
{
  {
    init_simple_test("aBFu32i_B_Sf");
    static aBFu32i_B_Sf lv;
    check2(sizeof(lv), 6, "sizeof(aBFu32i_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu32i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "aBFu32i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "aBFu32i_B_Sf");
    check_field_offset(lv, v2, 4, "aBFu32i_B_Sf.v2");
    check_field_offset(lv, v3, 5, "aBFu32i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu32i_B_Sf(Test_aBFu32i_B_Sf, "aBFu32i_B_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu32i_Sf_B()
{
  {
    init_simple_test("aBFu32i_Sf_B");
    static aBFu32i_Sf_B lv;
    check2(sizeof(lv), 6, "sizeof(aBFu32i_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu32i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "aBFu32i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "aBFu32i_Sf_B");
    check_field_offset(lv, v2, 4, "aBFu32i_Sf_B.v2");
    check_field_offset(lv, v3, 5, "aBFu32i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu32i_Sf_B(Test_aBFu32i_Sf_B, "aBFu32i_Sf_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu32ll_B_Sf()
{
  {
    init_simple_test("aBFu32ll_B_Sf");
    static aBFu32ll_B_Sf lv;
    check2(sizeof(lv), 6, "sizeof(aBFu32ll_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu32ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "aBFu32ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "aBFu32ll_B_Sf");
    check_field_offset(lv, v2, 4, "aBFu32ll_B_Sf.v2");
    check_field_offset(lv, v3, 5, "aBFu32ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu32ll_B_Sf(Test_aBFu32ll_B_Sf, "aBFu32ll_B_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu32ll_Sf_B()
{
  {
    init_simple_test("aBFu32ll_Sf_B");
    static aBFu32ll_Sf_B lv;
    check2(sizeof(lv), 6, "sizeof(aBFu32ll_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu32ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "aBFu32ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "aBFu32ll_Sf_B");
    check_field_offset(lv, v2, 4, "aBFu32ll_Sf_B.v2");
    check_field_offset(lv, v3, 5, "aBFu32ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu32ll_Sf_B(Test_aBFu32ll_Sf_B, "aBFu32ll_Sf_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu33_B_Sf()
{
  {
    init_simple_test("aBFu33_B_Sf");
    static aBFu33_B_Sf lv;
    check2(sizeof(lv), 7, "sizeof(aBFu33_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu33_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "aBFu33_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "aBFu33_B_Sf");
    check_field_offset(lv, v2, 5, "aBFu33_B_Sf.v2");
    check_field_offset(lv, v3, 6, "aBFu33_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu33_B_Sf(Test_aBFu33_B_Sf, "aBFu33_B_Sf", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu33_Sf_B()
{
  {
    init_simple_test("aBFu33_Sf_B");
    static aBFu33_Sf_B lv;
    check2(sizeof(lv), 7, "sizeof(aBFu33_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu33_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "aBFu33_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "aBFu33_Sf_B");
    check_field_offset(lv, v2, 5, "aBFu33_Sf_B.v2");
    check_field_offset(lv, v3, 6, "aBFu33_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu33_Sf_B(Test_aBFu33_Sf_B, "aBFu33_Sf_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu7c_B_Sf()
{
  {
    init_simple_test("aBFu7c_B_Sf");
    static aBFu7c_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aBFu7c_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu7c_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "aBFu7c_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "aBFu7c_B_Sf");
    check_field_offset(lv, v2, 1, "aBFu7c_B_Sf.v2");
    check_field_offset(lv, v3, 2, "aBFu7c_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu7c_B_Sf(Test_aBFu7c_B_Sf, "aBFu7c_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu7c_Sf_B()
{
  {
    init_simple_test("aBFu7c_Sf_B");
    static aBFu7c_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(aBFu7c_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu7c_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "aBFu7c_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "aBFu7c_Sf_B");
    check_field_offset(lv, v2, 1, "aBFu7c_Sf_B.v2");
    check_field_offset(lv, v3, 2, "aBFu7c_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu7c_Sf_B(Test_aBFu7c_Sf_B, "aBFu7c_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu7i_B_Sf()
{
  {
    init_simple_test("aBFu7i_B_Sf");
    static aBFu7i_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aBFu7i_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu7i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "aBFu7i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "aBFu7i_B_Sf");
    check_field_offset(lv, v2, 1, "aBFu7i_B_Sf.v2");
    check_field_offset(lv, v3, 2, "aBFu7i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu7i_B_Sf(Test_aBFu7i_B_Sf, "aBFu7i_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu7i_Sf_B()
{
  {
    init_simple_test("aBFu7i_Sf_B");
    static aBFu7i_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(aBFu7i_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu7i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "aBFu7i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "aBFu7i_Sf_B");
    check_field_offset(lv, v2, 1, "aBFu7i_Sf_B.v2");
    check_field_offset(lv, v3, 2, "aBFu7i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu7i_Sf_B(Test_aBFu7i_Sf_B, "aBFu7i_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu7ll_B_Sf()
{
  {
    init_simple_test("aBFu7ll_B_Sf");
    static aBFu7ll_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aBFu7ll_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu7ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "aBFu7ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "aBFu7ll_B_Sf");
    check_field_offset(lv, v2, 1, "aBFu7ll_B_Sf.v2");
    check_field_offset(lv, v3, 2, "aBFu7ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu7ll_B_Sf(Test_aBFu7ll_B_Sf, "aBFu7ll_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu7ll_Sf_B()
{
  {
    init_simple_test("aBFu7ll_Sf_B");
    static aBFu7ll_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(aBFu7ll_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu7ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "aBFu7ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "aBFu7ll_Sf_B");
    check_field_offset(lv, v2, 1, "aBFu7ll_Sf_B.v2");
    check_field_offset(lv, v3, 2, "aBFu7ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu7ll_Sf_B(Test_aBFu7ll_Sf_B, "aBFu7ll_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu7s_B_Sf()
{
  {
    init_simple_test("aBFu7s_B_Sf");
    static aBFu7s_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aBFu7s_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu7s_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "aBFu7s_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "aBFu7s_B_Sf");
    check_field_offset(lv, v2, 1, "aBFu7s_B_Sf.v2");
    check_field_offset(lv, v3, 2, "aBFu7s_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu7s_B_Sf(Test_aBFu7s_B_Sf, "aBFu7s_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu7s_Sf_B()
{
  {
    init_simple_test("aBFu7s_Sf_B");
    static aBFu7s_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(aBFu7s_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu7s_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "aBFu7s_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "aBFu7s_Sf_B");
    check_field_offset(lv, v2, 1, "aBFu7s_Sf_B.v2");
    check_field_offset(lv, v3, 2, "aBFu7s_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu7s_Sf_B(Test_aBFu7s_Sf_B, "aBFu7s_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu8c_B_Sf()
{
  {
    init_simple_test("aBFu8c_B_Sf");
    static aBFu8c_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aBFu8c_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu8c_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "aBFu8c_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "aBFu8c_B_Sf");
    check_field_offset(lv, v2, 1, "aBFu8c_B_Sf.v2");
    check_field_offset(lv, v3, 2, "aBFu8c_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu8c_B_Sf(Test_aBFu8c_B_Sf, "aBFu8c_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu8c_Sf_B()
{
  {
    init_simple_test("aBFu8c_Sf_B");
    static aBFu8c_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(aBFu8c_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu8c_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "aBFu8c_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "aBFu8c_Sf_B");
    check_field_offset(lv, v2, 1, "aBFu8c_Sf_B.v2");
    check_field_offset(lv, v3, 2, "aBFu8c_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu8c_Sf_B(Test_aBFu8c_Sf_B, "aBFu8c_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu8i_B_Sf()
{
  {
    init_simple_test("aBFu8i_B_Sf");
    static aBFu8i_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aBFu8i_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu8i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "aBFu8i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "aBFu8i_B_Sf");
    check_field_offset(lv, v2, 1, "aBFu8i_B_Sf.v2");
    check_field_offset(lv, v3, 2, "aBFu8i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu8i_B_Sf(Test_aBFu8i_B_Sf, "aBFu8i_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu8i_Sf_B()
{
  {
    init_simple_test("aBFu8i_Sf_B");
    static aBFu8i_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(aBFu8i_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu8i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "aBFu8i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "aBFu8i_Sf_B");
    check_field_offset(lv, v2, 1, "aBFu8i_Sf_B.v2");
    check_field_offset(lv, v3, 2, "aBFu8i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu8i_Sf_B(Test_aBFu8i_Sf_B, "aBFu8i_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu8ll_B_Sf()
{
  {
    init_simple_test("aBFu8ll_B_Sf");
    static aBFu8ll_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aBFu8ll_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu8ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "aBFu8ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "aBFu8ll_B_Sf");
    check_field_offset(lv, v2, 1, "aBFu8ll_B_Sf.v2");
    check_field_offset(lv, v3, 2, "aBFu8ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu8ll_B_Sf(Test_aBFu8ll_B_Sf, "aBFu8ll_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu8ll_Sf_B()
{
  {
    init_simple_test("aBFu8ll_Sf_B");
    static aBFu8ll_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(aBFu8ll_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu8ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "aBFu8ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "aBFu8ll_Sf_B");
    check_field_offset(lv, v2, 1, "aBFu8ll_Sf_B.v2");
    check_field_offset(lv, v3, 2, "aBFu8ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu8ll_Sf_B(Test_aBFu8ll_Sf_B, "aBFu8ll_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu8s_B_Sf()
{
  {
    init_simple_test("aBFu8s_B_Sf");
    static aBFu8s_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aBFu8s_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu8s_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "aBFu8s_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "aBFu8s_B_Sf");
    check_field_offset(lv, v2, 1, "aBFu8s_B_Sf.v2");
    check_field_offset(lv, v3, 2, "aBFu8s_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu8s_B_Sf(Test_aBFu8s_B_Sf, "aBFu8s_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu8s_Sf_B()
{
  {
    init_simple_test("aBFu8s_Sf_B");
    static aBFu8s_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(aBFu8s_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu8s_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "aBFu8s_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "aBFu8s_Sf_B");
    check_field_offset(lv, v2, 1, "aBFu8s_Sf_B.v2");
    check_field_offset(lv, v3, 2, "aBFu8s_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu8s_Sf_B(Test_aBFu8s_Sf_B, "aBFu8s_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu9i_B_Sf()
{
  {
    init_simple_test("aBFu9i_B_Sf");
    static aBFu9i_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aBFu9i_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu9i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "aBFu9i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "aBFu9i_B_Sf");
    check_field_offset(lv, v2, 2, "aBFu9i_B_Sf.v2");
    check_field_offset(lv, v3, 3, "aBFu9i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu9i_B_Sf(Test_aBFu9i_B_Sf, "aBFu9i_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu9i_Sf_B()
{
  {
    init_simple_test("aBFu9i_Sf_B");
    static aBFu9i_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(aBFu9i_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu9i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "aBFu9i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "aBFu9i_Sf_B");
    check_field_offset(lv, v2, 2, "aBFu9i_Sf_B.v2");
    check_field_offset(lv, v3, 3, "aBFu9i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu9i_Sf_B(Test_aBFu9i_Sf_B, "aBFu9i_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu9ll_B_Sf()
{
  {
    init_simple_test("aBFu9ll_B_Sf");
    static aBFu9ll_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aBFu9ll_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu9ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "aBFu9ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "aBFu9ll_B_Sf");
    check_field_offset(lv, v2, 2, "aBFu9ll_B_Sf.v2");
    check_field_offset(lv, v3, 3, "aBFu9ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu9ll_B_Sf(Test_aBFu9ll_B_Sf, "aBFu9ll_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu9ll_Sf_B()
{
  {
    init_simple_test("aBFu9ll_Sf_B");
    static aBFu9ll_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(aBFu9ll_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu9ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "aBFu9ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "aBFu9ll_Sf_B");
    check_field_offset(lv, v2, 2, "aBFu9ll_Sf_B.v2");
    check_field_offset(lv, v3, 3, "aBFu9ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu9ll_Sf_B(Test_aBFu9ll_Sf_B, "aBFu9ll_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu9s_B_Sf()
{
  {
    init_simple_test("aBFu9s_B_Sf");
    static aBFu9s_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aBFu9s_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu9s_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "aBFu9s_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "aBFu9s_B_Sf");
    check_field_offset(lv, v2, 2, "aBFu9s_B_Sf.v2");
    check_field_offset(lv, v3, 3, "aBFu9s_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaBFu9s_B_Sf(Test_aBFu9s_B_Sf, "aBFu9s_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aBFu9s_Sf_B()
{
  {
    init_simple_test("aBFu9s_Sf_B");
    static aBFu9s_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(aBFu9s_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aBFu9s_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "aBFu9s_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "aBFu9s_Sf_B");
    check_field_offset(lv, v2, 2, "aBFu9s_Sf_B.v2");
    check_field_offset(lv, v3, 3, "aBFu9s_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaBFu9s_Sf_B(Test_aBFu9s_Sf_B, "aBFu9s_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aC_B_Sf()
{
  {
    init_simple_test("aC_B_Sf");
    aC_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aC_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aC_B_Sf)");
    check_field_offset(lv, v1, 0, "aC_B_Sf.v1");
    check_field_offset(lv, v2, 1, "aC_B_Sf.v2");
    check_field_offset(lv, v3, 2, "aC_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaC_B_Sf(Test_aC_B_Sf, "aC_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aC_Sf_B()
{
  {
    init_simple_test("aC_Sf_B");
    aC_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(aC_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aC_Sf_B)");
    check_field_offset(lv, v1, 0, "aC_Sf_B.v1");
    check_field_offset(lv, v2, 1, "aC_Sf_B.v2");
    check_field_offset(lv, v3, 2, "aC_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaC_Sf_B(Test_aC_Sf_B, "aC_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aD_B_Sf()
{
  {
    init_simple_test("aD_B_Sf");
    aD_B_Sf lv;
    check2(sizeof(lv), 10, "sizeof(aD_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aD_B_Sf)");
    check_field_offset(lv, v1, 0, "aD_B_Sf.v1");
    check_field_offset(lv, v2, 8, "aD_B_Sf.v2");
    check_field_offset(lv, v3, 9, "aD_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaD_B_Sf(Test_aD_B_Sf, "aD_B_Sf", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aD_Sf_B()
{
  {
    init_simple_test("aD_Sf_B");
    aD_Sf_B lv;
    check2(sizeof(lv), 10, "sizeof(aD_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aD_Sf_B)");
    check_field_offset(lv, v1, 0, "aD_Sf_B.v1");
    check_field_offset(lv, v2, 8, "aD_Sf_B.v2");
    check_field_offset(lv, v3, 9, "aD_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaD_Sf_B(Test_aD_Sf_B, "aD_Sf_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aF_B_Sf()
{
  {
    init_simple_test("aF_B_Sf");
    aF_B_Sf lv;
    check2(sizeof(lv), 6, "sizeof(aF_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aF_B_Sf)");
    check_field_offset(lv, v1, 0, "aF_B_Sf.v1");
    check_field_offset(lv, v2, 4, "aF_B_Sf.v2");
    check_field_offset(lv, v3, 5, "aF_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaF_B_Sf(Test_aF_B_Sf, "aF_B_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aF_Sf_B()
{
  {
    init_simple_test("aF_Sf_B");
    aF_Sf_B lv;
    check2(sizeof(lv), 6, "sizeof(aF_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aF_Sf_B)");
    check_field_offset(lv, v1, 0, "aF_Sf_B.v1");
    check_field_offset(lv, v2, 4, "aF_Sf_B.v2");
    check_field_offset(lv, v3, 5, "aF_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaF_Sf_B(Test_aF_Sf_B, "aF_Sf_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aI_B_Sf()
{
  {
    init_simple_test("aI_B_Sf");
    aI_B_Sf lv;
    check2(sizeof(lv), 6, "sizeof(aI_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aI_B_Sf)");
    check_field_offset(lv, v1, 0, "aI_B_Sf.v1");
    check_field_offset(lv, v2, 4, "aI_B_Sf.v2");
    check_field_offset(lv, v3, 5, "aI_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaI_B_Sf(Test_aI_B_Sf, "aI_B_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aI_Sf_B()
{
  {
    init_simple_test("aI_Sf_B");
    aI_Sf_B lv;
    check2(sizeof(lv), 6, "sizeof(aI_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aI_Sf_B)");
    check_field_offset(lv, v1, 0, "aI_Sf_B.v1");
    check_field_offset(lv, v2, 4, "aI_Sf_B.v2");
    check_field_offset(lv, v3, 5, "aI_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaI_Sf_B(Test_aI_Sf_B, "aI_Sf_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aIp_B_Sf()
{
  {
    init_simple_test("aIp_B_Sf");
    aIp_B_Sf lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(aIp_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aIp_B_Sf)");
    check_field_offset(lv, v1, 0, "aIp_B_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "aIp_B_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "aIp_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaIp_B_Sf(Test_aIp_B_Sf, "aIp_B_Sf", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aIp_Sf_B()
{
  {
    init_simple_test("aIp_Sf_B");
    aIp_Sf_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(aIp_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aIp_Sf_B)");
    check_field_offset(lv, v1, 0, "aIp_Sf_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "aIp_Sf_B.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "aIp_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaIp_Sf_B(Test_aIp_Sf_B, "aIp_Sf_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aL_B_Sf()
{
  {
    init_simple_test("aL_B_Sf");
    aL_B_Sf lv;
    check2(sizeof(lv), 10, "sizeof(aL_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aL_B_Sf)");
    check_field_offset(lv, v1, 0, "aL_B_Sf.v1");
    check_field_offset(lv, v2, 8, "aL_B_Sf.v2");
    check_field_offset(lv, v3, 9, "aL_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaL_B_Sf(Test_aL_B_Sf, "aL_B_Sf", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aL_Sf_B()
{
  {
    init_simple_test("aL_Sf_B");
    aL_Sf_B lv;
    check2(sizeof(lv), 10, "sizeof(aL_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aL_Sf_B)");
    check_field_offset(lv, v1, 0, "aL_Sf_B.v1");
    check_field_offset(lv, v2, 8, "aL_Sf_B.v2");
    check_field_offset(lv, v3, 9, "aL_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaL_Sf_B(Test_aL_Sf_B, "aL_Sf_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aS_B_Sf()
{
  {
    init_simple_test("aS_B_Sf");
    aS_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aS_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aS_B_Sf)");
    check_field_offset(lv, v1, 0, "aS_B_Sf.v1");
    check_field_offset(lv, v2, 2, "aS_B_Sf.v2");
    check_field_offset(lv, v3, 3, "aS_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaS_B_Sf(Test_aS_B_Sf, "aS_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aS_Sf_B()
{
  {
    init_simple_test("aS_Sf_B");
    aS_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(aS_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aS_Sf_B)");
    check_field_offset(lv, v1, 0, "aS_Sf_B.v1");
    check_field_offset(lv, v2, 2, "aS_Sf_B.v2");
    check_field_offset(lv, v3, 3, "aS_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaS_Sf_B(Test_aS_Sf_B, "aS_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B()
{
  {
    init_simple_test("aSf_B");
    aSf_B lv;
    check2(sizeof(lv), 2, "sizeof(aSf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B)");
    check_field_offset(lv, v1, 0, "aSf_B.v1");
    check_field_offset(lv, v2, 1, "aSf_B.v2");
  }
}
static Arrange_To_Call_Me vaSf_B(Test_aSf_B, "aSf_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_B()
{
  {
    init_simple_test("aSf_B_B");
    aSf_B_B lv;
    check2(sizeof(lv), 3, "sizeof(aSf_B_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_B)");
    check_field_offset(lv, v1, 0, "aSf_B_B.v1");
    check_field_offset(lv, v2, 1, "aSf_B_B.v2");
    check_field_offset(lv, v3, 2, "aSf_B_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_B_B(Test_aSf_B_B, "aSf_B_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu15i()
{
  {
    init_simple_test("aSf_B_BFu15i");
    static aSf_B_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(aSf_B_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu15i)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu15i.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu15i.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "aSf_B_BFu15i");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "aSf_B_BFu15i");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu15i(Test_aSf_B_BFu15i, "aSf_B_BFu15i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu15ll()
{
  {
    init_simple_test("aSf_B_BFu15ll");
    static aSf_B_BFu15ll lv;
    check2(sizeof(lv), 4, "sizeof(aSf_B_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu15ll)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu15ll.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu15ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "aSf_B_BFu15ll");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "aSf_B_BFu15ll");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu15ll(Test_aSf_B_BFu15ll, "aSf_B_BFu15ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu15s()
{
  {
    init_simple_test("aSf_B_BFu15s");
    static aSf_B_BFu15s lv;
    check2(sizeof(lv), 4, "sizeof(aSf_B_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu15s)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu15s.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu15s.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "aSf_B_BFu15s");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "aSf_B_BFu15s");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu15s(Test_aSf_B_BFu15s, "aSf_B_BFu15s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu16i()
{
  {
    init_simple_test("aSf_B_BFu16i");
    static aSf_B_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(aSf_B_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu16i)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu16i.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu16i.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "aSf_B_BFu16i");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "aSf_B_BFu16i");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu16i(Test_aSf_B_BFu16i, "aSf_B_BFu16i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu16ll()
{
  {
    init_simple_test("aSf_B_BFu16ll");
    static aSf_B_BFu16ll lv;
    check2(sizeof(lv), 4, "sizeof(aSf_B_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu16ll)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu16ll.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu16ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "aSf_B_BFu16ll");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "aSf_B_BFu16ll");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu16ll(Test_aSf_B_BFu16ll, "aSf_B_BFu16ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu16s()
{
  {
    init_simple_test("aSf_B_BFu16s");
    static aSf_B_BFu16s lv;
    check2(sizeof(lv), 4, "sizeof(aSf_B_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu16s)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu16s.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu16s.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "aSf_B_BFu16s");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "aSf_B_BFu16s");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu16s(Test_aSf_B_BFu16s, "aSf_B_BFu16s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu17i()
{
  {
    init_simple_test("aSf_B_BFu17i");
    static aSf_B_BFu17i lv;
    check2(sizeof(lv), 5, "sizeof(aSf_B_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu17i)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu17i.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu17i.v2");
    set_bf_and_test(lv, v3, 2, 0, 17, 1, "aSf_B_BFu17i");
    set_bf_and_test(lv, v3, 2, 0, 17, hide_ull(1LL<<16), "aSf_B_BFu17i");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu17i(Test_aSf_B_BFu17i, "aSf_B_BFu17i", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu17ll()
{
  {
    init_simple_test("aSf_B_BFu17ll");
    static aSf_B_BFu17ll lv;
    check2(sizeof(lv), 5, "sizeof(aSf_B_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu17ll)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu17ll.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu17ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 17, 1, "aSf_B_BFu17ll");
    set_bf_and_test(lv, v3, 2, 0, 17, hide_ull(1LL<<16), "aSf_B_BFu17ll");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu17ll(Test_aSf_B_BFu17ll, "aSf_B_BFu17ll", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu1c()
{
  {
    init_simple_test("aSf_B_BFu1c");
    static aSf_B_BFu1c lv;
    check2(sizeof(lv), 3, "sizeof(aSf_B_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu1c)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu1c.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu1c.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "aSf_B_BFu1c");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu1c(Test_aSf_B_BFu1c, "aSf_B_BFu1c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu1i()
{
  {
    init_simple_test("aSf_B_BFu1i");
    static aSf_B_BFu1i lv;
    check2(sizeof(lv), 3, "sizeof(aSf_B_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu1i)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu1i.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu1i.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "aSf_B_BFu1i");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu1i(Test_aSf_B_BFu1i, "aSf_B_BFu1i", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu1ll()
{
  {
    init_simple_test("aSf_B_BFu1ll");
    static aSf_B_BFu1ll lv;
    check2(sizeof(lv), 3, "sizeof(aSf_B_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu1ll)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu1ll.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu1ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "aSf_B_BFu1ll");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu1ll(Test_aSf_B_BFu1ll, "aSf_B_BFu1ll", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu1s()
{
  {
    init_simple_test("aSf_B_BFu1s");
    static aSf_B_BFu1s lv;
    check2(sizeof(lv), 3, "sizeof(aSf_B_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu1s)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu1s.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu1s.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "aSf_B_BFu1s");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu1s(Test_aSf_B_BFu1s, "aSf_B_BFu1s", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu31i()
{
  {
    init_simple_test("aSf_B_BFu31i");
    static aSf_B_BFu31i lv;
    check2(sizeof(lv), 6, "sizeof(aSf_B_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu31i)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu31i.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu31i.v2");
    set_bf_and_test(lv, v3, 2, 0, 31, 1, "aSf_B_BFu31i");
    set_bf_and_test(lv, v3, 2, 0, 31, hide_ull(1LL<<30), "aSf_B_BFu31i");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu31i(Test_aSf_B_BFu31i, "aSf_B_BFu31i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu31ll()
{
  {
    init_simple_test("aSf_B_BFu31ll");
    static aSf_B_BFu31ll lv;
    check2(sizeof(lv), 6, "sizeof(aSf_B_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu31ll)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu31ll.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu31ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 31, 1, "aSf_B_BFu31ll");
    set_bf_and_test(lv, v3, 2, 0, 31, hide_ull(1LL<<30), "aSf_B_BFu31ll");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu31ll(Test_aSf_B_BFu31ll, "aSf_B_BFu31ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu32i()
{
  {
    init_simple_test("aSf_B_BFu32i");
    static aSf_B_BFu32i lv;
    check2(sizeof(lv), 6, "sizeof(aSf_B_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu32i)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu32i.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu32i.v2");
    set_bf_and_test(lv, v3, 2, 0, 32, 1, "aSf_B_BFu32i");
    set_bf_and_test(lv, v3, 2, 0, 32, hide_ull(1LL<<31), "aSf_B_BFu32i");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu32i(Test_aSf_B_BFu32i, "aSf_B_BFu32i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu32ll()
{
  {
    init_simple_test("aSf_B_BFu32ll");
    static aSf_B_BFu32ll lv;
    check2(sizeof(lv), 6, "sizeof(aSf_B_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu32ll)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu32ll.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu32ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 32, 1, "aSf_B_BFu32ll");
    set_bf_and_test(lv, v3, 2, 0, 32, hide_ull(1LL<<31), "aSf_B_BFu32ll");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu32ll(Test_aSf_B_BFu32ll, "aSf_B_BFu32ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu33()
{
  {
    init_simple_test("aSf_B_BFu33");
    static aSf_B_BFu33 lv;
    check2(sizeof(lv), 7, "sizeof(aSf_B_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu33)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu33.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu33.v2");
    set_bf_and_test(lv, v3, 2, 0, 33, 1, "aSf_B_BFu33");
    set_bf_and_test(lv, v3, 2, 0, 33, hide_ull(1LL<<32), "aSf_B_BFu33");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu33(Test_aSf_B_BFu33, "aSf_B_BFu33", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu7c()
{
  {
    init_simple_test("aSf_B_BFu7c");
    static aSf_B_BFu7c lv;
    check2(sizeof(lv), 3, "sizeof(aSf_B_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu7c)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu7c.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu7c.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "aSf_B_BFu7c");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "aSf_B_BFu7c");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu7c(Test_aSf_B_BFu7c, "aSf_B_BFu7c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu7i()
{
  {
    init_simple_test("aSf_B_BFu7i");
    static aSf_B_BFu7i lv;
    check2(sizeof(lv), 3, "sizeof(aSf_B_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu7i)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu7i.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu7i.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "aSf_B_BFu7i");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "aSf_B_BFu7i");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu7i(Test_aSf_B_BFu7i, "aSf_B_BFu7i", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu7ll()
{
  {
    init_simple_test("aSf_B_BFu7ll");
    static aSf_B_BFu7ll lv;
    check2(sizeof(lv), 3, "sizeof(aSf_B_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu7ll)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu7ll.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu7ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "aSf_B_BFu7ll");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "aSf_B_BFu7ll");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu7ll(Test_aSf_B_BFu7ll, "aSf_B_BFu7ll", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu7s()
{
  {
    init_simple_test("aSf_B_BFu7s");
    static aSf_B_BFu7s lv;
    check2(sizeof(lv), 3, "sizeof(aSf_B_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu7s)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu7s.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu7s.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "aSf_B_BFu7s");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "aSf_B_BFu7s");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu7s(Test_aSf_B_BFu7s, "aSf_B_BFu7s", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu8c()
{
  {
    init_simple_test("aSf_B_BFu8c");
    static aSf_B_BFu8c lv;
    check2(sizeof(lv), 3, "sizeof(aSf_B_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu8c)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu8c.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu8c.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "aSf_B_BFu8c");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "aSf_B_BFu8c");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu8c(Test_aSf_B_BFu8c, "aSf_B_BFu8c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu8i()
{
  {
    init_simple_test("aSf_B_BFu8i");
    static aSf_B_BFu8i lv;
    check2(sizeof(lv), 3, "sizeof(aSf_B_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu8i)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu8i.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu8i.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "aSf_B_BFu8i");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "aSf_B_BFu8i");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu8i(Test_aSf_B_BFu8i, "aSf_B_BFu8i", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu8ll()
{
  {
    init_simple_test("aSf_B_BFu8ll");
    static aSf_B_BFu8ll lv;
    check2(sizeof(lv), 3, "sizeof(aSf_B_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu8ll)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu8ll.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu8ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "aSf_B_BFu8ll");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "aSf_B_BFu8ll");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu8ll(Test_aSf_B_BFu8ll, "aSf_B_BFu8ll", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu8s()
{
  {
    init_simple_test("aSf_B_BFu8s");
    static aSf_B_BFu8s lv;
    check2(sizeof(lv), 3, "sizeof(aSf_B_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu8s)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu8s.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu8s.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "aSf_B_BFu8s");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "aSf_B_BFu8s");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu8s(Test_aSf_B_BFu8s, "aSf_B_BFu8s", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu9i()
{
  {
    init_simple_test("aSf_B_BFu9i");
    static aSf_B_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(aSf_B_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu9i)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu9i.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu9i.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "aSf_B_BFu9i");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "aSf_B_BFu9i");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu9i(Test_aSf_B_BFu9i, "aSf_B_BFu9i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu9ll()
{
  {
    init_simple_test("aSf_B_BFu9ll");
    static aSf_B_BFu9ll lv;
    check2(sizeof(lv), 4, "sizeof(aSf_B_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu9ll)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu9ll.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu9ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "aSf_B_BFu9ll");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "aSf_B_BFu9ll");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu9ll(Test_aSf_B_BFu9ll, "aSf_B_BFu9ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_BFu9s()
{
  {
    init_simple_test("aSf_B_BFu9s");
    static aSf_B_BFu9s lv;
    check2(sizeof(lv), 4, "sizeof(aSf_B_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_BFu9s)");
    check_field_offset(lv, v1, 0, "aSf_B_BFu9s.v1");
    check_field_offset(lv, v2, 1, "aSf_B_BFu9s.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "aSf_B_BFu9s");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "aSf_B_BFu9s");
  }
}
static Arrange_To_Call_Me vaSf_B_BFu9s(Test_aSf_B_BFu9s, "aSf_B_BFu9s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_C()
{
  {
    init_simple_test("aSf_B_C");
    aSf_B_C lv;
    check2(sizeof(lv), 3, "sizeof(aSf_B_C)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_C)");
    check_field_offset(lv, v1, 0, "aSf_B_C.v1");
    check_field_offset(lv, v2, 1, "aSf_B_C.v2");
    check_field_offset(lv, v3, 2, "aSf_B_C.v3");
  }
}
static Arrange_To_Call_Me vaSf_B_C(Test_aSf_B_C, "aSf_B_C", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_D()
{
  {
    init_simple_test("aSf_B_D");
    aSf_B_D lv;
    check2(sizeof(lv), 10, "sizeof(aSf_B_D)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_D)");
    check_field_offset(lv, v1, 0, "aSf_B_D.v1");
    check_field_offset(lv, v2, 1, "aSf_B_D.v2");
    check_field_offset(lv, v3, 2, "aSf_B_D.v3");
  }
}
static Arrange_To_Call_Me vaSf_B_D(Test_aSf_B_D, "aSf_B_D", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_F()
{
  {
    init_simple_test("aSf_B_F");
    aSf_B_F lv;
    check2(sizeof(lv), 6, "sizeof(aSf_B_F)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_F)");
    check_field_offset(lv, v1, 0, "aSf_B_F.v1");
    check_field_offset(lv, v2, 1, "aSf_B_F.v2");
    check_field_offset(lv, v3, 2, "aSf_B_F.v3");
  }
}
static Arrange_To_Call_Me vaSf_B_F(Test_aSf_B_F, "aSf_B_F", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_I()
{
  {
    init_simple_test("aSf_B_I");
    aSf_B_I lv;
    check2(sizeof(lv), 6, "sizeof(aSf_B_I)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_I)");
    check_field_offset(lv, v1, 0, "aSf_B_I.v1");
    check_field_offset(lv, v2, 1, "aSf_B_I.v2");
    check_field_offset(lv, v3, 2, "aSf_B_I.v3");
  }
}
static Arrange_To_Call_Me vaSf_B_I(Test_aSf_B_I, "aSf_B_I", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_Ip()
{
  {
    init_simple_test("aSf_B_Ip");
    aSf_B_Ip lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(aSf_B_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_Ip)");
    check_field_offset(lv, v1, 0, "aSf_B_Ip.v1");
    check_field_offset(lv, v2, 1, "aSf_B_Ip.v2");
    check_field_offset(lv, v3, 2, "aSf_B_Ip.v3");
  }
}
static Arrange_To_Call_Me vaSf_B_Ip(Test_aSf_B_Ip, "aSf_B_Ip", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_L()
{
  {
    init_simple_test("aSf_B_L");
    aSf_B_L lv;
    check2(sizeof(lv), 10, "sizeof(aSf_B_L)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_L)");
    check_field_offset(lv, v1, 0, "aSf_B_L.v1");
    check_field_offset(lv, v2, 1, "aSf_B_L.v2");
    check_field_offset(lv, v3, 2, "aSf_B_L.v3");
  }
}
static Arrange_To_Call_Me vaSf_B_L(Test_aSf_B_L, "aSf_B_L", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_S()
{
  {
    init_simple_test("aSf_B_S");
    aSf_B_S lv;
    check2(sizeof(lv), 4, "sizeof(aSf_B_S)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_S)");
    check_field_offset(lv, v1, 0, "aSf_B_S.v1");
    check_field_offset(lv, v2, 1, "aSf_B_S.v2");
    check_field_offset(lv, v3, 2, "aSf_B_S.v3");
  }
}
static Arrange_To_Call_Me vaSf_B_S(Test_aSf_B_S, "aSf_B_S", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_Sf()
{
  {
    init_simple_test("aSf_B_Sf");
    aSf_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aSf_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_Sf)");
    check_field_offset(lv, v1, 0, "aSf_B_Sf.v1");
    check_field_offset(lv, v2, 1, "aSf_B_Sf.v2");
    check_field_offset(lv, v3, 2, "aSf_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaSf_B_Sf(Test_aSf_B_Sf, "aSf_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_Uc()
{
  {
    init_simple_test("aSf_B_Uc");
    aSf_B_Uc lv;
    check2(sizeof(lv), 3, "sizeof(aSf_B_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_Uc)");
    check_field_offset(lv, v1, 0, "aSf_B_Uc.v1");
    check_field_offset(lv, v2, 1, "aSf_B_Uc.v2");
    check_field_offset(lv, v3, 2, "aSf_B_Uc.v3");
  }
}
static Arrange_To_Call_Me vaSf_B_Uc(Test_aSf_B_Uc, "aSf_B_Uc", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_Ui()
{
  {
    init_simple_test("aSf_B_Ui");
    aSf_B_Ui lv;
    check2(sizeof(lv), 6, "sizeof(aSf_B_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_Ui)");
    check_field_offset(lv, v1, 0, "aSf_B_Ui.v1");
    check_field_offset(lv, v2, 1, "aSf_B_Ui.v2");
    check_field_offset(lv, v3, 2, "aSf_B_Ui.v3");
  }
}
static Arrange_To_Call_Me vaSf_B_Ui(Test_aSf_B_Ui, "aSf_B_Ui", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_Ul()
{
  {
    init_simple_test("aSf_B_Ul");
    aSf_B_Ul lv;
    check2(sizeof(lv), 10, "sizeof(aSf_B_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_Ul)");
    check_field_offset(lv, v1, 0, "aSf_B_Ul.v1");
    check_field_offset(lv, v2, 1, "aSf_B_Ul.v2");
    check_field_offset(lv, v3, 2, "aSf_B_Ul.v3");
  }
}
static Arrange_To_Call_Me vaSf_B_Ul(Test_aSf_B_Ul, "aSf_B_Ul", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_Us()
{
  {
    init_simple_test("aSf_B_Us");
    aSf_B_Us lv;
    check2(sizeof(lv), 4, "sizeof(aSf_B_Us)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_Us)");
    check_field_offset(lv, v1, 0, "aSf_B_Us.v1");
    check_field_offset(lv, v2, 1, "aSf_B_Us.v2");
    check_field_offset(lv, v3, 2, "aSf_B_Us.v3");
  }
}
static Arrange_To_Call_Me vaSf_B_Us(Test_aSf_B_Us, "aSf_B_Us", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_B_Vp()
{
  {
    init_simple_test("aSf_B_Vp");
    aSf_B_Vp lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(aSf_B_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_B_Vp)");
    check_field_offset(lv, v1, 0, "aSf_B_Vp.v1");
    check_field_offset(lv, v2, 1, "aSf_B_Vp.v2");
    check_field_offset(lv, v3, 2, "aSf_B_Vp.v3");
  }
}
static Arrange_To_Call_Me vaSf_B_Vp(Test_aSf_B_Vp, "aSf_B_Vp", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu15i_B()
{
  {
    init_simple_test("aSf_BFu15i_B");
    static aSf_BFu15i_B lv;
    check2(sizeof(lv), 4, "sizeof(aSf_BFu15i_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu15i_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu15i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "aSf_BFu15i_B");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "aSf_BFu15i_B");
    check_field_offset(lv, v3, 3, "aSf_BFu15i_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu15i_B(Test_aSf_BFu15i_B, "aSf_BFu15i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu15ll_B()
{
  {
    init_simple_test("aSf_BFu15ll_B");
    static aSf_BFu15ll_B lv;
    check2(sizeof(lv), 4, "sizeof(aSf_BFu15ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu15ll_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu15ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "aSf_BFu15ll_B");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "aSf_BFu15ll_B");
    check_field_offset(lv, v3, 3, "aSf_BFu15ll_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu15ll_B(Test_aSf_BFu15ll_B, "aSf_BFu15ll_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu15s_B()
{
  {
    init_simple_test("aSf_BFu15s_B");
    static aSf_BFu15s_B lv;
    check2(sizeof(lv), 4, "sizeof(aSf_BFu15s_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu15s_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu15s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "aSf_BFu15s_B");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "aSf_BFu15s_B");
    check_field_offset(lv, v3, 3, "aSf_BFu15s_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu15s_B(Test_aSf_BFu15s_B, "aSf_BFu15s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu16i_B()
{
  {
    init_simple_test("aSf_BFu16i_B");
    static aSf_BFu16i_B lv;
    check2(sizeof(lv), 4, "sizeof(aSf_BFu16i_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu16i_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu16i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "aSf_BFu16i_B");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "aSf_BFu16i_B");
    check_field_offset(lv, v3, 3, "aSf_BFu16i_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu16i_B(Test_aSf_BFu16i_B, "aSf_BFu16i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu16ll_B()
{
  {
    init_simple_test("aSf_BFu16ll_B");
    static aSf_BFu16ll_B lv;
    check2(sizeof(lv), 4, "sizeof(aSf_BFu16ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu16ll_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu16ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "aSf_BFu16ll_B");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "aSf_BFu16ll_B");
    check_field_offset(lv, v3, 3, "aSf_BFu16ll_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu16ll_B(Test_aSf_BFu16ll_B, "aSf_BFu16ll_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu16s_B()
{
  {
    init_simple_test("aSf_BFu16s_B");
    static aSf_BFu16s_B lv;
    check2(sizeof(lv), 4, "sizeof(aSf_BFu16s_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu16s_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu16s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "aSf_BFu16s_B");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "aSf_BFu16s_B");
    check_field_offset(lv, v3, 3, "aSf_BFu16s_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu16s_B(Test_aSf_BFu16s_B, "aSf_BFu16s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu17i_B()
{
  {
    init_simple_test("aSf_BFu17i_B");
    static aSf_BFu17i_B lv;
    check2(sizeof(lv), 5, "sizeof(aSf_BFu17i_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu17i_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu17i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "aSf_BFu17i_B");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "aSf_BFu17i_B");
    check_field_offset(lv, v3, 4, "aSf_BFu17i_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu17i_B(Test_aSf_BFu17i_B, "aSf_BFu17i_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu17ll_B()
{
  {
    init_simple_test("aSf_BFu17ll_B");
    static aSf_BFu17ll_B lv;
    check2(sizeof(lv), 5, "sizeof(aSf_BFu17ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu17ll_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu17ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "aSf_BFu17ll_B");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "aSf_BFu17ll_B");
    check_field_offset(lv, v3, 4, "aSf_BFu17ll_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu17ll_B(Test_aSf_BFu17ll_B, "aSf_BFu17ll_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu1c_B()
{
  {
    init_simple_test("aSf_BFu1c_B");
    static aSf_BFu1c_B lv;
    check2(sizeof(lv), 3, "sizeof(aSf_BFu1c_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu1c_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu1c_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "aSf_BFu1c_B");
    check_field_offset(lv, v3, 2, "aSf_BFu1c_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu1c_B(Test_aSf_BFu1c_B, "aSf_BFu1c_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu1i_B()
{
  {
    init_simple_test("aSf_BFu1i_B");
    static aSf_BFu1i_B lv;
    check2(sizeof(lv), 3, "sizeof(aSf_BFu1i_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu1i_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu1i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "aSf_BFu1i_B");
    check_field_offset(lv, v3, 2, "aSf_BFu1i_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu1i_B(Test_aSf_BFu1i_B, "aSf_BFu1i_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu1ll_B()
{
  {
    init_simple_test("aSf_BFu1ll_B");
    static aSf_BFu1ll_B lv;
    check2(sizeof(lv), 3, "sizeof(aSf_BFu1ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu1ll_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu1ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "aSf_BFu1ll_B");
    check_field_offset(lv, v3, 2, "aSf_BFu1ll_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu1ll_B(Test_aSf_BFu1ll_B, "aSf_BFu1ll_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu1s_B()
{
  {
    init_simple_test("aSf_BFu1s_B");
    static aSf_BFu1s_B lv;
    check2(sizeof(lv), 3, "sizeof(aSf_BFu1s_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu1s_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu1s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "aSf_BFu1s_B");
    check_field_offset(lv, v3, 2, "aSf_BFu1s_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu1s_B(Test_aSf_BFu1s_B, "aSf_BFu1s_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu31i_B()
{
  {
    init_simple_test("aSf_BFu31i_B");
    static aSf_BFu31i_B lv;
    check2(sizeof(lv), 6, "sizeof(aSf_BFu31i_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu31i_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu31i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "aSf_BFu31i_B");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "aSf_BFu31i_B");
    check_field_offset(lv, v3, 5, "aSf_BFu31i_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu31i_B(Test_aSf_BFu31i_B, "aSf_BFu31i_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu31ll_B()
{
  {
    init_simple_test("aSf_BFu31ll_B");
    static aSf_BFu31ll_B lv;
    check2(sizeof(lv), 6, "sizeof(aSf_BFu31ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu31ll_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu31ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "aSf_BFu31ll_B");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "aSf_BFu31ll_B");
    check_field_offset(lv, v3, 5, "aSf_BFu31ll_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu31ll_B(Test_aSf_BFu31ll_B, "aSf_BFu31ll_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu32i_B()
{
  {
    init_simple_test("aSf_BFu32i_B");
    static aSf_BFu32i_B lv;
    check2(sizeof(lv), 6, "sizeof(aSf_BFu32i_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu32i_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu32i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "aSf_BFu32i_B");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "aSf_BFu32i_B");
    check_field_offset(lv, v3, 5, "aSf_BFu32i_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu32i_B(Test_aSf_BFu32i_B, "aSf_BFu32i_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu32ll_B()
{
  {
    init_simple_test("aSf_BFu32ll_B");
    static aSf_BFu32ll_B lv;
    check2(sizeof(lv), 6, "sizeof(aSf_BFu32ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu32ll_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu32ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "aSf_BFu32ll_B");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "aSf_BFu32ll_B");
    check_field_offset(lv, v3, 5, "aSf_BFu32ll_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu32ll_B(Test_aSf_BFu32ll_B, "aSf_BFu32ll_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu33_B()
{
  {
    init_simple_test("aSf_BFu33_B");
    static aSf_BFu33_B lv;
    check2(sizeof(lv), 7, "sizeof(aSf_BFu33_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu33_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu33_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 33, 1, "aSf_BFu33_B");
    set_bf_and_test(lv, v2, 1, 0, 33, hide_ull(1LL<<32), "aSf_BFu33_B");
    check_field_offset(lv, v3, 6, "aSf_BFu33_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu33_B(Test_aSf_BFu33_B, "aSf_BFu33_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu7c_B()
{
  {
    init_simple_test("aSf_BFu7c_B");
    static aSf_BFu7c_B lv;
    check2(sizeof(lv), 3, "sizeof(aSf_BFu7c_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu7c_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu7c_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "aSf_BFu7c_B");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "aSf_BFu7c_B");
    check_field_offset(lv, v3, 2, "aSf_BFu7c_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu7c_B(Test_aSf_BFu7c_B, "aSf_BFu7c_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu7i_B()
{
  {
    init_simple_test("aSf_BFu7i_B");
    static aSf_BFu7i_B lv;
    check2(sizeof(lv), 3, "sizeof(aSf_BFu7i_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu7i_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu7i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "aSf_BFu7i_B");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "aSf_BFu7i_B");
    check_field_offset(lv, v3, 2, "aSf_BFu7i_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu7i_B(Test_aSf_BFu7i_B, "aSf_BFu7i_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu7ll_B()
{
  {
    init_simple_test("aSf_BFu7ll_B");
    static aSf_BFu7ll_B lv;
    check2(sizeof(lv), 3, "sizeof(aSf_BFu7ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu7ll_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu7ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "aSf_BFu7ll_B");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "aSf_BFu7ll_B");
    check_field_offset(lv, v3, 2, "aSf_BFu7ll_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu7ll_B(Test_aSf_BFu7ll_B, "aSf_BFu7ll_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu7s_B()
{
  {
    init_simple_test("aSf_BFu7s_B");
    static aSf_BFu7s_B lv;
    check2(sizeof(lv), 3, "sizeof(aSf_BFu7s_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu7s_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu7s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "aSf_BFu7s_B");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "aSf_BFu7s_B");
    check_field_offset(lv, v3, 2, "aSf_BFu7s_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu7s_B(Test_aSf_BFu7s_B, "aSf_BFu7s_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu8c_B()
{
  {
    init_simple_test("aSf_BFu8c_B");
    static aSf_BFu8c_B lv;
    check2(sizeof(lv), 3, "sizeof(aSf_BFu8c_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu8c_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu8c_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "aSf_BFu8c_B");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "aSf_BFu8c_B");
    check_field_offset(lv, v3, 2, "aSf_BFu8c_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu8c_B(Test_aSf_BFu8c_B, "aSf_BFu8c_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu8i_B()
{
  {
    init_simple_test("aSf_BFu8i_B");
    static aSf_BFu8i_B lv;
    check2(sizeof(lv), 3, "sizeof(aSf_BFu8i_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu8i_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu8i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "aSf_BFu8i_B");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "aSf_BFu8i_B");
    check_field_offset(lv, v3, 2, "aSf_BFu8i_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu8i_B(Test_aSf_BFu8i_B, "aSf_BFu8i_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu8ll_B()
{
  {
    init_simple_test("aSf_BFu8ll_B");
    static aSf_BFu8ll_B lv;
    check2(sizeof(lv), 3, "sizeof(aSf_BFu8ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu8ll_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu8ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "aSf_BFu8ll_B");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "aSf_BFu8ll_B");
    check_field_offset(lv, v3, 2, "aSf_BFu8ll_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu8ll_B(Test_aSf_BFu8ll_B, "aSf_BFu8ll_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu8s_B()
{
  {
    init_simple_test("aSf_BFu8s_B");
    static aSf_BFu8s_B lv;
    check2(sizeof(lv), 3, "sizeof(aSf_BFu8s_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu8s_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu8s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "aSf_BFu8s_B");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "aSf_BFu8s_B");
    check_field_offset(lv, v3, 2, "aSf_BFu8s_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu8s_B(Test_aSf_BFu8s_B, "aSf_BFu8s_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu9i_B()
{
  {
    init_simple_test("aSf_BFu9i_B");
    static aSf_BFu9i_B lv;
    check2(sizeof(lv), 4, "sizeof(aSf_BFu9i_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu9i_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu9i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "aSf_BFu9i_B");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "aSf_BFu9i_B");
    check_field_offset(lv, v3, 3, "aSf_BFu9i_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu9i_B(Test_aSf_BFu9i_B, "aSf_BFu9i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu9ll_B()
{
  {
    init_simple_test("aSf_BFu9ll_B");
    static aSf_BFu9ll_B lv;
    check2(sizeof(lv), 4, "sizeof(aSf_BFu9ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu9ll_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu9ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "aSf_BFu9ll_B");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "aSf_BFu9ll_B");
    check_field_offset(lv, v3, 3, "aSf_BFu9ll_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu9ll_B(Test_aSf_BFu9ll_B, "aSf_BFu9ll_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_BFu9s_B()
{
  {
    init_simple_test("aSf_BFu9s_B");
    static aSf_BFu9s_B lv;
    check2(sizeof(lv), 4, "sizeof(aSf_BFu9s_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_BFu9s_B)");
    check_field_offset(lv, v1, 0, "aSf_BFu9s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "aSf_BFu9s_B");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "aSf_BFu9s_B");
    check_field_offset(lv, v3, 3, "aSf_BFu9s_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_BFu9s_B(Test_aSf_BFu9s_B, "aSf_BFu9s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_C_B()
{
  {
    init_simple_test("aSf_C_B");
    aSf_C_B lv;
    check2(sizeof(lv), 3, "sizeof(aSf_C_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_C_B)");
    check_field_offset(lv, v1, 0, "aSf_C_B.v1");
    check_field_offset(lv, v2, 1, "aSf_C_B.v2");
    check_field_offset(lv, v3, 2, "aSf_C_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_C_B(Test_aSf_C_B, "aSf_C_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_D_B()
{
  {
    init_simple_test("aSf_D_B");
    aSf_D_B lv;
    check2(sizeof(lv), 10, "sizeof(aSf_D_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_D_B)");
    check_field_offset(lv, v1, 0, "aSf_D_B.v1");
    check_field_offset(lv, v2, 1, "aSf_D_B.v2");
    check_field_offset(lv, v3, 9, "aSf_D_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_D_B(Test_aSf_D_B, "aSf_D_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_F_B()
{
  {
    init_simple_test("aSf_F_B");
    aSf_F_B lv;
    check2(sizeof(lv), 6, "sizeof(aSf_F_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_F_B)");
    check_field_offset(lv, v1, 0, "aSf_F_B.v1");
    check_field_offset(lv, v2, 1, "aSf_F_B.v2");
    check_field_offset(lv, v3, 5, "aSf_F_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_F_B(Test_aSf_F_B, "aSf_F_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_I_B()
{
  {
    init_simple_test("aSf_I_B");
    aSf_I_B lv;
    check2(sizeof(lv), 6, "sizeof(aSf_I_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_I_B)");
    check_field_offset(lv, v1, 0, "aSf_I_B.v1");
    check_field_offset(lv, v2, 1, "aSf_I_B.v2");
    check_field_offset(lv, v3, 5, "aSf_I_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_I_B(Test_aSf_I_B, "aSf_I_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_Ip_B()
{
  {
    init_simple_test("aSf_Ip_B");
    aSf_Ip_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(aSf_Ip_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_Ip_B)");
    check_field_offset(lv, v1, 0, "aSf_Ip_B.v1");
    check_field_offset(lv, v2, 1, "aSf_Ip_B.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "aSf_Ip_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_Ip_B(Test_aSf_Ip_B, "aSf_Ip_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_L_B()
{
  {
    init_simple_test("aSf_L_B");
    aSf_L_B lv;
    check2(sizeof(lv), 10, "sizeof(aSf_L_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_L_B)");
    check_field_offset(lv, v1, 0, "aSf_L_B.v1");
    check_field_offset(lv, v2, 1, "aSf_L_B.v2");
    check_field_offset(lv, v3, 9, "aSf_L_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_L_B(Test_aSf_L_B, "aSf_L_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_S_B()
{
  {
    init_simple_test("aSf_S_B");
    aSf_S_B lv;
    check2(sizeof(lv), 4, "sizeof(aSf_S_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_S_B)");
    check_field_offset(lv, v1, 0, "aSf_S_B.v1");
    check_field_offset(lv, v2, 1, "aSf_S_B.v2");
    check_field_offset(lv, v3, 3, "aSf_S_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_S_B(Test_aSf_S_B, "aSf_S_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_Sf_B()
{
  {
    init_simple_test("aSf_Sf_B");
    aSf_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(aSf_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_Sf_B)");
    check_field_offset(lv, v1, 0, "aSf_Sf_B.v1");
    check_field_offset(lv, v2, 1, "aSf_Sf_B.v2");
    check_field_offset(lv, v3, 2, "aSf_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_Sf_B(Test_aSf_Sf_B, "aSf_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_Uc_B()
{
  {
    init_simple_test("aSf_Uc_B");
    aSf_Uc_B lv;
    check2(sizeof(lv), 3, "sizeof(aSf_Uc_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_Uc_B)");
    check_field_offset(lv, v1, 0, "aSf_Uc_B.v1");
    check_field_offset(lv, v2, 1, "aSf_Uc_B.v2");
    check_field_offset(lv, v3, 2, "aSf_Uc_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_Uc_B(Test_aSf_Uc_B, "aSf_Uc_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_Ui_B()
{
  {
    init_simple_test("aSf_Ui_B");
    aSf_Ui_B lv;
    check2(sizeof(lv), 6, "sizeof(aSf_Ui_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_Ui_B)");
    check_field_offset(lv, v1, 0, "aSf_Ui_B.v1");
    check_field_offset(lv, v2, 1, "aSf_Ui_B.v2");
    check_field_offset(lv, v3, 5, "aSf_Ui_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_Ui_B(Test_aSf_Ui_B, "aSf_Ui_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_Ul_B()
{
  {
    init_simple_test("aSf_Ul_B");
    aSf_Ul_B lv;
    check2(sizeof(lv), 10, "sizeof(aSf_Ul_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_Ul_B)");
    check_field_offset(lv, v1, 0, "aSf_Ul_B.v1");
    check_field_offset(lv, v2, 1, "aSf_Ul_B.v2");
    check_field_offset(lv, v3, 9, "aSf_Ul_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_Ul_B(Test_aSf_Ul_B, "aSf_Ul_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_Us_B()
{
  {
    init_simple_test("aSf_Us_B");
    aSf_Us_B lv;
    check2(sizeof(lv), 4, "sizeof(aSf_Us_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_Us_B)");
    check_field_offset(lv, v1, 0, "aSf_Us_B.v1");
    check_field_offset(lv, v2, 1, "aSf_Us_B.v2");
    check_field_offset(lv, v3, 3, "aSf_Us_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_Us_B(Test_aSf_Us_B, "aSf_Us_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aSf_Vp_B()
{
  {
    init_simple_test("aSf_Vp_B");
    aSf_Vp_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(aSf_Vp_B)");
    check2(__alignof__(lv), 1, "__alignof__(aSf_Vp_B)");
    check_field_offset(lv, v1, 0, "aSf_Vp_B.v1");
    check_field_offset(lv, v2, 1, "aSf_Vp_B.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "aSf_Vp_B.v3");
  }
}
static Arrange_To_Call_Me vaSf_Vp_B(Test_aSf_Vp_B, "aSf_Vp_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aUc_B_Sf()
{
  {
    init_simple_test("aUc_B_Sf");
    aUc_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(aUc_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aUc_B_Sf)");
    check_field_offset(lv, v1, 0, "aUc_B_Sf.v1");
    check_field_offset(lv, v2, 1, "aUc_B_Sf.v2");
    check_field_offset(lv, v3, 2, "aUc_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaUc_B_Sf(Test_aUc_B_Sf, "aUc_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aUc_Sf_B()
{
  {
    init_simple_test("aUc_Sf_B");
    aUc_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(aUc_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aUc_Sf_B)");
    check_field_offset(lv, v1, 0, "aUc_Sf_B.v1");
    check_field_offset(lv, v2, 1, "aUc_Sf_B.v2");
    check_field_offset(lv, v3, 2, "aUc_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaUc_Sf_B(Test_aUc_Sf_B, "aUc_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aUi_B_Sf()
{
  {
    init_simple_test("aUi_B_Sf");
    aUi_B_Sf lv;
    check2(sizeof(lv), 6, "sizeof(aUi_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aUi_B_Sf)");
    check_field_offset(lv, v1, 0, "aUi_B_Sf.v1");
    check_field_offset(lv, v2, 4, "aUi_B_Sf.v2");
    check_field_offset(lv, v3, 5, "aUi_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaUi_B_Sf(Test_aUi_B_Sf, "aUi_B_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aUi_Sf_B()
{
  {
    init_simple_test("aUi_Sf_B");
    aUi_Sf_B lv;
    check2(sizeof(lv), 6, "sizeof(aUi_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aUi_Sf_B)");
    check_field_offset(lv, v1, 0, "aUi_Sf_B.v1");
    check_field_offset(lv, v2, 4, "aUi_Sf_B.v2");
    check_field_offset(lv, v3, 5, "aUi_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaUi_Sf_B(Test_aUi_Sf_B, "aUi_Sf_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aUl_B_Sf()
{
  {
    init_simple_test("aUl_B_Sf");
    aUl_B_Sf lv;
    check2(sizeof(lv), 10, "sizeof(aUl_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aUl_B_Sf)");
    check_field_offset(lv, v1, 0, "aUl_B_Sf.v1");
    check_field_offset(lv, v2, 8, "aUl_B_Sf.v2");
    check_field_offset(lv, v3, 9, "aUl_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaUl_B_Sf(Test_aUl_B_Sf, "aUl_B_Sf", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aUl_Sf_B()
{
  {
    init_simple_test("aUl_Sf_B");
    aUl_Sf_B lv;
    check2(sizeof(lv), 10, "sizeof(aUl_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aUl_Sf_B)");
    check_field_offset(lv, v1, 0, "aUl_Sf_B.v1");
    check_field_offset(lv, v2, 8, "aUl_Sf_B.v2");
    check_field_offset(lv, v3, 9, "aUl_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaUl_Sf_B(Test_aUl_Sf_B, "aUl_Sf_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aUs_B_Sf()
{
  {
    init_simple_test("aUs_B_Sf");
    aUs_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(aUs_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aUs_B_Sf)");
    check_field_offset(lv, v1, 0, "aUs_B_Sf.v1");
    check_field_offset(lv, v2, 2, "aUs_B_Sf.v2");
    check_field_offset(lv, v3, 3, "aUs_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaUs_B_Sf(Test_aUs_B_Sf, "aUs_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aUs_Sf_B()
{
  {
    init_simple_test("aUs_Sf_B");
    aUs_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(aUs_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aUs_Sf_B)");
    check_field_offset(lv, v1, 0, "aUs_Sf_B.v1");
    check_field_offset(lv, v2, 2, "aUs_Sf_B.v2");
    check_field_offset(lv, v3, 3, "aUs_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaUs_Sf_B(Test_aUs_Sf_B, "aUs_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aVp_B_Sf()
{
  {
    init_simple_test("aVp_B_Sf");
    aVp_B_Sf lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(aVp_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(aVp_B_Sf)");
    check_field_offset(lv, v1, 0, "aVp_B_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "aVp_B_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "aVp_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vaVp_B_Sf(Test_aVp_B_Sf, "aVp_B_Sf", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_aVp_Sf_B()
{
  {
    init_simple_test("aVp_Sf_B");
    aVp_Sf_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(aVp_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(aVp_Sf_B)");
    check_field_offset(lv, v1, 0, "aVp_Sf_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "aVp_Sf_B.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "aVp_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vaVp_Sf_B(Test_aVp_Sf_B, "aVp_Sf_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_B_Sf()
{
  {
    init_simple_test("B_B_Sf");
    B_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_B_Sf)");
    check_field_offset(lv, v1, 0, "B_B_Sf.v1");
    check_field_offset(lv, v2, 1, "B_B_Sf.v2");
    check_field_offset(lv, v3, 2, "B_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_B_Sf(Test_B_B_Sf, "B_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu15i_Sf()
{
  {
    init_simple_test("B_BFu15i_Sf");
    static B_BFu15i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu15i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu15i_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu15i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "B_BFu15i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "B_BFu15i_Sf");
    check_field_offset(lv, v3, 3, "B_BFu15i_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu15i_Sf(Test_B_BFu15i_Sf, "B_BFu15i_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu15ll_Sf()
{
  {
    init_simple_test("B_BFu15ll_Sf");
    static B_BFu15ll_Sf lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu15ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu15ll_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu15ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "B_BFu15ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "B_BFu15ll_Sf");
    check_field_offset(lv, v3, 3, "B_BFu15ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu15ll_Sf(Test_B_BFu15ll_Sf, "B_BFu15ll_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu15s_Sf()
{
  {
    init_simple_test("B_BFu15s_Sf");
    static B_BFu15s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu15s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu15s_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu15s_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "B_BFu15s_Sf");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "B_BFu15s_Sf");
    check_field_offset(lv, v3, 3, "B_BFu15s_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu15s_Sf(Test_B_BFu15s_Sf, "B_BFu15s_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu16i_Sf()
{
  {
    init_simple_test("B_BFu16i_Sf");
    static B_BFu16i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu16i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu16i_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu16i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "B_BFu16i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "B_BFu16i_Sf");
    check_field_offset(lv, v3, 3, "B_BFu16i_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu16i_Sf(Test_B_BFu16i_Sf, "B_BFu16i_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu16ll_Sf()
{
  {
    init_simple_test("B_BFu16ll_Sf");
    static B_BFu16ll_Sf lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu16ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu16ll_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu16ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "B_BFu16ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "B_BFu16ll_Sf");
    check_field_offset(lv, v3, 3, "B_BFu16ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu16ll_Sf(Test_B_BFu16ll_Sf, "B_BFu16ll_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu16s_Sf()
{
  {
    init_simple_test("B_BFu16s_Sf");
    static B_BFu16s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu16s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu16s_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu16s_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "B_BFu16s_Sf");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "B_BFu16s_Sf");
    check_field_offset(lv, v3, 3, "B_BFu16s_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu16s_Sf(Test_B_BFu16s_Sf, "B_BFu16s_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu17i_Sf()
{
  {
    init_simple_test("B_BFu17i_Sf");
    static B_BFu17i_Sf lv;
    check2(sizeof(lv), 5, "sizeof(B_BFu17i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu17i_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu17i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "B_BFu17i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "B_BFu17i_Sf");
    check_field_offset(lv, v3, 4, "B_BFu17i_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu17i_Sf(Test_B_BFu17i_Sf, "B_BFu17i_Sf", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu17ll_Sf()
{
  {
    init_simple_test("B_BFu17ll_Sf");
    static B_BFu17ll_Sf lv;
    check2(sizeof(lv), 5, "sizeof(B_BFu17ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu17ll_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu17ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "B_BFu17ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "B_BFu17ll_Sf");
    check_field_offset(lv, v3, 4, "B_BFu17ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu17ll_Sf(Test_B_BFu17ll_Sf, "B_BFu17ll_Sf", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu1c_Sf()
{
  {
    init_simple_test("B_BFu1c_Sf");
    static B_BFu1c_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_BFu1c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu1c_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu1c_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1c_Sf");
    check_field_offset(lv, v3, 2, "B_BFu1c_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu1c_Sf(Test_B_BFu1c_Sf, "B_BFu1c_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu1i_Sf()
{
  {
    init_simple_test("B_BFu1i_Sf");
    static B_BFu1i_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_BFu1i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu1i_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu1i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1i_Sf");
    check_field_offset(lv, v3, 2, "B_BFu1i_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu1i_Sf(Test_B_BFu1i_Sf, "B_BFu1i_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu1ll_Sf()
{
  {
    init_simple_test("B_BFu1ll_Sf");
    static B_BFu1ll_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_BFu1ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu1ll_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu1ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1ll_Sf");
    check_field_offset(lv, v3, 2, "B_BFu1ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu1ll_Sf(Test_B_BFu1ll_Sf, "B_BFu1ll_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu1s_Sf()
{
  {
    init_simple_test("B_BFu1s_Sf");
    static B_BFu1s_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_BFu1s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu1s_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu1s_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1s_Sf");
    check_field_offset(lv, v3, 2, "B_BFu1s_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu1s_Sf(Test_B_BFu1s_Sf, "B_BFu1s_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu31i_Sf()
{
  {
    init_simple_test("B_BFu31i_Sf");
    static B_BFu31i_Sf lv;
    check2(sizeof(lv), 6, "sizeof(B_BFu31i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu31i_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu31i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "B_BFu31i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "B_BFu31i_Sf");
    check_field_offset(lv, v3, 5, "B_BFu31i_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu31i_Sf(Test_B_BFu31i_Sf, "B_BFu31i_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu31ll_Sf()
{
  {
    init_simple_test("B_BFu31ll_Sf");
    static B_BFu31ll_Sf lv;
    check2(sizeof(lv), 6, "sizeof(B_BFu31ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu31ll_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu31ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "B_BFu31ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "B_BFu31ll_Sf");
    check_field_offset(lv, v3, 5, "B_BFu31ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu31ll_Sf(Test_B_BFu31ll_Sf, "B_BFu31ll_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu32i_Sf()
{
  {
    init_simple_test("B_BFu32i_Sf");
    static B_BFu32i_Sf lv;
    check2(sizeof(lv), 6, "sizeof(B_BFu32i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu32i_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu32i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "B_BFu32i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "B_BFu32i_Sf");
    check_field_offset(lv, v3, 5, "B_BFu32i_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu32i_Sf(Test_B_BFu32i_Sf, "B_BFu32i_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu32ll_Sf()
{
  {
    init_simple_test("B_BFu32ll_Sf");
    static B_BFu32ll_Sf lv;
    check2(sizeof(lv), 6, "sizeof(B_BFu32ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu32ll_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu32ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "B_BFu32ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "B_BFu32ll_Sf");
    check_field_offset(lv, v3, 5, "B_BFu32ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu32ll_Sf(Test_B_BFu32ll_Sf, "B_BFu32ll_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu33_Sf()
{
  {
    init_simple_test("B_BFu33_Sf");
    static B_BFu33_Sf lv;
    check2(sizeof(lv), 7, "sizeof(B_BFu33_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu33_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu33_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 33, 1, "B_BFu33_Sf");
    set_bf_and_test(lv, v2, 1, 0, 33, hide_ull(1LL<<32), "B_BFu33_Sf");
    check_field_offset(lv, v3, 6, "B_BFu33_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu33_Sf(Test_B_BFu33_Sf, "B_BFu33_Sf", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu7c_Sf()
{
  {
    init_simple_test("B_BFu7c_Sf");
    static B_BFu7c_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_BFu7c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu7c_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu7c_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7c_Sf");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7c_Sf");
    check_field_offset(lv, v3, 2, "B_BFu7c_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu7c_Sf(Test_B_BFu7c_Sf, "B_BFu7c_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu7i_Sf()
{
  {
    init_simple_test("B_BFu7i_Sf");
    static B_BFu7i_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_BFu7i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu7i_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu7i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7i_Sf");
    check_field_offset(lv, v3, 2, "B_BFu7i_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu7i_Sf(Test_B_BFu7i_Sf, "B_BFu7i_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu7ll_Sf()
{
  {
    init_simple_test("B_BFu7ll_Sf");
    static B_BFu7ll_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_BFu7ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu7ll_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu7ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7ll_Sf");
    check_field_offset(lv, v3, 2, "B_BFu7ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu7ll_Sf(Test_B_BFu7ll_Sf, "B_BFu7ll_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu7s_Sf()
{
  {
    init_simple_test("B_BFu7s_Sf");
    static B_BFu7s_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_BFu7s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu7s_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu7s_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7s_Sf");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7s_Sf");
    check_field_offset(lv, v3, 2, "B_BFu7s_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu7s_Sf(Test_B_BFu7s_Sf, "B_BFu7s_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu8c_Sf()
{
  {
    init_simple_test("B_BFu8c_Sf");
    static B_BFu8c_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_BFu8c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu8c_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu8c_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8c_Sf");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8c_Sf");
    check_field_offset(lv, v3, 2, "B_BFu8c_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu8c_Sf(Test_B_BFu8c_Sf, "B_BFu8c_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu8i_Sf()
{
  {
    init_simple_test("B_BFu8i_Sf");
    static B_BFu8i_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_BFu8i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu8i_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu8i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8i_Sf");
    check_field_offset(lv, v3, 2, "B_BFu8i_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu8i_Sf(Test_B_BFu8i_Sf, "B_BFu8i_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu8ll_Sf()
{
  {
    init_simple_test("B_BFu8ll_Sf");
    static B_BFu8ll_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_BFu8ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu8ll_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu8ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8ll_Sf");
    check_field_offset(lv, v3, 2, "B_BFu8ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu8ll_Sf(Test_B_BFu8ll_Sf, "B_BFu8ll_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu8s_Sf()
{
  {
    init_simple_test("B_BFu8s_Sf");
    static B_BFu8s_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_BFu8s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu8s_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu8s_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8s_Sf");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8s_Sf");
    check_field_offset(lv, v3, 2, "B_BFu8s_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu8s_Sf(Test_B_BFu8s_Sf, "B_BFu8s_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu9i_Sf()
{
  {
    init_simple_test("B_BFu9i_Sf");
    static B_BFu9i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu9i_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu9i_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu9i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "B_BFu9i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "B_BFu9i_Sf");
    check_field_offset(lv, v3, 3, "B_BFu9i_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu9i_Sf(Test_B_BFu9i_Sf, "B_BFu9i_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu9ll_Sf()
{
  {
    init_simple_test("B_BFu9ll_Sf");
    static B_BFu9ll_Sf lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu9ll_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu9ll_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu9ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "B_BFu9ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "B_BFu9ll_Sf");
    check_field_offset(lv, v3, 3, "B_BFu9ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu9ll_Sf(Test_B_BFu9ll_Sf, "B_BFu9ll_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_BFu9s_Sf()
{
  {
    init_simple_test("B_BFu9s_Sf");
    static B_BFu9s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu9s_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu9s_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu9s_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "B_BFu9s_Sf");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "B_BFu9s_Sf");
    check_field_offset(lv, v3, 3, "B_BFu9s_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu9s_Sf(Test_B_BFu9s_Sf, "B_BFu9s_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_C_Sf()
{
  {
    init_simple_test("B_C_Sf");
    B_C_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_C_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_C_Sf)");
    check_field_offset(lv, v1, 0, "B_C_Sf.v1");
    check_field_offset(lv, v2, 1, "B_C_Sf.v2");
    check_field_offset(lv, v3, 2, "B_C_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_C_Sf(Test_B_C_Sf, "B_C_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_D_Sf()
{
  {
    init_simple_test("B_D_Sf");
    B_D_Sf lv;
    check2(sizeof(lv), 10, "sizeof(B_D_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_D_Sf)");
    check_field_offset(lv, v1, 0, "B_D_Sf.v1");
    check_field_offset(lv, v2, 1, "B_D_Sf.v2");
    check_field_offset(lv, v3, 9, "B_D_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_D_Sf(Test_B_D_Sf, "B_D_Sf", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_F_Sf()
{
  {
    init_simple_test("B_F_Sf");
    B_F_Sf lv;
    check2(sizeof(lv), 6, "sizeof(B_F_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_F_Sf)");
    check_field_offset(lv, v1, 0, "B_F_Sf.v1");
    check_field_offset(lv, v2, 1, "B_F_Sf.v2");
    check_field_offset(lv, v3, 5, "B_F_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_F_Sf(Test_B_F_Sf, "B_F_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_I_Sf()
{
  {
    init_simple_test("B_I_Sf");
    B_I_Sf lv;
    check2(sizeof(lv), 6, "sizeof(B_I_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_I_Sf)");
    check_field_offset(lv, v1, 0, "B_I_Sf.v1");
    check_field_offset(lv, v2, 1, "B_I_Sf.v2");
    check_field_offset(lv, v3, 5, "B_I_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_I_Sf(Test_B_I_Sf, "B_I_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Ip_Sf()
{
  {
    init_simple_test("B_Ip_Sf");
    B_Ip_Sf lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(B_Ip_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_Ip_Sf)");
    check_field_offset(lv, v1, 0, "B_Ip_Sf.v1");
    check_field_offset(lv, v2, 1, "B_Ip_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "B_Ip_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_Ip_Sf(Test_B_Ip_Sf, "B_Ip_Sf", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_L_Sf()
{
  {
    init_simple_test("B_L_Sf");
    B_L_Sf lv;
    check2(sizeof(lv), 10, "sizeof(B_L_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_L_Sf)");
    check_field_offset(lv, v1, 0, "B_L_Sf.v1");
    check_field_offset(lv, v2, 1, "B_L_Sf.v2");
    check_field_offset(lv, v3, 9, "B_L_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_L_Sf(Test_B_L_Sf, "B_L_Sf", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_S_Sf()
{
  {
    init_simple_test("B_S_Sf");
    B_S_Sf lv;
    check2(sizeof(lv), 4, "sizeof(B_S_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_S_Sf)");
    check_field_offset(lv, v1, 0, "B_S_Sf.v1");
    check_field_offset(lv, v2, 1, "B_S_Sf.v2");
    check_field_offset(lv, v3, 3, "B_S_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_S_Sf(Test_B_S_Sf, "B_S_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf()
{
  {
    init_simple_test("B_Sf");
    B_Sf lv;
    check2(sizeof(lv), 2, "sizeof(B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf)");
    check_field_offset(lv, v1, 0, "B_Sf.v1");
    check_field_offset(lv, v2, 1, "B_Sf.v2");
  }
}
static Arrange_To_Call_Me vB_Sf(Test_B_Sf, "B_Sf", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_B()
{
  {
    init_simple_test("B_Sf_B");
    B_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_B)");
    check_field_offset(lv, v1, 0, "B_Sf_B.v1");
    check_field_offset(lv, v2, 1, "B_Sf_B.v2");
    check_field_offset(lv, v3, 2, "B_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_B(Test_B_Sf_B, "B_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu15i()
{
  {
    init_simple_test("B_Sf_BFu15i");
    static B_Sf_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu15i)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu15i.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu15i.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "B_Sf_BFu15i");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "B_Sf_BFu15i");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu15i(Test_B_Sf_BFu15i, "B_Sf_BFu15i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu15ll()
{
  {
    init_simple_test("B_Sf_BFu15ll");
    static B_Sf_BFu15ll lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu15ll)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu15ll.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu15ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "B_Sf_BFu15ll");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "B_Sf_BFu15ll");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu15ll(Test_B_Sf_BFu15ll, "B_Sf_BFu15ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu15s()
{
  {
    init_simple_test("B_Sf_BFu15s");
    static B_Sf_BFu15s lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu15s)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu15s.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu15s.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "B_Sf_BFu15s");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "B_Sf_BFu15s");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu15s(Test_B_Sf_BFu15s, "B_Sf_BFu15s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu16i()
{
  {
    init_simple_test("B_Sf_BFu16i");
    static B_Sf_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu16i)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu16i.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu16i.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "B_Sf_BFu16i");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "B_Sf_BFu16i");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu16i(Test_B_Sf_BFu16i, "B_Sf_BFu16i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu16ll()
{
  {
    init_simple_test("B_Sf_BFu16ll");
    static B_Sf_BFu16ll lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu16ll)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu16ll.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu16ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "B_Sf_BFu16ll");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "B_Sf_BFu16ll");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu16ll(Test_B_Sf_BFu16ll, "B_Sf_BFu16ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu16s()
{
  {
    init_simple_test("B_Sf_BFu16s");
    static B_Sf_BFu16s lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu16s)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu16s.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu16s.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "B_Sf_BFu16s");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "B_Sf_BFu16s");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu16s(Test_B_Sf_BFu16s, "B_Sf_BFu16s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu17i()
{
  {
    init_simple_test("B_Sf_BFu17i");
    static B_Sf_BFu17i lv;
    check2(sizeof(lv), 5, "sizeof(B_Sf_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu17i)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu17i.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu17i.v2");
    set_bf_and_test(lv, v3, 2, 0, 17, 1, "B_Sf_BFu17i");
    set_bf_and_test(lv, v3, 2, 0, 17, hide_ull(1LL<<16), "B_Sf_BFu17i");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu17i(Test_B_Sf_BFu17i, "B_Sf_BFu17i", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu17ll()
{
  {
    init_simple_test("B_Sf_BFu17ll");
    static B_Sf_BFu17ll lv;
    check2(sizeof(lv), 5, "sizeof(B_Sf_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu17ll)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu17ll.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu17ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 17, 1, "B_Sf_BFu17ll");
    set_bf_and_test(lv, v3, 2, 0, 17, hide_ull(1LL<<16), "B_Sf_BFu17ll");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu17ll(Test_B_Sf_BFu17ll, "B_Sf_BFu17ll", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu1c()
{
  {
    init_simple_test("B_Sf_BFu1c");
    static B_Sf_BFu1c lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu1c)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu1c.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu1c.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "B_Sf_BFu1c");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu1c(Test_B_Sf_BFu1c, "B_Sf_BFu1c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu1i()
{
  {
    init_simple_test("B_Sf_BFu1i");
    static B_Sf_BFu1i lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu1i)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu1i.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu1i.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "B_Sf_BFu1i");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu1i(Test_B_Sf_BFu1i, "B_Sf_BFu1i", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu1ll()
{
  {
    init_simple_test("B_Sf_BFu1ll");
    static B_Sf_BFu1ll lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu1ll)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu1ll.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu1ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "B_Sf_BFu1ll");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu1ll(Test_B_Sf_BFu1ll, "B_Sf_BFu1ll", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu1s()
{
  {
    init_simple_test("B_Sf_BFu1s");
    static B_Sf_BFu1s lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu1s)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu1s.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu1s.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "B_Sf_BFu1s");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu1s(Test_B_Sf_BFu1s, "B_Sf_BFu1s", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu31i()
{
  {
    init_simple_test("B_Sf_BFu31i");
    static B_Sf_BFu31i lv;
    check2(sizeof(lv), 6, "sizeof(B_Sf_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu31i)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu31i.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu31i.v2");
    set_bf_and_test(lv, v3, 2, 0, 31, 1, "B_Sf_BFu31i");
    set_bf_and_test(lv, v3, 2, 0, 31, hide_ull(1LL<<30), "B_Sf_BFu31i");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu31i(Test_B_Sf_BFu31i, "B_Sf_BFu31i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu31ll()
{
  {
    init_simple_test("B_Sf_BFu31ll");
    static B_Sf_BFu31ll lv;
    check2(sizeof(lv), 6, "sizeof(B_Sf_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu31ll)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu31ll.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu31ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 31, 1, "B_Sf_BFu31ll");
    set_bf_and_test(lv, v3, 2, 0, 31, hide_ull(1LL<<30), "B_Sf_BFu31ll");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu31ll(Test_B_Sf_BFu31ll, "B_Sf_BFu31ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu32i()
{
  {
    init_simple_test("B_Sf_BFu32i");
    static B_Sf_BFu32i lv;
    check2(sizeof(lv), 6, "sizeof(B_Sf_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu32i)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu32i.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu32i.v2");
    set_bf_and_test(lv, v3, 2, 0, 32, 1, "B_Sf_BFu32i");
    set_bf_and_test(lv, v3, 2, 0, 32, hide_ull(1LL<<31), "B_Sf_BFu32i");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu32i(Test_B_Sf_BFu32i, "B_Sf_BFu32i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu32ll()
{
  {
    init_simple_test("B_Sf_BFu32ll");
    static B_Sf_BFu32ll lv;
    check2(sizeof(lv), 6, "sizeof(B_Sf_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu32ll)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu32ll.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu32ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 32, 1, "B_Sf_BFu32ll");
    set_bf_and_test(lv, v3, 2, 0, 32, hide_ull(1LL<<31), "B_Sf_BFu32ll");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu32ll(Test_B_Sf_BFu32ll, "B_Sf_BFu32ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu33()
{
  {
    init_simple_test("B_Sf_BFu33");
    static B_Sf_BFu33 lv;
    check2(sizeof(lv), 7, "sizeof(B_Sf_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu33)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu33.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu33.v2");
    set_bf_and_test(lv, v3, 2, 0, 33, 1, "B_Sf_BFu33");
    set_bf_and_test(lv, v3, 2, 0, 33, hide_ull(1LL<<32), "B_Sf_BFu33");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu33(Test_B_Sf_BFu33, "B_Sf_BFu33", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu7c()
{
  {
    init_simple_test("B_Sf_BFu7c");
    static B_Sf_BFu7c lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu7c)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu7c.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu7c.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "B_Sf_BFu7c");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "B_Sf_BFu7c");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu7c(Test_B_Sf_BFu7c, "B_Sf_BFu7c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu7i()
{
  {
    init_simple_test("B_Sf_BFu7i");
    static B_Sf_BFu7i lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu7i)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu7i.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu7i.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "B_Sf_BFu7i");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "B_Sf_BFu7i");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu7i(Test_B_Sf_BFu7i, "B_Sf_BFu7i", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu7ll()
{
  {
    init_simple_test("B_Sf_BFu7ll");
    static B_Sf_BFu7ll lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu7ll)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu7ll.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu7ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "B_Sf_BFu7ll");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "B_Sf_BFu7ll");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu7ll(Test_B_Sf_BFu7ll, "B_Sf_BFu7ll", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu7s()
{
  {
    init_simple_test("B_Sf_BFu7s");
    static B_Sf_BFu7s lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu7s)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu7s.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu7s.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "B_Sf_BFu7s");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "B_Sf_BFu7s");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu7s(Test_B_Sf_BFu7s, "B_Sf_BFu7s", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu8c()
{
  {
    init_simple_test("B_Sf_BFu8c");
    static B_Sf_BFu8c lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu8c)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu8c.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu8c.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "B_Sf_BFu8c");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "B_Sf_BFu8c");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu8c(Test_B_Sf_BFu8c, "B_Sf_BFu8c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu8i()
{
  {
    init_simple_test("B_Sf_BFu8i");
    static B_Sf_BFu8i lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu8i)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu8i.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu8i.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "B_Sf_BFu8i");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "B_Sf_BFu8i");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu8i(Test_B_Sf_BFu8i, "B_Sf_BFu8i", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu8ll()
{
  {
    init_simple_test("B_Sf_BFu8ll");
    static B_Sf_BFu8ll lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu8ll)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu8ll.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu8ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "B_Sf_BFu8ll");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "B_Sf_BFu8ll");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu8ll(Test_B_Sf_BFu8ll, "B_Sf_BFu8ll", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu8s()
{
  {
    init_simple_test("B_Sf_BFu8s");
    static B_Sf_BFu8s lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu8s)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu8s.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu8s.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "B_Sf_BFu8s");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "B_Sf_BFu8s");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu8s(Test_B_Sf_BFu8s, "B_Sf_BFu8s", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu9i()
{
  {
    init_simple_test("B_Sf_BFu9i");
    static B_Sf_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu9i)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu9i.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu9i.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "B_Sf_BFu9i");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "B_Sf_BFu9i");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu9i(Test_B_Sf_BFu9i, "B_Sf_BFu9i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu9ll()
{
  {
    init_simple_test("B_Sf_BFu9ll");
    static B_Sf_BFu9ll lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu9ll)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu9ll.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu9ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "B_Sf_BFu9ll");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "B_Sf_BFu9ll");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu9ll(Test_B_Sf_BFu9ll, "B_Sf_BFu9ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_BFu9s()
{
  {
    init_simple_test("B_Sf_BFu9s");
    static B_Sf_BFu9s lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu9s)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu9s.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu9s.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "B_Sf_BFu9s");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "B_Sf_BFu9s");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu9s(Test_B_Sf_BFu9s, "B_Sf_BFu9s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_C()
{
  {
    init_simple_test("B_Sf_C");
    B_Sf_C lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_C)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_C)");
    check_field_offset(lv, v1, 0, "B_Sf_C.v1");
    check_field_offset(lv, v2, 1, "B_Sf_C.v2");
    check_field_offset(lv, v3, 2, "B_Sf_C.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_C(Test_B_Sf_C, "B_Sf_C", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_D()
{
  {
    init_simple_test("B_Sf_D");
    B_Sf_D lv;
    check2(sizeof(lv), 10, "sizeof(B_Sf_D)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_D)");
    check_field_offset(lv, v1, 0, "B_Sf_D.v1");
    check_field_offset(lv, v2, 1, "B_Sf_D.v2");
    check_field_offset(lv, v3, 2, "B_Sf_D.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_D(Test_B_Sf_D, "B_Sf_D", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_F()
{
  {
    init_simple_test("B_Sf_F");
    B_Sf_F lv;
    check2(sizeof(lv), 6, "sizeof(B_Sf_F)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_F)");
    check_field_offset(lv, v1, 0, "B_Sf_F.v1");
    check_field_offset(lv, v2, 1, "B_Sf_F.v2");
    check_field_offset(lv, v3, 2, "B_Sf_F.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_F(Test_B_Sf_F, "B_Sf_F", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_I()
{
  {
    init_simple_test("B_Sf_I");
    B_Sf_I lv;
    check2(sizeof(lv), 6, "sizeof(B_Sf_I)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_I)");
    check_field_offset(lv, v1, 0, "B_Sf_I.v1");
    check_field_offset(lv, v2, 1, "B_Sf_I.v2");
    check_field_offset(lv, v3, 2, "B_Sf_I.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_I(Test_B_Sf_I, "B_Sf_I", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_Ip()
{
  {
    init_simple_test("B_Sf_Ip");
    B_Sf_Ip lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(B_Sf_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_Ip)");
    check_field_offset(lv, v1, 0, "B_Sf_Ip.v1");
    check_field_offset(lv, v2, 1, "B_Sf_Ip.v2");
    check_field_offset(lv, v3, 2, "B_Sf_Ip.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_Ip(Test_B_Sf_Ip, "B_Sf_Ip", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_L()
{
  {
    init_simple_test("B_Sf_L");
    B_Sf_L lv;
    check2(sizeof(lv), 10, "sizeof(B_Sf_L)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_L)");
    check_field_offset(lv, v1, 0, "B_Sf_L.v1");
    check_field_offset(lv, v2, 1, "B_Sf_L.v2");
    check_field_offset(lv, v3, 2, "B_Sf_L.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_L(Test_B_Sf_L, "B_Sf_L", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_S()
{
  {
    init_simple_test("B_Sf_S");
    B_Sf_S lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_S)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_S)");
    check_field_offset(lv, v1, 0, "B_Sf_S.v1");
    check_field_offset(lv, v2, 1, "B_Sf_S.v2");
    check_field_offset(lv, v3, 2, "B_Sf_S.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_S(Test_B_Sf_S, "B_Sf_S", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_Sf()
{
  {
    init_simple_test("B_Sf_Sf");
    B_Sf_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_Sf)");
    check_field_offset(lv, v1, 0, "B_Sf_Sf.v1");
    check_field_offset(lv, v2, 1, "B_Sf_Sf.v2");
    check_field_offset(lv, v3, 2, "B_Sf_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_Sf(Test_B_Sf_Sf, "B_Sf_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_Uc()
{
  {
    init_simple_test("B_Sf_Uc");
    B_Sf_Uc lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_Uc)");
    check_field_offset(lv, v1, 0, "B_Sf_Uc.v1");
    check_field_offset(lv, v2, 1, "B_Sf_Uc.v2");
    check_field_offset(lv, v3, 2, "B_Sf_Uc.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_Uc(Test_B_Sf_Uc, "B_Sf_Uc", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_Ui()
{
  {
    init_simple_test("B_Sf_Ui");
    B_Sf_Ui lv;
    check2(sizeof(lv), 6, "sizeof(B_Sf_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_Ui)");
    check_field_offset(lv, v1, 0, "B_Sf_Ui.v1");
    check_field_offset(lv, v2, 1, "B_Sf_Ui.v2");
    check_field_offset(lv, v3, 2, "B_Sf_Ui.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_Ui(Test_B_Sf_Ui, "B_Sf_Ui", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_Ul()
{
  {
    init_simple_test("B_Sf_Ul");
    B_Sf_Ul lv;
    check2(sizeof(lv), 10, "sizeof(B_Sf_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_Ul)");
    check_field_offset(lv, v1, 0, "B_Sf_Ul.v1");
    check_field_offset(lv, v2, 1, "B_Sf_Ul.v2");
    check_field_offset(lv, v3, 2, "B_Sf_Ul.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_Ul(Test_B_Sf_Ul, "B_Sf_Ul", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_Us()
{
  {
    init_simple_test("B_Sf_Us");
    B_Sf_Us lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_Us)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_Us)");
    check_field_offset(lv, v1, 0, "B_Sf_Us.v1");
    check_field_offset(lv, v2, 1, "B_Sf_Us.v2");
    check_field_offset(lv, v3, 2, "B_Sf_Us.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_Us(Test_B_Sf_Us, "B_Sf_Us", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Sf_Vp()
{
  {
    init_simple_test("B_Sf_Vp");
    B_Sf_Vp lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(B_Sf_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_Vp)");
    check_field_offset(lv, v1, 0, "B_Sf_Vp.v1");
    check_field_offset(lv, v2, 1, "B_Sf_Vp.v2");
    check_field_offset(lv, v3, 2, "B_Sf_Vp.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_Vp(Test_B_Sf_Vp, "B_Sf_Vp", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Uc_Sf()
{
  {
    init_simple_test("B_Uc_Sf");
    B_Uc_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_Uc_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_Uc_Sf)");
    check_field_offset(lv, v1, 0, "B_Uc_Sf.v1");
    check_field_offset(lv, v2, 1, "B_Uc_Sf.v2");
    check_field_offset(lv, v3, 2, "B_Uc_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_Uc_Sf(Test_B_Uc_Sf, "B_Uc_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Ui_Sf()
{
  {
    init_simple_test("B_Ui_Sf");
    B_Ui_Sf lv;
    check2(sizeof(lv), 6, "sizeof(B_Ui_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_Ui_Sf)");
    check_field_offset(lv, v1, 0, "B_Ui_Sf.v1");
    check_field_offset(lv, v2, 1, "B_Ui_Sf.v2");
    check_field_offset(lv, v3, 5, "B_Ui_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_Ui_Sf(Test_B_Ui_Sf, "B_Ui_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Ul_Sf()
{
  {
    init_simple_test("B_Ul_Sf");
    B_Ul_Sf lv;
    check2(sizeof(lv), 10, "sizeof(B_Ul_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_Ul_Sf)");
    check_field_offset(lv, v1, 0, "B_Ul_Sf.v1");
    check_field_offset(lv, v2, 1, "B_Ul_Sf.v2");
    check_field_offset(lv, v3, 9, "B_Ul_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_Ul_Sf(Test_B_Ul_Sf, "B_Ul_Sf", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Us_Sf()
{
  {
    init_simple_test("B_Us_Sf");
    B_Us_Sf lv;
    check2(sizeof(lv), 4, "sizeof(B_Us_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_Us_Sf)");
    check_field_offset(lv, v1, 0, "B_Us_Sf.v1");
    check_field_offset(lv, v2, 1, "B_Us_Sf.v2");
    check_field_offset(lv, v3, 3, "B_Us_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_Us_Sf(Test_B_Us_Sf, "B_Us_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_B_Vp_Sf()
{
  {
    init_simple_test("B_Vp_Sf");
    B_Vp_Sf lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(B_Vp_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_Vp_Sf)");
    check_field_offset(lv, v1, 0, "B_Vp_Sf.v1");
    check_field_offset(lv, v2, 1, "B_Vp_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "B_Vp_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_Vp_Sf(Test_B_Vp_Sf, "B_Vp_Sf", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu15i_B_Sf()
{
  {
    init_simple_test("BFu15i_B_Sf");
    static BFu15i_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu15i_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu15i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15i_B_Sf");
    check_field_offset(lv, v2, 2, "BFu15i_B_Sf.v2");
    check_field_offset(lv, v3, 3, "BFu15i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu15i_B_Sf(Test_BFu15i_B_Sf, "BFu15i_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu15i_Sf_B()
{
  {
    init_simple_test("BFu15i_Sf_B");
    static BFu15i_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu15i_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu15i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15i_Sf_B");
    check_field_offset(lv, v2, 2, "BFu15i_Sf_B.v2");
    check_field_offset(lv, v3, 3, "BFu15i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu15i_Sf_B(Test_BFu15i_Sf_B, "BFu15i_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu15ll_B_Sf()
{
  {
    init_simple_test("BFu15ll_B_Sf");
    static BFu15ll_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu15ll_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu15ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15ll_B_Sf");
    check_field_offset(lv, v2, 2, "BFu15ll_B_Sf.v2");
    check_field_offset(lv, v3, 3, "BFu15ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu15ll_B_Sf(Test_BFu15ll_B_Sf, "BFu15ll_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu15ll_Sf_B()
{
  {
    init_simple_test("BFu15ll_Sf_B");
    static BFu15ll_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu15ll_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu15ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15ll_Sf_B");
    check_field_offset(lv, v2, 2, "BFu15ll_Sf_B.v2");
    check_field_offset(lv, v3, 3, "BFu15ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu15ll_Sf_B(Test_BFu15ll_Sf_B, "BFu15ll_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu15s_B_Sf()
{
  {
    init_simple_test("BFu15s_B_Sf");
    static BFu15s_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu15s_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu15s_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15s_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15s_B_Sf");
    check_field_offset(lv, v2, 2, "BFu15s_B_Sf.v2");
    check_field_offset(lv, v3, 3, "BFu15s_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu15s_B_Sf(Test_BFu15s_B_Sf, "BFu15s_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu15s_Sf_B()
{
  {
    init_simple_test("BFu15s_Sf_B");
    static BFu15s_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu15s_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu15s_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15s_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15s_Sf_B");
    check_field_offset(lv, v2, 2, "BFu15s_Sf_B.v2");
    check_field_offset(lv, v3, 3, "BFu15s_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu15s_Sf_B(Test_BFu15s_Sf_B, "BFu15s_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu16i_B_Sf()
{
  {
    init_simple_test("BFu16i_B_Sf");
    static BFu16i_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu16i_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu16i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16i_B_Sf");
    check_field_offset(lv, v2, 2, "BFu16i_B_Sf.v2");
    check_field_offset(lv, v3, 3, "BFu16i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu16i_B_Sf(Test_BFu16i_B_Sf, "BFu16i_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu16i_Sf_B()
{
  {
    init_simple_test("BFu16i_Sf_B");
    static BFu16i_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu16i_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu16i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16i_Sf_B");
    check_field_offset(lv, v2, 2, "BFu16i_Sf_B.v2");
    check_field_offset(lv, v3, 3, "BFu16i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu16i_Sf_B(Test_BFu16i_Sf_B, "BFu16i_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu16ll_B_Sf()
{
  {
    init_simple_test("BFu16ll_B_Sf");
    static BFu16ll_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu16ll_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu16ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16ll_B_Sf");
    check_field_offset(lv, v2, 2, "BFu16ll_B_Sf.v2");
    check_field_offset(lv, v3, 3, "BFu16ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu16ll_B_Sf(Test_BFu16ll_B_Sf, "BFu16ll_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu16ll_Sf_B()
{
  {
    init_simple_test("BFu16ll_Sf_B");
    static BFu16ll_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu16ll_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu16ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16ll_Sf_B");
    check_field_offset(lv, v2, 2, "BFu16ll_Sf_B.v2");
    check_field_offset(lv, v3, 3, "BFu16ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu16ll_Sf_B(Test_BFu16ll_Sf_B, "BFu16ll_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu16s_B_Sf()
{
  {
    init_simple_test("BFu16s_B_Sf");
    static BFu16s_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu16s_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu16s_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16s_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16s_B_Sf");
    check_field_offset(lv, v2, 2, "BFu16s_B_Sf.v2");
    check_field_offset(lv, v3, 3, "BFu16s_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu16s_B_Sf(Test_BFu16s_B_Sf, "BFu16s_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu16s_Sf_B()
{
  {
    init_simple_test("BFu16s_Sf_B");
    static BFu16s_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu16s_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu16s_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16s_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16s_Sf_B");
    check_field_offset(lv, v2, 2, "BFu16s_Sf_B.v2");
    check_field_offset(lv, v3, 3, "BFu16s_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu16s_Sf_B(Test_BFu16s_Sf_B, "BFu16s_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu17i_B_Sf()
{
  {
    init_simple_test("BFu17i_B_Sf");
    static BFu17i_B_Sf lv;
    check2(sizeof(lv), 5, "sizeof(BFu17i_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu17i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17i_B_Sf");
    check_field_offset(lv, v2, 3, "BFu17i_B_Sf.v2");
    check_field_offset(lv, v3, 4, "BFu17i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu17i_B_Sf(Test_BFu17i_B_Sf, "BFu17i_B_Sf", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu17i_Sf_B()
{
  {
    init_simple_test("BFu17i_Sf_B");
    static BFu17i_Sf_B lv;
    check2(sizeof(lv), 5, "sizeof(BFu17i_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu17i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17i_Sf_B");
    check_field_offset(lv, v2, 3, "BFu17i_Sf_B.v2");
    check_field_offset(lv, v3, 4, "BFu17i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu17i_Sf_B(Test_BFu17i_Sf_B, "BFu17i_Sf_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu17ll_B_Sf()
{
  {
    init_simple_test("BFu17ll_B_Sf");
    static BFu17ll_B_Sf lv;
    check2(sizeof(lv), 5, "sizeof(BFu17ll_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu17ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17ll_B_Sf");
    check_field_offset(lv, v2, 3, "BFu17ll_B_Sf.v2");
    check_field_offset(lv, v3, 4, "BFu17ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu17ll_B_Sf(Test_BFu17ll_B_Sf, "BFu17ll_B_Sf", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu17ll_Sf_B()
{
  {
    init_simple_test("BFu17ll_Sf_B");
    static BFu17ll_Sf_B lv;
    check2(sizeof(lv), 5, "sizeof(BFu17ll_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu17ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17ll_Sf_B");
    check_field_offset(lv, v2, 3, "BFu17ll_Sf_B.v2");
    check_field_offset(lv, v3, 4, "BFu17ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu17ll_Sf_B(Test_BFu17ll_Sf_B, "BFu17ll_Sf_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu1c_B_Sf()
{
  {
    init_simple_test("BFu1c_B_Sf");
    static BFu1c_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(BFu1c_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu1c_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1c_B_Sf");
    check_field_offset(lv, v2, 1, "BFu1c_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu1c_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu1c_B_Sf(Test_BFu1c_B_Sf, "BFu1c_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu1c_Sf_B()
{
  {
    init_simple_test("BFu1c_Sf_B");
    static BFu1c_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(BFu1c_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu1c_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1c_Sf_B");
    check_field_offset(lv, v2, 1, "BFu1c_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu1c_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu1c_Sf_B(Test_BFu1c_Sf_B, "BFu1c_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu1i_B_Sf()
{
  {
    init_simple_test("BFu1i_B_Sf");
    static BFu1i_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(BFu1i_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu1i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1i_B_Sf");
    check_field_offset(lv, v2, 1, "BFu1i_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu1i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu1i_B_Sf(Test_BFu1i_B_Sf, "BFu1i_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu1i_Sf_B()
{
  {
    init_simple_test("BFu1i_Sf_B");
    static BFu1i_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(BFu1i_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu1i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1i_Sf_B");
    check_field_offset(lv, v2, 1, "BFu1i_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu1i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu1i_Sf_B(Test_BFu1i_Sf_B, "BFu1i_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu1ll_B_Sf()
{
  {
    init_simple_test("BFu1ll_B_Sf");
    static BFu1ll_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(BFu1ll_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu1ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1ll_B_Sf");
    check_field_offset(lv, v2, 1, "BFu1ll_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu1ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu1ll_B_Sf(Test_BFu1ll_B_Sf, "BFu1ll_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu1ll_Sf_B()
{
  {
    init_simple_test("BFu1ll_Sf_B");
    static BFu1ll_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(BFu1ll_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu1ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1ll_Sf_B");
    check_field_offset(lv, v2, 1, "BFu1ll_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu1ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu1ll_Sf_B(Test_BFu1ll_Sf_B, "BFu1ll_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu1s_B_Sf()
{
  {
    init_simple_test("BFu1s_B_Sf");
    static BFu1s_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(BFu1s_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu1s_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1s_B_Sf");
    check_field_offset(lv, v2, 1, "BFu1s_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu1s_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu1s_B_Sf(Test_BFu1s_B_Sf, "BFu1s_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu1s_Sf_B()
{
  {
    init_simple_test("BFu1s_Sf_B");
    static BFu1s_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(BFu1s_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu1s_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1s_Sf_B");
    check_field_offset(lv, v2, 1, "BFu1s_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu1s_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu1s_Sf_B(Test_BFu1s_Sf_B, "BFu1s_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu31i_B_Sf()
{
  {
    init_simple_test("BFu31i_B_Sf");
    static BFu31i_B_Sf lv;
    check2(sizeof(lv), 6, "sizeof(BFu31i_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu31i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31i_B_Sf");
    check_field_offset(lv, v2, 4, "BFu31i_B_Sf.v2");
    check_field_offset(lv, v3, 5, "BFu31i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu31i_B_Sf(Test_BFu31i_B_Sf, "BFu31i_B_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu31i_Sf_B()
{
  {
    init_simple_test("BFu31i_Sf_B");
    static BFu31i_Sf_B lv;
    check2(sizeof(lv), 6, "sizeof(BFu31i_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu31i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31i_Sf_B");
    check_field_offset(lv, v2, 4, "BFu31i_Sf_B.v2");
    check_field_offset(lv, v3, 5, "BFu31i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu31i_Sf_B(Test_BFu31i_Sf_B, "BFu31i_Sf_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu31ll_B_Sf()
{
  {
    init_simple_test("BFu31ll_B_Sf");
    static BFu31ll_B_Sf lv;
    check2(sizeof(lv), 6, "sizeof(BFu31ll_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu31ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31ll_B_Sf");
    check_field_offset(lv, v2, 4, "BFu31ll_B_Sf.v2");
    check_field_offset(lv, v3, 5, "BFu31ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu31ll_B_Sf(Test_BFu31ll_B_Sf, "BFu31ll_B_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu31ll_Sf_B()
{
  {
    init_simple_test("BFu31ll_Sf_B");
    static BFu31ll_Sf_B lv;
    check2(sizeof(lv), 6, "sizeof(BFu31ll_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu31ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31ll_Sf_B");
    check_field_offset(lv, v2, 4, "BFu31ll_Sf_B.v2");
    check_field_offset(lv, v3, 5, "BFu31ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu31ll_Sf_B(Test_BFu31ll_Sf_B, "BFu31ll_Sf_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu32i_B_Sf()
{
  {
    init_simple_test("BFu32i_B_Sf");
    static BFu32i_B_Sf lv;
    check2(sizeof(lv), 6, "sizeof(BFu32i_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu32i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32i_B_Sf");
    check_field_offset(lv, v2, 4, "BFu32i_B_Sf.v2");
    check_field_offset(lv, v3, 5, "BFu32i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu32i_B_Sf(Test_BFu32i_B_Sf, "BFu32i_B_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu32i_Sf_B()
{
  {
    init_simple_test("BFu32i_Sf_B");
    static BFu32i_Sf_B lv;
    check2(sizeof(lv), 6, "sizeof(BFu32i_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu32i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32i_Sf_B");
    check_field_offset(lv, v2, 4, "BFu32i_Sf_B.v2");
    check_field_offset(lv, v3, 5, "BFu32i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu32i_Sf_B(Test_BFu32i_Sf_B, "BFu32i_Sf_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu32ll_B_Sf()
{
  {
    init_simple_test("BFu32ll_B_Sf");
    static BFu32ll_B_Sf lv;
    check2(sizeof(lv), 6, "sizeof(BFu32ll_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu32ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32ll_B_Sf");
    check_field_offset(lv, v2, 4, "BFu32ll_B_Sf.v2");
    check_field_offset(lv, v3, 5, "BFu32ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu32ll_B_Sf(Test_BFu32ll_B_Sf, "BFu32ll_B_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu32ll_Sf_B()
{
  {
    init_simple_test("BFu32ll_Sf_B");
    static BFu32ll_Sf_B lv;
    check2(sizeof(lv), 6, "sizeof(BFu32ll_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu32ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32ll_Sf_B");
    check_field_offset(lv, v2, 4, "BFu32ll_Sf_B.v2");
    check_field_offset(lv, v3, 5, "BFu32ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu32ll_Sf_B(Test_BFu32ll_Sf_B, "BFu32ll_Sf_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu33_B_Sf()
{
  {
    init_simple_test("BFu33_B_Sf");
    static BFu33_B_Sf lv;
    check2(sizeof(lv), 7, "sizeof(BFu33_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu33_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu33_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu33_B_Sf");
    check_field_offset(lv, v2, 5, "BFu33_B_Sf.v2");
    check_field_offset(lv, v3, 6, "BFu33_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu33_B_Sf(Test_BFu33_B_Sf, "BFu33_B_Sf", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu33_Sf_B()
{
  {
    init_simple_test("BFu33_Sf_B");
    static BFu33_Sf_B lv;
    check2(sizeof(lv), 7, "sizeof(BFu33_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu33_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu33_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu33_Sf_B");
    check_field_offset(lv, v2, 5, "BFu33_Sf_B.v2");
    check_field_offset(lv, v3, 6, "BFu33_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu33_Sf_B(Test_BFu33_Sf_B, "BFu33_Sf_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu7c_B_Sf()
{
  {
    init_simple_test("BFu7c_B_Sf");
    static BFu7c_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(BFu7c_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu7c_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7c_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7c_B_Sf");
    check_field_offset(lv, v2, 1, "BFu7c_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu7c_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu7c_B_Sf(Test_BFu7c_B_Sf, "BFu7c_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu7c_Sf_B()
{
  {
    init_simple_test("BFu7c_Sf_B");
    static BFu7c_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(BFu7c_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu7c_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7c_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7c_Sf_B");
    check_field_offset(lv, v2, 1, "BFu7c_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu7c_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu7c_Sf_B(Test_BFu7c_Sf_B, "BFu7c_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu7i_B_Sf()
{
  {
    init_simple_test("BFu7i_B_Sf");
    static BFu7i_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(BFu7i_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu7i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7i_B_Sf");
    check_field_offset(lv, v2, 1, "BFu7i_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu7i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu7i_B_Sf(Test_BFu7i_B_Sf, "BFu7i_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu7i_Sf_B()
{
  {
    init_simple_test("BFu7i_Sf_B");
    static BFu7i_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(BFu7i_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu7i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7i_Sf_B");
    check_field_offset(lv, v2, 1, "BFu7i_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu7i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu7i_Sf_B(Test_BFu7i_Sf_B, "BFu7i_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu7ll_B_Sf()
{
  {
    init_simple_test("BFu7ll_B_Sf");
    static BFu7ll_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(BFu7ll_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu7ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7ll_B_Sf");
    check_field_offset(lv, v2, 1, "BFu7ll_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu7ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu7ll_B_Sf(Test_BFu7ll_B_Sf, "BFu7ll_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu7ll_Sf_B()
{
  {
    init_simple_test("BFu7ll_Sf_B");
    static BFu7ll_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(BFu7ll_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu7ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7ll_Sf_B");
    check_field_offset(lv, v2, 1, "BFu7ll_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu7ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu7ll_Sf_B(Test_BFu7ll_Sf_B, "BFu7ll_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu7s_B_Sf()
{
  {
    init_simple_test("BFu7s_B_Sf");
    static BFu7s_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(BFu7s_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu7s_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7s_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7s_B_Sf");
    check_field_offset(lv, v2, 1, "BFu7s_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu7s_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu7s_B_Sf(Test_BFu7s_B_Sf, "BFu7s_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu7s_Sf_B()
{
  {
    init_simple_test("BFu7s_Sf_B");
    static BFu7s_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(BFu7s_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu7s_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7s_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7s_Sf_B");
    check_field_offset(lv, v2, 1, "BFu7s_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu7s_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu7s_Sf_B(Test_BFu7s_Sf_B, "BFu7s_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu8c_B_Sf()
{
  {
    init_simple_test("BFu8c_B_Sf");
    static BFu8c_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(BFu8c_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu8c_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8c_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8c_B_Sf");
    check_field_offset(lv, v2, 1, "BFu8c_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu8c_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu8c_B_Sf(Test_BFu8c_B_Sf, "BFu8c_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu8c_Sf_B()
{
  {
    init_simple_test("BFu8c_Sf_B");
    static BFu8c_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(BFu8c_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu8c_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8c_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8c_Sf_B");
    check_field_offset(lv, v2, 1, "BFu8c_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu8c_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu8c_Sf_B(Test_BFu8c_Sf_B, "BFu8c_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu8i_B_Sf()
{
  {
    init_simple_test("BFu8i_B_Sf");
    static BFu8i_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(BFu8i_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu8i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8i_B_Sf");
    check_field_offset(lv, v2, 1, "BFu8i_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu8i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu8i_B_Sf(Test_BFu8i_B_Sf, "BFu8i_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu8i_Sf_B()
{
  {
    init_simple_test("BFu8i_Sf_B");
    static BFu8i_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(BFu8i_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu8i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8i_Sf_B");
    check_field_offset(lv, v2, 1, "BFu8i_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu8i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu8i_Sf_B(Test_BFu8i_Sf_B, "BFu8i_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu8ll_B_Sf()
{
  {
    init_simple_test("BFu8ll_B_Sf");
    static BFu8ll_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(BFu8ll_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu8ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8ll_B_Sf");
    check_field_offset(lv, v2, 1, "BFu8ll_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu8ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu8ll_B_Sf(Test_BFu8ll_B_Sf, "BFu8ll_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu8ll_Sf_B()
{
  {
    init_simple_test("BFu8ll_Sf_B");
    static BFu8ll_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(BFu8ll_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu8ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8ll_Sf_B");
    check_field_offset(lv, v2, 1, "BFu8ll_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu8ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu8ll_Sf_B(Test_BFu8ll_Sf_B, "BFu8ll_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu8s_B_Sf()
{
  {
    init_simple_test("BFu8s_B_Sf");
    static BFu8s_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(BFu8s_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu8s_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8s_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8s_B_Sf");
    check_field_offset(lv, v2, 1, "BFu8s_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu8s_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu8s_B_Sf(Test_BFu8s_B_Sf, "BFu8s_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu8s_Sf_B()
{
  {
    init_simple_test("BFu8s_Sf_B");
    static BFu8s_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(BFu8s_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu8s_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8s_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8s_Sf_B");
    check_field_offset(lv, v2, 1, "BFu8s_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu8s_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu8s_Sf_B(Test_BFu8s_Sf_B, "BFu8s_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9i_B_Sf()
{
  {
    init_simple_test("BFu9i_B_Sf");
    static BFu9i_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu9i_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9i_B_Sf");
    check_field_offset(lv, v2, 2, "BFu9i_B_Sf.v2");
    check_field_offset(lv, v3, 3, "BFu9i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu9i_B_Sf(Test_BFu9i_B_Sf, "BFu9i_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9i_Sf_B()
{
  {
    init_simple_test("BFu9i_Sf_B");
    static BFu9i_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu9i_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9i_Sf_B");
    check_field_offset(lv, v2, 2, "BFu9i_Sf_B.v2");
    check_field_offset(lv, v3, 3, "BFu9i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9i_Sf_B(Test_BFu9i_Sf_B, "BFu9i_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9ll_B_Sf()
{
  {
    init_simple_test("BFu9ll_B_Sf");
    static BFu9ll_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu9ll_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9ll_B_Sf");
    check_field_offset(lv, v2, 2, "BFu9ll_B_Sf.v2");
    check_field_offset(lv, v3, 3, "BFu9ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu9ll_B_Sf(Test_BFu9ll_B_Sf, "BFu9ll_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9ll_Sf_B()
{
  {
    init_simple_test("BFu9ll_Sf_B");
    static BFu9ll_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu9ll_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9ll_Sf_B");
    check_field_offset(lv, v2, 2, "BFu9ll_Sf_B.v2");
    check_field_offset(lv, v3, 3, "BFu9ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9ll_Sf_B(Test_BFu9ll_Sf_B, "BFu9ll_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_B_Sf()
{
  {
    init_simple_test("BFu9s_B_Sf");
    static BFu9s_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu9s_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_B_Sf");
    check_field_offset(lv, v2, 2, "BFu9s_B_Sf.v2");
    check_field_offset(lv, v3, 3, "BFu9s_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_B_Sf(Test_BFu9s_B_Sf, "BFu9s_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_Sf_B()
{
  {
    init_simple_test("BFu9s_Sf_B");
    static BFu9s_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu9s_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_Sf_B");
    check_field_offset(lv, v2, 2, "BFu9s_Sf_B.v2");
    check_field_offset(lv, v3, 3, "BFu9s_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_Sf_B(Test_BFu9s_Sf_B, "BFu9s_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_Sf()
{
  {
    init_simple_test("C_B_Sf");
    C_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(C_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_Sf)");
    check_field_offset(lv, v1, 0, "C_B_Sf.v1");
    check_field_offset(lv, v2, 1, "C_B_Sf.v2");
    check_field_offset(lv, v3, 2, "C_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vC_B_Sf(Test_C_B_Sf, "C_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_Sf_B()
{
  {
    init_simple_test("C_Sf_B");
    C_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(C_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_Sf_B)");
    check_field_offset(lv, v1, 0, "C_Sf_B.v1");
    check_field_offset(lv, v2, 1, "C_Sf_B.v2");
    check_field_offset(lv, v3, 2, "C_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vC_Sf_B(Test_C_Sf_B, "C_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_Sf()
{
  {
    init_simple_test("D_B_Sf");
    D_B_Sf lv;
    check2(sizeof(lv), 10, "sizeof(D_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_Sf)");
    check_field_offset(lv, v1, 0, "D_B_Sf.v1");
    check_field_offset(lv, v2, 8, "D_B_Sf.v2");
    check_field_offset(lv, v3, 9, "D_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vD_B_Sf(Test_D_B_Sf, "D_B_Sf", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_Sf_B()
{
  {
    init_simple_test("D_Sf_B");
    D_Sf_B lv;
    check2(sizeof(lv), 10, "sizeof(D_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_Sf_B)");
    check_field_offset(lv, v1, 0, "D_Sf_B.v1");
    check_field_offset(lv, v2, 8, "D_Sf_B.v2");
    check_field_offset(lv, v3, 9, "D_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vD_Sf_B(Test_D_Sf_B, "D_Sf_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_Sf()
{
  {
    init_simple_test("F_B_Sf");
    F_B_Sf lv;
    check2(sizeof(lv), 6, "sizeof(F_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_Sf)");
    check_field_offset(lv, v1, 0, "F_B_Sf.v1");
    check_field_offset(lv, v2, 4, "F_B_Sf.v2");
    check_field_offset(lv, v3, 5, "F_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vF_B_Sf(Test_F_B_Sf, "F_B_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_Sf_B()
{
  {
    init_simple_test("F_Sf_B");
    F_Sf_B lv;
    check2(sizeof(lv), 6, "sizeof(F_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_Sf_B)");
    check_field_offset(lv, v1, 0, "F_Sf_B.v1");
    check_field_offset(lv, v2, 4, "F_Sf_B.v2");
    check_field_offset(lv, v3, 5, "F_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vF_Sf_B(Test_F_Sf_B, "F_Sf_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_Sf()
{
  {
    init_simple_test("I_B_Sf");
    I_B_Sf lv;
    check2(sizeof(lv), 6, "sizeof(I_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_Sf)");
    check_field_offset(lv, v1, 0, "I_B_Sf.v1");
    check_field_offset(lv, v2, 4, "I_B_Sf.v2");
    check_field_offset(lv, v3, 5, "I_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vI_B_Sf(Test_I_B_Sf, "I_B_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_Sf_B()
{
  {
    init_simple_test("I_Sf_B");
    I_Sf_B lv;
    check2(sizeof(lv), 6, "sizeof(I_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_Sf_B)");
    check_field_offset(lv, v1, 0, "I_Sf_B.v1");
    check_field_offset(lv, v2, 4, "I_Sf_B.v2");
    check_field_offset(lv, v3, 5, "I_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vI_Sf_B(Test_I_Sf_B, "I_Sf_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_Sf()
{
  {
    init_simple_test("Ip_B_Sf");
    Ip_B_Sf lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_Sf)");
    check_field_offset(lv, v1, 0, "Ip_B_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vIp_B_Sf(Test_Ip_B_Sf, "Ip_B_Sf", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_Sf_B()
{
  {
    init_simple_test("Ip_Sf_B");
    Ip_Sf_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_Sf_B)");
    check_field_offset(lv, v1, 0, "Ip_Sf_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_Sf_B.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vIp_Sf_B(Test_Ip_Sf_B, "Ip_Sf_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_Sf()
{
  {
    init_simple_test("L_B_Sf");
    L_B_Sf lv;
    check2(sizeof(lv), 10, "sizeof(L_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_Sf)");
    check_field_offset(lv, v1, 0, "L_B_Sf.v1");
    check_field_offset(lv, v2, 8, "L_B_Sf.v2");
    check_field_offset(lv, v3, 9, "L_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vL_B_Sf(Test_L_B_Sf, "L_B_Sf", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_Sf_B()
{
  {
    init_simple_test("L_Sf_B");
    L_Sf_B lv;
    check2(sizeof(lv), 10, "sizeof(L_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_Sf_B)");
    check_field_offset(lv, v1, 0, "L_Sf_B.v1");
    check_field_offset(lv, v2, 8, "L_Sf_B.v2");
    check_field_offset(lv, v3, 9, "L_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vL_Sf_B(Test_L_Sf_B, "L_Sf_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_Sf()
{
  {
    init_simple_test("S_B_Sf");
    S_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(S_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_Sf)");
    check_field_offset(lv, v1, 0, "S_B_Sf.v1");
    check_field_offset(lv, v2, 2, "S_B_Sf.v2");
    check_field_offset(lv, v3, 3, "S_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vS_B_Sf(Test_S_B_Sf, "S_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_Sf_B()
{
  {
    init_simple_test("S_Sf_B");
    S_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(S_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_Sf_B)");
    check_field_offset(lv, v1, 0, "S_Sf_B.v1");
    check_field_offset(lv, v2, 2, "S_Sf_B.v2");
    check_field_offset(lv, v3, 3, "S_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vS_Sf_B(Test_S_Sf_B, "S_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B()
{
  {
    init_simple_test("Sf_B");
    Sf_B lv;
    check2(sizeof(lv), 2, "sizeof(Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B)");
    check_field_offset(lv, v1, 0, "Sf_B.v1");
    check_field_offset(lv, v2, 1, "Sf_B.v2");
  }
}
static Arrange_To_Call_Me vSf_B(Test_Sf_B, "Sf_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_B()
{
  {
    init_simple_test("Sf_B_B");
    Sf_B_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_B)");
    check_field_offset(lv, v1, 0, "Sf_B_B.v1");
    check_field_offset(lv, v2, 1, "Sf_B_B.v2");
    check_field_offset(lv, v3, 2, "Sf_B_B.v3");
  }
}
static Arrange_To_Call_Me vSf_B_B(Test_Sf_B_B, "Sf_B_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu15i()
{
  {
    init_simple_test("Sf_B_BFu15i");
    static Sf_B_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu15i)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu15i.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu15i.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "Sf_B_BFu15i");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "Sf_B_BFu15i");
  }
}
static Arrange_To_Call_Me vSf_B_BFu15i(Test_Sf_B_BFu15i, "Sf_B_BFu15i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu15ll()
{
  {
    init_simple_test("Sf_B_BFu15ll");
    static Sf_B_BFu15ll lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu15ll)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu15ll.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu15ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "Sf_B_BFu15ll");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "Sf_B_BFu15ll");
  }
}
static Arrange_To_Call_Me vSf_B_BFu15ll(Test_Sf_B_BFu15ll, "Sf_B_BFu15ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu15s()
{
  {
    init_simple_test("Sf_B_BFu15s");
    static Sf_B_BFu15s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu15s)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu15s.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu15s.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "Sf_B_BFu15s");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "Sf_B_BFu15s");
  }
}
static Arrange_To_Call_Me vSf_B_BFu15s(Test_Sf_B_BFu15s, "Sf_B_BFu15s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu16i()
{
  {
    init_simple_test("Sf_B_BFu16i");
    static Sf_B_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu16i)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu16i.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu16i.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "Sf_B_BFu16i");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "Sf_B_BFu16i");
  }
}
static Arrange_To_Call_Me vSf_B_BFu16i(Test_Sf_B_BFu16i, "Sf_B_BFu16i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu16ll()
{
  {
    init_simple_test("Sf_B_BFu16ll");
    static Sf_B_BFu16ll lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu16ll)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu16ll.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu16ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "Sf_B_BFu16ll");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "Sf_B_BFu16ll");
  }
}
static Arrange_To_Call_Me vSf_B_BFu16ll(Test_Sf_B_BFu16ll, "Sf_B_BFu16ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu16s()
{
  {
    init_simple_test("Sf_B_BFu16s");
    static Sf_B_BFu16s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu16s)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu16s.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu16s.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "Sf_B_BFu16s");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "Sf_B_BFu16s");
  }
}
static Arrange_To_Call_Me vSf_B_BFu16s(Test_Sf_B_BFu16s, "Sf_B_BFu16s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu17i()
{
  {
    init_simple_test("Sf_B_BFu17i");
    static Sf_B_BFu17i lv;
    check2(sizeof(lv), 5, "sizeof(Sf_B_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu17i)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu17i.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu17i.v2");
    set_bf_and_test(lv, v3, 2, 0, 17, 1, "Sf_B_BFu17i");
    set_bf_and_test(lv, v3, 2, 0, 17, hide_ull(1LL<<16), "Sf_B_BFu17i");
  }
}
static Arrange_To_Call_Me vSf_B_BFu17i(Test_Sf_B_BFu17i, "Sf_B_BFu17i", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu17ll()
{
  {
    init_simple_test("Sf_B_BFu17ll");
    static Sf_B_BFu17ll lv;
    check2(sizeof(lv), 5, "sizeof(Sf_B_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu17ll)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu17ll.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu17ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 17, 1, "Sf_B_BFu17ll");
    set_bf_and_test(lv, v3, 2, 0, 17, hide_ull(1LL<<16), "Sf_B_BFu17ll");
  }
}
static Arrange_To_Call_Me vSf_B_BFu17ll(Test_Sf_B_BFu17ll, "Sf_B_BFu17ll", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu1c()
{
  {
    init_simple_test("Sf_B_BFu1c");
    static Sf_B_BFu1c lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu1c)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu1c.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu1c.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Sf_B_BFu1c");
  }
}
static Arrange_To_Call_Me vSf_B_BFu1c(Test_Sf_B_BFu1c, "Sf_B_BFu1c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu1i()
{
  {
    init_simple_test("Sf_B_BFu1i");
    static Sf_B_BFu1i lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu1i)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu1i.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu1i.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Sf_B_BFu1i");
  }
}
static Arrange_To_Call_Me vSf_B_BFu1i(Test_Sf_B_BFu1i, "Sf_B_BFu1i", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu1ll()
{
  {
    init_simple_test("Sf_B_BFu1ll");
    static Sf_B_BFu1ll lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu1ll)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu1ll.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu1ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Sf_B_BFu1ll");
  }
}
static Arrange_To_Call_Me vSf_B_BFu1ll(Test_Sf_B_BFu1ll, "Sf_B_BFu1ll", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu1s()
{
  {
    init_simple_test("Sf_B_BFu1s");
    static Sf_B_BFu1s lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu1s)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu1s.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu1s.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Sf_B_BFu1s");
  }
}
static Arrange_To_Call_Me vSf_B_BFu1s(Test_Sf_B_BFu1s, "Sf_B_BFu1s", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu31i()
{
  {
    init_simple_test("Sf_B_BFu31i");
    static Sf_B_BFu31i lv;
    check2(sizeof(lv), 6, "sizeof(Sf_B_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu31i)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu31i.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu31i.v2");
    set_bf_and_test(lv, v3, 2, 0, 31, 1, "Sf_B_BFu31i");
    set_bf_and_test(lv, v3, 2, 0, 31, hide_ull(1LL<<30), "Sf_B_BFu31i");
  }
}
static Arrange_To_Call_Me vSf_B_BFu31i(Test_Sf_B_BFu31i, "Sf_B_BFu31i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu31ll()
{
  {
    init_simple_test("Sf_B_BFu31ll");
    static Sf_B_BFu31ll lv;
    check2(sizeof(lv), 6, "sizeof(Sf_B_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu31ll)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu31ll.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu31ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 31, 1, "Sf_B_BFu31ll");
    set_bf_and_test(lv, v3, 2, 0, 31, hide_ull(1LL<<30), "Sf_B_BFu31ll");
  }
}
static Arrange_To_Call_Me vSf_B_BFu31ll(Test_Sf_B_BFu31ll, "Sf_B_BFu31ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu32i()
{
  {
    init_simple_test("Sf_B_BFu32i");
    static Sf_B_BFu32i lv;
    check2(sizeof(lv), 6, "sizeof(Sf_B_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu32i)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu32i.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu32i.v2");
    set_bf_and_test(lv, v3, 2, 0, 32, 1, "Sf_B_BFu32i");
    set_bf_and_test(lv, v3, 2, 0, 32, hide_ull(1LL<<31), "Sf_B_BFu32i");
  }
}
static Arrange_To_Call_Me vSf_B_BFu32i(Test_Sf_B_BFu32i, "Sf_B_BFu32i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu32ll()
{
  {
    init_simple_test("Sf_B_BFu32ll");
    static Sf_B_BFu32ll lv;
    check2(sizeof(lv), 6, "sizeof(Sf_B_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu32ll)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu32ll.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu32ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 32, 1, "Sf_B_BFu32ll");
    set_bf_and_test(lv, v3, 2, 0, 32, hide_ull(1LL<<31), "Sf_B_BFu32ll");
  }
}
static Arrange_To_Call_Me vSf_B_BFu32ll(Test_Sf_B_BFu32ll, "Sf_B_BFu32ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu33()
{
  {
    init_simple_test("Sf_B_BFu33");
    static Sf_B_BFu33 lv;
    check2(sizeof(lv), 7, "sizeof(Sf_B_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu33)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu33.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu33.v2");
    set_bf_and_test(lv, v3, 2, 0, 33, 1, "Sf_B_BFu33");
    set_bf_and_test(lv, v3, 2, 0, 33, hide_ull(1LL<<32), "Sf_B_BFu33");
  }
}
static Arrange_To_Call_Me vSf_B_BFu33(Test_Sf_B_BFu33, "Sf_B_BFu33", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu7c()
{
  {
    init_simple_test("Sf_B_BFu7c");
    static Sf_B_BFu7c lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu7c)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu7c.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu7c.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Sf_B_BFu7c");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Sf_B_BFu7c");
  }
}
static Arrange_To_Call_Me vSf_B_BFu7c(Test_Sf_B_BFu7c, "Sf_B_BFu7c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu7i()
{
  {
    init_simple_test("Sf_B_BFu7i");
    static Sf_B_BFu7i lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu7i)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu7i.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu7i.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Sf_B_BFu7i");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Sf_B_BFu7i");
  }
}
static Arrange_To_Call_Me vSf_B_BFu7i(Test_Sf_B_BFu7i, "Sf_B_BFu7i", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu7ll()
{
  {
    init_simple_test("Sf_B_BFu7ll");
    static Sf_B_BFu7ll lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu7ll)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu7ll.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu7ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Sf_B_BFu7ll");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Sf_B_BFu7ll");
  }
}
static Arrange_To_Call_Me vSf_B_BFu7ll(Test_Sf_B_BFu7ll, "Sf_B_BFu7ll", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu7s()
{
  {
    init_simple_test("Sf_B_BFu7s");
    static Sf_B_BFu7s lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu7s)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu7s.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu7s.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Sf_B_BFu7s");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Sf_B_BFu7s");
  }
}
static Arrange_To_Call_Me vSf_B_BFu7s(Test_Sf_B_BFu7s, "Sf_B_BFu7s", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu8c()
{
  {
    init_simple_test("Sf_B_BFu8c");
    static Sf_B_BFu8c lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu8c)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu8c.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu8c.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Sf_B_BFu8c");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Sf_B_BFu8c");
  }
}
static Arrange_To_Call_Me vSf_B_BFu8c(Test_Sf_B_BFu8c, "Sf_B_BFu8c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu8i()
{
  {
    init_simple_test("Sf_B_BFu8i");
    static Sf_B_BFu8i lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu8i)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu8i.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu8i.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Sf_B_BFu8i");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Sf_B_BFu8i");
  }
}
static Arrange_To_Call_Me vSf_B_BFu8i(Test_Sf_B_BFu8i, "Sf_B_BFu8i", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu8ll()
{
  {
    init_simple_test("Sf_B_BFu8ll");
    static Sf_B_BFu8ll lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu8ll)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu8ll.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu8ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Sf_B_BFu8ll");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Sf_B_BFu8ll");
  }
}
static Arrange_To_Call_Me vSf_B_BFu8ll(Test_Sf_B_BFu8ll, "Sf_B_BFu8ll", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu8s()
{
  {
    init_simple_test("Sf_B_BFu8s");
    static Sf_B_BFu8s lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu8s)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu8s.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu8s.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Sf_B_BFu8s");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Sf_B_BFu8s");
  }
}
static Arrange_To_Call_Me vSf_B_BFu8s(Test_Sf_B_BFu8s, "Sf_B_BFu8s", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu9i()
{
  {
    init_simple_test("Sf_B_BFu9i");
    static Sf_B_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu9i)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu9i.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu9i.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "Sf_B_BFu9i");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "Sf_B_BFu9i");
  }
}
static Arrange_To_Call_Me vSf_B_BFu9i(Test_Sf_B_BFu9i, "Sf_B_BFu9i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu9ll()
{
  {
    init_simple_test("Sf_B_BFu9ll");
    static Sf_B_BFu9ll lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu9ll)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu9ll.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu9ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "Sf_B_BFu9ll");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "Sf_B_BFu9ll");
  }
}
static Arrange_To_Call_Me vSf_B_BFu9ll(Test_Sf_B_BFu9ll, "Sf_B_BFu9ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_BFu9s()
{
  {
    init_simple_test("Sf_B_BFu9s");
    static Sf_B_BFu9s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu9s)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu9s.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu9s.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "Sf_B_BFu9s");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "Sf_B_BFu9s");
  }
}
static Arrange_To_Call_Me vSf_B_BFu9s(Test_Sf_B_BFu9s, "Sf_B_BFu9s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_C()
{
  {
    init_simple_test("Sf_B_C");
    Sf_B_C lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_C)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_C)");
    check_field_offset(lv, v1, 0, "Sf_B_C.v1");
    check_field_offset(lv, v2, 1, "Sf_B_C.v2");
    check_field_offset(lv, v3, 2, "Sf_B_C.v3");
  }
}
static Arrange_To_Call_Me vSf_B_C(Test_Sf_B_C, "Sf_B_C", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_D()
{
  {
    init_simple_test("Sf_B_D");
    Sf_B_D lv;
    check2(sizeof(lv), 10, "sizeof(Sf_B_D)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_D)");
    check_field_offset(lv, v1, 0, "Sf_B_D.v1");
    check_field_offset(lv, v2, 1, "Sf_B_D.v2");
    check_field_offset(lv, v3, 2, "Sf_B_D.v3");
  }
}
static Arrange_To_Call_Me vSf_B_D(Test_Sf_B_D, "Sf_B_D", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_F()
{
  {
    init_simple_test("Sf_B_F");
    Sf_B_F lv;
    check2(sizeof(lv), 6, "sizeof(Sf_B_F)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_F)");
    check_field_offset(lv, v1, 0, "Sf_B_F.v1");
    check_field_offset(lv, v2, 1, "Sf_B_F.v2");
    check_field_offset(lv, v3, 2, "Sf_B_F.v3");
  }
}
static Arrange_To_Call_Me vSf_B_F(Test_Sf_B_F, "Sf_B_F", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_I()
{
  {
    init_simple_test("Sf_B_I");
    Sf_B_I lv;
    check2(sizeof(lv), 6, "sizeof(Sf_B_I)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_I)");
    check_field_offset(lv, v1, 0, "Sf_B_I.v1");
    check_field_offset(lv, v2, 1, "Sf_B_I.v2");
    check_field_offset(lv, v3, 2, "Sf_B_I.v3");
  }
}
static Arrange_To_Call_Me vSf_B_I(Test_Sf_B_I, "Sf_B_I", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_Ip()
{
  {
    init_simple_test("Sf_B_Ip");
    Sf_B_Ip lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_B_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_Ip)");
    check_field_offset(lv, v1, 0, "Sf_B_Ip.v1");
    check_field_offset(lv, v2, 1, "Sf_B_Ip.v2");
    check_field_offset(lv, v3, 2, "Sf_B_Ip.v3");
  }
}
static Arrange_To_Call_Me vSf_B_Ip(Test_Sf_B_Ip, "Sf_B_Ip", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_L()
{
  {
    init_simple_test("Sf_B_L");
    Sf_B_L lv;
    check2(sizeof(lv), 10, "sizeof(Sf_B_L)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_L)");
    check_field_offset(lv, v1, 0, "Sf_B_L.v1");
    check_field_offset(lv, v2, 1, "Sf_B_L.v2");
    check_field_offset(lv, v3, 2, "Sf_B_L.v3");
  }
}
static Arrange_To_Call_Me vSf_B_L(Test_Sf_B_L, "Sf_B_L", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_S()
{
  {
    init_simple_test("Sf_B_S");
    Sf_B_S lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_S)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_S)");
    check_field_offset(lv, v1, 0, "Sf_B_S.v1");
    check_field_offset(lv, v2, 1, "Sf_B_S.v2");
    check_field_offset(lv, v3, 2, "Sf_B_S.v3");
  }
}
static Arrange_To_Call_Me vSf_B_S(Test_Sf_B_S, "Sf_B_S", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_Sf()
{
  {
    init_simple_test("Sf_B_Sf");
    Sf_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_Sf)");
    check_field_offset(lv, v1, 0, "Sf_B_Sf.v1");
    check_field_offset(lv, v2, 1, "Sf_B_Sf.v2");
    check_field_offset(lv, v3, 2, "Sf_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vSf_B_Sf(Test_Sf_B_Sf, "Sf_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_Uc()
{
  {
    init_simple_test("Sf_B_Uc");
    Sf_B_Uc lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_Uc)");
    check_field_offset(lv, v1, 0, "Sf_B_Uc.v1");
    check_field_offset(lv, v2, 1, "Sf_B_Uc.v2");
    check_field_offset(lv, v3, 2, "Sf_B_Uc.v3");
  }
}
static Arrange_To_Call_Me vSf_B_Uc(Test_Sf_B_Uc, "Sf_B_Uc", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_Ui()
{
  {
    init_simple_test("Sf_B_Ui");
    Sf_B_Ui lv;
    check2(sizeof(lv), 6, "sizeof(Sf_B_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_Ui)");
    check_field_offset(lv, v1, 0, "Sf_B_Ui.v1");
    check_field_offset(lv, v2, 1, "Sf_B_Ui.v2");
    check_field_offset(lv, v3, 2, "Sf_B_Ui.v3");
  }
}
static Arrange_To_Call_Me vSf_B_Ui(Test_Sf_B_Ui, "Sf_B_Ui", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_Ul()
{
  {
    init_simple_test("Sf_B_Ul");
    Sf_B_Ul lv;
    check2(sizeof(lv), 10, "sizeof(Sf_B_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_Ul)");
    check_field_offset(lv, v1, 0, "Sf_B_Ul.v1");
    check_field_offset(lv, v2, 1, "Sf_B_Ul.v2");
    check_field_offset(lv, v3, 2, "Sf_B_Ul.v3");
  }
}
static Arrange_To_Call_Me vSf_B_Ul(Test_Sf_B_Ul, "Sf_B_Ul", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_Us()
{
  {
    init_simple_test("Sf_B_Us");
    Sf_B_Us lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_Us)");
    check_field_offset(lv, v1, 0, "Sf_B_Us.v1");
    check_field_offset(lv, v2, 1, "Sf_B_Us.v2");
    check_field_offset(lv, v3, 2, "Sf_B_Us.v3");
  }
}
static Arrange_To_Call_Me vSf_B_Us(Test_Sf_B_Us, "Sf_B_Us", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_B_Vp()
{
  {
    init_simple_test("Sf_B_Vp");
    Sf_B_Vp lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_B_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_Vp)");
    check_field_offset(lv, v1, 0, "Sf_B_Vp.v1");
    check_field_offset(lv, v2, 1, "Sf_B_Vp.v2");
    check_field_offset(lv, v3, 2, "Sf_B_Vp.v3");
  }
}
static Arrange_To_Call_Me vSf_B_Vp(Test_Sf_B_Vp, "Sf_B_Vp", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu15i_B()
{
  {
    init_simple_test("Sf_BFu15i_B");
    static Sf_BFu15i_B lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu15i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu15i_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu15i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "Sf_BFu15i_B");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "Sf_BFu15i_B");
    check_field_offset(lv, v3, 3, "Sf_BFu15i_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu15i_B(Test_Sf_BFu15i_B, "Sf_BFu15i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu15ll_B()
{
  {
    init_simple_test("Sf_BFu15ll_B");
    static Sf_BFu15ll_B lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu15ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu15ll_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu15ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "Sf_BFu15ll_B");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "Sf_BFu15ll_B");
    check_field_offset(lv, v3, 3, "Sf_BFu15ll_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu15ll_B(Test_Sf_BFu15ll_B, "Sf_BFu15ll_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu15s_B()
{
  {
    init_simple_test("Sf_BFu15s_B");
    static Sf_BFu15s_B lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu15s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu15s_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu15s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "Sf_BFu15s_B");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "Sf_BFu15s_B");
    check_field_offset(lv, v3, 3, "Sf_BFu15s_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu15s_B(Test_Sf_BFu15s_B, "Sf_BFu15s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu16i_B()
{
  {
    init_simple_test("Sf_BFu16i_B");
    static Sf_BFu16i_B lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu16i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu16i_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu16i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "Sf_BFu16i_B");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "Sf_BFu16i_B");
    check_field_offset(lv, v3, 3, "Sf_BFu16i_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu16i_B(Test_Sf_BFu16i_B, "Sf_BFu16i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu16ll_B()
{
  {
    init_simple_test("Sf_BFu16ll_B");
    static Sf_BFu16ll_B lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu16ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu16ll_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu16ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "Sf_BFu16ll_B");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "Sf_BFu16ll_B");
    check_field_offset(lv, v3, 3, "Sf_BFu16ll_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu16ll_B(Test_Sf_BFu16ll_B, "Sf_BFu16ll_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu16s_B()
{
  {
    init_simple_test("Sf_BFu16s_B");
    static Sf_BFu16s_B lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu16s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu16s_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu16s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "Sf_BFu16s_B");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "Sf_BFu16s_B");
    check_field_offset(lv, v3, 3, "Sf_BFu16s_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu16s_B(Test_Sf_BFu16s_B, "Sf_BFu16s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu17i_B()
{
  {
    init_simple_test("Sf_BFu17i_B");
    static Sf_BFu17i_B lv;
    check2(sizeof(lv), 5, "sizeof(Sf_BFu17i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu17i_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu17i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "Sf_BFu17i_B");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "Sf_BFu17i_B");
    check_field_offset(lv, v3, 4, "Sf_BFu17i_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu17i_B(Test_Sf_BFu17i_B, "Sf_BFu17i_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu17ll_B()
{
  {
    init_simple_test("Sf_BFu17ll_B");
    static Sf_BFu17ll_B lv;
    check2(sizeof(lv), 5, "sizeof(Sf_BFu17ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu17ll_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu17ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "Sf_BFu17ll_B");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "Sf_BFu17ll_B");
    check_field_offset(lv, v3, 4, "Sf_BFu17ll_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu17ll_B(Test_Sf_BFu17ll_B, "Sf_BFu17ll_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu1c_B()
{
  {
    init_simple_test("Sf_BFu1c_B");
    static Sf_BFu1c_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu1c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu1c_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu1c_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "Sf_BFu1c_B");
    check_field_offset(lv, v3, 2, "Sf_BFu1c_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu1c_B(Test_Sf_BFu1c_B, "Sf_BFu1c_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu1i_B()
{
  {
    init_simple_test("Sf_BFu1i_B");
    static Sf_BFu1i_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu1i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu1i_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu1i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "Sf_BFu1i_B");
    check_field_offset(lv, v3, 2, "Sf_BFu1i_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu1i_B(Test_Sf_BFu1i_B, "Sf_BFu1i_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu1ll_B()
{
  {
    init_simple_test("Sf_BFu1ll_B");
    static Sf_BFu1ll_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu1ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu1ll_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu1ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "Sf_BFu1ll_B");
    check_field_offset(lv, v3, 2, "Sf_BFu1ll_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu1ll_B(Test_Sf_BFu1ll_B, "Sf_BFu1ll_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu1s_B()
{
  {
    init_simple_test("Sf_BFu1s_B");
    static Sf_BFu1s_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu1s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu1s_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu1s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "Sf_BFu1s_B");
    check_field_offset(lv, v3, 2, "Sf_BFu1s_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu1s_B(Test_Sf_BFu1s_B, "Sf_BFu1s_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu31i_B()
{
  {
    init_simple_test("Sf_BFu31i_B");
    static Sf_BFu31i_B lv;
    check2(sizeof(lv), 6, "sizeof(Sf_BFu31i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu31i_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu31i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "Sf_BFu31i_B");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "Sf_BFu31i_B");
    check_field_offset(lv, v3, 5, "Sf_BFu31i_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu31i_B(Test_Sf_BFu31i_B, "Sf_BFu31i_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu31ll_B()
{
  {
    init_simple_test("Sf_BFu31ll_B");
    static Sf_BFu31ll_B lv;
    check2(sizeof(lv), 6, "sizeof(Sf_BFu31ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu31ll_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu31ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "Sf_BFu31ll_B");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "Sf_BFu31ll_B");
    check_field_offset(lv, v3, 5, "Sf_BFu31ll_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu31ll_B(Test_Sf_BFu31ll_B, "Sf_BFu31ll_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu32i_B()
{
  {
    init_simple_test("Sf_BFu32i_B");
    static Sf_BFu32i_B lv;
    check2(sizeof(lv), 6, "sizeof(Sf_BFu32i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu32i_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu32i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "Sf_BFu32i_B");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "Sf_BFu32i_B");
    check_field_offset(lv, v3, 5, "Sf_BFu32i_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu32i_B(Test_Sf_BFu32i_B, "Sf_BFu32i_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu32ll_B()
{
  {
    init_simple_test("Sf_BFu32ll_B");
    static Sf_BFu32ll_B lv;
    check2(sizeof(lv), 6, "sizeof(Sf_BFu32ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu32ll_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu32ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "Sf_BFu32ll_B");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "Sf_BFu32ll_B");
    check_field_offset(lv, v3, 5, "Sf_BFu32ll_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu32ll_B(Test_Sf_BFu32ll_B, "Sf_BFu32ll_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu33_B()
{
  {
    init_simple_test("Sf_BFu33_B");
    static Sf_BFu33_B lv;
    check2(sizeof(lv), 7, "sizeof(Sf_BFu33_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu33_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu33_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 33, 1, "Sf_BFu33_B");
    set_bf_and_test(lv, v2, 1, 0, 33, hide_ull(1LL<<32), "Sf_BFu33_B");
    check_field_offset(lv, v3, 6, "Sf_BFu33_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu33_B(Test_Sf_BFu33_B, "Sf_BFu33_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu7c_B()
{
  {
    init_simple_test("Sf_BFu7c_B");
    static Sf_BFu7c_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu7c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu7c_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu7c_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "Sf_BFu7c_B");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "Sf_BFu7c_B");
    check_field_offset(lv, v3, 2, "Sf_BFu7c_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu7c_B(Test_Sf_BFu7c_B, "Sf_BFu7c_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu7i_B()
{
  {
    init_simple_test("Sf_BFu7i_B");
    static Sf_BFu7i_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu7i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu7i_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu7i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "Sf_BFu7i_B");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "Sf_BFu7i_B");
    check_field_offset(lv, v3, 2, "Sf_BFu7i_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu7i_B(Test_Sf_BFu7i_B, "Sf_BFu7i_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu7ll_B()
{
  {
    init_simple_test("Sf_BFu7ll_B");
    static Sf_BFu7ll_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu7ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu7ll_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu7ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "Sf_BFu7ll_B");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "Sf_BFu7ll_B");
    check_field_offset(lv, v3, 2, "Sf_BFu7ll_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu7ll_B(Test_Sf_BFu7ll_B, "Sf_BFu7ll_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu7s_B()
{
  {
    init_simple_test("Sf_BFu7s_B");
    static Sf_BFu7s_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu7s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu7s_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu7s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "Sf_BFu7s_B");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "Sf_BFu7s_B");
    check_field_offset(lv, v3, 2, "Sf_BFu7s_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu7s_B(Test_Sf_BFu7s_B, "Sf_BFu7s_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu8c_B()
{
  {
    init_simple_test("Sf_BFu8c_B");
    static Sf_BFu8c_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu8c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu8c_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu8c_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "Sf_BFu8c_B");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "Sf_BFu8c_B");
    check_field_offset(lv, v3, 2, "Sf_BFu8c_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu8c_B(Test_Sf_BFu8c_B, "Sf_BFu8c_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu8i_B()
{
  {
    init_simple_test("Sf_BFu8i_B");
    static Sf_BFu8i_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu8i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu8i_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu8i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "Sf_BFu8i_B");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "Sf_BFu8i_B");
    check_field_offset(lv, v3, 2, "Sf_BFu8i_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu8i_B(Test_Sf_BFu8i_B, "Sf_BFu8i_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu8ll_B()
{
  {
    init_simple_test("Sf_BFu8ll_B");
    static Sf_BFu8ll_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu8ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu8ll_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu8ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "Sf_BFu8ll_B");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "Sf_BFu8ll_B");
    check_field_offset(lv, v3, 2, "Sf_BFu8ll_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu8ll_B(Test_Sf_BFu8ll_B, "Sf_BFu8ll_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu8s_B()
{
  {
    init_simple_test("Sf_BFu8s_B");
    static Sf_BFu8s_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu8s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu8s_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu8s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "Sf_BFu8s_B");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "Sf_BFu8s_B");
    check_field_offset(lv, v3, 2, "Sf_BFu8s_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu8s_B(Test_Sf_BFu8s_B, "Sf_BFu8s_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu9i_B()
{
  {
    init_simple_test("Sf_BFu9i_B");
    static Sf_BFu9i_B lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu9i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9i_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu9i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "Sf_BFu9i_B");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "Sf_BFu9i_B");
    check_field_offset(lv, v3, 3, "Sf_BFu9i_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu9i_B(Test_Sf_BFu9i_B, "Sf_BFu9i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu9ll_B()
{
  {
    init_simple_test("Sf_BFu9ll_B");
    static Sf_BFu9ll_B lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu9ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9ll_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu9ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "Sf_BFu9ll_B");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "Sf_BFu9ll_B");
    check_field_offset(lv, v3, 3, "Sf_BFu9ll_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu9ll_B(Test_Sf_BFu9ll_B, "Sf_BFu9ll_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_BFu9s_B()
{
  {
    init_simple_test("Sf_BFu9s_B");
    static Sf_BFu9s_B lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu9s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu9s_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "Sf_BFu9s_B");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_B");
    check_field_offset(lv, v3, 3, "Sf_BFu9s_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu9s_B(Test_Sf_BFu9s_B, "Sf_BFu9s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_C_B()
{
  {
    init_simple_test("Sf_C_B");
    Sf_C_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_C_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_B)");
    check_field_offset(lv, v1, 0, "Sf_C_B.v1");
    check_field_offset(lv, v2, 1, "Sf_C_B.v2");
    check_field_offset(lv, v3, 2, "Sf_C_B.v3");
  }
}
static Arrange_To_Call_Me vSf_C_B(Test_Sf_C_B, "Sf_C_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_D_B()
{
  {
    init_simple_test("Sf_D_B");
    Sf_D_B lv;
    check2(sizeof(lv), 10, "sizeof(Sf_D_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_D_B)");
    check_field_offset(lv, v1, 0, "Sf_D_B.v1");
    check_field_offset(lv, v2, 1, "Sf_D_B.v2");
    check_field_offset(lv, v3, 9, "Sf_D_B.v3");
  }
}
static Arrange_To_Call_Me vSf_D_B(Test_Sf_D_B, "Sf_D_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_F_B()
{
  {
    init_simple_test("Sf_F_B");
    Sf_F_B lv;
    check2(sizeof(lv), 6, "sizeof(Sf_F_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_F_B)");
    check_field_offset(lv, v1, 0, "Sf_F_B.v1");
    check_field_offset(lv, v2, 1, "Sf_F_B.v2");
    check_field_offset(lv, v3, 5, "Sf_F_B.v3");
  }
}
static Arrange_To_Call_Me vSf_F_B(Test_Sf_F_B, "Sf_F_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_I_B()
{
  {
    init_simple_test("Sf_I_B");
    Sf_I_B lv;
    check2(sizeof(lv), 6, "sizeof(Sf_I_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_I_B)");
    check_field_offset(lv, v1, 0, "Sf_I_B.v1");
    check_field_offset(lv, v2, 1, "Sf_I_B.v2");
    check_field_offset(lv, v3, 5, "Sf_I_B.v3");
  }
}
static Arrange_To_Call_Me vSf_I_B(Test_Sf_I_B, "Sf_I_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_Ip_B()
{
  {
    init_simple_test("Sf_Ip_B");
    Sf_Ip_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Ip_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ip_B)");
    check_field_offset(lv, v1, 0, "Sf_Ip_B.v1");
    check_field_offset(lv, v2, 1, "Sf_Ip_B.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Sf_Ip_B.v3");
  }
}
static Arrange_To_Call_Me vSf_Ip_B(Test_Sf_Ip_B, "Sf_Ip_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_L_B()
{
  {
    init_simple_test("Sf_L_B");
    Sf_L_B lv;
    check2(sizeof(lv), 10, "sizeof(Sf_L_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_L_B)");
    check_field_offset(lv, v1, 0, "Sf_L_B.v1");
    check_field_offset(lv, v2, 1, "Sf_L_B.v2");
    check_field_offset(lv, v3, 9, "Sf_L_B.v3");
  }
}
static Arrange_To_Call_Me vSf_L_B(Test_Sf_L_B, "Sf_L_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_S_B()
{
  {
    init_simple_test("Sf_S_B");
    Sf_S_B lv;
    check2(sizeof(lv), 4, "sizeof(Sf_S_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_S_B)");
    check_field_offset(lv, v1, 0, "Sf_S_B.v1");
    check_field_offset(lv, v2, 1, "Sf_S_B.v2");
    check_field_offset(lv, v3, 3, "Sf_S_B.v3");
  }
}
static Arrange_To_Call_Me vSf_S_B(Test_Sf_S_B, "Sf_S_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_Sf_B()
{
  {
    init_simple_test("Sf_Sf_B");
    Sf_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_B)");
    check_field_offset(lv, v1, 0, "Sf_Sf_B.v1");
    check_field_offset(lv, v2, 1, "Sf_Sf_B.v2");
    check_field_offset(lv, v3, 2, "Sf_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vSf_Sf_B(Test_Sf_Sf_B, "Sf_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_Uc_B()
{
  {
    init_simple_test("Sf_Uc_B");
    Sf_Uc_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Uc_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_B)");
    check_field_offset(lv, v1, 0, "Sf_Uc_B.v1");
    check_field_offset(lv, v2, 1, "Sf_Uc_B.v2");
    check_field_offset(lv, v3, 2, "Sf_Uc_B.v3");
  }
}
static Arrange_To_Call_Me vSf_Uc_B(Test_Sf_Uc_B, "Sf_Uc_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_Ui_B()
{
  {
    init_simple_test("Sf_Ui_B");
    Sf_Ui_B lv;
    check2(sizeof(lv), 6, "sizeof(Sf_Ui_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ui_B)");
    check_field_offset(lv, v1, 0, "Sf_Ui_B.v1");
    check_field_offset(lv, v2, 1, "Sf_Ui_B.v2");
    check_field_offset(lv, v3, 5, "Sf_Ui_B.v3");
  }
}
static Arrange_To_Call_Me vSf_Ui_B(Test_Sf_Ui_B, "Sf_Ui_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_Ul_B()
{
  {
    init_simple_test("Sf_Ul_B");
    Sf_Ul_B lv;
    check2(sizeof(lv), 10, "sizeof(Sf_Ul_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Ul_B)");
    check_field_offset(lv, v1, 0, "Sf_Ul_B.v1");
    check_field_offset(lv, v2, 1, "Sf_Ul_B.v2");
    check_field_offset(lv, v3, 9, "Sf_Ul_B.v3");
  }
}
static Arrange_To_Call_Me vSf_Ul_B(Test_Sf_Ul_B, "Sf_Ul_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_Us_B()
{
  {
    init_simple_test("Sf_Us_B");
    Sf_Us_B lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Us_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Us_B)");
    check_field_offset(lv, v1, 0, "Sf_Us_B.v1");
    check_field_offset(lv, v2, 1, "Sf_Us_B.v2");
    check_field_offset(lv, v3, 3, "Sf_Us_B.v3");
  }
}
static Arrange_To_Call_Me vSf_Us_B(Test_Sf_Us_B, "Sf_Us_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Sf_Vp_B()
{
  {
    init_simple_test("Sf_Vp_B");
    Sf_Vp_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Sf_Vp_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Vp_B)");
    check_field_offset(lv, v1, 0, "Sf_Vp_B.v1");
    check_field_offset(lv, v2, 1, "Sf_Vp_B.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Sf_Vp_B.v3");
  }
}
static Arrange_To_Call_Me vSf_Vp_B(Test_Sf_Vp_B, "Sf_Vp_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_Sf()
{
  {
    init_simple_test("Uc_B_Sf");
    Uc_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Uc_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_Sf)");
    check_field_offset(lv, v1, 0, "Uc_B_Sf.v1");
    check_field_offset(lv, v2, 1, "Uc_B_Sf.v2");
    check_field_offset(lv, v3, 2, "Uc_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vUc_B_Sf(Test_Uc_B_Sf, "Uc_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_Sf_B()
{
  {
    init_simple_test("Uc_Sf_B");
    Uc_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(Uc_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_B)");
    check_field_offset(lv, v1, 0, "Uc_Sf_B.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_B.v2");
    check_field_offset(lv, v3, 2, "Uc_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vUc_Sf_B(Test_Uc_Sf_B, "Uc_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_Sf()
{
  {
    init_simple_test("Ui_B_Sf");
    Ui_B_Sf lv;
    check2(sizeof(lv), 6, "sizeof(Ui_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_Sf)");
    check_field_offset(lv, v1, 0, "Ui_B_Sf.v1");
    check_field_offset(lv, v2, 4, "Ui_B_Sf.v2");
    check_field_offset(lv, v3, 5, "Ui_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vUi_B_Sf(Test_Ui_B_Sf, "Ui_B_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Sf_B()
{
  {
    init_simple_test("Ui_Sf_B");
    Ui_Sf_B lv;
    check2(sizeof(lv), 6, "sizeof(Ui_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Sf_B)");
    check_field_offset(lv, v1, 0, "Ui_Sf_B.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_B.v2");
    check_field_offset(lv, v3, 5, "Ui_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vUi_Sf_B(Test_Ui_Sf_B, "Ui_Sf_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_Sf()
{
  {
    init_simple_test("Ul_B_Sf");
    Ul_B_Sf lv;
    check2(sizeof(lv), 10, "sizeof(Ul_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_Sf)");
    check_field_offset(lv, v1, 0, "Ul_B_Sf.v1");
    check_field_offset(lv, v2, 8, "Ul_B_Sf.v2");
    check_field_offset(lv, v3, 9, "Ul_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vUl_B_Sf(Test_Ul_B_Sf, "Ul_B_Sf", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Sf_B()
{
  {
    init_simple_test("Ul_Sf_B");
    Ul_Sf_B lv;
    check2(sizeof(lv), 10, "sizeof(Ul_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Sf_B)");
    check_field_offset(lv, v1, 0, "Ul_Sf_B.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_B.v2");
    check_field_offset(lv, v3, 9, "Ul_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vUl_Sf_B(Test_Ul_Sf_B, "Ul_Sf_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_Sf()
{
  {
    init_simple_test("Us_B_Sf");
    Us_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Us_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_Sf)");
    check_field_offset(lv, v1, 0, "Us_B_Sf.v1");
    check_field_offset(lv, v2, 2, "Us_B_Sf.v2");
    check_field_offset(lv, v3, 3, "Us_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vUs_B_Sf(Test_Us_B_Sf, "Us_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Sf_B()
{
  {
    init_simple_test("Us_Sf_B");
    Us_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(Us_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Sf_B)");
    check_field_offset(lv, v1, 0, "Us_Sf_B.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_B.v2");
    check_field_offset(lv, v3, 3, "Us_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vUs_Sf_B(Test_Us_Sf_B, "Us_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_Sf()
{
  {
    init_simple_test("Vp_B_Sf");
    Vp_B_Sf lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_Sf)");
    check_field_offset(lv, v1, 0, "Vp_B_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vVp_B_Sf(Test_Vp_B_Sf, "Vp_B_Sf", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Sf_B()
{
  {
    init_simple_test("Vp_Sf_B");
    Vp_Sf_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Sf_B)");
    check_field_offset(lv, v1, 0, "Vp_Sf_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_B.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vVp_Sf_B(Test_Vp_Sf_B, "Vp_Sf_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

