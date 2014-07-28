// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
// RUN: c_compiler -c -o %t1.o -I "common" "common/testsuite.c"
// RUN: cxx_compiler cxx_rtti -c %s -I "common" -o %t2.o
// RUN: linker -o %t2%exeext  %t1.o %t2.o
// RUN: runtool %t2%exeext | checker "TEST PASSED"
#include "testsuite.h"
#ifdef __cplusplus
#pragma pack(1)
struct BFu9s_BFu7i_B { unsigned short v1:9; unsigned int v2:7; bool v3; };
struct BFu9s_BFu7ll_B { unsigned short v1:9; unsigned long long v2:7; bool v3; };
struct BFu9s_BFu7s_B { unsigned short v1:9; unsigned short v2:7; bool v3; };
struct BFu9s_BFu8c_B { unsigned short v1:9; unsigned char v2:8; bool v3; };
struct BFu9s_BFu8i_B { unsigned short v1:9; unsigned int v2:8; bool v3; };
struct BFu9s_BFu8ll_B { unsigned short v1:9; unsigned long long v2:8; bool v3; };
struct BFu9s_BFu8s_B { unsigned short v1:9; unsigned short v2:8; bool v3; };
struct BFu9s_BFu9i_B { unsigned short v1:9; unsigned int v2:9; bool v3; };
struct BFu9s_BFu9ll_B { unsigned short v1:9; unsigned long long v2:9; bool v3; };
struct BFu9s_BFu9s_B { unsigned short v1:9; unsigned short v2:9; bool v3; };
struct BFu9s_C_B { unsigned short v1:9; char v2; bool v3; };
struct BFu9s_D_B { unsigned short v1:9; double v2; bool v3; };
struct BFu9s_F_B { unsigned short v1:9; float v2; bool v3; };
struct BFu9s_I_B { unsigned short v1:9; int v2; bool v3; };
struct BFu9s_Ip_B { unsigned short v1:9; int * v2; bool v3; };
struct BFu9s_L_B { unsigned short v1:9; long long v2; bool v3; };
struct BFu9s_S_B { unsigned short v1:9; short v2; bool v3; };
struct BFu9s_Uc_B { unsigned short v1:9; unsigned char v2; bool v3; };
struct BFu9s_Ui_B { unsigned short v1:9; unsigned int v2; bool v3; };
struct BFu9s_Ul_B { unsigned short v1:9; unsigned long long v2; bool v3; };
struct BFu9s_Us_B { unsigned short v1:9; unsigned short v2; bool v3; };
struct BFu9s_Vp_B { unsigned short v1:9; void * v2; bool v3; };
struct C_B { char v1; bool v2; };
struct C_B_B { char v1; bool v2; bool v3; };
struct C_B_BFu15i { char v1; bool v2; unsigned int v3:15; };
struct C_B_BFu15ll { char v1; bool v2; unsigned long long v3:15; };
struct C_B_BFu15s { char v1; bool v2; unsigned short v3:15; };
struct C_B_BFu16i { char v1; bool v2; unsigned int v3:16; };
struct C_B_BFu16ll { char v1; bool v2; unsigned long long v3:16; };
struct C_B_BFu16s { char v1; bool v2; unsigned short v3:16; };
struct C_B_BFu17i { char v1; bool v2; unsigned int v3:17; };
struct C_B_BFu17ll { char v1; bool v2; unsigned long long v3:17; };
struct C_B_BFu1c { char v1; bool v2; unsigned char v3:1; };
struct C_B_BFu1i { char v1; bool v2; unsigned int v3:1; };
struct C_B_BFu1ll { char v1; bool v2; unsigned long long v3:1; };
struct C_B_BFu1s { char v1; bool v2; unsigned short v3:1; };
struct C_B_BFu31i { char v1; bool v2; unsigned int v3:31; };
struct C_B_BFu31ll { char v1; bool v2; unsigned long long v3:31; };
struct C_B_BFu32i { char v1; bool v2; unsigned int v3:32; };
struct C_B_BFu32ll { char v1; bool v2; unsigned long long v3:32; };
struct C_B_BFu33 { char v1; bool v2; unsigned long long v3:33; };
struct C_B_BFu7c { char v1; bool v2; unsigned char v3:7; };
struct C_B_BFu7i { char v1; bool v2; unsigned int v3:7; };
struct C_B_BFu7ll { char v1; bool v2; unsigned long long v3:7; };
struct C_B_BFu7s { char v1; bool v2; unsigned short v3:7; };
struct C_B_BFu8c { char v1; bool v2; unsigned char v3:8; };
struct C_B_BFu8i { char v1; bool v2; unsigned int v3:8; };
struct C_B_BFu8ll { char v1; bool v2; unsigned long long v3:8; };
struct C_B_BFu8s { char v1; bool v2; unsigned short v3:8; };
struct C_B_BFu9i { char v1; bool v2; unsigned int v3:9; };
struct C_B_BFu9ll { char v1; bool v2; unsigned long long v3:9; };
struct C_B_BFu9s { char v1; bool v2; unsigned short v3:9; };
struct C_B_C { char v1; bool v2; char v3; };
struct C_B_D { char v1; bool v2; double v3; };
struct C_B_F { char v1; bool v2; float v3; };
struct C_B_I { char v1; bool v2; int v3; };
struct C_B_Ip { char v1; bool v2; int * v3; };
struct C_B_L { char v1; bool v2; long long v3; };
struct C_B_S { char v1; bool v2; short v3; };
struct C_B_Uc { char v1; bool v2; unsigned char v3; };
struct C_B_Ui { char v1; bool v2; unsigned int v3; };
struct C_B_Ul { char v1; bool v2; unsigned long long v3; };
struct C_B_Us { char v1; bool v2; unsigned short v3; };
struct C_B_Vp { char v1; bool v2; void * v3; };
struct C_BFu15i_B { char v1; unsigned int v2:15; bool v3; };
struct C_BFu15ll_B { char v1; unsigned long long v2:15; bool v3; };
struct C_BFu15s_B { char v1; unsigned short v2:15; bool v3; };
struct C_BFu16i_B { char v1; unsigned int v2:16; bool v3; };
struct C_BFu16ll_B { char v1; unsigned long long v2:16; bool v3; };
struct C_BFu16s_B { char v1; unsigned short v2:16; bool v3; };
struct C_BFu17i_B { char v1; unsigned int v2:17; bool v3; };
struct C_BFu17ll_B { char v1; unsigned long long v2:17; bool v3; };
struct C_BFu1c_B { char v1; unsigned char v2:1; bool v3; };
struct C_BFu1i_B { char v1; unsigned int v2:1; bool v3; };
struct C_BFu1ll_B { char v1; unsigned long long v2:1; bool v3; };
struct C_BFu1s_B { char v1; unsigned short v2:1; bool v3; };
struct C_BFu31i_B { char v1; unsigned int v2:31; bool v3; };
struct C_BFu31ll_B { char v1; unsigned long long v2:31; bool v3; };
struct C_BFu32i_B { char v1; unsigned int v2:32; bool v3; };
struct C_BFu32ll_B { char v1; unsigned long long v2:32; bool v3; };
struct C_BFu33_B { char v1; unsigned long long v2:33; bool v3; };
struct C_BFu7c_B { char v1; unsigned char v2:7; bool v3; };
struct C_BFu7i_B { char v1; unsigned int v2:7; bool v3; };
struct C_BFu7ll_B { char v1; unsigned long long v2:7; bool v3; };
struct C_BFu7s_B { char v1; unsigned short v2:7; bool v3; };
struct C_BFu8c_B { char v1; unsigned char v2:8; bool v3; };
struct C_BFu8i_B { char v1; unsigned int v2:8; bool v3; };
struct C_BFu8ll_B { char v1; unsigned long long v2:8; bool v3; };
struct C_BFu8s_B { char v1; unsigned short v2:8; bool v3; };
struct C_BFu9i_B { char v1; unsigned int v2:9; bool v3; };
struct C_BFu9ll_B { char v1; unsigned long long v2:9; bool v3; };
struct C_BFu9s_B { char v1; unsigned short v2:9; bool v3; };
struct C_C_B { char v1; char v2; bool v3; };
struct C_D_B { char v1; double v2; bool v3; };
struct C_F_B { char v1; float v2; bool v3; };
struct C_I_B { char v1; int v2; bool v3; };
struct C_Ip_B { char v1; int * v2; bool v3; };
struct C_L_B { char v1; long long v2; bool v3; };
struct C_S_B { char v1; short v2; bool v3; };
struct C_Uc_B { char v1; unsigned char v2; bool v3; };
struct C_Ui_B { char v1; unsigned int v2; bool v3; };
struct C_Ul_B { char v1; unsigned long long v2; bool v3; };
struct C_Us_B { char v1; unsigned short v2; bool v3; };
struct C_Vp_B { char v1; void * v2; bool v3; };
struct D_B { double v1; bool v2; };
struct D_B_B { double v1; bool v2; bool v3; };
struct D_B_BFu15i { double v1; bool v2; unsigned int v3:15; };
struct D_B_BFu15ll { double v1; bool v2; unsigned long long v3:15; };
struct D_B_BFu15s { double v1; bool v2; unsigned short v3:15; };
struct D_B_BFu16i { double v1; bool v2; unsigned int v3:16; };
struct D_B_BFu16ll { double v1; bool v2; unsigned long long v3:16; };
struct D_B_BFu16s { double v1; bool v2; unsigned short v3:16; };
struct D_B_BFu17i { double v1; bool v2; unsigned int v3:17; };
struct D_B_BFu17ll { double v1; bool v2; unsigned long long v3:17; };
struct D_B_BFu1c { double v1; bool v2; unsigned char v3:1; };
struct D_B_BFu1i { double v1; bool v2; unsigned int v3:1; };
struct D_B_BFu1ll { double v1; bool v2; unsigned long long v3:1; };
struct D_B_BFu1s { double v1; bool v2; unsigned short v3:1; };
struct D_B_BFu31i { double v1; bool v2; unsigned int v3:31; };
struct D_B_BFu31ll { double v1; bool v2; unsigned long long v3:31; };
struct D_B_BFu32i { double v1; bool v2; unsigned int v3:32; };
struct D_B_BFu32ll { double v1; bool v2; unsigned long long v3:32; };
struct D_B_BFu33 { double v1; bool v2; unsigned long long v3:33; };
struct D_B_BFu7c { double v1; bool v2; unsigned char v3:7; };
struct D_B_BFu7i { double v1; bool v2; unsigned int v3:7; };
struct D_B_BFu7ll { double v1; bool v2; unsigned long long v3:7; };
struct D_B_BFu7s { double v1; bool v2; unsigned short v3:7; };
struct D_B_BFu8c { double v1; bool v2; unsigned char v3:8; };
struct D_B_BFu8i { double v1; bool v2; unsigned int v3:8; };
struct D_B_BFu8ll { double v1; bool v2; unsigned long long v3:8; };
struct D_B_BFu8s { double v1; bool v2; unsigned short v3:8; };
struct D_B_BFu9i { double v1; bool v2; unsigned int v3:9; };
struct D_B_BFu9ll { double v1; bool v2; unsigned long long v3:9; };
struct D_B_BFu9s { double v1; bool v2; unsigned short v3:9; };
struct D_B_C { double v1; bool v2; char v3; };
struct D_B_D { double v1; bool v2; double v3; };
struct D_B_F { double v1; bool v2; float v3; };
struct D_B_I { double v1; bool v2; int v3; };
struct D_B_Ip { double v1; bool v2; int * v3; };
struct D_B_L { double v1; bool v2; long long v3; };
struct D_B_S { double v1; bool v2; short v3; };
struct D_B_Uc { double v1; bool v2; unsigned char v3; };
struct D_B_Ui { double v1; bool v2; unsigned int v3; };
struct D_B_Ul { double v1; bool v2; unsigned long long v3; };
struct D_B_Us { double v1; bool v2; unsigned short v3; };
struct D_B_Vp { double v1; bool v2; void * v3; };
struct D_BFu15i_B { double v1; unsigned int v2:15; bool v3; };
struct D_BFu15ll_B { double v1; unsigned long long v2:15; bool v3; };
struct D_BFu15s_B { double v1; unsigned short v2:15; bool v3; };
struct D_BFu16i_B { double v1; unsigned int v2:16; bool v3; };
struct D_BFu16ll_B { double v1; unsigned long long v2:16; bool v3; };
struct D_BFu16s_B { double v1; unsigned short v2:16; bool v3; };
struct D_BFu17i_B { double v1; unsigned int v2:17; bool v3; };
struct D_BFu17ll_B { double v1; unsigned long long v2:17; bool v3; };
struct D_BFu1c_B { double v1; unsigned char v2:1; bool v3; };
struct D_BFu1i_B { double v1; unsigned int v2:1; bool v3; };
struct D_BFu1ll_B { double v1; unsigned long long v2:1; bool v3; };
struct D_BFu1s_B { double v1; unsigned short v2:1; bool v3; };
struct D_BFu31i_B { double v1; unsigned int v2:31; bool v3; };
struct D_BFu31ll_B { double v1; unsigned long long v2:31; bool v3; };
struct D_BFu32i_B { double v1; unsigned int v2:32; bool v3; };
struct D_BFu32ll_B { double v1; unsigned long long v2:32; bool v3; };
struct D_BFu33_B { double v1; unsigned long long v2:33; bool v3; };
struct D_BFu7c_B { double v1; unsigned char v2:7; bool v3; };
struct D_BFu7i_B { double v1; unsigned int v2:7; bool v3; };
struct D_BFu7ll_B { double v1; unsigned long long v2:7; bool v3; };
struct D_BFu7s_B { double v1; unsigned short v2:7; bool v3; };
struct D_BFu8c_B { double v1; unsigned char v2:8; bool v3; };
struct D_BFu8i_B { double v1; unsigned int v2:8; bool v3; };
struct D_BFu8ll_B { double v1; unsigned long long v2:8; bool v3; };
struct D_BFu8s_B { double v1; unsigned short v2:8; bool v3; };
struct D_BFu9i_B { double v1; unsigned int v2:9; bool v3; };
struct D_BFu9ll_B { double v1; unsigned long long v2:9; bool v3; };
struct D_BFu9s_B { double v1; unsigned short v2:9; bool v3; };
struct D_C_B { double v1; char v2; bool v3; };
struct D_D_B { double v1; double v2; bool v3; };
struct D_F_B { double v1; float v2; bool v3; };
struct D_I_B { double v1; int v2; bool v3; };
struct D_Ip_B { double v1; int * v2; bool v3; };
struct D_L_B { double v1; long long v2; bool v3; };
struct D_S_B { double v1; short v2; bool v3; };
struct D_Uc_B { double v1; unsigned char v2; bool v3; };
struct D_Ui_B { double v1; unsigned int v2; bool v3; };
struct D_Ul_B { double v1; unsigned long long v2; bool v3; };
struct D_Us_B { double v1; unsigned short v2; bool v3; };
struct D_Vp_B { double v1; void * v2; bool v3; };
struct F_B { float v1; bool v2; };
struct F_B_B { float v1; bool v2; bool v3; };
struct F_B_BFu15i { float v1; bool v2; unsigned int v3:15; };
struct F_B_BFu15ll { float v1; bool v2; unsigned long long v3:15; };
struct F_B_BFu15s { float v1; bool v2; unsigned short v3:15; };
struct F_B_BFu16i { float v1; bool v2; unsigned int v3:16; };
struct F_B_BFu16ll { float v1; bool v2; unsigned long long v3:16; };
struct F_B_BFu16s { float v1; bool v2; unsigned short v3:16; };
struct F_B_BFu17i { float v1; bool v2; unsigned int v3:17; };
struct F_B_BFu17ll { float v1; bool v2; unsigned long long v3:17; };
struct F_B_BFu1c { float v1; bool v2; unsigned char v3:1; };
struct F_B_BFu1i { float v1; bool v2; unsigned int v3:1; };
struct F_B_BFu1ll { float v1; bool v2; unsigned long long v3:1; };
struct F_B_BFu1s { float v1; bool v2; unsigned short v3:1; };
struct F_B_BFu31i { float v1; bool v2; unsigned int v3:31; };
struct F_B_BFu31ll { float v1; bool v2; unsigned long long v3:31; };
struct F_B_BFu32i { float v1; bool v2; unsigned int v3:32; };
struct F_B_BFu32ll { float v1; bool v2; unsigned long long v3:32; };
struct F_B_BFu33 { float v1; bool v2; unsigned long long v3:33; };
struct F_B_BFu7c { float v1; bool v2; unsigned char v3:7; };
struct F_B_BFu7i { float v1; bool v2; unsigned int v3:7; };
struct F_B_BFu7ll { float v1; bool v2; unsigned long long v3:7; };
struct F_B_BFu7s { float v1; bool v2; unsigned short v3:7; };
struct F_B_BFu8c { float v1; bool v2; unsigned char v3:8; };
struct F_B_BFu8i { float v1; bool v2; unsigned int v3:8; };
struct F_B_BFu8ll { float v1; bool v2; unsigned long long v3:8; };
struct F_B_BFu8s { float v1; bool v2; unsigned short v3:8; };
struct F_B_BFu9i { float v1; bool v2; unsigned int v3:9; };
struct F_B_BFu9ll { float v1; bool v2; unsigned long long v3:9; };
struct F_B_BFu9s { float v1; bool v2; unsigned short v3:9; };
struct F_B_C { float v1; bool v2; char v3; };
struct F_B_D { float v1; bool v2; double v3; };
struct F_B_F { float v1; bool v2; float v3; };
struct F_B_I { float v1; bool v2; int v3; };
struct F_B_Ip { float v1; bool v2; int * v3; };
struct F_B_L { float v1; bool v2; long long v3; };
struct F_B_S { float v1; bool v2; short v3; };
struct F_B_Uc { float v1; bool v2; unsigned char v3; };
struct F_B_Ui { float v1; bool v2; unsigned int v3; };
struct F_B_Ul { float v1; bool v2; unsigned long long v3; };
struct F_B_Us { float v1; bool v2; unsigned short v3; };
struct F_B_Vp { float v1; bool v2; void * v3; };
struct F_BFu15i_B { float v1; unsigned int v2:15; bool v3; };
struct F_BFu15ll_B { float v1; unsigned long long v2:15; bool v3; };
struct F_BFu15s_B { float v1; unsigned short v2:15; bool v3; };
struct F_BFu16i_B { float v1; unsigned int v2:16; bool v3; };
struct F_BFu16ll_B { float v1; unsigned long long v2:16; bool v3; };
struct F_BFu16s_B { float v1; unsigned short v2:16; bool v3; };
struct F_BFu17i_B { float v1; unsigned int v2:17; bool v3; };
struct F_BFu17ll_B { float v1; unsigned long long v2:17; bool v3; };
struct F_BFu1c_B { float v1; unsigned char v2:1; bool v3; };
struct F_BFu1i_B { float v1; unsigned int v2:1; bool v3; };
struct F_BFu1ll_B { float v1; unsigned long long v2:1; bool v3; };
struct F_BFu1s_B { float v1; unsigned short v2:1; bool v3; };
struct F_BFu31i_B { float v1; unsigned int v2:31; bool v3; };
struct F_BFu31ll_B { float v1; unsigned long long v2:31; bool v3; };
struct F_BFu32i_B { float v1; unsigned int v2:32; bool v3; };
struct F_BFu32ll_B { float v1; unsigned long long v2:32; bool v3; };
struct F_BFu33_B { float v1; unsigned long long v2:33; bool v3; };
struct F_BFu7c_B { float v1; unsigned char v2:7; bool v3; };
struct F_BFu7i_B { float v1; unsigned int v2:7; bool v3; };
struct F_BFu7ll_B { float v1; unsigned long long v2:7; bool v3; };
struct F_BFu7s_B { float v1; unsigned short v2:7; bool v3; };
struct F_BFu8c_B { float v1; unsigned char v2:8; bool v3; };
struct F_BFu8i_B { float v1; unsigned int v2:8; bool v3; };
struct F_BFu8ll_B { float v1; unsigned long long v2:8; bool v3; };
struct F_BFu8s_B { float v1; unsigned short v2:8; bool v3; };
struct F_BFu9i_B { float v1; unsigned int v2:9; bool v3; };
struct F_BFu9ll_B { float v1; unsigned long long v2:9; bool v3; };
struct F_BFu9s_B { float v1; unsigned short v2:9; bool v3; };
struct F_C_B { float v1; char v2; bool v3; };
struct F_D_B { float v1; double v2; bool v3; };
struct F_F_B { float v1; float v2; bool v3; };
struct F_I_B { float v1; int v2; bool v3; };
struct F_Ip_B { float v1; int * v2; bool v3; };
struct F_L_B { float v1; long long v2; bool v3; };
struct F_S_B { float v1; short v2; bool v3; };
struct F_Uc_B { float v1; unsigned char v2; bool v3; };
struct F_Ui_B { float v1; unsigned int v2; bool v3; };
struct F_Ul_B { float v1; unsigned long long v2; bool v3; };
struct F_Us_B { float v1; unsigned short v2; bool v3; };
struct F_Vp_B { float v1; void * v2; bool v3; };
struct I_B { int v1; bool v2; };
struct I_B_B { int v1; bool v2; bool v3; };
struct I_B_BFu15i { int v1; bool v2; unsigned int v3:15; };
struct I_B_BFu15ll { int v1; bool v2; unsigned long long v3:15; };
struct I_B_BFu15s { int v1; bool v2; unsigned short v3:15; };
struct I_B_BFu16i { int v1; bool v2; unsigned int v3:16; };
struct I_B_BFu16ll { int v1; bool v2; unsigned long long v3:16; };
struct I_B_BFu16s { int v1; bool v2; unsigned short v3:16; };
struct I_B_BFu17i { int v1; bool v2; unsigned int v3:17; };
struct I_B_BFu17ll { int v1; bool v2; unsigned long long v3:17; };
struct I_B_BFu1c { int v1; bool v2; unsigned char v3:1; };
struct I_B_BFu1i { int v1; bool v2; unsigned int v3:1; };
struct I_B_BFu1ll { int v1; bool v2; unsigned long long v3:1; };
struct I_B_BFu1s { int v1; bool v2; unsigned short v3:1; };
struct I_B_BFu31i { int v1; bool v2; unsigned int v3:31; };
struct I_B_BFu31ll { int v1; bool v2; unsigned long long v3:31; };
struct I_B_BFu32i { int v1; bool v2; unsigned int v3:32; };
struct I_B_BFu32ll { int v1; bool v2; unsigned long long v3:32; };
struct I_B_BFu33 { int v1; bool v2; unsigned long long v3:33; };
struct I_B_BFu7c { int v1; bool v2; unsigned char v3:7; };
struct I_B_BFu7i { int v1; bool v2; unsigned int v3:7; };
struct I_B_BFu7ll { int v1; bool v2; unsigned long long v3:7; };
struct I_B_BFu7s { int v1; bool v2; unsigned short v3:7; };
struct I_B_BFu8c { int v1; bool v2; unsigned char v3:8; };
struct I_B_BFu8i { int v1; bool v2; unsigned int v3:8; };
struct I_B_BFu8ll { int v1; bool v2; unsigned long long v3:8; };
struct I_B_BFu8s { int v1; bool v2; unsigned short v3:8; };
struct I_B_BFu9i { int v1; bool v2; unsigned int v3:9; };
struct I_B_BFu9ll { int v1; bool v2; unsigned long long v3:9; };
struct I_B_BFu9s { int v1; bool v2; unsigned short v3:9; };
struct I_B_C { int v1; bool v2; char v3; };
struct I_B_D { int v1; bool v2; double v3; };
struct I_B_F { int v1; bool v2; float v3; };
struct I_B_I { int v1; bool v2; int v3; };
struct I_B_Ip { int v1; bool v2; int * v3; };
struct I_B_L { int v1; bool v2; long long v3; };
struct I_B_S { int v1; bool v2; short v3; };
struct I_B_Uc { int v1; bool v2; unsigned char v3; };
struct I_B_Ui { int v1; bool v2; unsigned int v3; };
struct I_B_Ul { int v1; bool v2; unsigned long long v3; };
struct I_B_Us { int v1; bool v2; unsigned short v3; };
struct I_B_Vp { int v1; bool v2; void * v3; };
struct I_BFu15i_B { int v1; unsigned int v2:15; bool v3; };
struct I_BFu15ll_B { int v1; unsigned long long v2:15; bool v3; };
struct I_BFu15s_B { int v1; unsigned short v2:15; bool v3; };
struct I_BFu16i_B { int v1; unsigned int v2:16; bool v3; };
struct I_BFu16ll_B { int v1; unsigned long long v2:16; bool v3; };
struct I_BFu16s_B { int v1; unsigned short v2:16; bool v3; };
struct I_BFu17i_B { int v1; unsigned int v2:17; bool v3; };
struct I_BFu17ll_B { int v1; unsigned long long v2:17; bool v3; };
struct I_BFu1c_B { int v1; unsigned char v2:1; bool v3; };
struct I_BFu1i_B { int v1; unsigned int v2:1; bool v3; };
struct I_BFu1ll_B { int v1; unsigned long long v2:1; bool v3; };
struct I_BFu1s_B { int v1; unsigned short v2:1; bool v3; };
struct I_BFu31i_B { int v1; unsigned int v2:31; bool v3; };
struct I_BFu31ll_B { int v1; unsigned long long v2:31; bool v3; };
struct I_BFu32i_B { int v1; unsigned int v2:32; bool v3; };
struct I_BFu32ll_B { int v1; unsigned long long v2:32; bool v3; };
struct I_BFu33_B { int v1; unsigned long long v2:33; bool v3; };
struct I_BFu7c_B { int v1; unsigned char v2:7; bool v3; };
struct I_BFu7i_B { int v1; unsigned int v2:7; bool v3; };
struct I_BFu7ll_B { int v1; unsigned long long v2:7; bool v3; };
struct I_BFu7s_B { int v1; unsigned short v2:7; bool v3; };
struct I_BFu8c_B { int v1; unsigned char v2:8; bool v3; };
struct I_BFu8i_B { int v1; unsigned int v2:8; bool v3; };
struct I_BFu8ll_B { int v1; unsigned long long v2:8; bool v3; };
struct I_BFu8s_B { int v1; unsigned short v2:8; bool v3; };
struct I_BFu9i_B { int v1; unsigned int v2:9; bool v3; };
struct I_BFu9ll_B { int v1; unsigned long long v2:9; bool v3; };
struct I_BFu9s_B { int v1; unsigned short v2:9; bool v3; };
struct I_C_B { int v1; char v2; bool v3; };
struct I_D_B { int v1; double v2; bool v3; };
struct I_F_B { int v1; float v2; bool v3; };
struct I_I_B { int v1; int v2; bool v3; };
struct I_Ip_B { int v1; int * v2; bool v3; };
struct I_L_B { int v1; long long v2; bool v3; };
struct I_S_B { int v1; short v2; bool v3; };
struct I_Uc_B { int v1; unsigned char v2; bool v3; };
struct I_Ui_B { int v1; unsigned int v2; bool v3; };
struct I_Ul_B { int v1; unsigned long long v2; bool v3; };
struct I_Us_B { int v1; unsigned short v2; bool v3; };
struct I_Vp_B { int v1; void * v2; bool v3; };
struct Ip_B { int * v1; bool v2; };
struct Ip_B_B { int * v1; bool v2; bool v3; };
struct Ip_B_BFu15i { int * v1; bool v2; unsigned int v3:15; };
struct Ip_B_BFu15ll { int * v1; bool v2; unsigned long long v3:15; };
struct Ip_B_BFu15s { int * v1; bool v2; unsigned short v3:15; };
struct Ip_B_BFu16i { int * v1; bool v2; unsigned int v3:16; };
struct Ip_B_BFu16ll { int * v1; bool v2; unsigned long long v3:16; };
struct Ip_B_BFu16s { int * v1; bool v2; unsigned short v3:16; };
struct Ip_B_BFu17i { int * v1; bool v2; unsigned int v3:17; };
struct Ip_B_BFu17ll { int * v1; bool v2; unsigned long long v3:17; };
struct Ip_B_BFu1c { int * v1; bool v2; unsigned char v3:1; };
struct Ip_B_BFu1i { int * v1; bool v2; unsigned int v3:1; };
struct Ip_B_BFu1ll { int * v1; bool v2; unsigned long long v3:1; };
struct Ip_B_BFu1s { int * v1; bool v2; unsigned short v3:1; };
struct Ip_B_BFu31i { int * v1; bool v2; unsigned int v3:31; };
struct Ip_B_BFu31ll { int * v1; bool v2; unsigned long long v3:31; };
struct Ip_B_BFu32i { int * v1; bool v2; unsigned int v3:32; };
struct Ip_B_BFu32ll { int * v1; bool v2; unsigned long long v3:32; };
struct Ip_B_BFu33 { int * v1; bool v2; unsigned long long v3:33; };
struct Ip_B_BFu7c { int * v1; bool v2; unsigned char v3:7; };
struct Ip_B_BFu7i { int * v1; bool v2; unsigned int v3:7; };
struct Ip_B_BFu7ll { int * v1; bool v2; unsigned long long v3:7; };
struct Ip_B_BFu7s { int * v1; bool v2; unsigned short v3:7; };
struct Ip_B_BFu8c { int * v1; bool v2; unsigned char v3:8; };
struct Ip_B_BFu8i { int * v1; bool v2; unsigned int v3:8; };
struct Ip_B_BFu8ll { int * v1; bool v2; unsigned long long v3:8; };
struct Ip_B_BFu8s { int * v1; bool v2; unsigned short v3:8; };
struct Ip_B_BFu9i { int * v1; bool v2; unsigned int v3:9; };
struct Ip_B_BFu9ll { int * v1; bool v2; unsigned long long v3:9; };
struct Ip_B_BFu9s { int * v1; bool v2; unsigned short v3:9; };
struct Ip_B_C { int * v1; bool v2; char v3; };
struct Ip_B_D { int * v1; bool v2; double v3; };
struct Ip_B_F { int * v1; bool v2; float v3; };
struct Ip_B_I { int * v1; bool v2; int v3; };
struct Ip_B_Ip { int * v1; bool v2; int * v3; };
struct Ip_B_L { int * v1; bool v2; long long v3; };
struct Ip_B_S { int * v1; bool v2; short v3; };
struct Ip_B_Uc { int * v1; bool v2; unsigned char v3; };
struct Ip_B_Ui { int * v1; bool v2; unsigned int v3; };
struct Ip_B_Ul { int * v1; bool v2; unsigned long long v3; };
struct Ip_B_Us { int * v1; bool v2; unsigned short v3; };
struct Ip_B_Vp { int * v1; bool v2; void * v3; };
struct Ip_BFu15i_B { int * v1; unsigned int v2:15; bool v3; };
struct Ip_BFu15ll_B { int * v1; unsigned long long v2:15; bool v3; };
struct Ip_BFu15s_B { int * v1; unsigned short v2:15; bool v3; };
struct Ip_BFu16i_B { int * v1; unsigned int v2:16; bool v3; };
struct Ip_BFu16ll_B { int * v1; unsigned long long v2:16; bool v3; };
struct Ip_BFu16s_B { int * v1; unsigned short v2:16; bool v3; };
struct Ip_BFu17i_B { int * v1; unsigned int v2:17; bool v3; };
struct Ip_BFu17ll_B { int * v1; unsigned long long v2:17; bool v3; };
struct Ip_BFu1c_B { int * v1; unsigned char v2:1; bool v3; };
struct Ip_BFu1i_B { int * v1; unsigned int v2:1; bool v3; };
struct Ip_BFu1ll_B { int * v1; unsigned long long v2:1; bool v3; };
struct Ip_BFu1s_B { int * v1; unsigned short v2:1; bool v3; };
struct Ip_BFu31i_B { int * v1; unsigned int v2:31; bool v3; };
struct Ip_BFu31ll_B { int * v1; unsigned long long v2:31; bool v3; };
struct Ip_BFu32i_B { int * v1; unsigned int v2:32; bool v3; };
struct Ip_BFu32ll_B { int * v1; unsigned long long v2:32; bool v3; };
struct Ip_BFu33_B { int * v1; unsigned long long v2:33; bool v3; };
struct Ip_BFu7c_B { int * v1; unsigned char v2:7; bool v3; };
struct Ip_BFu7i_B { int * v1; unsigned int v2:7; bool v3; };
struct Ip_BFu7ll_B { int * v1; unsigned long long v2:7; bool v3; };
struct Ip_BFu7s_B { int * v1; unsigned short v2:7; bool v3; };
struct Ip_BFu8c_B { int * v1; unsigned char v2:8; bool v3; };
struct Ip_BFu8i_B { int * v1; unsigned int v2:8; bool v3; };
struct Ip_BFu8ll_B { int * v1; unsigned long long v2:8; bool v3; };
struct Ip_BFu8s_B { int * v1; unsigned short v2:8; bool v3; };
struct Ip_BFu9i_B { int * v1; unsigned int v2:9; bool v3; };
struct Ip_BFu9ll_B { int * v1; unsigned long long v2:9; bool v3; };
struct Ip_BFu9s_B { int * v1; unsigned short v2:9; bool v3; };
struct Ip_C_B { int * v1; char v2; bool v3; };
struct Ip_D_B { int * v1; double v2; bool v3; };
struct Ip_F_B { int * v1; float v2; bool v3; };
struct Ip_I_B { int * v1; int v2; bool v3; };
struct Ip_Ip_B { int * v1; int * v2; bool v3; };
struct Ip_L_B { int * v1; long long v2; bool v3; };
struct Ip_S_B { int * v1; short v2; bool v3; };
struct Ip_Uc_B { int * v1; unsigned char v2; bool v3; };
struct Ip_Ui_B { int * v1; unsigned int v2; bool v3; };
struct Ip_Ul_B { int * v1; unsigned long long v2; bool v3; };
struct Ip_Us_B { int * v1; unsigned short v2; bool v3; };
struct Ip_Vp_B { int * v1; void * v2; bool v3; };
struct L_B { long long v1; bool v2; };
struct L_B_B { long long v1; bool v2; bool v3; };
struct L_B_BFu15i { long long v1; bool v2; unsigned int v3:15; };
struct L_B_BFu15ll { long long v1; bool v2; unsigned long long v3:15; };
struct L_B_BFu15s { long long v1; bool v2; unsigned short v3:15; };
struct L_B_BFu16i { long long v1; bool v2; unsigned int v3:16; };
struct L_B_BFu16ll { long long v1; bool v2; unsigned long long v3:16; };
struct L_B_BFu16s { long long v1; bool v2; unsigned short v3:16; };
struct L_B_BFu17i { long long v1; bool v2; unsigned int v3:17; };
struct L_B_BFu17ll { long long v1; bool v2; unsigned long long v3:17; };
struct L_B_BFu1c { long long v1; bool v2; unsigned char v3:1; };
struct L_B_BFu1i { long long v1; bool v2; unsigned int v3:1; };
struct L_B_BFu1ll { long long v1; bool v2; unsigned long long v3:1; };
struct L_B_BFu1s { long long v1; bool v2; unsigned short v3:1; };
struct L_B_BFu31i { long long v1; bool v2; unsigned int v3:31; };
struct L_B_BFu31ll { long long v1; bool v2; unsigned long long v3:31; };
struct L_B_BFu32i { long long v1; bool v2; unsigned int v3:32; };
struct L_B_BFu32ll { long long v1; bool v2; unsigned long long v3:32; };
struct L_B_BFu33 { long long v1; bool v2; unsigned long long v3:33; };
struct L_B_BFu7c { long long v1; bool v2; unsigned char v3:7; };
struct L_B_BFu7i { long long v1; bool v2; unsigned int v3:7; };
struct L_B_BFu7ll { long long v1; bool v2; unsigned long long v3:7; };
struct L_B_BFu7s { long long v1; bool v2; unsigned short v3:7; };
struct L_B_BFu8c { long long v1; bool v2; unsigned char v3:8; };
struct L_B_BFu8i { long long v1; bool v2; unsigned int v3:8; };
struct L_B_BFu8ll { long long v1; bool v2; unsigned long long v3:8; };
struct L_B_BFu8s { long long v1; bool v2; unsigned short v3:8; };
struct L_B_BFu9i { long long v1; bool v2; unsigned int v3:9; };
struct L_B_BFu9ll { long long v1; bool v2; unsigned long long v3:9; };
struct L_B_BFu9s { long long v1; bool v2; unsigned short v3:9; };
struct L_B_C { long long v1; bool v2; char v3; };
struct L_B_D { long long v1; bool v2; double v3; };
struct L_B_F { long long v1; bool v2; float v3; };
struct L_B_I { long long v1; bool v2; int v3; };
struct L_B_Ip { long long v1; bool v2; int * v3; };
struct L_B_L { long long v1; bool v2; long long v3; };
struct L_B_S { long long v1; bool v2; short v3; };
struct L_B_Uc { long long v1; bool v2; unsigned char v3; };
struct L_B_Ui { long long v1; bool v2; unsigned int v3; };
struct L_B_Ul { long long v1; bool v2; unsigned long long v3; };
struct L_B_Us { long long v1; bool v2; unsigned short v3; };
struct L_B_Vp { long long v1; bool v2; void * v3; };
struct L_BFu15i_B { long long v1; unsigned int v2:15; bool v3; };
struct L_BFu15ll_B { long long v1; unsigned long long v2:15; bool v3; };
struct L_BFu15s_B { long long v1; unsigned short v2:15; bool v3; };
struct L_BFu16i_B { long long v1; unsigned int v2:16; bool v3; };
struct L_BFu16ll_B { long long v1; unsigned long long v2:16; bool v3; };
struct L_BFu16s_B { long long v1; unsigned short v2:16; bool v3; };
struct L_BFu17i_B { long long v1; unsigned int v2:17; bool v3; };
struct L_BFu17ll_B { long long v1; unsigned long long v2:17; bool v3; };
struct L_BFu1c_B { long long v1; unsigned char v2:1; bool v3; };
struct L_BFu1i_B { long long v1; unsigned int v2:1; bool v3; };
struct L_BFu1ll_B { long long v1; unsigned long long v2:1; bool v3; };
struct L_BFu1s_B { long long v1; unsigned short v2:1; bool v3; };
struct L_BFu31i_B { long long v1; unsigned int v2:31; bool v3; };
struct L_BFu31ll_B { long long v1; unsigned long long v2:31; bool v3; };
struct L_BFu32i_B { long long v1; unsigned int v2:32; bool v3; };
struct L_BFu32ll_B { long long v1; unsigned long long v2:32; bool v3; };
struct L_BFu33_B { long long v1; unsigned long long v2:33; bool v3; };
struct L_BFu7c_B { long long v1; unsigned char v2:7; bool v3; };
struct L_BFu7i_B { long long v1; unsigned int v2:7; bool v3; };
struct L_BFu7ll_B { long long v1; unsigned long long v2:7; bool v3; };
struct L_BFu7s_B { long long v1; unsigned short v2:7; bool v3; };
struct L_BFu8c_B { long long v1; unsigned char v2:8; bool v3; };
struct L_BFu8i_B { long long v1; unsigned int v2:8; bool v3; };
struct L_BFu8ll_B { long long v1; unsigned long long v2:8; bool v3; };
struct L_BFu8s_B { long long v1; unsigned short v2:8; bool v3; };
struct L_BFu9i_B { long long v1; unsigned int v2:9; bool v3; };
struct L_BFu9ll_B { long long v1; unsigned long long v2:9; bool v3; };
struct L_BFu9s_B { long long v1; unsigned short v2:9; bool v3; };
struct L_C_B { long long v1; char v2; bool v3; };
struct L_D_B { long long v1; double v2; bool v3; };
struct L_F_B { long long v1; float v2; bool v3; };
struct L_I_B { long long v1; int v2; bool v3; };
struct L_Ip_B { long long v1; int * v2; bool v3; };
struct L_L_B { long long v1; long long v2; bool v3; };
struct L_S_B { long long v1; short v2; bool v3; };
struct L_Uc_B { long long v1; unsigned char v2; bool v3; };
struct L_Ui_B { long long v1; unsigned int v2; bool v3; };
struct L_Ul_B { long long v1; unsigned long long v2; bool v3; };
struct L_Us_B { long long v1; unsigned short v2; bool v3; };
struct L_Vp_B { long long v1; void * v2; bool v3; };
struct S_B { short v1; bool v2; };
struct S_B_B { short v1; bool v2; bool v3; };
struct S_B_BFu15i { short v1; bool v2; unsigned int v3:15; };
struct S_B_BFu15ll { short v1; bool v2; unsigned long long v3:15; };
struct S_B_BFu15s { short v1; bool v2; unsigned short v3:15; };
struct S_B_BFu16i { short v1; bool v2; unsigned int v3:16; };
struct S_B_BFu16ll { short v1; bool v2; unsigned long long v3:16; };
struct S_B_BFu16s { short v1; bool v2; unsigned short v3:16; };
struct S_B_BFu17i { short v1; bool v2; unsigned int v3:17; };
struct S_B_BFu17ll { short v1; bool v2; unsigned long long v3:17; };
struct S_B_BFu1c { short v1; bool v2; unsigned char v3:1; };
struct S_B_BFu1i { short v1; bool v2; unsigned int v3:1; };
struct S_B_BFu1ll { short v1; bool v2; unsigned long long v3:1; };
struct S_B_BFu1s { short v1; bool v2; unsigned short v3:1; };
struct S_B_BFu31i { short v1; bool v2; unsigned int v3:31; };
struct S_B_BFu31ll { short v1; bool v2; unsigned long long v3:31; };
struct S_B_BFu32i { short v1; bool v2; unsigned int v3:32; };
struct S_B_BFu32ll { short v1; bool v2; unsigned long long v3:32; };
struct S_B_BFu33 { short v1; bool v2; unsigned long long v3:33; };
struct S_B_BFu7c { short v1; bool v2; unsigned char v3:7; };
struct S_B_BFu7i { short v1; bool v2; unsigned int v3:7; };
struct S_B_BFu7ll { short v1; bool v2; unsigned long long v3:7; };
struct S_B_BFu7s { short v1; bool v2; unsigned short v3:7; };
struct S_B_BFu8c { short v1; bool v2; unsigned char v3:8; };
struct S_B_BFu8i { short v1; bool v2; unsigned int v3:8; };
struct S_B_BFu8ll { short v1; bool v2; unsigned long long v3:8; };
struct S_B_BFu8s { short v1; bool v2; unsigned short v3:8; };
struct S_B_BFu9i { short v1; bool v2; unsigned int v3:9; };
struct S_B_BFu9ll { short v1; bool v2; unsigned long long v3:9; };
struct S_B_BFu9s { short v1; bool v2; unsigned short v3:9; };
struct S_B_C { short v1; bool v2; char v3; };
struct S_B_D { short v1; bool v2; double v3; };
struct S_B_F { short v1; bool v2; float v3; };
struct S_B_I { short v1; bool v2; int v3; };
struct S_B_Ip { short v1; bool v2; int * v3; };
struct S_B_L { short v1; bool v2; long long v3; };
struct S_B_S { short v1; bool v2; short v3; };
struct S_B_Uc { short v1; bool v2; unsigned char v3; };
struct S_B_Ui { short v1; bool v2; unsigned int v3; };
struct S_B_Ul { short v1; bool v2; unsigned long long v3; };
struct S_B_Us { short v1; bool v2; unsigned short v3; };
struct S_B_Vp { short v1; bool v2; void * v3; };
struct S_BFu15i_B { short v1; unsigned int v2:15; bool v3; };
struct S_BFu15ll_B { short v1; unsigned long long v2:15; bool v3; };
struct S_BFu15s_B { short v1; unsigned short v2:15; bool v3; };
struct S_BFu16i_B { short v1; unsigned int v2:16; bool v3; };
struct S_BFu16ll_B { short v1; unsigned long long v2:16; bool v3; };
struct S_BFu16s_B { short v1; unsigned short v2:16; bool v3; };
struct S_BFu17i_B { short v1; unsigned int v2:17; bool v3; };
struct S_BFu17ll_B { short v1; unsigned long long v2:17; bool v3; };
struct S_BFu1c_B { short v1; unsigned char v2:1; bool v3; };
struct S_BFu1i_B { short v1; unsigned int v2:1; bool v3; };
struct S_BFu1ll_B { short v1; unsigned long long v2:1; bool v3; };
struct S_BFu1s_B { short v1; unsigned short v2:1; bool v3; };
struct S_BFu31i_B { short v1; unsigned int v2:31; bool v3; };
struct S_BFu31ll_B { short v1; unsigned long long v2:31; bool v3; };
struct S_BFu32i_B { short v1; unsigned int v2:32; bool v3; };
struct S_BFu32ll_B { short v1; unsigned long long v2:32; bool v3; };
struct S_BFu33_B { short v1; unsigned long long v2:33; bool v3; };
struct S_BFu7c_B { short v1; unsigned char v2:7; bool v3; };
struct S_BFu7i_B { short v1; unsigned int v2:7; bool v3; };
struct S_BFu7ll_B { short v1; unsigned long long v2:7; bool v3; };
struct S_BFu7s_B { short v1; unsigned short v2:7; bool v3; };
struct S_BFu8c_B { short v1; unsigned char v2:8; bool v3; };
struct S_BFu8i_B { short v1; unsigned int v2:8; bool v3; };
struct S_BFu8ll_B { short v1; unsigned long long v2:8; bool v3; };
struct S_BFu8s_B { short v1; unsigned short v2:8; bool v3; };
struct S_BFu9i_B { short v1; unsigned int v2:9; bool v3; };
struct S_BFu9ll_B { short v1; unsigned long long v2:9; bool v3; };
struct S_BFu9s_B { short v1; unsigned short v2:9; bool v3; };
struct S_C_B { short v1; char v2; bool v3; };
struct S_D_B { short v1; double v2; bool v3; };
struct S_F_B { short v1; float v2; bool v3; };
struct S_I_B { short v1; int v2; bool v3; };
struct S_Ip_B { short v1; int * v2; bool v3; };
struct S_L_B { short v1; long long v2; bool v3; };
struct S_S_B { short v1; short v2; bool v3; };
struct S_Uc_B { short v1; unsigned char v2; bool v3; };
struct S_Ui_B { short v1; unsigned int v2; bool v3; };
struct S_Ul_B { short v1; unsigned long long v2; bool v3; };
struct S_Us_B { short v1; unsigned short v2; bool v3; };
struct S_Vp_B { short v1; void * v2; bool v3; };
struct Uc_B { unsigned char v1; bool v2; };
struct Uc_B_B { unsigned char v1; bool v2; bool v3; };
struct Uc_B_BFu15i { unsigned char v1; bool v2; unsigned int v3:15; };
struct Uc_B_BFu15ll { unsigned char v1; bool v2; unsigned long long v3:15; };
struct Uc_B_BFu15s { unsigned char v1; bool v2; unsigned short v3:15; };
struct Uc_B_BFu16i { unsigned char v1; bool v2; unsigned int v3:16; };
struct Uc_B_BFu16ll { unsigned char v1; bool v2; unsigned long long v3:16; };
struct Uc_B_BFu16s { unsigned char v1; bool v2; unsigned short v3:16; };
struct Uc_B_BFu17i { unsigned char v1; bool v2; unsigned int v3:17; };
struct Uc_B_BFu17ll { unsigned char v1; bool v2; unsigned long long v3:17; };
struct Uc_B_BFu1c { unsigned char v1; bool v2; unsigned char v3:1; };
struct Uc_B_BFu1i { unsigned char v1; bool v2; unsigned int v3:1; };
struct Uc_B_BFu1ll { unsigned char v1; bool v2; unsigned long long v3:1; };
struct Uc_B_BFu1s { unsigned char v1; bool v2; unsigned short v3:1; };
struct Uc_B_BFu31i { unsigned char v1; bool v2; unsigned int v3:31; };
struct Uc_B_BFu31ll { unsigned char v1; bool v2; unsigned long long v3:31; };
struct Uc_B_BFu32i { unsigned char v1; bool v2; unsigned int v3:32; };
struct Uc_B_BFu32ll { unsigned char v1; bool v2; unsigned long long v3:32; };
struct Uc_B_BFu33 { unsigned char v1; bool v2; unsigned long long v3:33; };
struct Uc_B_BFu7c { unsigned char v1; bool v2; unsigned char v3:7; };
struct Uc_B_BFu7i { unsigned char v1; bool v2; unsigned int v3:7; };
struct Uc_B_BFu7ll { unsigned char v1; bool v2; unsigned long long v3:7; };
struct Uc_B_BFu7s { unsigned char v1; bool v2; unsigned short v3:7; };
struct Uc_B_BFu8c { unsigned char v1; bool v2; unsigned char v3:8; };
struct Uc_B_BFu8i { unsigned char v1; bool v2; unsigned int v3:8; };
struct Uc_B_BFu8ll { unsigned char v1; bool v2; unsigned long long v3:8; };
struct Uc_B_BFu8s { unsigned char v1; bool v2; unsigned short v3:8; };
struct Uc_B_BFu9i { unsigned char v1; bool v2; unsigned int v3:9; };
struct Uc_B_BFu9ll { unsigned char v1; bool v2; unsigned long long v3:9; };
struct Uc_B_BFu9s { unsigned char v1; bool v2; unsigned short v3:9; };
struct Uc_B_C { unsigned char v1; bool v2; char v3; };
struct Uc_B_D { unsigned char v1; bool v2; double v3; };
struct Uc_B_F { unsigned char v1; bool v2; float v3; };
struct Uc_B_I { unsigned char v1; bool v2; int v3; };
struct Uc_B_Ip { unsigned char v1; bool v2; int * v3; };
struct Uc_B_L { unsigned char v1; bool v2; long long v3; };
struct Uc_B_S { unsigned char v1; bool v2; short v3; };
struct Uc_B_Uc { unsigned char v1; bool v2; unsigned char v3; };
struct Uc_B_Ui { unsigned char v1; bool v2; unsigned int v3; };
struct Uc_B_Ul { unsigned char v1; bool v2; unsigned long long v3; };
struct Uc_B_Us { unsigned char v1; bool v2; unsigned short v3; };
struct Uc_B_Vp { unsigned char v1; bool v2; void * v3; };
struct Uc_BFu15i_B { unsigned char v1; unsigned int v2:15; bool v3; };
struct Uc_BFu15ll_B { unsigned char v1; unsigned long long v2:15; bool v3; };
struct Uc_BFu15s_B { unsigned char v1; unsigned short v2:15; bool v3; };
struct Uc_BFu16i_B { unsigned char v1; unsigned int v2:16; bool v3; };
struct Uc_BFu16ll_B { unsigned char v1; unsigned long long v2:16; bool v3; };
struct Uc_BFu16s_B { unsigned char v1; unsigned short v2:16; bool v3; };
struct Uc_BFu17i_B { unsigned char v1; unsigned int v2:17; bool v3; };
struct Uc_BFu17ll_B { unsigned char v1; unsigned long long v2:17; bool v3; };
struct Uc_BFu1c_B { unsigned char v1; unsigned char v2:1; bool v3; };
struct Uc_BFu1i_B { unsigned char v1; unsigned int v2:1; bool v3; };
struct Uc_BFu1ll_B { unsigned char v1; unsigned long long v2:1; bool v3; };
struct Uc_BFu1s_B { unsigned char v1; unsigned short v2:1; bool v3; };
struct Uc_BFu31i_B { unsigned char v1; unsigned int v2:31; bool v3; };
struct Uc_BFu31ll_B { unsigned char v1; unsigned long long v2:31; bool v3; };
struct Uc_BFu32i_B { unsigned char v1; unsigned int v2:32; bool v3; };
struct Uc_BFu32ll_B { unsigned char v1; unsigned long long v2:32; bool v3; };
struct Uc_BFu33_B { unsigned char v1; unsigned long long v2:33; bool v3; };
struct Uc_BFu7c_B { unsigned char v1; unsigned char v2:7; bool v3; };
struct Uc_BFu7i_B { unsigned char v1; unsigned int v2:7; bool v3; };
struct Uc_BFu7ll_B { unsigned char v1; unsigned long long v2:7; bool v3; };
struct Uc_BFu7s_B { unsigned char v1; unsigned short v2:7; bool v3; };
struct Uc_BFu8c_B { unsigned char v1; unsigned char v2:8; bool v3; };
struct Uc_BFu8i_B { unsigned char v1; unsigned int v2:8; bool v3; };
struct Uc_BFu8ll_B { unsigned char v1; unsigned long long v2:8; bool v3; };
struct Uc_BFu8s_B { unsigned char v1; unsigned short v2:8; bool v3; };
struct Uc_BFu9i_B { unsigned char v1; unsigned int v2:9; bool v3; };
struct Uc_BFu9ll_B { unsigned char v1; unsigned long long v2:9; bool v3; };
struct Uc_BFu9s_B { unsigned char v1; unsigned short v2:9; bool v3; };
struct Uc_C_B { unsigned char v1; char v2; bool v3; };
struct Uc_D_B { unsigned char v1; double v2; bool v3; };
struct Uc_F_B { unsigned char v1; float v2; bool v3; };
struct Uc_I_B { unsigned char v1; int v2; bool v3; };
struct Uc_Ip_B { unsigned char v1; int * v2; bool v3; };
struct Uc_L_B { unsigned char v1; long long v2; bool v3; };
struct Uc_S_B { unsigned char v1; short v2; bool v3; };
struct Uc_Uc_B { unsigned char v1; unsigned char v2; bool v3; };
struct Uc_Ui_B { unsigned char v1; unsigned int v2; bool v3; };
struct Uc_Ul_B { unsigned char v1; unsigned long long v2; bool v3; };
struct Uc_Us_B { unsigned char v1; unsigned short v2; bool v3; };
struct Uc_Vp_B { unsigned char v1; void * v2; bool v3; };
struct Ui_B { unsigned int v1; bool v2; };
struct Ui_B_B { unsigned int v1; bool v2; bool v3; };
struct Ui_B_BFu15i { unsigned int v1; bool v2; unsigned int v3:15; };
struct Ui_B_BFu15ll { unsigned int v1; bool v2; unsigned long long v3:15; };
struct Ui_B_BFu15s { unsigned int v1; bool v2; unsigned short v3:15; };
struct Ui_B_BFu16i { unsigned int v1; bool v2; unsigned int v3:16; };
struct Ui_B_BFu16ll { unsigned int v1; bool v2; unsigned long long v3:16; };
struct Ui_B_BFu16s { unsigned int v1; bool v2; unsigned short v3:16; };
struct Ui_B_BFu17i { unsigned int v1; bool v2; unsigned int v3:17; };
struct Ui_B_BFu17ll { unsigned int v1; bool v2; unsigned long long v3:17; };
struct Ui_B_BFu1c { unsigned int v1; bool v2; unsigned char v3:1; };
struct Ui_B_BFu1i { unsigned int v1; bool v2; unsigned int v3:1; };
struct Ui_B_BFu1ll { unsigned int v1; bool v2; unsigned long long v3:1; };
struct Ui_B_BFu1s { unsigned int v1; bool v2; unsigned short v3:1; };
struct Ui_B_BFu31i { unsigned int v1; bool v2; unsigned int v3:31; };
struct Ui_B_BFu31ll { unsigned int v1; bool v2; unsigned long long v3:31; };
struct Ui_B_BFu32i { unsigned int v1; bool v2; unsigned int v3:32; };
struct Ui_B_BFu32ll { unsigned int v1; bool v2; unsigned long long v3:32; };
struct Ui_B_BFu33 { unsigned int v1; bool v2; unsigned long long v3:33; };
struct Ui_B_BFu7c { unsigned int v1; bool v2; unsigned char v3:7; };
struct Ui_B_BFu7i { unsigned int v1; bool v2; unsigned int v3:7; };
struct Ui_B_BFu7ll { unsigned int v1; bool v2; unsigned long long v3:7; };
struct Ui_B_BFu7s { unsigned int v1; bool v2; unsigned short v3:7; };
struct Ui_B_BFu8c { unsigned int v1; bool v2; unsigned char v3:8; };
struct Ui_B_BFu8i { unsigned int v1; bool v2; unsigned int v3:8; };
struct Ui_B_BFu8ll { unsigned int v1; bool v2; unsigned long long v3:8; };
struct Ui_B_BFu8s { unsigned int v1; bool v2; unsigned short v3:8; };
struct Ui_B_BFu9i { unsigned int v1; bool v2; unsigned int v3:9; };
struct Ui_B_BFu9ll { unsigned int v1; bool v2; unsigned long long v3:9; };
struct Ui_B_BFu9s { unsigned int v1; bool v2; unsigned short v3:9; };
struct Ui_B_C { unsigned int v1; bool v2; char v3; };
struct Ui_B_D { unsigned int v1; bool v2; double v3; };
struct Ui_B_F { unsigned int v1; bool v2; float v3; };
struct Ui_B_I { unsigned int v1; bool v2; int v3; };
struct Ui_B_Ip { unsigned int v1; bool v2; int * v3; };
struct Ui_B_L { unsigned int v1; bool v2; long long v3; };
struct Ui_B_S { unsigned int v1; bool v2; short v3; };
struct Ui_B_Uc { unsigned int v1; bool v2; unsigned char v3; };
struct Ui_B_Ui { unsigned int v1; bool v2; unsigned int v3; };
struct Ui_B_Ul { unsigned int v1; bool v2; unsigned long long v3; };
struct Ui_B_Us { unsigned int v1; bool v2; unsigned short v3; };
struct Ui_B_Vp { unsigned int v1; bool v2; void * v3; };
struct Ui_BFu15i_B { unsigned int v1; unsigned int v2:15; bool v3; };
struct Ui_BFu15ll_B { unsigned int v1; unsigned long long v2:15; bool v3; };
struct Ui_BFu15s_B { unsigned int v1; unsigned short v2:15; bool v3; };
struct Ui_BFu16i_B { unsigned int v1; unsigned int v2:16; bool v3; };
struct Ui_BFu16ll_B { unsigned int v1; unsigned long long v2:16; bool v3; };
struct Ui_BFu16s_B { unsigned int v1; unsigned short v2:16; bool v3; };
struct Ui_BFu17i_B { unsigned int v1; unsigned int v2:17; bool v3; };
struct Ui_BFu17ll_B { unsigned int v1; unsigned long long v2:17; bool v3; };
struct Ui_BFu1c_B { unsigned int v1; unsigned char v2:1; bool v3; };
struct Ui_BFu1i_B { unsigned int v1; unsigned int v2:1; bool v3; };
struct Ui_BFu1ll_B { unsigned int v1; unsigned long long v2:1; bool v3; };
struct Ui_BFu1s_B { unsigned int v1; unsigned short v2:1; bool v3; };
struct Ui_BFu31i_B { unsigned int v1; unsigned int v2:31; bool v3; };
struct Ui_BFu31ll_B { unsigned int v1; unsigned long long v2:31; bool v3; };
struct Ui_BFu32i_B { unsigned int v1; unsigned int v2:32; bool v3; };
struct Ui_BFu32ll_B { unsigned int v1; unsigned long long v2:32; bool v3; };
struct Ui_BFu33_B { unsigned int v1; unsigned long long v2:33; bool v3; };
struct Ui_BFu7c_B { unsigned int v1; unsigned char v2:7; bool v3; };
struct Ui_BFu7i_B { unsigned int v1; unsigned int v2:7; bool v3; };
struct Ui_BFu7ll_B { unsigned int v1; unsigned long long v2:7; bool v3; };
struct Ui_BFu7s_B { unsigned int v1; unsigned short v2:7; bool v3; };
struct Ui_BFu8c_B { unsigned int v1; unsigned char v2:8; bool v3; };
struct Ui_BFu8i_B { unsigned int v1; unsigned int v2:8; bool v3; };
struct Ui_BFu8ll_B { unsigned int v1; unsigned long long v2:8; bool v3; };
struct Ui_BFu8s_B { unsigned int v1; unsigned short v2:8; bool v3; };
struct Ui_BFu9i_B { unsigned int v1; unsigned int v2:9; bool v3; };
struct Ui_BFu9ll_B { unsigned int v1; unsigned long long v2:9; bool v3; };
struct Ui_BFu9s_B { unsigned int v1; unsigned short v2:9; bool v3; };
struct Ui_C_B { unsigned int v1; char v2; bool v3; };
struct Ui_D_B { unsigned int v1; double v2; bool v3; };
struct Ui_F_B { unsigned int v1; float v2; bool v3; };
struct Ui_I_B { unsigned int v1; int v2; bool v3; };
struct Ui_Ip_B { unsigned int v1; int * v2; bool v3; };
struct Ui_L_B { unsigned int v1; long long v2; bool v3; };
struct Ui_S_B { unsigned int v1; short v2; bool v3; };
struct Ui_Uc_B { unsigned int v1; unsigned char v2; bool v3; };
struct Ui_Ui_B { unsigned int v1; unsigned int v2; bool v3; };
struct Ui_Ul_B { unsigned int v1; unsigned long long v2; bool v3; };
struct Ui_Us_B { unsigned int v1; unsigned short v2; bool v3; };
struct Ui_Vp_B { unsigned int v1; void * v2; bool v3; };
struct Ul_B { unsigned long long v1; bool v2; };
struct Ul_B_B { unsigned long long v1; bool v2; bool v3; };
struct Ul_B_BFu15i { unsigned long long v1; bool v2; unsigned int v3:15; };
struct Ul_B_BFu15ll { unsigned long long v1; bool v2; unsigned long long v3:15; };
struct Ul_B_BFu15s { unsigned long long v1; bool v2; unsigned short v3:15; };
struct Ul_B_BFu16i { unsigned long long v1; bool v2; unsigned int v3:16; };
struct Ul_B_BFu16ll { unsigned long long v1; bool v2; unsigned long long v3:16; };
struct Ul_B_BFu16s { unsigned long long v1; bool v2; unsigned short v3:16; };
struct Ul_B_BFu17i { unsigned long long v1; bool v2; unsigned int v3:17; };
struct Ul_B_BFu17ll { unsigned long long v1; bool v2; unsigned long long v3:17; };
struct Ul_B_BFu1c { unsigned long long v1; bool v2; unsigned char v3:1; };
struct Ul_B_BFu1i { unsigned long long v1; bool v2; unsigned int v3:1; };
struct Ul_B_BFu1ll { unsigned long long v1; bool v2; unsigned long long v3:1; };
struct Ul_B_BFu1s { unsigned long long v1; bool v2; unsigned short v3:1; };
struct Ul_B_BFu31i { unsigned long long v1; bool v2; unsigned int v3:31; };
struct Ul_B_BFu31ll { unsigned long long v1; bool v2; unsigned long long v3:31; };
struct Ul_B_BFu32i { unsigned long long v1; bool v2; unsigned int v3:32; };
struct Ul_B_BFu32ll { unsigned long long v1; bool v2; unsigned long long v3:32; };
struct Ul_B_BFu33 { unsigned long long v1; bool v2; unsigned long long v3:33; };
struct Ul_B_BFu7c { unsigned long long v1; bool v2; unsigned char v3:7; };
struct Ul_B_BFu7i { unsigned long long v1; bool v2; unsigned int v3:7; };
struct Ul_B_BFu7ll { unsigned long long v1; bool v2; unsigned long long v3:7; };
struct Ul_B_BFu7s { unsigned long long v1; bool v2; unsigned short v3:7; };
struct Ul_B_BFu8c { unsigned long long v1; bool v2; unsigned char v3:8; };
struct Ul_B_BFu8i { unsigned long long v1; bool v2; unsigned int v3:8; };
struct Ul_B_BFu8ll { unsigned long long v1; bool v2; unsigned long long v3:8; };
struct Ul_B_BFu8s { unsigned long long v1; bool v2; unsigned short v3:8; };
struct Ul_B_BFu9i { unsigned long long v1; bool v2; unsigned int v3:9; };
struct Ul_B_BFu9ll { unsigned long long v1; bool v2; unsigned long long v3:9; };
struct Ul_B_BFu9s { unsigned long long v1; bool v2; unsigned short v3:9; };
struct Ul_B_C { unsigned long long v1; bool v2; char v3; };
struct Ul_B_D { unsigned long long v1; bool v2; double v3; };
struct Ul_B_F { unsigned long long v1; bool v2; float v3; };
struct Ul_B_I { unsigned long long v1; bool v2; int v3; };
struct Ul_B_Ip { unsigned long long v1; bool v2; int * v3; };
struct Ul_B_L { unsigned long long v1; bool v2; long long v3; };
struct Ul_B_S { unsigned long long v1; bool v2; short v3; };
struct Ul_B_Uc { unsigned long long v1; bool v2; unsigned char v3; };
struct Ul_B_Ui { unsigned long long v1; bool v2; unsigned int v3; };
struct Ul_B_Ul { unsigned long long v1; bool v2; unsigned long long v3; };
struct Ul_B_Us { unsigned long long v1; bool v2; unsigned short v3; };
struct Ul_B_Vp { unsigned long long v1; bool v2; void * v3; };
struct Ul_BFu15i_B { unsigned long long v1; unsigned int v2:15; bool v3; };
struct Ul_BFu15ll_B { unsigned long long v1; unsigned long long v2:15; bool v3; };
struct Ul_BFu15s_B { unsigned long long v1; unsigned short v2:15; bool v3; };
struct Ul_BFu16i_B { unsigned long long v1; unsigned int v2:16; bool v3; };
struct Ul_BFu16ll_B { unsigned long long v1; unsigned long long v2:16; bool v3; };
struct Ul_BFu16s_B { unsigned long long v1; unsigned short v2:16; bool v3; };
struct Ul_BFu17i_B { unsigned long long v1; unsigned int v2:17; bool v3; };
struct Ul_BFu17ll_B { unsigned long long v1; unsigned long long v2:17; bool v3; };
struct Ul_BFu1c_B { unsigned long long v1; unsigned char v2:1; bool v3; };
struct Ul_BFu1i_B { unsigned long long v1; unsigned int v2:1; bool v3; };
struct Ul_BFu1ll_B { unsigned long long v1; unsigned long long v2:1; bool v3; };
struct Ul_BFu1s_B { unsigned long long v1; unsigned short v2:1; bool v3; };
struct Ul_BFu31i_B { unsigned long long v1; unsigned int v2:31; bool v3; };
struct Ul_BFu31ll_B { unsigned long long v1; unsigned long long v2:31; bool v3; };
struct Ul_BFu32i_B { unsigned long long v1; unsigned int v2:32; bool v3; };
struct Ul_BFu32ll_B { unsigned long long v1; unsigned long long v2:32; bool v3; };
struct Ul_BFu33_B { unsigned long long v1; unsigned long long v2:33; bool v3; };
struct Ul_BFu7c_B { unsigned long long v1; unsigned char v2:7; bool v3; };
struct Ul_BFu7i_B { unsigned long long v1; unsigned int v2:7; bool v3; };
struct Ul_BFu7ll_B { unsigned long long v1; unsigned long long v2:7; bool v3; };
struct Ul_BFu7s_B { unsigned long long v1; unsigned short v2:7; bool v3; };
struct Ul_BFu8c_B { unsigned long long v1; unsigned char v2:8; bool v3; };
struct Ul_BFu8i_B { unsigned long long v1; unsigned int v2:8; bool v3; };
struct Ul_BFu8ll_B { unsigned long long v1; unsigned long long v2:8; bool v3; };
struct Ul_BFu8s_B { unsigned long long v1; unsigned short v2:8; bool v3; };
struct Ul_BFu9i_B { unsigned long long v1; unsigned int v2:9; bool v3; };
struct Ul_BFu9ll_B { unsigned long long v1; unsigned long long v2:9; bool v3; };
struct Ul_BFu9s_B { unsigned long long v1; unsigned short v2:9; bool v3; };
struct Ul_C_B { unsigned long long v1; char v2; bool v3; };
struct Ul_D_B { unsigned long long v1; double v2; bool v3; };
struct Ul_F_B { unsigned long long v1; float v2; bool v3; };
struct Ul_I_B { unsigned long long v1; int v2; bool v3; };
struct Ul_Ip_B { unsigned long long v1; int * v2; bool v3; };
struct Ul_L_B { unsigned long long v1; long long v2; bool v3; };
struct Ul_S_B { unsigned long long v1; short v2; bool v3; };
struct Ul_Uc_B { unsigned long long v1; unsigned char v2; bool v3; };
struct Ul_Ui_B { unsigned long long v1; unsigned int v2; bool v3; };
struct Ul_Ul_B { unsigned long long v1; unsigned long long v2; bool v3; };
struct Ul_Us_B { unsigned long long v1; unsigned short v2; bool v3; };
struct Ul_Vp_B { unsigned long long v1; void * v2; bool v3; };
struct Us_B { unsigned short v1; bool v2; };
struct Us_B_B { unsigned short v1; bool v2; bool v3; };
struct Us_B_BFu15i { unsigned short v1; bool v2; unsigned int v3:15; };
struct Us_B_BFu15ll { unsigned short v1; bool v2; unsigned long long v3:15; };
struct Us_B_BFu15s { unsigned short v1; bool v2; unsigned short v3:15; };
struct Us_B_BFu16i { unsigned short v1; bool v2; unsigned int v3:16; };
struct Us_B_BFu16ll { unsigned short v1; bool v2; unsigned long long v3:16; };
struct Us_B_BFu16s { unsigned short v1; bool v2; unsigned short v3:16; };
struct Us_B_BFu17i { unsigned short v1; bool v2; unsigned int v3:17; };
struct Us_B_BFu17ll { unsigned short v1; bool v2; unsigned long long v3:17; };
struct Us_B_BFu1c { unsigned short v1; bool v2; unsigned char v3:1; };
struct Us_B_BFu1i { unsigned short v1; bool v2; unsigned int v3:1; };
struct Us_B_BFu1ll { unsigned short v1; bool v2; unsigned long long v3:1; };
struct Us_B_BFu1s { unsigned short v1; bool v2; unsigned short v3:1; };
struct Us_B_BFu31i { unsigned short v1; bool v2; unsigned int v3:31; };
struct Us_B_BFu31ll { unsigned short v1; bool v2; unsigned long long v3:31; };
struct Us_B_BFu32i { unsigned short v1; bool v2; unsigned int v3:32; };
struct Us_B_BFu32ll { unsigned short v1; bool v2; unsigned long long v3:32; };
struct Us_B_BFu33 { unsigned short v1; bool v2; unsigned long long v3:33; };
struct Us_B_BFu7c { unsigned short v1; bool v2; unsigned char v3:7; };
struct Us_B_BFu7i { unsigned short v1; bool v2; unsigned int v3:7; };
struct Us_B_BFu7ll { unsigned short v1; bool v2; unsigned long long v3:7; };
struct Us_B_BFu7s { unsigned short v1; bool v2; unsigned short v3:7; };
struct Us_B_BFu8c { unsigned short v1; bool v2; unsigned char v3:8; };
struct Us_B_BFu8i { unsigned short v1; bool v2; unsigned int v3:8; };
struct Us_B_BFu8ll { unsigned short v1; bool v2; unsigned long long v3:8; };
struct Us_B_BFu8s { unsigned short v1; bool v2; unsigned short v3:8; };
struct Us_B_BFu9i { unsigned short v1; bool v2; unsigned int v3:9; };
struct Us_B_BFu9ll { unsigned short v1; bool v2; unsigned long long v3:9; };
struct Us_B_BFu9s { unsigned short v1; bool v2; unsigned short v3:9; };
struct Us_B_C { unsigned short v1; bool v2; char v3; };
struct Us_B_D { unsigned short v1; bool v2; double v3; };
struct Us_B_F { unsigned short v1; bool v2; float v3; };
struct Us_B_I { unsigned short v1; bool v2; int v3; };
struct Us_B_Ip { unsigned short v1; bool v2; int * v3; };
struct Us_B_L { unsigned short v1; bool v2; long long v3; };
struct Us_B_S { unsigned short v1; bool v2; short v3; };
struct Us_B_Uc { unsigned short v1; bool v2; unsigned char v3; };
struct Us_B_Ui { unsigned short v1; bool v2; unsigned int v3; };
struct Us_B_Ul { unsigned short v1; bool v2; unsigned long long v3; };
struct Us_B_Us { unsigned short v1; bool v2; unsigned short v3; };
struct Us_B_Vp { unsigned short v1; bool v2; void * v3; };
struct Us_BFu15i_B { unsigned short v1; unsigned int v2:15; bool v3; };
struct Us_BFu15ll_B { unsigned short v1; unsigned long long v2:15; bool v3; };
struct Us_BFu15s_B { unsigned short v1; unsigned short v2:15; bool v3; };
struct Us_BFu16i_B { unsigned short v1; unsigned int v2:16; bool v3; };
struct Us_BFu16ll_B { unsigned short v1; unsigned long long v2:16; bool v3; };
struct Us_BFu16s_B { unsigned short v1; unsigned short v2:16; bool v3; };
struct Us_BFu17i_B { unsigned short v1; unsigned int v2:17; bool v3; };
struct Us_BFu17ll_B { unsigned short v1; unsigned long long v2:17; bool v3; };
struct Us_BFu1c_B { unsigned short v1; unsigned char v2:1; bool v3; };
struct Us_BFu1i_B { unsigned short v1; unsigned int v2:1; bool v3; };
struct Us_BFu1ll_B { unsigned short v1; unsigned long long v2:1; bool v3; };
struct Us_BFu1s_B { unsigned short v1; unsigned short v2:1; bool v3; };
struct Us_BFu31i_B { unsigned short v1; unsigned int v2:31; bool v3; };
struct Us_BFu31ll_B { unsigned short v1; unsigned long long v2:31; bool v3; };
struct Us_BFu32i_B { unsigned short v1; unsigned int v2:32; bool v3; };
struct Us_BFu32ll_B { unsigned short v1; unsigned long long v2:32; bool v3; };
struct Us_BFu33_B { unsigned short v1; unsigned long long v2:33; bool v3; };
struct Us_BFu7c_B { unsigned short v1; unsigned char v2:7; bool v3; };
struct Us_BFu7i_B { unsigned short v1; unsigned int v2:7; bool v3; };
struct Us_BFu7ll_B { unsigned short v1; unsigned long long v2:7; bool v3; };
struct Us_BFu7s_B { unsigned short v1; unsigned short v2:7; bool v3; };
struct Us_BFu8c_B { unsigned short v1; unsigned char v2:8; bool v3; };
struct Us_BFu8i_B { unsigned short v1; unsigned int v2:8; bool v3; };
struct Us_BFu8ll_B { unsigned short v1; unsigned long long v2:8; bool v3; };
struct Us_BFu8s_B { unsigned short v1; unsigned short v2:8; bool v3; };
struct Us_BFu9i_B { unsigned short v1; unsigned int v2:9; bool v3; };
struct Us_BFu9ll_B { unsigned short v1; unsigned long long v2:9; bool v3; };
struct Us_BFu9s_B { unsigned short v1; unsigned short v2:9; bool v3; };
struct Us_C_B { unsigned short v1; char v2; bool v3; };
struct Us_D_B { unsigned short v1; double v2; bool v3; };
struct Us_F_B { unsigned short v1; float v2; bool v3; };
struct Us_I_B { unsigned short v1; int v2; bool v3; };
struct Us_Ip_B { unsigned short v1; int * v2; bool v3; };
struct Us_L_B { unsigned short v1; long long v2; bool v3; };
struct Us_S_B { unsigned short v1; short v2; bool v3; };
struct Us_Uc_B { unsigned short v1; unsigned char v2; bool v3; };
struct Us_Ui_B { unsigned short v1; unsigned int v2; bool v3; };
struct Us_Ul_B { unsigned short v1; unsigned long long v2; bool v3; };
struct Us_Us_B { unsigned short v1; unsigned short v2; bool v3; };
struct Us_Vp_B { unsigned short v1; void * v2; bool v3; };
struct Vp_B { void * v1; bool v2; };
struct Vp_B_B { void * v1; bool v2; bool v3; };
struct Vp_B_BFu15i { void * v1; bool v2; unsigned int v3:15; };
struct Vp_B_BFu15ll { void * v1; bool v2; unsigned long long v3:15; };
struct Vp_B_BFu15s { void * v1; bool v2; unsigned short v3:15; };
struct Vp_B_BFu16i { void * v1; bool v2; unsigned int v3:16; };
struct Vp_B_BFu16ll { void * v1; bool v2; unsigned long long v3:16; };
struct Vp_B_BFu16s { void * v1; bool v2; unsigned short v3:16; };
struct Vp_B_BFu17i { void * v1; bool v2; unsigned int v3:17; };
struct Vp_B_BFu17ll { void * v1; bool v2; unsigned long long v3:17; };
struct Vp_B_BFu1c { void * v1; bool v2; unsigned char v3:1; };
struct Vp_B_BFu1i { void * v1; bool v2; unsigned int v3:1; };
struct Vp_B_BFu1ll { void * v1; bool v2; unsigned long long v3:1; };
struct Vp_B_BFu1s { void * v1; bool v2; unsigned short v3:1; };
struct Vp_B_BFu31i { void * v1; bool v2; unsigned int v3:31; };
struct Vp_B_BFu31ll { void * v1; bool v2; unsigned long long v3:31; };
struct Vp_B_BFu32i { void * v1; bool v2; unsigned int v3:32; };
struct Vp_B_BFu32ll { void * v1; bool v2; unsigned long long v3:32; };
struct Vp_B_BFu33 { void * v1; bool v2; unsigned long long v3:33; };
struct Vp_B_BFu7c { void * v1; bool v2; unsigned char v3:7; };
struct Vp_B_BFu7i { void * v1; bool v2; unsigned int v3:7; };
struct Vp_B_BFu7ll { void * v1; bool v2; unsigned long long v3:7; };
struct Vp_B_BFu7s { void * v1; bool v2; unsigned short v3:7; };
struct Vp_B_BFu8c { void * v1; bool v2; unsigned char v3:8; };
struct Vp_B_BFu8i { void * v1; bool v2; unsigned int v3:8; };
struct Vp_B_BFu8ll { void * v1; bool v2; unsigned long long v3:8; };
struct Vp_B_BFu8s { void * v1; bool v2; unsigned short v3:8; };
struct Vp_B_BFu9i { void * v1; bool v2; unsigned int v3:9; };
struct Vp_B_BFu9ll { void * v1; bool v2; unsigned long long v3:9; };
struct Vp_B_BFu9s { void * v1; bool v2; unsigned short v3:9; };
struct Vp_B_C { void * v1; bool v2; char v3; };
struct Vp_B_D { void * v1; bool v2; double v3; };
struct Vp_B_F { void * v1; bool v2; float v3; };
struct Vp_B_I { void * v1; bool v2; int v3; };
struct Vp_B_Ip { void * v1; bool v2; int * v3; };
struct Vp_B_L { void * v1; bool v2; long long v3; };
struct Vp_B_S { void * v1; bool v2; short v3; };
struct Vp_B_Uc { void * v1; bool v2; unsigned char v3; };
struct Vp_B_Ui { void * v1; bool v2; unsigned int v3; };
struct Vp_B_Ul { void * v1; bool v2; unsigned long long v3; };
struct Vp_B_Us { void * v1; bool v2; unsigned short v3; };
struct Vp_B_Vp { void * v1; bool v2; void * v3; };
struct Vp_BFu15i_B { void * v1; unsigned int v2:15; bool v3; };
struct Vp_BFu15ll_B { void * v1; unsigned long long v2:15; bool v3; };
struct Vp_BFu15s_B { void * v1; unsigned short v2:15; bool v3; };
struct Vp_BFu16i_B { void * v1; unsigned int v2:16; bool v3; };
struct Vp_BFu16ll_B { void * v1; unsigned long long v2:16; bool v3; };
struct Vp_BFu16s_B { void * v1; unsigned short v2:16; bool v3; };
struct Vp_BFu17i_B { void * v1; unsigned int v2:17; bool v3; };
struct Vp_BFu17ll_B { void * v1; unsigned long long v2:17; bool v3; };
struct Vp_BFu1c_B { void * v1; unsigned char v2:1; bool v3; };
struct Vp_BFu1i_B { void * v1; unsigned int v2:1; bool v3; };
struct Vp_BFu1ll_B { void * v1; unsigned long long v2:1; bool v3; };
struct Vp_BFu1s_B { void * v1; unsigned short v2:1; bool v3; };
struct Vp_BFu31i_B { void * v1; unsigned int v2:31; bool v3; };
struct Vp_BFu31ll_B { void * v1; unsigned long long v2:31; bool v3; };
struct Vp_BFu32i_B { void * v1; unsigned int v2:32; bool v3; };
struct Vp_BFu32ll_B { void * v1; unsigned long long v2:32; bool v3; };
struct Vp_BFu33_B { void * v1; unsigned long long v2:33; bool v3; };
struct Vp_BFu7c_B { void * v1; unsigned char v2:7; bool v3; };
struct Vp_BFu7i_B { void * v1; unsigned int v2:7; bool v3; };
struct Vp_BFu7ll_B { void * v1; unsigned long long v2:7; bool v3; };
struct Vp_BFu7s_B { void * v1; unsigned short v2:7; bool v3; };
struct Vp_BFu8c_B { void * v1; unsigned char v2:8; bool v3; };
struct Vp_BFu8i_B { void * v1; unsigned int v2:8; bool v3; };
struct Vp_BFu8ll_B { void * v1; unsigned long long v2:8; bool v3; };
struct Vp_BFu8s_B { void * v1; unsigned short v2:8; bool v3; };
struct Vp_BFu9i_B { void * v1; unsigned int v2:9; bool v3; };
struct Vp_BFu9ll_B { void * v1; unsigned long long v2:9; bool v3; };
struct Vp_BFu9s_B { void * v1; unsigned short v2:9; bool v3; };
struct Vp_C_B { void * v1; char v2; bool v3; };
struct Vp_D_B { void * v1; double v2; bool v3; };
struct Vp_F_B { void * v1; float v2; bool v3; };
struct Vp_I_B { void * v1; int v2; bool v3; };
struct Vp_Ip_B { void * v1; int * v2; bool v3; };
struct Vp_L_B { void * v1; long long v2; bool v3; };
struct Vp_S_B { void * v1; short v2; bool v3; };
struct Vp_Uc_B { void * v1; unsigned char v2; bool v3; };
struct Vp_Ui_B { void * v1; unsigned int v2; bool v3; };
struct Vp_Ul_B { void * v1; unsigned long long v2; bool v3; };
struct Vp_Us_B { void * v1; unsigned short v2; bool v3; };
struct Vp_Vp_B { void * v1; void * v2; bool v3; };
#endif // __cplusplus
#ifdef __cplusplus


static void Test_BFu9s_BFu7i_B()
{
  {
    init_simple_test("BFu9s_BFu7i_B");
    static BFu9s_BFu7i_B lv;
    check2(sizeof(lv), 3, "sizeof(BFu9s_BFu7i_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_BFu7i_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_BFu7i_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_BFu7i_B");
    set_bf_and_test(lv, v2, 1, 1, 7, 1, "BFu9s_BFu7i_B");
    set_bf_and_test(lv, v2, 1, 1, 7, hide_ull(1LL<<6), "BFu9s_BFu7i_B");
    check_field_offset(lv, v3, 2, "BFu9s_BFu7i_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_BFu7i_B(Test_BFu9s_BFu7i_B, "BFu9s_BFu7i_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_BFu7ll_B()
{
  {
    init_simple_test("BFu9s_BFu7ll_B");
    static BFu9s_BFu7ll_B lv;
    check2(sizeof(lv), 3, "sizeof(BFu9s_BFu7ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_BFu7ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_BFu7ll_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_BFu7ll_B");
    set_bf_and_test(lv, v2, 1, 1, 7, 1, "BFu9s_BFu7ll_B");
    set_bf_and_test(lv, v2, 1, 1, 7, hide_ull(1LL<<6), "BFu9s_BFu7ll_B");
    check_field_offset(lv, v3, 2, "BFu9s_BFu7ll_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_BFu7ll_B(Test_BFu9s_BFu7ll_B, "BFu9s_BFu7ll_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_BFu7s_B()
{
  {
    init_simple_test("BFu9s_BFu7s_B");
    static BFu9s_BFu7s_B lv;
    check2(sizeof(lv), 3, "sizeof(BFu9s_BFu7s_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_BFu7s_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_BFu7s_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_BFu7s_B");
    set_bf_and_test(lv, v2, 1, 1, 7, 1, "BFu9s_BFu7s_B");
    set_bf_and_test(lv, v2, 1, 1, 7, hide_ull(1LL<<6), "BFu9s_BFu7s_B");
    check_field_offset(lv, v3, 2, "BFu9s_BFu7s_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_BFu7s_B(Test_BFu9s_BFu7s_B, "BFu9s_BFu7s_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_BFu8c_B()
{
  {
    init_simple_test("BFu9s_BFu8c_B");
    static BFu9s_BFu8c_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu9s_BFu8c_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_BFu8c_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_BFu8c_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_BFu8c_B");
    set_bf_and_test(lv, v2, 1, 1, 8, 1, "BFu9s_BFu8c_B");
    set_bf_and_test(lv, v2, 1, 1, 8, hide_ull(1LL<<7), "BFu9s_BFu8c_B");
    check_field_offset(lv, v3, 3, "BFu9s_BFu8c_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_BFu8c_B(Test_BFu9s_BFu8c_B, "BFu9s_BFu8c_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_BFu8i_B()
{
  {
    init_simple_test("BFu9s_BFu8i_B");
    static BFu9s_BFu8i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu9s_BFu8i_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_BFu8i_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_BFu8i_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_BFu8i_B");
    set_bf_and_test(lv, v2, 1, 1, 8, 1, "BFu9s_BFu8i_B");
    set_bf_and_test(lv, v2, 1, 1, 8, hide_ull(1LL<<7), "BFu9s_BFu8i_B");
    check_field_offset(lv, v3, 3, "BFu9s_BFu8i_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_BFu8i_B(Test_BFu9s_BFu8i_B, "BFu9s_BFu8i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_BFu8ll_B()
{
  {
    init_simple_test("BFu9s_BFu8ll_B");
    static BFu9s_BFu8ll_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu9s_BFu8ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_BFu8ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_BFu8ll_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_BFu8ll_B");
    set_bf_and_test(lv, v2, 1, 1, 8, 1, "BFu9s_BFu8ll_B");
    set_bf_and_test(lv, v2, 1, 1, 8, hide_ull(1LL<<7), "BFu9s_BFu8ll_B");
    check_field_offset(lv, v3, 3, "BFu9s_BFu8ll_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_BFu8ll_B(Test_BFu9s_BFu8ll_B, "BFu9s_BFu8ll_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_BFu8s_B()
{
  {
    init_simple_test("BFu9s_BFu8s_B");
    static BFu9s_BFu8s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu9s_BFu8s_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_BFu8s_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_BFu8s_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_BFu8s_B");
    set_bf_and_test(lv, v2, 1, 1, 8, 1, "BFu9s_BFu8s_B");
    set_bf_and_test(lv, v2, 1, 1, 8, hide_ull(1LL<<7), "BFu9s_BFu8s_B");
    check_field_offset(lv, v3, 3, "BFu9s_BFu8s_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_BFu8s_B(Test_BFu9s_BFu8s_B, "BFu9s_BFu8s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_BFu9i_B()
{
  {
    init_simple_test("BFu9s_BFu9i_B");
    static BFu9s_BFu9i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu9s_BFu9i_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_BFu9i_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_BFu9i_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_BFu9i_B");
    set_bf_and_test(lv, v2, 1, 1, 9, 1, "BFu9s_BFu9i_B");
    set_bf_and_test(lv, v2, 1, 1, 9, hide_ull(1LL<<8), "BFu9s_BFu9i_B");
    check_field_offset(lv, v3, 3, "BFu9s_BFu9i_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_BFu9i_B(Test_BFu9s_BFu9i_B, "BFu9s_BFu9i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_BFu9ll_B()
{
  {
    init_simple_test("BFu9s_BFu9ll_B");
    static BFu9s_BFu9ll_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu9s_BFu9ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_BFu9ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_BFu9ll_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_BFu9ll_B");
    set_bf_and_test(lv, v2, 1, 1, 9, 1, "BFu9s_BFu9ll_B");
    set_bf_and_test(lv, v2, 1, 1, 9, hide_ull(1LL<<8), "BFu9s_BFu9ll_B");
    check_field_offset(lv, v3, 3, "BFu9s_BFu9ll_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_BFu9ll_B(Test_BFu9s_BFu9ll_B, "BFu9s_BFu9ll_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_BFu9s_B()
{
  {
    init_simple_test("BFu9s_BFu9s_B");
    static BFu9s_BFu9s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu9s_BFu9s_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_BFu9s_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_BFu9s_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_BFu9s_B");
    set_bf_and_test(lv, v2, 1, 1, 9, 1, "BFu9s_BFu9s_B");
    set_bf_and_test(lv, v2, 1, 1, 9, hide_ull(1LL<<8), "BFu9s_BFu9s_B");
    check_field_offset(lv, v3, 3, "BFu9s_BFu9s_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_BFu9s_B(Test_BFu9s_BFu9s_B, "BFu9s_BFu9s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_C_B()
{
  {
    init_simple_test("BFu9s_C_B");
    static BFu9s_C_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu9s_C_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_C_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_C_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_C_B");
    check_field_offset(lv, v2, 2, "BFu9s_C_B.v2");
    check_field_offset(lv, v3, 3, "BFu9s_C_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_C_B(Test_BFu9s_C_B, "BFu9s_C_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_D_B()
{
  {
    init_simple_test("BFu9s_D_B");
    static BFu9s_D_B lv;
    check2(sizeof(lv), 11, "sizeof(BFu9s_D_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_D_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_D_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_D_B");
    check_field_offset(lv, v2, 2, "BFu9s_D_B.v2");
    check_field_offset(lv, v3, 10, "BFu9s_D_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_D_B(Test_BFu9s_D_B, "BFu9s_D_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_F_B()
{
  {
    init_simple_test("BFu9s_F_B");
    static BFu9s_F_B lv;
    check2(sizeof(lv), 7, "sizeof(BFu9s_F_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_F_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_F_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_F_B");
    check_field_offset(lv, v2, 2, "BFu9s_F_B.v2");
    check_field_offset(lv, v3, 6, "BFu9s_F_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_F_B(Test_BFu9s_F_B, "BFu9s_F_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_I_B()
{
  {
    init_simple_test("BFu9s_I_B");
    static BFu9s_I_B lv;
    check2(sizeof(lv), 7, "sizeof(BFu9s_I_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_I_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_I_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_I_B");
    check_field_offset(lv, v2, 2, "BFu9s_I_B.v2");
    check_field_offset(lv, v3, 6, "BFu9s_I_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_I_B(Test_BFu9s_I_B, "BFu9s_I_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_Ip_B()
{
  {
    init_simple_test("BFu9s_Ip_B");
    static BFu9s_Ip_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(BFu9s_Ip_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_Ip_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_Ip_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_Ip_B");
    check_field_offset(lv, v2, 2, "BFu9s_Ip_B.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "BFu9s_Ip_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_Ip_B(Test_BFu9s_Ip_B, "BFu9s_Ip_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_L_B()
{
  {
    init_simple_test("BFu9s_L_B");
    static BFu9s_L_B lv;
    check2(sizeof(lv), 11, "sizeof(BFu9s_L_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_L_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_L_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_L_B");
    check_field_offset(lv, v2, 2, "BFu9s_L_B.v2");
    check_field_offset(lv, v3, 10, "BFu9s_L_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_L_B(Test_BFu9s_L_B, "BFu9s_L_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_S_B()
{
  {
    init_simple_test("BFu9s_S_B");
    static BFu9s_S_B lv;
    check2(sizeof(lv), 5, "sizeof(BFu9s_S_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_S_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_S_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_S_B");
    check_field_offset(lv, v2, 2, "BFu9s_S_B.v2");
    check_field_offset(lv, v3, 4, "BFu9s_S_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_S_B(Test_BFu9s_S_B, "BFu9s_S_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_Uc_B()
{
  {
    init_simple_test("BFu9s_Uc_B");
    static BFu9s_Uc_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu9s_Uc_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_Uc_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_Uc_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_Uc_B");
    check_field_offset(lv, v2, 2, "BFu9s_Uc_B.v2");
    check_field_offset(lv, v3, 3, "BFu9s_Uc_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_Uc_B(Test_BFu9s_Uc_B, "BFu9s_Uc_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_Ui_B()
{
  {
    init_simple_test("BFu9s_Ui_B");
    static BFu9s_Ui_B lv;
    check2(sizeof(lv), 7, "sizeof(BFu9s_Ui_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_Ui_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_Ui_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_Ui_B");
    check_field_offset(lv, v2, 2, "BFu9s_Ui_B.v2");
    check_field_offset(lv, v3, 6, "BFu9s_Ui_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_Ui_B(Test_BFu9s_Ui_B, "BFu9s_Ui_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_Ul_B()
{
  {
    init_simple_test("BFu9s_Ul_B");
    static BFu9s_Ul_B lv;
    check2(sizeof(lv), 11, "sizeof(BFu9s_Ul_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_Ul_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_Ul_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_Ul_B");
    check_field_offset(lv, v2, 2, "BFu9s_Ul_B.v2");
    check_field_offset(lv, v3, 10, "BFu9s_Ul_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_Ul_B(Test_BFu9s_Ul_B, "BFu9s_Ul_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_Us_B()
{
  {
    init_simple_test("BFu9s_Us_B");
    static BFu9s_Us_B lv;
    check2(sizeof(lv), 5, "sizeof(BFu9s_Us_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_Us_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_Us_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_Us_B");
    check_field_offset(lv, v2, 2, "BFu9s_Us_B.v2");
    check_field_offset(lv, v3, 4, "BFu9s_Us_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_Us_B(Test_BFu9s_Us_B, "BFu9s_Us_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_BFu9s_Vp_B()
{
  {
    init_simple_test("BFu9s_Vp_B");
    static BFu9s_Vp_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(BFu9s_Vp_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu9s_Vp_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_Vp_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_Vp_B");
    check_field_offset(lv, v2, 2, "BFu9s_Vp_B.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "BFu9s_Vp_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_Vp_B(Test_BFu9s_Vp_B, "BFu9s_Vp_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B()
{
  {
    init_simple_test("C_B");
    C_B lv;
    check2(sizeof(lv), 2, "sizeof(C_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_B)");
    check_field_offset(lv, v1, 0, "C_B.v1");
    check_field_offset(lv, v2, 1, "C_B.v2");
  }
}
static Arrange_To_Call_Me vC_B(Test_C_B, "C_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_B()
{
  {
    init_simple_test("C_B_B");
    C_B_B lv;
    check2(sizeof(lv), 3, "sizeof(C_B_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_B)");
    check_field_offset(lv, v1, 0, "C_B_B.v1");
    check_field_offset(lv, v2, 1, "C_B_B.v2");
    check_field_offset(lv, v3, 2, "C_B_B.v3");
  }
}
static Arrange_To_Call_Me vC_B_B(Test_C_B_B, "C_B_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu15i()
{
  {
    init_simple_test("C_B_BFu15i");
    static C_B_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(C_B_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu15i)");
    check_field_offset(lv, v1, 0, "C_B_BFu15i.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu15i.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "C_B_BFu15i");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "C_B_BFu15i");
  }
}
static Arrange_To_Call_Me vC_B_BFu15i(Test_C_B_BFu15i, "C_B_BFu15i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu15ll()
{
  {
    init_simple_test("C_B_BFu15ll");
    static C_B_BFu15ll lv;
    check2(sizeof(lv), 4, "sizeof(C_B_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu15ll)");
    check_field_offset(lv, v1, 0, "C_B_BFu15ll.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu15ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "C_B_BFu15ll");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "C_B_BFu15ll");
  }
}
static Arrange_To_Call_Me vC_B_BFu15ll(Test_C_B_BFu15ll, "C_B_BFu15ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu15s()
{
  {
    init_simple_test("C_B_BFu15s");
    static C_B_BFu15s lv;
    check2(sizeof(lv), 4, "sizeof(C_B_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu15s)");
    check_field_offset(lv, v1, 0, "C_B_BFu15s.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu15s.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "C_B_BFu15s");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "C_B_BFu15s");
  }
}
static Arrange_To_Call_Me vC_B_BFu15s(Test_C_B_BFu15s, "C_B_BFu15s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu16i()
{
  {
    init_simple_test("C_B_BFu16i");
    static C_B_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(C_B_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu16i)");
    check_field_offset(lv, v1, 0, "C_B_BFu16i.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu16i.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "C_B_BFu16i");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "C_B_BFu16i");
  }
}
static Arrange_To_Call_Me vC_B_BFu16i(Test_C_B_BFu16i, "C_B_BFu16i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu16ll()
{
  {
    init_simple_test("C_B_BFu16ll");
    static C_B_BFu16ll lv;
    check2(sizeof(lv), 4, "sizeof(C_B_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu16ll)");
    check_field_offset(lv, v1, 0, "C_B_BFu16ll.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu16ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "C_B_BFu16ll");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "C_B_BFu16ll");
  }
}
static Arrange_To_Call_Me vC_B_BFu16ll(Test_C_B_BFu16ll, "C_B_BFu16ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu16s()
{
  {
    init_simple_test("C_B_BFu16s");
    static C_B_BFu16s lv;
    check2(sizeof(lv), 4, "sizeof(C_B_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu16s)");
    check_field_offset(lv, v1, 0, "C_B_BFu16s.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu16s.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "C_B_BFu16s");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "C_B_BFu16s");
  }
}
static Arrange_To_Call_Me vC_B_BFu16s(Test_C_B_BFu16s, "C_B_BFu16s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu17i()
{
  {
    init_simple_test("C_B_BFu17i");
    static C_B_BFu17i lv;
    check2(sizeof(lv), 5, "sizeof(C_B_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu17i)");
    check_field_offset(lv, v1, 0, "C_B_BFu17i.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu17i.v2");
    set_bf_and_test(lv, v3, 2, 0, 17, 1, "C_B_BFu17i");
    set_bf_and_test(lv, v3, 2, 0, 17, hide_ull(1LL<<16), "C_B_BFu17i");
  }
}
static Arrange_To_Call_Me vC_B_BFu17i(Test_C_B_BFu17i, "C_B_BFu17i", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu17ll()
{
  {
    init_simple_test("C_B_BFu17ll");
    static C_B_BFu17ll lv;
    check2(sizeof(lv), 5, "sizeof(C_B_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu17ll)");
    check_field_offset(lv, v1, 0, "C_B_BFu17ll.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu17ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 17, 1, "C_B_BFu17ll");
    set_bf_and_test(lv, v3, 2, 0, 17, hide_ull(1LL<<16), "C_B_BFu17ll");
  }
}
static Arrange_To_Call_Me vC_B_BFu17ll(Test_C_B_BFu17ll, "C_B_BFu17ll", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu1c()
{
  {
    init_simple_test("C_B_BFu1c");
    static C_B_BFu1c lv;
    check2(sizeof(lv), 3, "sizeof(C_B_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu1c)");
    check_field_offset(lv, v1, 0, "C_B_BFu1c.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu1c.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "C_B_BFu1c");
  }
}
static Arrange_To_Call_Me vC_B_BFu1c(Test_C_B_BFu1c, "C_B_BFu1c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu1i()
{
  {
    init_simple_test("C_B_BFu1i");
    static C_B_BFu1i lv;
    check2(sizeof(lv), 3, "sizeof(C_B_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu1i)");
    check_field_offset(lv, v1, 0, "C_B_BFu1i.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu1i.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "C_B_BFu1i");
  }
}
static Arrange_To_Call_Me vC_B_BFu1i(Test_C_B_BFu1i, "C_B_BFu1i", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu1ll()
{
  {
    init_simple_test("C_B_BFu1ll");
    static C_B_BFu1ll lv;
    check2(sizeof(lv), 3, "sizeof(C_B_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu1ll)");
    check_field_offset(lv, v1, 0, "C_B_BFu1ll.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu1ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "C_B_BFu1ll");
  }
}
static Arrange_To_Call_Me vC_B_BFu1ll(Test_C_B_BFu1ll, "C_B_BFu1ll", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu1s()
{
  {
    init_simple_test("C_B_BFu1s");
    static C_B_BFu1s lv;
    check2(sizeof(lv), 3, "sizeof(C_B_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu1s)");
    check_field_offset(lv, v1, 0, "C_B_BFu1s.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu1s.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "C_B_BFu1s");
  }
}
static Arrange_To_Call_Me vC_B_BFu1s(Test_C_B_BFu1s, "C_B_BFu1s", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu31i()
{
  {
    init_simple_test("C_B_BFu31i");
    static C_B_BFu31i lv;
    check2(sizeof(lv), 6, "sizeof(C_B_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu31i)");
    check_field_offset(lv, v1, 0, "C_B_BFu31i.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu31i.v2");
    set_bf_and_test(lv, v3, 2, 0, 31, 1, "C_B_BFu31i");
    set_bf_and_test(lv, v3, 2, 0, 31, hide_ull(1LL<<30), "C_B_BFu31i");
  }
}
static Arrange_To_Call_Me vC_B_BFu31i(Test_C_B_BFu31i, "C_B_BFu31i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu31ll()
{
  {
    init_simple_test("C_B_BFu31ll");
    static C_B_BFu31ll lv;
    check2(sizeof(lv), 6, "sizeof(C_B_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu31ll)");
    check_field_offset(lv, v1, 0, "C_B_BFu31ll.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu31ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 31, 1, "C_B_BFu31ll");
    set_bf_and_test(lv, v3, 2, 0, 31, hide_ull(1LL<<30), "C_B_BFu31ll");
  }
}
static Arrange_To_Call_Me vC_B_BFu31ll(Test_C_B_BFu31ll, "C_B_BFu31ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu32i()
{
  {
    init_simple_test("C_B_BFu32i");
    static C_B_BFu32i lv;
    check2(sizeof(lv), 6, "sizeof(C_B_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu32i)");
    check_field_offset(lv, v1, 0, "C_B_BFu32i.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu32i.v2");
    set_bf_and_test(lv, v3, 2, 0, 32, 1, "C_B_BFu32i");
    set_bf_and_test(lv, v3, 2, 0, 32, hide_ull(1LL<<31), "C_B_BFu32i");
  }
}
static Arrange_To_Call_Me vC_B_BFu32i(Test_C_B_BFu32i, "C_B_BFu32i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu32ll()
{
  {
    init_simple_test("C_B_BFu32ll");
    static C_B_BFu32ll lv;
    check2(sizeof(lv), 6, "sizeof(C_B_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu32ll)");
    check_field_offset(lv, v1, 0, "C_B_BFu32ll.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu32ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 32, 1, "C_B_BFu32ll");
    set_bf_and_test(lv, v3, 2, 0, 32, hide_ull(1LL<<31), "C_B_BFu32ll");
  }
}
static Arrange_To_Call_Me vC_B_BFu32ll(Test_C_B_BFu32ll, "C_B_BFu32ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu33()
{
  {
    init_simple_test("C_B_BFu33");
    static C_B_BFu33 lv;
    check2(sizeof(lv), 7, "sizeof(C_B_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu33)");
    check_field_offset(lv, v1, 0, "C_B_BFu33.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu33.v2");
    set_bf_and_test(lv, v3, 2, 0, 33, 1, "C_B_BFu33");
    set_bf_and_test(lv, v3, 2, 0, 33, hide_ull(1LL<<32), "C_B_BFu33");
  }
}
static Arrange_To_Call_Me vC_B_BFu33(Test_C_B_BFu33, "C_B_BFu33", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu7c()
{
  {
    init_simple_test("C_B_BFu7c");
    static C_B_BFu7c lv;
    check2(sizeof(lv), 3, "sizeof(C_B_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu7c)");
    check_field_offset(lv, v1, 0, "C_B_BFu7c.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu7c.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "C_B_BFu7c");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "C_B_BFu7c");
  }
}
static Arrange_To_Call_Me vC_B_BFu7c(Test_C_B_BFu7c, "C_B_BFu7c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu7i()
{
  {
    init_simple_test("C_B_BFu7i");
    static C_B_BFu7i lv;
    check2(sizeof(lv), 3, "sizeof(C_B_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu7i)");
    check_field_offset(lv, v1, 0, "C_B_BFu7i.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu7i.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "C_B_BFu7i");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "C_B_BFu7i");
  }
}
static Arrange_To_Call_Me vC_B_BFu7i(Test_C_B_BFu7i, "C_B_BFu7i", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu7ll()
{
  {
    init_simple_test("C_B_BFu7ll");
    static C_B_BFu7ll lv;
    check2(sizeof(lv), 3, "sizeof(C_B_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu7ll)");
    check_field_offset(lv, v1, 0, "C_B_BFu7ll.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu7ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "C_B_BFu7ll");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "C_B_BFu7ll");
  }
}
static Arrange_To_Call_Me vC_B_BFu7ll(Test_C_B_BFu7ll, "C_B_BFu7ll", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu7s()
{
  {
    init_simple_test("C_B_BFu7s");
    static C_B_BFu7s lv;
    check2(sizeof(lv), 3, "sizeof(C_B_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu7s)");
    check_field_offset(lv, v1, 0, "C_B_BFu7s.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu7s.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "C_B_BFu7s");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "C_B_BFu7s");
  }
}
static Arrange_To_Call_Me vC_B_BFu7s(Test_C_B_BFu7s, "C_B_BFu7s", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu8c()
{
  {
    init_simple_test("C_B_BFu8c");
    static C_B_BFu8c lv;
    check2(sizeof(lv), 3, "sizeof(C_B_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu8c)");
    check_field_offset(lv, v1, 0, "C_B_BFu8c.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu8c.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "C_B_BFu8c");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "C_B_BFu8c");
  }
}
static Arrange_To_Call_Me vC_B_BFu8c(Test_C_B_BFu8c, "C_B_BFu8c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu8i()
{
  {
    init_simple_test("C_B_BFu8i");
    static C_B_BFu8i lv;
    check2(sizeof(lv), 3, "sizeof(C_B_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu8i)");
    check_field_offset(lv, v1, 0, "C_B_BFu8i.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu8i.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "C_B_BFu8i");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "C_B_BFu8i");
  }
}
static Arrange_To_Call_Me vC_B_BFu8i(Test_C_B_BFu8i, "C_B_BFu8i", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu8ll()
{
  {
    init_simple_test("C_B_BFu8ll");
    static C_B_BFu8ll lv;
    check2(sizeof(lv), 3, "sizeof(C_B_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu8ll)");
    check_field_offset(lv, v1, 0, "C_B_BFu8ll.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu8ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "C_B_BFu8ll");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "C_B_BFu8ll");
  }
}
static Arrange_To_Call_Me vC_B_BFu8ll(Test_C_B_BFu8ll, "C_B_BFu8ll", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu8s()
{
  {
    init_simple_test("C_B_BFu8s");
    static C_B_BFu8s lv;
    check2(sizeof(lv), 3, "sizeof(C_B_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu8s)");
    check_field_offset(lv, v1, 0, "C_B_BFu8s.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu8s.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "C_B_BFu8s");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "C_B_BFu8s");
  }
}
static Arrange_To_Call_Me vC_B_BFu8s(Test_C_B_BFu8s, "C_B_BFu8s", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu9i()
{
  {
    init_simple_test("C_B_BFu9i");
    static C_B_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(C_B_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu9i)");
    check_field_offset(lv, v1, 0, "C_B_BFu9i.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu9i.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "C_B_BFu9i");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "C_B_BFu9i");
  }
}
static Arrange_To_Call_Me vC_B_BFu9i(Test_C_B_BFu9i, "C_B_BFu9i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu9ll()
{
  {
    init_simple_test("C_B_BFu9ll");
    static C_B_BFu9ll lv;
    check2(sizeof(lv), 4, "sizeof(C_B_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu9ll)");
    check_field_offset(lv, v1, 0, "C_B_BFu9ll.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu9ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "C_B_BFu9ll");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "C_B_BFu9ll");
  }
}
static Arrange_To_Call_Me vC_B_BFu9ll(Test_C_B_BFu9ll, "C_B_BFu9ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_BFu9s()
{
  {
    init_simple_test("C_B_BFu9s");
    static C_B_BFu9s lv;
    check2(sizeof(lv), 4, "sizeof(C_B_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu9s)");
    check_field_offset(lv, v1, 0, "C_B_BFu9s.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu9s.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "C_B_BFu9s");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "C_B_BFu9s");
  }
}
static Arrange_To_Call_Me vC_B_BFu9s(Test_C_B_BFu9s, "C_B_BFu9s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_C()
{
  {
    init_simple_test("C_B_C");
    C_B_C lv;
    check2(sizeof(lv), 3, "sizeof(C_B_C)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_C)");
    check_field_offset(lv, v1, 0, "C_B_C.v1");
    check_field_offset(lv, v2, 1, "C_B_C.v2");
    check_field_offset(lv, v3, 2, "C_B_C.v3");
  }
}
static Arrange_To_Call_Me vC_B_C(Test_C_B_C, "C_B_C", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_D()
{
  {
    init_simple_test("C_B_D");
    C_B_D lv;
    check2(sizeof(lv), 10, "sizeof(C_B_D)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_D)");
    check_field_offset(lv, v1, 0, "C_B_D.v1");
    check_field_offset(lv, v2, 1, "C_B_D.v2");
    check_field_offset(lv, v3, 2, "C_B_D.v3");
  }
}
static Arrange_To_Call_Me vC_B_D(Test_C_B_D, "C_B_D", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_F()
{
  {
    init_simple_test("C_B_F");
    C_B_F lv;
    check2(sizeof(lv), 6, "sizeof(C_B_F)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_F)");
    check_field_offset(lv, v1, 0, "C_B_F.v1");
    check_field_offset(lv, v2, 1, "C_B_F.v2");
    check_field_offset(lv, v3, 2, "C_B_F.v3");
  }
}
static Arrange_To_Call_Me vC_B_F(Test_C_B_F, "C_B_F", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_I()
{
  {
    init_simple_test("C_B_I");
    C_B_I lv;
    check2(sizeof(lv), 6, "sizeof(C_B_I)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_I)");
    check_field_offset(lv, v1, 0, "C_B_I.v1");
    check_field_offset(lv, v2, 1, "C_B_I.v2");
    check_field_offset(lv, v3, 2, "C_B_I.v3");
  }
}
static Arrange_To_Call_Me vC_B_I(Test_C_B_I, "C_B_I", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_Ip()
{
  {
    init_simple_test("C_B_Ip");
    C_B_Ip lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(C_B_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_Ip)");
    check_field_offset(lv, v1, 0, "C_B_Ip.v1");
    check_field_offset(lv, v2, 1, "C_B_Ip.v2");
    check_field_offset(lv, v3, 2, "C_B_Ip.v3");
  }
}
static Arrange_To_Call_Me vC_B_Ip(Test_C_B_Ip, "C_B_Ip", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_L()
{
  {
    init_simple_test("C_B_L");
    C_B_L lv;
    check2(sizeof(lv), 10, "sizeof(C_B_L)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_L)");
    check_field_offset(lv, v1, 0, "C_B_L.v1");
    check_field_offset(lv, v2, 1, "C_B_L.v2");
    check_field_offset(lv, v3, 2, "C_B_L.v3");
  }
}
static Arrange_To_Call_Me vC_B_L(Test_C_B_L, "C_B_L", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_S()
{
  {
    init_simple_test("C_B_S");
    C_B_S lv;
    check2(sizeof(lv), 4, "sizeof(C_B_S)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_S)");
    check_field_offset(lv, v1, 0, "C_B_S.v1");
    check_field_offset(lv, v2, 1, "C_B_S.v2");
    check_field_offset(lv, v3, 2, "C_B_S.v3");
  }
}
static Arrange_To_Call_Me vC_B_S(Test_C_B_S, "C_B_S", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_Uc()
{
  {
    init_simple_test("C_B_Uc");
    C_B_Uc lv;
    check2(sizeof(lv), 3, "sizeof(C_B_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_Uc)");
    check_field_offset(lv, v1, 0, "C_B_Uc.v1");
    check_field_offset(lv, v2, 1, "C_B_Uc.v2");
    check_field_offset(lv, v3, 2, "C_B_Uc.v3");
  }
}
static Arrange_To_Call_Me vC_B_Uc(Test_C_B_Uc, "C_B_Uc", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_Ui()
{
  {
    init_simple_test("C_B_Ui");
    C_B_Ui lv;
    check2(sizeof(lv), 6, "sizeof(C_B_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_Ui)");
    check_field_offset(lv, v1, 0, "C_B_Ui.v1");
    check_field_offset(lv, v2, 1, "C_B_Ui.v2");
    check_field_offset(lv, v3, 2, "C_B_Ui.v3");
  }
}
static Arrange_To_Call_Me vC_B_Ui(Test_C_B_Ui, "C_B_Ui", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_Ul()
{
  {
    init_simple_test("C_B_Ul");
    C_B_Ul lv;
    check2(sizeof(lv), 10, "sizeof(C_B_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_Ul)");
    check_field_offset(lv, v1, 0, "C_B_Ul.v1");
    check_field_offset(lv, v2, 1, "C_B_Ul.v2");
    check_field_offset(lv, v3, 2, "C_B_Ul.v3");
  }
}
static Arrange_To_Call_Me vC_B_Ul(Test_C_B_Ul, "C_B_Ul", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_Us()
{
  {
    init_simple_test("C_B_Us");
    C_B_Us lv;
    check2(sizeof(lv), 4, "sizeof(C_B_Us)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_Us)");
    check_field_offset(lv, v1, 0, "C_B_Us.v1");
    check_field_offset(lv, v2, 1, "C_B_Us.v2");
    check_field_offset(lv, v3, 2, "C_B_Us.v3");
  }
}
static Arrange_To_Call_Me vC_B_Us(Test_C_B_Us, "C_B_Us", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_B_Vp()
{
  {
    init_simple_test("C_B_Vp");
    C_B_Vp lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(C_B_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_Vp)");
    check_field_offset(lv, v1, 0, "C_B_Vp.v1");
    check_field_offset(lv, v2, 1, "C_B_Vp.v2");
    check_field_offset(lv, v3, 2, "C_B_Vp.v3");
  }
}
static Arrange_To_Call_Me vC_B_Vp(Test_C_B_Vp, "C_B_Vp", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu15i_B()
{
  {
    init_simple_test("C_BFu15i_B");
    static C_BFu15i_B lv;
    check2(sizeof(lv), 4, "sizeof(C_BFu15i_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu15i_B)");
    check_field_offset(lv, v1, 0, "C_BFu15i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "C_BFu15i_B");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "C_BFu15i_B");
    check_field_offset(lv, v3, 3, "C_BFu15i_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu15i_B(Test_C_BFu15i_B, "C_BFu15i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu15ll_B()
{
  {
    init_simple_test("C_BFu15ll_B");
    static C_BFu15ll_B lv;
    check2(sizeof(lv), 4, "sizeof(C_BFu15ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu15ll_B)");
    check_field_offset(lv, v1, 0, "C_BFu15ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "C_BFu15ll_B");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "C_BFu15ll_B");
    check_field_offset(lv, v3, 3, "C_BFu15ll_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu15ll_B(Test_C_BFu15ll_B, "C_BFu15ll_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu15s_B()
{
  {
    init_simple_test("C_BFu15s_B");
    static C_BFu15s_B lv;
    check2(sizeof(lv), 4, "sizeof(C_BFu15s_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu15s_B)");
    check_field_offset(lv, v1, 0, "C_BFu15s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "C_BFu15s_B");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "C_BFu15s_B");
    check_field_offset(lv, v3, 3, "C_BFu15s_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu15s_B(Test_C_BFu15s_B, "C_BFu15s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu16i_B()
{
  {
    init_simple_test("C_BFu16i_B");
    static C_BFu16i_B lv;
    check2(sizeof(lv), 4, "sizeof(C_BFu16i_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu16i_B)");
    check_field_offset(lv, v1, 0, "C_BFu16i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "C_BFu16i_B");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "C_BFu16i_B");
    check_field_offset(lv, v3, 3, "C_BFu16i_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu16i_B(Test_C_BFu16i_B, "C_BFu16i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu16ll_B()
{
  {
    init_simple_test("C_BFu16ll_B");
    static C_BFu16ll_B lv;
    check2(sizeof(lv), 4, "sizeof(C_BFu16ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu16ll_B)");
    check_field_offset(lv, v1, 0, "C_BFu16ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "C_BFu16ll_B");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "C_BFu16ll_B");
    check_field_offset(lv, v3, 3, "C_BFu16ll_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu16ll_B(Test_C_BFu16ll_B, "C_BFu16ll_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu16s_B()
{
  {
    init_simple_test("C_BFu16s_B");
    static C_BFu16s_B lv;
    check2(sizeof(lv), 4, "sizeof(C_BFu16s_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu16s_B)");
    check_field_offset(lv, v1, 0, "C_BFu16s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "C_BFu16s_B");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "C_BFu16s_B");
    check_field_offset(lv, v3, 3, "C_BFu16s_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu16s_B(Test_C_BFu16s_B, "C_BFu16s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu17i_B()
{
  {
    init_simple_test("C_BFu17i_B");
    static C_BFu17i_B lv;
    check2(sizeof(lv), 5, "sizeof(C_BFu17i_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu17i_B)");
    check_field_offset(lv, v1, 0, "C_BFu17i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "C_BFu17i_B");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "C_BFu17i_B");
    check_field_offset(lv, v3, 4, "C_BFu17i_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu17i_B(Test_C_BFu17i_B, "C_BFu17i_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu17ll_B()
{
  {
    init_simple_test("C_BFu17ll_B");
    static C_BFu17ll_B lv;
    check2(sizeof(lv), 5, "sizeof(C_BFu17ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu17ll_B)");
    check_field_offset(lv, v1, 0, "C_BFu17ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "C_BFu17ll_B");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "C_BFu17ll_B");
    check_field_offset(lv, v3, 4, "C_BFu17ll_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu17ll_B(Test_C_BFu17ll_B, "C_BFu17ll_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu1c_B()
{
  {
    init_simple_test("C_BFu1c_B");
    static C_BFu1c_B lv;
    check2(sizeof(lv), 3, "sizeof(C_BFu1c_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu1c_B)");
    check_field_offset(lv, v1, 0, "C_BFu1c_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "C_BFu1c_B");
    check_field_offset(lv, v3, 2, "C_BFu1c_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu1c_B(Test_C_BFu1c_B, "C_BFu1c_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu1i_B()
{
  {
    init_simple_test("C_BFu1i_B");
    static C_BFu1i_B lv;
    check2(sizeof(lv), 3, "sizeof(C_BFu1i_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu1i_B)");
    check_field_offset(lv, v1, 0, "C_BFu1i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "C_BFu1i_B");
    check_field_offset(lv, v3, 2, "C_BFu1i_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu1i_B(Test_C_BFu1i_B, "C_BFu1i_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu1ll_B()
{
  {
    init_simple_test("C_BFu1ll_B");
    static C_BFu1ll_B lv;
    check2(sizeof(lv), 3, "sizeof(C_BFu1ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu1ll_B)");
    check_field_offset(lv, v1, 0, "C_BFu1ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "C_BFu1ll_B");
    check_field_offset(lv, v3, 2, "C_BFu1ll_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu1ll_B(Test_C_BFu1ll_B, "C_BFu1ll_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu1s_B()
{
  {
    init_simple_test("C_BFu1s_B");
    static C_BFu1s_B lv;
    check2(sizeof(lv), 3, "sizeof(C_BFu1s_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu1s_B)");
    check_field_offset(lv, v1, 0, "C_BFu1s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "C_BFu1s_B");
    check_field_offset(lv, v3, 2, "C_BFu1s_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu1s_B(Test_C_BFu1s_B, "C_BFu1s_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu31i_B()
{
  {
    init_simple_test("C_BFu31i_B");
    static C_BFu31i_B lv;
    check2(sizeof(lv), 6, "sizeof(C_BFu31i_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu31i_B)");
    check_field_offset(lv, v1, 0, "C_BFu31i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "C_BFu31i_B");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "C_BFu31i_B");
    check_field_offset(lv, v3, 5, "C_BFu31i_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu31i_B(Test_C_BFu31i_B, "C_BFu31i_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu31ll_B()
{
  {
    init_simple_test("C_BFu31ll_B");
    static C_BFu31ll_B lv;
    check2(sizeof(lv), 6, "sizeof(C_BFu31ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu31ll_B)");
    check_field_offset(lv, v1, 0, "C_BFu31ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "C_BFu31ll_B");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "C_BFu31ll_B");
    check_field_offset(lv, v3, 5, "C_BFu31ll_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu31ll_B(Test_C_BFu31ll_B, "C_BFu31ll_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu32i_B()
{
  {
    init_simple_test("C_BFu32i_B");
    static C_BFu32i_B lv;
    check2(sizeof(lv), 6, "sizeof(C_BFu32i_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu32i_B)");
    check_field_offset(lv, v1, 0, "C_BFu32i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "C_BFu32i_B");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "C_BFu32i_B");
    check_field_offset(lv, v3, 5, "C_BFu32i_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu32i_B(Test_C_BFu32i_B, "C_BFu32i_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu32ll_B()
{
  {
    init_simple_test("C_BFu32ll_B");
    static C_BFu32ll_B lv;
    check2(sizeof(lv), 6, "sizeof(C_BFu32ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu32ll_B)");
    check_field_offset(lv, v1, 0, "C_BFu32ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "C_BFu32ll_B");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "C_BFu32ll_B");
    check_field_offset(lv, v3, 5, "C_BFu32ll_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu32ll_B(Test_C_BFu32ll_B, "C_BFu32ll_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu33_B()
{
  {
    init_simple_test("C_BFu33_B");
    static C_BFu33_B lv;
    check2(sizeof(lv), 7, "sizeof(C_BFu33_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu33_B)");
    check_field_offset(lv, v1, 0, "C_BFu33_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 33, 1, "C_BFu33_B");
    set_bf_and_test(lv, v2, 1, 0, 33, hide_ull(1LL<<32), "C_BFu33_B");
    check_field_offset(lv, v3, 6, "C_BFu33_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu33_B(Test_C_BFu33_B, "C_BFu33_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu7c_B()
{
  {
    init_simple_test("C_BFu7c_B");
    static C_BFu7c_B lv;
    check2(sizeof(lv), 3, "sizeof(C_BFu7c_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu7c_B)");
    check_field_offset(lv, v1, 0, "C_BFu7c_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "C_BFu7c_B");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "C_BFu7c_B");
    check_field_offset(lv, v3, 2, "C_BFu7c_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu7c_B(Test_C_BFu7c_B, "C_BFu7c_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu7i_B()
{
  {
    init_simple_test("C_BFu7i_B");
    static C_BFu7i_B lv;
    check2(sizeof(lv), 3, "sizeof(C_BFu7i_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu7i_B)");
    check_field_offset(lv, v1, 0, "C_BFu7i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "C_BFu7i_B");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "C_BFu7i_B");
    check_field_offset(lv, v3, 2, "C_BFu7i_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu7i_B(Test_C_BFu7i_B, "C_BFu7i_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu7ll_B()
{
  {
    init_simple_test("C_BFu7ll_B");
    static C_BFu7ll_B lv;
    check2(sizeof(lv), 3, "sizeof(C_BFu7ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu7ll_B)");
    check_field_offset(lv, v1, 0, "C_BFu7ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "C_BFu7ll_B");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "C_BFu7ll_B");
    check_field_offset(lv, v3, 2, "C_BFu7ll_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu7ll_B(Test_C_BFu7ll_B, "C_BFu7ll_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu7s_B()
{
  {
    init_simple_test("C_BFu7s_B");
    static C_BFu7s_B lv;
    check2(sizeof(lv), 3, "sizeof(C_BFu7s_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu7s_B)");
    check_field_offset(lv, v1, 0, "C_BFu7s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "C_BFu7s_B");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "C_BFu7s_B");
    check_field_offset(lv, v3, 2, "C_BFu7s_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu7s_B(Test_C_BFu7s_B, "C_BFu7s_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu8c_B()
{
  {
    init_simple_test("C_BFu8c_B");
    static C_BFu8c_B lv;
    check2(sizeof(lv), 3, "sizeof(C_BFu8c_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu8c_B)");
    check_field_offset(lv, v1, 0, "C_BFu8c_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "C_BFu8c_B");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "C_BFu8c_B");
    check_field_offset(lv, v3, 2, "C_BFu8c_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu8c_B(Test_C_BFu8c_B, "C_BFu8c_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu8i_B()
{
  {
    init_simple_test("C_BFu8i_B");
    static C_BFu8i_B lv;
    check2(sizeof(lv), 3, "sizeof(C_BFu8i_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu8i_B)");
    check_field_offset(lv, v1, 0, "C_BFu8i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "C_BFu8i_B");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "C_BFu8i_B");
    check_field_offset(lv, v3, 2, "C_BFu8i_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu8i_B(Test_C_BFu8i_B, "C_BFu8i_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu8ll_B()
{
  {
    init_simple_test("C_BFu8ll_B");
    static C_BFu8ll_B lv;
    check2(sizeof(lv), 3, "sizeof(C_BFu8ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu8ll_B)");
    check_field_offset(lv, v1, 0, "C_BFu8ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "C_BFu8ll_B");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "C_BFu8ll_B");
    check_field_offset(lv, v3, 2, "C_BFu8ll_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu8ll_B(Test_C_BFu8ll_B, "C_BFu8ll_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu8s_B()
{
  {
    init_simple_test("C_BFu8s_B");
    static C_BFu8s_B lv;
    check2(sizeof(lv), 3, "sizeof(C_BFu8s_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu8s_B)");
    check_field_offset(lv, v1, 0, "C_BFu8s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "C_BFu8s_B");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "C_BFu8s_B");
    check_field_offset(lv, v3, 2, "C_BFu8s_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu8s_B(Test_C_BFu8s_B, "C_BFu8s_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu9i_B()
{
  {
    init_simple_test("C_BFu9i_B");
    static C_BFu9i_B lv;
    check2(sizeof(lv), 4, "sizeof(C_BFu9i_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu9i_B)");
    check_field_offset(lv, v1, 0, "C_BFu9i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "C_BFu9i_B");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "C_BFu9i_B");
    check_field_offset(lv, v3, 3, "C_BFu9i_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu9i_B(Test_C_BFu9i_B, "C_BFu9i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu9ll_B()
{
  {
    init_simple_test("C_BFu9ll_B");
    static C_BFu9ll_B lv;
    check2(sizeof(lv), 4, "sizeof(C_BFu9ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu9ll_B)");
    check_field_offset(lv, v1, 0, "C_BFu9ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "C_BFu9ll_B");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "C_BFu9ll_B");
    check_field_offset(lv, v3, 3, "C_BFu9ll_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu9ll_B(Test_C_BFu9ll_B, "C_BFu9ll_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_BFu9s_B()
{
  {
    init_simple_test("C_BFu9s_B");
    static C_BFu9s_B lv;
    check2(sizeof(lv), 4, "sizeof(C_BFu9s_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu9s_B)");
    check_field_offset(lv, v1, 0, "C_BFu9s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "C_BFu9s_B");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "C_BFu9s_B");
    check_field_offset(lv, v3, 3, "C_BFu9s_B.v3");
  }
}
static Arrange_To_Call_Me vC_BFu9s_B(Test_C_BFu9s_B, "C_BFu9s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_C_B()
{
  {
    init_simple_test("C_C_B");
    C_C_B lv;
    check2(sizeof(lv), 3, "sizeof(C_C_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_C_B)");
    check_field_offset(lv, v1, 0, "C_C_B.v1");
    check_field_offset(lv, v2, 1, "C_C_B.v2");
    check_field_offset(lv, v3, 2, "C_C_B.v3");
  }
}
static Arrange_To_Call_Me vC_C_B(Test_C_C_B, "C_C_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_D_B()
{
  {
    init_simple_test("C_D_B");
    C_D_B lv;
    check2(sizeof(lv), 10, "sizeof(C_D_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_D_B)");
    check_field_offset(lv, v1, 0, "C_D_B.v1");
    check_field_offset(lv, v2, 1, "C_D_B.v2");
    check_field_offset(lv, v3, 9, "C_D_B.v3");
  }
}
static Arrange_To_Call_Me vC_D_B(Test_C_D_B, "C_D_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_F_B()
{
  {
    init_simple_test("C_F_B");
    C_F_B lv;
    check2(sizeof(lv), 6, "sizeof(C_F_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_F_B)");
    check_field_offset(lv, v1, 0, "C_F_B.v1");
    check_field_offset(lv, v2, 1, "C_F_B.v2");
    check_field_offset(lv, v3, 5, "C_F_B.v3");
  }
}
static Arrange_To_Call_Me vC_F_B(Test_C_F_B, "C_F_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_I_B()
{
  {
    init_simple_test("C_I_B");
    C_I_B lv;
    check2(sizeof(lv), 6, "sizeof(C_I_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_I_B)");
    check_field_offset(lv, v1, 0, "C_I_B.v1");
    check_field_offset(lv, v2, 1, "C_I_B.v2");
    check_field_offset(lv, v3, 5, "C_I_B.v3");
  }
}
static Arrange_To_Call_Me vC_I_B(Test_C_I_B, "C_I_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_Ip_B()
{
  {
    init_simple_test("C_Ip_B");
    C_Ip_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(C_Ip_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_Ip_B)");
    check_field_offset(lv, v1, 0, "C_Ip_B.v1");
    check_field_offset(lv, v2, 1, "C_Ip_B.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "C_Ip_B.v3");
  }
}
static Arrange_To_Call_Me vC_Ip_B(Test_C_Ip_B, "C_Ip_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_L_B()
{
  {
    init_simple_test("C_L_B");
    C_L_B lv;
    check2(sizeof(lv), 10, "sizeof(C_L_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_L_B)");
    check_field_offset(lv, v1, 0, "C_L_B.v1");
    check_field_offset(lv, v2, 1, "C_L_B.v2");
    check_field_offset(lv, v3, 9, "C_L_B.v3");
  }
}
static Arrange_To_Call_Me vC_L_B(Test_C_L_B, "C_L_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_S_B()
{
  {
    init_simple_test("C_S_B");
    C_S_B lv;
    check2(sizeof(lv), 4, "sizeof(C_S_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_S_B)");
    check_field_offset(lv, v1, 0, "C_S_B.v1");
    check_field_offset(lv, v2, 1, "C_S_B.v2");
    check_field_offset(lv, v3, 3, "C_S_B.v3");
  }
}
static Arrange_To_Call_Me vC_S_B(Test_C_S_B, "C_S_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_Uc_B()
{
  {
    init_simple_test("C_Uc_B");
    C_Uc_B lv;
    check2(sizeof(lv), 3, "sizeof(C_Uc_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_Uc_B)");
    check_field_offset(lv, v1, 0, "C_Uc_B.v1");
    check_field_offset(lv, v2, 1, "C_Uc_B.v2");
    check_field_offset(lv, v3, 2, "C_Uc_B.v3");
  }
}
static Arrange_To_Call_Me vC_Uc_B(Test_C_Uc_B, "C_Uc_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_Ui_B()
{
  {
    init_simple_test("C_Ui_B");
    C_Ui_B lv;
    check2(sizeof(lv), 6, "sizeof(C_Ui_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_Ui_B)");
    check_field_offset(lv, v1, 0, "C_Ui_B.v1");
    check_field_offset(lv, v2, 1, "C_Ui_B.v2");
    check_field_offset(lv, v3, 5, "C_Ui_B.v3");
  }
}
static Arrange_To_Call_Me vC_Ui_B(Test_C_Ui_B, "C_Ui_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_Ul_B()
{
  {
    init_simple_test("C_Ul_B");
    C_Ul_B lv;
    check2(sizeof(lv), 10, "sizeof(C_Ul_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_Ul_B)");
    check_field_offset(lv, v1, 0, "C_Ul_B.v1");
    check_field_offset(lv, v2, 1, "C_Ul_B.v2");
    check_field_offset(lv, v3, 9, "C_Ul_B.v3");
  }
}
static Arrange_To_Call_Me vC_Ul_B(Test_C_Ul_B, "C_Ul_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_Us_B()
{
  {
    init_simple_test("C_Us_B");
    C_Us_B lv;
    check2(sizeof(lv), 4, "sizeof(C_Us_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_Us_B)");
    check_field_offset(lv, v1, 0, "C_Us_B.v1");
    check_field_offset(lv, v2, 1, "C_Us_B.v2");
    check_field_offset(lv, v3, 3, "C_Us_B.v3");
  }
}
static Arrange_To_Call_Me vC_Us_B(Test_C_Us_B, "C_Us_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_C_Vp_B()
{
  {
    init_simple_test("C_Vp_B");
    C_Vp_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(C_Vp_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_Vp_B)");
    check_field_offset(lv, v1, 0, "C_Vp_B.v1");
    check_field_offset(lv, v2, 1, "C_Vp_B.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "C_Vp_B.v3");
  }
}
static Arrange_To_Call_Me vC_Vp_B(Test_C_Vp_B, "C_Vp_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B()
{
  {
    init_simple_test("D_B");
    D_B lv;
    check2(sizeof(lv), 9, "sizeof(D_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_B)");
    check_field_offset(lv, v1, 0, "D_B.v1");
    check_field_offset(lv, v2, 8, "D_B.v2");
  }
}
static Arrange_To_Call_Me vD_B(Test_D_B, "D_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_B()
{
  {
    init_simple_test("D_B_B");
    D_B_B lv;
    check2(sizeof(lv), 10, "sizeof(D_B_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_B)");
    check_field_offset(lv, v1, 0, "D_B_B.v1");
    check_field_offset(lv, v2, 8, "D_B_B.v2");
    check_field_offset(lv, v3, 9, "D_B_B.v3");
  }
}
static Arrange_To_Call_Me vD_B_B(Test_D_B_B, "D_B_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu15i()
{
  {
    init_simple_test("D_B_BFu15i");
    static D_B_BFu15i lv;
    check2(sizeof(lv), 11, "sizeof(D_B_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu15i)");
    check_field_offset(lv, v1, 0, "D_B_BFu15i.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu15i.v2");
    set_bf_and_test(lv, v3, 9, 0, 15, 1, "D_B_BFu15i");
    set_bf_and_test(lv, v3, 9, 0, 15, hide_ull(1LL<<14), "D_B_BFu15i");
  }
}
static Arrange_To_Call_Me vD_B_BFu15i(Test_D_B_BFu15i, "D_B_BFu15i", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu15ll()
{
  {
    init_simple_test("D_B_BFu15ll");
    static D_B_BFu15ll lv;
    check2(sizeof(lv), 11, "sizeof(D_B_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu15ll)");
    check_field_offset(lv, v1, 0, "D_B_BFu15ll.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu15ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 15, 1, "D_B_BFu15ll");
    set_bf_and_test(lv, v3, 9, 0, 15, hide_ull(1LL<<14), "D_B_BFu15ll");
  }
}
static Arrange_To_Call_Me vD_B_BFu15ll(Test_D_B_BFu15ll, "D_B_BFu15ll", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu15s()
{
  {
    init_simple_test("D_B_BFu15s");
    static D_B_BFu15s lv;
    check2(sizeof(lv), 11, "sizeof(D_B_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu15s)");
    check_field_offset(lv, v1, 0, "D_B_BFu15s.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu15s.v2");
    set_bf_and_test(lv, v3, 9, 0, 15, 1, "D_B_BFu15s");
    set_bf_and_test(lv, v3, 9, 0, 15, hide_ull(1LL<<14), "D_B_BFu15s");
  }
}
static Arrange_To_Call_Me vD_B_BFu15s(Test_D_B_BFu15s, "D_B_BFu15s", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu16i()
{
  {
    init_simple_test("D_B_BFu16i");
    static D_B_BFu16i lv;
    check2(sizeof(lv), 11, "sizeof(D_B_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu16i)");
    check_field_offset(lv, v1, 0, "D_B_BFu16i.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu16i.v2");
    set_bf_and_test(lv, v3, 9, 0, 16, 1, "D_B_BFu16i");
    set_bf_and_test(lv, v3, 9, 0, 16, hide_ull(1LL<<15), "D_B_BFu16i");
  }
}
static Arrange_To_Call_Me vD_B_BFu16i(Test_D_B_BFu16i, "D_B_BFu16i", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu16ll()
{
  {
    init_simple_test("D_B_BFu16ll");
    static D_B_BFu16ll lv;
    check2(sizeof(lv), 11, "sizeof(D_B_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu16ll)");
    check_field_offset(lv, v1, 0, "D_B_BFu16ll.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu16ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 16, 1, "D_B_BFu16ll");
    set_bf_and_test(lv, v3, 9, 0, 16, hide_ull(1LL<<15), "D_B_BFu16ll");
  }
}
static Arrange_To_Call_Me vD_B_BFu16ll(Test_D_B_BFu16ll, "D_B_BFu16ll", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu16s()
{
  {
    init_simple_test("D_B_BFu16s");
    static D_B_BFu16s lv;
    check2(sizeof(lv), 11, "sizeof(D_B_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu16s)");
    check_field_offset(lv, v1, 0, "D_B_BFu16s.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu16s.v2");
    set_bf_and_test(lv, v3, 9, 0, 16, 1, "D_B_BFu16s");
    set_bf_and_test(lv, v3, 9, 0, 16, hide_ull(1LL<<15), "D_B_BFu16s");
  }
}
static Arrange_To_Call_Me vD_B_BFu16s(Test_D_B_BFu16s, "D_B_BFu16s", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu17i()
{
  {
    init_simple_test("D_B_BFu17i");
    static D_B_BFu17i lv;
    check2(sizeof(lv), 12, "sizeof(D_B_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu17i)");
    check_field_offset(lv, v1, 0, "D_B_BFu17i.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu17i.v2");
    set_bf_and_test(lv, v3, 9, 0, 17, 1, "D_B_BFu17i");
    set_bf_and_test(lv, v3, 9, 0, 17, hide_ull(1LL<<16), "D_B_BFu17i");
  }
}
static Arrange_To_Call_Me vD_B_BFu17i(Test_D_B_BFu17i, "D_B_BFu17i", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu17ll()
{
  {
    init_simple_test("D_B_BFu17ll");
    static D_B_BFu17ll lv;
    check2(sizeof(lv), 12, "sizeof(D_B_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu17ll)");
    check_field_offset(lv, v1, 0, "D_B_BFu17ll.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu17ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 17, 1, "D_B_BFu17ll");
    set_bf_and_test(lv, v3, 9, 0, 17, hide_ull(1LL<<16), "D_B_BFu17ll");
  }
}
static Arrange_To_Call_Me vD_B_BFu17ll(Test_D_B_BFu17ll, "D_B_BFu17ll", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu1c()
{
  {
    init_simple_test("D_B_BFu1c");
    static D_B_BFu1c lv;
    check2(sizeof(lv), 10, "sizeof(D_B_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu1c)");
    check_field_offset(lv, v1, 0, "D_B_BFu1c.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu1c.v2");
    set_bf_and_test(lv, v3, 9, 0, 1, 1, "D_B_BFu1c");
  }
}
static Arrange_To_Call_Me vD_B_BFu1c(Test_D_B_BFu1c, "D_B_BFu1c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu1i()
{
  {
    init_simple_test("D_B_BFu1i");
    static D_B_BFu1i lv;
    check2(sizeof(lv), 10, "sizeof(D_B_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu1i)");
    check_field_offset(lv, v1, 0, "D_B_BFu1i.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu1i.v2");
    set_bf_and_test(lv, v3, 9, 0, 1, 1, "D_B_BFu1i");
  }
}
static Arrange_To_Call_Me vD_B_BFu1i(Test_D_B_BFu1i, "D_B_BFu1i", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu1ll()
{
  {
    init_simple_test("D_B_BFu1ll");
    static D_B_BFu1ll lv;
    check2(sizeof(lv), 10, "sizeof(D_B_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu1ll)");
    check_field_offset(lv, v1, 0, "D_B_BFu1ll.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu1ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 1, 1, "D_B_BFu1ll");
  }
}
static Arrange_To_Call_Me vD_B_BFu1ll(Test_D_B_BFu1ll, "D_B_BFu1ll", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu1s()
{
  {
    init_simple_test("D_B_BFu1s");
    static D_B_BFu1s lv;
    check2(sizeof(lv), 10, "sizeof(D_B_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu1s)");
    check_field_offset(lv, v1, 0, "D_B_BFu1s.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu1s.v2");
    set_bf_and_test(lv, v3, 9, 0, 1, 1, "D_B_BFu1s");
  }
}
static Arrange_To_Call_Me vD_B_BFu1s(Test_D_B_BFu1s, "D_B_BFu1s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu31i()
{
  {
    init_simple_test("D_B_BFu31i");
    static D_B_BFu31i lv;
    check2(sizeof(lv), 13, "sizeof(D_B_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu31i)");
    check_field_offset(lv, v1, 0, "D_B_BFu31i.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu31i.v2");
    set_bf_and_test(lv, v3, 9, 0, 31, 1, "D_B_BFu31i");
    set_bf_and_test(lv, v3, 9, 0, 31, hide_ull(1LL<<30), "D_B_BFu31i");
  }
}
static Arrange_To_Call_Me vD_B_BFu31i(Test_D_B_BFu31i, "D_B_BFu31i", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu31ll()
{
  {
    init_simple_test("D_B_BFu31ll");
    static D_B_BFu31ll lv;
    check2(sizeof(lv), 13, "sizeof(D_B_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu31ll)");
    check_field_offset(lv, v1, 0, "D_B_BFu31ll.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu31ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 31, 1, "D_B_BFu31ll");
    set_bf_and_test(lv, v3, 9, 0, 31, hide_ull(1LL<<30), "D_B_BFu31ll");
  }
}
static Arrange_To_Call_Me vD_B_BFu31ll(Test_D_B_BFu31ll, "D_B_BFu31ll", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu32i()
{
  {
    init_simple_test("D_B_BFu32i");
    static D_B_BFu32i lv;
    check2(sizeof(lv), 13, "sizeof(D_B_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu32i)");
    check_field_offset(lv, v1, 0, "D_B_BFu32i.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu32i.v2");
    set_bf_and_test(lv, v3, 9, 0, 32, 1, "D_B_BFu32i");
    set_bf_and_test(lv, v3, 9, 0, 32, hide_ull(1LL<<31), "D_B_BFu32i");
  }
}
static Arrange_To_Call_Me vD_B_BFu32i(Test_D_B_BFu32i, "D_B_BFu32i", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu32ll()
{
  {
    init_simple_test("D_B_BFu32ll");
    static D_B_BFu32ll lv;
    check2(sizeof(lv), 13, "sizeof(D_B_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu32ll)");
    check_field_offset(lv, v1, 0, "D_B_BFu32ll.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu32ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 32, 1, "D_B_BFu32ll");
    set_bf_and_test(lv, v3, 9, 0, 32, hide_ull(1LL<<31), "D_B_BFu32ll");
  }
}
static Arrange_To_Call_Me vD_B_BFu32ll(Test_D_B_BFu32ll, "D_B_BFu32ll", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu33()
{
  {
    init_simple_test("D_B_BFu33");
    static D_B_BFu33 lv;
    check2(sizeof(lv), 14, "sizeof(D_B_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu33)");
    check_field_offset(lv, v1, 0, "D_B_BFu33.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu33.v2");
    set_bf_and_test(lv, v3, 9, 0, 33, 1, "D_B_BFu33");
    set_bf_and_test(lv, v3, 9, 0, 33, hide_ull(1LL<<32), "D_B_BFu33");
  }
}
static Arrange_To_Call_Me vD_B_BFu33(Test_D_B_BFu33, "D_B_BFu33", 14);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu7c()
{
  {
    init_simple_test("D_B_BFu7c");
    static D_B_BFu7c lv;
    check2(sizeof(lv), 10, "sizeof(D_B_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu7c)");
    check_field_offset(lv, v1, 0, "D_B_BFu7c.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu7c.v2");
    set_bf_and_test(lv, v3, 9, 0, 7, 1, "D_B_BFu7c");
    set_bf_and_test(lv, v3, 9, 0, 7, hide_ull(1LL<<6), "D_B_BFu7c");
  }
}
static Arrange_To_Call_Me vD_B_BFu7c(Test_D_B_BFu7c, "D_B_BFu7c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu7i()
{
  {
    init_simple_test("D_B_BFu7i");
    static D_B_BFu7i lv;
    check2(sizeof(lv), 10, "sizeof(D_B_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu7i)");
    check_field_offset(lv, v1, 0, "D_B_BFu7i.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu7i.v2");
    set_bf_and_test(lv, v3, 9, 0, 7, 1, "D_B_BFu7i");
    set_bf_and_test(lv, v3, 9, 0, 7, hide_ull(1LL<<6), "D_B_BFu7i");
  }
}
static Arrange_To_Call_Me vD_B_BFu7i(Test_D_B_BFu7i, "D_B_BFu7i", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu7ll()
{
  {
    init_simple_test("D_B_BFu7ll");
    static D_B_BFu7ll lv;
    check2(sizeof(lv), 10, "sizeof(D_B_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu7ll)");
    check_field_offset(lv, v1, 0, "D_B_BFu7ll.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu7ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 7, 1, "D_B_BFu7ll");
    set_bf_and_test(lv, v3, 9, 0, 7, hide_ull(1LL<<6), "D_B_BFu7ll");
  }
}
static Arrange_To_Call_Me vD_B_BFu7ll(Test_D_B_BFu7ll, "D_B_BFu7ll", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu7s()
{
  {
    init_simple_test("D_B_BFu7s");
    static D_B_BFu7s lv;
    check2(sizeof(lv), 10, "sizeof(D_B_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu7s)");
    check_field_offset(lv, v1, 0, "D_B_BFu7s.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu7s.v2");
    set_bf_and_test(lv, v3, 9, 0, 7, 1, "D_B_BFu7s");
    set_bf_and_test(lv, v3, 9, 0, 7, hide_ull(1LL<<6), "D_B_BFu7s");
  }
}
static Arrange_To_Call_Me vD_B_BFu7s(Test_D_B_BFu7s, "D_B_BFu7s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu8c()
{
  {
    init_simple_test("D_B_BFu8c");
    static D_B_BFu8c lv;
    check2(sizeof(lv), 10, "sizeof(D_B_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu8c)");
    check_field_offset(lv, v1, 0, "D_B_BFu8c.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu8c.v2");
    set_bf_and_test(lv, v3, 9, 0, 8, 1, "D_B_BFu8c");
    set_bf_and_test(lv, v3, 9, 0, 8, hide_ull(1LL<<7), "D_B_BFu8c");
  }
}
static Arrange_To_Call_Me vD_B_BFu8c(Test_D_B_BFu8c, "D_B_BFu8c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu8i()
{
  {
    init_simple_test("D_B_BFu8i");
    static D_B_BFu8i lv;
    check2(sizeof(lv), 10, "sizeof(D_B_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu8i)");
    check_field_offset(lv, v1, 0, "D_B_BFu8i.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu8i.v2");
    set_bf_and_test(lv, v3, 9, 0, 8, 1, "D_B_BFu8i");
    set_bf_and_test(lv, v3, 9, 0, 8, hide_ull(1LL<<7), "D_B_BFu8i");
  }
}
static Arrange_To_Call_Me vD_B_BFu8i(Test_D_B_BFu8i, "D_B_BFu8i", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu8ll()
{
  {
    init_simple_test("D_B_BFu8ll");
    static D_B_BFu8ll lv;
    check2(sizeof(lv), 10, "sizeof(D_B_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu8ll)");
    check_field_offset(lv, v1, 0, "D_B_BFu8ll.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu8ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 8, 1, "D_B_BFu8ll");
    set_bf_and_test(lv, v3, 9, 0, 8, hide_ull(1LL<<7), "D_B_BFu8ll");
  }
}
static Arrange_To_Call_Me vD_B_BFu8ll(Test_D_B_BFu8ll, "D_B_BFu8ll", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu8s()
{
  {
    init_simple_test("D_B_BFu8s");
    static D_B_BFu8s lv;
    check2(sizeof(lv), 10, "sizeof(D_B_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu8s)");
    check_field_offset(lv, v1, 0, "D_B_BFu8s.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu8s.v2");
    set_bf_and_test(lv, v3, 9, 0, 8, 1, "D_B_BFu8s");
    set_bf_and_test(lv, v3, 9, 0, 8, hide_ull(1LL<<7), "D_B_BFu8s");
  }
}
static Arrange_To_Call_Me vD_B_BFu8s(Test_D_B_BFu8s, "D_B_BFu8s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu9i()
{
  {
    init_simple_test("D_B_BFu9i");
    static D_B_BFu9i lv;
    check2(sizeof(lv), 11, "sizeof(D_B_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu9i)");
    check_field_offset(lv, v1, 0, "D_B_BFu9i.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu9i.v2");
    set_bf_and_test(lv, v3, 9, 0, 9, 1, "D_B_BFu9i");
    set_bf_and_test(lv, v3, 9, 0, 9, hide_ull(1LL<<8), "D_B_BFu9i");
  }
}
static Arrange_To_Call_Me vD_B_BFu9i(Test_D_B_BFu9i, "D_B_BFu9i", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu9ll()
{
  {
    init_simple_test("D_B_BFu9ll");
    static D_B_BFu9ll lv;
    check2(sizeof(lv), 11, "sizeof(D_B_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu9ll)");
    check_field_offset(lv, v1, 0, "D_B_BFu9ll.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu9ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 9, 1, "D_B_BFu9ll");
    set_bf_and_test(lv, v3, 9, 0, 9, hide_ull(1LL<<8), "D_B_BFu9ll");
  }
}
static Arrange_To_Call_Me vD_B_BFu9ll(Test_D_B_BFu9ll, "D_B_BFu9ll", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_BFu9s()
{
  {
    init_simple_test("D_B_BFu9s");
    static D_B_BFu9s lv;
    check2(sizeof(lv), 11, "sizeof(D_B_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_BFu9s)");
    check_field_offset(lv, v1, 0, "D_B_BFu9s.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu9s.v2");
    set_bf_and_test(lv, v3, 9, 0, 9, 1, "D_B_BFu9s");
    set_bf_and_test(lv, v3, 9, 0, 9, hide_ull(1LL<<8), "D_B_BFu9s");
  }
}
static Arrange_To_Call_Me vD_B_BFu9s(Test_D_B_BFu9s, "D_B_BFu9s", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_C()
{
  {
    init_simple_test("D_B_C");
    D_B_C lv;
    check2(sizeof(lv), 10, "sizeof(D_B_C)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_C)");
    check_field_offset(lv, v1, 0, "D_B_C.v1");
    check_field_offset(lv, v2, 8, "D_B_C.v2");
    check_field_offset(lv, v3, 9, "D_B_C.v3");
  }
}
static Arrange_To_Call_Me vD_B_C(Test_D_B_C, "D_B_C", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_D()
{
  {
    init_simple_test("D_B_D");
    D_B_D lv;
    check2(sizeof(lv), 17, "sizeof(D_B_D)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_D)");
    check_field_offset(lv, v1, 0, "D_B_D.v1");
    check_field_offset(lv, v2, 8, "D_B_D.v2");
    check_field_offset(lv, v3, 9, "D_B_D.v3");
  }
}
static Arrange_To_Call_Me vD_B_D(Test_D_B_D, "D_B_D", 17);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_F()
{
  {
    init_simple_test("D_B_F");
    D_B_F lv;
    check2(sizeof(lv), 13, "sizeof(D_B_F)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_F)");
    check_field_offset(lv, v1, 0, "D_B_F.v1");
    check_field_offset(lv, v2, 8, "D_B_F.v2");
    check_field_offset(lv, v3, 9, "D_B_F.v3");
  }
}
static Arrange_To_Call_Me vD_B_F(Test_D_B_F, "D_B_F", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_I()
{
  {
    init_simple_test("D_B_I");
    D_B_I lv;
    check2(sizeof(lv), 13, "sizeof(D_B_I)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_I)");
    check_field_offset(lv, v1, 0, "D_B_I.v1");
    check_field_offset(lv, v2, 8, "D_B_I.v2");
    check_field_offset(lv, v3, 9, "D_B_I.v3");
  }
}
static Arrange_To_Call_Me vD_B_I(Test_D_B_I, "D_B_I", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_Ip()
{
  {
    init_simple_test("D_B_Ip");
    D_B_Ip lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(D_B_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_Ip)");
    check_field_offset(lv, v1, 0, "D_B_Ip.v1");
    check_field_offset(lv, v2, 8, "D_B_Ip.v2");
    check_field_offset(lv, v3, 9, "D_B_Ip.v3");
  }
}
static Arrange_To_Call_Me vD_B_Ip(Test_D_B_Ip, "D_B_Ip", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_L()
{
  {
    init_simple_test("D_B_L");
    D_B_L lv;
    check2(sizeof(lv), 17, "sizeof(D_B_L)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_L)");
    check_field_offset(lv, v1, 0, "D_B_L.v1");
    check_field_offset(lv, v2, 8, "D_B_L.v2");
    check_field_offset(lv, v3, 9, "D_B_L.v3");
  }
}
static Arrange_To_Call_Me vD_B_L(Test_D_B_L, "D_B_L", 17);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_S()
{
  {
    init_simple_test("D_B_S");
    D_B_S lv;
    check2(sizeof(lv), 11, "sizeof(D_B_S)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_S)");
    check_field_offset(lv, v1, 0, "D_B_S.v1");
    check_field_offset(lv, v2, 8, "D_B_S.v2");
    check_field_offset(lv, v3, 9, "D_B_S.v3");
  }
}
static Arrange_To_Call_Me vD_B_S(Test_D_B_S, "D_B_S", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_Uc()
{
  {
    init_simple_test("D_B_Uc");
    D_B_Uc lv;
    check2(sizeof(lv), 10, "sizeof(D_B_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_Uc)");
    check_field_offset(lv, v1, 0, "D_B_Uc.v1");
    check_field_offset(lv, v2, 8, "D_B_Uc.v2");
    check_field_offset(lv, v3, 9, "D_B_Uc.v3");
  }
}
static Arrange_To_Call_Me vD_B_Uc(Test_D_B_Uc, "D_B_Uc", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_Ui()
{
  {
    init_simple_test("D_B_Ui");
    D_B_Ui lv;
    check2(sizeof(lv), 13, "sizeof(D_B_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_Ui)");
    check_field_offset(lv, v1, 0, "D_B_Ui.v1");
    check_field_offset(lv, v2, 8, "D_B_Ui.v2");
    check_field_offset(lv, v3, 9, "D_B_Ui.v3");
  }
}
static Arrange_To_Call_Me vD_B_Ui(Test_D_B_Ui, "D_B_Ui", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_Ul()
{
  {
    init_simple_test("D_B_Ul");
    D_B_Ul lv;
    check2(sizeof(lv), 17, "sizeof(D_B_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_Ul)");
    check_field_offset(lv, v1, 0, "D_B_Ul.v1");
    check_field_offset(lv, v2, 8, "D_B_Ul.v2");
    check_field_offset(lv, v3, 9, "D_B_Ul.v3");
  }
}
static Arrange_To_Call_Me vD_B_Ul(Test_D_B_Ul, "D_B_Ul", 17);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_Us()
{
  {
    init_simple_test("D_B_Us");
    D_B_Us lv;
    check2(sizeof(lv), 11, "sizeof(D_B_Us)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_Us)");
    check_field_offset(lv, v1, 0, "D_B_Us.v1");
    check_field_offset(lv, v2, 8, "D_B_Us.v2");
    check_field_offset(lv, v3, 9, "D_B_Us.v3");
  }
}
static Arrange_To_Call_Me vD_B_Us(Test_D_B_Us, "D_B_Us", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_B_Vp()
{
  {
    init_simple_test("D_B_Vp");
    D_B_Vp lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(D_B_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(D_B_Vp)");
    check_field_offset(lv, v1, 0, "D_B_Vp.v1");
    check_field_offset(lv, v2, 8, "D_B_Vp.v2");
    check_field_offset(lv, v3, 9, "D_B_Vp.v3");
  }
}
static Arrange_To_Call_Me vD_B_Vp(Test_D_B_Vp, "D_B_Vp", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu15i_B()
{
  {
    init_simple_test("D_BFu15i_B");
    static D_BFu15i_B lv;
    check2(sizeof(lv), 11, "sizeof(D_BFu15i_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu15i_B)");
    check_field_offset(lv, v1, 0, "D_BFu15i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "D_BFu15i_B");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "D_BFu15i_B");
    check_field_offset(lv, v3, 10, "D_BFu15i_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu15i_B(Test_D_BFu15i_B, "D_BFu15i_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu15ll_B()
{
  {
    init_simple_test("D_BFu15ll_B");
    static D_BFu15ll_B lv;
    check2(sizeof(lv), 11, "sizeof(D_BFu15ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu15ll_B)");
    check_field_offset(lv, v1, 0, "D_BFu15ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "D_BFu15ll_B");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "D_BFu15ll_B");
    check_field_offset(lv, v3, 10, "D_BFu15ll_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu15ll_B(Test_D_BFu15ll_B, "D_BFu15ll_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu15s_B()
{
  {
    init_simple_test("D_BFu15s_B");
    static D_BFu15s_B lv;
    check2(sizeof(lv), 11, "sizeof(D_BFu15s_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu15s_B)");
    check_field_offset(lv, v1, 0, "D_BFu15s_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "D_BFu15s_B");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "D_BFu15s_B");
    check_field_offset(lv, v3, 10, "D_BFu15s_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu15s_B(Test_D_BFu15s_B, "D_BFu15s_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu16i_B()
{
  {
    init_simple_test("D_BFu16i_B");
    static D_BFu16i_B lv;
    check2(sizeof(lv), 11, "sizeof(D_BFu16i_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu16i_B)");
    check_field_offset(lv, v1, 0, "D_BFu16i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "D_BFu16i_B");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "D_BFu16i_B");
    check_field_offset(lv, v3, 10, "D_BFu16i_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu16i_B(Test_D_BFu16i_B, "D_BFu16i_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu16ll_B()
{
  {
    init_simple_test("D_BFu16ll_B");
    static D_BFu16ll_B lv;
    check2(sizeof(lv), 11, "sizeof(D_BFu16ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu16ll_B)");
    check_field_offset(lv, v1, 0, "D_BFu16ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "D_BFu16ll_B");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "D_BFu16ll_B");
    check_field_offset(lv, v3, 10, "D_BFu16ll_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu16ll_B(Test_D_BFu16ll_B, "D_BFu16ll_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu16s_B()
{
  {
    init_simple_test("D_BFu16s_B");
    static D_BFu16s_B lv;
    check2(sizeof(lv), 11, "sizeof(D_BFu16s_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu16s_B)");
    check_field_offset(lv, v1, 0, "D_BFu16s_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "D_BFu16s_B");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "D_BFu16s_B");
    check_field_offset(lv, v3, 10, "D_BFu16s_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu16s_B(Test_D_BFu16s_B, "D_BFu16s_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu17i_B()
{
  {
    init_simple_test("D_BFu17i_B");
    static D_BFu17i_B lv;
    check2(sizeof(lv), 12, "sizeof(D_BFu17i_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu17i_B)");
    check_field_offset(lv, v1, 0, "D_BFu17i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "D_BFu17i_B");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "D_BFu17i_B");
    check_field_offset(lv, v3, 11, "D_BFu17i_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu17i_B(Test_D_BFu17i_B, "D_BFu17i_B", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu17ll_B()
{
  {
    init_simple_test("D_BFu17ll_B");
    static D_BFu17ll_B lv;
    check2(sizeof(lv), 12, "sizeof(D_BFu17ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu17ll_B)");
    check_field_offset(lv, v1, 0, "D_BFu17ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "D_BFu17ll_B");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "D_BFu17ll_B");
    check_field_offset(lv, v3, 11, "D_BFu17ll_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu17ll_B(Test_D_BFu17ll_B, "D_BFu17ll_B", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu1c_B()
{
  {
    init_simple_test("D_BFu1c_B");
    static D_BFu1c_B lv;
    check2(sizeof(lv), 10, "sizeof(D_BFu1c_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu1c_B)");
    check_field_offset(lv, v1, 0, "D_BFu1c_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "D_BFu1c_B");
    check_field_offset(lv, v3, 9, "D_BFu1c_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu1c_B(Test_D_BFu1c_B, "D_BFu1c_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu1i_B()
{
  {
    init_simple_test("D_BFu1i_B");
    static D_BFu1i_B lv;
    check2(sizeof(lv), 10, "sizeof(D_BFu1i_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu1i_B)");
    check_field_offset(lv, v1, 0, "D_BFu1i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "D_BFu1i_B");
    check_field_offset(lv, v3, 9, "D_BFu1i_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu1i_B(Test_D_BFu1i_B, "D_BFu1i_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu1ll_B()
{
  {
    init_simple_test("D_BFu1ll_B");
    static D_BFu1ll_B lv;
    check2(sizeof(lv), 10, "sizeof(D_BFu1ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu1ll_B)");
    check_field_offset(lv, v1, 0, "D_BFu1ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "D_BFu1ll_B");
    check_field_offset(lv, v3, 9, "D_BFu1ll_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu1ll_B(Test_D_BFu1ll_B, "D_BFu1ll_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu1s_B()
{
  {
    init_simple_test("D_BFu1s_B");
    static D_BFu1s_B lv;
    check2(sizeof(lv), 10, "sizeof(D_BFu1s_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu1s_B)");
    check_field_offset(lv, v1, 0, "D_BFu1s_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "D_BFu1s_B");
    check_field_offset(lv, v3, 9, "D_BFu1s_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu1s_B(Test_D_BFu1s_B, "D_BFu1s_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu31i_B()
{
  {
    init_simple_test("D_BFu31i_B");
    static D_BFu31i_B lv;
    check2(sizeof(lv), 13, "sizeof(D_BFu31i_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu31i_B)");
    check_field_offset(lv, v1, 0, "D_BFu31i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "D_BFu31i_B");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "D_BFu31i_B");
    check_field_offset(lv, v3, 12, "D_BFu31i_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu31i_B(Test_D_BFu31i_B, "D_BFu31i_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu31ll_B()
{
  {
    init_simple_test("D_BFu31ll_B");
    static D_BFu31ll_B lv;
    check2(sizeof(lv), 13, "sizeof(D_BFu31ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu31ll_B)");
    check_field_offset(lv, v1, 0, "D_BFu31ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "D_BFu31ll_B");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "D_BFu31ll_B");
    check_field_offset(lv, v3, 12, "D_BFu31ll_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu31ll_B(Test_D_BFu31ll_B, "D_BFu31ll_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu32i_B()
{
  {
    init_simple_test("D_BFu32i_B");
    static D_BFu32i_B lv;
    check2(sizeof(lv), 13, "sizeof(D_BFu32i_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu32i_B)");
    check_field_offset(lv, v1, 0, "D_BFu32i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "D_BFu32i_B");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "D_BFu32i_B");
    check_field_offset(lv, v3, 12, "D_BFu32i_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu32i_B(Test_D_BFu32i_B, "D_BFu32i_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu32ll_B()
{
  {
    init_simple_test("D_BFu32ll_B");
    static D_BFu32ll_B lv;
    check2(sizeof(lv), 13, "sizeof(D_BFu32ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu32ll_B)");
    check_field_offset(lv, v1, 0, "D_BFu32ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "D_BFu32ll_B");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "D_BFu32ll_B");
    check_field_offset(lv, v3, 12, "D_BFu32ll_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu32ll_B(Test_D_BFu32ll_B, "D_BFu32ll_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu33_B()
{
  {
    init_simple_test("D_BFu33_B");
    static D_BFu33_B lv;
    check2(sizeof(lv), 14, "sizeof(D_BFu33_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu33_B)");
    check_field_offset(lv, v1, 0, "D_BFu33_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 33, 1, "D_BFu33_B");
    set_bf_and_test(lv, v2, 8, 0, 33, hide_ull(1LL<<32), "D_BFu33_B");
    check_field_offset(lv, v3, 13, "D_BFu33_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu33_B(Test_D_BFu33_B, "D_BFu33_B", 14);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu7c_B()
{
  {
    init_simple_test("D_BFu7c_B");
    static D_BFu7c_B lv;
    check2(sizeof(lv), 10, "sizeof(D_BFu7c_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu7c_B)");
    check_field_offset(lv, v1, 0, "D_BFu7c_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "D_BFu7c_B");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "D_BFu7c_B");
    check_field_offset(lv, v3, 9, "D_BFu7c_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu7c_B(Test_D_BFu7c_B, "D_BFu7c_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu7i_B()
{
  {
    init_simple_test("D_BFu7i_B");
    static D_BFu7i_B lv;
    check2(sizeof(lv), 10, "sizeof(D_BFu7i_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu7i_B)");
    check_field_offset(lv, v1, 0, "D_BFu7i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "D_BFu7i_B");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "D_BFu7i_B");
    check_field_offset(lv, v3, 9, "D_BFu7i_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu7i_B(Test_D_BFu7i_B, "D_BFu7i_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu7ll_B()
{
  {
    init_simple_test("D_BFu7ll_B");
    static D_BFu7ll_B lv;
    check2(sizeof(lv), 10, "sizeof(D_BFu7ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu7ll_B)");
    check_field_offset(lv, v1, 0, "D_BFu7ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "D_BFu7ll_B");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "D_BFu7ll_B");
    check_field_offset(lv, v3, 9, "D_BFu7ll_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu7ll_B(Test_D_BFu7ll_B, "D_BFu7ll_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu7s_B()
{
  {
    init_simple_test("D_BFu7s_B");
    static D_BFu7s_B lv;
    check2(sizeof(lv), 10, "sizeof(D_BFu7s_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu7s_B)");
    check_field_offset(lv, v1, 0, "D_BFu7s_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "D_BFu7s_B");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "D_BFu7s_B");
    check_field_offset(lv, v3, 9, "D_BFu7s_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu7s_B(Test_D_BFu7s_B, "D_BFu7s_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu8c_B()
{
  {
    init_simple_test("D_BFu8c_B");
    static D_BFu8c_B lv;
    check2(sizeof(lv), 10, "sizeof(D_BFu8c_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu8c_B)");
    check_field_offset(lv, v1, 0, "D_BFu8c_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "D_BFu8c_B");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "D_BFu8c_B");
    check_field_offset(lv, v3, 9, "D_BFu8c_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu8c_B(Test_D_BFu8c_B, "D_BFu8c_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu8i_B()
{
  {
    init_simple_test("D_BFu8i_B");
    static D_BFu8i_B lv;
    check2(sizeof(lv), 10, "sizeof(D_BFu8i_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu8i_B)");
    check_field_offset(lv, v1, 0, "D_BFu8i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "D_BFu8i_B");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "D_BFu8i_B");
    check_field_offset(lv, v3, 9, "D_BFu8i_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu8i_B(Test_D_BFu8i_B, "D_BFu8i_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu8ll_B()
{
  {
    init_simple_test("D_BFu8ll_B");
    static D_BFu8ll_B lv;
    check2(sizeof(lv), 10, "sizeof(D_BFu8ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu8ll_B)");
    check_field_offset(lv, v1, 0, "D_BFu8ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "D_BFu8ll_B");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "D_BFu8ll_B");
    check_field_offset(lv, v3, 9, "D_BFu8ll_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu8ll_B(Test_D_BFu8ll_B, "D_BFu8ll_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu8s_B()
{
  {
    init_simple_test("D_BFu8s_B");
    static D_BFu8s_B lv;
    check2(sizeof(lv), 10, "sizeof(D_BFu8s_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu8s_B)");
    check_field_offset(lv, v1, 0, "D_BFu8s_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "D_BFu8s_B");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "D_BFu8s_B");
    check_field_offset(lv, v3, 9, "D_BFu8s_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu8s_B(Test_D_BFu8s_B, "D_BFu8s_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu9i_B()
{
  {
    init_simple_test("D_BFu9i_B");
    static D_BFu9i_B lv;
    check2(sizeof(lv), 11, "sizeof(D_BFu9i_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu9i_B)");
    check_field_offset(lv, v1, 0, "D_BFu9i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "D_BFu9i_B");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "D_BFu9i_B");
    check_field_offset(lv, v3, 10, "D_BFu9i_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu9i_B(Test_D_BFu9i_B, "D_BFu9i_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu9ll_B()
{
  {
    init_simple_test("D_BFu9ll_B");
    static D_BFu9ll_B lv;
    check2(sizeof(lv), 11, "sizeof(D_BFu9ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu9ll_B)");
    check_field_offset(lv, v1, 0, "D_BFu9ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "D_BFu9ll_B");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "D_BFu9ll_B");
    check_field_offset(lv, v3, 10, "D_BFu9ll_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu9ll_B(Test_D_BFu9ll_B, "D_BFu9ll_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_BFu9s_B()
{
  {
    init_simple_test("D_BFu9s_B");
    static D_BFu9s_B lv;
    check2(sizeof(lv), 11, "sizeof(D_BFu9s_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_BFu9s_B)");
    check_field_offset(lv, v1, 0, "D_BFu9s_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "D_BFu9s_B");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "D_BFu9s_B");
    check_field_offset(lv, v3, 10, "D_BFu9s_B.v3");
  }
}
static Arrange_To_Call_Me vD_BFu9s_B(Test_D_BFu9s_B, "D_BFu9s_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_C_B()
{
  {
    init_simple_test("D_C_B");
    D_C_B lv;
    check2(sizeof(lv), 10, "sizeof(D_C_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_C_B)");
    check_field_offset(lv, v1, 0, "D_C_B.v1");
    check_field_offset(lv, v2, 8, "D_C_B.v2");
    check_field_offset(lv, v3, 9, "D_C_B.v3");
  }
}
static Arrange_To_Call_Me vD_C_B(Test_D_C_B, "D_C_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_D_B()
{
  {
    init_simple_test("D_D_B");
    D_D_B lv;
    check2(sizeof(lv), 17, "sizeof(D_D_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_D_B)");
    check_field_offset(lv, v1, 0, "D_D_B.v1");
    check_field_offset(lv, v2, 8, "D_D_B.v2");
    check_field_offset(lv, v3, 16, "D_D_B.v3");
  }
}
static Arrange_To_Call_Me vD_D_B(Test_D_D_B, "D_D_B", 17);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_F_B()
{
  {
    init_simple_test("D_F_B");
    D_F_B lv;
    check2(sizeof(lv), 13, "sizeof(D_F_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_F_B)");
    check_field_offset(lv, v1, 0, "D_F_B.v1");
    check_field_offset(lv, v2, 8, "D_F_B.v2");
    check_field_offset(lv, v3, 12, "D_F_B.v3");
  }
}
static Arrange_To_Call_Me vD_F_B(Test_D_F_B, "D_F_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_I_B()
{
  {
    init_simple_test("D_I_B");
    D_I_B lv;
    check2(sizeof(lv), 13, "sizeof(D_I_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_I_B)");
    check_field_offset(lv, v1, 0, "D_I_B.v1");
    check_field_offset(lv, v2, 8, "D_I_B.v2");
    check_field_offset(lv, v3, 12, "D_I_B.v3");
  }
}
static Arrange_To_Call_Me vD_I_B(Test_D_I_B, "D_I_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_Ip_B()
{
  {
    init_simple_test("D_Ip_B");
    D_Ip_B lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(D_Ip_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_Ip_B)");
    check_field_offset(lv, v1, 0, "D_Ip_B.v1");
    check_field_offset(lv, v2, 8, "D_Ip_B.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "D_Ip_B.v3");
  }
}
static Arrange_To_Call_Me vD_Ip_B(Test_D_Ip_B, "D_Ip_B", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_L_B()
{
  {
    init_simple_test("D_L_B");
    D_L_B lv;
    check2(sizeof(lv), 17, "sizeof(D_L_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_L_B)");
    check_field_offset(lv, v1, 0, "D_L_B.v1");
    check_field_offset(lv, v2, 8, "D_L_B.v2");
    check_field_offset(lv, v3, 16, "D_L_B.v3");
  }
}
static Arrange_To_Call_Me vD_L_B(Test_D_L_B, "D_L_B", 17);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_S_B()
{
  {
    init_simple_test("D_S_B");
    D_S_B lv;
    check2(sizeof(lv), 11, "sizeof(D_S_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_S_B)");
    check_field_offset(lv, v1, 0, "D_S_B.v1");
    check_field_offset(lv, v2, 8, "D_S_B.v2");
    check_field_offset(lv, v3, 10, "D_S_B.v3");
  }
}
static Arrange_To_Call_Me vD_S_B(Test_D_S_B, "D_S_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_Uc_B()
{
  {
    init_simple_test("D_Uc_B");
    D_Uc_B lv;
    check2(sizeof(lv), 10, "sizeof(D_Uc_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_Uc_B)");
    check_field_offset(lv, v1, 0, "D_Uc_B.v1");
    check_field_offset(lv, v2, 8, "D_Uc_B.v2");
    check_field_offset(lv, v3, 9, "D_Uc_B.v3");
  }
}
static Arrange_To_Call_Me vD_Uc_B(Test_D_Uc_B, "D_Uc_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_Ui_B()
{
  {
    init_simple_test("D_Ui_B");
    D_Ui_B lv;
    check2(sizeof(lv), 13, "sizeof(D_Ui_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_Ui_B)");
    check_field_offset(lv, v1, 0, "D_Ui_B.v1");
    check_field_offset(lv, v2, 8, "D_Ui_B.v2");
    check_field_offset(lv, v3, 12, "D_Ui_B.v3");
  }
}
static Arrange_To_Call_Me vD_Ui_B(Test_D_Ui_B, "D_Ui_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_Ul_B()
{
  {
    init_simple_test("D_Ul_B");
    D_Ul_B lv;
    check2(sizeof(lv), 17, "sizeof(D_Ul_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_Ul_B)");
    check_field_offset(lv, v1, 0, "D_Ul_B.v1");
    check_field_offset(lv, v2, 8, "D_Ul_B.v2");
    check_field_offset(lv, v3, 16, "D_Ul_B.v3");
  }
}
static Arrange_To_Call_Me vD_Ul_B(Test_D_Ul_B, "D_Ul_B", 17);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_Us_B()
{
  {
    init_simple_test("D_Us_B");
    D_Us_B lv;
    check2(sizeof(lv), 11, "sizeof(D_Us_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_Us_B)");
    check_field_offset(lv, v1, 0, "D_Us_B.v1");
    check_field_offset(lv, v2, 8, "D_Us_B.v2");
    check_field_offset(lv, v3, 10, "D_Us_B.v3");
  }
}
static Arrange_To_Call_Me vD_Us_B(Test_D_Us_B, "D_Us_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_D_Vp_B()
{
  {
    init_simple_test("D_Vp_B");
    D_Vp_B lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(D_Vp_B)");
    check2(__alignof__(lv), 1, "__alignof__(D_Vp_B)");
    check_field_offset(lv, v1, 0, "D_Vp_B.v1");
    check_field_offset(lv, v2, 8, "D_Vp_B.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "D_Vp_B.v3");
  }
}
static Arrange_To_Call_Me vD_Vp_B(Test_D_Vp_B, "D_Vp_B", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B()
{
  {
    init_simple_test("F_B");
    F_B lv;
    check2(sizeof(lv), 5, "sizeof(F_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_B)");
    check_field_offset(lv, v1, 0, "F_B.v1");
    check_field_offset(lv, v2, 4, "F_B.v2");
  }
}
static Arrange_To_Call_Me vF_B(Test_F_B, "F_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_B()
{
  {
    init_simple_test("F_B_B");
    F_B_B lv;
    check2(sizeof(lv), 6, "sizeof(F_B_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_B)");
    check_field_offset(lv, v1, 0, "F_B_B.v1");
    check_field_offset(lv, v2, 4, "F_B_B.v2");
    check_field_offset(lv, v3, 5, "F_B_B.v3");
  }
}
static Arrange_To_Call_Me vF_B_B(Test_F_B_B, "F_B_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu15i()
{
  {
    init_simple_test("F_B_BFu15i");
    static F_B_BFu15i lv;
    check2(sizeof(lv), 7, "sizeof(F_B_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu15i)");
    check_field_offset(lv, v1, 0, "F_B_BFu15i.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu15i.v2");
    set_bf_and_test(lv, v3, 5, 0, 15, 1, "F_B_BFu15i");
    set_bf_and_test(lv, v3, 5, 0, 15, hide_ull(1LL<<14), "F_B_BFu15i");
  }
}
static Arrange_To_Call_Me vF_B_BFu15i(Test_F_B_BFu15i, "F_B_BFu15i", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu15ll()
{
  {
    init_simple_test("F_B_BFu15ll");
    static F_B_BFu15ll lv;
    check2(sizeof(lv), 7, "sizeof(F_B_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu15ll)");
    check_field_offset(lv, v1, 0, "F_B_BFu15ll.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu15ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 15, 1, "F_B_BFu15ll");
    set_bf_and_test(lv, v3, 5, 0, 15, hide_ull(1LL<<14), "F_B_BFu15ll");
  }
}
static Arrange_To_Call_Me vF_B_BFu15ll(Test_F_B_BFu15ll, "F_B_BFu15ll", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu15s()
{
  {
    init_simple_test("F_B_BFu15s");
    static F_B_BFu15s lv;
    check2(sizeof(lv), 7, "sizeof(F_B_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu15s)");
    check_field_offset(lv, v1, 0, "F_B_BFu15s.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu15s.v2");
    set_bf_and_test(lv, v3, 5, 0, 15, 1, "F_B_BFu15s");
    set_bf_and_test(lv, v3, 5, 0, 15, hide_ull(1LL<<14), "F_B_BFu15s");
  }
}
static Arrange_To_Call_Me vF_B_BFu15s(Test_F_B_BFu15s, "F_B_BFu15s", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu16i()
{
  {
    init_simple_test("F_B_BFu16i");
    static F_B_BFu16i lv;
    check2(sizeof(lv), 7, "sizeof(F_B_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu16i)");
    check_field_offset(lv, v1, 0, "F_B_BFu16i.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu16i.v2");
    set_bf_and_test(lv, v3, 5, 0, 16, 1, "F_B_BFu16i");
    set_bf_and_test(lv, v3, 5, 0, 16, hide_ull(1LL<<15), "F_B_BFu16i");
  }
}
static Arrange_To_Call_Me vF_B_BFu16i(Test_F_B_BFu16i, "F_B_BFu16i", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu16ll()
{
  {
    init_simple_test("F_B_BFu16ll");
    static F_B_BFu16ll lv;
    check2(sizeof(lv), 7, "sizeof(F_B_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu16ll)");
    check_field_offset(lv, v1, 0, "F_B_BFu16ll.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu16ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 16, 1, "F_B_BFu16ll");
    set_bf_and_test(lv, v3, 5, 0, 16, hide_ull(1LL<<15), "F_B_BFu16ll");
  }
}
static Arrange_To_Call_Me vF_B_BFu16ll(Test_F_B_BFu16ll, "F_B_BFu16ll", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu16s()
{
  {
    init_simple_test("F_B_BFu16s");
    static F_B_BFu16s lv;
    check2(sizeof(lv), 7, "sizeof(F_B_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu16s)");
    check_field_offset(lv, v1, 0, "F_B_BFu16s.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu16s.v2");
    set_bf_and_test(lv, v3, 5, 0, 16, 1, "F_B_BFu16s");
    set_bf_and_test(lv, v3, 5, 0, 16, hide_ull(1LL<<15), "F_B_BFu16s");
  }
}
static Arrange_To_Call_Me vF_B_BFu16s(Test_F_B_BFu16s, "F_B_BFu16s", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu17i()
{
  {
    init_simple_test("F_B_BFu17i");
    static F_B_BFu17i lv;
    check2(sizeof(lv), 8, "sizeof(F_B_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu17i)");
    check_field_offset(lv, v1, 0, "F_B_BFu17i.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu17i.v2");
    set_bf_and_test(lv, v3, 5, 0, 17, 1, "F_B_BFu17i");
    set_bf_and_test(lv, v3, 5, 0, 17, hide_ull(1LL<<16), "F_B_BFu17i");
  }
}
static Arrange_To_Call_Me vF_B_BFu17i(Test_F_B_BFu17i, "F_B_BFu17i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu17ll()
{
  {
    init_simple_test("F_B_BFu17ll");
    static F_B_BFu17ll lv;
    check2(sizeof(lv), 8, "sizeof(F_B_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu17ll)");
    check_field_offset(lv, v1, 0, "F_B_BFu17ll.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu17ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 17, 1, "F_B_BFu17ll");
    set_bf_and_test(lv, v3, 5, 0, 17, hide_ull(1LL<<16), "F_B_BFu17ll");
  }
}
static Arrange_To_Call_Me vF_B_BFu17ll(Test_F_B_BFu17ll, "F_B_BFu17ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu1c()
{
  {
    init_simple_test("F_B_BFu1c");
    static F_B_BFu1c lv;
    check2(sizeof(lv), 6, "sizeof(F_B_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu1c)");
    check_field_offset(lv, v1, 0, "F_B_BFu1c.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu1c.v2");
    set_bf_and_test(lv, v3, 5, 0, 1, 1, "F_B_BFu1c");
  }
}
static Arrange_To_Call_Me vF_B_BFu1c(Test_F_B_BFu1c, "F_B_BFu1c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu1i()
{
  {
    init_simple_test("F_B_BFu1i");
    static F_B_BFu1i lv;
    check2(sizeof(lv), 6, "sizeof(F_B_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu1i)");
    check_field_offset(lv, v1, 0, "F_B_BFu1i.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu1i.v2");
    set_bf_and_test(lv, v3, 5, 0, 1, 1, "F_B_BFu1i");
  }
}
static Arrange_To_Call_Me vF_B_BFu1i(Test_F_B_BFu1i, "F_B_BFu1i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu1ll()
{
  {
    init_simple_test("F_B_BFu1ll");
    static F_B_BFu1ll lv;
    check2(sizeof(lv), 6, "sizeof(F_B_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu1ll)");
    check_field_offset(lv, v1, 0, "F_B_BFu1ll.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu1ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 1, 1, "F_B_BFu1ll");
  }
}
static Arrange_To_Call_Me vF_B_BFu1ll(Test_F_B_BFu1ll, "F_B_BFu1ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu1s()
{
  {
    init_simple_test("F_B_BFu1s");
    static F_B_BFu1s lv;
    check2(sizeof(lv), 6, "sizeof(F_B_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu1s)");
    check_field_offset(lv, v1, 0, "F_B_BFu1s.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu1s.v2");
    set_bf_and_test(lv, v3, 5, 0, 1, 1, "F_B_BFu1s");
  }
}
static Arrange_To_Call_Me vF_B_BFu1s(Test_F_B_BFu1s, "F_B_BFu1s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu31i()
{
  {
    init_simple_test("F_B_BFu31i");
    static F_B_BFu31i lv;
    check2(sizeof(lv), 9, "sizeof(F_B_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu31i)");
    check_field_offset(lv, v1, 0, "F_B_BFu31i.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu31i.v2");
    set_bf_and_test(lv, v3, 5, 0, 31, 1, "F_B_BFu31i");
    set_bf_and_test(lv, v3, 5, 0, 31, hide_ull(1LL<<30), "F_B_BFu31i");
  }
}
static Arrange_To_Call_Me vF_B_BFu31i(Test_F_B_BFu31i, "F_B_BFu31i", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu31ll()
{
  {
    init_simple_test("F_B_BFu31ll");
    static F_B_BFu31ll lv;
    check2(sizeof(lv), 9, "sizeof(F_B_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu31ll)");
    check_field_offset(lv, v1, 0, "F_B_BFu31ll.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu31ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 31, 1, "F_B_BFu31ll");
    set_bf_and_test(lv, v3, 5, 0, 31, hide_ull(1LL<<30), "F_B_BFu31ll");
  }
}
static Arrange_To_Call_Me vF_B_BFu31ll(Test_F_B_BFu31ll, "F_B_BFu31ll", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu32i()
{
  {
    init_simple_test("F_B_BFu32i");
    static F_B_BFu32i lv;
    check2(sizeof(lv), 9, "sizeof(F_B_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu32i)");
    check_field_offset(lv, v1, 0, "F_B_BFu32i.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu32i.v2");
    set_bf_and_test(lv, v3, 5, 0, 32, 1, "F_B_BFu32i");
    set_bf_and_test(lv, v3, 5, 0, 32, hide_ull(1LL<<31), "F_B_BFu32i");
  }
}
static Arrange_To_Call_Me vF_B_BFu32i(Test_F_B_BFu32i, "F_B_BFu32i", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu32ll()
{
  {
    init_simple_test("F_B_BFu32ll");
    static F_B_BFu32ll lv;
    check2(sizeof(lv), 9, "sizeof(F_B_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu32ll)");
    check_field_offset(lv, v1, 0, "F_B_BFu32ll.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu32ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 32, 1, "F_B_BFu32ll");
    set_bf_and_test(lv, v3, 5, 0, 32, hide_ull(1LL<<31), "F_B_BFu32ll");
  }
}
static Arrange_To_Call_Me vF_B_BFu32ll(Test_F_B_BFu32ll, "F_B_BFu32ll", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu33()
{
  {
    init_simple_test("F_B_BFu33");
    static F_B_BFu33 lv;
    check2(sizeof(lv), 10, "sizeof(F_B_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu33)");
    check_field_offset(lv, v1, 0, "F_B_BFu33.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu33.v2");
    set_bf_and_test(lv, v3, 5, 0, 33, 1, "F_B_BFu33");
    set_bf_and_test(lv, v3, 5, 0, 33, hide_ull(1LL<<32), "F_B_BFu33");
  }
}
static Arrange_To_Call_Me vF_B_BFu33(Test_F_B_BFu33, "F_B_BFu33", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu7c()
{
  {
    init_simple_test("F_B_BFu7c");
    static F_B_BFu7c lv;
    check2(sizeof(lv), 6, "sizeof(F_B_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu7c)");
    check_field_offset(lv, v1, 0, "F_B_BFu7c.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu7c.v2");
    set_bf_and_test(lv, v3, 5, 0, 7, 1, "F_B_BFu7c");
    set_bf_and_test(lv, v3, 5, 0, 7, hide_ull(1LL<<6), "F_B_BFu7c");
  }
}
static Arrange_To_Call_Me vF_B_BFu7c(Test_F_B_BFu7c, "F_B_BFu7c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu7i()
{
  {
    init_simple_test("F_B_BFu7i");
    static F_B_BFu7i lv;
    check2(sizeof(lv), 6, "sizeof(F_B_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu7i)");
    check_field_offset(lv, v1, 0, "F_B_BFu7i.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu7i.v2");
    set_bf_and_test(lv, v3, 5, 0, 7, 1, "F_B_BFu7i");
    set_bf_and_test(lv, v3, 5, 0, 7, hide_ull(1LL<<6), "F_B_BFu7i");
  }
}
static Arrange_To_Call_Me vF_B_BFu7i(Test_F_B_BFu7i, "F_B_BFu7i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu7ll()
{
  {
    init_simple_test("F_B_BFu7ll");
    static F_B_BFu7ll lv;
    check2(sizeof(lv), 6, "sizeof(F_B_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu7ll)");
    check_field_offset(lv, v1, 0, "F_B_BFu7ll.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu7ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 7, 1, "F_B_BFu7ll");
    set_bf_and_test(lv, v3, 5, 0, 7, hide_ull(1LL<<6), "F_B_BFu7ll");
  }
}
static Arrange_To_Call_Me vF_B_BFu7ll(Test_F_B_BFu7ll, "F_B_BFu7ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu7s()
{
  {
    init_simple_test("F_B_BFu7s");
    static F_B_BFu7s lv;
    check2(sizeof(lv), 6, "sizeof(F_B_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu7s)");
    check_field_offset(lv, v1, 0, "F_B_BFu7s.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu7s.v2");
    set_bf_and_test(lv, v3, 5, 0, 7, 1, "F_B_BFu7s");
    set_bf_and_test(lv, v3, 5, 0, 7, hide_ull(1LL<<6), "F_B_BFu7s");
  }
}
static Arrange_To_Call_Me vF_B_BFu7s(Test_F_B_BFu7s, "F_B_BFu7s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu8c()
{
  {
    init_simple_test("F_B_BFu8c");
    static F_B_BFu8c lv;
    check2(sizeof(lv), 6, "sizeof(F_B_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu8c)");
    check_field_offset(lv, v1, 0, "F_B_BFu8c.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu8c.v2");
    set_bf_and_test(lv, v3, 5, 0, 8, 1, "F_B_BFu8c");
    set_bf_and_test(lv, v3, 5, 0, 8, hide_ull(1LL<<7), "F_B_BFu8c");
  }
}
static Arrange_To_Call_Me vF_B_BFu8c(Test_F_B_BFu8c, "F_B_BFu8c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu8i()
{
  {
    init_simple_test("F_B_BFu8i");
    static F_B_BFu8i lv;
    check2(sizeof(lv), 6, "sizeof(F_B_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu8i)");
    check_field_offset(lv, v1, 0, "F_B_BFu8i.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu8i.v2");
    set_bf_and_test(lv, v3, 5, 0, 8, 1, "F_B_BFu8i");
    set_bf_and_test(lv, v3, 5, 0, 8, hide_ull(1LL<<7), "F_B_BFu8i");
  }
}
static Arrange_To_Call_Me vF_B_BFu8i(Test_F_B_BFu8i, "F_B_BFu8i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu8ll()
{
  {
    init_simple_test("F_B_BFu8ll");
    static F_B_BFu8ll lv;
    check2(sizeof(lv), 6, "sizeof(F_B_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu8ll)");
    check_field_offset(lv, v1, 0, "F_B_BFu8ll.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu8ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 8, 1, "F_B_BFu8ll");
    set_bf_and_test(lv, v3, 5, 0, 8, hide_ull(1LL<<7), "F_B_BFu8ll");
  }
}
static Arrange_To_Call_Me vF_B_BFu8ll(Test_F_B_BFu8ll, "F_B_BFu8ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu8s()
{
  {
    init_simple_test("F_B_BFu8s");
    static F_B_BFu8s lv;
    check2(sizeof(lv), 6, "sizeof(F_B_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu8s)");
    check_field_offset(lv, v1, 0, "F_B_BFu8s.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu8s.v2");
    set_bf_and_test(lv, v3, 5, 0, 8, 1, "F_B_BFu8s");
    set_bf_and_test(lv, v3, 5, 0, 8, hide_ull(1LL<<7), "F_B_BFu8s");
  }
}
static Arrange_To_Call_Me vF_B_BFu8s(Test_F_B_BFu8s, "F_B_BFu8s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu9i()
{
  {
    init_simple_test("F_B_BFu9i");
    static F_B_BFu9i lv;
    check2(sizeof(lv), 7, "sizeof(F_B_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu9i)");
    check_field_offset(lv, v1, 0, "F_B_BFu9i.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu9i.v2");
    set_bf_and_test(lv, v3, 5, 0, 9, 1, "F_B_BFu9i");
    set_bf_and_test(lv, v3, 5, 0, 9, hide_ull(1LL<<8), "F_B_BFu9i");
  }
}
static Arrange_To_Call_Me vF_B_BFu9i(Test_F_B_BFu9i, "F_B_BFu9i", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu9ll()
{
  {
    init_simple_test("F_B_BFu9ll");
    static F_B_BFu9ll lv;
    check2(sizeof(lv), 7, "sizeof(F_B_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu9ll)");
    check_field_offset(lv, v1, 0, "F_B_BFu9ll.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu9ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 9, 1, "F_B_BFu9ll");
    set_bf_and_test(lv, v3, 5, 0, 9, hide_ull(1LL<<8), "F_B_BFu9ll");
  }
}
static Arrange_To_Call_Me vF_B_BFu9ll(Test_F_B_BFu9ll, "F_B_BFu9ll", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_BFu9s()
{
  {
    init_simple_test("F_B_BFu9s");
    static F_B_BFu9s lv;
    check2(sizeof(lv), 7, "sizeof(F_B_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_BFu9s)");
    check_field_offset(lv, v1, 0, "F_B_BFu9s.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu9s.v2");
    set_bf_and_test(lv, v3, 5, 0, 9, 1, "F_B_BFu9s");
    set_bf_and_test(lv, v3, 5, 0, 9, hide_ull(1LL<<8), "F_B_BFu9s");
  }
}
static Arrange_To_Call_Me vF_B_BFu9s(Test_F_B_BFu9s, "F_B_BFu9s", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_C()
{
  {
    init_simple_test("F_B_C");
    F_B_C lv;
    check2(sizeof(lv), 6, "sizeof(F_B_C)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_C)");
    check_field_offset(lv, v1, 0, "F_B_C.v1");
    check_field_offset(lv, v2, 4, "F_B_C.v2");
    check_field_offset(lv, v3, 5, "F_B_C.v3");
  }
}
static Arrange_To_Call_Me vF_B_C(Test_F_B_C, "F_B_C", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_D()
{
  {
    init_simple_test("F_B_D");
    F_B_D lv;
    check2(sizeof(lv), 13, "sizeof(F_B_D)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_D)");
    check_field_offset(lv, v1, 0, "F_B_D.v1");
    check_field_offset(lv, v2, 4, "F_B_D.v2");
    check_field_offset(lv, v3, 5, "F_B_D.v3");
  }
}
static Arrange_To_Call_Me vF_B_D(Test_F_B_D, "F_B_D", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_F()
{
  {
    init_simple_test("F_B_F");
    F_B_F lv;
    check2(sizeof(lv), 9, "sizeof(F_B_F)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_F)");
    check_field_offset(lv, v1, 0, "F_B_F.v1");
    check_field_offset(lv, v2, 4, "F_B_F.v2");
    check_field_offset(lv, v3, 5, "F_B_F.v3");
  }
}
static Arrange_To_Call_Me vF_B_F(Test_F_B_F, "F_B_F", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_I()
{
  {
    init_simple_test("F_B_I");
    F_B_I lv;
    check2(sizeof(lv), 9, "sizeof(F_B_I)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_I)");
    check_field_offset(lv, v1, 0, "F_B_I.v1");
    check_field_offset(lv, v2, 4, "F_B_I.v2");
    check_field_offset(lv, v3, 5, "F_B_I.v3");
  }
}
static Arrange_To_Call_Me vF_B_I(Test_F_B_I, "F_B_I", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_Ip()
{
  {
    init_simple_test("F_B_Ip");
    F_B_Ip lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(F_B_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_Ip)");
    check_field_offset(lv, v1, 0, "F_B_Ip.v1");
    check_field_offset(lv, v2, 4, "F_B_Ip.v2");
    check_field_offset(lv, v3, 5, "F_B_Ip.v3");
  }
}
static Arrange_To_Call_Me vF_B_Ip(Test_F_B_Ip, "F_B_Ip", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_L()
{
  {
    init_simple_test("F_B_L");
    F_B_L lv;
    check2(sizeof(lv), 13, "sizeof(F_B_L)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_L)");
    check_field_offset(lv, v1, 0, "F_B_L.v1");
    check_field_offset(lv, v2, 4, "F_B_L.v2");
    check_field_offset(lv, v3, 5, "F_B_L.v3");
  }
}
static Arrange_To_Call_Me vF_B_L(Test_F_B_L, "F_B_L", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_S()
{
  {
    init_simple_test("F_B_S");
    F_B_S lv;
    check2(sizeof(lv), 7, "sizeof(F_B_S)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_S)");
    check_field_offset(lv, v1, 0, "F_B_S.v1");
    check_field_offset(lv, v2, 4, "F_B_S.v2");
    check_field_offset(lv, v3, 5, "F_B_S.v3");
  }
}
static Arrange_To_Call_Me vF_B_S(Test_F_B_S, "F_B_S", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_Uc()
{
  {
    init_simple_test("F_B_Uc");
    F_B_Uc lv;
    check2(sizeof(lv), 6, "sizeof(F_B_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_Uc)");
    check_field_offset(lv, v1, 0, "F_B_Uc.v1");
    check_field_offset(lv, v2, 4, "F_B_Uc.v2");
    check_field_offset(lv, v3, 5, "F_B_Uc.v3");
  }
}
static Arrange_To_Call_Me vF_B_Uc(Test_F_B_Uc, "F_B_Uc", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_Ui()
{
  {
    init_simple_test("F_B_Ui");
    F_B_Ui lv;
    check2(sizeof(lv), 9, "sizeof(F_B_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_Ui)");
    check_field_offset(lv, v1, 0, "F_B_Ui.v1");
    check_field_offset(lv, v2, 4, "F_B_Ui.v2");
    check_field_offset(lv, v3, 5, "F_B_Ui.v3");
  }
}
static Arrange_To_Call_Me vF_B_Ui(Test_F_B_Ui, "F_B_Ui", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_Ul()
{
  {
    init_simple_test("F_B_Ul");
    F_B_Ul lv;
    check2(sizeof(lv), 13, "sizeof(F_B_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_Ul)");
    check_field_offset(lv, v1, 0, "F_B_Ul.v1");
    check_field_offset(lv, v2, 4, "F_B_Ul.v2");
    check_field_offset(lv, v3, 5, "F_B_Ul.v3");
  }
}
static Arrange_To_Call_Me vF_B_Ul(Test_F_B_Ul, "F_B_Ul", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_Us()
{
  {
    init_simple_test("F_B_Us");
    F_B_Us lv;
    check2(sizeof(lv), 7, "sizeof(F_B_Us)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_Us)");
    check_field_offset(lv, v1, 0, "F_B_Us.v1");
    check_field_offset(lv, v2, 4, "F_B_Us.v2");
    check_field_offset(lv, v3, 5, "F_B_Us.v3");
  }
}
static Arrange_To_Call_Me vF_B_Us(Test_F_B_Us, "F_B_Us", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_B_Vp()
{
  {
    init_simple_test("F_B_Vp");
    F_B_Vp lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(F_B_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(F_B_Vp)");
    check_field_offset(lv, v1, 0, "F_B_Vp.v1");
    check_field_offset(lv, v2, 4, "F_B_Vp.v2");
    check_field_offset(lv, v3, 5, "F_B_Vp.v3");
  }
}
static Arrange_To_Call_Me vF_B_Vp(Test_F_B_Vp, "F_B_Vp", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu15i_B()
{
  {
    init_simple_test("F_BFu15i_B");
    static F_BFu15i_B lv;
    check2(sizeof(lv), 7, "sizeof(F_BFu15i_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu15i_B)");
    check_field_offset(lv, v1, 0, "F_BFu15i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "F_BFu15i_B");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "F_BFu15i_B");
    check_field_offset(lv, v3, 6, "F_BFu15i_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu15i_B(Test_F_BFu15i_B, "F_BFu15i_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu15ll_B()
{
  {
    init_simple_test("F_BFu15ll_B");
    static F_BFu15ll_B lv;
    check2(sizeof(lv), 7, "sizeof(F_BFu15ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu15ll_B)");
    check_field_offset(lv, v1, 0, "F_BFu15ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "F_BFu15ll_B");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "F_BFu15ll_B");
    check_field_offset(lv, v3, 6, "F_BFu15ll_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu15ll_B(Test_F_BFu15ll_B, "F_BFu15ll_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu15s_B()
{
  {
    init_simple_test("F_BFu15s_B");
    static F_BFu15s_B lv;
    check2(sizeof(lv), 7, "sizeof(F_BFu15s_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu15s_B)");
    check_field_offset(lv, v1, 0, "F_BFu15s_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "F_BFu15s_B");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "F_BFu15s_B");
    check_field_offset(lv, v3, 6, "F_BFu15s_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu15s_B(Test_F_BFu15s_B, "F_BFu15s_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu16i_B()
{
  {
    init_simple_test("F_BFu16i_B");
    static F_BFu16i_B lv;
    check2(sizeof(lv), 7, "sizeof(F_BFu16i_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu16i_B)");
    check_field_offset(lv, v1, 0, "F_BFu16i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "F_BFu16i_B");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "F_BFu16i_B");
    check_field_offset(lv, v3, 6, "F_BFu16i_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu16i_B(Test_F_BFu16i_B, "F_BFu16i_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu16ll_B()
{
  {
    init_simple_test("F_BFu16ll_B");
    static F_BFu16ll_B lv;
    check2(sizeof(lv), 7, "sizeof(F_BFu16ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu16ll_B)");
    check_field_offset(lv, v1, 0, "F_BFu16ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "F_BFu16ll_B");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "F_BFu16ll_B");
    check_field_offset(lv, v3, 6, "F_BFu16ll_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu16ll_B(Test_F_BFu16ll_B, "F_BFu16ll_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu16s_B()
{
  {
    init_simple_test("F_BFu16s_B");
    static F_BFu16s_B lv;
    check2(sizeof(lv), 7, "sizeof(F_BFu16s_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu16s_B)");
    check_field_offset(lv, v1, 0, "F_BFu16s_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "F_BFu16s_B");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "F_BFu16s_B");
    check_field_offset(lv, v3, 6, "F_BFu16s_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu16s_B(Test_F_BFu16s_B, "F_BFu16s_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu17i_B()
{
  {
    init_simple_test("F_BFu17i_B");
    static F_BFu17i_B lv;
    check2(sizeof(lv), 8, "sizeof(F_BFu17i_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu17i_B)");
    check_field_offset(lv, v1, 0, "F_BFu17i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "F_BFu17i_B");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "F_BFu17i_B");
    check_field_offset(lv, v3, 7, "F_BFu17i_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu17i_B(Test_F_BFu17i_B, "F_BFu17i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu17ll_B()
{
  {
    init_simple_test("F_BFu17ll_B");
    static F_BFu17ll_B lv;
    check2(sizeof(lv), 8, "sizeof(F_BFu17ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu17ll_B)");
    check_field_offset(lv, v1, 0, "F_BFu17ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "F_BFu17ll_B");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "F_BFu17ll_B");
    check_field_offset(lv, v3, 7, "F_BFu17ll_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu17ll_B(Test_F_BFu17ll_B, "F_BFu17ll_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu1c_B()
{
  {
    init_simple_test("F_BFu1c_B");
    static F_BFu1c_B lv;
    check2(sizeof(lv), 6, "sizeof(F_BFu1c_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu1c_B)");
    check_field_offset(lv, v1, 0, "F_BFu1c_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "F_BFu1c_B");
    check_field_offset(lv, v3, 5, "F_BFu1c_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu1c_B(Test_F_BFu1c_B, "F_BFu1c_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu1i_B()
{
  {
    init_simple_test("F_BFu1i_B");
    static F_BFu1i_B lv;
    check2(sizeof(lv), 6, "sizeof(F_BFu1i_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu1i_B)");
    check_field_offset(lv, v1, 0, "F_BFu1i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "F_BFu1i_B");
    check_field_offset(lv, v3, 5, "F_BFu1i_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu1i_B(Test_F_BFu1i_B, "F_BFu1i_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu1ll_B()
{
  {
    init_simple_test("F_BFu1ll_B");
    static F_BFu1ll_B lv;
    check2(sizeof(lv), 6, "sizeof(F_BFu1ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu1ll_B)");
    check_field_offset(lv, v1, 0, "F_BFu1ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "F_BFu1ll_B");
    check_field_offset(lv, v3, 5, "F_BFu1ll_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu1ll_B(Test_F_BFu1ll_B, "F_BFu1ll_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu1s_B()
{
  {
    init_simple_test("F_BFu1s_B");
    static F_BFu1s_B lv;
    check2(sizeof(lv), 6, "sizeof(F_BFu1s_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu1s_B)");
    check_field_offset(lv, v1, 0, "F_BFu1s_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "F_BFu1s_B");
    check_field_offset(lv, v3, 5, "F_BFu1s_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu1s_B(Test_F_BFu1s_B, "F_BFu1s_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu31i_B()
{
  {
    init_simple_test("F_BFu31i_B");
    static F_BFu31i_B lv;
    check2(sizeof(lv), 9, "sizeof(F_BFu31i_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu31i_B)");
    check_field_offset(lv, v1, 0, "F_BFu31i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "F_BFu31i_B");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "F_BFu31i_B");
    check_field_offset(lv, v3, 8, "F_BFu31i_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu31i_B(Test_F_BFu31i_B, "F_BFu31i_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu31ll_B()
{
  {
    init_simple_test("F_BFu31ll_B");
    static F_BFu31ll_B lv;
    check2(sizeof(lv), 9, "sizeof(F_BFu31ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu31ll_B)");
    check_field_offset(lv, v1, 0, "F_BFu31ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "F_BFu31ll_B");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "F_BFu31ll_B");
    check_field_offset(lv, v3, 8, "F_BFu31ll_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu31ll_B(Test_F_BFu31ll_B, "F_BFu31ll_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu32i_B()
{
  {
    init_simple_test("F_BFu32i_B");
    static F_BFu32i_B lv;
    check2(sizeof(lv), 9, "sizeof(F_BFu32i_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu32i_B)");
    check_field_offset(lv, v1, 0, "F_BFu32i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "F_BFu32i_B");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "F_BFu32i_B");
    check_field_offset(lv, v3, 8, "F_BFu32i_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu32i_B(Test_F_BFu32i_B, "F_BFu32i_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu32ll_B()
{
  {
    init_simple_test("F_BFu32ll_B");
    static F_BFu32ll_B lv;
    check2(sizeof(lv), 9, "sizeof(F_BFu32ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu32ll_B)");
    check_field_offset(lv, v1, 0, "F_BFu32ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "F_BFu32ll_B");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "F_BFu32ll_B");
    check_field_offset(lv, v3, 8, "F_BFu32ll_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu32ll_B(Test_F_BFu32ll_B, "F_BFu32ll_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu33_B()
{
  {
    init_simple_test("F_BFu33_B");
    static F_BFu33_B lv;
    check2(sizeof(lv), 10, "sizeof(F_BFu33_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu33_B)");
    check_field_offset(lv, v1, 0, "F_BFu33_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 33, 1, "F_BFu33_B");
    set_bf_and_test(lv, v2, 4, 0, 33, hide_ull(1LL<<32), "F_BFu33_B");
    check_field_offset(lv, v3, 9, "F_BFu33_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu33_B(Test_F_BFu33_B, "F_BFu33_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu7c_B()
{
  {
    init_simple_test("F_BFu7c_B");
    static F_BFu7c_B lv;
    check2(sizeof(lv), 6, "sizeof(F_BFu7c_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu7c_B)");
    check_field_offset(lv, v1, 0, "F_BFu7c_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "F_BFu7c_B");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "F_BFu7c_B");
    check_field_offset(lv, v3, 5, "F_BFu7c_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu7c_B(Test_F_BFu7c_B, "F_BFu7c_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu7i_B()
{
  {
    init_simple_test("F_BFu7i_B");
    static F_BFu7i_B lv;
    check2(sizeof(lv), 6, "sizeof(F_BFu7i_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu7i_B)");
    check_field_offset(lv, v1, 0, "F_BFu7i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "F_BFu7i_B");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "F_BFu7i_B");
    check_field_offset(lv, v3, 5, "F_BFu7i_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu7i_B(Test_F_BFu7i_B, "F_BFu7i_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu7ll_B()
{
  {
    init_simple_test("F_BFu7ll_B");
    static F_BFu7ll_B lv;
    check2(sizeof(lv), 6, "sizeof(F_BFu7ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu7ll_B)");
    check_field_offset(lv, v1, 0, "F_BFu7ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "F_BFu7ll_B");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "F_BFu7ll_B");
    check_field_offset(lv, v3, 5, "F_BFu7ll_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu7ll_B(Test_F_BFu7ll_B, "F_BFu7ll_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu7s_B()
{
  {
    init_simple_test("F_BFu7s_B");
    static F_BFu7s_B lv;
    check2(sizeof(lv), 6, "sizeof(F_BFu7s_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu7s_B)");
    check_field_offset(lv, v1, 0, "F_BFu7s_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "F_BFu7s_B");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "F_BFu7s_B");
    check_field_offset(lv, v3, 5, "F_BFu7s_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu7s_B(Test_F_BFu7s_B, "F_BFu7s_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu8c_B()
{
  {
    init_simple_test("F_BFu8c_B");
    static F_BFu8c_B lv;
    check2(sizeof(lv), 6, "sizeof(F_BFu8c_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu8c_B)");
    check_field_offset(lv, v1, 0, "F_BFu8c_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "F_BFu8c_B");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "F_BFu8c_B");
    check_field_offset(lv, v3, 5, "F_BFu8c_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu8c_B(Test_F_BFu8c_B, "F_BFu8c_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu8i_B()
{
  {
    init_simple_test("F_BFu8i_B");
    static F_BFu8i_B lv;
    check2(sizeof(lv), 6, "sizeof(F_BFu8i_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu8i_B)");
    check_field_offset(lv, v1, 0, "F_BFu8i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "F_BFu8i_B");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "F_BFu8i_B");
    check_field_offset(lv, v3, 5, "F_BFu8i_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu8i_B(Test_F_BFu8i_B, "F_BFu8i_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu8ll_B()
{
  {
    init_simple_test("F_BFu8ll_B");
    static F_BFu8ll_B lv;
    check2(sizeof(lv), 6, "sizeof(F_BFu8ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu8ll_B)");
    check_field_offset(lv, v1, 0, "F_BFu8ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "F_BFu8ll_B");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "F_BFu8ll_B");
    check_field_offset(lv, v3, 5, "F_BFu8ll_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu8ll_B(Test_F_BFu8ll_B, "F_BFu8ll_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu8s_B()
{
  {
    init_simple_test("F_BFu8s_B");
    static F_BFu8s_B lv;
    check2(sizeof(lv), 6, "sizeof(F_BFu8s_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu8s_B)");
    check_field_offset(lv, v1, 0, "F_BFu8s_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "F_BFu8s_B");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "F_BFu8s_B");
    check_field_offset(lv, v3, 5, "F_BFu8s_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu8s_B(Test_F_BFu8s_B, "F_BFu8s_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu9i_B()
{
  {
    init_simple_test("F_BFu9i_B");
    static F_BFu9i_B lv;
    check2(sizeof(lv), 7, "sizeof(F_BFu9i_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu9i_B)");
    check_field_offset(lv, v1, 0, "F_BFu9i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "F_BFu9i_B");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "F_BFu9i_B");
    check_field_offset(lv, v3, 6, "F_BFu9i_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu9i_B(Test_F_BFu9i_B, "F_BFu9i_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu9ll_B()
{
  {
    init_simple_test("F_BFu9ll_B");
    static F_BFu9ll_B lv;
    check2(sizeof(lv), 7, "sizeof(F_BFu9ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu9ll_B)");
    check_field_offset(lv, v1, 0, "F_BFu9ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "F_BFu9ll_B");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "F_BFu9ll_B");
    check_field_offset(lv, v3, 6, "F_BFu9ll_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu9ll_B(Test_F_BFu9ll_B, "F_BFu9ll_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_BFu9s_B()
{
  {
    init_simple_test("F_BFu9s_B");
    static F_BFu9s_B lv;
    check2(sizeof(lv), 7, "sizeof(F_BFu9s_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_BFu9s_B)");
    check_field_offset(lv, v1, 0, "F_BFu9s_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "F_BFu9s_B");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "F_BFu9s_B");
    check_field_offset(lv, v3, 6, "F_BFu9s_B.v3");
  }
}
static Arrange_To_Call_Me vF_BFu9s_B(Test_F_BFu9s_B, "F_BFu9s_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_C_B()
{
  {
    init_simple_test("F_C_B");
    F_C_B lv;
    check2(sizeof(lv), 6, "sizeof(F_C_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_C_B)");
    check_field_offset(lv, v1, 0, "F_C_B.v1");
    check_field_offset(lv, v2, 4, "F_C_B.v2");
    check_field_offset(lv, v3, 5, "F_C_B.v3");
  }
}
static Arrange_To_Call_Me vF_C_B(Test_F_C_B, "F_C_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_D_B()
{
  {
    init_simple_test("F_D_B");
    F_D_B lv;
    check2(sizeof(lv), 13, "sizeof(F_D_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_D_B)");
    check_field_offset(lv, v1, 0, "F_D_B.v1");
    check_field_offset(lv, v2, 4, "F_D_B.v2");
    check_field_offset(lv, v3, 12, "F_D_B.v3");
  }
}
static Arrange_To_Call_Me vF_D_B(Test_F_D_B, "F_D_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_F_B()
{
  {
    init_simple_test("F_F_B");
    F_F_B lv;
    check2(sizeof(lv), 9, "sizeof(F_F_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_F_B)");
    check_field_offset(lv, v1, 0, "F_F_B.v1");
    check_field_offset(lv, v2, 4, "F_F_B.v2");
    check_field_offset(lv, v3, 8, "F_F_B.v3");
  }
}
static Arrange_To_Call_Me vF_F_B(Test_F_F_B, "F_F_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_I_B()
{
  {
    init_simple_test("F_I_B");
    F_I_B lv;
    check2(sizeof(lv), 9, "sizeof(F_I_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_I_B)");
    check_field_offset(lv, v1, 0, "F_I_B.v1");
    check_field_offset(lv, v2, 4, "F_I_B.v2");
    check_field_offset(lv, v3, 8, "F_I_B.v3");
  }
}
static Arrange_To_Call_Me vF_I_B(Test_F_I_B, "F_I_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_Ip_B()
{
  {
    init_simple_test("F_Ip_B");
    F_Ip_B lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(F_Ip_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_Ip_B)");
    check_field_offset(lv, v1, 0, "F_Ip_B.v1");
    check_field_offset(lv, v2, 4, "F_Ip_B.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "F_Ip_B.v3");
  }
}
static Arrange_To_Call_Me vF_Ip_B(Test_F_Ip_B, "F_Ip_B", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_L_B()
{
  {
    init_simple_test("F_L_B");
    F_L_B lv;
    check2(sizeof(lv), 13, "sizeof(F_L_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_L_B)");
    check_field_offset(lv, v1, 0, "F_L_B.v1");
    check_field_offset(lv, v2, 4, "F_L_B.v2");
    check_field_offset(lv, v3, 12, "F_L_B.v3");
  }
}
static Arrange_To_Call_Me vF_L_B(Test_F_L_B, "F_L_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_S_B()
{
  {
    init_simple_test("F_S_B");
    F_S_B lv;
    check2(sizeof(lv), 7, "sizeof(F_S_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_S_B)");
    check_field_offset(lv, v1, 0, "F_S_B.v1");
    check_field_offset(lv, v2, 4, "F_S_B.v2");
    check_field_offset(lv, v3, 6, "F_S_B.v3");
  }
}
static Arrange_To_Call_Me vF_S_B(Test_F_S_B, "F_S_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_Uc_B()
{
  {
    init_simple_test("F_Uc_B");
    F_Uc_B lv;
    check2(sizeof(lv), 6, "sizeof(F_Uc_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_Uc_B)");
    check_field_offset(lv, v1, 0, "F_Uc_B.v1");
    check_field_offset(lv, v2, 4, "F_Uc_B.v2");
    check_field_offset(lv, v3, 5, "F_Uc_B.v3");
  }
}
static Arrange_To_Call_Me vF_Uc_B(Test_F_Uc_B, "F_Uc_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_Ui_B()
{
  {
    init_simple_test("F_Ui_B");
    F_Ui_B lv;
    check2(sizeof(lv), 9, "sizeof(F_Ui_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_Ui_B)");
    check_field_offset(lv, v1, 0, "F_Ui_B.v1");
    check_field_offset(lv, v2, 4, "F_Ui_B.v2");
    check_field_offset(lv, v3, 8, "F_Ui_B.v3");
  }
}
static Arrange_To_Call_Me vF_Ui_B(Test_F_Ui_B, "F_Ui_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_Ul_B()
{
  {
    init_simple_test("F_Ul_B");
    F_Ul_B lv;
    check2(sizeof(lv), 13, "sizeof(F_Ul_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_Ul_B)");
    check_field_offset(lv, v1, 0, "F_Ul_B.v1");
    check_field_offset(lv, v2, 4, "F_Ul_B.v2");
    check_field_offset(lv, v3, 12, "F_Ul_B.v3");
  }
}
static Arrange_To_Call_Me vF_Ul_B(Test_F_Ul_B, "F_Ul_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_Us_B()
{
  {
    init_simple_test("F_Us_B");
    F_Us_B lv;
    check2(sizeof(lv), 7, "sizeof(F_Us_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_Us_B)");
    check_field_offset(lv, v1, 0, "F_Us_B.v1");
    check_field_offset(lv, v2, 4, "F_Us_B.v2");
    check_field_offset(lv, v3, 6, "F_Us_B.v3");
  }
}
static Arrange_To_Call_Me vF_Us_B(Test_F_Us_B, "F_Us_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_F_Vp_B()
{
  {
    init_simple_test("F_Vp_B");
    F_Vp_B lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(F_Vp_B)");
    check2(__alignof__(lv), 1, "__alignof__(F_Vp_B)");
    check_field_offset(lv, v1, 0, "F_Vp_B.v1");
    check_field_offset(lv, v2, 4, "F_Vp_B.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "F_Vp_B.v3");
  }
}
static Arrange_To_Call_Me vF_Vp_B(Test_F_Vp_B, "F_Vp_B", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B()
{
  {
    init_simple_test("I_B");
    I_B lv;
    check2(sizeof(lv), 5, "sizeof(I_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_B)");
    check_field_offset(lv, v1, 0, "I_B.v1");
    check_field_offset(lv, v2, 4, "I_B.v2");
  }
}
static Arrange_To_Call_Me vI_B(Test_I_B, "I_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_B()
{
  {
    init_simple_test("I_B_B");
    I_B_B lv;
    check2(sizeof(lv), 6, "sizeof(I_B_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_B)");
    check_field_offset(lv, v1, 0, "I_B_B.v1");
    check_field_offset(lv, v2, 4, "I_B_B.v2");
    check_field_offset(lv, v3, 5, "I_B_B.v3");
  }
}
static Arrange_To_Call_Me vI_B_B(Test_I_B_B, "I_B_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu15i()
{
  {
    init_simple_test("I_B_BFu15i");
    static I_B_BFu15i lv;
    check2(sizeof(lv), 7, "sizeof(I_B_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu15i)");
    check_field_offset(lv, v1, 0, "I_B_BFu15i.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu15i.v2");
    set_bf_and_test(lv, v3, 5, 0, 15, 1, "I_B_BFu15i");
    set_bf_and_test(lv, v3, 5, 0, 15, hide_ull(1LL<<14), "I_B_BFu15i");
  }
}
static Arrange_To_Call_Me vI_B_BFu15i(Test_I_B_BFu15i, "I_B_BFu15i", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu15ll()
{
  {
    init_simple_test("I_B_BFu15ll");
    static I_B_BFu15ll lv;
    check2(sizeof(lv), 7, "sizeof(I_B_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu15ll)");
    check_field_offset(lv, v1, 0, "I_B_BFu15ll.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu15ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 15, 1, "I_B_BFu15ll");
    set_bf_and_test(lv, v3, 5, 0, 15, hide_ull(1LL<<14), "I_B_BFu15ll");
  }
}
static Arrange_To_Call_Me vI_B_BFu15ll(Test_I_B_BFu15ll, "I_B_BFu15ll", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu15s()
{
  {
    init_simple_test("I_B_BFu15s");
    static I_B_BFu15s lv;
    check2(sizeof(lv), 7, "sizeof(I_B_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu15s)");
    check_field_offset(lv, v1, 0, "I_B_BFu15s.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu15s.v2");
    set_bf_and_test(lv, v3, 5, 0, 15, 1, "I_B_BFu15s");
    set_bf_and_test(lv, v3, 5, 0, 15, hide_ull(1LL<<14), "I_B_BFu15s");
  }
}
static Arrange_To_Call_Me vI_B_BFu15s(Test_I_B_BFu15s, "I_B_BFu15s", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu16i()
{
  {
    init_simple_test("I_B_BFu16i");
    static I_B_BFu16i lv;
    check2(sizeof(lv), 7, "sizeof(I_B_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu16i)");
    check_field_offset(lv, v1, 0, "I_B_BFu16i.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu16i.v2");
    set_bf_and_test(lv, v3, 5, 0, 16, 1, "I_B_BFu16i");
    set_bf_and_test(lv, v3, 5, 0, 16, hide_ull(1LL<<15), "I_B_BFu16i");
  }
}
static Arrange_To_Call_Me vI_B_BFu16i(Test_I_B_BFu16i, "I_B_BFu16i", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu16ll()
{
  {
    init_simple_test("I_B_BFu16ll");
    static I_B_BFu16ll lv;
    check2(sizeof(lv), 7, "sizeof(I_B_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu16ll)");
    check_field_offset(lv, v1, 0, "I_B_BFu16ll.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu16ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 16, 1, "I_B_BFu16ll");
    set_bf_and_test(lv, v3, 5, 0, 16, hide_ull(1LL<<15), "I_B_BFu16ll");
  }
}
static Arrange_To_Call_Me vI_B_BFu16ll(Test_I_B_BFu16ll, "I_B_BFu16ll", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu16s()
{
  {
    init_simple_test("I_B_BFu16s");
    static I_B_BFu16s lv;
    check2(sizeof(lv), 7, "sizeof(I_B_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu16s)");
    check_field_offset(lv, v1, 0, "I_B_BFu16s.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu16s.v2");
    set_bf_and_test(lv, v3, 5, 0, 16, 1, "I_B_BFu16s");
    set_bf_and_test(lv, v3, 5, 0, 16, hide_ull(1LL<<15), "I_B_BFu16s");
  }
}
static Arrange_To_Call_Me vI_B_BFu16s(Test_I_B_BFu16s, "I_B_BFu16s", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu17i()
{
  {
    init_simple_test("I_B_BFu17i");
    static I_B_BFu17i lv;
    check2(sizeof(lv), 8, "sizeof(I_B_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu17i)");
    check_field_offset(lv, v1, 0, "I_B_BFu17i.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu17i.v2");
    set_bf_and_test(lv, v3, 5, 0, 17, 1, "I_B_BFu17i");
    set_bf_and_test(lv, v3, 5, 0, 17, hide_ull(1LL<<16), "I_B_BFu17i");
  }
}
static Arrange_To_Call_Me vI_B_BFu17i(Test_I_B_BFu17i, "I_B_BFu17i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu17ll()
{
  {
    init_simple_test("I_B_BFu17ll");
    static I_B_BFu17ll lv;
    check2(sizeof(lv), 8, "sizeof(I_B_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu17ll)");
    check_field_offset(lv, v1, 0, "I_B_BFu17ll.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu17ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 17, 1, "I_B_BFu17ll");
    set_bf_and_test(lv, v3, 5, 0, 17, hide_ull(1LL<<16), "I_B_BFu17ll");
  }
}
static Arrange_To_Call_Me vI_B_BFu17ll(Test_I_B_BFu17ll, "I_B_BFu17ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu1c()
{
  {
    init_simple_test("I_B_BFu1c");
    static I_B_BFu1c lv;
    check2(sizeof(lv), 6, "sizeof(I_B_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu1c)");
    check_field_offset(lv, v1, 0, "I_B_BFu1c.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu1c.v2");
    set_bf_and_test(lv, v3, 5, 0, 1, 1, "I_B_BFu1c");
  }
}
static Arrange_To_Call_Me vI_B_BFu1c(Test_I_B_BFu1c, "I_B_BFu1c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu1i()
{
  {
    init_simple_test("I_B_BFu1i");
    static I_B_BFu1i lv;
    check2(sizeof(lv), 6, "sizeof(I_B_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu1i)");
    check_field_offset(lv, v1, 0, "I_B_BFu1i.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu1i.v2");
    set_bf_and_test(lv, v3, 5, 0, 1, 1, "I_B_BFu1i");
  }
}
static Arrange_To_Call_Me vI_B_BFu1i(Test_I_B_BFu1i, "I_B_BFu1i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu1ll()
{
  {
    init_simple_test("I_B_BFu1ll");
    static I_B_BFu1ll lv;
    check2(sizeof(lv), 6, "sizeof(I_B_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu1ll)");
    check_field_offset(lv, v1, 0, "I_B_BFu1ll.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu1ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 1, 1, "I_B_BFu1ll");
  }
}
static Arrange_To_Call_Me vI_B_BFu1ll(Test_I_B_BFu1ll, "I_B_BFu1ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu1s()
{
  {
    init_simple_test("I_B_BFu1s");
    static I_B_BFu1s lv;
    check2(sizeof(lv), 6, "sizeof(I_B_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu1s)");
    check_field_offset(lv, v1, 0, "I_B_BFu1s.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu1s.v2");
    set_bf_and_test(lv, v3, 5, 0, 1, 1, "I_B_BFu1s");
  }
}
static Arrange_To_Call_Me vI_B_BFu1s(Test_I_B_BFu1s, "I_B_BFu1s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu31i()
{
  {
    init_simple_test("I_B_BFu31i");
    static I_B_BFu31i lv;
    check2(sizeof(lv), 9, "sizeof(I_B_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu31i)");
    check_field_offset(lv, v1, 0, "I_B_BFu31i.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu31i.v2");
    set_bf_and_test(lv, v3, 5, 0, 31, 1, "I_B_BFu31i");
    set_bf_and_test(lv, v3, 5, 0, 31, hide_ull(1LL<<30), "I_B_BFu31i");
  }
}
static Arrange_To_Call_Me vI_B_BFu31i(Test_I_B_BFu31i, "I_B_BFu31i", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu31ll()
{
  {
    init_simple_test("I_B_BFu31ll");
    static I_B_BFu31ll lv;
    check2(sizeof(lv), 9, "sizeof(I_B_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu31ll)");
    check_field_offset(lv, v1, 0, "I_B_BFu31ll.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu31ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 31, 1, "I_B_BFu31ll");
    set_bf_and_test(lv, v3, 5, 0, 31, hide_ull(1LL<<30), "I_B_BFu31ll");
  }
}
static Arrange_To_Call_Me vI_B_BFu31ll(Test_I_B_BFu31ll, "I_B_BFu31ll", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu32i()
{
  {
    init_simple_test("I_B_BFu32i");
    static I_B_BFu32i lv;
    check2(sizeof(lv), 9, "sizeof(I_B_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu32i)");
    check_field_offset(lv, v1, 0, "I_B_BFu32i.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu32i.v2");
    set_bf_and_test(lv, v3, 5, 0, 32, 1, "I_B_BFu32i");
    set_bf_and_test(lv, v3, 5, 0, 32, hide_ull(1LL<<31), "I_B_BFu32i");
  }
}
static Arrange_To_Call_Me vI_B_BFu32i(Test_I_B_BFu32i, "I_B_BFu32i", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu32ll()
{
  {
    init_simple_test("I_B_BFu32ll");
    static I_B_BFu32ll lv;
    check2(sizeof(lv), 9, "sizeof(I_B_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu32ll)");
    check_field_offset(lv, v1, 0, "I_B_BFu32ll.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu32ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 32, 1, "I_B_BFu32ll");
    set_bf_and_test(lv, v3, 5, 0, 32, hide_ull(1LL<<31), "I_B_BFu32ll");
  }
}
static Arrange_To_Call_Me vI_B_BFu32ll(Test_I_B_BFu32ll, "I_B_BFu32ll", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu33()
{
  {
    init_simple_test("I_B_BFu33");
    static I_B_BFu33 lv;
    check2(sizeof(lv), 10, "sizeof(I_B_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu33)");
    check_field_offset(lv, v1, 0, "I_B_BFu33.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu33.v2");
    set_bf_and_test(lv, v3, 5, 0, 33, 1, "I_B_BFu33");
    set_bf_and_test(lv, v3, 5, 0, 33, hide_ull(1LL<<32), "I_B_BFu33");
  }
}
static Arrange_To_Call_Me vI_B_BFu33(Test_I_B_BFu33, "I_B_BFu33", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu7c()
{
  {
    init_simple_test("I_B_BFu7c");
    static I_B_BFu7c lv;
    check2(sizeof(lv), 6, "sizeof(I_B_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu7c)");
    check_field_offset(lv, v1, 0, "I_B_BFu7c.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu7c.v2");
    set_bf_and_test(lv, v3, 5, 0, 7, 1, "I_B_BFu7c");
    set_bf_and_test(lv, v3, 5, 0, 7, hide_ull(1LL<<6), "I_B_BFu7c");
  }
}
static Arrange_To_Call_Me vI_B_BFu7c(Test_I_B_BFu7c, "I_B_BFu7c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu7i()
{
  {
    init_simple_test("I_B_BFu7i");
    static I_B_BFu7i lv;
    check2(sizeof(lv), 6, "sizeof(I_B_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu7i)");
    check_field_offset(lv, v1, 0, "I_B_BFu7i.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu7i.v2");
    set_bf_and_test(lv, v3, 5, 0, 7, 1, "I_B_BFu7i");
    set_bf_and_test(lv, v3, 5, 0, 7, hide_ull(1LL<<6), "I_B_BFu7i");
  }
}
static Arrange_To_Call_Me vI_B_BFu7i(Test_I_B_BFu7i, "I_B_BFu7i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu7ll()
{
  {
    init_simple_test("I_B_BFu7ll");
    static I_B_BFu7ll lv;
    check2(sizeof(lv), 6, "sizeof(I_B_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu7ll)");
    check_field_offset(lv, v1, 0, "I_B_BFu7ll.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu7ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 7, 1, "I_B_BFu7ll");
    set_bf_and_test(lv, v3, 5, 0, 7, hide_ull(1LL<<6), "I_B_BFu7ll");
  }
}
static Arrange_To_Call_Me vI_B_BFu7ll(Test_I_B_BFu7ll, "I_B_BFu7ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu7s()
{
  {
    init_simple_test("I_B_BFu7s");
    static I_B_BFu7s lv;
    check2(sizeof(lv), 6, "sizeof(I_B_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu7s)");
    check_field_offset(lv, v1, 0, "I_B_BFu7s.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu7s.v2");
    set_bf_and_test(lv, v3, 5, 0, 7, 1, "I_B_BFu7s");
    set_bf_and_test(lv, v3, 5, 0, 7, hide_ull(1LL<<6), "I_B_BFu7s");
  }
}
static Arrange_To_Call_Me vI_B_BFu7s(Test_I_B_BFu7s, "I_B_BFu7s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu8c()
{
  {
    init_simple_test("I_B_BFu8c");
    static I_B_BFu8c lv;
    check2(sizeof(lv), 6, "sizeof(I_B_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu8c)");
    check_field_offset(lv, v1, 0, "I_B_BFu8c.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu8c.v2");
    set_bf_and_test(lv, v3, 5, 0, 8, 1, "I_B_BFu8c");
    set_bf_and_test(lv, v3, 5, 0, 8, hide_ull(1LL<<7), "I_B_BFu8c");
  }
}
static Arrange_To_Call_Me vI_B_BFu8c(Test_I_B_BFu8c, "I_B_BFu8c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu8i()
{
  {
    init_simple_test("I_B_BFu8i");
    static I_B_BFu8i lv;
    check2(sizeof(lv), 6, "sizeof(I_B_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu8i)");
    check_field_offset(lv, v1, 0, "I_B_BFu8i.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu8i.v2");
    set_bf_and_test(lv, v3, 5, 0, 8, 1, "I_B_BFu8i");
    set_bf_and_test(lv, v3, 5, 0, 8, hide_ull(1LL<<7), "I_B_BFu8i");
  }
}
static Arrange_To_Call_Me vI_B_BFu8i(Test_I_B_BFu8i, "I_B_BFu8i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu8ll()
{
  {
    init_simple_test("I_B_BFu8ll");
    static I_B_BFu8ll lv;
    check2(sizeof(lv), 6, "sizeof(I_B_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu8ll)");
    check_field_offset(lv, v1, 0, "I_B_BFu8ll.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu8ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 8, 1, "I_B_BFu8ll");
    set_bf_and_test(lv, v3, 5, 0, 8, hide_ull(1LL<<7), "I_B_BFu8ll");
  }
}
static Arrange_To_Call_Me vI_B_BFu8ll(Test_I_B_BFu8ll, "I_B_BFu8ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu8s()
{
  {
    init_simple_test("I_B_BFu8s");
    static I_B_BFu8s lv;
    check2(sizeof(lv), 6, "sizeof(I_B_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu8s)");
    check_field_offset(lv, v1, 0, "I_B_BFu8s.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu8s.v2");
    set_bf_and_test(lv, v3, 5, 0, 8, 1, "I_B_BFu8s");
    set_bf_and_test(lv, v3, 5, 0, 8, hide_ull(1LL<<7), "I_B_BFu8s");
  }
}
static Arrange_To_Call_Me vI_B_BFu8s(Test_I_B_BFu8s, "I_B_BFu8s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu9i()
{
  {
    init_simple_test("I_B_BFu9i");
    static I_B_BFu9i lv;
    check2(sizeof(lv), 7, "sizeof(I_B_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu9i)");
    check_field_offset(lv, v1, 0, "I_B_BFu9i.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu9i.v2");
    set_bf_and_test(lv, v3, 5, 0, 9, 1, "I_B_BFu9i");
    set_bf_and_test(lv, v3, 5, 0, 9, hide_ull(1LL<<8), "I_B_BFu9i");
  }
}
static Arrange_To_Call_Me vI_B_BFu9i(Test_I_B_BFu9i, "I_B_BFu9i", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu9ll()
{
  {
    init_simple_test("I_B_BFu9ll");
    static I_B_BFu9ll lv;
    check2(sizeof(lv), 7, "sizeof(I_B_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu9ll)");
    check_field_offset(lv, v1, 0, "I_B_BFu9ll.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu9ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 9, 1, "I_B_BFu9ll");
    set_bf_and_test(lv, v3, 5, 0, 9, hide_ull(1LL<<8), "I_B_BFu9ll");
  }
}
static Arrange_To_Call_Me vI_B_BFu9ll(Test_I_B_BFu9ll, "I_B_BFu9ll", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_BFu9s()
{
  {
    init_simple_test("I_B_BFu9s");
    static I_B_BFu9s lv;
    check2(sizeof(lv), 7, "sizeof(I_B_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_BFu9s)");
    check_field_offset(lv, v1, 0, "I_B_BFu9s.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu9s.v2");
    set_bf_and_test(lv, v3, 5, 0, 9, 1, "I_B_BFu9s");
    set_bf_and_test(lv, v3, 5, 0, 9, hide_ull(1LL<<8), "I_B_BFu9s");
  }
}
static Arrange_To_Call_Me vI_B_BFu9s(Test_I_B_BFu9s, "I_B_BFu9s", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_C()
{
  {
    init_simple_test("I_B_C");
    I_B_C lv;
    check2(sizeof(lv), 6, "sizeof(I_B_C)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_C)");
    check_field_offset(lv, v1, 0, "I_B_C.v1");
    check_field_offset(lv, v2, 4, "I_B_C.v2");
    check_field_offset(lv, v3, 5, "I_B_C.v3");
  }
}
static Arrange_To_Call_Me vI_B_C(Test_I_B_C, "I_B_C", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_D()
{
  {
    init_simple_test("I_B_D");
    I_B_D lv;
    check2(sizeof(lv), 13, "sizeof(I_B_D)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_D)");
    check_field_offset(lv, v1, 0, "I_B_D.v1");
    check_field_offset(lv, v2, 4, "I_B_D.v2");
    check_field_offset(lv, v3, 5, "I_B_D.v3");
  }
}
static Arrange_To_Call_Me vI_B_D(Test_I_B_D, "I_B_D", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_F()
{
  {
    init_simple_test("I_B_F");
    I_B_F lv;
    check2(sizeof(lv), 9, "sizeof(I_B_F)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_F)");
    check_field_offset(lv, v1, 0, "I_B_F.v1");
    check_field_offset(lv, v2, 4, "I_B_F.v2");
    check_field_offset(lv, v3, 5, "I_B_F.v3");
  }
}
static Arrange_To_Call_Me vI_B_F(Test_I_B_F, "I_B_F", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_I()
{
  {
    init_simple_test("I_B_I");
    I_B_I lv;
    check2(sizeof(lv), 9, "sizeof(I_B_I)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_I)");
    check_field_offset(lv, v1, 0, "I_B_I.v1");
    check_field_offset(lv, v2, 4, "I_B_I.v2");
    check_field_offset(lv, v3, 5, "I_B_I.v3");
  }
}
static Arrange_To_Call_Me vI_B_I(Test_I_B_I, "I_B_I", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_Ip()
{
  {
    init_simple_test("I_B_Ip");
    I_B_Ip lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(I_B_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_Ip)");
    check_field_offset(lv, v1, 0, "I_B_Ip.v1");
    check_field_offset(lv, v2, 4, "I_B_Ip.v2");
    check_field_offset(lv, v3, 5, "I_B_Ip.v3");
  }
}
static Arrange_To_Call_Me vI_B_Ip(Test_I_B_Ip, "I_B_Ip", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_L()
{
  {
    init_simple_test("I_B_L");
    I_B_L lv;
    check2(sizeof(lv), 13, "sizeof(I_B_L)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_L)");
    check_field_offset(lv, v1, 0, "I_B_L.v1");
    check_field_offset(lv, v2, 4, "I_B_L.v2");
    check_field_offset(lv, v3, 5, "I_B_L.v3");
  }
}
static Arrange_To_Call_Me vI_B_L(Test_I_B_L, "I_B_L", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_S()
{
  {
    init_simple_test("I_B_S");
    I_B_S lv;
    check2(sizeof(lv), 7, "sizeof(I_B_S)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_S)");
    check_field_offset(lv, v1, 0, "I_B_S.v1");
    check_field_offset(lv, v2, 4, "I_B_S.v2");
    check_field_offset(lv, v3, 5, "I_B_S.v3");
  }
}
static Arrange_To_Call_Me vI_B_S(Test_I_B_S, "I_B_S", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_Uc()
{
  {
    init_simple_test("I_B_Uc");
    I_B_Uc lv;
    check2(sizeof(lv), 6, "sizeof(I_B_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_Uc)");
    check_field_offset(lv, v1, 0, "I_B_Uc.v1");
    check_field_offset(lv, v2, 4, "I_B_Uc.v2");
    check_field_offset(lv, v3, 5, "I_B_Uc.v3");
  }
}
static Arrange_To_Call_Me vI_B_Uc(Test_I_B_Uc, "I_B_Uc", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_Ui()
{
  {
    init_simple_test("I_B_Ui");
    I_B_Ui lv;
    check2(sizeof(lv), 9, "sizeof(I_B_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_Ui)");
    check_field_offset(lv, v1, 0, "I_B_Ui.v1");
    check_field_offset(lv, v2, 4, "I_B_Ui.v2");
    check_field_offset(lv, v3, 5, "I_B_Ui.v3");
  }
}
static Arrange_To_Call_Me vI_B_Ui(Test_I_B_Ui, "I_B_Ui", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_Ul()
{
  {
    init_simple_test("I_B_Ul");
    I_B_Ul lv;
    check2(sizeof(lv), 13, "sizeof(I_B_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_Ul)");
    check_field_offset(lv, v1, 0, "I_B_Ul.v1");
    check_field_offset(lv, v2, 4, "I_B_Ul.v2");
    check_field_offset(lv, v3, 5, "I_B_Ul.v3");
  }
}
static Arrange_To_Call_Me vI_B_Ul(Test_I_B_Ul, "I_B_Ul", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_Us()
{
  {
    init_simple_test("I_B_Us");
    I_B_Us lv;
    check2(sizeof(lv), 7, "sizeof(I_B_Us)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_Us)");
    check_field_offset(lv, v1, 0, "I_B_Us.v1");
    check_field_offset(lv, v2, 4, "I_B_Us.v2");
    check_field_offset(lv, v3, 5, "I_B_Us.v3");
  }
}
static Arrange_To_Call_Me vI_B_Us(Test_I_B_Us, "I_B_Us", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_B_Vp()
{
  {
    init_simple_test("I_B_Vp");
    I_B_Vp lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(I_B_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(I_B_Vp)");
    check_field_offset(lv, v1, 0, "I_B_Vp.v1");
    check_field_offset(lv, v2, 4, "I_B_Vp.v2");
    check_field_offset(lv, v3, 5, "I_B_Vp.v3");
  }
}
static Arrange_To_Call_Me vI_B_Vp(Test_I_B_Vp, "I_B_Vp", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu15i_B()
{
  {
    init_simple_test("I_BFu15i_B");
    static I_BFu15i_B lv;
    check2(sizeof(lv), 7, "sizeof(I_BFu15i_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu15i_B)");
    check_field_offset(lv, v1, 0, "I_BFu15i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "I_BFu15i_B");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "I_BFu15i_B");
    check_field_offset(lv, v3, 6, "I_BFu15i_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu15i_B(Test_I_BFu15i_B, "I_BFu15i_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu15ll_B()
{
  {
    init_simple_test("I_BFu15ll_B");
    static I_BFu15ll_B lv;
    check2(sizeof(lv), 7, "sizeof(I_BFu15ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu15ll_B)");
    check_field_offset(lv, v1, 0, "I_BFu15ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "I_BFu15ll_B");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "I_BFu15ll_B");
    check_field_offset(lv, v3, 6, "I_BFu15ll_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu15ll_B(Test_I_BFu15ll_B, "I_BFu15ll_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu15s_B()
{
  {
    init_simple_test("I_BFu15s_B");
    static I_BFu15s_B lv;
    check2(sizeof(lv), 7, "sizeof(I_BFu15s_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu15s_B)");
    check_field_offset(lv, v1, 0, "I_BFu15s_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "I_BFu15s_B");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "I_BFu15s_B");
    check_field_offset(lv, v3, 6, "I_BFu15s_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu15s_B(Test_I_BFu15s_B, "I_BFu15s_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu16i_B()
{
  {
    init_simple_test("I_BFu16i_B");
    static I_BFu16i_B lv;
    check2(sizeof(lv), 7, "sizeof(I_BFu16i_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu16i_B)");
    check_field_offset(lv, v1, 0, "I_BFu16i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "I_BFu16i_B");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "I_BFu16i_B");
    check_field_offset(lv, v3, 6, "I_BFu16i_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu16i_B(Test_I_BFu16i_B, "I_BFu16i_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu16ll_B()
{
  {
    init_simple_test("I_BFu16ll_B");
    static I_BFu16ll_B lv;
    check2(sizeof(lv), 7, "sizeof(I_BFu16ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu16ll_B)");
    check_field_offset(lv, v1, 0, "I_BFu16ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "I_BFu16ll_B");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "I_BFu16ll_B");
    check_field_offset(lv, v3, 6, "I_BFu16ll_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu16ll_B(Test_I_BFu16ll_B, "I_BFu16ll_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu16s_B()
{
  {
    init_simple_test("I_BFu16s_B");
    static I_BFu16s_B lv;
    check2(sizeof(lv), 7, "sizeof(I_BFu16s_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu16s_B)");
    check_field_offset(lv, v1, 0, "I_BFu16s_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "I_BFu16s_B");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "I_BFu16s_B");
    check_field_offset(lv, v3, 6, "I_BFu16s_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu16s_B(Test_I_BFu16s_B, "I_BFu16s_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu17i_B()
{
  {
    init_simple_test("I_BFu17i_B");
    static I_BFu17i_B lv;
    check2(sizeof(lv), 8, "sizeof(I_BFu17i_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu17i_B)");
    check_field_offset(lv, v1, 0, "I_BFu17i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "I_BFu17i_B");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "I_BFu17i_B");
    check_field_offset(lv, v3, 7, "I_BFu17i_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu17i_B(Test_I_BFu17i_B, "I_BFu17i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu17ll_B()
{
  {
    init_simple_test("I_BFu17ll_B");
    static I_BFu17ll_B lv;
    check2(sizeof(lv), 8, "sizeof(I_BFu17ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu17ll_B)");
    check_field_offset(lv, v1, 0, "I_BFu17ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "I_BFu17ll_B");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "I_BFu17ll_B");
    check_field_offset(lv, v3, 7, "I_BFu17ll_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu17ll_B(Test_I_BFu17ll_B, "I_BFu17ll_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu1c_B()
{
  {
    init_simple_test("I_BFu1c_B");
    static I_BFu1c_B lv;
    check2(sizeof(lv), 6, "sizeof(I_BFu1c_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu1c_B)");
    check_field_offset(lv, v1, 0, "I_BFu1c_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "I_BFu1c_B");
    check_field_offset(lv, v3, 5, "I_BFu1c_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu1c_B(Test_I_BFu1c_B, "I_BFu1c_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu1i_B()
{
  {
    init_simple_test("I_BFu1i_B");
    static I_BFu1i_B lv;
    check2(sizeof(lv), 6, "sizeof(I_BFu1i_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu1i_B)");
    check_field_offset(lv, v1, 0, "I_BFu1i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "I_BFu1i_B");
    check_field_offset(lv, v3, 5, "I_BFu1i_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu1i_B(Test_I_BFu1i_B, "I_BFu1i_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu1ll_B()
{
  {
    init_simple_test("I_BFu1ll_B");
    static I_BFu1ll_B lv;
    check2(sizeof(lv), 6, "sizeof(I_BFu1ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu1ll_B)");
    check_field_offset(lv, v1, 0, "I_BFu1ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "I_BFu1ll_B");
    check_field_offset(lv, v3, 5, "I_BFu1ll_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu1ll_B(Test_I_BFu1ll_B, "I_BFu1ll_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu1s_B()
{
  {
    init_simple_test("I_BFu1s_B");
    static I_BFu1s_B lv;
    check2(sizeof(lv), 6, "sizeof(I_BFu1s_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu1s_B)");
    check_field_offset(lv, v1, 0, "I_BFu1s_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "I_BFu1s_B");
    check_field_offset(lv, v3, 5, "I_BFu1s_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu1s_B(Test_I_BFu1s_B, "I_BFu1s_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu31i_B()
{
  {
    init_simple_test("I_BFu31i_B");
    static I_BFu31i_B lv;
    check2(sizeof(lv), 9, "sizeof(I_BFu31i_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu31i_B)");
    check_field_offset(lv, v1, 0, "I_BFu31i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "I_BFu31i_B");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "I_BFu31i_B");
    check_field_offset(lv, v3, 8, "I_BFu31i_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu31i_B(Test_I_BFu31i_B, "I_BFu31i_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu31ll_B()
{
  {
    init_simple_test("I_BFu31ll_B");
    static I_BFu31ll_B lv;
    check2(sizeof(lv), 9, "sizeof(I_BFu31ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu31ll_B)");
    check_field_offset(lv, v1, 0, "I_BFu31ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "I_BFu31ll_B");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "I_BFu31ll_B");
    check_field_offset(lv, v3, 8, "I_BFu31ll_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu31ll_B(Test_I_BFu31ll_B, "I_BFu31ll_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu32i_B()
{
  {
    init_simple_test("I_BFu32i_B");
    static I_BFu32i_B lv;
    check2(sizeof(lv), 9, "sizeof(I_BFu32i_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu32i_B)");
    check_field_offset(lv, v1, 0, "I_BFu32i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "I_BFu32i_B");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "I_BFu32i_B");
    check_field_offset(lv, v3, 8, "I_BFu32i_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu32i_B(Test_I_BFu32i_B, "I_BFu32i_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu32ll_B()
{
  {
    init_simple_test("I_BFu32ll_B");
    static I_BFu32ll_B lv;
    check2(sizeof(lv), 9, "sizeof(I_BFu32ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu32ll_B)");
    check_field_offset(lv, v1, 0, "I_BFu32ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "I_BFu32ll_B");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "I_BFu32ll_B");
    check_field_offset(lv, v3, 8, "I_BFu32ll_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu32ll_B(Test_I_BFu32ll_B, "I_BFu32ll_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu33_B()
{
  {
    init_simple_test("I_BFu33_B");
    static I_BFu33_B lv;
    check2(sizeof(lv), 10, "sizeof(I_BFu33_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu33_B)");
    check_field_offset(lv, v1, 0, "I_BFu33_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 33, 1, "I_BFu33_B");
    set_bf_and_test(lv, v2, 4, 0, 33, hide_ull(1LL<<32), "I_BFu33_B");
    check_field_offset(lv, v3, 9, "I_BFu33_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu33_B(Test_I_BFu33_B, "I_BFu33_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu7c_B()
{
  {
    init_simple_test("I_BFu7c_B");
    static I_BFu7c_B lv;
    check2(sizeof(lv), 6, "sizeof(I_BFu7c_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu7c_B)");
    check_field_offset(lv, v1, 0, "I_BFu7c_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "I_BFu7c_B");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "I_BFu7c_B");
    check_field_offset(lv, v3, 5, "I_BFu7c_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu7c_B(Test_I_BFu7c_B, "I_BFu7c_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu7i_B()
{
  {
    init_simple_test("I_BFu7i_B");
    static I_BFu7i_B lv;
    check2(sizeof(lv), 6, "sizeof(I_BFu7i_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu7i_B)");
    check_field_offset(lv, v1, 0, "I_BFu7i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "I_BFu7i_B");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "I_BFu7i_B");
    check_field_offset(lv, v3, 5, "I_BFu7i_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu7i_B(Test_I_BFu7i_B, "I_BFu7i_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu7ll_B()
{
  {
    init_simple_test("I_BFu7ll_B");
    static I_BFu7ll_B lv;
    check2(sizeof(lv), 6, "sizeof(I_BFu7ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu7ll_B)");
    check_field_offset(lv, v1, 0, "I_BFu7ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "I_BFu7ll_B");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "I_BFu7ll_B");
    check_field_offset(lv, v3, 5, "I_BFu7ll_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu7ll_B(Test_I_BFu7ll_B, "I_BFu7ll_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu7s_B()
{
  {
    init_simple_test("I_BFu7s_B");
    static I_BFu7s_B lv;
    check2(sizeof(lv), 6, "sizeof(I_BFu7s_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu7s_B)");
    check_field_offset(lv, v1, 0, "I_BFu7s_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "I_BFu7s_B");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "I_BFu7s_B");
    check_field_offset(lv, v3, 5, "I_BFu7s_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu7s_B(Test_I_BFu7s_B, "I_BFu7s_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu8c_B()
{
  {
    init_simple_test("I_BFu8c_B");
    static I_BFu8c_B lv;
    check2(sizeof(lv), 6, "sizeof(I_BFu8c_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu8c_B)");
    check_field_offset(lv, v1, 0, "I_BFu8c_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "I_BFu8c_B");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "I_BFu8c_B");
    check_field_offset(lv, v3, 5, "I_BFu8c_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu8c_B(Test_I_BFu8c_B, "I_BFu8c_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu8i_B()
{
  {
    init_simple_test("I_BFu8i_B");
    static I_BFu8i_B lv;
    check2(sizeof(lv), 6, "sizeof(I_BFu8i_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu8i_B)");
    check_field_offset(lv, v1, 0, "I_BFu8i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "I_BFu8i_B");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "I_BFu8i_B");
    check_field_offset(lv, v3, 5, "I_BFu8i_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu8i_B(Test_I_BFu8i_B, "I_BFu8i_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu8ll_B()
{
  {
    init_simple_test("I_BFu8ll_B");
    static I_BFu8ll_B lv;
    check2(sizeof(lv), 6, "sizeof(I_BFu8ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu8ll_B)");
    check_field_offset(lv, v1, 0, "I_BFu8ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "I_BFu8ll_B");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "I_BFu8ll_B");
    check_field_offset(lv, v3, 5, "I_BFu8ll_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu8ll_B(Test_I_BFu8ll_B, "I_BFu8ll_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu8s_B()
{
  {
    init_simple_test("I_BFu8s_B");
    static I_BFu8s_B lv;
    check2(sizeof(lv), 6, "sizeof(I_BFu8s_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu8s_B)");
    check_field_offset(lv, v1, 0, "I_BFu8s_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "I_BFu8s_B");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "I_BFu8s_B");
    check_field_offset(lv, v3, 5, "I_BFu8s_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu8s_B(Test_I_BFu8s_B, "I_BFu8s_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu9i_B()
{
  {
    init_simple_test("I_BFu9i_B");
    static I_BFu9i_B lv;
    check2(sizeof(lv), 7, "sizeof(I_BFu9i_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu9i_B)");
    check_field_offset(lv, v1, 0, "I_BFu9i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "I_BFu9i_B");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "I_BFu9i_B");
    check_field_offset(lv, v3, 6, "I_BFu9i_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu9i_B(Test_I_BFu9i_B, "I_BFu9i_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu9ll_B()
{
  {
    init_simple_test("I_BFu9ll_B");
    static I_BFu9ll_B lv;
    check2(sizeof(lv), 7, "sizeof(I_BFu9ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu9ll_B)");
    check_field_offset(lv, v1, 0, "I_BFu9ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "I_BFu9ll_B");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "I_BFu9ll_B");
    check_field_offset(lv, v3, 6, "I_BFu9ll_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu9ll_B(Test_I_BFu9ll_B, "I_BFu9ll_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_BFu9s_B()
{
  {
    init_simple_test("I_BFu9s_B");
    static I_BFu9s_B lv;
    check2(sizeof(lv), 7, "sizeof(I_BFu9s_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_BFu9s_B)");
    check_field_offset(lv, v1, 0, "I_BFu9s_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "I_BFu9s_B");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "I_BFu9s_B");
    check_field_offset(lv, v3, 6, "I_BFu9s_B.v3");
  }
}
static Arrange_To_Call_Me vI_BFu9s_B(Test_I_BFu9s_B, "I_BFu9s_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_C_B()
{
  {
    init_simple_test("I_C_B");
    I_C_B lv;
    check2(sizeof(lv), 6, "sizeof(I_C_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_C_B)");
    check_field_offset(lv, v1, 0, "I_C_B.v1");
    check_field_offset(lv, v2, 4, "I_C_B.v2");
    check_field_offset(lv, v3, 5, "I_C_B.v3");
  }
}
static Arrange_To_Call_Me vI_C_B(Test_I_C_B, "I_C_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_D_B()
{
  {
    init_simple_test("I_D_B");
    I_D_B lv;
    check2(sizeof(lv), 13, "sizeof(I_D_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_D_B)");
    check_field_offset(lv, v1, 0, "I_D_B.v1");
    check_field_offset(lv, v2, 4, "I_D_B.v2");
    check_field_offset(lv, v3, 12, "I_D_B.v3");
  }
}
static Arrange_To_Call_Me vI_D_B(Test_I_D_B, "I_D_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_F_B()
{
  {
    init_simple_test("I_F_B");
    I_F_B lv;
    check2(sizeof(lv), 9, "sizeof(I_F_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_F_B)");
    check_field_offset(lv, v1, 0, "I_F_B.v1");
    check_field_offset(lv, v2, 4, "I_F_B.v2");
    check_field_offset(lv, v3, 8, "I_F_B.v3");
  }
}
static Arrange_To_Call_Me vI_F_B(Test_I_F_B, "I_F_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_I_B()
{
  {
    init_simple_test("I_I_B");
    I_I_B lv;
    check2(sizeof(lv), 9, "sizeof(I_I_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_I_B)");
    check_field_offset(lv, v1, 0, "I_I_B.v1");
    check_field_offset(lv, v2, 4, "I_I_B.v2");
    check_field_offset(lv, v3, 8, "I_I_B.v3");
  }
}
static Arrange_To_Call_Me vI_I_B(Test_I_I_B, "I_I_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_Ip_B()
{
  {
    init_simple_test("I_Ip_B");
    I_Ip_B lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(I_Ip_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_Ip_B)");
    check_field_offset(lv, v1, 0, "I_Ip_B.v1");
    check_field_offset(lv, v2, 4, "I_Ip_B.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "I_Ip_B.v3");
  }
}
static Arrange_To_Call_Me vI_Ip_B(Test_I_Ip_B, "I_Ip_B", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_L_B()
{
  {
    init_simple_test("I_L_B");
    I_L_B lv;
    check2(sizeof(lv), 13, "sizeof(I_L_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_L_B)");
    check_field_offset(lv, v1, 0, "I_L_B.v1");
    check_field_offset(lv, v2, 4, "I_L_B.v2");
    check_field_offset(lv, v3, 12, "I_L_B.v3");
  }
}
static Arrange_To_Call_Me vI_L_B(Test_I_L_B, "I_L_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_S_B()
{
  {
    init_simple_test("I_S_B");
    I_S_B lv;
    check2(sizeof(lv), 7, "sizeof(I_S_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_S_B)");
    check_field_offset(lv, v1, 0, "I_S_B.v1");
    check_field_offset(lv, v2, 4, "I_S_B.v2");
    check_field_offset(lv, v3, 6, "I_S_B.v3");
  }
}
static Arrange_To_Call_Me vI_S_B(Test_I_S_B, "I_S_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_Uc_B()
{
  {
    init_simple_test("I_Uc_B");
    I_Uc_B lv;
    check2(sizeof(lv), 6, "sizeof(I_Uc_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_Uc_B)");
    check_field_offset(lv, v1, 0, "I_Uc_B.v1");
    check_field_offset(lv, v2, 4, "I_Uc_B.v2");
    check_field_offset(lv, v3, 5, "I_Uc_B.v3");
  }
}
static Arrange_To_Call_Me vI_Uc_B(Test_I_Uc_B, "I_Uc_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_Ui_B()
{
  {
    init_simple_test("I_Ui_B");
    I_Ui_B lv;
    check2(sizeof(lv), 9, "sizeof(I_Ui_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_Ui_B)");
    check_field_offset(lv, v1, 0, "I_Ui_B.v1");
    check_field_offset(lv, v2, 4, "I_Ui_B.v2");
    check_field_offset(lv, v3, 8, "I_Ui_B.v3");
  }
}
static Arrange_To_Call_Me vI_Ui_B(Test_I_Ui_B, "I_Ui_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_Ul_B()
{
  {
    init_simple_test("I_Ul_B");
    I_Ul_B lv;
    check2(sizeof(lv), 13, "sizeof(I_Ul_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_Ul_B)");
    check_field_offset(lv, v1, 0, "I_Ul_B.v1");
    check_field_offset(lv, v2, 4, "I_Ul_B.v2");
    check_field_offset(lv, v3, 12, "I_Ul_B.v3");
  }
}
static Arrange_To_Call_Me vI_Ul_B(Test_I_Ul_B, "I_Ul_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_Us_B()
{
  {
    init_simple_test("I_Us_B");
    I_Us_B lv;
    check2(sizeof(lv), 7, "sizeof(I_Us_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_Us_B)");
    check_field_offset(lv, v1, 0, "I_Us_B.v1");
    check_field_offset(lv, v2, 4, "I_Us_B.v2");
    check_field_offset(lv, v3, 6, "I_Us_B.v3");
  }
}
static Arrange_To_Call_Me vI_Us_B(Test_I_Us_B, "I_Us_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_I_Vp_B()
{
  {
    init_simple_test("I_Vp_B");
    I_Vp_B lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(I_Vp_B)");
    check2(__alignof__(lv), 1, "__alignof__(I_Vp_B)");
    check_field_offset(lv, v1, 0, "I_Vp_B.v1");
    check_field_offset(lv, v2, 4, "I_Vp_B.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "I_Vp_B.v3");
  }
}
static Arrange_To_Call_Me vI_Vp_B(Test_I_Vp_B, "I_Vp_B", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B()
{
  {
    init_simple_test("Ip_B");
    Ip_B lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Ip_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B)");
    check_field_offset(lv, v1, 0, "Ip_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B.v2");
  }
}
static Arrange_To_Call_Me vIp_B(Test_Ip_B, "Ip_B", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_B()
{
  {
    init_simple_test("Ip_B_B");
    Ip_B_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_B_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_B)");
    check_field_offset(lv, v1, 0, "Ip_B_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_B.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_B_B.v3");
  }
}
static Arrange_To_Call_Me vIp_B_B(Test_Ip_B_B, "Ip_B_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu15i()
{
  {
    init_simple_test("Ip_B_BFu15i");
    static Ip_B_BFu15i lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_B_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu15i)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu15i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu15i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, 1, "Ip_B_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, hide_ull(1LL<<14), "Ip_B_BFu15i");
  }
}
static Arrange_To_Call_Me vIp_B_BFu15i(Test_Ip_B_BFu15i, "Ip_B_BFu15i", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu15ll()
{
  {
    init_simple_test("Ip_B_BFu15ll");
    static Ip_B_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_B_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu15ll)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu15ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu15ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, 1, "Ip_B_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, hide_ull(1LL<<14), "Ip_B_BFu15ll");
  }
}
static Arrange_To_Call_Me vIp_B_BFu15ll(Test_Ip_B_BFu15ll, "Ip_B_BFu15ll", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu15s()
{
  {
    init_simple_test("Ip_B_BFu15s");
    static Ip_B_BFu15s lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_B_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu15s)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu15s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu15s.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, 1, "Ip_B_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, hide_ull(1LL<<14), "Ip_B_BFu15s");
  }
}
static Arrange_To_Call_Me vIp_B_BFu15s(Test_Ip_B_BFu15s, "Ip_B_BFu15s", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu16i()
{
  {
    init_simple_test("Ip_B_BFu16i");
    static Ip_B_BFu16i lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_B_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu16i)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu16i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu16i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, 1, "Ip_B_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, hide_ull(1LL<<15), "Ip_B_BFu16i");
  }
}
static Arrange_To_Call_Me vIp_B_BFu16i(Test_Ip_B_BFu16i, "Ip_B_BFu16i", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu16ll()
{
  {
    init_simple_test("Ip_B_BFu16ll");
    static Ip_B_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_B_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu16ll)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu16ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu16ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, 1, "Ip_B_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, hide_ull(1LL<<15), "Ip_B_BFu16ll");
  }
}
static Arrange_To_Call_Me vIp_B_BFu16ll(Test_Ip_B_BFu16ll, "Ip_B_BFu16ll", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu16s()
{
  {
    init_simple_test("Ip_B_BFu16s");
    static Ip_B_BFu16s lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_B_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu16s)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu16s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu16s.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, 1, "Ip_B_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, hide_ull(1LL<<15), "Ip_B_BFu16s");
  }
}
static Arrange_To_Call_Me vIp_B_BFu16s(Test_Ip_B_BFu16s, "Ip_B_BFu16s", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu17i()
{
  {
    init_simple_test("Ip_B_BFu17i");
    static Ip_B_BFu17i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ip_B_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu17i)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu17i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu17i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, 1, "Ip_B_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, hide_ull(1LL<<16), "Ip_B_BFu17i");
  }
}
static Arrange_To_Call_Me vIp_B_BFu17i(Test_Ip_B_BFu17i, "Ip_B_BFu17i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu17ll()
{
  {
    init_simple_test("Ip_B_BFu17ll");
    static Ip_B_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ip_B_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu17ll)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu17ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu17ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, 1, "Ip_B_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, hide_ull(1LL<<16), "Ip_B_BFu17ll");
  }
}
static Arrange_To_Call_Me vIp_B_BFu17ll(Test_Ip_B_BFu17ll, "Ip_B_BFu17ll", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu1c()
{
  {
    init_simple_test("Ip_B_BFu1c");
    static Ip_B_BFu1c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_B_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu1c)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu1c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu1c.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Ip_B_BFu1c");
  }
}
static Arrange_To_Call_Me vIp_B_BFu1c(Test_Ip_B_BFu1c, "Ip_B_BFu1c", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu1i()
{
  {
    init_simple_test("Ip_B_BFu1i");
    static Ip_B_BFu1i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_B_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu1i)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu1i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu1i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Ip_B_BFu1i");
  }
}
static Arrange_To_Call_Me vIp_B_BFu1i(Test_Ip_B_BFu1i, "Ip_B_BFu1i", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu1ll()
{
  {
    init_simple_test("Ip_B_BFu1ll");
    static Ip_B_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_B_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu1ll)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu1ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu1ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Ip_B_BFu1ll");
  }
}
static Arrange_To_Call_Me vIp_B_BFu1ll(Test_Ip_B_BFu1ll, "Ip_B_BFu1ll", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu1s()
{
  {
    init_simple_test("Ip_B_BFu1s");
    static Ip_B_BFu1s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_B_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu1s)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu1s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu1s.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Ip_B_BFu1s");
  }
}
static Arrange_To_Call_Me vIp_B_BFu1s(Test_Ip_B_BFu1s, "Ip_B_BFu1s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu31i()
{
  {
    init_simple_test("Ip_B_BFu31i");
    static Ip_B_BFu31i lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Ip_B_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu31i)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu31i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu31i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 31, 1, "Ip_B_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 31, hide_ull(1LL<<30), "Ip_B_BFu31i");
  }
}
static Arrange_To_Call_Me vIp_B_BFu31i(Test_Ip_B_BFu31i, "Ip_B_BFu31i", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu31ll()
{
  {
    init_simple_test("Ip_B_BFu31ll");
    static Ip_B_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Ip_B_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu31ll)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu31ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu31ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 31, 1, "Ip_B_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 31, hide_ull(1LL<<30), "Ip_B_BFu31ll");
  }
}
static Arrange_To_Call_Me vIp_B_BFu31ll(Test_Ip_B_BFu31ll, "Ip_B_BFu31ll", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu32i()
{
  {
    init_simple_test("Ip_B_BFu32i");
    static Ip_B_BFu32i lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Ip_B_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu32i)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu32i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu32i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 32, 1, "Ip_B_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 32, hide_ull(1LL<<31), "Ip_B_BFu32i");
  }
}
static Arrange_To_Call_Me vIp_B_BFu32i(Test_Ip_B_BFu32i, "Ip_B_BFu32i", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu32ll()
{
  {
    init_simple_test("Ip_B_BFu32ll");
    static Ip_B_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Ip_B_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu32ll)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu32ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu32ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 32, 1, "Ip_B_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 32, hide_ull(1LL<<31), "Ip_B_BFu32ll");
  }
}
static Arrange_To_Call_Me vIp_B_BFu32ll(Test_Ip_B_BFu32ll, "Ip_B_BFu32ll", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu33()
{
  {
    init_simple_test("Ip_B_BFu33");
    static Ip_B_BFu33 lv;
    check2(sizeof(lv), ABISELECT(14,10), "sizeof(Ip_B_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu33)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu33.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu33.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 33, 1, "Ip_B_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 33, hide_ull(1LL<<32), "Ip_B_BFu33");
  }
}
static Arrange_To_Call_Me vIp_B_BFu33(Test_Ip_B_BFu33, "Ip_B_BFu33", ABISELECT(14,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu7c()
{
  {
    init_simple_test("Ip_B_BFu7c");
    static Ip_B_BFu7c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_B_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu7c)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu7c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu7c.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Ip_B_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Ip_B_BFu7c");
  }
}
static Arrange_To_Call_Me vIp_B_BFu7c(Test_Ip_B_BFu7c, "Ip_B_BFu7c", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu7i()
{
  {
    init_simple_test("Ip_B_BFu7i");
    static Ip_B_BFu7i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_B_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu7i)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu7i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu7i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Ip_B_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Ip_B_BFu7i");
  }
}
static Arrange_To_Call_Me vIp_B_BFu7i(Test_Ip_B_BFu7i, "Ip_B_BFu7i", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu7ll()
{
  {
    init_simple_test("Ip_B_BFu7ll");
    static Ip_B_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_B_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu7ll)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu7ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu7ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Ip_B_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Ip_B_BFu7ll");
  }
}
static Arrange_To_Call_Me vIp_B_BFu7ll(Test_Ip_B_BFu7ll, "Ip_B_BFu7ll", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu7s()
{
  {
    init_simple_test("Ip_B_BFu7s");
    static Ip_B_BFu7s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_B_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu7s)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu7s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu7s.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Ip_B_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Ip_B_BFu7s");
  }
}
static Arrange_To_Call_Me vIp_B_BFu7s(Test_Ip_B_BFu7s, "Ip_B_BFu7s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu8c()
{
  {
    init_simple_test("Ip_B_BFu8c");
    static Ip_B_BFu8c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_B_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu8c)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu8c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu8c.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Ip_B_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Ip_B_BFu8c");
  }
}
static Arrange_To_Call_Me vIp_B_BFu8c(Test_Ip_B_BFu8c, "Ip_B_BFu8c", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu8i()
{
  {
    init_simple_test("Ip_B_BFu8i");
    static Ip_B_BFu8i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_B_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu8i)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu8i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu8i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Ip_B_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Ip_B_BFu8i");
  }
}
static Arrange_To_Call_Me vIp_B_BFu8i(Test_Ip_B_BFu8i, "Ip_B_BFu8i", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu8ll()
{
  {
    init_simple_test("Ip_B_BFu8ll");
    static Ip_B_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_B_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu8ll)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu8ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu8ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Ip_B_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Ip_B_BFu8ll");
  }
}
static Arrange_To_Call_Me vIp_B_BFu8ll(Test_Ip_B_BFu8ll, "Ip_B_BFu8ll", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu8s()
{
  {
    init_simple_test("Ip_B_BFu8s");
    static Ip_B_BFu8s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_B_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu8s)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu8s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu8s.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Ip_B_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Ip_B_BFu8s");
  }
}
static Arrange_To_Call_Me vIp_B_BFu8s(Test_Ip_B_BFu8s, "Ip_B_BFu8s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu9i()
{
  {
    init_simple_test("Ip_B_BFu9i");
    static Ip_B_BFu9i lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_B_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu9i)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu9i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu9i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, 1, "Ip_B_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, hide_ull(1LL<<8), "Ip_B_BFu9i");
  }
}
static Arrange_To_Call_Me vIp_B_BFu9i(Test_Ip_B_BFu9i, "Ip_B_BFu9i", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu9ll()
{
  {
    init_simple_test("Ip_B_BFu9ll");
    static Ip_B_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_B_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu9ll)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu9ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu9ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, 1, "Ip_B_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, hide_ull(1LL<<8), "Ip_B_BFu9ll");
  }
}
static Arrange_To_Call_Me vIp_B_BFu9ll(Test_Ip_B_BFu9ll, "Ip_B_BFu9ll", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_BFu9s()
{
  {
    init_simple_test("Ip_B_BFu9s");
    static Ip_B_BFu9s lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_B_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_BFu9s)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu9s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu9s.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, 1, "Ip_B_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, hide_ull(1LL<<8), "Ip_B_BFu9s");
  }
}
static Arrange_To_Call_Me vIp_B_BFu9s(Test_Ip_B_BFu9s, "Ip_B_BFu9s", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_C()
{
  {
    init_simple_test("Ip_B_C");
    Ip_B_C lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_B_C)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_C)");
    check_field_offset(lv, v1, 0, "Ip_B_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_C.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_B_C.v3");
  }
}
static Arrange_To_Call_Me vIp_B_C(Test_Ip_B_C, "Ip_B_C", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_D()
{
  {
    init_simple_test("Ip_B_D");
    Ip_B_D lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(Ip_B_D)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_D)");
    check_field_offset(lv, v1, 0, "Ip_B_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_D.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_B_D.v3");
  }
}
static Arrange_To_Call_Me vIp_B_D(Test_Ip_B_D, "Ip_B_D", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_F()
{
  {
    init_simple_test("Ip_B_F");
    Ip_B_F lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Ip_B_F)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_F)");
    check_field_offset(lv, v1, 0, "Ip_B_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_F.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_B_F.v3");
  }
}
static Arrange_To_Call_Me vIp_B_F(Test_Ip_B_F, "Ip_B_F", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_I()
{
  {
    init_simple_test("Ip_B_I");
    Ip_B_I lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Ip_B_I)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_I)");
    check_field_offset(lv, v1, 0, "Ip_B_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_I.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_B_I.v3");
  }
}
static Arrange_To_Call_Me vIp_B_I(Test_Ip_B_I, "Ip_B_I", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_Ip()
{
  {
    init_simple_test("Ip_B_Ip");
    Ip_B_Ip lv;
    check2(sizeof(lv), ABISELECT(17,9), "sizeof(Ip_B_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_Ip)");
    check_field_offset(lv, v1, 0, "Ip_B_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_Ip.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_B_Ip.v3");
  }
}
static Arrange_To_Call_Me vIp_B_Ip(Test_Ip_B_Ip, "Ip_B_Ip", ABISELECT(17,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_L()
{
  {
    init_simple_test("Ip_B_L");
    Ip_B_L lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(Ip_B_L)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_L)");
    check_field_offset(lv, v1, 0, "Ip_B_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_L.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_B_L.v3");
  }
}
static Arrange_To_Call_Me vIp_B_L(Test_Ip_B_L, "Ip_B_L", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_S()
{
  {
    init_simple_test("Ip_B_S");
    Ip_B_S lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_B_S)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_S)");
    check_field_offset(lv, v1, 0, "Ip_B_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_S.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_B_S.v3");
  }
}
static Arrange_To_Call_Me vIp_B_S(Test_Ip_B_S, "Ip_B_S", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_Uc()
{
  {
    init_simple_test("Ip_B_Uc");
    Ip_B_Uc lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_B_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_Uc)");
    check_field_offset(lv, v1, 0, "Ip_B_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_Uc.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_B_Uc.v3");
  }
}
static Arrange_To_Call_Me vIp_B_Uc(Test_Ip_B_Uc, "Ip_B_Uc", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_Ui()
{
  {
    init_simple_test("Ip_B_Ui");
    Ip_B_Ui lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Ip_B_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_Ui)");
    check_field_offset(lv, v1, 0, "Ip_B_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_Ui.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_B_Ui.v3");
  }
}
static Arrange_To_Call_Me vIp_B_Ui(Test_Ip_B_Ui, "Ip_B_Ui", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_Ul()
{
  {
    init_simple_test("Ip_B_Ul");
    Ip_B_Ul lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(Ip_B_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_Ul)");
    check_field_offset(lv, v1, 0, "Ip_B_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_Ul.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_B_Ul.v3");
  }
}
static Arrange_To_Call_Me vIp_B_Ul(Test_Ip_B_Ul, "Ip_B_Ul", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_Us()
{
  {
    init_simple_test("Ip_B_Us");
    Ip_B_Us lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_B_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_Us)");
    check_field_offset(lv, v1, 0, "Ip_B_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_Us.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_B_Us.v3");
  }
}
static Arrange_To_Call_Me vIp_B_Us(Test_Ip_B_Us, "Ip_B_Us", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_B_Vp()
{
  {
    init_simple_test("Ip_B_Vp");
    Ip_B_Vp lv;
    check2(sizeof(lv), ABISELECT(17,9), "sizeof(Ip_B_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_B_Vp)");
    check_field_offset(lv, v1, 0, "Ip_B_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_Vp.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_B_Vp.v3");
  }
}
static Arrange_To_Call_Me vIp_B_Vp(Test_Ip_B_Vp, "Ip_B_Vp", ABISELECT(17,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu15i_B()
{
  {
    init_simple_test("Ip_BFu15i_B");
    static Ip_BFu15i_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_BFu15i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu15i_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu15i_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Ip_BFu15i_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Ip_BFu15i_B");
    check_field_offset(lv, v3, ABISELECT(10,6), "Ip_BFu15i_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu15i_B(Test_Ip_BFu15i_B, "Ip_BFu15i_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu15ll_B()
{
  {
    init_simple_test("Ip_BFu15ll_B");
    static Ip_BFu15ll_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_BFu15ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu15ll_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu15ll_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Ip_BFu15ll_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Ip_BFu15ll_B");
    check_field_offset(lv, v3, ABISELECT(10,6), "Ip_BFu15ll_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu15ll_B(Test_Ip_BFu15ll_B, "Ip_BFu15ll_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu15s_B()
{
  {
    init_simple_test("Ip_BFu15s_B");
    static Ip_BFu15s_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_BFu15s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu15s_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu15s_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Ip_BFu15s_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Ip_BFu15s_B");
    check_field_offset(lv, v3, ABISELECT(10,6), "Ip_BFu15s_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu15s_B(Test_Ip_BFu15s_B, "Ip_BFu15s_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu16i_B()
{
  {
    init_simple_test("Ip_BFu16i_B");
    static Ip_BFu16i_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_BFu16i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu16i_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu16i_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Ip_BFu16i_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Ip_BFu16i_B");
    check_field_offset(lv, v3, ABISELECT(10,6), "Ip_BFu16i_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu16i_B(Test_Ip_BFu16i_B, "Ip_BFu16i_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu16ll_B()
{
  {
    init_simple_test("Ip_BFu16ll_B");
    static Ip_BFu16ll_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_BFu16ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu16ll_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu16ll_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Ip_BFu16ll_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Ip_BFu16ll_B");
    check_field_offset(lv, v3, ABISELECT(10,6), "Ip_BFu16ll_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu16ll_B(Test_Ip_BFu16ll_B, "Ip_BFu16ll_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu16s_B()
{
  {
    init_simple_test("Ip_BFu16s_B");
    static Ip_BFu16s_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_BFu16s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu16s_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu16s_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Ip_BFu16s_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Ip_BFu16s_B");
    check_field_offset(lv, v3, ABISELECT(10,6), "Ip_BFu16s_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu16s_B(Test_Ip_BFu16s_B, "Ip_BFu16s_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu17i_B()
{
  {
    init_simple_test("Ip_BFu17i_B");
    static Ip_BFu17i_B lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ip_BFu17i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu17i_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu17i_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Ip_BFu17i_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Ip_BFu17i_B");
    check_field_offset(lv, v3, ABISELECT(11,7), "Ip_BFu17i_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu17i_B(Test_Ip_BFu17i_B, "Ip_BFu17i_B", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu17ll_B()
{
  {
    init_simple_test("Ip_BFu17ll_B");
    static Ip_BFu17ll_B lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ip_BFu17ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu17ll_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu17ll_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Ip_BFu17ll_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Ip_BFu17ll_B");
    check_field_offset(lv, v3, ABISELECT(11,7), "Ip_BFu17ll_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu17ll_B(Test_Ip_BFu17ll_B, "Ip_BFu17ll_B", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu1c_B()
{
  {
    init_simple_test("Ip_BFu1c_B");
    static Ip_BFu1c_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_BFu1c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu1c_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu1c_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Ip_BFu1c_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_BFu1c_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu1c_B(Test_Ip_BFu1c_B, "Ip_BFu1c_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu1i_B()
{
  {
    init_simple_test("Ip_BFu1i_B");
    static Ip_BFu1i_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_BFu1i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu1i_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu1i_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Ip_BFu1i_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_BFu1i_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu1i_B(Test_Ip_BFu1i_B, "Ip_BFu1i_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu1ll_B()
{
  {
    init_simple_test("Ip_BFu1ll_B");
    static Ip_BFu1ll_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_BFu1ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu1ll_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu1ll_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Ip_BFu1ll_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_BFu1ll_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu1ll_B(Test_Ip_BFu1ll_B, "Ip_BFu1ll_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu1s_B()
{
  {
    init_simple_test("Ip_BFu1s_B");
    static Ip_BFu1s_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_BFu1s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu1s_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu1s_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Ip_BFu1s_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_BFu1s_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu1s_B(Test_Ip_BFu1s_B, "Ip_BFu1s_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu31i_B()
{
  {
    init_simple_test("Ip_BFu31i_B");
    static Ip_BFu31i_B lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Ip_BFu31i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu31i_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu31i_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Ip_BFu31i_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Ip_BFu31i_B");
    check_field_offset(lv, v3, ABISELECT(12,8), "Ip_BFu31i_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu31i_B(Test_Ip_BFu31i_B, "Ip_BFu31i_B", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu31ll_B()
{
  {
    init_simple_test("Ip_BFu31ll_B");
    static Ip_BFu31ll_B lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Ip_BFu31ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu31ll_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu31ll_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Ip_BFu31ll_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Ip_BFu31ll_B");
    check_field_offset(lv, v3, ABISELECT(12,8), "Ip_BFu31ll_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu31ll_B(Test_Ip_BFu31ll_B, "Ip_BFu31ll_B", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu32i_B()
{
  {
    init_simple_test("Ip_BFu32i_B");
    static Ip_BFu32i_B lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Ip_BFu32i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu32i_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu32i_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Ip_BFu32i_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Ip_BFu32i_B");
    check_field_offset(lv, v3, ABISELECT(12,8), "Ip_BFu32i_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu32i_B(Test_Ip_BFu32i_B, "Ip_BFu32i_B", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu32ll_B()
{
  {
    init_simple_test("Ip_BFu32ll_B");
    static Ip_BFu32ll_B lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Ip_BFu32ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu32ll_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu32ll_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Ip_BFu32ll_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Ip_BFu32ll_B");
    check_field_offset(lv, v3, ABISELECT(12,8), "Ip_BFu32ll_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu32ll_B(Test_Ip_BFu32ll_B, "Ip_BFu32ll_B", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu33_B()
{
  {
    init_simple_test("Ip_BFu33_B");
    static Ip_BFu33_B lv;
    check2(sizeof(lv), ABISELECT(14,10), "sizeof(Ip_BFu33_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu33_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu33_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Ip_BFu33_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Ip_BFu33_B");
    check_field_offset(lv, v3, ABISELECT(13,9), "Ip_BFu33_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu33_B(Test_Ip_BFu33_B, "Ip_BFu33_B", ABISELECT(14,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu7c_B()
{
  {
    init_simple_test("Ip_BFu7c_B");
    static Ip_BFu7c_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_BFu7c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu7c_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu7c_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Ip_BFu7c_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Ip_BFu7c_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_BFu7c_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu7c_B(Test_Ip_BFu7c_B, "Ip_BFu7c_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu7i_B()
{
  {
    init_simple_test("Ip_BFu7i_B");
    static Ip_BFu7i_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_BFu7i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu7i_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu7i_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Ip_BFu7i_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Ip_BFu7i_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_BFu7i_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu7i_B(Test_Ip_BFu7i_B, "Ip_BFu7i_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu7ll_B()
{
  {
    init_simple_test("Ip_BFu7ll_B");
    static Ip_BFu7ll_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_BFu7ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu7ll_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu7ll_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Ip_BFu7ll_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Ip_BFu7ll_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_BFu7ll_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu7ll_B(Test_Ip_BFu7ll_B, "Ip_BFu7ll_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu7s_B()
{
  {
    init_simple_test("Ip_BFu7s_B");
    static Ip_BFu7s_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_BFu7s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu7s_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu7s_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Ip_BFu7s_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Ip_BFu7s_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_BFu7s_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu7s_B(Test_Ip_BFu7s_B, "Ip_BFu7s_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu8c_B()
{
  {
    init_simple_test("Ip_BFu8c_B");
    static Ip_BFu8c_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_BFu8c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu8c_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu8c_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Ip_BFu8c_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Ip_BFu8c_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_BFu8c_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu8c_B(Test_Ip_BFu8c_B, "Ip_BFu8c_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu8i_B()
{
  {
    init_simple_test("Ip_BFu8i_B");
    static Ip_BFu8i_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_BFu8i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu8i_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu8i_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Ip_BFu8i_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Ip_BFu8i_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_BFu8i_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu8i_B(Test_Ip_BFu8i_B, "Ip_BFu8i_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu8ll_B()
{
  {
    init_simple_test("Ip_BFu8ll_B");
    static Ip_BFu8ll_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_BFu8ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu8ll_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu8ll_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Ip_BFu8ll_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Ip_BFu8ll_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_BFu8ll_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu8ll_B(Test_Ip_BFu8ll_B, "Ip_BFu8ll_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu8s_B()
{
  {
    init_simple_test("Ip_BFu8s_B");
    static Ip_BFu8s_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_BFu8s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu8s_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu8s_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Ip_BFu8s_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Ip_BFu8s_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_BFu8s_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu8s_B(Test_Ip_BFu8s_B, "Ip_BFu8s_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu9i_B()
{
  {
    init_simple_test("Ip_BFu9i_B");
    static Ip_BFu9i_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_BFu9i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu9i_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu9i_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Ip_BFu9i_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Ip_BFu9i_B");
    check_field_offset(lv, v3, ABISELECT(10,6), "Ip_BFu9i_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu9i_B(Test_Ip_BFu9i_B, "Ip_BFu9i_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu9ll_B()
{
  {
    init_simple_test("Ip_BFu9ll_B");
    static Ip_BFu9ll_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_BFu9ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu9ll_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu9ll_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Ip_BFu9ll_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Ip_BFu9ll_B");
    check_field_offset(lv, v3, ABISELECT(10,6), "Ip_BFu9ll_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu9ll_B(Test_Ip_BFu9ll_B, "Ip_BFu9ll_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_BFu9s_B()
{
  {
    init_simple_test("Ip_BFu9s_B");
    static Ip_BFu9s_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_BFu9s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_BFu9s_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu9s_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Ip_BFu9s_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Ip_BFu9s_B");
    check_field_offset(lv, v3, ABISELECT(10,6), "Ip_BFu9s_B.v3");
  }
}
static Arrange_To_Call_Me vIp_BFu9s_B(Test_Ip_BFu9s_B, "Ip_BFu9s_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_C_B()
{
  {
    init_simple_test("Ip_C_B");
    Ip_C_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_C_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_C_B)");
    check_field_offset(lv, v1, 0, "Ip_C_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_C_B.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_C_B.v3");
  }
}
static Arrange_To_Call_Me vIp_C_B(Test_Ip_C_B, "Ip_C_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_D_B()
{
  {
    init_simple_test("Ip_D_B");
    Ip_D_B lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(Ip_D_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_D_B)");
    check_field_offset(lv, v1, 0, "Ip_D_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_D_B.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Ip_D_B.v3");
  }
}
static Arrange_To_Call_Me vIp_D_B(Test_Ip_D_B, "Ip_D_B", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_F_B()
{
  {
    init_simple_test("Ip_F_B");
    Ip_F_B lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Ip_F_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_F_B)");
    check_field_offset(lv, v1, 0, "Ip_F_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_F_B.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Ip_F_B.v3");
  }
}
static Arrange_To_Call_Me vIp_F_B(Test_Ip_F_B, "Ip_F_B", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_I_B()
{
  {
    init_simple_test("Ip_I_B");
    Ip_I_B lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Ip_I_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_I_B)");
    check_field_offset(lv, v1, 0, "Ip_I_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_I_B.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Ip_I_B.v3");
  }
}
static Arrange_To_Call_Me vIp_I_B(Test_Ip_I_B, "Ip_I_B", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_Ip_B()
{
  {
    init_simple_test("Ip_Ip_B");
    Ip_Ip_B lv;
    check2(sizeof(lv), ABISELECT(17,9), "sizeof(Ip_Ip_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_Ip_B)");
    check_field_offset(lv, v1, 0, "Ip_Ip_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_Ip_B.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Ip_Ip_B.v3");
  }
}
static Arrange_To_Call_Me vIp_Ip_B(Test_Ip_Ip_B, "Ip_Ip_B", ABISELECT(17,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_L_B()
{
  {
    init_simple_test("Ip_L_B");
    Ip_L_B lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(Ip_L_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_L_B)");
    check_field_offset(lv, v1, 0, "Ip_L_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_L_B.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Ip_L_B.v3");
  }
}
static Arrange_To_Call_Me vIp_L_B(Test_Ip_L_B, "Ip_L_B", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_S_B()
{
  {
    init_simple_test("Ip_S_B");
    Ip_S_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_S_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_S_B)");
    check_field_offset(lv, v1, 0, "Ip_S_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_S_B.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Ip_S_B.v3");
  }
}
static Arrange_To_Call_Me vIp_S_B(Test_Ip_S_B, "Ip_S_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_Uc_B()
{
  {
    init_simple_test("Ip_Uc_B");
    Ip_Uc_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ip_Uc_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_Uc_B)");
    check_field_offset(lv, v1, 0, "Ip_Uc_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_Uc_B.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_Uc_B.v3");
  }
}
static Arrange_To_Call_Me vIp_Uc_B(Test_Ip_Uc_B, "Ip_Uc_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_Ui_B()
{
  {
    init_simple_test("Ip_Ui_B");
    Ip_Ui_B lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Ip_Ui_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_Ui_B)");
    check_field_offset(lv, v1, 0, "Ip_Ui_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_Ui_B.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Ip_Ui_B.v3");
  }
}
static Arrange_To_Call_Me vIp_Ui_B(Test_Ip_Ui_B, "Ip_Ui_B", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_Ul_B()
{
  {
    init_simple_test("Ip_Ul_B");
    Ip_Ul_B lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(Ip_Ul_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_Ul_B)");
    check_field_offset(lv, v1, 0, "Ip_Ul_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_Ul_B.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Ip_Ul_B.v3");
  }
}
static Arrange_To_Call_Me vIp_Ul_B(Test_Ip_Ul_B, "Ip_Ul_B", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_Us_B()
{
  {
    init_simple_test("Ip_Us_B");
    Ip_Us_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Ip_Us_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_Us_B)");
    check_field_offset(lv, v1, 0, "Ip_Us_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_Us_B.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Ip_Us_B.v3");
  }
}
static Arrange_To_Call_Me vIp_Us_B(Test_Ip_Us_B, "Ip_Us_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ip_Vp_B()
{
  {
    init_simple_test("Ip_Vp_B");
    Ip_Vp_B lv;
    check2(sizeof(lv), ABISELECT(17,9), "sizeof(Ip_Vp_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ip_Vp_B)");
    check_field_offset(lv, v1, 0, "Ip_Vp_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_Vp_B.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Ip_Vp_B.v3");
  }
}
static Arrange_To_Call_Me vIp_Vp_B(Test_Ip_Vp_B, "Ip_Vp_B", ABISELECT(17,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B()
{
  {
    init_simple_test("L_B");
    L_B lv;
    check2(sizeof(lv), 9, "sizeof(L_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_B)");
    check_field_offset(lv, v1, 0, "L_B.v1");
    check_field_offset(lv, v2, 8, "L_B.v2");
  }
}
static Arrange_To_Call_Me vL_B(Test_L_B, "L_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_B()
{
  {
    init_simple_test("L_B_B");
    L_B_B lv;
    check2(sizeof(lv), 10, "sizeof(L_B_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_B)");
    check_field_offset(lv, v1, 0, "L_B_B.v1");
    check_field_offset(lv, v2, 8, "L_B_B.v2");
    check_field_offset(lv, v3, 9, "L_B_B.v3");
  }
}
static Arrange_To_Call_Me vL_B_B(Test_L_B_B, "L_B_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu15i()
{
  {
    init_simple_test("L_B_BFu15i");
    static L_B_BFu15i lv;
    check2(sizeof(lv), 11, "sizeof(L_B_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu15i)");
    check_field_offset(lv, v1, 0, "L_B_BFu15i.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu15i.v2");
    set_bf_and_test(lv, v3, 9, 0, 15, 1, "L_B_BFu15i");
    set_bf_and_test(lv, v3, 9, 0, 15, hide_ull(1LL<<14), "L_B_BFu15i");
  }
}
static Arrange_To_Call_Me vL_B_BFu15i(Test_L_B_BFu15i, "L_B_BFu15i", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu15ll()
{
  {
    init_simple_test("L_B_BFu15ll");
    static L_B_BFu15ll lv;
    check2(sizeof(lv), 11, "sizeof(L_B_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu15ll)");
    check_field_offset(lv, v1, 0, "L_B_BFu15ll.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu15ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 15, 1, "L_B_BFu15ll");
    set_bf_and_test(lv, v3, 9, 0, 15, hide_ull(1LL<<14), "L_B_BFu15ll");
  }
}
static Arrange_To_Call_Me vL_B_BFu15ll(Test_L_B_BFu15ll, "L_B_BFu15ll", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu15s()
{
  {
    init_simple_test("L_B_BFu15s");
    static L_B_BFu15s lv;
    check2(sizeof(lv), 11, "sizeof(L_B_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu15s)");
    check_field_offset(lv, v1, 0, "L_B_BFu15s.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu15s.v2");
    set_bf_and_test(lv, v3, 9, 0, 15, 1, "L_B_BFu15s");
    set_bf_and_test(lv, v3, 9, 0, 15, hide_ull(1LL<<14), "L_B_BFu15s");
  }
}
static Arrange_To_Call_Me vL_B_BFu15s(Test_L_B_BFu15s, "L_B_BFu15s", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu16i()
{
  {
    init_simple_test("L_B_BFu16i");
    static L_B_BFu16i lv;
    check2(sizeof(lv), 11, "sizeof(L_B_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu16i)");
    check_field_offset(lv, v1, 0, "L_B_BFu16i.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu16i.v2");
    set_bf_and_test(lv, v3, 9, 0, 16, 1, "L_B_BFu16i");
    set_bf_and_test(lv, v3, 9, 0, 16, hide_ull(1LL<<15), "L_B_BFu16i");
  }
}
static Arrange_To_Call_Me vL_B_BFu16i(Test_L_B_BFu16i, "L_B_BFu16i", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu16ll()
{
  {
    init_simple_test("L_B_BFu16ll");
    static L_B_BFu16ll lv;
    check2(sizeof(lv), 11, "sizeof(L_B_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu16ll)");
    check_field_offset(lv, v1, 0, "L_B_BFu16ll.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu16ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 16, 1, "L_B_BFu16ll");
    set_bf_and_test(lv, v3, 9, 0, 16, hide_ull(1LL<<15), "L_B_BFu16ll");
  }
}
static Arrange_To_Call_Me vL_B_BFu16ll(Test_L_B_BFu16ll, "L_B_BFu16ll", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu16s()
{
  {
    init_simple_test("L_B_BFu16s");
    static L_B_BFu16s lv;
    check2(sizeof(lv), 11, "sizeof(L_B_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu16s)");
    check_field_offset(lv, v1, 0, "L_B_BFu16s.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu16s.v2");
    set_bf_and_test(lv, v3, 9, 0, 16, 1, "L_B_BFu16s");
    set_bf_and_test(lv, v3, 9, 0, 16, hide_ull(1LL<<15), "L_B_BFu16s");
  }
}
static Arrange_To_Call_Me vL_B_BFu16s(Test_L_B_BFu16s, "L_B_BFu16s", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu17i()
{
  {
    init_simple_test("L_B_BFu17i");
    static L_B_BFu17i lv;
    check2(sizeof(lv), 12, "sizeof(L_B_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu17i)");
    check_field_offset(lv, v1, 0, "L_B_BFu17i.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu17i.v2");
    set_bf_and_test(lv, v3, 9, 0, 17, 1, "L_B_BFu17i");
    set_bf_and_test(lv, v3, 9, 0, 17, hide_ull(1LL<<16), "L_B_BFu17i");
  }
}
static Arrange_To_Call_Me vL_B_BFu17i(Test_L_B_BFu17i, "L_B_BFu17i", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu17ll()
{
  {
    init_simple_test("L_B_BFu17ll");
    static L_B_BFu17ll lv;
    check2(sizeof(lv), 12, "sizeof(L_B_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu17ll)");
    check_field_offset(lv, v1, 0, "L_B_BFu17ll.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu17ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 17, 1, "L_B_BFu17ll");
    set_bf_and_test(lv, v3, 9, 0, 17, hide_ull(1LL<<16), "L_B_BFu17ll");
  }
}
static Arrange_To_Call_Me vL_B_BFu17ll(Test_L_B_BFu17ll, "L_B_BFu17ll", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu1c()
{
  {
    init_simple_test("L_B_BFu1c");
    static L_B_BFu1c lv;
    check2(sizeof(lv), 10, "sizeof(L_B_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu1c)");
    check_field_offset(lv, v1, 0, "L_B_BFu1c.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu1c.v2");
    set_bf_and_test(lv, v3, 9, 0, 1, 1, "L_B_BFu1c");
  }
}
static Arrange_To_Call_Me vL_B_BFu1c(Test_L_B_BFu1c, "L_B_BFu1c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu1i()
{
  {
    init_simple_test("L_B_BFu1i");
    static L_B_BFu1i lv;
    check2(sizeof(lv), 10, "sizeof(L_B_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu1i)");
    check_field_offset(lv, v1, 0, "L_B_BFu1i.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu1i.v2");
    set_bf_and_test(lv, v3, 9, 0, 1, 1, "L_B_BFu1i");
  }
}
static Arrange_To_Call_Me vL_B_BFu1i(Test_L_B_BFu1i, "L_B_BFu1i", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu1ll()
{
  {
    init_simple_test("L_B_BFu1ll");
    static L_B_BFu1ll lv;
    check2(sizeof(lv), 10, "sizeof(L_B_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu1ll)");
    check_field_offset(lv, v1, 0, "L_B_BFu1ll.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu1ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 1, 1, "L_B_BFu1ll");
  }
}
static Arrange_To_Call_Me vL_B_BFu1ll(Test_L_B_BFu1ll, "L_B_BFu1ll", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu1s()
{
  {
    init_simple_test("L_B_BFu1s");
    static L_B_BFu1s lv;
    check2(sizeof(lv), 10, "sizeof(L_B_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu1s)");
    check_field_offset(lv, v1, 0, "L_B_BFu1s.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu1s.v2");
    set_bf_and_test(lv, v3, 9, 0, 1, 1, "L_B_BFu1s");
  }
}
static Arrange_To_Call_Me vL_B_BFu1s(Test_L_B_BFu1s, "L_B_BFu1s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu31i()
{
  {
    init_simple_test("L_B_BFu31i");
    static L_B_BFu31i lv;
    check2(sizeof(lv), 13, "sizeof(L_B_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu31i)");
    check_field_offset(lv, v1, 0, "L_B_BFu31i.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu31i.v2");
    set_bf_and_test(lv, v3, 9, 0, 31, 1, "L_B_BFu31i");
    set_bf_and_test(lv, v3, 9, 0, 31, hide_ull(1LL<<30), "L_B_BFu31i");
  }
}
static Arrange_To_Call_Me vL_B_BFu31i(Test_L_B_BFu31i, "L_B_BFu31i", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu31ll()
{
  {
    init_simple_test("L_B_BFu31ll");
    static L_B_BFu31ll lv;
    check2(sizeof(lv), 13, "sizeof(L_B_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu31ll)");
    check_field_offset(lv, v1, 0, "L_B_BFu31ll.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu31ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 31, 1, "L_B_BFu31ll");
    set_bf_and_test(lv, v3, 9, 0, 31, hide_ull(1LL<<30), "L_B_BFu31ll");
  }
}
static Arrange_To_Call_Me vL_B_BFu31ll(Test_L_B_BFu31ll, "L_B_BFu31ll", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu32i()
{
  {
    init_simple_test("L_B_BFu32i");
    static L_B_BFu32i lv;
    check2(sizeof(lv), 13, "sizeof(L_B_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu32i)");
    check_field_offset(lv, v1, 0, "L_B_BFu32i.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu32i.v2");
    set_bf_and_test(lv, v3, 9, 0, 32, 1, "L_B_BFu32i");
    set_bf_and_test(lv, v3, 9, 0, 32, hide_ull(1LL<<31), "L_B_BFu32i");
  }
}
static Arrange_To_Call_Me vL_B_BFu32i(Test_L_B_BFu32i, "L_B_BFu32i", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu32ll()
{
  {
    init_simple_test("L_B_BFu32ll");
    static L_B_BFu32ll lv;
    check2(sizeof(lv), 13, "sizeof(L_B_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu32ll)");
    check_field_offset(lv, v1, 0, "L_B_BFu32ll.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu32ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 32, 1, "L_B_BFu32ll");
    set_bf_and_test(lv, v3, 9, 0, 32, hide_ull(1LL<<31), "L_B_BFu32ll");
  }
}
static Arrange_To_Call_Me vL_B_BFu32ll(Test_L_B_BFu32ll, "L_B_BFu32ll", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu33()
{
  {
    init_simple_test("L_B_BFu33");
    static L_B_BFu33 lv;
    check2(sizeof(lv), 14, "sizeof(L_B_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu33)");
    check_field_offset(lv, v1, 0, "L_B_BFu33.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu33.v2");
    set_bf_and_test(lv, v3, 9, 0, 33, 1, "L_B_BFu33");
    set_bf_and_test(lv, v3, 9, 0, 33, hide_ull(1LL<<32), "L_B_BFu33");
  }
}
static Arrange_To_Call_Me vL_B_BFu33(Test_L_B_BFu33, "L_B_BFu33", 14);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu7c()
{
  {
    init_simple_test("L_B_BFu7c");
    static L_B_BFu7c lv;
    check2(sizeof(lv), 10, "sizeof(L_B_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu7c)");
    check_field_offset(lv, v1, 0, "L_B_BFu7c.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu7c.v2");
    set_bf_and_test(lv, v3, 9, 0, 7, 1, "L_B_BFu7c");
    set_bf_and_test(lv, v3, 9, 0, 7, hide_ull(1LL<<6), "L_B_BFu7c");
  }
}
static Arrange_To_Call_Me vL_B_BFu7c(Test_L_B_BFu7c, "L_B_BFu7c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu7i()
{
  {
    init_simple_test("L_B_BFu7i");
    static L_B_BFu7i lv;
    check2(sizeof(lv), 10, "sizeof(L_B_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu7i)");
    check_field_offset(lv, v1, 0, "L_B_BFu7i.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu7i.v2");
    set_bf_and_test(lv, v3, 9, 0, 7, 1, "L_B_BFu7i");
    set_bf_and_test(lv, v3, 9, 0, 7, hide_ull(1LL<<6), "L_B_BFu7i");
  }
}
static Arrange_To_Call_Me vL_B_BFu7i(Test_L_B_BFu7i, "L_B_BFu7i", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu7ll()
{
  {
    init_simple_test("L_B_BFu7ll");
    static L_B_BFu7ll lv;
    check2(sizeof(lv), 10, "sizeof(L_B_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu7ll)");
    check_field_offset(lv, v1, 0, "L_B_BFu7ll.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu7ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 7, 1, "L_B_BFu7ll");
    set_bf_and_test(lv, v3, 9, 0, 7, hide_ull(1LL<<6), "L_B_BFu7ll");
  }
}
static Arrange_To_Call_Me vL_B_BFu7ll(Test_L_B_BFu7ll, "L_B_BFu7ll", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu7s()
{
  {
    init_simple_test("L_B_BFu7s");
    static L_B_BFu7s lv;
    check2(sizeof(lv), 10, "sizeof(L_B_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu7s)");
    check_field_offset(lv, v1, 0, "L_B_BFu7s.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu7s.v2");
    set_bf_and_test(lv, v3, 9, 0, 7, 1, "L_B_BFu7s");
    set_bf_and_test(lv, v3, 9, 0, 7, hide_ull(1LL<<6), "L_B_BFu7s");
  }
}
static Arrange_To_Call_Me vL_B_BFu7s(Test_L_B_BFu7s, "L_B_BFu7s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu8c()
{
  {
    init_simple_test("L_B_BFu8c");
    static L_B_BFu8c lv;
    check2(sizeof(lv), 10, "sizeof(L_B_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu8c)");
    check_field_offset(lv, v1, 0, "L_B_BFu8c.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu8c.v2");
    set_bf_and_test(lv, v3, 9, 0, 8, 1, "L_B_BFu8c");
    set_bf_and_test(lv, v3, 9, 0, 8, hide_ull(1LL<<7), "L_B_BFu8c");
  }
}
static Arrange_To_Call_Me vL_B_BFu8c(Test_L_B_BFu8c, "L_B_BFu8c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu8i()
{
  {
    init_simple_test("L_B_BFu8i");
    static L_B_BFu8i lv;
    check2(sizeof(lv), 10, "sizeof(L_B_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu8i)");
    check_field_offset(lv, v1, 0, "L_B_BFu8i.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu8i.v2");
    set_bf_and_test(lv, v3, 9, 0, 8, 1, "L_B_BFu8i");
    set_bf_and_test(lv, v3, 9, 0, 8, hide_ull(1LL<<7), "L_B_BFu8i");
  }
}
static Arrange_To_Call_Me vL_B_BFu8i(Test_L_B_BFu8i, "L_B_BFu8i", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu8ll()
{
  {
    init_simple_test("L_B_BFu8ll");
    static L_B_BFu8ll lv;
    check2(sizeof(lv), 10, "sizeof(L_B_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu8ll)");
    check_field_offset(lv, v1, 0, "L_B_BFu8ll.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu8ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 8, 1, "L_B_BFu8ll");
    set_bf_and_test(lv, v3, 9, 0, 8, hide_ull(1LL<<7), "L_B_BFu8ll");
  }
}
static Arrange_To_Call_Me vL_B_BFu8ll(Test_L_B_BFu8ll, "L_B_BFu8ll", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu8s()
{
  {
    init_simple_test("L_B_BFu8s");
    static L_B_BFu8s lv;
    check2(sizeof(lv), 10, "sizeof(L_B_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu8s)");
    check_field_offset(lv, v1, 0, "L_B_BFu8s.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu8s.v2");
    set_bf_and_test(lv, v3, 9, 0, 8, 1, "L_B_BFu8s");
    set_bf_and_test(lv, v3, 9, 0, 8, hide_ull(1LL<<7), "L_B_BFu8s");
  }
}
static Arrange_To_Call_Me vL_B_BFu8s(Test_L_B_BFu8s, "L_B_BFu8s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu9i()
{
  {
    init_simple_test("L_B_BFu9i");
    static L_B_BFu9i lv;
    check2(sizeof(lv), 11, "sizeof(L_B_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu9i)");
    check_field_offset(lv, v1, 0, "L_B_BFu9i.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu9i.v2");
    set_bf_and_test(lv, v3, 9, 0, 9, 1, "L_B_BFu9i");
    set_bf_and_test(lv, v3, 9, 0, 9, hide_ull(1LL<<8), "L_B_BFu9i");
  }
}
static Arrange_To_Call_Me vL_B_BFu9i(Test_L_B_BFu9i, "L_B_BFu9i", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu9ll()
{
  {
    init_simple_test("L_B_BFu9ll");
    static L_B_BFu9ll lv;
    check2(sizeof(lv), 11, "sizeof(L_B_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu9ll)");
    check_field_offset(lv, v1, 0, "L_B_BFu9ll.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu9ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 9, 1, "L_B_BFu9ll");
    set_bf_and_test(lv, v3, 9, 0, 9, hide_ull(1LL<<8), "L_B_BFu9ll");
  }
}
static Arrange_To_Call_Me vL_B_BFu9ll(Test_L_B_BFu9ll, "L_B_BFu9ll", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_BFu9s()
{
  {
    init_simple_test("L_B_BFu9s");
    static L_B_BFu9s lv;
    check2(sizeof(lv), 11, "sizeof(L_B_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_BFu9s)");
    check_field_offset(lv, v1, 0, "L_B_BFu9s.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu9s.v2");
    set_bf_and_test(lv, v3, 9, 0, 9, 1, "L_B_BFu9s");
    set_bf_and_test(lv, v3, 9, 0, 9, hide_ull(1LL<<8), "L_B_BFu9s");
  }
}
static Arrange_To_Call_Me vL_B_BFu9s(Test_L_B_BFu9s, "L_B_BFu9s", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_C()
{
  {
    init_simple_test("L_B_C");
    L_B_C lv;
    check2(sizeof(lv), 10, "sizeof(L_B_C)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_C)");
    check_field_offset(lv, v1, 0, "L_B_C.v1");
    check_field_offset(lv, v2, 8, "L_B_C.v2");
    check_field_offset(lv, v3, 9, "L_B_C.v3");
  }
}
static Arrange_To_Call_Me vL_B_C(Test_L_B_C, "L_B_C", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_D()
{
  {
    init_simple_test("L_B_D");
    L_B_D lv;
    check2(sizeof(lv), 17, "sizeof(L_B_D)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_D)");
    check_field_offset(lv, v1, 0, "L_B_D.v1");
    check_field_offset(lv, v2, 8, "L_B_D.v2");
    check_field_offset(lv, v3, 9, "L_B_D.v3");
  }
}
static Arrange_To_Call_Me vL_B_D(Test_L_B_D, "L_B_D", 17);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_F()
{
  {
    init_simple_test("L_B_F");
    L_B_F lv;
    check2(sizeof(lv), 13, "sizeof(L_B_F)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_F)");
    check_field_offset(lv, v1, 0, "L_B_F.v1");
    check_field_offset(lv, v2, 8, "L_B_F.v2");
    check_field_offset(lv, v3, 9, "L_B_F.v3");
  }
}
static Arrange_To_Call_Me vL_B_F(Test_L_B_F, "L_B_F", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_I()
{
  {
    init_simple_test("L_B_I");
    L_B_I lv;
    check2(sizeof(lv), 13, "sizeof(L_B_I)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_I)");
    check_field_offset(lv, v1, 0, "L_B_I.v1");
    check_field_offset(lv, v2, 8, "L_B_I.v2");
    check_field_offset(lv, v3, 9, "L_B_I.v3");
  }
}
static Arrange_To_Call_Me vL_B_I(Test_L_B_I, "L_B_I", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_Ip()
{
  {
    init_simple_test("L_B_Ip");
    L_B_Ip lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(L_B_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_Ip)");
    check_field_offset(lv, v1, 0, "L_B_Ip.v1");
    check_field_offset(lv, v2, 8, "L_B_Ip.v2");
    check_field_offset(lv, v3, 9, "L_B_Ip.v3");
  }
}
static Arrange_To_Call_Me vL_B_Ip(Test_L_B_Ip, "L_B_Ip", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_L()
{
  {
    init_simple_test("L_B_L");
    L_B_L lv;
    check2(sizeof(lv), 17, "sizeof(L_B_L)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_L)");
    check_field_offset(lv, v1, 0, "L_B_L.v1");
    check_field_offset(lv, v2, 8, "L_B_L.v2");
    check_field_offset(lv, v3, 9, "L_B_L.v3");
  }
}
static Arrange_To_Call_Me vL_B_L(Test_L_B_L, "L_B_L", 17);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_S()
{
  {
    init_simple_test("L_B_S");
    L_B_S lv;
    check2(sizeof(lv), 11, "sizeof(L_B_S)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_S)");
    check_field_offset(lv, v1, 0, "L_B_S.v1");
    check_field_offset(lv, v2, 8, "L_B_S.v2");
    check_field_offset(lv, v3, 9, "L_B_S.v3");
  }
}
static Arrange_To_Call_Me vL_B_S(Test_L_B_S, "L_B_S", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_Uc()
{
  {
    init_simple_test("L_B_Uc");
    L_B_Uc lv;
    check2(sizeof(lv), 10, "sizeof(L_B_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_Uc)");
    check_field_offset(lv, v1, 0, "L_B_Uc.v1");
    check_field_offset(lv, v2, 8, "L_B_Uc.v2");
    check_field_offset(lv, v3, 9, "L_B_Uc.v3");
  }
}
static Arrange_To_Call_Me vL_B_Uc(Test_L_B_Uc, "L_B_Uc", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_Ui()
{
  {
    init_simple_test("L_B_Ui");
    L_B_Ui lv;
    check2(sizeof(lv), 13, "sizeof(L_B_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_Ui)");
    check_field_offset(lv, v1, 0, "L_B_Ui.v1");
    check_field_offset(lv, v2, 8, "L_B_Ui.v2");
    check_field_offset(lv, v3, 9, "L_B_Ui.v3");
  }
}
static Arrange_To_Call_Me vL_B_Ui(Test_L_B_Ui, "L_B_Ui", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_Ul()
{
  {
    init_simple_test("L_B_Ul");
    L_B_Ul lv;
    check2(sizeof(lv), 17, "sizeof(L_B_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_Ul)");
    check_field_offset(lv, v1, 0, "L_B_Ul.v1");
    check_field_offset(lv, v2, 8, "L_B_Ul.v2");
    check_field_offset(lv, v3, 9, "L_B_Ul.v3");
  }
}
static Arrange_To_Call_Me vL_B_Ul(Test_L_B_Ul, "L_B_Ul", 17);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_Us()
{
  {
    init_simple_test("L_B_Us");
    L_B_Us lv;
    check2(sizeof(lv), 11, "sizeof(L_B_Us)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_Us)");
    check_field_offset(lv, v1, 0, "L_B_Us.v1");
    check_field_offset(lv, v2, 8, "L_B_Us.v2");
    check_field_offset(lv, v3, 9, "L_B_Us.v3");
  }
}
static Arrange_To_Call_Me vL_B_Us(Test_L_B_Us, "L_B_Us", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_B_Vp()
{
  {
    init_simple_test("L_B_Vp");
    L_B_Vp lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(L_B_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(L_B_Vp)");
    check_field_offset(lv, v1, 0, "L_B_Vp.v1");
    check_field_offset(lv, v2, 8, "L_B_Vp.v2");
    check_field_offset(lv, v3, 9, "L_B_Vp.v3");
  }
}
static Arrange_To_Call_Me vL_B_Vp(Test_L_B_Vp, "L_B_Vp", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu15i_B()
{
  {
    init_simple_test("L_BFu15i_B");
    static L_BFu15i_B lv;
    check2(sizeof(lv), 11, "sizeof(L_BFu15i_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu15i_B)");
    check_field_offset(lv, v1, 0, "L_BFu15i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "L_BFu15i_B");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "L_BFu15i_B");
    check_field_offset(lv, v3, 10, "L_BFu15i_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu15i_B(Test_L_BFu15i_B, "L_BFu15i_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu15ll_B()
{
  {
    init_simple_test("L_BFu15ll_B");
    static L_BFu15ll_B lv;
    check2(sizeof(lv), 11, "sizeof(L_BFu15ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu15ll_B)");
    check_field_offset(lv, v1, 0, "L_BFu15ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "L_BFu15ll_B");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "L_BFu15ll_B");
    check_field_offset(lv, v3, 10, "L_BFu15ll_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu15ll_B(Test_L_BFu15ll_B, "L_BFu15ll_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu15s_B()
{
  {
    init_simple_test("L_BFu15s_B");
    static L_BFu15s_B lv;
    check2(sizeof(lv), 11, "sizeof(L_BFu15s_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu15s_B)");
    check_field_offset(lv, v1, 0, "L_BFu15s_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "L_BFu15s_B");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "L_BFu15s_B");
    check_field_offset(lv, v3, 10, "L_BFu15s_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu15s_B(Test_L_BFu15s_B, "L_BFu15s_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu16i_B()
{
  {
    init_simple_test("L_BFu16i_B");
    static L_BFu16i_B lv;
    check2(sizeof(lv), 11, "sizeof(L_BFu16i_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu16i_B)");
    check_field_offset(lv, v1, 0, "L_BFu16i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "L_BFu16i_B");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "L_BFu16i_B");
    check_field_offset(lv, v3, 10, "L_BFu16i_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu16i_B(Test_L_BFu16i_B, "L_BFu16i_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu16ll_B()
{
  {
    init_simple_test("L_BFu16ll_B");
    static L_BFu16ll_B lv;
    check2(sizeof(lv), 11, "sizeof(L_BFu16ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu16ll_B)");
    check_field_offset(lv, v1, 0, "L_BFu16ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "L_BFu16ll_B");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "L_BFu16ll_B");
    check_field_offset(lv, v3, 10, "L_BFu16ll_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu16ll_B(Test_L_BFu16ll_B, "L_BFu16ll_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu16s_B()
{
  {
    init_simple_test("L_BFu16s_B");
    static L_BFu16s_B lv;
    check2(sizeof(lv), 11, "sizeof(L_BFu16s_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu16s_B)");
    check_field_offset(lv, v1, 0, "L_BFu16s_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "L_BFu16s_B");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "L_BFu16s_B");
    check_field_offset(lv, v3, 10, "L_BFu16s_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu16s_B(Test_L_BFu16s_B, "L_BFu16s_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu17i_B()
{
  {
    init_simple_test("L_BFu17i_B");
    static L_BFu17i_B lv;
    check2(sizeof(lv), 12, "sizeof(L_BFu17i_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu17i_B)");
    check_field_offset(lv, v1, 0, "L_BFu17i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "L_BFu17i_B");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "L_BFu17i_B");
    check_field_offset(lv, v3, 11, "L_BFu17i_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu17i_B(Test_L_BFu17i_B, "L_BFu17i_B", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu17ll_B()
{
  {
    init_simple_test("L_BFu17ll_B");
    static L_BFu17ll_B lv;
    check2(sizeof(lv), 12, "sizeof(L_BFu17ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu17ll_B)");
    check_field_offset(lv, v1, 0, "L_BFu17ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "L_BFu17ll_B");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "L_BFu17ll_B");
    check_field_offset(lv, v3, 11, "L_BFu17ll_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu17ll_B(Test_L_BFu17ll_B, "L_BFu17ll_B", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu1c_B()
{
  {
    init_simple_test("L_BFu1c_B");
    static L_BFu1c_B lv;
    check2(sizeof(lv), 10, "sizeof(L_BFu1c_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu1c_B)");
    check_field_offset(lv, v1, 0, "L_BFu1c_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "L_BFu1c_B");
    check_field_offset(lv, v3, 9, "L_BFu1c_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu1c_B(Test_L_BFu1c_B, "L_BFu1c_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu1i_B()
{
  {
    init_simple_test("L_BFu1i_B");
    static L_BFu1i_B lv;
    check2(sizeof(lv), 10, "sizeof(L_BFu1i_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu1i_B)");
    check_field_offset(lv, v1, 0, "L_BFu1i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "L_BFu1i_B");
    check_field_offset(lv, v3, 9, "L_BFu1i_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu1i_B(Test_L_BFu1i_B, "L_BFu1i_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu1ll_B()
{
  {
    init_simple_test("L_BFu1ll_B");
    static L_BFu1ll_B lv;
    check2(sizeof(lv), 10, "sizeof(L_BFu1ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu1ll_B)");
    check_field_offset(lv, v1, 0, "L_BFu1ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "L_BFu1ll_B");
    check_field_offset(lv, v3, 9, "L_BFu1ll_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu1ll_B(Test_L_BFu1ll_B, "L_BFu1ll_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu1s_B()
{
  {
    init_simple_test("L_BFu1s_B");
    static L_BFu1s_B lv;
    check2(sizeof(lv), 10, "sizeof(L_BFu1s_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu1s_B)");
    check_field_offset(lv, v1, 0, "L_BFu1s_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "L_BFu1s_B");
    check_field_offset(lv, v3, 9, "L_BFu1s_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu1s_B(Test_L_BFu1s_B, "L_BFu1s_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu31i_B()
{
  {
    init_simple_test("L_BFu31i_B");
    static L_BFu31i_B lv;
    check2(sizeof(lv), 13, "sizeof(L_BFu31i_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu31i_B)");
    check_field_offset(lv, v1, 0, "L_BFu31i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "L_BFu31i_B");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "L_BFu31i_B");
    check_field_offset(lv, v3, 12, "L_BFu31i_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu31i_B(Test_L_BFu31i_B, "L_BFu31i_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu31ll_B()
{
  {
    init_simple_test("L_BFu31ll_B");
    static L_BFu31ll_B lv;
    check2(sizeof(lv), 13, "sizeof(L_BFu31ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu31ll_B)");
    check_field_offset(lv, v1, 0, "L_BFu31ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "L_BFu31ll_B");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "L_BFu31ll_B");
    check_field_offset(lv, v3, 12, "L_BFu31ll_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu31ll_B(Test_L_BFu31ll_B, "L_BFu31ll_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu32i_B()
{
  {
    init_simple_test("L_BFu32i_B");
    static L_BFu32i_B lv;
    check2(sizeof(lv), 13, "sizeof(L_BFu32i_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu32i_B)");
    check_field_offset(lv, v1, 0, "L_BFu32i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "L_BFu32i_B");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "L_BFu32i_B");
    check_field_offset(lv, v3, 12, "L_BFu32i_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu32i_B(Test_L_BFu32i_B, "L_BFu32i_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu32ll_B()
{
  {
    init_simple_test("L_BFu32ll_B");
    static L_BFu32ll_B lv;
    check2(sizeof(lv), 13, "sizeof(L_BFu32ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu32ll_B)");
    check_field_offset(lv, v1, 0, "L_BFu32ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "L_BFu32ll_B");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "L_BFu32ll_B");
    check_field_offset(lv, v3, 12, "L_BFu32ll_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu32ll_B(Test_L_BFu32ll_B, "L_BFu32ll_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu33_B()
{
  {
    init_simple_test("L_BFu33_B");
    static L_BFu33_B lv;
    check2(sizeof(lv), 14, "sizeof(L_BFu33_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu33_B)");
    check_field_offset(lv, v1, 0, "L_BFu33_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 33, 1, "L_BFu33_B");
    set_bf_and_test(lv, v2, 8, 0, 33, hide_ull(1LL<<32), "L_BFu33_B");
    check_field_offset(lv, v3, 13, "L_BFu33_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu33_B(Test_L_BFu33_B, "L_BFu33_B", 14);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu7c_B()
{
  {
    init_simple_test("L_BFu7c_B");
    static L_BFu7c_B lv;
    check2(sizeof(lv), 10, "sizeof(L_BFu7c_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu7c_B)");
    check_field_offset(lv, v1, 0, "L_BFu7c_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "L_BFu7c_B");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "L_BFu7c_B");
    check_field_offset(lv, v3, 9, "L_BFu7c_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu7c_B(Test_L_BFu7c_B, "L_BFu7c_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu7i_B()
{
  {
    init_simple_test("L_BFu7i_B");
    static L_BFu7i_B lv;
    check2(sizeof(lv), 10, "sizeof(L_BFu7i_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu7i_B)");
    check_field_offset(lv, v1, 0, "L_BFu7i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "L_BFu7i_B");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "L_BFu7i_B");
    check_field_offset(lv, v3, 9, "L_BFu7i_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu7i_B(Test_L_BFu7i_B, "L_BFu7i_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu7ll_B()
{
  {
    init_simple_test("L_BFu7ll_B");
    static L_BFu7ll_B lv;
    check2(sizeof(lv), 10, "sizeof(L_BFu7ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu7ll_B)");
    check_field_offset(lv, v1, 0, "L_BFu7ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "L_BFu7ll_B");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "L_BFu7ll_B");
    check_field_offset(lv, v3, 9, "L_BFu7ll_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu7ll_B(Test_L_BFu7ll_B, "L_BFu7ll_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu7s_B()
{
  {
    init_simple_test("L_BFu7s_B");
    static L_BFu7s_B lv;
    check2(sizeof(lv), 10, "sizeof(L_BFu7s_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu7s_B)");
    check_field_offset(lv, v1, 0, "L_BFu7s_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "L_BFu7s_B");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "L_BFu7s_B");
    check_field_offset(lv, v3, 9, "L_BFu7s_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu7s_B(Test_L_BFu7s_B, "L_BFu7s_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu8c_B()
{
  {
    init_simple_test("L_BFu8c_B");
    static L_BFu8c_B lv;
    check2(sizeof(lv), 10, "sizeof(L_BFu8c_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu8c_B)");
    check_field_offset(lv, v1, 0, "L_BFu8c_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "L_BFu8c_B");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "L_BFu8c_B");
    check_field_offset(lv, v3, 9, "L_BFu8c_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu8c_B(Test_L_BFu8c_B, "L_BFu8c_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu8i_B()
{
  {
    init_simple_test("L_BFu8i_B");
    static L_BFu8i_B lv;
    check2(sizeof(lv), 10, "sizeof(L_BFu8i_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu8i_B)");
    check_field_offset(lv, v1, 0, "L_BFu8i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "L_BFu8i_B");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "L_BFu8i_B");
    check_field_offset(lv, v3, 9, "L_BFu8i_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu8i_B(Test_L_BFu8i_B, "L_BFu8i_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu8ll_B()
{
  {
    init_simple_test("L_BFu8ll_B");
    static L_BFu8ll_B lv;
    check2(sizeof(lv), 10, "sizeof(L_BFu8ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu8ll_B)");
    check_field_offset(lv, v1, 0, "L_BFu8ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "L_BFu8ll_B");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "L_BFu8ll_B");
    check_field_offset(lv, v3, 9, "L_BFu8ll_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu8ll_B(Test_L_BFu8ll_B, "L_BFu8ll_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu8s_B()
{
  {
    init_simple_test("L_BFu8s_B");
    static L_BFu8s_B lv;
    check2(sizeof(lv), 10, "sizeof(L_BFu8s_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu8s_B)");
    check_field_offset(lv, v1, 0, "L_BFu8s_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "L_BFu8s_B");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "L_BFu8s_B");
    check_field_offset(lv, v3, 9, "L_BFu8s_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu8s_B(Test_L_BFu8s_B, "L_BFu8s_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu9i_B()
{
  {
    init_simple_test("L_BFu9i_B");
    static L_BFu9i_B lv;
    check2(sizeof(lv), 11, "sizeof(L_BFu9i_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu9i_B)");
    check_field_offset(lv, v1, 0, "L_BFu9i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "L_BFu9i_B");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "L_BFu9i_B");
    check_field_offset(lv, v3, 10, "L_BFu9i_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu9i_B(Test_L_BFu9i_B, "L_BFu9i_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu9ll_B()
{
  {
    init_simple_test("L_BFu9ll_B");
    static L_BFu9ll_B lv;
    check2(sizeof(lv), 11, "sizeof(L_BFu9ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu9ll_B)");
    check_field_offset(lv, v1, 0, "L_BFu9ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "L_BFu9ll_B");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "L_BFu9ll_B");
    check_field_offset(lv, v3, 10, "L_BFu9ll_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu9ll_B(Test_L_BFu9ll_B, "L_BFu9ll_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_BFu9s_B()
{
  {
    init_simple_test("L_BFu9s_B");
    static L_BFu9s_B lv;
    check2(sizeof(lv), 11, "sizeof(L_BFu9s_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_BFu9s_B)");
    check_field_offset(lv, v1, 0, "L_BFu9s_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "L_BFu9s_B");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "L_BFu9s_B");
    check_field_offset(lv, v3, 10, "L_BFu9s_B.v3");
  }
}
static Arrange_To_Call_Me vL_BFu9s_B(Test_L_BFu9s_B, "L_BFu9s_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_C_B()
{
  {
    init_simple_test("L_C_B");
    L_C_B lv;
    check2(sizeof(lv), 10, "sizeof(L_C_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_C_B)");
    check_field_offset(lv, v1, 0, "L_C_B.v1");
    check_field_offset(lv, v2, 8, "L_C_B.v2");
    check_field_offset(lv, v3, 9, "L_C_B.v3");
  }
}
static Arrange_To_Call_Me vL_C_B(Test_L_C_B, "L_C_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_D_B()
{
  {
    init_simple_test("L_D_B");
    L_D_B lv;
    check2(sizeof(lv), 17, "sizeof(L_D_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_D_B)");
    check_field_offset(lv, v1, 0, "L_D_B.v1");
    check_field_offset(lv, v2, 8, "L_D_B.v2");
    check_field_offset(lv, v3, 16, "L_D_B.v3");
  }
}
static Arrange_To_Call_Me vL_D_B(Test_L_D_B, "L_D_B", 17);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_F_B()
{
  {
    init_simple_test("L_F_B");
    L_F_B lv;
    check2(sizeof(lv), 13, "sizeof(L_F_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_F_B)");
    check_field_offset(lv, v1, 0, "L_F_B.v1");
    check_field_offset(lv, v2, 8, "L_F_B.v2");
    check_field_offset(lv, v3, 12, "L_F_B.v3");
  }
}
static Arrange_To_Call_Me vL_F_B(Test_L_F_B, "L_F_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_I_B()
{
  {
    init_simple_test("L_I_B");
    L_I_B lv;
    check2(sizeof(lv), 13, "sizeof(L_I_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_I_B)");
    check_field_offset(lv, v1, 0, "L_I_B.v1");
    check_field_offset(lv, v2, 8, "L_I_B.v2");
    check_field_offset(lv, v3, 12, "L_I_B.v3");
  }
}
static Arrange_To_Call_Me vL_I_B(Test_L_I_B, "L_I_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_Ip_B()
{
  {
    init_simple_test("L_Ip_B");
    L_Ip_B lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(L_Ip_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_Ip_B)");
    check_field_offset(lv, v1, 0, "L_Ip_B.v1");
    check_field_offset(lv, v2, 8, "L_Ip_B.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "L_Ip_B.v3");
  }
}
static Arrange_To_Call_Me vL_Ip_B(Test_L_Ip_B, "L_Ip_B", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_L_B()
{
  {
    init_simple_test("L_L_B");
    L_L_B lv;
    check2(sizeof(lv), 17, "sizeof(L_L_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_L_B)");
    check_field_offset(lv, v1, 0, "L_L_B.v1");
    check_field_offset(lv, v2, 8, "L_L_B.v2");
    check_field_offset(lv, v3, 16, "L_L_B.v3");
  }
}
static Arrange_To_Call_Me vL_L_B(Test_L_L_B, "L_L_B", 17);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_S_B()
{
  {
    init_simple_test("L_S_B");
    L_S_B lv;
    check2(sizeof(lv), 11, "sizeof(L_S_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_S_B)");
    check_field_offset(lv, v1, 0, "L_S_B.v1");
    check_field_offset(lv, v2, 8, "L_S_B.v2");
    check_field_offset(lv, v3, 10, "L_S_B.v3");
  }
}
static Arrange_To_Call_Me vL_S_B(Test_L_S_B, "L_S_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_Uc_B()
{
  {
    init_simple_test("L_Uc_B");
    L_Uc_B lv;
    check2(sizeof(lv), 10, "sizeof(L_Uc_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_Uc_B)");
    check_field_offset(lv, v1, 0, "L_Uc_B.v1");
    check_field_offset(lv, v2, 8, "L_Uc_B.v2");
    check_field_offset(lv, v3, 9, "L_Uc_B.v3");
  }
}
static Arrange_To_Call_Me vL_Uc_B(Test_L_Uc_B, "L_Uc_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_Ui_B()
{
  {
    init_simple_test("L_Ui_B");
    L_Ui_B lv;
    check2(sizeof(lv), 13, "sizeof(L_Ui_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_Ui_B)");
    check_field_offset(lv, v1, 0, "L_Ui_B.v1");
    check_field_offset(lv, v2, 8, "L_Ui_B.v2");
    check_field_offset(lv, v3, 12, "L_Ui_B.v3");
  }
}
static Arrange_To_Call_Me vL_Ui_B(Test_L_Ui_B, "L_Ui_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_Ul_B()
{
  {
    init_simple_test("L_Ul_B");
    L_Ul_B lv;
    check2(sizeof(lv), 17, "sizeof(L_Ul_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_Ul_B)");
    check_field_offset(lv, v1, 0, "L_Ul_B.v1");
    check_field_offset(lv, v2, 8, "L_Ul_B.v2");
    check_field_offset(lv, v3, 16, "L_Ul_B.v3");
  }
}
static Arrange_To_Call_Me vL_Ul_B(Test_L_Ul_B, "L_Ul_B", 17);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_Us_B()
{
  {
    init_simple_test("L_Us_B");
    L_Us_B lv;
    check2(sizeof(lv), 11, "sizeof(L_Us_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_Us_B)");
    check_field_offset(lv, v1, 0, "L_Us_B.v1");
    check_field_offset(lv, v2, 8, "L_Us_B.v2");
    check_field_offset(lv, v3, 10, "L_Us_B.v3");
  }
}
static Arrange_To_Call_Me vL_Us_B(Test_L_Us_B, "L_Us_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_L_Vp_B()
{
  {
    init_simple_test("L_Vp_B");
    L_Vp_B lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(L_Vp_B)");
    check2(__alignof__(lv), 1, "__alignof__(L_Vp_B)");
    check_field_offset(lv, v1, 0, "L_Vp_B.v1");
    check_field_offset(lv, v2, 8, "L_Vp_B.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "L_Vp_B.v3");
  }
}
static Arrange_To_Call_Me vL_Vp_B(Test_L_Vp_B, "L_Vp_B", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B()
{
  {
    init_simple_test("S_B");
    S_B lv;
    check2(sizeof(lv), 3, "sizeof(S_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_B)");
    check_field_offset(lv, v1, 0, "S_B.v1");
    check_field_offset(lv, v2, 2, "S_B.v2");
  }
}
static Arrange_To_Call_Me vS_B(Test_S_B, "S_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_B()
{
  {
    init_simple_test("S_B_B");
    S_B_B lv;
    check2(sizeof(lv), 4, "sizeof(S_B_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_B)");
    check_field_offset(lv, v1, 0, "S_B_B.v1");
    check_field_offset(lv, v2, 2, "S_B_B.v2");
    check_field_offset(lv, v3, 3, "S_B_B.v3");
  }
}
static Arrange_To_Call_Me vS_B_B(Test_S_B_B, "S_B_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu15i()
{
  {
    init_simple_test("S_B_BFu15i");
    static S_B_BFu15i lv;
    check2(sizeof(lv), 5, "sizeof(S_B_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu15i)");
    check_field_offset(lv, v1, 0, "S_B_BFu15i.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu15i.v2");
    set_bf_and_test(lv, v3, 3, 0, 15, 1, "S_B_BFu15i");
    set_bf_and_test(lv, v3, 3, 0, 15, hide_ull(1LL<<14), "S_B_BFu15i");
  }
}
static Arrange_To_Call_Me vS_B_BFu15i(Test_S_B_BFu15i, "S_B_BFu15i", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu15ll()
{
  {
    init_simple_test("S_B_BFu15ll");
    static S_B_BFu15ll lv;
    check2(sizeof(lv), 5, "sizeof(S_B_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu15ll)");
    check_field_offset(lv, v1, 0, "S_B_BFu15ll.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu15ll.v2");
    set_bf_and_test(lv, v3, 3, 0, 15, 1, "S_B_BFu15ll");
    set_bf_and_test(lv, v3, 3, 0, 15, hide_ull(1LL<<14), "S_B_BFu15ll");
  }
}
static Arrange_To_Call_Me vS_B_BFu15ll(Test_S_B_BFu15ll, "S_B_BFu15ll", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu15s()
{
  {
    init_simple_test("S_B_BFu15s");
    static S_B_BFu15s lv;
    check2(sizeof(lv), 5, "sizeof(S_B_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu15s)");
    check_field_offset(lv, v1, 0, "S_B_BFu15s.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu15s.v2");
    set_bf_and_test(lv, v3, 3, 0, 15, 1, "S_B_BFu15s");
    set_bf_and_test(lv, v3, 3, 0, 15, hide_ull(1LL<<14), "S_B_BFu15s");
  }
}
static Arrange_To_Call_Me vS_B_BFu15s(Test_S_B_BFu15s, "S_B_BFu15s", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu16i()
{
  {
    init_simple_test("S_B_BFu16i");
    static S_B_BFu16i lv;
    check2(sizeof(lv), 5, "sizeof(S_B_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu16i)");
    check_field_offset(lv, v1, 0, "S_B_BFu16i.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu16i.v2");
    set_bf_and_test(lv, v3, 3, 0, 16, 1, "S_B_BFu16i");
    set_bf_and_test(lv, v3, 3, 0, 16, hide_ull(1LL<<15), "S_B_BFu16i");
  }
}
static Arrange_To_Call_Me vS_B_BFu16i(Test_S_B_BFu16i, "S_B_BFu16i", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu16ll()
{
  {
    init_simple_test("S_B_BFu16ll");
    static S_B_BFu16ll lv;
    check2(sizeof(lv), 5, "sizeof(S_B_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu16ll)");
    check_field_offset(lv, v1, 0, "S_B_BFu16ll.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu16ll.v2");
    set_bf_and_test(lv, v3, 3, 0, 16, 1, "S_B_BFu16ll");
    set_bf_and_test(lv, v3, 3, 0, 16, hide_ull(1LL<<15), "S_B_BFu16ll");
  }
}
static Arrange_To_Call_Me vS_B_BFu16ll(Test_S_B_BFu16ll, "S_B_BFu16ll", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu16s()
{
  {
    init_simple_test("S_B_BFu16s");
    static S_B_BFu16s lv;
    check2(sizeof(lv), 5, "sizeof(S_B_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu16s)");
    check_field_offset(lv, v1, 0, "S_B_BFu16s.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu16s.v2");
    set_bf_and_test(lv, v3, 3, 0, 16, 1, "S_B_BFu16s");
    set_bf_and_test(lv, v3, 3, 0, 16, hide_ull(1LL<<15), "S_B_BFu16s");
  }
}
static Arrange_To_Call_Me vS_B_BFu16s(Test_S_B_BFu16s, "S_B_BFu16s", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu17i()
{
  {
    init_simple_test("S_B_BFu17i");
    static S_B_BFu17i lv;
    check2(sizeof(lv), 6, "sizeof(S_B_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu17i)");
    check_field_offset(lv, v1, 0, "S_B_BFu17i.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu17i.v2");
    set_bf_and_test(lv, v3, 3, 0, 17, 1, "S_B_BFu17i");
    set_bf_and_test(lv, v3, 3, 0, 17, hide_ull(1LL<<16), "S_B_BFu17i");
  }
}
static Arrange_To_Call_Me vS_B_BFu17i(Test_S_B_BFu17i, "S_B_BFu17i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu17ll()
{
  {
    init_simple_test("S_B_BFu17ll");
    static S_B_BFu17ll lv;
    check2(sizeof(lv), 6, "sizeof(S_B_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu17ll)");
    check_field_offset(lv, v1, 0, "S_B_BFu17ll.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu17ll.v2");
    set_bf_and_test(lv, v3, 3, 0, 17, 1, "S_B_BFu17ll");
    set_bf_and_test(lv, v3, 3, 0, 17, hide_ull(1LL<<16), "S_B_BFu17ll");
  }
}
static Arrange_To_Call_Me vS_B_BFu17ll(Test_S_B_BFu17ll, "S_B_BFu17ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu1c()
{
  {
    init_simple_test("S_B_BFu1c");
    static S_B_BFu1c lv;
    check2(sizeof(lv), 4, "sizeof(S_B_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu1c)");
    check_field_offset(lv, v1, 0, "S_B_BFu1c.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu1c.v2");
    set_bf_and_test(lv, v3, 3, 0, 1, 1, "S_B_BFu1c");
  }
}
static Arrange_To_Call_Me vS_B_BFu1c(Test_S_B_BFu1c, "S_B_BFu1c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu1i()
{
  {
    init_simple_test("S_B_BFu1i");
    static S_B_BFu1i lv;
    check2(sizeof(lv), 4, "sizeof(S_B_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu1i)");
    check_field_offset(lv, v1, 0, "S_B_BFu1i.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu1i.v2");
    set_bf_and_test(lv, v3, 3, 0, 1, 1, "S_B_BFu1i");
  }
}
static Arrange_To_Call_Me vS_B_BFu1i(Test_S_B_BFu1i, "S_B_BFu1i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu1ll()
{
  {
    init_simple_test("S_B_BFu1ll");
    static S_B_BFu1ll lv;
    check2(sizeof(lv), 4, "sizeof(S_B_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu1ll)");
    check_field_offset(lv, v1, 0, "S_B_BFu1ll.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu1ll.v2");
    set_bf_and_test(lv, v3, 3, 0, 1, 1, "S_B_BFu1ll");
  }
}
static Arrange_To_Call_Me vS_B_BFu1ll(Test_S_B_BFu1ll, "S_B_BFu1ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu1s()
{
  {
    init_simple_test("S_B_BFu1s");
    static S_B_BFu1s lv;
    check2(sizeof(lv), 4, "sizeof(S_B_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu1s)");
    check_field_offset(lv, v1, 0, "S_B_BFu1s.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu1s.v2");
    set_bf_and_test(lv, v3, 3, 0, 1, 1, "S_B_BFu1s");
  }
}
static Arrange_To_Call_Me vS_B_BFu1s(Test_S_B_BFu1s, "S_B_BFu1s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu31i()
{
  {
    init_simple_test("S_B_BFu31i");
    static S_B_BFu31i lv;
    check2(sizeof(lv), 7, "sizeof(S_B_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu31i)");
    check_field_offset(lv, v1, 0, "S_B_BFu31i.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu31i.v2");
    set_bf_and_test(lv, v3, 3, 0, 31, 1, "S_B_BFu31i");
    set_bf_and_test(lv, v3, 3, 0, 31, hide_ull(1LL<<30), "S_B_BFu31i");
  }
}
static Arrange_To_Call_Me vS_B_BFu31i(Test_S_B_BFu31i, "S_B_BFu31i", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu31ll()
{
  {
    init_simple_test("S_B_BFu31ll");
    static S_B_BFu31ll lv;
    check2(sizeof(lv), 7, "sizeof(S_B_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu31ll)");
    check_field_offset(lv, v1, 0, "S_B_BFu31ll.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu31ll.v2");
    set_bf_and_test(lv, v3, 3, 0, 31, 1, "S_B_BFu31ll");
    set_bf_and_test(lv, v3, 3, 0, 31, hide_ull(1LL<<30), "S_B_BFu31ll");
  }
}
static Arrange_To_Call_Me vS_B_BFu31ll(Test_S_B_BFu31ll, "S_B_BFu31ll", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu32i()
{
  {
    init_simple_test("S_B_BFu32i");
    static S_B_BFu32i lv;
    check2(sizeof(lv), 7, "sizeof(S_B_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu32i)");
    check_field_offset(lv, v1, 0, "S_B_BFu32i.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu32i.v2");
    set_bf_and_test(lv, v3, 3, 0, 32, 1, "S_B_BFu32i");
    set_bf_and_test(lv, v3, 3, 0, 32, hide_ull(1LL<<31), "S_B_BFu32i");
  }
}
static Arrange_To_Call_Me vS_B_BFu32i(Test_S_B_BFu32i, "S_B_BFu32i", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu32ll()
{
  {
    init_simple_test("S_B_BFu32ll");
    static S_B_BFu32ll lv;
    check2(sizeof(lv), 7, "sizeof(S_B_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu32ll)");
    check_field_offset(lv, v1, 0, "S_B_BFu32ll.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu32ll.v2");
    set_bf_and_test(lv, v3, 3, 0, 32, 1, "S_B_BFu32ll");
    set_bf_and_test(lv, v3, 3, 0, 32, hide_ull(1LL<<31), "S_B_BFu32ll");
  }
}
static Arrange_To_Call_Me vS_B_BFu32ll(Test_S_B_BFu32ll, "S_B_BFu32ll", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu33()
{
  {
    init_simple_test("S_B_BFu33");
    static S_B_BFu33 lv;
    check2(sizeof(lv), 8, "sizeof(S_B_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu33)");
    check_field_offset(lv, v1, 0, "S_B_BFu33.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu33.v2");
    set_bf_and_test(lv, v3, 3, 0, 33, 1, "S_B_BFu33");
    set_bf_and_test(lv, v3, 3, 0, 33, hide_ull(1LL<<32), "S_B_BFu33");
  }
}
static Arrange_To_Call_Me vS_B_BFu33(Test_S_B_BFu33, "S_B_BFu33", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu7c()
{
  {
    init_simple_test("S_B_BFu7c");
    static S_B_BFu7c lv;
    check2(sizeof(lv), 4, "sizeof(S_B_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu7c)");
    check_field_offset(lv, v1, 0, "S_B_BFu7c.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu7c.v2");
    set_bf_and_test(lv, v3, 3, 0, 7, 1, "S_B_BFu7c");
    set_bf_and_test(lv, v3, 3, 0, 7, hide_ull(1LL<<6), "S_B_BFu7c");
  }
}
static Arrange_To_Call_Me vS_B_BFu7c(Test_S_B_BFu7c, "S_B_BFu7c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu7i()
{
  {
    init_simple_test("S_B_BFu7i");
    static S_B_BFu7i lv;
    check2(sizeof(lv), 4, "sizeof(S_B_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu7i)");
    check_field_offset(lv, v1, 0, "S_B_BFu7i.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu7i.v2");
    set_bf_and_test(lv, v3, 3, 0, 7, 1, "S_B_BFu7i");
    set_bf_and_test(lv, v3, 3, 0, 7, hide_ull(1LL<<6), "S_B_BFu7i");
  }
}
static Arrange_To_Call_Me vS_B_BFu7i(Test_S_B_BFu7i, "S_B_BFu7i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu7ll()
{
  {
    init_simple_test("S_B_BFu7ll");
    static S_B_BFu7ll lv;
    check2(sizeof(lv), 4, "sizeof(S_B_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu7ll)");
    check_field_offset(lv, v1, 0, "S_B_BFu7ll.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu7ll.v2");
    set_bf_and_test(lv, v3, 3, 0, 7, 1, "S_B_BFu7ll");
    set_bf_and_test(lv, v3, 3, 0, 7, hide_ull(1LL<<6), "S_B_BFu7ll");
  }
}
static Arrange_To_Call_Me vS_B_BFu7ll(Test_S_B_BFu7ll, "S_B_BFu7ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu7s()
{
  {
    init_simple_test("S_B_BFu7s");
    static S_B_BFu7s lv;
    check2(sizeof(lv), 4, "sizeof(S_B_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu7s)");
    check_field_offset(lv, v1, 0, "S_B_BFu7s.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu7s.v2");
    set_bf_and_test(lv, v3, 3, 0, 7, 1, "S_B_BFu7s");
    set_bf_and_test(lv, v3, 3, 0, 7, hide_ull(1LL<<6), "S_B_BFu7s");
  }
}
static Arrange_To_Call_Me vS_B_BFu7s(Test_S_B_BFu7s, "S_B_BFu7s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu8c()
{
  {
    init_simple_test("S_B_BFu8c");
    static S_B_BFu8c lv;
    check2(sizeof(lv), 4, "sizeof(S_B_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu8c)");
    check_field_offset(lv, v1, 0, "S_B_BFu8c.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu8c.v2");
    set_bf_and_test(lv, v3, 3, 0, 8, 1, "S_B_BFu8c");
    set_bf_and_test(lv, v3, 3, 0, 8, hide_ull(1LL<<7), "S_B_BFu8c");
  }
}
static Arrange_To_Call_Me vS_B_BFu8c(Test_S_B_BFu8c, "S_B_BFu8c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu8i()
{
  {
    init_simple_test("S_B_BFu8i");
    static S_B_BFu8i lv;
    check2(sizeof(lv), 4, "sizeof(S_B_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu8i)");
    check_field_offset(lv, v1, 0, "S_B_BFu8i.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu8i.v2");
    set_bf_and_test(lv, v3, 3, 0, 8, 1, "S_B_BFu8i");
    set_bf_and_test(lv, v3, 3, 0, 8, hide_ull(1LL<<7), "S_B_BFu8i");
  }
}
static Arrange_To_Call_Me vS_B_BFu8i(Test_S_B_BFu8i, "S_B_BFu8i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu8ll()
{
  {
    init_simple_test("S_B_BFu8ll");
    static S_B_BFu8ll lv;
    check2(sizeof(lv), 4, "sizeof(S_B_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu8ll)");
    check_field_offset(lv, v1, 0, "S_B_BFu8ll.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu8ll.v2");
    set_bf_and_test(lv, v3, 3, 0, 8, 1, "S_B_BFu8ll");
    set_bf_and_test(lv, v3, 3, 0, 8, hide_ull(1LL<<7), "S_B_BFu8ll");
  }
}
static Arrange_To_Call_Me vS_B_BFu8ll(Test_S_B_BFu8ll, "S_B_BFu8ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu8s()
{
  {
    init_simple_test("S_B_BFu8s");
    static S_B_BFu8s lv;
    check2(sizeof(lv), 4, "sizeof(S_B_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu8s)");
    check_field_offset(lv, v1, 0, "S_B_BFu8s.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu8s.v2");
    set_bf_and_test(lv, v3, 3, 0, 8, 1, "S_B_BFu8s");
    set_bf_and_test(lv, v3, 3, 0, 8, hide_ull(1LL<<7), "S_B_BFu8s");
  }
}
static Arrange_To_Call_Me vS_B_BFu8s(Test_S_B_BFu8s, "S_B_BFu8s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu9i()
{
  {
    init_simple_test("S_B_BFu9i");
    static S_B_BFu9i lv;
    check2(sizeof(lv), 5, "sizeof(S_B_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu9i)");
    check_field_offset(lv, v1, 0, "S_B_BFu9i.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu9i.v2");
    set_bf_and_test(lv, v3, 3, 0, 9, 1, "S_B_BFu9i");
    set_bf_and_test(lv, v3, 3, 0, 9, hide_ull(1LL<<8), "S_B_BFu9i");
  }
}
static Arrange_To_Call_Me vS_B_BFu9i(Test_S_B_BFu9i, "S_B_BFu9i", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu9ll()
{
  {
    init_simple_test("S_B_BFu9ll");
    static S_B_BFu9ll lv;
    check2(sizeof(lv), 5, "sizeof(S_B_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu9ll)");
    check_field_offset(lv, v1, 0, "S_B_BFu9ll.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu9ll.v2");
    set_bf_and_test(lv, v3, 3, 0, 9, 1, "S_B_BFu9ll");
    set_bf_and_test(lv, v3, 3, 0, 9, hide_ull(1LL<<8), "S_B_BFu9ll");
  }
}
static Arrange_To_Call_Me vS_B_BFu9ll(Test_S_B_BFu9ll, "S_B_BFu9ll", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_BFu9s()
{
  {
    init_simple_test("S_B_BFu9s");
    static S_B_BFu9s lv;
    check2(sizeof(lv), 5, "sizeof(S_B_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_BFu9s)");
    check_field_offset(lv, v1, 0, "S_B_BFu9s.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu9s.v2");
    set_bf_and_test(lv, v3, 3, 0, 9, 1, "S_B_BFu9s");
    set_bf_and_test(lv, v3, 3, 0, 9, hide_ull(1LL<<8), "S_B_BFu9s");
  }
}
static Arrange_To_Call_Me vS_B_BFu9s(Test_S_B_BFu9s, "S_B_BFu9s", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_C()
{
  {
    init_simple_test("S_B_C");
    S_B_C lv;
    check2(sizeof(lv), 4, "sizeof(S_B_C)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_C)");
    check_field_offset(lv, v1, 0, "S_B_C.v1");
    check_field_offset(lv, v2, 2, "S_B_C.v2");
    check_field_offset(lv, v3, 3, "S_B_C.v3");
  }
}
static Arrange_To_Call_Me vS_B_C(Test_S_B_C, "S_B_C", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_D()
{
  {
    init_simple_test("S_B_D");
    S_B_D lv;
    check2(sizeof(lv), 11, "sizeof(S_B_D)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_D)");
    check_field_offset(lv, v1, 0, "S_B_D.v1");
    check_field_offset(lv, v2, 2, "S_B_D.v2");
    check_field_offset(lv, v3, 3, "S_B_D.v3");
  }
}
static Arrange_To_Call_Me vS_B_D(Test_S_B_D, "S_B_D", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_F()
{
  {
    init_simple_test("S_B_F");
    S_B_F lv;
    check2(sizeof(lv), 7, "sizeof(S_B_F)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_F)");
    check_field_offset(lv, v1, 0, "S_B_F.v1");
    check_field_offset(lv, v2, 2, "S_B_F.v2");
    check_field_offset(lv, v3, 3, "S_B_F.v3");
  }
}
static Arrange_To_Call_Me vS_B_F(Test_S_B_F, "S_B_F", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_I()
{
  {
    init_simple_test("S_B_I");
    S_B_I lv;
    check2(sizeof(lv), 7, "sizeof(S_B_I)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_I)");
    check_field_offset(lv, v1, 0, "S_B_I.v1");
    check_field_offset(lv, v2, 2, "S_B_I.v2");
    check_field_offset(lv, v3, 3, "S_B_I.v3");
  }
}
static Arrange_To_Call_Me vS_B_I(Test_S_B_I, "S_B_I", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_Ip()
{
  {
    init_simple_test("S_B_Ip");
    S_B_Ip lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(S_B_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_Ip)");
    check_field_offset(lv, v1, 0, "S_B_Ip.v1");
    check_field_offset(lv, v2, 2, "S_B_Ip.v2");
    check_field_offset(lv, v3, 3, "S_B_Ip.v3");
  }
}
static Arrange_To_Call_Me vS_B_Ip(Test_S_B_Ip, "S_B_Ip", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_L()
{
  {
    init_simple_test("S_B_L");
    S_B_L lv;
    check2(sizeof(lv), 11, "sizeof(S_B_L)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_L)");
    check_field_offset(lv, v1, 0, "S_B_L.v1");
    check_field_offset(lv, v2, 2, "S_B_L.v2");
    check_field_offset(lv, v3, 3, "S_B_L.v3");
  }
}
static Arrange_To_Call_Me vS_B_L(Test_S_B_L, "S_B_L", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_S()
{
  {
    init_simple_test("S_B_S");
    S_B_S lv;
    check2(sizeof(lv), 5, "sizeof(S_B_S)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_S)");
    check_field_offset(lv, v1, 0, "S_B_S.v1");
    check_field_offset(lv, v2, 2, "S_B_S.v2");
    check_field_offset(lv, v3, 3, "S_B_S.v3");
  }
}
static Arrange_To_Call_Me vS_B_S(Test_S_B_S, "S_B_S", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_Uc()
{
  {
    init_simple_test("S_B_Uc");
    S_B_Uc lv;
    check2(sizeof(lv), 4, "sizeof(S_B_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_Uc)");
    check_field_offset(lv, v1, 0, "S_B_Uc.v1");
    check_field_offset(lv, v2, 2, "S_B_Uc.v2");
    check_field_offset(lv, v3, 3, "S_B_Uc.v3");
  }
}
static Arrange_To_Call_Me vS_B_Uc(Test_S_B_Uc, "S_B_Uc", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_Ui()
{
  {
    init_simple_test("S_B_Ui");
    S_B_Ui lv;
    check2(sizeof(lv), 7, "sizeof(S_B_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_Ui)");
    check_field_offset(lv, v1, 0, "S_B_Ui.v1");
    check_field_offset(lv, v2, 2, "S_B_Ui.v2");
    check_field_offset(lv, v3, 3, "S_B_Ui.v3");
  }
}
static Arrange_To_Call_Me vS_B_Ui(Test_S_B_Ui, "S_B_Ui", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_Ul()
{
  {
    init_simple_test("S_B_Ul");
    S_B_Ul lv;
    check2(sizeof(lv), 11, "sizeof(S_B_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_Ul)");
    check_field_offset(lv, v1, 0, "S_B_Ul.v1");
    check_field_offset(lv, v2, 2, "S_B_Ul.v2");
    check_field_offset(lv, v3, 3, "S_B_Ul.v3");
  }
}
static Arrange_To_Call_Me vS_B_Ul(Test_S_B_Ul, "S_B_Ul", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_Us()
{
  {
    init_simple_test("S_B_Us");
    S_B_Us lv;
    check2(sizeof(lv), 5, "sizeof(S_B_Us)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_Us)");
    check_field_offset(lv, v1, 0, "S_B_Us.v1");
    check_field_offset(lv, v2, 2, "S_B_Us.v2");
    check_field_offset(lv, v3, 3, "S_B_Us.v3");
  }
}
static Arrange_To_Call_Me vS_B_Us(Test_S_B_Us, "S_B_Us", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_B_Vp()
{
  {
    init_simple_test("S_B_Vp");
    S_B_Vp lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(S_B_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(S_B_Vp)");
    check_field_offset(lv, v1, 0, "S_B_Vp.v1");
    check_field_offset(lv, v2, 2, "S_B_Vp.v2");
    check_field_offset(lv, v3, 3, "S_B_Vp.v3");
  }
}
static Arrange_To_Call_Me vS_B_Vp(Test_S_B_Vp, "S_B_Vp", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu15i_B()
{
  {
    init_simple_test("S_BFu15i_B");
    static S_BFu15i_B lv;
    check2(sizeof(lv), 5, "sizeof(S_BFu15i_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu15i_B)");
    check_field_offset(lv, v1, 0, "S_BFu15i_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "S_BFu15i_B");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "S_BFu15i_B");
    check_field_offset(lv, v3, 4, "S_BFu15i_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu15i_B(Test_S_BFu15i_B, "S_BFu15i_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu15ll_B()
{
  {
    init_simple_test("S_BFu15ll_B");
    static S_BFu15ll_B lv;
    check2(sizeof(lv), 5, "sizeof(S_BFu15ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu15ll_B)");
    check_field_offset(lv, v1, 0, "S_BFu15ll_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "S_BFu15ll_B");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "S_BFu15ll_B");
    check_field_offset(lv, v3, 4, "S_BFu15ll_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu15ll_B(Test_S_BFu15ll_B, "S_BFu15ll_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu15s_B()
{
  {
    init_simple_test("S_BFu15s_B");
    static S_BFu15s_B lv;
    check2(sizeof(lv), 5, "sizeof(S_BFu15s_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu15s_B)");
    check_field_offset(lv, v1, 0, "S_BFu15s_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "S_BFu15s_B");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "S_BFu15s_B");
    check_field_offset(lv, v3, 4, "S_BFu15s_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu15s_B(Test_S_BFu15s_B, "S_BFu15s_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu16i_B()
{
  {
    init_simple_test("S_BFu16i_B");
    static S_BFu16i_B lv;
    check2(sizeof(lv), 5, "sizeof(S_BFu16i_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu16i_B)");
    check_field_offset(lv, v1, 0, "S_BFu16i_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "S_BFu16i_B");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "S_BFu16i_B");
    check_field_offset(lv, v3, 4, "S_BFu16i_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu16i_B(Test_S_BFu16i_B, "S_BFu16i_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu16ll_B()
{
  {
    init_simple_test("S_BFu16ll_B");
    static S_BFu16ll_B lv;
    check2(sizeof(lv), 5, "sizeof(S_BFu16ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu16ll_B)");
    check_field_offset(lv, v1, 0, "S_BFu16ll_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "S_BFu16ll_B");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "S_BFu16ll_B");
    check_field_offset(lv, v3, 4, "S_BFu16ll_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu16ll_B(Test_S_BFu16ll_B, "S_BFu16ll_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu16s_B()
{
  {
    init_simple_test("S_BFu16s_B");
    static S_BFu16s_B lv;
    check2(sizeof(lv), 5, "sizeof(S_BFu16s_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu16s_B)");
    check_field_offset(lv, v1, 0, "S_BFu16s_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "S_BFu16s_B");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "S_BFu16s_B");
    check_field_offset(lv, v3, 4, "S_BFu16s_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu16s_B(Test_S_BFu16s_B, "S_BFu16s_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu17i_B()
{
  {
    init_simple_test("S_BFu17i_B");
    static S_BFu17i_B lv;
    check2(sizeof(lv), 6, "sizeof(S_BFu17i_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu17i_B)");
    check_field_offset(lv, v1, 0, "S_BFu17i_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "S_BFu17i_B");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "S_BFu17i_B");
    check_field_offset(lv, v3, 5, "S_BFu17i_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu17i_B(Test_S_BFu17i_B, "S_BFu17i_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu17ll_B()
{
  {
    init_simple_test("S_BFu17ll_B");
    static S_BFu17ll_B lv;
    check2(sizeof(lv), 6, "sizeof(S_BFu17ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu17ll_B)");
    check_field_offset(lv, v1, 0, "S_BFu17ll_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "S_BFu17ll_B");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "S_BFu17ll_B");
    check_field_offset(lv, v3, 5, "S_BFu17ll_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu17ll_B(Test_S_BFu17ll_B, "S_BFu17ll_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu1c_B()
{
  {
    init_simple_test("S_BFu1c_B");
    static S_BFu1c_B lv;
    check2(sizeof(lv), 4, "sizeof(S_BFu1c_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu1c_B)");
    check_field_offset(lv, v1, 0, "S_BFu1c_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "S_BFu1c_B");
    check_field_offset(lv, v3, 3, "S_BFu1c_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu1c_B(Test_S_BFu1c_B, "S_BFu1c_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu1i_B()
{
  {
    init_simple_test("S_BFu1i_B");
    static S_BFu1i_B lv;
    check2(sizeof(lv), 4, "sizeof(S_BFu1i_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu1i_B)");
    check_field_offset(lv, v1, 0, "S_BFu1i_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "S_BFu1i_B");
    check_field_offset(lv, v3, 3, "S_BFu1i_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu1i_B(Test_S_BFu1i_B, "S_BFu1i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu1ll_B()
{
  {
    init_simple_test("S_BFu1ll_B");
    static S_BFu1ll_B lv;
    check2(sizeof(lv), 4, "sizeof(S_BFu1ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu1ll_B)");
    check_field_offset(lv, v1, 0, "S_BFu1ll_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "S_BFu1ll_B");
    check_field_offset(lv, v3, 3, "S_BFu1ll_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu1ll_B(Test_S_BFu1ll_B, "S_BFu1ll_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu1s_B()
{
  {
    init_simple_test("S_BFu1s_B");
    static S_BFu1s_B lv;
    check2(sizeof(lv), 4, "sizeof(S_BFu1s_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu1s_B)");
    check_field_offset(lv, v1, 0, "S_BFu1s_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "S_BFu1s_B");
    check_field_offset(lv, v3, 3, "S_BFu1s_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu1s_B(Test_S_BFu1s_B, "S_BFu1s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu31i_B()
{
  {
    init_simple_test("S_BFu31i_B");
    static S_BFu31i_B lv;
    check2(sizeof(lv), 7, "sizeof(S_BFu31i_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu31i_B)");
    check_field_offset(lv, v1, 0, "S_BFu31i_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "S_BFu31i_B");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "S_BFu31i_B");
    check_field_offset(lv, v3, 6, "S_BFu31i_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu31i_B(Test_S_BFu31i_B, "S_BFu31i_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu31ll_B()
{
  {
    init_simple_test("S_BFu31ll_B");
    static S_BFu31ll_B lv;
    check2(sizeof(lv), 7, "sizeof(S_BFu31ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu31ll_B)");
    check_field_offset(lv, v1, 0, "S_BFu31ll_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "S_BFu31ll_B");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "S_BFu31ll_B");
    check_field_offset(lv, v3, 6, "S_BFu31ll_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu31ll_B(Test_S_BFu31ll_B, "S_BFu31ll_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu32i_B()
{
  {
    init_simple_test("S_BFu32i_B");
    static S_BFu32i_B lv;
    check2(sizeof(lv), 7, "sizeof(S_BFu32i_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu32i_B)");
    check_field_offset(lv, v1, 0, "S_BFu32i_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "S_BFu32i_B");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "S_BFu32i_B");
    check_field_offset(lv, v3, 6, "S_BFu32i_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu32i_B(Test_S_BFu32i_B, "S_BFu32i_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu32ll_B()
{
  {
    init_simple_test("S_BFu32ll_B");
    static S_BFu32ll_B lv;
    check2(sizeof(lv), 7, "sizeof(S_BFu32ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu32ll_B)");
    check_field_offset(lv, v1, 0, "S_BFu32ll_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "S_BFu32ll_B");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "S_BFu32ll_B");
    check_field_offset(lv, v3, 6, "S_BFu32ll_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu32ll_B(Test_S_BFu32ll_B, "S_BFu32ll_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu33_B()
{
  {
    init_simple_test("S_BFu33_B");
    static S_BFu33_B lv;
    check2(sizeof(lv), 8, "sizeof(S_BFu33_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu33_B)");
    check_field_offset(lv, v1, 0, "S_BFu33_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 33, 1, "S_BFu33_B");
    set_bf_and_test(lv, v2, 2, 0, 33, hide_ull(1LL<<32), "S_BFu33_B");
    check_field_offset(lv, v3, 7, "S_BFu33_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu33_B(Test_S_BFu33_B, "S_BFu33_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu7c_B()
{
  {
    init_simple_test("S_BFu7c_B");
    static S_BFu7c_B lv;
    check2(sizeof(lv), 4, "sizeof(S_BFu7c_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu7c_B)");
    check_field_offset(lv, v1, 0, "S_BFu7c_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "S_BFu7c_B");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "S_BFu7c_B");
    check_field_offset(lv, v3, 3, "S_BFu7c_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu7c_B(Test_S_BFu7c_B, "S_BFu7c_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu7i_B()
{
  {
    init_simple_test("S_BFu7i_B");
    static S_BFu7i_B lv;
    check2(sizeof(lv), 4, "sizeof(S_BFu7i_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu7i_B)");
    check_field_offset(lv, v1, 0, "S_BFu7i_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "S_BFu7i_B");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "S_BFu7i_B");
    check_field_offset(lv, v3, 3, "S_BFu7i_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu7i_B(Test_S_BFu7i_B, "S_BFu7i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu7ll_B()
{
  {
    init_simple_test("S_BFu7ll_B");
    static S_BFu7ll_B lv;
    check2(sizeof(lv), 4, "sizeof(S_BFu7ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu7ll_B)");
    check_field_offset(lv, v1, 0, "S_BFu7ll_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "S_BFu7ll_B");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "S_BFu7ll_B");
    check_field_offset(lv, v3, 3, "S_BFu7ll_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu7ll_B(Test_S_BFu7ll_B, "S_BFu7ll_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu7s_B()
{
  {
    init_simple_test("S_BFu7s_B");
    static S_BFu7s_B lv;
    check2(sizeof(lv), 4, "sizeof(S_BFu7s_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu7s_B)");
    check_field_offset(lv, v1, 0, "S_BFu7s_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "S_BFu7s_B");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "S_BFu7s_B");
    check_field_offset(lv, v3, 3, "S_BFu7s_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu7s_B(Test_S_BFu7s_B, "S_BFu7s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu8c_B()
{
  {
    init_simple_test("S_BFu8c_B");
    static S_BFu8c_B lv;
    check2(sizeof(lv), 4, "sizeof(S_BFu8c_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu8c_B)");
    check_field_offset(lv, v1, 0, "S_BFu8c_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "S_BFu8c_B");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "S_BFu8c_B");
    check_field_offset(lv, v3, 3, "S_BFu8c_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu8c_B(Test_S_BFu8c_B, "S_BFu8c_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu8i_B()
{
  {
    init_simple_test("S_BFu8i_B");
    static S_BFu8i_B lv;
    check2(sizeof(lv), 4, "sizeof(S_BFu8i_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu8i_B)");
    check_field_offset(lv, v1, 0, "S_BFu8i_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "S_BFu8i_B");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "S_BFu8i_B");
    check_field_offset(lv, v3, 3, "S_BFu8i_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu8i_B(Test_S_BFu8i_B, "S_BFu8i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu8ll_B()
{
  {
    init_simple_test("S_BFu8ll_B");
    static S_BFu8ll_B lv;
    check2(sizeof(lv), 4, "sizeof(S_BFu8ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu8ll_B)");
    check_field_offset(lv, v1, 0, "S_BFu8ll_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "S_BFu8ll_B");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "S_BFu8ll_B");
    check_field_offset(lv, v3, 3, "S_BFu8ll_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu8ll_B(Test_S_BFu8ll_B, "S_BFu8ll_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu8s_B()
{
  {
    init_simple_test("S_BFu8s_B");
    static S_BFu8s_B lv;
    check2(sizeof(lv), 4, "sizeof(S_BFu8s_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu8s_B)");
    check_field_offset(lv, v1, 0, "S_BFu8s_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "S_BFu8s_B");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "S_BFu8s_B");
    check_field_offset(lv, v3, 3, "S_BFu8s_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu8s_B(Test_S_BFu8s_B, "S_BFu8s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu9i_B()
{
  {
    init_simple_test("S_BFu9i_B");
    static S_BFu9i_B lv;
    check2(sizeof(lv), 5, "sizeof(S_BFu9i_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu9i_B)");
    check_field_offset(lv, v1, 0, "S_BFu9i_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "S_BFu9i_B");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "S_BFu9i_B");
    check_field_offset(lv, v3, 4, "S_BFu9i_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu9i_B(Test_S_BFu9i_B, "S_BFu9i_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu9ll_B()
{
  {
    init_simple_test("S_BFu9ll_B");
    static S_BFu9ll_B lv;
    check2(sizeof(lv), 5, "sizeof(S_BFu9ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu9ll_B)");
    check_field_offset(lv, v1, 0, "S_BFu9ll_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "S_BFu9ll_B");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "S_BFu9ll_B");
    check_field_offset(lv, v3, 4, "S_BFu9ll_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu9ll_B(Test_S_BFu9ll_B, "S_BFu9ll_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_BFu9s_B()
{
  {
    init_simple_test("S_BFu9s_B");
    static S_BFu9s_B lv;
    check2(sizeof(lv), 5, "sizeof(S_BFu9s_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_BFu9s_B)");
    check_field_offset(lv, v1, 0, "S_BFu9s_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "S_BFu9s_B");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "S_BFu9s_B");
    check_field_offset(lv, v3, 4, "S_BFu9s_B.v3");
  }
}
static Arrange_To_Call_Me vS_BFu9s_B(Test_S_BFu9s_B, "S_BFu9s_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_C_B()
{
  {
    init_simple_test("S_C_B");
    S_C_B lv;
    check2(sizeof(lv), 4, "sizeof(S_C_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_C_B)");
    check_field_offset(lv, v1, 0, "S_C_B.v1");
    check_field_offset(lv, v2, 2, "S_C_B.v2");
    check_field_offset(lv, v3, 3, "S_C_B.v3");
  }
}
static Arrange_To_Call_Me vS_C_B(Test_S_C_B, "S_C_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_D_B()
{
  {
    init_simple_test("S_D_B");
    S_D_B lv;
    check2(sizeof(lv), 11, "sizeof(S_D_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_D_B)");
    check_field_offset(lv, v1, 0, "S_D_B.v1");
    check_field_offset(lv, v2, 2, "S_D_B.v2");
    check_field_offset(lv, v3, 10, "S_D_B.v3");
  }
}
static Arrange_To_Call_Me vS_D_B(Test_S_D_B, "S_D_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_F_B()
{
  {
    init_simple_test("S_F_B");
    S_F_B lv;
    check2(sizeof(lv), 7, "sizeof(S_F_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_F_B)");
    check_field_offset(lv, v1, 0, "S_F_B.v1");
    check_field_offset(lv, v2, 2, "S_F_B.v2");
    check_field_offset(lv, v3, 6, "S_F_B.v3");
  }
}
static Arrange_To_Call_Me vS_F_B(Test_S_F_B, "S_F_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_I_B()
{
  {
    init_simple_test("S_I_B");
    S_I_B lv;
    check2(sizeof(lv), 7, "sizeof(S_I_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_I_B)");
    check_field_offset(lv, v1, 0, "S_I_B.v1");
    check_field_offset(lv, v2, 2, "S_I_B.v2");
    check_field_offset(lv, v3, 6, "S_I_B.v3");
  }
}
static Arrange_To_Call_Me vS_I_B(Test_S_I_B, "S_I_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_Ip_B()
{
  {
    init_simple_test("S_Ip_B");
    S_Ip_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(S_Ip_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_Ip_B)");
    check_field_offset(lv, v1, 0, "S_Ip_B.v1");
    check_field_offset(lv, v2, 2, "S_Ip_B.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "S_Ip_B.v3");
  }
}
static Arrange_To_Call_Me vS_Ip_B(Test_S_Ip_B, "S_Ip_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_L_B()
{
  {
    init_simple_test("S_L_B");
    S_L_B lv;
    check2(sizeof(lv), 11, "sizeof(S_L_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_L_B)");
    check_field_offset(lv, v1, 0, "S_L_B.v1");
    check_field_offset(lv, v2, 2, "S_L_B.v2");
    check_field_offset(lv, v3, 10, "S_L_B.v3");
  }
}
static Arrange_To_Call_Me vS_L_B(Test_S_L_B, "S_L_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_S_B()
{
  {
    init_simple_test("S_S_B");
    S_S_B lv;
    check2(sizeof(lv), 5, "sizeof(S_S_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_S_B)");
    check_field_offset(lv, v1, 0, "S_S_B.v1");
    check_field_offset(lv, v2, 2, "S_S_B.v2");
    check_field_offset(lv, v3, 4, "S_S_B.v3");
  }
}
static Arrange_To_Call_Me vS_S_B(Test_S_S_B, "S_S_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_Uc_B()
{
  {
    init_simple_test("S_Uc_B");
    S_Uc_B lv;
    check2(sizeof(lv), 4, "sizeof(S_Uc_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_Uc_B)");
    check_field_offset(lv, v1, 0, "S_Uc_B.v1");
    check_field_offset(lv, v2, 2, "S_Uc_B.v2");
    check_field_offset(lv, v3, 3, "S_Uc_B.v3");
  }
}
static Arrange_To_Call_Me vS_Uc_B(Test_S_Uc_B, "S_Uc_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_Ui_B()
{
  {
    init_simple_test("S_Ui_B");
    S_Ui_B lv;
    check2(sizeof(lv), 7, "sizeof(S_Ui_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_Ui_B)");
    check_field_offset(lv, v1, 0, "S_Ui_B.v1");
    check_field_offset(lv, v2, 2, "S_Ui_B.v2");
    check_field_offset(lv, v3, 6, "S_Ui_B.v3");
  }
}
static Arrange_To_Call_Me vS_Ui_B(Test_S_Ui_B, "S_Ui_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_Ul_B()
{
  {
    init_simple_test("S_Ul_B");
    S_Ul_B lv;
    check2(sizeof(lv), 11, "sizeof(S_Ul_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_Ul_B)");
    check_field_offset(lv, v1, 0, "S_Ul_B.v1");
    check_field_offset(lv, v2, 2, "S_Ul_B.v2");
    check_field_offset(lv, v3, 10, "S_Ul_B.v3");
  }
}
static Arrange_To_Call_Me vS_Ul_B(Test_S_Ul_B, "S_Ul_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_Us_B()
{
  {
    init_simple_test("S_Us_B");
    S_Us_B lv;
    check2(sizeof(lv), 5, "sizeof(S_Us_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_Us_B)");
    check_field_offset(lv, v1, 0, "S_Us_B.v1");
    check_field_offset(lv, v2, 2, "S_Us_B.v2");
    check_field_offset(lv, v3, 4, "S_Us_B.v3");
  }
}
static Arrange_To_Call_Me vS_Us_B(Test_S_Us_B, "S_Us_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_S_Vp_B()
{
  {
    init_simple_test("S_Vp_B");
    S_Vp_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(S_Vp_B)");
    check2(__alignof__(lv), 1, "__alignof__(S_Vp_B)");
    check_field_offset(lv, v1, 0, "S_Vp_B.v1");
    check_field_offset(lv, v2, 2, "S_Vp_B.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "S_Vp_B.v3");
  }
}
static Arrange_To_Call_Me vS_Vp_B(Test_S_Vp_B, "S_Vp_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B()
{
  {
    init_simple_test("Uc_B");
    Uc_B lv;
    check2(sizeof(lv), 2, "sizeof(Uc_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B)");
    check_field_offset(lv, v1, 0, "Uc_B.v1");
    check_field_offset(lv, v2, 1, "Uc_B.v2");
  }
}
static Arrange_To_Call_Me vUc_B(Test_Uc_B, "Uc_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_B()
{
  {
    init_simple_test("Uc_B_B");
    Uc_B_B lv;
    check2(sizeof(lv), 3, "sizeof(Uc_B_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_B)");
    check_field_offset(lv, v1, 0, "Uc_B_B.v1");
    check_field_offset(lv, v2, 1, "Uc_B_B.v2");
    check_field_offset(lv, v3, 2, "Uc_B_B.v3");
  }
}
static Arrange_To_Call_Me vUc_B_B(Test_Uc_B_B, "Uc_B_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu15i()
{
  {
    init_simple_test("Uc_B_BFu15i");
    static Uc_B_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(Uc_B_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu15i)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu15i.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu15i.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "Uc_B_BFu15i");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "Uc_B_BFu15i");
  }
}
static Arrange_To_Call_Me vUc_B_BFu15i(Test_Uc_B_BFu15i, "Uc_B_BFu15i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu15ll()
{
  {
    init_simple_test("Uc_B_BFu15ll");
    static Uc_B_BFu15ll lv;
    check2(sizeof(lv), 4, "sizeof(Uc_B_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu15ll)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu15ll.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu15ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "Uc_B_BFu15ll");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "Uc_B_BFu15ll");
  }
}
static Arrange_To_Call_Me vUc_B_BFu15ll(Test_Uc_B_BFu15ll, "Uc_B_BFu15ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu15s()
{
  {
    init_simple_test("Uc_B_BFu15s");
    static Uc_B_BFu15s lv;
    check2(sizeof(lv), 4, "sizeof(Uc_B_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu15s)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu15s.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu15s.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "Uc_B_BFu15s");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "Uc_B_BFu15s");
  }
}
static Arrange_To_Call_Me vUc_B_BFu15s(Test_Uc_B_BFu15s, "Uc_B_BFu15s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu16i()
{
  {
    init_simple_test("Uc_B_BFu16i");
    static Uc_B_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(Uc_B_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu16i)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu16i.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu16i.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "Uc_B_BFu16i");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "Uc_B_BFu16i");
  }
}
static Arrange_To_Call_Me vUc_B_BFu16i(Test_Uc_B_BFu16i, "Uc_B_BFu16i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu16ll()
{
  {
    init_simple_test("Uc_B_BFu16ll");
    static Uc_B_BFu16ll lv;
    check2(sizeof(lv), 4, "sizeof(Uc_B_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu16ll)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu16ll.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu16ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "Uc_B_BFu16ll");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "Uc_B_BFu16ll");
  }
}
static Arrange_To_Call_Me vUc_B_BFu16ll(Test_Uc_B_BFu16ll, "Uc_B_BFu16ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu16s()
{
  {
    init_simple_test("Uc_B_BFu16s");
    static Uc_B_BFu16s lv;
    check2(sizeof(lv), 4, "sizeof(Uc_B_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu16s)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu16s.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu16s.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "Uc_B_BFu16s");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "Uc_B_BFu16s");
  }
}
static Arrange_To_Call_Me vUc_B_BFu16s(Test_Uc_B_BFu16s, "Uc_B_BFu16s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu17i()
{
  {
    init_simple_test("Uc_B_BFu17i");
    static Uc_B_BFu17i lv;
    check2(sizeof(lv), 5, "sizeof(Uc_B_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu17i)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu17i.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu17i.v2");
    set_bf_and_test(lv, v3, 2, 0, 17, 1, "Uc_B_BFu17i");
    set_bf_and_test(lv, v3, 2, 0, 17, hide_ull(1LL<<16), "Uc_B_BFu17i");
  }
}
static Arrange_To_Call_Me vUc_B_BFu17i(Test_Uc_B_BFu17i, "Uc_B_BFu17i", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu17ll()
{
  {
    init_simple_test("Uc_B_BFu17ll");
    static Uc_B_BFu17ll lv;
    check2(sizeof(lv), 5, "sizeof(Uc_B_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu17ll)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu17ll.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu17ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 17, 1, "Uc_B_BFu17ll");
    set_bf_and_test(lv, v3, 2, 0, 17, hide_ull(1LL<<16), "Uc_B_BFu17ll");
  }
}
static Arrange_To_Call_Me vUc_B_BFu17ll(Test_Uc_B_BFu17ll, "Uc_B_BFu17ll", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu1c()
{
  {
    init_simple_test("Uc_B_BFu1c");
    static Uc_B_BFu1c lv;
    check2(sizeof(lv), 3, "sizeof(Uc_B_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu1c)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu1c.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu1c.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Uc_B_BFu1c");
  }
}
static Arrange_To_Call_Me vUc_B_BFu1c(Test_Uc_B_BFu1c, "Uc_B_BFu1c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu1i()
{
  {
    init_simple_test("Uc_B_BFu1i");
    static Uc_B_BFu1i lv;
    check2(sizeof(lv), 3, "sizeof(Uc_B_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu1i)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu1i.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu1i.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Uc_B_BFu1i");
  }
}
static Arrange_To_Call_Me vUc_B_BFu1i(Test_Uc_B_BFu1i, "Uc_B_BFu1i", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu1ll()
{
  {
    init_simple_test("Uc_B_BFu1ll");
    static Uc_B_BFu1ll lv;
    check2(sizeof(lv), 3, "sizeof(Uc_B_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu1ll)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu1ll.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu1ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Uc_B_BFu1ll");
  }
}
static Arrange_To_Call_Me vUc_B_BFu1ll(Test_Uc_B_BFu1ll, "Uc_B_BFu1ll", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu1s()
{
  {
    init_simple_test("Uc_B_BFu1s");
    static Uc_B_BFu1s lv;
    check2(sizeof(lv), 3, "sizeof(Uc_B_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu1s)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu1s.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu1s.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Uc_B_BFu1s");
  }
}
static Arrange_To_Call_Me vUc_B_BFu1s(Test_Uc_B_BFu1s, "Uc_B_BFu1s", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu31i()
{
  {
    init_simple_test("Uc_B_BFu31i");
    static Uc_B_BFu31i lv;
    check2(sizeof(lv), 6, "sizeof(Uc_B_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu31i)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu31i.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu31i.v2");
    set_bf_and_test(lv, v3, 2, 0, 31, 1, "Uc_B_BFu31i");
    set_bf_and_test(lv, v3, 2, 0, 31, hide_ull(1LL<<30), "Uc_B_BFu31i");
  }
}
static Arrange_To_Call_Me vUc_B_BFu31i(Test_Uc_B_BFu31i, "Uc_B_BFu31i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu31ll()
{
  {
    init_simple_test("Uc_B_BFu31ll");
    static Uc_B_BFu31ll lv;
    check2(sizeof(lv), 6, "sizeof(Uc_B_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu31ll)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu31ll.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu31ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 31, 1, "Uc_B_BFu31ll");
    set_bf_and_test(lv, v3, 2, 0, 31, hide_ull(1LL<<30), "Uc_B_BFu31ll");
  }
}
static Arrange_To_Call_Me vUc_B_BFu31ll(Test_Uc_B_BFu31ll, "Uc_B_BFu31ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu32i()
{
  {
    init_simple_test("Uc_B_BFu32i");
    static Uc_B_BFu32i lv;
    check2(sizeof(lv), 6, "sizeof(Uc_B_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu32i)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu32i.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu32i.v2");
    set_bf_and_test(lv, v3, 2, 0, 32, 1, "Uc_B_BFu32i");
    set_bf_and_test(lv, v3, 2, 0, 32, hide_ull(1LL<<31), "Uc_B_BFu32i");
  }
}
static Arrange_To_Call_Me vUc_B_BFu32i(Test_Uc_B_BFu32i, "Uc_B_BFu32i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu32ll()
{
  {
    init_simple_test("Uc_B_BFu32ll");
    static Uc_B_BFu32ll lv;
    check2(sizeof(lv), 6, "sizeof(Uc_B_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu32ll)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu32ll.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu32ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 32, 1, "Uc_B_BFu32ll");
    set_bf_and_test(lv, v3, 2, 0, 32, hide_ull(1LL<<31), "Uc_B_BFu32ll");
  }
}
static Arrange_To_Call_Me vUc_B_BFu32ll(Test_Uc_B_BFu32ll, "Uc_B_BFu32ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu33()
{
  {
    init_simple_test("Uc_B_BFu33");
    static Uc_B_BFu33 lv;
    check2(sizeof(lv), 7, "sizeof(Uc_B_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu33)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu33.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu33.v2");
    set_bf_and_test(lv, v3, 2, 0, 33, 1, "Uc_B_BFu33");
    set_bf_and_test(lv, v3, 2, 0, 33, hide_ull(1LL<<32), "Uc_B_BFu33");
  }
}
static Arrange_To_Call_Me vUc_B_BFu33(Test_Uc_B_BFu33, "Uc_B_BFu33", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu7c()
{
  {
    init_simple_test("Uc_B_BFu7c");
    static Uc_B_BFu7c lv;
    check2(sizeof(lv), 3, "sizeof(Uc_B_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu7c)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu7c.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu7c.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Uc_B_BFu7c");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Uc_B_BFu7c");
  }
}
static Arrange_To_Call_Me vUc_B_BFu7c(Test_Uc_B_BFu7c, "Uc_B_BFu7c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu7i()
{
  {
    init_simple_test("Uc_B_BFu7i");
    static Uc_B_BFu7i lv;
    check2(sizeof(lv), 3, "sizeof(Uc_B_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu7i)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu7i.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu7i.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Uc_B_BFu7i");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Uc_B_BFu7i");
  }
}
static Arrange_To_Call_Me vUc_B_BFu7i(Test_Uc_B_BFu7i, "Uc_B_BFu7i", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu7ll()
{
  {
    init_simple_test("Uc_B_BFu7ll");
    static Uc_B_BFu7ll lv;
    check2(sizeof(lv), 3, "sizeof(Uc_B_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu7ll)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu7ll.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu7ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Uc_B_BFu7ll");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Uc_B_BFu7ll");
  }
}
static Arrange_To_Call_Me vUc_B_BFu7ll(Test_Uc_B_BFu7ll, "Uc_B_BFu7ll", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu7s()
{
  {
    init_simple_test("Uc_B_BFu7s");
    static Uc_B_BFu7s lv;
    check2(sizeof(lv), 3, "sizeof(Uc_B_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu7s)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu7s.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu7s.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Uc_B_BFu7s");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Uc_B_BFu7s");
  }
}
static Arrange_To_Call_Me vUc_B_BFu7s(Test_Uc_B_BFu7s, "Uc_B_BFu7s", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu8c()
{
  {
    init_simple_test("Uc_B_BFu8c");
    static Uc_B_BFu8c lv;
    check2(sizeof(lv), 3, "sizeof(Uc_B_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu8c)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu8c.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu8c.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Uc_B_BFu8c");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Uc_B_BFu8c");
  }
}
static Arrange_To_Call_Me vUc_B_BFu8c(Test_Uc_B_BFu8c, "Uc_B_BFu8c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu8i()
{
  {
    init_simple_test("Uc_B_BFu8i");
    static Uc_B_BFu8i lv;
    check2(sizeof(lv), 3, "sizeof(Uc_B_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu8i)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu8i.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu8i.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Uc_B_BFu8i");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Uc_B_BFu8i");
  }
}
static Arrange_To_Call_Me vUc_B_BFu8i(Test_Uc_B_BFu8i, "Uc_B_BFu8i", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu8ll()
{
  {
    init_simple_test("Uc_B_BFu8ll");
    static Uc_B_BFu8ll lv;
    check2(sizeof(lv), 3, "sizeof(Uc_B_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu8ll)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu8ll.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu8ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Uc_B_BFu8ll");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Uc_B_BFu8ll");
  }
}
static Arrange_To_Call_Me vUc_B_BFu8ll(Test_Uc_B_BFu8ll, "Uc_B_BFu8ll", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu8s()
{
  {
    init_simple_test("Uc_B_BFu8s");
    static Uc_B_BFu8s lv;
    check2(sizeof(lv), 3, "sizeof(Uc_B_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu8s)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu8s.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu8s.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Uc_B_BFu8s");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Uc_B_BFu8s");
  }
}
static Arrange_To_Call_Me vUc_B_BFu8s(Test_Uc_B_BFu8s, "Uc_B_BFu8s", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu9i()
{
  {
    init_simple_test("Uc_B_BFu9i");
    static Uc_B_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(Uc_B_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu9i)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu9i.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu9i.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "Uc_B_BFu9i");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "Uc_B_BFu9i");
  }
}
static Arrange_To_Call_Me vUc_B_BFu9i(Test_Uc_B_BFu9i, "Uc_B_BFu9i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu9ll()
{
  {
    init_simple_test("Uc_B_BFu9ll");
    static Uc_B_BFu9ll lv;
    check2(sizeof(lv), 4, "sizeof(Uc_B_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu9ll)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu9ll.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu9ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "Uc_B_BFu9ll");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "Uc_B_BFu9ll");
  }
}
static Arrange_To_Call_Me vUc_B_BFu9ll(Test_Uc_B_BFu9ll, "Uc_B_BFu9ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_BFu9s()
{
  {
    init_simple_test("Uc_B_BFu9s");
    static Uc_B_BFu9s lv;
    check2(sizeof(lv), 4, "sizeof(Uc_B_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu9s)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu9s.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu9s.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "Uc_B_BFu9s");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "Uc_B_BFu9s");
  }
}
static Arrange_To_Call_Me vUc_B_BFu9s(Test_Uc_B_BFu9s, "Uc_B_BFu9s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_C()
{
  {
    init_simple_test("Uc_B_C");
    Uc_B_C lv;
    check2(sizeof(lv), 3, "sizeof(Uc_B_C)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_C)");
    check_field_offset(lv, v1, 0, "Uc_B_C.v1");
    check_field_offset(lv, v2, 1, "Uc_B_C.v2");
    check_field_offset(lv, v3, 2, "Uc_B_C.v3");
  }
}
static Arrange_To_Call_Me vUc_B_C(Test_Uc_B_C, "Uc_B_C", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_D()
{
  {
    init_simple_test("Uc_B_D");
    Uc_B_D lv;
    check2(sizeof(lv), 10, "sizeof(Uc_B_D)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_D)");
    check_field_offset(lv, v1, 0, "Uc_B_D.v1");
    check_field_offset(lv, v2, 1, "Uc_B_D.v2");
    check_field_offset(lv, v3, 2, "Uc_B_D.v3");
  }
}
static Arrange_To_Call_Me vUc_B_D(Test_Uc_B_D, "Uc_B_D", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_F()
{
  {
    init_simple_test("Uc_B_F");
    Uc_B_F lv;
    check2(sizeof(lv), 6, "sizeof(Uc_B_F)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_F)");
    check_field_offset(lv, v1, 0, "Uc_B_F.v1");
    check_field_offset(lv, v2, 1, "Uc_B_F.v2");
    check_field_offset(lv, v3, 2, "Uc_B_F.v3");
  }
}
static Arrange_To_Call_Me vUc_B_F(Test_Uc_B_F, "Uc_B_F", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_I()
{
  {
    init_simple_test("Uc_B_I");
    Uc_B_I lv;
    check2(sizeof(lv), 6, "sizeof(Uc_B_I)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_I)");
    check_field_offset(lv, v1, 0, "Uc_B_I.v1");
    check_field_offset(lv, v2, 1, "Uc_B_I.v2");
    check_field_offset(lv, v3, 2, "Uc_B_I.v3");
  }
}
static Arrange_To_Call_Me vUc_B_I(Test_Uc_B_I, "Uc_B_I", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_Ip()
{
  {
    init_simple_test("Uc_B_Ip");
    Uc_B_Ip lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Uc_B_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_Ip)");
    check_field_offset(lv, v1, 0, "Uc_B_Ip.v1");
    check_field_offset(lv, v2, 1, "Uc_B_Ip.v2");
    check_field_offset(lv, v3, 2, "Uc_B_Ip.v3");
  }
}
static Arrange_To_Call_Me vUc_B_Ip(Test_Uc_B_Ip, "Uc_B_Ip", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_L()
{
  {
    init_simple_test("Uc_B_L");
    Uc_B_L lv;
    check2(sizeof(lv), 10, "sizeof(Uc_B_L)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_L)");
    check_field_offset(lv, v1, 0, "Uc_B_L.v1");
    check_field_offset(lv, v2, 1, "Uc_B_L.v2");
    check_field_offset(lv, v3, 2, "Uc_B_L.v3");
  }
}
static Arrange_To_Call_Me vUc_B_L(Test_Uc_B_L, "Uc_B_L", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_S()
{
  {
    init_simple_test("Uc_B_S");
    Uc_B_S lv;
    check2(sizeof(lv), 4, "sizeof(Uc_B_S)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_S)");
    check_field_offset(lv, v1, 0, "Uc_B_S.v1");
    check_field_offset(lv, v2, 1, "Uc_B_S.v2");
    check_field_offset(lv, v3, 2, "Uc_B_S.v3");
  }
}
static Arrange_To_Call_Me vUc_B_S(Test_Uc_B_S, "Uc_B_S", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_Uc()
{
  {
    init_simple_test("Uc_B_Uc");
    Uc_B_Uc lv;
    check2(sizeof(lv), 3, "sizeof(Uc_B_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_Uc)");
    check_field_offset(lv, v1, 0, "Uc_B_Uc.v1");
    check_field_offset(lv, v2, 1, "Uc_B_Uc.v2");
    check_field_offset(lv, v3, 2, "Uc_B_Uc.v3");
  }
}
static Arrange_To_Call_Me vUc_B_Uc(Test_Uc_B_Uc, "Uc_B_Uc", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_Ui()
{
  {
    init_simple_test("Uc_B_Ui");
    Uc_B_Ui lv;
    check2(sizeof(lv), 6, "sizeof(Uc_B_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_Ui)");
    check_field_offset(lv, v1, 0, "Uc_B_Ui.v1");
    check_field_offset(lv, v2, 1, "Uc_B_Ui.v2");
    check_field_offset(lv, v3, 2, "Uc_B_Ui.v3");
  }
}
static Arrange_To_Call_Me vUc_B_Ui(Test_Uc_B_Ui, "Uc_B_Ui", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_Ul()
{
  {
    init_simple_test("Uc_B_Ul");
    Uc_B_Ul lv;
    check2(sizeof(lv), 10, "sizeof(Uc_B_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_Ul)");
    check_field_offset(lv, v1, 0, "Uc_B_Ul.v1");
    check_field_offset(lv, v2, 1, "Uc_B_Ul.v2");
    check_field_offset(lv, v3, 2, "Uc_B_Ul.v3");
  }
}
static Arrange_To_Call_Me vUc_B_Ul(Test_Uc_B_Ul, "Uc_B_Ul", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_Us()
{
  {
    init_simple_test("Uc_B_Us");
    Uc_B_Us lv;
    check2(sizeof(lv), 4, "sizeof(Uc_B_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_Us)");
    check_field_offset(lv, v1, 0, "Uc_B_Us.v1");
    check_field_offset(lv, v2, 1, "Uc_B_Us.v2");
    check_field_offset(lv, v3, 2, "Uc_B_Us.v3");
  }
}
static Arrange_To_Call_Me vUc_B_Us(Test_Uc_B_Us, "Uc_B_Us", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_B_Vp()
{
  {
    init_simple_test("Uc_B_Vp");
    Uc_B_Vp lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Uc_B_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_Vp)");
    check_field_offset(lv, v1, 0, "Uc_B_Vp.v1");
    check_field_offset(lv, v2, 1, "Uc_B_Vp.v2");
    check_field_offset(lv, v3, 2, "Uc_B_Vp.v3");
  }
}
static Arrange_To_Call_Me vUc_B_Vp(Test_Uc_B_Vp, "Uc_B_Vp", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu15i_B()
{
  {
    init_simple_test("Uc_BFu15i_B");
    static Uc_BFu15i_B lv;
    check2(sizeof(lv), 4, "sizeof(Uc_BFu15i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu15i_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu15i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "Uc_BFu15i_B");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "Uc_BFu15i_B");
    check_field_offset(lv, v3, 3, "Uc_BFu15i_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu15i_B(Test_Uc_BFu15i_B, "Uc_BFu15i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu15ll_B()
{
  {
    init_simple_test("Uc_BFu15ll_B");
    static Uc_BFu15ll_B lv;
    check2(sizeof(lv), 4, "sizeof(Uc_BFu15ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu15ll_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu15ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "Uc_BFu15ll_B");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "Uc_BFu15ll_B");
    check_field_offset(lv, v3, 3, "Uc_BFu15ll_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu15ll_B(Test_Uc_BFu15ll_B, "Uc_BFu15ll_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu15s_B()
{
  {
    init_simple_test("Uc_BFu15s_B");
    static Uc_BFu15s_B lv;
    check2(sizeof(lv), 4, "sizeof(Uc_BFu15s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu15s_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu15s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "Uc_BFu15s_B");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "Uc_BFu15s_B");
    check_field_offset(lv, v3, 3, "Uc_BFu15s_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu15s_B(Test_Uc_BFu15s_B, "Uc_BFu15s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu16i_B()
{
  {
    init_simple_test("Uc_BFu16i_B");
    static Uc_BFu16i_B lv;
    check2(sizeof(lv), 4, "sizeof(Uc_BFu16i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu16i_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu16i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "Uc_BFu16i_B");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "Uc_BFu16i_B");
    check_field_offset(lv, v3, 3, "Uc_BFu16i_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu16i_B(Test_Uc_BFu16i_B, "Uc_BFu16i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu16ll_B()
{
  {
    init_simple_test("Uc_BFu16ll_B");
    static Uc_BFu16ll_B lv;
    check2(sizeof(lv), 4, "sizeof(Uc_BFu16ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu16ll_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu16ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "Uc_BFu16ll_B");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "Uc_BFu16ll_B");
    check_field_offset(lv, v3, 3, "Uc_BFu16ll_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu16ll_B(Test_Uc_BFu16ll_B, "Uc_BFu16ll_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu16s_B()
{
  {
    init_simple_test("Uc_BFu16s_B");
    static Uc_BFu16s_B lv;
    check2(sizeof(lv), 4, "sizeof(Uc_BFu16s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu16s_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu16s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "Uc_BFu16s_B");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "Uc_BFu16s_B");
    check_field_offset(lv, v3, 3, "Uc_BFu16s_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu16s_B(Test_Uc_BFu16s_B, "Uc_BFu16s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu17i_B()
{
  {
    init_simple_test("Uc_BFu17i_B");
    static Uc_BFu17i_B lv;
    check2(sizeof(lv), 5, "sizeof(Uc_BFu17i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu17i_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu17i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "Uc_BFu17i_B");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "Uc_BFu17i_B");
    check_field_offset(lv, v3, 4, "Uc_BFu17i_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu17i_B(Test_Uc_BFu17i_B, "Uc_BFu17i_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu17ll_B()
{
  {
    init_simple_test("Uc_BFu17ll_B");
    static Uc_BFu17ll_B lv;
    check2(sizeof(lv), 5, "sizeof(Uc_BFu17ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu17ll_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu17ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "Uc_BFu17ll_B");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "Uc_BFu17ll_B");
    check_field_offset(lv, v3, 4, "Uc_BFu17ll_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu17ll_B(Test_Uc_BFu17ll_B, "Uc_BFu17ll_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu1c_B()
{
  {
    init_simple_test("Uc_BFu1c_B");
    static Uc_BFu1c_B lv;
    check2(sizeof(lv), 3, "sizeof(Uc_BFu1c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu1c_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu1c_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "Uc_BFu1c_B");
    check_field_offset(lv, v3, 2, "Uc_BFu1c_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu1c_B(Test_Uc_BFu1c_B, "Uc_BFu1c_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu1i_B()
{
  {
    init_simple_test("Uc_BFu1i_B");
    static Uc_BFu1i_B lv;
    check2(sizeof(lv), 3, "sizeof(Uc_BFu1i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu1i_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu1i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "Uc_BFu1i_B");
    check_field_offset(lv, v3, 2, "Uc_BFu1i_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu1i_B(Test_Uc_BFu1i_B, "Uc_BFu1i_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu1ll_B()
{
  {
    init_simple_test("Uc_BFu1ll_B");
    static Uc_BFu1ll_B lv;
    check2(sizeof(lv), 3, "sizeof(Uc_BFu1ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu1ll_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu1ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "Uc_BFu1ll_B");
    check_field_offset(lv, v3, 2, "Uc_BFu1ll_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu1ll_B(Test_Uc_BFu1ll_B, "Uc_BFu1ll_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu1s_B()
{
  {
    init_simple_test("Uc_BFu1s_B");
    static Uc_BFu1s_B lv;
    check2(sizeof(lv), 3, "sizeof(Uc_BFu1s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu1s_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu1s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "Uc_BFu1s_B");
    check_field_offset(lv, v3, 2, "Uc_BFu1s_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu1s_B(Test_Uc_BFu1s_B, "Uc_BFu1s_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu31i_B()
{
  {
    init_simple_test("Uc_BFu31i_B");
    static Uc_BFu31i_B lv;
    check2(sizeof(lv), 6, "sizeof(Uc_BFu31i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu31i_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu31i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "Uc_BFu31i_B");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "Uc_BFu31i_B");
    check_field_offset(lv, v3, 5, "Uc_BFu31i_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu31i_B(Test_Uc_BFu31i_B, "Uc_BFu31i_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu31ll_B()
{
  {
    init_simple_test("Uc_BFu31ll_B");
    static Uc_BFu31ll_B lv;
    check2(sizeof(lv), 6, "sizeof(Uc_BFu31ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu31ll_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu31ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "Uc_BFu31ll_B");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "Uc_BFu31ll_B");
    check_field_offset(lv, v3, 5, "Uc_BFu31ll_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu31ll_B(Test_Uc_BFu31ll_B, "Uc_BFu31ll_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu32i_B()
{
  {
    init_simple_test("Uc_BFu32i_B");
    static Uc_BFu32i_B lv;
    check2(sizeof(lv), 6, "sizeof(Uc_BFu32i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu32i_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu32i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "Uc_BFu32i_B");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "Uc_BFu32i_B");
    check_field_offset(lv, v3, 5, "Uc_BFu32i_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu32i_B(Test_Uc_BFu32i_B, "Uc_BFu32i_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu32ll_B()
{
  {
    init_simple_test("Uc_BFu32ll_B");
    static Uc_BFu32ll_B lv;
    check2(sizeof(lv), 6, "sizeof(Uc_BFu32ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu32ll_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu32ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "Uc_BFu32ll_B");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "Uc_BFu32ll_B");
    check_field_offset(lv, v3, 5, "Uc_BFu32ll_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu32ll_B(Test_Uc_BFu32ll_B, "Uc_BFu32ll_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu33_B()
{
  {
    init_simple_test("Uc_BFu33_B");
    static Uc_BFu33_B lv;
    check2(sizeof(lv), 7, "sizeof(Uc_BFu33_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu33_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu33_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 33, 1, "Uc_BFu33_B");
    set_bf_and_test(lv, v2, 1, 0, 33, hide_ull(1LL<<32), "Uc_BFu33_B");
    check_field_offset(lv, v3, 6, "Uc_BFu33_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu33_B(Test_Uc_BFu33_B, "Uc_BFu33_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu7c_B()
{
  {
    init_simple_test("Uc_BFu7c_B");
    static Uc_BFu7c_B lv;
    check2(sizeof(lv), 3, "sizeof(Uc_BFu7c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu7c_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu7c_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "Uc_BFu7c_B");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "Uc_BFu7c_B");
    check_field_offset(lv, v3, 2, "Uc_BFu7c_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu7c_B(Test_Uc_BFu7c_B, "Uc_BFu7c_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu7i_B()
{
  {
    init_simple_test("Uc_BFu7i_B");
    static Uc_BFu7i_B lv;
    check2(sizeof(lv), 3, "sizeof(Uc_BFu7i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu7i_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu7i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "Uc_BFu7i_B");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "Uc_BFu7i_B");
    check_field_offset(lv, v3, 2, "Uc_BFu7i_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu7i_B(Test_Uc_BFu7i_B, "Uc_BFu7i_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu7ll_B()
{
  {
    init_simple_test("Uc_BFu7ll_B");
    static Uc_BFu7ll_B lv;
    check2(sizeof(lv), 3, "sizeof(Uc_BFu7ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu7ll_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu7ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "Uc_BFu7ll_B");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "Uc_BFu7ll_B");
    check_field_offset(lv, v3, 2, "Uc_BFu7ll_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu7ll_B(Test_Uc_BFu7ll_B, "Uc_BFu7ll_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu7s_B()
{
  {
    init_simple_test("Uc_BFu7s_B");
    static Uc_BFu7s_B lv;
    check2(sizeof(lv), 3, "sizeof(Uc_BFu7s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu7s_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu7s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "Uc_BFu7s_B");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "Uc_BFu7s_B");
    check_field_offset(lv, v3, 2, "Uc_BFu7s_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu7s_B(Test_Uc_BFu7s_B, "Uc_BFu7s_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu8c_B()
{
  {
    init_simple_test("Uc_BFu8c_B");
    static Uc_BFu8c_B lv;
    check2(sizeof(lv), 3, "sizeof(Uc_BFu8c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu8c_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu8c_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "Uc_BFu8c_B");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "Uc_BFu8c_B");
    check_field_offset(lv, v3, 2, "Uc_BFu8c_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu8c_B(Test_Uc_BFu8c_B, "Uc_BFu8c_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu8i_B()
{
  {
    init_simple_test("Uc_BFu8i_B");
    static Uc_BFu8i_B lv;
    check2(sizeof(lv), 3, "sizeof(Uc_BFu8i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu8i_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu8i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "Uc_BFu8i_B");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "Uc_BFu8i_B");
    check_field_offset(lv, v3, 2, "Uc_BFu8i_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu8i_B(Test_Uc_BFu8i_B, "Uc_BFu8i_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu8ll_B()
{
  {
    init_simple_test("Uc_BFu8ll_B");
    static Uc_BFu8ll_B lv;
    check2(sizeof(lv), 3, "sizeof(Uc_BFu8ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu8ll_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu8ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "Uc_BFu8ll_B");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "Uc_BFu8ll_B");
    check_field_offset(lv, v3, 2, "Uc_BFu8ll_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu8ll_B(Test_Uc_BFu8ll_B, "Uc_BFu8ll_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu8s_B()
{
  {
    init_simple_test("Uc_BFu8s_B");
    static Uc_BFu8s_B lv;
    check2(sizeof(lv), 3, "sizeof(Uc_BFu8s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu8s_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu8s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "Uc_BFu8s_B");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "Uc_BFu8s_B");
    check_field_offset(lv, v3, 2, "Uc_BFu8s_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu8s_B(Test_Uc_BFu8s_B, "Uc_BFu8s_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu9i_B()
{
  {
    init_simple_test("Uc_BFu9i_B");
    static Uc_BFu9i_B lv;
    check2(sizeof(lv), 4, "sizeof(Uc_BFu9i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu9i_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu9i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "Uc_BFu9i_B");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "Uc_BFu9i_B");
    check_field_offset(lv, v3, 3, "Uc_BFu9i_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu9i_B(Test_Uc_BFu9i_B, "Uc_BFu9i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu9ll_B()
{
  {
    init_simple_test("Uc_BFu9ll_B");
    static Uc_BFu9ll_B lv;
    check2(sizeof(lv), 4, "sizeof(Uc_BFu9ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu9ll_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu9ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "Uc_BFu9ll_B");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "Uc_BFu9ll_B");
    check_field_offset(lv, v3, 3, "Uc_BFu9ll_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu9ll_B(Test_Uc_BFu9ll_B, "Uc_BFu9ll_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_BFu9s_B()
{
  {
    init_simple_test("Uc_BFu9s_B");
    static Uc_BFu9s_B lv;
    check2(sizeof(lv), 4, "sizeof(Uc_BFu9s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu9s_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu9s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "Uc_BFu9s_B");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "Uc_BFu9s_B");
    check_field_offset(lv, v3, 3, "Uc_BFu9s_B.v3");
  }
}
static Arrange_To_Call_Me vUc_BFu9s_B(Test_Uc_BFu9s_B, "Uc_BFu9s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_C_B()
{
  {
    init_simple_test("Uc_C_B");
    Uc_C_B lv;
    check2(sizeof(lv), 3, "sizeof(Uc_C_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_C_B)");
    check_field_offset(lv, v1, 0, "Uc_C_B.v1");
    check_field_offset(lv, v2, 1, "Uc_C_B.v2");
    check_field_offset(lv, v3, 2, "Uc_C_B.v3");
  }
}
static Arrange_To_Call_Me vUc_C_B(Test_Uc_C_B, "Uc_C_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_D_B()
{
  {
    init_simple_test("Uc_D_B");
    Uc_D_B lv;
    check2(sizeof(lv), 10, "sizeof(Uc_D_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_D_B)");
    check_field_offset(lv, v1, 0, "Uc_D_B.v1");
    check_field_offset(lv, v2, 1, "Uc_D_B.v2");
    check_field_offset(lv, v3, 9, "Uc_D_B.v3");
  }
}
static Arrange_To_Call_Me vUc_D_B(Test_Uc_D_B, "Uc_D_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_F_B()
{
  {
    init_simple_test("Uc_F_B");
    Uc_F_B lv;
    check2(sizeof(lv), 6, "sizeof(Uc_F_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_F_B)");
    check_field_offset(lv, v1, 0, "Uc_F_B.v1");
    check_field_offset(lv, v2, 1, "Uc_F_B.v2");
    check_field_offset(lv, v3, 5, "Uc_F_B.v3");
  }
}
static Arrange_To_Call_Me vUc_F_B(Test_Uc_F_B, "Uc_F_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_I_B()
{
  {
    init_simple_test("Uc_I_B");
    Uc_I_B lv;
    check2(sizeof(lv), 6, "sizeof(Uc_I_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_I_B)");
    check_field_offset(lv, v1, 0, "Uc_I_B.v1");
    check_field_offset(lv, v2, 1, "Uc_I_B.v2");
    check_field_offset(lv, v3, 5, "Uc_I_B.v3");
  }
}
static Arrange_To_Call_Me vUc_I_B(Test_Uc_I_B, "Uc_I_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_Ip_B()
{
  {
    init_simple_test("Uc_Ip_B");
    Uc_Ip_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Uc_Ip_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Ip_B)");
    check_field_offset(lv, v1, 0, "Uc_Ip_B.v1");
    check_field_offset(lv, v2, 1, "Uc_Ip_B.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Uc_Ip_B.v3");
  }
}
static Arrange_To_Call_Me vUc_Ip_B(Test_Uc_Ip_B, "Uc_Ip_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_L_B()
{
  {
    init_simple_test("Uc_L_B");
    Uc_L_B lv;
    check2(sizeof(lv), 10, "sizeof(Uc_L_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_L_B)");
    check_field_offset(lv, v1, 0, "Uc_L_B.v1");
    check_field_offset(lv, v2, 1, "Uc_L_B.v2");
    check_field_offset(lv, v3, 9, "Uc_L_B.v3");
  }
}
static Arrange_To_Call_Me vUc_L_B(Test_Uc_L_B, "Uc_L_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_S_B()
{
  {
    init_simple_test("Uc_S_B");
    Uc_S_B lv;
    check2(sizeof(lv), 4, "sizeof(Uc_S_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_S_B)");
    check_field_offset(lv, v1, 0, "Uc_S_B.v1");
    check_field_offset(lv, v2, 1, "Uc_S_B.v2");
    check_field_offset(lv, v3, 3, "Uc_S_B.v3");
  }
}
static Arrange_To_Call_Me vUc_S_B(Test_Uc_S_B, "Uc_S_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_Uc_B()
{
  {
    init_simple_test("Uc_Uc_B");
    Uc_Uc_B lv;
    check2(sizeof(lv), 3, "sizeof(Uc_Uc_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Uc_B)");
    check_field_offset(lv, v1, 0, "Uc_Uc_B.v1");
    check_field_offset(lv, v2, 1, "Uc_Uc_B.v2");
    check_field_offset(lv, v3, 2, "Uc_Uc_B.v3");
  }
}
static Arrange_To_Call_Me vUc_Uc_B(Test_Uc_Uc_B, "Uc_Uc_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_Ui_B()
{
  {
    init_simple_test("Uc_Ui_B");
    Uc_Ui_B lv;
    check2(sizeof(lv), 6, "sizeof(Uc_Ui_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Ui_B)");
    check_field_offset(lv, v1, 0, "Uc_Ui_B.v1");
    check_field_offset(lv, v2, 1, "Uc_Ui_B.v2");
    check_field_offset(lv, v3, 5, "Uc_Ui_B.v3");
  }
}
static Arrange_To_Call_Me vUc_Ui_B(Test_Uc_Ui_B, "Uc_Ui_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_Ul_B()
{
  {
    init_simple_test("Uc_Ul_B");
    Uc_Ul_B lv;
    check2(sizeof(lv), 10, "sizeof(Uc_Ul_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Ul_B)");
    check_field_offset(lv, v1, 0, "Uc_Ul_B.v1");
    check_field_offset(lv, v2, 1, "Uc_Ul_B.v2");
    check_field_offset(lv, v3, 9, "Uc_Ul_B.v3");
  }
}
static Arrange_To_Call_Me vUc_Ul_B(Test_Uc_Ul_B, "Uc_Ul_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_Us_B()
{
  {
    init_simple_test("Uc_Us_B");
    Uc_Us_B lv;
    check2(sizeof(lv), 4, "sizeof(Uc_Us_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Us_B)");
    check_field_offset(lv, v1, 0, "Uc_Us_B.v1");
    check_field_offset(lv, v2, 1, "Uc_Us_B.v2");
    check_field_offset(lv, v3, 3, "Uc_Us_B.v3");
  }
}
static Arrange_To_Call_Me vUc_Us_B(Test_Uc_Us_B, "Uc_Us_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Uc_Vp_B()
{
  {
    init_simple_test("Uc_Vp_B");
    Uc_Vp_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Uc_Vp_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Vp_B)");
    check_field_offset(lv, v1, 0, "Uc_Vp_B.v1");
    check_field_offset(lv, v2, 1, "Uc_Vp_B.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Uc_Vp_B.v3");
  }
}
static Arrange_To_Call_Me vUc_Vp_B(Test_Uc_Vp_B, "Uc_Vp_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B()
{
  {
    init_simple_test("Ui_B");
    Ui_B lv;
    check2(sizeof(lv), 5, "sizeof(Ui_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B)");
    check_field_offset(lv, v1, 0, "Ui_B.v1");
    check_field_offset(lv, v2, 4, "Ui_B.v2");
  }
}
static Arrange_To_Call_Me vUi_B(Test_Ui_B, "Ui_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_B()
{
  {
    init_simple_test("Ui_B_B");
    Ui_B_B lv;
    check2(sizeof(lv), 6, "sizeof(Ui_B_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_B)");
    check_field_offset(lv, v1, 0, "Ui_B_B.v1");
    check_field_offset(lv, v2, 4, "Ui_B_B.v2");
    check_field_offset(lv, v3, 5, "Ui_B_B.v3");
  }
}
static Arrange_To_Call_Me vUi_B_B(Test_Ui_B_B, "Ui_B_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu15i()
{
  {
    init_simple_test("Ui_B_BFu15i");
    static Ui_B_BFu15i lv;
    check2(sizeof(lv), 7, "sizeof(Ui_B_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu15i)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu15i.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu15i.v2");
    set_bf_and_test(lv, v3, 5, 0, 15, 1, "Ui_B_BFu15i");
    set_bf_and_test(lv, v3, 5, 0, 15, hide_ull(1LL<<14), "Ui_B_BFu15i");
  }
}
static Arrange_To_Call_Me vUi_B_BFu15i(Test_Ui_B_BFu15i, "Ui_B_BFu15i", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu15ll()
{
  {
    init_simple_test("Ui_B_BFu15ll");
    static Ui_B_BFu15ll lv;
    check2(sizeof(lv), 7, "sizeof(Ui_B_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu15ll)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu15ll.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu15ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 15, 1, "Ui_B_BFu15ll");
    set_bf_and_test(lv, v3, 5, 0, 15, hide_ull(1LL<<14), "Ui_B_BFu15ll");
  }
}
static Arrange_To_Call_Me vUi_B_BFu15ll(Test_Ui_B_BFu15ll, "Ui_B_BFu15ll", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu15s()
{
  {
    init_simple_test("Ui_B_BFu15s");
    static Ui_B_BFu15s lv;
    check2(sizeof(lv), 7, "sizeof(Ui_B_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu15s)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu15s.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu15s.v2");
    set_bf_and_test(lv, v3, 5, 0, 15, 1, "Ui_B_BFu15s");
    set_bf_and_test(lv, v3, 5, 0, 15, hide_ull(1LL<<14), "Ui_B_BFu15s");
  }
}
static Arrange_To_Call_Me vUi_B_BFu15s(Test_Ui_B_BFu15s, "Ui_B_BFu15s", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu16i()
{
  {
    init_simple_test("Ui_B_BFu16i");
    static Ui_B_BFu16i lv;
    check2(sizeof(lv), 7, "sizeof(Ui_B_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu16i)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu16i.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu16i.v2");
    set_bf_and_test(lv, v3, 5, 0, 16, 1, "Ui_B_BFu16i");
    set_bf_and_test(lv, v3, 5, 0, 16, hide_ull(1LL<<15), "Ui_B_BFu16i");
  }
}
static Arrange_To_Call_Me vUi_B_BFu16i(Test_Ui_B_BFu16i, "Ui_B_BFu16i", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu16ll()
{
  {
    init_simple_test("Ui_B_BFu16ll");
    static Ui_B_BFu16ll lv;
    check2(sizeof(lv), 7, "sizeof(Ui_B_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu16ll)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu16ll.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu16ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 16, 1, "Ui_B_BFu16ll");
    set_bf_and_test(lv, v3, 5, 0, 16, hide_ull(1LL<<15), "Ui_B_BFu16ll");
  }
}
static Arrange_To_Call_Me vUi_B_BFu16ll(Test_Ui_B_BFu16ll, "Ui_B_BFu16ll", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu16s()
{
  {
    init_simple_test("Ui_B_BFu16s");
    static Ui_B_BFu16s lv;
    check2(sizeof(lv), 7, "sizeof(Ui_B_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu16s)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu16s.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu16s.v2");
    set_bf_and_test(lv, v3, 5, 0, 16, 1, "Ui_B_BFu16s");
    set_bf_and_test(lv, v3, 5, 0, 16, hide_ull(1LL<<15), "Ui_B_BFu16s");
  }
}
static Arrange_To_Call_Me vUi_B_BFu16s(Test_Ui_B_BFu16s, "Ui_B_BFu16s", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu17i()
{
  {
    init_simple_test("Ui_B_BFu17i");
    static Ui_B_BFu17i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_B_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu17i)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu17i.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu17i.v2");
    set_bf_and_test(lv, v3, 5, 0, 17, 1, "Ui_B_BFu17i");
    set_bf_and_test(lv, v3, 5, 0, 17, hide_ull(1LL<<16), "Ui_B_BFu17i");
  }
}
static Arrange_To_Call_Me vUi_B_BFu17i(Test_Ui_B_BFu17i, "Ui_B_BFu17i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu17ll()
{
  {
    init_simple_test("Ui_B_BFu17ll");
    static Ui_B_BFu17ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_B_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu17ll)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu17ll.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu17ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 17, 1, "Ui_B_BFu17ll");
    set_bf_and_test(lv, v3, 5, 0, 17, hide_ull(1LL<<16), "Ui_B_BFu17ll");
  }
}
static Arrange_To_Call_Me vUi_B_BFu17ll(Test_Ui_B_BFu17ll, "Ui_B_BFu17ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu1c()
{
  {
    init_simple_test("Ui_B_BFu1c");
    static Ui_B_BFu1c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_B_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu1c)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu1c.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu1c.v2");
    set_bf_and_test(lv, v3, 5, 0, 1, 1, "Ui_B_BFu1c");
  }
}
static Arrange_To_Call_Me vUi_B_BFu1c(Test_Ui_B_BFu1c, "Ui_B_BFu1c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu1i()
{
  {
    init_simple_test("Ui_B_BFu1i");
    static Ui_B_BFu1i lv;
    check2(sizeof(lv), 6, "sizeof(Ui_B_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu1i)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu1i.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu1i.v2");
    set_bf_and_test(lv, v3, 5, 0, 1, 1, "Ui_B_BFu1i");
  }
}
static Arrange_To_Call_Me vUi_B_BFu1i(Test_Ui_B_BFu1i, "Ui_B_BFu1i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu1ll()
{
  {
    init_simple_test("Ui_B_BFu1ll");
    static Ui_B_BFu1ll lv;
    check2(sizeof(lv), 6, "sizeof(Ui_B_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu1ll)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu1ll.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu1ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 1, 1, "Ui_B_BFu1ll");
  }
}
static Arrange_To_Call_Me vUi_B_BFu1ll(Test_Ui_B_BFu1ll, "Ui_B_BFu1ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu1s()
{
  {
    init_simple_test("Ui_B_BFu1s");
    static Ui_B_BFu1s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_B_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu1s)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu1s.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu1s.v2");
    set_bf_and_test(lv, v3, 5, 0, 1, 1, "Ui_B_BFu1s");
  }
}
static Arrange_To_Call_Me vUi_B_BFu1s(Test_Ui_B_BFu1s, "Ui_B_BFu1s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu31i()
{
  {
    init_simple_test("Ui_B_BFu31i");
    static Ui_B_BFu31i lv;
    check2(sizeof(lv), 9, "sizeof(Ui_B_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu31i)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu31i.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu31i.v2");
    set_bf_and_test(lv, v3, 5, 0, 31, 1, "Ui_B_BFu31i");
    set_bf_and_test(lv, v3, 5, 0, 31, hide_ull(1LL<<30), "Ui_B_BFu31i");
  }
}
static Arrange_To_Call_Me vUi_B_BFu31i(Test_Ui_B_BFu31i, "Ui_B_BFu31i", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu31ll()
{
  {
    init_simple_test("Ui_B_BFu31ll");
    static Ui_B_BFu31ll lv;
    check2(sizeof(lv), 9, "sizeof(Ui_B_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu31ll)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu31ll.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu31ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 31, 1, "Ui_B_BFu31ll");
    set_bf_and_test(lv, v3, 5, 0, 31, hide_ull(1LL<<30), "Ui_B_BFu31ll");
  }
}
static Arrange_To_Call_Me vUi_B_BFu31ll(Test_Ui_B_BFu31ll, "Ui_B_BFu31ll", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu32i()
{
  {
    init_simple_test("Ui_B_BFu32i");
    static Ui_B_BFu32i lv;
    check2(sizeof(lv), 9, "sizeof(Ui_B_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu32i)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu32i.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu32i.v2");
    set_bf_and_test(lv, v3, 5, 0, 32, 1, "Ui_B_BFu32i");
    set_bf_and_test(lv, v3, 5, 0, 32, hide_ull(1LL<<31), "Ui_B_BFu32i");
  }
}
static Arrange_To_Call_Me vUi_B_BFu32i(Test_Ui_B_BFu32i, "Ui_B_BFu32i", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu32ll()
{
  {
    init_simple_test("Ui_B_BFu32ll");
    static Ui_B_BFu32ll lv;
    check2(sizeof(lv), 9, "sizeof(Ui_B_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu32ll)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu32ll.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu32ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 32, 1, "Ui_B_BFu32ll");
    set_bf_and_test(lv, v3, 5, 0, 32, hide_ull(1LL<<31), "Ui_B_BFu32ll");
  }
}
static Arrange_To_Call_Me vUi_B_BFu32ll(Test_Ui_B_BFu32ll, "Ui_B_BFu32ll", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu33()
{
  {
    init_simple_test("Ui_B_BFu33");
    static Ui_B_BFu33 lv;
    check2(sizeof(lv), 10, "sizeof(Ui_B_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu33)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu33.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu33.v2");
    set_bf_and_test(lv, v3, 5, 0, 33, 1, "Ui_B_BFu33");
    set_bf_and_test(lv, v3, 5, 0, 33, hide_ull(1LL<<32), "Ui_B_BFu33");
  }
}
static Arrange_To_Call_Me vUi_B_BFu33(Test_Ui_B_BFu33, "Ui_B_BFu33", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu7c()
{
  {
    init_simple_test("Ui_B_BFu7c");
    static Ui_B_BFu7c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_B_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu7c)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu7c.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu7c.v2");
    set_bf_and_test(lv, v3, 5, 0, 7, 1, "Ui_B_BFu7c");
    set_bf_and_test(lv, v3, 5, 0, 7, hide_ull(1LL<<6), "Ui_B_BFu7c");
  }
}
static Arrange_To_Call_Me vUi_B_BFu7c(Test_Ui_B_BFu7c, "Ui_B_BFu7c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu7i()
{
  {
    init_simple_test("Ui_B_BFu7i");
    static Ui_B_BFu7i lv;
    check2(sizeof(lv), 6, "sizeof(Ui_B_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu7i)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu7i.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu7i.v2");
    set_bf_and_test(lv, v3, 5, 0, 7, 1, "Ui_B_BFu7i");
    set_bf_and_test(lv, v3, 5, 0, 7, hide_ull(1LL<<6), "Ui_B_BFu7i");
  }
}
static Arrange_To_Call_Me vUi_B_BFu7i(Test_Ui_B_BFu7i, "Ui_B_BFu7i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu7ll()
{
  {
    init_simple_test("Ui_B_BFu7ll");
    static Ui_B_BFu7ll lv;
    check2(sizeof(lv), 6, "sizeof(Ui_B_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu7ll)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu7ll.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu7ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 7, 1, "Ui_B_BFu7ll");
    set_bf_and_test(lv, v3, 5, 0, 7, hide_ull(1LL<<6), "Ui_B_BFu7ll");
  }
}
static Arrange_To_Call_Me vUi_B_BFu7ll(Test_Ui_B_BFu7ll, "Ui_B_BFu7ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu7s()
{
  {
    init_simple_test("Ui_B_BFu7s");
    static Ui_B_BFu7s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_B_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu7s)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu7s.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu7s.v2");
    set_bf_and_test(lv, v3, 5, 0, 7, 1, "Ui_B_BFu7s");
    set_bf_and_test(lv, v3, 5, 0, 7, hide_ull(1LL<<6), "Ui_B_BFu7s");
  }
}
static Arrange_To_Call_Me vUi_B_BFu7s(Test_Ui_B_BFu7s, "Ui_B_BFu7s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu8c()
{
  {
    init_simple_test("Ui_B_BFu8c");
    static Ui_B_BFu8c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_B_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu8c)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu8c.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu8c.v2");
    set_bf_and_test(lv, v3, 5, 0, 8, 1, "Ui_B_BFu8c");
    set_bf_and_test(lv, v3, 5, 0, 8, hide_ull(1LL<<7), "Ui_B_BFu8c");
  }
}
static Arrange_To_Call_Me vUi_B_BFu8c(Test_Ui_B_BFu8c, "Ui_B_BFu8c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu8i()
{
  {
    init_simple_test("Ui_B_BFu8i");
    static Ui_B_BFu8i lv;
    check2(sizeof(lv), 6, "sizeof(Ui_B_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu8i)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu8i.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu8i.v2");
    set_bf_and_test(lv, v3, 5, 0, 8, 1, "Ui_B_BFu8i");
    set_bf_and_test(lv, v3, 5, 0, 8, hide_ull(1LL<<7), "Ui_B_BFu8i");
  }
}
static Arrange_To_Call_Me vUi_B_BFu8i(Test_Ui_B_BFu8i, "Ui_B_BFu8i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu8ll()
{
  {
    init_simple_test("Ui_B_BFu8ll");
    static Ui_B_BFu8ll lv;
    check2(sizeof(lv), 6, "sizeof(Ui_B_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu8ll)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu8ll.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu8ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 8, 1, "Ui_B_BFu8ll");
    set_bf_and_test(lv, v3, 5, 0, 8, hide_ull(1LL<<7), "Ui_B_BFu8ll");
  }
}
static Arrange_To_Call_Me vUi_B_BFu8ll(Test_Ui_B_BFu8ll, "Ui_B_BFu8ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu8s()
{
  {
    init_simple_test("Ui_B_BFu8s");
    static Ui_B_BFu8s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_B_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu8s)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu8s.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu8s.v2");
    set_bf_and_test(lv, v3, 5, 0, 8, 1, "Ui_B_BFu8s");
    set_bf_and_test(lv, v3, 5, 0, 8, hide_ull(1LL<<7), "Ui_B_BFu8s");
  }
}
static Arrange_To_Call_Me vUi_B_BFu8s(Test_Ui_B_BFu8s, "Ui_B_BFu8s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu9i()
{
  {
    init_simple_test("Ui_B_BFu9i");
    static Ui_B_BFu9i lv;
    check2(sizeof(lv), 7, "sizeof(Ui_B_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu9i)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu9i.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu9i.v2");
    set_bf_and_test(lv, v3, 5, 0, 9, 1, "Ui_B_BFu9i");
    set_bf_and_test(lv, v3, 5, 0, 9, hide_ull(1LL<<8), "Ui_B_BFu9i");
  }
}
static Arrange_To_Call_Me vUi_B_BFu9i(Test_Ui_B_BFu9i, "Ui_B_BFu9i", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu9ll()
{
  {
    init_simple_test("Ui_B_BFu9ll");
    static Ui_B_BFu9ll lv;
    check2(sizeof(lv), 7, "sizeof(Ui_B_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu9ll)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu9ll.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu9ll.v2");
    set_bf_and_test(lv, v3, 5, 0, 9, 1, "Ui_B_BFu9ll");
    set_bf_and_test(lv, v3, 5, 0, 9, hide_ull(1LL<<8), "Ui_B_BFu9ll");
  }
}
static Arrange_To_Call_Me vUi_B_BFu9ll(Test_Ui_B_BFu9ll, "Ui_B_BFu9ll", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_BFu9s()
{
  {
    init_simple_test("Ui_B_BFu9s");
    static Ui_B_BFu9s lv;
    check2(sizeof(lv), 7, "sizeof(Ui_B_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_BFu9s)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu9s.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu9s.v2");
    set_bf_and_test(lv, v3, 5, 0, 9, 1, "Ui_B_BFu9s");
    set_bf_and_test(lv, v3, 5, 0, 9, hide_ull(1LL<<8), "Ui_B_BFu9s");
  }
}
static Arrange_To_Call_Me vUi_B_BFu9s(Test_Ui_B_BFu9s, "Ui_B_BFu9s", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_C()
{
  {
    init_simple_test("Ui_B_C");
    Ui_B_C lv;
    check2(sizeof(lv), 6, "sizeof(Ui_B_C)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_C)");
    check_field_offset(lv, v1, 0, "Ui_B_C.v1");
    check_field_offset(lv, v2, 4, "Ui_B_C.v2");
    check_field_offset(lv, v3, 5, "Ui_B_C.v3");
  }
}
static Arrange_To_Call_Me vUi_B_C(Test_Ui_B_C, "Ui_B_C", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_D()
{
  {
    init_simple_test("Ui_B_D");
    Ui_B_D lv;
    check2(sizeof(lv), 13, "sizeof(Ui_B_D)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_D)");
    check_field_offset(lv, v1, 0, "Ui_B_D.v1");
    check_field_offset(lv, v2, 4, "Ui_B_D.v2");
    check_field_offset(lv, v3, 5, "Ui_B_D.v3");
  }
}
static Arrange_To_Call_Me vUi_B_D(Test_Ui_B_D, "Ui_B_D", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_F()
{
  {
    init_simple_test("Ui_B_F");
    Ui_B_F lv;
    check2(sizeof(lv), 9, "sizeof(Ui_B_F)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_F)");
    check_field_offset(lv, v1, 0, "Ui_B_F.v1");
    check_field_offset(lv, v2, 4, "Ui_B_F.v2");
    check_field_offset(lv, v3, 5, "Ui_B_F.v3");
  }
}
static Arrange_To_Call_Me vUi_B_F(Test_Ui_B_F, "Ui_B_F", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_I()
{
  {
    init_simple_test("Ui_B_I");
    Ui_B_I lv;
    check2(sizeof(lv), 9, "sizeof(Ui_B_I)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_I)");
    check_field_offset(lv, v1, 0, "Ui_B_I.v1");
    check_field_offset(lv, v2, 4, "Ui_B_I.v2");
    check_field_offset(lv, v3, 5, "Ui_B_I.v3");
  }
}
static Arrange_To_Call_Me vUi_B_I(Test_Ui_B_I, "Ui_B_I", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_Ip()
{
  {
    init_simple_test("Ui_B_Ip");
    Ui_B_Ip lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Ui_B_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_Ip)");
    check_field_offset(lv, v1, 0, "Ui_B_Ip.v1");
    check_field_offset(lv, v2, 4, "Ui_B_Ip.v2");
    check_field_offset(lv, v3, 5, "Ui_B_Ip.v3");
  }
}
static Arrange_To_Call_Me vUi_B_Ip(Test_Ui_B_Ip, "Ui_B_Ip", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_L()
{
  {
    init_simple_test("Ui_B_L");
    Ui_B_L lv;
    check2(sizeof(lv), 13, "sizeof(Ui_B_L)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_L)");
    check_field_offset(lv, v1, 0, "Ui_B_L.v1");
    check_field_offset(lv, v2, 4, "Ui_B_L.v2");
    check_field_offset(lv, v3, 5, "Ui_B_L.v3");
  }
}
static Arrange_To_Call_Me vUi_B_L(Test_Ui_B_L, "Ui_B_L", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_S()
{
  {
    init_simple_test("Ui_B_S");
    Ui_B_S lv;
    check2(sizeof(lv), 7, "sizeof(Ui_B_S)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_S)");
    check_field_offset(lv, v1, 0, "Ui_B_S.v1");
    check_field_offset(lv, v2, 4, "Ui_B_S.v2");
    check_field_offset(lv, v3, 5, "Ui_B_S.v3");
  }
}
static Arrange_To_Call_Me vUi_B_S(Test_Ui_B_S, "Ui_B_S", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_Uc()
{
  {
    init_simple_test("Ui_B_Uc");
    Ui_B_Uc lv;
    check2(sizeof(lv), 6, "sizeof(Ui_B_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_Uc)");
    check_field_offset(lv, v1, 0, "Ui_B_Uc.v1");
    check_field_offset(lv, v2, 4, "Ui_B_Uc.v2");
    check_field_offset(lv, v3, 5, "Ui_B_Uc.v3");
  }
}
static Arrange_To_Call_Me vUi_B_Uc(Test_Ui_B_Uc, "Ui_B_Uc", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_Ui()
{
  {
    init_simple_test("Ui_B_Ui");
    Ui_B_Ui lv;
    check2(sizeof(lv), 9, "sizeof(Ui_B_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_Ui)");
    check_field_offset(lv, v1, 0, "Ui_B_Ui.v1");
    check_field_offset(lv, v2, 4, "Ui_B_Ui.v2");
    check_field_offset(lv, v3, 5, "Ui_B_Ui.v3");
  }
}
static Arrange_To_Call_Me vUi_B_Ui(Test_Ui_B_Ui, "Ui_B_Ui", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_Ul()
{
  {
    init_simple_test("Ui_B_Ul");
    Ui_B_Ul lv;
    check2(sizeof(lv), 13, "sizeof(Ui_B_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_Ul)");
    check_field_offset(lv, v1, 0, "Ui_B_Ul.v1");
    check_field_offset(lv, v2, 4, "Ui_B_Ul.v2");
    check_field_offset(lv, v3, 5, "Ui_B_Ul.v3");
  }
}
static Arrange_To_Call_Me vUi_B_Ul(Test_Ui_B_Ul, "Ui_B_Ul", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_Us()
{
  {
    init_simple_test("Ui_B_Us");
    Ui_B_Us lv;
    check2(sizeof(lv), 7, "sizeof(Ui_B_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_Us)");
    check_field_offset(lv, v1, 0, "Ui_B_Us.v1");
    check_field_offset(lv, v2, 4, "Ui_B_Us.v2");
    check_field_offset(lv, v3, 5, "Ui_B_Us.v3");
  }
}
static Arrange_To_Call_Me vUi_B_Us(Test_Ui_B_Us, "Ui_B_Us", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_B_Vp()
{
  {
    init_simple_test("Ui_B_Vp");
    Ui_B_Vp lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Ui_B_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_B_Vp)");
    check_field_offset(lv, v1, 0, "Ui_B_Vp.v1");
    check_field_offset(lv, v2, 4, "Ui_B_Vp.v2");
    check_field_offset(lv, v3, 5, "Ui_B_Vp.v3");
  }
}
static Arrange_To_Call_Me vUi_B_Vp(Test_Ui_B_Vp, "Ui_B_Vp", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu15i_B()
{
  {
    init_simple_test("Ui_BFu15i_B");
    static Ui_BFu15i_B lv;
    check2(sizeof(lv), 7, "sizeof(Ui_BFu15i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu15i_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu15i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15i_B");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15i_B");
    check_field_offset(lv, v3, 6, "Ui_BFu15i_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu15i_B(Test_Ui_BFu15i_B, "Ui_BFu15i_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu15ll_B()
{
  {
    init_simple_test("Ui_BFu15ll_B");
    static Ui_BFu15ll_B lv;
    check2(sizeof(lv), 7, "sizeof(Ui_BFu15ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu15ll_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu15ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15ll_B");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15ll_B");
    check_field_offset(lv, v3, 6, "Ui_BFu15ll_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu15ll_B(Test_Ui_BFu15ll_B, "Ui_BFu15ll_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu15s_B()
{
  {
    init_simple_test("Ui_BFu15s_B");
    static Ui_BFu15s_B lv;
    check2(sizeof(lv), 7, "sizeof(Ui_BFu15s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu15s_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu15s_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15s_B");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15s_B");
    check_field_offset(lv, v3, 6, "Ui_BFu15s_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu15s_B(Test_Ui_BFu15s_B, "Ui_BFu15s_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu16i_B()
{
  {
    init_simple_test("Ui_BFu16i_B");
    static Ui_BFu16i_B lv;
    check2(sizeof(lv), 7, "sizeof(Ui_BFu16i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu16i_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu16i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16i_B");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16i_B");
    check_field_offset(lv, v3, 6, "Ui_BFu16i_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu16i_B(Test_Ui_BFu16i_B, "Ui_BFu16i_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu16ll_B()
{
  {
    init_simple_test("Ui_BFu16ll_B");
    static Ui_BFu16ll_B lv;
    check2(sizeof(lv), 7, "sizeof(Ui_BFu16ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu16ll_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu16ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16ll_B");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16ll_B");
    check_field_offset(lv, v3, 6, "Ui_BFu16ll_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu16ll_B(Test_Ui_BFu16ll_B, "Ui_BFu16ll_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu16s_B()
{
  {
    init_simple_test("Ui_BFu16s_B");
    static Ui_BFu16s_B lv;
    check2(sizeof(lv), 7, "sizeof(Ui_BFu16s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu16s_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu16s_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16s_B");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16s_B");
    check_field_offset(lv, v3, 6, "Ui_BFu16s_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu16s_B(Test_Ui_BFu16s_B, "Ui_BFu16s_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu17i_B()
{
  {
    init_simple_test("Ui_BFu17i_B");
    static Ui_BFu17i_B lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu17i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu17i_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu17i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu17i_B");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu17i_B");
    check_field_offset(lv, v3, 7, "Ui_BFu17i_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu17i_B(Test_Ui_BFu17i_B, "Ui_BFu17i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu17ll_B()
{
  {
    init_simple_test("Ui_BFu17ll_B");
    static Ui_BFu17ll_B lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu17ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu17ll_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu17ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu17ll_B");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu17ll_B");
    check_field_offset(lv, v3, 7, "Ui_BFu17ll_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu17ll_B(Test_Ui_BFu17ll_B, "Ui_BFu17ll_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu1c_B()
{
  {
    init_simple_test("Ui_BFu1c_B");
    static Ui_BFu1c_B lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu1c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu1c_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu1c_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1c_B");
    check_field_offset(lv, v3, 5, "Ui_BFu1c_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu1c_B(Test_Ui_BFu1c_B, "Ui_BFu1c_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu1i_B()
{
  {
    init_simple_test("Ui_BFu1i_B");
    static Ui_BFu1i_B lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu1i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu1i_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu1i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1i_B");
    check_field_offset(lv, v3, 5, "Ui_BFu1i_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu1i_B(Test_Ui_BFu1i_B, "Ui_BFu1i_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu1ll_B()
{
  {
    init_simple_test("Ui_BFu1ll_B");
    static Ui_BFu1ll_B lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu1ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu1ll_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu1ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1ll_B");
    check_field_offset(lv, v3, 5, "Ui_BFu1ll_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu1ll_B(Test_Ui_BFu1ll_B, "Ui_BFu1ll_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu1s_B()
{
  {
    init_simple_test("Ui_BFu1s_B");
    static Ui_BFu1s_B lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu1s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu1s_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu1s_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1s_B");
    check_field_offset(lv, v3, 5, "Ui_BFu1s_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu1s_B(Test_Ui_BFu1s_B, "Ui_BFu1s_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu31i_B()
{
  {
    init_simple_test("Ui_BFu31i_B");
    static Ui_BFu31i_B lv;
    check2(sizeof(lv), 9, "sizeof(Ui_BFu31i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu31i_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu31i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu31i_B");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu31i_B");
    check_field_offset(lv, v3, 8, "Ui_BFu31i_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu31i_B(Test_Ui_BFu31i_B, "Ui_BFu31i_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu31ll_B()
{
  {
    init_simple_test("Ui_BFu31ll_B");
    static Ui_BFu31ll_B lv;
    check2(sizeof(lv), 9, "sizeof(Ui_BFu31ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu31ll_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu31ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu31ll_B");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu31ll_B");
    check_field_offset(lv, v3, 8, "Ui_BFu31ll_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu31ll_B(Test_Ui_BFu31ll_B, "Ui_BFu31ll_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu32i_B()
{
  {
    init_simple_test("Ui_BFu32i_B");
    static Ui_BFu32i_B lv;
    check2(sizeof(lv), 9, "sizeof(Ui_BFu32i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu32i_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu32i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu32i_B");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu32i_B");
    check_field_offset(lv, v3, 8, "Ui_BFu32i_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu32i_B(Test_Ui_BFu32i_B, "Ui_BFu32i_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu32ll_B()
{
  {
    init_simple_test("Ui_BFu32ll_B");
    static Ui_BFu32ll_B lv;
    check2(sizeof(lv), 9, "sizeof(Ui_BFu32ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu32ll_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu32ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu32ll_B");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu32ll_B");
    check_field_offset(lv, v3, 8, "Ui_BFu32ll_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu32ll_B(Test_Ui_BFu32ll_B, "Ui_BFu32ll_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu33_B()
{
  {
    init_simple_test("Ui_BFu33_B");
    static Ui_BFu33_B lv;
    check2(sizeof(lv), 10, "sizeof(Ui_BFu33_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu33_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu33_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 33, 1, "Ui_BFu33_B");
    set_bf_and_test(lv, v2, 4, 0, 33, hide_ull(1LL<<32), "Ui_BFu33_B");
    check_field_offset(lv, v3, 9, "Ui_BFu33_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu33_B(Test_Ui_BFu33_B, "Ui_BFu33_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu7c_B()
{
  {
    init_simple_test("Ui_BFu7c_B");
    static Ui_BFu7c_B lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu7c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu7c_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu7c_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7c_B");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7c_B");
    check_field_offset(lv, v3, 5, "Ui_BFu7c_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu7c_B(Test_Ui_BFu7c_B, "Ui_BFu7c_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu7i_B()
{
  {
    init_simple_test("Ui_BFu7i_B");
    static Ui_BFu7i_B lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu7i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu7i_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu7i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7i_B");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7i_B");
    check_field_offset(lv, v3, 5, "Ui_BFu7i_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu7i_B(Test_Ui_BFu7i_B, "Ui_BFu7i_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu7ll_B()
{
  {
    init_simple_test("Ui_BFu7ll_B");
    static Ui_BFu7ll_B lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu7ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu7ll_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu7ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7ll_B");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7ll_B");
    check_field_offset(lv, v3, 5, "Ui_BFu7ll_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu7ll_B(Test_Ui_BFu7ll_B, "Ui_BFu7ll_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu7s_B()
{
  {
    init_simple_test("Ui_BFu7s_B");
    static Ui_BFu7s_B lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu7s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu7s_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu7s_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7s_B");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7s_B");
    check_field_offset(lv, v3, 5, "Ui_BFu7s_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu7s_B(Test_Ui_BFu7s_B, "Ui_BFu7s_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu8c_B()
{
  {
    init_simple_test("Ui_BFu8c_B");
    static Ui_BFu8c_B lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu8c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu8c_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu8c_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8c_B");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8c_B");
    check_field_offset(lv, v3, 5, "Ui_BFu8c_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu8c_B(Test_Ui_BFu8c_B, "Ui_BFu8c_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu8i_B()
{
  {
    init_simple_test("Ui_BFu8i_B");
    static Ui_BFu8i_B lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu8i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu8i_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu8i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8i_B");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8i_B");
    check_field_offset(lv, v3, 5, "Ui_BFu8i_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu8i_B(Test_Ui_BFu8i_B, "Ui_BFu8i_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu8ll_B()
{
  {
    init_simple_test("Ui_BFu8ll_B");
    static Ui_BFu8ll_B lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu8ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu8ll_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu8ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8ll_B");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8ll_B");
    check_field_offset(lv, v3, 5, "Ui_BFu8ll_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu8ll_B(Test_Ui_BFu8ll_B, "Ui_BFu8ll_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu8s_B()
{
  {
    init_simple_test("Ui_BFu8s_B");
    static Ui_BFu8s_B lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu8s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu8s_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu8s_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8s_B");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8s_B");
    check_field_offset(lv, v3, 5, "Ui_BFu8s_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu8s_B(Test_Ui_BFu8s_B, "Ui_BFu8s_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu9i_B()
{
  {
    init_simple_test("Ui_BFu9i_B");
    static Ui_BFu9i_B lv;
    check2(sizeof(lv), 7, "sizeof(Ui_BFu9i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu9i_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu9i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9i_B");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9i_B");
    check_field_offset(lv, v3, 6, "Ui_BFu9i_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu9i_B(Test_Ui_BFu9i_B, "Ui_BFu9i_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu9ll_B()
{
  {
    init_simple_test("Ui_BFu9ll_B");
    static Ui_BFu9ll_B lv;
    check2(sizeof(lv), 7, "sizeof(Ui_BFu9ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu9ll_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu9ll_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9ll_B");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9ll_B");
    check_field_offset(lv, v3, 6, "Ui_BFu9ll_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu9ll_B(Test_Ui_BFu9ll_B, "Ui_BFu9ll_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu9s_B()
{
  {
    init_simple_test("Ui_BFu9s_B");
    static Ui_BFu9s_B lv;
    check2(sizeof(lv), 7, "sizeof(Ui_BFu9s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu9s_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu9s_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9s_B");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9s_B");
    check_field_offset(lv, v3, 6, "Ui_BFu9s_B.v3");
  }
}
static Arrange_To_Call_Me vUi_BFu9s_B(Test_Ui_BFu9s_B, "Ui_BFu9s_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_C_B()
{
  {
    init_simple_test("Ui_C_B");
    Ui_C_B lv;
    check2(sizeof(lv), 6, "sizeof(Ui_C_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_C_B)");
    check_field_offset(lv, v1, 0, "Ui_C_B.v1");
    check_field_offset(lv, v2, 4, "Ui_C_B.v2");
    check_field_offset(lv, v3, 5, "Ui_C_B.v3");
  }
}
static Arrange_To_Call_Me vUi_C_B(Test_Ui_C_B, "Ui_C_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_D_B()
{
  {
    init_simple_test("Ui_D_B");
    Ui_D_B lv;
    check2(sizeof(lv), 13, "sizeof(Ui_D_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_D_B)");
    check_field_offset(lv, v1, 0, "Ui_D_B.v1");
    check_field_offset(lv, v2, 4, "Ui_D_B.v2");
    check_field_offset(lv, v3, 12, "Ui_D_B.v3");
  }
}
static Arrange_To_Call_Me vUi_D_B(Test_Ui_D_B, "Ui_D_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_F_B()
{
  {
    init_simple_test("Ui_F_B");
    Ui_F_B lv;
    check2(sizeof(lv), 9, "sizeof(Ui_F_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_F_B)");
    check_field_offset(lv, v1, 0, "Ui_F_B.v1");
    check_field_offset(lv, v2, 4, "Ui_F_B.v2");
    check_field_offset(lv, v3, 8, "Ui_F_B.v3");
  }
}
static Arrange_To_Call_Me vUi_F_B(Test_Ui_F_B, "Ui_F_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_I_B()
{
  {
    init_simple_test("Ui_I_B");
    Ui_I_B lv;
    check2(sizeof(lv), 9, "sizeof(Ui_I_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_I_B)");
    check_field_offset(lv, v1, 0, "Ui_I_B.v1");
    check_field_offset(lv, v2, 4, "Ui_I_B.v2");
    check_field_offset(lv, v3, 8, "Ui_I_B.v3");
  }
}
static Arrange_To_Call_Me vUi_I_B(Test_Ui_I_B, "Ui_I_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Ip_B()
{
  {
    init_simple_test("Ui_Ip_B");
    Ui_Ip_B lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Ui_Ip_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Ip_B)");
    check_field_offset(lv, v1, 0, "Ui_Ip_B.v1");
    check_field_offset(lv, v2, 4, "Ui_Ip_B.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Ui_Ip_B.v3");
  }
}
static Arrange_To_Call_Me vUi_Ip_B(Test_Ui_Ip_B, "Ui_Ip_B", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_L_B()
{
  {
    init_simple_test("Ui_L_B");
    Ui_L_B lv;
    check2(sizeof(lv), 13, "sizeof(Ui_L_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_L_B)");
    check_field_offset(lv, v1, 0, "Ui_L_B.v1");
    check_field_offset(lv, v2, 4, "Ui_L_B.v2");
    check_field_offset(lv, v3, 12, "Ui_L_B.v3");
  }
}
static Arrange_To_Call_Me vUi_L_B(Test_Ui_L_B, "Ui_L_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_S_B()
{
  {
    init_simple_test("Ui_S_B");
    Ui_S_B lv;
    check2(sizeof(lv), 7, "sizeof(Ui_S_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_S_B)");
    check_field_offset(lv, v1, 0, "Ui_S_B.v1");
    check_field_offset(lv, v2, 4, "Ui_S_B.v2");
    check_field_offset(lv, v3, 6, "Ui_S_B.v3");
  }
}
static Arrange_To_Call_Me vUi_S_B(Test_Ui_S_B, "Ui_S_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Uc_B()
{
  {
    init_simple_test("Ui_Uc_B");
    Ui_Uc_B lv;
    check2(sizeof(lv), 6, "sizeof(Ui_Uc_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Uc_B)");
    check_field_offset(lv, v1, 0, "Ui_Uc_B.v1");
    check_field_offset(lv, v2, 4, "Ui_Uc_B.v2");
    check_field_offset(lv, v3, 5, "Ui_Uc_B.v3");
  }
}
static Arrange_To_Call_Me vUi_Uc_B(Test_Ui_Uc_B, "Ui_Uc_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Ui_B()
{
  {
    init_simple_test("Ui_Ui_B");
    Ui_Ui_B lv;
    check2(sizeof(lv), 9, "sizeof(Ui_Ui_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Ui_B)");
    check_field_offset(lv, v1, 0, "Ui_Ui_B.v1");
    check_field_offset(lv, v2, 4, "Ui_Ui_B.v2");
    check_field_offset(lv, v3, 8, "Ui_Ui_B.v3");
  }
}
static Arrange_To_Call_Me vUi_Ui_B(Test_Ui_Ui_B, "Ui_Ui_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Ul_B()
{
  {
    init_simple_test("Ui_Ul_B");
    Ui_Ul_B lv;
    check2(sizeof(lv), 13, "sizeof(Ui_Ul_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Ul_B)");
    check_field_offset(lv, v1, 0, "Ui_Ul_B.v1");
    check_field_offset(lv, v2, 4, "Ui_Ul_B.v2");
    check_field_offset(lv, v3, 12, "Ui_Ul_B.v3");
  }
}
static Arrange_To_Call_Me vUi_Ul_B(Test_Ui_Ul_B, "Ui_Ul_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Us_B()
{
  {
    init_simple_test("Ui_Us_B");
    Ui_Us_B lv;
    check2(sizeof(lv), 7, "sizeof(Ui_Us_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Us_B)");
    check_field_offset(lv, v1, 0, "Ui_Us_B.v1");
    check_field_offset(lv, v2, 4, "Ui_Us_B.v2");
    check_field_offset(lv, v3, 6, "Ui_Us_B.v3");
  }
}
static Arrange_To_Call_Me vUi_Us_B(Test_Ui_Us_B, "Ui_Us_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Vp_B()
{
  {
    init_simple_test("Ui_Vp_B");
    Ui_Vp_B lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Ui_Vp_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Vp_B)");
    check_field_offset(lv, v1, 0, "Ui_Vp_B.v1");
    check_field_offset(lv, v2, 4, "Ui_Vp_B.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Ui_Vp_B.v3");
  }
}
static Arrange_To_Call_Me vUi_Vp_B(Test_Ui_Vp_B, "Ui_Vp_B", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B()
{
  {
    init_simple_test("Ul_B");
    Ul_B lv;
    check2(sizeof(lv), 9, "sizeof(Ul_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B)");
    check_field_offset(lv, v1, 0, "Ul_B.v1");
    check_field_offset(lv, v2, 8, "Ul_B.v2");
  }
}
static Arrange_To_Call_Me vUl_B(Test_Ul_B, "Ul_B", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_B()
{
  {
    init_simple_test("Ul_B_B");
    Ul_B_B lv;
    check2(sizeof(lv), 10, "sizeof(Ul_B_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_B)");
    check_field_offset(lv, v1, 0, "Ul_B_B.v1");
    check_field_offset(lv, v2, 8, "Ul_B_B.v2");
    check_field_offset(lv, v3, 9, "Ul_B_B.v3");
  }
}
static Arrange_To_Call_Me vUl_B_B(Test_Ul_B_B, "Ul_B_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu15i()
{
  {
    init_simple_test("Ul_B_BFu15i");
    static Ul_B_BFu15i lv;
    check2(sizeof(lv), 11, "sizeof(Ul_B_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu15i)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu15i.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu15i.v2");
    set_bf_and_test(lv, v3, 9, 0, 15, 1, "Ul_B_BFu15i");
    set_bf_and_test(lv, v3, 9, 0, 15, hide_ull(1LL<<14), "Ul_B_BFu15i");
  }
}
static Arrange_To_Call_Me vUl_B_BFu15i(Test_Ul_B_BFu15i, "Ul_B_BFu15i", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu15ll()
{
  {
    init_simple_test("Ul_B_BFu15ll");
    static Ul_B_BFu15ll lv;
    check2(sizeof(lv), 11, "sizeof(Ul_B_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu15ll)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu15ll.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu15ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 15, 1, "Ul_B_BFu15ll");
    set_bf_and_test(lv, v3, 9, 0, 15, hide_ull(1LL<<14), "Ul_B_BFu15ll");
  }
}
static Arrange_To_Call_Me vUl_B_BFu15ll(Test_Ul_B_BFu15ll, "Ul_B_BFu15ll", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu15s()
{
  {
    init_simple_test("Ul_B_BFu15s");
    static Ul_B_BFu15s lv;
    check2(sizeof(lv), 11, "sizeof(Ul_B_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu15s)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu15s.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu15s.v2");
    set_bf_and_test(lv, v3, 9, 0, 15, 1, "Ul_B_BFu15s");
    set_bf_and_test(lv, v3, 9, 0, 15, hide_ull(1LL<<14), "Ul_B_BFu15s");
  }
}
static Arrange_To_Call_Me vUl_B_BFu15s(Test_Ul_B_BFu15s, "Ul_B_BFu15s", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu16i()
{
  {
    init_simple_test("Ul_B_BFu16i");
    static Ul_B_BFu16i lv;
    check2(sizeof(lv), 11, "sizeof(Ul_B_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu16i)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu16i.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu16i.v2");
    set_bf_and_test(lv, v3, 9, 0, 16, 1, "Ul_B_BFu16i");
    set_bf_and_test(lv, v3, 9, 0, 16, hide_ull(1LL<<15), "Ul_B_BFu16i");
  }
}
static Arrange_To_Call_Me vUl_B_BFu16i(Test_Ul_B_BFu16i, "Ul_B_BFu16i", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu16ll()
{
  {
    init_simple_test("Ul_B_BFu16ll");
    static Ul_B_BFu16ll lv;
    check2(sizeof(lv), 11, "sizeof(Ul_B_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu16ll)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu16ll.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu16ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 16, 1, "Ul_B_BFu16ll");
    set_bf_and_test(lv, v3, 9, 0, 16, hide_ull(1LL<<15), "Ul_B_BFu16ll");
  }
}
static Arrange_To_Call_Me vUl_B_BFu16ll(Test_Ul_B_BFu16ll, "Ul_B_BFu16ll", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu16s()
{
  {
    init_simple_test("Ul_B_BFu16s");
    static Ul_B_BFu16s lv;
    check2(sizeof(lv), 11, "sizeof(Ul_B_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu16s)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu16s.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu16s.v2");
    set_bf_and_test(lv, v3, 9, 0, 16, 1, "Ul_B_BFu16s");
    set_bf_and_test(lv, v3, 9, 0, 16, hide_ull(1LL<<15), "Ul_B_BFu16s");
  }
}
static Arrange_To_Call_Me vUl_B_BFu16s(Test_Ul_B_BFu16s, "Ul_B_BFu16s", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu17i()
{
  {
    init_simple_test("Ul_B_BFu17i");
    static Ul_B_BFu17i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_B_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu17i)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu17i.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu17i.v2");
    set_bf_and_test(lv, v3, 9, 0, 17, 1, "Ul_B_BFu17i");
    set_bf_and_test(lv, v3, 9, 0, 17, hide_ull(1LL<<16), "Ul_B_BFu17i");
  }
}
static Arrange_To_Call_Me vUl_B_BFu17i(Test_Ul_B_BFu17i, "Ul_B_BFu17i", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu17ll()
{
  {
    init_simple_test("Ul_B_BFu17ll");
    static Ul_B_BFu17ll lv;
    check2(sizeof(lv), 12, "sizeof(Ul_B_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu17ll)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu17ll.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu17ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 17, 1, "Ul_B_BFu17ll");
    set_bf_and_test(lv, v3, 9, 0, 17, hide_ull(1LL<<16), "Ul_B_BFu17ll");
  }
}
static Arrange_To_Call_Me vUl_B_BFu17ll(Test_Ul_B_BFu17ll, "Ul_B_BFu17ll", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu1c()
{
  {
    init_simple_test("Ul_B_BFu1c");
    static Ul_B_BFu1c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_B_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu1c)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu1c.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu1c.v2");
    set_bf_and_test(lv, v3, 9, 0, 1, 1, "Ul_B_BFu1c");
  }
}
static Arrange_To_Call_Me vUl_B_BFu1c(Test_Ul_B_BFu1c, "Ul_B_BFu1c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu1i()
{
  {
    init_simple_test("Ul_B_BFu1i");
    static Ul_B_BFu1i lv;
    check2(sizeof(lv), 10, "sizeof(Ul_B_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu1i)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu1i.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu1i.v2");
    set_bf_and_test(lv, v3, 9, 0, 1, 1, "Ul_B_BFu1i");
  }
}
static Arrange_To_Call_Me vUl_B_BFu1i(Test_Ul_B_BFu1i, "Ul_B_BFu1i", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu1ll()
{
  {
    init_simple_test("Ul_B_BFu1ll");
    static Ul_B_BFu1ll lv;
    check2(sizeof(lv), 10, "sizeof(Ul_B_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu1ll)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu1ll.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu1ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 1, 1, "Ul_B_BFu1ll");
  }
}
static Arrange_To_Call_Me vUl_B_BFu1ll(Test_Ul_B_BFu1ll, "Ul_B_BFu1ll", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu1s()
{
  {
    init_simple_test("Ul_B_BFu1s");
    static Ul_B_BFu1s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_B_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu1s)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu1s.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu1s.v2");
    set_bf_and_test(lv, v3, 9, 0, 1, 1, "Ul_B_BFu1s");
  }
}
static Arrange_To_Call_Me vUl_B_BFu1s(Test_Ul_B_BFu1s, "Ul_B_BFu1s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu31i()
{
  {
    init_simple_test("Ul_B_BFu31i");
    static Ul_B_BFu31i lv;
    check2(sizeof(lv), 13, "sizeof(Ul_B_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu31i)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu31i.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu31i.v2");
    set_bf_and_test(lv, v3, 9, 0, 31, 1, "Ul_B_BFu31i");
    set_bf_and_test(lv, v3, 9, 0, 31, hide_ull(1LL<<30), "Ul_B_BFu31i");
  }
}
static Arrange_To_Call_Me vUl_B_BFu31i(Test_Ul_B_BFu31i, "Ul_B_BFu31i", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu31ll()
{
  {
    init_simple_test("Ul_B_BFu31ll");
    static Ul_B_BFu31ll lv;
    check2(sizeof(lv), 13, "sizeof(Ul_B_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu31ll)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu31ll.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu31ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 31, 1, "Ul_B_BFu31ll");
    set_bf_and_test(lv, v3, 9, 0, 31, hide_ull(1LL<<30), "Ul_B_BFu31ll");
  }
}
static Arrange_To_Call_Me vUl_B_BFu31ll(Test_Ul_B_BFu31ll, "Ul_B_BFu31ll", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu32i()
{
  {
    init_simple_test("Ul_B_BFu32i");
    static Ul_B_BFu32i lv;
    check2(sizeof(lv), 13, "sizeof(Ul_B_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu32i)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu32i.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu32i.v2");
    set_bf_and_test(lv, v3, 9, 0, 32, 1, "Ul_B_BFu32i");
    set_bf_and_test(lv, v3, 9, 0, 32, hide_ull(1LL<<31), "Ul_B_BFu32i");
  }
}
static Arrange_To_Call_Me vUl_B_BFu32i(Test_Ul_B_BFu32i, "Ul_B_BFu32i", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu32ll()
{
  {
    init_simple_test("Ul_B_BFu32ll");
    static Ul_B_BFu32ll lv;
    check2(sizeof(lv), 13, "sizeof(Ul_B_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu32ll)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu32ll.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu32ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 32, 1, "Ul_B_BFu32ll");
    set_bf_and_test(lv, v3, 9, 0, 32, hide_ull(1LL<<31), "Ul_B_BFu32ll");
  }
}
static Arrange_To_Call_Me vUl_B_BFu32ll(Test_Ul_B_BFu32ll, "Ul_B_BFu32ll", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu33()
{
  {
    init_simple_test("Ul_B_BFu33");
    static Ul_B_BFu33 lv;
    check2(sizeof(lv), 14, "sizeof(Ul_B_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu33)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu33.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu33.v2");
    set_bf_and_test(lv, v3, 9, 0, 33, 1, "Ul_B_BFu33");
    set_bf_and_test(lv, v3, 9, 0, 33, hide_ull(1LL<<32), "Ul_B_BFu33");
  }
}
static Arrange_To_Call_Me vUl_B_BFu33(Test_Ul_B_BFu33, "Ul_B_BFu33", 14);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu7c()
{
  {
    init_simple_test("Ul_B_BFu7c");
    static Ul_B_BFu7c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_B_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu7c)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu7c.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu7c.v2");
    set_bf_and_test(lv, v3, 9, 0, 7, 1, "Ul_B_BFu7c");
    set_bf_and_test(lv, v3, 9, 0, 7, hide_ull(1LL<<6), "Ul_B_BFu7c");
  }
}
static Arrange_To_Call_Me vUl_B_BFu7c(Test_Ul_B_BFu7c, "Ul_B_BFu7c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu7i()
{
  {
    init_simple_test("Ul_B_BFu7i");
    static Ul_B_BFu7i lv;
    check2(sizeof(lv), 10, "sizeof(Ul_B_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu7i)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu7i.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu7i.v2");
    set_bf_and_test(lv, v3, 9, 0, 7, 1, "Ul_B_BFu7i");
    set_bf_and_test(lv, v3, 9, 0, 7, hide_ull(1LL<<6), "Ul_B_BFu7i");
  }
}
static Arrange_To_Call_Me vUl_B_BFu7i(Test_Ul_B_BFu7i, "Ul_B_BFu7i", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu7ll()
{
  {
    init_simple_test("Ul_B_BFu7ll");
    static Ul_B_BFu7ll lv;
    check2(sizeof(lv), 10, "sizeof(Ul_B_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu7ll)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu7ll.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu7ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 7, 1, "Ul_B_BFu7ll");
    set_bf_and_test(lv, v3, 9, 0, 7, hide_ull(1LL<<6), "Ul_B_BFu7ll");
  }
}
static Arrange_To_Call_Me vUl_B_BFu7ll(Test_Ul_B_BFu7ll, "Ul_B_BFu7ll", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu7s()
{
  {
    init_simple_test("Ul_B_BFu7s");
    static Ul_B_BFu7s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_B_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu7s)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu7s.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu7s.v2");
    set_bf_and_test(lv, v3, 9, 0, 7, 1, "Ul_B_BFu7s");
    set_bf_and_test(lv, v3, 9, 0, 7, hide_ull(1LL<<6), "Ul_B_BFu7s");
  }
}
static Arrange_To_Call_Me vUl_B_BFu7s(Test_Ul_B_BFu7s, "Ul_B_BFu7s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu8c()
{
  {
    init_simple_test("Ul_B_BFu8c");
    static Ul_B_BFu8c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_B_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu8c)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu8c.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu8c.v2");
    set_bf_and_test(lv, v3, 9, 0, 8, 1, "Ul_B_BFu8c");
    set_bf_and_test(lv, v3, 9, 0, 8, hide_ull(1LL<<7), "Ul_B_BFu8c");
  }
}
static Arrange_To_Call_Me vUl_B_BFu8c(Test_Ul_B_BFu8c, "Ul_B_BFu8c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu8i()
{
  {
    init_simple_test("Ul_B_BFu8i");
    static Ul_B_BFu8i lv;
    check2(sizeof(lv), 10, "sizeof(Ul_B_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu8i)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu8i.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu8i.v2");
    set_bf_and_test(lv, v3, 9, 0, 8, 1, "Ul_B_BFu8i");
    set_bf_and_test(lv, v3, 9, 0, 8, hide_ull(1LL<<7), "Ul_B_BFu8i");
  }
}
static Arrange_To_Call_Me vUl_B_BFu8i(Test_Ul_B_BFu8i, "Ul_B_BFu8i", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu8ll()
{
  {
    init_simple_test("Ul_B_BFu8ll");
    static Ul_B_BFu8ll lv;
    check2(sizeof(lv), 10, "sizeof(Ul_B_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu8ll)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu8ll.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu8ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 8, 1, "Ul_B_BFu8ll");
    set_bf_and_test(lv, v3, 9, 0, 8, hide_ull(1LL<<7), "Ul_B_BFu8ll");
  }
}
static Arrange_To_Call_Me vUl_B_BFu8ll(Test_Ul_B_BFu8ll, "Ul_B_BFu8ll", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu8s()
{
  {
    init_simple_test("Ul_B_BFu8s");
    static Ul_B_BFu8s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_B_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu8s)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu8s.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu8s.v2");
    set_bf_and_test(lv, v3, 9, 0, 8, 1, "Ul_B_BFu8s");
    set_bf_and_test(lv, v3, 9, 0, 8, hide_ull(1LL<<7), "Ul_B_BFu8s");
  }
}
static Arrange_To_Call_Me vUl_B_BFu8s(Test_Ul_B_BFu8s, "Ul_B_BFu8s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu9i()
{
  {
    init_simple_test("Ul_B_BFu9i");
    static Ul_B_BFu9i lv;
    check2(sizeof(lv), 11, "sizeof(Ul_B_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu9i)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu9i.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu9i.v2");
    set_bf_and_test(lv, v3, 9, 0, 9, 1, "Ul_B_BFu9i");
    set_bf_and_test(lv, v3, 9, 0, 9, hide_ull(1LL<<8), "Ul_B_BFu9i");
  }
}
static Arrange_To_Call_Me vUl_B_BFu9i(Test_Ul_B_BFu9i, "Ul_B_BFu9i", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu9ll()
{
  {
    init_simple_test("Ul_B_BFu9ll");
    static Ul_B_BFu9ll lv;
    check2(sizeof(lv), 11, "sizeof(Ul_B_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu9ll)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu9ll.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu9ll.v2");
    set_bf_and_test(lv, v3, 9, 0, 9, 1, "Ul_B_BFu9ll");
    set_bf_and_test(lv, v3, 9, 0, 9, hide_ull(1LL<<8), "Ul_B_BFu9ll");
  }
}
static Arrange_To_Call_Me vUl_B_BFu9ll(Test_Ul_B_BFu9ll, "Ul_B_BFu9ll", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_BFu9s()
{
  {
    init_simple_test("Ul_B_BFu9s");
    static Ul_B_BFu9s lv;
    check2(sizeof(lv), 11, "sizeof(Ul_B_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_BFu9s)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu9s.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu9s.v2");
    set_bf_and_test(lv, v3, 9, 0, 9, 1, "Ul_B_BFu9s");
    set_bf_and_test(lv, v3, 9, 0, 9, hide_ull(1LL<<8), "Ul_B_BFu9s");
  }
}
static Arrange_To_Call_Me vUl_B_BFu9s(Test_Ul_B_BFu9s, "Ul_B_BFu9s", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_C()
{
  {
    init_simple_test("Ul_B_C");
    Ul_B_C lv;
    check2(sizeof(lv), 10, "sizeof(Ul_B_C)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_C)");
    check_field_offset(lv, v1, 0, "Ul_B_C.v1");
    check_field_offset(lv, v2, 8, "Ul_B_C.v2");
    check_field_offset(lv, v3, 9, "Ul_B_C.v3");
  }
}
static Arrange_To_Call_Me vUl_B_C(Test_Ul_B_C, "Ul_B_C", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_D()
{
  {
    init_simple_test("Ul_B_D");
    Ul_B_D lv;
    check2(sizeof(lv), 17, "sizeof(Ul_B_D)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_D)");
    check_field_offset(lv, v1, 0, "Ul_B_D.v1");
    check_field_offset(lv, v2, 8, "Ul_B_D.v2");
    check_field_offset(lv, v3, 9, "Ul_B_D.v3");
  }
}
static Arrange_To_Call_Me vUl_B_D(Test_Ul_B_D, "Ul_B_D", 17);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_F()
{
  {
    init_simple_test("Ul_B_F");
    Ul_B_F lv;
    check2(sizeof(lv), 13, "sizeof(Ul_B_F)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_F)");
    check_field_offset(lv, v1, 0, "Ul_B_F.v1");
    check_field_offset(lv, v2, 8, "Ul_B_F.v2");
    check_field_offset(lv, v3, 9, "Ul_B_F.v3");
  }
}
static Arrange_To_Call_Me vUl_B_F(Test_Ul_B_F, "Ul_B_F", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_I()
{
  {
    init_simple_test("Ul_B_I");
    Ul_B_I lv;
    check2(sizeof(lv), 13, "sizeof(Ul_B_I)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_I)");
    check_field_offset(lv, v1, 0, "Ul_B_I.v1");
    check_field_offset(lv, v2, 8, "Ul_B_I.v2");
    check_field_offset(lv, v3, 9, "Ul_B_I.v3");
  }
}
static Arrange_To_Call_Me vUl_B_I(Test_Ul_B_I, "Ul_B_I", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_Ip()
{
  {
    init_simple_test("Ul_B_Ip");
    Ul_B_Ip lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(Ul_B_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_Ip)");
    check_field_offset(lv, v1, 0, "Ul_B_Ip.v1");
    check_field_offset(lv, v2, 8, "Ul_B_Ip.v2");
    check_field_offset(lv, v3, 9, "Ul_B_Ip.v3");
  }
}
static Arrange_To_Call_Me vUl_B_Ip(Test_Ul_B_Ip, "Ul_B_Ip", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_L()
{
  {
    init_simple_test("Ul_B_L");
    Ul_B_L lv;
    check2(sizeof(lv), 17, "sizeof(Ul_B_L)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_L)");
    check_field_offset(lv, v1, 0, "Ul_B_L.v1");
    check_field_offset(lv, v2, 8, "Ul_B_L.v2");
    check_field_offset(lv, v3, 9, "Ul_B_L.v3");
  }
}
static Arrange_To_Call_Me vUl_B_L(Test_Ul_B_L, "Ul_B_L", 17);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_S()
{
  {
    init_simple_test("Ul_B_S");
    Ul_B_S lv;
    check2(sizeof(lv), 11, "sizeof(Ul_B_S)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_S)");
    check_field_offset(lv, v1, 0, "Ul_B_S.v1");
    check_field_offset(lv, v2, 8, "Ul_B_S.v2");
    check_field_offset(lv, v3, 9, "Ul_B_S.v3");
  }
}
static Arrange_To_Call_Me vUl_B_S(Test_Ul_B_S, "Ul_B_S", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_Uc()
{
  {
    init_simple_test("Ul_B_Uc");
    Ul_B_Uc lv;
    check2(sizeof(lv), 10, "sizeof(Ul_B_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_Uc)");
    check_field_offset(lv, v1, 0, "Ul_B_Uc.v1");
    check_field_offset(lv, v2, 8, "Ul_B_Uc.v2");
    check_field_offset(lv, v3, 9, "Ul_B_Uc.v3");
  }
}
static Arrange_To_Call_Me vUl_B_Uc(Test_Ul_B_Uc, "Ul_B_Uc", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_Ui()
{
  {
    init_simple_test("Ul_B_Ui");
    Ul_B_Ui lv;
    check2(sizeof(lv), 13, "sizeof(Ul_B_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_Ui)");
    check_field_offset(lv, v1, 0, "Ul_B_Ui.v1");
    check_field_offset(lv, v2, 8, "Ul_B_Ui.v2");
    check_field_offset(lv, v3, 9, "Ul_B_Ui.v3");
  }
}
static Arrange_To_Call_Me vUl_B_Ui(Test_Ul_B_Ui, "Ul_B_Ui", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_Ul()
{
  {
    init_simple_test("Ul_B_Ul");
    Ul_B_Ul lv;
    check2(sizeof(lv), 17, "sizeof(Ul_B_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_Ul)");
    check_field_offset(lv, v1, 0, "Ul_B_Ul.v1");
    check_field_offset(lv, v2, 8, "Ul_B_Ul.v2");
    check_field_offset(lv, v3, 9, "Ul_B_Ul.v3");
  }
}
static Arrange_To_Call_Me vUl_B_Ul(Test_Ul_B_Ul, "Ul_B_Ul", 17);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_Us()
{
  {
    init_simple_test("Ul_B_Us");
    Ul_B_Us lv;
    check2(sizeof(lv), 11, "sizeof(Ul_B_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_Us)");
    check_field_offset(lv, v1, 0, "Ul_B_Us.v1");
    check_field_offset(lv, v2, 8, "Ul_B_Us.v2");
    check_field_offset(lv, v3, 9, "Ul_B_Us.v3");
  }
}
static Arrange_To_Call_Me vUl_B_Us(Test_Ul_B_Us, "Ul_B_Us", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_B_Vp()
{
  {
    init_simple_test("Ul_B_Vp");
    Ul_B_Vp lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(Ul_B_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_B_Vp)");
    check_field_offset(lv, v1, 0, "Ul_B_Vp.v1");
    check_field_offset(lv, v2, 8, "Ul_B_Vp.v2");
    check_field_offset(lv, v3, 9, "Ul_B_Vp.v3");
  }
}
static Arrange_To_Call_Me vUl_B_Vp(Test_Ul_B_Vp, "Ul_B_Vp", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu15i_B()
{
  {
    init_simple_test("Ul_BFu15i_B");
    static Ul_BFu15i_B lv;
    check2(sizeof(lv), 11, "sizeof(Ul_BFu15i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu15i_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu15i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15i_B");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15i_B");
    check_field_offset(lv, v3, 10, "Ul_BFu15i_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu15i_B(Test_Ul_BFu15i_B, "Ul_BFu15i_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu15ll_B()
{
  {
    init_simple_test("Ul_BFu15ll_B");
    static Ul_BFu15ll_B lv;
    check2(sizeof(lv), 11, "sizeof(Ul_BFu15ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu15ll_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu15ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15ll_B");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15ll_B");
    check_field_offset(lv, v3, 10, "Ul_BFu15ll_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu15ll_B(Test_Ul_BFu15ll_B, "Ul_BFu15ll_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu15s_B()
{
  {
    init_simple_test("Ul_BFu15s_B");
    static Ul_BFu15s_B lv;
    check2(sizeof(lv), 11, "sizeof(Ul_BFu15s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu15s_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu15s_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15s_B");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15s_B");
    check_field_offset(lv, v3, 10, "Ul_BFu15s_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu15s_B(Test_Ul_BFu15s_B, "Ul_BFu15s_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu16i_B()
{
  {
    init_simple_test("Ul_BFu16i_B");
    static Ul_BFu16i_B lv;
    check2(sizeof(lv), 11, "sizeof(Ul_BFu16i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu16i_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu16i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16i_B");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16i_B");
    check_field_offset(lv, v3, 10, "Ul_BFu16i_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu16i_B(Test_Ul_BFu16i_B, "Ul_BFu16i_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu16ll_B()
{
  {
    init_simple_test("Ul_BFu16ll_B");
    static Ul_BFu16ll_B lv;
    check2(sizeof(lv), 11, "sizeof(Ul_BFu16ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu16ll_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu16ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16ll_B");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16ll_B");
    check_field_offset(lv, v3, 10, "Ul_BFu16ll_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu16ll_B(Test_Ul_BFu16ll_B, "Ul_BFu16ll_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu16s_B()
{
  {
    init_simple_test("Ul_BFu16s_B");
    static Ul_BFu16s_B lv;
    check2(sizeof(lv), 11, "sizeof(Ul_BFu16s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu16s_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu16s_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16s_B");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16s_B");
    check_field_offset(lv, v3, 10, "Ul_BFu16s_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu16s_B(Test_Ul_BFu16s_B, "Ul_BFu16s_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu17i_B()
{
  {
    init_simple_test("Ul_BFu17i_B");
    static Ul_BFu17i_B lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu17i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu17i_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu17i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu17i_B");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu17i_B");
    check_field_offset(lv, v3, 11, "Ul_BFu17i_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu17i_B(Test_Ul_BFu17i_B, "Ul_BFu17i_B", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu17ll_B()
{
  {
    init_simple_test("Ul_BFu17ll_B");
    static Ul_BFu17ll_B lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu17ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu17ll_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu17ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu17ll_B");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu17ll_B");
    check_field_offset(lv, v3, 11, "Ul_BFu17ll_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu17ll_B(Test_Ul_BFu17ll_B, "Ul_BFu17ll_B", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu1c_B()
{
  {
    init_simple_test("Ul_BFu1c_B");
    static Ul_BFu1c_B lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu1c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu1c_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu1c_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1c_B");
    check_field_offset(lv, v3, 9, "Ul_BFu1c_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu1c_B(Test_Ul_BFu1c_B, "Ul_BFu1c_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu1i_B()
{
  {
    init_simple_test("Ul_BFu1i_B");
    static Ul_BFu1i_B lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu1i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu1i_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu1i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1i_B");
    check_field_offset(lv, v3, 9, "Ul_BFu1i_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu1i_B(Test_Ul_BFu1i_B, "Ul_BFu1i_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu1ll_B()
{
  {
    init_simple_test("Ul_BFu1ll_B");
    static Ul_BFu1ll_B lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu1ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu1ll_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu1ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1ll_B");
    check_field_offset(lv, v3, 9, "Ul_BFu1ll_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu1ll_B(Test_Ul_BFu1ll_B, "Ul_BFu1ll_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu1s_B()
{
  {
    init_simple_test("Ul_BFu1s_B");
    static Ul_BFu1s_B lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu1s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu1s_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu1s_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1s_B");
    check_field_offset(lv, v3, 9, "Ul_BFu1s_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu1s_B(Test_Ul_BFu1s_B, "Ul_BFu1s_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu31i_B()
{
  {
    init_simple_test("Ul_BFu31i_B");
    static Ul_BFu31i_B lv;
    check2(sizeof(lv), 13, "sizeof(Ul_BFu31i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu31i_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu31i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu31i_B");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu31i_B");
    check_field_offset(lv, v3, 12, "Ul_BFu31i_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu31i_B(Test_Ul_BFu31i_B, "Ul_BFu31i_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu31ll_B()
{
  {
    init_simple_test("Ul_BFu31ll_B");
    static Ul_BFu31ll_B lv;
    check2(sizeof(lv), 13, "sizeof(Ul_BFu31ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu31ll_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu31ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu31ll_B");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu31ll_B");
    check_field_offset(lv, v3, 12, "Ul_BFu31ll_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu31ll_B(Test_Ul_BFu31ll_B, "Ul_BFu31ll_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu32i_B()
{
  {
    init_simple_test("Ul_BFu32i_B");
    static Ul_BFu32i_B lv;
    check2(sizeof(lv), 13, "sizeof(Ul_BFu32i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu32i_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu32i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu32i_B");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu32i_B");
    check_field_offset(lv, v3, 12, "Ul_BFu32i_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu32i_B(Test_Ul_BFu32i_B, "Ul_BFu32i_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu32ll_B()
{
  {
    init_simple_test("Ul_BFu32ll_B");
    static Ul_BFu32ll_B lv;
    check2(sizeof(lv), 13, "sizeof(Ul_BFu32ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu32ll_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu32ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu32ll_B");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu32ll_B");
    check_field_offset(lv, v3, 12, "Ul_BFu32ll_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu32ll_B(Test_Ul_BFu32ll_B, "Ul_BFu32ll_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu33_B()
{
  {
    init_simple_test("Ul_BFu33_B");
    static Ul_BFu33_B lv;
    check2(sizeof(lv), 14, "sizeof(Ul_BFu33_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu33_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu33_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 33, 1, "Ul_BFu33_B");
    set_bf_and_test(lv, v2, 8, 0, 33, hide_ull(1LL<<32), "Ul_BFu33_B");
    check_field_offset(lv, v3, 13, "Ul_BFu33_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu33_B(Test_Ul_BFu33_B, "Ul_BFu33_B", 14);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu7c_B()
{
  {
    init_simple_test("Ul_BFu7c_B");
    static Ul_BFu7c_B lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu7c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu7c_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu7c_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7c_B");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7c_B");
    check_field_offset(lv, v3, 9, "Ul_BFu7c_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu7c_B(Test_Ul_BFu7c_B, "Ul_BFu7c_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu7i_B()
{
  {
    init_simple_test("Ul_BFu7i_B");
    static Ul_BFu7i_B lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu7i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu7i_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu7i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7i_B");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7i_B");
    check_field_offset(lv, v3, 9, "Ul_BFu7i_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu7i_B(Test_Ul_BFu7i_B, "Ul_BFu7i_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu7ll_B()
{
  {
    init_simple_test("Ul_BFu7ll_B");
    static Ul_BFu7ll_B lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu7ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu7ll_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu7ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7ll_B");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7ll_B");
    check_field_offset(lv, v3, 9, "Ul_BFu7ll_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu7ll_B(Test_Ul_BFu7ll_B, "Ul_BFu7ll_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu7s_B()
{
  {
    init_simple_test("Ul_BFu7s_B");
    static Ul_BFu7s_B lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu7s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu7s_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu7s_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7s_B");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7s_B");
    check_field_offset(lv, v3, 9, "Ul_BFu7s_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu7s_B(Test_Ul_BFu7s_B, "Ul_BFu7s_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu8c_B()
{
  {
    init_simple_test("Ul_BFu8c_B");
    static Ul_BFu8c_B lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu8c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu8c_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu8c_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8c_B");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8c_B");
    check_field_offset(lv, v3, 9, "Ul_BFu8c_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu8c_B(Test_Ul_BFu8c_B, "Ul_BFu8c_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu8i_B()
{
  {
    init_simple_test("Ul_BFu8i_B");
    static Ul_BFu8i_B lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu8i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu8i_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu8i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8i_B");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8i_B");
    check_field_offset(lv, v3, 9, "Ul_BFu8i_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu8i_B(Test_Ul_BFu8i_B, "Ul_BFu8i_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu8ll_B()
{
  {
    init_simple_test("Ul_BFu8ll_B");
    static Ul_BFu8ll_B lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu8ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu8ll_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu8ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8ll_B");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8ll_B");
    check_field_offset(lv, v3, 9, "Ul_BFu8ll_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu8ll_B(Test_Ul_BFu8ll_B, "Ul_BFu8ll_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu8s_B()
{
  {
    init_simple_test("Ul_BFu8s_B");
    static Ul_BFu8s_B lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu8s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu8s_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu8s_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8s_B");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8s_B");
    check_field_offset(lv, v3, 9, "Ul_BFu8s_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu8s_B(Test_Ul_BFu8s_B, "Ul_BFu8s_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu9i_B()
{
  {
    init_simple_test("Ul_BFu9i_B");
    static Ul_BFu9i_B lv;
    check2(sizeof(lv), 11, "sizeof(Ul_BFu9i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu9i_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu9i_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9i_B");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9i_B");
    check_field_offset(lv, v3, 10, "Ul_BFu9i_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu9i_B(Test_Ul_BFu9i_B, "Ul_BFu9i_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu9ll_B()
{
  {
    init_simple_test("Ul_BFu9ll_B");
    static Ul_BFu9ll_B lv;
    check2(sizeof(lv), 11, "sizeof(Ul_BFu9ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu9ll_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu9ll_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9ll_B");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9ll_B");
    check_field_offset(lv, v3, 10, "Ul_BFu9ll_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu9ll_B(Test_Ul_BFu9ll_B, "Ul_BFu9ll_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu9s_B()
{
  {
    init_simple_test("Ul_BFu9s_B");
    static Ul_BFu9s_B lv;
    check2(sizeof(lv), 11, "sizeof(Ul_BFu9s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu9s_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu9s_B.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9s_B");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9s_B");
    check_field_offset(lv, v3, 10, "Ul_BFu9s_B.v3");
  }
}
static Arrange_To_Call_Me vUl_BFu9s_B(Test_Ul_BFu9s_B, "Ul_BFu9s_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_C_B()
{
  {
    init_simple_test("Ul_C_B");
    Ul_C_B lv;
    check2(sizeof(lv), 10, "sizeof(Ul_C_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_C_B)");
    check_field_offset(lv, v1, 0, "Ul_C_B.v1");
    check_field_offset(lv, v2, 8, "Ul_C_B.v2");
    check_field_offset(lv, v3, 9, "Ul_C_B.v3");
  }
}
static Arrange_To_Call_Me vUl_C_B(Test_Ul_C_B, "Ul_C_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_D_B()
{
  {
    init_simple_test("Ul_D_B");
    Ul_D_B lv;
    check2(sizeof(lv), 17, "sizeof(Ul_D_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_D_B)");
    check_field_offset(lv, v1, 0, "Ul_D_B.v1");
    check_field_offset(lv, v2, 8, "Ul_D_B.v2");
    check_field_offset(lv, v3, 16, "Ul_D_B.v3");
  }
}
static Arrange_To_Call_Me vUl_D_B(Test_Ul_D_B, "Ul_D_B", 17);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_F_B()
{
  {
    init_simple_test("Ul_F_B");
    Ul_F_B lv;
    check2(sizeof(lv), 13, "sizeof(Ul_F_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_F_B)");
    check_field_offset(lv, v1, 0, "Ul_F_B.v1");
    check_field_offset(lv, v2, 8, "Ul_F_B.v2");
    check_field_offset(lv, v3, 12, "Ul_F_B.v3");
  }
}
static Arrange_To_Call_Me vUl_F_B(Test_Ul_F_B, "Ul_F_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_I_B()
{
  {
    init_simple_test("Ul_I_B");
    Ul_I_B lv;
    check2(sizeof(lv), 13, "sizeof(Ul_I_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_I_B)");
    check_field_offset(lv, v1, 0, "Ul_I_B.v1");
    check_field_offset(lv, v2, 8, "Ul_I_B.v2");
    check_field_offset(lv, v3, 12, "Ul_I_B.v3");
  }
}
static Arrange_To_Call_Me vUl_I_B(Test_Ul_I_B, "Ul_I_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Ip_B()
{
  {
    init_simple_test("Ul_Ip_B");
    Ul_Ip_B lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(Ul_Ip_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Ip_B)");
    check_field_offset(lv, v1, 0, "Ul_Ip_B.v1");
    check_field_offset(lv, v2, 8, "Ul_Ip_B.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Ul_Ip_B.v3");
  }
}
static Arrange_To_Call_Me vUl_Ip_B(Test_Ul_Ip_B, "Ul_Ip_B", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_L_B()
{
  {
    init_simple_test("Ul_L_B");
    Ul_L_B lv;
    check2(sizeof(lv), 17, "sizeof(Ul_L_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_L_B)");
    check_field_offset(lv, v1, 0, "Ul_L_B.v1");
    check_field_offset(lv, v2, 8, "Ul_L_B.v2");
    check_field_offset(lv, v3, 16, "Ul_L_B.v3");
  }
}
static Arrange_To_Call_Me vUl_L_B(Test_Ul_L_B, "Ul_L_B", 17);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_S_B()
{
  {
    init_simple_test("Ul_S_B");
    Ul_S_B lv;
    check2(sizeof(lv), 11, "sizeof(Ul_S_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_S_B)");
    check_field_offset(lv, v1, 0, "Ul_S_B.v1");
    check_field_offset(lv, v2, 8, "Ul_S_B.v2");
    check_field_offset(lv, v3, 10, "Ul_S_B.v3");
  }
}
static Arrange_To_Call_Me vUl_S_B(Test_Ul_S_B, "Ul_S_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Uc_B()
{
  {
    init_simple_test("Ul_Uc_B");
    Ul_Uc_B lv;
    check2(sizeof(lv), 10, "sizeof(Ul_Uc_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Uc_B)");
    check_field_offset(lv, v1, 0, "Ul_Uc_B.v1");
    check_field_offset(lv, v2, 8, "Ul_Uc_B.v2");
    check_field_offset(lv, v3, 9, "Ul_Uc_B.v3");
  }
}
static Arrange_To_Call_Me vUl_Uc_B(Test_Ul_Uc_B, "Ul_Uc_B", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Ui_B()
{
  {
    init_simple_test("Ul_Ui_B");
    Ul_Ui_B lv;
    check2(sizeof(lv), 13, "sizeof(Ul_Ui_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Ui_B)");
    check_field_offset(lv, v1, 0, "Ul_Ui_B.v1");
    check_field_offset(lv, v2, 8, "Ul_Ui_B.v2");
    check_field_offset(lv, v3, 12, "Ul_Ui_B.v3");
  }
}
static Arrange_To_Call_Me vUl_Ui_B(Test_Ul_Ui_B, "Ul_Ui_B", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Ul_B()
{
  {
    init_simple_test("Ul_Ul_B");
    Ul_Ul_B lv;
    check2(sizeof(lv), 17, "sizeof(Ul_Ul_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Ul_B)");
    check_field_offset(lv, v1, 0, "Ul_Ul_B.v1");
    check_field_offset(lv, v2, 8, "Ul_Ul_B.v2");
    check_field_offset(lv, v3, 16, "Ul_Ul_B.v3");
  }
}
static Arrange_To_Call_Me vUl_Ul_B(Test_Ul_Ul_B, "Ul_Ul_B", 17);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Us_B()
{
  {
    init_simple_test("Ul_Us_B");
    Ul_Us_B lv;
    check2(sizeof(lv), 11, "sizeof(Ul_Us_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Us_B)");
    check_field_offset(lv, v1, 0, "Ul_Us_B.v1");
    check_field_offset(lv, v2, 8, "Ul_Us_B.v2");
    check_field_offset(lv, v3, 10, "Ul_Us_B.v3");
  }
}
static Arrange_To_Call_Me vUl_Us_B(Test_Ul_Us_B, "Ul_Us_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Vp_B()
{
  {
    init_simple_test("Ul_Vp_B");
    Ul_Vp_B lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(Ul_Vp_B)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Vp_B)");
    check_field_offset(lv, v1, 0, "Ul_Vp_B.v1");
    check_field_offset(lv, v2, 8, "Ul_Vp_B.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Ul_Vp_B.v3");
  }
}
static Arrange_To_Call_Me vUl_Vp_B(Test_Ul_Vp_B, "Ul_Vp_B", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B()
{
  {
    init_simple_test("Us_B");
    Us_B lv;
    check2(sizeof(lv), 3, "sizeof(Us_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B)");
    check_field_offset(lv, v1, 0, "Us_B.v1");
    check_field_offset(lv, v2, 2, "Us_B.v2");
  }
}
static Arrange_To_Call_Me vUs_B(Test_Us_B, "Us_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_B()
{
  {
    init_simple_test("Us_B_B");
    Us_B_B lv;
    check2(sizeof(lv), 4, "sizeof(Us_B_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_B)");
    check_field_offset(lv, v1, 0, "Us_B_B.v1");
    check_field_offset(lv, v2, 2, "Us_B_B.v2");
    check_field_offset(lv, v3, 3, "Us_B_B.v3");
  }
}
static Arrange_To_Call_Me vUs_B_B(Test_Us_B_B, "Us_B_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu15i()
{
  {
    init_simple_test("Us_B_BFu15i");
    static Us_B_BFu15i lv;
    check2(sizeof(lv), 5, "sizeof(Us_B_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu15i)");
    check_field_offset(lv, v1, 0, "Us_B_BFu15i.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu15i.v2");
    set_bf_and_test(lv, v3, 3, 0, 15, 1, "Us_B_BFu15i");
    set_bf_and_test(lv, v3, 3, 0, 15, hide_ull(1LL<<14), "Us_B_BFu15i");
  }
}
static Arrange_To_Call_Me vUs_B_BFu15i(Test_Us_B_BFu15i, "Us_B_BFu15i", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu15ll()
{
  {
    init_simple_test("Us_B_BFu15ll");
    static Us_B_BFu15ll lv;
    check2(sizeof(lv), 5, "sizeof(Us_B_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu15ll)");
    check_field_offset(lv, v1, 0, "Us_B_BFu15ll.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu15ll.v2");
    set_bf_and_test(lv, v3, 3, 0, 15, 1, "Us_B_BFu15ll");
    set_bf_and_test(lv, v3, 3, 0, 15, hide_ull(1LL<<14), "Us_B_BFu15ll");
  }
}
static Arrange_To_Call_Me vUs_B_BFu15ll(Test_Us_B_BFu15ll, "Us_B_BFu15ll", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu15s()
{
  {
    init_simple_test("Us_B_BFu15s");
    static Us_B_BFu15s lv;
    check2(sizeof(lv), 5, "sizeof(Us_B_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu15s)");
    check_field_offset(lv, v1, 0, "Us_B_BFu15s.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu15s.v2");
    set_bf_and_test(lv, v3, 3, 0, 15, 1, "Us_B_BFu15s");
    set_bf_and_test(lv, v3, 3, 0, 15, hide_ull(1LL<<14), "Us_B_BFu15s");
  }
}
static Arrange_To_Call_Me vUs_B_BFu15s(Test_Us_B_BFu15s, "Us_B_BFu15s", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu16i()
{
  {
    init_simple_test("Us_B_BFu16i");
    static Us_B_BFu16i lv;
    check2(sizeof(lv), 5, "sizeof(Us_B_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu16i)");
    check_field_offset(lv, v1, 0, "Us_B_BFu16i.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu16i.v2");
    set_bf_and_test(lv, v3, 3, 0, 16, 1, "Us_B_BFu16i");
    set_bf_and_test(lv, v3, 3, 0, 16, hide_ull(1LL<<15), "Us_B_BFu16i");
  }
}
static Arrange_To_Call_Me vUs_B_BFu16i(Test_Us_B_BFu16i, "Us_B_BFu16i", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu16ll()
{
  {
    init_simple_test("Us_B_BFu16ll");
    static Us_B_BFu16ll lv;
    check2(sizeof(lv), 5, "sizeof(Us_B_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu16ll)");
    check_field_offset(lv, v1, 0, "Us_B_BFu16ll.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu16ll.v2");
    set_bf_and_test(lv, v3, 3, 0, 16, 1, "Us_B_BFu16ll");
    set_bf_and_test(lv, v3, 3, 0, 16, hide_ull(1LL<<15), "Us_B_BFu16ll");
  }
}
static Arrange_To_Call_Me vUs_B_BFu16ll(Test_Us_B_BFu16ll, "Us_B_BFu16ll", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu16s()
{
  {
    init_simple_test("Us_B_BFu16s");
    static Us_B_BFu16s lv;
    check2(sizeof(lv), 5, "sizeof(Us_B_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu16s)");
    check_field_offset(lv, v1, 0, "Us_B_BFu16s.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu16s.v2");
    set_bf_and_test(lv, v3, 3, 0, 16, 1, "Us_B_BFu16s");
    set_bf_and_test(lv, v3, 3, 0, 16, hide_ull(1LL<<15), "Us_B_BFu16s");
  }
}
static Arrange_To_Call_Me vUs_B_BFu16s(Test_Us_B_BFu16s, "Us_B_BFu16s", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu17i()
{
  {
    init_simple_test("Us_B_BFu17i");
    static Us_B_BFu17i lv;
    check2(sizeof(lv), 6, "sizeof(Us_B_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu17i)");
    check_field_offset(lv, v1, 0, "Us_B_BFu17i.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu17i.v2");
    set_bf_and_test(lv, v3, 3, 0, 17, 1, "Us_B_BFu17i");
    set_bf_and_test(lv, v3, 3, 0, 17, hide_ull(1LL<<16), "Us_B_BFu17i");
  }
}
static Arrange_To_Call_Me vUs_B_BFu17i(Test_Us_B_BFu17i, "Us_B_BFu17i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu17ll()
{
  {
    init_simple_test("Us_B_BFu17ll");
    static Us_B_BFu17ll lv;
    check2(sizeof(lv), 6, "sizeof(Us_B_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu17ll)");
    check_field_offset(lv, v1, 0, "Us_B_BFu17ll.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu17ll.v2");
    set_bf_and_test(lv, v3, 3, 0, 17, 1, "Us_B_BFu17ll");
    set_bf_and_test(lv, v3, 3, 0, 17, hide_ull(1LL<<16), "Us_B_BFu17ll");
  }
}
static Arrange_To_Call_Me vUs_B_BFu17ll(Test_Us_B_BFu17ll, "Us_B_BFu17ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu1c()
{
  {
    init_simple_test("Us_B_BFu1c");
    static Us_B_BFu1c lv;
    check2(sizeof(lv), 4, "sizeof(Us_B_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu1c)");
    check_field_offset(lv, v1, 0, "Us_B_BFu1c.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu1c.v2");
    set_bf_and_test(lv, v3, 3, 0, 1, 1, "Us_B_BFu1c");
  }
}
static Arrange_To_Call_Me vUs_B_BFu1c(Test_Us_B_BFu1c, "Us_B_BFu1c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu1i()
{
  {
    init_simple_test("Us_B_BFu1i");
    static Us_B_BFu1i lv;
    check2(sizeof(lv), 4, "sizeof(Us_B_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu1i)");
    check_field_offset(lv, v1, 0, "Us_B_BFu1i.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu1i.v2");
    set_bf_and_test(lv, v3, 3, 0, 1, 1, "Us_B_BFu1i");
  }
}
static Arrange_To_Call_Me vUs_B_BFu1i(Test_Us_B_BFu1i, "Us_B_BFu1i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu1ll()
{
  {
    init_simple_test("Us_B_BFu1ll");
    static Us_B_BFu1ll lv;
    check2(sizeof(lv), 4, "sizeof(Us_B_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu1ll)");
    check_field_offset(lv, v1, 0, "Us_B_BFu1ll.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu1ll.v2");
    set_bf_and_test(lv, v3, 3, 0, 1, 1, "Us_B_BFu1ll");
  }
}
static Arrange_To_Call_Me vUs_B_BFu1ll(Test_Us_B_BFu1ll, "Us_B_BFu1ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu1s()
{
  {
    init_simple_test("Us_B_BFu1s");
    static Us_B_BFu1s lv;
    check2(sizeof(lv), 4, "sizeof(Us_B_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu1s)");
    check_field_offset(lv, v1, 0, "Us_B_BFu1s.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu1s.v2");
    set_bf_and_test(lv, v3, 3, 0, 1, 1, "Us_B_BFu1s");
  }
}
static Arrange_To_Call_Me vUs_B_BFu1s(Test_Us_B_BFu1s, "Us_B_BFu1s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu31i()
{
  {
    init_simple_test("Us_B_BFu31i");
    static Us_B_BFu31i lv;
    check2(sizeof(lv), 7, "sizeof(Us_B_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu31i)");
    check_field_offset(lv, v1, 0, "Us_B_BFu31i.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu31i.v2");
    set_bf_and_test(lv, v3, 3, 0, 31, 1, "Us_B_BFu31i");
    set_bf_and_test(lv, v3, 3, 0, 31, hide_ull(1LL<<30), "Us_B_BFu31i");
  }
}
static Arrange_To_Call_Me vUs_B_BFu31i(Test_Us_B_BFu31i, "Us_B_BFu31i", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu31ll()
{
  {
    init_simple_test("Us_B_BFu31ll");
    static Us_B_BFu31ll lv;
    check2(sizeof(lv), 7, "sizeof(Us_B_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu31ll)");
    check_field_offset(lv, v1, 0, "Us_B_BFu31ll.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu31ll.v2");
    set_bf_and_test(lv, v3, 3, 0, 31, 1, "Us_B_BFu31ll");
    set_bf_and_test(lv, v3, 3, 0, 31, hide_ull(1LL<<30), "Us_B_BFu31ll");
  }
}
static Arrange_To_Call_Me vUs_B_BFu31ll(Test_Us_B_BFu31ll, "Us_B_BFu31ll", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu32i()
{
  {
    init_simple_test("Us_B_BFu32i");
    static Us_B_BFu32i lv;
    check2(sizeof(lv), 7, "sizeof(Us_B_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu32i)");
    check_field_offset(lv, v1, 0, "Us_B_BFu32i.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu32i.v2");
    set_bf_and_test(lv, v3, 3, 0, 32, 1, "Us_B_BFu32i");
    set_bf_and_test(lv, v3, 3, 0, 32, hide_ull(1LL<<31), "Us_B_BFu32i");
  }
}
static Arrange_To_Call_Me vUs_B_BFu32i(Test_Us_B_BFu32i, "Us_B_BFu32i", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu32ll()
{
  {
    init_simple_test("Us_B_BFu32ll");
    static Us_B_BFu32ll lv;
    check2(sizeof(lv), 7, "sizeof(Us_B_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu32ll)");
    check_field_offset(lv, v1, 0, "Us_B_BFu32ll.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu32ll.v2");
    set_bf_and_test(lv, v3, 3, 0, 32, 1, "Us_B_BFu32ll");
    set_bf_and_test(lv, v3, 3, 0, 32, hide_ull(1LL<<31), "Us_B_BFu32ll");
  }
}
static Arrange_To_Call_Me vUs_B_BFu32ll(Test_Us_B_BFu32ll, "Us_B_BFu32ll", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu33()
{
  {
    init_simple_test("Us_B_BFu33");
    static Us_B_BFu33 lv;
    check2(sizeof(lv), 8, "sizeof(Us_B_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu33)");
    check_field_offset(lv, v1, 0, "Us_B_BFu33.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu33.v2");
    set_bf_and_test(lv, v3, 3, 0, 33, 1, "Us_B_BFu33");
    set_bf_and_test(lv, v3, 3, 0, 33, hide_ull(1LL<<32), "Us_B_BFu33");
  }
}
static Arrange_To_Call_Me vUs_B_BFu33(Test_Us_B_BFu33, "Us_B_BFu33", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu7c()
{
  {
    init_simple_test("Us_B_BFu7c");
    static Us_B_BFu7c lv;
    check2(sizeof(lv), 4, "sizeof(Us_B_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu7c)");
    check_field_offset(lv, v1, 0, "Us_B_BFu7c.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu7c.v2");
    set_bf_and_test(lv, v3, 3, 0, 7, 1, "Us_B_BFu7c");
    set_bf_and_test(lv, v3, 3, 0, 7, hide_ull(1LL<<6), "Us_B_BFu7c");
  }
}
static Arrange_To_Call_Me vUs_B_BFu7c(Test_Us_B_BFu7c, "Us_B_BFu7c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu7i()
{
  {
    init_simple_test("Us_B_BFu7i");
    static Us_B_BFu7i lv;
    check2(sizeof(lv), 4, "sizeof(Us_B_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu7i)");
    check_field_offset(lv, v1, 0, "Us_B_BFu7i.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu7i.v2");
    set_bf_and_test(lv, v3, 3, 0, 7, 1, "Us_B_BFu7i");
    set_bf_and_test(lv, v3, 3, 0, 7, hide_ull(1LL<<6), "Us_B_BFu7i");
  }
}
static Arrange_To_Call_Me vUs_B_BFu7i(Test_Us_B_BFu7i, "Us_B_BFu7i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu7ll()
{
  {
    init_simple_test("Us_B_BFu7ll");
    static Us_B_BFu7ll lv;
    check2(sizeof(lv), 4, "sizeof(Us_B_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu7ll)");
    check_field_offset(lv, v1, 0, "Us_B_BFu7ll.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu7ll.v2");
    set_bf_and_test(lv, v3, 3, 0, 7, 1, "Us_B_BFu7ll");
    set_bf_and_test(lv, v3, 3, 0, 7, hide_ull(1LL<<6), "Us_B_BFu7ll");
  }
}
static Arrange_To_Call_Me vUs_B_BFu7ll(Test_Us_B_BFu7ll, "Us_B_BFu7ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu7s()
{
  {
    init_simple_test("Us_B_BFu7s");
    static Us_B_BFu7s lv;
    check2(sizeof(lv), 4, "sizeof(Us_B_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu7s)");
    check_field_offset(lv, v1, 0, "Us_B_BFu7s.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu7s.v2");
    set_bf_and_test(lv, v3, 3, 0, 7, 1, "Us_B_BFu7s");
    set_bf_and_test(lv, v3, 3, 0, 7, hide_ull(1LL<<6), "Us_B_BFu7s");
  }
}
static Arrange_To_Call_Me vUs_B_BFu7s(Test_Us_B_BFu7s, "Us_B_BFu7s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu8c()
{
  {
    init_simple_test("Us_B_BFu8c");
    static Us_B_BFu8c lv;
    check2(sizeof(lv), 4, "sizeof(Us_B_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu8c)");
    check_field_offset(lv, v1, 0, "Us_B_BFu8c.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu8c.v2");
    set_bf_and_test(lv, v3, 3, 0, 8, 1, "Us_B_BFu8c");
    set_bf_and_test(lv, v3, 3, 0, 8, hide_ull(1LL<<7), "Us_B_BFu8c");
  }
}
static Arrange_To_Call_Me vUs_B_BFu8c(Test_Us_B_BFu8c, "Us_B_BFu8c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu8i()
{
  {
    init_simple_test("Us_B_BFu8i");
    static Us_B_BFu8i lv;
    check2(sizeof(lv), 4, "sizeof(Us_B_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu8i)");
    check_field_offset(lv, v1, 0, "Us_B_BFu8i.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu8i.v2");
    set_bf_and_test(lv, v3, 3, 0, 8, 1, "Us_B_BFu8i");
    set_bf_and_test(lv, v3, 3, 0, 8, hide_ull(1LL<<7), "Us_B_BFu8i");
  }
}
static Arrange_To_Call_Me vUs_B_BFu8i(Test_Us_B_BFu8i, "Us_B_BFu8i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu8ll()
{
  {
    init_simple_test("Us_B_BFu8ll");
    static Us_B_BFu8ll lv;
    check2(sizeof(lv), 4, "sizeof(Us_B_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu8ll)");
    check_field_offset(lv, v1, 0, "Us_B_BFu8ll.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu8ll.v2");
    set_bf_and_test(lv, v3, 3, 0, 8, 1, "Us_B_BFu8ll");
    set_bf_and_test(lv, v3, 3, 0, 8, hide_ull(1LL<<7), "Us_B_BFu8ll");
  }
}
static Arrange_To_Call_Me vUs_B_BFu8ll(Test_Us_B_BFu8ll, "Us_B_BFu8ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu8s()
{
  {
    init_simple_test("Us_B_BFu8s");
    static Us_B_BFu8s lv;
    check2(sizeof(lv), 4, "sizeof(Us_B_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu8s)");
    check_field_offset(lv, v1, 0, "Us_B_BFu8s.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu8s.v2");
    set_bf_and_test(lv, v3, 3, 0, 8, 1, "Us_B_BFu8s");
    set_bf_and_test(lv, v3, 3, 0, 8, hide_ull(1LL<<7), "Us_B_BFu8s");
  }
}
static Arrange_To_Call_Me vUs_B_BFu8s(Test_Us_B_BFu8s, "Us_B_BFu8s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu9i()
{
  {
    init_simple_test("Us_B_BFu9i");
    static Us_B_BFu9i lv;
    check2(sizeof(lv), 5, "sizeof(Us_B_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu9i)");
    check_field_offset(lv, v1, 0, "Us_B_BFu9i.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu9i.v2");
    set_bf_and_test(lv, v3, 3, 0, 9, 1, "Us_B_BFu9i");
    set_bf_and_test(lv, v3, 3, 0, 9, hide_ull(1LL<<8), "Us_B_BFu9i");
  }
}
static Arrange_To_Call_Me vUs_B_BFu9i(Test_Us_B_BFu9i, "Us_B_BFu9i", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu9ll()
{
  {
    init_simple_test("Us_B_BFu9ll");
    static Us_B_BFu9ll lv;
    check2(sizeof(lv), 5, "sizeof(Us_B_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu9ll)");
    check_field_offset(lv, v1, 0, "Us_B_BFu9ll.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu9ll.v2");
    set_bf_and_test(lv, v3, 3, 0, 9, 1, "Us_B_BFu9ll");
    set_bf_and_test(lv, v3, 3, 0, 9, hide_ull(1LL<<8), "Us_B_BFu9ll");
  }
}
static Arrange_To_Call_Me vUs_B_BFu9ll(Test_Us_B_BFu9ll, "Us_B_BFu9ll", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_BFu9s()
{
  {
    init_simple_test("Us_B_BFu9s");
    static Us_B_BFu9s lv;
    check2(sizeof(lv), 5, "sizeof(Us_B_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_BFu9s)");
    check_field_offset(lv, v1, 0, "Us_B_BFu9s.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu9s.v2");
    set_bf_and_test(lv, v3, 3, 0, 9, 1, "Us_B_BFu9s");
    set_bf_and_test(lv, v3, 3, 0, 9, hide_ull(1LL<<8), "Us_B_BFu9s");
  }
}
static Arrange_To_Call_Me vUs_B_BFu9s(Test_Us_B_BFu9s, "Us_B_BFu9s", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_C()
{
  {
    init_simple_test("Us_B_C");
    Us_B_C lv;
    check2(sizeof(lv), 4, "sizeof(Us_B_C)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_C)");
    check_field_offset(lv, v1, 0, "Us_B_C.v1");
    check_field_offset(lv, v2, 2, "Us_B_C.v2");
    check_field_offset(lv, v3, 3, "Us_B_C.v3");
  }
}
static Arrange_To_Call_Me vUs_B_C(Test_Us_B_C, "Us_B_C", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_D()
{
  {
    init_simple_test("Us_B_D");
    Us_B_D lv;
    check2(sizeof(lv), 11, "sizeof(Us_B_D)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_D)");
    check_field_offset(lv, v1, 0, "Us_B_D.v1");
    check_field_offset(lv, v2, 2, "Us_B_D.v2");
    check_field_offset(lv, v3, 3, "Us_B_D.v3");
  }
}
static Arrange_To_Call_Me vUs_B_D(Test_Us_B_D, "Us_B_D", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_F()
{
  {
    init_simple_test("Us_B_F");
    Us_B_F lv;
    check2(sizeof(lv), 7, "sizeof(Us_B_F)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_F)");
    check_field_offset(lv, v1, 0, "Us_B_F.v1");
    check_field_offset(lv, v2, 2, "Us_B_F.v2");
    check_field_offset(lv, v3, 3, "Us_B_F.v3");
  }
}
static Arrange_To_Call_Me vUs_B_F(Test_Us_B_F, "Us_B_F", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_I()
{
  {
    init_simple_test("Us_B_I");
    Us_B_I lv;
    check2(sizeof(lv), 7, "sizeof(Us_B_I)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_I)");
    check_field_offset(lv, v1, 0, "Us_B_I.v1");
    check_field_offset(lv, v2, 2, "Us_B_I.v2");
    check_field_offset(lv, v3, 3, "Us_B_I.v3");
  }
}
static Arrange_To_Call_Me vUs_B_I(Test_Us_B_I, "Us_B_I", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_Ip()
{
  {
    init_simple_test("Us_B_Ip");
    Us_B_Ip lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Us_B_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_Ip)");
    check_field_offset(lv, v1, 0, "Us_B_Ip.v1");
    check_field_offset(lv, v2, 2, "Us_B_Ip.v2");
    check_field_offset(lv, v3, 3, "Us_B_Ip.v3");
  }
}
static Arrange_To_Call_Me vUs_B_Ip(Test_Us_B_Ip, "Us_B_Ip", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_L()
{
  {
    init_simple_test("Us_B_L");
    Us_B_L lv;
    check2(sizeof(lv), 11, "sizeof(Us_B_L)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_L)");
    check_field_offset(lv, v1, 0, "Us_B_L.v1");
    check_field_offset(lv, v2, 2, "Us_B_L.v2");
    check_field_offset(lv, v3, 3, "Us_B_L.v3");
  }
}
static Arrange_To_Call_Me vUs_B_L(Test_Us_B_L, "Us_B_L", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_S()
{
  {
    init_simple_test("Us_B_S");
    Us_B_S lv;
    check2(sizeof(lv), 5, "sizeof(Us_B_S)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_S)");
    check_field_offset(lv, v1, 0, "Us_B_S.v1");
    check_field_offset(lv, v2, 2, "Us_B_S.v2");
    check_field_offset(lv, v3, 3, "Us_B_S.v3");
  }
}
static Arrange_To_Call_Me vUs_B_S(Test_Us_B_S, "Us_B_S", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_Uc()
{
  {
    init_simple_test("Us_B_Uc");
    Us_B_Uc lv;
    check2(sizeof(lv), 4, "sizeof(Us_B_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_Uc)");
    check_field_offset(lv, v1, 0, "Us_B_Uc.v1");
    check_field_offset(lv, v2, 2, "Us_B_Uc.v2");
    check_field_offset(lv, v3, 3, "Us_B_Uc.v3");
  }
}
static Arrange_To_Call_Me vUs_B_Uc(Test_Us_B_Uc, "Us_B_Uc", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_Ui()
{
  {
    init_simple_test("Us_B_Ui");
    Us_B_Ui lv;
    check2(sizeof(lv), 7, "sizeof(Us_B_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_Ui)");
    check_field_offset(lv, v1, 0, "Us_B_Ui.v1");
    check_field_offset(lv, v2, 2, "Us_B_Ui.v2");
    check_field_offset(lv, v3, 3, "Us_B_Ui.v3");
  }
}
static Arrange_To_Call_Me vUs_B_Ui(Test_Us_B_Ui, "Us_B_Ui", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_Ul()
{
  {
    init_simple_test("Us_B_Ul");
    Us_B_Ul lv;
    check2(sizeof(lv), 11, "sizeof(Us_B_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_Ul)");
    check_field_offset(lv, v1, 0, "Us_B_Ul.v1");
    check_field_offset(lv, v2, 2, "Us_B_Ul.v2");
    check_field_offset(lv, v3, 3, "Us_B_Ul.v3");
  }
}
static Arrange_To_Call_Me vUs_B_Ul(Test_Us_B_Ul, "Us_B_Ul", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_Us()
{
  {
    init_simple_test("Us_B_Us");
    Us_B_Us lv;
    check2(sizeof(lv), 5, "sizeof(Us_B_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_Us)");
    check_field_offset(lv, v1, 0, "Us_B_Us.v1");
    check_field_offset(lv, v2, 2, "Us_B_Us.v2");
    check_field_offset(lv, v3, 3, "Us_B_Us.v3");
  }
}
static Arrange_To_Call_Me vUs_B_Us(Test_Us_B_Us, "Us_B_Us", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_B_Vp()
{
  {
    init_simple_test("Us_B_Vp");
    Us_B_Vp lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Us_B_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Us_B_Vp)");
    check_field_offset(lv, v1, 0, "Us_B_Vp.v1");
    check_field_offset(lv, v2, 2, "Us_B_Vp.v2");
    check_field_offset(lv, v3, 3, "Us_B_Vp.v3");
  }
}
static Arrange_To_Call_Me vUs_B_Vp(Test_Us_B_Vp, "Us_B_Vp", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu15i_B()
{
  {
    init_simple_test("Us_BFu15i_B");
    static Us_BFu15i_B lv;
    check2(sizeof(lv), 5, "sizeof(Us_BFu15i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu15i_B)");
    check_field_offset(lv, v1, 0, "Us_BFu15i_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15i_B");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15i_B");
    check_field_offset(lv, v3, 4, "Us_BFu15i_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu15i_B(Test_Us_BFu15i_B, "Us_BFu15i_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu15ll_B()
{
  {
    init_simple_test("Us_BFu15ll_B");
    static Us_BFu15ll_B lv;
    check2(sizeof(lv), 5, "sizeof(Us_BFu15ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu15ll_B)");
    check_field_offset(lv, v1, 0, "Us_BFu15ll_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15ll_B");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15ll_B");
    check_field_offset(lv, v3, 4, "Us_BFu15ll_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu15ll_B(Test_Us_BFu15ll_B, "Us_BFu15ll_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu15s_B()
{
  {
    init_simple_test("Us_BFu15s_B");
    static Us_BFu15s_B lv;
    check2(sizeof(lv), 5, "sizeof(Us_BFu15s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu15s_B)");
    check_field_offset(lv, v1, 0, "Us_BFu15s_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15s_B");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15s_B");
    check_field_offset(lv, v3, 4, "Us_BFu15s_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu15s_B(Test_Us_BFu15s_B, "Us_BFu15s_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu16i_B()
{
  {
    init_simple_test("Us_BFu16i_B");
    static Us_BFu16i_B lv;
    check2(sizeof(lv), 5, "sizeof(Us_BFu16i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu16i_B)");
    check_field_offset(lv, v1, 0, "Us_BFu16i_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16i_B");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16i_B");
    check_field_offset(lv, v3, 4, "Us_BFu16i_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu16i_B(Test_Us_BFu16i_B, "Us_BFu16i_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu16ll_B()
{
  {
    init_simple_test("Us_BFu16ll_B");
    static Us_BFu16ll_B lv;
    check2(sizeof(lv), 5, "sizeof(Us_BFu16ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu16ll_B)");
    check_field_offset(lv, v1, 0, "Us_BFu16ll_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16ll_B");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16ll_B");
    check_field_offset(lv, v3, 4, "Us_BFu16ll_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu16ll_B(Test_Us_BFu16ll_B, "Us_BFu16ll_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu16s_B()
{
  {
    init_simple_test("Us_BFu16s_B");
    static Us_BFu16s_B lv;
    check2(sizeof(lv), 5, "sizeof(Us_BFu16s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu16s_B)");
    check_field_offset(lv, v1, 0, "Us_BFu16s_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16s_B");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16s_B");
    check_field_offset(lv, v3, 4, "Us_BFu16s_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu16s_B(Test_Us_BFu16s_B, "Us_BFu16s_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu17i_B()
{
  {
    init_simple_test("Us_BFu17i_B");
    static Us_BFu17i_B lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu17i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu17i_B)");
    check_field_offset(lv, v1, 0, "Us_BFu17i_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu17i_B");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu17i_B");
    check_field_offset(lv, v3, 5, "Us_BFu17i_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu17i_B(Test_Us_BFu17i_B, "Us_BFu17i_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu17ll_B()
{
  {
    init_simple_test("Us_BFu17ll_B");
    static Us_BFu17ll_B lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu17ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu17ll_B)");
    check_field_offset(lv, v1, 0, "Us_BFu17ll_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu17ll_B");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu17ll_B");
    check_field_offset(lv, v3, 5, "Us_BFu17ll_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu17ll_B(Test_Us_BFu17ll_B, "Us_BFu17ll_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu1c_B()
{
  {
    init_simple_test("Us_BFu1c_B");
    static Us_BFu1c_B lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu1c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu1c_B)");
    check_field_offset(lv, v1, 0, "Us_BFu1c_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1c_B");
    check_field_offset(lv, v3, 3, "Us_BFu1c_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu1c_B(Test_Us_BFu1c_B, "Us_BFu1c_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu1i_B()
{
  {
    init_simple_test("Us_BFu1i_B");
    static Us_BFu1i_B lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu1i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu1i_B)");
    check_field_offset(lv, v1, 0, "Us_BFu1i_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1i_B");
    check_field_offset(lv, v3, 3, "Us_BFu1i_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu1i_B(Test_Us_BFu1i_B, "Us_BFu1i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu1ll_B()
{
  {
    init_simple_test("Us_BFu1ll_B");
    static Us_BFu1ll_B lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu1ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu1ll_B)");
    check_field_offset(lv, v1, 0, "Us_BFu1ll_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1ll_B");
    check_field_offset(lv, v3, 3, "Us_BFu1ll_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu1ll_B(Test_Us_BFu1ll_B, "Us_BFu1ll_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu1s_B()
{
  {
    init_simple_test("Us_BFu1s_B");
    static Us_BFu1s_B lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu1s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu1s_B)");
    check_field_offset(lv, v1, 0, "Us_BFu1s_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1s_B");
    check_field_offset(lv, v3, 3, "Us_BFu1s_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu1s_B(Test_Us_BFu1s_B, "Us_BFu1s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu31i_B()
{
  {
    init_simple_test("Us_BFu31i_B");
    static Us_BFu31i_B lv;
    check2(sizeof(lv), 7, "sizeof(Us_BFu31i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu31i_B)");
    check_field_offset(lv, v1, 0, "Us_BFu31i_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu31i_B");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu31i_B");
    check_field_offset(lv, v3, 6, "Us_BFu31i_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu31i_B(Test_Us_BFu31i_B, "Us_BFu31i_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu31ll_B()
{
  {
    init_simple_test("Us_BFu31ll_B");
    static Us_BFu31ll_B lv;
    check2(sizeof(lv), 7, "sizeof(Us_BFu31ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu31ll_B)");
    check_field_offset(lv, v1, 0, "Us_BFu31ll_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu31ll_B");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu31ll_B");
    check_field_offset(lv, v3, 6, "Us_BFu31ll_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu31ll_B(Test_Us_BFu31ll_B, "Us_BFu31ll_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu32i_B()
{
  {
    init_simple_test("Us_BFu32i_B");
    static Us_BFu32i_B lv;
    check2(sizeof(lv), 7, "sizeof(Us_BFu32i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu32i_B)");
    check_field_offset(lv, v1, 0, "Us_BFu32i_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu32i_B");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu32i_B");
    check_field_offset(lv, v3, 6, "Us_BFu32i_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu32i_B(Test_Us_BFu32i_B, "Us_BFu32i_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu32ll_B()
{
  {
    init_simple_test("Us_BFu32ll_B");
    static Us_BFu32ll_B lv;
    check2(sizeof(lv), 7, "sizeof(Us_BFu32ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu32ll_B)");
    check_field_offset(lv, v1, 0, "Us_BFu32ll_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu32ll_B");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu32ll_B");
    check_field_offset(lv, v3, 6, "Us_BFu32ll_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu32ll_B(Test_Us_BFu32ll_B, "Us_BFu32ll_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu33_B()
{
  {
    init_simple_test("Us_BFu33_B");
    static Us_BFu33_B lv;
    check2(sizeof(lv), 8, "sizeof(Us_BFu33_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu33_B)");
    check_field_offset(lv, v1, 0, "Us_BFu33_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 33, 1, "Us_BFu33_B");
    set_bf_and_test(lv, v2, 2, 0, 33, hide_ull(1LL<<32), "Us_BFu33_B");
    check_field_offset(lv, v3, 7, "Us_BFu33_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu33_B(Test_Us_BFu33_B, "Us_BFu33_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu7c_B()
{
  {
    init_simple_test("Us_BFu7c_B");
    static Us_BFu7c_B lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu7c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu7c_B)");
    check_field_offset(lv, v1, 0, "Us_BFu7c_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7c_B");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7c_B");
    check_field_offset(lv, v3, 3, "Us_BFu7c_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu7c_B(Test_Us_BFu7c_B, "Us_BFu7c_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu7i_B()
{
  {
    init_simple_test("Us_BFu7i_B");
    static Us_BFu7i_B lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu7i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu7i_B)");
    check_field_offset(lv, v1, 0, "Us_BFu7i_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7i_B");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7i_B");
    check_field_offset(lv, v3, 3, "Us_BFu7i_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu7i_B(Test_Us_BFu7i_B, "Us_BFu7i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu7ll_B()
{
  {
    init_simple_test("Us_BFu7ll_B");
    static Us_BFu7ll_B lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu7ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu7ll_B)");
    check_field_offset(lv, v1, 0, "Us_BFu7ll_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7ll_B");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7ll_B");
    check_field_offset(lv, v3, 3, "Us_BFu7ll_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu7ll_B(Test_Us_BFu7ll_B, "Us_BFu7ll_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu7s_B()
{
  {
    init_simple_test("Us_BFu7s_B");
    static Us_BFu7s_B lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu7s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu7s_B)");
    check_field_offset(lv, v1, 0, "Us_BFu7s_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7s_B");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7s_B");
    check_field_offset(lv, v3, 3, "Us_BFu7s_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu7s_B(Test_Us_BFu7s_B, "Us_BFu7s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu8c_B()
{
  {
    init_simple_test("Us_BFu8c_B");
    static Us_BFu8c_B lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu8c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu8c_B)");
    check_field_offset(lv, v1, 0, "Us_BFu8c_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8c_B");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8c_B");
    check_field_offset(lv, v3, 3, "Us_BFu8c_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu8c_B(Test_Us_BFu8c_B, "Us_BFu8c_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu8i_B()
{
  {
    init_simple_test("Us_BFu8i_B");
    static Us_BFu8i_B lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu8i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu8i_B)");
    check_field_offset(lv, v1, 0, "Us_BFu8i_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8i_B");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8i_B");
    check_field_offset(lv, v3, 3, "Us_BFu8i_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu8i_B(Test_Us_BFu8i_B, "Us_BFu8i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu8ll_B()
{
  {
    init_simple_test("Us_BFu8ll_B");
    static Us_BFu8ll_B lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu8ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu8ll_B)");
    check_field_offset(lv, v1, 0, "Us_BFu8ll_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8ll_B");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8ll_B");
    check_field_offset(lv, v3, 3, "Us_BFu8ll_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu8ll_B(Test_Us_BFu8ll_B, "Us_BFu8ll_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu8s_B()
{
  {
    init_simple_test("Us_BFu8s_B");
    static Us_BFu8s_B lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu8s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu8s_B)");
    check_field_offset(lv, v1, 0, "Us_BFu8s_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8s_B");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8s_B");
    check_field_offset(lv, v3, 3, "Us_BFu8s_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu8s_B(Test_Us_BFu8s_B, "Us_BFu8s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu9i_B()
{
  {
    init_simple_test("Us_BFu9i_B");
    static Us_BFu9i_B lv;
    check2(sizeof(lv), 5, "sizeof(Us_BFu9i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu9i_B)");
    check_field_offset(lv, v1, 0, "Us_BFu9i_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9i_B");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9i_B");
    check_field_offset(lv, v3, 4, "Us_BFu9i_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu9i_B(Test_Us_BFu9i_B, "Us_BFu9i_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu9ll_B()
{
  {
    init_simple_test("Us_BFu9ll_B");
    static Us_BFu9ll_B lv;
    check2(sizeof(lv), 5, "sizeof(Us_BFu9ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu9ll_B)");
    check_field_offset(lv, v1, 0, "Us_BFu9ll_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9ll_B");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9ll_B");
    check_field_offset(lv, v3, 4, "Us_BFu9ll_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu9ll_B(Test_Us_BFu9ll_B, "Us_BFu9ll_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu9s_B()
{
  {
    init_simple_test("Us_BFu9s_B");
    static Us_BFu9s_B lv;
    check2(sizeof(lv), 5, "sizeof(Us_BFu9s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu9s_B)");
    check_field_offset(lv, v1, 0, "Us_BFu9s_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9s_B");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9s_B");
    check_field_offset(lv, v3, 4, "Us_BFu9s_B.v3");
  }
}
static Arrange_To_Call_Me vUs_BFu9s_B(Test_Us_BFu9s_B, "Us_BFu9s_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_C_B()
{
  {
    init_simple_test("Us_C_B");
    Us_C_B lv;
    check2(sizeof(lv), 4, "sizeof(Us_C_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_C_B)");
    check_field_offset(lv, v1, 0, "Us_C_B.v1");
    check_field_offset(lv, v2, 2, "Us_C_B.v2");
    check_field_offset(lv, v3, 3, "Us_C_B.v3");
  }
}
static Arrange_To_Call_Me vUs_C_B(Test_Us_C_B, "Us_C_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_D_B()
{
  {
    init_simple_test("Us_D_B");
    Us_D_B lv;
    check2(sizeof(lv), 11, "sizeof(Us_D_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_D_B)");
    check_field_offset(lv, v1, 0, "Us_D_B.v1");
    check_field_offset(lv, v2, 2, "Us_D_B.v2");
    check_field_offset(lv, v3, 10, "Us_D_B.v3");
  }
}
static Arrange_To_Call_Me vUs_D_B(Test_Us_D_B, "Us_D_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_F_B()
{
  {
    init_simple_test("Us_F_B");
    Us_F_B lv;
    check2(sizeof(lv), 7, "sizeof(Us_F_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_F_B)");
    check_field_offset(lv, v1, 0, "Us_F_B.v1");
    check_field_offset(lv, v2, 2, "Us_F_B.v2");
    check_field_offset(lv, v3, 6, "Us_F_B.v3");
  }
}
static Arrange_To_Call_Me vUs_F_B(Test_Us_F_B, "Us_F_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_I_B()
{
  {
    init_simple_test("Us_I_B");
    Us_I_B lv;
    check2(sizeof(lv), 7, "sizeof(Us_I_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_I_B)");
    check_field_offset(lv, v1, 0, "Us_I_B.v1");
    check_field_offset(lv, v2, 2, "Us_I_B.v2");
    check_field_offset(lv, v3, 6, "Us_I_B.v3");
  }
}
static Arrange_To_Call_Me vUs_I_B(Test_Us_I_B, "Us_I_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Ip_B()
{
  {
    init_simple_test("Us_Ip_B");
    Us_Ip_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Us_Ip_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Ip_B)");
    check_field_offset(lv, v1, 0, "Us_Ip_B.v1");
    check_field_offset(lv, v2, 2, "Us_Ip_B.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Us_Ip_B.v3");
  }
}
static Arrange_To_Call_Me vUs_Ip_B(Test_Us_Ip_B, "Us_Ip_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_L_B()
{
  {
    init_simple_test("Us_L_B");
    Us_L_B lv;
    check2(sizeof(lv), 11, "sizeof(Us_L_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_L_B)");
    check_field_offset(lv, v1, 0, "Us_L_B.v1");
    check_field_offset(lv, v2, 2, "Us_L_B.v2");
    check_field_offset(lv, v3, 10, "Us_L_B.v3");
  }
}
static Arrange_To_Call_Me vUs_L_B(Test_Us_L_B, "Us_L_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_S_B()
{
  {
    init_simple_test("Us_S_B");
    Us_S_B lv;
    check2(sizeof(lv), 5, "sizeof(Us_S_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_S_B)");
    check_field_offset(lv, v1, 0, "Us_S_B.v1");
    check_field_offset(lv, v2, 2, "Us_S_B.v2");
    check_field_offset(lv, v3, 4, "Us_S_B.v3");
  }
}
static Arrange_To_Call_Me vUs_S_B(Test_Us_S_B, "Us_S_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Uc_B()
{
  {
    init_simple_test("Us_Uc_B");
    Us_Uc_B lv;
    check2(sizeof(lv), 4, "sizeof(Us_Uc_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Uc_B)");
    check_field_offset(lv, v1, 0, "Us_Uc_B.v1");
    check_field_offset(lv, v2, 2, "Us_Uc_B.v2");
    check_field_offset(lv, v3, 3, "Us_Uc_B.v3");
  }
}
static Arrange_To_Call_Me vUs_Uc_B(Test_Us_Uc_B, "Us_Uc_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Ui_B()
{
  {
    init_simple_test("Us_Ui_B");
    Us_Ui_B lv;
    check2(sizeof(lv), 7, "sizeof(Us_Ui_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Ui_B)");
    check_field_offset(lv, v1, 0, "Us_Ui_B.v1");
    check_field_offset(lv, v2, 2, "Us_Ui_B.v2");
    check_field_offset(lv, v3, 6, "Us_Ui_B.v3");
  }
}
static Arrange_To_Call_Me vUs_Ui_B(Test_Us_Ui_B, "Us_Ui_B", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Ul_B()
{
  {
    init_simple_test("Us_Ul_B");
    Us_Ul_B lv;
    check2(sizeof(lv), 11, "sizeof(Us_Ul_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Ul_B)");
    check_field_offset(lv, v1, 0, "Us_Ul_B.v1");
    check_field_offset(lv, v2, 2, "Us_Ul_B.v2");
    check_field_offset(lv, v3, 10, "Us_Ul_B.v3");
  }
}
static Arrange_To_Call_Me vUs_Ul_B(Test_Us_Ul_B, "Us_Ul_B", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Us_B()
{
  {
    init_simple_test("Us_Us_B");
    Us_Us_B lv;
    check2(sizeof(lv), 5, "sizeof(Us_Us_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Us_B)");
    check_field_offset(lv, v1, 0, "Us_Us_B.v1");
    check_field_offset(lv, v2, 2, "Us_Us_B.v2");
    check_field_offset(lv, v3, 4, "Us_Us_B.v3");
  }
}
static Arrange_To_Call_Me vUs_Us_B(Test_Us_Us_B, "Us_Us_B", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Vp_B()
{
  {
    init_simple_test("Us_Vp_B");
    Us_Vp_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Us_Vp_B)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Vp_B)");
    check_field_offset(lv, v1, 0, "Us_Vp_B.v1");
    check_field_offset(lv, v2, 2, "Us_Vp_B.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Us_Vp_B.v3");
  }
}
static Arrange_To_Call_Me vUs_Vp_B(Test_Us_Vp_B, "Us_Vp_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B()
{
  {
    init_simple_test("Vp_B");
    Vp_B lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B)");
    check_field_offset(lv, v1, 0, "Vp_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B.v2");
  }
}
static Arrange_To_Call_Me vVp_B(Test_Vp_B, "Vp_B", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_B()
{
  {
    init_simple_test("Vp_B_B");
    Vp_B_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_B_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_B)");
    check_field_offset(lv, v1, 0, "Vp_B_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_B.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_B_B.v3");
  }
}
static Arrange_To_Call_Me vVp_B_B(Test_Vp_B_B, "Vp_B_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu15i()
{
  {
    init_simple_test("Vp_B_BFu15i");
    static Vp_B_BFu15i lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_B_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu15i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu15i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, 1, "Vp_B_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, hide_ull(1LL<<14), "Vp_B_BFu15i");
  }
}
static Arrange_To_Call_Me vVp_B_BFu15i(Test_Vp_B_BFu15i, "Vp_B_BFu15i", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu15ll()
{
  {
    init_simple_test("Vp_B_BFu15ll");
    static Vp_B_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_B_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu15ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu15ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, 1, "Vp_B_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, hide_ull(1LL<<14), "Vp_B_BFu15ll");
  }
}
static Arrange_To_Call_Me vVp_B_BFu15ll(Test_Vp_B_BFu15ll, "Vp_B_BFu15ll", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu15s()
{
  {
    init_simple_test("Vp_B_BFu15s");
    static Vp_B_BFu15s lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_B_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu15s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu15s.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, 1, "Vp_B_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, hide_ull(1LL<<14), "Vp_B_BFu15s");
  }
}
static Arrange_To_Call_Me vVp_B_BFu15s(Test_Vp_B_BFu15s, "Vp_B_BFu15s", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu16i()
{
  {
    init_simple_test("Vp_B_BFu16i");
    static Vp_B_BFu16i lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_B_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu16i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu16i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, 1, "Vp_B_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, hide_ull(1LL<<15), "Vp_B_BFu16i");
  }
}
static Arrange_To_Call_Me vVp_B_BFu16i(Test_Vp_B_BFu16i, "Vp_B_BFu16i", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu16ll()
{
  {
    init_simple_test("Vp_B_BFu16ll");
    static Vp_B_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_B_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu16ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu16ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, 1, "Vp_B_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, hide_ull(1LL<<15), "Vp_B_BFu16ll");
  }
}
static Arrange_To_Call_Me vVp_B_BFu16ll(Test_Vp_B_BFu16ll, "Vp_B_BFu16ll", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu16s()
{
  {
    init_simple_test("Vp_B_BFu16s");
    static Vp_B_BFu16s lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_B_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu16s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu16s.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, 1, "Vp_B_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, hide_ull(1LL<<15), "Vp_B_BFu16s");
  }
}
static Arrange_To_Call_Me vVp_B_BFu16s(Test_Vp_B_BFu16s, "Vp_B_BFu16s", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu17i()
{
  {
    init_simple_test("Vp_B_BFu17i");
    static Vp_B_BFu17i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_B_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu17i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu17i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, 1, "Vp_B_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, hide_ull(1LL<<16), "Vp_B_BFu17i");
  }
}
static Arrange_To_Call_Me vVp_B_BFu17i(Test_Vp_B_BFu17i, "Vp_B_BFu17i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu17ll()
{
  {
    init_simple_test("Vp_B_BFu17ll");
    static Vp_B_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_B_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu17ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu17ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, 1, "Vp_B_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, hide_ull(1LL<<16), "Vp_B_BFu17ll");
  }
}
static Arrange_To_Call_Me vVp_B_BFu17ll(Test_Vp_B_BFu17ll, "Vp_B_BFu17ll", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu1c()
{
  {
    init_simple_test("Vp_B_BFu1c");
    static Vp_B_BFu1c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_B_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu1c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu1c.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_B_BFu1c");
  }
}
static Arrange_To_Call_Me vVp_B_BFu1c(Test_Vp_B_BFu1c, "Vp_B_BFu1c", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu1i()
{
  {
    init_simple_test("Vp_B_BFu1i");
    static Vp_B_BFu1i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_B_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu1i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu1i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_B_BFu1i");
  }
}
static Arrange_To_Call_Me vVp_B_BFu1i(Test_Vp_B_BFu1i, "Vp_B_BFu1i", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu1ll()
{
  {
    init_simple_test("Vp_B_BFu1ll");
    static Vp_B_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_B_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu1ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu1ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_B_BFu1ll");
  }
}
static Arrange_To_Call_Me vVp_B_BFu1ll(Test_Vp_B_BFu1ll, "Vp_B_BFu1ll", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu1s()
{
  {
    init_simple_test("Vp_B_BFu1s");
    static Vp_B_BFu1s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_B_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu1s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu1s.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_B_BFu1s");
  }
}
static Arrange_To_Call_Me vVp_B_BFu1s(Test_Vp_B_BFu1s, "Vp_B_BFu1s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu31i()
{
  {
    init_simple_test("Vp_B_BFu31i");
    static Vp_B_BFu31i lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_B_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu31i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu31i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 31, 1, "Vp_B_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 31, hide_ull(1LL<<30), "Vp_B_BFu31i");
  }
}
static Arrange_To_Call_Me vVp_B_BFu31i(Test_Vp_B_BFu31i, "Vp_B_BFu31i", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu31ll()
{
  {
    init_simple_test("Vp_B_BFu31ll");
    static Vp_B_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_B_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu31ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu31ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 31, 1, "Vp_B_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 31, hide_ull(1LL<<30), "Vp_B_BFu31ll");
  }
}
static Arrange_To_Call_Me vVp_B_BFu31ll(Test_Vp_B_BFu31ll, "Vp_B_BFu31ll", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu32i()
{
  {
    init_simple_test("Vp_B_BFu32i");
    static Vp_B_BFu32i lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_B_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu32i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu32i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 32, 1, "Vp_B_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 32, hide_ull(1LL<<31), "Vp_B_BFu32i");
  }
}
static Arrange_To_Call_Me vVp_B_BFu32i(Test_Vp_B_BFu32i, "Vp_B_BFu32i", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu32ll()
{
  {
    init_simple_test("Vp_B_BFu32ll");
    static Vp_B_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_B_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu32ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu32ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 32, 1, "Vp_B_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 32, hide_ull(1LL<<31), "Vp_B_BFu32ll");
  }
}
static Arrange_To_Call_Me vVp_B_BFu32ll(Test_Vp_B_BFu32ll, "Vp_B_BFu32ll", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu33()
{
  {
    init_simple_test("Vp_B_BFu33");
    static Vp_B_BFu33 lv;
    check2(sizeof(lv), ABISELECT(14,10), "sizeof(Vp_B_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu33.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu33.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 33, 1, "Vp_B_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 33, hide_ull(1LL<<32), "Vp_B_BFu33");
  }
}
static Arrange_To_Call_Me vVp_B_BFu33(Test_Vp_B_BFu33, "Vp_B_BFu33", ABISELECT(14,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu7c()
{
  {
    init_simple_test("Vp_B_BFu7c");
    static Vp_B_BFu7c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_B_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu7c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu7c.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_B_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_B_BFu7c");
  }
}
static Arrange_To_Call_Me vVp_B_BFu7c(Test_Vp_B_BFu7c, "Vp_B_BFu7c", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu7i()
{
  {
    init_simple_test("Vp_B_BFu7i");
    static Vp_B_BFu7i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_B_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu7i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu7i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_B_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_B_BFu7i");
  }
}
static Arrange_To_Call_Me vVp_B_BFu7i(Test_Vp_B_BFu7i, "Vp_B_BFu7i", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu7ll()
{
  {
    init_simple_test("Vp_B_BFu7ll");
    static Vp_B_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_B_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu7ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu7ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_B_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_B_BFu7ll");
  }
}
static Arrange_To_Call_Me vVp_B_BFu7ll(Test_Vp_B_BFu7ll, "Vp_B_BFu7ll", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu7s()
{
  {
    init_simple_test("Vp_B_BFu7s");
    static Vp_B_BFu7s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_B_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu7s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu7s.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_B_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_B_BFu7s");
  }
}
static Arrange_To_Call_Me vVp_B_BFu7s(Test_Vp_B_BFu7s, "Vp_B_BFu7s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu8c()
{
  {
    init_simple_test("Vp_B_BFu8c");
    static Vp_B_BFu8c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_B_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu8c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu8c.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_B_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_B_BFu8c");
  }
}
static Arrange_To_Call_Me vVp_B_BFu8c(Test_Vp_B_BFu8c, "Vp_B_BFu8c", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu8i()
{
  {
    init_simple_test("Vp_B_BFu8i");
    static Vp_B_BFu8i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_B_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu8i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu8i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_B_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_B_BFu8i");
  }
}
static Arrange_To_Call_Me vVp_B_BFu8i(Test_Vp_B_BFu8i, "Vp_B_BFu8i", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu8ll()
{
  {
    init_simple_test("Vp_B_BFu8ll");
    static Vp_B_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_B_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu8ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu8ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_B_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_B_BFu8ll");
  }
}
static Arrange_To_Call_Me vVp_B_BFu8ll(Test_Vp_B_BFu8ll, "Vp_B_BFu8ll", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu8s()
{
  {
    init_simple_test("Vp_B_BFu8s");
    static Vp_B_BFu8s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_B_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu8s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu8s.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_B_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_B_BFu8s");
  }
}
static Arrange_To_Call_Me vVp_B_BFu8s(Test_Vp_B_BFu8s, "Vp_B_BFu8s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu9i()
{
  {
    init_simple_test("Vp_B_BFu9i");
    static Vp_B_BFu9i lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_B_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu9i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu9i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, 1, "Vp_B_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, hide_ull(1LL<<8), "Vp_B_BFu9i");
  }
}
static Arrange_To_Call_Me vVp_B_BFu9i(Test_Vp_B_BFu9i, "Vp_B_BFu9i", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu9ll()
{
  {
    init_simple_test("Vp_B_BFu9ll");
    static Vp_B_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_B_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu9ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu9ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, 1, "Vp_B_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, hide_ull(1LL<<8), "Vp_B_BFu9ll");
  }
}
static Arrange_To_Call_Me vVp_B_BFu9ll(Test_Vp_B_BFu9ll, "Vp_B_BFu9ll", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_BFu9s()
{
  {
    init_simple_test("Vp_B_BFu9s");
    static Vp_B_BFu9s lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_B_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu9s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu9s.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, 1, "Vp_B_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, hide_ull(1LL<<8), "Vp_B_BFu9s");
  }
}
static Arrange_To_Call_Me vVp_B_BFu9s(Test_Vp_B_BFu9s, "Vp_B_BFu9s", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_C()
{
  {
    init_simple_test("Vp_B_C");
    Vp_B_C lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_B_C)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_C)");
    check_field_offset(lv, v1, 0, "Vp_B_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_C.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_B_C.v3");
  }
}
static Arrange_To_Call_Me vVp_B_C(Test_Vp_B_C, "Vp_B_C", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_D()
{
  {
    init_simple_test("Vp_B_D");
    Vp_B_D lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(Vp_B_D)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_D)");
    check_field_offset(lv, v1, 0, "Vp_B_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_D.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_B_D.v3");
  }
}
static Arrange_To_Call_Me vVp_B_D(Test_Vp_B_D, "Vp_B_D", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_F()
{
  {
    init_simple_test("Vp_B_F");
    Vp_B_F lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_B_F)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_F)");
    check_field_offset(lv, v1, 0, "Vp_B_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_F.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_B_F.v3");
  }
}
static Arrange_To_Call_Me vVp_B_F(Test_Vp_B_F, "Vp_B_F", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_I()
{
  {
    init_simple_test("Vp_B_I");
    Vp_B_I lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_B_I)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_I)");
    check_field_offset(lv, v1, 0, "Vp_B_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_I.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_B_I.v3");
  }
}
static Arrange_To_Call_Me vVp_B_I(Test_Vp_B_I, "Vp_B_I", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_Ip()
{
  {
    init_simple_test("Vp_B_Ip");
    Vp_B_Ip lv;
    check2(sizeof(lv), ABISELECT(17,9), "sizeof(Vp_B_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_Ip)");
    check_field_offset(lv, v1, 0, "Vp_B_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_Ip.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_B_Ip.v3");
  }
}
static Arrange_To_Call_Me vVp_B_Ip(Test_Vp_B_Ip, "Vp_B_Ip", ABISELECT(17,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_L()
{
  {
    init_simple_test("Vp_B_L");
    Vp_B_L lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(Vp_B_L)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_L)");
    check_field_offset(lv, v1, 0, "Vp_B_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_L.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_B_L.v3");
  }
}
static Arrange_To_Call_Me vVp_B_L(Test_Vp_B_L, "Vp_B_L", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_S()
{
  {
    init_simple_test("Vp_B_S");
    Vp_B_S lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_B_S)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_S)");
    check_field_offset(lv, v1, 0, "Vp_B_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_S.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_B_S.v3");
  }
}
static Arrange_To_Call_Me vVp_B_S(Test_Vp_B_S, "Vp_B_S", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_Uc()
{
  {
    init_simple_test("Vp_B_Uc");
    Vp_B_Uc lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_B_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_Uc)");
    check_field_offset(lv, v1, 0, "Vp_B_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_Uc.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_B_Uc.v3");
  }
}
static Arrange_To_Call_Me vVp_B_Uc(Test_Vp_B_Uc, "Vp_B_Uc", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_Ui()
{
  {
    init_simple_test("Vp_B_Ui");
    Vp_B_Ui lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_B_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_Ui)");
    check_field_offset(lv, v1, 0, "Vp_B_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_Ui.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_B_Ui.v3");
  }
}
static Arrange_To_Call_Me vVp_B_Ui(Test_Vp_B_Ui, "Vp_B_Ui", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_Ul()
{
  {
    init_simple_test("Vp_B_Ul");
    Vp_B_Ul lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(Vp_B_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_Ul)");
    check_field_offset(lv, v1, 0, "Vp_B_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_Ul.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_B_Ul.v3");
  }
}
static Arrange_To_Call_Me vVp_B_Ul(Test_Vp_B_Ul, "Vp_B_Ul", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_Us()
{
  {
    init_simple_test("Vp_B_Us");
    Vp_B_Us lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_B_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_Us)");
    check_field_offset(lv, v1, 0, "Vp_B_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_Us.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_B_Us.v3");
  }
}
static Arrange_To_Call_Me vVp_B_Us(Test_Vp_B_Us, "Vp_B_Us", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_B_Vp()
{
  {
    init_simple_test("Vp_B_Vp");
    Vp_B_Vp lv;
    check2(sizeof(lv), ABISELECT(17,9), "sizeof(Vp_B_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_B_Vp)");
    check_field_offset(lv, v1, 0, "Vp_B_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_Vp.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_B_Vp.v3");
  }
}
static Arrange_To_Call_Me vVp_B_Vp(Test_Vp_B_Vp, "Vp_B_Vp", ABISELECT(17,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu15i_B()
{
  {
    init_simple_test("Vp_BFu15i_B");
    static Vp_BFu15i_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu15i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu15i_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu15i_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15i_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15i_B");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu15i_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu15i_B(Test_Vp_BFu15i_B, "Vp_BFu15i_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu15ll_B()
{
  {
    init_simple_test("Vp_BFu15ll_B");
    static Vp_BFu15ll_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu15ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu15ll_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu15ll_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15ll_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15ll_B");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu15ll_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu15ll_B(Test_Vp_BFu15ll_B, "Vp_BFu15ll_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu15s_B()
{
  {
    init_simple_test("Vp_BFu15s_B");
    static Vp_BFu15s_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu15s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu15s_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu15s_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15s_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15s_B");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu15s_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu15s_B(Test_Vp_BFu15s_B, "Vp_BFu15s_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu16i_B()
{
  {
    init_simple_test("Vp_BFu16i_B");
    static Vp_BFu16i_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu16i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu16i_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu16i_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16i_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16i_B");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu16i_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu16i_B(Test_Vp_BFu16i_B, "Vp_BFu16i_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu16ll_B()
{
  {
    init_simple_test("Vp_BFu16ll_B");
    static Vp_BFu16ll_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu16ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu16ll_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu16ll_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16ll_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16ll_B");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu16ll_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu16ll_B(Test_Vp_BFu16ll_B, "Vp_BFu16ll_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu16s_B()
{
  {
    init_simple_test("Vp_BFu16s_B");
    static Vp_BFu16s_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu16s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu16s_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu16s_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16s_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16s_B");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu16s_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu16s_B(Test_Vp_BFu16s_B, "Vp_BFu16s_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu17i_B()
{
  {
    init_simple_test("Vp_BFu17i_B");
    static Vp_BFu17i_B lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu17i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu17i_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu17i_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu17i_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu17i_B");
    check_field_offset(lv, v3, ABISELECT(11,7), "Vp_BFu17i_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu17i_B(Test_Vp_BFu17i_B, "Vp_BFu17i_B", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu17ll_B()
{
  {
    init_simple_test("Vp_BFu17ll_B");
    static Vp_BFu17ll_B lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu17ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu17ll_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu17ll_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu17ll_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu17ll_B");
    check_field_offset(lv, v3, ABISELECT(11,7), "Vp_BFu17ll_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu17ll_B(Test_Vp_BFu17ll_B, "Vp_BFu17ll_B", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu1c_B()
{
  {
    init_simple_test("Vp_BFu1c_B");
    static Vp_BFu1c_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu1c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu1c_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu1c_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1c_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu1c_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu1c_B(Test_Vp_BFu1c_B, "Vp_BFu1c_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu1i_B()
{
  {
    init_simple_test("Vp_BFu1i_B");
    static Vp_BFu1i_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu1i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu1i_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu1i_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1i_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu1i_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu1i_B(Test_Vp_BFu1i_B, "Vp_BFu1i_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu1ll_B()
{
  {
    init_simple_test("Vp_BFu1ll_B");
    static Vp_BFu1ll_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu1ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu1ll_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu1ll_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1ll_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu1ll_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu1ll_B(Test_Vp_BFu1ll_B, "Vp_BFu1ll_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu1s_B()
{
  {
    init_simple_test("Vp_BFu1s_B");
    static Vp_BFu1s_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu1s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu1s_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu1s_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1s_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu1s_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu1s_B(Test_Vp_BFu1s_B, "Vp_BFu1s_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu31i_B()
{
  {
    init_simple_test("Vp_BFu31i_B");
    static Vp_BFu31i_B lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_BFu31i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu31i_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu31i_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu31i_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu31i_B");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu31i_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu31i_B(Test_Vp_BFu31i_B, "Vp_BFu31i_B", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu31ll_B()
{
  {
    init_simple_test("Vp_BFu31ll_B");
    static Vp_BFu31ll_B lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_BFu31ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu31ll_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu31ll_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu31ll_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu31ll_B");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu31ll_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu31ll_B(Test_Vp_BFu31ll_B, "Vp_BFu31ll_B", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu32i_B()
{
  {
    init_simple_test("Vp_BFu32i_B");
    static Vp_BFu32i_B lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_BFu32i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu32i_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu32i_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32i_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32i_B");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu32i_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu32i_B(Test_Vp_BFu32i_B, "Vp_BFu32i_B", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu32ll_B()
{
  {
    init_simple_test("Vp_BFu32ll_B");
    static Vp_BFu32ll_B lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_BFu32ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu32ll_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_B");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu32ll_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu32ll_B(Test_Vp_BFu32ll_B, "Vp_BFu32ll_B", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu33_B()
{
  {
    init_simple_test("Vp_BFu33_B");
    static Vp_BFu33_B lv;
    check2(sizeof(lv), ABISELECT(14,10), "sizeof(Vp_BFu33_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu33_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_B");
    check_field_offset(lv, v3, ABISELECT(13,9), "Vp_BFu33_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu33_B(Test_Vp_BFu33_B, "Vp_BFu33_B", ABISELECT(14,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu7c_B()
{
  {
    init_simple_test("Vp_BFu7c_B");
    static Vp_BFu7c_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu7c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu7c_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu7c_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu7c_B(Test_Vp_BFu7c_B, "Vp_BFu7c_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu7i_B()
{
  {
    init_simple_test("Vp_BFu7i_B");
    static Vp_BFu7i_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu7i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu7i_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu7i_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu7i_B(Test_Vp_BFu7i_B, "Vp_BFu7i_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu7ll_B()
{
  {
    init_simple_test("Vp_BFu7ll_B");
    static Vp_BFu7ll_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu7ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu7ll_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu7ll_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu7ll_B(Test_Vp_BFu7ll_B, "Vp_BFu7ll_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu7s_B()
{
  {
    init_simple_test("Vp_BFu7s_B");
    static Vp_BFu7s_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu7s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu7s_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu7s_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu7s_B(Test_Vp_BFu7s_B, "Vp_BFu7s_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu8c_B()
{
  {
    init_simple_test("Vp_BFu8c_B");
    static Vp_BFu8c_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu8c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu8c_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu8c_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu8c_B(Test_Vp_BFu8c_B, "Vp_BFu8c_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu8i_B()
{
  {
    init_simple_test("Vp_BFu8i_B");
    static Vp_BFu8i_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu8i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu8i_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu8i_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu8i_B(Test_Vp_BFu8i_B, "Vp_BFu8i_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu8ll_B()
{
  {
    init_simple_test("Vp_BFu8ll_B");
    static Vp_BFu8ll_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu8ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu8ll_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu8ll_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu8ll_B(Test_Vp_BFu8ll_B, "Vp_BFu8ll_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu8s_B()
{
  {
    init_simple_test("Vp_BFu8s_B");
    static Vp_BFu8s_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu8s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu8s_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_B");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu8s_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu8s_B(Test_Vp_BFu8s_B, "Vp_BFu8s_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu9i_B()
{
  {
    init_simple_test("Vp_BFu9i_B");
    static Vp_BFu9i_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu9i_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu9i_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_B");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu9i_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu9i_B(Test_Vp_BFu9i_B, "Vp_BFu9i_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu9ll_B()
{
  {
    init_simple_test("Vp_BFu9ll_B");
    static Vp_BFu9ll_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu9ll_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu9ll_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_B");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu9ll_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu9ll_B(Test_Vp_BFu9ll_B, "Vp_BFu9ll_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu9s_B()
{
  {
    init_simple_test("Vp_BFu9s_B");
    static Vp_BFu9s_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu9s_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu9s_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_B.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_B");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_B");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu9s_B.v3");
  }
}
static Arrange_To_Call_Me vVp_BFu9s_B(Test_Vp_BFu9s_B, "Vp_BFu9s_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_C_B()
{
  {
    init_simple_test("Vp_C_B");
    Vp_C_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_C_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_C_B)");
    check_field_offset(lv, v1, 0, "Vp_C_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_B.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_C_B.v3");
  }
}
static Arrange_To_Call_Me vVp_C_B(Test_Vp_C_B, "Vp_C_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_D_B()
{
  {
    init_simple_test("Vp_D_B");
    Vp_D_B lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(Vp_D_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_D_B)");
    check_field_offset(lv, v1, 0, "Vp_D_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_B.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_D_B.v3");
  }
}
static Arrange_To_Call_Me vVp_D_B(Test_Vp_D_B, "Vp_D_B", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_F_B()
{
  {
    init_simple_test("Vp_F_B");
    Vp_F_B lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_F_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_F_B)");
    check_field_offset(lv, v1, 0, "Vp_F_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_B.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_F_B.v3");
  }
}
static Arrange_To_Call_Me vVp_F_B(Test_Vp_F_B, "Vp_F_B", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_I_B()
{
  {
    init_simple_test("Vp_I_B");
    Vp_I_B lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_I_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_I_B)");
    check_field_offset(lv, v1, 0, "Vp_I_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_B.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_I_B.v3");
  }
}
static Arrange_To_Call_Me vVp_I_B(Test_Vp_I_B, "Vp_I_B", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Ip_B()
{
  {
    init_simple_test("Vp_Ip_B");
    Vp_Ip_B lv;
    check2(sizeof(lv), ABISELECT(17,9), "sizeof(Vp_Ip_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Ip_B)");
    check_field_offset(lv, v1, 0, "Vp_Ip_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_B.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Ip_B.v3");
  }
}
static Arrange_To_Call_Me vVp_Ip_B(Test_Vp_Ip_B, "Vp_Ip_B", ABISELECT(17,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_L_B()
{
  {
    init_simple_test("Vp_L_B");
    Vp_L_B lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(Vp_L_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_L_B)");
    check_field_offset(lv, v1, 0, "Vp_L_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_B.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_L_B.v3");
  }
}
static Arrange_To_Call_Me vVp_L_B(Test_Vp_L_B, "Vp_L_B", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_S_B()
{
  {
    init_simple_test("Vp_S_B");
    Vp_S_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_S_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_S_B)");
    check_field_offset(lv, v1, 0, "Vp_S_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_B.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_S_B.v3");
  }
}
static Arrange_To_Call_Me vVp_S_B(Test_Vp_S_B, "Vp_S_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Uc_B()
{
  {
    init_simple_test("Vp_Uc_B");
    Vp_Uc_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_Uc_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Uc_B)");
    check_field_offset(lv, v1, 0, "Vp_Uc_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_B.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_Uc_B.v3");
  }
}
static Arrange_To_Call_Me vVp_Uc_B(Test_Vp_Uc_B, "Vp_Uc_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Ui_B()
{
  {
    init_simple_test("Vp_Ui_B");
    Vp_Ui_B lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_Ui_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Ui_B)");
    check_field_offset(lv, v1, 0, "Vp_Ui_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_B.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_Ui_B.v3");
  }
}
static Arrange_To_Call_Me vVp_Ui_B(Test_Vp_Ui_B, "Vp_Ui_B", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Ul_B()
{
  {
    init_simple_test("Vp_Ul_B");
    Vp_Ul_B lv;
    check2(sizeof(lv), ABISELECT(17,13), "sizeof(Vp_Ul_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Ul_B)");
    check_field_offset(lv, v1, 0, "Vp_Ul_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_B.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_Ul_B.v3");
  }
}
static Arrange_To_Call_Me vVp_Ul_B(Test_Vp_Ul_B, "Vp_Ul_B", ABISELECT(17,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Us_B()
{
  {
    init_simple_test("Vp_Us_B");
    Vp_Us_B lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_Us_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Us_B)");
    check_field_offset(lv, v1, 0, "Vp_Us_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_B.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_Us_B.v3");
  }
}
static Arrange_To_Call_Me vVp_Us_B(Test_Vp_Us_B, "Vp_Us_B", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Vp_B()
{
  {
    init_simple_test("Vp_Vp_B");
    Vp_Vp_B lv;
    check2(sizeof(lv), ABISELECT(17,9), "sizeof(Vp_Vp_B)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Vp_B)");
    check_field_offset(lv, v1, 0, "Vp_Vp_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_B.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Vp_B.v3");
  }
}
static Arrange_To_Call_Me vVp_Vp_B(Test_Vp_Vp_B, "Vp_Vp_B", ABISELECT(17,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

