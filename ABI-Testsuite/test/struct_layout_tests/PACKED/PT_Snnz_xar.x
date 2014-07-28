// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
// RUN: c_compiler -c -o %t1.o -I "common" "common/testsuite.c"
// RUN: cxx_compiler cxx_rtti -c %s -I "common" -o %t2.o
// RUN: linker -o %t2%exeext  %t1.o %t2.o
// RUN: runtool %t2%exeext | checker "TEST PASSED"
#include "testsuite.h"
#ifdef __cplusplus
#pragma pack(1)
struct Ui_BFu0ll_L { unsigned int v1; unsigned long long :0; long long v2; };
struct Ui_BFu0ll_S { unsigned int v1; unsigned long long :0; short v2; };
struct Ui_BFu0ll_Uc { unsigned int v1; unsigned long long :0; unsigned char v2; };
struct Ui_BFu0ll_Ui { unsigned int v1; unsigned long long :0; unsigned int v2; };
struct Ui_BFu0ll_Ul { unsigned int v1; unsigned long long :0; unsigned long long v2; };
struct Ui_BFu0ll_Us { unsigned int v1; unsigned long long :0; unsigned short v2; };
struct Ui_BFu0ll_Vp { unsigned int v1; unsigned long long :0; void * v2; };
struct Ui_BFu0s { unsigned int v1; unsigned short :0; };
struct Ui_BFu0s_BFu0c { unsigned int v1; unsigned short :0; unsigned char :0; };
struct Ui_BFu0s_BFu0i { unsigned int v1; unsigned short :0; unsigned int :0; };
struct Ui_BFu0s_BFu0ll { unsigned int v1; unsigned short :0; unsigned long long :0; };
struct Ui_BFu0s_BFu0s { unsigned int v1; unsigned short :0; unsigned short :0; };
struct Ui_BFu0s_BFu15i { unsigned int v1; unsigned short :0; unsigned int v2:15; };
struct Ui_BFu0s_BFu15ll { unsigned int v1; unsigned short :0; unsigned long long v2:15; };
struct Ui_BFu0s_BFu15s { unsigned int v1; unsigned short :0; unsigned short v2:15; };
struct Ui_BFu0s_BFu16i { unsigned int v1; unsigned short :0; unsigned int v2:16; };
struct Ui_BFu0s_BFu16ll { unsigned int v1; unsigned short :0; unsigned long long v2:16; };
struct Ui_BFu0s_BFu16s { unsigned int v1; unsigned short :0; unsigned short v2:16; };
struct Ui_BFu0s_BFu17i { unsigned int v1; unsigned short :0; unsigned int v2:17; };
struct Ui_BFu0s_BFu17ll { unsigned int v1; unsigned short :0; unsigned long long v2:17; };
struct Ui_BFu0s_BFu1c { unsigned int v1; unsigned short :0; unsigned char v2:1; };
struct Ui_BFu0s_BFu1i { unsigned int v1; unsigned short :0; unsigned int v2:1; };
struct Ui_BFu0s_BFu1ll { unsigned int v1; unsigned short :0; unsigned long long v2:1; };
struct Ui_BFu0s_BFu1s { unsigned int v1; unsigned short :0; unsigned short v2:1; };
struct Ui_BFu0s_BFu31i { unsigned int v1; unsigned short :0; unsigned int v2:31; };
struct Ui_BFu0s_BFu31ll { unsigned int v1; unsigned short :0; unsigned long long v2:31; };
struct Ui_BFu0s_BFu32i { unsigned int v1; unsigned short :0; unsigned int v2:32; };
struct Ui_BFu0s_BFu32ll { unsigned int v1; unsigned short :0; unsigned long long v2:32; };
struct Ui_BFu0s_BFu33 { unsigned int v1; unsigned short :0; unsigned long long v2:33; };
struct Ui_BFu0s_BFu7c { unsigned int v1; unsigned short :0; unsigned char v2:7; };
struct Ui_BFu0s_BFu7i { unsigned int v1; unsigned short :0; unsigned int v2:7; };
struct Ui_BFu0s_BFu7ll { unsigned int v1; unsigned short :0; unsigned long long v2:7; };
struct Ui_BFu0s_BFu7s { unsigned int v1; unsigned short :0; unsigned short v2:7; };
struct Ui_BFu0s_BFu8c { unsigned int v1; unsigned short :0; unsigned char v2:8; };
struct Ui_BFu0s_BFu8i { unsigned int v1; unsigned short :0; unsigned int v2:8; };
struct Ui_BFu0s_BFu8ll { unsigned int v1; unsigned short :0; unsigned long long v2:8; };
struct Ui_BFu0s_BFu8s { unsigned int v1; unsigned short :0; unsigned short v2:8; };
struct Ui_BFu0s_BFu9i { unsigned int v1; unsigned short :0; unsigned int v2:9; };
struct Ui_BFu0s_BFu9ll { unsigned int v1; unsigned short :0; unsigned long long v2:9; };
struct Ui_BFu0s_BFu9s { unsigned int v1; unsigned short :0; unsigned short v2:9; };
struct Ui_BFu0s_C { unsigned int v1; unsigned short :0; char v2; };
struct Ui_BFu0s_D { unsigned int v1; unsigned short :0; double v2; };
struct Ui_BFu0s_F { unsigned int v1; unsigned short :0; float v2; };
struct Ui_BFu0s_I { unsigned int v1; unsigned short :0; int v2; };
struct Ui_BFu0s_Ip { unsigned int v1; unsigned short :0; int * v2; };
struct Ui_BFu0s_L { unsigned int v1; unsigned short :0; long long v2; };
struct Ui_BFu0s_S { unsigned int v1; unsigned short :0; short v2; };
struct Ui_BFu0s_Uc { unsigned int v1; unsigned short :0; unsigned char v2; };
struct Ui_BFu0s_Ui { unsigned int v1; unsigned short :0; unsigned int v2; };
struct Ui_BFu0s_Ul { unsigned int v1; unsigned short :0; unsigned long long v2; };
struct Ui_BFu0s_Us { unsigned int v1; unsigned short :0; unsigned short v2; };
struct Ui_BFu0s_Vp { unsigned int v1; unsigned short :0; void * v2; };
struct Ui_BFu15i_BFu0c { unsigned int v1; unsigned int v2:15; unsigned char :0; };
struct Ui_BFu15i_BFu0i { unsigned int v1; unsigned int v2:15; unsigned int :0; };
struct Ui_BFu15i_BFu0ll { unsigned int v1; unsigned int v2:15; unsigned long long :0; };
struct Ui_BFu15i_BFu0s { unsigned int v1; unsigned int v2:15; unsigned short :0; };
struct Ui_BFu15ll_BFu0c { unsigned int v1; unsigned long long v2:15; unsigned char :0; };
struct Ui_BFu15ll_BFu0i { unsigned int v1; unsigned long long v2:15; unsigned int :0; };
struct Ui_BFu15ll_BFu0ll { unsigned int v1; unsigned long long v2:15; unsigned long long :0; };
struct Ui_BFu15ll_BFu0s { unsigned int v1; unsigned long long v2:15; unsigned short :0; };
struct Ui_BFu15s_BFu0c { unsigned int v1; unsigned short v2:15; unsigned char :0; };
struct Ui_BFu15s_BFu0i { unsigned int v1; unsigned short v2:15; unsigned int :0; };
struct Ui_BFu15s_BFu0ll { unsigned int v1; unsigned short v2:15; unsigned long long :0; };
struct Ui_BFu15s_BFu0s { unsigned int v1; unsigned short v2:15; unsigned short :0; };
struct Ui_BFu16i_BFu0c { unsigned int v1; unsigned int v2:16; unsigned char :0; };
struct Ui_BFu16i_BFu0i { unsigned int v1; unsigned int v2:16; unsigned int :0; };
struct Ui_BFu16i_BFu0ll { unsigned int v1; unsigned int v2:16; unsigned long long :0; };
struct Ui_BFu16i_BFu0s { unsigned int v1; unsigned int v2:16; unsigned short :0; };
struct Ui_BFu16ll_BFu0c { unsigned int v1; unsigned long long v2:16; unsigned char :0; };
struct Ui_BFu16ll_BFu0i { unsigned int v1; unsigned long long v2:16; unsigned int :0; };
struct Ui_BFu16ll_BFu0ll { unsigned int v1; unsigned long long v2:16; unsigned long long :0; };
struct Ui_BFu16ll_BFu0s { unsigned int v1; unsigned long long v2:16; unsigned short :0; };
struct Ui_BFu16s_BFu0c { unsigned int v1; unsigned short v2:16; unsigned char :0; };
struct Ui_BFu16s_BFu0i { unsigned int v1; unsigned short v2:16; unsigned int :0; };
struct Ui_BFu16s_BFu0ll { unsigned int v1; unsigned short v2:16; unsigned long long :0; };
struct Ui_BFu16s_BFu0s { unsigned int v1; unsigned short v2:16; unsigned short :0; };
struct Ui_BFu17i_BFu0c { unsigned int v1; unsigned int v2:17; unsigned char :0; };
struct Ui_BFu17i_BFu0i { unsigned int v1; unsigned int v2:17; unsigned int :0; };
struct Ui_BFu17i_BFu0ll { unsigned int v1; unsigned int v2:17; unsigned long long :0; };
struct Ui_BFu17i_BFu0s { unsigned int v1; unsigned int v2:17; unsigned short :0; };
struct Ui_BFu17ll_BFu0c { unsigned int v1; unsigned long long v2:17; unsigned char :0; };
struct Ui_BFu17ll_BFu0i { unsigned int v1; unsigned long long v2:17; unsigned int :0; };
struct Ui_BFu17ll_BFu0ll { unsigned int v1; unsigned long long v2:17; unsigned long long :0; };
struct Ui_BFu17ll_BFu0s { unsigned int v1; unsigned long long v2:17; unsigned short :0; };
struct Ui_BFu1c_BFu0c { unsigned int v1; unsigned char v2:1; unsigned char :0; };
struct Ui_BFu1c_BFu0i { unsigned int v1; unsigned char v2:1; unsigned int :0; };
struct Ui_BFu1c_BFu0ll { unsigned int v1; unsigned char v2:1; unsigned long long :0; };
struct Ui_BFu1c_BFu0s { unsigned int v1; unsigned char v2:1; unsigned short :0; };
struct Ui_BFu1i_BFu0c { unsigned int v1; unsigned int v2:1; unsigned char :0; };
struct Ui_BFu1i_BFu0i { unsigned int v1; unsigned int v2:1; unsigned int :0; };
struct Ui_BFu1i_BFu0ll { unsigned int v1; unsigned int v2:1; unsigned long long :0; };
struct Ui_BFu1i_BFu0s { unsigned int v1; unsigned int v2:1; unsigned short :0; };
struct Ui_BFu1ll_BFu0c { unsigned int v1; unsigned long long v2:1; unsigned char :0; };
struct Ui_BFu1ll_BFu0i { unsigned int v1; unsigned long long v2:1; unsigned int :0; };
struct Ui_BFu1ll_BFu0ll { unsigned int v1; unsigned long long v2:1; unsigned long long :0; };
struct Ui_BFu1ll_BFu0s { unsigned int v1; unsigned long long v2:1; unsigned short :0; };
struct Ui_BFu1s_BFu0c { unsigned int v1; unsigned short v2:1; unsigned char :0; };
struct Ui_BFu1s_BFu0i { unsigned int v1; unsigned short v2:1; unsigned int :0; };
struct Ui_BFu1s_BFu0ll { unsigned int v1; unsigned short v2:1; unsigned long long :0; };
struct Ui_BFu1s_BFu0s { unsigned int v1; unsigned short v2:1; unsigned short :0; };
struct Ui_BFu31i_BFu0c { unsigned int v1; unsigned int v2:31; unsigned char :0; };
struct Ui_BFu31i_BFu0i { unsigned int v1; unsigned int v2:31; unsigned int :0; };
struct Ui_BFu31i_BFu0ll { unsigned int v1; unsigned int v2:31; unsigned long long :0; };
struct Ui_BFu31i_BFu0s { unsigned int v1; unsigned int v2:31; unsigned short :0; };
struct Ui_BFu31ll_BFu0c { unsigned int v1; unsigned long long v2:31; unsigned char :0; };
struct Ui_BFu31ll_BFu0i { unsigned int v1; unsigned long long v2:31; unsigned int :0; };
struct Ui_BFu31ll_BFu0ll { unsigned int v1; unsigned long long v2:31; unsigned long long :0; };
struct Ui_BFu31ll_BFu0s { unsigned int v1; unsigned long long v2:31; unsigned short :0; };
struct Ui_BFu32i_BFu0c { unsigned int v1; unsigned int v2:32; unsigned char :0; };
struct Ui_BFu32i_BFu0i { unsigned int v1; unsigned int v2:32; unsigned int :0; };
struct Ui_BFu32i_BFu0ll { unsigned int v1; unsigned int v2:32; unsigned long long :0; };
struct Ui_BFu32i_BFu0s { unsigned int v1; unsigned int v2:32; unsigned short :0; };
struct Ui_BFu32ll_BFu0c { unsigned int v1; unsigned long long v2:32; unsigned char :0; };
struct Ui_BFu32ll_BFu0i { unsigned int v1; unsigned long long v2:32; unsigned int :0; };
struct Ui_BFu32ll_BFu0ll { unsigned int v1; unsigned long long v2:32; unsigned long long :0; };
struct Ui_BFu32ll_BFu0s { unsigned int v1; unsigned long long v2:32; unsigned short :0; };
struct Ui_BFu33_BFu0c { unsigned int v1; unsigned long long v2:33; unsigned char :0; };
struct Ui_BFu33_BFu0i { unsigned int v1; unsigned long long v2:33; unsigned int :0; };
struct Ui_BFu33_BFu0ll { unsigned int v1; unsigned long long v2:33; unsigned long long :0; };
struct Ui_BFu33_BFu0s { unsigned int v1; unsigned long long v2:33; unsigned short :0; };
struct Ui_BFu7c_BFu0c { unsigned int v1; unsigned char v2:7; unsigned char :0; };
struct Ui_BFu7c_BFu0i { unsigned int v1; unsigned char v2:7; unsigned int :0; };
struct Ui_BFu7c_BFu0ll { unsigned int v1; unsigned char v2:7; unsigned long long :0; };
struct Ui_BFu7c_BFu0s { unsigned int v1; unsigned char v2:7; unsigned short :0; };
struct Ui_BFu7i_BFu0c { unsigned int v1; unsigned int v2:7; unsigned char :0; };
struct Ui_BFu7i_BFu0i { unsigned int v1; unsigned int v2:7; unsigned int :0; };
struct Ui_BFu7i_BFu0ll { unsigned int v1; unsigned int v2:7; unsigned long long :0; };
struct Ui_BFu7i_BFu0s { unsigned int v1; unsigned int v2:7; unsigned short :0; };
struct Ui_BFu7ll_BFu0c { unsigned int v1; unsigned long long v2:7; unsigned char :0; };
struct Ui_BFu7ll_BFu0i { unsigned int v1; unsigned long long v2:7; unsigned int :0; };
struct Ui_BFu7ll_BFu0ll { unsigned int v1; unsigned long long v2:7; unsigned long long :0; };
struct Ui_BFu7ll_BFu0s { unsigned int v1; unsigned long long v2:7; unsigned short :0; };
struct Ui_BFu7s_BFu0c { unsigned int v1; unsigned short v2:7; unsigned char :0; };
struct Ui_BFu7s_BFu0i { unsigned int v1; unsigned short v2:7; unsigned int :0; };
struct Ui_BFu7s_BFu0ll { unsigned int v1; unsigned short v2:7; unsigned long long :0; };
struct Ui_BFu7s_BFu0s { unsigned int v1; unsigned short v2:7; unsigned short :0; };
struct Ui_BFu8c_BFu0c { unsigned int v1; unsigned char v2:8; unsigned char :0; };
struct Ui_BFu8c_BFu0i { unsigned int v1; unsigned char v2:8; unsigned int :0; };
struct Ui_BFu8c_BFu0ll { unsigned int v1; unsigned char v2:8; unsigned long long :0; };
struct Ui_BFu8c_BFu0s { unsigned int v1; unsigned char v2:8; unsigned short :0; };
struct Ui_BFu8i_BFu0c { unsigned int v1; unsigned int v2:8; unsigned char :0; };
struct Ui_BFu8i_BFu0i { unsigned int v1; unsigned int v2:8; unsigned int :0; };
struct Ui_BFu8i_BFu0ll { unsigned int v1; unsigned int v2:8; unsigned long long :0; };
struct Ui_BFu8i_BFu0s { unsigned int v1; unsigned int v2:8; unsigned short :0; };
struct Ui_BFu8ll_BFu0c { unsigned int v1; unsigned long long v2:8; unsigned char :0; };
struct Ui_BFu8ll_BFu0i { unsigned int v1; unsigned long long v2:8; unsigned int :0; };
struct Ui_BFu8ll_BFu0ll { unsigned int v1; unsigned long long v2:8; unsigned long long :0; };
struct Ui_BFu8ll_BFu0s { unsigned int v1; unsigned long long v2:8; unsigned short :0; };
struct Ui_BFu8s_BFu0c { unsigned int v1; unsigned short v2:8; unsigned char :0; };
struct Ui_BFu8s_BFu0i { unsigned int v1; unsigned short v2:8; unsigned int :0; };
struct Ui_BFu8s_BFu0ll { unsigned int v1; unsigned short v2:8; unsigned long long :0; };
struct Ui_BFu8s_BFu0s { unsigned int v1; unsigned short v2:8; unsigned short :0; };
struct Ui_BFu9i_BFu0c { unsigned int v1; unsigned int v2:9; unsigned char :0; };
struct Ui_BFu9i_BFu0i { unsigned int v1; unsigned int v2:9; unsigned int :0; };
struct Ui_BFu9i_BFu0ll { unsigned int v1; unsigned int v2:9; unsigned long long :0; };
struct Ui_BFu9i_BFu0s { unsigned int v1; unsigned int v2:9; unsigned short :0; };
struct Ui_BFu9ll_BFu0c { unsigned int v1; unsigned long long v2:9; unsigned char :0; };
struct Ui_BFu9ll_BFu0i { unsigned int v1; unsigned long long v2:9; unsigned int :0; };
struct Ui_BFu9ll_BFu0ll { unsigned int v1; unsigned long long v2:9; unsigned long long :0; };
struct Ui_BFu9ll_BFu0s { unsigned int v1; unsigned long long v2:9; unsigned short :0; };
struct Ui_BFu9s_BFu0c { unsigned int v1; unsigned short v2:9; unsigned char :0; };
struct Ui_BFu9s_BFu0i { unsigned int v1; unsigned short v2:9; unsigned int :0; };
struct Ui_BFu9s_BFu0ll { unsigned int v1; unsigned short v2:9; unsigned long long :0; };
struct Ui_BFu9s_BFu0s { unsigned int v1; unsigned short v2:9; unsigned short :0; };
struct Ui_C_BFu0c { unsigned int v1; char v2; unsigned char :0; };
struct Ui_C_BFu0i { unsigned int v1; char v2; unsigned int :0; };
struct Ui_C_BFu0ll { unsigned int v1; char v2; unsigned long long :0; };
struct Ui_C_BFu0s { unsigned int v1; char v2; unsigned short :0; };
struct Ui_D_BFu0c { unsigned int v1; double v2; unsigned char :0; };
struct Ui_D_BFu0i { unsigned int v1; double v2; unsigned int :0; };
struct Ui_D_BFu0ll { unsigned int v1; double v2; unsigned long long :0; };
struct Ui_D_BFu0s { unsigned int v1; double v2; unsigned short :0; };
struct Ui_F_BFu0c { unsigned int v1; float v2; unsigned char :0; };
struct Ui_F_BFu0i { unsigned int v1; float v2; unsigned int :0; };
struct Ui_F_BFu0ll { unsigned int v1; float v2; unsigned long long :0; };
struct Ui_F_BFu0s { unsigned int v1; float v2; unsigned short :0; };
struct Ui_I_BFu0c { unsigned int v1; int v2; unsigned char :0; };
struct Ui_I_BFu0i { unsigned int v1; int v2; unsigned int :0; };
struct Ui_I_BFu0ll { unsigned int v1; int v2; unsigned long long :0; };
struct Ui_I_BFu0s { unsigned int v1; int v2; unsigned short :0; };
struct Ui_Ip_BFu0c { unsigned int v1; int * v2; unsigned char :0; };
struct Ui_Ip_BFu0i { unsigned int v1; int * v2; unsigned int :0; };
struct Ui_Ip_BFu0ll { unsigned int v1; int * v2; unsigned long long :0; };
struct Ui_Ip_BFu0s { unsigned int v1; int * v2; unsigned short :0; };
struct Ui_L_BFu0c { unsigned int v1; long long v2; unsigned char :0; };
struct Ui_L_BFu0i { unsigned int v1; long long v2; unsigned int :0; };
struct Ui_L_BFu0ll { unsigned int v1; long long v2; unsigned long long :0; };
struct Ui_L_BFu0s { unsigned int v1; long long v2; unsigned short :0; };
struct Ui_S_BFu0c { unsigned int v1; short v2; unsigned char :0; };
struct Ui_S_BFu0i { unsigned int v1; short v2; unsigned int :0; };
struct Ui_S_BFu0ll { unsigned int v1; short v2; unsigned long long :0; };
struct Ui_S_BFu0s { unsigned int v1; short v2; unsigned short :0; };
struct Ui_Uc_BFu0c { unsigned int v1; unsigned char v2; unsigned char :0; };
struct Ui_Uc_BFu0i { unsigned int v1; unsigned char v2; unsigned int :0; };
struct Ui_Uc_BFu0ll { unsigned int v1; unsigned char v2; unsigned long long :0; };
struct Ui_Uc_BFu0s { unsigned int v1; unsigned char v2; unsigned short :0; };
struct Ui_Ui_BFu0c { unsigned int v1; unsigned int v2; unsigned char :0; };
struct Ui_Ui_BFu0i { unsigned int v1; unsigned int v2; unsigned int :0; };
struct Ui_Ui_BFu0ll { unsigned int v1; unsigned int v2; unsigned long long :0; };
struct Ui_Ui_BFu0s { unsigned int v1; unsigned int v2; unsigned short :0; };
struct Ui_Ul_BFu0c { unsigned int v1; unsigned long long v2; unsigned char :0; };
struct Ui_Ul_BFu0i { unsigned int v1; unsigned long long v2; unsigned int :0; };
struct Ui_Ul_BFu0ll { unsigned int v1; unsigned long long v2; unsigned long long :0; };
struct Ui_Ul_BFu0s { unsigned int v1; unsigned long long v2; unsigned short :0; };
struct Ui_Us_BFu0c { unsigned int v1; unsigned short v2; unsigned char :0; };
struct Ui_Us_BFu0i { unsigned int v1; unsigned short v2; unsigned int :0; };
struct Ui_Us_BFu0ll { unsigned int v1; unsigned short v2; unsigned long long :0; };
struct Ui_Us_BFu0s { unsigned int v1; unsigned short v2; unsigned short :0; };
struct Ui_Vp_BFu0c { unsigned int v1; void * v2; unsigned char :0; };
struct Ui_Vp_BFu0i { unsigned int v1; void * v2; unsigned int :0; };
struct Ui_Vp_BFu0ll { unsigned int v1; void * v2; unsigned long long :0; };
struct Ui_Vp_BFu0s { unsigned int v1; void * v2; unsigned short :0; };
struct Ul_BFu0c { unsigned long long v1; unsigned char :0; };
struct Ul_BFu0c_BFu0c { unsigned long long v1; unsigned char :0; unsigned char :0; };
struct Ul_BFu0c_BFu0i { unsigned long long v1; unsigned char :0; unsigned int :0; };
struct Ul_BFu0c_BFu0ll { unsigned long long v1; unsigned char :0; unsigned long long :0; };
struct Ul_BFu0c_BFu0s { unsigned long long v1; unsigned char :0; unsigned short :0; };
struct Ul_BFu0c_BFu15i { unsigned long long v1; unsigned char :0; unsigned int v2:15; };
struct Ul_BFu0c_BFu15ll { unsigned long long v1; unsigned char :0; unsigned long long v2:15; };
struct Ul_BFu0c_BFu15s { unsigned long long v1; unsigned char :0; unsigned short v2:15; };
struct Ul_BFu0c_BFu16i { unsigned long long v1; unsigned char :0; unsigned int v2:16; };
struct Ul_BFu0c_BFu16ll { unsigned long long v1; unsigned char :0; unsigned long long v2:16; };
struct Ul_BFu0c_BFu16s { unsigned long long v1; unsigned char :0; unsigned short v2:16; };
struct Ul_BFu0c_BFu17i { unsigned long long v1; unsigned char :0; unsigned int v2:17; };
struct Ul_BFu0c_BFu17ll { unsigned long long v1; unsigned char :0; unsigned long long v2:17; };
struct Ul_BFu0c_BFu1c { unsigned long long v1; unsigned char :0; unsigned char v2:1; };
struct Ul_BFu0c_BFu1i { unsigned long long v1; unsigned char :0; unsigned int v2:1; };
struct Ul_BFu0c_BFu1ll { unsigned long long v1; unsigned char :0; unsigned long long v2:1; };
struct Ul_BFu0c_BFu1s { unsigned long long v1; unsigned char :0; unsigned short v2:1; };
struct Ul_BFu0c_BFu31i { unsigned long long v1; unsigned char :0; unsigned int v2:31; };
struct Ul_BFu0c_BFu31ll { unsigned long long v1; unsigned char :0; unsigned long long v2:31; };
struct Ul_BFu0c_BFu32i { unsigned long long v1; unsigned char :0; unsigned int v2:32; };
struct Ul_BFu0c_BFu32ll { unsigned long long v1; unsigned char :0; unsigned long long v2:32; };
struct Ul_BFu0c_BFu33 { unsigned long long v1; unsigned char :0; unsigned long long v2:33; };
struct Ul_BFu0c_BFu7c { unsigned long long v1; unsigned char :0; unsigned char v2:7; };
struct Ul_BFu0c_BFu7i { unsigned long long v1; unsigned char :0; unsigned int v2:7; };
struct Ul_BFu0c_BFu7ll { unsigned long long v1; unsigned char :0; unsigned long long v2:7; };
struct Ul_BFu0c_BFu7s { unsigned long long v1; unsigned char :0; unsigned short v2:7; };
struct Ul_BFu0c_BFu8c { unsigned long long v1; unsigned char :0; unsigned char v2:8; };
struct Ul_BFu0c_BFu8i { unsigned long long v1; unsigned char :0; unsigned int v2:8; };
struct Ul_BFu0c_BFu8ll { unsigned long long v1; unsigned char :0; unsigned long long v2:8; };
struct Ul_BFu0c_BFu8s { unsigned long long v1; unsigned char :0; unsigned short v2:8; };
struct Ul_BFu0c_BFu9i { unsigned long long v1; unsigned char :0; unsigned int v2:9; };
struct Ul_BFu0c_BFu9ll { unsigned long long v1; unsigned char :0; unsigned long long v2:9; };
struct Ul_BFu0c_BFu9s { unsigned long long v1; unsigned char :0; unsigned short v2:9; };
struct Ul_BFu0c_C { unsigned long long v1; unsigned char :0; char v2; };
struct Ul_BFu0c_D { unsigned long long v1; unsigned char :0; double v2; };
struct Ul_BFu0c_F { unsigned long long v1; unsigned char :0; float v2; };
struct Ul_BFu0c_I { unsigned long long v1; unsigned char :0; int v2; };
struct Ul_BFu0c_Ip { unsigned long long v1; unsigned char :0; int * v2; };
struct Ul_BFu0c_L { unsigned long long v1; unsigned char :0; long long v2; };
struct Ul_BFu0c_S { unsigned long long v1; unsigned char :0; short v2; };
struct Ul_BFu0c_Uc { unsigned long long v1; unsigned char :0; unsigned char v2; };
struct Ul_BFu0c_Ui { unsigned long long v1; unsigned char :0; unsigned int v2; };
struct Ul_BFu0c_Ul { unsigned long long v1; unsigned char :0; unsigned long long v2; };
struct Ul_BFu0c_Us { unsigned long long v1; unsigned char :0; unsigned short v2; };
struct Ul_BFu0c_Vp { unsigned long long v1; unsigned char :0; void * v2; };
struct Ul_BFu0i { unsigned long long v1; unsigned int :0; };
struct Ul_BFu0i_BFu0c { unsigned long long v1; unsigned int :0; unsigned char :0; };
struct Ul_BFu0i_BFu0i { unsigned long long v1; unsigned int :0; unsigned int :0; };
struct Ul_BFu0i_BFu0ll { unsigned long long v1; unsigned int :0; unsigned long long :0; };
struct Ul_BFu0i_BFu0s { unsigned long long v1; unsigned int :0; unsigned short :0; };
struct Ul_BFu0i_BFu15i { unsigned long long v1; unsigned int :0; unsigned int v2:15; };
struct Ul_BFu0i_BFu15ll { unsigned long long v1; unsigned int :0; unsigned long long v2:15; };
struct Ul_BFu0i_BFu15s { unsigned long long v1; unsigned int :0; unsigned short v2:15; };
struct Ul_BFu0i_BFu16i { unsigned long long v1; unsigned int :0; unsigned int v2:16; };
struct Ul_BFu0i_BFu16ll { unsigned long long v1; unsigned int :0; unsigned long long v2:16; };
struct Ul_BFu0i_BFu16s { unsigned long long v1; unsigned int :0; unsigned short v2:16; };
struct Ul_BFu0i_BFu17i { unsigned long long v1; unsigned int :0; unsigned int v2:17; };
struct Ul_BFu0i_BFu17ll { unsigned long long v1; unsigned int :0; unsigned long long v2:17; };
struct Ul_BFu0i_BFu1c { unsigned long long v1; unsigned int :0; unsigned char v2:1; };
struct Ul_BFu0i_BFu1i { unsigned long long v1; unsigned int :0; unsigned int v2:1; };
struct Ul_BFu0i_BFu1ll { unsigned long long v1; unsigned int :0; unsigned long long v2:1; };
struct Ul_BFu0i_BFu1s { unsigned long long v1; unsigned int :0; unsigned short v2:1; };
struct Ul_BFu0i_BFu31i { unsigned long long v1; unsigned int :0; unsigned int v2:31; };
struct Ul_BFu0i_BFu31ll { unsigned long long v1; unsigned int :0; unsigned long long v2:31; };
struct Ul_BFu0i_BFu32i { unsigned long long v1; unsigned int :0; unsigned int v2:32; };
struct Ul_BFu0i_BFu32ll { unsigned long long v1; unsigned int :0; unsigned long long v2:32; };
struct Ul_BFu0i_BFu33 { unsigned long long v1; unsigned int :0; unsigned long long v2:33; };
struct Ul_BFu0i_BFu7c { unsigned long long v1; unsigned int :0; unsigned char v2:7; };
struct Ul_BFu0i_BFu7i { unsigned long long v1; unsigned int :0; unsigned int v2:7; };
struct Ul_BFu0i_BFu7ll { unsigned long long v1; unsigned int :0; unsigned long long v2:7; };
struct Ul_BFu0i_BFu7s { unsigned long long v1; unsigned int :0; unsigned short v2:7; };
struct Ul_BFu0i_BFu8c { unsigned long long v1; unsigned int :0; unsigned char v2:8; };
struct Ul_BFu0i_BFu8i { unsigned long long v1; unsigned int :0; unsigned int v2:8; };
struct Ul_BFu0i_BFu8ll { unsigned long long v1; unsigned int :0; unsigned long long v2:8; };
struct Ul_BFu0i_BFu8s { unsigned long long v1; unsigned int :0; unsigned short v2:8; };
struct Ul_BFu0i_BFu9i { unsigned long long v1; unsigned int :0; unsigned int v2:9; };
struct Ul_BFu0i_BFu9ll { unsigned long long v1; unsigned int :0; unsigned long long v2:9; };
struct Ul_BFu0i_BFu9s { unsigned long long v1; unsigned int :0; unsigned short v2:9; };
struct Ul_BFu0i_C { unsigned long long v1; unsigned int :0; char v2; };
struct Ul_BFu0i_D { unsigned long long v1; unsigned int :0; double v2; };
struct Ul_BFu0i_F { unsigned long long v1; unsigned int :0; float v2; };
struct Ul_BFu0i_I { unsigned long long v1; unsigned int :0; int v2; };
struct Ul_BFu0i_Ip { unsigned long long v1; unsigned int :0; int * v2; };
struct Ul_BFu0i_L { unsigned long long v1; unsigned int :0; long long v2; };
struct Ul_BFu0i_S { unsigned long long v1; unsigned int :0; short v2; };
struct Ul_BFu0i_Uc { unsigned long long v1; unsigned int :0; unsigned char v2; };
struct Ul_BFu0i_Ui { unsigned long long v1; unsigned int :0; unsigned int v2; };
struct Ul_BFu0i_Ul { unsigned long long v1; unsigned int :0; unsigned long long v2; };
struct Ul_BFu0i_Us { unsigned long long v1; unsigned int :0; unsigned short v2; };
struct Ul_BFu0i_Vp { unsigned long long v1; unsigned int :0; void * v2; };
struct Ul_BFu0ll { unsigned long long v1; unsigned long long :0; };
struct Ul_BFu0ll_BFu0c { unsigned long long v1; unsigned long long :0; unsigned char :0; };
struct Ul_BFu0ll_BFu0i { unsigned long long v1; unsigned long long :0; unsigned int :0; };
struct Ul_BFu0ll_BFu0ll { unsigned long long v1; unsigned long long :0; unsigned long long :0; };
struct Ul_BFu0ll_BFu0s { unsigned long long v1; unsigned long long :0; unsigned short :0; };
struct Ul_BFu0ll_BFu15i { unsigned long long v1; unsigned long long :0; unsigned int v2:15; };
struct Ul_BFu0ll_BFu15ll { unsigned long long v1; unsigned long long :0; unsigned long long v2:15; };
struct Ul_BFu0ll_BFu15s { unsigned long long v1; unsigned long long :0; unsigned short v2:15; };
struct Ul_BFu0ll_BFu16i { unsigned long long v1; unsigned long long :0; unsigned int v2:16; };
struct Ul_BFu0ll_BFu16ll { unsigned long long v1; unsigned long long :0; unsigned long long v2:16; };
struct Ul_BFu0ll_BFu16s { unsigned long long v1; unsigned long long :0; unsigned short v2:16; };
struct Ul_BFu0ll_BFu17i { unsigned long long v1; unsigned long long :0; unsigned int v2:17; };
struct Ul_BFu0ll_BFu17ll { unsigned long long v1; unsigned long long :0; unsigned long long v2:17; };
struct Ul_BFu0ll_BFu1c { unsigned long long v1; unsigned long long :0; unsigned char v2:1; };
struct Ul_BFu0ll_BFu1i { unsigned long long v1; unsigned long long :0; unsigned int v2:1; };
struct Ul_BFu0ll_BFu1ll { unsigned long long v1; unsigned long long :0; unsigned long long v2:1; };
struct Ul_BFu0ll_BFu1s { unsigned long long v1; unsigned long long :0; unsigned short v2:1; };
struct Ul_BFu0ll_BFu31i { unsigned long long v1; unsigned long long :0; unsigned int v2:31; };
struct Ul_BFu0ll_BFu31ll { unsigned long long v1; unsigned long long :0; unsigned long long v2:31; };
struct Ul_BFu0ll_BFu32i { unsigned long long v1; unsigned long long :0; unsigned int v2:32; };
struct Ul_BFu0ll_BFu32ll { unsigned long long v1; unsigned long long :0; unsigned long long v2:32; };
struct Ul_BFu0ll_BFu33 { unsigned long long v1; unsigned long long :0; unsigned long long v2:33; };
struct Ul_BFu0ll_BFu7c { unsigned long long v1; unsigned long long :0; unsigned char v2:7; };
struct Ul_BFu0ll_BFu7i { unsigned long long v1; unsigned long long :0; unsigned int v2:7; };
struct Ul_BFu0ll_BFu7ll { unsigned long long v1; unsigned long long :0; unsigned long long v2:7; };
struct Ul_BFu0ll_BFu7s { unsigned long long v1; unsigned long long :0; unsigned short v2:7; };
struct Ul_BFu0ll_BFu8c { unsigned long long v1; unsigned long long :0; unsigned char v2:8; };
struct Ul_BFu0ll_BFu8i { unsigned long long v1; unsigned long long :0; unsigned int v2:8; };
struct Ul_BFu0ll_BFu8ll { unsigned long long v1; unsigned long long :0; unsigned long long v2:8; };
struct Ul_BFu0ll_BFu8s { unsigned long long v1; unsigned long long :0; unsigned short v2:8; };
struct Ul_BFu0ll_BFu9i { unsigned long long v1; unsigned long long :0; unsigned int v2:9; };
struct Ul_BFu0ll_BFu9ll { unsigned long long v1; unsigned long long :0; unsigned long long v2:9; };
struct Ul_BFu0ll_BFu9s { unsigned long long v1; unsigned long long :0; unsigned short v2:9; };
struct Ul_BFu0ll_C { unsigned long long v1; unsigned long long :0; char v2; };
struct Ul_BFu0ll_D { unsigned long long v1; unsigned long long :0; double v2; };
struct Ul_BFu0ll_F { unsigned long long v1; unsigned long long :0; float v2; };
struct Ul_BFu0ll_I { unsigned long long v1; unsigned long long :0; int v2; };
struct Ul_BFu0ll_Ip { unsigned long long v1; unsigned long long :0; int * v2; };
struct Ul_BFu0ll_L { unsigned long long v1; unsigned long long :0; long long v2; };
struct Ul_BFu0ll_S { unsigned long long v1; unsigned long long :0; short v2; };
struct Ul_BFu0ll_Uc { unsigned long long v1; unsigned long long :0; unsigned char v2; };
struct Ul_BFu0ll_Ui { unsigned long long v1; unsigned long long :0; unsigned int v2; };
struct Ul_BFu0ll_Ul { unsigned long long v1; unsigned long long :0; unsigned long long v2; };
struct Ul_BFu0ll_Us { unsigned long long v1; unsigned long long :0; unsigned short v2; };
struct Ul_BFu0ll_Vp { unsigned long long v1; unsigned long long :0; void * v2; };
struct Ul_BFu0s { unsigned long long v1; unsigned short :0; };
struct Ul_BFu0s_BFu0c { unsigned long long v1; unsigned short :0; unsigned char :0; };
struct Ul_BFu0s_BFu0i { unsigned long long v1; unsigned short :0; unsigned int :0; };
struct Ul_BFu0s_BFu0ll { unsigned long long v1; unsigned short :0; unsigned long long :0; };
struct Ul_BFu0s_BFu0s { unsigned long long v1; unsigned short :0; unsigned short :0; };
struct Ul_BFu0s_BFu15i { unsigned long long v1; unsigned short :0; unsigned int v2:15; };
struct Ul_BFu0s_BFu15ll { unsigned long long v1; unsigned short :0; unsigned long long v2:15; };
struct Ul_BFu0s_BFu15s { unsigned long long v1; unsigned short :0; unsigned short v2:15; };
struct Ul_BFu0s_BFu16i { unsigned long long v1; unsigned short :0; unsigned int v2:16; };
struct Ul_BFu0s_BFu16ll { unsigned long long v1; unsigned short :0; unsigned long long v2:16; };
struct Ul_BFu0s_BFu16s { unsigned long long v1; unsigned short :0; unsigned short v2:16; };
struct Ul_BFu0s_BFu17i { unsigned long long v1; unsigned short :0; unsigned int v2:17; };
struct Ul_BFu0s_BFu17ll { unsigned long long v1; unsigned short :0; unsigned long long v2:17; };
struct Ul_BFu0s_BFu1c { unsigned long long v1; unsigned short :0; unsigned char v2:1; };
struct Ul_BFu0s_BFu1i { unsigned long long v1; unsigned short :0; unsigned int v2:1; };
struct Ul_BFu0s_BFu1ll { unsigned long long v1; unsigned short :0; unsigned long long v2:1; };
struct Ul_BFu0s_BFu1s { unsigned long long v1; unsigned short :0; unsigned short v2:1; };
struct Ul_BFu0s_BFu31i { unsigned long long v1; unsigned short :0; unsigned int v2:31; };
struct Ul_BFu0s_BFu31ll { unsigned long long v1; unsigned short :0; unsigned long long v2:31; };
struct Ul_BFu0s_BFu32i { unsigned long long v1; unsigned short :0; unsigned int v2:32; };
struct Ul_BFu0s_BFu32ll { unsigned long long v1; unsigned short :0; unsigned long long v2:32; };
struct Ul_BFu0s_BFu33 { unsigned long long v1; unsigned short :0; unsigned long long v2:33; };
struct Ul_BFu0s_BFu7c { unsigned long long v1; unsigned short :0; unsigned char v2:7; };
struct Ul_BFu0s_BFu7i { unsigned long long v1; unsigned short :0; unsigned int v2:7; };
struct Ul_BFu0s_BFu7ll { unsigned long long v1; unsigned short :0; unsigned long long v2:7; };
struct Ul_BFu0s_BFu7s { unsigned long long v1; unsigned short :0; unsigned short v2:7; };
struct Ul_BFu0s_BFu8c { unsigned long long v1; unsigned short :0; unsigned char v2:8; };
struct Ul_BFu0s_BFu8i { unsigned long long v1; unsigned short :0; unsigned int v2:8; };
struct Ul_BFu0s_BFu8ll { unsigned long long v1; unsigned short :0; unsigned long long v2:8; };
struct Ul_BFu0s_BFu8s { unsigned long long v1; unsigned short :0; unsigned short v2:8; };
struct Ul_BFu0s_BFu9i { unsigned long long v1; unsigned short :0; unsigned int v2:9; };
struct Ul_BFu0s_BFu9ll { unsigned long long v1; unsigned short :0; unsigned long long v2:9; };
struct Ul_BFu0s_BFu9s { unsigned long long v1; unsigned short :0; unsigned short v2:9; };
struct Ul_BFu0s_C { unsigned long long v1; unsigned short :0; char v2; };
struct Ul_BFu0s_D { unsigned long long v1; unsigned short :0; double v2; };
struct Ul_BFu0s_F { unsigned long long v1; unsigned short :0; float v2; };
struct Ul_BFu0s_I { unsigned long long v1; unsigned short :0; int v2; };
struct Ul_BFu0s_Ip { unsigned long long v1; unsigned short :0; int * v2; };
struct Ul_BFu0s_L { unsigned long long v1; unsigned short :0; long long v2; };
struct Ul_BFu0s_S { unsigned long long v1; unsigned short :0; short v2; };
struct Ul_BFu0s_Uc { unsigned long long v1; unsigned short :0; unsigned char v2; };
struct Ul_BFu0s_Ui { unsigned long long v1; unsigned short :0; unsigned int v2; };
struct Ul_BFu0s_Ul { unsigned long long v1; unsigned short :0; unsigned long long v2; };
struct Ul_BFu0s_Us { unsigned long long v1; unsigned short :0; unsigned short v2; };
struct Ul_BFu0s_Vp { unsigned long long v1; unsigned short :0; void * v2; };
struct Ul_BFu15i_BFu0c { unsigned long long v1; unsigned int v2:15; unsigned char :0; };
struct Ul_BFu15i_BFu0i { unsigned long long v1; unsigned int v2:15; unsigned int :0; };
struct Ul_BFu15i_BFu0ll { unsigned long long v1; unsigned int v2:15; unsigned long long :0; };
struct Ul_BFu15i_BFu0s { unsigned long long v1; unsigned int v2:15; unsigned short :0; };
struct Ul_BFu15ll_BFu0c { unsigned long long v1; unsigned long long v2:15; unsigned char :0; };
struct Ul_BFu15ll_BFu0i { unsigned long long v1; unsigned long long v2:15; unsigned int :0; };
struct Ul_BFu15ll_BFu0ll { unsigned long long v1; unsigned long long v2:15; unsigned long long :0; };
struct Ul_BFu15ll_BFu0s { unsigned long long v1; unsigned long long v2:15; unsigned short :0; };
struct Ul_BFu15s_BFu0c { unsigned long long v1; unsigned short v2:15; unsigned char :0; };
struct Ul_BFu15s_BFu0i { unsigned long long v1; unsigned short v2:15; unsigned int :0; };
struct Ul_BFu15s_BFu0ll { unsigned long long v1; unsigned short v2:15; unsigned long long :0; };
struct Ul_BFu15s_BFu0s { unsigned long long v1; unsigned short v2:15; unsigned short :0; };
struct Ul_BFu16i_BFu0c { unsigned long long v1; unsigned int v2:16; unsigned char :0; };
struct Ul_BFu16i_BFu0i { unsigned long long v1; unsigned int v2:16; unsigned int :0; };
struct Ul_BFu16i_BFu0ll { unsigned long long v1; unsigned int v2:16; unsigned long long :0; };
struct Ul_BFu16i_BFu0s { unsigned long long v1; unsigned int v2:16; unsigned short :0; };
struct Ul_BFu16ll_BFu0c { unsigned long long v1; unsigned long long v2:16; unsigned char :0; };
struct Ul_BFu16ll_BFu0i { unsigned long long v1; unsigned long long v2:16; unsigned int :0; };
struct Ul_BFu16ll_BFu0ll { unsigned long long v1; unsigned long long v2:16; unsigned long long :0; };
struct Ul_BFu16ll_BFu0s { unsigned long long v1; unsigned long long v2:16; unsigned short :0; };
struct Ul_BFu16s_BFu0c { unsigned long long v1; unsigned short v2:16; unsigned char :0; };
struct Ul_BFu16s_BFu0i { unsigned long long v1; unsigned short v2:16; unsigned int :0; };
struct Ul_BFu16s_BFu0ll { unsigned long long v1; unsigned short v2:16; unsigned long long :0; };
struct Ul_BFu16s_BFu0s { unsigned long long v1; unsigned short v2:16; unsigned short :0; };
struct Ul_BFu17i_BFu0c { unsigned long long v1; unsigned int v2:17; unsigned char :0; };
struct Ul_BFu17i_BFu0i { unsigned long long v1; unsigned int v2:17; unsigned int :0; };
struct Ul_BFu17i_BFu0ll { unsigned long long v1; unsigned int v2:17; unsigned long long :0; };
struct Ul_BFu17i_BFu0s { unsigned long long v1; unsigned int v2:17; unsigned short :0; };
struct Ul_BFu17ll_BFu0c { unsigned long long v1; unsigned long long v2:17; unsigned char :0; };
struct Ul_BFu17ll_BFu0i { unsigned long long v1; unsigned long long v2:17; unsigned int :0; };
struct Ul_BFu17ll_BFu0ll { unsigned long long v1; unsigned long long v2:17; unsigned long long :0; };
struct Ul_BFu17ll_BFu0s { unsigned long long v1; unsigned long long v2:17; unsigned short :0; };
struct Ul_BFu1c_BFu0c { unsigned long long v1; unsigned char v2:1; unsigned char :0; };
struct Ul_BFu1c_BFu0i { unsigned long long v1; unsigned char v2:1; unsigned int :0; };
struct Ul_BFu1c_BFu0ll { unsigned long long v1; unsigned char v2:1; unsigned long long :0; };
struct Ul_BFu1c_BFu0s { unsigned long long v1; unsigned char v2:1; unsigned short :0; };
struct Ul_BFu1i_BFu0c { unsigned long long v1; unsigned int v2:1; unsigned char :0; };
struct Ul_BFu1i_BFu0i { unsigned long long v1; unsigned int v2:1; unsigned int :0; };
struct Ul_BFu1i_BFu0ll { unsigned long long v1; unsigned int v2:1; unsigned long long :0; };
struct Ul_BFu1i_BFu0s { unsigned long long v1; unsigned int v2:1; unsigned short :0; };
struct Ul_BFu1ll_BFu0c { unsigned long long v1; unsigned long long v2:1; unsigned char :0; };
struct Ul_BFu1ll_BFu0i { unsigned long long v1; unsigned long long v2:1; unsigned int :0; };
struct Ul_BFu1ll_BFu0ll { unsigned long long v1; unsigned long long v2:1; unsigned long long :0; };
struct Ul_BFu1ll_BFu0s { unsigned long long v1; unsigned long long v2:1; unsigned short :0; };
struct Ul_BFu1s_BFu0c { unsigned long long v1; unsigned short v2:1; unsigned char :0; };
struct Ul_BFu1s_BFu0i { unsigned long long v1; unsigned short v2:1; unsigned int :0; };
struct Ul_BFu1s_BFu0ll { unsigned long long v1; unsigned short v2:1; unsigned long long :0; };
struct Ul_BFu1s_BFu0s { unsigned long long v1; unsigned short v2:1; unsigned short :0; };
struct Ul_BFu31i_BFu0c { unsigned long long v1; unsigned int v2:31; unsigned char :0; };
struct Ul_BFu31i_BFu0i { unsigned long long v1; unsigned int v2:31; unsigned int :0; };
struct Ul_BFu31i_BFu0ll { unsigned long long v1; unsigned int v2:31; unsigned long long :0; };
struct Ul_BFu31i_BFu0s { unsigned long long v1; unsigned int v2:31; unsigned short :0; };
struct Ul_BFu31ll_BFu0c { unsigned long long v1; unsigned long long v2:31; unsigned char :0; };
struct Ul_BFu31ll_BFu0i { unsigned long long v1; unsigned long long v2:31; unsigned int :0; };
struct Ul_BFu31ll_BFu0ll { unsigned long long v1; unsigned long long v2:31; unsigned long long :0; };
struct Ul_BFu31ll_BFu0s { unsigned long long v1; unsigned long long v2:31; unsigned short :0; };
struct Ul_BFu32i_BFu0c { unsigned long long v1; unsigned int v2:32; unsigned char :0; };
struct Ul_BFu32i_BFu0i { unsigned long long v1; unsigned int v2:32; unsigned int :0; };
struct Ul_BFu32i_BFu0ll { unsigned long long v1; unsigned int v2:32; unsigned long long :0; };
struct Ul_BFu32i_BFu0s { unsigned long long v1; unsigned int v2:32; unsigned short :0; };
struct Ul_BFu32ll_BFu0c { unsigned long long v1; unsigned long long v2:32; unsigned char :0; };
struct Ul_BFu32ll_BFu0i { unsigned long long v1; unsigned long long v2:32; unsigned int :0; };
struct Ul_BFu32ll_BFu0ll { unsigned long long v1; unsigned long long v2:32; unsigned long long :0; };
struct Ul_BFu32ll_BFu0s { unsigned long long v1; unsigned long long v2:32; unsigned short :0; };
struct Ul_BFu33_BFu0c { unsigned long long v1; unsigned long long v2:33; unsigned char :0; };
struct Ul_BFu33_BFu0i { unsigned long long v1; unsigned long long v2:33; unsigned int :0; };
struct Ul_BFu33_BFu0ll { unsigned long long v1; unsigned long long v2:33; unsigned long long :0; };
struct Ul_BFu33_BFu0s { unsigned long long v1; unsigned long long v2:33; unsigned short :0; };
struct Ul_BFu7c_BFu0c { unsigned long long v1; unsigned char v2:7; unsigned char :0; };
struct Ul_BFu7c_BFu0i { unsigned long long v1; unsigned char v2:7; unsigned int :0; };
struct Ul_BFu7c_BFu0ll { unsigned long long v1; unsigned char v2:7; unsigned long long :0; };
struct Ul_BFu7c_BFu0s { unsigned long long v1; unsigned char v2:7; unsigned short :0; };
struct Ul_BFu7i_BFu0c { unsigned long long v1; unsigned int v2:7; unsigned char :0; };
struct Ul_BFu7i_BFu0i { unsigned long long v1; unsigned int v2:7; unsigned int :0; };
struct Ul_BFu7i_BFu0ll { unsigned long long v1; unsigned int v2:7; unsigned long long :0; };
struct Ul_BFu7i_BFu0s { unsigned long long v1; unsigned int v2:7; unsigned short :0; };
struct Ul_BFu7ll_BFu0c { unsigned long long v1; unsigned long long v2:7; unsigned char :0; };
struct Ul_BFu7ll_BFu0i { unsigned long long v1; unsigned long long v2:7; unsigned int :0; };
struct Ul_BFu7ll_BFu0ll { unsigned long long v1; unsigned long long v2:7; unsigned long long :0; };
struct Ul_BFu7ll_BFu0s { unsigned long long v1; unsigned long long v2:7; unsigned short :0; };
struct Ul_BFu7s_BFu0c { unsigned long long v1; unsigned short v2:7; unsigned char :0; };
struct Ul_BFu7s_BFu0i { unsigned long long v1; unsigned short v2:7; unsigned int :0; };
struct Ul_BFu7s_BFu0ll { unsigned long long v1; unsigned short v2:7; unsigned long long :0; };
struct Ul_BFu7s_BFu0s { unsigned long long v1; unsigned short v2:7; unsigned short :0; };
struct Ul_BFu8c_BFu0c { unsigned long long v1; unsigned char v2:8; unsigned char :0; };
struct Ul_BFu8c_BFu0i { unsigned long long v1; unsigned char v2:8; unsigned int :0; };
struct Ul_BFu8c_BFu0ll { unsigned long long v1; unsigned char v2:8; unsigned long long :0; };
struct Ul_BFu8c_BFu0s { unsigned long long v1; unsigned char v2:8; unsigned short :0; };
struct Ul_BFu8i_BFu0c { unsigned long long v1; unsigned int v2:8; unsigned char :0; };
struct Ul_BFu8i_BFu0i { unsigned long long v1; unsigned int v2:8; unsigned int :0; };
struct Ul_BFu8i_BFu0ll { unsigned long long v1; unsigned int v2:8; unsigned long long :0; };
struct Ul_BFu8i_BFu0s { unsigned long long v1; unsigned int v2:8; unsigned short :0; };
struct Ul_BFu8ll_BFu0c { unsigned long long v1; unsigned long long v2:8; unsigned char :0; };
struct Ul_BFu8ll_BFu0i { unsigned long long v1; unsigned long long v2:8; unsigned int :0; };
struct Ul_BFu8ll_BFu0ll { unsigned long long v1; unsigned long long v2:8; unsigned long long :0; };
struct Ul_BFu8ll_BFu0s { unsigned long long v1; unsigned long long v2:8; unsigned short :0; };
struct Ul_BFu8s_BFu0c { unsigned long long v1; unsigned short v2:8; unsigned char :0; };
struct Ul_BFu8s_BFu0i { unsigned long long v1; unsigned short v2:8; unsigned int :0; };
struct Ul_BFu8s_BFu0ll { unsigned long long v1; unsigned short v2:8; unsigned long long :0; };
struct Ul_BFu8s_BFu0s { unsigned long long v1; unsigned short v2:8; unsigned short :0; };
struct Ul_BFu9i_BFu0c { unsigned long long v1; unsigned int v2:9; unsigned char :0; };
struct Ul_BFu9i_BFu0i { unsigned long long v1; unsigned int v2:9; unsigned int :0; };
struct Ul_BFu9i_BFu0ll { unsigned long long v1; unsigned int v2:9; unsigned long long :0; };
struct Ul_BFu9i_BFu0s { unsigned long long v1; unsigned int v2:9; unsigned short :0; };
struct Ul_BFu9ll_BFu0c { unsigned long long v1; unsigned long long v2:9; unsigned char :0; };
struct Ul_BFu9ll_BFu0i { unsigned long long v1; unsigned long long v2:9; unsigned int :0; };
struct Ul_BFu9ll_BFu0ll { unsigned long long v1; unsigned long long v2:9; unsigned long long :0; };
struct Ul_BFu9ll_BFu0s { unsigned long long v1; unsigned long long v2:9; unsigned short :0; };
struct Ul_BFu9s_BFu0c { unsigned long long v1; unsigned short v2:9; unsigned char :0; };
struct Ul_BFu9s_BFu0i { unsigned long long v1; unsigned short v2:9; unsigned int :0; };
struct Ul_BFu9s_BFu0ll { unsigned long long v1; unsigned short v2:9; unsigned long long :0; };
struct Ul_BFu9s_BFu0s { unsigned long long v1; unsigned short v2:9; unsigned short :0; };
struct Ul_C_BFu0c { unsigned long long v1; char v2; unsigned char :0; };
struct Ul_C_BFu0i { unsigned long long v1; char v2; unsigned int :0; };
struct Ul_C_BFu0ll { unsigned long long v1; char v2; unsigned long long :0; };
struct Ul_C_BFu0s { unsigned long long v1; char v2; unsigned short :0; };
struct Ul_D_BFu0c { unsigned long long v1; double v2; unsigned char :0; };
struct Ul_D_BFu0i { unsigned long long v1; double v2; unsigned int :0; };
struct Ul_D_BFu0ll { unsigned long long v1; double v2; unsigned long long :0; };
struct Ul_D_BFu0s { unsigned long long v1; double v2; unsigned short :0; };
struct Ul_F_BFu0c { unsigned long long v1; float v2; unsigned char :0; };
struct Ul_F_BFu0i { unsigned long long v1; float v2; unsigned int :0; };
struct Ul_F_BFu0ll { unsigned long long v1; float v2; unsigned long long :0; };
struct Ul_F_BFu0s { unsigned long long v1; float v2; unsigned short :0; };
struct Ul_I_BFu0c { unsigned long long v1; int v2; unsigned char :0; };
struct Ul_I_BFu0i { unsigned long long v1; int v2; unsigned int :0; };
struct Ul_I_BFu0ll { unsigned long long v1; int v2; unsigned long long :0; };
struct Ul_I_BFu0s { unsigned long long v1; int v2; unsigned short :0; };
struct Ul_Ip_BFu0c { unsigned long long v1; int * v2; unsigned char :0; };
struct Ul_Ip_BFu0i { unsigned long long v1; int * v2; unsigned int :0; };
struct Ul_Ip_BFu0ll { unsigned long long v1; int * v2; unsigned long long :0; };
struct Ul_Ip_BFu0s { unsigned long long v1; int * v2; unsigned short :0; };
struct Ul_L_BFu0c { unsigned long long v1; long long v2; unsigned char :0; };
struct Ul_L_BFu0i { unsigned long long v1; long long v2; unsigned int :0; };
struct Ul_L_BFu0ll { unsigned long long v1; long long v2; unsigned long long :0; };
struct Ul_L_BFu0s { unsigned long long v1; long long v2; unsigned short :0; };
struct Ul_S_BFu0c { unsigned long long v1; short v2; unsigned char :0; };
struct Ul_S_BFu0i { unsigned long long v1; short v2; unsigned int :0; };
struct Ul_S_BFu0ll { unsigned long long v1; short v2; unsigned long long :0; };
struct Ul_S_BFu0s { unsigned long long v1; short v2; unsigned short :0; };
struct Ul_Uc_BFu0c { unsigned long long v1; unsigned char v2; unsigned char :0; };
struct Ul_Uc_BFu0i { unsigned long long v1; unsigned char v2; unsigned int :0; };
struct Ul_Uc_BFu0ll { unsigned long long v1; unsigned char v2; unsigned long long :0; };
struct Ul_Uc_BFu0s { unsigned long long v1; unsigned char v2; unsigned short :0; };
struct Ul_Ui_BFu0c { unsigned long long v1; unsigned int v2; unsigned char :0; };
struct Ul_Ui_BFu0i { unsigned long long v1; unsigned int v2; unsigned int :0; };
struct Ul_Ui_BFu0ll { unsigned long long v1; unsigned int v2; unsigned long long :0; };
struct Ul_Ui_BFu0s { unsigned long long v1; unsigned int v2; unsigned short :0; };
struct Ul_Ul_BFu0c { unsigned long long v1; unsigned long long v2; unsigned char :0; };
struct Ul_Ul_BFu0i { unsigned long long v1; unsigned long long v2; unsigned int :0; };
struct Ul_Ul_BFu0ll { unsigned long long v1; unsigned long long v2; unsigned long long :0; };
struct Ul_Ul_BFu0s { unsigned long long v1; unsigned long long v2; unsigned short :0; };
struct Ul_Us_BFu0c { unsigned long long v1; unsigned short v2; unsigned char :0; };
struct Ul_Us_BFu0i { unsigned long long v1; unsigned short v2; unsigned int :0; };
struct Ul_Us_BFu0ll { unsigned long long v1; unsigned short v2; unsigned long long :0; };
struct Ul_Us_BFu0s { unsigned long long v1; unsigned short v2; unsigned short :0; };
struct Ul_Vp_BFu0c { unsigned long long v1; void * v2; unsigned char :0; };
struct Ul_Vp_BFu0i { unsigned long long v1; void * v2; unsigned int :0; };
struct Ul_Vp_BFu0ll { unsigned long long v1; void * v2; unsigned long long :0; };
struct Ul_Vp_BFu0s { unsigned long long v1; void * v2; unsigned short :0; };
struct Us_BFu0c { unsigned short v1; unsigned char :0; };
struct Us_BFu0c_BFu0c { unsigned short v1; unsigned char :0; unsigned char :0; };
struct Us_BFu0c_BFu0i { unsigned short v1; unsigned char :0; unsigned int :0; };
struct Us_BFu0c_BFu0ll { unsigned short v1; unsigned char :0; unsigned long long :0; };
struct Us_BFu0c_BFu0s { unsigned short v1; unsigned char :0; unsigned short :0; };
struct Us_BFu0c_BFu15i { unsigned short v1; unsigned char :0; unsigned int v2:15; };
struct Us_BFu0c_BFu15ll { unsigned short v1; unsigned char :0; unsigned long long v2:15; };
struct Us_BFu0c_BFu15s { unsigned short v1; unsigned char :0; unsigned short v2:15; };
struct Us_BFu0c_BFu16i { unsigned short v1; unsigned char :0; unsigned int v2:16; };
struct Us_BFu0c_BFu16ll { unsigned short v1; unsigned char :0; unsigned long long v2:16; };
struct Us_BFu0c_BFu16s { unsigned short v1; unsigned char :0; unsigned short v2:16; };
struct Us_BFu0c_BFu17i { unsigned short v1; unsigned char :0; unsigned int v2:17; };
struct Us_BFu0c_BFu17ll { unsigned short v1; unsigned char :0; unsigned long long v2:17; };
struct Us_BFu0c_BFu1c { unsigned short v1; unsigned char :0; unsigned char v2:1; };
struct Us_BFu0c_BFu1i { unsigned short v1; unsigned char :0; unsigned int v2:1; };
struct Us_BFu0c_BFu1ll { unsigned short v1; unsigned char :0; unsigned long long v2:1; };
struct Us_BFu0c_BFu1s { unsigned short v1; unsigned char :0; unsigned short v2:1; };
struct Us_BFu0c_BFu31i { unsigned short v1; unsigned char :0; unsigned int v2:31; };
struct Us_BFu0c_BFu31ll { unsigned short v1; unsigned char :0; unsigned long long v2:31; };
struct Us_BFu0c_BFu32i { unsigned short v1; unsigned char :0; unsigned int v2:32; };
struct Us_BFu0c_BFu32ll { unsigned short v1; unsigned char :0; unsigned long long v2:32; };
struct Us_BFu0c_BFu33 { unsigned short v1; unsigned char :0; unsigned long long v2:33; };
struct Us_BFu0c_BFu7c { unsigned short v1; unsigned char :0; unsigned char v2:7; };
struct Us_BFu0c_BFu7i { unsigned short v1; unsigned char :0; unsigned int v2:7; };
struct Us_BFu0c_BFu7ll { unsigned short v1; unsigned char :0; unsigned long long v2:7; };
struct Us_BFu0c_BFu7s { unsigned short v1; unsigned char :0; unsigned short v2:7; };
struct Us_BFu0c_BFu8c { unsigned short v1; unsigned char :0; unsigned char v2:8; };
struct Us_BFu0c_BFu8i { unsigned short v1; unsigned char :0; unsigned int v2:8; };
struct Us_BFu0c_BFu8ll { unsigned short v1; unsigned char :0; unsigned long long v2:8; };
struct Us_BFu0c_BFu8s { unsigned short v1; unsigned char :0; unsigned short v2:8; };
struct Us_BFu0c_BFu9i { unsigned short v1; unsigned char :0; unsigned int v2:9; };
struct Us_BFu0c_BFu9ll { unsigned short v1; unsigned char :0; unsigned long long v2:9; };
struct Us_BFu0c_BFu9s { unsigned short v1; unsigned char :0; unsigned short v2:9; };
struct Us_BFu0c_C { unsigned short v1; unsigned char :0; char v2; };
struct Us_BFu0c_D { unsigned short v1; unsigned char :0; double v2; };
struct Us_BFu0c_F { unsigned short v1; unsigned char :0; float v2; };
struct Us_BFu0c_I { unsigned short v1; unsigned char :0; int v2; };
struct Us_BFu0c_Ip { unsigned short v1; unsigned char :0; int * v2; };
struct Us_BFu0c_L { unsigned short v1; unsigned char :0; long long v2; };
struct Us_BFu0c_S { unsigned short v1; unsigned char :0; short v2; };
struct Us_BFu0c_Uc { unsigned short v1; unsigned char :0; unsigned char v2; };
struct Us_BFu0c_Ui { unsigned short v1; unsigned char :0; unsigned int v2; };
struct Us_BFu0c_Ul { unsigned short v1; unsigned char :0; unsigned long long v2; };
struct Us_BFu0c_Us { unsigned short v1; unsigned char :0; unsigned short v2; };
struct Us_BFu0c_Vp { unsigned short v1; unsigned char :0; void * v2; };
struct Us_BFu0i { unsigned short v1; unsigned int :0; };
struct Us_BFu0i_BFu0c { unsigned short v1; unsigned int :0; unsigned char :0; };
struct Us_BFu0i_BFu0i { unsigned short v1; unsigned int :0; unsigned int :0; };
struct Us_BFu0i_BFu0ll { unsigned short v1; unsigned int :0; unsigned long long :0; };
struct Us_BFu0i_BFu0s { unsigned short v1; unsigned int :0; unsigned short :0; };
struct Us_BFu0i_BFu15i { unsigned short v1; unsigned int :0; unsigned int v2:15; };
struct Us_BFu0i_BFu15ll { unsigned short v1; unsigned int :0; unsigned long long v2:15; };
struct Us_BFu0i_BFu15s { unsigned short v1; unsigned int :0; unsigned short v2:15; };
struct Us_BFu0i_BFu16i { unsigned short v1; unsigned int :0; unsigned int v2:16; };
struct Us_BFu0i_BFu16ll { unsigned short v1; unsigned int :0; unsigned long long v2:16; };
struct Us_BFu0i_BFu16s { unsigned short v1; unsigned int :0; unsigned short v2:16; };
struct Us_BFu0i_BFu17i { unsigned short v1; unsigned int :0; unsigned int v2:17; };
struct Us_BFu0i_BFu17ll { unsigned short v1; unsigned int :0; unsigned long long v2:17; };
struct Us_BFu0i_BFu1c { unsigned short v1; unsigned int :0; unsigned char v2:1; };
struct Us_BFu0i_BFu1i { unsigned short v1; unsigned int :0; unsigned int v2:1; };
struct Us_BFu0i_BFu1ll { unsigned short v1; unsigned int :0; unsigned long long v2:1; };
struct Us_BFu0i_BFu1s { unsigned short v1; unsigned int :0; unsigned short v2:1; };
struct Us_BFu0i_BFu31i { unsigned short v1; unsigned int :0; unsigned int v2:31; };
struct Us_BFu0i_BFu31ll { unsigned short v1; unsigned int :0; unsigned long long v2:31; };
struct Us_BFu0i_BFu32i { unsigned short v1; unsigned int :0; unsigned int v2:32; };
struct Us_BFu0i_BFu32ll { unsigned short v1; unsigned int :0; unsigned long long v2:32; };
struct Us_BFu0i_BFu33 { unsigned short v1; unsigned int :0; unsigned long long v2:33; };
struct Us_BFu0i_BFu7c { unsigned short v1; unsigned int :0; unsigned char v2:7; };
struct Us_BFu0i_BFu7i { unsigned short v1; unsigned int :0; unsigned int v2:7; };
struct Us_BFu0i_BFu7ll { unsigned short v1; unsigned int :0; unsigned long long v2:7; };
struct Us_BFu0i_BFu7s { unsigned short v1; unsigned int :0; unsigned short v2:7; };
struct Us_BFu0i_BFu8c { unsigned short v1; unsigned int :0; unsigned char v2:8; };
struct Us_BFu0i_BFu8i { unsigned short v1; unsigned int :0; unsigned int v2:8; };
struct Us_BFu0i_BFu8ll { unsigned short v1; unsigned int :0; unsigned long long v2:8; };
struct Us_BFu0i_BFu8s { unsigned short v1; unsigned int :0; unsigned short v2:8; };
struct Us_BFu0i_BFu9i { unsigned short v1; unsigned int :0; unsigned int v2:9; };
struct Us_BFu0i_BFu9ll { unsigned short v1; unsigned int :0; unsigned long long v2:9; };
struct Us_BFu0i_BFu9s { unsigned short v1; unsigned int :0; unsigned short v2:9; };
struct Us_BFu0i_C { unsigned short v1; unsigned int :0; char v2; };
struct Us_BFu0i_D { unsigned short v1; unsigned int :0; double v2; };
struct Us_BFu0i_F { unsigned short v1; unsigned int :0; float v2; };
struct Us_BFu0i_I { unsigned short v1; unsigned int :0; int v2; };
struct Us_BFu0i_Ip { unsigned short v1; unsigned int :0; int * v2; };
struct Us_BFu0i_L { unsigned short v1; unsigned int :0; long long v2; };
struct Us_BFu0i_S { unsigned short v1; unsigned int :0; short v2; };
struct Us_BFu0i_Uc { unsigned short v1; unsigned int :0; unsigned char v2; };
struct Us_BFu0i_Ui { unsigned short v1; unsigned int :0; unsigned int v2; };
struct Us_BFu0i_Ul { unsigned short v1; unsigned int :0; unsigned long long v2; };
struct Us_BFu0i_Us { unsigned short v1; unsigned int :0; unsigned short v2; };
struct Us_BFu0i_Vp { unsigned short v1; unsigned int :0; void * v2; };
struct Us_BFu0ll { unsigned short v1; unsigned long long :0; };
struct Us_BFu0ll_BFu0c { unsigned short v1; unsigned long long :0; unsigned char :0; };
struct Us_BFu0ll_BFu0i { unsigned short v1; unsigned long long :0; unsigned int :0; };
struct Us_BFu0ll_BFu0ll { unsigned short v1; unsigned long long :0; unsigned long long :0; };
struct Us_BFu0ll_BFu0s { unsigned short v1; unsigned long long :0; unsigned short :0; };
struct Us_BFu0ll_BFu15i { unsigned short v1; unsigned long long :0; unsigned int v2:15; };
struct Us_BFu0ll_BFu15ll { unsigned short v1; unsigned long long :0; unsigned long long v2:15; };
struct Us_BFu0ll_BFu15s { unsigned short v1; unsigned long long :0; unsigned short v2:15; };
struct Us_BFu0ll_BFu16i { unsigned short v1; unsigned long long :0; unsigned int v2:16; };
struct Us_BFu0ll_BFu16ll { unsigned short v1; unsigned long long :0; unsigned long long v2:16; };
struct Us_BFu0ll_BFu16s { unsigned short v1; unsigned long long :0; unsigned short v2:16; };
struct Us_BFu0ll_BFu17i { unsigned short v1; unsigned long long :0; unsigned int v2:17; };
struct Us_BFu0ll_BFu17ll { unsigned short v1; unsigned long long :0; unsigned long long v2:17; };
struct Us_BFu0ll_BFu1c { unsigned short v1; unsigned long long :0; unsigned char v2:1; };
struct Us_BFu0ll_BFu1i { unsigned short v1; unsigned long long :0; unsigned int v2:1; };
struct Us_BFu0ll_BFu1ll { unsigned short v1; unsigned long long :0; unsigned long long v2:1; };
struct Us_BFu0ll_BFu1s { unsigned short v1; unsigned long long :0; unsigned short v2:1; };
struct Us_BFu0ll_BFu31i { unsigned short v1; unsigned long long :0; unsigned int v2:31; };
struct Us_BFu0ll_BFu31ll { unsigned short v1; unsigned long long :0; unsigned long long v2:31; };
struct Us_BFu0ll_BFu32i { unsigned short v1; unsigned long long :0; unsigned int v2:32; };
struct Us_BFu0ll_BFu32ll { unsigned short v1; unsigned long long :0; unsigned long long v2:32; };
struct Us_BFu0ll_BFu33 { unsigned short v1; unsigned long long :0; unsigned long long v2:33; };
struct Us_BFu0ll_BFu7c { unsigned short v1; unsigned long long :0; unsigned char v2:7; };
struct Us_BFu0ll_BFu7i { unsigned short v1; unsigned long long :0; unsigned int v2:7; };
struct Us_BFu0ll_BFu7ll { unsigned short v1; unsigned long long :0; unsigned long long v2:7; };
struct Us_BFu0ll_BFu7s { unsigned short v1; unsigned long long :0; unsigned short v2:7; };
struct Us_BFu0ll_BFu8c { unsigned short v1; unsigned long long :0; unsigned char v2:8; };
struct Us_BFu0ll_BFu8i { unsigned short v1; unsigned long long :0; unsigned int v2:8; };
struct Us_BFu0ll_BFu8ll { unsigned short v1; unsigned long long :0; unsigned long long v2:8; };
struct Us_BFu0ll_BFu8s { unsigned short v1; unsigned long long :0; unsigned short v2:8; };
struct Us_BFu0ll_BFu9i { unsigned short v1; unsigned long long :0; unsigned int v2:9; };
struct Us_BFu0ll_BFu9ll { unsigned short v1; unsigned long long :0; unsigned long long v2:9; };
struct Us_BFu0ll_BFu9s { unsigned short v1; unsigned long long :0; unsigned short v2:9; };
struct Us_BFu0ll_C { unsigned short v1; unsigned long long :0; char v2; };
struct Us_BFu0ll_D { unsigned short v1; unsigned long long :0; double v2; };
struct Us_BFu0ll_F { unsigned short v1; unsigned long long :0; float v2; };
struct Us_BFu0ll_I { unsigned short v1; unsigned long long :0; int v2; };
struct Us_BFu0ll_Ip { unsigned short v1; unsigned long long :0; int * v2; };
struct Us_BFu0ll_L { unsigned short v1; unsigned long long :0; long long v2; };
struct Us_BFu0ll_S { unsigned short v1; unsigned long long :0; short v2; };
struct Us_BFu0ll_Uc { unsigned short v1; unsigned long long :0; unsigned char v2; };
struct Us_BFu0ll_Ui { unsigned short v1; unsigned long long :0; unsigned int v2; };
struct Us_BFu0ll_Ul { unsigned short v1; unsigned long long :0; unsigned long long v2; };
struct Us_BFu0ll_Us { unsigned short v1; unsigned long long :0; unsigned short v2; };
struct Us_BFu0ll_Vp { unsigned short v1; unsigned long long :0; void * v2; };
struct Us_BFu0s { unsigned short v1; unsigned short :0; };
struct Us_BFu0s_BFu0c { unsigned short v1; unsigned short :0; unsigned char :0; };
struct Us_BFu0s_BFu0i { unsigned short v1; unsigned short :0; unsigned int :0; };
struct Us_BFu0s_BFu0ll { unsigned short v1; unsigned short :0; unsigned long long :0; };
struct Us_BFu0s_BFu0s { unsigned short v1; unsigned short :0; unsigned short :0; };
struct Us_BFu0s_BFu15i { unsigned short v1; unsigned short :0; unsigned int v2:15; };
struct Us_BFu0s_BFu15ll { unsigned short v1; unsigned short :0; unsigned long long v2:15; };
struct Us_BFu0s_BFu15s { unsigned short v1; unsigned short :0; unsigned short v2:15; };
struct Us_BFu0s_BFu16i { unsigned short v1; unsigned short :0; unsigned int v2:16; };
struct Us_BFu0s_BFu16ll { unsigned short v1; unsigned short :0; unsigned long long v2:16; };
struct Us_BFu0s_BFu16s { unsigned short v1; unsigned short :0; unsigned short v2:16; };
struct Us_BFu0s_BFu17i { unsigned short v1; unsigned short :0; unsigned int v2:17; };
struct Us_BFu0s_BFu17ll { unsigned short v1; unsigned short :0; unsigned long long v2:17; };
struct Us_BFu0s_BFu1c { unsigned short v1; unsigned short :0; unsigned char v2:1; };
struct Us_BFu0s_BFu1i { unsigned short v1; unsigned short :0; unsigned int v2:1; };
struct Us_BFu0s_BFu1ll { unsigned short v1; unsigned short :0; unsigned long long v2:1; };
struct Us_BFu0s_BFu1s { unsigned short v1; unsigned short :0; unsigned short v2:1; };
struct Us_BFu0s_BFu31i { unsigned short v1; unsigned short :0; unsigned int v2:31; };
struct Us_BFu0s_BFu31ll { unsigned short v1; unsigned short :0; unsigned long long v2:31; };
struct Us_BFu0s_BFu32i { unsigned short v1; unsigned short :0; unsigned int v2:32; };
struct Us_BFu0s_BFu32ll { unsigned short v1; unsigned short :0; unsigned long long v2:32; };
struct Us_BFu0s_BFu33 { unsigned short v1; unsigned short :0; unsigned long long v2:33; };
struct Us_BFu0s_BFu7c { unsigned short v1; unsigned short :0; unsigned char v2:7; };
struct Us_BFu0s_BFu7i { unsigned short v1; unsigned short :0; unsigned int v2:7; };
struct Us_BFu0s_BFu7ll { unsigned short v1; unsigned short :0; unsigned long long v2:7; };
struct Us_BFu0s_BFu7s { unsigned short v1; unsigned short :0; unsigned short v2:7; };
struct Us_BFu0s_BFu8c { unsigned short v1; unsigned short :0; unsigned char v2:8; };
struct Us_BFu0s_BFu8i { unsigned short v1; unsigned short :0; unsigned int v2:8; };
struct Us_BFu0s_BFu8ll { unsigned short v1; unsigned short :0; unsigned long long v2:8; };
struct Us_BFu0s_BFu8s { unsigned short v1; unsigned short :0; unsigned short v2:8; };
struct Us_BFu0s_BFu9i { unsigned short v1; unsigned short :0; unsigned int v2:9; };
struct Us_BFu0s_BFu9ll { unsigned short v1; unsigned short :0; unsigned long long v2:9; };
struct Us_BFu0s_BFu9s { unsigned short v1; unsigned short :0; unsigned short v2:9; };
struct Us_BFu0s_C { unsigned short v1; unsigned short :0; char v2; };
struct Us_BFu0s_D { unsigned short v1; unsigned short :0; double v2; };
struct Us_BFu0s_F { unsigned short v1; unsigned short :0; float v2; };
struct Us_BFu0s_I { unsigned short v1; unsigned short :0; int v2; };
struct Us_BFu0s_Ip { unsigned short v1; unsigned short :0; int * v2; };
struct Us_BFu0s_L { unsigned short v1; unsigned short :0; long long v2; };
struct Us_BFu0s_S { unsigned short v1; unsigned short :0; short v2; };
struct Us_BFu0s_Uc { unsigned short v1; unsigned short :0; unsigned char v2; };
struct Us_BFu0s_Ui { unsigned short v1; unsigned short :0; unsigned int v2; };
struct Us_BFu0s_Ul { unsigned short v1; unsigned short :0; unsigned long long v2; };
struct Us_BFu0s_Us { unsigned short v1; unsigned short :0; unsigned short v2; };
struct Us_BFu0s_Vp { unsigned short v1; unsigned short :0; void * v2; };
struct Us_BFu15i_BFu0c { unsigned short v1; unsigned int v2:15; unsigned char :0; };
struct Us_BFu15i_BFu0i { unsigned short v1; unsigned int v2:15; unsigned int :0; };
struct Us_BFu15i_BFu0ll { unsigned short v1; unsigned int v2:15; unsigned long long :0; };
struct Us_BFu15i_BFu0s { unsigned short v1; unsigned int v2:15; unsigned short :0; };
struct Us_BFu15ll_BFu0c { unsigned short v1; unsigned long long v2:15; unsigned char :0; };
struct Us_BFu15ll_BFu0i { unsigned short v1; unsigned long long v2:15; unsigned int :0; };
struct Us_BFu15ll_BFu0ll { unsigned short v1; unsigned long long v2:15; unsigned long long :0; };
struct Us_BFu15ll_BFu0s { unsigned short v1; unsigned long long v2:15; unsigned short :0; };
struct Us_BFu15s_BFu0c { unsigned short v1; unsigned short v2:15; unsigned char :0; };
struct Us_BFu15s_BFu0i { unsigned short v1; unsigned short v2:15; unsigned int :0; };
struct Us_BFu15s_BFu0ll { unsigned short v1; unsigned short v2:15; unsigned long long :0; };
struct Us_BFu15s_BFu0s { unsigned short v1; unsigned short v2:15; unsigned short :0; };
struct Us_BFu16i_BFu0c { unsigned short v1; unsigned int v2:16; unsigned char :0; };
struct Us_BFu16i_BFu0i { unsigned short v1; unsigned int v2:16; unsigned int :0; };
struct Us_BFu16i_BFu0ll { unsigned short v1; unsigned int v2:16; unsigned long long :0; };
struct Us_BFu16i_BFu0s { unsigned short v1; unsigned int v2:16; unsigned short :0; };
struct Us_BFu16ll_BFu0c { unsigned short v1; unsigned long long v2:16; unsigned char :0; };
struct Us_BFu16ll_BFu0i { unsigned short v1; unsigned long long v2:16; unsigned int :0; };
struct Us_BFu16ll_BFu0ll { unsigned short v1; unsigned long long v2:16; unsigned long long :0; };
struct Us_BFu16ll_BFu0s { unsigned short v1; unsigned long long v2:16; unsigned short :0; };
struct Us_BFu16s_BFu0c { unsigned short v1; unsigned short v2:16; unsigned char :0; };
struct Us_BFu16s_BFu0i { unsigned short v1; unsigned short v2:16; unsigned int :0; };
struct Us_BFu16s_BFu0ll { unsigned short v1; unsigned short v2:16; unsigned long long :0; };
struct Us_BFu16s_BFu0s { unsigned short v1; unsigned short v2:16; unsigned short :0; };
struct Us_BFu17i_BFu0c { unsigned short v1; unsigned int v2:17; unsigned char :0; };
struct Us_BFu17i_BFu0i { unsigned short v1; unsigned int v2:17; unsigned int :0; };
struct Us_BFu17i_BFu0ll { unsigned short v1; unsigned int v2:17; unsigned long long :0; };
struct Us_BFu17i_BFu0s { unsigned short v1; unsigned int v2:17; unsigned short :0; };
struct Us_BFu17ll_BFu0c { unsigned short v1; unsigned long long v2:17; unsigned char :0; };
struct Us_BFu17ll_BFu0i { unsigned short v1; unsigned long long v2:17; unsigned int :0; };
struct Us_BFu17ll_BFu0ll { unsigned short v1; unsigned long long v2:17; unsigned long long :0; };
struct Us_BFu17ll_BFu0s { unsigned short v1; unsigned long long v2:17; unsigned short :0; };
struct Us_BFu1c_BFu0c { unsigned short v1; unsigned char v2:1; unsigned char :0; };
struct Us_BFu1c_BFu0i { unsigned short v1; unsigned char v2:1; unsigned int :0; };
struct Us_BFu1c_BFu0ll { unsigned short v1; unsigned char v2:1; unsigned long long :0; };
struct Us_BFu1c_BFu0s { unsigned short v1; unsigned char v2:1; unsigned short :0; };
struct Us_BFu1i_BFu0c { unsigned short v1; unsigned int v2:1; unsigned char :0; };
struct Us_BFu1i_BFu0i { unsigned short v1; unsigned int v2:1; unsigned int :0; };
struct Us_BFu1i_BFu0ll { unsigned short v1; unsigned int v2:1; unsigned long long :0; };
struct Us_BFu1i_BFu0s { unsigned short v1; unsigned int v2:1; unsigned short :0; };
struct Us_BFu1ll_BFu0c { unsigned short v1; unsigned long long v2:1; unsigned char :0; };
struct Us_BFu1ll_BFu0i { unsigned short v1; unsigned long long v2:1; unsigned int :0; };
struct Us_BFu1ll_BFu0ll { unsigned short v1; unsigned long long v2:1; unsigned long long :0; };
struct Us_BFu1ll_BFu0s { unsigned short v1; unsigned long long v2:1; unsigned short :0; };
struct Us_BFu1s_BFu0c { unsigned short v1; unsigned short v2:1; unsigned char :0; };
struct Us_BFu1s_BFu0i { unsigned short v1; unsigned short v2:1; unsigned int :0; };
struct Us_BFu1s_BFu0ll { unsigned short v1; unsigned short v2:1; unsigned long long :0; };
struct Us_BFu1s_BFu0s { unsigned short v1; unsigned short v2:1; unsigned short :0; };
struct Us_BFu31i_BFu0c { unsigned short v1; unsigned int v2:31; unsigned char :0; };
struct Us_BFu31i_BFu0i { unsigned short v1; unsigned int v2:31; unsigned int :0; };
struct Us_BFu31i_BFu0ll { unsigned short v1; unsigned int v2:31; unsigned long long :0; };
struct Us_BFu31i_BFu0s { unsigned short v1; unsigned int v2:31; unsigned short :0; };
struct Us_BFu31ll_BFu0c { unsigned short v1; unsigned long long v2:31; unsigned char :0; };
struct Us_BFu31ll_BFu0i { unsigned short v1; unsigned long long v2:31; unsigned int :0; };
struct Us_BFu31ll_BFu0ll { unsigned short v1; unsigned long long v2:31; unsigned long long :0; };
struct Us_BFu31ll_BFu0s { unsigned short v1; unsigned long long v2:31; unsigned short :0; };
struct Us_BFu32i_BFu0c { unsigned short v1; unsigned int v2:32; unsigned char :0; };
struct Us_BFu32i_BFu0i { unsigned short v1; unsigned int v2:32; unsigned int :0; };
struct Us_BFu32i_BFu0ll { unsigned short v1; unsigned int v2:32; unsigned long long :0; };
struct Us_BFu32i_BFu0s { unsigned short v1; unsigned int v2:32; unsigned short :0; };
struct Us_BFu32ll_BFu0c { unsigned short v1; unsigned long long v2:32; unsigned char :0; };
struct Us_BFu32ll_BFu0i { unsigned short v1; unsigned long long v2:32; unsigned int :0; };
struct Us_BFu32ll_BFu0ll { unsigned short v1; unsigned long long v2:32; unsigned long long :0; };
struct Us_BFu32ll_BFu0s { unsigned short v1; unsigned long long v2:32; unsigned short :0; };
struct Us_BFu33_BFu0c { unsigned short v1; unsigned long long v2:33; unsigned char :0; };
struct Us_BFu33_BFu0i { unsigned short v1; unsigned long long v2:33; unsigned int :0; };
struct Us_BFu33_BFu0ll { unsigned short v1; unsigned long long v2:33; unsigned long long :0; };
struct Us_BFu33_BFu0s { unsigned short v1; unsigned long long v2:33; unsigned short :0; };
struct Us_BFu7c_BFu0c { unsigned short v1; unsigned char v2:7; unsigned char :0; };
struct Us_BFu7c_BFu0i { unsigned short v1; unsigned char v2:7; unsigned int :0; };
struct Us_BFu7c_BFu0ll { unsigned short v1; unsigned char v2:7; unsigned long long :0; };
struct Us_BFu7c_BFu0s { unsigned short v1; unsigned char v2:7; unsigned short :0; };
struct Us_BFu7i_BFu0c { unsigned short v1; unsigned int v2:7; unsigned char :0; };
struct Us_BFu7i_BFu0i { unsigned short v1; unsigned int v2:7; unsigned int :0; };
struct Us_BFu7i_BFu0ll { unsigned short v1; unsigned int v2:7; unsigned long long :0; };
struct Us_BFu7i_BFu0s { unsigned short v1; unsigned int v2:7; unsigned short :0; };
struct Us_BFu7ll_BFu0c { unsigned short v1; unsigned long long v2:7; unsigned char :0; };
struct Us_BFu7ll_BFu0i { unsigned short v1; unsigned long long v2:7; unsigned int :0; };
struct Us_BFu7ll_BFu0ll { unsigned short v1; unsigned long long v2:7; unsigned long long :0; };
struct Us_BFu7ll_BFu0s { unsigned short v1; unsigned long long v2:7; unsigned short :0; };
struct Us_BFu7s_BFu0c { unsigned short v1; unsigned short v2:7; unsigned char :0; };
struct Us_BFu7s_BFu0i { unsigned short v1; unsigned short v2:7; unsigned int :0; };
struct Us_BFu7s_BFu0ll { unsigned short v1; unsigned short v2:7; unsigned long long :0; };
struct Us_BFu7s_BFu0s { unsigned short v1; unsigned short v2:7; unsigned short :0; };
struct Us_BFu8c_BFu0c { unsigned short v1; unsigned char v2:8; unsigned char :0; };
struct Us_BFu8c_BFu0i { unsigned short v1; unsigned char v2:8; unsigned int :0; };
struct Us_BFu8c_BFu0ll { unsigned short v1; unsigned char v2:8; unsigned long long :0; };
struct Us_BFu8c_BFu0s { unsigned short v1; unsigned char v2:8; unsigned short :0; };
struct Us_BFu8i_BFu0c { unsigned short v1; unsigned int v2:8; unsigned char :0; };
struct Us_BFu8i_BFu0i { unsigned short v1; unsigned int v2:8; unsigned int :0; };
struct Us_BFu8i_BFu0ll { unsigned short v1; unsigned int v2:8; unsigned long long :0; };
struct Us_BFu8i_BFu0s { unsigned short v1; unsigned int v2:8; unsigned short :0; };
struct Us_BFu8ll_BFu0c { unsigned short v1; unsigned long long v2:8; unsigned char :0; };
struct Us_BFu8ll_BFu0i { unsigned short v1; unsigned long long v2:8; unsigned int :0; };
struct Us_BFu8ll_BFu0ll { unsigned short v1; unsigned long long v2:8; unsigned long long :0; };
struct Us_BFu8ll_BFu0s { unsigned short v1; unsigned long long v2:8; unsigned short :0; };
struct Us_BFu8s_BFu0c { unsigned short v1; unsigned short v2:8; unsigned char :0; };
struct Us_BFu8s_BFu0i { unsigned short v1; unsigned short v2:8; unsigned int :0; };
struct Us_BFu8s_BFu0ll { unsigned short v1; unsigned short v2:8; unsigned long long :0; };
struct Us_BFu8s_BFu0s { unsigned short v1; unsigned short v2:8; unsigned short :0; };
struct Us_BFu9i_BFu0c { unsigned short v1; unsigned int v2:9; unsigned char :0; };
struct Us_BFu9i_BFu0i { unsigned short v1; unsigned int v2:9; unsigned int :0; };
struct Us_BFu9i_BFu0ll { unsigned short v1; unsigned int v2:9; unsigned long long :0; };
struct Us_BFu9i_BFu0s { unsigned short v1; unsigned int v2:9; unsigned short :0; };
struct Us_BFu9ll_BFu0c { unsigned short v1; unsigned long long v2:9; unsigned char :0; };
struct Us_BFu9ll_BFu0i { unsigned short v1; unsigned long long v2:9; unsigned int :0; };
struct Us_BFu9ll_BFu0ll { unsigned short v1; unsigned long long v2:9; unsigned long long :0; };
struct Us_BFu9ll_BFu0s { unsigned short v1; unsigned long long v2:9; unsigned short :0; };
struct Us_BFu9s_BFu0c { unsigned short v1; unsigned short v2:9; unsigned char :0; };
struct Us_BFu9s_BFu0i { unsigned short v1; unsigned short v2:9; unsigned int :0; };
struct Us_BFu9s_BFu0ll { unsigned short v1; unsigned short v2:9; unsigned long long :0; };
struct Us_BFu9s_BFu0s { unsigned short v1; unsigned short v2:9; unsigned short :0; };
struct Us_C_BFu0c { unsigned short v1; char v2; unsigned char :0; };
struct Us_C_BFu0i { unsigned short v1; char v2; unsigned int :0; };
struct Us_C_BFu0ll { unsigned short v1; char v2; unsigned long long :0; };
struct Us_C_BFu0s { unsigned short v1; char v2; unsigned short :0; };
struct Us_D_BFu0c { unsigned short v1; double v2; unsigned char :0; };
struct Us_D_BFu0i { unsigned short v1; double v2; unsigned int :0; };
struct Us_D_BFu0ll { unsigned short v1; double v2; unsigned long long :0; };
struct Us_D_BFu0s { unsigned short v1; double v2; unsigned short :0; };
struct Us_F_BFu0c { unsigned short v1; float v2; unsigned char :0; };
struct Us_F_BFu0i { unsigned short v1; float v2; unsigned int :0; };
struct Us_F_BFu0ll { unsigned short v1; float v2; unsigned long long :0; };
struct Us_F_BFu0s { unsigned short v1; float v2; unsigned short :0; };
struct Us_I_BFu0c { unsigned short v1; int v2; unsigned char :0; };
struct Us_I_BFu0i { unsigned short v1; int v2; unsigned int :0; };
struct Us_I_BFu0ll { unsigned short v1; int v2; unsigned long long :0; };
struct Us_I_BFu0s { unsigned short v1; int v2; unsigned short :0; };
struct Us_Ip_BFu0c { unsigned short v1; int * v2; unsigned char :0; };
struct Us_Ip_BFu0i { unsigned short v1; int * v2; unsigned int :0; };
struct Us_Ip_BFu0ll { unsigned short v1; int * v2; unsigned long long :0; };
struct Us_Ip_BFu0s { unsigned short v1; int * v2; unsigned short :0; };
struct Us_L_BFu0c { unsigned short v1; long long v2; unsigned char :0; };
struct Us_L_BFu0i { unsigned short v1; long long v2; unsigned int :0; };
struct Us_L_BFu0ll { unsigned short v1; long long v2; unsigned long long :0; };
struct Us_L_BFu0s { unsigned short v1; long long v2; unsigned short :0; };
struct Us_S_BFu0c { unsigned short v1; short v2; unsigned char :0; };
struct Us_S_BFu0i { unsigned short v1; short v2; unsigned int :0; };
struct Us_S_BFu0ll { unsigned short v1; short v2; unsigned long long :0; };
struct Us_S_BFu0s { unsigned short v1; short v2; unsigned short :0; };
struct Us_Uc_BFu0c { unsigned short v1; unsigned char v2; unsigned char :0; };
struct Us_Uc_BFu0i { unsigned short v1; unsigned char v2; unsigned int :0; };
struct Us_Uc_BFu0ll { unsigned short v1; unsigned char v2; unsigned long long :0; };
struct Us_Uc_BFu0s { unsigned short v1; unsigned char v2; unsigned short :0; };
struct Us_Ui_BFu0c { unsigned short v1; unsigned int v2; unsigned char :0; };
struct Us_Ui_BFu0i { unsigned short v1; unsigned int v2; unsigned int :0; };
struct Us_Ui_BFu0ll { unsigned short v1; unsigned int v2; unsigned long long :0; };
struct Us_Ui_BFu0s { unsigned short v1; unsigned int v2; unsigned short :0; };
struct Us_Ul_BFu0c { unsigned short v1; unsigned long long v2; unsigned char :0; };
struct Us_Ul_BFu0i { unsigned short v1; unsigned long long v2; unsigned int :0; };
struct Us_Ul_BFu0ll { unsigned short v1; unsigned long long v2; unsigned long long :0; };
struct Us_Ul_BFu0s { unsigned short v1; unsigned long long v2; unsigned short :0; };
struct Us_Us_BFu0c { unsigned short v1; unsigned short v2; unsigned char :0; };
struct Us_Us_BFu0i { unsigned short v1; unsigned short v2; unsigned int :0; };
struct Us_Us_BFu0ll { unsigned short v1; unsigned short v2; unsigned long long :0; };
struct Us_Us_BFu0s { unsigned short v1; unsigned short v2; unsigned short :0; };
struct Us_Vp_BFu0c { unsigned short v1; void * v2; unsigned char :0; };
struct Us_Vp_BFu0i { unsigned short v1; void * v2; unsigned int :0; };
struct Us_Vp_BFu0ll { unsigned short v1; void * v2; unsigned long long :0; };
struct Us_Vp_BFu0s { unsigned short v1; void * v2; unsigned short :0; };
struct Vp_BFu0c { void * v1; unsigned char :0; };
struct Vp_BFu0c_BFu0c { void * v1; unsigned char :0; unsigned char :0; };
struct Vp_BFu0c_BFu0i { void * v1; unsigned char :0; unsigned int :0; };
struct Vp_BFu0c_BFu0ll { void * v1; unsigned char :0; unsigned long long :0; };
struct Vp_BFu0c_BFu0s { void * v1; unsigned char :0; unsigned short :0; };
struct Vp_BFu0c_BFu15i { void * v1; unsigned char :0; unsigned int v2:15; };
struct Vp_BFu0c_BFu15ll { void * v1; unsigned char :0; unsigned long long v2:15; };
struct Vp_BFu0c_BFu15s { void * v1; unsigned char :0; unsigned short v2:15; };
struct Vp_BFu0c_BFu16i { void * v1; unsigned char :0; unsigned int v2:16; };
struct Vp_BFu0c_BFu16ll { void * v1; unsigned char :0; unsigned long long v2:16; };
struct Vp_BFu0c_BFu16s { void * v1; unsigned char :0; unsigned short v2:16; };
struct Vp_BFu0c_BFu17i { void * v1; unsigned char :0; unsigned int v2:17; };
struct Vp_BFu0c_BFu17ll { void * v1; unsigned char :0; unsigned long long v2:17; };
struct Vp_BFu0c_BFu1c { void * v1; unsigned char :0; unsigned char v2:1; };
struct Vp_BFu0c_BFu1i { void * v1; unsigned char :0; unsigned int v2:1; };
struct Vp_BFu0c_BFu1ll { void * v1; unsigned char :0; unsigned long long v2:1; };
struct Vp_BFu0c_BFu1s { void * v1; unsigned char :0; unsigned short v2:1; };
struct Vp_BFu0c_BFu31i { void * v1; unsigned char :0; unsigned int v2:31; };
struct Vp_BFu0c_BFu31ll { void * v1; unsigned char :0; unsigned long long v2:31; };
struct Vp_BFu0c_BFu32i { void * v1; unsigned char :0; unsigned int v2:32; };
struct Vp_BFu0c_BFu32ll { void * v1; unsigned char :0; unsigned long long v2:32; };
struct Vp_BFu0c_BFu33 { void * v1; unsigned char :0; unsigned long long v2:33; };
struct Vp_BFu0c_BFu7c { void * v1; unsigned char :0; unsigned char v2:7; };
struct Vp_BFu0c_BFu7i { void * v1; unsigned char :0; unsigned int v2:7; };
struct Vp_BFu0c_BFu7ll { void * v1; unsigned char :0; unsigned long long v2:7; };
struct Vp_BFu0c_BFu7s { void * v1; unsigned char :0; unsigned short v2:7; };
struct Vp_BFu0c_BFu8c { void * v1; unsigned char :0; unsigned char v2:8; };
struct Vp_BFu0c_BFu8i { void * v1; unsigned char :0; unsigned int v2:8; };
struct Vp_BFu0c_BFu8ll { void * v1; unsigned char :0; unsigned long long v2:8; };
struct Vp_BFu0c_BFu8s { void * v1; unsigned char :0; unsigned short v2:8; };
struct Vp_BFu0c_BFu9i { void * v1; unsigned char :0; unsigned int v2:9; };
struct Vp_BFu0c_BFu9ll { void * v1; unsigned char :0; unsigned long long v2:9; };
struct Vp_BFu0c_BFu9s { void * v1; unsigned char :0; unsigned short v2:9; };
struct Vp_BFu0c_C { void * v1; unsigned char :0; char v2; };
struct Vp_BFu0c_D { void * v1; unsigned char :0; double v2; };
struct Vp_BFu0c_F { void * v1; unsigned char :0; float v2; };
struct Vp_BFu0c_I { void * v1; unsigned char :0; int v2; };
struct Vp_BFu0c_Ip { void * v1; unsigned char :0; int * v2; };
struct Vp_BFu0c_L { void * v1; unsigned char :0; long long v2; };
struct Vp_BFu0c_S { void * v1; unsigned char :0; short v2; };
struct Vp_BFu0c_Uc { void * v1; unsigned char :0; unsigned char v2; };
struct Vp_BFu0c_Ui { void * v1; unsigned char :0; unsigned int v2; };
struct Vp_BFu0c_Ul { void * v1; unsigned char :0; unsigned long long v2; };
struct Vp_BFu0c_Us { void * v1; unsigned char :0; unsigned short v2; };
struct Vp_BFu0c_Vp { void * v1; unsigned char :0; void * v2; };
struct Vp_BFu0i { void * v1; unsigned int :0; };
struct Vp_BFu0i_BFu0c { void * v1; unsigned int :0; unsigned char :0; };
struct Vp_BFu0i_BFu0i { void * v1; unsigned int :0; unsigned int :0; };
struct Vp_BFu0i_BFu0ll { void * v1; unsigned int :0; unsigned long long :0; };
struct Vp_BFu0i_BFu0s { void * v1; unsigned int :0; unsigned short :0; };
struct Vp_BFu0i_BFu15i { void * v1; unsigned int :0; unsigned int v2:15; };
struct Vp_BFu0i_BFu15ll { void * v1; unsigned int :0; unsigned long long v2:15; };
struct Vp_BFu0i_BFu15s { void * v1; unsigned int :0; unsigned short v2:15; };
struct Vp_BFu0i_BFu16i { void * v1; unsigned int :0; unsigned int v2:16; };
struct Vp_BFu0i_BFu16ll { void * v1; unsigned int :0; unsigned long long v2:16; };
struct Vp_BFu0i_BFu16s { void * v1; unsigned int :0; unsigned short v2:16; };
struct Vp_BFu0i_BFu17i { void * v1; unsigned int :0; unsigned int v2:17; };
struct Vp_BFu0i_BFu17ll { void * v1; unsigned int :0; unsigned long long v2:17; };
struct Vp_BFu0i_BFu1c { void * v1; unsigned int :0; unsigned char v2:1; };
struct Vp_BFu0i_BFu1i { void * v1; unsigned int :0; unsigned int v2:1; };
struct Vp_BFu0i_BFu1ll { void * v1; unsigned int :0; unsigned long long v2:1; };
struct Vp_BFu0i_BFu1s { void * v1; unsigned int :0; unsigned short v2:1; };
struct Vp_BFu0i_BFu31i { void * v1; unsigned int :0; unsigned int v2:31; };
struct Vp_BFu0i_BFu31ll { void * v1; unsigned int :0; unsigned long long v2:31; };
struct Vp_BFu0i_BFu32i { void * v1; unsigned int :0; unsigned int v2:32; };
struct Vp_BFu0i_BFu32ll { void * v1; unsigned int :0; unsigned long long v2:32; };
struct Vp_BFu0i_BFu33 { void * v1; unsigned int :0; unsigned long long v2:33; };
struct Vp_BFu0i_BFu7c { void * v1; unsigned int :0; unsigned char v2:7; };
struct Vp_BFu0i_BFu7i { void * v1; unsigned int :0; unsigned int v2:7; };
struct Vp_BFu0i_BFu7ll { void * v1; unsigned int :0; unsigned long long v2:7; };
struct Vp_BFu0i_BFu7s { void * v1; unsigned int :0; unsigned short v2:7; };
struct Vp_BFu0i_BFu8c { void * v1; unsigned int :0; unsigned char v2:8; };
struct Vp_BFu0i_BFu8i { void * v1; unsigned int :0; unsigned int v2:8; };
struct Vp_BFu0i_BFu8ll { void * v1; unsigned int :0; unsigned long long v2:8; };
struct Vp_BFu0i_BFu8s { void * v1; unsigned int :0; unsigned short v2:8; };
struct Vp_BFu0i_BFu9i { void * v1; unsigned int :0; unsigned int v2:9; };
struct Vp_BFu0i_BFu9ll { void * v1; unsigned int :0; unsigned long long v2:9; };
struct Vp_BFu0i_BFu9s { void * v1; unsigned int :0; unsigned short v2:9; };
struct Vp_BFu0i_C { void * v1; unsigned int :0; char v2; };
struct Vp_BFu0i_D { void * v1; unsigned int :0; double v2; };
struct Vp_BFu0i_F { void * v1; unsigned int :0; float v2; };
struct Vp_BFu0i_I { void * v1; unsigned int :0; int v2; };
struct Vp_BFu0i_Ip { void * v1; unsigned int :0; int * v2; };
struct Vp_BFu0i_L { void * v1; unsigned int :0; long long v2; };
struct Vp_BFu0i_S { void * v1; unsigned int :0; short v2; };
struct Vp_BFu0i_Uc { void * v1; unsigned int :0; unsigned char v2; };
struct Vp_BFu0i_Ui { void * v1; unsigned int :0; unsigned int v2; };
struct Vp_BFu0i_Ul { void * v1; unsigned int :0; unsigned long long v2; };
struct Vp_BFu0i_Us { void * v1; unsigned int :0; unsigned short v2; };
struct Vp_BFu0i_Vp { void * v1; unsigned int :0; void * v2; };
struct Vp_BFu0ll { void * v1; unsigned long long :0; };
struct Vp_BFu0ll_BFu0c { void * v1; unsigned long long :0; unsigned char :0; };
struct Vp_BFu0ll_BFu0i { void * v1; unsigned long long :0; unsigned int :0; };
struct Vp_BFu0ll_BFu0ll { void * v1; unsigned long long :0; unsigned long long :0; };
struct Vp_BFu0ll_BFu0s { void * v1; unsigned long long :0; unsigned short :0; };
struct Vp_BFu0ll_BFu15i { void * v1; unsigned long long :0; unsigned int v2:15; };
struct Vp_BFu0ll_BFu15ll { void * v1; unsigned long long :0; unsigned long long v2:15; };
struct Vp_BFu0ll_BFu15s { void * v1; unsigned long long :0; unsigned short v2:15; };
struct Vp_BFu0ll_BFu16i { void * v1; unsigned long long :0; unsigned int v2:16; };
struct Vp_BFu0ll_BFu16ll { void * v1; unsigned long long :0; unsigned long long v2:16; };
struct Vp_BFu0ll_BFu16s { void * v1; unsigned long long :0; unsigned short v2:16; };
struct Vp_BFu0ll_BFu17i { void * v1; unsigned long long :0; unsigned int v2:17; };
struct Vp_BFu0ll_BFu17ll { void * v1; unsigned long long :0; unsigned long long v2:17; };
struct Vp_BFu0ll_BFu1c { void * v1; unsigned long long :0; unsigned char v2:1; };
struct Vp_BFu0ll_BFu1i { void * v1; unsigned long long :0; unsigned int v2:1; };
struct Vp_BFu0ll_BFu1ll { void * v1; unsigned long long :0; unsigned long long v2:1; };
struct Vp_BFu0ll_BFu1s { void * v1; unsigned long long :0; unsigned short v2:1; };
struct Vp_BFu0ll_BFu31i { void * v1; unsigned long long :0; unsigned int v2:31; };
struct Vp_BFu0ll_BFu31ll { void * v1; unsigned long long :0; unsigned long long v2:31; };
struct Vp_BFu0ll_BFu32i { void * v1; unsigned long long :0; unsigned int v2:32; };
struct Vp_BFu0ll_BFu32ll { void * v1; unsigned long long :0; unsigned long long v2:32; };
struct Vp_BFu0ll_BFu33 { void * v1; unsigned long long :0; unsigned long long v2:33; };
struct Vp_BFu0ll_BFu7c { void * v1; unsigned long long :0; unsigned char v2:7; };
struct Vp_BFu0ll_BFu7i { void * v1; unsigned long long :0; unsigned int v2:7; };
struct Vp_BFu0ll_BFu7ll { void * v1; unsigned long long :0; unsigned long long v2:7; };
struct Vp_BFu0ll_BFu7s { void * v1; unsigned long long :0; unsigned short v2:7; };
struct Vp_BFu0ll_BFu8c { void * v1; unsigned long long :0; unsigned char v2:8; };
struct Vp_BFu0ll_BFu8i { void * v1; unsigned long long :0; unsigned int v2:8; };
struct Vp_BFu0ll_BFu8ll { void * v1; unsigned long long :0; unsigned long long v2:8; };
struct Vp_BFu0ll_BFu8s { void * v1; unsigned long long :0; unsigned short v2:8; };
struct Vp_BFu0ll_BFu9i { void * v1; unsigned long long :0; unsigned int v2:9; };
struct Vp_BFu0ll_BFu9ll { void * v1; unsigned long long :0; unsigned long long v2:9; };
struct Vp_BFu0ll_BFu9s { void * v1; unsigned long long :0; unsigned short v2:9; };
struct Vp_BFu0ll_C { void * v1; unsigned long long :0; char v2; };
struct Vp_BFu0ll_D { void * v1; unsigned long long :0; double v2; };
struct Vp_BFu0ll_F { void * v1; unsigned long long :0; float v2; };
struct Vp_BFu0ll_I { void * v1; unsigned long long :0; int v2; };
struct Vp_BFu0ll_Ip { void * v1; unsigned long long :0; int * v2; };
struct Vp_BFu0ll_L { void * v1; unsigned long long :0; long long v2; };
struct Vp_BFu0ll_S { void * v1; unsigned long long :0; short v2; };
struct Vp_BFu0ll_Uc { void * v1; unsigned long long :0; unsigned char v2; };
struct Vp_BFu0ll_Ui { void * v1; unsigned long long :0; unsigned int v2; };
struct Vp_BFu0ll_Ul { void * v1; unsigned long long :0; unsigned long long v2; };
struct Vp_BFu0ll_Us { void * v1; unsigned long long :0; unsigned short v2; };
struct Vp_BFu0ll_Vp { void * v1; unsigned long long :0; void * v2; };
struct Vp_BFu0s { void * v1; unsigned short :0; };
struct Vp_BFu0s_BFu0c { void * v1; unsigned short :0; unsigned char :0; };
struct Vp_BFu0s_BFu0i { void * v1; unsigned short :0; unsigned int :0; };
struct Vp_BFu0s_BFu0ll { void * v1; unsigned short :0; unsigned long long :0; };
struct Vp_BFu0s_BFu0s { void * v1; unsigned short :0; unsigned short :0; };
struct Vp_BFu0s_BFu15i { void * v1; unsigned short :0; unsigned int v2:15; };
struct Vp_BFu0s_BFu15ll { void * v1; unsigned short :0; unsigned long long v2:15; };
struct Vp_BFu0s_BFu15s { void * v1; unsigned short :0; unsigned short v2:15; };
struct Vp_BFu0s_BFu16i { void * v1; unsigned short :0; unsigned int v2:16; };
struct Vp_BFu0s_BFu16ll { void * v1; unsigned short :0; unsigned long long v2:16; };
struct Vp_BFu0s_BFu16s { void * v1; unsigned short :0; unsigned short v2:16; };
struct Vp_BFu0s_BFu17i { void * v1; unsigned short :0; unsigned int v2:17; };
struct Vp_BFu0s_BFu17ll { void * v1; unsigned short :0; unsigned long long v2:17; };
struct Vp_BFu0s_BFu1c { void * v1; unsigned short :0; unsigned char v2:1; };
struct Vp_BFu0s_BFu1i { void * v1; unsigned short :0; unsigned int v2:1; };
struct Vp_BFu0s_BFu1ll { void * v1; unsigned short :0; unsigned long long v2:1; };
struct Vp_BFu0s_BFu1s { void * v1; unsigned short :0; unsigned short v2:1; };
struct Vp_BFu0s_BFu31i { void * v1; unsigned short :0; unsigned int v2:31; };
struct Vp_BFu0s_BFu31ll { void * v1; unsigned short :0; unsigned long long v2:31; };
struct Vp_BFu0s_BFu32i { void * v1; unsigned short :0; unsigned int v2:32; };
struct Vp_BFu0s_BFu32ll { void * v1; unsigned short :0; unsigned long long v2:32; };
struct Vp_BFu0s_BFu33 { void * v1; unsigned short :0; unsigned long long v2:33; };
struct Vp_BFu0s_BFu7c { void * v1; unsigned short :0; unsigned char v2:7; };
struct Vp_BFu0s_BFu7i { void * v1; unsigned short :0; unsigned int v2:7; };
struct Vp_BFu0s_BFu7ll { void * v1; unsigned short :0; unsigned long long v2:7; };
struct Vp_BFu0s_BFu7s { void * v1; unsigned short :0; unsigned short v2:7; };
struct Vp_BFu0s_BFu8c { void * v1; unsigned short :0; unsigned char v2:8; };
struct Vp_BFu0s_BFu8i { void * v1; unsigned short :0; unsigned int v2:8; };
struct Vp_BFu0s_BFu8ll { void * v1; unsigned short :0; unsigned long long v2:8; };
struct Vp_BFu0s_BFu8s { void * v1; unsigned short :0; unsigned short v2:8; };
struct Vp_BFu0s_BFu9i { void * v1; unsigned short :0; unsigned int v2:9; };
struct Vp_BFu0s_BFu9ll { void * v1; unsigned short :0; unsigned long long v2:9; };
struct Vp_BFu0s_BFu9s { void * v1; unsigned short :0; unsigned short v2:9; };
struct Vp_BFu0s_C { void * v1; unsigned short :0; char v2; };
struct Vp_BFu0s_D { void * v1; unsigned short :0; double v2; };
struct Vp_BFu0s_F { void * v1; unsigned short :0; float v2; };
struct Vp_BFu0s_I { void * v1; unsigned short :0; int v2; };
struct Vp_BFu0s_Ip { void * v1; unsigned short :0; int * v2; };
struct Vp_BFu0s_L { void * v1; unsigned short :0; long long v2; };
struct Vp_BFu0s_S { void * v1; unsigned short :0; short v2; };
struct Vp_BFu0s_Uc { void * v1; unsigned short :0; unsigned char v2; };
struct Vp_BFu0s_Ui { void * v1; unsigned short :0; unsigned int v2; };
struct Vp_BFu0s_Ul { void * v1; unsigned short :0; unsigned long long v2; };
struct Vp_BFu0s_Us { void * v1; unsigned short :0; unsigned short v2; };
struct Vp_BFu0s_Vp { void * v1; unsigned short :0; void * v2; };
struct Vp_BFu15i_BFu0c { void * v1; unsigned int v2:15; unsigned char :0; };
struct Vp_BFu15i_BFu0i { void * v1; unsigned int v2:15; unsigned int :0; };
struct Vp_BFu15i_BFu0ll { void * v1; unsigned int v2:15; unsigned long long :0; };
struct Vp_BFu15i_BFu0s { void * v1; unsigned int v2:15; unsigned short :0; };
struct Vp_BFu15ll_BFu0c { void * v1; unsigned long long v2:15; unsigned char :0; };
struct Vp_BFu15ll_BFu0i { void * v1; unsigned long long v2:15; unsigned int :0; };
struct Vp_BFu15ll_BFu0ll { void * v1; unsigned long long v2:15; unsigned long long :0; };
struct Vp_BFu15ll_BFu0s { void * v1; unsigned long long v2:15; unsigned short :0; };
struct Vp_BFu15s_BFu0c { void * v1; unsigned short v2:15; unsigned char :0; };
struct Vp_BFu15s_BFu0i { void * v1; unsigned short v2:15; unsigned int :0; };
struct Vp_BFu15s_BFu0ll { void * v1; unsigned short v2:15; unsigned long long :0; };
struct Vp_BFu15s_BFu0s { void * v1; unsigned short v2:15; unsigned short :0; };
struct Vp_BFu16i_BFu0c { void * v1; unsigned int v2:16; unsigned char :0; };
struct Vp_BFu16i_BFu0i { void * v1; unsigned int v2:16; unsigned int :0; };
struct Vp_BFu16i_BFu0ll { void * v1; unsigned int v2:16; unsigned long long :0; };
struct Vp_BFu16i_BFu0s { void * v1; unsigned int v2:16; unsigned short :0; };
struct Vp_BFu16ll_BFu0c { void * v1; unsigned long long v2:16; unsigned char :0; };
struct Vp_BFu16ll_BFu0i { void * v1; unsigned long long v2:16; unsigned int :0; };
struct Vp_BFu16ll_BFu0ll { void * v1; unsigned long long v2:16; unsigned long long :0; };
struct Vp_BFu16ll_BFu0s { void * v1; unsigned long long v2:16; unsigned short :0; };
struct Vp_BFu16s_BFu0c { void * v1; unsigned short v2:16; unsigned char :0; };
struct Vp_BFu16s_BFu0i { void * v1; unsigned short v2:16; unsigned int :0; };
struct Vp_BFu16s_BFu0ll { void * v1; unsigned short v2:16; unsigned long long :0; };
struct Vp_BFu16s_BFu0s { void * v1; unsigned short v2:16; unsigned short :0; };
struct Vp_BFu17i_BFu0c { void * v1; unsigned int v2:17; unsigned char :0; };
struct Vp_BFu17i_BFu0i { void * v1; unsigned int v2:17; unsigned int :0; };
struct Vp_BFu17i_BFu0ll { void * v1; unsigned int v2:17; unsigned long long :0; };
struct Vp_BFu17i_BFu0s { void * v1; unsigned int v2:17; unsigned short :0; };
struct Vp_BFu17ll_BFu0c { void * v1; unsigned long long v2:17; unsigned char :0; };
struct Vp_BFu17ll_BFu0i { void * v1; unsigned long long v2:17; unsigned int :0; };
struct Vp_BFu17ll_BFu0ll { void * v1; unsigned long long v2:17; unsigned long long :0; };
struct Vp_BFu17ll_BFu0s { void * v1; unsigned long long v2:17; unsigned short :0; };
struct Vp_BFu1c_BFu0c { void * v1; unsigned char v2:1; unsigned char :0; };
struct Vp_BFu1c_BFu0i { void * v1; unsigned char v2:1; unsigned int :0; };
struct Vp_BFu1c_BFu0ll { void * v1; unsigned char v2:1; unsigned long long :0; };
struct Vp_BFu1c_BFu0s { void * v1; unsigned char v2:1; unsigned short :0; };
struct Vp_BFu1i_BFu0c { void * v1; unsigned int v2:1; unsigned char :0; };
struct Vp_BFu1i_BFu0i { void * v1; unsigned int v2:1; unsigned int :0; };
struct Vp_BFu1i_BFu0ll { void * v1; unsigned int v2:1; unsigned long long :0; };
struct Vp_BFu1i_BFu0s { void * v1; unsigned int v2:1; unsigned short :0; };
struct Vp_BFu1ll_BFu0c { void * v1; unsigned long long v2:1; unsigned char :0; };
struct Vp_BFu1ll_BFu0i { void * v1; unsigned long long v2:1; unsigned int :0; };
struct Vp_BFu1ll_BFu0ll { void * v1; unsigned long long v2:1; unsigned long long :0; };
struct Vp_BFu1ll_BFu0s { void * v1; unsigned long long v2:1; unsigned short :0; };
struct Vp_BFu1s_BFu0c { void * v1; unsigned short v2:1; unsigned char :0; };
struct Vp_BFu1s_BFu0i { void * v1; unsigned short v2:1; unsigned int :0; };
struct Vp_BFu1s_BFu0ll { void * v1; unsigned short v2:1; unsigned long long :0; };
struct Vp_BFu1s_BFu0s { void * v1; unsigned short v2:1; unsigned short :0; };
struct Vp_BFu31i_BFu0c { void * v1; unsigned int v2:31; unsigned char :0; };
struct Vp_BFu31i_BFu0i { void * v1; unsigned int v2:31; unsigned int :0; };
struct Vp_BFu31i_BFu0ll { void * v1; unsigned int v2:31; unsigned long long :0; };
struct Vp_BFu31i_BFu0s { void * v1; unsigned int v2:31; unsigned short :0; };
struct Vp_BFu31ll_BFu0c { void * v1; unsigned long long v2:31; unsigned char :0; };
struct Vp_BFu31ll_BFu0i { void * v1; unsigned long long v2:31; unsigned int :0; };
struct Vp_BFu31ll_BFu0ll { void * v1; unsigned long long v2:31; unsigned long long :0; };
struct Vp_BFu31ll_BFu0s { void * v1; unsigned long long v2:31; unsigned short :0; };
struct Vp_BFu32i_BFu0c { void * v1; unsigned int v2:32; unsigned char :0; };
struct Vp_BFu32i_BFu0i { void * v1; unsigned int v2:32; unsigned int :0; };
struct Vp_BFu32i_BFu0ll { void * v1; unsigned int v2:32; unsigned long long :0; };
struct Vp_BFu32i_BFu0s { void * v1; unsigned int v2:32; unsigned short :0; };
struct Vp_BFu32ll_BFu0c { void * v1; unsigned long long v2:32; unsigned char :0; };
struct Vp_BFu32ll_BFu0i { void * v1; unsigned long long v2:32; unsigned int :0; };
struct Vp_BFu32ll_BFu0ll { void * v1; unsigned long long v2:32; unsigned long long :0; };
struct Vp_BFu32ll_BFu0s { void * v1; unsigned long long v2:32; unsigned short :0; };
struct Vp_BFu33_BFu0c { void * v1; unsigned long long v2:33; unsigned char :0; };
struct Vp_BFu33_BFu0i { void * v1; unsigned long long v2:33; unsigned int :0; };
struct Vp_BFu33_BFu0ll { void * v1; unsigned long long v2:33; unsigned long long :0; };
struct Vp_BFu33_BFu0s { void * v1; unsigned long long v2:33; unsigned short :0; };
struct Vp_BFu7c_BFu0c { void * v1; unsigned char v2:7; unsigned char :0; };
struct Vp_BFu7c_BFu0i { void * v1; unsigned char v2:7; unsigned int :0; };
struct Vp_BFu7c_BFu0ll { void * v1; unsigned char v2:7; unsigned long long :0; };
struct Vp_BFu7c_BFu0s { void * v1; unsigned char v2:7; unsigned short :0; };
struct Vp_BFu7i_BFu0c { void * v1; unsigned int v2:7; unsigned char :0; };
struct Vp_BFu7i_BFu0i { void * v1; unsigned int v2:7; unsigned int :0; };
struct Vp_BFu7i_BFu0ll { void * v1; unsigned int v2:7; unsigned long long :0; };
struct Vp_BFu7i_BFu0s { void * v1; unsigned int v2:7; unsigned short :0; };
struct Vp_BFu7ll_BFu0c { void * v1; unsigned long long v2:7; unsigned char :0; };
struct Vp_BFu7ll_BFu0i { void * v1; unsigned long long v2:7; unsigned int :0; };
struct Vp_BFu7ll_BFu0ll { void * v1; unsigned long long v2:7; unsigned long long :0; };
struct Vp_BFu7ll_BFu0s { void * v1; unsigned long long v2:7; unsigned short :0; };
struct Vp_BFu7s_BFu0c { void * v1; unsigned short v2:7; unsigned char :0; };
struct Vp_BFu7s_BFu0i { void * v1; unsigned short v2:7; unsigned int :0; };
struct Vp_BFu7s_BFu0ll { void * v1; unsigned short v2:7; unsigned long long :0; };
struct Vp_BFu7s_BFu0s { void * v1; unsigned short v2:7; unsigned short :0; };
struct Vp_BFu8c_BFu0c { void * v1; unsigned char v2:8; unsigned char :0; };
struct Vp_BFu8c_BFu0i { void * v1; unsigned char v2:8; unsigned int :0; };
struct Vp_BFu8c_BFu0ll { void * v1; unsigned char v2:8; unsigned long long :0; };
struct Vp_BFu8c_BFu0s { void * v1; unsigned char v2:8; unsigned short :0; };
struct Vp_BFu8i_BFu0c { void * v1; unsigned int v2:8; unsigned char :0; };
struct Vp_BFu8i_BFu0i { void * v1; unsigned int v2:8; unsigned int :0; };
struct Vp_BFu8i_BFu0ll { void * v1; unsigned int v2:8; unsigned long long :0; };
struct Vp_BFu8i_BFu0s { void * v1; unsigned int v2:8; unsigned short :0; };
struct Vp_BFu8ll_BFu0c { void * v1; unsigned long long v2:8; unsigned char :0; };
struct Vp_BFu8ll_BFu0i { void * v1; unsigned long long v2:8; unsigned int :0; };
struct Vp_BFu8ll_BFu0ll { void * v1; unsigned long long v2:8; unsigned long long :0; };
struct Vp_BFu8ll_BFu0s { void * v1; unsigned long long v2:8; unsigned short :0; };
struct Vp_BFu8s_BFu0c { void * v1; unsigned short v2:8; unsigned char :0; };
struct Vp_BFu8s_BFu0i { void * v1; unsigned short v2:8; unsigned int :0; };
struct Vp_BFu8s_BFu0ll { void * v1; unsigned short v2:8; unsigned long long :0; };
struct Vp_BFu8s_BFu0s { void * v1; unsigned short v2:8; unsigned short :0; };
struct Vp_BFu9i_BFu0c { void * v1; unsigned int v2:9; unsigned char :0; };
struct Vp_BFu9i_BFu0i { void * v1; unsigned int v2:9; unsigned int :0; };
struct Vp_BFu9i_BFu0ll { void * v1; unsigned int v2:9; unsigned long long :0; };
struct Vp_BFu9i_BFu0s { void * v1; unsigned int v2:9; unsigned short :0; };
struct Vp_BFu9ll_BFu0c { void * v1; unsigned long long v2:9; unsigned char :0; };
struct Vp_BFu9ll_BFu0i { void * v1; unsigned long long v2:9; unsigned int :0; };
struct Vp_BFu9ll_BFu0ll { void * v1; unsigned long long v2:9; unsigned long long :0; };
struct Vp_BFu9ll_BFu0s { void * v1; unsigned long long v2:9; unsigned short :0; };
struct Vp_BFu9s_BFu0c { void * v1; unsigned short v2:9; unsigned char :0; };
struct Vp_BFu9s_BFu0i { void * v1; unsigned short v2:9; unsigned int :0; };
struct Vp_BFu9s_BFu0ll { void * v1; unsigned short v2:9; unsigned long long :0; };
struct Vp_BFu9s_BFu0s { void * v1; unsigned short v2:9; unsigned short :0; };
struct Vp_C_BFu0c { void * v1; char v2; unsigned char :0; };
struct Vp_C_BFu0i { void * v1; char v2; unsigned int :0; };
struct Vp_C_BFu0ll { void * v1; char v2; unsigned long long :0; };
struct Vp_C_BFu0s { void * v1; char v2; unsigned short :0; };
struct Vp_D_BFu0c { void * v1; double v2; unsigned char :0; };
struct Vp_D_BFu0i { void * v1; double v2; unsigned int :0; };
struct Vp_D_BFu0ll { void * v1; double v2; unsigned long long :0; };
struct Vp_D_BFu0s { void * v1; double v2; unsigned short :0; };
struct Vp_F_BFu0c { void * v1; float v2; unsigned char :0; };
struct Vp_F_BFu0i { void * v1; float v2; unsigned int :0; };
struct Vp_F_BFu0ll { void * v1; float v2; unsigned long long :0; };
struct Vp_F_BFu0s { void * v1; float v2; unsigned short :0; };
struct Vp_I_BFu0c { void * v1; int v2; unsigned char :0; };
struct Vp_I_BFu0i { void * v1; int v2; unsigned int :0; };
struct Vp_I_BFu0ll { void * v1; int v2; unsigned long long :0; };
struct Vp_I_BFu0s { void * v1; int v2; unsigned short :0; };
struct Vp_Ip_BFu0c { void * v1; int * v2; unsigned char :0; };
struct Vp_Ip_BFu0i { void * v1; int * v2; unsigned int :0; };
struct Vp_Ip_BFu0ll { void * v1; int * v2; unsigned long long :0; };
struct Vp_Ip_BFu0s { void * v1; int * v2; unsigned short :0; };
struct Vp_L_BFu0c { void * v1; long long v2; unsigned char :0; };
struct Vp_L_BFu0i { void * v1; long long v2; unsigned int :0; };
struct Vp_L_BFu0ll { void * v1; long long v2; unsigned long long :0; };
struct Vp_L_BFu0s { void * v1; long long v2; unsigned short :0; };
struct Vp_S_BFu0c { void * v1; short v2; unsigned char :0; };
struct Vp_S_BFu0i { void * v1; short v2; unsigned int :0; };
struct Vp_S_BFu0ll { void * v1; short v2; unsigned long long :0; };
struct Vp_S_BFu0s { void * v1; short v2; unsigned short :0; };
struct Vp_Uc_BFu0c { void * v1; unsigned char v2; unsigned char :0; };
struct Vp_Uc_BFu0i { void * v1; unsigned char v2; unsigned int :0; };
struct Vp_Uc_BFu0ll { void * v1; unsigned char v2; unsigned long long :0; };
struct Vp_Uc_BFu0s { void * v1; unsigned char v2; unsigned short :0; };
struct Vp_Ui_BFu0c { void * v1; unsigned int v2; unsigned char :0; };
struct Vp_Ui_BFu0i { void * v1; unsigned int v2; unsigned int :0; };
struct Vp_Ui_BFu0ll { void * v1; unsigned int v2; unsigned long long :0; };
struct Vp_Ui_BFu0s { void * v1; unsigned int v2; unsigned short :0; };
struct Vp_Ul_BFu0c { void * v1; unsigned long long v2; unsigned char :0; };
struct Vp_Ul_BFu0i { void * v1; unsigned long long v2; unsigned int :0; };
struct Vp_Ul_BFu0ll { void * v1; unsigned long long v2; unsigned long long :0; };
struct Vp_Ul_BFu0s { void * v1; unsigned long long v2; unsigned short :0; };
struct Vp_Us_BFu0c { void * v1; unsigned short v2; unsigned char :0; };
struct Vp_Us_BFu0i { void * v1; unsigned short v2; unsigned int :0; };
struct Vp_Us_BFu0ll { void * v1; unsigned short v2; unsigned long long :0; };
struct Vp_Us_BFu0s { void * v1; unsigned short v2; unsigned short :0; };
struct Vp_Vp_BFu0c { void * v1; void * v2; unsigned char :0; };
struct Vp_Vp_BFu0i { void * v1; void * v2; unsigned int :0; };
struct Vp_Vp_BFu0ll { void * v1; void * v2; unsigned long long :0; };
struct Vp_Vp_BFu0s { void * v1; void * v2; unsigned short :0; };
#endif // __cplusplus
#ifdef __cplusplus


static void Test_Ui_BFu0ll_L()
{
  {
    init_simple_test("Ui_BFu0ll_L");
    static Ui_BFu0ll_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ui_BFu0ll_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0ll_L)");
    check_field_offset(lv, v1, 0, "Ui_BFu0ll_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ui_BFu0ll_L.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0ll_L(Test_Ui_BFu0ll_L, "Ui_BFu0ll_L", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0ll_S()
{
  {
    init_simple_test("Ui_BFu0ll_S");
    static Ui_BFu0ll_S lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ui_BFu0ll_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0ll_S)");
    check_field_offset(lv, v1, 0, "Ui_BFu0ll_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ui_BFu0ll_S.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0ll_S(Test_Ui_BFu0ll_S, "Ui_BFu0ll_S", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0ll_Uc()
{
  {
    init_simple_test("Ui_BFu0ll_Uc");
    static Ui_BFu0ll_Uc lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Ui_BFu0ll_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0ll_Uc)");
    check_field_offset(lv, v1, 0, "Ui_BFu0ll_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ui_BFu0ll_Uc.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0ll_Uc(Test_Ui_BFu0ll_Uc, "Ui_BFu0ll_Uc", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0ll_Ui()
{
  {
    init_simple_test("Ui_BFu0ll_Ui");
    static Ui_BFu0ll_Ui lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_BFu0ll_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0ll_Ui)");
    check_field_offset(lv, v1, 0, "Ui_BFu0ll_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ui_BFu0ll_Ui.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0ll_Ui(Test_Ui_BFu0ll_Ui, "Ui_BFu0ll_Ui", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0ll_Ul()
{
  {
    init_simple_test("Ui_BFu0ll_Ul");
    static Ui_BFu0ll_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ui_BFu0ll_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0ll_Ul)");
    check_field_offset(lv, v1, 0, "Ui_BFu0ll_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ui_BFu0ll_Ul.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0ll_Ul(Test_Ui_BFu0ll_Ul, "Ui_BFu0ll_Ul", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0ll_Us()
{
  {
    init_simple_test("Ui_BFu0ll_Us");
    static Ui_BFu0ll_Us lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ui_BFu0ll_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0ll_Us)");
    check_field_offset(lv, v1, 0, "Ui_BFu0ll_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ui_BFu0ll_Us.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0ll_Us(Test_Ui_BFu0ll_Us, "Ui_BFu0ll_Us", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0ll_Vp()
{
  {
    init_simple_test("Ui_BFu0ll_Vp");
    static Ui_BFu0ll_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Ui_BFu0ll_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0ll_Vp)");
    check_field_offset(lv, v1, 0, "Ui_BFu0ll_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ui_BFu0ll_Vp.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0ll_Vp(Test_Ui_BFu0ll_Vp, "Ui_BFu0ll_Vp", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s()
{
  {
    init_simple_test("Ui_BFu0s");
    static Ui_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Ui_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vUi_BFu0s(Test_Ui_BFu0s, "Ui_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu0c()
{
  {
    init_simple_test("Ui_BFu0s_BFu0c");
    static Ui_BFu0s_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Ui_BFu0s_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu0c(Test_Ui_BFu0s_BFu0c, "Ui_BFu0s_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu0i()
{
  {
    init_simple_test("Ui_BFu0s_BFu0i");
    static Ui_BFu0s_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Ui_BFu0s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu0i(Test_Ui_BFu0s_BFu0i, "Ui_BFu0s_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu0ll()
{
  {
    init_simple_test("Ui_BFu0s_BFu0ll");
    static Ui_BFu0s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Ui_BFu0s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu0ll(Test_Ui_BFu0s_BFu0ll, "Ui_BFu0s_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu0s()
{
  {
    init_simple_test("Ui_BFu0s_BFu0s");
    static Ui_BFu0s_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Ui_BFu0s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu0s(Test_Ui_BFu0s_BFu0s, "Ui_BFu0s_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu15i()
{
  {
    init_simple_test("Ui_BFu0s_BFu15i");
    static Ui_BFu0s_BFu15i lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_BFu15i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu15i)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu15i.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu0s_BFu15i");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu0s_BFu15i");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu15i(Test_Ui_BFu0s_BFu15i, "Ui_BFu0s_BFu15i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu15ll()
{
  {
    init_simple_test("Ui_BFu0s_BFu15ll");
    static Ui_BFu0s_BFu15ll lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu15ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu15ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu0s_BFu15ll");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu0s_BFu15ll");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu15ll(Test_Ui_BFu0s_BFu15ll, "Ui_BFu0s_BFu15ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu15s()
{
  {
    init_simple_test("Ui_BFu0s_BFu15s");
    static Ui_BFu0s_BFu15s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_BFu15s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu15s)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu15s.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu0s_BFu15s");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu0s_BFu15s");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu15s(Test_Ui_BFu0s_BFu15s, "Ui_BFu0s_BFu15s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu16i()
{
  {
    init_simple_test("Ui_BFu0s_BFu16i");
    static Ui_BFu0s_BFu16i lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_BFu16i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu16i)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu16i.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu0s_BFu16i");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu0s_BFu16i");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu16i(Test_Ui_BFu0s_BFu16i, "Ui_BFu0s_BFu16i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu16ll()
{
  {
    init_simple_test("Ui_BFu0s_BFu16ll");
    static Ui_BFu0s_BFu16ll lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu16ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu16ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu0s_BFu16ll");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu0s_BFu16ll");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu16ll(Test_Ui_BFu0s_BFu16ll, "Ui_BFu0s_BFu16ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu16s()
{
  {
    init_simple_test("Ui_BFu0s_BFu16s");
    static Ui_BFu0s_BFu16s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_BFu16s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu16s)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu16s.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu0s_BFu16s");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu0s_BFu16s");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu16s(Test_Ui_BFu0s_BFu16s, "Ui_BFu0s_BFu16s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu17i()
{
  {
    init_simple_test("Ui_BFu0s_BFu17i");
    static Ui_BFu0s_BFu17i lv;
    check2(sizeof(lv), ABISELECT(7,7), "sizeof(Ui_BFu0s_BFu17i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu17i)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu17i.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu0s_BFu17i");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu0s_BFu17i");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu17i(Test_Ui_BFu0s_BFu17i, "Ui_BFu0s_BFu17i", ABISELECT(7,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu17ll()
{
  {
    init_simple_test("Ui_BFu0s_BFu17ll");
    static Ui_BFu0s_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(7,7), "sizeof(Ui_BFu0s_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu17ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu17ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu0s_BFu17ll");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu0s_BFu17ll");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu17ll(Test_Ui_BFu0s_BFu17ll, "Ui_BFu0s_BFu17ll", ABISELECT(7,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu1c()
{
  {
    init_simple_test("Ui_BFu0s_BFu1c");
    static Ui_BFu0s_BFu1c lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu1c)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu1c.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu0s_BFu1c");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu1c(Test_Ui_BFu0s_BFu1c, "Ui_BFu0s_BFu1c", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu1i()
{
  {
    init_simple_test("Ui_BFu0s_BFu1i");
    static Ui_BFu0s_BFu1i lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu1i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu1i)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu1i.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu0s_BFu1i");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu1i(Test_Ui_BFu0s_BFu1i, "Ui_BFu0s_BFu1i", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu1ll()
{
  {
    init_simple_test("Ui_BFu0s_BFu1ll");
    static Ui_BFu0s_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu1ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu1ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu0s_BFu1ll");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu1ll(Test_Ui_BFu0s_BFu1ll, "Ui_BFu0s_BFu1ll", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu1s()
{
  {
    init_simple_test("Ui_BFu0s_BFu1s");
    static Ui_BFu0s_BFu1s lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu1s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu1s)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu1s.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu0s_BFu1s");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu1s(Test_Ui_BFu0s_BFu1s, "Ui_BFu0s_BFu1s", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu31i()
{
  {
    init_simple_test("Ui_BFu0s_BFu31i");
    static Ui_BFu0s_BFu31i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu0s_BFu31i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu31i)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu31i.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu0s_BFu31i");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu0s_BFu31i");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu31i(Test_Ui_BFu0s_BFu31i, "Ui_BFu0s_BFu31i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu31ll()
{
  {
    init_simple_test("Ui_BFu0s_BFu31ll");
    static Ui_BFu0s_BFu31ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu0s_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu31ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu31ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu0s_BFu31ll");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu0s_BFu31ll");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu31ll(Test_Ui_BFu0s_BFu31ll, "Ui_BFu0s_BFu31ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu32i()
{
  {
    init_simple_test("Ui_BFu0s_BFu32i");
    static Ui_BFu0s_BFu32i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu0s_BFu32i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu32i)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu32i.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu0s_BFu32i");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu0s_BFu32i");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu32i(Test_Ui_BFu0s_BFu32i, "Ui_BFu0s_BFu32i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu32ll()
{
  {
    init_simple_test("Ui_BFu0s_BFu32ll");
    static Ui_BFu0s_BFu32ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu0s_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu32ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu32ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu0s_BFu32ll");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu0s_BFu32ll");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu32ll(Test_Ui_BFu0s_BFu32ll, "Ui_BFu0s_BFu32ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu33()
{
  {
    init_simple_test("Ui_BFu0s_BFu33");
    static Ui_BFu0s_BFu33 lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ui_BFu0s_BFu33)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu33)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu33.v1");
    set_bf_and_test(lv, v2, 4, 0, 33, 1, "Ui_BFu0s_BFu33");
    set_bf_and_test(lv, v2, 4, 0, 33, hide_ull(1LL<<32), "Ui_BFu0s_BFu33");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu33(Test_Ui_BFu0s_BFu33, "Ui_BFu0s_BFu33", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu7c()
{
  {
    init_simple_test("Ui_BFu0s_BFu7c");
    static Ui_BFu0s_BFu7c lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu7c)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu7c.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu0s_BFu7c");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu0s_BFu7c");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu7c(Test_Ui_BFu0s_BFu7c, "Ui_BFu0s_BFu7c", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu7i()
{
  {
    init_simple_test("Ui_BFu0s_BFu7i");
    static Ui_BFu0s_BFu7i lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu7i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu7i)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu7i.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu0s_BFu7i");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu0s_BFu7i");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu7i(Test_Ui_BFu0s_BFu7i, "Ui_BFu0s_BFu7i", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu7ll()
{
  {
    init_simple_test("Ui_BFu0s_BFu7ll");
    static Ui_BFu0s_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu7ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu7ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu0s_BFu7ll");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu0s_BFu7ll");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu7ll(Test_Ui_BFu0s_BFu7ll, "Ui_BFu0s_BFu7ll", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu7s()
{
  {
    init_simple_test("Ui_BFu0s_BFu7s");
    static Ui_BFu0s_BFu7s lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu7s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu7s)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu7s.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu0s_BFu7s");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu0s_BFu7s");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu7s(Test_Ui_BFu0s_BFu7s, "Ui_BFu0s_BFu7s", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu8c()
{
  {
    init_simple_test("Ui_BFu0s_BFu8c");
    static Ui_BFu0s_BFu8c lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu8c)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu8c.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu0s_BFu8c");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu0s_BFu8c");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu8c(Test_Ui_BFu0s_BFu8c, "Ui_BFu0s_BFu8c", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu8i()
{
  {
    init_simple_test("Ui_BFu0s_BFu8i");
    static Ui_BFu0s_BFu8i lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu8i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu8i)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu8i.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu0s_BFu8i");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu0s_BFu8i");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu8i(Test_Ui_BFu0s_BFu8i, "Ui_BFu0s_BFu8i", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu8ll()
{
  {
    init_simple_test("Ui_BFu0s_BFu8ll");
    static Ui_BFu0s_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu8ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu8ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu0s_BFu8ll");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu0s_BFu8ll");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu8ll(Test_Ui_BFu0s_BFu8ll, "Ui_BFu0s_BFu8ll", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu8s()
{
  {
    init_simple_test("Ui_BFu0s_BFu8s");
    static Ui_BFu0s_BFu8s lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu8s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu8s)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu8s.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu0s_BFu8s");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu0s_BFu8s");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu8s(Test_Ui_BFu0s_BFu8s, "Ui_BFu0s_BFu8s", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu9i()
{
  {
    init_simple_test("Ui_BFu0s_BFu9i");
    static Ui_BFu0s_BFu9i lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_BFu9i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu9i)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu9i.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu0s_BFu9i");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu0s_BFu9i");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu9i(Test_Ui_BFu0s_BFu9i, "Ui_BFu0s_BFu9i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu9ll()
{
  {
    init_simple_test("Ui_BFu0s_BFu9ll");
    static Ui_BFu0s_BFu9ll lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu9ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu9ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu0s_BFu9ll");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu0s_BFu9ll");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu9ll(Test_Ui_BFu0s_BFu9ll, "Ui_BFu0s_BFu9ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_BFu9s()
{
  {
    init_simple_test("Ui_BFu0s_BFu9s");
    static Ui_BFu0s_BFu9s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_BFu9s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu9s)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu9s.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu0s_BFu9s");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu0s_BFu9s");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_BFu9s(Test_Ui_BFu0s_BFu9s, "Ui_BFu0s_BFu9s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_C()
{
  {
    init_simple_test("Ui_BFu0s_C");
    static Ui_BFu0s_C lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_C)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_C.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_C.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_C(Test_Ui_BFu0s_C, "Ui_BFu0s_C", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_D()
{
  {
    init_simple_test("Ui_BFu0s_D");
    static Ui_BFu0s_D lv;
    check2(sizeof(lv), 12, "sizeof(Ui_BFu0s_D)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_D)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_D.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_D.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_D(Test_Ui_BFu0s_D, "Ui_BFu0s_D", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_F()
{
  {
    init_simple_test("Ui_BFu0s_F");
    static Ui_BFu0s_F lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu0s_F)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_F)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_F.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_F.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_F(Test_Ui_BFu0s_F, "Ui_BFu0s_F", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_I()
{
  {
    init_simple_test("Ui_BFu0s_I");
    static Ui_BFu0s_I lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu0s_I)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_I)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_I.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_I.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_I(Test_Ui_BFu0s_I, "Ui_BFu0s_I", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_Ip()
{
  {
    init_simple_test("Ui_BFu0s_Ip");
    static Ui_BFu0s_Ip lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_BFu0s_Ip)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_Ip)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_Ip.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_Ip.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_Ip(Test_Ui_BFu0s_Ip, "Ui_BFu0s_Ip", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_L()
{
  {
    init_simple_test("Ui_BFu0s_L");
    static Ui_BFu0s_L lv;
    check2(sizeof(lv), 12, "sizeof(Ui_BFu0s_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_L)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_L.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_L.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_L(Test_Ui_BFu0s_L, "Ui_BFu0s_L", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_S()
{
  {
    init_simple_test("Ui_BFu0s_S");
    static Ui_BFu0s_S lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_S)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_S.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_S.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_S(Test_Ui_BFu0s_S, "Ui_BFu0s_S", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_Uc()
{
  {
    init_simple_test("Ui_BFu0s_Uc");
    static Ui_BFu0s_Uc lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_Uc)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_Uc.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_Uc.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_Uc(Test_Ui_BFu0s_Uc, "Ui_BFu0s_Uc", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_Ui()
{
  {
    init_simple_test("Ui_BFu0s_Ui");
    static Ui_BFu0s_Ui lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu0s_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_Ui)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_Ui.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_Ui.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_Ui(Test_Ui_BFu0s_Ui, "Ui_BFu0s_Ui", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_Ul()
{
  {
    init_simple_test("Ui_BFu0s_Ul");
    static Ui_BFu0s_Ul lv;
    check2(sizeof(lv), 12, "sizeof(Ui_BFu0s_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_Ul)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_Ul.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_Ul.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_Ul(Test_Ui_BFu0s_Ul, "Ui_BFu0s_Ul", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_Us()
{
  {
    init_simple_test("Ui_BFu0s_Us");
    static Ui_BFu0s_Us lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_Us)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_Us.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_Us.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_Us(Test_Ui_BFu0s_Us, "Ui_BFu0s_Us", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu0s_Vp()
{
  {
    init_simple_test("Ui_BFu0s_Vp");
    static Ui_BFu0s_Vp lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_BFu0s_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_Vp)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_Vp.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_Vp.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_Vp(Test_Ui_BFu0s_Vp, "Ui_BFu0s_Vp", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu15i_BFu0c()
{
  {
    init_simple_test("Ui_BFu15i_BFu0c");
    static Ui_BFu15i_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu15i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu15i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu15i_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15i_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15i_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu15i_BFu0c(Test_Ui_BFu15i_BFu0c, "Ui_BFu15i_BFu0c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu15i_BFu0i()
{
  {
    init_simple_test("Ui_BFu15i_BFu0i");
    static Ui_BFu15i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu15i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu15i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu15i_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15i_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15i_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu15i_BFu0i(Test_Ui_BFu15i_BFu0i, "Ui_BFu15i_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu15i_BFu0ll()
{
  {
    init_simple_test("Ui_BFu15i_BFu0ll");
    static Ui_BFu15i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu15i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu15i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu15i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15i_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu15i_BFu0ll(Test_Ui_BFu15i_BFu0ll, "Ui_BFu15i_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu15i_BFu0s()
{
  {
    init_simple_test("Ui_BFu15i_BFu0s");
    static Ui_BFu15i_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu15i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu15i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu15i_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15i_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15i_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu15i_BFu0s(Test_Ui_BFu15i_BFu0s, "Ui_BFu15i_BFu0s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu15ll_BFu0c()
{
  {
    init_simple_test("Ui_BFu15ll_BFu0c");
    static Ui_BFu15ll_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu15ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu15ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu15ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15ll_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu15ll_BFu0c(Test_Ui_BFu15ll_BFu0c, "Ui_BFu15ll_BFu0c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu15ll_BFu0i()
{
  {
    init_simple_test("Ui_BFu15ll_BFu0i");
    static Ui_BFu15ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu15ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu15ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu15ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15ll_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu15ll_BFu0i(Test_Ui_BFu15ll_BFu0i, "Ui_BFu15ll_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu15ll_BFu0ll()
{
  {
    init_simple_test("Ui_BFu15ll_BFu0ll");
    static Ui_BFu15ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu15ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu15ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu15ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15ll_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu15ll_BFu0ll(Test_Ui_BFu15ll_BFu0ll, "Ui_BFu15ll_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu15ll_BFu0s()
{
  {
    init_simple_test("Ui_BFu15ll_BFu0s");
    static Ui_BFu15ll_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu15ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu15ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu15ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15ll_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu15ll_BFu0s(Test_Ui_BFu15ll_BFu0s, "Ui_BFu15ll_BFu0s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu15s_BFu0c()
{
  {
    init_simple_test("Ui_BFu15s_BFu0c");
    static Ui_BFu15s_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu15s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu15s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu15s_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15s_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15s_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu15s_BFu0c(Test_Ui_BFu15s_BFu0c, "Ui_BFu15s_BFu0c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu15s_BFu0i()
{
  {
    init_simple_test("Ui_BFu15s_BFu0i");
    static Ui_BFu15s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu15s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu15s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu15s_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15s_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15s_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu15s_BFu0i(Test_Ui_BFu15s_BFu0i, "Ui_BFu15s_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu15s_BFu0ll()
{
  {
    init_simple_test("Ui_BFu15s_BFu0ll");
    static Ui_BFu15s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu15s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu15s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu15s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15s_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15s_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu15s_BFu0ll(Test_Ui_BFu15s_BFu0ll, "Ui_BFu15s_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu15s_BFu0s()
{
  {
    init_simple_test("Ui_BFu15s_BFu0s");
    static Ui_BFu15s_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu15s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu15s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu15s_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15s_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15s_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu15s_BFu0s(Test_Ui_BFu15s_BFu0s, "Ui_BFu15s_BFu0s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu16i_BFu0c()
{
  {
    init_simple_test("Ui_BFu16i_BFu0c");
    static Ui_BFu16i_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu16i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu16i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu16i_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16i_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16i_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu16i_BFu0c(Test_Ui_BFu16i_BFu0c, "Ui_BFu16i_BFu0c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu16i_BFu0i()
{
  {
    init_simple_test("Ui_BFu16i_BFu0i");
    static Ui_BFu16i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu16i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu16i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu16i_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16i_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16i_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu16i_BFu0i(Test_Ui_BFu16i_BFu0i, "Ui_BFu16i_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu16i_BFu0ll()
{
  {
    init_simple_test("Ui_BFu16i_BFu0ll");
    static Ui_BFu16i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu16i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu16i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu16i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16i_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu16i_BFu0ll(Test_Ui_BFu16i_BFu0ll, "Ui_BFu16i_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu16i_BFu0s()
{
  {
    init_simple_test("Ui_BFu16i_BFu0s");
    static Ui_BFu16i_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu16i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu16i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu16i_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16i_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16i_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu16i_BFu0s(Test_Ui_BFu16i_BFu0s, "Ui_BFu16i_BFu0s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu16ll_BFu0c()
{
  {
    init_simple_test("Ui_BFu16ll_BFu0c");
    static Ui_BFu16ll_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu16ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu16ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu16ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16ll_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu16ll_BFu0c(Test_Ui_BFu16ll_BFu0c, "Ui_BFu16ll_BFu0c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu16ll_BFu0i()
{
  {
    init_simple_test("Ui_BFu16ll_BFu0i");
    static Ui_BFu16ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu16ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu16ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu16ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16ll_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu16ll_BFu0i(Test_Ui_BFu16ll_BFu0i, "Ui_BFu16ll_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu16ll_BFu0ll()
{
  {
    init_simple_test("Ui_BFu16ll_BFu0ll");
    static Ui_BFu16ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu16ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu16ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu16ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16ll_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu16ll_BFu0ll(Test_Ui_BFu16ll_BFu0ll, "Ui_BFu16ll_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu16ll_BFu0s()
{
  {
    init_simple_test("Ui_BFu16ll_BFu0s");
    static Ui_BFu16ll_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu16ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu16ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu16ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16ll_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu16ll_BFu0s(Test_Ui_BFu16ll_BFu0s, "Ui_BFu16ll_BFu0s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu16s_BFu0c()
{
  {
    init_simple_test("Ui_BFu16s_BFu0c");
    static Ui_BFu16s_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu16s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu16s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu16s_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16s_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16s_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu16s_BFu0c(Test_Ui_BFu16s_BFu0c, "Ui_BFu16s_BFu0c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu16s_BFu0i()
{
  {
    init_simple_test("Ui_BFu16s_BFu0i");
    static Ui_BFu16s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu16s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu16s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu16s_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16s_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16s_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu16s_BFu0i(Test_Ui_BFu16s_BFu0i, "Ui_BFu16s_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu16s_BFu0ll()
{
  {
    init_simple_test("Ui_BFu16s_BFu0ll");
    static Ui_BFu16s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu16s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu16s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu16s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16s_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16s_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu16s_BFu0ll(Test_Ui_BFu16s_BFu0ll, "Ui_BFu16s_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu16s_BFu0s()
{
  {
    init_simple_test("Ui_BFu16s_BFu0s");
    static Ui_BFu16s_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu16s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu16s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu16s_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16s_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16s_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu16s_BFu0s(Test_Ui_BFu16s_BFu0s, "Ui_BFu16s_BFu0s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu17i_BFu0c()
{
  {
    init_simple_test("Ui_BFu17i_BFu0c");
    static Ui_BFu17i_BFu0c lv;
    check2(sizeof(lv), 7, "sizeof(Ui_BFu17i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu17i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu17i_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu17i_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu17i_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu17i_BFu0c(Test_Ui_BFu17i_BFu0c, "Ui_BFu17i_BFu0c", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu17i_BFu0i()
{
  {
    init_simple_test("Ui_BFu17i_BFu0i");
    static Ui_BFu17i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu17i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu17i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu17i_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu17i_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu17i_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu17i_BFu0i(Test_Ui_BFu17i_BFu0i, "Ui_BFu17i_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu17i_BFu0ll()
{
  {
    init_simple_test("Ui_BFu17i_BFu0ll");
    static Ui_BFu17i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu17i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu17i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu17i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu17i_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu17i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu17i_BFu0ll(Test_Ui_BFu17i_BFu0ll, "Ui_BFu17i_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu17i_BFu0s()
{
  {
    init_simple_test("Ui_BFu17i_BFu0s");
    static Ui_BFu17i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu17i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu17i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu17i_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu17i_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu17i_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu17i_BFu0s(Test_Ui_BFu17i_BFu0s, "Ui_BFu17i_BFu0s", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu17ll_BFu0c()
{
  {
    init_simple_test("Ui_BFu17ll_BFu0c");
    static Ui_BFu17ll_BFu0c lv;
    check2(sizeof(lv), 7, "sizeof(Ui_BFu17ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu17ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu17ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu17ll_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu17ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu17ll_BFu0c(Test_Ui_BFu17ll_BFu0c, "Ui_BFu17ll_BFu0c", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu17ll_BFu0i()
{
  {
    init_simple_test("Ui_BFu17ll_BFu0i");
    static Ui_BFu17ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu17ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu17ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu17ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu17ll_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu17ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu17ll_BFu0i(Test_Ui_BFu17ll_BFu0i, "Ui_BFu17ll_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu17ll_BFu0ll()
{
  {
    init_simple_test("Ui_BFu17ll_BFu0ll");
    static Ui_BFu17ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu17ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu17ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu17ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu17ll_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu17ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu17ll_BFu0ll(Test_Ui_BFu17ll_BFu0ll, "Ui_BFu17ll_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu17ll_BFu0s()
{
  {
    init_simple_test("Ui_BFu17ll_BFu0s");
    static Ui_BFu17ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu17ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu17ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu17ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu17ll_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu17ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu17ll_BFu0s(Test_Ui_BFu17ll_BFu0s, "Ui_BFu17ll_BFu0s", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu1c_BFu0c()
{
  {
    init_simple_test("Ui_BFu1c_BFu0c");
    static Ui_BFu1c_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu1c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu1c_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu1c_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1c_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu1c_BFu0c(Test_Ui_BFu1c_BFu0c, "Ui_BFu1c_BFu0c", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu1c_BFu0i()
{
  {
    init_simple_test("Ui_BFu1c_BFu0i");
    static Ui_BFu1c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu1c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1c_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu1c_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1c_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu1c_BFu0i(Test_Ui_BFu1c_BFu0i, "Ui_BFu1c_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu1c_BFu0ll()
{
  {
    init_simple_test("Ui_BFu1c_BFu0ll");
    static Ui_BFu1c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu1c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu1c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1c_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu1c_BFu0ll(Test_Ui_BFu1c_BFu0ll, "Ui_BFu1c_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu1c_BFu0s()
{
  {
    init_simple_test("Ui_BFu1c_BFu0s");
    static Ui_BFu1c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu1c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1c_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu1c_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1c_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu1c_BFu0s(Test_Ui_BFu1c_BFu0s, "Ui_BFu1c_BFu0s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu1i_BFu0c()
{
  {
    init_simple_test("Ui_BFu1i_BFu0c");
    static Ui_BFu1i_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu1i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu1i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu1i_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1i_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu1i_BFu0c(Test_Ui_BFu1i_BFu0c, "Ui_BFu1i_BFu0c", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu1i_BFu0i()
{
  {
    init_simple_test("Ui_BFu1i_BFu0i");
    static Ui_BFu1i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu1i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu1i_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1i_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu1i_BFu0i(Test_Ui_BFu1i_BFu0i, "Ui_BFu1i_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu1i_BFu0ll()
{
  {
    init_simple_test("Ui_BFu1i_BFu0ll");
    static Ui_BFu1i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu1i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu1i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu1i_BFu0ll(Test_Ui_BFu1i_BFu0ll, "Ui_BFu1i_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu1i_BFu0s()
{
  {
    init_simple_test("Ui_BFu1i_BFu0s");
    static Ui_BFu1i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu1i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu1i_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1i_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu1i_BFu0s(Test_Ui_BFu1i_BFu0s, "Ui_BFu1i_BFu0s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu1ll_BFu0c()
{
  {
    init_simple_test("Ui_BFu1ll_BFu0c");
    static Ui_BFu1ll_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu1ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu1ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu1ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu1ll_BFu0c(Test_Ui_BFu1ll_BFu0c, "Ui_BFu1ll_BFu0c", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu1ll_BFu0i()
{
  {
    init_simple_test("Ui_BFu1ll_BFu0i");
    static Ui_BFu1ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu1ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu1ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu1ll_BFu0i(Test_Ui_BFu1ll_BFu0i, "Ui_BFu1ll_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu1ll_BFu0ll()
{
  {
    init_simple_test("Ui_BFu1ll_BFu0ll");
    static Ui_BFu1ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu1ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu1ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu1ll_BFu0ll(Test_Ui_BFu1ll_BFu0ll, "Ui_BFu1ll_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu1ll_BFu0s()
{
  {
    init_simple_test("Ui_BFu1ll_BFu0s");
    static Ui_BFu1ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu1ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu1ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu1ll_BFu0s(Test_Ui_BFu1ll_BFu0s, "Ui_BFu1ll_BFu0s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu1s_BFu0c()
{
  {
    init_simple_test("Ui_BFu1s_BFu0c");
    static Ui_BFu1s_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu1s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu1s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu1s_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1s_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu1s_BFu0c(Test_Ui_BFu1s_BFu0c, "Ui_BFu1s_BFu0c", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu1s_BFu0i()
{
  {
    init_simple_test("Ui_BFu1s_BFu0i");
    static Ui_BFu1s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu1s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu1s_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1s_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu1s_BFu0i(Test_Ui_BFu1s_BFu0i, "Ui_BFu1s_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu1s_BFu0ll()
{
  {
    init_simple_test("Ui_BFu1s_BFu0ll");
    static Ui_BFu1s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu1s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu1s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1s_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu1s_BFu0ll(Test_Ui_BFu1s_BFu0ll, "Ui_BFu1s_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu1s_BFu0s()
{
  {
    init_simple_test("Ui_BFu1s_BFu0s");
    static Ui_BFu1s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu1s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu1s_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1s_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu1s_BFu0s(Test_Ui_BFu1s_BFu0s, "Ui_BFu1s_BFu0s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu31i_BFu0c()
{
  {
    init_simple_test("Ui_BFu31i_BFu0c");
    static Ui_BFu31i_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu31i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu31i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu31i_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu31i_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu31i_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu31i_BFu0c(Test_Ui_BFu31i_BFu0c, "Ui_BFu31i_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu31i_BFu0i()
{
  {
    init_simple_test("Ui_BFu31i_BFu0i");
    static Ui_BFu31i_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu31i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu31i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu31i_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu31i_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu31i_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu31i_BFu0i(Test_Ui_BFu31i_BFu0i, "Ui_BFu31i_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu31i_BFu0ll()
{
  {
    init_simple_test("Ui_BFu31i_BFu0ll");
    static Ui_BFu31i_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu31i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu31i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu31i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu31i_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu31i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu31i_BFu0ll(Test_Ui_BFu31i_BFu0ll, "Ui_BFu31i_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu31i_BFu0s()
{
  {
    init_simple_test("Ui_BFu31i_BFu0s");
    static Ui_BFu31i_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu31i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu31i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu31i_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu31i_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu31i_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu31i_BFu0s(Test_Ui_BFu31i_BFu0s, "Ui_BFu31i_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu31ll_BFu0c()
{
  {
    init_simple_test("Ui_BFu31ll_BFu0c");
    static Ui_BFu31ll_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu31ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu31ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu31ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu31ll_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu31ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu31ll_BFu0c(Test_Ui_BFu31ll_BFu0c, "Ui_BFu31ll_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu31ll_BFu0i()
{
  {
    init_simple_test("Ui_BFu31ll_BFu0i");
    static Ui_BFu31ll_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu31ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu31ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu31ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu31ll_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu31ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu31ll_BFu0i(Test_Ui_BFu31ll_BFu0i, "Ui_BFu31ll_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu31ll_BFu0ll()
{
  {
    init_simple_test("Ui_BFu31ll_BFu0ll");
    static Ui_BFu31ll_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu31ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu31ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu31ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu31ll_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu31ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu31ll_BFu0ll(Test_Ui_BFu31ll_BFu0ll, "Ui_BFu31ll_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu31ll_BFu0s()
{
  {
    init_simple_test("Ui_BFu31ll_BFu0s");
    static Ui_BFu31ll_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu31ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu31ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu31ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu31ll_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu31ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu31ll_BFu0s(Test_Ui_BFu31ll_BFu0s, "Ui_BFu31ll_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu32i_BFu0c()
{
  {
    init_simple_test("Ui_BFu32i_BFu0c");
    static Ui_BFu32i_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu32i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu32i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu32i_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu32i_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu32i_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu32i_BFu0c(Test_Ui_BFu32i_BFu0c, "Ui_BFu32i_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu32i_BFu0i()
{
  {
    init_simple_test("Ui_BFu32i_BFu0i");
    static Ui_BFu32i_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu32i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu32i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu32i_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu32i_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu32i_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu32i_BFu0i(Test_Ui_BFu32i_BFu0i, "Ui_BFu32i_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu32i_BFu0ll()
{
  {
    init_simple_test("Ui_BFu32i_BFu0ll");
    static Ui_BFu32i_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu32i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu32i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu32i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu32i_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu32i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu32i_BFu0ll(Test_Ui_BFu32i_BFu0ll, "Ui_BFu32i_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu32i_BFu0s()
{
  {
    init_simple_test("Ui_BFu32i_BFu0s");
    static Ui_BFu32i_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu32i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu32i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu32i_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu32i_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu32i_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu32i_BFu0s(Test_Ui_BFu32i_BFu0s, "Ui_BFu32i_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu32ll_BFu0c()
{
  {
    init_simple_test("Ui_BFu32ll_BFu0c");
    static Ui_BFu32ll_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu32ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu32ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu32ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu32ll_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu32ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu32ll_BFu0c(Test_Ui_BFu32ll_BFu0c, "Ui_BFu32ll_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu32ll_BFu0i()
{
  {
    init_simple_test("Ui_BFu32ll_BFu0i");
    static Ui_BFu32ll_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu32ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu32ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu32ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu32ll_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu32ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu32ll_BFu0i(Test_Ui_BFu32ll_BFu0i, "Ui_BFu32ll_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu32ll_BFu0ll()
{
  {
    init_simple_test("Ui_BFu32ll_BFu0ll");
    static Ui_BFu32ll_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu32ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu32ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu32ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu32ll_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu32ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu32ll_BFu0ll(Test_Ui_BFu32ll_BFu0ll, "Ui_BFu32ll_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu32ll_BFu0s()
{
  {
    init_simple_test("Ui_BFu32ll_BFu0s");
    static Ui_BFu32ll_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu32ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu32ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu32ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu32ll_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu32ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu32ll_BFu0s(Test_Ui_BFu32ll_BFu0s, "Ui_BFu32ll_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu33_BFu0c()
{
  {
    init_simple_test("Ui_BFu33_BFu0c");
    static Ui_BFu33_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ui_BFu33_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu33_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu33_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 33, 1, "Ui_BFu33_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 33, hide_ull(1LL<<32), "Ui_BFu33_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu33_BFu0c(Test_Ui_BFu33_BFu0c, "Ui_BFu33_BFu0c", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu33_BFu0i()
{
  {
    init_simple_test("Ui_BFu33_BFu0i");
    static Ui_BFu33_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ui_BFu33_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu33_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu33_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 33, 1, "Ui_BFu33_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 33, hide_ull(1LL<<32), "Ui_BFu33_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu33_BFu0i(Test_Ui_BFu33_BFu0i, "Ui_BFu33_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu33_BFu0ll()
{
  {
    init_simple_test("Ui_BFu33_BFu0ll");
    static Ui_BFu33_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ui_BFu33_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu33_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu33_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 33, 1, "Ui_BFu33_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 33, hide_ull(1LL<<32), "Ui_BFu33_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu33_BFu0ll(Test_Ui_BFu33_BFu0ll, "Ui_BFu33_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu33_BFu0s()
{
  {
    init_simple_test("Ui_BFu33_BFu0s");
    static Ui_BFu33_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ui_BFu33_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu33_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu33_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 33, 1, "Ui_BFu33_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 33, hide_ull(1LL<<32), "Ui_BFu33_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu33_BFu0s(Test_Ui_BFu33_BFu0s, "Ui_BFu33_BFu0s", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu7c_BFu0c()
{
  {
    init_simple_test("Ui_BFu7c_BFu0c");
    static Ui_BFu7c_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu7c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu7c_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu7c_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7c_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7c_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu7c_BFu0c(Test_Ui_BFu7c_BFu0c, "Ui_BFu7c_BFu0c", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu7c_BFu0i()
{
  {
    init_simple_test("Ui_BFu7c_BFu0i");
    static Ui_BFu7c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu7c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7c_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu7c_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7c_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7c_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu7c_BFu0i(Test_Ui_BFu7c_BFu0i, "Ui_BFu7c_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu7c_BFu0ll()
{
  {
    init_simple_test("Ui_BFu7c_BFu0ll");
    static Ui_BFu7c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu7c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu7c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7c_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7c_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu7c_BFu0ll(Test_Ui_BFu7c_BFu0ll, "Ui_BFu7c_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu7c_BFu0s()
{
  {
    init_simple_test("Ui_BFu7c_BFu0s");
    static Ui_BFu7c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu7c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7c_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu7c_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7c_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7c_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu7c_BFu0s(Test_Ui_BFu7c_BFu0s, "Ui_BFu7c_BFu0s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu7i_BFu0c()
{
  {
    init_simple_test("Ui_BFu7i_BFu0c");
    static Ui_BFu7i_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu7i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu7i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu7i_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7i_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7i_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu7i_BFu0c(Test_Ui_BFu7i_BFu0c, "Ui_BFu7i_BFu0c", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu7i_BFu0i()
{
  {
    init_simple_test("Ui_BFu7i_BFu0i");
    static Ui_BFu7i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu7i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu7i_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7i_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7i_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu7i_BFu0i(Test_Ui_BFu7i_BFu0i, "Ui_BFu7i_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu7i_BFu0ll()
{
  {
    init_simple_test("Ui_BFu7i_BFu0ll");
    static Ui_BFu7i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu7i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu7i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7i_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu7i_BFu0ll(Test_Ui_BFu7i_BFu0ll, "Ui_BFu7i_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu7i_BFu0s()
{
  {
    init_simple_test("Ui_BFu7i_BFu0s");
    static Ui_BFu7i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu7i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu7i_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7i_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7i_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu7i_BFu0s(Test_Ui_BFu7i_BFu0s, "Ui_BFu7i_BFu0s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu7ll_BFu0c()
{
  {
    init_simple_test("Ui_BFu7ll_BFu0c");
    static Ui_BFu7ll_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu7ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu7ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu7ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7ll_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu7ll_BFu0c(Test_Ui_BFu7ll_BFu0c, "Ui_BFu7ll_BFu0c", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu7ll_BFu0i()
{
  {
    init_simple_test("Ui_BFu7ll_BFu0i");
    static Ui_BFu7ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu7ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu7ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7ll_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu7ll_BFu0i(Test_Ui_BFu7ll_BFu0i, "Ui_BFu7ll_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu7ll_BFu0ll()
{
  {
    init_simple_test("Ui_BFu7ll_BFu0ll");
    static Ui_BFu7ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu7ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu7ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7ll_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu7ll_BFu0ll(Test_Ui_BFu7ll_BFu0ll, "Ui_BFu7ll_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu7ll_BFu0s()
{
  {
    init_simple_test("Ui_BFu7ll_BFu0s");
    static Ui_BFu7ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu7ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu7ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7ll_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu7ll_BFu0s(Test_Ui_BFu7ll_BFu0s, "Ui_BFu7ll_BFu0s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu7s_BFu0c()
{
  {
    init_simple_test("Ui_BFu7s_BFu0c");
    static Ui_BFu7s_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu7s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu7s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu7s_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7s_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7s_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu7s_BFu0c(Test_Ui_BFu7s_BFu0c, "Ui_BFu7s_BFu0c", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu7s_BFu0i()
{
  {
    init_simple_test("Ui_BFu7s_BFu0i");
    static Ui_BFu7s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu7s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu7s_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7s_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7s_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu7s_BFu0i(Test_Ui_BFu7s_BFu0i, "Ui_BFu7s_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu7s_BFu0ll()
{
  {
    init_simple_test("Ui_BFu7s_BFu0ll");
    static Ui_BFu7s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu7s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu7s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7s_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7s_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu7s_BFu0ll(Test_Ui_BFu7s_BFu0ll, "Ui_BFu7s_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu7s_BFu0s()
{
  {
    init_simple_test("Ui_BFu7s_BFu0s");
    static Ui_BFu7s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu7s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu7s_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7s_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7s_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu7s_BFu0s(Test_Ui_BFu7s_BFu0s, "Ui_BFu7s_BFu0s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu8c_BFu0c()
{
  {
    init_simple_test("Ui_BFu8c_BFu0c");
    static Ui_BFu8c_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu8c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu8c_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu8c_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8c_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8c_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu8c_BFu0c(Test_Ui_BFu8c_BFu0c, "Ui_BFu8c_BFu0c", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu8c_BFu0i()
{
  {
    init_simple_test("Ui_BFu8c_BFu0i");
    static Ui_BFu8c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu8c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8c_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu8c_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8c_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8c_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu8c_BFu0i(Test_Ui_BFu8c_BFu0i, "Ui_BFu8c_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu8c_BFu0ll()
{
  {
    init_simple_test("Ui_BFu8c_BFu0ll");
    static Ui_BFu8c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu8c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu8c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8c_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8c_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu8c_BFu0ll(Test_Ui_BFu8c_BFu0ll, "Ui_BFu8c_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu8c_BFu0s()
{
  {
    init_simple_test("Ui_BFu8c_BFu0s");
    static Ui_BFu8c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu8c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8c_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu8c_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8c_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8c_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu8c_BFu0s(Test_Ui_BFu8c_BFu0s, "Ui_BFu8c_BFu0s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu8i_BFu0c()
{
  {
    init_simple_test("Ui_BFu8i_BFu0c");
    static Ui_BFu8i_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu8i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu8i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu8i_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8i_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8i_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu8i_BFu0c(Test_Ui_BFu8i_BFu0c, "Ui_BFu8i_BFu0c", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu8i_BFu0i()
{
  {
    init_simple_test("Ui_BFu8i_BFu0i");
    static Ui_BFu8i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu8i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu8i_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8i_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8i_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu8i_BFu0i(Test_Ui_BFu8i_BFu0i, "Ui_BFu8i_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu8i_BFu0ll()
{
  {
    init_simple_test("Ui_BFu8i_BFu0ll");
    static Ui_BFu8i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu8i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu8i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8i_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu8i_BFu0ll(Test_Ui_BFu8i_BFu0ll, "Ui_BFu8i_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu8i_BFu0s()
{
  {
    init_simple_test("Ui_BFu8i_BFu0s");
    static Ui_BFu8i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu8i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu8i_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8i_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8i_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu8i_BFu0s(Test_Ui_BFu8i_BFu0s, "Ui_BFu8i_BFu0s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu8ll_BFu0c()
{
  {
    init_simple_test("Ui_BFu8ll_BFu0c");
    static Ui_BFu8ll_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu8ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu8ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu8ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8ll_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu8ll_BFu0c(Test_Ui_BFu8ll_BFu0c, "Ui_BFu8ll_BFu0c", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu8ll_BFu0i()
{
  {
    init_simple_test("Ui_BFu8ll_BFu0i");
    static Ui_BFu8ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu8ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu8ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8ll_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu8ll_BFu0i(Test_Ui_BFu8ll_BFu0i, "Ui_BFu8ll_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu8ll_BFu0ll()
{
  {
    init_simple_test("Ui_BFu8ll_BFu0ll");
    static Ui_BFu8ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu8ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu8ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8ll_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu8ll_BFu0ll(Test_Ui_BFu8ll_BFu0ll, "Ui_BFu8ll_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu8ll_BFu0s()
{
  {
    init_simple_test("Ui_BFu8ll_BFu0s");
    static Ui_BFu8ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu8ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu8ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8ll_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu8ll_BFu0s(Test_Ui_BFu8ll_BFu0s, "Ui_BFu8ll_BFu0s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu8s_BFu0c()
{
  {
    init_simple_test("Ui_BFu8s_BFu0c");
    static Ui_BFu8s_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu8s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu8s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu8s_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8s_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8s_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu8s_BFu0c(Test_Ui_BFu8s_BFu0c, "Ui_BFu8s_BFu0c", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu8s_BFu0i()
{
  {
    init_simple_test("Ui_BFu8s_BFu0i");
    static Ui_BFu8s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu8s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu8s_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8s_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8s_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu8s_BFu0i(Test_Ui_BFu8s_BFu0i, "Ui_BFu8s_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu8s_BFu0ll()
{
  {
    init_simple_test("Ui_BFu8s_BFu0ll");
    static Ui_BFu8s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu8s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu8s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8s_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8s_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu8s_BFu0ll(Test_Ui_BFu8s_BFu0ll, "Ui_BFu8s_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu8s_BFu0s()
{
  {
    init_simple_test("Ui_BFu8s_BFu0s");
    static Ui_BFu8s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu8s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu8s_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8s_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8s_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu8s_BFu0s(Test_Ui_BFu8s_BFu0s, "Ui_BFu8s_BFu0s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu9i_BFu0c()
{
  {
    init_simple_test("Ui_BFu9i_BFu0c");
    static Ui_BFu9i_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu9i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu9i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu9i_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9i_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9i_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu9i_BFu0c(Test_Ui_BFu9i_BFu0c, "Ui_BFu9i_BFu0c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu9i_BFu0i()
{
  {
    init_simple_test("Ui_BFu9i_BFu0i");
    static Ui_BFu9i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu9i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu9i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu9i_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9i_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9i_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu9i_BFu0i(Test_Ui_BFu9i_BFu0i, "Ui_BFu9i_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu9i_BFu0ll()
{
  {
    init_simple_test("Ui_BFu9i_BFu0ll");
    static Ui_BFu9i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu9i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu9i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu9i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9i_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu9i_BFu0ll(Test_Ui_BFu9i_BFu0ll, "Ui_BFu9i_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu9i_BFu0s()
{
  {
    init_simple_test("Ui_BFu9i_BFu0s");
    static Ui_BFu9i_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu9i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu9i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu9i_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9i_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9i_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu9i_BFu0s(Test_Ui_BFu9i_BFu0s, "Ui_BFu9i_BFu0s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu9ll_BFu0c()
{
  {
    init_simple_test("Ui_BFu9ll_BFu0c");
    static Ui_BFu9ll_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu9ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu9ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu9ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9ll_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu9ll_BFu0c(Test_Ui_BFu9ll_BFu0c, "Ui_BFu9ll_BFu0c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu9ll_BFu0i()
{
  {
    init_simple_test("Ui_BFu9ll_BFu0i");
    static Ui_BFu9ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu9ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu9ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu9ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9ll_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu9ll_BFu0i(Test_Ui_BFu9ll_BFu0i, "Ui_BFu9ll_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu9ll_BFu0ll()
{
  {
    init_simple_test("Ui_BFu9ll_BFu0ll");
    static Ui_BFu9ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu9ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu9ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu9ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9ll_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu9ll_BFu0ll(Test_Ui_BFu9ll_BFu0ll, "Ui_BFu9ll_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu9ll_BFu0s()
{
  {
    init_simple_test("Ui_BFu9ll_BFu0s");
    static Ui_BFu9ll_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu9ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu9ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu9ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9ll_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu9ll_BFu0s(Test_Ui_BFu9ll_BFu0s, "Ui_BFu9ll_BFu0s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu9s_BFu0c()
{
  {
    init_simple_test("Ui_BFu9s_BFu0c");
    static Ui_BFu9s_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu9s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu9s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu9s_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9s_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9s_BFu0c");
  }
}
static Arrange_To_Call_Me vUi_BFu9s_BFu0c(Test_Ui_BFu9s_BFu0c, "Ui_BFu9s_BFu0c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu9s_BFu0i()
{
  {
    init_simple_test("Ui_BFu9s_BFu0i");
    static Ui_BFu9s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu9s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu9s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu9s_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9s_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9s_BFu0i");
  }
}
static Arrange_To_Call_Me vUi_BFu9s_BFu0i(Test_Ui_BFu9s_BFu0i, "Ui_BFu9s_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu9s_BFu0ll()
{
  {
    init_simple_test("Ui_BFu9s_BFu0ll");
    static Ui_BFu9s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu9s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu9s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu9s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9s_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9s_BFu0ll");
  }
}
static Arrange_To_Call_Me vUi_BFu9s_BFu0ll(Test_Ui_BFu9s_BFu0ll, "Ui_BFu9s_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_BFu9s_BFu0s()
{
  {
    init_simple_test("Ui_BFu9s_BFu0s");
    static Ui_BFu9s_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu9s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu9s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu9s_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9s_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9s_BFu0s");
  }
}
static Arrange_To_Call_Me vUi_BFu9s_BFu0s(Test_Ui_BFu9s_BFu0s, "Ui_BFu9s_BFu0s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_C_BFu0c()
{
  {
    init_simple_test("Ui_C_BFu0c");
    static Ui_C_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_C_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_C_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_C_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_C_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUi_C_BFu0c(Test_Ui_C_BFu0c, "Ui_C_BFu0c", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_C_BFu0i()
{
  {
    init_simple_test("Ui_C_BFu0i");
    static Ui_C_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_C_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_C_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_C_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_C_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUi_C_BFu0i(Test_Ui_C_BFu0i, "Ui_C_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_C_BFu0ll()
{
  {
    init_simple_test("Ui_C_BFu0ll");
    static Ui_C_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_C_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_C_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_C_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_C_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUi_C_BFu0ll(Test_Ui_C_BFu0ll, "Ui_C_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_C_BFu0s()
{
  {
    init_simple_test("Ui_C_BFu0s");
    static Ui_C_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_C_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_C_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_C_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_C_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUi_C_BFu0s(Test_Ui_C_BFu0s, "Ui_C_BFu0s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_D_BFu0c()
{
  {
    init_simple_test("Ui_D_BFu0c");
    static Ui_D_BFu0c lv;
    check2(sizeof(lv), 12, "sizeof(Ui_D_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_D_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_D_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_D_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUi_D_BFu0c(Test_Ui_D_BFu0c, "Ui_D_BFu0c", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_D_BFu0i()
{
  {
    init_simple_test("Ui_D_BFu0i");
    static Ui_D_BFu0i lv;
    check2(sizeof(lv), 12, "sizeof(Ui_D_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_D_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_D_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_D_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUi_D_BFu0i(Test_Ui_D_BFu0i, "Ui_D_BFu0i", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_D_BFu0ll()
{
  {
    init_simple_test("Ui_D_BFu0ll");
    static Ui_D_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ui_D_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_D_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_D_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_D_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUi_D_BFu0ll(Test_Ui_D_BFu0ll, "Ui_D_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_D_BFu0s()
{
  {
    init_simple_test("Ui_D_BFu0s");
    static Ui_D_BFu0s lv;
    check2(sizeof(lv), 12, "sizeof(Ui_D_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_D_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_D_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_D_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUi_D_BFu0s(Test_Ui_D_BFu0s, "Ui_D_BFu0s", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_F_BFu0c()
{
  {
    init_simple_test("Ui_F_BFu0c");
    static Ui_F_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ui_F_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_F_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_F_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_F_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUi_F_BFu0c(Test_Ui_F_BFu0c, "Ui_F_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_F_BFu0i()
{
  {
    init_simple_test("Ui_F_BFu0i");
    static Ui_F_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_F_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_F_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_F_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_F_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUi_F_BFu0i(Test_Ui_F_BFu0i, "Ui_F_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_F_BFu0ll()
{
  {
    init_simple_test("Ui_F_BFu0ll");
    static Ui_F_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_F_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_F_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_F_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_F_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUi_F_BFu0ll(Test_Ui_F_BFu0ll, "Ui_F_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_F_BFu0s()
{
  {
    init_simple_test("Ui_F_BFu0s");
    static Ui_F_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ui_F_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_F_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_F_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_F_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUi_F_BFu0s(Test_Ui_F_BFu0s, "Ui_F_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_I_BFu0c()
{
  {
    init_simple_test("Ui_I_BFu0c");
    static Ui_I_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ui_I_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_I_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_I_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_I_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUi_I_BFu0c(Test_Ui_I_BFu0c, "Ui_I_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_I_BFu0i()
{
  {
    init_simple_test("Ui_I_BFu0i");
    static Ui_I_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_I_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_I_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_I_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_I_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUi_I_BFu0i(Test_Ui_I_BFu0i, "Ui_I_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_I_BFu0ll()
{
  {
    init_simple_test("Ui_I_BFu0ll");
    static Ui_I_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_I_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_I_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_I_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_I_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUi_I_BFu0ll(Test_Ui_I_BFu0ll, "Ui_I_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_I_BFu0s()
{
  {
    init_simple_test("Ui_I_BFu0s");
    static Ui_I_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ui_I_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_I_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_I_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_I_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUi_I_BFu0s(Test_Ui_I_BFu0s, "Ui_I_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Ip_BFu0c()
{
  {
    init_simple_test("Ui_Ip_BFu0c");
    static Ui_Ip_BFu0c lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_Ip_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Ip_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_Ip_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_Ip_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUi_Ip_BFu0c(Test_Ui_Ip_BFu0c, "Ui_Ip_BFu0c", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Ip_BFu0i()
{
  {
    init_simple_test("Ui_Ip_BFu0i");
    static Ui_Ip_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_Ip_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Ip_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_Ip_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_Ip_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUi_Ip_BFu0i(Test_Ui_Ip_BFu0i, "Ui_Ip_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Ip_BFu0ll()
{
  {
    init_simple_test("Ui_Ip_BFu0ll");
    static Ui_Ip_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Ui_Ip_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Ip_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_Ip_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Ip_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUi_Ip_BFu0ll(Test_Ui_Ip_BFu0ll, "Ui_Ip_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Ip_BFu0s()
{
  {
    init_simple_test("Ui_Ip_BFu0s");
    static Ui_Ip_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_Ip_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Ip_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_Ip_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_Ip_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUi_Ip_BFu0s(Test_Ui_Ip_BFu0s, "Ui_Ip_BFu0s", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_L_BFu0c()
{
  {
    init_simple_test("Ui_L_BFu0c");
    static Ui_L_BFu0c lv;
    check2(sizeof(lv), 12, "sizeof(Ui_L_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_L_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_L_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_L_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUi_L_BFu0c(Test_Ui_L_BFu0c, "Ui_L_BFu0c", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_L_BFu0i()
{
  {
    init_simple_test("Ui_L_BFu0i");
    static Ui_L_BFu0i lv;
    check2(sizeof(lv), 12, "sizeof(Ui_L_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_L_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_L_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_L_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUi_L_BFu0i(Test_Ui_L_BFu0i, "Ui_L_BFu0i", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_L_BFu0ll()
{
  {
    init_simple_test("Ui_L_BFu0ll");
    static Ui_L_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ui_L_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_L_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_L_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_L_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUi_L_BFu0ll(Test_Ui_L_BFu0ll, "Ui_L_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_L_BFu0s()
{
  {
    init_simple_test("Ui_L_BFu0s");
    static Ui_L_BFu0s lv;
    check2(sizeof(lv), 12, "sizeof(Ui_L_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_L_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_L_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_L_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUi_L_BFu0s(Test_Ui_L_BFu0s, "Ui_L_BFu0s", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_S_BFu0c()
{
  {
    init_simple_test("Ui_S_BFu0c");
    static Ui_S_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_S_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_S_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_S_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_S_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUi_S_BFu0c(Test_Ui_S_BFu0c, "Ui_S_BFu0c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_S_BFu0i()
{
  {
    init_simple_test("Ui_S_BFu0i");
    static Ui_S_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_S_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_S_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_S_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_S_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUi_S_BFu0i(Test_Ui_S_BFu0i, "Ui_S_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_S_BFu0ll()
{
  {
    init_simple_test("Ui_S_BFu0ll");
    static Ui_S_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_S_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_S_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_S_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_S_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUi_S_BFu0ll(Test_Ui_S_BFu0ll, "Ui_S_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_S_BFu0s()
{
  {
    init_simple_test("Ui_S_BFu0s");
    static Ui_S_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_S_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_S_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_S_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_S_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUi_S_BFu0s(Test_Ui_S_BFu0s, "Ui_S_BFu0s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Uc_BFu0c()
{
  {
    init_simple_test("Ui_Uc_BFu0c");
    static Ui_Uc_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_Uc_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Uc_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_Uc_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_Uc_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUi_Uc_BFu0c(Test_Ui_Uc_BFu0c, "Ui_Uc_BFu0c", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Uc_BFu0i()
{
  {
    init_simple_test("Ui_Uc_BFu0i");
    static Ui_Uc_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_Uc_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Uc_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_Uc_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_Uc_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUi_Uc_BFu0i(Test_Ui_Uc_BFu0i, "Ui_Uc_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Uc_BFu0ll()
{
  {
    init_simple_test("Ui_Uc_BFu0ll");
    static Ui_Uc_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_Uc_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Uc_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_Uc_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Uc_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUi_Uc_BFu0ll(Test_Ui_Uc_BFu0ll, "Ui_Uc_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Uc_BFu0s()
{
  {
    init_simple_test("Ui_Uc_BFu0s");
    static Ui_Uc_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_Uc_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Uc_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_Uc_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_Uc_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUi_Uc_BFu0s(Test_Ui_Uc_BFu0s, "Ui_Uc_BFu0s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Ui_BFu0c()
{
  {
    init_simple_test("Ui_Ui_BFu0c");
    static Ui_Ui_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ui_Ui_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Ui_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_Ui_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_Ui_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUi_Ui_BFu0c(Test_Ui_Ui_BFu0c, "Ui_Ui_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Ui_BFu0i()
{
  {
    init_simple_test("Ui_Ui_BFu0i");
    static Ui_Ui_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_Ui_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Ui_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_Ui_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_Ui_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUi_Ui_BFu0i(Test_Ui_Ui_BFu0i, "Ui_Ui_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Ui_BFu0ll()
{
  {
    init_simple_test("Ui_Ui_BFu0ll");
    static Ui_Ui_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_Ui_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Ui_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_Ui_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Ui_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUi_Ui_BFu0ll(Test_Ui_Ui_BFu0ll, "Ui_Ui_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Ui_BFu0s()
{
  {
    init_simple_test("Ui_Ui_BFu0s");
    static Ui_Ui_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ui_Ui_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Ui_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_Ui_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_Ui_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUi_Ui_BFu0s(Test_Ui_Ui_BFu0s, "Ui_Ui_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Ul_BFu0c()
{
  {
    init_simple_test("Ui_Ul_BFu0c");
    static Ui_Ul_BFu0c lv;
    check2(sizeof(lv), 12, "sizeof(Ui_Ul_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Ul_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_Ul_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_Ul_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUi_Ul_BFu0c(Test_Ui_Ul_BFu0c, "Ui_Ul_BFu0c", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Ul_BFu0i()
{
  {
    init_simple_test("Ui_Ul_BFu0i");
    static Ui_Ul_BFu0i lv;
    check2(sizeof(lv), 12, "sizeof(Ui_Ul_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Ul_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_Ul_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_Ul_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUi_Ul_BFu0i(Test_Ui_Ul_BFu0i, "Ui_Ul_BFu0i", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Ul_BFu0ll()
{
  {
    init_simple_test("Ui_Ul_BFu0ll");
    static Ui_Ul_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ui_Ul_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Ul_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_Ul_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Ul_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUi_Ul_BFu0ll(Test_Ui_Ul_BFu0ll, "Ui_Ul_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Ul_BFu0s()
{
  {
    init_simple_test("Ui_Ul_BFu0s");
    static Ui_Ul_BFu0s lv;
    check2(sizeof(lv), 12, "sizeof(Ui_Ul_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Ul_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_Ul_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_Ul_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUi_Ul_BFu0s(Test_Ui_Ul_BFu0s, "Ui_Ul_BFu0s", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Us_BFu0c()
{
  {
    init_simple_test("Ui_Us_BFu0c");
    static Ui_Us_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_Us_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Us_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_Us_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_Us_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUi_Us_BFu0c(Test_Ui_Us_BFu0c, "Ui_Us_BFu0c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Us_BFu0i()
{
  {
    init_simple_test("Ui_Us_BFu0i");
    static Ui_Us_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_Us_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Us_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_Us_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_Us_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUi_Us_BFu0i(Test_Ui_Us_BFu0i, "Ui_Us_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Us_BFu0ll()
{
  {
    init_simple_test("Ui_Us_BFu0ll");
    static Ui_Us_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_Us_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Us_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_Us_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Us_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUi_Us_BFu0ll(Test_Ui_Us_BFu0ll, "Ui_Us_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Us_BFu0s()
{
  {
    init_simple_test("Ui_Us_BFu0s");
    static Ui_Us_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_Us_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Us_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_Us_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_Us_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUi_Us_BFu0s(Test_Ui_Us_BFu0s, "Ui_Us_BFu0s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Vp_BFu0c()
{
  {
    init_simple_test("Ui_Vp_BFu0c");
    static Ui_Vp_BFu0c lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_Vp_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Vp_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_Vp_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_Vp_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUi_Vp_BFu0c(Test_Ui_Vp_BFu0c, "Ui_Vp_BFu0c", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Vp_BFu0i()
{
  {
    init_simple_test("Ui_Vp_BFu0i");
    static Ui_Vp_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_Vp_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Vp_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_Vp_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_Vp_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUi_Vp_BFu0i(Test_Ui_Vp_BFu0i, "Ui_Vp_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Vp_BFu0ll()
{
  {
    init_simple_test("Ui_Vp_BFu0ll");
    static Ui_Vp_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Ui_Vp_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Vp_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_Vp_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Vp_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUi_Vp_BFu0ll(Test_Ui_Vp_BFu0ll, "Ui_Vp_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ui_Vp_BFu0s()
{
  {
    init_simple_test("Ui_Vp_BFu0s");
    static Ui_Vp_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_Vp_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Vp_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_Vp_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_Vp_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUi_Vp_BFu0s(Test_Ui_Vp_BFu0s, "Ui_Vp_BFu0s", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c()
{
  {
    init_simple_test("Ul_BFu0c");
    static Ul_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vUl_BFu0c(Test_Ul_BFu0c, "Ul_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu0c()
{
  {
    init_simple_test("Ul_BFu0c_BFu0c");
    static Ul_BFu0c_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu0c(Test_Ul_BFu0c_BFu0c, "Ul_BFu0c_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu0i()
{
  {
    init_simple_test("Ul_BFu0c_BFu0i");
    static Ul_BFu0c_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0c_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu0i(Test_Ul_BFu0c_BFu0i, "Ul_BFu0c_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu0ll()
{
  {
    init_simple_test("Ul_BFu0c_BFu0ll");
    static Ul_BFu0c_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu0ll(Test_Ul_BFu0c_BFu0ll, "Ul_BFu0c_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu0s()
{
  {
    init_simple_test("Ul_BFu0c_BFu0s");
    static Ul_BFu0c_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0c_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu0s(Test_Ul_BFu0c_BFu0s, "Ul_BFu0c_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu15i()
{
  {
    init_simple_test("Ul_BFu0c_BFu15i");
    static Ul_BFu0c_BFu15i lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu15i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu15i.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0c_BFu15i");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0c_BFu15i");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu15i(Test_Ul_BFu0c_BFu15i, "Ul_BFu0c_BFu15i", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu15ll()
{
  {
    init_simple_test("Ul_BFu0c_BFu15ll");
    static Ul_BFu0c_BFu15ll lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu15ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu15ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0c_BFu15ll");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0c_BFu15ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu15ll(Test_Ul_BFu0c_BFu15ll, "Ul_BFu0c_BFu15ll", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu15s()
{
  {
    init_simple_test("Ul_BFu0c_BFu15s");
    static Ul_BFu0c_BFu15s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu15s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu15s.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0c_BFu15s");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0c_BFu15s");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu15s(Test_Ul_BFu0c_BFu15s, "Ul_BFu0c_BFu15s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu16i()
{
  {
    init_simple_test("Ul_BFu0c_BFu16i");
    static Ul_BFu0c_BFu16i lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu16i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu16i.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0c_BFu16i");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0c_BFu16i");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu16i(Test_Ul_BFu0c_BFu16i, "Ul_BFu0c_BFu16i", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu16ll()
{
  {
    init_simple_test("Ul_BFu0c_BFu16ll");
    static Ul_BFu0c_BFu16ll lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu16ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu16ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0c_BFu16ll");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0c_BFu16ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu16ll(Test_Ul_BFu0c_BFu16ll, "Ul_BFu0c_BFu16ll", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu16s()
{
  {
    init_simple_test("Ul_BFu0c_BFu16s");
    static Ul_BFu0c_BFu16s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu16s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu16s.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0c_BFu16s");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0c_BFu16s");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu16s(Test_Ul_BFu0c_BFu16s, "Ul_BFu0c_BFu16s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu17i()
{
  {
    init_simple_test("Ul_BFu0c_BFu17i");
    static Ul_BFu0c_BFu17i lv;
    check2(sizeof(lv), 11, "sizeof(Ul_BFu0c_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu17i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu17i.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu0c_BFu17i");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu0c_BFu17i");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu17i(Test_Ul_BFu0c_BFu17i, "Ul_BFu0c_BFu17i", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu17ll()
{
  {
    init_simple_test("Ul_BFu0c_BFu17ll");
    static Ul_BFu0c_BFu17ll lv;
    check2(sizeof(lv), 11, "sizeof(Ul_BFu0c_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu17ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu17ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu0c_BFu17ll");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu0c_BFu17ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu17ll(Test_Ul_BFu0c_BFu17ll, "Ul_BFu0c_BFu17ll", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu1c()
{
  {
    init_simple_test("Ul_BFu0c_BFu1c");
    static Ul_BFu0c_BFu1c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu1c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu1c.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0c_BFu1c");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu1c(Test_Ul_BFu0c_BFu1c, "Ul_BFu0c_BFu1c", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu1i()
{
  {
    init_simple_test("Ul_BFu0c_BFu1i");
    static Ul_BFu0c_BFu1i lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu1i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu1i.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0c_BFu1i");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu1i(Test_Ul_BFu0c_BFu1i, "Ul_BFu0c_BFu1i", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu1ll()
{
  {
    init_simple_test("Ul_BFu0c_BFu1ll");
    static Ul_BFu0c_BFu1ll lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu1ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu1ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0c_BFu1ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu1ll(Test_Ul_BFu0c_BFu1ll, "Ul_BFu0c_BFu1ll", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu1s()
{
  {
    init_simple_test("Ul_BFu0c_BFu1s");
    static Ul_BFu0c_BFu1s lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu1s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu1s.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0c_BFu1s");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu1s(Test_Ul_BFu0c_BFu1s, "Ul_BFu0c_BFu1s", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu31i()
{
  {
    init_simple_test("Ul_BFu0c_BFu31i");
    static Ul_BFu0c_BFu31i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0c_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu31i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu31i.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu0c_BFu31i");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu0c_BFu31i");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu31i(Test_Ul_BFu0c_BFu31i, "Ul_BFu0c_BFu31i", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu31ll()
{
  {
    init_simple_test("Ul_BFu0c_BFu31ll");
    static Ul_BFu0c_BFu31ll lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0c_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu31ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu31ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu0c_BFu31ll");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu0c_BFu31ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu31ll(Test_Ul_BFu0c_BFu31ll, "Ul_BFu0c_BFu31ll", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu32i()
{
  {
    init_simple_test("Ul_BFu0c_BFu32i");
    static Ul_BFu0c_BFu32i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0c_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu32i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu32i.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu0c_BFu32i");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu0c_BFu32i");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu32i(Test_Ul_BFu0c_BFu32i, "Ul_BFu0c_BFu32i", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu32ll()
{
  {
    init_simple_test("Ul_BFu0c_BFu32ll");
    static Ul_BFu0c_BFu32ll lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0c_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu32ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu32ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu0c_BFu32ll");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu0c_BFu32ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu32ll(Test_Ul_BFu0c_BFu32ll, "Ul_BFu0c_BFu32ll", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu33()
{
  {
    init_simple_test("Ul_BFu0c_BFu33");
    static Ul_BFu0c_BFu33 lv;
    check2(sizeof(lv), 13, "sizeof(Ul_BFu0c_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu33)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu33.v1");
    set_bf_and_test(lv, v2, 8, 0, 33, 1, "Ul_BFu0c_BFu33");
    set_bf_and_test(lv, v2, 8, 0, 33, hide_ull(1LL<<32), "Ul_BFu0c_BFu33");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu33(Test_Ul_BFu0c_BFu33, "Ul_BFu0c_BFu33", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu7c()
{
  {
    init_simple_test("Ul_BFu0c_BFu7c");
    static Ul_BFu0c_BFu7c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu7c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu7c.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0c_BFu7c");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0c_BFu7c");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu7c(Test_Ul_BFu0c_BFu7c, "Ul_BFu0c_BFu7c", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu7i()
{
  {
    init_simple_test("Ul_BFu0c_BFu7i");
    static Ul_BFu0c_BFu7i lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu7i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu7i.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0c_BFu7i");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0c_BFu7i");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu7i(Test_Ul_BFu0c_BFu7i, "Ul_BFu0c_BFu7i", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu7ll()
{
  {
    init_simple_test("Ul_BFu0c_BFu7ll");
    static Ul_BFu0c_BFu7ll lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu7ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu7ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0c_BFu7ll");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0c_BFu7ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu7ll(Test_Ul_BFu0c_BFu7ll, "Ul_BFu0c_BFu7ll", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu7s()
{
  {
    init_simple_test("Ul_BFu0c_BFu7s");
    static Ul_BFu0c_BFu7s lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu7s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu7s.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0c_BFu7s");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0c_BFu7s");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu7s(Test_Ul_BFu0c_BFu7s, "Ul_BFu0c_BFu7s", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu8c()
{
  {
    init_simple_test("Ul_BFu0c_BFu8c");
    static Ul_BFu0c_BFu8c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu8c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu8c.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0c_BFu8c");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0c_BFu8c");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu8c(Test_Ul_BFu0c_BFu8c, "Ul_BFu0c_BFu8c", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu8i()
{
  {
    init_simple_test("Ul_BFu0c_BFu8i");
    static Ul_BFu0c_BFu8i lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu8i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu8i.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0c_BFu8i");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0c_BFu8i");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu8i(Test_Ul_BFu0c_BFu8i, "Ul_BFu0c_BFu8i", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu8ll()
{
  {
    init_simple_test("Ul_BFu0c_BFu8ll");
    static Ul_BFu0c_BFu8ll lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu8ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu8ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0c_BFu8ll");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0c_BFu8ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu8ll(Test_Ul_BFu0c_BFu8ll, "Ul_BFu0c_BFu8ll", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu8s()
{
  {
    init_simple_test("Ul_BFu0c_BFu8s");
    static Ul_BFu0c_BFu8s lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu8s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu8s.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0c_BFu8s");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0c_BFu8s");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu8s(Test_Ul_BFu0c_BFu8s, "Ul_BFu0c_BFu8s", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu9i()
{
  {
    init_simple_test("Ul_BFu0c_BFu9i");
    static Ul_BFu0c_BFu9i lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu9i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu9i.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0c_BFu9i");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0c_BFu9i");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu9i(Test_Ul_BFu0c_BFu9i, "Ul_BFu0c_BFu9i", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu9ll()
{
  {
    init_simple_test("Ul_BFu0c_BFu9ll");
    static Ul_BFu0c_BFu9ll lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu9ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu9ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0c_BFu9ll");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0c_BFu9ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu9ll(Test_Ul_BFu0c_BFu9ll, "Ul_BFu0c_BFu9ll", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_BFu9s()
{
  {
    init_simple_test("Ul_BFu0c_BFu9s");
    static Ul_BFu0c_BFu9s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu9s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu9s.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0c_BFu9s");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0c_BFu9s");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_BFu9s(Test_Ul_BFu0c_BFu9s, "Ul_BFu0c_BFu9s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_C()
{
  {
    init_simple_test("Ul_BFu0c_C");
    static Ul_BFu0c_C lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_C)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_C)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_C.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_C.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_C(Test_Ul_BFu0c_C, "Ul_BFu0c_C", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_D()
{
  {
    init_simple_test("Ul_BFu0c_D");
    static Ul_BFu0c_D lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0c_D)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_D)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_D.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_D.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_D(Test_Ul_BFu0c_D, "Ul_BFu0c_D", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_F()
{
  {
    init_simple_test("Ul_BFu0c_F");
    static Ul_BFu0c_F lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0c_F)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_F)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_F.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_F.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_F(Test_Ul_BFu0c_F, "Ul_BFu0c_F", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_I()
{
  {
    init_simple_test("Ul_BFu0c_I");
    static Ul_BFu0c_I lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0c_I)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_I)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_I.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_I.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_I(Test_Ul_BFu0c_I, "Ul_BFu0c_I", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_Ip()
{
  {
    init_simple_test("Ul_BFu0c_Ip");
    static Ul_BFu0c_Ip lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu0c_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_Ip)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_Ip.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_Ip.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_Ip(Test_Ul_BFu0c_Ip, "Ul_BFu0c_Ip", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_L()
{
  {
    init_simple_test("Ul_BFu0c_L");
    static Ul_BFu0c_L lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0c_L)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_L)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_L.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_L.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_L(Test_Ul_BFu0c_L, "Ul_BFu0c_L", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_S()
{
  {
    init_simple_test("Ul_BFu0c_S");
    static Ul_BFu0c_S lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_S)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_S)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_S.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_S.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_S(Test_Ul_BFu0c_S, "Ul_BFu0c_S", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_Uc()
{
  {
    init_simple_test("Ul_BFu0c_Uc");
    static Ul_BFu0c_Uc lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_Uc)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_Uc.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_Uc.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_Uc(Test_Ul_BFu0c_Uc, "Ul_BFu0c_Uc", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_Ui()
{
  {
    init_simple_test("Ul_BFu0c_Ui");
    static Ul_BFu0c_Ui lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0c_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_Ui)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_Ui.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_Ui.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_Ui(Test_Ul_BFu0c_Ui, "Ul_BFu0c_Ui", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_Ul()
{
  {
    init_simple_test("Ul_BFu0c_Ul");
    static Ul_BFu0c_Ul lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0c_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_Ul)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_Ul.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_Ul.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_Ul(Test_Ul_BFu0c_Ul, "Ul_BFu0c_Ul", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_Us()
{
  {
    init_simple_test("Ul_BFu0c_Us");
    static Ul_BFu0c_Us lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_Us)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_Us.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_Us.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_Us(Test_Ul_BFu0c_Us, "Ul_BFu0c_Us", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0c_Vp()
{
  {
    init_simple_test("Ul_BFu0c_Vp");
    static Ul_BFu0c_Vp lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu0c_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_Vp)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_Vp.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_Vp.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_Vp(Test_Ul_BFu0c_Vp, "Ul_BFu0c_Vp", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i()
{
  {
    init_simple_test("Ul_BFu0i");
    static Ul_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vUl_BFu0i(Test_Ul_BFu0i, "Ul_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu0c()
{
  {
    init_simple_test("Ul_BFu0i_BFu0c");
    static Ul_BFu0i_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0i_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu0c(Test_Ul_BFu0i_BFu0c, "Ul_BFu0i_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu0i()
{
  {
    init_simple_test("Ul_BFu0i_BFu0i");
    static Ul_BFu0i_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu0i(Test_Ul_BFu0i_BFu0i, "Ul_BFu0i_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu0ll()
{
  {
    init_simple_test("Ul_BFu0i_BFu0ll");
    static Ul_BFu0i_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu0ll(Test_Ul_BFu0i_BFu0ll, "Ul_BFu0i_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu0s()
{
  {
    init_simple_test("Ul_BFu0i_BFu0s");
    static Ul_BFu0i_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu0s(Test_Ul_BFu0i_BFu0s, "Ul_BFu0i_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu15i()
{
  {
    init_simple_test("Ul_BFu0i_BFu15i");
    static Ul_BFu0i_BFu15i lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_BFu15i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu15i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu15i.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0i_BFu15i");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0i_BFu15i");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu15i(Test_Ul_BFu0i_BFu15i, "Ul_BFu0i_BFu15i", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu15ll()
{
  {
    init_simple_test("Ul_BFu0i_BFu15ll");
    static Ul_BFu0i_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu15ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu15ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0i_BFu15ll");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0i_BFu15ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu15ll(Test_Ul_BFu0i_BFu15ll, "Ul_BFu0i_BFu15ll", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu15s()
{
  {
    init_simple_test("Ul_BFu0i_BFu15s");
    static Ul_BFu0i_BFu15s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_BFu15s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu15s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu15s.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0i_BFu15s");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0i_BFu15s");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu15s(Test_Ul_BFu0i_BFu15s, "Ul_BFu0i_BFu15s", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu16i()
{
  {
    init_simple_test("Ul_BFu0i_BFu16i");
    static Ul_BFu0i_BFu16i lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_BFu16i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu16i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu16i.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0i_BFu16i");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0i_BFu16i");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu16i(Test_Ul_BFu0i_BFu16i, "Ul_BFu0i_BFu16i", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu16ll()
{
  {
    init_simple_test("Ul_BFu0i_BFu16ll");
    static Ul_BFu0i_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu16ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu16ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0i_BFu16ll");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0i_BFu16ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu16ll(Test_Ul_BFu0i_BFu16ll, "Ul_BFu0i_BFu16ll", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu16s()
{
  {
    init_simple_test("Ul_BFu0i_BFu16s");
    static Ul_BFu0i_BFu16s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_BFu16s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu16s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu16s.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0i_BFu16s");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0i_BFu16s");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu16s(Test_Ul_BFu0i_BFu16s, "Ul_BFu0i_BFu16s", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu17i()
{
  {
    init_simple_test("Ul_BFu0i_BFu17i");
    static Ul_BFu0i_BFu17i lv;
    check2(sizeof(lv), ABISELECT(11,11), "sizeof(Ul_BFu0i_BFu17i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu17i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu17i.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu0i_BFu17i");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu0i_BFu17i");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu17i(Test_Ul_BFu0i_BFu17i, "Ul_BFu0i_BFu17i", ABISELECT(11,11));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu17ll()
{
  {
    init_simple_test("Ul_BFu0i_BFu17ll");
    static Ul_BFu0i_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(11,11), "sizeof(Ul_BFu0i_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu17ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu17ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu0i_BFu17ll");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu0i_BFu17ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu17ll(Test_Ul_BFu0i_BFu17ll, "Ul_BFu0i_BFu17ll", ABISELECT(11,11));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu1c()
{
  {
    init_simple_test("Ul_BFu0i_BFu1c");
    static Ul_BFu0i_BFu1c lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu1c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu1c.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0i_BFu1c");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu1c(Test_Ul_BFu0i_BFu1c, "Ul_BFu0i_BFu1c", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu1i()
{
  {
    init_simple_test("Ul_BFu0i_BFu1i");
    static Ul_BFu0i_BFu1i lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu1i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu1i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu1i.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0i_BFu1i");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu1i(Test_Ul_BFu0i_BFu1i, "Ul_BFu0i_BFu1i", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu1ll()
{
  {
    init_simple_test("Ul_BFu0i_BFu1ll");
    static Ul_BFu0i_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu1ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu1ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0i_BFu1ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu1ll(Test_Ul_BFu0i_BFu1ll, "Ul_BFu0i_BFu1ll", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu1s()
{
  {
    init_simple_test("Ul_BFu0i_BFu1s");
    static Ul_BFu0i_BFu1s lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu1s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu1s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu1s.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0i_BFu1s");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu1s(Test_Ul_BFu0i_BFu1s, "Ul_BFu0i_BFu1s", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu31i()
{
  {
    init_simple_test("Ul_BFu0i_BFu31i");
    static Ul_BFu0i_BFu31i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0i_BFu31i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu31i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu31i.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu0i_BFu31i");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu0i_BFu31i");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu31i(Test_Ul_BFu0i_BFu31i, "Ul_BFu0i_BFu31i", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu31ll()
{
  {
    init_simple_test("Ul_BFu0i_BFu31ll");
    static Ul_BFu0i_BFu31ll lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0i_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu31ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu31ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu0i_BFu31ll");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu0i_BFu31ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu31ll(Test_Ul_BFu0i_BFu31ll, "Ul_BFu0i_BFu31ll", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu32i()
{
  {
    init_simple_test("Ul_BFu0i_BFu32i");
    static Ul_BFu0i_BFu32i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0i_BFu32i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu32i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu32i.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu0i_BFu32i");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu0i_BFu32i");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu32i(Test_Ul_BFu0i_BFu32i, "Ul_BFu0i_BFu32i", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu32ll()
{
  {
    init_simple_test("Ul_BFu0i_BFu32ll");
    static Ul_BFu0i_BFu32ll lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0i_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu32ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu32ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu0i_BFu32ll");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu0i_BFu32ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu32ll(Test_Ul_BFu0i_BFu32ll, "Ul_BFu0i_BFu32ll", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu33()
{
  {
    init_simple_test("Ul_BFu0i_BFu33");
    static Ul_BFu0i_BFu33 lv;
    check2(sizeof(lv), ABISELECT(13,13), "sizeof(Ul_BFu0i_BFu33)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu33)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu33.v1");
    set_bf_and_test(lv, v2, 8, 0, 33, 1, "Ul_BFu0i_BFu33");
    set_bf_and_test(lv, v2, 8, 0, 33, hide_ull(1LL<<32), "Ul_BFu0i_BFu33");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu33(Test_Ul_BFu0i_BFu33, "Ul_BFu0i_BFu33", ABISELECT(13,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu7c()
{
  {
    init_simple_test("Ul_BFu0i_BFu7c");
    static Ul_BFu0i_BFu7c lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu7c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu7c.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0i_BFu7c");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0i_BFu7c");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu7c(Test_Ul_BFu0i_BFu7c, "Ul_BFu0i_BFu7c", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu7i()
{
  {
    init_simple_test("Ul_BFu0i_BFu7i");
    static Ul_BFu0i_BFu7i lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu7i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu7i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu7i.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0i_BFu7i");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0i_BFu7i");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu7i(Test_Ul_BFu0i_BFu7i, "Ul_BFu0i_BFu7i", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu7ll()
{
  {
    init_simple_test("Ul_BFu0i_BFu7ll");
    static Ul_BFu0i_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu7ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu7ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0i_BFu7ll");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0i_BFu7ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu7ll(Test_Ul_BFu0i_BFu7ll, "Ul_BFu0i_BFu7ll", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu7s()
{
  {
    init_simple_test("Ul_BFu0i_BFu7s");
    static Ul_BFu0i_BFu7s lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu7s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu7s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu7s.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0i_BFu7s");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0i_BFu7s");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu7s(Test_Ul_BFu0i_BFu7s, "Ul_BFu0i_BFu7s", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu8c()
{
  {
    init_simple_test("Ul_BFu0i_BFu8c");
    static Ul_BFu0i_BFu8c lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu8c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu8c.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0i_BFu8c");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0i_BFu8c");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu8c(Test_Ul_BFu0i_BFu8c, "Ul_BFu0i_BFu8c", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu8i()
{
  {
    init_simple_test("Ul_BFu0i_BFu8i");
    static Ul_BFu0i_BFu8i lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu8i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu8i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu8i.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0i_BFu8i");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0i_BFu8i");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu8i(Test_Ul_BFu0i_BFu8i, "Ul_BFu0i_BFu8i", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu8ll()
{
  {
    init_simple_test("Ul_BFu0i_BFu8ll");
    static Ul_BFu0i_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu8ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu8ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0i_BFu8ll");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0i_BFu8ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu8ll(Test_Ul_BFu0i_BFu8ll, "Ul_BFu0i_BFu8ll", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu8s()
{
  {
    init_simple_test("Ul_BFu0i_BFu8s");
    static Ul_BFu0i_BFu8s lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu8s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu8s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu8s.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0i_BFu8s");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0i_BFu8s");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu8s(Test_Ul_BFu0i_BFu8s, "Ul_BFu0i_BFu8s", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu9i()
{
  {
    init_simple_test("Ul_BFu0i_BFu9i");
    static Ul_BFu0i_BFu9i lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_BFu9i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu9i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu9i.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0i_BFu9i");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0i_BFu9i");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu9i(Test_Ul_BFu0i_BFu9i, "Ul_BFu0i_BFu9i", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu9ll()
{
  {
    init_simple_test("Ul_BFu0i_BFu9ll");
    static Ul_BFu0i_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu9ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu9ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0i_BFu9ll");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0i_BFu9ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu9ll(Test_Ul_BFu0i_BFu9ll, "Ul_BFu0i_BFu9ll", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_BFu9s()
{
  {
    init_simple_test("Ul_BFu0i_BFu9s");
    static Ul_BFu0i_BFu9s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_BFu9s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu9s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu9s.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0i_BFu9s");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0i_BFu9s");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_BFu9s(Test_Ul_BFu0i_BFu9s, "Ul_BFu0i_BFu9s", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_C()
{
  {
    init_simple_test("Ul_BFu0i_C");
    static Ul_BFu0i_C lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_C)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_C.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_C.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_C(Test_Ul_BFu0i_C, "Ul_BFu0i_C", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_D()
{
  {
    init_simple_test("Ul_BFu0i_D");
    static Ul_BFu0i_D lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0i_D)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_D)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_D.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_D.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_D(Test_Ul_BFu0i_D, "Ul_BFu0i_D", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_F()
{
  {
    init_simple_test("Ul_BFu0i_F");
    static Ul_BFu0i_F lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0i_F)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_F)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_F.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_F.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_F(Test_Ul_BFu0i_F, "Ul_BFu0i_F", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_I()
{
  {
    init_simple_test("Ul_BFu0i_I");
    static Ul_BFu0i_I lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0i_I)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_I)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_I.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_I.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_I(Test_Ul_BFu0i_I, "Ul_BFu0i_I", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_Ip()
{
  {
    init_simple_test("Ul_BFu0i_Ip");
    static Ul_BFu0i_Ip lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu0i_Ip)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_Ip)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_Ip.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_Ip.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_Ip(Test_Ul_BFu0i_Ip, "Ul_BFu0i_Ip", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_L()
{
  {
    init_simple_test("Ul_BFu0i_L");
    static Ul_BFu0i_L lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0i_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_L)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_L.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_L.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_L(Test_Ul_BFu0i_L, "Ul_BFu0i_L", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_S()
{
  {
    init_simple_test("Ul_BFu0i_S");
    static Ul_BFu0i_S lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_S)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_S.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_S.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_S(Test_Ul_BFu0i_S, "Ul_BFu0i_S", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_Uc()
{
  {
    init_simple_test("Ul_BFu0i_Uc");
    static Ul_BFu0i_Uc lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_Uc)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_Uc.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_Uc.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_Uc(Test_Ul_BFu0i_Uc, "Ul_BFu0i_Uc", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_Ui()
{
  {
    init_simple_test("Ul_BFu0i_Ui");
    static Ul_BFu0i_Ui lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0i_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_Ui)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_Ui.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_Ui.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_Ui(Test_Ul_BFu0i_Ui, "Ul_BFu0i_Ui", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_Ul()
{
  {
    init_simple_test("Ul_BFu0i_Ul");
    static Ul_BFu0i_Ul lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0i_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_Ul)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_Ul.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_Ul.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_Ul(Test_Ul_BFu0i_Ul, "Ul_BFu0i_Ul", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_Us()
{
  {
    init_simple_test("Ul_BFu0i_Us");
    static Ul_BFu0i_Us lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_Us)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_Us.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_Us.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_Us(Test_Ul_BFu0i_Us, "Ul_BFu0i_Us", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0i_Vp()
{
  {
    init_simple_test("Ul_BFu0i_Vp");
    static Ul_BFu0i_Vp lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu0i_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_Vp)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_Vp.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_Vp.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_Vp(Test_Ul_BFu0i_Vp, "Ul_BFu0i_Vp", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll()
{
  {
    init_simple_test("Ul_BFu0ll");
    static Ul_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll(Test_Ul_BFu0ll, "Ul_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu0c()
{
  {
    init_simple_test("Ul_BFu0ll_BFu0c");
    static Ul_BFu0ll_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu0c(Test_Ul_BFu0ll_BFu0c, "Ul_BFu0ll_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu0i()
{
  {
    init_simple_test("Ul_BFu0ll_BFu0i");
    static Ul_BFu0ll_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu0i(Test_Ul_BFu0ll_BFu0i, "Ul_BFu0ll_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu0ll()
{
  {
    init_simple_test("Ul_BFu0ll_BFu0ll");
    static Ul_BFu0ll_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu0ll(Test_Ul_BFu0ll_BFu0ll, "Ul_BFu0ll_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu0s()
{
  {
    init_simple_test("Ul_BFu0ll_BFu0s");
    static Ul_BFu0ll_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu0s(Test_Ul_BFu0ll_BFu0s, "Ul_BFu0ll_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu15i()
{
  {
    init_simple_test("Ul_BFu0ll_BFu15i");
    static Ul_BFu0ll_BFu15i lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_BFu15i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu15i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu15i.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0ll_BFu15i");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0ll_BFu15i");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu15i(Test_Ul_BFu0ll_BFu15i, "Ul_BFu0ll_BFu15i", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu15ll()
{
  {
    init_simple_test("Ul_BFu0ll_BFu15ll");
    static Ul_BFu0ll_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu15ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu15ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0ll_BFu15ll");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0ll_BFu15ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu15ll(Test_Ul_BFu0ll_BFu15ll, "Ul_BFu0ll_BFu15ll", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu15s()
{
  {
    init_simple_test("Ul_BFu0ll_BFu15s");
    static Ul_BFu0ll_BFu15s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_BFu15s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu15s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu15s.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0ll_BFu15s");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0ll_BFu15s");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu15s(Test_Ul_BFu0ll_BFu15s, "Ul_BFu0ll_BFu15s", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu16i()
{
  {
    init_simple_test("Ul_BFu0ll_BFu16i");
    static Ul_BFu0ll_BFu16i lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_BFu16i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu16i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu16i.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0ll_BFu16i");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0ll_BFu16i");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu16i(Test_Ul_BFu0ll_BFu16i, "Ul_BFu0ll_BFu16i", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu16ll()
{
  {
    init_simple_test("Ul_BFu0ll_BFu16ll");
    static Ul_BFu0ll_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu16ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu16ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0ll_BFu16ll");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0ll_BFu16ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu16ll(Test_Ul_BFu0ll_BFu16ll, "Ul_BFu0ll_BFu16ll", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu16s()
{
  {
    init_simple_test("Ul_BFu0ll_BFu16s");
    static Ul_BFu0ll_BFu16s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_BFu16s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu16s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu16s.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0ll_BFu16s");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0ll_BFu16s");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu16s(Test_Ul_BFu0ll_BFu16s, "Ul_BFu0ll_BFu16s", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu17i()
{
  {
    init_simple_test("Ul_BFu0ll_BFu17i");
    static Ul_BFu0ll_BFu17i lv;
    check2(sizeof(lv), ABISELECT(11,11), "sizeof(Ul_BFu0ll_BFu17i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu17i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu17i.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu0ll_BFu17i");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu0ll_BFu17i");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu17i(Test_Ul_BFu0ll_BFu17i, "Ul_BFu0ll_BFu17i", ABISELECT(11,11));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu17ll()
{
  {
    init_simple_test("Ul_BFu0ll_BFu17ll");
    static Ul_BFu0ll_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(11,11), "sizeof(Ul_BFu0ll_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu17ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu17ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu0ll_BFu17ll");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu0ll_BFu17ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu17ll(Test_Ul_BFu0ll_BFu17ll, "Ul_BFu0ll_BFu17ll", ABISELECT(11,11));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu1c()
{
  {
    init_simple_test("Ul_BFu0ll_BFu1c");
    static Ul_BFu0ll_BFu1c lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu1c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu1c.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0ll_BFu1c");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu1c(Test_Ul_BFu0ll_BFu1c, "Ul_BFu0ll_BFu1c", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu1i()
{
  {
    init_simple_test("Ul_BFu0ll_BFu1i");
    static Ul_BFu0ll_BFu1i lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu1i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu1i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu1i.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0ll_BFu1i");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu1i(Test_Ul_BFu0ll_BFu1i, "Ul_BFu0ll_BFu1i", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu1ll()
{
  {
    init_simple_test("Ul_BFu0ll_BFu1ll");
    static Ul_BFu0ll_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu1ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu1ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0ll_BFu1ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu1ll(Test_Ul_BFu0ll_BFu1ll, "Ul_BFu0ll_BFu1ll", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu1s()
{
  {
    init_simple_test("Ul_BFu0ll_BFu1s");
    static Ul_BFu0ll_BFu1s lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu1s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu1s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu1s.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0ll_BFu1s");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu1s(Test_Ul_BFu0ll_BFu1s, "Ul_BFu0ll_BFu1s", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu31i()
{
  {
    init_simple_test("Ul_BFu0ll_BFu31i");
    static Ul_BFu0ll_BFu31i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu0ll_BFu31i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu31i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu31i.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu0ll_BFu31i");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu0ll_BFu31i");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu31i(Test_Ul_BFu0ll_BFu31i, "Ul_BFu0ll_BFu31i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu31ll()
{
  {
    init_simple_test("Ul_BFu0ll_BFu31ll");
    static Ul_BFu0ll_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu0ll_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu31ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu31ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu0ll_BFu31ll");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu0ll_BFu31ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu31ll(Test_Ul_BFu0ll_BFu31ll, "Ul_BFu0ll_BFu31ll", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu32i()
{
  {
    init_simple_test("Ul_BFu0ll_BFu32i");
    static Ul_BFu0ll_BFu32i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu0ll_BFu32i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu32i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu32i.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu0ll_BFu32i");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu0ll_BFu32i");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu32i(Test_Ul_BFu0ll_BFu32i, "Ul_BFu0ll_BFu32i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu32ll()
{
  {
    init_simple_test("Ul_BFu0ll_BFu32ll");
    static Ul_BFu0ll_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu0ll_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu32ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu32ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu0ll_BFu32ll");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu0ll_BFu32ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu32ll(Test_Ul_BFu0ll_BFu32ll, "Ul_BFu0ll_BFu32ll", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu33()
{
  {
    init_simple_test("Ul_BFu0ll_BFu33");
    static Ul_BFu0ll_BFu33 lv;
    check2(sizeof(lv), ABISELECT(13,13), "sizeof(Ul_BFu0ll_BFu33)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu33)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu33.v1");
    set_bf_and_test(lv, v2, 8, 0, 33, 1, "Ul_BFu0ll_BFu33");
    set_bf_and_test(lv, v2, 8, 0, 33, hide_ull(1LL<<32), "Ul_BFu0ll_BFu33");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu33(Test_Ul_BFu0ll_BFu33, "Ul_BFu0ll_BFu33", ABISELECT(13,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu7c()
{
  {
    init_simple_test("Ul_BFu0ll_BFu7c");
    static Ul_BFu0ll_BFu7c lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu7c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu7c.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0ll_BFu7c");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0ll_BFu7c");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu7c(Test_Ul_BFu0ll_BFu7c, "Ul_BFu0ll_BFu7c", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu7i()
{
  {
    init_simple_test("Ul_BFu0ll_BFu7i");
    static Ul_BFu0ll_BFu7i lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu7i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu7i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu7i.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0ll_BFu7i");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0ll_BFu7i");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu7i(Test_Ul_BFu0ll_BFu7i, "Ul_BFu0ll_BFu7i", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu7ll()
{
  {
    init_simple_test("Ul_BFu0ll_BFu7ll");
    static Ul_BFu0ll_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu7ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu7ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0ll_BFu7ll");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0ll_BFu7ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu7ll(Test_Ul_BFu0ll_BFu7ll, "Ul_BFu0ll_BFu7ll", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu7s()
{
  {
    init_simple_test("Ul_BFu0ll_BFu7s");
    static Ul_BFu0ll_BFu7s lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu7s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu7s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu7s.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0ll_BFu7s");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0ll_BFu7s");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu7s(Test_Ul_BFu0ll_BFu7s, "Ul_BFu0ll_BFu7s", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu8c()
{
  {
    init_simple_test("Ul_BFu0ll_BFu8c");
    static Ul_BFu0ll_BFu8c lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu8c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu8c.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0ll_BFu8c");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0ll_BFu8c");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu8c(Test_Ul_BFu0ll_BFu8c, "Ul_BFu0ll_BFu8c", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu8i()
{
  {
    init_simple_test("Ul_BFu0ll_BFu8i");
    static Ul_BFu0ll_BFu8i lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu8i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu8i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu8i.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0ll_BFu8i");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0ll_BFu8i");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu8i(Test_Ul_BFu0ll_BFu8i, "Ul_BFu0ll_BFu8i", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu8ll()
{
  {
    init_simple_test("Ul_BFu0ll_BFu8ll");
    static Ul_BFu0ll_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu8ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu8ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0ll_BFu8ll");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0ll_BFu8ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu8ll(Test_Ul_BFu0ll_BFu8ll, "Ul_BFu0ll_BFu8ll", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu8s()
{
  {
    init_simple_test("Ul_BFu0ll_BFu8s");
    static Ul_BFu0ll_BFu8s lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu8s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu8s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu8s.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0ll_BFu8s");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0ll_BFu8s");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu8s(Test_Ul_BFu0ll_BFu8s, "Ul_BFu0ll_BFu8s", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu9i()
{
  {
    init_simple_test("Ul_BFu0ll_BFu9i");
    static Ul_BFu0ll_BFu9i lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_BFu9i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu9i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu9i.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0ll_BFu9i");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0ll_BFu9i");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu9i(Test_Ul_BFu0ll_BFu9i, "Ul_BFu0ll_BFu9i", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu9ll()
{
  {
    init_simple_test("Ul_BFu0ll_BFu9ll");
    static Ul_BFu0ll_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu9ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu9ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0ll_BFu9ll");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0ll_BFu9ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu9ll(Test_Ul_BFu0ll_BFu9ll, "Ul_BFu0ll_BFu9ll", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_BFu9s()
{
  {
    init_simple_test("Ul_BFu0ll_BFu9s");
    static Ul_BFu0ll_BFu9s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_BFu9s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu9s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu9s.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0ll_BFu9s");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0ll_BFu9s");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_BFu9s(Test_Ul_BFu0ll_BFu9s, "Ul_BFu0ll_BFu9s", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_C()
{
  {
    init_simple_test("Ul_BFu0ll_C");
    static Ul_BFu0ll_C lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_C)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_C.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_C.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_C(Test_Ul_BFu0ll_C, "Ul_BFu0ll_C", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_D()
{
  {
    init_simple_test("Ul_BFu0ll_D");
    static Ul_BFu0ll_D lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0ll_D)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_D)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_D.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_D.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_D(Test_Ul_BFu0ll_D, "Ul_BFu0ll_D", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_F()
{
  {
    init_simple_test("Ul_BFu0ll_F");
    static Ul_BFu0ll_F lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu0ll_F)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_F)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_F.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_F.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_F(Test_Ul_BFu0ll_F, "Ul_BFu0ll_F", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_I()
{
  {
    init_simple_test("Ul_BFu0ll_I");
    static Ul_BFu0ll_I lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu0ll_I)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_I)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_I.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_I.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_I(Test_Ul_BFu0ll_I, "Ul_BFu0ll_I", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_Ip()
{
  {
    init_simple_test("Ul_BFu0ll_Ip");
    static Ul_BFu0ll_Ip lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu0ll_Ip)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_Ip)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_Ip.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_Ip.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_Ip(Test_Ul_BFu0ll_Ip, "Ul_BFu0ll_Ip", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_L()
{
  {
    init_simple_test("Ul_BFu0ll_L");
    static Ul_BFu0ll_L lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0ll_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_L)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_L.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_L.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_L(Test_Ul_BFu0ll_L, "Ul_BFu0ll_L", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_S()
{
  {
    init_simple_test("Ul_BFu0ll_S");
    static Ul_BFu0ll_S lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_S)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_S.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_S.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_S(Test_Ul_BFu0ll_S, "Ul_BFu0ll_S", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_Uc()
{
  {
    init_simple_test("Ul_BFu0ll_Uc");
    static Ul_BFu0ll_Uc lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_Uc)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_Uc.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_Uc.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_Uc(Test_Ul_BFu0ll_Uc, "Ul_BFu0ll_Uc", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_Ui()
{
  {
    init_simple_test("Ul_BFu0ll_Ui");
    static Ul_BFu0ll_Ui lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu0ll_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_Ui)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_Ui.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_Ui.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_Ui(Test_Ul_BFu0ll_Ui, "Ul_BFu0ll_Ui", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_Ul()
{
  {
    init_simple_test("Ul_BFu0ll_Ul");
    static Ul_BFu0ll_Ul lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0ll_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_Ul)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_Ul.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_Ul.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_Ul(Test_Ul_BFu0ll_Ul, "Ul_BFu0ll_Ul", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_Us()
{
  {
    init_simple_test("Ul_BFu0ll_Us");
    static Ul_BFu0ll_Us lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_Us)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_Us.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_Us.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_Us(Test_Ul_BFu0ll_Us, "Ul_BFu0ll_Us", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0ll_Vp()
{
  {
    init_simple_test("Ul_BFu0ll_Vp");
    static Ul_BFu0ll_Vp lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu0ll_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_Vp)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_Vp.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_Vp.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_Vp(Test_Ul_BFu0ll_Vp, "Ul_BFu0ll_Vp", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s()
{
  {
    init_simple_test("Ul_BFu0s");
    static Ul_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vUl_BFu0s(Test_Ul_BFu0s, "Ul_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu0c()
{
  {
    init_simple_test("Ul_BFu0s_BFu0c");
    static Ul_BFu0s_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0s_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu0c(Test_Ul_BFu0s_BFu0c, "Ul_BFu0s_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu0i()
{
  {
    init_simple_test("Ul_BFu0s_BFu0i");
    static Ul_BFu0s_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu0i(Test_Ul_BFu0s_BFu0i, "Ul_BFu0s_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu0ll()
{
  {
    init_simple_test("Ul_BFu0s_BFu0ll");
    static Ul_BFu0s_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu0ll(Test_Ul_BFu0s_BFu0ll, "Ul_BFu0s_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu0s()
{
  {
    init_simple_test("Ul_BFu0s_BFu0s");
    static Ul_BFu0s_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu0s(Test_Ul_BFu0s_BFu0s, "Ul_BFu0s_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu15i()
{
  {
    init_simple_test("Ul_BFu0s_BFu15i");
    static Ul_BFu0s_BFu15i lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_BFu15i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu15i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu15i.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0s_BFu15i");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0s_BFu15i");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu15i(Test_Ul_BFu0s_BFu15i, "Ul_BFu0s_BFu15i", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu15ll()
{
  {
    init_simple_test("Ul_BFu0s_BFu15ll");
    static Ul_BFu0s_BFu15ll lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu15ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu15ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0s_BFu15ll");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0s_BFu15ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu15ll(Test_Ul_BFu0s_BFu15ll, "Ul_BFu0s_BFu15ll", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu15s()
{
  {
    init_simple_test("Ul_BFu0s_BFu15s");
    static Ul_BFu0s_BFu15s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_BFu15s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu15s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu15s.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0s_BFu15s");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0s_BFu15s");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu15s(Test_Ul_BFu0s_BFu15s, "Ul_BFu0s_BFu15s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu16i()
{
  {
    init_simple_test("Ul_BFu0s_BFu16i");
    static Ul_BFu0s_BFu16i lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_BFu16i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu16i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu16i.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0s_BFu16i");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0s_BFu16i");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu16i(Test_Ul_BFu0s_BFu16i, "Ul_BFu0s_BFu16i", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu16ll()
{
  {
    init_simple_test("Ul_BFu0s_BFu16ll");
    static Ul_BFu0s_BFu16ll lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu16ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu16ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0s_BFu16ll");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0s_BFu16ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu16ll(Test_Ul_BFu0s_BFu16ll, "Ul_BFu0s_BFu16ll", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu16s()
{
  {
    init_simple_test("Ul_BFu0s_BFu16s");
    static Ul_BFu0s_BFu16s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_BFu16s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu16s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu16s.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0s_BFu16s");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0s_BFu16s");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu16s(Test_Ul_BFu0s_BFu16s, "Ul_BFu0s_BFu16s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu17i()
{
  {
    init_simple_test("Ul_BFu0s_BFu17i");
    static Ul_BFu0s_BFu17i lv;
    check2(sizeof(lv), ABISELECT(11,11), "sizeof(Ul_BFu0s_BFu17i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu17i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu17i.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu0s_BFu17i");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu0s_BFu17i");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu17i(Test_Ul_BFu0s_BFu17i, "Ul_BFu0s_BFu17i", ABISELECT(11,11));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu17ll()
{
  {
    init_simple_test("Ul_BFu0s_BFu17ll");
    static Ul_BFu0s_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(11,11), "sizeof(Ul_BFu0s_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu17ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu17ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu0s_BFu17ll");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu0s_BFu17ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu17ll(Test_Ul_BFu0s_BFu17ll, "Ul_BFu0s_BFu17ll", ABISELECT(11,11));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu1c()
{
  {
    init_simple_test("Ul_BFu0s_BFu1c");
    static Ul_BFu0s_BFu1c lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu1c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu1c.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0s_BFu1c");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu1c(Test_Ul_BFu0s_BFu1c, "Ul_BFu0s_BFu1c", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu1i()
{
  {
    init_simple_test("Ul_BFu0s_BFu1i");
    static Ul_BFu0s_BFu1i lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu1i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu1i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu1i.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0s_BFu1i");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu1i(Test_Ul_BFu0s_BFu1i, "Ul_BFu0s_BFu1i", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu1ll()
{
  {
    init_simple_test("Ul_BFu0s_BFu1ll");
    static Ul_BFu0s_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu1ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu1ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0s_BFu1ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu1ll(Test_Ul_BFu0s_BFu1ll, "Ul_BFu0s_BFu1ll", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu1s()
{
  {
    init_simple_test("Ul_BFu0s_BFu1s");
    static Ul_BFu0s_BFu1s lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu1s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu1s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu1s.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0s_BFu1s");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu1s(Test_Ul_BFu0s_BFu1s, "Ul_BFu0s_BFu1s", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu31i()
{
  {
    init_simple_test("Ul_BFu0s_BFu31i");
    static Ul_BFu0s_BFu31i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0s_BFu31i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu31i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu31i.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu0s_BFu31i");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu0s_BFu31i");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu31i(Test_Ul_BFu0s_BFu31i, "Ul_BFu0s_BFu31i", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu31ll()
{
  {
    init_simple_test("Ul_BFu0s_BFu31ll");
    static Ul_BFu0s_BFu31ll lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0s_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu31ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu31ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu0s_BFu31ll");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu0s_BFu31ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu31ll(Test_Ul_BFu0s_BFu31ll, "Ul_BFu0s_BFu31ll", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu32i()
{
  {
    init_simple_test("Ul_BFu0s_BFu32i");
    static Ul_BFu0s_BFu32i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0s_BFu32i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu32i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu32i.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu0s_BFu32i");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu0s_BFu32i");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu32i(Test_Ul_BFu0s_BFu32i, "Ul_BFu0s_BFu32i", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu32ll()
{
  {
    init_simple_test("Ul_BFu0s_BFu32ll");
    static Ul_BFu0s_BFu32ll lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0s_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu32ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu32ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu0s_BFu32ll");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu0s_BFu32ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu32ll(Test_Ul_BFu0s_BFu32ll, "Ul_BFu0s_BFu32ll", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu33()
{
  {
    init_simple_test("Ul_BFu0s_BFu33");
    static Ul_BFu0s_BFu33 lv;
    check2(sizeof(lv), ABISELECT(13,13), "sizeof(Ul_BFu0s_BFu33)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu33)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu33.v1");
    set_bf_and_test(lv, v2, 8, 0, 33, 1, "Ul_BFu0s_BFu33");
    set_bf_and_test(lv, v2, 8, 0, 33, hide_ull(1LL<<32), "Ul_BFu0s_BFu33");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu33(Test_Ul_BFu0s_BFu33, "Ul_BFu0s_BFu33", ABISELECT(13,13));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu7c()
{
  {
    init_simple_test("Ul_BFu0s_BFu7c");
    static Ul_BFu0s_BFu7c lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu7c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu7c.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0s_BFu7c");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0s_BFu7c");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu7c(Test_Ul_BFu0s_BFu7c, "Ul_BFu0s_BFu7c", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu7i()
{
  {
    init_simple_test("Ul_BFu0s_BFu7i");
    static Ul_BFu0s_BFu7i lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu7i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu7i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu7i.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0s_BFu7i");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0s_BFu7i");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu7i(Test_Ul_BFu0s_BFu7i, "Ul_BFu0s_BFu7i", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu7ll()
{
  {
    init_simple_test("Ul_BFu0s_BFu7ll");
    static Ul_BFu0s_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu7ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu7ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0s_BFu7ll");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0s_BFu7ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu7ll(Test_Ul_BFu0s_BFu7ll, "Ul_BFu0s_BFu7ll", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu7s()
{
  {
    init_simple_test("Ul_BFu0s_BFu7s");
    static Ul_BFu0s_BFu7s lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu7s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu7s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu7s.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0s_BFu7s");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0s_BFu7s");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu7s(Test_Ul_BFu0s_BFu7s, "Ul_BFu0s_BFu7s", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu8c()
{
  {
    init_simple_test("Ul_BFu0s_BFu8c");
    static Ul_BFu0s_BFu8c lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu8c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu8c.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0s_BFu8c");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0s_BFu8c");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu8c(Test_Ul_BFu0s_BFu8c, "Ul_BFu0s_BFu8c", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu8i()
{
  {
    init_simple_test("Ul_BFu0s_BFu8i");
    static Ul_BFu0s_BFu8i lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu8i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu8i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu8i.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0s_BFu8i");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0s_BFu8i");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu8i(Test_Ul_BFu0s_BFu8i, "Ul_BFu0s_BFu8i", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu8ll()
{
  {
    init_simple_test("Ul_BFu0s_BFu8ll");
    static Ul_BFu0s_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu8ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu8ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0s_BFu8ll");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0s_BFu8ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu8ll(Test_Ul_BFu0s_BFu8ll, "Ul_BFu0s_BFu8ll", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu8s()
{
  {
    init_simple_test("Ul_BFu0s_BFu8s");
    static Ul_BFu0s_BFu8s lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu8s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu8s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu8s.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0s_BFu8s");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0s_BFu8s");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu8s(Test_Ul_BFu0s_BFu8s, "Ul_BFu0s_BFu8s", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu9i()
{
  {
    init_simple_test("Ul_BFu0s_BFu9i");
    static Ul_BFu0s_BFu9i lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_BFu9i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu9i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu9i.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0s_BFu9i");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0s_BFu9i");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu9i(Test_Ul_BFu0s_BFu9i, "Ul_BFu0s_BFu9i", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu9ll()
{
  {
    init_simple_test("Ul_BFu0s_BFu9ll");
    static Ul_BFu0s_BFu9ll lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu9ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu9ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0s_BFu9ll");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0s_BFu9ll");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu9ll(Test_Ul_BFu0s_BFu9ll, "Ul_BFu0s_BFu9ll", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_BFu9s()
{
  {
    init_simple_test("Ul_BFu0s_BFu9s");
    static Ul_BFu0s_BFu9s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_BFu9s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu9s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu9s.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0s_BFu9s");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0s_BFu9s");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_BFu9s(Test_Ul_BFu0s_BFu9s, "Ul_BFu0s_BFu9s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_C()
{
  {
    init_simple_test("Ul_BFu0s_C");
    static Ul_BFu0s_C lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_C)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_C.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_C.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_C(Test_Ul_BFu0s_C, "Ul_BFu0s_C", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_D()
{
  {
    init_simple_test("Ul_BFu0s_D");
    static Ul_BFu0s_D lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0s_D)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_D)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_D.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_D.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_D(Test_Ul_BFu0s_D, "Ul_BFu0s_D", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_F()
{
  {
    init_simple_test("Ul_BFu0s_F");
    static Ul_BFu0s_F lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0s_F)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_F)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_F.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_F.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_F(Test_Ul_BFu0s_F, "Ul_BFu0s_F", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_I()
{
  {
    init_simple_test("Ul_BFu0s_I");
    static Ul_BFu0s_I lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0s_I)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_I)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_I.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_I.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_I(Test_Ul_BFu0s_I, "Ul_BFu0s_I", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_Ip()
{
  {
    init_simple_test("Ul_BFu0s_Ip");
    static Ul_BFu0s_Ip lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu0s_Ip)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_Ip)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_Ip.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_Ip.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_Ip(Test_Ul_BFu0s_Ip, "Ul_BFu0s_Ip", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_L()
{
  {
    init_simple_test("Ul_BFu0s_L");
    static Ul_BFu0s_L lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0s_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_L)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_L.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_L.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_L(Test_Ul_BFu0s_L, "Ul_BFu0s_L", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_S()
{
  {
    init_simple_test("Ul_BFu0s_S");
    static Ul_BFu0s_S lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_S)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_S.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_S.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_S(Test_Ul_BFu0s_S, "Ul_BFu0s_S", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_Uc()
{
  {
    init_simple_test("Ul_BFu0s_Uc");
    static Ul_BFu0s_Uc lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_Uc)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_Uc.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_Uc.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_Uc(Test_Ul_BFu0s_Uc, "Ul_BFu0s_Uc", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_Ui()
{
  {
    init_simple_test("Ul_BFu0s_Ui");
    static Ul_BFu0s_Ui lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0s_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_Ui)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_Ui.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_Ui.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_Ui(Test_Ul_BFu0s_Ui, "Ul_BFu0s_Ui", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_Ul()
{
  {
    init_simple_test("Ul_BFu0s_Ul");
    static Ul_BFu0s_Ul lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0s_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_Ul)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_Ul.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_Ul.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_Ul(Test_Ul_BFu0s_Ul, "Ul_BFu0s_Ul", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_Us()
{
  {
    init_simple_test("Ul_BFu0s_Us");
    static Ul_BFu0s_Us lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_Us)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_Us.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_Us.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_Us(Test_Ul_BFu0s_Us, "Ul_BFu0s_Us", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu0s_Vp()
{
  {
    init_simple_test("Ul_BFu0s_Vp");
    static Ul_BFu0s_Vp lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu0s_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_Vp)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_Vp.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_Vp.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_Vp(Test_Ul_BFu0s_Vp, "Ul_BFu0s_Vp", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu15i_BFu0c()
{
  {
    init_simple_test("Ul_BFu15i_BFu0c");
    static Ul_BFu15i_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu15i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu15i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu15i_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15i_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15i_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu15i_BFu0c(Test_Ul_BFu15i_BFu0c, "Ul_BFu15i_BFu0c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu15i_BFu0i()
{
  {
    init_simple_test("Ul_BFu15i_BFu0i");
    static Ul_BFu15i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu15i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu15i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu15i_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15i_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15i_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu15i_BFu0i(Test_Ul_BFu15i_BFu0i, "Ul_BFu15i_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu15i_BFu0ll()
{
  {
    init_simple_test("Ul_BFu15i_BFu0ll");
    static Ul_BFu15i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu15i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu15i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu15i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15i_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu15i_BFu0ll(Test_Ul_BFu15i_BFu0ll, "Ul_BFu15i_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu15i_BFu0s()
{
  {
    init_simple_test("Ul_BFu15i_BFu0s");
    static Ul_BFu15i_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu15i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu15i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu15i_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15i_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15i_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu15i_BFu0s(Test_Ul_BFu15i_BFu0s, "Ul_BFu15i_BFu0s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu15ll_BFu0c()
{
  {
    init_simple_test("Ul_BFu15ll_BFu0c");
    static Ul_BFu15ll_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu15ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu15ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu15ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15ll_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu15ll_BFu0c(Test_Ul_BFu15ll_BFu0c, "Ul_BFu15ll_BFu0c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu15ll_BFu0i()
{
  {
    init_simple_test("Ul_BFu15ll_BFu0i");
    static Ul_BFu15ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu15ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu15ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu15ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15ll_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu15ll_BFu0i(Test_Ul_BFu15ll_BFu0i, "Ul_BFu15ll_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu15ll_BFu0ll()
{
  {
    init_simple_test("Ul_BFu15ll_BFu0ll");
    static Ul_BFu15ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu15ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu15ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu15ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15ll_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu15ll_BFu0ll(Test_Ul_BFu15ll_BFu0ll, "Ul_BFu15ll_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu15ll_BFu0s()
{
  {
    init_simple_test("Ul_BFu15ll_BFu0s");
    static Ul_BFu15ll_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu15ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu15ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu15ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15ll_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu15ll_BFu0s(Test_Ul_BFu15ll_BFu0s, "Ul_BFu15ll_BFu0s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu15s_BFu0c()
{
  {
    init_simple_test("Ul_BFu15s_BFu0c");
    static Ul_BFu15s_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu15s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu15s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu15s_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15s_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15s_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu15s_BFu0c(Test_Ul_BFu15s_BFu0c, "Ul_BFu15s_BFu0c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu15s_BFu0i()
{
  {
    init_simple_test("Ul_BFu15s_BFu0i");
    static Ul_BFu15s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu15s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu15s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu15s_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15s_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15s_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu15s_BFu0i(Test_Ul_BFu15s_BFu0i, "Ul_BFu15s_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu15s_BFu0ll()
{
  {
    init_simple_test("Ul_BFu15s_BFu0ll");
    static Ul_BFu15s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu15s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu15s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu15s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15s_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15s_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu15s_BFu0ll(Test_Ul_BFu15s_BFu0ll, "Ul_BFu15s_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu15s_BFu0s()
{
  {
    init_simple_test("Ul_BFu15s_BFu0s");
    static Ul_BFu15s_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu15s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu15s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu15s_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15s_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15s_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu15s_BFu0s(Test_Ul_BFu15s_BFu0s, "Ul_BFu15s_BFu0s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu16i_BFu0c()
{
  {
    init_simple_test("Ul_BFu16i_BFu0c");
    static Ul_BFu16i_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu16i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu16i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu16i_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16i_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16i_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu16i_BFu0c(Test_Ul_BFu16i_BFu0c, "Ul_BFu16i_BFu0c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu16i_BFu0i()
{
  {
    init_simple_test("Ul_BFu16i_BFu0i");
    static Ul_BFu16i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu16i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu16i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu16i_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16i_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16i_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu16i_BFu0i(Test_Ul_BFu16i_BFu0i, "Ul_BFu16i_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu16i_BFu0ll()
{
  {
    init_simple_test("Ul_BFu16i_BFu0ll");
    static Ul_BFu16i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu16i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu16i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu16i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16i_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu16i_BFu0ll(Test_Ul_BFu16i_BFu0ll, "Ul_BFu16i_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu16i_BFu0s()
{
  {
    init_simple_test("Ul_BFu16i_BFu0s");
    static Ul_BFu16i_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu16i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu16i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu16i_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16i_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16i_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu16i_BFu0s(Test_Ul_BFu16i_BFu0s, "Ul_BFu16i_BFu0s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu16ll_BFu0c()
{
  {
    init_simple_test("Ul_BFu16ll_BFu0c");
    static Ul_BFu16ll_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu16ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu16ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu16ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16ll_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu16ll_BFu0c(Test_Ul_BFu16ll_BFu0c, "Ul_BFu16ll_BFu0c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu16ll_BFu0i()
{
  {
    init_simple_test("Ul_BFu16ll_BFu0i");
    static Ul_BFu16ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu16ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu16ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu16ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16ll_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu16ll_BFu0i(Test_Ul_BFu16ll_BFu0i, "Ul_BFu16ll_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu16ll_BFu0ll()
{
  {
    init_simple_test("Ul_BFu16ll_BFu0ll");
    static Ul_BFu16ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu16ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu16ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu16ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16ll_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu16ll_BFu0ll(Test_Ul_BFu16ll_BFu0ll, "Ul_BFu16ll_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu16ll_BFu0s()
{
  {
    init_simple_test("Ul_BFu16ll_BFu0s");
    static Ul_BFu16ll_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu16ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu16ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu16ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16ll_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu16ll_BFu0s(Test_Ul_BFu16ll_BFu0s, "Ul_BFu16ll_BFu0s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu16s_BFu0c()
{
  {
    init_simple_test("Ul_BFu16s_BFu0c");
    static Ul_BFu16s_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu16s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu16s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu16s_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16s_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16s_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu16s_BFu0c(Test_Ul_BFu16s_BFu0c, "Ul_BFu16s_BFu0c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu16s_BFu0i()
{
  {
    init_simple_test("Ul_BFu16s_BFu0i");
    static Ul_BFu16s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu16s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu16s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu16s_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16s_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16s_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu16s_BFu0i(Test_Ul_BFu16s_BFu0i, "Ul_BFu16s_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu16s_BFu0ll()
{
  {
    init_simple_test("Ul_BFu16s_BFu0ll");
    static Ul_BFu16s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu16s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu16s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu16s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16s_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16s_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu16s_BFu0ll(Test_Ul_BFu16s_BFu0ll, "Ul_BFu16s_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu16s_BFu0s()
{
  {
    init_simple_test("Ul_BFu16s_BFu0s");
    static Ul_BFu16s_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu16s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu16s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu16s_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16s_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16s_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu16s_BFu0s(Test_Ul_BFu16s_BFu0s, "Ul_BFu16s_BFu0s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu17i_BFu0c()
{
  {
    init_simple_test("Ul_BFu17i_BFu0c");
    static Ul_BFu17i_BFu0c lv;
    check2(sizeof(lv), 11, "sizeof(Ul_BFu17i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu17i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu17i_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu17i_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu17i_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu17i_BFu0c(Test_Ul_BFu17i_BFu0c, "Ul_BFu17i_BFu0c", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu17i_BFu0i()
{
  {
    init_simple_test("Ul_BFu17i_BFu0i");
    static Ul_BFu17i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu17i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu17i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu17i_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu17i_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu17i_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu17i_BFu0i(Test_Ul_BFu17i_BFu0i, "Ul_BFu17i_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu17i_BFu0ll()
{
  {
    init_simple_test("Ul_BFu17i_BFu0ll");
    static Ul_BFu17i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu17i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu17i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu17i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu17i_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu17i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu17i_BFu0ll(Test_Ul_BFu17i_BFu0ll, "Ul_BFu17i_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu17i_BFu0s()
{
  {
    init_simple_test("Ul_BFu17i_BFu0s");
    static Ul_BFu17i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu17i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu17i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu17i_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu17i_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu17i_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu17i_BFu0s(Test_Ul_BFu17i_BFu0s, "Ul_BFu17i_BFu0s", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu17ll_BFu0c()
{
  {
    init_simple_test("Ul_BFu17ll_BFu0c");
    static Ul_BFu17ll_BFu0c lv;
    check2(sizeof(lv), 11, "sizeof(Ul_BFu17ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu17ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu17ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu17ll_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu17ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu17ll_BFu0c(Test_Ul_BFu17ll_BFu0c, "Ul_BFu17ll_BFu0c", 11);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu17ll_BFu0i()
{
  {
    init_simple_test("Ul_BFu17ll_BFu0i");
    static Ul_BFu17ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu17ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu17ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu17ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu17ll_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu17ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu17ll_BFu0i(Test_Ul_BFu17ll_BFu0i, "Ul_BFu17ll_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu17ll_BFu0ll()
{
  {
    init_simple_test("Ul_BFu17ll_BFu0ll");
    static Ul_BFu17ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu17ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu17ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu17ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu17ll_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu17ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu17ll_BFu0ll(Test_Ul_BFu17ll_BFu0ll, "Ul_BFu17ll_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu17ll_BFu0s()
{
  {
    init_simple_test("Ul_BFu17ll_BFu0s");
    static Ul_BFu17ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu17ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu17ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu17ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu17ll_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu17ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu17ll_BFu0s(Test_Ul_BFu17ll_BFu0s, "Ul_BFu17ll_BFu0s", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu1c_BFu0c()
{
  {
    init_simple_test("Ul_BFu1c_BFu0c");
    static Ul_BFu1c_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu1c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu1c_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu1c_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1c_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu1c_BFu0c(Test_Ul_BFu1c_BFu0c, "Ul_BFu1c_BFu0c", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu1c_BFu0i()
{
  {
    init_simple_test("Ul_BFu1c_BFu0i");
    static Ul_BFu1c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu1c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1c_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu1c_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1c_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu1c_BFu0i(Test_Ul_BFu1c_BFu0i, "Ul_BFu1c_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu1c_BFu0ll()
{
  {
    init_simple_test("Ul_BFu1c_BFu0ll");
    static Ul_BFu1c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu1c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu1c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1c_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu1c_BFu0ll(Test_Ul_BFu1c_BFu0ll, "Ul_BFu1c_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu1c_BFu0s()
{
  {
    init_simple_test("Ul_BFu1c_BFu0s");
    static Ul_BFu1c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu1c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1c_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu1c_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1c_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu1c_BFu0s(Test_Ul_BFu1c_BFu0s, "Ul_BFu1c_BFu0s", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu1i_BFu0c()
{
  {
    init_simple_test("Ul_BFu1i_BFu0c");
    static Ul_BFu1i_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu1i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu1i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu1i_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1i_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu1i_BFu0c(Test_Ul_BFu1i_BFu0c, "Ul_BFu1i_BFu0c", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu1i_BFu0i()
{
  {
    init_simple_test("Ul_BFu1i_BFu0i");
    static Ul_BFu1i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu1i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu1i_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1i_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu1i_BFu0i(Test_Ul_BFu1i_BFu0i, "Ul_BFu1i_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu1i_BFu0ll()
{
  {
    init_simple_test("Ul_BFu1i_BFu0ll");
    static Ul_BFu1i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu1i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu1i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu1i_BFu0ll(Test_Ul_BFu1i_BFu0ll, "Ul_BFu1i_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu1i_BFu0s()
{
  {
    init_simple_test("Ul_BFu1i_BFu0s");
    static Ul_BFu1i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu1i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu1i_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1i_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu1i_BFu0s(Test_Ul_BFu1i_BFu0s, "Ul_BFu1i_BFu0s", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu1ll_BFu0c()
{
  {
    init_simple_test("Ul_BFu1ll_BFu0c");
    static Ul_BFu1ll_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu1ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu1ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu1ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu1ll_BFu0c(Test_Ul_BFu1ll_BFu0c, "Ul_BFu1ll_BFu0c", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu1ll_BFu0i()
{
  {
    init_simple_test("Ul_BFu1ll_BFu0i");
    static Ul_BFu1ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu1ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu1ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu1ll_BFu0i(Test_Ul_BFu1ll_BFu0i, "Ul_BFu1ll_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu1ll_BFu0ll()
{
  {
    init_simple_test("Ul_BFu1ll_BFu0ll");
    static Ul_BFu1ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu1ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu1ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu1ll_BFu0ll(Test_Ul_BFu1ll_BFu0ll, "Ul_BFu1ll_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu1ll_BFu0s()
{
  {
    init_simple_test("Ul_BFu1ll_BFu0s");
    static Ul_BFu1ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu1ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu1ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu1ll_BFu0s(Test_Ul_BFu1ll_BFu0s, "Ul_BFu1ll_BFu0s", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu1s_BFu0c()
{
  {
    init_simple_test("Ul_BFu1s_BFu0c");
    static Ul_BFu1s_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu1s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu1s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu1s_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1s_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu1s_BFu0c(Test_Ul_BFu1s_BFu0c, "Ul_BFu1s_BFu0c", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu1s_BFu0i()
{
  {
    init_simple_test("Ul_BFu1s_BFu0i");
    static Ul_BFu1s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu1s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu1s_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1s_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu1s_BFu0i(Test_Ul_BFu1s_BFu0i, "Ul_BFu1s_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu1s_BFu0ll()
{
  {
    init_simple_test("Ul_BFu1s_BFu0ll");
    static Ul_BFu1s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu1s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu1s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1s_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu1s_BFu0ll(Test_Ul_BFu1s_BFu0ll, "Ul_BFu1s_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu1s_BFu0s()
{
  {
    init_simple_test("Ul_BFu1s_BFu0s");
    static Ul_BFu1s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu1s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu1s_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1s_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu1s_BFu0s(Test_Ul_BFu1s_BFu0s, "Ul_BFu1s_BFu0s", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu31i_BFu0c()
{
  {
    init_simple_test("Ul_BFu31i_BFu0c");
    static Ul_BFu31i_BFu0c lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu31i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu31i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu31i_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu31i_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu31i_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu31i_BFu0c(Test_Ul_BFu31i_BFu0c, "Ul_BFu31i_BFu0c", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu31i_BFu0i()
{
  {
    init_simple_test("Ul_BFu31i_BFu0i");
    static Ul_BFu31i_BFu0i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu31i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu31i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu31i_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu31i_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu31i_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu31i_BFu0i(Test_Ul_BFu31i_BFu0i, "Ul_BFu31i_BFu0i", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu31i_BFu0ll()
{
  {
    init_simple_test("Ul_BFu31i_BFu0ll");
    static Ul_BFu31i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu31i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu31i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu31i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu31i_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu31i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu31i_BFu0ll(Test_Ul_BFu31i_BFu0ll, "Ul_BFu31i_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu31i_BFu0s()
{
  {
    init_simple_test("Ul_BFu31i_BFu0s");
    static Ul_BFu31i_BFu0s lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu31i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu31i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu31i_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu31i_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu31i_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu31i_BFu0s(Test_Ul_BFu31i_BFu0s, "Ul_BFu31i_BFu0s", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu31ll_BFu0c()
{
  {
    init_simple_test("Ul_BFu31ll_BFu0c");
    static Ul_BFu31ll_BFu0c lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu31ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu31ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu31ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu31ll_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu31ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu31ll_BFu0c(Test_Ul_BFu31ll_BFu0c, "Ul_BFu31ll_BFu0c", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu31ll_BFu0i()
{
  {
    init_simple_test("Ul_BFu31ll_BFu0i");
    static Ul_BFu31ll_BFu0i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu31ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu31ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu31ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu31ll_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu31ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu31ll_BFu0i(Test_Ul_BFu31ll_BFu0i, "Ul_BFu31ll_BFu0i", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu31ll_BFu0ll()
{
  {
    init_simple_test("Ul_BFu31ll_BFu0ll");
    static Ul_BFu31ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu31ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu31ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu31ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu31ll_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu31ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu31ll_BFu0ll(Test_Ul_BFu31ll_BFu0ll, "Ul_BFu31ll_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu31ll_BFu0s()
{
  {
    init_simple_test("Ul_BFu31ll_BFu0s");
    static Ul_BFu31ll_BFu0s lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu31ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu31ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu31ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu31ll_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu31ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu31ll_BFu0s(Test_Ul_BFu31ll_BFu0s, "Ul_BFu31ll_BFu0s", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu32i_BFu0c()
{
  {
    init_simple_test("Ul_BFu32i_BFu0c");
    static Ul_BFu32i_BFu0c lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu32i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu32i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu32i_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu32i_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu32i_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu32i_BFu0c(Test_Ul_BFu32i_BFu0c, "Ul_BFu32i_BFu0c", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu32i_BFu0i()
{
  {
    init_simple_test("Ul_BFu32i_BFu0i");
    static Ul_BFu32i_BFu0i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu32i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu32i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu32i_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu32i_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu32i_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu32i_BFu0i(Test_Ul_BFu32i_BFu0i, "Ul_BFu32i_BFu0i", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu32i_BFu0ll()
{
  {
    init_simple_test("Ul_BFu32i_BFu0ll");
    static Ul_BFu32i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu32i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu32i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu32i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu32i_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu32i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu32i_BFu0ll(Test_Ul_BFu32i_BFu0ll, "Ul_BFu32i_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu32i_BFu0s()
{
  {
    init_simple_test("Ul_BFu32i_BFu0s");
    static Ul_BFu32i_BFu0s lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu32i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu32i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu32i_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu32i_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu32i_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu32i_BFu0s(Test_Ul_BFu32i_BFu0s, "Ul_BFu32i_BFu0s", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu32ll_BFu0c()
{
  {
    init_simple_test("Ul_BFu32ll_BFu0c");
    static Ul_BFu32ll_BFu0c lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu32ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu32ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu32ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu32ll_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu32ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu32ll_BFu0c(Test_Ul_BFu32ll_BFu0c, "Ul_BFu32ll_BFu0c", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu32ll_BFu0i()
{
  {
    init_simple_test("Ul_BFu32ll_BFu0i");
    static Ul_BFu32ll_BFu0i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu32ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu32ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu32ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu32ll_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu32ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu32ll_BFu0i(Test_Ul_BFu32ll_BFu0i, "Ul_BFu32ll_BFu0i", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu32ll_BFu0ll()
{
  {
    init_simple_test("Ul_BFu32ll_BFu0ll");
    static Ul_BFu32ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu32ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu32ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu32ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu32ll_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu32ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu32ll_BFu0ll(Test_Ul_BFu32ll_BFu0ll, "Ul_BFu32ll_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu32ll_BFu0s()
{
  {
    init_simple_test("Ul_BFu32ll_BFu0s");
    static Ul_BFu32ll_BFu0s lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu32ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu32ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu32ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu32ll_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu32ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu32ll_BFu0s(Test_Ul_BFu32ll_BFu0s, "Ul_BFu32ll_BFu0s", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu33_BFu0c()
{
  {
    init_simple_test("Ul_BFu33_BFu0c");
    static Ul_BFu33_BFu0c lv;
    check2(sizeof(lv), 13, "sizeof(Ul_BFu33_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu33_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu33_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 33, 1, "Ul_BFu33_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 33, hide_ull(1LL<<32), "Ul_BFu33_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu33_BFu0c(Test_Ul_BFu33_BFu0c, "Ul_BFu33_BFu0c", 13);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu33_BFu0i()
{
  {
    init_simple_test("Ul_BFu33_BFu0i");
    static Ul_BFu33_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,16), "sizeof(Ul_BFu33_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu33_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu33_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 33, 1, "Ul_BFu33_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 33, hide_ull(1LL<<32), "Ul_BFu33_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu33_BFu0i(Test_Ul_BFu33_BFu0i, "Ul_BFu33_BFu0i", ABISELECT(16,16));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu33_BFu0ll()
{
  {
    init_simple_test("Ul_BFu33_BFu0ll");
    static Ul_BFu33_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,16), "sizeof(Ul_BFu33_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu33_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu33_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 33, 1, "Ul_BFu33_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 33, hide_ull(1LL<<32), "Ul_BFu33_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu33_BFu0ll(Test_Ul_BFu33_BFu0ll, "Ul_BFu33_BFu0ll", ABISELECT(16,16));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu33_BFu0s()
{
  {
    init_simple_test("Ul_BFu33_BFu0s");
    static Ul_BFu33_BFu0s lv;
    check2(sizeof(lv), ABISELECT(14,14), "sizeof(Ul_BFu33_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu33_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu33_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 33, 1, "Ul_BFu33_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 33, hide_ull(1LL<<32), "Ul_BFu33_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu33_BFu0s(Test_Ul_BFu33_BFu0s, "Ul_BFu33_BFu0s", ABISELECT(14,14));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu7c_BFu0c()
{
  {
    init_simple_test("Ul_BFu7c_BFu0c");
    static Ul_BFu7c_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu7c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu7c_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu7c_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7c_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7c_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu7c_BFu0c(Test_Ul_BFu7c_BFu0c, "Ul_BFu7c_BFu0c", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu7c_BFu0i()
{
  {
    init_simple_test("Ul_BFu7c_BFu0i");
    static Ul_BFu7c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu7c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7c_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu7c_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7c_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7c_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu7c_BFu0i(Test_Ul_BFu7c_BFu0i, "Ul_BFu7c_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu7c_BFu0ll()
{
  {
    init_simple_test("Ul_BFu7c_BFu0ll");
    static Ul_BFu7c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu7c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu7c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7c_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7c_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu7c_BFu0ll(Test_Ul_BFu7c_BFu0ll, "Ul_BFu7c_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu7c_BFu0s()
{
  {
    init_simple_test("Ul_BFu7c_BFu0s");
    static Ul_BFu7c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu7c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7c_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu7c_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7c_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7c_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu7c_BFu0s(Test_Ul_BFu7c_BFu0s, "Ul_BFu7c_BFu0s", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu7i_BFu0c()
{
  {
    init_simple_test("Ul_BFu7i_BFu0c");
    static Ul_BFu7i_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu7i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu7i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu7i_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7i_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7i_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu7i_BFu0c(Test_Ul_BFu7i_BFu0c, "Ul_BFu7i_BFu0c", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu7i_BFu0i()
{
  {
    init_simple_test("Ul_BFu7i_BFu0i");
    static Ul_BFu7i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu7i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu7i_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7i_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7i_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu7i_BFu0i(Test_Ul_BFu7i_BFu0i, "Ul_BFu7i_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu7i_BFu0ll()
{
  {
    init_simple_test("Ul_BFu7i_BFu0ll");
    static Ul_BFu7i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu7i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu7i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7i_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu7i_BFu0ll(Test_Ul_BFu7i_BFu0ll, "Ul_BFu7i_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu7i_BFu0s()
{
  {
    init_simple_test("Ul_BFu7i_BFu0s");
    static Ul_BFu7i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu7i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu7i_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7i_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7i_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu7i_BFu0s(Test_Ul_BFu7i_BFu0s, "Ul_BFu7i_BFu0s", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu7ll_BFu0c()
{
  {
    init_simple_test("Ul_BFu7ll_BFu0c");
    static Ul_BFu7ll_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu7ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu7ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu7ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7ll_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu7ll_BFu0c(Test_Ul_BFu7ll_BFu0c, "Ul_BFu7ll_BFu0c", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu7ll_BFu0i()
{
  {
    init_simple_test("Ul_BFu7ll_BFu0i");
    static Ul_BFu7ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu7ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu7ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7ll_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu7ll_BFu0i(Test_Ul_BFu7ll_BFu0i, "Ul_BFu7ll_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu7ll_BFu0ll()
{
  {
    init_simple_test("Ul_BFu7ll_BFu0ll");
    static Ul_BFu7ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu7ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu7ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7ll_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu7ll_BFu0ll(Test_Ul_BFu7ll_BFu0ll, "Ul_BFu7ll_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu7ll_BFu0s()
{
  {
    init_simple_test("Ul_BFu7ll_BFu0s");
    static Ul_BFu7ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu7ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu7ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7ll_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu7ll_BFu0s(Test_Ul_BFu7ll_BFu0s, "Ul_BFu7ll_BFu0s", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu7s_BFu0c()
{
  {
    init_simple_test("Ul_BFu7s_BFu0c");
    static Ul_BFu7s_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu7s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu7s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu7s_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7s_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7s_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu7s_BFu0c(Test_Ul_BFu7s_BFu0c, "Ul_BFu7s_BFu0c", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu7s_BFu0i()
{
  {
    init_simple_test("Ul_BFu7s_BFu0i");
    static Ul_BFu7s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu7s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu7s_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7s_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7s_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu7s_BFu0i(Test_Ul_BFu7s_BFu0i, "Ul_BFu7s_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu7s_BFu0ll()
{
  {
    init_simple_test("Ul_BFu7s_BFu0ll");
    static Ul_BFu7s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu7s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu7s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7s_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7s_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu7s_BFu0ll(Test_Ul_BFu7s_BFu0ll, "Ul_BFu7s_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu7s_BFu0s()
{
  {
    init_simple_test("Ul_BFu7s_BFu0s");
    static Ul_BFu7s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu7s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu7s_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7s_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7s_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu7s_BFu0s(Test_Ul_BFu7s_BFu0s, "Ul_BFu7s_BFu0s", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu8c_BFu0c()
{
  {
    init_simple_test("Ul_BFu8c_BFu0c");
    static Ul_BFu8c_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu8c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu8c_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu8c_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8c_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8c_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu8c_BFu0c(Test_Ul_BFu8c_BFu0c, "Ul_BFu8c_BFu0c", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu8c_BFu0i()
{
  {
    init_simple_test("Ul_BFu8c_BFu0i");
    static Ul_BFu8c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu8c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8c_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu8c_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8c_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8c_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu8c_BFu0i(Test_Ul_BFu8c_BFu0i, "Ul_BFu8c_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu8c_BFu0ll()
{
  {
    init_simple_test("Ul_BFu8c_BFu0ll");
    static Ul_BFu8c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu8c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu8c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8c_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8c_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu8c_BFu0ll(Test_Ul_BFu8c_BFu0ll, "Ul_BFu8c_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu8c_BFu0s()
{
  {
    init_simple_test("Ul_BFu8c_BFu0s");
    static Ul_BFu8c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu8c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8c_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu8c_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8c_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8c_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu8c_BFu0s(Test_Ul_BFu8c_BFu0s, "Ul_BFu8c_BFu0s", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu8i_BFu0c()
{
  {
    init_simple_test("Ul_BFu8i_BFu0c");
    static Ul_BFu8i_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu8i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu8i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu8i_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8i_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8i_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu8i_BFu0c(Test_Ul_BFu8i_BFu0c, "Ul_BFu8i_BFu0c", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu8i_BFu0i()
{
  {
    init_simple_test("Ul_BFu8i_BFu0i");
    static Ul_BFu8i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu8i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu8i_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8i_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8i_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu8i_BFu0i(Test_Ul_BFu8i_BFu0i, "Ul_BFu8i_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu8i_BFu0ll()
{
  {
    init_simple_test("Ul_BFu8i_BFu0ll");
    static Ul_BFu8i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu8i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu8i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8i_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu8i_BFu0ll(Test_Ul_BFu8i_BFu0ll, "Ul_BFu8i_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu8i_BFu0s()
{
  {
    init_simple_test("Ul_BFu8i_BFu0s");
    static Ul_BFu8i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu8i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu8i_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8i_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8i_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu8i_BFu0s(Test_Ul_BFu8i_BFu0s, "Ul_BFu8i_BFu0s", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu8ll_BFu0c()
{
  {
    init_simple_test("Ul_BFu8ll_BFu0c");
    static Ul_BFu8ll_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu8ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu8ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu8ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8ll_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu8ll_BFu0c(Test_Ul_BFu8ll_BFu0c, "Ul_BFu8ll_BFu0c", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu8ll_BFu0i()
{
  {
    init_simple_test("Ul_BFu8ll_BFu0i");
    static Ul_BFu8ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu8ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu8ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8ll_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu8ll_BFu0i(Test_Ul_BFu8ll_BFu0i, "Ul_BFu8ll_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu8ll_BFu0ll()
{
  {
    init_simple_test("Ul_BFu8ll_BFu0ll");
    static Ul_BFu8ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu8ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu8ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8ll_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu8ll_BFu0ll(Test_Ul_BFu8ll_BFu0ll, "Ul_BFu8ll_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu8ll_BFu0s()
{
  {
    init_simple_test("Ul_BFu8ll_BFu0s");
    static Ul_BFu8ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu8ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu8ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8ll_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu8ll_BFu0s(Test_Ul_BFu8ll_BFu0s, "Ul_BFu8ll_BFu0s", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu8s_BFu0c()
{
  {
    init_simple_test("Ul_BFu8s_BFu0c");
    static Ul_BFu8s_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu8s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu8s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu8s_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8s_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8s_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu8s_BFu0c(Test_Ul_BFu8s_BFu0c, "Ul_BFu8s_BFu0c", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu8s_BFu0i()
{
  {
    init_simple_test("Ul_BFu8s_BFu0i");
    static Ul_BFu8s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu8s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu8s_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8s_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8s_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu8s_BFu0i(Test_Ul_BFu8s_BFu0i, "Ul_BFu8s_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu8s_BFu0ll()
{
  {
    init_simple_test("Ul_BFu8s_BFu0ll");
    static Ul_BFu8s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu8s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu8s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8s_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8s_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu8s_BFu0ll(Test_Ul_BFu8s_BFu0ll, "Ul_BFu8s_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu8s_BFu0s()
{
  {
    init_simple_test("Ul_BFu8s_BFu0s");
    static Ul_BFu8s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu8s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu8s_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8s_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8s_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu8s_BFu0s(Test_Ul_BFu8s_BFu0s, "Ul_BFu8s_BFu0s", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu9i_BFu0c()
{
  {
    init_simple_test("Ul_BFu9i_BFu0c");
    static Ul_BFu9i_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu9i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu9i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu9i_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9i_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9i_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu9i_BFu0c(Test_Ul_BFu9i_BFu0c, "Ul_BFu9i_BFu0c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu9i_BFu0i()
{
  {
    init_simple_test("Ul_BFu9i_BFu0i");
    static Ul_BFu9i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu9i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu9i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu9i_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9i_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9i_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu9i_BFu0i(Test_Ul_BFu9i_BFu0i, "Ul_BFu9i_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu9i_BFu0ll()
{
  {
    init_simple_test("Ul_BFu9i_BFu0ll");
    static Ul_BFu9i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu9i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu9i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu9i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9i_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu9i_BFu0ll(Test_Ul_BFu9i_BFu0ll, "Ul_BFu9i_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu9i_BFu0s()
{
  {
    init_simple_test("Ul_BFu9i_BFu0s");
    static Ul_BFu9i_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu9i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu9i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu9i_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9i_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9i_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu9i_BFu0s(Test_Ul_BFu9i_BFu0s, "Ul_BFu9i_BFu0s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu9ll_BFu0c()
{
  {
    init_simple_test("Ul_BFu9ll_BFu0c");
    static Ul_BFu9ll_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu9ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu9ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu9ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9ll_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu9ll_BFu0c(Test_Ul_BFu9ll_BFu0c, "Ul_BFu9ll_BFu0c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu9ll_BFu0i()
{
  {
    init_simple_test("Ul_BFu9ll_BFu0i");
    static Ul_BFu9ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu9ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu9ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu9ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9ll_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu9ll_BFu0i(Test_Ul_BFu9ll_BFu0i, "Ul_BFu9ll_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu9ll_BFu0ll()
{
  {
    init_simple_test("Ul_BFu9ll_BFu0ll");
    static Ul_BFu9ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu9ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu9ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu9ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9ll_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu9ll_BFu0ll(Test_Ul_BFu9ll_BFu0ll, "Ul_BFu9ll_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu9ll_BFu0s()
{
  {
    init_simple_test("Ul_BFu9ll_BFu0s");
    static Ul_BFu9ll_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu9ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu9ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu9ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9ll_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu9ll_BFu0s(Test_Ul_BFu9ll_BFu0s, "Ul_BFu9ll_BFu0s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu9s_BFu0c()
{
  {
    init_simple_test("Ul_BFu9s_BFu0c");
    static Ul_BFu9s_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu9s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu9s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu9s_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9s_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9s_BFu0c");
  }
}
static Arrange_To_Call_Me vUl_BFu9s_BFu0c(Test_Ul_BFu9s_BFu0c, "Ul_BFu9s_BFu0c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu9s_BFu0i()
{
  {
    init_simple_test("Ul_BFu9s_BFu0i");
    static Ul_BFu9s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu9s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu9s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu9s_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9s_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9s_BFu0i");
  }
}
static Arrange_To_Call_Me vUl_BFu9s_BFu0i(Test_Ul_BFu9s_BFu0i, "Ul_BFu9s_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu9s_BFu0ll()
{
  {
    init_simple_test("Ul_BFu9s_BFu0ll");
    static Ul_BFu9s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu9s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu9s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu9s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9s_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9s_BFu0ll");
  }
}
static Arrange_To_Call_Me vUl_BFu9s_BFu0ll(Test_Ul_BFu9s_BFu0ll, "Ul_BFu9s_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_BFu9s_BFu0s()
{
  {
    init_simple_test("Ul_BFu9s_BFu0s");
    static Ul_BFu9s_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu9s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu9s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu9s_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9s_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9s_BFu0s");
  }
}
static Arrange_To_Call_Me vUl_BFu9s_BFu0s(Test_Ul_BFu9s_BFu0s, "Ul_BFu9s_BFu0s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_C_BFu0c()
{
  {
    init_simple_test("Ul_C_BFu0c");
    static Ul_C_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_C_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_C_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_C_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_C_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUl_C_BFu0c(Test_Ul_C_BFu0c, "Ul_C_BFu0c", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_C_BFu0i()
{
  {
    init_simple_test("Ul_C_BFu0i");
    static Ul_C_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_C_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_C_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_C_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_C_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUl_C_BFu0i(Test_Ul_C_BFu0i, "Ul_C_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_C_BFu0ll()
{
  {
    init_simple_test("Ul_C_BFu0ll");
    static Ul_C_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_C_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_C_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_C_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_C_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUl_C_BFu0ll(Test_Ul_C_BFu0ll, "Ul_C_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_C_BFu0s()
{
  {
    init_simple_test("Ul_C_BFu0s");
    static Ul_C_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_C_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_C_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_C_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_C_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUl_C_BFu0s(Test_Ul_C_BFu0s, "Ul_C_BFu0s", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_D_BFu0c()
{
  {
    init_simple_test("Ul_D_BFu0c");
    static Ul_D_BFu0c lv;
    check2(sizeof(lv), 16, "sizeof(Ul_D_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_D_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_D_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_D_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUl_D_BFu0c(Test_Ul_D_BFu0c, "Ul_D_BFu0c", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_D_BFu0i()
{
  {
    init_simple_test("Ul_D_BFu0i");
    static Ul_D_BFu0i lv;
    check2(sizeof(lv), 16, "sizeof(Ul_D_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_D_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_D_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_D_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUl_D_BFu0i(Test_Ul_D_BFu0i, "Ul_D_BFu0i", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_D_BFu0ll()
{
  {
    init_simple_test("Ul_D_BFu0ll");
    static Ul_D_BFu0ll lv;
    check2(sizeof(lv), 16, "sizeof(Ul_D_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_D_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_D_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_D_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUl_D_BFu0ll(Test_Ul_D_BFu0ll, "Ul_D_BFu0ll", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_D_BFu0s()
{
  {
    init_simple_test("Ul_D_BFu0s");
    static Ul_D_BFu0s lv;
    check2(sizeof(lv), 16, "sizeof(Ul_D_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_D_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_D_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_D_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUl_D_BFu0s(Test_Ul_D_BFu0s, "Ul_D_BFu0s", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_F_BFu0c()
{
  {
    init_simple_test("Ul_F_BFu0c");
    static Ul_F_BFu0c lv;
    check2(sizeof(lv), 12, "sizeof(Ul_F_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_F_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_F_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_F_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUl_F_BFu0c(Test_Ul_F_BFu0c, "Ul_F_BFu0c", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_F_BFu0i()
{
  {
    init_simple_test("Ul_F_BFu0i");
    static Ul_F_BFu0i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_F_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_F_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_F_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_F_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUl_F_BFu0i(Test_Ul_F_BFu0i, "Ul_F_BFu0i", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_F_BFu0ll()
{
  {
    init_simple_test("Ul_F_BFu0ll");
    static Ul_F_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_F_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_F_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_F_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_F_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUl_F_BFu0ll(Test_Ul_F_BFu0ll, "Ul_F_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_F_BFu0s()
{
  {
    init_simple_test("Ul_F_BFu0s");
    static Ul_F_BFu0s lv;
    check2(sizeof(lv), 12, "sizeof(Ul_F_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_F_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_F_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_F_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUl_F_BFu0s(Test_Ul_F_BFu0s, "Ul_F_BFu0s", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_I_BFu0c()
{
  {
    init_simple_test("Ul_I_BFu0c");
    static Ul_I_BFu0c lv;
    check2(sizeof(lv), 12, "sizeof(Ul_I_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_I_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_I_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_I_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUl_I_BFu0c(Test_Ul_I_BFu0c, "Ul_I_BFu0c", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_I_BFu0i()
{
  {
    init_simple_test("Ul_I_BFu0i");
    static Ul_I_BFu0i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_I_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_I_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_I_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_I_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUl_I_BFu0i(Test_Ul_I_BFu0i, "Ul_I_BFu0i", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_I_BFu0ll()
{
  {
    init_simple_test("Ul_I_BFu0ll");
    static Ul_I_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_I_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_I_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_I_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_I_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUl_I_BFu0ll(Test_Ul_I_BFu0ll, "Ul_I_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_I_BFu0s()
{
  {
    init_simple_test("Ul_I_BFu0s");
    static Ul_I_BFu0s lv;
    check2(sizeof(lv), 12, "sizeof(Ul_I_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_I_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_I_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_I_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUl_I_BFu0s(Test_Ul_I_BFu0s, "Ul_I_BFu0s", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Ip_BFu0c()
{
  {
    init_simple_test("Ul_Ip_BFu0c");
    static Ul_Ip_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Ip_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Ip_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_Ip_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_Ip_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUl_Ip_BFu0c(Test_Ul_Ip_BFu0c, "Ul_Ip_BFu0c", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Ip_BFu0i()
{
  {
    init_simple_test("Ul_Ip_BFu0i");
    static Ul_Ip_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Ip_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Ip_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_Ip_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_Ip_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUl_Ip_BFu0i(Test_Ul_Ip_BFu0i, "Ul_Ip_BFu0i", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Ip_BFu0ll()
{
  {
    init_simple_test("Ul_Ip_BFu0ll");
    static Ul_Ip_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Ip_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Ip_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_Ip_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Ip_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUl_Ip_BFu0ll(Test_Ul_Ip_BFu0ll, "Ul_Ip_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Ip_BFu0s()
{
  {
    init_simple_test("Ul_Ip_BFu0s");
    static Ul_Ip_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Ip_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Ip_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_Ip_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_Ip_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUl_Ip_BFu0s(Test_Ul_Ip_BFu0s, "Ul_Ip_BFu0s", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_L_BFu0c()
{
  {
    init_simple_test("Ul_L_BFu0c");
    static Ul_L_BFu0c lv;
    check2(sizeof(lv), 16, "sizeof(Ul_L_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_L_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_L_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_L_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUl_L_BFu0c(Test_Ul_L_BFu0c, "Ul_L_BFu0c", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_L_BFu0i()
{
  {
    init_simple_test("Ul_L_BFu0i");
    static Ul_L_BFu0i lv;
    check2(sizeof(lv), 16, "sizeof(Ul_L_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_L_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_L_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_L_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUl_L_BFu0i(Test_Ul_L_BFu0i, "Ul_L_BFu0i", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_L_BFu0ll()
{
  {
    init_simple_test("Ul_L_BFu0ll");
    static Ul_L_BFu0ll lv;
    check2(sizeof(lv), 16, "sizeof(Ul_L_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_L_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_L_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_L_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUl_L_BFu0ll(Test_Ul_L_BFu0ll, "Ul_L_BFu0ll", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_L_BFu0s()
{
  {
    init_simple_test("Ul_L_BFu0s");
    static Ul_L_BFu0s lv;
    check2(sizeof(lv), 16, "sizeof(Ul_L_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_L_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_L_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_L_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUl_L_BFu0s(Test_Ul_L_BFu0s, "Ul_L_BFu0s", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_S_BFu0c()
{
  {
    init_simple_test("Ul_S_BFu0c");
    static Ul_S_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_S_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_S_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_S_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_S_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUl_S_BFu0c(Test_Ul_S_BFu0c, "Ul_S_BFu0c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_S_BFu0i()
{
  {
    init_simple_test("Ul_S_BFu0i");
    static Ul_S_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_S_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_S_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_S_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_S_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUl_S_BFu0i(Test_Ul_S_BFu0i, "Ul_S_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_S_BFu0ll()
{
  {
    init_simple_test("Ul_S_BFu0ll");
    static Ul_S_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_S_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_S_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_S_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_S_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUl_S_BFu0ll(Test_Ul_S_BFu0ll, "Ul_S_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_S_BFu0s()
{
  {
    init_simple_test("Ul_S_BFu0s");
    static Ul_S_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_S_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_S_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_S_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_S_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUl_S_BFu0s(Test_Ul_S_BFu0s, "Ul_S_BFu0s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Uc_BFu0c()
{
  {
    init_simple_test("Ul_Uc_BFu0c");
    static Ul_Uc_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_Uc_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Uc_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_Uc_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_Uc_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUl_Uc_BFu0c(Test_Ul_Uc_BFu0c, "Ul_Uc_BFu0c", 9);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Uc_BFu0i()
{
  {
    init_simple_test("Ul_Uc_BFu0i");
    static Ul_Uc_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_Uc_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Uc_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_Uc_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_Uc_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUl_Uc_BFu0i(Test_Ul_Uc_BFu0i, "Ul_Uc_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Uc_BFu0ll()
{
  {
    init_simple_test("Ul_Uc_BFu0ll");
    static Ul_Uc_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Uc_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Uc_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_Uc_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Uc_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUl_Uc_BFu0ll(Test_Ul_Uc_BFu0ll, "Ul_Uc_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Uc_BFu0s()
{
  {
    init_simple_test("Ul_Uc_BFu0s");
    static Ul_Uc_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_Uc_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Uc_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_Uc_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_Uc_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUl_Uc_BFu0s(Test_Ul_Uc_BFu0s, "Ul_Uc_BFu0s", ABISELECT(10,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Ui_BFu0c()
{
  {
    init_simple_test("Ul_Ui_BFu0c");
    static Ul_Ui_BFu0c lv;
    check2(sizeof(lv), 12, "sizeof(Ul_Ui_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Ui_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_Ui_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_Ui_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUl_Ui_BFu0c(Test_Ul_Ui_BFu0c, "Ul_Ui_BFu0c", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Ui_BFu0i()
{
  {
    init_simple_test("Ul_Ui_BFu0i");
    static Ul_Ui_BFu0i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_Ui_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Ui_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_Ui_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_Ui_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUl_Ui_BFu0i(Test_Ul_Ui_BFu0i, "Ul_Ui_BFu0i", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Ui_BFu0ll()
{
  {
    init_simple_test("Ul_Ui_BFu0ll");
    static Ul_Ui_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Ui_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Ui_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_Ui_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Ui_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUl_Ui_BFu0ll(Test_Ul_Ui_BFu0ll, "Ul_Ui_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Ui_BFu0s()
{
  {
    init_simple_test("Ul_Ui_BFu0s");
    static Ul_Ui_BFu0s lv;
    check2(sizeof(lv), 12, "sizeof(Ul_Ui_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Ui_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_Ui_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_Ui_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUl_Ui_BFu0s(Test_Ul_Ui_BFu0s, "Ul_Ui_BFu0s", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Ul_BFu0c()
{
  {
    init_simple_test("Ul_Ul_BFu0c");
    static Ul_Ul_BFu0c lv;
    check2(sizeof(lv), 16, "sizeof(Ul_Ul_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Ul_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_Ul_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_Ul_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUl_Ul_BFu0c(Test_Ul_Ul_BFu0c, "Ul_Ul_BFu0c", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Ul_BFu0i()
{
  {
    init_simple_test("Ul_Ul_BFu0i");
    static Ul_Ul_BFu0i lv;
    check2(sizeof(lv), 16, "sizeof(Ul_Ul_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Ul_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_Ul_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_Ul_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUl_Ul_BFu0i(Test_Ul_Ul_BFu0i, "Ul_Ul_BFu0i", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Ul_BFu0ll()
{
  {
    init_simple_test("Ul_Ul_BFu0ll");
    static Ul_Ul_BFu0ll lv;
    check2(sizeof(lv), 16, "sizeof(Ul_Ul_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Ul_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_Ul_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Ul_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUl_Ul_BFu0ll(Test_Ul_Ul_BFu0ll, "Ul_Ul_BFu0ll", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Ul_BFu0s()
{
  {
    init_simple_test("Ul_Ul_BFu0s");
    static Ul_Ul_BFu0s lv;
    check2(sizeof(lv), 16, "sizeof(Ul_Ul_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Ul_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_Ul_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_Ul_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUl_Ul_BFu0s(Test_Ul_Ul_BFu0s, "Ul_Ul_BFu0s", 16);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Us_BFu0c()
{
  {
    init_simple_test("Ul_Us_BFu0c");
    static Ul_Us_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_Us_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Us_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_Us_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_Us_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUl_Us_BFu0c(Test_Ul_Us_BFu0c, "Ul_Us_BFu0c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Us_BFu0i()
{
  {
    init_simple_test("Ul_Us_BFu0i");
    static Ul_Us_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_Us_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Us_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_Us_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_Us_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUl_Us_BFu0i(Test_Ul_Us_BFu0i, "Ul_Us_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Us_BFu0ll()
{
  {
    init_simple_test("Ul_Us_BFu0ll");
    static Ul_Us_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Us_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Us_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_Us_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Us_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUl_Us_BFu0ll(Test_Ul_Us_BFu0ll, "Ul_Us_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Us_BFu0s()
{
  {
    init_simple_test("Ul_Us_BFu0s");
    static Ul_Us_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_Us_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Us_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_Us_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_Us_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUl_Us_BFu0s(Test_Ul_Us_BFu0s, "Ul_Us_BFu0s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Vp_BFu0c()
{
  {
    init_simple_test("Ul_Vp_BFu0c");
    static Ul_Vp_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Vp_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Vp_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_Vp_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_Vp_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUl_Vp_BFu0c(Test_Ul_Vp_BFu0c, "Ul_Vp_BFu0c", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Vp_BFu0i()
{
  {
    init_simple_test("Ul_Vp_BFu0i");
    static Ul_Vp_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Vp_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Vp_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_Vp_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_Vp_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUl_Vp_BFu0i(Test_Ul_Vp_BFu0i, "Ul_Vp_BFu0i", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Vp_BFu0ll()
{
  {
    init_simple_test("Ul_Vp_BFu0ll");
    static Ul_Vp_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Vp_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Vp_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_Vp_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Vp_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUl_Vp_BFu0ll(Test_Ul_Vp_BFu0ll, "Ul_Vp_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Ul_Vp_BFu0s()
{
  {
    init_simple_test("Ul_Vp_BFu0s");
    static Ul_Vp_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Vp_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Vp_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_Vp_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_Vp_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUl_Vp_BFu0s(Test_Ul_Vp_BFu0s, "Ul_Vp_BFu0s", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c()
{
  {
    init_simple_test("Us_BFu0c");
    static Us_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(Us_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vUs_BFu0c(Test_Us_BFu0c, "Us_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu0c()
{
  {
    init_simple_test("Us_BFu0c_BFu0c");
    static Us_BFu0c_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(Us_BFu0c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu0c(Test_Us_BFu0c_BFu0c, "Us_BFu0c_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu0i()
{
  {
    init_simple_test("Us_BFu0c_BFu0i");
    static Us_BFu0c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu0c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0c_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu0i(Test_Us_BFu0c_BFu0i, "Us_BFu0c_BFu0i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu0ll()
{
  {
    init_simple_test("Us_BFu0c_BFu0ll");
    static Us_BFu0c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu0c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu0ll(Test_Us_BFu0c_BFu0ll, "Us_BFu0c_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu0s()
{
  {
    init_simple_test("Us_BFu0c_BFu0s");
    static Us_BFu0c_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Us_BFu0c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0c_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu0s(Test_Us_BFu0c_BFu0s, "Us_BFu0c_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu15i()
{
  {
    init_simple_test("Us_BFu0c_BFu15i");
    static Us_BFu0c_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu15i)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu15i.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu0c_BFu15i");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu0c_BFu15i");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu15i(Test_Us_BFu0c_BFu15i, "Us_BFu0c_BFu15i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu15ll()
{
  {
    init_simple_test("Us_BFu0c_BFu15ll");
    static Us_BFu0c_BFu15ll lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu15ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu15ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu0c_BFu15ll");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu0c_BFu15ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu15ll(Test_Us_BFu0c_BFu15ll, "Us_BFu0c_BFu15ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu15s()
{
  {
    init_simple_test("Us_BFu0c_BFu15s");
    static Us_BFu0c_BFu15s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu15s)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu15s.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu0c_BFu15s");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu0c_BFu15s");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu15s(Test_Us_BFu0c_BFu15s, "Us_BFu0c_BFu15s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu16i()
{
  {
    init_simple_test("Us_BFu0c_BFu16i");
    static Us_BFu0c_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu16i)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu16i.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu0c_BFu16i");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu0c_BFu16i");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu16i(Test_Us_BFu0c_BFu16i, "Us_BFu0c_BFu16i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu16ll()
{
  {
    init_simple_test("Us_BFu0c_BFu16ll");
    static Us_BFu0c_BFu16ll lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu16ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu16ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu0c_BFu16ll");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu0c_BFu16ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu16ll(Test_Us_BFu0c_BFu16ll, "Us_BFu0c_BFu16ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu16s()
{
  {
    init_simple_test("Us_BFu0c_BFu16s");
    static Us_BFu0c_BFu16s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu16s)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu16s.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu0c_BFu16s");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu0c_BFu16s");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu16s(Test_Us_BFu0c_BFu16s, "Us_BFu0c_BFu16s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu17i()
{
  {
    init_simple_test("Us_BFu0c_BFu17i");
    static Us_BFu0c_BFu17i lv;
    check2(sizeof(lv), 5, "sizeof(Us_BFu0c_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu17i)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu17i.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu0c_BFu17i");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu0c_BFu17i");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu17i(Test_Us_BFu0c_BFu17i, "Us_BFu0c_BFu17i", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu17ll()
{
  {
    init_simple_test("Us_BFu0c_BFu17ll");
    static Us_BFu0c_BFu17ll lv;
    check2(sizeof(lv), 5, "sizeof(Us_BFu0c_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu17ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu17ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu0c_BFu17ll");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu0c_BFu17ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu17ll(Test_Us_BFu0c_BFu17ll, "Us_BFu0c_BFu17ll", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu1c()
{
  {
    init_simple_test("Us_BFu0c_BFu1c");
    static Us_BFu0c_BFu1c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu1c)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu1c.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu0c_BFu1c");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu1c(Test_Us_BFu0c_BFu1c, "Us_BFu0c_BFu1c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu1i()
{
  {
    init_simple_test("Us_BFu0c_BFu1i");
    static Us_BFu0c_BFu1i lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu1i)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu1i.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu0c_BFu1i");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu1i(Test_Us_BFu0c_BFu1i, "Us_BFu0c_BFu1i", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu1ll()
{
  {
    init_simple_test("Us_BFu0c_BFu1ll");
    static Us_BFu0c_BFu1ll lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu1ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu1ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu0c_BFu1ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu1ll(Test_Us_BFu0c_BFu1ll, "Us_BFu0c_BFu1ll", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu1s()
{
  {
    init_simple_test("Us_BFu0c_BFu1s");
    static Us_BFu0c_BFu1s lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu1s)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu1s.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu0c_BFu1s");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu1s(Test_Us_BFu0c_BFu1s, "Us_BFu0c_BFu1s", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu31i()
{
  {
    init_simple_test("Us_BFu0c_BFu31i");
    static Us_BFu0c_BFu31i lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0c_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu31i)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu31i.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu0c_BFu31i");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu0c_BFu31i");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu31i(Test_Us_BFu0c_BFu31i, "Us_BFu0c_BFu31i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu31ll()
{
  {
    init_simple_test("Us_BFu0c_BFu31ll");
    static Us_BFu0c_BFu31ll lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0c_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu31ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu31ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu0c_BFu31ll");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu0c_BFu31ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu31ll(Test_Us_BFu0c_BFu31ll, "Us_BFu0c_BFu31ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu32i()
{
  {
    init_simple_test("Us_BFu0c_BFu32i");
    static Us_BFu0c_BFu32i lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0c_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu32i)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu32i.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu0c_BFu32i");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu0c_BFu32i");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu32i(Test_Us_BFu0c_BFu32i, "Us_BFu0c_BFu32i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu32ll()
{
  {
    init_simple_test("Us_BFu0c_BFu32ll");
    static Us_BFu0c_BFu32ll lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0c_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu32ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu32ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu0c_BFu32ll");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu0c_BFu32ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu32ll(Test_Us_BFu0c_BFu32ll, "Us_BFu0c_BFu32ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu33()
{
  {
    init_simple_test("Us_BFu0c_BFu33");
    static Us_BFu0c_BFu33 lv;
    check2(sizeof(lv), 7, "sizeof(Us_BFu0c_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu33)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu33.v1");
    set_bf_and_test(lv, v2, 2, 0, 33, 1, "Us_BFu0c_BFu33");
    set_bf_and_test(lv, v2, 2, 0, 33, hide_ull(1LL<<32), "Us_BFu0c_BFu33");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu33(Test_Us_BFu0c_BFu33, "Us_BFu0c_BFu33", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu7c()
{
  {
    init_simple_test("Us_BFu0c_BFu7c");
    static Us_BFu0c_BFu7c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu7c)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu7c.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu0c_BFu7c");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu0c_BFu7c");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu7c(Test_Us_BFu0c_BFu7c, "Us_BFu0c_BFu7c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu7i()
{
  {
    init_simple_test("Us_BFu0c_BFu7i");
    static Us_BFu0c_BFu7i lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu7i)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu7i.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu0c_BFu7i");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu0c_BFu7i");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu7i(Test_Us_BFu0c_BFu7i, "Us_BFu0c_BFu7i", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu7ll()
{
  {
    init_simple_test("Us_BFu0c_BFu7ll");
    static Us_BFu0c_BFu7ll lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu7ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu7ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu0c_BFu7ll");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu0c_BFu7ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu7ll(Test_Us_BFu0c_BFu7ll, "Us_BFu0c_BFu7ll", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu7s()
{
  {
    init_simple_test("Us_BFu0c_BFu7s");
    static Us_BFu0c_BFu7s lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu7s)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu7s.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu0c_BFu7s");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu0c_BFu7s");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu7s(Test_Us_BFu0c_BFu7s, "Us_BFu0c_BFu7s", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu8c()
{
  {
    init_simple_test("Us_BFu0c_BFu8c");
    static Us_BFu0c_BFu8c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu8c)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu8c.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu0c_BFu8c");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu0c_BFu8c");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu8c(Test_Us_BFu0c_BFu8c, "Us_BFu0c_BFu8c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu8i()
{
  {
    init_simple_test("Us_BFu0c_BFu8i");
    static Us_BFu0c_BFu8i lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu8i)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu8i.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu0c_BFu8i");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu0c_BFu8i");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu8i(Test_Us_BFu0c_BFu8i, "Us_BFu0c_BFu8i", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu8ll()
{
  {
    init_simple_test("Us_BFu0c_BFu8ll");
    static Us_BFu0c_BFu8ll lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu8ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu8ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu0c_BFu8ll");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu0c_BFu8ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu8ll(Test_Us_BFu0c_BFu8ll, "Us_BFu0c_BFu8ll", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu8s()
{
  {
    init_simple_test("Us_BFu0c_BFu8s");
    static Us_BFu0c_BFu8s lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu8s)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu8s.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu0c_BFu8s");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu0c_BFu8s");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu8s(Test_Us_BFu0c_BFu8s, "Us_BFu0c_BFu8s", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu9i()
{
  {
    init_simple_test("Us_BFu0c_BFu9i");
    static Us_BFu0c_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu9i)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu9i.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu0c_BFu9i");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu0c_BFu9i");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu9i(Test_Us_BFu0c_BFu9i, "Us_BFu0c_BFu9i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu9ll()
{
  {
    init_simple_test("Us_BFu0c_BFu9ll");
    static Us_BFu0c_BFu9ll lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu9ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu9ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu0c_BFu9ll");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu0c_BFu9ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu9ll(Test_Us_BFu0c_BFu9ll, "Us_BFu0c_BFu9ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_BFu9s()
{
  {
    init_simple_test("Us_BFu0c_BFu9s");
    static Us_BFu0c_BFu9s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu9s)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu9s.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu0c_BFu9s");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu0c_BFu9s");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_BFu9s(Test_Us_BFu0c_BFu9s, "Us_BFu0c_BFu9s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_C()
{
  {
    init_simple_test("Us_BFu0c_C");
    static Us_BFu0c_C lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_C)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_C)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_C.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_C.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_C(Test_Us_BFu0c_C, "Us_BFu0c_C", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_D()
{
  {
    init_simple_test("Us_BFu0c_D");
    static Us_BFu0c_D lv;
    check2(sizeof(lv), 10, "sizeof(Us_BFu0c_D)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_D)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_D.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_D.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_D(Test_Us_BFu0c_D, "Us_BFu0c_D", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_F()
{
  {
    init_simple_test("Us_BFu0c_F");
    static Us_BFu0c_F lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0c_F)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_F)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_F.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_F.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_F(Test_Us_BFu0c_F, "Us_BFu0c_F", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_I()
{
  {
    init_simple_test("Us_BFu0c_I");
    static Us_BFu0c_I lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0c_I)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_I)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_I.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_I.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_I(Test_Us_BFu0c_I, "Us_BFu0c_I", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_Ip()
{
  {
    init_simple_test("Us_BFu0c_Ip");
    static Us_BFu0c_Ip lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0c_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_Ip)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_Ip.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_Ip.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_Ip(Test_Us_BFu0c_Ip, "Us_BFu0c_Ip", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_L()
{
  {
    init_simple_test("Us_BFu0c_L");
    static Us_BFu0c_L lv;
    check2(sizeof(lv), 10, "sizeof(Us_BFu0c_L)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_L)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_L.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_L.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_L(Test_Us_BFu0c_L, "Us_BFu0c_L", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_S()
{
  {
    init_simple_test("Us_BFu0c_S");
    static Us_BFu0c_S lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_S)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_S)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_S.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_S.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_S(Test_Us_BFu0c_S, "Us_BFu0c_S", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_Uc()
{
  {
    init_simple_test("Us_BFu0c_Uc");
    static Us_BFu0c_Uc lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_Uc)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_Uc.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_Uc.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_Uc(Test_Us_BFu0c_Uc, "Us_BFu0c_Uc", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_Ui()
{
  {
    init_simple_test("Us_BFu0c_Ui");
    static Us_BFu0c_Ui lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0c_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_Ui)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_Ui.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_Ui.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_Ui(Test_Us_BFu0c_Ui, "Us_BFu0c_Ui", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_Ul()
{
  {
    init_simple_test("Us_BFu0c_Ul");
    static Us_BFu0c_Ul lv;
    check2(sizeof(lv), 10, "sizeof(Us_BFu0c_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_Ul)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_Ul.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_Ul.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_Ul(Test_Us_BFu0c_Ul, "Us_BFu0c_Ul", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_Us()
{
  {
    init_simple_test("Us_BFu0c_Us");
    static Us_BFu0c_Us lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_Us)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_Us.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_Us.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_Us(Test_Us_BFu0c_Us, "Us_BFu0c_Us", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0c_Vp()
{
  {
    init_simple_test("Us_BFu0c_Vp");
    static Us_BFu0c_Vp lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0c_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_Vp)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_Vp.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_Vp.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_Vp(Test_Us_BFu0c_Vp, "Us_BFu0c_Vp", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i()
{
  {
    init_simple_test("Us_BFu0i");
    static Us_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vUs_BFu0i(Test_Us_BFu0i, "Us_BFu0i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu0c()
{
  {
    init_simple_test("Us_BFu0i_BFu0c");
    static Us_BFu0i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu0i_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu0c(Test_Us_BFu0i_BFu0c, "Us_BFu0i_BFu0c", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu0i()
{
  {
    init_simple_test("Us_BFu0i_BFu0i");
    static Us_BFu0i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu0i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu0i(Test_Us_BFu0i_BFu0i, "Us_BFu0i_BFu0i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu0ll()
{
  {
    init_simple_test("Us_BFu0i_BFu0ll");
    static Us_BFu0i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu0i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu0ll(Test_Us_BFu0i_BFu0ll, "Us_BFu0i_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu0s()
{
  {
    init_simple_test("Us_BFu0i_BFu0s");
    static Us_BFu0i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu0i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu0s(Test_Us_BFu0i_BFu0s, "Us_BFu0i_BFu0s", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu15i()
{
  {
    init_simple_test("Us_BFu0i_BFu15i");
    static Us_BFu0i_BFu15i lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_BFu15i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu15i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 15, 1, "Us_BFu0i_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 15, hide_ull(1LL<<14), "Us_BFu0i_BFu15i");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu15i(Test_Us_BFu0i_BFu15i, "Us_BFu0i_BFu15i", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu15ll()
{
  {
    init_simple_test("Us_BFu0i_BFu15ll");
    static Us_BFu0i_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu15ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 15, 1, "Us_BFu0i_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 15, hide_ull(1LL<<14), "Us_BFu0i_BFu15ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu15ll(Test_Us_BFu0i_BFu15ll, "Us_BFu0i_BFu15ll", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu15s()
{
  {
    init_simple_test("Us_BFu0i_BFu15s");
    static Us_BFu0i_BFu15s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_BFu15s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu15s)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 15, 1, "Us_BFu0i_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 15, hide_ull(1LL<<14), "Us_BFu0i_BFu15s");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu15s(Test_Us_BFu0i_BFu15s, "Us_BFu0i_BFu15s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu16i()
{
  {
    init_simple_test("Us_BFu0i_BFu16i");
    static Us_BFu0i_BFu16i lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_BFu16i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu16i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 16, 1, "Us_BFu0i_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 16, hide_ull(1LL<<15), "Us_BFu0i_BFu16i");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu16i(Test_Us_BFu0i_BFu16i, "Us_BFu0i_BFu16i", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu16ll()
{
  {
    init_simple_test("Us_BFu0i_BFu16ll");
    static Us_BFu0i_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu16ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 16, 1, "Us_BFu0i_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 16, hide_ull(1LL<<15), "Us_BFu0i_BFu16ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu16ll(Test_Us_BFu0i_BFu16ll, "Us_BFu0i_BFu16ll", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu16s()
{
  {
    init_simple_test("Us_BFu0i_BFu16s");
    static Us_BFu0i_BFu16s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_BFu16s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu16s)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 16, 1, "Us_BFu0i_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 16, hide_ull(1LL<<15), "Us_BFu0i_BFu16s");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu16s(Test_Us_BFu0i_BFu16s, "Us_BFu0i_BFu16s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu17i()
{
  {
    init_simple_test("Us_BFu0i_BFu17i");
    static Us_BFu0i_BFu17i lv;
    check2(sizeof(lv), ABISELECT(7,7), "sizeof(Us_BFu0i_BFu17i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu17i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 17, 1, "Us_BFu0i_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 17, hide_ull(1LL<<16), "Us_BFu0i_BFu17i");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu17i(Test_Us_BFu0i_BFu17i, "Us_BFu0i_BFu17i", ABISELECT(7,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu17ll()
{
  {
    init_simple_test("Us_BFu0i_BFu17ll");
    static Us_BFu0i_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(7,7), "sizeof(Us_BFu0i_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu17ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 17, 1, "Us_BFu0i_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 17, hide_ull(1LL<<16), "Us_BFu0i_BFu17ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu17ll(Test_Us_BFu0i_BFu17ll, "Us_BFu0i_BFu17ll", ABISELECT(7,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu1c()
{
  {
    init_simple_test("Us_BFu0i_BFu1c");
    static Us_BFu0i_BFu1c lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu1c)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 1, 1, "Us_BFu0i_BFu1c");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu1c(Test_Us_BFu0i_BFu1c, "Us_BFu0i_BFu1c", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu1i()
{
  {
    init_simple_test("Us_BFu0i_BFu1i");
    static Us_BFu0i_BFu1i lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu1i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu1i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 1, 1, "Us_BFu0i_BFu1i");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu1i(Test_Us_BFu0i_BFu1i, "Us_BFu0i_BFu1i", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu1ll()
{
  {
    init_simple_test("Us_BFu0i_BFu1ll");
    static Us_BFu0i_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu1ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 1, 1, "Us_BFu0i_BFu1ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu1ll(Test_Us_BFu0i_BFu1ll, "Us_BFu0i_BFu1ll", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu1s()
{
  {
    init_simple_test("Us_BFu0i_BFu1s");
    static Us_BFu0i_BFu1s lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu1s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu1s)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 1, 1, "Us_BFu0i_BFu1s");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu1s(Test_Us_BFu0i_BFu1s, "Us_BFu0i_BFu1s", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu31i()
{
  {
    init_simple_test("Us_BFu0i_BFu31i");
    static Us_BFu0i_BFu31i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu0i_BFu31i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu31i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 31, 1, "Us_BFu0i_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 31, hide_ull(1LL<<30), "Us_BFu0i_BFu31i");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu31i(Test_Us_BFu0i_BFu31i, "Us_BFu0i_BFu31i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu31ll()
{
  {
    init_simple_test("Us_BFu0i_BFu31ll");
    static Us_BFu0i_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu0i_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu31ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 31, 1, "Us_BFu0i_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 31, hide_ull(1LL<<30), "Us_BFu0i_BFu31ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu31ll(Test_Us_BFu0i_BFu31ll, "Us_BFu0i_BFu31ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu32i()
{
  {
    init_simple_test("Us_BFu0i_BFu32i");
    static Us_BFu0i_BFu32i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu0i_BFu32i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu32i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 32, 1, "Us_BFu0i_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 32, hide_ull(1LL<<31), "Us_BFu0i_BFu32i");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu32i(Test_Us_BFu0i_BFu32i, "Us_BFu0i_BFu32i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu32ll()
{
  {
    init_simple_test("Us_BFu0i_BFu32ll");
    static Us_BFu0i_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu0i_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu32ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 32, 1, "Us_BFu0i_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 32, hide_ull(1LL<<31), "Us_BFu0i_BFu32ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu32ll(Test_Us_BFu0i_BFu32ll, "Us_BFu0i_BFu32ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu33()
{
  {
    init_simple_test("Us_BFu0i_BFu33");
    static Us_BFu0i_BFu33 lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Us_BFu0i_BFu33)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu33)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 33, 1, "Us_BFu0i_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 33, hide_ull(1LL<<32), "Us_BFu0i_BFu33");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu33(Test_Us_BFu0i_BFu33, "Us_BFu0i_BFu33", ABISELECT(9,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu7c()
{
  {
    init_simple_test("Us_BFu0i_BFu7c");
    static Us_BFu0i_BFu7c lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu7c)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 7, 1, "Us_BFu0i_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 7, hide_ull(1LL<<6), "Us_BFu0i_BFu7c");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu7c(Test_Us_BFu0i_BFu7c, "Us_BFu0i_BFu7c", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu7i()
{
  {
    init_simple_test("Us_BFu0i_BFu7i");
    static Us_BFu0i_BFu7i lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu7i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu7i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 7, 1, "Us_BFu0i_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 7, hide_ull(1LL<<6), "Us_BFu0i_BFu7i");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu7i(Test_Us_BFu0i_BFu7i, "Us_BFu0i_BFu7i", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu7ll()
{
  {
    init_simple_test("Us_BFu0i_BFu7ll");
    static Us_BFu0i_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu7ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 7, 1, "Us_BFu0i_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 7, hide_ull(1LL<<6), "Us_BFu0i_BFu7ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu7ll(Test_Us_BFu0i_BFu7ll, "Us_BFu0i_BFu7ll", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu7s()
{
  {
    init_simple_test("Us_BFu0i_BFu7s");
    static Us_BFu0i_BFu7s lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu7s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu7s)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 7, 1, "Us_BFu0i_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 7, hide_ull(1LL<<6), "Us_BFu0i_BFu7s");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu7s(Test_Us_BFu0i_BFu7s, "Us_BFu0i_BFu7s", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu8c()
{
  {
    init_simple_test("Us_BFu0i_BFu8c");
    static Us_BFu0i_BFu8c lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu8c)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 8, 1, "Us_BFu0i_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 8, hide_ull(1LL<<7), "Us_BFu0i_BFu8c");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu8c(Test_Us_BFu0i_BFu8c, "Us_BFu0i_BFu8c", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu8i()
{
  {
    init_simple_test("Us_BFu0i_BFu8i");
    static Us_BFu0i_BFu8i lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu8i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu8i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 8, 1, "Us_BFu0i_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 8, hide_ull(1LL<<7), "Us_BFu0i_BFu8i");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu8i(Test_Us_BFu0i_BFu8i, "Us_BFu0i_BFu8i", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu8ll()
{
  {
    init_simple_test("Us_BFu0i_BFu8ll");
    static Us_BFu0i_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu8ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 8, 1, "Us_BFu0i_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 8, hide_ull(1LL<<7), "Us_BFu0i_BFu8ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu8ll(Test_Us_BFu0i_BFu8ll, "Us_BFu0i_BFu8ll", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu8s()
{
  {
    init_simple_test("Us_BFu0i_BFu8s");
    static Us_BFu0i_BFu8s lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu8s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu8s)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 8, 1, "Us_BFu0i_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 8, hide_ull(1LL<<7), "Us_BFu0i_BFu8s");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu8s(Test_Us_BFu0i_BFu8s, "Us_BFu0i_BFu8s", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu9i()
{
  {
    init_simple_test("Us_BFu0i_BFu9i");
    static Us_BFu0i_BFu9i lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_BFu9i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu9i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 9, 1, "Us_BFu0i_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 9, hide_ull(1LL<<8), "Us_BFu0i_BFu9i");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu9i(Test_Us_BFu0i_BFu9i, "Us_BFu0i_BFu9i", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu9ll()
{
  {
    init_simple_test("Us_BFu0i_BFu9ll");
    static Us_BFu0i_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu9ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 9, 1, "Us_BFu0i_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 9, hide_ull(1LL<<8), "Us_BFu0i_BFu9ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu9ll(Test_Us_BFu0i_BFu9ll, "Us_BFu0i_BFu9ll", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_BFu9s()
{
  {
    init_simple_test("Us_BFu0i_BFu9s");
    static Us_BFu0i_BFu9s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_BFu9s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu9s)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 9, 1, "Us_BFu0i_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 9, hide_ull(1LL<<8), "Us_BFu0i_BFu9s");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_BFu9s(Test_Us_BFu0i_BFu9s, "Us_BFu0i_BFu9s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_C()
{
  {
    init_simple_test("Us_BFu0i_C");
    static Us_BFu0i_C lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_C)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_C.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_C.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_C(Test_Us_BFu0i_C, "Us_BFu0i_C", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_D()
{
  {
    init_simple_test("Us_BFu0i_D");
    static Us_BFu0i_D lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Us_BFu0i_D)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_D)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_D.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_D.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_D(Test_Us_BFu0i_D, "Us_BFu0i_D", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_F()
{
  {
    init_simple_test("Us_BFu0i_F");
    static Us_BFu0i_F lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu0i_F)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_F)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_F.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_F.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_F(Test_Us_BFu0i_F, "Us_BFu0i_F", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_I()
{
  {
    init_simple_test("Us_BFu0i_I");
    static Us_BFu0i_I lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu0i_I)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_I)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_I.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_I.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_I(Test_Us_BFu0i_I, "Us_BFu0i_I", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_Ip()
{
  {
    init_simple_test("Us_BFu0i_Ip");
    static Us_BFu0i_Ip lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_BFu0i_Ip)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_Ip)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_Ip.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_Ip(Test_Us_BFu0i_Ip, "Us_BFu0i_Ip", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_L()
{
  {
    init_simple_test("Us_BFu0i_L");
    static Us_BFu0i_L lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Us_BFu0i_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_L)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_L.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_L.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_L(Test_Us_BFu0i_L, "Us_BFu0i_L", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_S()
{
  {
    init_simple_test("Us_BFu0i_S");
    static Us_BFu0i_S lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_S)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_S.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_S.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_S(Test_Us_BFu0i_S, "Us_BFu0i_S", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_Uc()
{
  {
    init_simple_test("Us_BFu0i_Uc");
    static Us_BFu0i_Uc lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_Uc)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_Uc.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_Uc(Test_Us_BFu0i_Uc, "Us_BFu0i_Uc", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_Ui()
{
  {
    init_simple_test("Us_BFu0i_Ui");
    static Us_BFu0i_Ui lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu0i_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_Ui)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_Ui.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_Ui(Test_Us_BFu0i_Ui, "Us_BFu0i_Ui", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_Ul()
{
  {
    init_simple_test("Us_BFu0i_Ul");
    static Us_BFu0i_Ul lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Us_BFu0i_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_Ul)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_Ul.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_Ul(Test_Us_BFu0i_Ul, "Us_BFu0i_Ul", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_Us()
{
  {
    init_simple_test("Us_BFu0i_Us");
    static Us_BFu0i_Us lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_Us)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_Us.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_Us.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_Us(Test_Us_BFu0i_Us, "Us_BFu0i_Us", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0i_Vp()
{
  {
    init_simple_test("Us_BFu0i_Vp");
    static Us_BFu0i_Vp lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_BFu0i_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_Vp)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_Vp.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_Vp(Test_Us_BFu0i_Vp, "Us_BFu0i_Vp", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll()
{
  {
    init_simple_test("Us_BFu0ll");
    static Us_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll(Test_Us_BFu0ll, "Us_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu0c()
{
  {
    init_simple_test("Us_BFu0ll_BFu0c");
    static Us_BFu0ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu0ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu0c(Test_Us_BFu0ll_BFu0c, "Us_BFu0ll_BFu0c", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu0i()
{
  {
    init_simple_test("Us_BFu0ll_BFu0i");
    static Us_BFu0ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu0ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu0i(Test_Us_BFu0ll_BFu0i, "Us_BFu0ll_BFu0i", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu0ll()
{
  {
    init_simple_test("Us_BFu0ll_BFu0ll");
    static Us_BFu0ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu0ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu0ll(Test_Us_BFu0ll_BFu0ll, "Us_BFu0ll_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu0s()
{
  {
    init_simple_test("Us_BFu0ll_BFu0s");
    static Us_BFu0ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu0ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu0s(Test_Us_BFu0ll_BFu0s, "Us_BFu0ll_BFu0s", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu15i()
{
  {
    init_simple_test("Us_BFu0ll_BFu15i");
    static Us_BFu0ll_BFu15i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_BFu15i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu15i)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Us_BFu0ll_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Us_BFu0ll_BFu15i");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu15i(Test_Us_BFu0ll_BFu15i, "Us_BFu0ll_BFu15i", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu15ll()
{
  {
    init_simple_test("Us_BFu0ll_BFu15ll");
    static Us_BFu0ll_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu15ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Us_BFu0ll_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Us_BFu0ll_BFu15ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu15ll(Test_Us_BFu0ll_BFu15ll, "Us_BFu0ll_BFu15ll", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu15s()
{
  {
    init_simple_test("Us_BFu0ll_BFu15s");
    static Us_BFu0ll_BFu15s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_BFu15s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu15s)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Us_BFu0ll_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Us_BFu0ll_BFu15s");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu15s(Test_Us_BFu0ll_BFu15s, "Us_BFu0ll_BFu15s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu16i()
{
  {
    init_simple_test("Us_BFu0ll_BFu16i");
    static Us_BFu0ll_BFu16i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_BFu16i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu16i)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Us_BFu0ll_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Us_BFu0ll_BFu16i");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu16i(Test_Us_BFu0ll_BFu16i, "Us_BFu0ll_BFu16i", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu16ll()
{
  {
    init_simple_test("Us_BFu0ll_BFu16ll");
    static Us_BFu0ll_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu16ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Us_BFu0ll_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Us_BFu0ll_BFu16ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu16ll(Test_Us_BFu0ll_BFu16ll, "Us_BFu0ll_BFu16ll", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu16s()
{
  {
    init_simple_test("Us_BFu0ll_BFu16s");
    static Us_BFu0ll_BFu16s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_BFu16s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu16s)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Us_BFu0ll_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Us_BFu0ll_BFu16s");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu16s(Test_Us_BFu0ll_BFu16s, "Us_BFu0ll_BFu16s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu17i()
{
  {
    init_simple_test("Us_BFu0ll_BFu17i");
    static Us_BFu0ll_BFu17i lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Us_BFu0ll_BFu17i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu17i)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Us_BFu0ll_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Us_BFu0ll_BFu17i");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu17i(Test_Us_BFu0ll_BFu17i, "Us_BFu0ll_BFu17i", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu17ll()
{
  {
    init_simple_test("Us_BFu0ll_BFu17ll");
    static Us_BFu0ll_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Us_BFu0ll_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu17ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Us_BFu0ll_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Us_BFu0ll_BFu17ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu17ll(Test_Us_BFu0ll_BFu17ll, "Us_BFu0ll_BFu17ll", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu1c()
{
  {
    init_simple_test("Us_BFu0ll_BFu1c");
    static Us_BFu0ll_BFu1c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu1c)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Us_BFu0ll_BFu1c");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu1c(Test_Us_BFu0ll_BFu1c, "Us_BFu0ll_BFu1c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu1i()
{
  {
    init_simple_test("Us_BFu0ll_BFu1i");
    static Us_BFu0ll_BFu1i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu1i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu1i)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Us_BFu0ll_BFu1i");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu1i(Test_Us_BFu0ll_BFu1i, "Us_BFu0ll_BFu1i", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu1ll()
{
  {
    init_simple_test("Us_BFu0ll_BFu1ll");
    static Us_BFu0ll_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu1ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Us_BFu0ll_BFu1ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu1ll(Test_Us_BFu0ll_BFu1ll, "Us_BFu0ll_BFu1ll", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu1s()
{
  {
    init_simple_test("Us_BFu0ll_BFu1s");
    static Us_BFu0ll_BFu1s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu1s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu1s)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Us_BFu0ll_BFu1s");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu1s(Test_Us_BFu0ll_BFu1s, "Us_BFu0ll_BFu1s", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu31i()
{
  {
    init_simple_test("Us_BFu0ll_BFu31i");
    static Us_BFu0ll_BFu31i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_BFu0ll_BFu31i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu31i)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Us_BFu0ll_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Us_BFu0ll_BFu31i");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu31i(Test_Us_BFu0ll_BFu31i, "Us_BFu0ll_BFu31i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu31ll()
{
  {
    init_simple_test("Us_BFu0ll_BFu31ll");
    static Us_BFu0ll_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_BFu0ll_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu31ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Us_BFu0ll_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Us_BFu0ll_BFu31ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu31ll(Test_Us_BFu0ll_BFu31ll, "Us_BFu0ll_BFu31ll", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu32i()
{
  {
    init_simple_test("Us_BFu0ll_BFu32i");
    static Us_BFu0ll_BFu32i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_BFu0ll_BFu32i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu32i)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Us_BFu0ll_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Us_BFu0ll_BFu32i");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu32i(Test_Us_BFu0ll_BFu32i, "Us_BFu0ll_BFu32i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu32ll()
{
  {
    init_simple_test("Us_BFu0ll_BFu32ll");
    static Us_BFu0ll_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_BFu0ll_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu32ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Us_BFu0ll_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Us_BFu0ll_BFu32ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu32ll(Test_Us_BFu0ll_BFu32ll, "Us_BFu0ll_BFu32ll", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu33()
{
  {
    init_simple_test("Us_BFu0ll_BFu33");
    static Us_BFu0ll_BFu33 lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Us_BFu0ll_BFu33)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu33)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Us_BFu0ll_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Us_BFu0ll_BFu33");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu33(Test_Us_BFu0ll_BFu33, "Us_BFu0ll_BFu33", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu7c()
{
  {
    init_simple_test("Us_BFu0ll_BFu7c");
    static Us_BFu0ll_BFu7c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu7c)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Us_BFu0ll_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Us_BFu0ll_BFu7c");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu7c(Test_Us_BFu0ll_BFu7c, "Us_BFu0ll_BFu7c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu7i()
{
  {
    init_simple_test("Us_BFu0ll_BFu7i");
    static Us_BFu0ll_BFu7i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu7i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu7i)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Us_BFu0ll_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Us_BFu0ll_BFu7i");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu7i(Test_Us_BFu0ll_BFu7i, "Us_BFu0ll_BFu7i", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu7ll()
{
  {
    init_simple_test("Us_BFu0ll_BFu7ll");
    static Us_BFu0ll_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu7ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Us_BFu0ll_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Us_BFu0ll_BFu7ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu7ll(Test_Us_BFu0ll_BFu7ll, "Us_BFu0ll_BFu7ll", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu7s()
{
  {
    init_simple_test("Us_BFu0ll_BFu7s");
    static Us_BFu0ll_BFu7s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu7s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu7s)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Us_BFu0ll_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Us_BFu0ll_BFu7s");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu7s(Test_Us_BFu0ll_BFu7s, "Us_BFu0ll_BFu7s", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu8c()
{
  {
    init_simple_test("Us_BFu0ll_BFu8c");
    static Us_BFu0ll_BFu8c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu8c)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Us_BFu0ll_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Us_BFu0ll_BFu8c");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu8c(Test_Us_BFu0ll_BFu8c, "Us_BFu0ll_BFu8c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu8i()
{
  {
    init_simple_test("Us_BFu0ll_BFu8i");
    static Us_BFu0ll_BFu8i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu8i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu8i)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Us_BFu0ll_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Us_BFu0ll_BFu8i");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu8i(Test_Us_BFu0ll_BFu8i, "Us_BFu0ll_BFu8i", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu8ll()
{
  {
    init_simple_test("Us_BFu0ll_BFu8ll");
    static Us_BFu0ll_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu8ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Us_BFu0ll_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Us_BFu0ll_BFu8ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu8ll(Test_Us_BFu0ll_BFu8ll, "Us_BFu0ll_BFu8ll", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu8s()
{
  {
    init_simple_test("Us_BFu0ll_BFu8s");
    static Us_BFu0ll_BFu8s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu8s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu8s)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Us_BFu0ll_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Us_BFu0ll_BFu8s");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu8s(Test_Us_BFu0ll_BFu8s, "Us_BFu0ll_BFu8s", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu9i()
{
  {
    init_simple_test("Us_BFu0ll_BFu9i");
    static Us_BFu0ll_BFu9i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_BFu9i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu9i)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Us_BFu0ll_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Us_BFu0ll_BFu9i");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu9i(Test_Us_BFu0ll_BFu9i, "Us_BFu0ll_BFu9i", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu9ll()
{
  {
    init_simple_test("Us_BFu0ll_BFu9ll");
    static Us_BFu0ll_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu9ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Us_BFu0ll_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Us_BFu0ll_BFu9ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu9ll(Test_Us_BFu0ll_BFu9ll, "Us_BFu0ll_BFu9ll", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_BFu9s()
{
  {
    init_simple_test("Us_BFu0ll_BFu9s");
    static Us_BFu0ll_BFu9s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_BFu9s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu9s)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Us_BFu0ll_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Us_BFu0ll_BFu9s");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_BFu9s(Test_Us_BFu0ll_BFu9s, "Us_BFu0ll_BFu9s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_C()
{
  {
    init_simple_test("Us_BFu0ll_C");
    static Us_BFu0ll_C lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_C)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_C.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_C(Test_Us_BFu0ll_C, "Us_BFu0ll_C", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_D()
{
  {
    init_simple_test("Us_BFu0ll_D");
    static Us_BFu0ll_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Us_BFu0ll_D)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_D)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_D.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_D(Test_Us_BFu0ll_D, "Us_BFu0ll_D", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_F()
{
  {
    init_simple_test("Us_BFu0ll_F");
    static Us_BFu0ll_F lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_BFu0ll_F)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_F)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_F.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_F(Test_Us_BFu0ll_F, "Us_BFu0ll_F", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_I()
{
  {
    init_simple_test("Us_BFu0ll_I");
    static Us_BFu0ll_I lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_BFu0ll_I)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_I)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_I.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_I(Test_Us_BFu0ll_I, "Us_BFu0ll_I", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_Ip()
{
  {
    init_simple_test("Us_BFu0ll_Ip");
    static Us_BFu0ll_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Us_BFu0ll_Ip)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_Ip)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_Ip.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_Ip(Test_Us_BFu0ll_Ip, "Us_BFu0ll_Ip", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_L()
{
  {
    init_simple_test("Us_BFu0ll_L");
    static Us_BFu0ll_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Us_BFu0ll_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_L)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_L.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_L(Test_Us_BFu0ll_L, "Us_BFu0ll_L", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_S()
{
  {
    init_simple_test("Us_BFu0ll_S");
    static Us_BFu0ll_S lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_S)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_S.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_S(Test_Us_BFu0ll_S, "Us_BFu0ll_S", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_Uc()
{
  {
    init_simple_test("Us_BFu0ll_Uc");
    static Us_BFu0ll_Uc lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_Uc)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_Uc.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_Uc(Test_Us_BFu0ll_Uc, "Us_BFu0ll_Uc", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_Ui()
{
  {
    init_simple_test("Us_BFu0ll_Ui");
    static Us_BFu0ll_Ui lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_BFu0ll_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_Ui)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_Ui.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_Ui(Test_Us_BFu0ll_Ui, "Us_BFu0ll_Ui", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_Ul()
{
  {
    init_simple_test("Us_BFu0ll_Ul");
    static Us_BFu0ll_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Us_BFu0ll_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_Ul)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_Ul.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_Ul(Test_Us_BFu0ll_Ul, "Us_BFu0ll_Ul", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_Us()
{
  {
    init_simple_test("Us_BFu0ll_Us");
    static Us_BFu0ll_Us lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_Us)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_Us.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_Us(Test_Us_BFu0ll_Us, "Us_BFu0ll_Us", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0ll_Vp()
{
  {
    init_simple_test("Us_BFu0ll_Vp");
    static Us_BFu0ll_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Us_BFu0ll_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_Vp)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_Vp.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_Vp(Test_Us_BFu0ll_Vp, "Us_BFu0ll_Vp", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s()
{
  {
    init_simple_test("Us_BFu0s");
    static Us_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Us_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vUs_BFu0s(Test_Us_BFu0s, "Us_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu0c()
{
  {
    init_simple_test("Us_BFu0s_BFu0c");
    static Us_BFu0s_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(Us_BFu0s_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu0c(Test_Us_BFu0s_BFu0c, "Us_BFu0s_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu0i()
{
  {
    init_simple_test("Us_BFu0s_BFu0i");
    static Us_BFu0s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu0s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu0i(Test_Us_BFu0s_BFu0i, "Us_BFu0s_BFu0i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu0ll()
{
  {
    init_simple_test("Us_BFu0s_BFu0ll");
    static Us_BFu0s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu0s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu0ll(Test_Us_BFu0s_BFu0ll, "Us_BFu0s_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu0s()
{
  {
    init_simple_test("Us_BFu0s_BFu0s");
    static Us_BFu0s_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Us_BFu0s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu0s(Test_Us_BFu0s_BFu0s, "Us_BFu0s_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu15i()
{
  {
    init_simple_test("Us_BFu0s_BFu15i");
    static Us_BFu0s_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_BFu15i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu15i)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu15i.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu0s_BFu15i");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu0s_BFu15i");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu15i(Test_Us_BFu0s_BFu15i, "Us_BFu0s_BFu15i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu15ll()
{
  {
    init_simple_test("Us_BFu0s_BFu15ll");
    static Us_BFu0s_BFu15ll lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu15ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu15ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu0s_BFu15ll");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu0s_BFu15ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu15ll(Test_Us_BFu0s_BFu15ll, "Us_BFu0s_BFu15ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu15s()
{
  {
    init_simple_test("Us_BFu0s_BFu15s");
    static Us_BFu0s_BFu15s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_BFu15s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu15s)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu15s.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu0s_BFu15s");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu0s_BFu15s");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu15s(Test_Us_BFu0s_BFu15s, "Us_BFu0s_BFu15s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu16i()
{
  {
    init_simple_test("Us_BFu0s_BFu16i");
    static Us_BFu0s_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_BFu16i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu16i)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu16i.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu0s_BFu16i");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu0s_BFu16i");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu16i(Test_Us_BFu0s_BFu16i, "Us_BFu0s_BFu16i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu16ll()
{
  {
    init_simple_test("Us_BFu0s_BFu16ll");
    static Us_BFu0s_BFu16ll lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu16ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu16ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu0s_BFu16ll");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu0s_BFu16ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu16ll(Test_Us_BFu0s_BFu16ll, "Us_BFu0s_BFu16ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu16s()
{
  {
    init_simple_test("Us_BFu0s_BFu16s");
    static Us_BFu0s_BFu16s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_BFu16s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu16s)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu16s.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu0s_BFu16s");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu0s_BFu16s");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu16s(Test_Us_BFu0s_BFu16s, "Us_BFu0s_BFu16s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu17i()
{
  {
    init_simple_test("Us_BFu0s_BFu17i");
    static Us_BFu0s_BFu17i lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0s_BFu17i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu17i)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu17i.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu0s_BFu17i");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu0s_BFu17i");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu17i(Test_Us_BFu0s_BFu17i, "Us_BFu0s_BFu17i", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu17ll()
{
  {
    init_simple_test("Us_BFu0s_BFu17ll");
    static Us_BFu0s_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0s_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu17ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu17ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu0s_BFu17ll");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu0s_BFu17ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu17ll(Test_Us_BFu0s_BFu17ll, "Us_BFu0s_BFu17ll", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu1c()
{
  {
    init_simple_test("Us_BFu0s_BFu1c");
    static Us_BFu0s_BFu1c lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu1c)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu1c.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu0s_BFu1c");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu1c(Test_Us_BFu0s_BFu1c, "Us_BFu0s_BFu1c", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu1i()
{
  {
    init_simple_test("Us_BFu0s_BFu1i");
    static Us_BFu0s_BFu1i lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu1i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu1i)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu1i.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu0s_BFu1i");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu1i(Test_Us_BFu0s_BFu1i, "Us_BFu0s_BFu1i", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu1ll()
{
  {
    init_simple_test("Us_BFu0s_BFu1ll");
    static Us_BFu0s_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu1ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu1ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu0s_BFu1ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu1ll(Test_Us_BFu0s_BFu1ll, "Us_BFu0s_BFu1ll", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu1s()
{
  {
    init_simple_test("Us_BFu0s_BFu1s");
    static Us_BFu0s_BFu1s lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu1s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu1s)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu1s.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu0s_BFu1s");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu1s(Test_Us_BFu0s_BFu1s, "Us_BFu0s_BFu1s", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu31i()
{
  {
    init_simple_test("Us_BFu0s_BFu31i");
    static Us_BFu0s_BFu31i lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0s_BFu31i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu31i)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu31i.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu0s_BFu31i");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu0s_BFu31i");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu31i(Test_Us_BFu0s_BFu31i, "Us_BFu0s_BFu31i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu31ll()
{
  {
    init_simple_test("Us_BFu0s_BFu31ll");
    static Us_BFu0s_BFu31ll lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0s_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu31ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu31ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu0s_BFu31ll");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu0s_BFu31ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu31ll(Test_Us_BFu0s_BFu31ll, "Us_BFu0s_BFu31ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu32i()
{
  {
    init_simple_test("Us_BFu0s_BFu32i");
    static Us_BFu0s_BFu32i lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0s_BFu32i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu32i)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu32i.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu0s_BFu32i");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu0s_BFu32i");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu32i(Test_Us_BFu0s_BFu32i, "Us_BFu0s_BFu32i", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu32ll()
{
  {
    init_simple_test("Us_BFu0s_BFu32ll");
    static Us_BFu0s_BFu32ll lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0s_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu32ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu32ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu0s_BFu32ll");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu0s_BFu32ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu32ll(Test_Us_BFu0s_BFu32ll, "Us_BFu0s_BFu32ll", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu33()
{
  {
    init_simple_test("Us_BFu0s_BFu33");
    static Us_BFu0s_BFu33 lv;
    check2(sizeof(lv), ABISELECT(7,7), "sizeof(Us_BFu0s_BFu33)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu33)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu33.v1");
    set_bf_and_test(lv, v2, 2, 0, 33, 1, "Us_BFu0s_BFu33");
    set_bf_and_test(lv, v2, 2, 0, 33, hide_ull(1LL<<32), "Us_BFu0s_BFu33");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu33(Test_Us_BFu0s_BFu33, "Us_BFu0s_BFu33", ABISELECT(7,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu7c()
{
  {
    init_simple_test("Us_BFu0s_BFu7c");
    static Us_BFu0s_BFu7c lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu7c)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu7c.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu0s_BFu7c");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu0s_BFu7c");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu7c(Test_Us_BFu0s_BFu7c, "Us_BFu0s_BFu7c", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu7i()
{
  {
    init_simple_test("Us_BFu0s_BFu7i");
    static Us_BFu0s_BFu7i lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu7i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu7i)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu7i.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu0s_BFu7i");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu0s_BFu7i");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu7i(Test_Us_BFu0s_BFu7i, "Us_BFu0s_BFu7i", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu7ll()
{
  {
    init_simple_test("Us_BFu0s_BFu7ll");
    static Us_BFu0s_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu7ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu7ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu0s_BFu7ll");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu0s_BFu7ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu7ll(Test_Us_BFu0s_BFu7ll, "Us_BFu0s_BFu7ll", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu7s()
{
  {
    init_simple_test("Us_BFu0s_BFu7s");
    static Us_BFu0s_BFu7s lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu7s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu7s)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu7s.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu0s_BFu7s");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu0s_BFu7s");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu7s(Test_Us_BFu0s_BFu7s, "Us_BFu0s_BFu7s", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu8c()
{
  {
    init_simple_test("Us_BFu0s_BFu8c");
    static Us_BFu0s_BFu8c lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu8c)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu8c.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu0s_BFu8c");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu0s_BFu8c");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu8c(Test_Us_BFu0s_BFu8c, "Us_BFu0s_BFu8c", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu8i()
{
  {
    init_simple_test("Us_BFu0s_BFu8i");
    static Us_BFu0s_BFu8i lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu8i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu8i)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu8i.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu0s_BFu8i");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu0s_BFu8i");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu8i(Test_Us_BFu0s_BFu8i, "Us_BFu0s_BFu8i", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu8ll()
{
  {
    init_simple_test("Us_BFu0s_BFu8ll");
    static Us_BFu0s_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu8ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu8ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu0s_BFu8ll");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu0s_BFu8ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu8ll(Test_Us_BFu0s_BFu8ll, "Us_BFu0s_BFu8ll", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu8s()
{
  {
    init_simple_test("Us_BFu0s_BFu8s");
    static Us_BFu0s_BFu8s lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu8s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu8s)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu8s.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu0s_BFu8s");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu0s_BFu8s");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu8s(Test_Us_BFu0s_BFu8s, "Us_BFu0s_BFu8s", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu9i()
{
  {
    init_simple_test("Us_BFu0s_BFu9i");
    static Us_BFu0s_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_BFu9i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu9i)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu9i.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu0s_BFu9i");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu0s_BFu9i");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu9i(Test_Us_BFu0s_BFu9i, "Us_BFu0s_BFu9i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu9ll()
{
  {
    init_simple_test("Us_BFu0s_BFu9ll");
    static Us_BFu0s_BFu9ll lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu9ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu9ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu0s_BFu9ll");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu0s_BFu9ll");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu9ll(Test_Us_BFu0s_BFu9ll, "Us_BFu0s_BFu9ll", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_BFu9s()
{
  {
    init_simple_test("Us_BFu0s_BFu9s");
    static Us_BFu0s_BFu9s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_BFu9s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu9s)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu9s.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu0s_BFu9s");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu0s_BFu9s");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_BFu9s(Test_Us_BFu0s_BFu9s, "Us_BFu0s_BFu9s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_C()
{
  {
    init_simple_test("Us_BFu0s_C");
    static Us_BFu0s_C lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_C)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_C.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_C.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_C(Test_Us_BFu0s_C, "Us_BFu0s_C", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_D()
{
  {
    init_simple_test("Us_BFu0s_D");
    static Us_BFu0s_D lv;
    check2(sizeof(lv), 10, "sizeof(Us_BFu0s_D)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_D)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_D.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_D.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_D(Test_Us_BFu0s_D, "Us_BFu0s_D", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_F()
{
  {
    init_simple_test("Us_BFu0s_F");
    static Us_BFu0s_F lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0s_F)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_F)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_F.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_F.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_F(Test_Us_BFu0s_F, "Us_BFu0s_F", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_I()
{
  {
    init_simple_test("Us_BFu0s_I");
    static Us_BFu0s_I lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0s_I)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_I)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_I.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_I.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_I(Test_Us_BFu0s_I, "Us_BFu0s_I", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_Ip()
{
  {
    init_simple_test("Us_BFu0s_Ip");
    static Us_BFu0s_Ip lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0s_Ip)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_Ip)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_Ip.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_Ip.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_Ip(Test_Us_BFu0s_Ip, "Us_BFu0s_Ip", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_L()
{
  {
    init_simple_test("Us_BFu0s_L");
    static Us_BFu0s_L lv;
    check2(sizeof(lv), 10, "sizeof(Us_BFu0s_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_L)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_L.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_L.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_L(Test_Us_BFu0s_L, "Us_BFu0s_L", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_S()
{
  {
    init_simple_test("Us_BFu0s_S");
    static Us_BFu0s_S lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_S)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_S.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_S.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_S(Test_Us_BFu0s_S, "Us_BFu0s_S", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_Uc()
{
  {
    init_simple_test("Us_BFu0s_Uc");
    static Us_BFu0s_Uc lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_Uc)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_Uc.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_Uc.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_Uc(Test_Us_BFu0s_Uc, "Us_BFu0s_Uc", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_Ui()
{
  {
    init_simple_test("Us_BFu0s_Ui");
    static Us_BFu0s_Ui lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0s_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_Ui)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_Ui.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_Ui.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_Ui(Test_Us_BFu0s_Ui, "Us_BFu0s_Ui", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_Ul()
{
  {
    init_simple_test("Us_BFu0s_Ul");
    static Us_BFu0s_Ul lv;
    check2(sizeof(lv), 10, "sizeof(Us_BFu0s_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_Ul)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_Ul.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_Ul.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_Ul(Test_Us_BFu0s_Ul, "Us_BFu0s_Ul", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_Us()
{
  {
    init_simple_test("Us_BFu0s_Us");
    static Us_BFu0s_Us lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_Us)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_Us.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_Us.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_Us(Test_Us_BFu0s_Us, "Us_BFu0s_Us", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu0s_Vp()
{
  {
    init_simple_test("Us_BFu0s_Vp");
    static Us_BFu0s_Vp lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0s_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_Vp)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_Vp.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_Vp.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_Vp(Test_Us_BFu0s_Vp, "Us_BFu0s_Vp", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu15i_BFu0c()
{
  {
    init_simple_test("Us_BFu15i_BFu0c");
    static Us_BFu15i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu15i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu15i_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu15i_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15i_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15i_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu15i_BFu0c(Test_Us_BFu15i_BFu0c, "Us_BFu15i_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu15i_BFu0i()
{
  {
    init_simple_test("Us_BFu15i_BFu0i");
    static Us_BFu15i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu15i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu15i_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu15i_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15i_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15i_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu15i_BFu0i(Test_Us_BFu15i_BFu0i, "Us_BFu15i_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu15i_BFu0ll()
{
  {
    init_simple_test("Us_BFu15i_BFu0ll");
    static Us_BFu15i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu15i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu15i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu15i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15i_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu15i_BFu0ll(Test_Us_BFu15i_BFu0ll, "Us_BFu15i_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu15i_BFu0s()
{
  {
    init_simple_test("Us_BFu15i_BFu0s");
    static Us_BFu15i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu15i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu15i_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu15i_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15i_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15i_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu15i_BFu0s(Test_Us_BFu15i_BFu0s, "Us_BFu15i_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu15ll_BFu0c()
{
  {
    init_simple_test("Us_BFu15ll_BFu0c");
    static Us_BFu15ll_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu15ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu15ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu15ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15ll_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu15ll_BFu0c(Test_Us_BFu15ll_BFu0c, "Us_BFu15ll_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu15ll_BFu0i()
{
  {
    init_simple_test("Us_BFu15ll_BFu0i");
    static Us_BFu15ll_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu15ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu15ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu15ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15ll_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu15ll_BFu0i(Test_Us_BFu15ll_BFu0i, "Us_BFu15ll_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu15ll_BFu0ll()
{
  {
    init_simple_test("Us_BFu15ll_BFu0ll");
    static Us_BFu15ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu15ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu15ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu15ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15ll_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu15ll_BFu0ll(Test_Us_BFu15ll_BFu0ll, "Us_BFu15ll_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu15ll_BFu0s()
{
  {
    init_simple_test("Us_BFu15ll_BFu0s");
    static Us_BFu15ll_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu15ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu15ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu15ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15ll_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu15ll_BFu0s(Test_Us_BFu15ll_BFu0s, "Us_BFu15ll_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu15s_BFu0c()
{
  {
    init_simple_test("Us_BFu15s_BFu0c");
    static Us_BFu15s_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu15s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu15s_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu15s_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15s_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15s_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu15s_BFu0c(Test_Us_BFu15s_BFu0c, "Us_BFu15s_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu15s_BFu0i()
{
  {
    init_simple_test("Us_BFu15s_BFu0i");
    static Us_BFu15s_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu15s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu15s_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu15s_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15s_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15s_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu15s_BFu0i(Test_Us_BFu15s_BFu0i, "Us_BFu15s_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu15s_BFu0ll()
{
  {
    init_simple_test("Us_BFu15s_BFu0ll");
    static Us_BFu15s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu15s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu15s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu15s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15s_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15s_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu15s_BFu0ll(Test_Us_BFu15s_BFu0ll, "Us_BFu15s_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu15s_BFu0s()
{
  {
    init_simple_test("Us_BFu15s_BFu0s");
    static Us_BFu15s_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu15s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu15s_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu15s_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15s_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15s_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu15s_BFu0s(Test_Us_BFu15s_BFu0s, "Us_BFu15s_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu16i_BFu0c()
{
  {
    init_simple_test("Us_BFu16i_BFu0c");
    static Us_BFu16i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu16i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu16i_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu16i_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16i_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16i_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu16i_BFu0c(Test_Us_BFu16i_BFu0c, "Us_BFu16i_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu16i_BFu0i()
{
  {
    init_simple_test("Us_BFu16i_BFu0i");
    static Us_BFu16i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu16i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu16i_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu16i_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16i_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16i_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu16i_BFu0i(Test_Us_BFu16i_BFu0i, "Us_BFu16i_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu16i_BFu0ll()
{
  {
    init_simple_test("Us_BFu16i_BFu0ll");
    static Us_BFu16i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu16i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu16i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu16i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16i_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu16i_BFu0ll(Test_Us_BFu16i_BFu0ll, "Us_BFu16i_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu16i_BFu0s()
{
  {
    init_simple_test("Us_BFu16i_BFu0s");
    static Us_BFu16i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu16i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu16i_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu16i_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16i_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16i_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu16i_BFu0s(Test_Us_BFu16i_BFu0s, "Us_BFu16i_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu16ll_BFu0c()
{
  {
    init_simple_test("Us_BFu16ll_BFu0c");
    static Us_BFu16ll_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu16ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu16ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu16ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16ll_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu16ll_BFu0c(Test_Us_BFu16ll_BFu0c, "Us_BFu16ll_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu16ll_BFu0i()
{
  {
    init_simple_test("Us_BFu16ll_BFu0i");
    static Us_BFu16ll_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu16ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu16ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu16ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16ll_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu16ll_BFu0i(Test_Us_BFu16ll_BFu0i, "Us_BFu16ll_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu16ll_BFu0ll()
{
  {
    init_simple_test("Us_BFu16ll_BFu0ll");
    static Us_BFu16ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu16ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu16ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu16ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16ll_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu16ll_BFu0ll(Test_Us_BFu16ll_BFu0ll, "Us_BFu16ll_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu16ll_BFu0s()
{
  {
    init_simple_test("Us_BFu16ll_BFu0s");
    static Us_BFu16ll_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu16ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu16ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu16ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16ll_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu16ll_BFu0s(Test_Us_BFu16ll_BFu0s, "Us_BFu16ll_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu16s_BFu0c()
{
  {
    init_simple_test("Us_BFu16s_BFu0c");
    static Us_BFu16s_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu16s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu16s_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu16s_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16s_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16s_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu16s_BFu0c(Test_Us_BFu16s_BFu0c, "Us_BFu16s_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu16s_BFu0i()
{
  {
    init_simple_test("Us_BFu16s_BFu0i");
    static Us_BFu16s_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu16s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu16s_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu16s_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16s_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16s_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu16s_BFu0i(Test_Us_BFu16s_BFu0i, "Us_BFu16s_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu16s_BFu0ll()
{
  {
    init_simple_test("Us_BFu16s_BFu0ll");
    static Us_BFu16s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu16s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu16s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu16s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16s_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16s_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu16s_BFu0ll(Test_Us_BFu16s_BFu0ll, "Us_BFu16s_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu16s_BFu0s()
{
  {
    init_simple_test("Us_BFu16s_BFu0s");
    static Us_BFu16s_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu16s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu16s_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu16s_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16s_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16s_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu16s_BFu0s(Test_Us_BFu16s_BFu0s, "Us_BFu16s_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu17i_BFu0c()
{
  {
    init_simple_test("Us_BFu17i_BFu0c");
    static Us_BFu17i_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Us_BFu17i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu17i_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu17i_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu17i_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu17i_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu17i_BFu0c(Test_Us_BFu17i_BFu0c, "Us_BFu17i_BFu0c", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu17i_BFu0i()
{
  {
    init_simple_test("Us_BFu17i_BFu0i");
    static Us_BFu17i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu17i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu17i_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu17i_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu17i_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu17i_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu17i_BFu0i(Test_Us_BFu17i_BFu0i, "Us_BFu17i_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu17i_BFu0ll()
{
  {
    init_simple_test("Us_BFu17i_BFu0ll");
    static Us_BFu17i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu17i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu17i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu17i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu17i_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu17i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu17i_BFu0ll(Test_Us_BFu17i_BFu0ll, "Us_BFu17i_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu17i_BFu0s()
{
  {
    init_simple_test("Us_BFu17i_BFu0s");
    static Us_BFu17i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu17i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu17i_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu17i_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu17i_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu17i_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu17i_BFu0s(Test_Us_BFu17i_BFu0s, "Us_BFu17i_BFu0s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu17ll_BFu0c()
{
  {
    init_simple_test("Us_BFu17ll_BFu0c");
    static Us_BFu17ll_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Us_BFu17ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu17ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu17ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu17ll_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu17ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu17ll_BFu0c(Test_Us_BFu17ll_BFu0c, "Us_BFu17ll_BFu0c", 5);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu17ll_BFu0i()
{
  {
    init_simple_test("Us_BFu17ll_BFu0i");
    static Us_BFu17ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu17ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu17ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu17ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu17ll_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu17ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu17ll_BFu0i(Test_Us_BFu17ll_BFu0i, "Us_BFu17ll_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu17ll_BFu0ll()
{
  {
    init_simple_test("Us_BFu17ll_BFu0ll");
    static Us_BFu17ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu17ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu17ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu17ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu17ll_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu17ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu17ll_BFu0ll(Test_Us_BFu17ll_BFu0ll, "Us_BFu17ll_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu17ll_BFu0s()
{
  {
    init_simple_test("Us_BFu17ll_BFu0s");
    static Us_BFu17ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu17ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu17ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu17ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu17ll_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu17ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu17ll_BFu0s(Test_Us_BFu17ll_BFu0s, "Us_BFu17ll_BFu0s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu1c_BFu0c()
{
  {
    init_simple_test("Us_BFu1c_BFu0c");
    static Us_BFu1c_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu1c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu1c_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu1c_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1c_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu1c_BFu0c(Test_Us_BFu1c_BFu0c, "Us_BFu1c_BFu0c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu1c_BFu0i()
{
  {
    init_simple_test("Us_BFu1c_BFu0i");
    static Us_BFu1c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu1c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1c_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu1c_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1c_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu1c_BFu0i(Test_Us_BFu1c_BFu0i, "Us_BFu1c_BFu0i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu1c_BFu0ll()
{
  {
    init_simple_test("Us_BFu1c_BFu0ll");
    static Us_BFu1c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu1c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu1c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1c_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu1c_BFu0ll(Test_Us_BFu1c_BFu0ll, "Us_BFu1c_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu1c_BFu0s()
{
  {
    init_simple_test("Us_BFu1c_BFu0s");
    static Us_BFu1c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu1c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1c_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu1c_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1c_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu1c_BFu0s(Test_Us_BFu1c_BFu0s, "Us_BFu1c_BFu0s", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu1i_BFu0c()
{
  {
    init_simple_test("Us_BFu1i_BFu0c");
    static Us_BFu1i_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu1i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu1i_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu1i_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1i_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu1i_BFu0c(Test_Us_BFu1i_BFu0c, "Us_BFu1i_BFu0c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu1i_BFu0i()
{
  {
    init_simple_test("Us_BFu1i_BFu0i");
    static Us_BFu1i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu1i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1i_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu1i_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1i_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu1i_BFu0i(Test_Us_BFu1i_BFu0i, "Us_BFu1i_BFu0i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu1i_BFu0ll()
{
  {
    init_simple_test("Us_BFu1i_BFu0ll");
    static Us_BFu1i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu1i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu1i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu1i_BFu0ll(Test_Us_BFu1i_BFu0ll, "Us_BFu1i_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu1i_BFu0s()
{
  {
    init_simple_test("Us_BFu1i_BFu0s");
    static Us_BFu1i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu1i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1i_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu1i_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1i_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu1i_BFu0s(Test_Us_BFu1i_BFu0s, "Us_BFu1i_BFu0s", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu1ll_BFu0c()
{
  {
    init_simple_test("Us_BFu1ll_BFu0c");
    static Us_BFu1ll_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu1ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu1ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu1ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu1ll_BFu0c(Test_Us_BFu1ll_BFu0c, "Us_BFu1ll_BFu0c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu1ll_BFu0i()
{
  {
    init_simple_test("Us_BFu1ll_BFu0i");
    static Us_BFu1ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu1ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu1ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu1ll_BFu0i(Test_Us_BFu1ll_BFu0i, "Us_BFu1ll_BFu0i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu1ll_BFu0ll()
{
  {
    init_simple_test("Us_BFu1ll_BFu0ll");
    static Us_BFu1ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu1ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu1ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu1ll_BFu0ll(Test_Us_BFu1ll_BFu0ll, "Us_BFu1ll_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu1ll_BFu0s()
{
  {
    init_simple_test("Us_BFu1ll_BFu0s");
    static Us_BFu1ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu1ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu1ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu1ll_BFu0s(Test_Us_BFu1ll_BFu0s, "Us_BFu1ll_BFu0s", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu1s_BFu0c()
{
  {
    init_simple_test("Us_BFu1s_BFu0c");
    static Us_BFu1s_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu1s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu1s_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu1s_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1s_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu1s_BFu0c(Test_Us_BFu1s_BFu0c, "Us_BFu1s_BFu0c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu1s_BFu0i()
{
  {
    init_simple_test("Us_BFu1s_BFu0i");
    static Us_BFu1s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu1s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1s_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu1s_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1s_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu1s_BFu0i(Test_Us_BFu1s_BFu0i, "Us_BFu1s_BFu0i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu1s_BFu0ll()
{
  {
    init_simple_test("Us_BFu1s_BFu0ll");
    static Us_BFu1s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu1s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu1s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1s_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu1s_BFu0ll(Test_Us_BFu1s_BFu0ll, "Us_BFu1s_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu1s_BFu0s()
{
  {
    init_simple_test("Us_BFu1s_BFu0s");
    static Us_BFu1s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu1s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1s_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu1s_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1s_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu1s_BFu0s(Test_Us_BFu1s_BFu0s, "Us_BFu1s_BFu0s", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu31i_BFu0c()
{
  {
    init_simple_test("Us_BFu31i_BFu0c");
    static Us_BFu31i_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu31i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu31i_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu31i_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu31i_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu31i_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu31i_BFu0c(Test_Us_BFu31i_BFu0c, "Us_BFu31i_BFu0c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu31i_BFu0i()
{
  {
    init_simple_test("Us_BFu31i_BFu0i");
    static Us_BFu31i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu31i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu31i_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu31i_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu31i_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu31i_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu31i_BFu0i(Test_Us_BFu31i_BFu0i, "Us_BFu31i_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu31i_BFu0ll()
{
  {
    init_simple_test("Us_BFu31i_BFu0ll");
    static Us_BFu31i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu31i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu31i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu31i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu31i_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu31i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu31i_BFu0ll(Test_Us_BFu31i_BFu0ll, "Us_BFu31i_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu31i_BFu0s()
{
  {
    init_simple_test("Us_BFu31i_BFu0s");
    static Us_BFu31i_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu31i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu31i_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu31i_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu31i_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu31i_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu31i_BFu0s(Test_Us_BFu31i_BFu0s, "Us_BFu31i_BFu0s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu31ll_BFu0c()
{
  {
    init_simple_test("Us_BFu31ll_BFu0c");
    static Us_BFu31ll_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu31ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu31ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu31ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu31ll_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu31ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu31ll_BFu0c(Test_Us_BFu31ll_BFu0c, "Us_BFu31ll_BFu0c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu31ll_BFu0i()
{
  {
    init_simple_test("Us_BFu31ll_BFu0i");
    static Us_BFu31ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu31ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu31ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu31ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu31ll_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu31ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu31ll_BFu0i(Test_Us_BFu31ll_BFu0i, "Us_BFu31ll_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu31ll_BFu0ll()
{
  {
    init_simple_test("Us_BFu31ll_BFu0ll");
    static Us_BFu31ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu31ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu31ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu31ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu31ll_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu31ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu31ll_BFu0ll(Test_Us_BFu31ll_BFu0ll, "Us_BFu31ll_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu31ll_BFu0s()
{
  {
    init_simple_test("Us_BFu31ll_BFu0s");
    static Us_BFu31ll_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu31ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu31ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu31ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu31ll_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu31ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu31ll_BFu0s(Test_Us_BFu31ll_BFu0s, "Us_BFu31ll_BFu0s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu32i_BFu0c()
{
  {
    init_simple_test("Us_BFu32i_BFu0c");
    static Us_BFu32i_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu32i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu32i_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu32i_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu32i_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu32i_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu32i_BFu0c(Test_Us_BFu32i_BFu0c, "Us_BFu32i_BFu0c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu32i_BFu0i()
{
  {
    init_simple_test("Us_BFu32i_BFu0i");
    static Us_BFu32i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu32i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu32i_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu32i_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu32i_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu32i_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu32i_BFu0i(Test_Us_BFu32i_BFu0i, "Us_BFu32i_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu32i_BFu0ll()
{
  {
    init_simple_test("Us_BFu32i_BFu0ll");
    static Us_BFu32i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu32i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu32i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu32i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu32i_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu32i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu32i_BFu0ll(Test_Us_BFu32i_BFu0ll, "Us_BFu32i_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu32i_BFu0s()
{
  {
    init_simple_test("Us_BFu32i_BFu0s");
    static Us_BFu32i_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu32i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu32i_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu32i_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu32i_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu32i_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu32i_BFu0s(Test_Us_BFu32i_BFu0s, "Us_BFu32i_BFu0s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu32ll_BFu0c()
{
  {
    init_simple_test("Us_BFu32ll_BFu0c");
    static Us_BFu32ll_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu32ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu32ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu32ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu32ll_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu32ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu32ll_BFu0c(Test_Us_BFu32ll_BFu0c, "Us_BFu32ll_BFu0c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu32ll_BFu0i()
{
  {
    init_simple_test("Us_BFu32ll_BFu0i");
    static Us_BFu32ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu32ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu32ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu32ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu32ll_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu32ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu32ll_BFu0i(Test_Us_BFu32ll_BFu0i, "Us_BFu32ll_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu32ll_BFu0ll()
{
  {
    init_simple_test("Us_BFu32ll_BFu0ll");
    static Us_BFu32ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu32ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu32ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu32ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu32ll_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu32ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu32ll_BFu0ll(Test_Us_BFu32ll_BFu0ll, "Us_BFu32ll_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu32ll_BFu0s()
{
  {
    init_simple_test("Us_BFu32ll_BFu0s");
    static Us_BFu32ll_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu32ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu32ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu32ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu32ll_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu32ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu32ll_BFu0s(Test_Us_BFu32ll_BFu0s, "Us_BFu32ll_BFu0s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu33_BFu0c()
{
  {
    init_simple_test("Us_BFu33_BFu0c");
    static Us_BFu33_BFu0c lv;
    check2(sizeof(lv), 7, "sizeof(Us_BFu33_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu33_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu33_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 33, 1, "Us_BFu33_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 33, hide_ull(1LL<<32), "Us_BFu33_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu33_BFu0c(Test_Us_BFu33_BFu0c, "Us_BFu33_BFu0c", 7);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu33_BFu0i()
{
  {
    init_simple_test("Us_BFu33_BFu0i");
    static Us_BFu33_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu33_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu33_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu33_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 33, 1, "Us_BFu33_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 33, hide_ull(1LL<<32), "Us_BFu33_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu33_BFu0i(Test_Us_BFu33_BFu0i, "Us_BFu33_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu33_BFu0ll()
{
  {
    init_simple_test("Us_BFu33_BFu0ll");
    static Us_BFu33_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu33_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu33_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu33_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 33, 1, "Us_BFu33_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 33, hide_ull(1LL<<32), "Us_BFu33_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu33_BFu0ll(Test_Us_BFu33_BFu0ll, "Us_BFu33_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu33_BFu0s()
{
  {
    init_simple_test("Us_BFu33_BFu0s");
    static Us_BFu33_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu33_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu33_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu33_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 33, 1, "Us_BFu33_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 33, hide_ull(1LL<<32), "Us_BFu33_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu33_BFu0s(Test_Us_BFu33_BFu0s, "Us_BFu33_BFu0s", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu7c_BFu0c()
{
  {
    init_simple_test("Us_BFu7c_BFu0c");
    static Us_BFu7c_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu7c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu7c_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu7c_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7c_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7c_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu7c_BFu0c(Test_Us_BFu7c_BFu0c, "Us_BFu7c_BFu0c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu7c_BFu0i()
{
  {
    init_simple_test("Us_BFu7c_BFu0i");
    static Us_BFu7c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu7c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7c_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu7c_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7c_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7c_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu7c_BFu0i(Test_Us_BFu7c_BFu0i, "Us_BFu7c_BFu0i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu7c_BFu0ll()
{
  {
    init_simple_test("Us_BFu7c_BFu0ll");
    static Us_BFu7c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu7c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu7c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7c_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7c_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu7c_BFu0ll(Test_Us_BFu7c_BFu0ll, "Us_BFu7c_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu7c_BFu0s()
{
  {
    init_simple_test("Us_BFu7c_BFu0s");
    static Us_BFu7c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu7c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7c_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu7c_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7c_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7c_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu7c_BFu0s(Test_Us_BFu7c_BFu0s, "Us_BFu7c_BFu0s", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu7i_BFu0c()
{
  {
    init_simple_test("Us_BFu7i_BFu0c");
    static Us_BFu7i_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu7i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu7i_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu7i_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7i_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7i_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu7i_BFu0c(Test_Us_BFu7i_BFu0c, "Us_BFu7i_BFu0c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu7i_BFu0i()
{
  {
    init_simple_test("Us_BFu7i_BFu0i");
    static Us_BFu7i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu7i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7i_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu7i_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7i_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7i_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu7i_BFu0i(Test_Us_BFu7i_BFu0i, "Us_BFu7i_BFu0i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu7i_BFu0ll()
{
  {
    init_simple_test("Us_BFu7i_BFu0ll");
    static Us_BFu7i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu7i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu7i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7i_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu7i_BFu0ll(Test_Us_BFu7i_BFu0ll, "Us_BFu7i_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu7i_BFu0s()
{
  {
    init_simple_test("Us_BFu7i_BFu0s");
    static Us_BFu7i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu7i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7i_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu7i_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7i_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7i_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu7i_BFu0s(Test_Us_BFu7i_BFu0s, "Us_BFu7i_BFu0s", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu7ll_BFu0c()
{
  {
    init_simple_test("Us_BFu7ll_BFu0c");
    static Us_BFu7ll_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu7ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu7ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu7ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7ll_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu7ll_BFu0c(Test_Us_BFu7ll_BFu0c, "Us_BFu7ll_BFu0c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu7ll_BFu0i()
{
  {
    init_simple_test("Us_BFu7ll_BFu0i");
    static Us_BFu7ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu7ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu7ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7ll_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu7ll_BFu0i(Test_Us_BFu7ll_BFu0i, "Us_BFu7ll_BFu0i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu7ll_BFu0ll()
{
  {
    init_simple_test("Us_BFu7ll_BFu0ll");
    static Us_BFu7ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu7ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu7ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7ll_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu7ll_BFu0ll(Test_Us_BFu7ll_BFu0ll, "Us_BFu7ll_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu7ll_BFu0s()
{
  {
    init_simple_test("Us_BFu7ll_BFu0s");
    static Us_BFu7ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu7ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu7ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7ll_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu7ll_BFu0s(Test_Us_BFu7ll_BFu0s, "Us_BFu7ll_BFu0s", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu7s_BFu0c()
{
  {
    init_simple_test("Us_BFu7s_BFu0c");
    static Us_BFu7s_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu7s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu7s_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu7s_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7s_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7s_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu7s_BFu0c(Test_Us_BFu7s_BFu0c, "Us_BFu7s_BFu0c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu7s_BFu0i()
{
  {
    init_simple_test("Us_BFu7s_BFu0i");
    static Us_BFu7s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu7s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7s_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu7s_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7s_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7s_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu7s_BFu0i(Test_Us_BFu7s_BFu0i, "Us_BFu7s_BFu0i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu7s_BFu0ll()
{
  {
    init_simple_test("Us_BFu7s_BFu0ll");
    static Us_BFu7s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu7s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu7s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7s_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7s_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu7s_BFu0ll(Test_Us_BFu7s_BFu0ll, "Us_BFu7s_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu7s_BFu0s()
{
  {
    init_simple_test("Us_BFu7s_BFu0s");
    static Us_BFu7s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu7s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7s_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu7s_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7s_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7s_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu7s_BFu0s(Test_Us_BFu7s_BFu0s, "Us_BFu7s_BFu0s", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu8c_BFu0c()
{
  {
    init_simple_test("Us_BFu8c_BFu0c");
    static Us_BFu8c_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu8c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu8c_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu8c_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8c_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8c_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu8c_BFu0c(Test_Us_BFu8c_BFu0c, "Us_BFu8c_BFu0c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu8c_BFu0i()
{
  {
    init_simple_test("Us_BFu8c_BFu0i");
    static Us_BFu8c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu8c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8c_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu8c_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8c_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8c_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu8c_BFu0i(Test_Us_BFu8c_BFu0i, "Us_BFu8c_BFu0i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu8c_BFu0ll()
{
  {
    init_simple_test("Us_BFu8c_BFu0ll");
    static Us_BFu8c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu8c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu8c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8c_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8c_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu8c_BFu0ll(Test_Us_BFu8c_BFu0ll, "Us_BFu8c_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu8c_BFu0s()
{
  {
    init_simple_test("Us_BFu8c_BFu0s");
    static Us_BFu8c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu8c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8c_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu8c_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8c_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8c_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu8c_BFu0s(Test_Us_BFu8c_BFu0s, "Us_BFu8c_BFu0s", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu8i_BFu0c()
{
  {
    init_simple_test("Us_BFu8i_BFu0c");
    static Us_BFu8i_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu8i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu8i_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu8i_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8i_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8i_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu8i_BFu0c(Test_Us_BFu8i_BFu0c, "Us_BFu8i_BFu0c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu8i_BFu0i()
{
  {
    init_simple_test("Us_BFu8i_BFu0i");
    static Us_BFu8i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu8i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8i_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu8i_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8i_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8i_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu8i_BFu0i(Test_Us_BFu8i_BFu0i, "Us_BFu8i_BFu0i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu8i_BFu0ll()
{
  {
    init_simple_test("Us_BFu8i_BFu0ll");
    static Us_BFu8i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu8i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu8i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8i_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu8i_BFu0ll(Test_Us_BFu8i_BFu0ll, "Us_BFu8i_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu8i_BFu0s()
{
  {
    init_simple_test("Us_BFu8i_BFu0s");
    static Us_BFu8i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu8i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8i_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu8i_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8i_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8i_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu8i_BFu0s(Test_Us_BFu8i_BFu0s, "Us_BFu8i_BFu0s", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu8ll_BFu0c()
{
  {
    init_simple_test("Us_BFu8ll_BFu0c");
    static Us_BFu8ll_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu8ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu8ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu8ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8ll_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu8ll_BFu0c(Test_Us_BFu8ll_BFu0c, "Us_BFu8ll_BFu0c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu8ll_BFu0i()
{
  {
    init_simple_test("Us_BFu8ll_BFu0i");
    static Us_BFu8ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu8ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu8ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8ll_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu8ll_BFu0i(Test_Us_BFu8ll_BFu0i, "Us_BFu8ll_BFu0i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu8ll_BFu0ll()
{
  {
    init_simple_test("Us_BFu8ll_BFu0ll");
    static Us_BFu8ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu8ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu8ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8ll_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu8ll_BFu0ll(Test_Us_BFu8ll_BFu0ll, "Us_BFu8ll_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu8ll_BFu0s()
{
  {
    init_simple_test("Us_BFu8ll_BFu0s");
    static Us_BFu8ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu8ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu8ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8ll_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu8ll_BFu0s(Test_Us_BFu8ll_BFu0s, "Us_BFu8ll_BFu0s", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu8s_BFu0c()
{
  {
    init_simple_test("Us_BFu8s_BFu0c");
    static Us_BFu8s_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu8s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu8s_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu8s_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8s_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8s_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu8s_BFu0c(Test_Us_BFu8s_BFu0c, "Us_BFu8s_BFu0c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu8s_BFu0i()
{
  {
    init_simple_test("Us_BFu8s_BFu0i");
    static Us_BFu8s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu8s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8s_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu8s_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8s_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8s_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu8s_BFu0i(Test_Us_BFu8s_BFu0i, "Us_BFu8s_BFu0i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu8s_BFu0ll()
{
  {
    init_simple_test("Us_BFu8s_BFu0ll");
    static Us_BFu8s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu8s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu8s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8s_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8s_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu8s_BFu0ll(Test_Us_BFu8s_BFu0ll, "Us_BFu8s_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu8s_BFu0s()
{
  {
    init_simple_test("Us_BFu8s_BFu0s");
    static Us_BFu8s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu8s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8s_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu8s_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8s_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8s_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu8s_BFu0s(Test_Us_BFu8s_BFu0s, "Us_BFu8s_BFu0s", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu9i_BFu0c()
{
  {
    init_simple_test("Us_BFu9i_BFu0c");
    static Us_BFu9i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu9i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu9i_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu9i_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9i_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9i_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu9i_BFu0c(Test_Us_BFu9i_BFu0c, "Us_BFu9i_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu9i_BFu0i()
{
  {
    init_simple_test("Us_BFu9i_BFu0i");
    static Us_BFu9i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu9i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu9i_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu9i_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9i_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9i_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu9i_BFu0i(Test_Us_BFu9i_BFu0i, "Us_BFu9i_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu9i_BFu0ll()
{
  {
    init_simple_test("Us_BFu9i_BFu0ll");
    static Us_BFu9i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu9i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu9i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu9i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9i_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9i_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu9i_BFu0ll(Test_Us_BFu9i_BFu0ll, "Us_BFu9i_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu9i_BFu0s()
{
  {
    init_simple_test("Us_BFu9i_BFu0s");
    static Us_BFu9i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu9i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu9i_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu9i_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9i_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9i_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu9i_BFu0s(Test_Us_BFu9i_BFu0s, "Us_BFu9i_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu9ll_BFu0c()
{
  {
    init_simple_test("Us_BFu9ll_BFu0c");
    static Us_BFu9ll_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu9ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu9ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu9ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9ll_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9ll_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu9ll_BFu0c(Test_Us_BFu9ll_BFu0c, "Us_BFu9ll_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu9ll_BFu0i()
{
  {
    init_simple_test("Us_BFu9ll_BFu0i");
    static Us_BFu9ll_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu9ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu9ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu9ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9ll_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9ll_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu9ll_BFu0i(Test_Us_BFu9ll_BFu0i, "Us_BFu9ll_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu9ll_BFu0ll()
{
  {
    init_simple_test("Us_BFu9ll_BFu0ll");
    static Us_BFu9ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu9ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu9ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu9ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9ll_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu9ll_BFu0ll(Test_Us_BFu9ll_BFu0ll, "Us_BFu9ll_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu9ll_BFu0s()
{
  {
    init_simple_test("Us_BFu9ll_BFu0s");
    static Us_BFu9ll_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu9ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu9ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu9ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9ll_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9ll_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu9ll_BFu0s(Test_Us_BFu9ll_BFu0s, "Us_BFu9ll_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu9s_BFu0c()
{
  {
    init_simple_test("Us_BFu9s_BFu0c");
    static Us_BFu9s_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu9s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu9s_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu9s_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9s_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9s_BFu0c");
  }
}
static Arrange_To_Call_Me vUs_BFu9s_BFu0c(Test_Us_BFu9s_BFu0c, "Us_BFu9s_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu9s_BFu0i()
{
  {
    init_simple_test("Us_BFu9s_BFu0i");
    static Us_BFu9s_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu9s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu9s_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu9s_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9s_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9s_BFu0i");
  }
}
static Arrange_To_Call_Me vUs_BFu9s_BFu0i(Test_Us_BFu9s_BFu0i, "Us_BFu9s_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu9s_BFu0ll()
{
  {
    init_simple_test("Us_BFu9s_BFu0ll");
    static Us_BFu9s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu9s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu9s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu9s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9s_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9s_BFu0ll");
  }
}
static Arrange_To_Call_Me vUs_BFu9s_BFu0ll(Test_Us_BFu9s_BFu0ll, "Us_BFu9s_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_BFu9s_BFu0s()
{
  {
    init_simple_test("Us_BFu9s_BFu0s");
    static Us_BFu9s_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu9s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu9s_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu9s_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9s_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9s_BFu0s");
  }
}
static Arrange_To_Call_Me vUs_BFu9s_BFu0s(Test_Us_BFu9s_BFu0s, "Us_BFu9s_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_C_BFu0c()
{
  {
    init_simple_test("Us_C_BFu0c");
    static Us_C_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_C_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_C_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_C_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_C_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUs_C_BFu0c(Test_Us_C_BFu0c, "Us_C_BFu0c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_C_BFu0i()
{
  {
    init_simple_test("Us_C_BFu0i");
    static Us_C_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_C_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_C_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_C_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_C_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUs_C_BFu0i(Test_Us_C_BFu0i, "Us_C_BFu0i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_C_BFu0ll()
{
  {
    init_simple_test("Us_C_BFu0ll");
    static Us_C_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_C_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_C_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_C_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_C_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUs_C_BFu0ll(Test_Us_C_BFu0ll, "Us_C_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_C_BFu0s()
{
  {
    init_simple_test("Us_C_BFu0s");
    static Us_C_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_C_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_C_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_C_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_C_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUs_C_BFu0s(Test_Us_C_BFu0s, "Us_C_BFu0s", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_D_BFu0c()
{
  {
    init_simple_test("Us_D_BFu0c");
    static Us_D_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Us_D_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_D_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_D_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_D_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUs_D_BFu0c(Test_Us_D_BFu0c, "Us_D_BFu0c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_D_BFu0i()
{
  {
    init_simple_test("Us_D_BFu0i");
    static Us_D_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Us_D_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_D_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_D_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_D_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUs_D_BFu0i(Test_Us_D_BFu0i, "Us_D_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_D_BFu0ll()
{
  {
    init_simple_test("Us_D_BFu0ll");
    static Us_D_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Us_D_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_D_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_D_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_D_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUs_D_BFu0ll(Test_Us_D_BFu0ll, "Us_D_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_D_BFu0s()
{
  {
    init_simple_test("Us_D_BFu0s");
    static Us_D_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Us_D_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_D_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_D_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_D_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUs_D_BFu0s(Test_Us_D_BFu0s, "Us_D_BFu0s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_F_BFu0c()
{
  {
    init_simple_test("Us_F_BFu0c");
    static Us_F_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Us_F_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_F_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_F_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_F_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUs_F_BFu0c(Test_Us_F_BFu0c, "Us_F_BFu0c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_F_BFu0i()
{
  {
    init_simple_test("Us_F_BFu0i");
    static Us_F_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_F_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_F_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_F_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_F_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUs_F_BFu0i(Test_Us_F_BFu0i, "Us_F_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_F_BFu0ll()
{
  {
    init_simple_test("Us_F_BFu0ll");
    static Us_F_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_F_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_F_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_F_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_F_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUs_F_BFu0ll(Test_Us_F_BFu0ll, "Us_F_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_F_BFu0s()
{
  {
    init_simple_test("Us_F_BFu0s");
    static Us_F_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Us_F_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_F_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_F_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_F_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUs_F_BFu0s(Test_Us_F_BFu0s, "Us_F_BFu0s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_I_BFu0c()
{
  {
    init_simple_test("Us_I_BFu0c");
    static Us_I_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Us_I_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_I_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_I_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_I_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUs_I_BFu0c(Test_Us_I_BFu0c, "Us_I_BFu0c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_I_BFu0i()
{
  {
    init_simple_test("Us_I_BFu0i");
    static Us_I_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_I_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_I_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_I_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_I_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUs_I_BFu0i(Test_Us_I_BFu0i, "Us_I_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_I_BFu0ll()
{
  {
    init_simple_test("Us_I_BFu0ll");
    static Us_I_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_I_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_I_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_I_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_I_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUs_I_BFu0ll(Test_Us_I_BFu0ll, "Us_I_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_I_BFu0s()
{
  {
    init_simple_test("Us_I_BFu0s");
    static Us_I_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Us_I_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_I_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_I_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_I_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUs_I_BFu0s(Test_Us_I_BFu0s, "Us_I_BFu0s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Ip_BFu0c()
{
  {
    init_simple_test("Us_Ip_BFu0c");
    static Us_Ip_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_Ip_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Ip_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_Ip_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_Ip_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUs_Ip_BFu0c(Test_Us_Ip_BFu0c, "Us_Ip_BFu0c", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Ip_BFu0i()
{
  {
    init_simple_test("Us_Ip_BFu0i");
    static Us_Ip_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_Ip_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Ip_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_Ip_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_Ip_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUs_Ip_BFu0i(Test_Us_Ip_BFu0i, "Us_Ip_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Ip_BFu0ll()
{
  {
    init_simple_test("Us_Ip_BFu0ll");
    static Us_Ip_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Us_Ip_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Ip_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_Ip_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_Ip_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUs_Ip_BFu0ll(Test_Us_Ip_BFu0ll, "Us_Ip_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Ip_BFu0s()
{
  {
    init_simple_test("Us_Ip_BFu0s");
    static Us_Ip_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_Ip_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Ip_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_Ip_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_Ip_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUs_Ip_BFu0s(Test_Us_Ip_BFu0s, "Us_Ip_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_L_BFu0c()
{
  {
    init_simple_test("Us_L_BFu0c");
    static Us_L_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Us_L_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_L_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_L_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_L_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUs_L_BFu0c(Test_Us_L_BFu0c, "Us_L_BFu0c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_L_BFu0i()
{
  {
    init_simple_test("Us_L_BFu0i");
    static Us_L_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Us_L_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_L_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_L_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_L_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUs_L_BFu0i(Test_Us_L_BFu0i, "Us_L_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_L_BFu0ll()
{
  {
    init_simple_test("Us_L_BFu0ll");
    static Us_L_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Us_L_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_L_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_L_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_L_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUs_L_BFu0ll(Test_Us_L_BFu0ll, "Us_L_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_L_BFu0s()
{
  {
    init_simple_test("Us_L_BFu0s");
    static Us_L_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Us_L_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_L_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_L_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_L_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUs_L_BFu0s(Test_Us_L_BFu0s, "Us_L_BFu0s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_S_BFu0c()
{
  {
    init_simple_test("Us_S_BFu0c");
    static Us_S_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_S_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_S_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_S_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_S_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUs_S_BFu0c(Test_Us_S_BFu0c, "Us_S_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_S_BFu0i()
{
  {
    init_simple_test("Us_S_BFu0i");
    static Us_S_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_S_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_S_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_S_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_S_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUs_S_BFu0i(Test_Us_S_BFu0i, "Us_S_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_S_BFu0ll()
{
  {
    init_simple_test("Us_S_BFu0ll");
    static Us_S_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_S_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_S_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_S_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_S_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUs_S_BFu0ll(Test_Us_S_BFu0ll, "Us_S_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_S_BFu0s()
{
  {
    init_simple_test("Us_S_BFu0s");
    static Us_S_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_S_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_S_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_S_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_S_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUs_S_BFu0s(Test_Us_S_BFu0s, "Us_S_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Uc_BFu0c()
{
  {
    init_simple_test("Us_Uc_BFu0c");
    static Us_Uc_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_Uc_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Uc_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_Uc_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_Uc_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUs_Uc_BFu0c(Test_Us_Uc_BFu0c, "Us_Uc_BFu0c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Uc_BFu0i()
{
  {
    init_simple_test("Us_Uc_BFu0i");
    static Us_Uc_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_Uc_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Uc_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_Uc_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_Uc_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUs_Uc_BFu0i(Test_Us_Uc_BFu0i, "Us_Uc_BFu0i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Uc_BFu0ll()
{
  {
    init_simple_test("Us_Uc_BFu0ll");
    static Us_Uc_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_Uc_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Uc_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_Uc_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_Uc_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUs_Uc_BFu0ll(Test_Us_Uc_BFu0ll, "Us_Uc_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Uc_BFu0s()
{
  {
    init_simple_test("Us_Uc_BFu0s");
    static Us_Uc_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_Uc_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Uc_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_Uc_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_Uc_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUs_Uc_BFu0s(Test_Us_Uc_BFu0s, "Us_Uc_BFu0s", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Ui_BFu0c()
{
  {
    init_simple_test("Us_Ui_BFu0c");
    static Us_Ui_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Us_Ui_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Ui_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_Ui_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_Ui_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUs_Ui_BFu0c(Test_Us_Ui_BFu0c, "Us_Ui_BFu0c", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Ui_BFu0i()
{
  {
    init_simple_test("Us_Ui_BFu0i");
    static Us_Ui_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_Ui_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Ui_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_Ui_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_Ui_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUs_Ui_BFu0i(Test_Us_Ui_BFu0i, "Us_Ui_BFu0i", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Ui_BFu0ll()
{
  {
    init_simple_test("Us_Ui_BFu0ll");
    static Us_Ui_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_Ui_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Ui_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_Ui_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_Ui_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUs_Ui_BFu0ll(Test_Us_Ui_BFu0ll, "Us_Ui_BFu0ll", ABISELECT(8,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Ui_BFu0s()
{
  {
    init_simple_test("Us_Ui_BFu0s");
    static Us_Ui_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Us_Ui_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Ui_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_Ui_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_Ui_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUs_Ui_BFu0s(Test_Us_Ui_BFu0s, "Us_Ui_BFu0s", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Ul_BFu0c()
{
  {
    init_simple_test("Us_Ul_BFu0c");
    static Us_Ul_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Us_Ul_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Ul_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_Ul_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_Ul_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUs_Ul_BFu0c(Test_Us_Ul_BFu0c, "Us_Ul_BFu0c", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Ul_BFu0i()
{
  {
    init_simple_test("Us_Ul_BFu0i");
    static Us_Ul_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Us_Ul_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Ul_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_Ul_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_Ul_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUs_Ul_BFu0i(Test_Us_Ul_BFu0i, "Us_Ul_BFu0i", ABISELECT(12,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Ul_BFu0ll()
{
  {
    init_simple_test("Us_Ul_BFu0ll");
    static Us_Ul_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Us_Ul_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Ul_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_Ul_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_Ul_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUs_Ul_BFu0ll(Test_Us_Ul_BFu0ll, "Us_Ul_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Ul_BFu0s()
{
  {
    init_simple_test("Us_Ul_BFu0s");
    static Us_Ul_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Us_Ul_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Ul_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_Ul_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_Ul_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUs_Ul_BFu0s(Test_Us_Ul_BFu0s, "Us_Ul_BFu0s", 10);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Us_BFu0c()
{
  {
    init_simple_test("Us_Us_BFu0c");
    static Us_Us_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_Us_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Us_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_Us_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_Us_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUs_Us_BFu0c(Test_Us_Us_BFu0c, "Us_Us_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Us_BFu0i()
{
  {
    init_simple_test("Us_Us_BFu0i");
    static Us_Us_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_Us_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Us_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_Us_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_Us_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUs_Us_BFu0i(Test_Us_Us_BFu0i, "Us_Us_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Us_BFu0ll()
{
  {
    init_simple_test("Us_Us_BFu0ll");
    static Us_Us_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_Us_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Us_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_Us_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_Us_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUs_Us_BFu0ll(Test_Us_Us_BFu0ll, "Us_Us_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Us_BFu0s()
{
  {
    init_simple_test("Us_Us_BFu0s");
    static Us_Us_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_Us_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Us_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_Us_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_Us_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUs_Us_BFu0s(Test_Us_Us_BFu0s, "Us_Us_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Vp_BFu0c()
{
  {
    init_simple_test("Us_Vp_BFu0c");
    static Us_Vp_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_Vp_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Vp_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_Vp_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_Vp_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUs_Vp_BFu0c(Test_Us_Vp_BFu0c, "Us_Vp_BFu0c", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Vp_BFu0i()
{
  {
    init_simple_test("Us_Vp_BFu0i");
    static Us_Vp_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_Vp_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Vp_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_Vp_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_Vp_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUs_Vp_BFu0i(Test_Us_Vp_BFu0i, "Us_Vp_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Vp_BFu0ll()
{
  {
    init_simple_test("Us_Vp_BFu0ll");
    static Us_Vp_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Us_Vp_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Vp_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_Vp_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_Vp_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUs_Vp_BFu0ll(Test_Us_Vp_BFu0ll, "Us_Vp_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Us_Vp_BFu0s()
{
  {
    init_simple_test("Us_Vp_BFu0s");
    static Us_Vp_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_Vp_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Vp_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_Vp_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_Vp_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUs_Vp_BFu0s(Test_Us_Vp_BFu0s, "Us_Vp_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c()
{
  {
    init_simple_test("Vp_BFu0c");
    static Vp_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vVp_BFu0c(Test_Vp_BFu0c, "Vp_BFu0c", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu0c()
{
  {
    init_simple_test("Vp_BFu0c_BFu0c");
    static Vp_BFu0c_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu0c(Test_Vp_BFu0c_BFu0c, "Vp_BFu0c_BFu0c", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu0i()
{
  {
    init_simple_test("Vp_BFu0c_BFu0i");
    static Vp_BFu0c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0c_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu0i(Test_Vp_BFu0c_BFu0i, "Vp_BFu0c_BFu0i", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu0ll()
{
  {
    init_simple_test("Vp_BFu0c_BFu0ll");
    static Vp_BFu0c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu0ll(Test_Vp_BFu0c_BFu0ll, "Vp_BFu0c_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu0s()
{
  {
    init_simple_test("Vp_BFu0c_BFu0s");
    static Vp_BFu0c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0c_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu0s(Test_Vp_BFu0c_BFu0s, "Vp_BFu0c_BFu0s", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu15i()
{
  {
    init_simple_test("Vp_BFu0c_BFu15i");
    static Vp_BFu0c_BFu15i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0c_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0c_BFu15i");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu15i(Test_Vp_BFu0c_BFu15i, "Vp_BFu0c_BFu15i", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu15ll()
{
  {
    init_simple_test("Vp_BFu0c_BFu15ll");
    static Vp_BFu0c_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0c_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0c_BFu15ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu15ll(Test_Vp_BFu0c_BFu15ll, "Vp_BFu0c_BFu15ll", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu15s()
{
  {
    init_simple_test("Vp_BFu0c_BFu15s");
    static Vp_BFu0c_BFu15s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0c_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0c_BFu15s");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu15s(Test_Vp_BFu0c_BFu15s, "Vp_BFu0c_BFu15s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu16i()
{
  {
    init_simple_test("Vp_BFu0c_BFu16i");
    static Vp_BFu0c_BFu16i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0c_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0c_BFu16i");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu16i(Test_Vp_BFu0c_BFu16i, "Vp_BFu0c_BFu16i", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu16ll()
{
  {
    init_simple_test("Vp_BFu0c_BFu16ll");
    static Vp_BFu0c_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0c_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0c_BFu16ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu16ll(Test_Vp_BFu0c_BFu16ll, "Vp_BFu0c_BFu16ll", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu16s()
{
  {
    init_simple_test("Vp_BFu0c_BFu16s");
    static Vp_BFu0c_BFu16s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0c_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0c_BFu16s");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu16s(Test_Vp_BFu0c_BFu16s, "Vp_BFu0c_BFu16s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu17i()
{
  {
    init_simple_test("Vp_BFu0c_BFu17i");
    static Vp_BFu0c_BFu17i lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu0c_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu0c_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu0c_BFu17i");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu17i(Test_Vp_BFu0c_BFu17i, "Vp_BFu0c_BFu17i", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu17ll()
{
  {
    init_simple_test("Vp_BFu0c_BFu17ll");
    static Vp_BFu0c_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu0c_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu0c_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu0c_BFu17ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu17ll(Test_Vp_BFu0c_BFu17ll, "Vp_BFu0c_BFu17ll", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu1c()
{
  {
    init_simple_test("Vp_BFu0c_BFu1c");
    static Vp_BFu0c_BFu1c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0c_BFu1c");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu1c(Test_Vp_BFu0c_BFu1c, "Vp_BFu0c_BFu1c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu1i()
{
  {
    init_simple_test("Vp_BFu0c_BFu1i");
    static Vp_BFu0c_BFu1i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0c_BFu1i");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu1i(Test_Vp_BFu0c_BFu1i, "Vp_BFu0c_BFu1i", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu1ll()
{
  {
    init_simple_test("Vp_BFu0c_BFu1ll");
    static Vp_BFu0c_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0c_BFu1ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu1ll(Test_Vp_BFu0c_BFu1ll, "Vp_BFu0c_BFu1ll", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu1s()
{
  {
    init_simple_test("Vp_BFu0c_BFu1s");
    static Vp_BFu0c_BFu1s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0c_BFu1s");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu1s(Test_Vp_BFu0c_BFu1s, "Vp_BFu0c_BFu1s", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu31i()
{
  {
    init_simple_test("Vp_BFu0c_BFu31i");
    static Vp_BFu0c_BFu31i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0c_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu0c_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu0c_BFu31i");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu31i(Test_Vp_BFu0c_BFu31i, "Vp_BFu0c_BFu31i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu31ll()
{
  {
    init_simple_test("Vp_BFu0c_BFu31ll");
    static Vp_BFu0c_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0c_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu0c_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu0c_BFu31ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu31ll(Test_Vp_BFu0c_BFu31ll, "Vp_BFu0c_BFu31ll", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu32i()
{
  {
    init_simple_test("Vp_BFu0c_BFu32i");
    static Vp_BFu0c_BFu32i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0c_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu0c_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu0c_BFu32i");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu32i(Test_Vp_BFu0c_BFu32i, "Vp_BFu0c_BFu32i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu32ll()
{
  {
    init_simple_test("Vp_BFu0c_BFu32ll");
    static Vp_BFu0c_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0c_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu0c_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu0c_BFu32ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu32ll(Test_Vp_BFu0c_BFu32ll, "Vp_BFu0c_BFu32ll", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu33()
{
  {
    init_simple_test("Vp_BFu0c_BFu33");
    static Vp_BFu0c_BFu33 lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_BFu0c_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu0c_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu0c_BFu33");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu33(Test_Vp_BFu0c_BFu33, "Vp_BFu0c_BFu33", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu7c()
{
  {
    init_simple_test("Vp_BFu0c_BFu7c");
    static Vp_BFu0c_BFu7c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0c_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0c_BFu7c");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu7c(Test_Vp_BFu0c_BFu7c, "Vp_BFu0c_BFu7c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu7i()
{
  {
    init_simple_test("Vp_BFu0c_BFu7i");
    static Vp_BFu0c_BFu7i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0c_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0c_BFu7i");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu7i(Test_Vp_BFu0c_BFu7i, "Vp_BFu0c_BFu7i", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu7ll()
{
  {
    init_simple_test("Vp_BFu0c_BFu7ll");
    static Vp_BFu0c_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0c_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0c_BFu7ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu7ll(Test_Vp_BFu0c_BFu7ll, "Vp_BFu0c_BFu7ll", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu7s()
{
  {
    init_simple_test("Vp_BFu0c_BFu7s");
    static Vp_BFu0c_BFu7s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0c_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0c_BFu7s");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu7s(Test_Vp_BFu0c_BFu7s, "Vp_BFu0c_BFu7s", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu8c()
{
  {
    init_simple_test("Vp_BFu0c_BFu8c");
    static Vp_BFu0c_BFu8c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0c_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0c_BFu8c");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu8c(Test_Vp_BFu0c_BFu8c, "Vp_BFu0c_BFu8c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu8i()
{
  {
    init_simple_test("Vp_BFu0c_BFu8i");
    static Vp_BFu0c_BFu8i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0c_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0c_BFu8i");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu8i(Test_Vp_BFu0c_BFu8i, "Vp_BFu0c_BFu8i", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu8ll()
{
  {
    init_simple_test("Vp_BFu0c_BFu8ll");
    static Vp_BFu0c_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0c_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0c_BFu8ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu8ll(Test_Vp_BFu0c_BFu8ll, "Vp_BFu0c_BFu8ll", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu8s()
{
  {
    init_simple_test("Vp_BFu0c_BFu8s");
    static Vp_BFu0c_BFu8s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0c_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0c_BFu8s");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu8s(Test_Vp_BFu0c_BFu8s, "Vp_BFu0c_BFu8s", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu9i()
{
  {
    init_simple_test("Vp_BFu0c_BFu9i");
    static Vp_BFu0c_BFu9i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0c_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0c_BFu9i");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu9i(Test_Vp_BFu0c_BFu9i, "Vp_BFu0c_BFu9i", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu9ll()
{
  {
    init_simple_test("Vp_BFu0c_BFu9ll");
    static Vp_BFu0c_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0c_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0c_BFu9ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu9ll(Test_Vp_BFu0c_BFu9ll, "Vp_BFu0c_BFu9ll", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_BFu9s()
{
  {
    init_simple_test("Vp_BFu0c_BFu9s");
    static Vp_BFu0c_BFu9s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0c_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0c_BFu9s");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_BFu9s(Test_Vp_BFu0c_BFu9s, "Vp_BFu0c_BFu9s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_C()
{
  {
    init_simple_test("Vp_BFu0c_C");
    static Vp_BFu0c_C lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_C)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_C)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_C.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_C(Test_Vp_BFu0c_C, "Vp_BFu0c_C", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_D()
{
  {
    init_simple_test("Vp_BFu0c_D");
    static Vp_BFu0c_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0c_D)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_D)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_D.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_D(Test_Vp_BFu0c_D, "Vp_BFu0c_D", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_F()
{
  {
    init_simple_test("Vp_BFu0c_F");
    static Vp_BFu0c_F lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0c_F)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_F)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_F.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_F(Test_Vp_BFu0c_F, "Vp_BFu0c_F", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_I()
{
  {
    init_simple_test("Vp_BFu0c_I");
    static Vp_BFu0c_I lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0c_I)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_I)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_I.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_I(Test_Vp_BFu0c_I, "Vp_BFu0c_I", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_Ip()
{
  {
    init_simple_test("Vp_BFu0c_Ip");
    static Vp_BFu0c_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu0c_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_Ip)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_Ip.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_Ip(Test_Vp_BFu0c_Ip, "Vp_BFu0c_Ip", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_L()
{
  {
    init_simple_test("Vp_BFu0c_L");
    static Vp_BFu0c_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0c_L)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_L)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_L.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_L(Test_Vp_BFu0c_L, "Vp_BFu0c_L", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_S()
{
  {
    init_simple_test("Vp_BFu0c_S");
    static Vp_BFu0c_S lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_S)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_S)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_S.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_S(Test_Vp_BFu0c_S, "Vp_BFu0c_S", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_Uc()
{
  {
    init_simple_test("Vp_BFu0c_Uc");
    static Vp_BFu0c_Uc lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_Uc)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_Uc.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_Uc(Test_Vp_BFu0c_Uc, "Vp_BFu0c_Uc", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_Ui()
{
  {
    init_simple_test("Vp_BFu0c_Ui");
    static Vp_BFu0c_Ui lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0c_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_Ui)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_Ui.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_Ui(Test_Vp_BFu0c_Ui, "Vp_BFu0c_Ui", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_Ul()
{
  {
    init_simple_test("Vp_BFu0c_Ul");
    static Vp_BFu0c_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0c_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_Ul)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_Ul.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_Ul(Test_Vp_BFu0c_Ul, "Vp_BFu0c_Ul", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_Us()
{
  {
    init_simple_test("Vp_BFu0c_Us");
    static Vp_BFu0c_Us lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_Us)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_Us.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_Us(Test_Vp_BFu0c_Us, "Vp_BFu0c_Us", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0c_Vp()
{
  {
    init_simple_test("Vp_BFu0c_Vp");
    static Vp_BFu0c_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu0c_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_Vp)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_Vp.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_Vp(Test_Vp_BFu0c_Vp, "Vp_BFu0c_Vp", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i()
{
  {
    init_simple_test("Vp_BFu0i");
    static Vp_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vVp_BFu0i(Test_Vp_BFu0i, "Vp_BFu0i", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu0c()
{
  {
    init_simple_test("Vp_BFu0i_BFu0c");
    static Vp_BFu0i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0i_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu0c(Test_Vp_BFu0i_BFu0c, "Vp_BFu0i_BFu0c", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu0i()
{
  {
    init_simple_test("Vp_BFu0i_BFu0i");
    static Vp_BFu0i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu0i(Test_Vp_BFu0i_BFu0i, "Vp_BFu0i_BFu0i", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu0ll()
{
  {
    init_simple_test("Vp_BFu0i_BFu0ll");
    static Vp_BFu0i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu0ll(Test_Vp_BFu0i_BFu0ll, "Vp_BFu0i_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu0s()
{
  {
    init_simple_test("Vp_BFu0i_BFu0s");
    static Vp_BFu0i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu0s(Test_Vp_BFu0i_BFu0s, "Vp_BFu0i_BFu0s", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu15i()
{
  {
    init_simple_test("Vp_BFu0i_BFu15i");
    static Vp_BFu0i_BFu15i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_BFu15i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0i_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0i_BFu15i");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu15i(Test_Vp_BFu0i_BFu15i, "Vp_BFu0i_BFu15i", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu15ll()
{
  {
    init_simple_test("Vp_BFu0i_BFu15ll");
    static Vp_BFu0i_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0i_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0i_BFu15ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu15ll(Test_Vp_BFu0i_BFu15ll, "Vp_BFu0i_BFu15ll", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu15s()
{
  {
    init_simple_test("Vp_BFu0i_BFu15s");
    static Vp_BFu0i_BFu15s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_BFu15s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0i_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0i_BFu15s");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu15s(Test_Vp_BFu0i_BFu15s, "Vp_BFu0i_BFu15s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu16i()
{
  {
    init_simple_test("Vp_BFu0i_BFu16i");
    static Vp_BFu0i_BFu16i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_BFu16i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0i_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0i_BFu16i");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu16i(Test_Vp_BFu0i_BFu16i, "Vp_BFu0i_BFu16i", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu16ll()
{
  {
    init_simple_test("Vp_BFu0i_BFu16ll");
    static Vp_BFu0i_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0i_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0i_BFu16ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu16ll(Test_Vp_BFu0i_BFu16ll, "Vp_BFu0i_BFu16ll", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu16s()
{
  {
    init_simple_test("Vp_BFu0i_BFu16s");
    static Vp_BFu0i_BFu16s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_BFu16s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0i_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0i_BFu16s");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu16s(Test_Vp_BFu0i_BFu16s, "Vp_BFu0i_BFu16s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu17i()
{
  {
    init_simple_test("Vp_BFu0i_BFu17i");
    static Vp_BFu0i_BFu17i lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu0i_BFu17i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu0i_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu0i_BFu17i");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu17i(Test_Vp_BFu0i_BFu17i, "Vp_BFu0i_BFu17i", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu17ll()
{
  {
    init_simple_test("Vp_BFu0i_BFu17ll");
    static Vp_BFu0i_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu0i_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu0i_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu0i_BFu17ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu17ll(Test_Vp_BFu0i_BFu17ll, "Vp_BFu0i_BFu17ll", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu1c()
{
  {
    init_simple_test("Vp_BFu0i_BFu1c");
    static Vp_BFu0i_BFu1c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0i_BFu1c");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu1c(Test_Vp_BFu0i_BFu1c, "Vp_BFu0i_BFu1c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu1i()
{
  {
    init_simple_test("Vp_BFu0i_BFu1i");
    static Vp_BFu0i_BFu1i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu1i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0i_BFu1i");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu1i(Test_Vp_BFu0i_BFu1i, "Vp_BFu0i_BFu1i", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu1ll()
{
  {
    init_simple_test("Vp_BFu0i_BFu1ll");
    static Vp_BFu0i_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0i_BFu1ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu1ll(Test_Vp_BFu0i_BFu1ll, "Vp_BFu0i_BFu1ll", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu1s()
{
  {
    init_simple_test("Vp_BFu0i_BFu1s");
    static Vp_BFu0i_BFu1s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu1s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0i_BFu1s");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu1s(Test_Vp_BFu0i_BFu1s, "Vp_BFu0i_BFu1s", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu31i()
{
  {
    init_simple_test("Vp_BFu0i_BFu31i");
    static Vp_BFu0i_BFu31i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0i_BFu31i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu0i_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu0i_BFu31i");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu31i(Test_Vp_BFu0i_BFu31i, "Vp_BFu0i_BFu31i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu31ll()
{
  {
    init_simple_test("Vp_BFu0i_BFu31ll");
    static Vp_BFu0i_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0i_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu0i_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu0i_BFu31ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu31ll(Test_Vp_BFu0i_BFu31ll, "Vp_BFu0i_BFu31ll", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu32i()
{
  {
    init_simple_test("Vp_BFu0i_BFu32i");
    static Vp_BFu0i_BFu32i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0i_BFu32i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu0i_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu0i_BFu32i");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu32i(Test_Vp_BFu0i_BFu32i, "Vp_BFu0i_BFu32i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu32ll()
{
  {
    init_simple_test("Vp_BFu0i_BFu32ll");
    static Vp_BFu0i_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0i_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu0i_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu0i_BFu32ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu32ll(Test_Vp_BFu0i_BFu32ll, "Vp_BFu0i_BFu32ll", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu33()
{
  {
    init_simple_test("Vp_BFu0i_BFu33");
    static Vp_BFu0i_BFu33 lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_BFu0i_BFu33)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu0i_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu0i_BFu33");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu33(Test_Vp_BFu0i_BFu33, "Vp_BFu0i_BFu33", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu7c()
{
  {
    init_simple_test("Vp_BFu0i_BFu7c");
    static Vp_BFu0i_BFu7c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0i_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0i_BFu7c");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu7c(Test_Vp_BFu0i_BFu7c, "Vp_BFu0i_BFu7c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu7i()
{
  {
    init_simple_test("Vp_BFu0i_BFu7i");
    static Vp_BFu0i_BFu7i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu7i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0i_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0i_BFu7i");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu7i(Test_Vp_BFu0i_BFu7i, "Vp_BFu0i_BFu7i", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu7ll()
{
  {
    init_simple_test("Vp_BFu0i_BFu7ll");
    static Vp_BFu0i_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0i_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0i_BFu7ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu7ll(Test_Vp_BFu0i_BFu7ll, "Vp_BFu0i_BFu7ll", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu7s()
{
  {
    init_simple_test("Vp_BFu0i_BFu7s");
    static Vp_BFu0i_BFu7s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu7s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0i_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0i_BFu7s");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu7s(Test_Vp_BFu0i_BFu7s, "Vp_BFu0i_BFu7s", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu8c()
{
  {
    init_simple_test("Vp_BFu0i_BFu8c");
    static Vp_BFu0i_BFu8c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0i_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0i_BFu8c");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu8c(Test_Vp_BFu0i_BFu8c, "Vp_BFu0i_BFu8c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu8i()
{
  {
    init_simple_test("Vp_BFu0i_BFu8i");
    static Vp_BFu0i_BFu8i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu8i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0i_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0i_BFu8i");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu8i(Test_Vp_BFu0i_BFu8i, "Vp_BFu0i_BFu8i", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu8ll()
{
  {
    init_simple_test("Vp_BFu0i_BFu8ll");
    static Vp_BFu0i_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0i_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0i_BFu8ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu8ll(Test_Vp_BFu0i_BFu8ll, "Vp_BFu0i_BFu8ll", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu8s()
{
  {
    init_simple_test("Vp_BFu0i_BFu8s");
    static Vp_BFu0i_BFu8s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu8s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0i_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0i_BFu8s");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu8s(Test_Vp_BFu0i_BFu8s, "Vp_BFu0i_BFu8s", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu9i()
{
  {
    init_simple_test("Vp_BFu0i_BFu9i");
    static Vp_BFu0i_BFu9i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_BFu9i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0i_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0i_BFu9i");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu9i(Test_Vp_BFu0i_BFu9i, "Vp_BFu0i_BFu9i", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu9ll()
{
  {
    init_simple_test("Vp_BFu0i_BFu9ll");
    static Vp_BFu0i_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0i_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0i_BFu9ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu9ll(Test_Vp_BFu0i_BFu9ll, "Vp_BFu0i_BFu9ll", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_BFu9s()
{
  {
    init_simple_test("Vp_BFu0i_BFu9s");
    static Vp_BFu0i_BFu9s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_BFu9s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0i_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0i_BFu9s");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_BFu9s(Test_Vp_BFu0i_BFu9s, "Vp_BFu0i_BFu9s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_C()
{
  {
    init_simple_test("Vp_BFu0i_C");
    static Vp_BFu0i_C lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_C)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_C.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_C(Test_Vp_BFu0i_C, "Vp_BFu0i_C", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_D()
{
  {
    init_simple_test("Vp_BFu0i_D");
    static Vp_BFu0i_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0i_D)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_D)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_D.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_D(Test_Vp_BFu0i_D, "Vp_BFu0i_D", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_F()
{
  {
    init_simple_test("Vp_BFu0i_F");
    static Vp_BFu0i_F lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0i_F)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_F)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_F.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_F(Test_Vp_BFu0i_F, "Vp_BFu0i_F", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_I()
{
  {
    init_simple_test("Vp_BFu0i_I");
    static Vp_BFu0i_I lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0i_I)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_I)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_I.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_I(Test_Vp_BFu0i_I, "Vp_BFu0i_I", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_Ip()
{
  {
    init_simple_test("Vp_BFu0i_Ip");
    static Vp_BFu0i_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu0i_Ip)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_Ip)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_Ip.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_Ip(Test_Vp_BFu0i_Ip, "Vp_BFu0i_Ip", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_L()
{
  {
    init_simple_test("Vp_BFu0i_L");
    static Vp_BFu0i_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0i_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_L)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_L.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_L(Test_Vp_BFu0i_L, "Vp_BFu0i_L", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_S()
{
  {
    init_simple_test("Vp_BFu0i_S");
    static Vp_BFu0i_S lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_S)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_S.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_S(Test_Vp_BFu0i_S, "Vp_BFu0i_S", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_Uc()
{
  {
    init_simple_test("Vp_BFu0i_Uc");
    static Vp_BFu0i_Uc lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_Uc)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_Uc.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_Uc(Test_Vp_BFu0i_Uc, "Vp_BFu0i_Uc", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_Ui()
{
  {
    init_simple_test("Vp_BFu0i_Ui");
    static Vp_BFu0i_Ui lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0i_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_Ui)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_Ui.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_Ui(Test_Vp_BFu0i_Ui, "Vp_BFu0i_Ui", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_Ul()
{
  {
    init_simple_test("Vp_BFu0i_Ul");
    static Vp_BFu0i_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0i_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_Ul)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_Ul.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_Ul(Test_Vp_BFu0i_Ul, "Vp_BFu0i_Ul", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_Us()
{
  {
    init_simple_test("Vp_BFu0i_Us");
    static Vp_BFu0i_Us lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_Us)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_Us.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_Us(Test_Vp_BFu0i_Us, "Vp_BFu0i_Us", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0i_Vp()
{
  {
    init_simple_test("Vp_BFu0i_Vp");
    static Vp_BFu0i_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu0i_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_Vp)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_Vp.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_Vp(Test_Vp_BFu0i_Vp, "Vp_BFu0i_Vp", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll()
{
  {
    init_simple_test("Vp_BFu0ll");
    static Vp_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll(Test_Vp_BFu0ll, "Vp_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu0c()
{
  {
    init_simple_test("Vp_BFu0ll_BFu0c");
    static Vp_BFu0ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu0c(Test_Vp_BFu0ll_BFu0c, "Vp_BFu0ll_BFu0c", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu0i()
{
  {
    init_simple_test("Vp_BFu0ll_BFu0i");
    static Vp_BFu0ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu0i(Test_Vp_BFu0ll_BFu0i, "Vp_BFu0ll_BFu0i", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu0ll()
{
  {
    init_simple_test("Vp_BFu0ll_BFu0ll");
    static Vp_BFu0ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu0ll(Test_Vp_BFu0ll_BFu0ll, "Vp_BFu0ll_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu0s()
{
  {
    init_simple_test("Vp_BFu0ll_BFu0s");
    static Vp_BFu0ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu0s(Test_Vp_BFu0ll_BFu0s, "Vp_BFu0ll_BFu0s", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu15i()
{
  {
    init_simple_test("Vp_BFu0ll_BFu15i");
    static Vp_BFu0ll_BFu15i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_BFu15i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0ll_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0ll_BFu15i");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu15i(Test_Vp_BFu0ll_BFu15i, "Vp_BFu0ll_BFu15i", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu15ll()
{
  {
    init_simple_test("Vp_BFu0ll_BFu15ll");
    static Vp_BFu0ll_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0ll_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0ll_BFu15ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu15ll(Test_Vp_BFu0ll_BFu15ll, "Vp_BFu0ll_BFu15ll", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu15s()
{
  {
    init_simple_test("Vp_BFu0ll_BFu15s");
    static Vp_BFu0ll_BFu15s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_BFu15s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0ll_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0ll_BFu15s");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu15s(Test_Vp_BFu0ll_BFu15s, "Vp_BFu0ll_BFu15s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu16i()
{
  {
    init_simple_test("Vp_BFu0ll_BFu16i");
    static Vp_BFu0ll_BFu16i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_BFu16i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0ll_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0ll_BFu16i");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu16i(Test_Vp_BFu0ll_BFu16i, "Vp_BFu0ll_BFu16i", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu16ll()
{
  {
    init_simple_test("Vp_BFu0ll_BFu16ll");
    static Vp_BFu0ll_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0ll_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0ll_BFu16ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu16ll(Test_Vp_BFu0ll_BFu16ll, "Vp_BFu0ll_BFu16ll", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu16s()
{
  {
    init_simple_test("Vp_BFu0ll_BFu16s");
    static Vp_BFu0ll_BFu16s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_BFu16s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0ll_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0ll_BFu16s");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu16s(Test_Vp_BFu0ll_BFu16s, "Vp_BFu0ll_BFu16s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu17i()
{
  {
    init_simple_test("Vp_BFu0ll_BFu17i");
    static Vp_BFu0ll_BFu17i lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu0ll_BFu17i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu0ll_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu0ll_BFu17i");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu17i(Test_Vp_BFu0ll_BFu17i, "Vp_BFu0ll_BFu17i", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu17ll()
{
  {
    init_simple_test("Vp_BFu0ll_BFu17ll");
    static Vp_BFu0ll_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu0ll_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu0ll_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu0ll_BFu17ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu17ll(Test_Vp_BFu0ll_BFu17ll, "Vp_BFu0ll_BFu17ll", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu1c()
{
  {
    init_simple_test("Vp_BFu0ll_BFu1c");
    static Vp_BFu0ll_BFu1c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0ll_BFu1c");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu1c(Test_Vp_BFu0ll_BFu1c, "Vp_BFu0ll_BFu1c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu1i()
{
  {
    init_simple_test("Vp_BFu0ll_BFu1i");
    static Vp_BFu0ll_BFu1i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu1i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0ll_BFu1i");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu1i(Test_Vp_BFu0ll_BFu1i, "Vp_BFu0ll_BFu1i", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu1ll()
{
  {
    init_simple_test("Vp_BFu0ll_BFu1ll");
    static Vp_BFu0ll_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0ll_BFu1ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu1ll(Test_Vp_BFu0ll_BFu1ll, "Vp_BFu0ll_BFu1ll", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu1s()
{
  {
    init_simple_test("Vp_BFu0ll_BFu1s");
    static Vp_BFu0ll_BFu1s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu1s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0ll_BFu1s");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu1s(Test_Vp_BFu0ll_BFu1s, "Vp_BFu0ll_BFu1s", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu31i()
{
  {
    init_simple_test("Vp_BFu0ll_BFu31i");
    static Vp_BFu0ll_BFu31i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0ll_BFu31i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu0ll_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu0ll_BFu31i");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu31i(Test_Vp_BFu0ll_BFu31i, "Vp_BFu0ll_BFu31i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu31ll()
{
  {
    init_simple_test("Vp_BFu0ll_BFu31ll");
    static Vp_BFu0ll_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0ll_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu0ll_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu0ll_BFu31ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu31ll(Test_Vp_BFu0ll_BFu31ll, "Vp_BFu0ll_BFu31ll", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu32i()
{
  {
    init_simple_test("Vp_BFu0ll_BFu32i");
    static Vp_BFu0ll_BFu32i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0ll_BFu32i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu0ll_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu0ll_BFu32i");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu32i(Test_Vp_BFu0ll_BFu32i, "Vp_BFu0ll_BFu32i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu32ll()
{
  {
    init_simple_test("Vp_BFu0ll_BFu32ll");
    static Vp_BFu0ll_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0ll_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu0ll_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu0ll_BFu32ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu32ll(Test_Vp_BFu0ll_BFu32ll, "Vp_BFu0ll_BFu32ll", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu33()
{
  {
    init_simple_test("Vp_BFu0ll_BFu33");
    static Vp_BFu0ll_BFu33 lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_BFu0ll_BFu33)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu0ll_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu0ll_BFu33");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu33(Test_Vp_BFu0ll_BFu33, "Vp_BFu0ll_BFu33", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu7c()
{
  {
    init_simple_test("Vp_BFu0ll_BFu7c");
    static Vp_BFu0ll_BFu7c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0ll_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0ll_BFu7c");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu7c(Test_Vp_BFu0ll_BFu7c, "Vp_BFu0ll_BFu7c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu7i()
{
  {
    init_simple_test("Vp_BFu0ll_BFu7i");
    static Vp_BFu0ll_BFu7i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu7i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0ll_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0ll_BFu7i");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu7i(Test_Vp_BFu0ll_BFu7i, "Vp_BFu0ll_BFu7i", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu7ll()
{
  {
    init_simple_test("Vp_BFu0ll_BFu7ll");
    static Vp_BFu0ll_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0ll_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0ll_BFu7ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu7ll(Test_Vp_BFu0ll_BFu7ll, "Vp_BFu0ll_BFu7ll", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu7s()
{
  {
    init_simple_test("Vp_BFu0ll_BFu7s");
    static Vp_BFu0ll_BFu7s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu7s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0ll_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0ll_BFu7s");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu7s(Test_Vp_BFu0ll_BFu7s, "Vp_BFu0ll_BFu7s", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu8c()
{
  {
    init_simple_test("Vp_BFu0ll_BFu8c");
    static Vp_BFu0ll_BFu8c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0ll_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0ll_BFu8c");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu8c(Test_Vp_BFu0ll_BFu8c, "Vp_BFu0ll_BFu8c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu8i()
{
  {
    init_simple_test("Vp_BFu0ll_BFu8i");
    static Vp_BFu0ll_BFu8i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu8i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0ll_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0ll_BFu8i");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu8i(Test_Vp_BFu0ll_BFu8i, "Vp_BFu0ll_BFu8i", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu8ll()
{
  {
    init_simple_test("Vp_BFu0ll_BFu8ll");
    static Vp_BFu0ll_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0ll_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0ll_BFu8ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu8ll(Test_Vp_BFu0ll_BFu8ll, "Vp_BFu0ll_BFu8ll", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu8s()
{
  {
    init_simple_test("Vp_BFu0ll_BFu8s");
    static Vp_BFu0ll_BFu8s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu8s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0ll_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0ll_BFu8s");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu8s(Test_Vp_BFu0ll_BFu8s, "Vp_BFu0ll_BFu8s", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu9i()
{
  {
    init_simple_test("Vp_BFu0ll_BFu9i");
    static Vp_BFu0ll_BFu9i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_BFu9i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0ll_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0ll_BFu9i");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu9i(Test_Vp_BFu0ll_BFu9i, "Vp_BFu0ll_BFu9i", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu9ll()
{
  {
    init_simple_test("Vp_BFu0ll_BFu9ll");
    static Vp_BFu0ll_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0ll_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0ll_BFu9ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu9ll(Test_Vp_BFu0ll_BFu9ll, "Vp_BFu0ll_BFu9ll", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_BFu9s()
{
  {
    init_simple_test("Vp_BFu0ll_BFu9s");
    static Vp_BFu0ll_BFu9s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_BFu9s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0ll_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0ll_BFu9s");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_BFu9s(Test_Vp_BFu0ll_BFu9s, "Vp_BFu0ll_BFu9s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_C()
{
  {
    init_simple_test("Vp_BFu0ll_C");
    static Vp_BFu0ll_C lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_C)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_C.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_C(Test_Vp_BFu0ll_C, "Vp_BFu0ll_C", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_D()
{
  {
    init_simple_test("Vp_BFu0ll_D");
    static Vp_BFu0ll_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0ll_D)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_D)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_D.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_D(Test_Vp_BFu0ll_D, "Vp_BFu0ll_D", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_F()
{
  {
    init_simple_test("Vp_BFu0ll_F");
    static Vp_BFu0ll_F lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0ll_F)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_F)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_F.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_F(Test_Vp_BFu0ll_F, "Vp_BFu0ll_F", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_I()
{
  {
    init_simple_test("Vp_BFu0ll_I");
    static Vp_BFu0ll_I lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0ll_I)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_I)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_I.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_I(Test_Vp_BFu0ll_I, "Vp_BFu0ll_I", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_Ip()
{
  {
    init_simple_test("Vp_BFu0ll_Ip");
    static Vp_BFu0ll_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu0ll_Ip)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_Ip)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_Ip.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_Ip(Test_Vp_BFu0ll_Ip, "Vp_BFu0ll_Ip", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_L()
{
  {
    init_simple_test("Vp_BFu0ll_L");
    static Vp_BFu0ll_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0ll_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_L)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_L.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_L(Test_Vp_BFu0ll_L, "Vp_BFu0ll_L", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_S()
{
  {
    init_simple_test("Vp_BFu0ll_S");
    static Vp_BFu0ll_S lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_S)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_S.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_S(Test_Vp_BFu0ll_S, "Vp_BFu0ll_S", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_Uc()
{
  {
    init_simple_test("Vp_BFu0ll_Uc");
    static Vp_BFu0ll_Uc lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_Uc)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_Uc.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_Uc(Test_Vp_BFu0ll_Uc, "Vp_BFu0ll_Uc", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_Ui()
{
  {
    init_simple_test("Vp_BFu0ll_Ui");
    static Vp_BFu0ll_Ui lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0ll_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_Ui)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_Ui.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_Ui(Test_Vp_BFu0ll_Ui, "Vp_BFu0ll_Ui", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_Ul()
{
  {
    init_simple_test("Vp_BFu0ll_Ul");
    static Vp_BFu0ll_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0ll_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_Ul)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_Ul.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_Ul(Test_Vp_BFu0ll_Ul, "Vp_BFu0ll_Ul", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_Us()
{
  {
    init_simple_test("Vp_BFu0ll_Us");
    static Vp_BFu0ll_Us lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_Us)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_Us.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_Us(Test_Vp_BFu0ll_Us, "Vp_BFu0ll_Us", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0ll_Vp()
{
  {
    init_simple_test("Vp_BFu0ll_Vp");
    static Vp_BFu0ll_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu0ll_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_Vp)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_Vp.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_Vp(Test_Vp_BFu0ll_Vp, "Vp_BFu0ll_Vp", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s()
{
  {
    init_simple_test("Vp_BFu0s");
    static Vp_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vVp_BFu0s(Test_Vp_BFu0s, "Vp_BFu0s", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu0c()
{
  {
    init_simple_test("Vp_BFu0s_BFu0c");
    static Vp_BFu0s_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0s_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu0c(Test_Vp_BFu0s_BFu0c, "Vp_BFu0s_BFu0c", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu0i()
{
  {
    init_simple_test("Vp_BFu0s_BFu0i");
    static Vp_BFu0s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu0i(Test_Vp_BFu0s_BFu0i, "Vp_BFu0s_BFu0i", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu0ll()
{
  {
    init_simple_test("Vp_BFu0s_BFu0ll");
    static Vp_BFu0s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu0ll(Test_Vp_BFu0s_BFu0ll, "Vp_BFu0s_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu0s()
{
  {
    init_simple_test("Vp_BFu0s_BFu0s");
    static Vp_BFu0s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu0s(Test_Vp_BFu0s_BFu0s, "Vp_BFu0s_BFu0s", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu15i()
{
  {
    init_simple_test("Vp_BFu0s_BFu15i");
    static Vp_BFu0s_BFu15i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_BFu15i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0s_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0s_BFu15i");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu15i(Test_Vp_BFu0s_BFu15i, "Vp_BFu0s_BFu15i", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu15ll()
{
  {
    init_simple_test("Vp_BFu0s_BFu15ll");
    static Vp_BFu0s_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0s_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0s_BFu15ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu15ll(Test_Vp_BFu0s_BFu15ll, "Vp_BFu0s_BFu15ll", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu15s()
{
  {
    init_simple_test("Vp_BFu0s_BFu15s");
    static Vp_BFu0s_BFu15s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_BFu15s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0s_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0s_BFu15s");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu15s(Test_Vp_BFu0s_BFu15s, "Vp_BFu0s_BFu15s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu16i()
{
  {
    init_simple_test("Vp_BFu0s_BFu16i");
    static Vp_BFu0s_BFu16i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_BFu16i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0s_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0s_BFu16i");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu16i(Test_Vp_BFu0s_BFu16i, "Vp_BFu0s_BFu16i", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu16ll()
{
  {
    init_simple_test("Vp_BFu0s_BFu16ll");
    static Vp_BFu0s_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0s_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0s_BFu16ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu16ll(Test_Vp_BFu0s_BFu16ll, "Vp_BFu0s_BFu16ll", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu16s()
{
  {
    init_simple_test("Vp_BFu0s_BFu16s");
    static Vp_BFu0s_BFu16s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_BFu16s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0s_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0s_BFu16s");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu16s(Test_Vp_BFu0s_BFu16s, "Vp_BFu0s_BFu16s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu17i()
{
  {
    init_simple_test("Vp_BFu0s_BFu17i");
    static Vp_BFu0s_BFu17i lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu0s_BFu17i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu0s_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu0s_BFu17i");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu17i(Test_Vp_BFu0s_BFu17i, "Vp_BFu0s_BFu17i", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu17ll()
{
  {
    init_simple_test("Vp_BFu0s_BFu17ll");
    static Vp_BFu0s_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu0s_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu0s_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu0s_BFu17ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu17ll(Test_Vp_BFu0s_BFu17ll, "Vp_BFu0s_BFu17ll", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu1c()
{
  {
    init_simple_test("Vp_BFu0s_BFu1c");
    static Vp_BFu0s_BFu1c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0s_BFu1c");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu1c(Test_Vp_BFu0s_BFu1c, "Vp_BFu0s_BFu1c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu1i()
{
  {
    init_simple_test("Vp_BFu0s_BFu1i");
    static Vp_BFu0s_BFu1i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu1i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0s_BFu1i");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu1i(Test_Vp_BFu0s_BFu1i, "Vp_BFu0s_BFu1i", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu1ll()
{
  {
    init_simple_test("Vp_BFu0s_BFu1ll");
    static Vp_BFu0s_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0s_BFu1ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu1ll(Test_Vp_BFu0s_BFu1ll, "Vp_BFu0s_BFu1ll", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu1s()
{
  {
    init_simple_test("Vp_BFu0s_BFu1s");
    static Vp_BFu0s_BFu1s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu1s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0s_BFu1s");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu1s(Test_Vp_BFu0s_BFu1s, "Vp_BFu0s_BFu1s", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu31i()
{
  {
    init_simple_test("Vp_BFu0s_BFu31i");
    static Vp_BFu0s_BFu31i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0s_BFu31i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu0s_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu0s_BFu31i");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu31i(Test_Vp_BFu0s_BFu31i, "Vp_BFu0s_BFu31i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu31ll()
{
  {
    init_simple_test("Vp_BFu0s_BFu31ll");
    static Vp_BFu0s_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0s_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu0s_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu0s_BFu31ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu31ll(Test_Vp_BFu0s_BFu31ll, "Vp_BFu0s_BFu31ll", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu32i()
{
  {
    init_simple_test("Vp_BFu0s_BFu32i");
    static Vp_BFu0s_BFu32i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0s_BFu32i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu0s_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu0s_BFu32i");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu32i(Test_Vp_BFu0s_BFu32i, "Vp_BFu0s_BFu32i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu32ll()
{
  {
    init_simple_test("Vp_BFu0s_BFu32ll");
    static Vp_BFu0s_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0s_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu0s_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu0s_BFu32ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu32ll(Test_Vp_BFu0s_BFu32ll, "Vp_BFu0s_BFu32ll", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu33()
{
  {
    init_simple_test("Vp_BFu0s_BFu33");
    static Vp_BFu0s_BFu33 lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_BFu0s_BFu33)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu0s_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu0s_BFu33");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu33(Test_Vp_BFu0s_BFu33, "Vp_BFu0s_BFu33", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu7c()
{
  {
    init_simple_test("Vp_BFu0s_BFu7c");
    static Vp_BFu0s_BFu7c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0s_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0s_BFu7c");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu7c(Test_Vp_BFu0s_BFu7c, "Vp_BFu0s_BFu7c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu7i()
{
  {
    init_simple_test("Vp_BFu0s_BFu7i");
    static Vp_BFu0s_BFu7i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu7i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0s_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0s_BFu7i");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu7i(Test_Vp_BFu0s_BFu7i, "Vp_BFu0s_BFu7i", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu7ll()
{
  {
    init_simple_test("Vp_BFu0s_BFu7ll");
    static Vp_BFu0s_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0s_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0s_BFu7ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu7ll(Test_Vp_BFu0s_BFu7ll, "Vp_BFu0s_BFu7ll", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu7s()
{
  {
    init_simple_test("Vp_BFu0s_BFu7s");
    static Vp_BFu0s_BFu7s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu7s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0s_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0s_BFu7s");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu7s(Test_Vp_BFu0s_BFu7s, "Vp_BFu0s_BFu7s", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu8c()
{
  {
    init_simple_test("Vp_BFu0s_BFu8c");
    static Vp_BFu0s_BFu8c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0s_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0s_BFu8c");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu8c(Test_Vp_BFu0s_BFu8c, "Vp_BFu0s_BFu8c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu8i()
{
  {
    init_simple_test("Vp_BFu0s_BFu8i");
    static Vp_BFu0s_BFu8i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu8i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0s_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0s_BFu8i");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu8i(Test_Vp_BFu0s_BFu8i, "Vp_BFu0s_BFu8i", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu8ll()
{
  {
    init_simple_test("Vp_BFu0s_BFu8ll");
    static Vp_BFu0s_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0s_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0s_BFu8ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu8ll(Test_Vp_BFu0s_BFu8ll, "Vp_BFu0s_BFu8ll", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu8s()
{
  {
    init_simple_test("Vp_BFu0s_BFu8s");
    static Vp_BFu0s_BFu8s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu8s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0s_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0s_BFu8s");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu8s(Test_Vp_BFu0s_BFu8s, "Vp_BFu0s_BFu8s", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu9i()
{
  {
    init_simple_test("Vp_BFu0s_BFu9i");
    static Vp_BFu0s_BFu9i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_BFu9i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0s_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0s_BFu9i");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu9i(Test_Vp_BFu0s_BFu9i, "Vp_BFu0s_BFu9i", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu9ll()
{
  {
    init_simple_test("Vp_BFu0s_BFu9ll");
    static Vp_BFu0s_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0s_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0s_BFu9ll");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu9ll(Test_Vp_BFu0s_BFu9ll, "Vp_BFu0s_BFu9ll", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_BFu9s()
{
  {
    init_simple_test("Vp_BFu0s_BFu9s");
    static Vp_BFu0s_BFu9s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_BFu9s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0s_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0s_BFu9s");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_BFu9s(Test_Vp_BFu0s_BFu9s, "Vp_BFu0s_BFu9s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_C()
{
  {
    init_simple_test("Vp_BFu0s_C");
    static Vp_BFu0s_C lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_C)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_C.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_C(Test_Vp_BFu0s_C, "Vp_BFu0s_C", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_D()
{
  {
    init_simple_test("Vp_BFu0s_D");
    static Vp_BFu0s_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0s_D)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_D)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_D.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_D(Test_Vp_BFu0s_D, "Vp_BFu0s_D", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_F()
{
  {
    init_simple_test("Vp_BFu0s_F");
    static Vp_BFu0s_F lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0s_F)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_F)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_F.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_F(Test_Vp_BFu0s_F, "Vp_BFu0s_F", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_I()
{
  {
    init_simple_test("Vp_BFu0s_I");
    static Vp_BFu0s_I lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0s_I)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_I)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_I.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_I(Test_Vp_BFu0s_I, "Vp_BFu0s_I", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_Ip()
{
  {
    init_simple_test("Vp_BFu0s_Ip");
    static Vp_BFu0s_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu0s_Ip)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_Ip)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_Ip.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_Ip(Test_Vp_BFu0s_Ip, "Vp_BFu0s_Ip", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_L()
{
  {
    init_simple_test("Vp_BFu0s_L");
    static Vp_BFu0s_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0s_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_L)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_L.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_L(Test_Vp_BFu0s_L, "Vp_BFu0s_L", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_S()
{
  {
    init_simple_test("Vp_BFu0s_S");
    static Vp_BFu0s_S lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_S)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_S.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_S(Test_Vp_BFu0s_S, "Vp_BFu0s_S", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_Uc()
{
  {
    init_simple_test("Vp_BFu0s_Uc");
    static Vp_BFu0s_Uc lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_Uc)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_Uc.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_Uc(Test_Vp_BFu0s_Uc, "Vp_BFu0s_Uc", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_Ui()
{
  {
    init_simple_test("Vp_BFu0s_Ui");
    static Vp_BFu0s_Ui lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0s_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_Ui)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_Ui.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_Ui(Test_Vp_BFu0s_Ui, "Vp_BFu0s_Ui", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_Ul()
{
  {
    init_simple_test("Vp_BFu0s_Ul");
    static Vp_BFu0s_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0s_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_Ul)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_Ul.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_Ul(Test_Vp_BFu0s_Ul, "Vp_BFu0s_Ul", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_Us()
{
  {
    init_simple_test("Vp_BFu0s_Us");
    static Vp_BFu0s_Us lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_Us)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_Us.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_Us(Test_Vp_BFu0s_Us, "Vp_BFu0s_Us", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu0s_Vp()
{
  {
    init_simple_test("Vp_BFu0s_Vp");
    static Vp_BFu0s_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu0s_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_Vp)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_Vp.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_Vp(Test_Vp_BFu0s_Vp, "Vp_BFu0s_Vp", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu15i_BFu0c()
{
  {
    init_simple_test("Vp_BFu15i_BFu0c");
    static Vp_BFu15i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu15i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu15i_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu15i_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15i_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15i_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu15i_BFu0c(Test_Vp_BFu15i_BFu0c, "Vp_BFu15i_BFu0c", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu15i_BFu0i()
{
  {
    init_simple_test("Vp_BFu15i_BFu0i");
    static Vp_BFu15i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu15i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu15i_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu15i_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15i_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15i_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu15i_BFu0i(Test_Vp_BFu15i_BFu0i, "Vp_BFu15i_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu15i_BFu0ll()
{
  {
    init_simple_test("Vp_BFu15i_BFu0ll");
    static Vp_BFu15i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu15i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu15i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu15i_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15i_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15i_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu15i_BFu0ll(Test_Vp_BFu15i_BFu0ll, "Vp_BFu15i_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu15i_BFu0s()
{
  {
    init_simple_test("Vp_BFu15i_BFu0s");
    static Vp_BFu15i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu15i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu15i_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu15i_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15i_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15i_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu15i_BFu0s(Test_Vp_BFu15i_BFu0s, "Vp_BFu15i_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu15ll_BFu0c()
{
  {
    init_simple_test("Vp_BFu15ll_BFu0c");
    static Vp_BFu15ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu15ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu15ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu15ll_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15ll_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15ll_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu15ll_BFu0c(Test_Vp_BFu15ll_BFu0c, "Vp_BFu15ll_BFu0c", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu15ll_BFu0i()
{
  {
    init_simple_test("Vp_BFu15ll_BFu0i");
    static Vp_BFu15ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu15ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu15ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu15ll_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15ll_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15ll_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu15ll_BFu0i(Test_Vp_BFu15ll_BFu0i, "Vp_BFu15ll_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu15ll_BFu0ll()
{
  {
    init_simple_test("Vp_BFu15ll_BFu0ll");
    static Vp_BFu15ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu15ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu15ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu15ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15ll_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu15ll_BFu0ll(Test_Vp_BFu15ll_BFu0ll, "Vp_BFu15ll_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu15ll_BFu0s()
{
  {
    init_simple_test("Vp_BFu15ll_BFu0s");
    static Vp_BFu15ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu15ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu15ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu15ll_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15ll_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15ll_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu15ll_BFu0s(Test_Vp_BFu15ll_BFu0s, "Vp_BFu15ll_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu15s_BFu0c()
{
  {
    init_simple_test("Vp_BFu15s_BFu0c");
    static Vp_BFu15s_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu15s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu15s_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu15s_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15s_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15s_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu15s_BFu0c(Test_Vp_BFu15s_BFu0c, "Vp_BFu15s_BFu0c", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu15s_BFu0i()
{
  {
    init_simple_test("Vp_BFu15s_BFu0i");
    static Vp_BFu15s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu15s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu15s_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu15s_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15s_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15s_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu15s_BFu0i(Test_Vp_BFu15s_BFu0i, "Vp_BFu15s_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu15s_BFu0ll()
{
  {
    init_simple_test("Vp_BFu15s_BFu0ll");
    static Vp_BFu15s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu15s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu15s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu15s_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15s_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15s_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu15s_BFu0ll(Test_Vp_BFu15s_BFu0ll, "Vp_BFu15s_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu15s_BFu0s()
{
  {
    init_simple_test("Vp_BFu15s_BFu0s");
    static Vp_BFu15s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu15s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu15s_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu15s_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15s_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15s_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu15s_BFu0s(Test_Vp_BFu15s_BFu0s, "Vp_BFu15s_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu16i_BFu0c()
{
  {
    init_simple_test("Vp_BFu16i_BFu0c");
    static Vp_BFu16i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu16i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu16i_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu16i_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16i_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16i_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu16i_BFu0c(Test_Vp_BFu16i_BFu0c, "Vp_BFu16i_BFu0c", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu16i_BFu0i()
{
  {
    init_simple_test("Vp_BFu16i_BFu0i");
    static Vp_BFu16i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu16i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu16i_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu16i_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16i_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16i_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu16i_BFu0i(Test_Vp_BFu16i_BFu0i, "Vp_BFu16i_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu16i_BFu0ll()
{
  {
    init_simple_test("Vp_BFu16i_BFu0ll");
    static Vp_BFu16i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu16i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu16i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu16i_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16i_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16i_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu16i_BFu0ll(Test_Vp_BFu16i_BFu0ll, "Vp_BFu16i_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu16i_BFu0s()
{
  {
    init_simple_test("Vp_BFu16i_BFu0s");
    static Vp_BFu16i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu16i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu16i_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu16i_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16i_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16i_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu16i_BFu0s(Test_Vp_BFu16i_BFu0s, "Vp_BFu16i_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu16ll_BFu0c()
{
  {
    init_simple_test("Vp_BFu16ll_BFu0c");
    static Vp_BFu16ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu16ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu16ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu16ll_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16ll_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16ll_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu16ll_BFu0c(Test_Vp_BFu16ll_BFu0c, "Vp_BFu16ll_BFu0c", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu16ll_BFu0i()
{
  {
    init_simple_test("Vp_BFu16ll_BFu0i");
    static Vp_BFu16ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu16ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu16ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu16ll_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16ll_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16ll_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu16ll_BFu0i(Test_Vp_BFu16ll_BFu0i, "Vp_BFu16ll_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu16ll_BFu0ll()
{
  {
    init_simple_test("Vp_BFu16ll_BFu0ll");
    static Vp_BFu16ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu16ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu16ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu16ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16ll_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu16ll_BFu0ll(Test_Vp_BFu16ll_BFu0ll, "Vp_BFu16ll_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu16ll_BFu0s()
{
  {
    init_simple_test("Vp_BFu16ll_BFu0s");
    static Vp_BFu16ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu16ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu16ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu16ll_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16ll_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16ll_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu16ll_BFu0s(Test_Vp_BFu16ll_BFu0s, "Vp_BFu16ll_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu16s_BFu0c()
{
  {
    init_simple_test("Vp_BFu16s_BFu0c");
    static Vp_BFu16s_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu16s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu16s_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu16s_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16s_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16s_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu16s_BFu0c(Test_Vp_BFu16s_BFu0c, "Vp_BFu16s_BFu0c", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu16s_BFu0i()
{
  {
    init_simple_test("Vp_BFu16s_BFu0i");
    static Vp_BFu16s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu16s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu16s_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu16s_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16s_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16s_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu16s_BFu0i(Test_Vp_BFu16s_BFu0i, "Vp_BFu16s_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu16s_BFu0ll()
{
  {
    init_simple_test("Vp_BFu16s_BFu0ll");
    static Vp_BFu16s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu16s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu16s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu16s_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16s_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16s_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu16s_BFu0ll(Test_Vp_BFu16s_BFu0ll, "Vp_BFu16s_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu16s_BFu0s()
{
  {
    init_simple_test("Vp_BFu16s_BFu0s");
    static Vp_BFu16s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu16s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu16s_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu16s_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16s_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16s_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu16s_BFu0s(Test_Vp_BFu16s_BFu0s, "Vp_BFu16s_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu17i_BFu0c()
{
  {
    init_simple_test("Vp_BFu17i_BFu0c");
    static Vp_BFu17i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu17i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu17i_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu17i_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu17i_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu17i_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu17i_BFu0c(Test_Vp_BFu17i_BFu0c, "Vp_BFu17i_BFu0c", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu17i_BFu0i()
{
  {
    init_simple_test("Vp_BFu17i_BFu0i");
    static Vp_BFu17i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu17i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu17i_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu17i_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu17i_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu17i_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu17i_BFu0i(Test_Vp_BFu17i_BFu0i, "Vp_BFu17i_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu17i_BFu0ll()
{
  {
    init_simple_test("Vp_BFu17i_BFu0ll");
    static Vp_BFu17i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu17i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu17i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu17i_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu17i_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu17i_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu17i_BFu0ll(Test_Vp_BFu17i_BFu0ll, "Vp_BFu17i_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu17i_BFu0s()
{
  {
    init_simple_test("Vp_BFu17i_BFu0s");
    static Vp_BFu17i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu17i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu17i_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu17i_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu17i_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu17i_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu17i_BFu0s(Test_Vp_BFu17i_BFu0s, "Vp_BFu17i_BFu0s", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu17ll_BFu0c()
{
  {
    init_simple_test("Vp_BFu17ll_BFu0c");
    static Vp_BFu17ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu17ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu17ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu17ll_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu17ll_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu17ll_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu17ll_BFu0c(Test_Vp_BFu17ll_BFu0c, "Vp_BFu17ll_BFu0c", ABISELECT(11,7));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu17ll_BFu0i()
{
  {
    init_simple_test("Vp_BFu17ll_BFu0i");
    static Vp_BFu17ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu17ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu17ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu17ll_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu17ll_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu17ll_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu17ll_BFu0i(Test_Vp_BFu17ll_BFu0i, "Vp_BFu17ll_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu17ll_BFu0ll()
{
  {
    init_simple_test("Vp_BFu17ll_BFu0ll");
    static Vp_BFu17ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu17ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu17ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu17ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu17ll_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu17ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu17ll_BFu0ll(Test_Vp_BFu17ll_BFu0ll, "Vp_BFu17ll_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu17ll_BFu0s()
{
  {
    init_simple_test("Vp_BFu17ll_BFu0s");
    static Vp_BFu17ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu17ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu17ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu17ll_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu17ll_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu17ll_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu17ll_BFu0s(Test_Vp_BFu17ll_BFu0s, "Vp_BFu17ll_BFu0s", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu1c_BFu0c()
{
  {
    init_simple_test("Vp_BFu1c_BFu0c");
    static Vp_BFu1c_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu1c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu1c_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu1c_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1c_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu1c_BFu0c(Test_Vp_BFu1c_BFu0c, "Vp_BFu1c_BFu0c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu1c_BFu0i()
{
  {
    init_simple_test("Vp_BFu1c_BFu0i");
    static Vp_BFu1c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu1c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1c_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu1c_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1c_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu1c_BFu0i(Test_Vp_BFu1c_BFu0i, "Vp_BFu1c_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu1c_BFu0ll()
{
  {
    init_simple_test("Vp_BFu1c_BFu0ll");
    static Vp_BFu1c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu1c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu1c_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1c_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu1c_BFu0ll(Test_Vp_BFu1c_BFu0ll, "Vp_BFu1c_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu1c_BFu0s()
{
  {
    init_simple_test("Vp_BFu1c_BFu0s");
    static Vp_BFu1c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu1c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1c_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu1c_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1c_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu1c_BFu0s(Test_Vp_BFu1c_BFu0s, "Vp_BFu1c_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu1i_BFu0c()
{
  {
    init_simple_test("Vp_BFu1i_BFu0c");
    static Vp_BFu1i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu1i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu1i_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu1i_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1i_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu1i_BFu0c(Test_Vp_BFu1i_BFu0c, "Vp_BFu1i_BFu0c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu1i_BFu0i()
{
  {
    init_simple_test("Vp_BFu1i_BFu0i");
    static Vp_BFu1i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu1i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1i_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu1i_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1i_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu1i_BFu0i(Test_Vp_BFu1i_BFu0i, "Vp_BFu1i_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu1i_BFu0ll()
{
  {
    init_simple_test("Vp_BFu1i_BFu0ll");
    static Vp_BFu1i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu1i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu1i_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1i_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu1i_BFu0ll(Test_Vp_BFu1i_BFu0ll, "Vp_BFu1i_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu1i_BFu0s()
{
  {
    init_simple_test("Vp_BFu1i_BFu0s");
    static Vp_BFu1i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu1i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1i_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu1i_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1i_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu1i_BFu0s(Test_Vp_BFu1i_BFu0s, "Vp_BFu1i_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu1ll_BFu0c()
{
  {
    init_simple_test("Vp_BFu1ll_BFu0c");
    static Vp_BFu1ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu1ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu1ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu1ll_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1ll_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu1ll_BFu0c(Test_Vp_BFu1ll_BFu0c, "Vp_BFu1ll_BFu0c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu1ll_BFu0i()
{
  {
    init_simple_test("Vp_BFu1ll_BFu0i");
    static Vp_BFu1ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu1ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu1ll_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1ll_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu1ll_BFu0i(Test_Vp_BFu1ll_BFu0i, "Vp_BFu1ll_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu1ll_BFu0ll()
{
  {
    init_simple_test("Vp_BFu1ll_BFu0ll");
    static Vp_BFu1ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu1ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu1ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu1ll_BFu0ll(Test_Vp_BFu1ll_BFu0ll, "Vp_BFu1ll_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu1ll_BFu0s()
{
  {
    init_simple_test("Vp_BFu1ll_BFu0s");
    static Vp_BFu1ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu1ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu1ll_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1ll_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu1ll_BFu0s(Test_Vp_BFu1ll_BFu0s, "Vp_BFu1ll_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu1s_BFu0c()
{
  {
    init_simple_test("Vp_BFu1s_BFu0c");
    static Vp_BFu1s_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu1s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu1s_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu1s_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1s_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu1s_BFu0c(Test_Vp_BFu1s_BFu0c, "Vp_BFu1s_BFu0c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu1s_BFu0i()
{
  {
    init_simple_test("Vp_BFu1s_BFu0i");
    static Vp_BFu1s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu1s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1s_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu1s_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1s_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu1s_BFu0i(Test_Vp_BFu1s_BFu0i, "Vp_BFu1s_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu1s_BFu0ll()
{
  {
    init_simple_test("Vp_BFu1s_BFu0ll");
    static Vp_BFu1s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu1s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu1s_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1s_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu1s_BFu0ll(Test_Vp_BFu1s_BFu0ll, "Vp_BFu1s_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu1s_BFu0s()
{
  {
    init_simple_test("Vp_BFu1s_BFu0s");
    static Vp_BFu1s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu1s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1s_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu1s_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1s_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu1s_BFu0s(Test_Vp_BFu1s_BFu0s, "Vp_BFu1s_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu31i_BFu0c()
{
  {
    init_simple_test("Vp_BFu31i_BFu0c");
    static Vp_BFu31i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu31i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu31i_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu31i_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu31i_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu31i_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu31i_BFu0c(Test_Vp_BFu31i_BFu0c, "Vp_BFu31i_BFu0c", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu31i_BFu0i()
{
  {
    init_simple_test("Vp_BFu31i_BFu0i");
    static Vp_BFu31i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu31i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu31i_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu31i_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu31i_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu31i_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu31i_BFu0i(Test_Vp_BFu31i_BFu0i, "Vp_BFu31i_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu31i_BFu0ll()
{
  {
    init_simple_test("Vp_BFu31i_BFu0ll");
    static Vp_BFu31i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu31i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu31i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu31i_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu31i_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu31i_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu31i_BFu0ll(Test_Vp_BFu31i_BFu0ll, "Vp_BFu31i_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu31i_BFu0s()
{
  {
    init_simple_test("Vp_BFu31i_BFu0s");
    static Vp_BFu31i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu31i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu31i_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu31i_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu31i_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu31i_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu31i_BFu0s(Test_Vp_BFu31i_BFu0s, "Vp_BFu31i_BFu0s", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu31ll_BFu0c()
{
  {
    init_simple_test("Vp_BFu31ll_BFu0c");
    static Vp_BFu31ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu31ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu31ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu31ll_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu31ll_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu31ll_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu31ll_BFu0c(Test_Vp_BFu31ll_BFu0c, "Vp_BFu31ll_BFu0c", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu31ll_BFu0i()
{
  {
    init_simple_test("Vp_BFu31ll_BFu0i");
    static Vp_BFu31ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu31ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu31ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu31ll_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu31ll_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu31ll_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu31ll_BFu0i(Test_Vp_BFu31ll_BFu0i, "Vp_BFu31ll_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu31ll_BFu0ll()
{
  {
    init_simple_test("Vp_BFu31ll_BFu0ll");
    static Vp_BFu31ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu31ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu31ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu31ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu31ll_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu31ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu31ll_BFu0ll(Test_Vp_BFu31ll_BFu0ll, "Vp_BFu31ll_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu31ll_BFu0s()
{
  {
    init_simple_test("Vp_BFu31ll_BFu0s");
    static Vp_BFu31ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu31ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu31ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu31ll_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu31ll_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu31ll_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu31ll_BFu0s(Test_Vp_BFu31ll_BFu0s, "Vp_BFu31ll_BFu0s", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu32i_BFu0c()
{
  {
    init_simple_test("Vp_BFu32i_BFu0c");
    static Vp_BFu32i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu32i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu32i_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu32i_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32i_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32i_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu32i_BFu0c(Test_Vp_BFu32i_BFu0c, "Vp_BFu32i_BFu0c", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu32i_BFu0i()
{
  {
    init_simple_test("Vp_BFu32i_BFu0i");
    static Vp_BFu32i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu32i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu32i_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu32i_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32i_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32i_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu32i_BFu0i(Test_Vp_BFu32i_BFu0i, "Vp_BFu32i_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu32i_BFu0ll()
{
  {
    init_simple_test("Vp_BFu32i_BFu0ll");
    static Vp_BFu32i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu32i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu32i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu32i_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32i_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32i_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu32i_BFu0ll(Test_Vp_BFu32i_BFu0ll, "Vp_BFu32i_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu32i_BFu0s()
{
  {
    init_simple_test("Vp_BFu32i_BFu0s");
    static Vp_BFu32i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu32i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu32i_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu32i_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32i_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32i_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu32i_BFu0s(Test_Vp_BFu32i_BFu0s, "Vp_BFu32i_BFu0s", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu32ll_BFu0c()
{
  {
    init_simple_test("Vp_BFu32ll_BFu0c");
    static Vp_BFu32ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu32ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu32ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu32ll_BFu0c(Test_Vp_BFu32ll_BFu0c, "Vp_BFu32ll_BFu0c", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu32ll_BFu0i()
{
  {
    init_simple_test("Vp_BFu32ll_BFu0i");
    static Vp_BFu32ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu32ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu32ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu32ll_BFu0i(Test_Vp_BFu32ll_BFu0i, "Vp_BFu32ll_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu32ll_BFu0ll()
{
  {
    init_simple_test("Vp_BFu32ll_BFu0ll");
    static Vp_BFu32ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu32ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu32ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu32ll_BFu0ll(Test_Vp_BFu32ll_BFu0ll, "Vp_BFu32ll_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu32ll_BFu0s()
{
  {
    init_simple_test("Vp_BFu32ll_BFu0s");
    static Vp_BFu32ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu32ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu32ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu32ll_BFu0s(Test_Vp_BFu32ll_BFu0s, "Vp_BFu32ll_BFu0s", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu33_BFu0c()
{
  {
    init_simple_test("Vp_BFu33_BFu0c");
    static Vp_BFu33_BFu0c lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_BFu33_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu33_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu33_BFu0c(Test_Vp_BFu33_BFu0c, "Vp_BFu33_BFu0c", ABISELECT(13,9));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu33_BFu0i()
{
  {
    init_simple_test("Vp_BFu33_BFu0i");
    static Vp_BFu33_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu33_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu33_BFu0i(Test_Vp_BFu33_BFu0i, "Vp_BFu33_BFu0i", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu33_BFu0ll()
{
  {
    init_simple_test("Vp_BFu33_BFu0ll");
    static Vp_BFu33_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu33_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu33_BFu0ll(Test_Vp_BFu33_BFu0ll, "Vp_BFu33_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu33_BFu0s()
{
  {
    init_simple_test("Vp_BFu33_BFu0s");
    static Vp_BFu33_BFu0s lv;
    check2(sizeof(lv), ABISELECT(14,10), "sizeof(Vp_BFu33_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu33_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu33_BFu0s(Test_Vp_BFu33_BFu0s, "Vp_BFu33_BFu0s", ABISELECT(14,10));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu7c_BFu0c()
{
  {
    init_simple_test("Vp_BFu7c_BFu0c");
    static Vp_BFu7c_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu7c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu7c_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu7c_BFu0c(Test_Vp_BFu7c_BFu0c, "Vp_BFu7c_BFu0c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu7c_BFu0i()
{
  {
    init_simple_test("Vp_BFu7c_BFu0i");
    static Vp_BFu7c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu7c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7c_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu7c_BFu0i(Test_Vp_BFu7c_BFu0i, "Vp_BFu7c_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu7c_BFu0ll()
{
  {
    init_simple_test("Vp_BFu7c_BFu0ll");
    static Vp_BFu7c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu7c_BFu0ll(Test_Vp_BFu7c_BFu0ll, "Vp_BFu7c_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu7c_BFu0s()
{
  {
    init_simple_test("Vp_BFu7c_BFu0s");
    static Vp_BFu7c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu7c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7c_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu7c_BFu0s(Test_Vp_BFu7c_BFu0s, "Vp_BFu7c_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu7i_BFu0c()
{
  {
    init_simple_test("Vp_BFu7i_BFu0c");
    static Vp_BFu7i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu7i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu7i_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu7i_BFu0c(Test_Vp_BFu7i_BFu0c, "Vp_BFu7i_BFu0c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu7i_BFu0i()
{
  {
    init_simple_test("Vp_BFu7i_BFu0i");
    static Vp_BFu7i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu7i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7i_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu7i_BFu0i(Test_Vp_BFu7i_BFu0i, "Vp_BFu7i_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu7i_BFu0ll()
{
  {
    init_simple_test("Vp_BFu7i_BFu0ll");
    static Vp_BFu7i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu7i_BFu0ll(Test_Vp_BFu7i_BFu0ll, "Vp_BFu7i_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu7i_BFu0s()
{
  {
    init_simple_test("Vp_BFu7i_BFu0s");
    static Vp_BFu7i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu7i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7i_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu7i_BFu0s(Test_Vp_BFu7i_BFu0s, "Vp_BFu7i_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu7ll_BFu0c()
{
  {
    init_simple_test("Vp_BFu7ll_BFu0c");
    static Vp_BFu7ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu7ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu7ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu7ll_BFu0c(Test_Vp_BFu7ll_BFu0c, "Vp_BFu7ll_BFu0c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu7ll_BFu0i()
{
  {
    init_simple_test("Vp_BFu7ll_BFu0i");
    static Vp_BFu7ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu7ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu7ll_BFu0i(Test_Vp_BFu7ll_BFu0i, "Vp_BFu7ll_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu7ll_BFu0ll()
{
  {
    init_simple_test("Vp_BFu7ll_BFu0ll");
    static Vp_BFu7ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu7ll_BFu0ll(Test_Vp_BFu7ll_BFu0ll, "Vp_BFu7ll_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu7ll_BFu0s()
{
  {
    init_simple_test("Vp_BFu7ll_BFu0s");
    static Vp_BFu7ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu7ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu7ll_BFu0s(Test_Vp_BFu7ll_BFu0s, "Vp_BFu7ll_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu7s_BFu0c()
{
  {
    init_simple_test("Vp_BFu7s_BFu0c");
    static Vp_BFu7s_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu7s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu7s_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu7s_BFu0c(Test_Vp_BFu7s_BFu0c, "Vp_BFu7s_BFu0c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu7s_BFu0i()
{
  {
    init_simple_test("Vp_BFu7s_BFu0i");
    static Vp_BFu7s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu7s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7s_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu7s_BFu0i(Test_Vp_BFu7s_BFu0i, "Vp_BFu7s_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu7s_BFu0ll()
{
  {
    init_simple_test("Vp_BFu7s_BFu0ll");
    static Vp_BFu7s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu7s_BFu0ll(Test_Vp_BFu7s_BFu0ll, "Vp_BFu7s_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu7s_BFu0s()
{
  {
    init_simple_test("Vp_BFu7s_BFu0s");
    static Vp_BFu7s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu7s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7s_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu7s_BFu0s(Test_Vp_BFu7s_BFu0s, "Vp_BFu7s_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu8c_BFu0c()
{
  {
    init_simple_test("Vp_BFu8c_BFu0c");
    static Vp_BFu8c_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu8c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu8c_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu8c_BFu0c(Test_Vp_BFu8c_BFu0c, "Vp_BFu8c_BFu0c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu8c_BFu0i()
{
  {
    init_simple_test("Vp_BFu8c_BFu0i");
    static Vp_BFu8c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu8c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8c_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu8c_BFu0i(Test_Vp_BFu8c_BFu0i, "Vp_BFu8c_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu8c_BFu0ll()
{
  {
    init_simple_test("Vp_BFu8c_BFu0ll");
    static Vp_BFu8c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu8c_BFu0ll(Test_Vp_BFu8c_BFu0ll, "Vp_BFu8c_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu8c_BFu0s()
{
  {
    init_simple_test("Vp_BFu8c_BFu0s");
    static Vp_BFu8c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu8c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8c_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu8c_BFu0s(Test_Vp_BFu8c_BFu0s, "Vp_BFu8c_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu8i_BFu0c()
{
  {
    init_simple_test("Vp_BFu8i_BFu0c");
    static Vp_BFu8i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu8i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu8i_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu8i_BFu0c(Test_Vp_BFu8i_BFu0c, "Vp_BFu8i_BFu0c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu8i_BFu0i()
{
  {
    init_simple_test("Vp_BFu8i_BFu0i");
    static Vp_BFu8i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu8i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8i_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu8i_BFu0i(Test_Vp_BFu8i_BFu0i, "Vp_BFu8i_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu8i_BFu0ll()
{
  {
    init_simple_test("Vp_BFu8i_BFu0ll");
    static Vp_BFu8i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu8i_BFu0ll(Test_Vp_BFu8i_BFu0ll, "Vp_BFu8i_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu8i_BFu0s()
{
  {
    init_simple_test("Vp_BFu8i_BFu0s");
    static Vp_BFu8i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu8i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8i_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu8i_BFu0s(Test_Vp_BFu8i_BFu0s, "Vp_BFu8i_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu8ll_BFu0c()
{
  {
    init_simple_test("Vp_BFu8ll_BFu0c");
    static Vp_BFu8ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu8ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu8ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu8ll_BFu0c(Test_Vp_BFu8ll_BFu0c, "Vp_BFu8ll_BFu0c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu8ll_BFu0i()
{
  {
    init_simple_test("Vp_BFu8ll_BFu0i");
    static Vp_BFu8ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu8ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu8ll_BFu0i(Test_Vp_BFu8ll_BFu0i, "Vp_BFu8ll_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu8ll_BFu0ll()
{
  {
    init_simple_test("Vp_BFu8ll_BFu0ll");
    static Vp_BFu8ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu8ll_BFu0ll(Test_Vp_BFu8ll_BFu0ll, "Vp_BFu8ll_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu8ll_BFu0s()
{
  {
    init_simple_test("Vp_BFu8ll_BFu0s");
    static Vp_BFu8ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu8ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu8ll_BFu0s(Test_Vp_BFu8ll_BFu0s, "Vp_BFu8ll_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu8s_BFu0c()
{
  {
    init_simple_test("Vp_BFu8s_BFu0c");
    static Vp_BFu8s_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu8s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu8s_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu8s_BFu0c(Test_Vp_BFu8s_BFu0c, "Vp_BFu8s_BFu0c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu8s_BFu0i()
{
  {
    init_simple_test("Vp_BFu8s_BFu0i");
    static Vp_BFu8s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu8s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8s_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu8s_BFu0i(Test_Vp_BFu8s_BFu0i, "Vp_BFu8s_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu8s_BFu0ll()
{
  {
    init_simple_test("Vp_BFu8s_BFu0ll");
    static Vp_BFu8s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu8s_BFu0ll(Test_Vp_BFu8s_BFu0ll, "Vp_BFu8s_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu8s_BFu0s()
{
  {
    init_simple_test("Vp_BFu8s_BFu0s");
    static Vp_BFu8s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu8s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8s_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu8s_BFu0s(Test_Vp_BFu8s_BFu0s, "Vp_BFu8s_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu9i_BFu0c()
{
  {
    init_simple_test("Vp_BFu9i_BFu0c");
    static Vp_BFu9i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu9i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu9i_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu9i_BFu0c(Test_Vp_BFu9i_BFu0c, "Vp_BFu9i_BFu0c", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu9i_BFu0i()
{
  {
    init_simple_test("Vp_BFu9i_BFu0i");
    static Vp_BFu9i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu9i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu9i_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu9i_BFu0i(Test_Vp_BFu9i_BFu0i, "Vp_BFu9i_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu9i_BFu0ll()
{
  {
    init_simple_test("Vp_BFu9i_BFu0ll");
    static Vp_BFu9i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu9i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu9i_BFu0ll(Test_Vp_BFu9i_BFu0ll, "Vp_BFu9i_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu9i_BFu0s()
{
  {
    init_simple_test("Vp_BFu9i_BFu0s");
    static Vp_BFu9i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu9i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu9i_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu9i_BFu0s(Test_Vp_BFu9i_BFu0s, "Vp_BFu9i_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu9ll_BFu0c()
{
  {
    init_simple_test("Vp_BFu9ll_BFu0c");
    static Vp_BFu9ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu9ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu9ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu9ll_BFu0c(Test_Vp_BFu9ll_BFu0c, "Vp_BFu9ll_BFu0c", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu9ll_BFu0i()
{
  {
    init_simple_test("Vp_BFu9ll_BFu0i");
    static Vp_BFu9ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu9ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu9ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu9ll_BFu0i(Test_Vp_BFu9ll_BFu0i, "Vp_BFu9ll_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu9ll_BFu0ll()
{
  {
    init_simple_test("Vp_BFu9ll_BFu0ll");
    static Vp_BFu9ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu9ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu9ll_BFu0ll(Test_Vp_BFu9ll_BFu0ll, "Vp_BFu9ll_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu9ll_BFu0s()
{
  {
    init_simple_test("Vp_BFu9ll_BFu0s");
    static Vp_BFu9ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu9ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu9ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu9ll_BFu0s(Test_Vp_BFu9ll_BFu0s, "Vp_BFu9ll_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu9s_BFu0c()
{
  {
    init_simple_test("Vp_BFu9s_BFu0c");
    static Vp_BFu9s_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu9s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu9s_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu0c");
  }
}
static Arrange_To_Call_Me vVp_BFu9s_BFu0c(Test_Vp_BFu9s_BFu0c, "Vp_BFu9s_BFu0c", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu9s_BFu0i()
{
  {
    init_simple_test("Vp_BFu9s_BFu0i");
    static Vp_BFu9s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu9s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu9s_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu0i");
  }
}
static Arrange_To_Call_Me vVp_BFu9s_BFu0i(Test_Vp_BFu9s_BFu0i, "Vp_BFu9s_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu9s_BFu0ll()
{
  {
    init_simple_test("Vp_BFu9s_BFu0ll");
    static Vp_BFu9s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu9s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu0ll");
  }
}
static Arrange_To_Call_Me vVp_BFu9s_BFu0ll(Test_Vp_BFu9s_BFu0ll, "Vp_BFu9s_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_BFu9s_BFu0s()
{
  {
    init_simple_test("Vp_BFu9s_BFu0s");
    static Vp_BFu9s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu9s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu9s_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu0s");
  }
}
static Arrange_To_Call_Me vVp_BFu9s_BFu0s(Test_Vp_BFu9s_BFu0s, "Vp_BFu9s_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_C_BFu0c()
{
  {
    init_simple_test("Vp_C_BFu0c");
    static Vp_C_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_C_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_C_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vVp_C_BFu0c(Test_Vp_C_BFu0c, "Vp_C_BFu0c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_C_BFu0i()
{
  {
    init_simple_test("Vp_C_BFu0i");
    static Vp_C_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_C_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_C_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vVp_C_BFu0i(Test_Vp_C_BFu0i, "Vp_C_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_C_BFu0ll()
{
  {
    init_simple_test("Vp_C_BFu0ll");
    static Vp_C_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_C_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vVp_C_BFu0ll(Test_Vp_C_BFu0ll, "Vp_C_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_C_BFu0s()
{
  {
    init_simple_test("Vp_C_BFu0s");
    static Vp_C_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_C_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_C_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vVp_C_BFu0s(Test_Vp_C_BFu0s, "Vp_C_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_D_BFu0c()
{
  {
    init_simple_test("Vp_D_BFu0c");
    static Vp_D_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_D_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_D_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vVp_D_BFu0c(Test_Vp_D_BFu0c, "Vp_D_BFu0c", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_D_BFu0i()
{
  {
    init_simple_test("Vp_D_BFu0i");
    static Vp_D_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_D_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_D_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vVp_D_BFu0i(Test_Vp_D_BFu0i, "Vp_D_BFu0i", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_D_BFu0ll()
{
  {
    init_simple_test("Vp_D_BFu0ll");
    static Vp_D_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_D_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_D_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vVp_D_BFu0ll(Test_Vp_D_BFu0ll, "Vp_D_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_D_BFu0s()
{
  {
    init_simple_test("Vp_D_BFu0s");
    static Vp_D_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_D_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_D_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vVp_D_BFu0s(Test_Vp_D_BFu0s, "Vp_D_BFu0s", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_F_BFu0c()
{
  {
    init_simple_test("Vp_F_BFu0c");
    static Vp_F_BFu0c lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_F_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_F_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vVp_F_BFu0c(Test_Vp_F_BFu0c, "Vp_F_BFu0c", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_F_BFu0i()
{
  {
    init_simple_test("Vp_F_BFu0i");
    static Vp_F_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_F_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_F_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vVp_F_BFu0i(Test_Vp_F_BFu0i, "Vp_F_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_F_BFu0ll()
{
  {
    init_simple_test("Vp_F_BFu0ll");
    static Vp_F_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_F_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_F_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vVp_F_BFu0ll(Test_Vp_F_BFu0ll, "Vp_F_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_F_BFu0s()
{
  {
    init_simple_test("Vp_F_BFu0s");
    static Vp_F_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_F_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_F_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vVp_F_BFu0s(Test_Vp_F_BFu0s, "Vp_F_BFu0s", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_I_BFu0c()
{
  {
    init_simple_test("Vp_I_BFu0c");
    static Vp_I_BFu0c lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_I_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_I_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vVp_I_BFu0c(Test_Vp_I_BFu0c, "Vp_I_BFu0c", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_I_BFu0i()
{
  {
    init_simple_test("Vp_I_BFu0i");
    static Vp_I_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_I_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_I_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vVp_I_BFu0i(Test_Vp_I_BFu0i, "Vp_I_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_I_BFu0ll()
{
  {
    init_simple_test("Vp_I_BFu0ll");
    static Vp_I_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_I_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_I_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vVp_I_BFu0ll(Test_Vp_I_BFu0ll, "Vp_I_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_I_BFu0s()
{
  {
    init_simple_test("Vp_I_BFu0s");
    static Vp_I_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_I_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_I_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vVp_I_BFu0s(Test_Vp_I_BFu0s, "Vp_I_BFu0s", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Ip_BFu0c()
{
  {
    init_simple_test("Vp_Ip_BFu0c");
    static Vp_Ip_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Ip_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Ip_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vVp_Ip_BFu0c(Test_Vp_Ip_BFu0c, "Vp_Ip_BFu0c", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Ip_BFu0i()
{
  {
    init_simple_test("Vp_Ip_BFu0i");
    static Vp_Ip_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Ip_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Ip_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vVp_Ip_BFu0i(Test_Vp_Ip_BFu0i, "Vp_Ip_BFu0i", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Ip_BFu0ll()
{
  {
    init_simple_test("Vp_Ip_BFu0ll");
    static Vp_Ip_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Ip_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Ip_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vVp_Ip_BFu0ll(Test_Vp_Ip_BFu0ll, "Vp_Ip_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Ip_BFu0s()
{
  {
    init_simple_test("Vp_Ip_BFu0s");
    static Vp_Ip_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Ip_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Ip_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vVp_Ip_BFu0s(Test_Vp_Ip_BFu0s, "Vp_Ip_BFu0s", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_L_BFu0c()
{
  {
    init_simple_test("Vp_L_BFu0c");
    static Vp_L_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_L_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_L_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vVp_L_BFu0c(Test_Vp_L_BFu0c, "Vp_L_BFu0c", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_L_BFu0i()
{
  {
    init_simple_test("Vp_L_BFu0i");
    static Vp_L_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_L_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_L_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vVp_L_BFu0i(Test_Vp_L_BFu0i, "Vp_L_BFu0i", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_L_BFu0ll()
{
  {
    init_simple_test("Vp_L_BFu0ll");
    static Vp_L_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_L_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_L_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vVp_L_BFu0ll(Test_Vp_L_BFu0ll, "Vp_L_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_L_BFu0s()
{
  {
    init_simple_test("Vp_L_BFu0s");
    static Vp_L_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_L_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_L_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vVp_L_BFu0s(Test_Vp_L_BFu0s, "Vp_L_BFu0s", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_S_BFu0c()
{
  {
    init_simple_test("Vp_S_BFu0c");
    static Vp_S_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_S_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_S_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vVp_S_BFu0c(Test_Vp_S_BFu0c, "Vp_S_BFu0c", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_S_BFu0i()
{
  {
    init_simple_test("Vp_S_BFu0i");
    static Vp_S_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_S_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_S_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vVp_S_BFu0i(Test_Vp_S_BFu0i, "Vp_S_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_S_BFu0ll()
{
  {
    init_simple_test("Vp_S_BFu0ll");
    static Vp_S_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_S_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vVp_S_BFu0ll(Test_Vp_S_BFu0ll, "Vp_S_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_S_BFu0s()
{
  {
    init_simple_test("Vp_S_BFu0s");
    static Vp_S_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_S_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_S_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vVp_S_BFu0s(Test_Vp_S_BFu0s, "Vp_S_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Uc_BFu0c()
{
  {
    init_simple_test("Vp_Uc_BFu0c");
    static Vp_Uc_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_Uc_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Uc_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vVp_Uc_BFu0c(Test_Vp_Uc_BFu0c, "Vp_Uc_BFu0c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Uc_BFu0i()
{
  {
    init_simple_test("Vp_Uc_BFu0i");
    static Vp_Uc_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_Uc_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Uc_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vVp_Uc_BFu0i(Test_Vp_Uc_BFu0i, "Vp_Uc_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Uc_BFu0ll()
{
  {
    init_simple_test("Vp_Uc_BFu0ll");
    static Vp_Uc_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Uc_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vVp_Uc_BFu0ll(Test_Vp_Uc_BFu0ll, "Vp_Uc_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Uc_BFu0s()
{
  {
    init_simple_test("Vp_Uc_BFu0s");
    static Vp_Uc_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_Uc_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Uc_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vVp_Uc_BFu0s(Test_Vp_Uc_BFu0s, "Vp_Uc_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Ui_BFu0c()
{
  {
    init_simple_test("Vp_Ui_BFu0c");
    static Vp_Ui_BFu0c lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_Ui_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Ui_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vVp_Ui_BFu0c(Test_Vp_Ui_BFu0c, "Vp_Ui_BFu0c", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Ui_BFu0i()
{
  {
    init_simple_test("Vp_Ui_BFu0i");
    static Vp_Ui_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_Ui_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Ui_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vVp_Ui_BFu0i(Test_Vp_Ui_BFu0i, "Vp_Ui_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Ui_BFu0ll()
{
  {
    init_simple_test("Vp_Ui_BFu0ll");
    static Vp_Ui_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Ui_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Ui_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vVp_Ui_BFu0ll(Test_Vp_Ui_BFu0ll, "Vp_Ui_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Ui_BFu0s()
{
  {
    init_simple_test("Vp_Ui_BFu0s");
    static Vp_Ui_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_Ui_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Ui_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vVp_Ui_BFu0s(Test_Vp_Ui_BFu0s, "Vp_Ui_BFu0s", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Ul_BFu0c()
{
  {
    init_simple_test("Vp_Ul_BFu0c");
    static Vp_Ul_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ul_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Ul_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vVp_Ul_BFu0c(Test_Vp_Ul_BFu0c, "Vp_Ul_BFu0c", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Ul_BFu0i()
{
  {
    init_simple_test("Vp_Ul_BFu0i");
    static Vp_Ul_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ul_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Ul_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vVp_Ul_BFu0i(Test_Vp_Ul_BFu0i, "Vp_Ul_BFu0i", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Ul_BFu0ll()
{
  {
    init_simple_test("Vp_Ul_BFu0ll");
    static Vp_Ul_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ul_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Ul_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vVp_Ul_BFu0ll(Test_Vp_Ul_BFu0ll, "Vp_Ul_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Ul_BFu0s()
{
  {
    init_simple_test("Vp_Ul_BFu0s");
    static Vp_Ul_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ul_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Ul_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vVp_Ul_BFu0s(Test_Vp_Ul_BFu0s, "Vp_Ul_BFu0s", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Us_BFu0c()
{
  {
    init_simple_test("Vp_Us_BFu0c");
    static Vp_Us_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_Us_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Us_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vVp_Us_BFu0c(Test_Vp_Us_BFu0c, "Vp_Us_BFu0c", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Us_BFu0i()
{
  {
    init_simple_test("Vp_Us_BFu0i");
    static Vp_Us_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_Us_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Us_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vVp_Us_BFu0i(Test_Vp_Us_BFu0i, "Vp_Us_BFu0i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Us_BFu0ll()
{
  {
    init_simple_test("Vp_Us_BFu0ll");
    static Vp_Us_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Us_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vVp_Us_BFu0ll(Test_Vp_Us_BFu0ll, "Vp_Us_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Us_BFu0s()
{
  {
    init_simple_test("Vp_Us_BFu0s");
    static Vp_Us_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_Us_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Us_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vVp_Us_BFu0s(Test_Vp_Us_BFu0s, "Vp_Us_BFu0s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Vp_BFu0c()
{
  {
    init_simple_test("Vp_Vp_BFu0c");
    static Vp_Vp_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Vp_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Vp_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vVp_Vp_BFu0c(Test_Vp_Vp_BFu0c, "Vp_Vp_BFu0c", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Vp_BFu0i()
{
  {
    init_simple_test("Vp_Vp_BFu0i");
    static Vp_Vp_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Vp_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Vp_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vVp_Vp_BFu0i(Test_Vp_Vp_BFu0i, "Vp_Vp_BFu0i", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Vp_BFu0ll()
{
  {
    init_simple_test("Vp_Vp_BFu0ll");
    static Vp_Vp_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Vp_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Vp_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vVp_Vp_BFu0ll(Test_Vp_Vp_BFu0ll, "Vp_Vp_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus


static void Test_Vp_Vp_BFu0s()
{
  {
    init_simple_test("Vp_Vp_BFu0s");
    static Vp_Vp_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Vp_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Vp_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vVp_Vp_BFu0s(Test_Vp_Vp_BFu0s, "Vp_Vp_BFu0s", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

