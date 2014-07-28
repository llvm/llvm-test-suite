// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
// RUN: c_compiler -c -o %t1.o -I "common" "common/testsuite.c"
// RUN: c_compiler -c %s -I "common" -o %t2.o
// RUN: linker -o %t1%exeext  %t1.o %t2.o
// RUN: runtool %t1%exeext | checker "TEST PASSED"
#include "testsuite.h"
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


static void Test_Ui_BFu0ll_L()
{
  {
    init_simple_test("Ui_BFu0ll_L");
    static STRUCT_IF_C Ui_BFu0ll_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ui_BFu0ll_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0ll_L)");
    check_field_offset(lv, v1, 0, "Ui_BFu0ll_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ui_BFu0ll_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0ll_L, Ui_BFu0ll_L)
//============================================================================



static void Test_Ui_BFu0ll_S()
{
  {
    init_simple_test("Ui_BFu0ll_S");
    static STRUCT_IF_C Ui_BFu0ll_S lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ui_BFu0ll_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0ll_S)");
    check_field_offset(lv, v1, 0, "Ui_BFu0ll_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ui_BFu0ll_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0ll_S, Ui_BFu0ll_S)
//============================================================================



static void Test_Ui_BFu0ll_Uc()
{
  {
    init_simple_test("Ui_BFu0ll_Uc");
    static STRUCT_IF_C Ui_BFu0ll_Uc lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Ui_BFu0ll_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0ll_Uc)");
    check_field_offset(lv, v1, 0, "Ui_BFu0ll_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ui_BFu0ll_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0ll_Uc, Ui_BFu0ll_Uc)
//============================================================================



static void Test_Ui_BFu0ll_Ui()
{
  {
    init_simple_test("Ui_BFu0ll_Ui");
    static STRUCT_IF_C Ui_BFu0ll_Ui lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_BFu0ll_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0ll_Ui)");
    check_field_offset(lv, v1, 0, "Ui_BFu0ll_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ui_BFu0ll_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0ll_Ui, Ui_BFu0ll_Ui)
//============================================================================



static void Test_Ui_BFu0ll_Ul()
{
  {
    init_simple_test("Ui_BFu0ll_Ul");
    static STRUCT_IF_C Ui_BFu0ll_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ui_BFu0ll_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0ll_Ul)");
    check_field_offset(lv, v1, 0, "Ui_BFu0ll_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ui_BFu0ll_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0ll_Ul, Ui_BFu0ll_Ul)
//============================================================================



static void Test_Ui_BFu0ll_Us()
{
  {
    init_simple_test("Ui_BFu0ll_Us");
    static STRUCT_IF_C Ui_BFu0ll_Us lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Ui_BFu0ll_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0ll_Us)");
    check_field_offset(lv, v1, 0, "Ui_BFu0ll_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ui_BFu0ll_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0ll_Us, Ui_BFu0ll_Us)
//============================================================================



static void Test_Ui_BFu0ll_Vp()
{
  {
    init_simple_test("Ui_BFu0ll_Vp");
    static STRUCT_IF_C Ui_BFu0ll_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Ui_BFu0ll_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0ll_Vp)");
    check_field_offset(lv, v1, 0, "Ui_BFu0ll_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ui_BFu0ll_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0ll_Vp, Ui_BFu0ll_Vp)
//============================================================================



static void Test_Ui_BFu0s()
{
  {
    init_simple_test("Ui_BFu0s");
    static STRUCT_IF_C Ui_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Ui_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s, Ui_BFu0s)
//============================================================================



static void Test_Ui_BFu0s_BFu0c()
{
  {
    init_simple_test("Ui_BFu0s_BFu0c");
    static STRUCT_IF_C Ui_BFu0s_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Ui_BFu0s_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu0c, Ui_BFu0s_BFu0c)
//============================================================================



static void Test_Ui_BFu0s_BFu0i()
{
  {
    init_simple_test("Ui_BFu0s_BFu0i");
    static STRUCT_IF_C Ui_BFu0s_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Ui_BFu0s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu0i, Ui_BFu0s_BFu0i)
//============================================================================



static void Test_Ui_BFu0s_BFu0ll()
{
  {
    init_simple_test("Ui_BFu0s_BFu0ll");
    static STRUCT_IF_C Ui_BFu0s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Ui_BFu0s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu0ll, Ui_BFu0s_BFu0ll)
//============================================================================



static void Test_Ui_BFu0s_BFu0s()
{
  {
    init_simple_test("Ui_BFu0s_BFu0s");
    static STRUCT_IF_C Ui_BFu0s_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Ui_BFu0s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu0s, Ui_BFu0s_BFu0s)
//============================================================================



static void Test_Ui_BFu0s_BFu15i()
{
  {
    init_simple_test("Ui_BFu0s_BFu15i");
    static STRUCT_IF_C Ui_BFu0s_BFu15i lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_BFu15i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu15i)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu15i.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu0s_BFu15i");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu0s_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu15i, Ui_BFu0s_BFu15i)
//============================================================================



static void Test_Ui_BFu0s_BFu15ll()
{
  {
    init_simple_test("Ui_BFu0s_BFu15ll");
    static STRUCT_IF_C Ui_BFu0s_BFu15ll lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu15ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu15ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu0s_BFu15ll");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu0s_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu15ll, Ui_BFu0s_BFu15ll)
//============================================================================



static void Test_Ui_BFu0s_BFu15s()
{
  {
    init_simple_test("Ui_BFu0s_BFu15s");
    static STRUCT_IF_C Ui_BFu0s_BFu15s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_BFu15s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu15s)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu15s.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu0s_BFu15s");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu0s_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu15s, Ui_BFu0s_BFu15s)
//============================================================================



static void Test_Ui_BFu0s_BFu16i()
{
  {
    init_simple_test("Ui_BFu0s_BFu16i");
    static STRUCT_IF_C Ui_BFu0s_BFu16i lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_BFu16i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu16i)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu16i.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu0s_BFu16i");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu0s_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu16i, Ui_BFu0s_BFu16i)
//============================================================================



static void Test_Ui_BFu0s_BFu16ll()
{
  {
    init_simple_test("Ui_BFu0s_BFu16ll");
    static STRUCT_IF_C Ui_BFu0s_BFu16ll lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu16ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu16ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu0s_BFu16ll");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu0s_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu16ll, Ui_BFu0s_BFu16ll)
//============================================================================



static void Test_Ui_BFu0s_BFu16s()
{
  {
    init_simple_test("Ui_BFu0s_BFu16s");
    static STRUCT_IF_C Ui_BFu0s_BFu16s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_BFu16s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu16s)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu16s.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu0s_BFu16s");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu0s_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu16s, Ui_BFu0s_BFu16s)
//============================================================================



static void Test_Ui_BFu0s_BFu17i()
{
  {
    init_simple_test("Ui_BFu0s_BFu17i");
    static STRUCT_IF_C Ui_BFu0s_BFu17i lv;
    check2(sizeof(lv), ABISELECT(7,7), "sizeof(Ui_BFu0s_BFu17i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu17i)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu17i.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu0s_BFu17i");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu0s_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu17i, Ui_BFu0s_BFu17i)
//============================================================================



static void Test_Ui_BFu0s_BFu17ll()
{
  {
    init_simple_test("Ui_BFu0s_BFu17ll");
    static STRUCT_IF_C Ui_BFu0s_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(7,7), "sizeof(Ui_BFu0s_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu17ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu17ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu0s_BFu17ll");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu0s_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu17ll, Ui_BFu0s_BFu17ll)
//============================================================================



static void Test_Ui_BFu0s_BFu1c()
{
  {
    init_simple_test("Ui_BFu0s_BFu1c");
    static STRUCT_IF_C Ui_BFu0s_BFu1c lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu1c)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu1c.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu0s_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu1c, Ui_BFu0s_BFu1c)
//============================================================================



static void Test_Ui_BFu0s_BFu1i()
{
  {
    init_simple_test("Ui_BFu0s_BFu1i");
    static STRUCT_IF_C Ui_BFu0s_BFu1i lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu1i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu1i)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu1i.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu0s_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu1i, Ui_BFu0s_BFu1i)
//============================================================================



static void Test_Ui_BFu0s_BFu1ll()
{
  {
    init_simple_test("Ui_BFu0s_BFu1ll");
    static STRUCT_IF_C Ui_BFu0s_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu1ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu1ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu0s_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu1ll, Ui_BFu0s_BFu1ll)
//============================================================================



static void Test_Ui_BFu0s_BFu1s()
{
  {
    init_simple_test("Ui_BFu0s_BFu1s");
    static STRUCT_IF_C Ui_BFu0s_BFu1s lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu1s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu1s)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu1s.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu0s_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu1s, Ui_BFu0s_BFu1s)
//============================================================================



static void Test_Ui_BFu0s_BFu31i()
{
  {
    init_simple_test("Ui_BFu0s_BFu31i");
    static STRUCT_IF_C Ui_BFu0s_BFu31i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu0s_BFu31i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu31i)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu31i.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu0s_BFu31i");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu0s_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu31i, Ui_BFu0s_BFu31i)
//============================================================================



static void Test_Ui_BFu0s_BFu31ll()
{
  {
    init_simple_test("Ui_BFu0s_BFu31ll");
    static STRUCT_IF_C Ui_BFu0s_BFu31ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu0s_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu31ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu31ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu0s_BFu31ll");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu0s_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu31ll, Ui_BFu0s_BFu31ll)
//============================================================================



static void Test_Ui_BFu0s_BFu32i()
{
  {
    init_simple_test("Ui_BFu0s_BFu32i");
    static STRUCT_IF_C Ui_BFu0s_BFu32i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu0s_BFu32i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu32i)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu32i.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu0s_BFu32i");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu0s_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu32i, Ui_BFu0s_BFu32i)
//============================================================================



static void Test_Ui_BFu0s_BFu32ll()
{
  {
    init_simple_test("Ui_BFu0s_BFu32ll");
    static STRUCT_IF_C Ui_BFu0s_BFu32ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu0s_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu32ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu32ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu0s_BFu32ll");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu0s_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu32ll, Ui_BFu0s_BFu32ll)
//============================================================================



static void Test_Ui_BFu0s_BFu33()
{
  {
    init_simple_test("Ui_BFu0s_BFu33");
    static STRUCT_IF_C Ui_BFu0s_BFu33 lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ui_BFu0s_BFu33)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu33)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu33.v1");
    set_bf_and_test(lv, v2, 4, 0, 33, 1, "Ui_BFu0s_BFu33");
    set_bf_and_test(lv, v2, 4, 0, 33, hide_ull(1LL<<32), "Ui_BFu0s_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu33, Ui_BFu0s_BFu33)
//============================================================================



static void Test_Ui_BFu0s_BFu7c()
{
  {
    init_simple_test("Ui_BFu0s_BFu7c");
    static STRUCT_IF_C Ui_BFu0s_BFu7c lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu7c)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu7c.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu0s_BFu7c");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu0s_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu7c, Ui_BFu0s_BFu7c)
//============================================================================



static void Test_Ui_BFu0s_BFu7i()
{
  {
    init_simple_test("Ui_BFu0s_BFu7i");
    static STRUCT_IF_C Ui_BFu0s_BFu7i lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu7i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu7i)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu7i.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu0s_BFu7i");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu0s_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu7i, Ui_BFu0s_BFu7i)
//============================================================================



static void Test_Ui_BFu0s_BFu7ll()
{
  {
    init_simple_test("Ui_BFu0s_BFu7ll");
    static STRUCT_IF_C Ui_BFu0s_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu7ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu7ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu0s_BFu7ll");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu0s_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu7ll, Ui_BFu0s_BFu7ll)
//============================================================================



static void Test_Ui_BFu0s_BFu7s()
{
  {
    init_simple_test("Ui_BFu0s_BFu7s");
    static STRUCT_IF_C Ui_BFu0s_BFu7s lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu7s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu7s)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu7s.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu0s_BFu7s");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu0s_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu7s, Ui_BFu0s_BFu7s)
//============================================================================



static void Test_Ui_BFu0s_BFu8c()
{
  {
    init_simple_test("Ui_BFu0s_BFu8c");
    static STRUCT_IF_C Ui_BFu0s_BFu8c lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu8c)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu8c.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu0s_BFu8c");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu0s_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu8c, Ui_BFu0s_BFu8c)
//============================================================================



static void Test_Ui_BFu0s_BFu8i()
{
  {
    init_simple_test("Ui_BFu0s_BFu8i");
    static STRUCT_IF_C Ui_BFu0s_BFu8i lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu8i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu8i)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu8i.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu0s_BFu8i");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu0s_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu8i, Ui_BFu0s_BFu8i)
//============================================================================



static void Test_Ui_BFu0s_BFu8ll()
{
  {
    init_simple_test("Ui_BFu0s_BFu8ll");
    static STRUCT_IF_C Ui_BFu0s_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu8ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu8ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu0s_BFu8ll");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu0s_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu8ll, Ui_BFu0s_BFu8ll)
//============================================================================



static void Test_Ui_BFu0s_BFu8s()
{
  {
    init_simple_test("Ui_BFu0s_BFu8s");
    static STRUCT_IF_C Ui_BFu0s_BFu8s lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_BFu8s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu8s)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu8s.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu0s_BFu8s");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu0s_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu8s, Ui_BFu0s_BFu8s)
//============================================================================



static void Test_Ui_BFu0s_BFu9i()
{
  {
    init_simple_test("Ui_BFu0s_BFu9i");
    static STRUCT_IF_C Ui_BFu0s_BFu9i lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_BFu9i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu9i)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu9i.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu0s_BFu9i");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu0s_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu9i, Ui_BFu0s_BFu9i)
//============================================================================



static void Test_Ui_BFu0s_BFu9ll()
{
  {
    init_simple_test("Ui_BFu0s_BFu9ll");
    static STRUCT_IF_C Ui_BFu0s_BFu9ll lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu9ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu9ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu0s_BFu9ll");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu0s_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu9ll, Ui_BFu0s_BFu9ll)
//============================================================================



static void Test_Ui_BFu0s_BFu9s()
{
  {
    init_simple_test("Ui_BFu0s_BFu9s");
    static STRUCT_IF_C Ui_BFu0s_BFu9s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_BFu9s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_BFu9s)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_BFu9s.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu0s_BFu9s");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu0s_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_BFu9s, Ui_BFu0s_BFu9s)
//============================================================================



static void Test_Ui_BFu0s_C()
{
  {
    init_simple_test("Ui_BFu0s_C");
    static STRUCT_IF_C Ui_BFu0s_C lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_C)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_C.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_C, Ui_BFu0s_C)
//============================================================================



static void Test_Ui_BFu0s_D()
{
  {
    init_simple_test("Ui_BFu0s_D");
    static STRUCT_IF_C Ui_BFu0s_D lv;
    check2(sizeof(lv), 12, "sizeof(Ui_BFu0s_D)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_D)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_D.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_D, Ui_BFu0s_D)
//============================================================================



static void Test_Ui_BFu0s_F()
{
  {
    init_simple_test("Ui_BFu0s_F");
    static STRUCT_IF_C Ui_BFu0s_F lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu0s_F)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_F)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_F.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_F, Ui_BFu0s_F)
//============================================================================



static void Test_Ui_BFu0s_I()
{
  {
    init_simple_test("Ui_BFu0s_I");
    static STRUCT_IF_C Ui_BFu0s_I lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu0s_I)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_I)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_I.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_I, Ui_BFu0s_I)
//============================================================================



static void Test_Ui_BFu0s_Ip()
{
  {
    init_simple_test("Ui_BFu0s_Ip");
    static STRUCT_IF_C Ui_BFu0s_Ip lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_BFu0s_Ip)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_Ip)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_Ip.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_Ip, Ui_BFu0s_Ip)
//============================================================================



static void Test_Ui_BFu0s_L()
{
  {
    init_simple_test("Ui_BFu0s_L");
    static STRUCT_IF_C Ui_BFu0s_L lv;
    check2(sizeof(lv), 12, "sizeof(Ui_BFu0s_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_L)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_L.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_L, Ui_BFu0s_L)
//============================================================================



static void Test_Ui_BFu0s_S()
{
  {
    init_simple_test("Ui_BFu0s_S");
    static STRUCT_IF_C Ui_BFu0s_S lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_S)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_S.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_S, Ui_BFu0s_S)
//============================================================================



static void Test_Ui_BFu0s_Uc()
{
  {
    init_simple_test("Ui_BFu0s_Uc");
    static STRUCT_IF_C Ui_BFu0s_Uc lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Ui_BFu0s_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_Uc)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_Uc.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_Uc, Ui_BFu0s_Uc)
//============================================================================



static void Test_Ui_BFu0s_Ui()
{
  {
    init_simple_test("Ui_BFu0s_Ui");
    static STRUCT_IF_C Ui_BFu0s_Ui lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu0s_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_Ui)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_Ui.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_Ui, Ui_BFu0s_Ui)
//============================================================================



static void Test_Ui_BFu0s_Ul()
{
  {
    init_simple_test("Ui_BFu0s_Ul");
    static STRUCT_IF_C Ui_BFu0s_Ul lv;
    check2(sizeof(lv), 12, "sizeof(Ui_BFu0s_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_Ul)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_Ul.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_Ul, Ui_BFu0s_Ul)
//============================================================================



static void Test_Ui_BFu0s_Us()
{
  {
    init_simple_test("Ui_BFu0s_Us");
    static STRUCT_IF_C Ui_BFu0s_Us lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu0s_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_Us)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_Us.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_Us, Ui_BFu0s_Us)
//============================================================================



static void Test_Ui_BFu0s_Vp()
{
  {
    init_simple_test("Ui_BFu0s_Vp");
    static STRUCT_IF_C Ui_BFu0s_Vp lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_BFu0s_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu0s_Vp)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_Vp.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_Vp, Ui_BFu0s_Vp)
//============================================================================



static void Test_Ui_BFu15i_BFu0c()
{
  {
    init_simple_test("Ui_BFu15i_BFu0c");
    static STRUCT_IF_C Ui_BFu15i_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu15i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu15i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu15i_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15i_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu15i_BFu0c, Ui_BFu15i_BFu0c)
//============================================================================



static void Test_Ui_BFu15i_BFu0i()
{
  {
    init_simple_test("Ui_BFu15i_BFu0i");
    static STRUCT_IF_C Ui_BFu15i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu15i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu15i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu15i_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15i_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu15i_BFu0i, Ui_BFu15i_BFu0i)
//============================================================================



static void Test_Ui_BFu15i_BFu0ll()
{
  {
    init_simple_test("Ui_BFu15i_BFu0ll");
    static STRUCT_IF_C Ui_BFu15i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu15i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu15i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu15i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15i_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu15i_BFu0ll, Ui_BFu15i_BFu0ll)
//============================================================================



static void Test_Ui_BFu15i_BFu0s()
{
  {
    init_simple_test("Ui_BFu15i_BFu0s");
    static STRUCT_IF_C Ui_BFu15i_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu15i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu15i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu15i_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15i_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu15i_BFu0s, Ui_BFu15i_BFu0s)
//============================================================================



static void Test_Ui_BFu15ll_BFu0c()
{
  {
    init_simple_test("Ui_BFu15ll_BFu0c");
    static STRUCT_IF_C Ui_BFu15ll_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu15ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu15ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu15ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15ll_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu15ll_BFu0c, Ui_BFu15ll_BFu0c)
//============================================================================



static void Test_Ui_BFu15ll_BFu0i()
{
  {
    init_simple_test("Ui_BFu15ll_BFu0i");
    static STRUCT_IF_C Ui_BFu15ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu15ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu15ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu15ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15ll_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu15ll_BFu0i, Ui_BFu15ll_BFu0i)
//============================================================================



static void Test_Ui_BFu15ll_BFu0ll()
{
  {
    init_simple_test("Ui_BFu15ll_BFu0ll");
    static STRUCT_IF_C Ui_BFu15ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu15ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu15ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu15ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15ll_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu15ll_BFu0ll, Ui_BFu15ll_BFu0ll)
//============================================================================



static void Test_Ui_BFu15ll_BFu0s()
{
  {
    init_simple_test("Ui_BFu15ll_BFu0s");
    static STRUCT_IF_C Ui_BFu15ll_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu15ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu15ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu15ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15ll_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu15ll_BFu0s, Ui_BFu15ll_BFu0s)
//============================================================================



static void Test_Ui_BFu15s_BFu0c()
{
  {
    init_simple_test("Ui_BFu15s_BFu0c");
    static STRUCT_IF_C Ui_BFu15s_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu15s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu15s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu15s_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15s_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu15s_BFu0c, Ui_BFu15s_BFu0c)
//============================================================================



static void Test_Ui_BFu15s_BFu0i()
{
  {
    init_simple_test("Ui_BFu15s_BFu0i");
    static STRUCT_IF_C Ui_BFu15s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu15s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu15s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu15s_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15s_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu15s_BFu0i, Ui_BFu15s_BFu0i)
//============================================================================



static void Test_Ui_BFu15s_BFu0ll()
{
  {
    init_simple_test("Ui_BFu15s_BFu0ll");
    static STRUCT_IF_C Ui_BFu15s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu15s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu15s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu15s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15s_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu15s_BFu0ll, Ui_BFu15s_BFu0ll)
//============================================================================



static void Test_Ui_BFu15s_BFu0s()
{
  {
    init_simple_test("Ui_BFu15s_BFu0s");
    static STRUCT_IF_C Ui_BFu15s_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu15s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu15s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu15s_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "Ui_BFu15s_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "Ui_BFu15s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu15s_BFu0s, Ui_BFu15s_BFu0s)
//============================================================================



static void Test_Ui_BFu16i_BFu0c()
{
  {
    init_simple_test("Ui_BFu16i_BFu0c");
    static STRUCT_IF_C Ui_BFu16i_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu16i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu16i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu16i_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16i_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu16i_BFu0c, Ui_BFu16i_BFu0c)
//============================================================================



static void Test_Ui_BFu16i_BFu0i()
{
  {
    init_simple_test("Ui_BFu16i_BFu0i");
    static STRUCT_IF_C Ui_BFu16i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu16i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu16i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu16i_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16i_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu16i_BFu0i, Ui_BFu16i_BFu0i)
//============================================================================



static void Test_Ui_BFu16i_BFu0ll()
{
  {
    init_simple_test("Ui_BFu16i_BFu0ll");
    static STRUCT_IF_C Ui_BFu16i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu16i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu16i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu16i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16i_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu16i_BFu0ll, Ui_BFu16i_BFu0ll)
//============================================================================



static void Test_Ui_BFu16i_BFu0s()
{
  {
    init_simple_test("Ui_BFu16i_BFu0s");
    static STRUCT_IF_C Ui_BFu16i_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu16i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu16i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu16i_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16i_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu16i_BFu0s, Ui_BFu16i_BFu0s)
//============================================================================



static void Test_Ui_BFu16ll_BFu0c()
{
  {
    init_simple_test("Ui_BFu16ll_BFu0c");
    static STRUCT_IF_C Ui_BFu16ll_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu16ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu16ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu16ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16ll_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu16ll_BFu0c, Ui_BFu16ll_BFu0c)
//============================================================================



static void Test_Ui_BFu16ll_BFu0i()
{
  {
    init_simple_test("Ui_BFu16ll_BFu0i");
    static STRUCT_IF_C Ui_BFu16ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu16ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu16ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu16ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16ll_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu16ll_BFu0i, Ui_BFu16ll_BFu0i)
//============================================================================



static void Test_Ui_BFu16ll_BFu0ll()
{
  {
    init_simple_test("Ui_BFu16ll_BFu0ll");
    static STRUCT_IF_C Ui_BFu16ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu16ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu16ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu16ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16ll_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu16ll_BFu0ll, Ui_BFu16ll_BFu0ll)
//============================================================================



static void Test_Ui_BFu16ll_BFu0s()
{
  {
    init_simple_test("Ui_BFu16ll_BFu0s");
    static STRUCT_IF_C Ui_BFu16ll_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu16ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu16ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu16ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16ll_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu16ll_BFu0s, Ui_BFu16ll_BFu0s)
//============================================================================



static void Test_Ui_BFu16s_BFu0c()
{
  {
    init_simple_test("Ui_BFu16s_BFu0c");
    static STRUCT_IF_C Ui_BFu16s_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu16s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu16s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu16s_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16s_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu16s_BFu0c, Ui_BFu16s_BFu0c)
//============================================================================



static void Test_Ui_BFu16s_BFu0i()
{
  {
    init_simple_test("Ui_BFu16s_BFu0i");
    static STRUCT_IF_C Ui_BFu16s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu16s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu16s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu16s_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16s_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu16s_BFu0i, Ui_BFu16s_BFu0i)
//============================================================================



static void Test_Ui_BFu16s_BFu0ll()
{
  {
    init_simple_test("Ui_BFu16s_BFu0ll");
    static STRUCT_IF_C Ui_BFu16s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu16s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu16s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu16s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16s_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu16s_BFu0ll, Ui_BFu16s_BFu0ll)
//============================================================================



static void Test_Ui_BFu16s_BFu0s()
{
  {
    init_simple_test("Ui_BFu16s_BFu0s");
    static STRUCT_IF_C Ui_BFu16s_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu16s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu16s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu16s_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "Ui_BFu16s_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "Ui_BFu16s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu16s_BFu0s, Ui_BFu16s_BFu0s)
//============================================================================



static void Test_Ui_BFu17i_BFu0c()
{
  {
    init_simple_test("Ui_BFu17i_BFu0c");
    static STRUCT_IF_C Ui_BFu17i_BFu0c lv;
    check2(sizeof(lv), 7, "sizeof(Ui_BFu17i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu17i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu17i_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu17i_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu17i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu17i_BFu0c, Ui_BFu17i_BFu0c)
//============================================================================



static void Test_Ui_BFu17i_BFu0i()
{
  {
    init_simple_test("Ui_BFu17i_BFu0i");
    static STRUCT_IF_C Ui_BFu17i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu17i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu17i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu17i_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu17i_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu17i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu17i_BFu0i, Ui_BFu17i_BFu0i)
//============================================================================



static void Test_Ui_BFu17i_BFu0ll()
{
  {
    init_simple_test("Ui_BFu17i_BFu0ll");
    static STRUCT_IF_C Ui_BFu17i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu17i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu17i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu17i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu17i_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu17i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu17i_BFu0ll, Ui_BFu17i_BFu0ll)
//============================================================================



static void Test_Ui_BFu17i_BFu0s()
{
  {
    init_simple_test("Ui_BFu17i_BFu0s");
    static STRUCT_IF_C Ui_BFu17i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu17i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu17i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu17i_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu17i_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu17i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu17i_BFu0s, Ui_BFu17i_BFu0s)
//============================================================================



static void Test_Ui_BFu17ll_BFu0c()
{
  {
    init_simple_test("Ui_BFu17ll_BFu0c");
    static STRUCT_IF_C Ui_BFu17ll_BFu0c lv;
    check2(sizeof(lv), 7, "sizeof(Ui_BFu17ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu17ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu17ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu17ll_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu17ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu17ll_BFu0c, Ui_BFu17ll_BFu0c)
//============================================================================



static void Test_Ui_BFu17ll_BFu0i()
{
  {
    init_simple_test("Ui_BFu17ll_BFu0i");
    static STRUCT_IF_C Ui_BFu17ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu17ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu17ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu17ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu17ll_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu17ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu17ll_BFu0i, Ui_BFu17ll_BFu0i)
//============================================================================



static void Test_Ui_BFu17ll_BFu0ll()
{
  {
    init_simple_test("Ui_BFu17ll_BFu0ll");
    static STRUCT_IF_C Ui_BFu17ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu17ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu17ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu17ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu17ll_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu17ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu17ll_BFu0ll, Ui_BFu17ll_BFu0ll)
//============================================================================



static void Test_Ui_BFu17ll_BFu0s()
{
  {
    init_simple_test("Ui_BFu17ll_BFu0s");
    static STRUCT_IF_C Ui_BFu17ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu17ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu17ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu17ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "Ui_BFu17ll_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "Ui_BFu17ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu17ll_BFu0s, Ui_BFu17ll_BFu0s)
//============================================================================



static void Test_Ui_BFu1c_BFu0c()
{
  {
    init_simple_test("Ui_BFu1c_BFu0c");
    static STRUCT_IF_C Ui_BFu1c_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu1c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu1c_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu1c_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1c_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu1c_BFu0c, Ui_BFu1c_BFu0c)
//============================================================================



static void Test_Ui_BFu1c_BFu0i()
{
  {
    init_simple_test("Ui_BFu1c_BFu0i");
    static STRUCT_IF_C Ui_BFu1c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu1c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1c_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu1c_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1c_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu1c_BFu0i, Ui_BFu1c_BFu0i)
//============================================================================



static void Test_Ui_BFu1c_BFu0ll()
{
  {
    init_simple_test("Ui_BFu1c_BFu0ll");
    static STRUCT_IF_C Ui_BFu1c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu1c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu1c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1c_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu1c_BFu0ll, Ui_BFu1c_BFu0ll)
//============================================================================



static void Test_Ui_BFu1c_BFu0s()
{
  {
    init_simple_test("Ui_BFu1c_BFu0s");
    static STRUCT_IF_C Ui_BFu1c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu1c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1c_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu1c_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1c_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu1c_BFu0s, Ui_BFu1c_BFu0s)
//============================================================================



static void Test_Ui_BFu1i_BFu0c()
{
  {
    init_simple_test("Ui_BFu1i_BFu0c");
    static STRUCT_IF_C Ui_BFu1i_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu1i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu1i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu1i_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu1i_BFu0c, Ui_BFu1i_BFu0c)
//============================================================================



static void Test_Ui_BFu1i_BFu0i()
{
  {
    init_simple_test("Ui_BFu1i_BFu0i");
    static STRUCT_IF_C Ui_BFu1i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu1i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu1i_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu1i_BFu0i, Ui_BFu1i_BFu0i)
//============================================================================



static void Test_Ui_BFu1i_BFu0ll()
{
  {
    init_simple_test("Ui_BFu1i_BFu0ll");
    static STRUCT_IF_C Ui_BFu1i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu1i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu1i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu1i_BFu0ll, Ui_BFu1i_BFu0ll)
//============================================================================



static void Test_Ui_BFu1i_BFu0s()
{
  {
    init_simple_test("Ui_BFu1i_BFu0s");
    static STRUCT_IF_C Ui_BFu1i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu1i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu1i_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu1i_BFu0s, Ui_BFu1i_BFu0s)
//============================================================================



static void Test_Ui_BFu1ll_BFu0c()
{
  {
    init_simple_test("Ui_BFu1ll_BFu0c");
    static STRUCT_IF_C Ui_BFu1ll_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu1ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu1ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu1ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu1ll_BFu0c, Ui_BFu1ll_BFu0c)
//============================================================================



static void Test_Ui_BFu1ll_BFu0i()
{
  {
    init_simple_test("Ui_BFu1ll_BFu0i");
    static STRUCT_IF_C Ui_BFu1ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu1ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu1ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu1ll_BFu0i, Ui_BFu1ll_BFu0i)
//============================================================================



static void Test_Ui_BFu1ll_BFu0ll()
{
  {
    init_simple_test("Ui_BFu1ll_BFu0ll");
    static STRUCT_IF_C Ui_BFu1ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu1ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu1ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu1ll_BFu0ll, Ui_BFu1ll_BFu0ll)
//============================================================================



static void Test_Ui_BFu1ll_BFu0s()
{
  {
    init_simple_test("Ui_BFu1ll_BFu0s");
    static STRUCT_IF_C Ui_BFu1ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu1ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu1ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu1ll_BFu0s, Ui_BFu1ll_BFu0s)
//============================================================================



static void Test_Ui_BFu1s_BFu0c()
{
  {
    init_simple_test("Ui_BFu1s_BFu0c");
    static STRUCT_IF_C Ui_BFu1s_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu1s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu1s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu1s_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu1s_BFu0c, Ui_BFu1s_BFu0c)
//============================================================================



static void Test_Ui_BFu1s_BFu0i()
{
  {
    init_simple_test("Ui_BFu1s_BFu0i");
    static STRUCT_IF_C Ui_BFu1s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu1s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu1s_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu1s_BFu0i, Ui_BFu1s_BFu0i)
//============================================================================



static void Test_Ui_BFu1s_BFu0ll()
{
  {
    init_simple_test("Ui_BFu1s_BFu0ll");
    static STRUCT_IF_C Ui_BFu1s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu1s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu1s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu1s_BFu0ll, Ui_BFu1s_BFu0ll)
//============================================================================



static void Test_Ui_BFu1s_BFu0s()
{
  {
    init_simple_test("Ui_BFu1s_BFu0s");
    static STRUCT_IF_C Ui_BFu1s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu1s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu1s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu1s_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "Ui_BFu1s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu1s_BFu0s, Ui_BFu1s_BFu0s)
//============================================================================



static void Test_Ui_BFu31i_BFu0c()
{
  {
    init_simple_test("Ui_BFu31i_BFu0c");
    static STRUCT_IF_C Ui_BFu31i_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu31i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu31i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu31i_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu31i_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu31i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu31i_BFu0c, Ui_BFu31i_BFu0c)
//============================================================================



static void Test_Ui_BFu31i_BFu0i()
{
  {
    init_simple_test("Ui_BFu31i_BFu0i");
    static STRUCT_IF_C Ui_BFu31i_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu31i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu31i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu31i_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu31i_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu31i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu31i_BFu0i, Ui_BFu31i_BFu0i)
//============================================================================



static void Test_Ui_BFu31i_BFu0ll()
{
  {
    init_simple_test("Ui_BFu31i_BFu0ll");
    static STRUCT_IF_C Ui_BFu31i_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu31i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu31i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu31i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu31i_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu31i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu31i_BFu0ll, Ui_BFu31i_BFu0ll)
//============================================================================



static void Test_Ui_BFu31i_BFu0s()
{
  {
    init_simple_test("Ui_BFu31i_BFu0s");
    static STRUCT_IF_C Ui_BFu31i_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu31i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu31i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu31i_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu31i_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu31i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu31i_BFu0s, Ui_BFu31i_BFu0s)
//============================================================================



static void Test_Ui_BFu31ll_BFu0c()
{
  {
    init_simple_test("Ui_BFu31ll_BFu0c");
    static STRUCT_IF_C Ui_BFu31ll_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu31ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu31ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu31ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu31ll_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu31ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu31ll_BFu0c, Ui_BFu31ll_BFu0c)
//============================================================================



static void Test_Ui_BFu31ll_BFu0i()
{
  {
    init_simple_test("Ui_BFu31ll_BFu0i");
    static STRUCT_IF_C Ui_BFu31ll_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu31ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu31ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu31ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu31ll_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu31ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu31ll_BFu0i, Ui_BFu31ll_BFu0i)
//============================================================================



static void Test_Ui_BFu31ll_BFu0ll()
{
  {
    init_simple_test("Ui_BFu31ll_BFu0ll");
    static STRUCT_IF_C Ui_BFu31ll_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu31ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu31ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu31ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu31ll_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu31ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu31ll_BFu0ll, Ui_BFu31ll_BFu0ll)
//============================================================================



static void Test_Ui_BFu31ll_BFu0s()
{
  {
    init_simple_test("Ui_BFu31ll_BFu0s");
    static STRUCT_IF_C Ui_BFu31ll_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu31ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu31ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu31ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Ui_BFu31ll_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Ui_BFu31ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu31ll_BFu0s, Ui_BFu31ll_BFu0s)
//============================================================================



static void Test_Ui_BFu32i_BFu0c()
{
  {
    init_simple_test("Ui_BFu32i_BFu0c");
    static STRUCT_IF_C Ui_BFu32i_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu32i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu32i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu32i_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu32i_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu32i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu32i_BFu0c, Ui_BFu32i_BFu0c)
//============================================================================



static void Test_Ui_BFu32i_BFu0i()
{
  {
    init_simple_test("Ui_BFu32i_BFu0i");
    static STRUCT_IF_C Ui_BFu32i_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu32i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu32i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu32i_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu32i_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu32i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu32i_BFu0i, Ui_BFu32i_BFu0i)
//============================================================================



static void Test_Ui_BFu32i_BFu0ll()
{
  {
    init_simple_test("Ui_BFu32i_BFu0ll");
    static STRUCT_IF_C Ui_BFu32i_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu32i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu32i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu32i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu32i_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu32i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu32i_BFu0ll, Ui_BFu32i_BFu0ll)
//============================================================================



static void Test_Ui_BFu32i_BFu0s()
{
  {
    init_simple_test("Ui_BFu32i_BFu0s");
    static STRUCT_IF_C Ui_BFu32i_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu32i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu32i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu32i_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu32i_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu32i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu32i_BFu0s, Ui_BFu32i_BFu0s)
//============================================================================



static void Test_Ui_BFu32ll_BFu0c()
{
  {
    init_simple_test("Ui_BFu32ll_BFu0c");
    static STRUCT_IF_C Ui_BFu32ll_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu32ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu32ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu32ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu32ll_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu32ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu32ll_BFu0c, Ui_BFu32ll_BFu0c)
//============================================================================



static void Test_Ui_BFu32ll_BFu0i()
{
  {
    init_simple_test("Ui_BFu32ll_BFu0i");
    static STRUCT_IF_C Ui_BFu32ll_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu32ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu32ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu32ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu32ll_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu32ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu32ll_BFu0i, Ui_BFu32ll_BFu0i)
//============================================================================



static void Test_Ui_BFu32ll_BFu0ll()
{
  {
    init_simple_test("Ui_BFu32ll_BFu0ll");
    static STRUCT_IF_C Ui_BFu32ll_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu32ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu32ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu32ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu32ll_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu32ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu32ll_BFu0ll, Ui_BFu32ll_BFu0ll)
//============================================================================



static void Test_Ui_BFu32ll_BFu0s()
{
  {
    init_simple_test("Ui_BFu32ll_BFu0s");
    static STRUCT_IF_C Ui_BFu32ll_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu32ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu32ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu32ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Ui_BFu32ll_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Ui_BFu32ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu32ll_BFu0s, Ui_BFu32ll_BFu0s)
//============================================================================



static void Test_Ui_BFu33_BFu0c()
{
  {
    init_simple_test("Ui_BFu33_BFu0c");
    static STRUCT_IF_C Ui_BFu33_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ui_BFu33_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu33_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu33_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 33, 1, "Ui_BFu33_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 33, hide_ull(1LL<<32), "Ui_BFu33_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu33_BFu0c, Ui_BFu33_BFu0c)
//============================================================================



static void Test_Ui_BFu33_BFu0i()
{
  {
    init_simple_test("Ui_BFu33_BFu0i");
    static STRUCT_IF_C Ui_BFu33_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ui_BFu33_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu33_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu33_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 33, 1, "Ui_BFu33_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 33, hide_ull(1LL<<32), "Ui_BFu33_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu33_BFu0i, Ui_BFu33_BFu0i)
//============================================================================



static void Test_Ui_BFu33_BFu0ll()
{
  {
    init_simple_test("Ui_BFu33_BFu0ll");
    static STRUCT_IF_C Ui_BFu33_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ui_BFu33_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu33_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu33_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 33, 1, "Ui_BFu33_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 33, hide_ull(1LL<<32), "Ui_BFu33_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu33_BFu0ll, Ui_BFu33_BFu0ll)
//============================================================================



static void Test_Ui_BFu33_BFu0s()
{
  {
    init_simple_test("Ui_BFu33_BFu0s");
    static STRUCT_IF_C Ui_BFu33_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ui_BFu33_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu33_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu33_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 33, 1, "Ui_BFu33_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 33, hide_ull(1LL<<32), "Ui_BFu33_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu33_BFu0s, Ui_BFu33_BFu0s)
//============================================================================



static void Test_Ui_BFu7c_BFu0c()
{
  {
    init_simple_test("Ui_BFu7c_BFu0c");
    static STRUCT_IF_C Ui_BFu7c_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu7c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu7c_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu7c_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7c_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7c_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu7c_BFu0c, Ui_BFu7c_BFu0c)
//============================================================================



static void Test_Ui_BFu7c_BFu0i()
{
  {
    init_simple_test("Ui_BFu7c_BFu0i");
    static STRUCT_IF_C Ui_BFu7c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu7c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7c_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu7c_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7c_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7c_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu7c_BFu0i, Ui_BFu7c_BFu0i)
//============================================================================



static void Test_Ui_BFu7c_BFu0ll()
{
  {
    init_simple_test("Ui_BFu7c_BFu0ll");
    static STRUCT_IF_C Ui_BFu7c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu7c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu7c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7c_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7c_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu7c_BFu0ll, Ui_BFu7c_BFu0ll)
//============================================================================



static void Test_Ui_BFu7c_BFu0s()
{
  {
    init_simple_test("Ui_BFu7c_BFu0s");
    static STRUCT_IF_C Ui_BFu7c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu7c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7c_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu7c_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7c_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7c_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu7c_BFu0s, Ui_BFu7c_BFu0s)
//============================================================================



static void Test_Ui_BFu7i_BFu0c()
{
  {
    init_simple_test("Ui_BFu7i_BFu0c");
    static STRUCT_IF_C Ui_BFu7i_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu7i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu7i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu7i_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7i_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu7i_BFu0c, Ui_BFu7i_BFu0c)
//============================================================================



static void Test_Ui_BFu7i_BFu0i()
{
  {
    init_simple_test("Ui_BFu7i_BFu0i");
    static STRUCT_IF_C Ui_BFu7i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu7i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu7i_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7i_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu7i_BFu0i, Ui_BFu7i_BFu0i)
//============================================================================



static void Test_Ui_BFu7i_BFu0ll()
{
  {
    init_simple_test("Ui_BFu7i_BFu0ll");
    static STRUCT_IF_C Ui_BFu7i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu7i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu7i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7i_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu7i_BFu0ll, Ui_BFu7i_BFu0ll)
//============================================================================



static void Test_Ui_BFu7i_BFu0s()
{
  {
    init_simple_test("Ui_BFu7i_BFu0s");
    static STRUCT_IF_C Ui_BFu7i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu7i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu7i_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7i_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu7i_BFu0s, Ui_BFu7i_BFu0s)
//============================================================================



static void Test_Ui_BFu7ll_BFu0c()
{
  {
    init_simple_test("Ui_BFu7ll_BFu0c");
    static STRUCT_IF_C Ui_BFu7ll_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu7ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu7ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu7ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7ll_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu7ll_BFu0c, Ui_BFu7ll_BFu0c)
//============================================================================



static void Test_Ui_BFu7ll_BFu0i()
{
  {
    init_simple_test("Ui_BFu7ll_BFu0i");
    static STRUCT_IF_C Ui_BFu7ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu7ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu7ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7ll_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu7ll_BFu0i, Ui_BFu7ll_BFu0i)
//============================================================================



static void Test_Ui_BFu7ll_BFu0ll()
{
  {
    init_simple_test("Ui_BFu7ll_BFu0ll");
    static STRUCT_IF_C Ui_BFu7ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu7ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu7ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7ll_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu7ll_BFu0ll, Ui_BFu7ll_BFu0ll)
//============================================================================



static void Test_Ui_BFu7ll_BFu0s()
{
  {
    init_simple_test("Ui_BFu7ll_BFu0s");
    static STRUCT_IF_C Ui_BFu7ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu7ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu7ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7ll_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu7ll_BFu0s, Ui_BFu7ll_BFu0s)
//============================================================================



static void Test_Ui_BFu7s_BFu0c()
{
  {
    init_simple_test("Ui_BFu7s_BFu0c");
    static STRUCT_IF_C Ui_BFu7s_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu7s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu7s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu7s_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7s_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu7s_BFu0c, Ui_BFu7s_BFu0c)
//============================================================================



static void Test_Ui_BFu7s_BFu0i()
{
  {
    init_simple_test("Ui_BFu7s_BFu0i");
    static STRUCT_IF_C Ui_BFu7s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu7s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu7s_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7s_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu7s_BFu0i, Ui_BFu7s_BFu0i)
//============================================================================



static void Test_Ui_BFu7s_BFu0ll()
{
  {
    init_simple_test("Ui_BFu7s_BFu0ll");
    static STRUCT_IF_C Ui_BFu7s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu7s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu7s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7s_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu7s_BFu0ll, Ui_BFu7s_BFu0ll)
//============================================================================



static void Test_Ui_BFu7s_BFu0s()
{
  {
    init_simple_test("Ui_BFu7s_BFu0s");
    static STRUCT_IF_C Ui_BFu7s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu7s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu7s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu7s_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "Ui_BFu7s_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "Ui_BFu7s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu7s_BFu0s, Ui_BFu7s_BFu0s)
//============================================================================



static void Test_Ui_BFu8c_BFu0c()
{
  {
    init_simple_test("Ui_BFu8c_BFu0c");
    static STRUCT_IF_C Ui_BFu8c_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu8c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu8c_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu8c_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8c_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8c_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu8c_BFu0c, Ui_BFu8c_BFu0c)
//============================================================================



static void Test_Ui_BFu8c_BFu0i()
{
  {
    init_simple_test("Ui_BFu8c_BFu0i");
    static STRUCT_IF_C Ui_BFu8c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu8c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8c_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu8c_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8c_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8c_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu8c_BFu0i, Ui_BFu8c_BFu0i)
//============================================================================



static void Test_Ui_BFu8c_BFu0ll()
{
  {
    init_simple_test("Ui_BFu8c_BFu0ll");
    static STRUCT_IF_C Ui_BFu8c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu8c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu8c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8c_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8c_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu8c_BFu0ll, Ui_BFu8c_BFu0ll)
//============================================================================



static void Test_Ui_BFu8c_BFu0s()
{
  {
    init_simple_test("Ui_BFu8c_BFu0s");
    static STRUCT_IF_C Ui_BFu8c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu8c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8c_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu8c_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8c_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8c_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu8c_BFu0s, Ui_BFu8c_BFu0s)
//============================================================================



static void Test_Ui_BFu8i_BFu0c()
{
  {
    init_simple_test("Ui_BFu8i_BFu0c");
    static STRUCT_IF_C Ui_BFu8i_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu8i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu8i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu8i_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8i_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu8i_BFu0c, Ui_BFu8i_BFu0c)
//============================================================================



static void Test_Ui_BFu8i_BFu0i()
{
  {
    init_simple_test("Ui_BFu8i_BFu0i");
    static STRUCT_IF_C Ui_BFu8i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu8i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu8i_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8i_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu8i_BFu0i, Ui_BFu8i_BFu0i)
//============================================================================



static void Test_Ui_BFu8i_BFu0ll()
{
  {
    init_simple_test("Ui_BFu8i_BFu0ll");
    static STRUCT_IF_C Ui_BFu8i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu8i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu8i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8i_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu8i_BFu0ll, Ui_BFu8i_BFu0ll)
//============================================================================



static void Test_Ui_BFu8i_BFu0s()
{
  {
    init_simple_test("Ui_BFu8i_BFu0s");
    static STRUCT_IF_C Ui_BFu8i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu8i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu8i_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8i_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu8i_BFu0s, Ui_BFu8i_BFu0s)
//============================================================================



static void Test_Ui_BFu8ll_BFu0c()
{
  {
    init_simple_test("Ui_BFu8ll_BFu0c");
    static STRUCT_IF_C Ui_BFu8ll_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu8ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu8ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu8ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8ll_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu8ll_BFu0c, Ui_BFu8ll_BFu0c)
//============================================================================



static void Test_Ui_BFu8ll_BFu0i()
{
  {
    init_simple_test("Ui_BFu8ll_BFu0i");
    static STRUCT_IF_C Ui_BFu8ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu8ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu8ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8ll_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu8ll_BFu0i, Ui_BFu8ll_BFu0i)
//============================================================================



static void Test_Ui_BFu8ll_BFu0ll()
{
  {
    init_simple_test("Ui_BFu8ll_BFu0ll");
    static STRUCT_IF_C Ui_BFu8ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu8ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu8ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8ll_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu8ll_BFu0ll, Ui_BFu8ll_BFu0ll)
//============================================================================



static void Test_Ui_BFu8ll_BFu0s()
{
  {
    init_simple_test("Ui_BFu8ll_BFu0s");
    static STRUCT_IF_C Ui_BFu8ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu8ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu8ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8ll_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu8ll_BFu0s, Ui_BFu8ll_BFu0s)
//============================================================================



static void Test_Ui_BFu8s_BFu0c()
{
  {
    init_simple_test("Ui_BFu8s_BFu0c");
    static STRUCT_IF_C Ui_BFu8s_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_BFu8s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu8s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu8s_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8s_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu8s_BFu0c, Ui_BFu8s_BFu0c)
//============================================================================



static void Test_Ui_BFu8s_BFu0i()
{
  {
    init_simple_test("Ui_BFu8s_BFu0i");
    static STRUCT_IF_C Ui_BFu8s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu8s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu8s_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8s_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu8s_BFu0i, Ui_BFu8s_BFu0i)
//============================================================================



static void Test_Ui_BFu8s_BFu0ll()
{
  {
    init_simple_test("Ui_BFu8s_BFu0ll");
    static STRUCT_IF_C Ui_BFu8s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu8s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu8s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8s_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu8s_BFu0ll, Ui_BFu8s_BFu0ll)
//============================================================================



static void Test_Ui_BFu8s_BFu0s()
{
  {
    init_simple_test("Ui_BFu8s_BFu0s");
    static STRUCT_IF_C Ui_BFu8s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_BFu8s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu8s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu8s_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "Ui_BFu8s_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "Ui_BFu8s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu8s_BFu0s, Ui_BFu8s_BFu0s)
//============================================================================



static void Test_Ui_BFu9i_BFu0c()
{
  {
    init_simple_test("Ui_BFu9i_BFu0c");
    static STRUCT_IF_C Ui_BFu9i_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu9i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu9i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu9i_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9i_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu9i_BFu0c, Ui_BFu9i_BFu0c)
//============================================================================



static void Test_Ui_BFu9i_BFu0i()
{
  {
    init_simple_test("Ui_BFu9i_BFu0i");
    static STRUCT_IF_C Ui_BFu9i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu9i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu9i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu9i_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9i_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu9i_BFu0i, Ui_BFu9i_BFu0i)
//============================================================================



static void Test_Ui_BFu9i_BFu0ll()
{
  {
    init_simple_test("Ui_BFu9i_BFu0ll");
    static STRUCT_IF_C Ui_BFu9i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu9i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu9i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu9i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9i_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu9i_BFu0ll, Ui_BFu9i_BFu0ll)
//============================================================================



static void Test_Ui_BFu9i_BFu0s()
{
  {
    init_simple_test("Ui_BFu9i_BFu0s");
    static STRUCT_IF_C Ui_BFu9i_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu9i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu9i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu9i_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9i_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu9i_BFu0s, Ui_BFu9i_BFu0s)
//============================================================================



static void Test_Ui_BFu9ll_BFu0c()
{
  {
    init_simple_test("Ui_BFu9ll_BFu0c");
    static STRUCT_IF_C Ui_BFu9ll_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu9ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu9ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu9ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9ll_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu9ll_BFu0c, Ui_BFu9ll_BFu0c)
//============================================================================



static void Test_Ui_BFu9ll_BFu0i()
{
  {
    init_simple_test("Ui_BFu9ll_BFu0i");
    static STRUCT_IF_C Ui_BFu9ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu9ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu9ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu9ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9ll_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu9ll_BFu0i, Ui_BFu9ll_BFu0i)
//============================================================================



static void Test_Ui_BFu9ll_BFu0ll()
{
  {
    init_simple_test("Ui_BFu9ll_BFu0ll");
    static STRUCT_IF_C Ui_BFu9ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu9ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu9ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu9ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9ll_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu9ll_BFu0ll, Ui_BFu9ll_BFu0ll)
//============================================================================



static void Test_Ui_BFu9ll_BFu0s()
{
  {
    init_simple_test("Ui_BFu9ll_BFu0s");
    static STRUCT_IF_C Ui_BFu9ll_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu9ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu9ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu9ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9ll_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu9ll_BFu0s, Ui_BFu9ll_BFu0s)
//============================================================================



static void Test_Ui_BFu9s_BFu0c()
{
  {
    init_simple_test("Ui_BFu9s_BFu0c");
    static STRUCT_IF_C Ui_BFu9s_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu9s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_BFu9s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_BFu9s_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9s_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu9s_BFu0c, Ui_BFu9s_BFu0c)
//============================================================================



static void Test_Ui_BFu9s_BFu0i()
{
  {
    init_simple_test("Ui_BFu9s_BFu0i");
    static STRUCT_IF_C Ui_BFu9s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu9s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu9s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_BFu9s_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9s_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu9s_BFu0i, Ui_BFu9s_BFu0i)
//============================================================================



static void Test_Ui_BFu9s_BFu0ll()
{
  {
    init_simple_test("Ui_BFu9s_BFu0ll");
    static STRUCT_IF_C Ui_BFu9s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_BFu9s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu9s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_BFu9s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9s_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu9s_BFu0ll, Ui_BFu9s_BFu0ll)
//============================================================================



static void Test_Ui_BFu9s_BFu0s()
{
  {
    init_simple_test("Ui_BFu9s_BFu0s");
    static STRUCT_IF_C Ui_BFu9s_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_BFu9s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_BFu9s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_BFu9s_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "Ui_BFu9s_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "Ui_BFu9s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu9s_BFu0s, Ui_BFu9s_BFu0s)
//============================================================================



static void Test_Ui_C_BFu0c()
{
  {
    init_simple_test("Ui_C_BFu0c");
    static STRUCT_IF_C Ui_C_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_C_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_C_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_C_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_C_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_C_BFu0c, Ui_C_BFu0c)
//============================================================================



static void Test_Ui_C_BFu0i()
{
  {
    init_simple_test("Ui_C_BFu0i");
    static STRUCT_IF_C Ui_C_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_C_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_C_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_C_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_C_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_C_BFu0i, Ui_C_BFu0i)
//============================================================================



static void Test_Ui_C_BFu0ll()
{
  {
    init_simple_test("Ui_C_BFu0ll");
    static STRUCT_IF_C Ui_C_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_C_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_C_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_C_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_C_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_C_BFu0ll, Ui_C_BFu0ll)
//============================================================================



static void Test_Ui_C_BFu0s()
{
  {
    init_simple_test("Ui_C_BFu0s");
    static STRUCT_IF_C Ui_C_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_C_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_C_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_C_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_C_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_C_BFu0s, Ui_C_BFu0s)
//============================================================================



static void Test_Ui_D_BFu0c()
{
  {
    init_simple_test("Ui_D_BFu0c");
    static STRUCT_IF_C Ui_D_BFu0c lv;
    check2(sizeof(lv), 12, "sizeof(Ui_D_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_D_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_D_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_D_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_D_BFu0c, Ui_D_BFu0c)
//============================================================================



static void Test_Ui_D_BFu0i()
{
  {
    init_simple_test("Ui_D_BFu0i");
    static STRUCT_IF_C Ui_D_BFu0i lv;
    check2(sizeof(lv), 12, "sizeof(Ui_D_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_D_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_D_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_D_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_D_BFu0i, Ui_D_BFu0i)
//============================================================================



static void Test_Ui_D_BFu0ll()
{
  {
    init_simple_test("Ui_D_BFu0ll");
    static STRUCT_IF_C Ui_D_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ui_D_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_D_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_D_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_D_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_D_BFu0ll, Ui_D_BFu0ll)
//============================================================================



static void Test_Ui_D_BFu0s()
{
  {
    init_simple_test("Ui_D_BFu0s");
    static STRUCT_IF_C Ui_D_BFu0s lv;
    check2(sizeof(lv), 12, "sizeof(Ui_D_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_D_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_D_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_D_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_D_BFu0s, Ui_D_BFu0s)
//============================================================================



static void Test_Ui_F_BFu0c()
{
  {
    init_simple_test("Ui_F_BFu0c");
    static STRUCT_IF_C Ui_F_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ui_F_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_F_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_F_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_F_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_F_BFu0c, Ui_F_BFu0c)
//============================================================================



static void Test_Ui_F_BFu0i()
{
  {
    init_simple_test("Ui_F_BFu0i");
    static STRUCT_IF_C Ui_F_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_F_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_F_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_F_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_F_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_F_BFu0i, Ui_F_BFu0i)
//============================================================================



static void Test_Ui_F_BFu0ll()
{
  {
    init_simple_test("Ui_F_BFu0ll");
    static STRUCT_IF_C Ui_F_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_F_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_F_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_F_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_F_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_F_BFu0ll, Ui_F_BFu0ll)
//============================================================================



static void Test_Ui_F_BFu0s()
{
  {
    init_simple_test("Ui_F_BFu0s");
    static STRUCT_IF_C Ui_F_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ui_F_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_F_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_F_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_F_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_F_BFu0s, Ui_F_BFu0s)
//============================================================================



static void Test_Ui_I_BFu0c()
{
  {
    init_simple_test("Ui_I_BFu0c");
    static STRUCT_IF_C Ui_I_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ui_I_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_I_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_I_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_I_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_I_BFu0c, Ui_I_BFu0c)
//============================================================================



static void Test_Ui_I_BFu0i()
{
  {
    init_simple_test("Ui_I_BFu0i");
    static STRUCT_IF_C Ui_I_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_I_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_I_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_I_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_I_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_I_BFu0i, Ui_I_BFu0i)
//============================================================================



static void Test_Ui_I_BFu0ll()
{
  {
    init_simple_test("Ui_I_BFu0ll");
    static STRUCT_IF_C Ui_I_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_I_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_I_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_I_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_I_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_I_BFu0ll, Ui_I_BFu0ll)
//============================================================================



static void Test_Ui_I_BFu0s()
{
  {
    init_simple_test("Ui_I_BFu0s");
    static STRUCT_IF_C Ui_I_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ui_I_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_I_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_I_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_I_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_I_BFu0s, Ui_I_BFu0s)
//============================================================================



static void Test_Ui_Ip_BFu0c()
{
  {
    init_simple_test("Ui_Ip_BFu0c");
    static STRUCT_IF_C Ui_Ip_BFu0c lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_Ip_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Ip_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_Ip_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_Ip_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Ip_BFu0c, Ui_Ip_BFu0c)
//============================================================================



static void Test_Ui_Ip_BFu0i()
{
  {
    init_simple_test("Ui_Ip_BFu0i");
    static STRUCT_IF_C Ui_Ip_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_Ip_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Ip_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_Ip_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_Ip_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Ip_BFu0i, Ui_Ip_BFu0i)
//============================================================================



static void Test_Ui_Ip_BFu0ll()
{
  {
    init_simple_test("Ui_Ip_BFu0ll");
    static STRUCT_IF_C Ui_Ip_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Ui_Ip_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Ip_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_Ip_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Ip_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Ip_BFu0ll, Ui_Ip_BFu0ll)
//============================================================================



static void Test_Ui_Ip_BFu0s()
{
  {
    init_simple_test("Ui_Ip_BFu0s");
    static STRUCT_IF_C Ui_Ip_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_Ip_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Ip_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_Ip_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_Ip_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Ip_BFu0s, Ui_Ip_BFu0s)
//============================================================================



static void Test_Ui_L_BFu0c()
{
  {
    init_simple_test("Ui_L_BFu0c");
    static STRUCT_IF_C Ui_L_BFu0c lv;
    check2(sizeof(lv), 12, "sizeof(Ui_L_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_L_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_L_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_L_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_L_BFu0c, Ui_L_BFu0c)
//============================================================================



static void Test_Ui_L_BFu0i()
{
  {
    init_simple_test("Ui_L_BFu0i");
    static STRUCT_IF_C Ui_L_BFu0i lv;
    check2(sizeof(lv), 12, "sizeof(Ui_L_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_L_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_L_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_L_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_L_BFu0i, Ui_L_BFu0i)
//============================================================================



static void Test_Ui_L_BFu0ll()
{
  {
    init_simple_test("Ui_L_BFu0ll");
    static STRUCT_IF_C Ui_L_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ui_L_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_L_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_L_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_L_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_L_BFu0ll, Ui_L_BFu0ll)
//============================================================================



static void Test_Ui_L_BFu0s()
{
  {
    init_simple_test("Ui_L_BFu0s");
    static STRUCT_IF_C Ui_L_BFu0s lv;
    check2(sizeof(lv), 12, "sizeof(Ui_L_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_L_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_L_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_L_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_L_BFu0s, Ui_L_BFu0s)
//============================================================================



static void Test_Ui_S_BFu0c()
{
  {
    init_simple_test("Ui_S_BFu0c");
    static STRUCT_IF_C Ui_S_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_S_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_S_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_S_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_S_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_S_BFu0c, Ui_S_BFu0c)
//============================================================================



static void Test_Ui_S_BFu0i()
{
  {
    init_simple_test("Ui_S_BFu0i");
    static STRUCT_IF_C Ui_S_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_S_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_S_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_S_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_S_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_S_BFu0i, Ui_S_BFu0i)
//============================================================================



static void Test_Ui_S_BFu0ll()
{
  {
    init_simple_test("Ui_S_BFu0ll");
    static STRUCT_IF_C Ui_S_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_S_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_S_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_S_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_S_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_S_BFu0ll, Ui_S_BFu0ll)
//============================================================================



static void Test_Ui_S_BFu0s()
{
  {
    init_simple_test("Ui_S_BFu0s");
    static STRUCT_IF_C Ui_S_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_S_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_S_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_S_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_S_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_S_BFu0s, Ui_S_BFu0s)
//============================================================================



static void Test_Ui_Uc_BFu0c()
{
  {
    init_simple_test("Ui_Uc_BFu0c");
    static STRUCT_IF_C Ui_Uc_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Ui_Uc_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Uc_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_Uc_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_Uc_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Uc_BFu0c, Ui_Uc_BFu0c)
//============================================================================



static void Test_Ui_Uc_BFu0i()
{
  {
    init_simple_test("Ui_Uc_BFu0i");
    static STRUCT_IF_C Ui_Uc_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_Uc_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Uc_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_Uc_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_Uc_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Uc_BFu0i, Ui_Uc_BFu0i)
//============================================================================



static void Test_Ui_Uc_BFu0ll()
{
  {
    init_simple_test("Ui_Uc_BFu0ll");
    static STRUCT_IF_C Ui_Uc_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_Uc_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Uc_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_Uc_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Uc_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Uc_BFu0ll, Ui_Uc_BFu0ll)
//============================================================================



static void Test_Ui_Uc_BFu0s()
{
  {
    init_simple_test("Ui_Uc_BFu0s");
    static STRUCT_IF_C Ui_Uc_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Ui_Uc_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Uc_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_Uc_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_Uc_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Uc_BFu0s, Ui_Uc_BFu0s)
//============================================================================



static void Test_Ui_Ui_BFu0c()
{
  {
    init_simple_test("Ui_Ui_BFu0c");
    static STRUCT_IF_C Ui_Ui_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ui_Ui_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Ui_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_Ui_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_Ui_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Ui_BFu0c, Ui_Ui_BFu0c)
//============================================================================



static void Test_Ui_Ui_BFu0i()
{
  {
    init_simple_test("Ui_Ui_BFu0i");
    static STRUCT_IF_C Ui_Ui_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_Ui_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Ui_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_Ui_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_Ui_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Ui_BFu0i, Ui_Ui_BFu0i)
//============================================================================



static void Test_Ui_Ui_BFu0ll()
{
  {
    init_simple_test("Ui_Ui_BFu0ll");
    static STRUCT_IF_C Ui_Ui_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_Ui_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Ui_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_Ui_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Ui_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Ui_BFu0ll, Ui_Ui_BFu0ll)
//============================================================================



static void Test_Ui_Ui_BFu0s()
{
  {
    init_simple_test("Ui_Ui_BFu0s");
    static STRUCT_IF_C Ui_Ui_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ui_Ui_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Ui_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_Ui_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_Ui_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Ui_BFu0s, Ui_Ui_BFu0s)
//============================================================================



static void Test_Ui_Ul_BFu0c()
{
  {
    init_simple_test("Ui_Ul_BFu0c");
    static STRUCT_IF_C Ui_Ul_BFu0c lv;
    check2(sizeof(lv), 12, "sizeof(Ui_Ul_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Ul_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_Ul_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_Ul_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Ul_BFu0c, Ui_Ul_BFu0c)
//============================================================================



static void Test_Ui_Ul_BFu0i()
{
  {
    init_simple_test("Ui_Ul_BFu0i");
    static STRUCT_IF_C Ui_Ul_BFu0i lv;
    check2(sizeof(lv), 12, "sizeof(Ui_Ul_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Ul_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_Ul_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_Ul_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Ul_BFu0i, Ui_Ul_BFu0i)
//============================================================================



static void Test_Ui_Ul_BFu0ll()
{
  {
    init_simple_test("Ui_Ul_BFu0ll");
    static STRUCT_IF_C Ui_Ul_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ui_Ul_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Ul_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_Ul_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Ul_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Ul_BFu0ll, Ui_Ul_BFu0ll)
//============================================================================



static void Test_Ui_Ul_BFu0s()
{
  {
    init_simple_test("Ui_Ul_BFu0s");
    static STRUCT_IF_C Ui_Ul_BFu0s lv;
    check2(sizeof(lv), 12, "sizeof(Ui_Ul_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Ul_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_Ul_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_Ul_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Ul_BFu0s, Ui_Ul_BFu0s)
//============================================================================



static void Test_Ui_Us_BFu0c()
{
  {
    init_simple_test("Ui_Us_BFu0c");
    static STRUCT_IF_C Ui_Us_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Ui_Us_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Us_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_Us_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_Us_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Us_BFu0c, Ui_Us_BFu0c)
//============================================================================



static void Test_Ui_Us_BFu0i()
{
  {
    init_simple_test("Ui_Us_BFu0i");
    static STRUCT_IF_C Ui_Us_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_Us_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Us_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_Us_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_Us_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Us_BFu0i, Ui_Us_BFu0i)
//============================================================================



static void Test_Ui_Us_BFu0ll()
{
  {
    init_simple_test("Ui_Us_BFu0ll");
    static STRUCT_IF_C Ui_Us_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Ui_Us_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Us_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_Us_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Us_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Us_BFu0ll, Ui_Us_BFu0ll)
//============================================================================



static void Test_Ui_Us_BFu0s()
{
  {
    init_simple_test("Ui_Us_BFu0s");
    static STRUCT_IF_C Ui_Us_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Ui_Us_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Us_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_Us_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_Us_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Us_BFu0s, Ui_Us_BFu0s)
//============================================================================



static void Test_Ui_Vp_BFu0c()
{
  {
    init_simple_test("Ui_Vp_BFu0c");
    static STRUCT_IF_C Ui_Vp_BFu0c lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_Vp_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ui_Vp_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_Vp_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_Vp_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Vp_BFu0c, Ui_Vp_BFu0c)
//============================================================================



static void Test_Ui_Vp_BFu0i()
{
  {
    init_simple_test("Ui_Vp_BFu0i");
    static STRUCT_IF_C Ui_Vp_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_Vp_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Vp_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_Vp_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_Vp_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Vp_BFu0i, Ui_Vp_BFu0i)
//============================================================================



static void Test_Ui_Vp_BFu0ll()
{
  {
    init_simple_test("Ui_Vp_BFu0ll");
    static STRUCT_IF_C Ui_Vp_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Ui_Vp_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Vp_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_Vp_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Vp_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Vp_BFu0ll, Ui_Vp_BFu0ll)
//============================================================================



static void Test_Ui_Vp_BFu0s()
{
  {
    init_simple_test("Ui_Vp_BFu0s");
    static STRUCT_IF_C Ui_Vp_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_Vp_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ui_Vp_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_Vp_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_Vp_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Vp_BFu0s, Ui_Vp_BFu0s)
//============================================================================



static void Test_Ul_BFu0c()
{
  {
    init_simple_test("Ul_BFu0c");
    static STRUCT_IF_C Ul_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c, Ul_BFu0c)
//============================================================================



static void Test_Ul_BFu0c_BFu0c()
{
  {
    init_simple_test("Ul_BFu0c_BFu0c");
    static STRUCT_IF_C Ul_BFu0c_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu0c, Ul_BFu0c_BFu0c)
//============================================================================



static void Test_Ul_BFu0c_BFu0i()
{
  {
    init_simple_test("Ul_BFu0c_BFu0i");
    static STRUCT_IF_C Ul_BFu0c_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0c_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu0i, Ul_BFu0c_BFu0i)
//============================================================================



static void Test_Ul_BFu0c_BFu0ll()
{
  {
    init_simple_test("Ul_BFu0c_BFu0ll");
    static STRUCT_IF_C Ul_BFu0c_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu0ll, Ul_BFu0c_BFu0ll)
//============================================================================



static void Test_Ul_BFu0c_BFu0s()
{
  {
    init_simple_test("Ul_BFu0c_BFu0s");
    static STRUCT_IF_C Ul_BFu0c_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0c_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu0s, Ul_BFu0c_BFu0s)
//============================================================================



static void Test_Ul_BFu0c_BFu15i()
{
  {
    init_simple_test("Ul_BFu0c_BFu15i");
    static STRUCT_IF_C Ul_BFu0c_BFu15i lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu15i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu15i.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0c_BFu15i");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0c_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu15i, Ul_BFu0c_BFu15i)
//============================================================================



static void Test_Ul_BFu0c_BFu15ll()
{
  {
    init_simple_test("Ul_BFu0c_BFu15ll");
    static STRUCT_IF_C Ul_BFu0c_BFu15ll lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu15ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu15ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0c_BFu15ll");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0c_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu15ll, Ul_BFu0c_BFu15ll)
//============================================================================



static void Test_Ul_BFu0c_BFu15s()
{
  {
    init_simple_test("Ul_BFu0c_BFu15s");
    static STRUCT_IF_C Ul_BFu0c_BFu15s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu15s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu15s.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0c_BFu15s");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0c_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu15s, Ul_BFu0c_BFu15s)
//============================================================================



static void Test_Ul_BFu0c_BFu16i()
{
  {
    init_simple_test("Ul_BFu0c_BFu16i");
    static STRUCT_IF_C Ul_BFu0c_BFu16i lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu16i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu16i.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0c_BFu16i");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0c_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu16i, Ul_BFu0c_BFu16i)
//============================================================================



static void Test_Ul_BFu0c_BFu16ll()
{
  {
    init_simple_test("Ul_BFu0c_BFu16ll");
    static STRUCT_IF_C Ul_BFu0c_BFu16ll lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu16ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu16ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0c_BFu16ll");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0c_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu16ll, Ul_BFu0c_BFu16ll)
//============================================================================



static void Test_Ul_BFu0c_BFu16s()
{
  {
    init_simple_test("Ul_BFu0c_BFu16s");
    static STRUCT_IF_C Ul_BFu0c_BFu16s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu16s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu16s.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0c_BFu16s");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0c_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu16s, Ul_BFu0c_BFu16s)
//============================================================================



static void Test_Ul_BFu0c_BFu17i()
{
  {
    init_simple_test("Ul_BFu0c_BFu17i");
    static STRUCT_IF_C Ul_BFu0c_BFu17i lv;
    check2(sizeof(lv), 11, "sizeof(Ul_BFu0c_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu17i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu17i.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu0c_BFu17i");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu0c_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu17i, Ul_BFu0c_BFu17i)
//============================================================================



static void Test_Ul_BFu0c_BFu17ll()
{
  {
    init_simple_test("Ul_BFu0c_BFu17ll");
    static STRUCT_IF_C Ul_BFu0c_BFu17ll lv;
    check2(sizeof(lv), 11, "sizeof(Ul_BFu0c_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu17ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu17ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu0c_BFu17ll");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu0c_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu17ll, Ul_BFu0c_BFu17ll)
//============================================================================



static void Test_Ul_BFu0c_BFu1c()
{
  {
    init_simple_test("Ul_BFu0c_BFu1c");
    static STRUCT_IF_C Ul_BFu0c_BFu1c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu1c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu1c.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0c_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu1c, Ul_BFu0c_BFu1c)
//============================================================================



static void Test_Ul_BFu0c_BFu1i()
{
  {
    init_simple_test("Ul_BFu0c_BFu1i");
    static STRUCT_IF_C Ul_BFu0c_BFu1i lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu1i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu1i.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0c_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu1i, Ul_BFu0c_BFu1i)
//============================================================================



static void Test_Ul_BFu0c_BFu1ll()
{
  {
    init_simple_test("Ul_BFu0c_BFu1ll");
    static STRUCT_IF_C Ul_BFu0c_BFu1ll lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu1ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu1ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0c_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu1ll, Ul_BFu0c_BFu1ll)
//============================================================================



static void Test_Ul_BFu0c_BFu1s()
{
  {
    init_simple_test("Ul_BFu0c_BFu1s");
    static STRUCT_IF_C Ul_BFu0c_BFu1s lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu1s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu1s.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0c_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu1s, Ul_BFu0c_BFu1s)
//============================================================================



static void Test_Ul_BFu0c_BFu31i()
{
  {
    init_simple_test("Ul_BFu0c_BFu31i");
    static STRUCT_IF_C Ul_BFu0c_BFu31i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0c_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu31i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu31i.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu0c_BFu31i");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu0c_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu31i, Ul_BFu0c_BFu31i)
//============================================================================



static void Test_Ul_BFu0c_BFu31ll()
{
  {
    init_simple_test("Ul_BFu0c_BFu31ll");
    static STRUCT_IF_C Ul_BFu0c_BFu31ll lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0c_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu31ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu31ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu0c_BFu31ll");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu0c_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu31ll, Ul_BFu0c_BFu31ll)
//============================================================================



static void Test_Ul_BFu0c_BFu32i()
{
  {
    init_simple_test("Ul_BFu0c_BFu32i");
    static STRUCT_IF_C Ul_BFu0c_BFu32i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0c_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu32i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu32i.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu0c_BFu32i");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu0c_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu32i, Ul_BFu0c_BFu32i)
//============================================================================



static void Test_Ul_BFu0c_BFu32ll()
{
  {
    init_simple_test("Ul_BFu0c_BFu32ll");
    static STRUCT_IF_C Ul_BFu0c_BFu32ll lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0c_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu32ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu32ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu0c_BFu32ll");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu0c_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu32ll, Ul_BFu0c_BFu32ll)
//============================================================================



static void Test_Ul_BFu0c_BFu33()
{
  {
    init_simple_test("Ul_BFu0c_BFu33");
    static STRUCT_IF_C Ul_BFu0c_BFu33 lv;
    check2(sizeof(lv), 13, "sizeof(Ul_BFu0c_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu33)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu33.v1");
    set_bf_and_test(lv, v2, 8, 0, 33, 1, "Ul_BFu0c_BFu33");
    set_bf_and_test(lv, v2, 8, 0, 33, hide_ull(1LL<<32), "Ul_BFu0c_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu33, Ul_BFu0c_BFu33)
//============================================================================



static void Test_Ul_BFu0c_BFu7c()
{
  {
    init_simple_test("Ul_BFu0c_BFu7c");
    static STRUCT_IF_C Ul_BFu0c_BFu7c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu7c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu7c.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0c_BFu7c");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0c_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu7c, Ul_BFu0c_BFu7c)
//============================================================================



static void Test_Ul_BFu0c_BFu7i()
{
  {
    init_simple_test("Ul_BFu0c_BFu7i");
    static STRUCT_IF_C Ul_BFu0c_BFu7i lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu7i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu7i.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0c_BFu7i");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0c_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu7i, Ul_BFu0c_BFu7i)
//============================================================================



static void Test_Ul_BFu0c_BFu7ll()
{
  {
    init_simple_test("Ul_BFu0c_BFu7ll");
    static STRUCT_IF_C Ul_BFu0c_BFu7ll lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu7ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu7ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0c_BFu7ll");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0c_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu7ll, Ul_BFu0c_BFu7ll)
//============================================================================



static void Test_Ul_BFu0c_BFu7s()
{
  {
    init_simple_test("Ul_BFu0c_BFu7s");
    static STRUCT_IF_C Ul_BFu0c_BFu7s lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu7s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu7s.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0c_BFu7s");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0c_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu7s, Ul_BFu0c_BFu7s)
//============================================================================



static void Test_Ul_BFu0c_BFu8c()
{
  {
    init_simple_test("Ul_BFu0c_BFu8c");
    static STRUCT_IF_C Ul_BFu0c_BFu8c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu8c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu8c.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0c_BFu8c");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0c_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu8c, Ul_BFu0c_BFu8c)
//============================================================================



static void Test_Ul_BFu0c_BFu8i()
{
  {
    init_simple_test("Ul_BFu0c_BFu8i");
    static STRUCT_IF_C Ul_BFu0c_BFu8i lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu8i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu8i.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0c_BFu8i");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0c_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu8i, Ul_BFu0c_BFu8i)
//============================================================================



static void Test_Ul_BFu0c_BFu8ll()
{
  {
    init_simple_test("Ul_BFu0c_BFu8ll");
    static STRUCT_IF_C Ul_BFu0c_BFu8ll lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu8ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu8ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0c_BFu8ll");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0c_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu8ll, Ul_BFu0c_BFu8ll)
//============================================================================



static void Test_Ul_BFu0c_BFu8s()
{
  {
    init_simple_test("Ul_BFu0c_BFu8s");
    static STRUCT_IF_C Ul_BFu0c_BFu8s lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu8s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu8s.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0c_BFu8s");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0c_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu8s, Ul_BFu0c_BFu8s)
//============================================================================



static void Test_Ul_BFu0c_BFu9i()
{
  {
    init_simple_test("Ul_BFu0c_BFu9i");
    static STRUCT_IF_C Ul_BFu0c_BFu9i lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu9i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu9i.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0c_BFu9i");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0c_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu9i, Ul_BFu0c_BFu9i)
//============================================================================



static void Test_Ul_BFu0c_BFu9ll()
{
  {
    init_simple_test("Ul_BFu0c_BFu9ll");
    static STRUCT_IF_C Ul_BFu0c_BFu9ll lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu9ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu9ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0c_BFu9ll");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0c_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu9ll, Ul_BFu0c_BFu9ll)
//============================================================================



static void Test_Ul_BFu0c_BFu9s()
{
  {
    init_simple_test("Ul_BFu0c_BFu9s");
    static STRUCT_IF_C Ul_BFu0c_BFu9s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_BFu9s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_BFu9s.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0c_BFu9s");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0c_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_BFu9s, Ul_BFu0c_BFu9s)
//============================================================================



static void Test_Ul_BFu0c_C()
{
  {
    init_simple_test("Ul_BFu0c_C");
    static STRUCT_IF_C Ul_BFu0c_C lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_C)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_C)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_C.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_C, Ul_BFu0c_C)
//============================================================================



static void Test_Ul_BFu0c_D()
{
  {
    init_simple_test("Ul_BFu0c_D");
    static STRUCT_IF_C Ul_BFu0c_D lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0c_D)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_D)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_D.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_D, Ul_BFu0c_D)
//============================================================================



static void Test_Ul_BFu0c_F()
{
  {
    init_simple_test("Ul_BFu0c_F");
    static STRUCT_IF_C Ul_BFu0c_F lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0c_F)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_F)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_F.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_F, Ul_BFu0c_F)
//============================================================================



static void Test_Ul_BFu0c_I()
{
  {
    init_simple_test("Ul_BFu0c_I");
    static STRUCT_IF_C Ul_BFu0c_I lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0c_I)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_I)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_I.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_I, Ul_BFu0c_I)
//============================================================================



static void Test_Ul_BFu0c_Ip()
{
  {
    init_simple_test("Ul_BFu0c_Ip");
    static STRUCT_IF_C Ul_BFu0c_Ip lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu0c_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_Ip)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_Ip.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_Ip, Ul_BFu0c_Ip)
//============================================================================



static void Test_Ul_BFu0c_L()
{
  {
    init_simple_test("Ul_BFu0c_L");
    static STRUCT_IF_C Ul_BFu0c_L lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0c_L)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_L)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_L.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_L, Ul_BFu0c_L)
//============================================================================



static void Test_Ul_BFu0c_S()
{
  {
    init_simple_test("Ul_BFu0c_S");
    static STRUCT_IF_C Ul_BFu0c_S lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_S)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_S)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_S.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_S, Ul_BFu0c_S)
//============================================================================



static void Test_Ul_BFu0c_Uc()
{
  {
    init_simple_test("Ul_BFu0c_Uc");
    static STRUCT_IF_C Ul_BFu0c_Uc lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu0c_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_Uc)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_Uc.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_Uc, Ul_BFu0c_Uc)
//============================================================================



static void Test_Ul_BFu0c_Ui()
{
  {
    init_simple_test("Ul_BFu0c_Ui");
    static STRUCT_IF_C Ul_BFu0c_Ui lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0c_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_Ui)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_Ui.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_Ui, Ul_BFu0c_Ui)
//============================================================================



static void Test_Ul_BFu0c_Ul()
{
  {
    init_simple_test("Ul_BFu0c_Ul");
    static STRUCT_IF_C Ul_BFu0c_Ul lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0c_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_Ul)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_Ul.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_Ul, Ul_BFu0c_Ul)
//============================================================================



static void Test_Ul_BFu0c_Us()
{
  {
    init_simple_test("Ul_BFu0c_Us");
    static STRUCT_IF_C Ul_BFu0c_Us lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0c_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_Us)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_Us.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_Us, Ul_BFu0c_Us)
//============================================================================



static void Test_Ul_BFu0c_Vp()
{
  {
    init_simple_test("Ul_BFu0c_Vp");
    static STRUCT_IF_C Ul_BFu0c_Vp lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu0c_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu0c_Vp)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_Vp.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_Vp, Ul_BFu0c_Vp)
//============================================================================



static void Test_Ul_BFu0i()
{
  {
    init_simple_test("Ul_BFu0i");
    static STRUCT_IF_C Ul_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i, Ul_BFu0i)
//============================================================================



static void Test_Ul_BFu0i_BFu0c()
{
  {
    init_simple_test("Ul_BFu0i_BFu0c");
    static STRUCT_IF_C Ul_BFu0i_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0i_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu0c, Ul_BFu0i_BFu0c)
//============================================================================



static void Test_Ul_BFu0i_BFu0i()
{
  {
    init_simple_test("Ul_BFu0i_BFu0i");
    static STRUCT_IF_C Ul_BFu0i_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu0i, Ul_BFu0i_BFu0i)
//============================================================================



static void Test_Ul_BFu0i_BFu0ll()
{
  {
    init_simple_test("Ul_BFu0i_BFu0ll");
    static STRUCT_IF_C Ul_BFu0i_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu0ll, Ul_BFu0i_BFu0ll)
//============================================================================



static void Test_Ul_BFu0i_BFu0s()
{
  {
    init_simple_test("Ul_BFu0i_BFu0s");
    static STRUCT_IF_C Ul_BFu0i_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu0s, Ul_BFu0i_BFu0s)
//============================================================================



static void Test_Ul_BFu0i_BFu15i()
{
  {
    init_simple_test("Ul_BFu0i_BFu15i");
    static STRUCT_IF_C Ul_BFu0i_BFu15i lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_BFu15i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu15i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu15i.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0i_BFu15i");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0i_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu15i, Ul_BFu0i_BFu15i)
//============================================================================



static void Test_Ul_BFu0i_BFu15ll()
{
  {
    init_simple_test("Ul_BFu0i_BFu15ll");
    static STRUCT_IF_C Ul_BFu0i_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu15ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu15ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0i_BFu15ll");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0i_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu15ll, Ul_BFu0i_BFu15ll)
//============================================================================



static void Test_Ul_BFu0i_BFu15s()
{
  {
    init_simple_test("Ul_BFu0i_BFu15s");
    static STRUCT_IF_C Ul_BFu0i_BFu15s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_BFu15s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu15s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu15s.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0i_BFu15s");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0i_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu15s, Ul_BFu0i_BFu15s)
//============================================================================



static void Test_Ul_BFu0i_BFu16i()
{
  {
    init_simple_test("Ul_BFu0i_BFu16i");
    static STRUCT_IF_C Ul_BFu0i_BFu16i lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_BFu16i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu16i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu16i.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0i_BFu16i");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0i_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu16i, Ul_BFu0i_BFu16i)
//============================================================================



static void Test_Ul_BFu0i_BFu16ll()
{
  {
    init_simple_test("Ul_BFu0i_BFu16ll");
    static STRUCT_IF_C Ul_BFu0i_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu16ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu16ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0i_BFu16ll");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0i_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu16ll, Ul_BFu0i_BFu16ll)
//============================================================================



static void Test_Ul_BFu0i_BFu16s()
{
  {
    init_simple_test("Ul_BFu0i_BFu16s");
    static STRUCT_IF_C Ul_BFu0i_BFu16s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_BFu16s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu16s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu16s.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0i_BFu16s");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0i_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu16s, Ul_BFu0i_BFu16s)
//============================================================================



static void Test_Ul_BFu0i_BFu17i()
{
  {
    init_simple_test("Ul_BFu0i_BFu17i");
    static STRUCT_IF_C Ul_BFu0i_BFu17i lv;
    check2(sizeof(lv), ABISELECT(11,11), "sizeof(Ul_BFu0i_BFu17i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu17i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu17i.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu0i_BFu17i");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu0i_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu17i, Ul_BFu0i_BFu17i)
//============================================================================



static void Test_Ul_BFu0i_BFu17ll()
{
  {
    init_simple_test("Ul_BFu0i_BFu17ll");
    static STRUCT_IF_C Ul_BFu0i_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(11,11), "sizeof(Ul_BFu0i_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu17ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu17ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu0i_BFu17ll");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu0i_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu17ll, Ul_BFu0i_BFu17ll)
//============================================================================



static void Test_Ul_BFu0i_BFu1c()
{
  {
    init_simple_test("Ul_BFu0i_BFu1c");
    static STRUCT_IF_C Ul_BFu0i_BFu1c lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu1c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu1c.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0i_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu1c, Ul_BFu0i_BFu1c)
//============================================================================



static void Test_Ul_BFu0i_BFu1i()
{
  {
    init_simple_test("Ul_BFu0i_BFu1i");
    static STRUCT_IF_C Ul_BFu0i_BFu1i lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu1i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu1i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu1i.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0i_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu1i, Ul_BFu0i_BFu1i)
//============================================================================



static void Test_Ul_BFu0i_BFu1ll()
{
  {
    init_simple_test("Ul_BFu0i_BFu1ll");
    static STRUCT_IF_C Ul_BFu0i_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu1ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu1ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0i_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu1ll, Ul_BFu0i_BFu1ll)
//============================================================================



static void Test_Ul_BFu0i_BFu1s()
{
  {
    init_simple_test("Ul_BFu0i_BFu1s");
    static STRUCT_IF_C Ul_BFu0i_BFu1s lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu1s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu1s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu1s.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0i_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu1s, Ul_BFu0i_BFu1s)
//============================================================================



static void Test_Ul_BFu0i_BFu31i()
{
  {
    init_simple_test("Ul_BFu0i_BFu31i");
    static STRUCT_IF_C Ul_BFu0i_BFu31i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0i_BFu31i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu31i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu31i.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu0i_BFu31i");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu0i_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu31i, Ul_BFu0i_BFu31i)
//============================================================================



static void Test_Ul_BFu0i_BFu31ll()
{
  {
    init_simple_test("Ul_BFu0i_BFu31ll");
    static STRUCT_IF_C Ul_BFu0i_BFu31ll lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0i_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu31ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu31ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu0i_BFu31ll");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu0i_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu31ll, Ul_BFu0i_BFu31ll)
//============================================================================



static void Test_Ul_BFu0i_BFu32i()
{
  {
    init_simple_test("Ul_BFu0i_BFu32i");
    static STRUCT_IF_C Ul_BFu0i_BFu32i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0i_BFu32i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu32i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu32i.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu0i_BFu32i");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu0i_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu32i, Ul_BFu0i_BFu32i)
//============================================================================



static void Test_Ul_BFu0i_BFu32ll()
{
  {
    init_simple_test("Ul_BFu0i_BFu32ll");
    static STRUCT_IF_C Ul_BFu0i_BFu32ll lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0i_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu32ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu32ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu0i_BFu32ll");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu0i_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu32ll, Ul_BFu0i_BFu32ll)
//============================================================================



static void Test_Ul_BFu0i_BFu33()
{
  {
    init_simple_test("Ul_BFu0i_BFu33");
    static STRUCT_IF_C Ul_BFu0i_BFu33 lv;
    check2(sizeof(lv), ABISELECT(13,13), "sizeof(Ul_BFu0i_BFu33)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu33)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu33.v1");
    set_bf_and_test(lv, v2, 8, 0, 33, 1, "Ul_BFu0i_BFu33");
    set_bf_and_test(lv, v2, 8, 0, 33, hide_ull(1LL<<32), "Ul_BFu0i_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu33, Ul_BFu0i_BFu33)
//============================================================================



static void Test_Ul_BFu0i_BFu7c()
{
  {
    init_simple_test("Ul_BFu0i_BFu7c");
    static STRUCT_IF_C Ul_BFu0i_BFu7c lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu7c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu7c.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0i_BFu7c");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0i_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu7c, Ul_BFu0i_BFu7c)
//============================================================================



static void Test_Ul_BFu0i_BFu7i()
{
  {
    init_simple_test("Ul_BFu0i_BFu7i");
    static STRUCT_IF_C Ul_BFu0i_BFu7i lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu7i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu7i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu7i.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0i_BFu7i");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0i_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu7i, Ul_BFu0i_BFu7i)
//============================================================================



static void Test_Ul_BFu0i_BFu7ll()
{
  {
    init_simple_test("Ul_BFu0i_BFu7ll");
    static STRUCT_IF_C Ul_BFu0i_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu7ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu7ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0i_BFu7ll");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0i_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu7ll, Ul_BFu0i_BFu7ll)
//============================================================================



static void Test_Ul_BFu0i_BFu7s()
{
  {
    init_simple_test("Ul_BFu0i_BFu7s");
    static STRUCT_IF_C Ul_BFu0i_BFu7s lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu7s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu7s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu7s.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0i_BFu7s");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0i_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu7s, Ul_BFu0i_BFu7s)
//============================================================================



static void Test_Ul_BFu0i_BFu8c()
{
  {
    init_simple_test("Ul_BFu0i_BFu8c");
    static STRUCT_IF_C Ul_BFu0i_BFu8c lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu8c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu8c.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0i_BFu8c");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0i_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu8c, Ul_BFu0i_BFu8c)
//============================================================================



static void Test_Ul_BFu0i_BFu8i()
{
  {
    init_simple_test("Ul_BFu0i_BFu8i");
    static STRUCT_IF_C Ul_BFu0i_BFu8i lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu8i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu8i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu8i.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0i_BFu8i");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0i_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu8i, Ul_BFu0i_BFu8i)
//============================================================================



static void Test_Ul_BFu0i_BFu8ll()
{
  {
    init_simple_test("Ul_BFu0i_BFu8ll");
    static STRUCT_IF_C Ul_BFu0i_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu8ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu8ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0i_BFu8ll");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0i_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu8ll, Ul_BFu0i_BFu8ll)
//============================================================================



static void Test_Ul_BFu0i_BFu8s()
{
  {
    init_simple_test("Ul_BFu0i_BFu8s");
    static STRUCT_IF_C Ul_BFu0i_BFu8s lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_BFu8s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu8s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu8s.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0i_BFu8s");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0i_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu8s, Ul_BFu0i_BFu8s)
//============================================================================



static void Test_Ul_BFu0i_BFu9i()
{
  {
    init_simple_test("Ul_BFu0i_BFu9i");
    static STRUCT_IF_C Ul_BFu0i_BFu9i lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_BFu9i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu9i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu9i.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0i_BFu9i");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0i_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu9i, Ul_BFu0i_BFu9i)
//============================================================================



static void Test_Ul_BFu0i_BFu9ll()
{
  {
    init_simple_test("Ul_BFu0i_BFu9ll");
    static STRUCT_IF_C Ul_BFu0i_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu9ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu9ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0i_BFu9ll");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0i_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu9ll, Ul_BFu0i_BFu9ll)
//============================================================================



static void Test_Ul_BFu0i_BFu9s()
{
  {
    init_simple_test("Ul_BFu0i_BFu9s");
    static STRUCT_IF_C Ul_BFu0i_BFu9s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_BFu9s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_BFu9s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_BFu9s.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0i_BFu9s");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0i_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_BFu9s, Ul_BFu0i_BFu9s)
//============================================================================



static void Test_Ul_BFu0i_C()
{
  {
    init_simple_test("Ul_BFu0i_C");
    static STRUCT_IF_C Ul_BFu0i_C lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_C)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_C.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_C, Ul_BFu0i_C)
//============================================================================



static void Test_Ul_BFu0i_D()
{
  {
    init_simple_test("Ul_BFu0i_D");
    static STRUCT_IF_C Ul_BFu0i_D lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0i_D)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_D)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_D.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_D, Ul_BFu0i_D)
//============================================================================



static void Test_Ul_BFu0i_F()
{
  {
    init_simple_test("Ul_BFu0i_F");
    static STRUCT_IF_C Ul_BFu0i_F lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0i_F)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_F)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_F.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_F, Ul_BFu0i_F)
//============================================================================



static void Test_Ul_BFu0i_I()
{
  {
    init_simple_test("Ul_BFu0i_I");
    static STRUCT_IF_C Ul_BFu0i_I lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0i_I)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_I)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_I.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_I, Ul_BFu0i_I)
//============================================================================



static void Test_Ul_BFu0i_Ip()
{
  {
    init_simple_test("Ul_BFu0i_Ip");
    static STRUCT_IF_C Ul_BFu0i_Ip lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu0i_Ip)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_Ip)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_Ip.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_Ip, Ul_BFu0i_Ip)
//============================================================================



static void Test_Ul_BFu0i_L()
{
  {
    init_simple_test("Ul_BFu0i_L");
    static STRUCT_IF_C Ul_BFu0i_L lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0i_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_L)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_L.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_L, Ul_BFu0i_L)
//============================================================================



static void Test_Ul_BFu0i_S()
{
  {
    init_simple_test("Ul_BFu0i_S");
    static STRUCT_IF_C Ul_BFu0i_S lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_S)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_S.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_S, Ul_BFu0i_S)
//============================================================================



static void Test_Ul_BFu0i_Uc()
{
  {
    init_simple_test("Ul_BFu0i_Uc");
    static STRUCT_IF_C Ul_BFu0i_Uc lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0i_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_Uc)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_Uc.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_Uc, Ul_BFu0i_Uc)
//============================================================================



static void Test_Ul_BFu0i_Ui()
{
  {
    init_simple_test("Ul_BFu0i_Ui");
    static STRUCT_IF_C Ul_BFu0i_Ui lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0i_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_Ui)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_Ui.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_Ui, Ul_BFu0i_Ui)
//============================================================================



static void Test_Ul_BFu0i_Ul()
{
  {
    init_simple_test("Ul_BFu0i_Ul");
    static STRUCT_IF_C Ul_BFu0i_Ul lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0i_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_Ul)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_Ul.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_Ul, Ul_BFu0i_Ul)
//============================================================================



static void Test_Ul_BFu0i_Us()
{
  {
    init_simple_test("Ul_BFu0i_Us");
    static STRUCT_IF_C Ul_BFu0i_Us lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0i_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_Us)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_Us.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_Us, Ul_BFu0i_Us)
//============================================================================



static void Test_Ul_BFu0i_Vp()
{
  {
    init_simple_test("Ul_BFu0i_Vp");
    static STRUCT_IF_C Ul_BFu0i_Vp lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu0i_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0i_Vp)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_Vp.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_Vp, Ul_BFu0i_Vp)
//============================================================================



static void Test_Ul_BFu0ll()
{
  {
    init_simple_test("Ul_BFu0ll");
    static STRUCT_IF_C Ul_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll, Ul_BFu0ll)
//============================================================================



static void Test_Ul_BFu0ll_BFu0c()
{
  {
    init_simple_test("Ul_BFu0ll_BFu0c");
    static STRUCT_IF_C Ul_BFu0ll_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu0c, Ul_BFu0ll_BFu0c)
//============================================================================



static void Test_Ul_BFu0ll_BFu0i()
{
  {
    init_simple_test("Ul_BFu0ll_BFu0i");
    static STRUCT_IF_C Ul_BFu0ll_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu0i, Ul_BFu0ll_BFu0i)
//============================================================================



static void Test_Ul_BFu0ll_BFu0ll()
{
  {
    init_simple_test("Ul_BFu0ll_BFu0ll");
    static STRUCT_IF_C Ul_BFu0ll_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu0ll, Ul_BFu0ll_BFu0ll)
//============================================================================



static void Test_Ul_BFu0ll_BFu0s()
{
  {
    init_simple_test("Ul_BFu0ll_BFu0s");
    static STRUCT_IF_C Ul_BFu0ll_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu0s, Ul_BFu0ll_BFu0s)
//============================================================================



static void Test_Ul_BFu0ll_BFu15i()
{
  {
    init_simple_test("Ul_BFu0ll_BFu15i");
    static STRUCT_IF_C Ul_BFu0ll_BFu15i lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_BFu15i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu15i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu15i.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0ll_BFu15i");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0ll_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu15i, Ul_BFu0ll_BFu15i)
//============================================================================



static void Test_Ul_BFu0ll_BFu15ll()
{
  {
    init_simple_test("Ul_BFu0ll_BFu15ll");
    static STRUCT_IF_C Ul_BFu0ll_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu15ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu15ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0ll_BFu15ll");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0ll_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu15ll, Ul_BFu0ll_BFu15ll)
//============================================================================



static void Test_Ul_BFu0ll_BFu15s()
{
  {
    init_simple_test("Ul_BFu0ll_BFu15s");
    static STRUCT_IF_C Ul_BFu0ll_BFu15s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_BFu15s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu15s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu15s.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0ll_BFu15s");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0ll_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu15s, Ul_BFu0ll_BFu15s)
//============================================================================



static void Test_Ul_BFu0ll_BFu16i()
{
  {
    init_simple_test("Ul_BFu0ll_BFu16i");
    static STRUCT_IF_C Ul_BFu0ll_BFu16i lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_BFu16i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu16i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu16i.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0ll_BFu16i");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0ll_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu16i, Ul_BFu0ll_BFu16i)
//============================================================================



static void Test_Ul_BFu0ll_BFu16ll()
{
  {
    init_simple_test("Ul_BFu0ll_BFu16ll");
    static STRUCT_IF_C Ul_BFu0ll_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu16ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu16ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0ll_BFu16ll");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0ll_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu16ll, Ul_BFu0ll_BFu16ll)
//============================================================================



static void Test_Ul_BFu0ll_BFu16s()
{
  {
    init_simple_test("Ul_BFu0ll_BFu16s");
    static STRUCT_IF_C Ul_BFu0ll_BFu16s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_BFu16s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu16s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu16s.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0ll_BFu16s");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0ll_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu16s, Ul_BFu0ll_BFu16s)
//============================================================================



static void Test_Ul_BFu0ll_BFu17i()
{
  {
    init_simple_test("Ul_BFu0ll_BFu17i");
    static STRUCT_IF_C Ul_BFu0ll_BFu17i lv;
    check2(sizeof(lv), ABISELECT(11,11), "sizeof(Ul_BFu0ll_BFu17i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu17i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu17i.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu0ll_BFu17i");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu0ll_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu17i, Ul_BFu0ll_BFu17i)
//============================================================================



static void Test_Ul_BFu0ll_BFu17ll()
{
  {
    init_simple_test("Ul_BFu0ll_BFu17ll");
    static STRUCT_IF_C Ul_BFu0ll_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(11,11), "sizeof(Ul_BFu0ll_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu17ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu17ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu0ll_BFu17ll");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu0ll_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu17ll, Ul_BFu0ll_BFu17ll)
//============================================================================



static void Test_Ul_BFu0ll_BFu1c()
{
  {
    init_simple_test("Ul_BFu0ll_BFu1c");
    static STRUCT_IF_C Ul_BFu0ll_BFu1c lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu1c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu1c.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0ll_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu1c, Ul_BFu0ll_BFu1c)
//============================================================================



static void Test_Ul_BFu0ll_BFu1i()
{
  {
    init_simple_test("Ul_BFu0ll_BFu1i");
    static STRUCT_IF_C Ul_BFu0ll_BFu1i lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu1i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu1i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu1i.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0ll_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu1i, Ul_BFu0ll_BFu1i)
//============================================================================



static void Test_Ul_BFu0ll_BFu1ll()
{
  {
    init_simple_test("Ul_BFu0ll_BFu1ll");
    static STRUCT_IF_C Ul_BFu0ll_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu1ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu1ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0ll_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu1ll, Ul_BFu0ll_BFu1ll)
//============================================================================



static void Test_Ul_BFu0ll_BFu1s()
{
  {
    init_simple_test("Ul_BFu0ll_BFu1s");
    static STRUCT_IF_C Ul_BFu0ll_BFu1s lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu1s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu1s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu1s.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0ll_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu1s, Ul_BFu0ll_BFu1s)
//============================================================================



static void Test_Ul_BFu0ll_BFu31i()
{
  {
    init_simple_test("Ul_BFu0ll_BFu31i");
    static STRUCT_IF_C Ul_BFu0ll_BFu31i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu0ll_BFu31i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu31i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu31i.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu0ll_BFu31i");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu0ll_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu31i, Ul_BFu0ll_BFu31i)
//============================================================================



static void Test_Ul_BFu0ll_BFu31ll()
{
  {
    init_simple_test("Ul_BFu0ll_BFu31ll");
    static STRUCT_IF_C Ul_BFu0ll_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu0ll_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu31ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu31ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu0ll_BFu31ll");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu0ll_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu31ll, Ul_BFu0ll_BFu31ll)
//============================================================================



static void Test_Ul_BFu0ll_BFu32i()
{
  {
    init_simple_test("Ul_BFu0ll_BFu32i");
    static STRUCT_IF_C Ul_BFu0ll_BFu32i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu0ll_BFu32i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu32i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu32i.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu0ll_BFu32i");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu0ll_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu32i, Ul_BFu0ll_BFu32i)
//============================================================================



static void Test_Ul_BFu0ll_BFu32ll()
{
  {
    init_simple_test("Ul_BFu0ll_BFu32ll");
    static STRUCT_IF_C Ul_BFu0ll_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu0ll_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu32ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu32ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu0ll_BFu32ll");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu0ll_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu32ll, Ul_BFu0ll_BFu32ll)
//============================================================================



static void Test_Ul_BFu0ll_BFu33()
{
  {
    init_simple_test("Ul_BFu0ll_BFu33");
    static STRUCT_IF_C Ul_BFu0ll_BFu33 lv;
    check2(sizeof(lv), ABISELECT(13,13), "sizeof(Ul_BFu0ll_BFu33)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu33)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu33.v1");
    set_bf_and_test(lv, v2, 8, 0, 33, 1, "Ul_BFu0ll_BFu33");
    set_bf_and_test(lv, v2, 8, 0, 33, hide_ull(1LL<<32), "Ul_BFu0ll_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu33, Ul_BFu0ll_BFu33)
//============================================================================



static void Test_Ul_BFu0ll_BFu7c()
{
  {
    init_simple_test("Ul_BFu0ll_BFu7c");
    static STRUCT_IF_C Ul_BFu0ll_BFu7c lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu7c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu7c.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0ll_BFu7c");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0ll_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu7c, Ul_BFu0ll_BFu7c)
//============================================================================



static void Test_Ul_BFu0ll_BFu7i()
{
  {
    init_simple_test("Ul_BFu0ll_BFu7i");
    static STRUCT_IF_C Ul_BFu0ll_BFu7i lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu7i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu7i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu7i.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0ll_BFu7i");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0ll_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu7i, Ul_BFu0ll_BFu7i)
//============================================================================



static void Test_Ul_BFu0ll_BFu7ll()
{
  {
    init_simple_test("Ul_BFu0ll_BFu7ll");
    static STRUCT_IF_C Ul_BFu0ll_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu7ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu7ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0ll_BFu7ll");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0ll_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu7ll, Ul_BFu0ll_BFu7ll)
//============================================================================



static void Test_Ul_BFu0ll_BFu7s()
{
  {
    init_simple_test("Ul_BFu0ll_BFu7s");
    static STRUCT_IF_C Ul_BFu0ll_BFu7s lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu7s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu7s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu7s.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0ll_BFu7s");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0ll_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu7s, Ul_BFu0ll_BFu7s)
//============================================================================



static void Test_Ul_BFu0ll_BFu8c()
{
  {
    init_simple_test("Ul_BFu0ll_BFu8c");
    static STRUCT_IF_C Ul_BFu0ll_BFu8c lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu8c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu8c.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0ll_BFu8c");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0ll_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu8c, Ul_BFu0ll_BFu8c)
//============================================================================



static void Test_Ul_BFu0ll_BFu8i()
{
  {
    init_simple_test("Ul_BFu0ll_BFu8i");
    static STRUCT_IF_C Ul_BFu0ll_BFu8i lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu8i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu8i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu8i.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0ll_BFu8i");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0ll_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu8i, Ul_BFu0ll_BFu8i)
//============================================================================



static void Test_Ul_BFu0ll_BFu8ll()
{
  {
    init_simple_test("Ul_BFu0ll_BFu8ll");
    static STRUCT_IF_C Ul_BFu0ll_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu8ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu8ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0ll_BFu8ll");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0ll_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu8ll, Ul_BFu0ll_BFu8ll)
//============================================================================



static void Test_Ul_BFu0ll_BFu8s()
{
  {
    init_simple_test("Ul_BFu0ll_BFu8s");
    static STRUCT_IF_C Ul_BFu0ll_BFu8s lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_BFu8s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu8s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu8s.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0ll_BFu8s");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0ll_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu8s, Ul_BFu0ll_BFu8s)
//============================================================================



static void Test_Ul_BFu0ll_BFu9i()
{
  {
    init_simple_test("Ul_BFu0ll_BFu9i");
    static STRUCT_IF_C Ul_BFu0ll_BFu9i lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_BFu9i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu9i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu9i.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0ll_BFu9i");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0ll_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu9i, Ul_BFu0ll_BFu9i)
//============================================================================



static void Test_Ul_BFu0ll_BFu9ll()
{
  {
    init_simple_test("Ul_BFu0ll_BFu9ll");
    static STRUCT_IF_C Ul_BFu0ll_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu9ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu9ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0ll_BFu9ll");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0ll_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu9ll, Ul_BFu0ll_BFu9ll)
//============================================================================



static void Test_Ul_BFu0ll_BFu9s()
{
  {
    init_simple_test("Ul_BFu0ll_BFu9s");
    static STRUCT_IF_C Ul_BFu0ll_BFu9s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_BFu9s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_BFu9s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_BFu9s.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0ll_BFu9s");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0ll_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_BFu9s, Ul_BFu0ll_BFu9s)
//============================================================================



static void Test_Ul_BFu0ll_C()
{
  {
    init_simple_test("Ul_BFu0ll_C");
    static STRUCT_IF_C Ul_BFu0ll_C lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_C)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_C.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_C, Ul_BFu0ll_C)
//============================================================================



static void Test_Ul_BFu0ll_D()
{
  {
    init_simple_test("Ul_BFu0ll_D");
    static STRUCT_IF_C Ul_BFu0ll_D lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0ll_D)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_D)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_D.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_D, Ul_BFu0ll_D)
//============================================================================



static void Test_Ul_BFu0ll_F()
{
  {
    init_simple_test("Ul_BFu0ll_F");
    static STRUCT_IF_C Ul_BFu0ll_F lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu0ll_F)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_F)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_F.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_F, Ul_BFu0ll_F)
//============================================================================



static void Test_Ul_BFu0ll_I()
{
  {
    init_simple_test("Ul_BFu0ll_I");
    static STRUCT_IF_C Ul_BFu0ll_I lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu0ll_I)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_I)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_I.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_I, Ul_BFu0ll_I)
//============================================================================



static void Test_Ul_BFu0ll_Ip()
{
  {
    init_simple_test("Ul_BFu0ll_Ip");
    static STRUCT_IF_C Ul_BFu0ll_Ip lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu0ll_Ip)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_Ip)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_Ip.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_Ip, Ul_BFu0ll_Ip)
//============================================================================



static void Test_Ul_BFu0ll_L()
{
  {
    init_simple_test("Ul_BFu0ll_L");
    static STRUCT_IF_C Ul_BFu0ll_L lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0ll_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_L)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_L.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_L, Ul_BFu0ll_L)
//============================================================================



static void Test_Ul_BFu0ll_S()
{
  {
    init_simple_test("Ul_BFu0ll_S");
    static STRUCT_IF_C Ul_BFu0ll_S lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_S)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_S.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_S, Ul_BFu0ll_S)
//============================================================================



static void Test_Ul_BFu0ll_Uc()
{
  {
    init_simple_test("Ul_BFu0ll_Uc");
    static STRUCT_IF_C Ul_BFu0ll_Uc lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0ll_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_Uc)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_Uc.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_Uc, Ul_BFu0ll_Uc)
//============================================================================



static void Test_Ul_BFu0ll_Ui()
{
  {
    init_simple_test("Ul_BFu0ll_Ui");
    static STRUCT_IF_C Ul_BFu0ll_Ui lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu0ll_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_Ui)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_Ui.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_Ui, Ul_BFu0ll_Ui)
//============================================================================



static void Test_Ul_BFu0ll_Ul()
{
  {
    init_simple_test("Ul_BFu0ll_Ul");
    static STRUCT_IF_C Ul_BFu0ll_Ul lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0ll_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_Ul)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_Ul.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_Ul, Ul_BFu0ll_Ul)
//============================================================================



static void Test_Ul_BFu0ll_Us()
{
  {
    init_simple_test("Ul_BFu0ll_Us");
    static STRUCT_IF_C Ul_BFu0ll_Us lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu0ll_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_Us)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_Us.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_Us, Ul_BFu0ll_Us)
//============================================================================



static void Test_Ul_BFu0ll_Vp()
{
  {
    init_simple_test("Ul_BFu0ll_Vp");
    static STRUCT_IF_C Ul_BFu0ll_Vp lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu0ll_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0ll_Vp)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_Vp.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_Vp, Ul_BFu0ll_Vp)
//============================================================================



static void Test_Ul_BFu0s()
{
  {
    init_simple_test("Ul_BFu0s");
    static STRUCT_IF_C Ul_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s, Ul_BFu0s)
//============================================================================



static void Test_Ul_BFu0s_BFu0c()
{
  {
    init_simple_test("Ul_BFu0s_BFu0c");
    static STRUCT_IF_C Ul_BFu0s_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0s_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu0c, Ul_BFu0s_BFu0c)
//============================================================================



static void Test_Ul_BFu0s_BFu0i()
{
  {
    init_simple_test("Ul_BFu0s_BFu0i");
    static STRUCT_IF_C Ul_BFu0s_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu0i, Ul_BFu0s_BFu0i)
//============================================================================



static void Test_Ul_BFu0s_BFu0ll()
{
  {
    init_simple_test("Ul_BFu0s_BFu0ll");
    static STRUCT_IF_C Ul_BFu0s_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu0ll, Ul_BFu0s_BFu0ll)
//============================================================================



static void Test_Ul_BFu0s_BFu0s()
{
  {
    init_simple_test("Ul_BFu0s_BFu0s");
    static STRUCT_IF_C Ul_BFu0s_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu0s, Ul_BFu0s_BFu0s)
//============================================================================



static void Test_Ul_BFu0s_BFu15i()
{
  {
    init_simple_test("Ul_BFu0s_BFu15i");
    static STRUCT_IF_C Ul_BFu0s_BFu15i lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_BFu15i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu15i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu15i.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0s_BFu15i");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0s_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu15i, Ul_BFu0s_BFu15i)
//============================================================================



static void Test_Ul_BFu0s_BFu15ll()
{
  {
    init_simple_test("Ul_BFu0s_BFu15ll");
    static STRUCT_IF_C Ul_BFu0s_BFu15ll lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu15ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu15ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0s_BFu15ll");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0s_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu15ll, Ul_BFu0s_BFu15ll)
//============================================================================



static void Test_Ul_BFu0s_BFu15s()
{
  {
    init_simple_test("Ul_BFu0s_BFu15s");
    static STRUCT_IF_C Ul_BFu0s_BFu15s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_BFu15s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu15s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu15s.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu0s_BFu15s");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu0s_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu15s, Ul_BFu0s_BFu15s)
//============================================================================



static void Test_Ul_BFu0s_BFu16i()
{
  {
    init_simple_test("Ul_BFu0s_BFu16i");
    static STRUCT_IF_C Ul_BFu0s_BFu16i lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_BFu16i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu16i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu16i.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0s_BFu16i");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0s_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu16i, Ul_BFu0s_BFu16i)
//============================================================================



static void Test_Ul_BFu0s_BFu16ll()
{
  {
    init_simple_test("Ul_BFu0s_BFu16ll");
    static STRUCT_IF_C Ul_BFu0s_BFu16ll lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu16ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu16ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0s_BFu16ll");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0s_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu16ll, Ul_BFu0s_BFu16ll)
//============================================================================



static void Test_Ul_BFu0s_BFu16s()
{
  {
    init_simple_test("Ul_BFu0s_BFu16s");
    static STRUCT_IF_C Ul_BFu0s_BFu16s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_BFu16s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu16s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu16s.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu0s_BFu16s");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu0s_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu16s, Ul_BFu0s_BFu16s)
//============================================================================



static void Test_Ul_BFu0s_BFu17i()
{
  {
    init_simple_test("Ul_BFu0s_BFu17i");
    static STRUCT_IF_C Ul_BFu0s_BFu17i lv;
    check2(sizeof(lv), ABISELECT(11,11), "sizeof(Ul_BFu0s_BFu17i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu17i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu17i.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu0s_BFu17i");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu0s_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu17i, Ul_BFu0s_BFu17i)
//============================================================================



static void Test_Ul_BFu0s_BFu17ll()
{
  {
    init_simple_test("Ul_BFu0s_BFu17ll");
    static STRUCT_IF_C Ul_BFu0s_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(11,11), "sizeof(Ul_BFu0s_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu17ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu17ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu0s_BFu17ll");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu0s_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu17ll, Ul_BFu0s_BFu17ll)
//============================================================================



static void Test_Ul_BFu0s_BFu1c()
{
  {
    init_simple_test("Ul_BFu0s_BFu1c");
    static STRUCT_IF_C Ul_BFu0s_BFu1c lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu1c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu1c.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0s_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu1c, Ul_BFu0s_BFu1c)
//============================================================================



static void Test_Ul_BFu0s_BFu1i()
{
  {
    init_simple_test("Ul_BFu0s_BFu1i");
    static STRUCT_IF_C Ul_BFu0s_BFu1i lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu1i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu1i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu1i.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0s_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu1i, Ul_BFu0s_BFu1i)
//============================================================================



static void Test_Ul_BFu0s_BFu1ll()
{
  {
    init_simple_test("Ul_BFu0s_BFu1ll");
    static STRUCT_IF_C Ul_BFu0s_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu1ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu1ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0s_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu1ll, Ul_BFu0s_BFu1ll)
//============================================================================



static void Test_Ul_BFu0s_BFu1s()
{
  {
    init_simple_test("Ul_BFu0s_BFu1s");
    static STRUCT_IF_C Ul_BFu0s_BFu1s lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu1s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu1s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu1s.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu0s_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu1s, Ul_BFu0s_BFu1s)
//============================================================================



static void Test_Ul_BFu0s_BFu31i()
{
  {
    init_simple_test("Ul_BFu0s_BFu31i");
    static STRUCT_IF_C Ul_BFu0s_BFu31i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0s_BFu31i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu31i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu31i.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu0s_BFu31i");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu0s_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu31i, Ul_BFu0s_BFu31i)
//============================================================================



static void Test_Ul_BFu0s_BFu31ll()
{
  {
    init_simple_test("Ul_BFu0s_BFu31ll");
    static STRUCT_IF_C Ul_BFu0s_BFu31ll lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0s_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu31ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu31ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu0s_BFu31ll");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu0s_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu31ll, Ul_BFu0s_BFu31ll)
//============================================================================



static void Test_Ul_BFu0s_BFu32i()
{
  {
    init_simple_test("Ul_BFu0s_BFu32i");
    static STRUCT_IF_C Ul_BFu0s_BFu32i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0s_BFu32i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu32i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu32i.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu0s_BFu32i");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu0s_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu32i, Ul_BFu0s_BFu32i)
//============================================================================



static void Test_Ul_BFu0s_BFu32ll()
{
  {
    init_simple_test("Ul_BFu0s_BFu32ll");
    static STRUCT_IF_C Ul_BFu0s_BFu32ll lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0s_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu32ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu32ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu0s_BFu32ll");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu0s_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu32ll, Ul_BFu0s_BFu32ll)
//============================================================================



static void Test_Ul_BFu0s_BFu33()
{
  {
    init_simple_test("Ul_BFu0s_BFu33");
    static STRUCT_IF_C Ul_BFu0s_BFu33 lv;
    check2(sizeof(lv), ABISELECT(13,13), "sizeof(Ul_BFu0s_BFu33)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu33)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu33.v1");
    set_bf_and_test(lv, v2, 8, 0, 33, 1, "Ul_BFu0s_BFu33");
    set_bf_and_test(lv, v2, 8, 0, 33, hide_ull(1LL<<32), "Ul_BFu0s_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu33, Ul_BFu0s_BFu33)
//============================================================================



static void Test_Ul_BFu0s_BFu7c()
{
  {
    init_simple_test("Ul_BFu0s_BFu7c");
    static STRUCT_IF_C Ul_BFu0s_BFu7c lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu7c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu7c.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0s_BFu7c");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0s_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu7c, Ul_BFu0s_BFu7c)
//============================================================================



static void Test_Ul_BFu0s_BFu7i()
{
  {
    init_simple_test("Ul_BFu0s_BFu7i");
    static STRUCT_IF_C Ul_BFu0s_BFu7i lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu7i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu7i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu7i.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0s_BFu7i");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0s_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu7i, Ul_BFu0s_BFu7i)
//============================================================================



static void Test_Ul_BFu0s_BFu7ll()
{
  {
    init_simple_test("Ul_BFu0s_BFu7ll");
    static STRUCT_IF_C Ul_BFu0s_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu7ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu7ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0s_BFu7ll");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0s_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu7ll, Ul_BFu0s_BFu7ll)
//============================================================================



static void Test_Ul_BFu0s_BFu7s()
{
  {
    init_simple_test("Ul_BFu0s_BFu7s");
    static STRUCT_IF_C Ul_BFu0s_BFu7s lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu7s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu7s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu7s.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu0s_BFu7s");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu0s_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu7s, Ul_BFu0s_BFu7s)
//============================================================================



static void Test_Ul_BFu0s_BFu8c()
{
  {
    init_simple_test("Ul_BFu0s_BFu8c");
    static STRUCT_IF_C Ul_BFu0s_BFu8c lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu8c)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu8c.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0s_BFu8c");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0s_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu8c, Ul_BFu0s_BFu8c)
//============================================================================



static void Test_Ul_BFu0s_BFu8i()
{
  {
    init_simple_test("Ul_BFu0s_BFu8i");
    static STRUCT_IF_C Ul_BFu0s_BFu8i lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu8i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu8i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu8i.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0s_BFu8i");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0s_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu8i, Ul_BFu0s_BFu8i)
//============================================================================



static void Test_Ul_BFu0s_BFu8ll()
{
  {
    init_simple_test("Ul_BFu0s_BFu8ll");
    static STRUCT_IF_C Ul_BFu0s_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu8ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu8ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0s_BFu8ll");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0s_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu8ll, Ul_BFu0s_BFu8ll)
//============================================================================



static void Test_Ul_BFu0s_BFu8s()
{
  {
    init_simple_test("Ul_BFu0s_BFu8s");
    static STRUCT_IF_C Ul_BFu0s_BFu8s lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_BFu8s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu8s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu8s.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu0s_BFu8s");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu0s_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu8s, Ul_BFu0s_BFu8s)
//============================================================================



static void Test_Ul_BFu0s_BFu9i()
{
  {
    init_simple_test("Ul_BFu0s_BFu9i");
    static STRUCT_IF_C Ul_BFu0s_BFu9i lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_BFu9i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu9i)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu9i.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0s_BFu9i");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0s_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu9i, Ul_BFu0s_BFu9i)
//============================================================================



static void Test_Ul_BFu0s_BFu9ll()
{
  {
    init_simple_test("Ul_BFu0s_BFu9ll");
    static STRUCT_IF_C Ul_BFu0s_BFu9ll lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu9ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu9ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0s_BFu9ll");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0s_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu9ll, Ul_BFu0s_BFu9ll)
//============================================================================



static void Test_Ul_BFu0s_BFu9s()
{
  {
    init_simple_test("Ul_BFu0s_BFu9s");
    static STRUCT_IF_C Ul_BFu0s_BFu9s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_BFu9s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_BFu9s)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_BFu9s.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu0s_BFu9s");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu0s_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_BFu9s, Ul_BFu0s_BFu9s)
//============================================================================



static void Test_Ul_BFu0s_C()
{
  {
    init_simple_test("Ul_BFu0s_C");
    static STRUCT_IF_C Ul_BFu0s_C lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_C)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_C.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_C, Ul_BFu0s_C)
//============================================================================



static void Test_Ul_BFu0s_D()
{
  {
    init_simple_test("Ul_BFu0s_D");
    static STRUCT_IF_C Ul_BFu0s_D lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0s_D)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_D)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_D.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_D, Ul_BFu0s_D)
//============================================================================



static void Test_Ul_BFu0s_F()
{
  {
    init_simple_test("Ul_BFu0s_F");
    static STRUCT_IF_C Ul_BFu0s_F lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0s_F)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_F)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_F.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_F, Ul_BFu0s_F)
//============================================================================



static void Test_Ul_BFu0s_I()
{
  {
    init_simple_test("Ul_BFu0s_I");
    static STRUCT_IF_C Ul_BFu0s_I lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0s_I)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_I)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_I.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_I, Ul_BFu0s_I)
//============================================================================



static void Test_Ul_BFu0s_Ip()
{
  {
    init_simple_test("Ul_BFu0s_Ip");
    static STRUCT_IF_C Ul_BFu0s_Ip lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu0s_Ip)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_Ip)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_Ip.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_Ip, Ul_BFu0s_Ip)
//============================================================================



static void Test_Ul_BFu0s_L()
{
  {
    init_simple_test("Ul_BFu0s_L");
    static STRUCT_IF_C Ul_BFu0s_L lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0s_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_L)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_L.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_L, Ul_BFu0s_L)
//============================================================================



static void Test_Ul_BFu0s_S()
{
  {
    init_simple_test("Ul_BFu0s_S");
    static STRUCT_IF_C Ul_BFu0s_S lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_S)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_S.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_S, Ul_BFu0s_S)
//============================================================================



static void Test_Ul_BFu0s_Uc()
{
  {
    init_simple_test("Ul_BFu0s_Uc");
    static STRUCT_IF_C Ul_BFu0s_Uc lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Ul_BFu0s_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_Uc)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_Uc.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_Uc, Ul_BFu0s_Uc)
//============================================================================



static void Test_Ul_BFu0s_Ui()
{
  {
    init_simple_test("Ul_BFu0s_Ui");
    static STRUCT_IF_C Ul_BFu0s_Ui lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu0s_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_Ui)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_Ui.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_Ui, Ul_BFu0s_Ui)
//============================================================================



static void Test_Ul_BFu0s_Ul()
{
  {
    init_simple_test("Ul_BFu0s_Ul");
    static STRUCT_IF_C Ul_BFu0s_Ul lv;
    check2(sizeof(lv), 16, "sizeof(Ul_BFu0s_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_Ul)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_Ul.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_Ul, Ul_BFu0s_Ul)
//============================================================================



static void Test_Ul_BFu0s_Us()
{
  {
    init_simple_test("Ul_BFu0s_Us");
    static STRUCT_IF_C Ul_BFu0s_Us lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu0s_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_Us)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_Us.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_Us, Ul_BFu0s_Us)
//============================================================================



static void Test_Ul_BFu0s_Vp()
{
  {
    init_simple_test("Ul_BFu0s_Vp");
    static STRUCT_IF_C Ul_BFu0s_Vp lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu0s_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu0s_Vp)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_Vp.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_Vp, Ul_BFu0s_Vp)
//============================================================================



static void Test_Ul_BFu15i_BFu0c()
{
  {
    init_simple_test("Ul_BFu15i_BFu0c");
    static STRUCT_IF_C Ul_BFu15i_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu15i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu15i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu15i_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15i_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu15i_BFu0c, Ul_BFu15i_BFu0c)
//============================================================================



static void Test_Ul_BFu15i_BFu0i()
{
  {
    init_simple_test("Ul_BFu15i_BFu0i");
    static STRUCT_IF_C Ul_BFu15i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu15i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu15i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu15i_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15i_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu15i_BFu0i, Ul_BFu15i_BFu0i)
//============================================================================



static void Test_Ul_BFu15i_BFu0ll()
{
  {
    init_simple_test("Ul_BFu15i_BFu0ll");
    static STRUCT_IF_C Ul_BFu15i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu15i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu15i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu15i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15i_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu15i_BFu0ll, Ul_BFu15i_BFu0ll)
//============================================================================



static void Test_Ul_BFu15i_BFu0s()
{
  {
    init_simple_test("Ul_BFu15i_BFu0s");
    static STRUCT_IF_C Ul_BFu15i_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu15i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu15i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu15i_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15i_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu15i_BFu0s, Ul_BFu15i_BFu0s)
//============================================================================



static void Test_Ul_BFu15ll_BFu0c()
{
  {
    init_simple_test("Ul_BFu15ll_BFu0c");
    static STRUCT_IF_C Ul_BFu15ll_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu15ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu15ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu15ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15ll_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu15ll_BFu0c, Ul_BFu15ll_BFu0c)
//============================================================================



static void Test_Ul_BFu15ll_BFu0i()
{
  {
    init_simple_test("Ul_BFu15ll_BFu0i");
    static STRUCT_IF_C Ul_BFu15ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu15ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu15ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu15ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15ll_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu15ll_BFu0i, Ul_BFu15ll_BFu0i)
//============================================================================



static void Test_Ul_BFu15ll_BFu0ll()
{
  {
    init_simple_test("Ul_BFu15ll_BFu0ll");
    static STRUCT_IF_C Ul_BFu15ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu15ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu15ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu15ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15ll_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu15ll_BFu0ll, Ul_BFu15ll_BFu0ll)
//============================================================================



static void Test_Ul_BFu15ll_BFu0s()
{
  {
    init_simple_test("Ul_BFu15ll_BFu0s");
    static STRUCT_IF_C Ul_BFu15ll_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu15ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu15ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu15ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15ll_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu15ll_BFu0s, Ul_BFu15ll_BFu0s)
//============================================================================



static void Test_Ul_BFu15s_BFu0c()
{
  {
    init_simple_test("Ul_BFu15s_BFu0c");
    static STRUCT_IF_C Ul_BFu15s_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu15s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu15s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu15s_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15s_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu15s_BFu0c, Ul_BFu15s_BFu0c)
//============================================================================



static void Test_Ul_BFu15s_BFu0i()
{
  {
    init_simple_test("Ul_BFu15s_BFu0i");
    static STRUCT_IF_C Ul_BFu15s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu15s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu15s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu15s_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15s_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu15s_BFu0i, Ul_BFu15s_BFu0i)
//============================================================================



static void Test_Ul_BFu15s_BFu0ll()
{
  {
    init_simple_test("Ul_BFu15s_BFu0ll");
    static STRUCT_IF_C Ul_BFu15s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu15s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu15s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu15s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15s_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu15s_BFu0ll, Ul_BFu15s_BFu0ll)
//============================================================================



static void Test_Ul_BFu15s_BFu0s()
{
  {
    init_simple_test("Ul_BFu15s_BFu0s");
    static STRUCT_IF_C Ul_BFu15s_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu15s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu15s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu15s_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 15, 1, "Ul_BFu15s_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 15, hide_ull(1LL<<14), "Ul_BFu15s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu15s_BFu0s, Ul_BFu15s_BFu0s)
//============================================================================



static void Test_Ul_BFu16i_BFu0c()
{
  {
    init_simple_test("Ul_BFu16i_BFu0c");
    static STRUCT_IF_C Ul_BFu16i_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu16i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu16i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu16i_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16i_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu16i_BFu0c, Ul_BFu16i_BFu0c)
//============================================================================



static void Test_Ul_BFu16i_BFu0i()
{
  {
    init_simple_test("Ul_BFu16i_BFu0i");
    static STRUCT_IF_C Ul_BFu16i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu16i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu16i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu16i_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16i_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu16i_BFu0i, Ul_BFu16i_BFu0i)
//============================================================================



static void Test_Ul_BFu16i_BFu0ll()
{
  {
    init_simple_test("Ul_BFu16i_BFu0ll");
    static STRUCT_IF_C Ul_BFu16i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu16i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu16i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu16i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16i_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu16i_BFu0ll, Ul_BFu16i_BFu0ll)
//============================================================================



static void Test_Ul_BFu16i_BFu0s()
{
  {
    init_simple_test("Ul_BFu16i_BFu0s");
    static STRUCT_IF_C Ul_BFu16i_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu16i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu16i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu16i_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16i_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu16i_BFu0s, Ul_BFu16i_BFu0s)
//============================================================================



static void Test_Ul_BFu16ll_BFu0c()
{
  {
    init_simple_test("Ul_BFu16ll_BFu0c");
    static STRUCT_IF_C Ul_BFu16ll_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu16ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu16ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu16ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16ll_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu16ll_BFu0c, Ul_BFu16ll_BFu0c)
//============================================================================



static void Test_Ul_BFu16ll_BFu0i()
{
  {
    init_simple_test("Ul_BFu16ll_BFu0i");
    static STRUCT_IF_C Ul_BFu16ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu16ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu16ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu16ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16ll_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu16ll_BFu0i, Ul_BFu16ll_BFu0i)
//============================================================================



static void Test_Ul_BFu16ll_BFu0ll()
{
  {
    init_simple_test("Ul_BFu16ll_BFu0ll");
    static STRUCT_IF_C Ul_BFu16ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu16ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu16ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu16ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16ll_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu16ll_BFu0ll, Ul_BFu16ll_BFu0ll)
//============================================================================



static void Test_Ul_BFu16ll_BFu0s()
{
  {
    init_simple_test("Ul_BFu16ll_BFu0s");
    static STRUCT_IF_C Ul_BFu16ll_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu16ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu16ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu16ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16ll_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu16ll_BFu0s, Ul_BFu16ll_BFu0s)
//============================================================================



static void Test_Ul_BFu16s_BFu0c()
{
  {
    init_simple_test("Ul_BFu16s_BFu0c");
    static STRUCT_IF_C Ul_BFu16s_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu16s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu16s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu16s_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16s_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu16s_BFu0c, Ul_BFu16s_BFu0c)
//============================================================================



static void Test_Ul_BFu16s_BFu0i()
{
  {
    init_simple_test("Ul_BFu16s_BFu0i");
    static STRUCT_IF_C Ul_BFu16s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu16s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu16s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu16s_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16s_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu16s_BFu0i, Ul_BFu16s_BFu0i)
//============================================================================



static void Test_Ul_BFu16s_BFu0ll()
{
  {
    init_simple_test("Ul_BFu16s_BFu0ll");
    static STRUCT_IF_C Ul_BFu16s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu16s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu16s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu16s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16s_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu16s_BFu0ll, Ul_BFu16s_BFu0ll)
//============================================================================



static void Test_Ul_BFu16s_BFu0s()
{
  {
    init_simple_test("Ul_BFu16s_BFu0s");
    static STRUCT_IF_C Ul_BFu16s_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu16s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu16s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu16s_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 16, 1, "Ul_BFu16s_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 16, hide_ull(1LL<<15), "Ul_BFu16s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu16s_BFu0s, Ul_BFu16s_BFu0s)
//============================================================================



static void Test_Ul_BFu17i_BFu0c()
{
  {
    init_simple_test("Ul_BFu17i_BFu0c");
    static STRUCT_IF_C Ul_BFu17i_BFu0c lv;
    check2(sizeof(lv), 11, "sizeof(Ul_BFu17i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu17i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu17i_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu17i_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu17i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu17i_BFu0c, Ul_BFu17i_BFu0c)
//============================================================================



static void Test_Ul_BFu17i_BFu0i()
{
  {
    init_simple_test("Ul_BFu17i_BFu0i");
    static STRUCT_IF_C Ul_BFu17i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu17i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu17i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu17i_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu17i_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu17i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu17i_BFu0i, Ul_BFu17i_BFu0i)
//============================================================================



static void Test_Ul_BFu17i_BFu0ll()
{
  {
    init_simple_test("Ul_BFu17i_BFu0ll");
    static STRUCT_IF_C Ul_BFu17i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu17i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu17i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu17i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu17i_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu17i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu17i_BFu0ll, Ul_BFu17i_BFu0ll)
//============================================================================



static void Test_Ul_BFu17i_BFu0s()
{
  {
    init_simple_test("Ul_BFu17i_BFu0s");
    static STRUCT_IF_C Ul_BFu17i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu17i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu17i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu17i_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu17i_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu17i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu17i_BFu0s, Ul_BFu17i_BFu0s)
//============================================================================



static void Test_Ul_BFu17ll_BFu0c()
{
  {
    init_simple_test("Ul_BFu17ll_BFu0c");
    static STRUCT_IF_C Ul_BFu17ll_BFu0c lv;
    check2(sizeof(lv), 11, "sizeof(Ul_BFu17ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu17ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu17ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu17ll_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu17ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu17ll_BFu0c, Ul_BFu17ll_BFu0c)
//============================================================================



static void Test_Ul_BFu17ll_BFu0i()
{
  {
    init_simple_test("Ul_BFu17ll_BFu0i");
    static STRUCT_IF_C Ul_BFu17ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu17ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu17ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu17ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu17ll_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu17ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu17ll_BFu0i, Ul_BFu17ll_BFu0i)
//============================================================================



static void Test_Ul_BFu17ll_BFu0ll()
{
  {
    init_simple_test("Ul_BFu17ll_BFu0ll");
    static STRUCT_IF_C Ul_BFu17ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu17ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu17ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu17ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu17ll_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu17ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu17ll_BFu0ll, Ul_BFu17ll_BFu0ll)
//============================================================================



static void Test_Ul_BFu17ll_BFu0s()
{
  {
    init_simple_test("Ul_BFu17ll_BFu0s");
    static STRUCT_IF_C Ul_BFu17ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu17ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu17ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu17ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 17, 1, "Ul_BFu17ll_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 17, hide_ull(1LL<<16), "Ul_BFu17ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu17ll_BFu0s, Ul_BFu17ll_BFu0s)
//============================================================================



static void Test_Ul_BFu1c_BFu0c()
{
  {
    init_simple_test("Ul_BFu1c_BFu0c");
    static STRUCT_IF_C Ul_BFu1c_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu1c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu1c_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu1c_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1c_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu1c_BFu0c, Ul_BFu1c_BFu0c)
//============================================================================



static void Test_Ul_BFu1c_BFu0i()
{
  {
    init_simple_test("Ul_BFu1c_BFu0i");
    static STRUCT_IF_C Ul_BFu1c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu1c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1c_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu1c_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1c_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu1c_BFu0i, Ul_BFu1c_BFu0i)
//============================================================================



static void Test_Ul_BFu1c_BFu0ll()
{
  {
    init_simple_test("Ul_BFu1c_BFu0ll");
    static STRUCT_IF_C Ul_BFu1c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu1c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu1c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1c_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu1c_BFu0ll, Ul_BFu1c_BFu0ll)
//============================================================================



static void Test_Ul_BFu1c_BFu0s()
{
  {
    init_simple_test("Ul_BFu1c_BFu0s");
    static STRUCT_IF_C Ul_BFu1c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu1c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1c_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu1c_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1c_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu1c_BFu0s, Ul_BFu1c_BFu0s)
//============================================================================



static void Test_Ul_BFu1i_BFu0c()
{
  {
    init_simple_test("Ul_BFu1i_BFu0c");
    static STRUCT_IF_C Ul_BFu1i_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu1i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu1i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu1i_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu1i_BFu0c, Ul_BFu1i_BFu0c)
//============================================================================



static void Test_Ul_BFu1i_BFu0i()
{
  {
    init_simple_test("Ul_BFu1i_BFu0i");
    static STRUCT_IF_C Ul_BFu1i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu1i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu1i_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu1i_BFu0i, Ul_BFu1i_BFu0i)
//============================================================================



static void Test_Ul_BFu1i_BFu0ll()
{
  {
    init_simple_test("Ul_BFu1i_BFu0ll");
    static STRUCT_IF_C Ul_BFu1i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu1i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu1i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu1i_BFu0ll, Ul_BFu1i_BFu0ll)
//============================================================================



static void Test_Ul_BFu1i_BFu0s()
{
  {
    init_simple_test("Ul_BFu1i_BFu0s");
    static STRUCT_IF_C Ul_BFu1i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu1i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu1i_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu1i_BFu0s, Ul_BFu1i_BFu0s)
//============================================================================



static void Test_Ul_BFu1ll_BFu0c()
{
  {
    init_simple_test("Ul_BFu1ll_BFu0c");
    static STRUCT_IF_C Ul_BFu1ll_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu1ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu1ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu1ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu1ll_BFu0c, Ul_BFu1ll_BFu0c)
//============================================================================



static void Test_Ul_BFu1ll_BFu0i()
{
  {
    init_simple_test("Ul_BFu1ll_BFu0i");
    static STRUCT_IF_C Ul_BFu1ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu1ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu1ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu1ll_BFu0i, Ul_BFu1ll_BFu0i)
//============================================================================



static void Test_Ul_BFu1ll_BFu0ll()
{
  {
    init_simple_test("Ul_BFu1ll_BFu0ll");
    static STRUCT_IF_C Ul_BFu1ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu1ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu1ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu1ll_BFu0ll, Ul_BFu1ll_BFu0ll)
//============================================================================



static void Test_Ul_BFu1ll_BFu0s()
{
  {
    init_simple_test("Ul_BFu1ll_BFu0s");
    static STRUCT_IF_C Ul_BFu1ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu1ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu1ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu1ll_BFu0s, Ul_BFu1ll_BFu0s)
//============================================================================



static void Test_Ul_BFu1s_BFu0c()
{
  {
    init_simple_test("Ul_BFu1s_BFu0c");
    static STRUCT_IF_C Ul_BFu1s_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu1s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu1s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu1s_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu1s_BFu0c, Ul_BFu1s_BFu0c)
//============================================================================



static void Test_Ul_BFu1s_BFu0i()
{
  {
    init_simple_test("Ul_BFu1s_BFu0i");
    static STRUCT_IF_C Ul_BFu1s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu1s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu1s_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu1s_BFu0i, Ul_BFu1s_BFu0i)
//============================================================================



static void Test_Ul_BFu1s_BFu0ll()
{
  {
    init_simple_test("Ul_BFu1s_BFu0ll");
    static STRUCT_IF_C Ul_BFu1s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu1s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu1s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu1s_BFu0ll, Ul_BFu1s_BFu0ll)
//============================================================================



static void Test_Ul_BFu1s_BFu0s()
{
  {
    init_simple_test("Ul_BFu1s_BFu0s");
    static STRUCT_IF_C Ul_BFu1s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu1s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu1s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu1s_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 1, 1, "Ul_BFu1s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu1s_BFu0s, Ul_BFu1s_BFu0s)
//============================================================================



static void Test_Ul_BFu31i_BFu0c()
{
  {
    init_simple_test("Ul_BFu31i_BFu0c");
    static STRUCT_IF_C Ul_BFu31i_BFu0c lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu31i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu31i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu31i_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu31i_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu31i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu31i_BFu0c, Ul_BFu31i_BFu0c)
//============================================================================



static void Test_Ul_BFu31i_BFu0i()
{
  {
    init_simple_test("Ul_BFu31i_BFu0i");
    static STRUCT_IF_C Ul_BFu31i_BFu0i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu31i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu31i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu31i_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu31i_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu31i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu31i_BFu0i, Ul_BFu31i_BFu0i)
//============================================================================



static void Test_Ul_BFu31i_BFu0ll()
{
  {
    init_simple_test("Ul_BFu31i_BFu0ll");
    static STRUCT_IF_C Ul_BFu31i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu31i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu31i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu31i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu31i_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu31i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu31i_BFu0ll, Ul_BFu31i_BFu0ll)
//============================================================================



static void Test_Ul_BFu31i_BFu0s()
{
  {
    init_simple_test("Ul_BFu31i_BFu0s");
    static STRUCT_IF_C Ul_BFu31i_BFu0s lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu31i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu31i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu31i_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu31i_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu31i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu31i_BFu0s, Ul_BFu31i_BFu0s)
//============================================================================



static void Test_Ul_BFu31ll_BFu0c()
{
  {
    init_simple_test("Ul_BFu31ll_BFu0c");
    static STRUCT_IF_C Ul_BFu31ll_BFu0c lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu31ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu31ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu31ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu31ll_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu31ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu31ll_BFu0c, Ul_BFu31ll_BFu0c)
//============================================================================



static void Test_Ul_BFu31ll_BFu0i()
{
  {
    init_simple_test("Ul_BFu31ll_BFu0i");
    static STRUCT_IF_C Ul_BFu31ll_BFu0i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu31ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu31ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu31ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu31ll_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu31ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu31ll_BFu0i, Ul_BFu31ll_BFu0i)
//============================================================================



static void Test_Ul_BFu31ll_BFu0ll()
{
  {
    init_simple_test("Ul_BFu31ll_BFu0ll");
    static STRUCT_IF_C Ul_BFu31ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu31ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu31ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu31ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu31ll_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu31ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu31ll_BFu0ll, Ul_BFu31ll_BFu0ll)
//============================================================================



static void Test_Ul_BFu31ll_BFu0s()
{
  {
    init_simple_test("Ul_BFu31ll_BFu0s");
    static STRUCT_IF_C Ul_BFu31ll_BFu0s lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu31ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu31ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu31ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 31, 1, "Ul_BFu31ll_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 31, hide_ull(1LL<<30), "Ul_BFu31ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu31ll_BFu0s, Ul_BFu31ll_BFu0s)
//============================================================================



static void Test_Ul_BFu32i_BFu0c()
{
  {
    init_simple_test("Ul_BFu32i_BFu0c");
    static STRUCT_IF_C Ul_BFu32i_BFu0c lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu32i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu32i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu32i_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu32i_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu32i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu32i_BFu0c, Ul_BFu32i_BFu0c)
//============================================================================



static void Test_Ul_BFu32i_BFu0i()
{
  {
    init_simple_test("Ul_BFu32i_BFu0i");
    static STRUCT_IF_C Ul_BFu32i_BFu0i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu32i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu32i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu32i_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu32i_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu32i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu32i_BFu0i, Ul_BFu32i_BFu0i)
//============================================================================



static void Test_Ul_BFu32i_BFu0ll()
{
  {
    init_simple_test("Ul_BFu32i_BFu0ll");
    static STRUCT_IF_C Ul_BFu32i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu32i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu32i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu32i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu32i_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu32i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu32i_BFu0ll, Ul_BFu32i_BFu0ll)
//============================================================================



static void Test_Ul_BFu32i_BFu0s()
{
  {
    init_simple_test("Ul_BFu32i_BFu0s");
    static STRUCT_IF_C Ul_BFu32i_BFu0s lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu32i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu32i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu32i_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu32i_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu32i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu32i_BFu0s, Ul_BFu32i_BFu0s)
//============================================================================



static void Test_Ul_BFu32ll_BFu0c()
{
  {
    init_simple_test("Ul_BFu32ll_BFu0c");
    static STRUCT_IF_C Ul_BFu32ll_BFu0c lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu32ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu32ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu32ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu32ll_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu32ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu32ll_BFu0c, Ul_BFu32ll_BFu0c)
//============================================================================



static void Test_Ul_BFu32ll_BFu0i()
{
  {
    init_simple_test("Ul_BFu32ll_BFu0i");
    static STRUCT_IF_C Ul_BFu32ll_BFu0i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu32ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu32ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu32ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu32ll_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu32ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu32ll_BFu0i, Ul_BFu32ll_BFu0i)
//============================================================================



static void Test_Ul_BFu32ll_BFu0ll()
{
  {
    init_simple_test("Ul_BFu32ll_BFu0ll");
    static STRUCT_IF_C Ul_BFu32ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu32ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu32ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu32ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu32ll_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu32ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu32ll_BFu0ll, Ul_BFu32ll_BFu0ll)
//============================================================================



static void Test_Ul_BFu32ll_BFu0s()
{
  {
    init_simple_test("Ul_BFu32ll_BFu0s");
    static STRUCT_IF_C Ul_BFu32ll_BFu0s lv;
    check2(sizeof(lv), 12, "sizeof(Ul_BFu32ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu32ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu32ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 32, 1, "Ul_BFu32ll_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 32, hide_ull(1LL<<31), "Ul_BFu32ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu32ll_BFu0s, Ul_BFu32ll_BFu0s)
//============================================================================



static void Test_Ul_BFu33_BFu0c()
{
  {
    init_simple_test("Ul_BFu33_BFu0c");
    static STRUCT_IF_C Ul_BFu33_BFu0c lv;
    check2(sizeof(lv), 13, "sizeof(Ul_BFu33_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu33_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu33_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 33, 1, "Ul_BFu33_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 33, hide_ull(1LL<<32), "Ul_BFu33_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu33_BFu0c, Ul_BFu33_BFu0c)
//============================================================================



static void Test_Ul_BFu33_BFu0i()
{
  {
    init_simple_test("Ul_BFu33_BFu0i");
    static STRUCT_IF_C Ul_BFu33_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,16), "sizeof(Ul_BFu33_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu33_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu33_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 33, 1, "Ul_BFu33_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 33, hide_ull(1LL<<32), "Ul_BFu33_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu33_BFu0i, Ul_BFu33_BFu0i)
//============================================================================



static void Test_Ul_BFu33_BFu0ll()
{
  {
    init_simple_test("Ul_BFu33_BFu0ll");
    static STRUCT_IF_C Ul_BFu33_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,16), "sizeof(Ul_BFu33_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu33_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu33_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 33, 1, "Ul_BFu33_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 33, hide_ull(1LL<<32), "Ul_BFu33_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu33_BFu0ll, Ul_BFu33_BFu0ll)
//============================================================================



static void Test_Ul_BFu33_BFu0s()
{
  {
    init_simple_test("Ul_BFu33_BFu0s");
    static STRUCT_IF_C Ul_BFu33_BFu0s lv;
    check2(sizeof(lv), ABISELECT(14,14), "sizeof(Ul_BFu33_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu33_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu33_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 33, 1, "Ul_BFu33_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 33, hide_ull(1LL<<32), "Ul_BFu33_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu33_BFu0s, Ul_BFu33_BFu0s)
//============================================================================



static void Test_Ul_BFu7c_BFu0c()
{
  {
    init_simple_test("Ul_BFu7c_BFu0c");
    static STRUCT_IF_C Ul_BFu7c_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu7c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu7c_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu7c_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7c_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7c_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu7c_BFu0c, Ul_BFu7c_BFu0c)
//============================================================================



static void Test_Ul_BFu7c_BFu0i()
{
  {
    init_simple_test("Ul_BFu7c_BFu0i");
    static STRUCT_IF_C Ul_BFu7c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu7c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7c_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu7c_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7c_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7c_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu7c_BFu0i, Ul_BFu7c_BFu0i)
//============================================================================



static void Test_Ul_BFu7c_BFu0ll()
{
  {
    init_simple_test("Ul_BFu7c_BFu0ll");
    static STRUCT_IF_C Ul_BFu7c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu7c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu7c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7c_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7c_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu7c_BFu0ll, Ul_BFu7c_BFu0ll)
//============================================================================



static void Test_Ul_BFu7c_BFu0s()
{
  {
    init_simple_test("Ul_BFu7c_BFu0s");
    static STRUCT_IF_C Ul_BFu7c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu7c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7c_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu7c_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7c_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7c_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu7c_BFu0s, Ul_BFu7c_BFu0s)
//============================================================================



static void Test_Ul_BFu7i_BFu0c()
{
  {
    init_simple_test("Ul_BFu7i_BFu0c");
    static STRUCT_IF_C Ul_BFu7i_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu7i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu7i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu7i_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7i_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu7i_BFu0c, Ul_BFu7i_BFu0c)
//============================================================================



static void Test_Ul_BFu7i_BFu0i()
{
  {
    init_simple_test("Ul_BFu7i_BFu0i");
    static STRUCT_IF_C Ul_BFu7i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu7i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu7i_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7i_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu7i_BFu0i, Ul_BFu7i_BFu0i)
//============================================================================



static void Test_Ul_BFu7i_BFu0ll()
{
  {
    init_simple_test("Ul_BFu7i_BFu0ll");
    static STRUCT_IF_C Ul_BFu7i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu7i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu7i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7i_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu7i_BFu0ll, Ul_BFu7i_BFu0ll)
//============================================================================



static void Test_Ul_BFu7i_BFu0s()
{
  {
    init_simple_test("Ul_BFu7i_BFu0s");
    static STRUCT_IF_C Ul_BFu7i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu7i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu7i_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7i_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu7i_BFu0s, Ul_BFu7i_BFu0s)
//============================================================================



static void Test_Ul_BFu7ll_BFu0c()
{
  {
    init_simple_test("Ul_BFu7ll_BFu0c");
    static STRUCT_IF_C Ul_BFu7ll_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu7ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu7ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu7ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7ll_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu7ll_BFu0c, Ul_BFu7ll_BFu0c)
//============================================================================



static void Test_Ul_BFu7ll_BFu0i()
{
  {
    init_simple_test("Ul_BFu7ll_BFu0i");
    static STRUCT_IF_C Ul_BFu7ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu7ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu7ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7ll_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu7ll_BFu0i, Ul_BFu7ll_BFu0i)
//============================================================================



static void Test_Ul_BFu7ll_BFu0ll()
{
  {
    init_simple_test("Ul_BFu7ll_BFu0ll");
    static STRUCT_IF_C Ul_BFu7ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu7ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu7ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7ll_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu7ll_BFu0ll, Ul_BFu7ll_BFu0ll)
//============================================================================



static void Test_Ul_BFu7ll_BFu0s()
{
  {
    init_simple_test("Ul_BFu7ll_BFu0s");
    static STRUCT_IF_C Ul_BFu7ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu7ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu7ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7ll_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu7ll_BFu0s, Ul_BFu7ll_BFu0s)
//============================================================================



static void Test_Ul_BFu7s_BFu0c()
{
  {
    init_simple_test("Ul_BFu7s_BFu0c");
    static STRUCT_IF_C Ul_BFu7s_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu7s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu7s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu7s_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7s_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu7s_BFu0c, Ul_BFu7s_BFu0c)
//============================================================================



static void Test_Ul_BFu7s_BFu0i()
{
  {
    init_simple_test("Ul_BFu7s_BFu0i");
    static STRUCT_IF_C Ul_BFu7s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu7s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu7s_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7s_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu7s_BFu0i, Ul_BFu7s_BFu0i)
//============================================================================



static void Test_Ul_BFu7s_BFu0ll()
{
  {
    init_simple_test("Ul_BFu7s_BFu0ll");
    static STRUCT_IF_C Ul_BFu7s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu7s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu7s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7s_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu7s_BFu0ll, Ul_BFu7s_BFu0ll)
//============================================================================



static void Test_Ul_BFu7s_BFu0s()
{
  {
    init_simple_test("Ul_BFu7s_BFu0s");
    static STRUCT_IF_C Ul_BFu7s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu7s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu7s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu7s_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 7, 1, "Ul_BFu7s_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 7, hide_ull(1LL<<6), "Ul_BFu7s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu7s_BFu0s, Ul_BFu7s_BFu0s)
//============================================================================



static void Test_Ul_BFu8c_BFu0c()
{
  {
    init_simple_test("Ul_BFu8c_BFu0c");
    static STRUCT_IF_C Ul_BFu8c_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu8c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu8c_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu8c_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8c_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8c_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu8c_BFu0c, Ul_BFu8c_BFu0c)
//============================================================================



static void Test_Ul_BFu8c_BFu0i()
{
  {
    init_simple_test("Ul_BFu8c_BFu0i");
    static STRUCT_IF_C Ul_BFu8c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu8c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8c_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu8c_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8c_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8c_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu8c_BFu0i, Ul_BFu8c_BFu0i)
//============================================================================



static void Test_Ul_BFu8c_BFu0ll()
{
  {
    init_simple_test("Ul_BFu8c_BFu0ll");
    static STRUCT_IF_C Ul_BFu8c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu8c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu8c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8c_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8c_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu8c_BFu0ll, Ul_BFu8c_BFu0ll)
//============================================================================



static void Test_Ul_BFu8c_BFu0s()
{
  {
    init_simple_test("Ul_BFu8c_BFu0s");
    static STRUCT_IF_C Ul_BFu8c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu8c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8c_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu8c_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8c_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8c_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu8c_BFu0s, Ul_BFu8c_BFu0s)
//============================================================================



static void Test_Ul_BFu8i_BFu0c()
{
  {
    init_simple_test("Ul_BFu8i_BFu0c");
    static STRUCT_IF_C Ul_BFu8i_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu8i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu8i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu8i_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8i_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu8i_BFu0c, Ul_BFu8i_BFu0c)
//============================================================================



static void Test_Ul_BFu8i_BFu0i()
{
  {
    init_simple_test("Ul_BFu8i_BFu0i");
    static STRUCT_IF_C Ul_BFu8i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu8i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu8i_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8i_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu8i_BFu0i, Ul_BFu8i_BFu0i)
//============================================================================



static void Test_Ul_BFu8i_BFu0ll()
{
  {
    init_simple_test("Ul_BFu8i_BFu0ll");
    static STRUCT_IF_C Ul_BFu8i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu8i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu8i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8i_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu8i_BFu0ll, Ul_BFu8i_BFu0ll)
//============================================================================



static void Test_Ul_BFu8i_BFu0s()
{
  {
    init_simple_test("Ul_BFu8i_BFu0s");
    static STRUCT_IF_C Ul_BFu8i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu8i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu8i_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8i_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu8i_BFu0s, Ul_BFu8i_BFu0s)
//============================================================================



static void Test_Ul_BFu8ll_BFu0c()
{
  {
    init_simple_test("Ul_BFu8ll_BFu0c");
    static STRUCT_IF_C Ul_BFu8ll_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu8ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu8ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu8ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8ll_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu8ll_BFu0c, Ul_BFu8ll_BFu0c)
//============================================================================



static void Test_Ul_BFu8ll_BFu0i()
{
  {
    init_simple_test("Ul_BFu8ll_BFu0i");
    static STRUCT_IF_C Ul_BFu8ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu8ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu8ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8ll_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu8ll_BFu0i, Ul_BFu8ll_BFu0i)
//============================================================================



static void Test_Ul_BFu8ll_BFu0ll()
{
  {
    init_simple_test("Ul_BFu8ll_BFu0ll");
    static STRUCT_IF_C Ul_BFu8ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu8ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu8ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8ll_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu8ll_BFu0ll, Ul_BFu8ll_BFu0ll)
//============================================================================



static void Test_Ul_BFu8ll_BFu0s()
{
  {
    init_simple_test("Ul_BFu8ll_BFu0s");
    static STRUCT_IF_C Ul_BFu8ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu8ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu8ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8ll_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu8ll_BFu0s, Ul_BFu8ll_BFu0s)
//============================================================================



static void Test_Ul_BFu8s_BFu0c()
{
  {
    init_simple_test("Ul_BFu8s_BFu0c");
    static STRUCT_IF_C Ul_BFu8s_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_BFu8s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu8s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu8s_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8s_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu8s_BFu0c, Ul_BFu8s_BFu0c)
//============================================================================



static void Test_Ul_BFu8s_BFu0i()
{
  {
    init_simple_test("Ul_BFu8s_BFu0i");
    static STRUCT_IF_C Ul_BFu8s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu8s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu8s_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8s_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu8s_BFu0i, Ul_BFu8s_BFu0i)
//============================================================================



static void Test_Ul_BFu8s_BFu0ll()
{
  {
    init_simple_test("Ul_BFu8s_BFu0ll");
    static STRUCT_IF_C Ul_BFu8s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu8s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu8s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8s_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu8s_BFu0ll, Ul_BFu8s_BFu0ll)
//============================================================================



static void Test_Ul_BFu8s_BFu0s()
{
  {
    init_simple_test("Ul_BFu8s_BFu0s");
    static STRUCT_IF_C Ul_BFu8s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_BFu8s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu8s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu8s_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 8, 1, "Ul_BFu8s_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 8, hide_ull(1LL<<7), "Ul_BFu8s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu8s_BFu0s, Ul_BFu8s_BFu0s)
//============================================================================



static void Test_Ul_BFu9i_BFu0c()
{
  {
    init_simple_test("Ul_BFu9i_BFu0c");
    static STRUCT_IF_C Ul_BFu9i_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu9i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu9i_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu9i_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9i_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu9i_BFu0c, Ul_BFu9i_BFu0c)
//============================================================================



static void Test_Ul_BFu9i_BFu0i()
{
  {
    init_simple_test("Ul_BFu9i_BFu0i");
    static STRUCT_IF_C Ul_BFu9i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu9i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu9i_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu9i_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9i_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu9i_BFu0i, Ul_BFu9i_BFu0i)
//============================================================================



static void Test_Ul_BFu9i_BFu0ll()
{
  {
    init_simple_test("Ul_BFu9i_BFu0ll");
    static STRUCT_IF_C Ul_BFu9i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu9i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu9i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu9i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9i_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu9i_BFu0ll, Ul_BFu9i_BFu0ll)
//============================================================================



static void Test_Ul_BFu9i_BFu0s()
{
  {
    init_simple_test("Ul_BFu9i_BFu0s");
    static STRUCT_IF_C Ul_BFu9i_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu9i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu9i_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu9i_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9i_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu9i_BFu0s, Ul_BFu9i_BFu0s)
//============================================================================



static void Test_Ul_BFu9ll_BFu0c()
{
  {
    init_simple_test("Ul_BFu9ll_BFu0c");
    static STRUCT_IF_C Ul_BFu9ll_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu9ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu9ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu9ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9ll_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu9ll_BFu0c, Ul_BFu9ll_BFu0c)
//============================================================================



static void Test_Ul_BFu9ll_BFu0i()
{
  {
    init_simple_test("Ul_BFu9ll_BFu0i");
    static STRUCT_IF_C Ul_BFu9ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu9ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu9ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu9ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9ll_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu9ll_BFu0i, Ul_BFu9ll_BFu0i)
//============================================================================



static void Test_Ul_BFu9ll_BFu0ll()
{
  {
    init_simple_test("Ul_BFu9ll_BFu0ll");
    static STRUCT_IF_C Ul_BFu9ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu9ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu9ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu9ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9ll_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu9ll_BFu0ll, Ul_BFu9ll_BFu0ll)
//============================================================================



static void Test_Ul_BFu9ll_BFu0s()
{
  {
    init_simple_test("Ul_BFu9ll_BFu0s");
    static STRUCT_IF_C Ul_BFu9ll_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu9ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu9ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu9ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9ll_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu9ll_BFu0s, Ul_BFu9ll_BFu0s)
//============================================================================



static void Test_Ul_BFu9s_BFu0c()
{
  {
    init_simple_test("Ul_BFu9s_BFu0c");
    static STRUCT_IF_C Ul_BFu9s_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu9s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_BFu9s_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_BFu9s_BFu0c.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9s_BFu0c");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu9s_BFu0c, Ul_BFu9s_BFu0c)
//============================================================================



static void Test_Ul_BFu9s_BFu0i()
{
  {
    init_simple_test("Ul_BFu9s_BFu0i");
    static STRUCT_IF_C Ul_BFu9s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_BFu9s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu9s_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_BFu9s_BFu0i.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9s_BFu0i");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu9s_BFu0i, Ul_BFu9s_BFu0i)
//============================================================================



static void Test_Ul_BFu9s_BFu0ll()
{
  {
    init_simple_test("Ul_BFu9s_BFu0ll");
    static STRUCT_IF_C Ul_BFu9s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu9s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu9s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_BFu9s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9s_BFu0ll");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu9s_BFu0ll, Ul_BFu9s_BFu0ll)
//============================================================================



static void Test_Ul_BFu9s_BFu0s()
{
  {
    init_simple_test("Ul_BFu9s_BFu0s");
    static STRUCT_IF_C Ul_BFu9s_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_BFu9s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_BFu9s_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_BFu9s_BFu0s.v1");
    set_bf_and_test(lv, v2, 8, 0, 9, 1, "Ul_BFu9s_BFu0s");
    set_bf_and_test(lv, v2, 8, 0, 9, hide_ull(1LL<<8), "Ul_BFu9s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu9s_BFu0s, Ul_BFu9s_BFu0s)
//============================================================================



static void Test_Ul_C_BFu0c()
{
  {
    init_simple_test("Ul_C_BFu0c");
    static STRUCT_IF_C Ul_C_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_C_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_C_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_C_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_C_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_C_BFu0c, Ul_C_BFu0c)
//============================================================================



static void Test_Ul_C_BFu0i()
{
  {
    init_simple_test("Ul_C_BFu0i");
    static STRUCT_IF_C Ul_C_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_C_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_C_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_C_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_C_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_C_BFu0i, Ul_C_BFu0i)
//============================================================================



static void Test_Ul_C_BFu0ll()
{
  {
    init_simple_test("Ul_C_BFu0ll");
    static STRUCT_IF_C Ul_C_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_C_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_C_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_C_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_C_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_C_BFu0ll, Ul_C_BFu0ll)
//============================================================================



static void Test_Ul_C_BFu0s()
{
  {
    init_simple_test("Ul_C_BFu0s");
    static STRUCT_IF_C Ul_C_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_C_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_C_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_C_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_C_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_C_BFu0s, Ul_C_BFu0s)
//============================================================================



static void Test_Ul_D_BFu0c()
{
  {
    init_simple_test("Ul_D_BFu0c");
    static STRUCT_IF_C Ul_D_BFu0c lv;
    check2(sizeof(lv), 16, "sizeof(Ul_D_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_D_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_D_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_D_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_D_BFu0c, Ul_D_BFu0c)
//============================================================================



static void Test_Ul_D_BFu0i()
{
  {
    init_simple_test("Ul_D_BFu0i");
    static STRUCT_IF_C Ul_D_BFu0i lv;
    check2(sizeof(lv), 16, "sizeof(Ul_D_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_D_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_D_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_D_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_D_BFu0i, Ul_D_BFu0i)
//============================================================================



static void Test_Ul_D_BFu0ll()
{
  {
    init_simple_test("Ul_D_BFu0ll");
    static STRUCT_IF_C Ul_D_BFu0ll lv;
    check2(sizeof(lv), 16, "sizeof(Ul_D_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_D_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_D_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_D_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_D_BFu0ll, Ul_D_BFu0ll)
//============================================================================



static void Test_Ul_D_BFu0s()
{
  {
    init_simple_test("Ul_D_BFu0s");
    static STRUCT_IF_C Ul_D_BFu0s lv;
    check2(sizeof(lv), 16, "sizeof(Ul_D_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_D_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_D_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_D_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_D_BFu0s, Ul_D_BFu0s)
//============================================================================



static void Test_Ul_F_BFu0c()
{
  {
    init_simple_test("Ul_F_BFu0c");
    static STRUCT_IF_C Ul_F_BFu0c lv;
    check2(sizeof(lv), 12, "sizeof(Ul_F_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_F_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_F_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_F_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_F_BFu0c, Ul_F_BFu0c)
//============================================================================



static void Test_Ul_F_BFu0i()
{
  {
    init_simple_test("Ul_F_BFu0i");
    static STRUCT_IF_C Ul_F_BFu0i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_F_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_F_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_F_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_F_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_F_BFu0i, Ul_F_BFu0i)
//============================================================================



static void Test_Ul_F_BFu0ll()
{
  {
    init_simple_test("Ul_F_BFu0ll");
    static STRUCT_IF_C Ul_F_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_F_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_F_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_F_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_F_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_F_BFu0ll, Ul_F_BFu0ll)
//============================================================================



static void Test_Ul_F_BFu0s()
{
  {
    init_simple_test("Ul_F_BFu0s");
    static STRUCT_IF_C Ul_F_BFu0s lv;
    check2(sizeof(lv), 12, "sizeof(Ul_F_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_F_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_F_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_F_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_F_BFu0s, Ul_F_BFu0s)
//============================================================================



static void Test_Ul_I_BFu0c()
{
  {
    init_simple_test("Ul_I_BFu0c");
    static STRUCT_IF_C Ul_I_BFu0c lv;
    check2(sizeof(lv), 12, "sizeof(Ul_I_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_I_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_I_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_I_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_I_BFu0c, Ul_I_BFu0c)
//============================================================================



static void Test_Ul_I_BFu0i()
{
  {
    init_simple_test("Ul_I_BFu0i");
    static STRUCT_IF_C Ul_I_BFu0i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_I_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_I_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_I_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_I_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_I_BFu0i, Ul_I_BFu0i)
//============================================================================



static void Test_Ul_I_BFu0ll()
{
  {
    init_simple_test("Ul_I_BFu0ll");
    static STRUCT_IF_C Ul_I_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_I_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_I_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_I_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_I_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_I_BFu0ll, Ul_I_BFu0ll)
//============================================================================



static void Test_Ul_I_BFu0s()
{
  {
    init_simple_test("Ul_I_BFu0s");
    static STRUCT_IF_C Ul_I_BFu0s lv;
    check2(sizeof(lv), 12, "sizeof(Ul_I_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_I_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_I_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_I_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_I_BFu0s, Ul_I_BFu0s)
//============================================================================



static void Test_Ul_Ip_BFu0c()
{
  {
    init_simple_test("Ul_Ip_BFu0c");
    static STRUCT_IF_C Ul_Ip_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Ip_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Ip_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_Ip_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_Ip_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Ip_BFu0c, Ul_Ip_BFu0c)
//============================================================================



static void Test_Ul_Ip_BFu0i()
{
  {
    init_simple_test("Ul_Ip_BFu0i");
    static STRUCT_IF_C Ul_Ip_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Ip_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Ip_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_Ip_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_Ip_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Ip_BFu0i, Ul_Ip_BFu0i)
//============================================================================



static void Test_Ul_Ip_BFu0ll()
{
  {
    init_simple_test("Ul_Ip_BFu0ll");
    static STRUCT_IF_C Ul_Ip_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Ip_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Ip_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_Ip_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Ip_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Ip_BFu0ll, Ul_Ip_BFu0ll)
//============================================================================



static void Test_Ul_Ip_BFu0s()
{
  {
    init_simple_test("Ul_Ip_BFu0s");
    static STRUCT_IF_C Ul_Ip_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Ip_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Ip_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_Ip_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_Ip_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Ip_BFu0s, Ul_Ip_BFu0s)
//============================================================================



static void Test_Ul_L_BFu0c()
{
  {
    init_simple_test("Ul_L_BFu0c");
    static STRUCT_IF_C Ul_L_BFu0c lv;
    check2(sizeof(lv), 16, "sizeof(Ul_L_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_L_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_L_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_L_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_L_BFu0c, Ul_L_BFu0c)
//============================================================================



static void Test_Ul_L_BFu0i()
{
  {
    init_simple_test("Ul_L_BFu0i");
    static STRUCT_IF_C Ul_L_BFu0i lv;
    check2(sizeof(lv), 16, "sizeof(Ul_L_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_L_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_L_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_L_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_L_BFu0i, Ul_L_BFu0i)
//============================================================================



static void Test_Ul_L_BFu0ll()
{
  {
    init_simple_test("Ul_L_BFu0ll");
    static STRUCT_IF_C Ul_L_BFu0ll lv;
    check2(sizeof(lv), 16, "sizeof(Ul_L_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_L_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_L_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_L_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_L_BFu0ll, Ul_L_BFu0ll)
//============================================================================



static void Test_Ul_L_BFu0s()
{
  {
    init_simple_test("Ul_L_BFu0s");
    static STRUCT_IF_C Ul_L_BFu0s lv;
    check2(sizeof(lv), 16, "sizeof(Ul_L_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_L_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_L_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_L_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_L_BFu0s, Ul_L_BFu0s)
//============================================================================



static void Test_Ul_S_BFu0c()
{
  {
    init_simple_test("Ul_S_BFu0c");
    static STRUCT_IF_C Ul_S_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_S_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_S_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_S_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_S_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_S_BFu0c, Ul_S_BFu0c)
//============================================================================



static void Test_Ul_S_BFu0i()
{
  {
    init_simple_test("Ul_S_BFu0i");
    static STRUCT_IF_C Ul_S_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_S_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_S_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_S_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_S_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_S_BFu0i, Ul_S_BFu0i)
//============================================================================



static void Test_Ul_S_BFu0ll()
{
  {
    init_simple_test("Ul_S_BFu0ll");
    static STRUCT_IF_C Ul_S_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_S_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_S_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_S_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_S_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_S_BFu0ll, Ul_S_BFu0ll)
//============================================================================



static void Test_Ul_S_BFu0s()
{
  {
    init_simple_test("Ul_S_BFu0s");
    static STRUCT_IF_C Ul_S_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_S_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_S_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_S_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_S_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_S_BFu0s, Ul_S_BFu0s)
//============================================================================



static void Test_Ul_Uc_BFu0c()
{
  {
    init_simple_test("Ul_Uc_BFu0c");
    static STRUCT_IF_C Ul_Uc_BFu0c lv;
    check2(sizeof(lv), 9, "sizeof(Ul_Uc_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Uc_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_Uc_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_Uc_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Uc_BFu0c, Ul_Uc_BFu0c)
//============================================================================



static void Test_Ul_Uc_BFu0i()
{
  {
    init_simple_test("Ul_Uc_BFu0i");
    static STRUCT_IF_C Ul_Uc_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_Uc_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Uc_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_Uc_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_Uc_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Uc_BFu0i, Ul_Uc_BFu0i)
//============================================================================



static void Test_Ul_Uc_BFu0ll()
{
  {
    init_simple_test("Ul_Uc_BFu0ll");
    static STRUCT_IF_C Ul_Uc_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Uc_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Uc_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_Uc_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Uc_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Uc_BFu0ll, Ul_Uc_BFu0ll)
//============================================================================



static void Test_Ul_Uc_BFu0s()
{
  {
    init_simple_test("Ul_Uc_BFu0s");
    static STRUCT_IF_C Ul_Uc_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,10), "sizeof(Ul_Uc_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Uc_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_Uc_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_Uc_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Uc_BFu0s, Ul_Uc_BFu0s)
//============================================================================



static void Test_Ul_Ui_BFu0c()
{
  {
    init_simple_test("Ul_Ui_BFu0c");
    static STRUCT_IF_C Ul_Ui_BFu0c lv;
    check2(sizeof(lv), 12, "sizeof(Ul_Ui_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Ui_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_Ui_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_Ui_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Ui_BFu0c, Ul_Ui_BFu0c)
//============================================================================



static void Test_Ul_Ui_BFu0i()
{
  {
    init_simple_test("Ul_Ui_BFu0i");
    static STRUCT_IF_C Ul_Ui_BFu0i lv;
    check2(sizeof(lv), 12, "sizeof(Ul_Ui_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Ui_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_Ui_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_Ui_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Ui_BFu0i, Ul_Ui_BFu0i)
//============================================================================



static void Test_Ul_Ui_BFu0ll()
{
  {
    init_simple_test("Ul_Ui_BFu0ll");
    static STRUCT_IF_C Ul_Ui_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Ui_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Ui_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_Ui_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Ui_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Ui_BFu0ll, Ul_Ui_BFu0ll)
//============================================================================



static void Test_Ul_Ui_BFu0s()
{
  {
    init_simple_test("Ul_Ui_BFu0s");
    static STRUCT_IF_C Ul_Ui_BFu0s lv;
    check2(sizeof(lv), 12, "sizeof(Ul_Ui_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Ui_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_Ui_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_Ui_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Ui_BFu0s, Ul_Ui_BFu0s)
//============================================================================



static void Test_Ul_Ul_BFu0c()
{
  {
    init_simple_test("Ul_Ul_BFu0c");
    static STRUCT_IF_C Ul_Ul_BFu0c lv;
    check2(sizeof(lv), 16, "sizeof(Ul_Ul_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Ul_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_Ul_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_Ul_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Ul_BFu0c, Ul_Ul_BFu0c)
//============================================================================



static void Test_Ul_Ul_BFu0i()
{
  {
    init_simple_test("Ul_Ul_BFu0i");
    static STRUCT_IF_C Ul_Ul_BFu0i lv;
    check2(sizeof(lv), 16, "sizeof(Ul_Ul_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Ul_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_Ul_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_Ul_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Ul_BFu0i, Ul_Ul_BFu0i)
//============================================================================



static void Test_Ul_Ul_BFu0ll()
{
  {
    init_simple_test("Ul_Ul_BFu0ll");
    static STRUCT_IF_C Ul_Ul_BFu0ll lv;
    check2(sizeof(lv), 16, "sizeof(Ul_Ul_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Ul_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_Ul_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Ul_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Ul_BFu0ll, Ul_Ul_BFu0ll)
//============================================================================



static void Test_Ul_Ul_BFu0s()
{
  {
    init_simple_test("Ul_Ul_BFu0s");
    static STRUCT_IF_C Ul_Ul_BFu0s lv;
    check2(sizeof(lv), 16, "sizeof(Ul_Ul_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Ul_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_Ul_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_Ul_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Ul_BFu0s, Ul_Ul_BFu0s)
//============================================================================



static void Test_Ul_Us_BFu0c()
{
  {
    init_simple_test("Ul_Us_BFu0c");
    static STRUCT_IF_C Ul_Us_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Ul_Us_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Us_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_Us_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_Us_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Us_BFu0c, Ul_Us_BFu0c)
//============================================================================



static void Test_Ul_Us_BFu0i()
{
  {
    init_simple_test("Ul_Us_BFu0i");
    static STRUCT_IF_C Ul_Us_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Ul_Us_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Us_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_Us_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_Us_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Us_BFu0i, Ul_Us_BFu0i)
//============================================================================



static void Test_Ul_Us_BFu0ll()
{
  {
    init_simple_test("Ul_Us_BFu0ll");
    static STRUCT_IF_C Ul_Us_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Us_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Us_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_Us_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Us_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Us_BFu0ll, Ul_Us_BFu0ll)
//============================================================================



static void Test_Ul_Us_BFu0s()
{
  {
    init_simple_test("Ul_Us_BFu0s");
    static STRUCT_IF_C Ul_Us_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Ul_Us_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Us_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_Us_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_Us_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Us_BFu0s, Ul_Us_BFu0s)
//============================================================================



static void Test_Ul_Vp_BFu0c()
{
  {
    init_simple_test("Ul_Vp_BFu0c");
    static STRUCT_IF_C Ul_Vp_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Vp_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Ul_Vp_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_Vp_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_Vp_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Vp_BFu0c, Ul_Vp_BFu0c)
//============================================================================



static void Test_Ul_Vp_BFu0i()
{
  {
    init_simple_test("Ul_Vp_BFu0i");
    static STRUCT_IF_C Ul_Vp_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Vp_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Vp_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_Vp_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_Vp_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Vp_BFu0i, Ul_Vp_BFu0i)
//============================================================================



static void Test_Ul_Vp_BFu0ll()
{
  {
    init_simple_test("Ul_Vp_BFu0ll");
    static STRUCT_IF_C Ul_Vp_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Vp_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Vp_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_Vp_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Vp_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Vp_BFu0ll, Ul_Vp_BFu0ll)
//============================================================================



static void Test_Ul_Vp_BFu0s()
{
  {
    init_simple_test("Ul_Vp_BFu0s");
    static STRUCT_IF_C Ul_Vp_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Vp_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Ul_Vp_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_Vp_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_Vp_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Vp_BFu0s, Ul_Vp_BFu0s)
//============================================================================



static void Test_Us_BFu0c()
{
  {
    init_simple_test("Us_BFu0c");
    static STRUCT_IF_C Us_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(Us_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c, Us_BFu0c)
//============================================================================



static void Test_Us_BFu0c_BFu0c()
{
  {
    init_simple_test("Us_BFu0c_BFu0c");
    static STRUCT_IF_C Us_BFu0c_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(Us_BFu0c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu0c, Us_BFu0c_BFu0c)
//============================================================================



static void Test_Us_BFu0c_BFu0i()
{
  {
    init_simple_test("Us_BFu0c_BFu0i");
    static STRUCT_IF_C Us_BFu0c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu0c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0c_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu0i, Us_BFu0c_BFu0i)
//============================================================================



static void Test_Us_BFu0c_BFu0ll()
{
  {
    init_simple_test("Us_BFu0c_BFu0ll");
    static STRUCT_IF_C Us_BFu0c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu0c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu0ll, Us_BFu0c_BFu0ll)
//============================================================================



static void Test_Us_BFu0c_BFu0s()
{
  {
    init_simple_test("Us_BFu0c_BFu0s");
    static STRUCT_IF_C Us_BFu0c_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Us_BFu0c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0c_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu0s, Us_BFu0c_BFu0s)
//============================================================================



static void Test_Us_BFu0c_BFu15i()
{
  {
    init_simple_test("Us_BFu0c_BFu15i");
    static STRUCT_IF_C Us_BFu0c_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu15i)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu15i.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu0c_BFu15i");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu0c_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu15i, Us_BFu0c_BFu15i)
//============================================================================



static void Test_Us_BFu0c_BFu15ll()
{
  {
    init_simple_test("Us_BFu0c_BFu15ll");
    static STRUCT_IF_C Us_BFu0c_BFu15ll lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu15ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu15ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu0c_BFu15ll");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu0c_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu15ll, Us_BFu0c_BFu15ll)
//============================================================================



static void Test_Us_BFu0c_BFu15s()
{
  {
    init_simple_test("Us_BFu0c_BFu15s");
    static STRUCT_IF_C Us_BFu0c_BFu15s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu15s)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu15s.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu0c_BFu15s");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu0c_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu15s, Us_BFu0c_BFu15s)
//============================================================================



static void Test_Us_BFu0c_BFu16i()
{
  {
    init_simple_test("Us_BFu0c_BFu16i");
    static STRUCT_IF_C Us_BFu0c_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu16i)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu16i.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu0c_BFu16i");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu0c_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu16i, Us_BFu0c_BFu16i)
//============================================================================



static void Test_Us_BFu0c_BFu16ll()
{
  {
    init_simple_test("Us_BFu0c_BFu16ll");
    static STRUCT_IF_C Us_BFu0c_BFu16ll lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu16ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu16ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu0c_BFu16ll");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu0c_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu16ll, Us_BFu0c_BFu16ll)
//============================================================================



static void Test_Us_BFu0c_BFu16s()
{
  {
    init_simple_test("Us_BFu0c_BFu16s");
    static STRUCT_IF_C Us_BFu0c_BFu16s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu16s)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu16s.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu0c_BFu16s");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu0c_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu16s, Us_BFu0c_BFu16s)
//============================================================================



static void Test_Us_BFu0c_BFu17i()
{
  {
    init_simple_test("Us_BFu0c_BFu17i");
    static STRUCT_IF_C Us_BFu0c_BFu17i lv;
    check2(sizeof(lv), 5, "sizeof(Us_BFu0c_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu17i)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu17i.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu0c_BFu17i");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu0c_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu17i, Us_BFu0c_BFu17i)
//============================================================================



static void Test_Us_BFu0c_BFu17ll()
{
  {
    init_simple_test("Us_BFu0c_BFu17ll");
    static STRUCT_IF_C Us_BFu0c_BFu17ll lv;
    check2(sizeof(lv), 5, "sizeof(Us_BFu0c_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu17ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu17ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu0c_BFu17ll");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu0c_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu17ll, Us_BFu0c_BFu17ll)
//============================================================================



static void Test_Us_BFu0c_BFu1c()
{
  {
    init_simple_test("Us_BFu0c_BFu1c");
    static STRUCT_IF_C Us_BFu0c_BFu1c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu1c)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu1c.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu0c_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu1c, Us_BFu0c_BFu1c)
//============================================================================



static void Test_Us_BFu0c_BFu1i()
{
  {
    init_simple_test("Us_BFu0c_BFu1i");
    static STRUCT_IF_C Us_BFu0c_BFu1i lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu1i)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu1i.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu0c_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu1i, Us_BFu0c_BFu1i)
//============================================================================



static void Test_Us_BFu0c_BFu1ll()
{
  {
    init_simple_test("Us_BFu0c_BFu1ll");
    static STRUCT_IF_C Us_BFu0c_BFu1ll lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu1ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu1ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu0c_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu1ll, Us_BFu0c_BFu1ll)
//============================================================================



static void Test_Us_BFu0c_BFu1s()
{
  {
    init_simple_test("Us_BFu0c_BFu1s");
    static STRUCT_IF_C Us_BFu0c_BFu1s lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu1s)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu1s.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu0c_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu1s, Us_BFu0c_BFu1s)
//============================================================================



static void Test_Us_BFu0c_BFu31i()
{
  {
    init_simple_test("Us_BFu0c_BFu31i");
    static STRUCT_IF_C Us_BFu0c_BFu31i lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0c_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu31i)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu31i.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu0c_BFu31i");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu0c_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu31i, Us_BFu0c_BFu31i)
//============================================================================



static void Test_Us_BFu0c_BFu31ll()
{
  {
    init_simple_test("Us_BFu0c_BFu31ll");
    static STRUCT_IF_C Us_BFu0c_BFu31ll lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0c_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu31ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu31ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu0c_BFu31ll");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu0c_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu31ll, Us_BFu0c_BFu31ll)
//============================================================================



static void Test_Us_BFu0c_BFu32i()
{
  {
    init_simple_test("Us_BFu0c_BFu32i");
    static STRUCT_IF_C Us_BFu0c_BFu32i lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0c_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu32i)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu32i.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu0c_BFu32i");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu0c_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu32i, Us_BFu0c_BFu32i)
//============================================================================



static void Test_Us_BFu0c_BFu32ll()
{
  {
    init_simple_test("Us_BFu0c_BFu32ll");
    static STRUCT_IF_C Us_BFu0c_BFu32ll lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0c_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu32ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu32ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu0c_BFu32ll");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu0c_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu32ll, Us_BFu0c_BFu32ll)
//============================================================================



static void Test_Us_BFu0c_BFu33()
{
  {
    init_simple_test("Us_BFu0c_BFu33");
    static STRUCT_IF_C Us_BFu0c_BFu33 lv;
    check2(sizeof(lv), 7, "sizeof(Us_BFu0c_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu33)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu33.v1");
    set_bf_and_test(lv, v2, 2, 0, 33, 1, "Us_BFu0c_BFu33");
    set_bf_and_test(lv, v2, 2, 0, 33, hide_ull(1LL<<32), "Us_BFu0c_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu33, Us_BFu0c_BFu33)
//============================================================================



static void Test_Us_BFu0c_BFu7c()
{
  {
    init_simple_test("Us_BFu0c_BFu7c");
    static STRUCT_IF_C Us_BFu0c_BFu7c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu7c)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu7c.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu0c_BFu7c");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu0c_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu7c, Us_BFu0c_BFu7c)
//============================================================================



static void Test_Us_BFu0c_BFu7i()
{
  {
    init_simple_test("Us_BFu0c_BFu7i");
    static STRUCT_IF_C Us_BFu0c_BFu7i lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu7i)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu7i.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu0c_BFu7i");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu0c_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu7i, Us_BFu0c_BFu7i)
//============================================================================



static void Test_Us_BFu0c_BFu7ll()
{
  {
    init_simple_test("Us_BFu0c_BFu7ll");
    static STRUCT_IF_C Us_BFu0c_BFu7ll lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu7ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu7ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu0c_BFu7ll");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu0c_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu7ll, Us_BFu0c_BFu7ll)
//============================================================================



static void Test_Us_BFu0c_BFu7s()
{
  {
    init_simple_test("Us_BFu0c_BFu7s");
    static STRUCT_IF_C Us_BFu0c_BFu7s lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu7s)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu7s.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu0c_BFu7s");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu0c_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu7s, Us_BFu0c_BFu7s)
//============================================================================



static void Test_Us_BFu0c_BFu8c()
{
  {
    init_simple_test("Us_BFu0c_BFu8c");
    static STRUCT_IF_C Us_BFu0c_BFu8c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu8c)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu8c.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu0c_BFu8c");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu0c_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu8c, Us_BFu0c_BFu8c)
//============================================================================



static void Test_Us_BFu0c_BFu8i()
{
  {
    init_simple_test("Us_BFu0c_BFu8i");
    static STRUCT_IF_C Us_BFu0c_BFu8i lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu8i)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu8i.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu0c_BFu8i");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu0c_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu8i, Us_BFu0c_BFu8i)
//============================================================================



static void Test_Us_BFu0c_BFu8ll()
{
  {
    init_simple_test("Us_BFu0c_BFu8ll");
    static STRUCT_IF_C Us_BFu0c_BFu8ll lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu8ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu8ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu0c_BFu8ll");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu0c_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu8ll, Us_BFu0c_BFu8ll)
//============================================================================



static void Test_Us_BFu0c_BFu8s()
{
  {
    init_simple_test("Us_BFu0c_BFu8s");
    static STRUCT_IF_C Us_BFu0c_BFu8s lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu8s)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu8s.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu0c_BFu8s");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu0c_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu8s, Us_BFu0c_BFu8s)
//============================================================================



static void Test_Us_BFu0c_BFu9i()
{
  {
    init_simple_test("Us_BFu0c_BFu9i");
    static STRUCT_IF_C Us_BFu0c_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu9i)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu9i.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu0c_BFu9i");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu0c_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu9i, Us_BFu0c_BFu9i)
//============================================================================



static void Test_Us_BFu0c_BFu9ll()
{
  {
    init_simple_test("Us_BFu0c_BFu9ll");
    static STRUCT_IF_C Us_BFu0c_BFu9ll lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu9ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu9ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu0c_BFu9ll");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu0c_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu9ll, Us_BFu0c_BFu9ll)
//============================================================================



static void Test_Us_BFu0c_BFu9s()
{
  {
    init_simple_test("Us_BFu0c_BFu9s");
    static STRUCT_IF_C Us_BFu0c_BFu9s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_BFu9s)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_BFu9s.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu0c_BFu9s");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu0c_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_BFu9s, Us_BFu0c_BFu9s)
//============================================================================



static void Test_Us_BFu0c_C()
{
  {
    init_simple_test("Us_BFu0c_C");
    static STRUCT_IF_C Us_BFu0c_C lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_C)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_C)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_C.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_C, Us_BFu0c_C)
//============================================================================



static void Test_Us_BFu0c_D()
{
  {
    init_simple_test("Us_BFu0c_D");
    static STRUCT_IF_C Us_BFu0c_D lv;
    check2(sizeof(lv), 10, "sizeof(Us_BFu0c_D)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_D)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_D.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_D, Us_BFu0c_D)
//============================================================================



static void Test_Us_BFu0c_F()
{
  {
    init_simple_test("Us_BFu0c_F");
    static STRUCT_IF_C Us_BFu0c_F lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0c_F)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_F)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_F.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_F, Us_BFu0c_F)
//============================================================================



static void Test_Us_BFu0c_I()
{
  {
    init_simple_test("Us_BFu0c_I");
    static STRUCT_IF_C Us_BFu0c_I lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0c_I)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_I)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_I.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_I, Us_BFu0c_I)
//============================================================================



static void Test_Us_BFu0c_Ip()
{
  {
    init_simple_test("Us_BFu0c_Ip");
    static STRUCT_IF_C Us_BFu0c_Ip lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0c_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_Ip)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_Ip.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_Ip, Us_BFu0c_Ip)
//============================================================================



static void Test_Us_BFu0c_L()
{
  {
    init_simple_test("Us_BFu0c_L");
    static STRUCT_IF_C Us_BFu0c_L lv;
    check2(sizeof(lv), 10, "sizeof(Us_BFu0c_L)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_L)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_L.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_L, Us_BFu0c_L)
//============================================================================



static void Test_Us_BFu0c_S()
{
  {
    init_simple_test("Us_BFu0c_S");
    static STRUCT_IF_C Us_BFu0c_S lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_S)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_S)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_S.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_S, Us_BFu0c_S)
//============================================================================



static void Test_Us_BFu0c_Uc()
{
  {
    init_simple_test("Us_BFu0c_Uc");
    static STRUCT_IF_C Us_BFu0c_Uc lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu0c_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_Uc)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_Uc.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_Uc, Us_BFu0c_Uc)
//============================================================================



static void Test_Us_BFu0c_Ui()
{
  {
    init_simple_test("Us_BFu0c_Ui");
    static STRUCT_IF_C Us_BFu0c_Ui lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0c_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_Ui)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_Ui.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_Ui, Us_BFu0c_Ui)
//============================================================================



static void Test_Us_BFu0c_Ul()
{
  {
    init_simple_test("Us_BFu0c_Ul");
    static STRUCT_IF_C Us_BFu0c_Ul lv;
    check2(sizeof(lv), 10, "sizeof(Us_BFu0c_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_Ul)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_Ul.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_Ul, Us_BFu0c_Ul)
//============================================================================



static void Test_Us_BFu0c_Us()
{
  {
    init_simple_test("Us_BFu0c_Us");
    static STRUCT_IF_C Us_BFu0c_Us lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_Us)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_Us.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_Us, Us_BFu0c_Us)
//============================================================================



static void Test_Us_BFu0c_Vp()
{
  {
    init_simple_test("Us_BFu0c_Vp");
    static STRUCT_IF_C Us_BFu0c_Vp lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0c_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu0c_Vp)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_Vp.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_Vp, Us_BFu0c_Vp)
//============================================================================



static void Test_Us_BFu0i()
{
  {
    init_simple_test("Us_BFu0i");
    static STRUCT_IF_C Us_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i, Us_BFu0i)
//============================================================================



static void Test_Us_BFu0i_BFu0c()
{
  {
    init_simple_test("Us_BFu0i_BFu0c");
    static STRUCT_IF_C Us_BFu0i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu0i_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu0c, Us_BFu0i_BFu0c)
//============================================================================



static void Test_Us_BFu0i_BFu0i()
{
  {
    init_simple_test("Us_BFu0i_BFu0i");
    static STRUCT_IF_C Us_BFu0i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu0i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu0i, Us_BFu0i_BFu0i)
//============================================================================



static void Test_Us_BFu0i_BFu0ll()
{
  {
    init_simple_test("Us_BFu0i_BFu0ll");
    static STRUCT_IF_C Us_BFu0i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu0i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu0ll, Us_BFu0i_BFu0ll)
//============================================================================



static void Test_Us_BFu0i_BFu0s()
{
  {
    init_simple_test("Us_BFu0i_BFu0s");
    static STRUCT_IF_C Us_BFu0i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu0i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu0s, Us_BFu0i_BFu0s)
//============================================================================



static void Test_Us_BFu0i_BFu15i()
{
  {
    init_simple_test("Us_BFu0i_BFu15i");
    static STRUCT_IF_C Us_BFu0i_BFu15i lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_BFu15i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu15i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 15, 1, "Us_BFu0i_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 15, hide_ull(1LL<<14), "Us_BFu0i_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu15i, Us_BFu0i_BFu15i)
//============================================================================



static void Test_Us_BFu0i_BFu15ll()
{
  {
    init_simple_test("Us_BFu0i_BFu15ll");
    static STRUCT_IF_C Us_BFu0i_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu15ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 15, 1, "Us_BFu0i_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 15, hide_ull(1LL<<14), "Us_BFu0i_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu15ll, Us_BFu0i_BFu15ll)
//============================================================================



static void Test_Us_BFu0i_BFu15s()
{
  {
    init_simple_test("Us_BFu0i_BFu15s");
    static STRUCT_IF_C Us_BFu0i_BFu15s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_BFu15s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu15s)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 15, 1, "Us_BFu0i_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 15, hide_ull(1LL<<14), "Us_BFu0i_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu15s, Us_BFu0i_BFu15s)
//============================================================================



static void Test_Us_BFu0i_BFu16i()
{
  {
    init_simple_test("Us_BFu0i_BFu16i");
    static STRUCT_IF_C Us_BFu0i_BFu16i lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_BFu16i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu16i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 16, 1, "Us_BFu0i_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 16, hide_ull(1LL<<15), "Us_BFu0i_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu16i, Us_BFu0i_BFu16i)
//============================================================================



static void Test_Us_BFu0i_BFu16ll()
{
  {
    init_simple_test("Us_BFu0i_BFu16ll");
    static STRUCT_IF_C Us_BFu0i_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu16ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 16, 1, "Us_BFu0i_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 16, hide_ull(1LL<<15), "Us_BFu0i_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu16ll, Us_BFu0i_BFu16ll)
//============================================================================



static void Test_Us_BFu0i_BFu16s()
{
  {
    init_simple_test("Us_BFu0i_BFu16s");
    static STRUCT_IF_C Us_BFu0i_BFu16s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_BFu16s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu16s)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 16, 1, "Us_BFu0i_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 16, hide_ull(1LL<<15), "Us_BFu0i_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu16s, Us_BFu0i_BFu16s)
//============================================================================



static void Test_Us_BFu0i_BFu17i()
{
  {
    init_simple_test("Us_BFu0i_BFu17i");
    static STRUCT_IF_C Us_BFu0i_BFu17i lv;
    check2(sizeof(lv), ABISELECT(7,7), "sizeof(Us_BFu0i_BFu17i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu17i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 17, 1, "Us_BFu0i_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 17, hide_ull(1LL<<16), "Us_BFu0i_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu17i, Us_BFu0i_BFu17i)
//============================================================================



static void Test_Us_BFu0i_BFu17ll()
{
  {
    init_simple_test("Us_BFu0i_BFu17ll");
    static STRUCT_IF_C Us_BFu0i_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(7,7), "sizeof(Us_BFu0i_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu17ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 17, 1, "Us_BFu0i_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 17, hide_ull(1LL<<16), "Us_BFu0i_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu17ll, Us_BFu0i_BFu17ll)
//============================================================================



static void Test_Us_BFu0i_BFu1c()
{
  {
    init_simple_test("Us_BFu0i_BFu1c");
    static STRUCT_IF_C Us_BFu0i_BFu1c lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu1c)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 1, 1, "Us_BFu0i_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu1c, Us_BFu0i_BFu1c)
//============================================================================



static void Test_Us_BFu0i_BFu1i()
{
  {
    init_simple_test("Us_BFu0i_BFu1i");
    static STRUCT_IF_C Us_BFu0i_BFu1i lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu1i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu1i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 1, 1, "Us_BFu0i_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu1i, Us_BFu0i_BFu1i)
//============================================================================



static void Test_Us_BFu0i_BFu1ll()
{
  {
    init_simple_test("Us_BFu0i_BFu1ll");
    static STRUCT_IF_C Us_BFu0i_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu1ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 1, 1, "Us_BFu0i_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu1ll, Us_BFu0i_BFu1ll)
//============================================================================



static void Test_Us_BFu0i_BFu1s()
{
  {
    init_simple_test("Us_BFu0i_BFu1s");
    static STRUCT_IF_C Us_BFu0i_BFu1s lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu1s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu1s)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 1, 1, "Us_BFu0i_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu1s, Us_BFu0i_BFu1s)
//============================================================================



static void Test_Us_BFu0i_BFu31i()
{
  {
    init_simple_test("Us_BFu0i_BFu31i");
    static STRUCT_IF_C Us_BFu0i_BFu31i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu0i_BFu31i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu31i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 31, 1, "Us_BFu0i_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 31, hide_ull(1LL<<30), "Us_BFu0i_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu31i, Us_BFu0i_BFu31i)
//============================================================================



static void Test_Us_BFu0i_BFu31ll()
{
  {
    init_simple_test("Us_BFu0i_BFu31ll");
    static STRUCT_IF_C Us_BFu0i_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu0i_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu31ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 31, 1, "Us_BFu0i_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 31, hide_ull(1LL<<30), "Us_BFu0i_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu31ll, Us_BFu0i_BFu31ll)
//============================================================================



static void Test_Us_BFu0i_BFu32i()
{
  {
    init_simple_test("Us_BFu0i_BFu32i");
    static STRUCT_IF_C Us_BFu0i_BFu32i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu0i_BFu32i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu32i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 32, 1, "Us_BFu0i_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 32, hide_ull(1LL<<31), "Us_BFu0i_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu32i, Us_BFu0i_BFu32i)
//============================================================================



static void Test_Us_BFu0i_BFu32ll()
{
  {
    init_simple_test("Us_BFu0i_BFu32ll");
    static STRUCT_IF_C Us_BFu0i_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu0i_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu32ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 32, 1, "Us_BFu0i_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 32, hide_ull(1LL<<31), "Us_BFu0i_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu32ll, Us_BFu0i_BFu32ll)
//============================================================================



static void Test_Us_BFu0i_BFu33()
{
  {
    init_simple_test("Us_BFu0i_BFu33");
    static STRUCT_IF_C Us_BFu0i_BFu33 lv;
    check2(sizeof(lv), ABISELECT(9,9), "sizeof(Us_BFu0i_BFu33)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu33)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 33, 1, "Us_BFu0i_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 33, hide_ull(1LL<<32), "Us_BFu0i_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu33, Us_BFu0i_BFu33)
//============================================================================



static void Test_Us_BFu0i_BFu7c()
{
  {
    init_simple_test("Us_BFu0i_BFu7c");
    static STRUCT_IF_C Us_BFu0i_BFu7c lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu7c)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 7, 1, "Us_BFu0i_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 7, hide_ull(1LL<<6), "Us_BFu0i_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu7c, Us_BFu0i_BFu7c)
//============================================================================



static void Test_Us_BFu0i_BFu7i()
{
  {
    init_simple_test("Us_BFu0i_BFu7i");
    static STRUCT_IF_C Us_BFu0i_BFu7i lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu7i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu7i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 7, 1, "Us_BFu0i_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 7, hide_ull(1LL<<6), "Us_BFu0i_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu7i, Us_BFu0i_BFu7i)
//============================================================================



static void Test_Us_BFu0i_BFu7ll()
{
  {
    init_simple_test("Us_BFu0i_BFu7ll");
    static STRUCT_IF_C Us_BFu0i_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu7ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 7, 1, "Us_BFu0i_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 7, hide_ull(1LL<<6), "Us_BFu0i_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu7ll, Us_BFu0i_BFu7ll)
//============================================================================



static void Test_Us_BFu0i_BFu7s()
{
  {
    init_simple_test("Us_BFu0i_BFu7s");
    static STRUCT_IF_C Us_BFu0i_BFu7s lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu7s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu7s)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 7, 1, "Us_BFu0i_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 7, hide_ull(1LL<<6), "Us_BFu0i_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu7s, Us_BFu0i_BFu7s)
//============================================================================



static void Test_Us_BFu0i_BFu8c()
{
  {
    init_simple_test("Us_BFu0i_BFu8c");
    static STRUCT_IF_C Us_BFu0i_BFu8c lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu8c)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 8, 1, "Us_BFu0i_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 8, hide_ull(1LL<<7), "Us_BFu0i_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu8c, Us_BFu0i_BFu8c)
//============================================================================



static void Test_Us_BFu0i_BFu8i()
{
  {
    init_simple_test("Us_BFu0i_BFu8i");
    static STRUCT_IF_C Us_BFu0i_BFu8i lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu8i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu8i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 8, 1, "Us_BFu0i_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 8, hide_ull(1LL<<7), "Us_BFu0i_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu8i, Us_BFu0i_BFu8i)
//============================================================================



static void Test_Us_BFu0i_BFu8ll()
{
  {
    init_simple_test("Us_BFu0i_BFu8ll");
    static STRUCT_IF_C Us_BFu0i_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu8ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 8, 1, "Us_BFu0i_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 8, hide_ull(1LL<<7), "Us_BFu0i_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu8ll, Us_BFu0i_BFu8ll)
//============================================================================



static void Test_Us_BFu0i_BFu8s()
{
  {
    init_simple_test("Us_BFu0i_BFu8s");
    static STRUCT_IF_C Us_BFu0i_BFu8s lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_BFu8s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu8s)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 8, 1, "Us_BFu0i_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 8, hide_ull(1LL<<7), "Us_BFu0i_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu8s, Us_BFu0i_BFu8s)
//============================================================================



static void Test_Us_BFu0i_BFu9i()
{
  {
    init_simple_test("Us_BFu0i_BFu9i");
    static STRUCT_IF_C Us_BFu0i_BFu9i lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_BFu9i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu9i)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 9, 1, "Us_BFu0i_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 9, hide_ull(1LL<<8), "Us_BFu0i_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu9i, Us_BFu0i_BFu9i)
//============================================================================



static void Test_Us_BFu0i_BFu9ll()
{
  {
    init_simple_test("Us_BFu0i_BFu9ll");
    static STRUCT_IF_C Us_BFu0i_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu9ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 9, 1, "Us_BFu0i_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 9, hide_ull(1LL<<8), "Us_BFu0i_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu9ll, Us_BFu0i_BFu9ll)
//============================================================================



static void Test_Us_BFu0i_BFu9s()
{
  {
    init_simple_test("Us_BFu0i_BFu9s");
    static STRUCT_IF_C Us_BFu0i_BFu9s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_BFu9s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_BFu9s)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 9, 1, "Us_BFu0i_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(4,4), 0, 9, hide_ull(1LL<<8), "Us_BFu0i_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_BFu9s, Us_BFu0i_BFu9s)
//============================================================================



static void Test_Us_BFu0i_C()
{
  {
    init_simple_test("Us_BFu0i_C");
    static STRUCT_IF_C Us_BFu0i_C lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_C)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_C.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_C, Us_BFu0i_C)
//============================================================================



static void Test_Us_BFu0i_D()
{
  {
    init_simple_test("Us_BFu0i_D");
    static STRUCT_IF_C Us_BFu0i_D lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Us_BFu0i_D)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_D)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_D.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_D, Us_BFu0i_D)
//============================================================================



static void Test_Us_BFu0i_F()
{
  {
    init_simple_test("Us_BFu0i_F");
    static STRUCT_IF_C Us_BFu0i_F lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu0i_F)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_F)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_F.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_F, Us_BFu0i_F)
//============================================================================



static void Test_Us_BFu0i_I()
{
  {
    init_simple_test("Us_BFu0i_I");
    static STRUCT_IF_C Us_BFu0i_I lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu0i_I)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_I)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_I.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_I, Us_BFu0i_I)
//============================================================================



static void Test_Us_BFu0i_Ip()
{
  {
    init_simple_test("Us_BFu0i_Ip");
    static STRUCT_IF_C Us_BFu0i_Ip lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_BFu0i_Ip)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_Ip)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_Ip, Us_BFu0i_Ip)
//============================================================================



static void Test_Us_BFu0i_L()
{
  {
    init_simple_test("Us_BFu0i_L");
    static STRUCT_IF_C Us_BFu0i_L lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Us_BFu0i_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_L)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_L.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_L, Us_BFu0i_L)
//============================================================================



static void Test_Us_BFu0i_S()
{
  {
    init_simple_test("Us_BFu0i_S");
    static STRUCT_IF_C Us_BFu0i_S lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_S)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_S.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_S, Us_BFu0i_S)
//============================================================================



static void Test_Us_BFu0i_Uc()
{
  {
    init_simple_test("Us_BFu0i_Uc");
    static STRUCT_IF_C Us_BFu0i_Uc lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0i_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_Uc)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_Uc, Us_BFu0i_Uc)
//============================================================================



static void Test_Us_BFu0i_Ui()
{
  {
    init_simple_test("Us_BFu0i_Ui");
    static STRUCT_IF_C Us_BFu0i_Ui lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu0i_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_Ui)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_Ui, Us_BFu0i_Ui)
//============================================================================



static void Test_Us_BFu0i_Ul()
{
  {
    init_simple_test("Us_BFu0i_Ul");
    static STRUCT_IF_C Us_BFu0i_Ul lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Us_BFu0i_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_Ul)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_Ul, Us_BFu0i_Ul)
//============================================================================



static void Test_Us_BFu0i_Us()
{
  {
    init_simple_test("Us_BFu0i_Us");
    static STRUCT_IF_C Us_BFu0i_Us lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_Us)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_Us.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_Us, Us_BFu0i_Us)
//============================================================================



static void Test_Us_BFu0i_Vp()
{
  {
    init_simple_test("Us_BFu0i_Vp");
    static STRUCT_IF_C Us_BFu0i_Vp lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_BFu0i_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0i_Vp)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(4,4), "Us_BFu0i_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_Vp, Us_BFu0i_Vp)
//============================================================================



static void Test_Us_BFu0ll()
{
  {
    init_simple_test("Us_BFu0ll");
    static STRUCT_IF_C Us_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll, Us_BFu0ll)
//============================================================================



static void Test_Us_BFu0ll_BFu0c()
{
  {
    init_simple_test("Us_BFu0ll_BFu0c");
    static STRUCT_IF_C Us_BFu0ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu0ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu0c, Us_BFu0ll_BFu0c)
//============================================================================



static void Test_Us_BFu0ll_BFu0i()
{
  {
    init_simple_test("Us_BFu0ll_BFu0i");
    static STRUCT_IF_C Us_BFu0ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu0ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu0i, Us_BFu0ll_BFu0i)
//============================================================================



static void Test_Us_BFu0ll_BFu0ll()
{
  {
    init_simple_test("Us_BFu0ll_BFu0ll");
    static STRUCT_IF_C Us_BFu0ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu0ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu0ll, Us_BFu0ll_BFu0ll)
//============================================================================



static void Test_Us_BFu0ll_BFu0s()
{
  {
    init_simple_test("Us_BFu0ll_BFu0s");
    static STRUCT_IF_C Us_BFu0ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu0ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu0s, Us_BFu0ll_BFu0s)
//============================================================================



static void Test_Us_BFu0ll_BFu15i()
{
  {
    init_simple_test("Us_BFu0ll_BFu15i");
    static STRUCT_IF_C Us_BFu0ll_BFu15i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_BFu15i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu15i)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Us_BFu0ll_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Us_BFu0ll_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu15i, Us_BFu0ll_BFu15i)
//============================================================================



static void Test_Us_BFu0ll_BFu15ll()
{
  {
    init_simple_test("Us_BFu0ll_BFu15ll");
    static STRUCT_IF_C Us_BFu0ll_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu15ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Us_BFu0ll_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Us_BFu0ll_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu15ll, Us_BFu0ll_BFu15ll)
//============================================================================



static void Test_Us_BFu0ll_BFu15s()
{
  {
    init_simple_test("Us_BFu0ll_BFu15s");
    static STRUCT_IF_C Us_BFu0ll_BFu15s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_BFu15s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu15s)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Us_BFu0ll_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Us_BFu0ll_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu15s, Us_BFu0ll_BFu15s)
//============================================================================



static void Test_Us_BFu0ll_BFu16i()
{
  {
    init_simple_test("Us_BFu0ll_BFu16i");
    static STRUCT_IF_C Us_BFu0ll_BFu16i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_BFu16i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu16i)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Us_BFu0ll_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Us_BFu0ll_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu16i, Us_BFu0ll_BFu16i)
//============================================================================



static void Test_Us_BFu0ll_BFu16ll()
{
  {
    init_simple_test("Us_BFu0ll_BFu16ll");
    static STRUCT_IF_C Us_BFu0ll_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu16ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Us_BFu0ll_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Us_BFu0ll_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu16ll, Us_BFu0ll_BFu16ll)
//============================================================================



static void Test_Us_BFu0ll_BFu16s()
{
  {
    init_simple_test("Us_BFu0ll_BFu16s");
    static STRUCT_IF_C Us_BFu0ll_BFu16s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_BFu16s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu16s)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Us_BFu0ll_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Us_BFu0ll_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu16s, Us_BFu0ll_BFu16s)
//============================================================================



static void Test_Us_BFu0ll_BFu17i()
{
  {
    init_simple_test("Us_BFu0ll_BFu17i");
    static STRUCT_IF_C Us_BFu0ll_BFu17i lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Us_BFu0ll_BFu17i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu17i)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Us_BFu0ll_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Us_BFu0ll_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu17i, Us_BFu0ll_BFu17i)
//============================================================================



static void Test_Us_BFu0ll_BFu17ll()
{
  {
    init_simple_test("Us_BFu0ll_BFu17ll");
    static STRUCT_IF_C Us_BFu0ll_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Us_BFu0ll_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu17ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Us_BFu0ll_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Us_BFu0ll_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu17ll, Us_BFu0ll_BFu17ll)
//============================================================================



static void Test_Us_BFu0ll_BFu1c()
{
  {
    init_simple_test("Us_BFu0ll_BFu1c");
    static STRUCT_IF_C Us_BFu0ll_BFu1c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu1c)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Us_BFu0ll_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu1c, Us_BFu0ll_BFu1c)
//============================================================================



static void Test_Us_BFu0ll_BFu1i()
{
  {
    init_simple_test("Us_BFu0ll_BFu1i");
    static STRUCT_IF_C Us_BFu0ll_BFu1i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu1i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu1i)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Us_BFu0ll_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu1i, Us_BFu0ll_BFu1i)
//============================================================================



static void Test_Us_BFu0ll_BFu1ll()
{
  {
    init_simple_test("Us_BFu0ll_BFu1ll");
    static STRUCT_IF_C Us_BFu0ll_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu1ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Us_BFu0ll_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu1ll, Us_BFu0ll_BFu1ll)
//============================================================================



static void Test_Us_BFu0ll_BFu1s()
{
  {
    init_simple_test("Us_BFu0ll_BFu1s");
    static STRUCT_IF_C Us_BFu0ll_BFu1s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu1s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu1s)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Us_BFu0ll_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu1s, Us_BFu0ll_BFu1s)
//============================================================================



static void Test_Us_BFu0ll_BFu31i()
{
  {
    init_simple_test("Us_BFu0ll_BFu31i");
    static STRUCT_IF_C Us_BFu0ll_BFu31i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_BFu0ll_BFu31i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu31i)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Us_BFu0ll_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Us_BFu0ll_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu31i, Us_BFu0ll_BFu31i)
//============================================================================



static void Test_Us_BFu0ll_BFu31ll()
{
  {
    init_simple_test("Us_BFu0ll_BFu31ll");
    static STRUCT_IF_C Us_BFu0ll_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_BFu0ll_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu31ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Us_BFu0ll_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Us_BFu0ll_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu31ll, Us_BFu0ll_BFu31ll)
//============================================================================



static void Test_Us_BFu0ll_BFu32i()
{
  {
    init_simple_test("Us_BFu0ll_BFu32i");
    static STRUCT_IF_C Us_BFu0ll_BFu32i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_BFu0ll_BFu32i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu32i)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Us_BFu0ll_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Us_BFu0ll_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu32i, Us_BFu0ll_BFu32i)
//============================================================================



static void Test_Us_BFu0ll_BFu32ll()
{
  {
    init_simple_test("Us_BFu0ll_BFu32ll");
    static STRUCT_IF_C Us_BFu0ll_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_BFu0ll_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu32ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Us_BFu0ll_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Us_BFu0ll_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu32ll, Us_BFu0ll_BFu32ll)
//============================================================================



static void Test_Us_BFu0ll_BFu33()
{
  {
    init_simple_test("Us_BFu0ll_BFu33");
    static STRUCT_IF_C Us_BFu0ll_BFu33 lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Us_BFu0ll_BFu33)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu33)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Us_BFu0ll_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Us_BFu0ll_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu33, Us_BFu0ll_BFu33)
//============================================================================



static void Test_Us_BFu0ll_BFu7c()
{
  {
    init_simple_test("Us_BFu0ll_BFu7c");
    static STRUCT_IF_C Us_BFu0ll_BFu7c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu7c)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Us_BFu0ll_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Us_BFu0ll_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu7c, Us_BFu0ll_BFu7c)
//============================================================================



static void Test_Us_BFu0ll_BFu7i()
{
  {
    init_simple_test("Us_BFu0ll_BFu7i");
    static STRUCT_IF_C Us_BFu0ll_BFu7i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu7i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu7i)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Us_BFu0ll_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Us_BFu0ll_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu7i, Us_BFu0ll_BFu7i)
//============================================================================



static void Test_Us_BFu0ll_BFu7ll()
{
  {
    init_simple_test("Us_BFu0ll_BFu7ll");
    static STRUCT_IF_C Us_BFu0ll_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu7ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Us_BFu0ll_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Us_BFu0ll_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu7ll, Us_BFu0ll_BFu7ll)
//============================================================================



static void Test_Us_BFu0ll_BFu7s()
{
  {
    init_simple_test("Us_BFu0ll_BFu7s");
    static STRUCT_IF_C Us_BFu0ll_BFu7s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu7s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu7s)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Us_BFu0ll_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Us_BFu0ll_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu7s, Us_BFu0ll_BFu7s)
//============================================================================



static void Test_Us_BFu0ll_BFu8c()
{
  {
    init_simple_test("Us_BFu0ll_BFu8c");
    static STRUCT_IF_C Us_BFu0ll_BFu8c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu8c)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Us_BFu0ll_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Us_BFu0ll_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu8c, Us_BFu0ll_BFu8c)
//============================================================================



static void Test_Us_BFu0ll_BFu8i()
{
  {
    init_simple_test("Us_BFu0ll_BFu8i");
    static STRUCT_IF_C Us_BFu0ll_BFu8i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu8i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu8i)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Us_BFu0ll_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Us_BFu0ll_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu8i, Us_BFu0ll_BFu8i)
//============================================================================



static void Test_Us_BFu0ll_BFu8ll()
{
  {
    init_simple_test("Us_BFu0ll_BFu8ll");
    static STRUCT_IF_C Us_BFu0ll_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu8ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Us_BFu0ll_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Us_BFu0ll_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu8ll, Us_BFu0ll_BFu8ll)
//============================================================================



static void Test_Us_BFu0ll_BFu8s()
{
  {
    init_simple_test("Us_BFu0ll_BFu8s");
    static STRUCT_IF_C Us_BFu0ll_BFu8s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_BFu8s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu8s)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Us_BFu0ll_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Us_BFu0ll_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu8s, Us_BFu0ll_BFu8s)
//============================================================================



static void Test_Us_BFu0ll_BFu9i()
{
  {
    init_simple_test("Us_BFu0ll_BFu9i");
    static STRUCT_IF_C Us_BFu0ll_BFu9i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_BFu9i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu9i)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Us_BFu0ll_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Us_BFu0ll_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu9i, Us_BFu0ll_BFu9i)
//============================================================================



static void Test_Us_BFu0ll_BFu9ll()
{
  {
    init_simple_test("Us_BFu0ll_BFu9ll");
    static STRUCT_IF_C Us_BFu0ll_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu9ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Us_BFu0ll_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Us_BFu0ll_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu9ll, Us_BFu0ll_BFu9ll)
//============================================================================



static void Test_Us_BFu0ll_BFu9s()
{
  {
    init_simple_test("Us_BFu0ll_BFu9s");
    static STRUCT_IF_C Us_BFu0ll_BFu9s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_BFu9s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_BFu9s)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Us_BFu0ll_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Us_BFu0ll_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_BFu9s, Us_BFu0ll_BFu9s)
//============================================================================



static void Test_Us_BFu0ll_C()
{
  {
    init_simple_test("Us_BFu0ll_C");
    static STRUCT_IF_C Us_BFu0ll_C lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_C)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_C, Us_BFu0ll_C)
//============================================================================



static void Test_Us_BFu0ll_D()
{
  {
    init_simple_test("Us_BFu0ll_D");
    static STRUCT_IF_C Us_BFu0ll_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Us_BFu0ll_D)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_D)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_D, Us_BFu0ll_D)
//============================================================================



static void Test_Us_BFu0ll_F()
{
  {
    init_simple_test("Us_BFu0ll_F");
    static STRUCT_IF_C Us_BFu0ll_F lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_BFu0ll_F)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_F)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_F, Us_BFu0ll_F)
//============================================================================



static void Test_Us_BFu0ll_I()
{
  {
    init_simple_test("Us_BFu0ll_I");
    static STRUCT_IF_C Us_BFu0ll_I lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_BFu0ll_I)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_I)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_I, Us_BFu0ll_I)
//============================================================================



static void Test_Us_BFu0ll_Ip()
{
  {
    init_simple_test("Us_BFu0ll_Ip");
    static STRUCT_IF_C Us_BFu0ll_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Us_BFu0ll_Ip)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_Ip)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_Ip, Us_BFu0ll_Ip)
//============================================================================



static void Test_Us_BFu0ll_L()
{
  {
    init_simple_test("Us_BFu0ll_L");
    static STRUCT_IF_C Us_BFu0ll_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Us_BFu0ll_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_L)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_L, Us_BFu0ll_L)
//============================================================================



static void Test_Us_BFu0ll_S()
{
  {
    init_simple_test("Us_BFu0ll_S");
    static STRUCT_IF_C Us_BFu0ll_S lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_S)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_S, Us_BFu0ll_S)
//============================================================================



static void Test_Us_BFu0ll_Uc()
{
  {
    init_simple_test("Us_BFu0ll_Uc");
    static STRUCT_IF_C Us_BFu0ll_Uc lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Us_BFu0ll_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_Uc)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_Uc, Us_BFu0ll_Uc)
//============================================================================



static void Test_Us_BFu0ll_Ui()
{
  {
    init_simple_test("Us_BFu0ll_Ui");
    static STRUCT_IF_C Us_BFu0ll_Ui lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_BFu0ll_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_Ui)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_Ui, Us_BFu0ll_Ui)
//============================================================================



static void Test_Us_BFu0ll_Ul()
{
  {
    init_simple_test("Us_BFu0ll_Ul");
    static STRUCT_IF_C Us_BFu0ll_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Us_BFu0ll_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_Ul)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_Ul, Us_BFu0ll_Ul)
//============================================================================



static void Test_Us_BFu0ll_Us()
{
  {
    init_simple_test("Us_BFu0ll_Us");
    static STRUCT_IF_C Us_BFu0ll_Us lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_Us)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_Us, Us_BFu0ll_Us)
//============================================================================



static void Test_Us_BFu0ll_Vp()
{
  {
    init_simple_test("Us_BFu0ll_Vp");
    static STRUCT_IF_C Us_BFu0ll_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Us_BFu0ll_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0ll_Vp)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_Vp, Us_BFu0ll_Vp)
//============================================================================



static void Test_Us_BFu0s()
{
  {
    init_simple_test("Us_BFu0s");
    static STRUCT_IF_C Us_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Us_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s, Us_BFu0s)
//============================================================================



static void Test_Us_BFu0s_BFu0c()
{
  {
    init_simple_test("Us_BFu0s_BFu0c");
    static STRUCT_IF_C Us_BFu0s_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(Us_BFu0s_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu0c, Us_BFu0s_BFu0c)
//============================================================================



static void Test_Us_BFu0s_BFu0i()
{
  {
    init_simple_test("Us_BFu0s_BFu0i");
    static STRUCT_IF_C Us_BFu0s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu0s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu0i, Us_BFu0s_BFu0i)
//============================================================================



static void Test_Us_BFu0s_BFu0ll()
{
  {
    init_simple_test("Us_BFu0s_BFu0ll");
    static STRUCT_IF_C Us_BFu0s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu0s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu0ll, Us_BFu0s_BFu0ll)
//============================================================================



static void Test_Us_BFu0s_BFu0s()
{
  {
    init_simple_test("Us_BFu0s_BFu0s");
    static STRUCT_IF_C Us_BFu0s_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Us_BFu0s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu0s, Us_BFu0s_BFu0s)
//============================================================================



static void Test_Us_BFu0s_BFu15i()
{
  {
    init_simple_test("Us_BFu0s_BFu15i");
    static STRUCT_IF_C Us_BFu0s_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_BFu15i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu15i)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu15i.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu0s_BFu15i");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu0s_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu15i, Us_BFu0s_BFu15i)
//============================================================================



static void Test_Us_BFu0s_BFu15ll()
{
  {
    init_simple_test("Us_BFu0s_BFu15ll");
    static STRUCT_IF_C Us_BFu0s_BFu15ll lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu15ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu15ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu0s_BFu15ll");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu0s_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu15ll, Us_BFu0s_BFu15ll)
//============================================================================



static void Test_Us_BFu0s_BFu15s()
{
  {
    init_simple_test("Us_BFu0s_BFu15s");
    static STRUCT_IF_C Us_BFu0s_BFu15s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_BFu15s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu15s)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu15s.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu0s_BFu15s");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu0s_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu15s, Us_BFu0s_BFu15s)
//============================================================================



static void Test_Us_BFu0s_BFu16i()
{
  {
    init_simple_test("Us_BFu0s_BFu16i");
    static STRUCT_IF_C Us_BFu0s_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_BFu16i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu16i)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu16i.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu0s_BFu16i");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu0s_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu16i, Us_BFu0s_BFu16i)
//============================================================================



static void Test_Us_BFu0s_BFu16ll()
{
  {
    init_simple_test("Us_BFu0s_BFu16ll");
    static STRUCT_IF_C Us_BFu0s_BFu16ll lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu16ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu16ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu0s_BFu16ll");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu0s_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu16ll, Us_BFu0s_BFu16ll)
//============================================================================



static void Test_Us_BFu0s_BFu16s()
{
  {
    init_simple_test("Us_BFu0s_BFu16s");
    static STRUCT_IF_C Us_BFu0s_BFu16s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_BFu16s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu16s)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu16s.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu0s_BFu16s");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu0s_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu16s, Us_BFu0s_BFu16s)
//============================================================================



static void Test_Us_BFu0s_BFu17i()
{
  {
    init_simple_test("Us_BFu0s_BFu17i");
    static STRUCT_IF_C Us_BFu0s_BFu17i lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0s_BFu17i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu17i)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu17i.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu0s_BFu17i");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu0s_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu17i, Us_BFu0s_BFu17i)
//============================================================================



static void Test_Us_BFu0s_BFu17ll()
{
  {
    init_simple_test("Us_BFu0s_BFu17ll");
    static STRUCT_IF_C Us_BFu0s_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Us_BFu0s_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu17ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu17ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu0s_BFu17ll");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu0s_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu17ll, Us_BFu0s_BFu17ll)
//============================================================================



static void Test_Us_BFu0s_BFu1c()
{
  {
    init_simple_test("Us_BFu0s_BFu1c");
    static STRUCT_IF_C Us_BFu0s_BFu1c lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu1c)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu1c.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu0s_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu1c, Us_BFu0s_BFu1c)
//============================================================================



static void Test_Us_BFu0s_BFu1i()
{
  {
    init_simple_test("Us_BFu0s_BFu1i");
    static STRUCT_IF_C Us_BFu0s_BFu1i lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu1i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu1i)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu1i.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu0s_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu1i, Us_BFu0s_BFu1i)
//============================================================================



static void Test_Us_BFu0s_BFu1ll()
{
  {
    init_simple_test("Us_BFu0s_BFu1ll");
    static STRUCT_IF_C Us_BFu0s_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu1ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu1ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu0s_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu1ll, Us_BFu0s_BFu1ll)
//============================================================================



static void Test_Us_BFu0s_BFu1s()
{
  {
    init_simple_test("Us_BFu0s_BFu1s");
    static STRUCT_IF_C Us_BFu0s_BFu1s lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu1s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu1s)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu1s.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu0s_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu1s, Us_BFu0s_BFu1s)
//============================================================================



static void Test_Us_BFu0s_BFu31i()
{
  {
    init_simple_test("Us_BFu0s_BFu31i");
    static STRUCT_IF_C Us_BFu0s_BFu31i lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0s_BFu31i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu31i)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu31i.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu0s_BFu31i");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu0s_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu31i, Us_BFu0s_BFu31i)
//============================================================================



static void Test_Us_BFu0s_BFu31ll()
{
  {
    init_simple_test("Us_BFu0s_BFu31ll");
    static STRUCT_IF_C Us_BFu0s_BFu31ll lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0s_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu31ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu31ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu0s_BFu31ll");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu0s_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu31ll, Us_BFu0s_BFu31ll)
//============================================================================



static void Test_Us_BFu0s_BFu32i()
{
  {
    init_simple_test("Us_BFu0s_BFu32i");
    static STRUCT_IF_C Us_BFu0s_BFu32i lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0s_BFu32i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu32i)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu32i.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu0s_BFu32i");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu0s_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu32i, Us_BFu0s_BFu32i)
//============================================================================



static void Test_Us_BFu0s_BFu32ll()
{
  {
    init_simple_test("Us_BFu0s_BFu32ll");
    static STRUCT_IF_C Us_BFu0s_BFu32ll lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0s_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu32ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu32ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu0s_BFu32ll");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu0s_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu32ll, Us_BFu0s_BFu32ll)
//============================================================================



static void Test_Us_BFu0s_BFu33()
{
  {
    init_simple_test("Us_BFu0s_BFu33");
    static STRUCT_IF_C Us_BFu0s_BFu33 lv;
    check2(sizeof(lv), ABISELECT(7,7), "sizeof(Us_BFu0s_BFu33)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu33)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu33.v1");
    set_bf_and_test(lv, v2, 2, 0, 33, 1, "Us_BFu0s_BFu33");
    set_bf_and_test(lv, v2, 2, 0, 33, hide_ull(1LL<<32), "Us_BFu0s_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu33, Us_BFu0s_BFu33)
//============================================================================



static void Test_Us_BFu0s_BFu7c()
{
  {
    init_simple_test("Us_BFu0s_BFu7c");
    static STRUCT_IF_C Us_BFu0s_BFu7c lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu7c)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu7c.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu0s_BFu7c");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu0s_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu7c, Us_BFu0s_BFu7c)
//============================================================================



static void Test_Us_BFu0s_BFu7i()
{
  {
    init_simple_test("Us_BFu0s_BFu7i");
    static STRUCT_IF_C Us_BFu0s_BFu7i lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu7i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu7i)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu7i.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu0s_BFu7i");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu0s_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu7i, Us_BFu0s_BFu7i)
//============================================================================



static void Test_Us_BFu0s_BFu7ll()
{
  {
    init_simple_test("Us_BFu0s_BFu7ll");
    static STRUCT_IF_C Us_BFu0s_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu7ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu7ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu0s_BFu7ll");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu0s_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu7ll, Us_BFu0s_BFu7ll)
//============================================================================



static void Test_Us_BFu0s_BFu7s()
{
  {
    init_simple_test("Us_BFu0s_BFu7s");
    static STRUCT_IF_C Us_BFu0s_BFu7s lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu7s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu7s)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu7s.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu0s_BFu7s");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu0s_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu7s, Us_BFu0s_BFu7s)
//============================================================================



static void Test_Us_BFu0s_BFu8c()
{
  {
    init_simple_test("Us_BFu0s_BFu8c");
    static STRUCT_IF_C Us_BFu0s_BFu8c lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu8c)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu8c.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu0s_BFu8c");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu0s_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu8c, Us_BFu0s_BFu8c)
//============================================================================



static void Test_Us_BFu0s_BFu8i()
{
  {
    init_simple_test("Us_BFu0s_BFu8i");
    static STRUCT_IF_C Us_BFu0s_BFu8i lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu8i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu8i)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu8i.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu0s_BFu8i");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu0s_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu8i, Us_BFu0s_BFu8i)
//============================================================================



static void Test_Us_BFu0s_BFu8ll()
{
  {
    init_simple_test("Us_BFu0s_BFu8ll");
    static STRUCT_IF_C Us_BFu0s_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu8ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu8ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu0s_BFu8ll");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu0s_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu8ll, Us_BFu0s_BFu8ll)
//============================================================================



static void Test_Us_BFu0s_BFu8s()
{
  {
    init_simple_test("Us_BFu0s_BFu8s");
    static STRUCT_IF_C Us_BFu0s_BFu8s lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_BFu8s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu8s)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu8s.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu0s_BFu8s");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu0s_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu8s, Us_BFu0s_BFu8s)
//============================================================================



static void Test_Us_BFu0s_BFu9i()
{
  {
    init_simple_test("Us_BFu0s_BFu9i");
    static STRUCT_IF_C Us_BFu0s_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_BFu9i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu9i)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu9i.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu0s_BFu9i");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu0s_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu9i, Us_BFu0s_BFu9i)
//============================================================================



static void Test_Us_BFu0s_BFu9ll()
{
  {
    init_simple_test("Us_BFu0s_BFu9ll");
    static STRUCT_IF_C Us_BFu0s_BFu9ll lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu9ll)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu9ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu0s_BFu9ll");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu0s_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu9ll, Us_BFu0s_BFu9ll)
//============================================================================



static void Test_Us_BFu0s_BFu9s()
{
  {
    init_simple_test("Us_BFu0s_BFu9s");
    static STRUCT_IF_C Us_BFu0s_BFu9s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_BFu9s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_BFu9s)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_BFu9s.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu0s_BFu9s");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu0s_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_BFu9s, Us_BFu0s_BFu9s)
//============================================================================



static void Test_Us_BFu0s_C()
{
  {
    init_simple_test("Us_BFu0s_C");
    static STRUCT_IF_C Us_BFu0s_C lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_C)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_C.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_C, Us_BFu0s_C)
//============================================================================



static void Test_Us_BFu0s_D()
{
  {
    init_simple_test("Us_BFu0s_D");
    static STRUCT_IF_C Us_BFu0s_D lv;
    check2(sizeof(lv), 10, "sizeof(Us_BFu0s_D)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_D)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_D.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_D, Us_BFu0s_D)
//============================================================================



static void Test_Us_BFu0s_F()
{
  {
    init_simple_test("Us_BFu0s_F");
    static STRUCT_IF_C Us_BFu0s_F lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0s_F)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_F)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_F.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_F, Us_BFu0s_F)
//============================================================================



static void Test_Us_BFu0s_I()
{
  {
    init_simple_test("Us_BFu0s_I");
    static STRUCT_IF_C Us_BFu0s_I lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0s_I)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_I)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_I.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_I, Us_BFu0s_I)
//============================================================================



static void Test_Us_BFu0s_Ip()
{
  {
    init_simple_test("Us_BFu0s_Ip");
    static STRUCT_IF_C Us_BFu0s_Ip lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0s_Ip)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_Ip)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_Ip.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_Ip, Us_BFu0s_Ip)
//============================================================================



static void Test_Us_BFu0s_L()
{
  {
    init_simple_test("Us_BFu0s_L");
    static STRUCT_IF_C Us_BFu0s_L lv;
    check2(sizeof(lv), 10, "sizeof(Us_BFu0s_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_L)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_L.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_L, Us_BFu0s_L)
//============================================================================



static void Test_Us_BFu0s_S()
{
  {
    init_simple_test("Us_BFu0s_S");
    static STRUCT_IF_C Us_BFu0s_S lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_S)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_S.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_S, Us_BFu0s_S)
//============================================================================



static void Test_Us_BFu0s_Uc()
{
  {
    init_simple_test("Us_BFu0s_Uc");
    static STRUCT_IF_C Us_BFu0s_Uc lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Us_BFu0s_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_Uc)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_Uc.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_Uc, Us_BFu0s_Uc)
//============================================================================



static void Test_Us_BFu0s_Ui()
{
  {
    init_simple_test("Us_BFu0s_Ui");
    static STRUCT_IF_C Us_BFu0s_Ui lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu0s_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_Ui)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_Ui.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_Ui, Us_BFu0s_Ui)
//============================================================================



static void Test_Us_BFu0s_Ul()
{
  {
    init_simple_test("Us_BFu0s_Ul");
    static STRUCT_IF_C Us_BFu0s_Ul lv;
    check2(sizeof(lv), 10, "sizeof(Us_BFu0s_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_Ul)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_Ul.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_Ul, Us_BFu0s_Ul)
//============================================================================



static void Test_Us_BFu0s_Us()
{
  {
    init_simple_test("Us_BFu0s_Us");
    static STRUCT_IF_C Us_BFu0s_Us lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_Us)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_Us.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_Us, Us_BFu0s_Us)
//============================================================================



static void Test_Us_BFu0s_Vp()
{
  {
    init_simple_test("Us_BFu0s_Vp");
    static STRUCT_IF_C Us_BFu0s_Vp lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0s_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu0s_Vp)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_Vp.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_Vp, Us_BFu0s_Vp)
//============================================================================



static void Test_Us_BFu15i_BFu0c()
{
  {
    init_simple_test("Us_BFu15i_BFu0c");
    static STRUCT_IF_C Us_BFu15i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu15i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu15i_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu15i_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15i_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu15i_BFu0c, Us_BFu15i_BFu0c)
//============================================================================



static void Test_Us_BFu15i_BFu0i()
{
  {
    init_simple_test("Us_BFu15i_BFu0i");
    static STRUCT_IF_C Us_BFu15i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu15i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu15i_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu15i_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15i_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu15i_BFu0i, Us_BFu15i_BFu0i)
//============================================================================



static void Test_Us_BFu15i_BFu0ll()
{
  {
    init_simple_test("Us_BFu15i_BFu0ll");
    static STRUCT_IF_C Us_BFu15i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu15i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu15i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu15i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15i_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu15i_BFu0ll, Us_BFu15i_BFu0ll)
//============================================================================



static void Test_Us_BFu15i_BFu0s()
{
  {
    init_simple_test("Us_BFu15i_BFu0s");
    static STRUCT_IF_C Us_BFu15i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu15i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu15i_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu15i_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15i_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu15i_BFu0s, Us_BFu15i_BFu0s)
//============================================================================



static void Test_Us_BFu15ll_BFu0c()
{
  {
    init_simple_test("Us_BFu15ll_BFu0c");
    static STRUCT_IF_C Us_BFu15ll_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu15ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu15ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu15ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15ll_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu15ll_BFu0c, Us_BFu15ll_BFu0c)
//============================================================================



static void Test_Us_BFu15ll_BFu0i()
{
  {
    init_simple_test("Us_BFu15ll_BFu0i");
    static STRUCT_IF_C Us_BFu15ll_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu15ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu15ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu15ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15ll_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu15ll_BFu0i, Us_BFu15ll_BFu0i)
//============================================================================



static void Test_Us_BFu15ll_BFu0ll()
{
  {
    init_simple_test("Us_BFu15ll_BFu0ll");
    static STRUCT_IF_C Us_BFu15ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu15ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu15ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu15ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15ll_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu15ll_BFu0ll, Us_BFu15ll_BFu0ll)
//============================================================================



static void Test_Us_BFu15ll_BFu0s()
{
  {
    init_simple_test("Us_BFu15ll_BFu0s");
    static STRUCT_IF_C Us_BFu15ll_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu15ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu15ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu15ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15ll_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu15ll_BFu0s, Us_BFu15ll_BFu0s)
//============================================================================



static void Test_Us_BFu15s_BFu0c()
{
  {
    init_simple_test("Us_BFu15s_BFu0c");
    static STRUCT_IF_C Us_BFu15s_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu15s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu15s_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu15s_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15s_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu15s_BFu0c, Us_BFu15s_BFu0c)
//============================================================================



static void Test_Us_BFu15s_BFu0i()
{
  {
    init_simple_test("Us_BFu15s_BFu0i");
    static STRUCT_IF_C Us_BFu15s_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu15s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu15s_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu15s_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15s_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu15s_BFu0i, Us_BFu15s_BFu0i)
//============================================================================



static void Test_Us_BFu15s_BFu0ll()
{
  {
    init_simple_test("Us_BFu15s_BFu0ll");
    static STRUCT_IF_C Us_BFu15s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu15s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu15s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu15s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15s_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu15s_BFu0ll, Us_BFu15s_BFu0ll)
//============================================================================



static void Test_Us_BFu15s_BFu0s()
{
  {
    init_simple_test("Us_BFu15s_BFu0s");
    static STRUCT_IF_C Us_BFu15s_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu15s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu15s_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu15s_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Us_BFu15s_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Us_BFu15s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu15s_BFu0s, Us_BFu15s_BFu0s)
//============================================================================



static void Test_Us_BFu16i_BFu0c()
{
  {
    init_simple_test("Us_BFu16i_BFu0c");
    static STRUCT_IF_C Us_BFu16i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu16i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu16i_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu16i_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16i_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu16i_BFu0c, Us_BFu16i_BFu0c)
//============================================================================



static void Test_Us_BFu16i_BFu0i()
{
  {
    init_simple_test("Us_BFu16i_BFu0i");
    static STRUCT_IF_C Us_BFu16i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu16i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu16i_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu16i_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16i_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu16i_BFu0i, Us_BFu16i_BFu0i)
//============================================================================



static void Test_Us_BFu16i_BFu0ll()
{
  {
    init_simple_test("Us_BFu16i_BFu0ll");
    static STRUCT_IF_C Us_BFu16i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu16i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu16i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu16i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16i_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu16i_BFu0ll, Us_BFu16i_BFu0ll)
//============================================================================



static void Test_Us_BFu16i_BFu0s()
{
  {
    init_simple_test("Us_BFu16i_BFu0s");
    static STRUCT_IF_C Us_BFu16i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu16i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu16i_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu16i_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16i_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu16i_BFu0s, Us_BFu16i_BFu0s)
//============================================================================



static void Test_Us_BFu16ll_BFu0c()
{
  {
    init_simple_test("Us_BFu16ll_BFu0c");
    static STRUCT_IF_C Us_BFu16ll_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu16ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu16ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu16ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16ll_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu16ll_BFu0c, Us_BFu16ll_BFu0c)
//============================================================================



static void Test_Us_BFu16ll_BFu0i()
{
  {
    init_simple_test("Us_BFu16ll_BFu0i");
    static STRUCT_IF_C Us_BFu16ll_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu16ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu16ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu16ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16ll_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu16ll_BFu0i, Us_BFu16ll_BFu0i)
//============================================================================



static void Test_Us_BFu16ll_BFu0ll()
{
  {
    init_simple_test("Us_BFu16ll_BFu0ll");
    static STRUCT_IF_C Us_BFu16ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu16ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu16ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu16ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16ll_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu16ll_BFu0ll, Us_BFu16ll_BFu0ll)
//============================================================================



static void Test_Us_BFu16ll_BFu0s()
{
  {
    init_simple_test("Us_BFu16ll_BFu0s");
    static STRUCT_IF_C Us_BFu16ll_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu16ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu16ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu16ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16ll_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu16ll_BFu0s, Us_BFu16ll_BFu0s)
//============================================================================



static void Test_Us_BFu16s_BFu0c()
{
  {
    init_simple_test("Us_BFu16s_BFu0c");
    static STRUCT_IF_C Us_BFu16s_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu16s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu16s_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu16s_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16s_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu16s_BFu0c, Us_BFu16s_BFu0c)
//============================================================================



static void Test_Us_BFu16s_BFu0i()
{
  {
    init_simple_test("Us_BFu16s_BFu0i");
    static STRUCT_IF_C Us_BFu16s_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu16s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu16s_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu16s_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16s_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu16s_BFu0i, Us_BFu16s_BFu0i)
//============================================================================



static void Test_Us_BFu16s_BFu0ll()
{
  {
    init_simple_test("Us_BFu16s_BFu0ll");
    static STRUCT_IF_C Us_BFu16s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu16s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu16s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu16s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16s_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu16s_BFu0ll, Us_BFu16s_BFu0ll)
//============================================================================



static void Test_Us_BFu16s_BFu0s()
{
  {
    init_simple_test("Us_BFu16s_BFu0s");
    static STRUCT_IF_C Us_BFu16s_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu16s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu16s_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu16s_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Us_BFu16s_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Us_BFu16s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu16s_BFu0s, Us_BFu16s_BFu0s)
//============================================================================



static void Test_Us_BFu17i_BFu0c()
{
  {
    init_simple_test("Us_BFu17i_BFu0c");
    static STRUCT_IF_C Us_BFu17i_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Us_BFu17i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu17i_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu17i_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu17i_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu17i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu17i_BFu0c, Us_BFu17i_BFu0c)
//============================================================================



static void Test_Us_BFu17i_BFu0i()
{
  {
    init_simple_test("Us_BFu17i_BFu0i");
    static STRUCT_IF_C Us_BFu17i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu17i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu17i_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu17i_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu17i_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu17i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu17i_BFu0i, Us_BFu17i_BFu0i)
//============================================================================



static void Test_Us_BFu17i_BFu0ll()
{
  {
    init_simple_test("Us_BFu17i_BFu0ll");
    static STRUCT_IF_C Us_BFu17i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu17i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu17i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu17i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu17i_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu17i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu17i_BFu0ll, Us_BFu17i_BFu0ll)
//============================================================================



static void Test_Us_BFu17i_BFu0s()
{
  {
    init_simple_test("Us_BFu17i_BFu0s");
    static STRUCT_IF_C Us_BFu17i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu17i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu17i_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu17i_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu17i_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu17i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu17i_BFu0s, Us_BFu17i_BFu0s)
//============================================================================



static void Test_Us_BFu17ll_BFu0c()
{
  {
    init_simple_test("Us_BFu17ll_BFu0c");
    static STRUCT_IF_C Us_BFu17ll_BFu0c lv;
    check2(sizeof(lv), 5, "sizeof(Us_BFu17ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu17ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu17ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu17ll_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu17ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu17ll_BFu0c, Us_BFu17ll_BFu0c)
//============================================================================



static void Test_Us_BFu17ll_BFu0i()
{
  {
    init_simple_test("Us_BFu17ll_BFu0i");
    static STRUCT_IF_C Us_BFu17ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu17ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu17ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu17ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu17ll_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu17ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu17ll_BFu0i, Us_BFu17ll_BFu0i)
//============================================================================



static void Test_Us_BFu17ll_BFu0ll()
{
  {
    init_simple_test("Us_BFu17ll_BFu0ll");
    static STRUCT_IF_C Us_BFu17ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu17ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu17ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu17ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu17ll_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu17ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu17ll_BFu0ll, Us_BFu17ll_BFu0ll)
//============================================================================



static void Test_Us_BFu17ll_BFu0s()
{
  {
    init_simple_test("Us_BFu17ll_BFu0s");
    static STRUCT_IF_C Us_BFu17ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu17ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu17ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu17ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "Us_BFu17ll_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "Us_BFu17ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu17ll_BFu0s, Us_BFu17ll_BFu0s)
//============================================================================



static void Test_Us_BFu1c_BFu0c()
{
  {
    init_simple_test("Us_BFu1c_BFu0c");
    static STRUCT_IF_C Us_BFu1c_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu1c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu1c_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu1c_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1c_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu1c_BFu0c, Us_BFu1c_BFu0c)
//============================================================================



static void Test_Us_BFu1c_BFu0i()
{
  {
    init_simple_test("Us_BFu1c_BFu0i");
    static STRUCT_IF_C Us_BFu1c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu1c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1c_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu1c_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1c_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu1c_BFu0i, Us_BFu1c_BFu0i)
//============================================================================



static void Test_Us_BFu1c_BFu0ll()
{
  {
    init_simple_test("Us_BFu1c_BFu0ll");
    static STRUCT_IF_C Us_BFu1c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu1c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu1c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1c_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu1c_BFu0ll, Us_BFu1c_BFu0ll)
//============================================================================



static void Test_Us_BFu1c_BFu0s()
{
  {
    init_simple_test("Us_BFu1c_BFu0s");
    static STRUCT_IF_C Us_BFu1c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu1c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1c_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu1c_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1c_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu1c_BFu0s, Us_BFu1c_BFu0s)
//============================================================================



static void Test_Us_BFu1i_BFu0c()
{
  {
    init_simple_test("Us_BFu1i_BFu0c");
    static STRUCT_IF_C Us_BFu1i_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu1i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu1i_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu1i_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu1i_BFu0c, Us_BFu1i_BFu0c)
//============================================================================



static void Test_Us_BFu1i_BFu0i()
{
  {
    init_simple_test("Us_BFu1i_BFu0i");
    static STRUCT_IF_C Us_BFu1i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu1i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1i_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu1i_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu1i_BFu0i, Us_BFu1i_BFu0i)
//============================================================================



static void Test_Us_BFu1i_BFu0ll()
{
  {
    init_simple_test("Us_BFu1i_BFu0ll");
    static STRUCT_IF_C Us_BFu1i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu1i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu1i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu1i_BFu0ll, Us_BFu1i_BFu0ll)
//============================================================================



static void Test_Us_BFu1i_BFu0s()
{
  {
    init_simple_test("Us_BFu1i_BFu0s");
    static STRUCT_IF_C Us_BFu1i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu1i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1i_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu1i_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu1i_BFu0s, Us_BFu1i_BFu0s)
//============================================================================



static void Test_Us_BFu1ll_BFu0c()
{
  {
    init_simple_test("Us_BFu1ll_BFu0c");
    static STRUCT_IF_C Us_BFu1ll_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu1ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu1ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu1ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu1ll_BFu0c, Us_BFu1ll_BFu0c)
//============================================================================



static void Test_Us_BFu1ll_BFu0i()
{
  {
    init_simple_test("Us_BFu1ll_BFu0i");
    static STRUCT_IF_C Us_BFu1ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu1ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu1ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu1ll_BFu0i, Us_BFu1ll_BFu0i)
//============================================================================



static void Test_Us_BFu1ll_BFu0ll()
{
  {
    init_simple_test("Us_BFu1ll_BFu0ll");
    static STRUCT_IF_C Us_BFu1ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu1ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu1ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu1ll_BFu0ll, Us_BFu1ll_BFu0ll)
//============================================================================



static void Test_Us_BFu1ll_BFu0s()
{
  {
    init_simple_test("Us_BFu1ll_BFu0s");
    static STRUCT_IF_C Us_BFu1ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu1ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu1ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu1ll_BFu0s, Us_BFu1ll_BFu0s)
//============================================================================



static void Test_Us_BFu1s_BFu0c()
{
  {
    init_simple_test("Us_BFu1s_BFu0c");
    static STRUCT_IF_C Us_BFu1s_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu1s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu1s_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu1s_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu1s_BFu0c, Us_BFu1s_BFu0c)
//============================================================================



static void Test_Us_BFu1s_BFu0i()
{
  {
    init_simple_test("Us_BFu1s_BFu0i");
    static STRUCT_IF_C Us_BFu1s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu1s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1s_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu1s_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu1s_BFu0i, Us_BFu1s_BFu0i)
//============================================================================



static void Test_Us_BFu1s_BFu0ll()
{
  {
    init_simple_test("Us_BFu1s_BFu0ll");
    static STRUCT_IF_C Us_BFu1s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu1s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu1s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu1s_BFu0ll, Us_BFu1s_BFu0ll)
//============================================================================



static void Test_Us_BFu1s_BFu0s()
{
  {
    init_simple_test("Us_BFu1s_BFu0s");
    static STRUCT_IF_C Us_BFu1s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu1s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu1s_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu1s_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "Us_BFu1s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu1s_BFu0s, Us_BFu1s_BFu0s)
//============================================================================



static void Test_Us_BFu31i_BFu0c()
{
  {
    init_simple_test("Us_BFu31i_BFu0c");
    static STRUCT_IF_C Us_BFu31i_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu31i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu31i_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu31i_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu31i_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu31i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu31i_BFu0c, Us_BFu31i_BFu0c)
//============================================================================



static void Test_Us_BFu31i_BFu0i()
{
  {
    init_simple_test("Us_BFu31i_BFu0i");
    static STRUCT_IF_C Us_BFu31i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu31i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu31i_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu31i_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu31i_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu31i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu31i_BFu0i, Us_BFu31i_BFu0i)
//============================================================================



static void Test_Us_BFu31i_BFu0ll()
{
  {
    init_simple_test("Us_BFu31i_BFu0ll");
    static STRUCT_IF_C Us_BFu31i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu31i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu31i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu31i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu31i_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu31i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu31i_BFu0ll, Us_BFu31i_BFu0ll)
//============================================================================



static void Test_Us_BFu31i_BFu0s()
{
  {
    init_simple_test("Us_BFu31i_BFu0s");
    static STRUCT_IF_C Us_BFu31i_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu31i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu31i_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu31i_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu31i_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu31i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu31i_BFu0s, Us_BFu31i_BFu0s)
//============================================================================



static void Test_Us_BFu31ll_BFu0c()
{
  {
    init_simple_test("Us_BFu31ll_BFu0c");
    static STRUCT_IF_C Us_BFu31ll_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu31ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu31ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu31ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu31ll_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu31ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu31ll_BFu0c, Us_BFu31ll_BFu0c)
//============================================================================



static void Test_Us_BFu31ll_BFu0i()
{
  {
    init_simple_test("Us_BFu31ll_BFu0i");
    static STRUCT_IF_C Us_BFu31ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu31ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu31ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu31ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu31ll_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu31ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu31ll_BFu0i, Us_BFu31ll_BFu0i)
//============================================================================



static void Test_Us_BFu31ll_BFu0ll()
{
  {
    init_simple_test("Us_BFu31ll_BFu0ll");
    static STRUCT_IF_C Us_BFu31ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu31ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu31ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu31ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu31ll_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu31ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu31ll_BFu0ll, Us_BFu31ll_BFu0ll)
//============================================================================



static void Test_Us_BFu31ll_BFu0s()
{
  {
    init_simple_test("Us_BFu31ll_BFu0s");
    static STRUCT_IF_C Us_BFu31ll_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu31ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu31ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu31ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "Us_BFu31ll_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "Us_BFu31ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu31ll_BFu0s, Us_BFu31ll_BFu0s)
//============================================================================



static void Test_Us_BFu32i_BFu0c()
{
  {
    init_simple_test("Us_BFu32i_BFu0c");
    static STRUCT_IF_C Us_BFu32i_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu32i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu32i_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu32i_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu32i_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu32i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu32i_BFu0c, Us_BFu32i_BFu0c)
//============================================================================



static void Test_Us_BFu32i_BFu0i()
{
  {
    init_simple_test("Us_BFu32i_BFu0i");
    static STRUCT_IF_C Us_BFu32i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu32i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu32i_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu32i_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu32i_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu32i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu32i_BFu0i, Us_BFu32i_BFu0i)
//============================================================================



static void Test_Us_BFu32i_BFu0ll()
{
  {
    init_simple_test("Us_BFu32i_BFu0ll");
    static STRUCT_IF_C Us_BFu32i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu32i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu32i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu32i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu32i_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu32i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu32i_BFu0ll, Us_BFu32i_BFu0ll)
//============================================================================



static void Test_Us_BFu32i_BFu0s()
{
  {
    init_simple_test("Us_BFu32i_BFu0s");
    static STRUCT_IF_C Us_BFu32i_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu32i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu32i_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu32i_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu32i_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu32i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu32i_BFu0s, Us_BFu32i_BFu0s)
//============================================================================



static void Test_Us_BFu32ll_BFu0c()
{
  {
    init_simple_test("Us_BFu32ll_BFu0c");
    static STRUCT_IF_C Us_BFu32ll_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu32ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu32ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu32ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu32ll_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu32ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu32ll_BFu0c, Us_BFu32ll_BFu0c)
//============================================================================



static void Test_Us_BFu32ll_BFu0i()
{
  {
    init_simple_test("Us_BFu32ll_BFu0i");
    static STRUCT_IF_C Us_BFu32ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu32ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu32ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu32ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu32ll_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu32ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu32ll_BFu0i, Us_BFu32ll_BFu0i)
//============================================================================



static void Test_Us_BFu32ll_BFu0ll()
{
  {
    init_simple_test("Us_BFu32ll_BFu0ll");
    static STRUCT_IF_C Us_BFu32ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu32ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu32ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu32ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu32ll_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu32ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu32ll_BFu0ll, Us_BFu32ll_BFu0ll)
//============================================================================



static void Test_Us_BFu32ll_BFu0s()
{
  {
    init_simple_test("Us_BFu32ll_BFu0s");
    static STRUCT_IF_C Us_BFu32ll_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Us_BFu32ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu32ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu32ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "Us_BFu32ll_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "Us_BFu32ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu32ll_BFu0s, Us_BFu32ll_BFu0s)
//============================================================================



static void Test_Us_BFu33_BFu0c()
{
  {
    init_simple_test("Us_BFu33_BFu0c");
    static STRUCT_IF_C Us_BFu33_BFu0c lv;
    check2(sizeof(lv), 7, "sizeof(Us_BFu33_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu33_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu33_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 33, 1, "Us_BFu33_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 33, hide_ull(1LL<<32), "Us_BFu33_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu33_BFu0c, Us_BFu33_BFu0c)
//============================================================================



static void Test_Us_BFu33_BFu0i()
{
  {
    init_simple_test("Us_BFu33_BFu0i");
    static STRUCT_IF_C Us_BFu33_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu33_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu33_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu33_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 33, 1, "Us_BFu33_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 33, hide_ull(1LL<<32), "Us_BFu33_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu33_BFu0i, Us_BFu33_BFu0i)
//============================================================================



static void Test_Us_BFu33_BFu0ll()
{
  {
    init_simple_test("Us_BFu33_BFu0ll");
    static STRUCT_IF_C Us_BFu33_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu33_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu33_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu33_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 33, 1, "Us_BFu33_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 33, hide_ull(1LL<<32), "Us_BFu33_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu33_BFu0ll, Us_BFu33_BFu0ll)
//============================================================================



static void Test_Us_BFu33_BFu0s()
{
  {
    init_simple_test("Us_BFu33_BFu0s");
    static STRUCT_IF_C Us_BFu33_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_BFu33_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu33_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu33_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 33, 1, "Us_BFu33_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 33, hide_ull(1LL<<32), "Us_BFu33_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu33_BFu0s, Us_BFu33_BFu0s)
//============================================================================



static void Test_Us_BFu7c_BFu0c()
{
  {
    init_simple_test("Us_BFu7c_BFu0c");
    static STRUCT_IF_C Us_BFu7c_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu7c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu7c_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu7c_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7c_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7c_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu7c_BFu0c, Us_BFu7c_BFu0c)
//============================================================================



static void Test_Us_BFu7c_BFu0i()
{
  {
    init_simple_test("Us_BFu7c_BFu0i");
    static STRUCT_IF_C Us_BFu7c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu7c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7c_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu7c_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7c_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7c_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu7c_BFu0i, Us_BFu7c_BFu0i)
//============================================================================



static void Test_Us_BFu7c_BFu0ll()
{
  {
    init_simple_test("Us_BFu7c_BFu0ll");
    static STRUCT_IF_C Us_BFu7c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu7c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu7c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7c_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7c_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu7c_BFu0ll, Us_BFu7c_BFu0ll)
//============================================================================



static void Test_Us_BFu7c_BFu0s()
{
  {
    init_simple_test("Us_BFu7c_BFu0s");
    static STRUCT_IF_C Us_BFu7c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu7c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7c_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu7c_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7c_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7c_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu7c_BFu0s, Us_BFu7c_BFu0s)
//============================================================================



static void Test_Us_BFu7i_BFu0c()
{
  {
    init_simple_test("Us_BFu7i_BFu0c");
    static STRUCT_IF_C Us_BFu7i_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu7i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu7i_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu7i_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7i_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu7i_BFu0c, Us_BFu7i_BFu0c)
//============================================================================



static void Test_Us_BFu7i_BFu0i()
{
  {
    init_simple_test("Us_BFu7i_BFu0i");
    static STRUCT_IF_C Us_BFu7i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu7i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7i_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu7i_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7i_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu7i_BFu0i, Us_BFu7i_BFu0i)
//============================================================================



static void Test_Us_BFu7i_BFu0ll()
{
  {
    init_simple_test("Us_BFu7i_BFu0ll");
    static STRUCT_IF_C Us_BFu7i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu7i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu7i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7i_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu7i_BFu0ll, Us_BFu7i_BFu0ll)
//============================================================================



static void Test_Us_BFu7i_BFu0s()
{
  {
    init_simple_test("Us_BFu7i_BFu0s");
    static STRUCT_IF_C Us_BFu7i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu7i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7i_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu7i_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7i_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu7i_BFu0s, Us_BFu7i_BFu0s)
//============================================================================



static void Test_Us_BFu7ll_BFu0c()
{
  {
    init_simple_test("Us_BFu7ll_BFu0c");
    static STRUCT_IF_C Us_BFu7ll_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu7ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu7ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu7ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7ll_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu7ll_BFu0c, Us_BFu7ll_BFu0c)
//============================================================================



static void Test_Us_BFu7ll_BFu0i()
{
  {
    init_simple_test("Us_BFu7ll_BFu0i");
    static STRUCT_IF_C Us_BFu7ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu7ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu7ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7ll_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu7ll_BFu0i, Us_BFu7ll_BFu0i)
//============================================================================



static void Test_Us_BFu7ll_BFu0ll()
{
  {
    init_simple_test("Us_BFu7ll_BFu0ll");
    static STRUCT_IF_C Us_BFu7ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu7ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu7ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7ll_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu7ll_BFu0ll, Us_BFu7ll_BFu0ll)
//============================================================================



static void Test_Us_BFu7ll_BFu0s()
{
  {
    init_simple_test("Us_BFu7ll_BFu0s");
    static STRUCT_IF_C Us_BFu7ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu7ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu7ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7ll_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu7ll_BFu0s, Us_BFu7ll_BFu0s)
//============================================================================



static void Test_Us_BFu7s_BFu0c()
{
  {
    init_simple_test("Us_BFu7s_BFu0c");
    static STRUCT_IF_C Us_BFu7s_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu7s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu7s_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu7s_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7s_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu7s_BFu0c, Us_BFu7s_BFu0c)
//============================================================================



static void Test_Us_BFu7s_BFu0i()
{
  {
    init_simple_test("Us_BFu7s_BFu0i");
    static STRUCT_IF_C Us_BFu7s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu7s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7s_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu7s_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7s_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu7s_BFu0i, Us_BFu7s_BFu0i)
//============================================================================



static void Test_Us_BFu7s_BFu0ll()
{
  {
    init_simple_test("Us_BFu7s_BFu0ll");
    static STRUCT_IF_C Us_BFu7s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu7s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu7s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7s_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu7s_BFu0ll, Us_BFu7s_BFu0ll)
//============================================================================



static void Test_Us_BFu7s_BFu0s()
{
  {
    init_simple_test("Us_BFu7s_BFu0s");
    static STRUCT_IF_C Us_BFu7s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu7s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu7s_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu7s_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "Us_BFu7s_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "Us_BFu7s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu7s_BFu0s, Us_BFu7s_BFu0s)
//============================================================================



static void Test_Us_BFu8c_BFu0c()
{
  {
    init_simple_test("Us_BFu8c_BFu0c");
    static STRUCT_IF_C Us_BFu8c_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu8c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu8c_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu8c_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8c_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8c_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu8c_BFu0c, Us_BFu8c_BFu0c)
//============================================================================



static void Test_Us_BFu8c_BFu0i()
{
  {
    init_simple_test("Us_BFu8c_BFu0i");
    static STRUCT_IF_C Us_BFu8c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu8c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8c_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu8c_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8c_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8c_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu8c_BFu0i, Us_BFu8c_BFu0i)
//============================================================================



static void Test_Us_BFu8c_BFu0ll()
{
  {
    init_simple_test("Us_BFu8c_BFu0ll");
    static STRUCT_IF_C Us_BFu8c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu8c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu8c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8c_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8c_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu8c_BFu0ll, Us_BFu8c_BFu0ll)
//============================================================================



static void Test_Us_BFu8c_BFu0s()
{
  {
    init_simple_test("Us_BFu8c_BFu0s");
    static STRUCT_IF_C Us_BFu8c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu8c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8c_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu8c_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8c_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8c_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu8c_BFu0s, Us_BFu8c_BFu0s)
//============================================================================



static void Test_Us_BFu8i_BFu0c()
{
  {
    init_simple_test("Us_BFu8i_BFu0c");
    static STRUCT_IF_C Us_BFu8i_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu8i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu8i_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu8i_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8i_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu8i_BFu0c, Us_BFu8i_BFu0c)
//============================================================================



static void Test_Us_BFu8i_BFu0i()
{
  {
    init_simple_test("Us_BFu8i_BFu0i");
    static STRUCT_IF_C Us_BFu8i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu8i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8i_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu8i_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8i_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu8i_BFu0i, Us_BFu8i_BFu0i)
//============================================================================



static void Test_Us_BFu8i_BFu0ll()
{
  {
    init_simple_test("Us_BFu8i_BFu0ll");
    static STRUCT_IF_C Us_BFu8i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu8i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu8i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8i_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu8i_BFu0ll, Us_BFu8i_BFu0ll)
//============================================================================



static void Test_Us_BFu8i_BFu0s()
{
  {
    init_simple_test("Us_BFu8i_BFu0s");
    static STRUCT_IF_C Us_BFu8i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu8i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8i_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu8i_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8i_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu8i_BFu0s, Us_BFu8i_BFu0s)
//============================================================================



static void Test_Us_BFu8ll_BFu0c()
{
  {
    init_simple_test("Us_BFu8ll_BFu0c");
    static STRUCT_IF_C Us_BFu8ll_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu8ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu8ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu8ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8ll_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu8ll_BFu0c, Us_BFu8ll_BFu0c)
//============================================================================



static void Test_Us_BFu8ll_BFu0i()
{
  {
    init_simple_test("Us_BFu8ll_BFu0i");
    static STRUCT_IF_C Us_BFu8ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu8ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu8ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8ll_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu8ll_BFu0i, Us_BFu8ll_BFu0i)
//============================================================================



static void Test_Us_BFu8ll_BFu0ll()
{
  {
    init_simple_test("Us_BFu8ll_BFu0ll");
    static STRUCT_IF_C Us_BFu8ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu8ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu8ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8ll_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu8ll_BFu0ll, Us_BFu8ll_BFu0ll)
//============================================================================



static void Test_Us_BFu8ll_BFu0s()
{
  {
    init_simple_test("Us_BFu8ll_BFu0s");
    static STRUCT_IF_C Us_BFu8ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu8ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu8ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8ll_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu8ll_BFu0s, Us_BFu8ll_BFu0s)
//============================================================================



static void Test_Us_BFu8s_BFu0c()
{
  {
    init_simple_test("Us_BFu8s_BFu0c");
    static STRUCT_IF_C Us_BFu8s_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_BFu8s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu8s_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu8s_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8s_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu8s_BFu0c, Us_BFu8s_BFu0c)
//============================================================================



static void Test_Us_BFu8s_BFu0i()
{
  {
    init_simple_test("Us_BFu8s_BFu0i");
    static STRUCT_IF_C Us_BFu8s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu8s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8s_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu8s_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8s_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu8s_BFu0i, Us_BFu8s_BFu0i)
//============================================================================



static void Test_Us_BFu8s_BFu0ll()
{
  {
    init_simple_test("Us_BFu8s_BFu0ll");
    static STRUCT_IF_C Us_BFu8s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu8s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu8s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8s_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu8s_BFu0ll, Us_BFu8s_BFu0ll)
//============================================================================



static void Test_Us_BFu8s_BFu0s()
{
  {
    init_simple_test("Us_BFu8s_BFu0s");
    static STRUCT_IF_C Us_BFu8s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_BFu8s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu8s_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu8s_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "Us_BFu8s_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "Us_BFu8s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu8s_BFu0s, Us_BFu8s_BFu0s)
//============================================================================



static void Test_Us_BFu9i_BFu0c()
{
  {
    init_simple_test("Us_BFu9i_BFu0c");
    static STRUCT_IF_C Us_BFu9i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu9i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu9i_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu9i_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9i_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu9i_BFu0c, Us_BFu9i_BFu0c)
//============================================================================



static void Test_Us_BFu9i_BFu0i()
{
  {
    init_simple_test("Us_BFu9i_BFu0i");
    static STRUCT_IF_C Us_BFu9i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu9i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu9i_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu9i_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9i_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu9i_BFu0i, Us_BFu9i_BFu0i)
//============================================================================



static void Test_Us_BFu9i_BFu0ll()
{
  {
    init_simple_test("Us_BFu9i_BFu0ll");
    static STRUCT_IF_C Us_BFu9i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu9i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu9i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu9i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9i_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu9i_BFu0ll, Us_BFu9i_BFu0ll)
//============================================================================



static void Test_Us_BFu9i_BFu0s()
{
  {
    init_simple_test("Us_BFu9i_BFu0s");
    static STRUCT_IF_C Us_BFu9i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu9i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu9i_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu9i_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9i_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu9i_BFu0s, Us_BFu9i_BFu0s)
//============================================================================



static void Test_Us_BFu9ll_BFu0c()
{
  {
    init_simple_test("Us_BFu9ll_BFu0c");
    static STRUCT_IF_C Us_BFu9ll_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu9ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu9ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu9ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9ll_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu9ll_BFu0c, Us_BFu9ll_BFu0c)
//============================================================================



static void Test_Us_BFu9ll_BFu0i()
{
  {
    init_simple_test("Us_BFu9ll_BFu0i");
    static STRUCT_IF_C Us_BFu9ll_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu9ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu9ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu9ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9ll_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu9ll_BFu0i, Us_BFu9ll_BFu0i)
//============================================================================



static void Test_Us_BFu9ll_BFu0ll()
{
  {
    init_simple_test("Us_BFu9ll_BFu0ll");
    static STRUCT_IF_C Us_BFu9ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu9ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu9ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu9ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9ll_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu9ll_BFu0ll, Us_BFu9ll_BFu0ll)
//============================================================================



static void Test_Us_BFu9ll_BFu0s()
{
  {
    init_simple_test("Us_BFu9ll_BFu0s");
    static STRUCT_IF_C Us_BFu9ll_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu9ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu9ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu9ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9ll_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu9ll_BFu0s, Us_BFu9ll_BFu0s)
//============================================================================



static void Test_Us_BFu9s_BFu0c()
{
  {
    init_simple_test("Us_BFu9s_BFu0c");
    static STRUCT_IF_C Us_BFu9s_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu9s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_BFu9s_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_BFu9s_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9s_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu9s_BFu0c, Us_BFu9s_BFu0c)
//============================================================================



static void Test_Us_BFu9s_BFu0i()
{
  {
    init_simple_test("Us_BFu9s_BFu0i");
    static STRUCT_IF_C Us_BFu9s_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu9s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu9s_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_BFu9s_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9s_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu9s_BFu0i, Us_BFu9s_BFu0i)
//============================================================================



static void Test_Us_BFu9s_BFu0ll()
{
  {
    init_simple_test("Us_BFu9s_BFu0ll");
    static STRUCT_IF_C Us_BFu9s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu9s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu9s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_BFu9s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9s_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu9s_BFu0ll, Us_BFu9s_BFu0ll)
//============================================================================



static void Test_Us_BFu9s_BFu0s()
{
  {
    init_simple_test("Us_BFu9s_BFu0s");
    static STRUCT_IF_C Us_BFu9s_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu9s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_BFu9s_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_BFu9s_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Us_BFu9s_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Us_BFu9s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu9s_BFu0s, Us_BFu9s_BFu0s)
//============================================================================



static void Test_Us_C_BFu0c()
{
  {
    init_simple_test("Us_C_BFu0c");
    static STRUCT_IF_C Us_C_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_C_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_C_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_C_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_C_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_C_BFu0c, Us_C_BFu0c)
//============================================================================



static void Test_Us_C_BFu0i()
{
  {
    init_simple_test("Us_C_BFu0i");
    static STRUCT_IF_C Us_C_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_C_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_C_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_C_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_C_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_C_BFu0i, Us_C_BFu0i)
//============================================================================



static void Test_Us_C_BFu0ll()
{
  {
    init_simple_test("Us_C_BFu0ll");
    static STRUCT_IF_C Us_C_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_C_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_C_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_C_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_C_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_C_BFu0ll, Us_C_BFu0ll)
//============================================================================



static void Test_Us_C_BFu0s()
{
  {
    init_simple_test("Us_C_BFu0s");
    static STRUCT_IF_C Us_C_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_C_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_C_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_C_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_C_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_C_BFu0s, Us_C_BFu0s)
//============================================================================



static void Test_Us_D_BFu0c()
{
  {
    init_simple_test("Us_D_BFu0c");
    static STRUCT_IF_C Us_D_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Us_D_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_D_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_D_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_D_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_D_BFu0c, Us_D_BFu0c)
//============================================================================



static void Test_Us_D_BFu0i()
{
  {
    init_simple_test("Us_D_BFu0i");
    static STRUCT_IF_C Us_D_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Us_D_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_D_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_D_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_D_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_D_BFu0i, Us_D_BFu0i)
//============================================================================



static void Test_Us_D_BFu0ll()
{
  {
    init_simple_test("Us_D_BFu0ll");
    static STRUCT_IF_C Us_D_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Us_D_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_D_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_D_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_D_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_D_BFu0ll, Us_D_BFu0ll)
//============================================================================



static void Test_Us_D_BFu0s()
{
  {
    init_simple_test("Us_D_BFu0s");
    static STRUCT_IF_C Us_D_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Us_D_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_D_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_D_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_D_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_D_BFu0s, Us_D_BFu0s)
//============================================================================



static void Test_Us_F_BFu0c()
{
  {
    init_simple_test("Us_F_BFu0c");
    static STRUCT_IF_C Us_F_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Us_F_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_F_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_F_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_F_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_F_BFu0c, Us_F_BFu0c)
//============================================================================



static void Test_Us_F_BFu0i()
{
  {
    init_simple_test("Us_F_BFu0i");
    static STRUCT_IF_C Us_F_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_F_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_F_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_F_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_F_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_F_BFu0i, Us_F_BFu0i)
//============================================================================



static void Test_Us_F_BFu0ll()
{
  {
    init_simple_test("Us_F_BFu0ll");
    static STRUCT_IF_C Us_F_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_F_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_F_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_F_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_F_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_F_BFu0ll, Us_F_BFu0ll)
//============================================================================



static void Test_Us_F_BFu0s()
{
  {
    init_simple_test("Us_F_BFu0s");
    static STRUCT_IF_C Us_F_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Us_F_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_F_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_F_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_F_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_F_BFu0s, Us_F_BFu0s)
//============================================================================



static void Test_Us_I_BFu0c()
{
  {
    init_simple_test("Us_I_BFu0c");
    static STRUCT_IF_C Us_I_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Us_I_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_I_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_I_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_I_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_I_BFu0c, Us_I_BFu0c)
//============================================================================



static void Test_Us_I_BFu0i()
{
  {
    init_simple_test("Us_I_BFu0i");
    static STRUCT_IF_C Us_I_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_I_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_I_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_I_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_I_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_I_BFu0i, Us_I_BFu0i)
//============================================================================



static void Test_Us_I_BFu0ll()
{
  {
    init_simple_test("Us_I_BFu0ll");
    static STRUCT_IF_C Us_I_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_I_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_I_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_I_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_I_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_I_BFu0ll, Us_I_BFu0ll)
//============================================================================



static void Test_Us_I_BFu0s()
{
  {
    init_simple_test("Us_I_BFu0s");
    static STRUCT_IF_C Us_I_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Us_I_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_I_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_I_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_I_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_I_BFu0s, Us_I_BFu0s)
//============================================================================



static void Test_Us_Ip_BFu0c()
{
  {
    init_simple_test("Us_Ip_BFu0c");
    static STRUCT_IF_C Us_Ip_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_Ip_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Ip_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_Ip_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_Ip_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Ip_BFu0c, Us_Ip_BFu0c)
//============================================================================



static void Test_Us_Ip_BFu0i()
{
  {
    init_simple_test("Us_Ip_BFu0i");
    static STRUCT_IF_C Us_Ip_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_Ip_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Ip_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_Ip_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_Ip_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Ip_BFu0i, Us_Ip_BFu0i)
//============================================================================



static void Test_Us_Ip_BFu0ll()
{
  {
    init_simple_test("Us_Ip_BFu0ll");
    static STRUCT_IF_C Us_Ip_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Us_Ip_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Ip_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_Ip_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_Ip_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Ip_BFu0ll, Us_Ip_BFu0ll)
//============================================================================



static void Test_Us_Ip_BFu0s()
{
  {
    init_simple_test("Us_Ip_BFu0s");
    static STRUCT_IF_C Us_Ip_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_Ip_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Ip_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_Ip_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_Ip_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Ip_BFu0s, Us_Ip_BFu0s)
//============================================================================



static void Test_Us_L_BFu0c()
{
  {
    init_simple_test("Us_L_BFu0c");
    static STRUCT_IF_C Us_L_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Us_L_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_L_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_L_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_L_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_L_BFu0c, Us_L_BFu0c)
//============================================================================



static void Test_Us_L_BFu0i()
{
  {
    init_simple_test("Us_L_BFu0i");
    static STRUCT_IF_C Us_L_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Us_L_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_L_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_L_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_L_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_L_BFu0i, Us_L_BFu0i)
//============================================================================



static void Test_Us_L_BFu0ll()
{
  {
    init_simple_test("Us_L_BFu0ll");
    static STRUCT_IF_C Us_L_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Us_L_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_L_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_L_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_L_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_L_BFu0ll, Us_L_BFu0ll)
//============================================================================



static void Test_Us_L_BFu0s()
{
  {
    init_simple_test("Us_L_BFu0s");
    static STRUCT_IF_C Us_L_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Us_L_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_L_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_L_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_L_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_L_BFu0s, Us_L_BFu0s)
//============================================================================



static void Test_Us_S_BFu0c()
{
  {
    init_simple_test("Us_S_BFu0c");
    static STRUCT_IF_C Us_S_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_S_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_S_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_S_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_S_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_S_BFu0c, Us_S_BFu0c)
//============================================================================



static void Test_Us_S_BFu0i()
{
  {
    init_simple_test("Us_S_BFu0i");
    static STRUCT_IF_C Us_S_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_S_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_S_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_S_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_S_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_S_BFu0i, Us_S_BFu0i)
//============================================================================



static void Test_Us_S_BFu0ll()
{
  {
    init_simple_test("Us_S_BFu0ll");
    static STRUCT_IF_C Us_S_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_S_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_S_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_S_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_S_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_S_BFu0ll, Us_S_BFu0ll)
//============================================================================



static void Test_Us_S_BFu0s()
{
  {
    init_simple_test("Us_S_BFu0s");
    static STRUCT_IF_C Us_S_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_S_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_S_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_S_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_S_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_S_BFu0s, Us_S_BFu0s)
//============================================================================



static void Test_Us_Uc_BFu0c()
{
  {
    init_simple_test("Us_Uc_BFu0c");
    static STRUCT_IF_C Us_Uc_BFu0c lv;
    check2(sizeof(lv), 3, "sizeof(Us_Uc_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Uc_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_Uc_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_Uc_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Uc_BFu0c, Us_Uc_BFu0c)
//============================================================================



static void Test_Us_Uc_BFu0i()
{
  {
    init_simple_test("Us_Uc_BFu0i");
    static STRUCT_IF_C Us_Uc_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_Uc_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Uc_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_Uc_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_Uc_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Uc_BFu0i, Us_Uc_BFu0i)
//============================================================================



static void Test_Us_Uc_BFu0ll()
{
  {
    init_simple_test("Us_Uc_BFu0ll");
    static STRUCT_IF_C Us_Uc_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_Uc_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Uc_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_Uc_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_Uc_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Uc_BFu0ll, Us_Uc_BFu0ll)
//============================================================================



static void Test_Us_Uc_BFu0s()
{
  {
    init_simple_test("Us_Uc_BFu0s");
    static STRUCT_IF_C Us_Uc_BFu0s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Us_Uc_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Uc_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_Uc_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_Uc_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Uc_BFu0s, Us_Uc_BFu0s)
//============================================================================



static void Test_Us_Ui_BFu0c()
{
  {
    init_simple_test("Us_Ui_BFu0c");
    static STRUCT_IF_C Us_Ui_BFu0c lv;
    check2(sizeof(lv), 6, "sizeof(Us_Ui_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Ui_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_Ui_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_Ui_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Ui_BFu0c, Us_Ui_BFu0c)
//============================================================================



static void Test_Us_Ui_BFu0i()
{
  {
    init_simple_test("Us_Ui_BFu0i");
    static STRUCT_IF_C Us_Ui_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_Ui_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Ui_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_Ui_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_Ui_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Ui_BFu0i, Us_Ui_BFu0i)
//============================================================================



static void Test_Us_Ui_BFu0ll()
{
  {
    init_simple_test("Us_Ui_BFu0ll");
    static STRUCT_IF_C Us_Ui_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,8), "sizeof(Us_Ui_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Ui_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_Ui_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_Ui_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Ui_BFu0ll, Us_Ui_BFu0ll)
//============================================================================



static void Test_Us_Ui_BFu0s()
{
  {
    init_simple_test("Us_Ui_BFu0s");
    static STRUCT_IF_C Us_Ui_BFu0s lv;
    check2(sizeof(lv), 6, "sizeof(Us_Ui_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Ui_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_Ui_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_Ui_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Ui_BFu0s, Us_Ui_BFu0s)
//============================================================================



static void Test_Us_Ul_BFu0c()
{
  {
    init_simple_test("Us_Ul_BFu0c");
    static STRUCT_IF_C Us_Ul_BFu0c lv;
    check2(sizeof(lv), 10, "sizeof(Us_Ul_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Ul_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_Ul_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_Ul_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Ul_BFu0c, Us_Ul_BFu0c)
//============================================================================



static void Test_Us_Ul_BFu0i()
{
  {
    init_simple_test("Us_Ul_BFu0i");
    static STRUCT_IF_C Us_Ul_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,12), "sizeof(Us_Ul_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Ul_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_Ul_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_Ul_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Ul_BFu0i, Us_Ul_BFu0i)
//============================================================================



static void Test_Us_Ul_BFu0ll()
{
  {
    init_simple_test("Us_Ul_BFu0ll");
    static STRUCT_IF_C Us_Ul_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Us_Ul_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Ul_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_Ul_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_Ul_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Ul_BFu0ll, Us_Ul_BFu0ll)
//============================================================================



static void Test_Us_Ul_BFu0s()
{
  {
    init_simple_test("Us_Ul_BFu0s");
    static STRUCT_IF_C Us_Ul_BFu0s lv;
    check2(sizeof(lv), 10, "sizeof(Us_Ul_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Ul_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_Ul_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_Ul_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Ul_BFu0s, Us_Ul_BFu0s)
//============================================================================



static void Test_Us_Us_BFu0c()
{
  {
    init_simple_test("Us_Us_BFu0c");
    static STRUCT_IF_C Us_Us_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_Us_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Us_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_Us_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_Us_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Us_BFu0c, Us_Us_BFu0c)
//============================================================================



static void Test_Us_Us_BFu0i()
{
  {
    init_simple_test("Us_Us_BFu0i");
    static STRUCT_IF_C Us_Us_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_Us_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Us_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_Us_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_Us_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Us_BFu0i, Us_Us_BFu0i)
//============================================================================



static void Test_Us_Us_BFu0ll()
{
  {
    init_simple_test("Us_Us_BFu0ll");
    static STRUCT_IF_C Us_Us_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_Us_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Us_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_Us_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_Us_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Us_BFu0ll, Us_Us_BFu0ll)
//============================================================================



static void Test_Us_Us_BFu0s()
{
  {
    init_simple_test("Us_Us_BFu0s");
    static STRUCT_IF_C Us_Us_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_Us_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Us_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_Us_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_Us_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Us_BFu0s, Us_Us_BFu0s)
//============================================================================



static void Test_Us_Vp_BFu0c()
{
  {
    init_simple_test("Us_Vp_BFu0c");
    static STRUCT_IF_C Us_Vp_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_Vp_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Us_Vp_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_Vp_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_Vp_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Vp_BFu0c, Us_Vp_BFu0c)
//============================================================================



static void Test_Us_Vp_BFu0i()
{
  {
    init_simple_test("Us_Vp_BFu0i");
    static STRUCT_IF_C Us_Vp_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Us_Vp_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Vp_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_Vp_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_Vp_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Vp_BFu0i, Us_Vp_BFu0i)
//============================================================================



static void Test_Us_Vp_BFu0ll()
{
  {
    init_simple_test("Us_Vp_BFu0ll");
    static STRUCT_IF_C Us_Vp_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Us_Vp_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Vp_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_Vp_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_Vp_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Vp_BFu0ll, Us_Vp_BFu0ll)
//============================================================================



static void Test_Us_Vp_BFu0s()
{
  {
    init_simple_test("Us_Vp_BFu0s");
    static STRUCT_IF_C Us_Vp_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_Vp_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Us_Vp_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_Vp_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_Vp_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Vp_BFu0s, Us_Vp_BFu0s)
//============================================================================



static void Test_Vp_BFu0c()
{
  {
    init_simple_test("Vp_BFu0c");
    static STRUCT_IF_C Vp_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c, Vp_BFu0c)
//============================================================================



static void Test_Vp_BFu0c_BFu0c()
{
  {
    init_simple_test("Vp_BFu0c_BFu0c");
    static STRUCT_IF_C Vp_BFu0c_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu0c, Vp_BFu0c_BFu0c)
//============================================================================



static void Test_Vp_BFu0c_BFu0i()
{
  {
    init_simple_test("Vp_BFu0c_BFu0i");
    static STRUCT_IF_C Vp_BFu0c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0c_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu0i, Vp_BFu0c_BFu0i)
//============================================================================



static void Test_Vp_BFu0c_BFu0ll()
{
  {
    init_simple_test("Vp_BFu0c_BFu0ll");
    static STRUCT_IF_C Vp_BFu0c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu0ll, Vp_BFu0c_BFu0ll)
//============================================================================



static void Test_Vp_BFu0c_BFu0s()
{
  {
    init_simple_test("Vp_BFu0c_BFu0s");
    static STRUCT_IF_C Vp_BFu0c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0c_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu0s, Vp_BFu0c_BFu0s)
//============================================================================



static void Test_Vp_BFu0c_BFu15i()
{
  {
    init_simple_test("Vp_BFu0c_BFu15i");
    static STRUCT_IF_C Vp_BFu0c_BFu15i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_BFu15i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0c_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0c_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu15i, Vp_BFu0c_BFu15i)
//============================================================================



static void Test_Vp_BFu0c_BFu15ll()
{
  {
    init_simple_test("Vp_BFu0c_BFu15ll");
    static STRUCT_IF_C Vp_BFu0c_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_BFu15ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0c_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0c_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu15ll, Vp_BFu0c_BFu15ll)
//============================================================================



static void Test_Vp_BFu0c_BFu15s()
{
  {
    init_simple_test("Vp_BFu0c_BFu15s");
    static STRUCT_IF_C Vp_BFu0c_BFu15s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_BFu15s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0c_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0c_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu15s, Vp_BFu0c_BFu15s)
//============================================================================



static void Test_Vp_BFu0c_BFu16i()
{
  {
    init_simple_test("Vp_BFu0c_BFu16i");
    static STRUCT_IF_C Vp_BFu0c_BFu16i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_BFu16i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0c_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0c_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu16i, Vp_BFu0c_BFu16i)
//============================================================================



static void Test_Vp_BFu0c_BFu16ll()
{
  {
    init_simple_test("Vp_BFu0c_BFu16ll");
    static STRUCT_IF_C Vp_BFu0c_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_BFu16ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0c_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0c_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu16ll, Vp_BFu0c_BFu16ll)
//============================================================================



static void Test_Vp_BFu0c_BFu16s()
{
  {
    init_simple_test("Vp_BFu0c_BFu16s");
    static STRUCT_IF_C Vp_BFu0c_BFu16s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_BFu16s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0c_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0c_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu16s, Vp_BFu0c_BFu16s)
//============================================================================



static void Test_Vp_BFu0c_BFu17i()
{
  {
    init_simple_test("Vp_BFu0c_BFu17i");
    static STRUCT_IF_C Vp_BFu0c_BFu17i lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu0c_BFu17i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu0c_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu0c_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu17i, Vp_BFu0c_BFu17i)
//============================================================================



static void Test_Vp_BFu0c_BFu17ll()
{
  {
    init_simple_test("Vp_BFu0c_BFu17ll");
    static STRUCT_IF_C Vp_BFu0c_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu0c_BFu17ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu0c_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu0c_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu17ll, Vp_BFu0c_BFu17ll)
//============================================================================



static void Test_Vp_BFu0c_BFu1c()
{
  {
    init_simple_test("Vp_BFu0c_BFu1c");
    static STRUCT_IF_C Vp_BFu0c_BFu1c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0c_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu1c, Vp_BFu0c_BFu1c)
//============================================================================



static void Test_Vp_BFu0c_BFu1i()
{
  {
    init_simple_test("Vp_BFu0c_BFu1i");
    static STRUCT_IF_C Vp_BFu0c_BFu1i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu1i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0c_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu1i, Vp_BFu0c_BFu1i)
//============================================================================



static void Test_Vp_BFu0c_BFu1ll()
{
  {
    init_simple_test("Vp_BFu0c_BFu1ll");
    static STRUCT_IF_C Vp_BFu0c_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu1ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0c_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu1ll, Vp_BFu0c_BFu1ll)
//============================================================================



static void Test_Vp_BFu0c_BFu1s()
{
  {
    init_simple_test("Vp_BFu0c_BFu1s");
    static STRUCT_IF_C Vp_BFu0c_BFu1s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu1s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0c_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu1s, Vp_BFu0c_BFu1s)
//============================================================================



static void Test_Vp_BFu0c_BFu31i()
{
  {
    init_simple_test("Vp_BFu0c_BFu31i");
    static STRUCT_IF_C Vp_BFu0c_BFu31i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0c_BFu31i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu0c_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu0c_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu31i, Vp_BFu0c_BFu31i)
//============================================================================



static void Test_Vp_BFu0c_BFu31ll()
{
  {
    init_simple_test("Vp_BFu0c_BFu31ll");
    static STRUCT_IF_C Vp_BFu0c_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0c_BFu31ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu0c_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu0c_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu31ll, Vp_BFu0c_BFu31ll)
//============================================================================



static void Test_Vp_BFu0c_BFu32i()
{
  {
    init_simple_test("Vp_BFu0c_BFu32i");
    static STRUCT_IF_C Vp_BFu0c_BFu32i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0c_BFu32i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu0c_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu0c_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu32i, Vp_BFu0c_BFu32i)
//============================================================================



static void Test_Vp_BFu0c_BFu32ll()
{
  {
    init_simple_test("Vp_BFu0c_BFu32ll");
    static STRUCT_IF_C Vp_BFu0c_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0c_BFu32ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu0c_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu0c_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu32ll, Vp_BFu0c_BFu32ll)
//============================================================================



static void Test_Vp_BFu0c_BFu33()
{
  {
    init_simple_test("Vp_BFu0c_BFu33");
    static STRUCT_IF_C Vp_BFu0c_BFu33 lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_BFu0c_BFu33)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu0c_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu0c_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu33, Vp_BFu0c_BFu33)
//============================================================================



static void Test_Vp_BFu0c_BFu7c()
{
  {
    init_simple_test("Vp_BFu0c_BFu7c");
    static STRUCT_IF_C Vp_BFu0c_BFu7c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0c_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0c_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu7c, Vp_BFu0c_BFu7c)
//============================================================================



static void Test_Vp_BFu0c_BFu7i()
{
  {
    init_simple_test("Vp_BFu0c_BFu7i");
    static STRUCT_IF_C Vp_BFu0c_BFu7i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu7i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0c_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0c_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu7i, Vp_BFu0c_BFu7i)
//============================================================================



static void Test_Vp_BFu0c_BFu7ll()
{
  {
    init_simple_test("Vp_BFu0c_BFu7ll");
    static STRUCT_IF_C Vp_BFu0c_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu7ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0c_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0c_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu7ll, Vp_BFu0c_BFu7ll)
//============================================================================



static void Test_Vp_BFu0c_BFu7s()
{
  {
    init_simple_test("Vp_BFu0c_BFu7s");
    static STRUCT_IF_C Vp_BFu0c_BFu7s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu7s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0c_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0c_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu7s, Vp_BFu0c_BFu7s)
//============================================================================



static void Test_Vp_BFu0c_BFu8c()
{
  {
    init_simple_test("Vp_BFu0c_BFu8c");
    static STRUCT_IF_C Vp_BFu0c_BFu8c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0c_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0c_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu8c, Vp_BFu0c_BFu8c)
//============================================================================



static void Test_Vp_BFu0c_BFu8i()
{
  {
    init_simple_test("Vp_BFu0c_BFu8i");
    static STRUCT_IF_C Vp_BFu0c_BFu8i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu8i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0c_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0c_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu8i, Vp_BFu0c_BFu8i)
//============================================================================



static void Test_Vp_BFu0c_BFu8ll()
{
  {
    init_simple_test("Vp_BFu0c_BFu8ll");
    static STRUCT_IF_C Vp_BFu0c_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu8ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0c_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0c_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu8ll, Vp_BFu0c_BFu8ll)
//============================================================================



static void Test_Vp_BFu0c_BFu8s()
{
  {
    init_simple_test("Vp_BFu0c_BFu8s");
    static STRUCT_IF_C Vp_BFu0c_BFu8s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_BFu8s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0c_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0c_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu8s, Vp_BFu0c_BFu8s)
//============================================================================



static void Test_Vp_BFu0c_BFu9i()
{
  {
    init_simple_test("Vp_BFu0c_BFu9i");
    static STRUCT_IF_C Vp_BFu0c_BFu9i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_BFu9i)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0c_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0c_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu9i, Vp_BFu0c_BFu9i)
//============================================================================



static void Test_Vp_BFu0c_BFu9ll()
{
  {
    init_simple_test("Vp_BFu0c_BFu9ll");
    static STRUCT_IF_C Vp_BFu0c_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_BFu9ll)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0c_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0c_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu9ll, Vp_BFu0c_BFu9ll)
//============================================================================



static void Test_Vp_BFu0c_BFu9s()
{
  {
    init_simple_test("Vp_BFu0c_BFu9s");
    static STRUCT_IF_C Vp_BFu0c_BFu9s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_BFu9s)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0c_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0c_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_BFu9s, Vp_BFu0c_BFu9s)
//============================================================================



static void Test_Vp_BFu0c_C()
{
  {
    init_simple_test("Vp_BFu0c_C");
    static STRUCT_IF_C Vp_BFu0c_C lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_C)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_C)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_C, Vp_BFu0c_C)
//============================================================================



static void Test_Vp_BFu0c_D()
{
  {
    init_simple_test("Vp_BFu0c_D");
    static STRUCT_IF_C Vp_BFu0c_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0c_D)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_D)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_D, Vp_BFu0c_D)
//============================================================================



static void Test_Vp_BFu0c_F()
{
  {
    init_simple_test("Vp_BFu0c_F");
    static STRUCT_IF_C Vp_BFu0c_F lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0c_F)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_F)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_F, Vp_BFu0c_F)
//============================================================================



static void Test_Vp_BFu0c_I()
{
  {
    init_simple_test("Vp_BFu0c_I");
    static STRUCT_IF_C Vp_BFu0c_I lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0c_I)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_I)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_I, Vp_BFu0c_I)
//============================================================================



static void Test_Vp_BFu0c_Ip()
{
  {
    init_simple_test("Vp_BFu0c_Ip");
    static STRUCT_IF_C Vp_BFu0c_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu0c_Ip)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_Ip)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_Ip, Vp_BFu0c_Ip)
//============================================================================



static void Test_Vp_BFu0c_L()
{
  {
    init_simple_test("Vp_BFu0c_L");
    static STRUCT_IF_C Vp_BFu0c_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0c_L)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_L)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_L, Vp_BFu0c_L)
//============================================================================



static void Test_Vp_BFu0c_S()
{
  {
    init_simple_test("Vp_BFu0c_S");
    static STRUCT_IF_C Vp_BFu0c_S lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_S)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_S)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_S, Vp_BFu0c_S)
//============================================================================



static void Test_Vp_BFu0c_Uc()
{
  {
    init_simple_test("Vp_BFu0c_Uc");
    static STRUCT_IF_C Vp_BFu0c_Uc lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0c_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_Uc)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_Uc, Vp_BFu0c_Uc)
//============================================================================



static void Test_Vp_BFu0c_Ui()
{
  {
    init_simple_test("Vp_BFu0c_Ui");
    static STRUCT_IF_C Vp_BFu0c_Ui lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0c_Ui)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_Ui)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_Ui, Vp_BFu0c_Ui)
//============================================================================



static void Test_Vp_BFu0c_Ul()
{
  {
    init_simple_test("Vp_BFu0c_Ul");
    static STRUCT_IF_C Vp_BFu0c_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0c_Ul)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_Ul)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_Ul, Vp_BFu0c_Ul)
//============================================================================



static void Test_Vp_BFu0c_Us()
{
  {
    init_simple_test("Vp_BFu0c_Us");
    static STRUCT_IF_C Vp_BFu0c_Us lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0c_Us)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_Us)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_Us, Vp_BFu0c_Us)
//============================================================================



static void Test_Vp_BFu0c_Vp()
{
  {
    init_simple_test("Vp_BFu0c_Vp");
    static STRUCT_IF_C Vp_BFu0c_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu0c_Vp)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu0c_Vp)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_Vp, Vp_BFu0c_Vp)
//============================================================================



static void Test_Vp_BFu0i()
{
  {
    init_simple_test("Vp_BFu0i");
    static STRUCT_IF_C Vp_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i, Vp_BFu0i)
//============================================================================



static void Test_Vp_BFu0i_BFu0c()
{
  {
    init_simple_test("Vp_BFu0i_BFu0c");
    static STRUCT_IF_C Vp_BFu0i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0i_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu0c, Vp_BFu0i_BFu0c)
//============================================================================



static void Test_Vp_BFu0i_BFu0i()
{
  {
    init_simple_test("Vp_BFu0i_BFu0i");
    static STRUCT_IF_C Vp_BFu0i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu0i, Vp_BFu0i_BFu0i)
//============================================================================



static void Test_Vp_BFu0i_BFu0ll()
{
  {
    init_simple_test("Vp_BFu0i_BFu0ll");
    static STRUCT_IF_C Vp_BFu0i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu0ll, Vp_BFu0i_BFu0ll)
//============================================================================



static void Test_Vp_BFu0i_BFu0s()
{
  {
    init_simple_test("Vp_BFu0i_BFu0s");
    static STRUCT_IF_C Vp_BFu0i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu0s, Vp_BFu0i_BFu0s)
//============================================================================



static void Test_Vp_BFu0i_BFu15i()
{
  {
    init_simple_test("Vp_BFu0i_BFu15i");
    static STRUCT_IF_C Vp_BFu0i_BFu15i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_BFu15i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0i_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0i_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu15i, Vp_BFu0i_BFu15i)
//============================================================================



static void Test_Vp_BFu0i_BFu15ll()
{
  {
    init_simple_test("Vp_BFu0i_BFu15ll");
    static STRUCT_IF_C Vp_BFu0i_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0i_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0i_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu15ll, Vp_BFu0i_BFu15ll)
//============================================================================



static void Test_Vp_BFu0i_BFu15s()
{
  {
    init_simple_test("Vp_BFu0i_BFu15s");
    static STRUCT_IF_C Vp_BFu0i_BFu15s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_BFu15s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0i_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0i_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu15s, Vp_BFu0i_BFu15s)
//============================================================================



static void Test_Vp_BFu0i_BFu16i()
{
  {
    init_simple_test("Vp_BFu0i_BFu16i");
    static STRUCT_IF_C Vp_BFu0i_BFu16i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_BFu16i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0i_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0i_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu16i, Vp_BFu0i_BFu16i)
//============================================================================



static void Test_Vp_BFu0i_BFu16ll()
{
  {
    init_simple_test("Vp_BFu0i_BFu16ll");
    static STRUCT_IF_C Vp_BFu0i_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0i_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0i_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu16ll, Vp_BFu0i_BFu16ll)
//============================================================================



static void Test_Vp_BFu0i_BFu16s()
{
  {
    init_simple_test("Vp_BFu0i_BFu16s");
    static STRUCT_IF_C Vp_BFu0i_BFu16s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_BFu16s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0i_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0i_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu16s, Vp_BFu0i_BFu16s)
//============================================================================



static void Test_Vp_BFu0i_BFu17i()
{
  {
    init_simple_test("Vp_BFu0i_BFu17i");
    static STRUCT_IF_C Vp_BFu0i_BFu17i lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu0i_BFu17i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu0i_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu0i_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu17i, Vp_BFu0i_BFu17i)
//============================================================================



static void Test_Vp_BFu0i_BFu17ll()
{
  {
    init_simple_test("Vp_BFu0i_BFu17ll");
    static STRUCT_IF_C Vp_BFu0i_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu0i_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu0i_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu0i_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu17ll, Vp_BFu0i_BFu17ll)
//============================================================================



static void Test_Vp_BFu0i_BFu1c()
{
  {
    init_simple_test("Vp_BFu0i_BFu1c");
    static STRUCT_IF_C Vp_BFu0i_BFu1c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0i_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu1c, Vp_BFu0i_BFu1c)
//============================================================================



static void Test_Vp_BFu0i_BFu1i()
{
  {
    init_simple_test("Vp_BFu0i_BFu1i");
    static STRUCT_IF_C Vp_BFu0i_BFu1i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu1i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0i_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu1i, Vp_BFu0i_BFu1i)
//============================================================================



static void Test_Vp_BFu0i_BFu1ll()
{
  {
    init_simple_test("Vp_BFu0i_BFu1ll");
    static STRUCT_IF_C Vp_BFu0i_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0i_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu1ll, Vp_BFu0i_BFu1ll)
//============================================================================



static void Test_Vp_BFu0i_BFu1s()
{
  {
    init_simple_test("Vp_BFu0i_BFu1s");
    static STRUCT_IF_C Vp_BFu0i_BFu1s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu1s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0i_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu1s, Vp_BFu0i_BFu1s)
//============================================================================



static void Test_Vp_BFu0i_BFu31i()
{
  {
    init_simple_test("Vp_BFu0i_BFu31i");
    static STRUCT_IF_C Vp_BFu0i_BFu31i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0i_BFu31i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu0i_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu0i_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu31i, Vp_BFu0i_BFu31i)
//============================================================================



static void Test_Vp_BFu0i_BFu31ll()
{
  {
    init_simple_test("Vp_BFu0i_BFu31ll");
    static STRUCT_IF_C Vp_BFu0i_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0i_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu0i_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu0i_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu31ll, Vp_BFu0i_BFu31ll)
//============================================================================



static void Test_Vp_BFu0i_BFu32i()
{
  {
    init_simple_test("Vp_BFu0i_BFu32i");
    static STRUCT_IF_C Vp_BFu0i_BFu32i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0i_BFu32i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu0i_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu0i_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu32i, Vp_BFu0i_BFu32i)
//============================================================================



static void Test_Vp_BFu0i_BFu32ll()
{
  {
    init_simple_test("Vp_BFu0i_BFu32ll");
    static STRUCT_IF_C Vp_BFu0i_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0i_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu0i_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu0i_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu32ll, Vp_BFu0i_BFu32ll)
//============================================================================



static void Test_Vp_BFu0i_BFu33()
{
  {
    init_simple_test("Vp_BFu0i_BFu33");
    static STRUCT_IF_C Vp_BFu0i_BFu33 lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_BFu0i_BFu33)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu0i_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu0i_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu33, Vp_BFu0i_BFu33)
//============================================================================



static void Test_Vp_BFu0i_BFu7c()
{
  {
    init_simple_test("Vp_BFu0i_BFu7c");
    static STRUCT_IF_C Vp_BFu0i_BFu7c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0i_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0i_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu7c, Vp_BFu0i_BFu7c)
//============================================================================



static void Test_Vp_BFu0i_BFu7i()
{
  {
    init_simple_test("Vp_BFu0i_BFu7i");
    static STRUCT_IF_C Vp_BFu0i_BFu7i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu7i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0i_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0i_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu7i, Vp_BFu0i_BFu7i)
//============================================================================



static void Test_Vp_BFu0i_BFu7ll()
{
  {
    init_simple_test("Vp_BFu0i_BFu7ll");
    static STRUCT_IF_C Vp_BFu0i_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0i_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0i_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu7ll, Vp_BFu0i_BFu7ll)
//============================================================================



static void Test_Vp_BFu0i_BFu7s()
{
  {
    init_simple_test("Vp_BFu0i_BFu7s");
    static STRUCT_IF_C Vp_BFu0i_BFu7s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu7s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0i_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0i_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu7s, Vp_BFu0i_BFu7s)
//============================================================================



static void Test_Vp_BFu0i_BFu8c()
{
  {
    init_simple_test("Vp_BFu0i_BFu8c");
    static STRUCT_IF_C Vp_BFu0i_BFu8c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0i_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0i_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu8c, Vp_BFu0i_BFu8c)
//============================================================================



static void Test_Vp_BFu0i_BFu8i()
{
  {
    init_simple_test("Vp_BFu0i_BFu8i");
    static STRUCT_IF_C Vp_BFu0i_BFu8i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu8i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0i_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0i_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu8i, Vp_BFu0i_BFu8i)
//============================================================================



static void Test_Vp_BFu0i_BFu8ll()
{
  {
    init_simple_test("Vp_BFu0i_BFu8ll");
    static STRUCT_IF_C Vp_BFu0i_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0i_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0i_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu8ll, Vp_BFu0i_BFu8ll)
//============================================================================



static void Test_Vp_BFu0i_BFu8s()
{
  {
    init_simple_test("Vp_BFu0i_BFu8s");
    static STRUCT_IF_C Vp_BFu0i_BFu8s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_BFu8s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0i_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0i_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu8s, Vp_BFu0i_BFu8s)
//============================================================================



static void Test_Vp_BFu0i_BFu9i()
{
  {
    init_simple_test("Vp_BFu0i_BFu9i");
    static STRUCT_IF_C Vp_BFu0i_BFu9i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_BFu9i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0i_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0i_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu9i, Vp_BFu0i_BFu9i)
//============================================================================



static void Test_Vp_BFu0i_BFu9ll()
{
  {
    init_simple_test("Vp_BFu0i_BFu9ll");
    static STRUCT_IF_C Vp_BFu0i_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0i_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0i_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu9ll, Vp_BFu0i_BFu9ll)
//============================================================================



static void Test_Vp_BFu0i_BFu9s()
{
  {
    init_simple_test("Vp_BFu0i_BFu9s");
    static STRUCT_IF_C Vp_BFu0i_BFu9s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_BFu9s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0i_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0i_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_BFu9s, Vp_BFu0i_BFu9s)
//============================================================================



static void Test_Vp_BFu0i_C()
{
  {
    init_simple_test("Vp_BFu0i_C");
    static STRUCT_IF_C Vp_BFu0i_C lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_C)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_C, Vp_BFu0i_C)
//============================================================================



static void Test_Vp_BFu0i_D()
{
  {
    init_simple_test("Vp_BFu0i_D");
    static STRUCT_IF_C Vp_BFu0i_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0i_D)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_D)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_D, Vp_BFu0i_D)
//============================================================================



static void Test_Vp_BFu0i_F()
{
  {
    init_simple_test("Vp_BFu0i_F");
    static STRUCT_IF_C Vp_BFu0i_F lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0i_F)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_F)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_F, Vp_BFu0i_F)
//============================================================================



static void Test_Vp_BFu0i_I()
{
  {
    init_simple_test("Vp_BFu0i_I");
    static STRUCT_IF_C Vp_BFu0i_I lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0i_I)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_I)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_I, Vp_BFu0i_I)
//============================================================================



static void Test_Vp_BFu0i_Ip()
{
  {
    init_simple_test("Vp_BFu0i_Ip");
    static STRUCT_IF_C Vp_BFu0i_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu0i_Ip)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_Ip)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_Ip, Vp_BFu0i_Ip)
//============================================================================



static void Test_Vp_BFu0i_L()
{
  {
    init_simple_test("Vp_BFu0i_L");
    static STRUCT_IF_C Vp_BFu0i_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0i_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_L)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_L, Vp_BFu0i_L)
//============================================================================



static void Test_Vp_BFu0i_S()
{
  {
    init_simple_test("Vp_BFu0i_S");
    static STRUCT_IF_C Vp_BFu0i_S lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_S)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_S, Vp_BFu0i_S)
//============================================================================



static void Test_Vp_BFu0i_Uc()
{
  {
    init_simple_test("Vp_BFu0i_Uc");
    static STRUCT_IF_C Vp_BFu0i_Uc lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0i_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_Uc)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_Uc, Vp_BFu0i_Uc)
//============================================================================



static void Test_Vp_BFu0i_Ui()
{
  {
    init_simple_test("Vp_BFu0i_Ui");
    static STRUCT_IF_C Vp_BFu0i_Ui lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0i_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_Ui)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_Ui, Vp_BFu0i_Ui)
//============================================================================



static void Test_Vp_BFu0i_Ul()
{
  {
    init_simple_test("Vp_BFu0i_Ul");
    static STRUCT_IF_C Vp_BFu0i_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0i_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_Ul)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_Ul, Vp_BFu0i_Ul)
//============================================================================



static void Test_Vp_BFu0i_Us()
{
  {
    init_simple_test("Vp_BFu0i_Us");
    static STRUCT_IF_C Vp_BFu0i_Us lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0i_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_Us)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_Us, Vp_BFu0i_Us)
//============================================================================



static void Test_Vp_BFu0i_Vp()
{
  {
    init_simple_test("Vp_BFu0i_Vp");
    static STRUCT_IF_C Vp_BFu0i_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu0i_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0i_Vp)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_Vp, Vp_BFu0i_Vp)
//============================================================================



static void Test_Vp_BFu0ll()
{
  {
    init_simple_test("Vp_BFu0ll");
    static STRUCT_IF_C Vp_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll, Vp_BFu0ll)
//============================================================================



static void Test_Vp_BFu0ll_BFu0c()
{
  {
    init_simple_test("Vp_BFu0ll_BFu0c");
    static STRUCT_IF_C Vp_BFu0ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu0c, Vp_BFu0ll_BFu0c)
//============================================================================



static void Test_Vp_BFu0ll_BFu0i()
{
  {
    init_simple_test("Vp_BFu0ll_BFu0i");
    static STRUCT_IF_C Vp_BFu0ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu0i, Vp_BFu0ll_BFu0i)
//============================================================================



static void Test_Vp_BFu0ll_BFu0ll()
{
  {
    init_simple_test("Vp_BFu0ll_BFu0ll");
    static STRUCT_IF_C Vp_BFu0ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu0ll, Vp_BFu0ll_BFu0ll)
//============================================================================



static void Test_Vp_BFu0ll_BFu0s()
{
  {
    init_simple_test("Vp_BFu0ll_BFu0s");
    static STRUCT_IF_C Vp_BFu0ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu0s, Vp_BFu0ll_BFu0s)
//============================================================================



static void Test_Vp_BFu0ll_BFu15i()
{
  {
    init_simple_test("Vp_BFu0ll_BFu15i");
    static STRUCT_IF_C Vp_BFu0ll_BFu15i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_BFu15i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0ll_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0ll_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu15i, Vp_BFu0ll_BFu15i)
//============================================================================



static void Test_Vp_BFu0ll_BFu15ll()
{
  {
    init_simple_test("Vp_BFu0ll_BFu15ll");
    static STRUCT_IF_C Vp_BFu0ll_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0ll_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0ll_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu15ll, Vp_BFu0ll_BFu15ll)
//============================================================================



static void Test_Vp_BFu0ll_BFu15s()
{
  {
    init_simple_test("Vp_BFu0ll_BFu15s");
    static STRUCT_IF_C Vp_BFu0ll_BFu15s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_BFu15s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0ll_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0ll_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu15s, Vp_BFu0ll_BFu15s)
//============================================================================



static void Test_Vp_BFu0ll_BFu16i()
{
  {
    init_simple_test("Vp_BFu0ll_BFu16i");
    static STRUCT_IF_C Vp_BFu0ll_BFu16i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_BFu16i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0ll_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0ll_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu16i, Vp_BFu0ll_BFu16i)
//============================================================================



static void Test_Vp_BFu0ll_BFu16ll()
{
  {
    init_simple_test("Vp_BFu0ll_BFu16ll");
    static STRUCT_IF_C Vp_BFu0ll_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0ll_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0ll_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu16ll, Vp_BFu0ll_BFu16ll)
//============================================================================



static void Test_Vp_BFu0ll_BFu16s()
{
  {
    init_simple_test("Vp_BFu0ll_BFu16s");
    static STRUCT_IF_C Vp_BFu0ll_BFu16s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_BFu16s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0ll_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0ll_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu16s, Vp_BFu0ll_BFu16s)
//============================================================================



static void Test_Vp_BFu0ll_BFu17i()
{
  {
    init_simple_test("Vp_BFu0ll_BFu17i");
    static STRUCT_IF_C Vp_BFu0ll_BFu17i lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu0ll_BFu17i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu0ll_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu0ll_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu17i, Vp_BFu0ll_BFu17i)
//============================================================================



static void Test_Vp_BFu0ll_BFu17ll()
{
  {
    init_simple_test("Vp_BFu0ll_BFu17ll");
    static STRUCT_IF_C Vp_BFu0ll_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu0ll_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu0ll_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu0ll_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu17ll, Vp_BFu0ll_BFu17ll)
//============================================================================



static void Test_Vp_BFu0ll_BFu1c()
{
  {
    init_simple_test("Vp_BFu0ll_BFu1c");
    static STRUCT_IF_C Vp_BFu0ll_BFu1c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0ll_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu1c, Vp_BFu0ll_BFu1c)
//============================================================================



static void Test_Vp_BFu0ll_BFu1i()
{
  {
    init_simple_test("Vp_BFu0ll_BFu1i");
    static STRUCT_IF_C Vp_BFu0ll_BFu1i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu1i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0ll_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu1i, Vp_BFu0ll_BFu1i)
//============================================================================



static void Test_Vp_BFu0ll_BFu1ll()
{
  {
    init_simple_test("Vp_BFu0ll_BFu1ll");
    static STRUCT_IF_C Vp_BFu0ll_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0ll_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu1ll, Vp_BFu0ll_BFu1ll)
//============================================================================



static void Test_Vp_BFu0ll_BFu1s()
{
  {
    init_simple_test("Vp_BFu0ll_BFu1s");
    static STRUCT_IF_C Vp_BFu0ll_BFu1s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu1s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0ll_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu1s, Vp_BFu0ll_BFu1s)
//============================================================================



static void Test_Vp_BFu0ll_BFu31i()
{
  {
    init_simple_test("Vp_BFu0ll_BFu31i");
    static STRUCT_IF_C Vp_BFu0ll_BFu31i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0ll_BFu31i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu0ll_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu0ll_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu31i, Vp_BFu0ll_BFu31i)
//============================================================================



static void Test_Vp_BFu0ll_BFu31ll()
{
  {
    init_simple_test("Vp_BFu0ll_BFu31ll");
    static STRUCT_IF_C Vp_BFu0ll_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0ll_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu0ll_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu0ll_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu31ll, Vp_BFu0ll_BFu31ll)
//============================================================================



static void Test_Vp_BFu0ll_BFu32i()
{
  {
    init_simple_test("Vp_BFu0ll_BFu32i");
    static STRUCT_IF_C Vp_BFu0ll_BFu32i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0ll_BFu32i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu0ll_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu0ll_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu32i, Vp_BFu0ll_BFu32i)
//============================================================================



static void Test_Vp_BFu0ll_BFu32ll()
{
  {
    init_simple_test("Vp_BFu0ll_BFu32ll");
    static STRUCT_IF_C Vp_BFu0ll_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0ll_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu0ll_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu0ll_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu32ll, Vp_BFu0ll_BFu32ll)
//============================================================================



static void Test_Vp_BFu0ll_BFu33()
{
  {
    init_simple_test("Vp_BFu0ll_BFu33");
    static STRUCT_IF_C Vp_BFu0ll_BFu33 lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_BFu0ll_BFu33)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu0ll_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu0ll_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu33, Vp_BFu0ll_BFu33)
//============================================================================



static void Test_Vp_BFu0ll_BFu7c()
{
  {
    init_simple_test("Vp_BFu0ll_BFu7c");
    static STRUCT_IF_C Vp_BFu0ll_BFu7c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0ll_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0ll_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu7c, Vp_BFu0ll_BFu7c)
//============================================================================



static void Test_Vp_BFu0ll_BFu7i()
{
  {
    init_simple_test("Vp_BFu0ll_BFu7i");
    static STRUCT_IF_C Vp_BFu0ll_BFu7i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu7i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0ll_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0ll_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu7i, Vp_BFu0ll_BFu7i)
//============================================================================



static void Test_Vp_BFu0ll_BFu7ll()
{
  {
    init_simple_test("Vp_BFu0ll_BFu7ll");
    static STRUCT_IF_C Vp_BFu0ll_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0ll_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0ll_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu7ll, Vp_BFu0ll_BFu7ll)
//============================================================================



static void Test_Vp_BFu0ll_BFu7s()
{
  {
    init_simple_test("Vp_BFu0ll_BFu7s");
    static STRUCT_IF_C Vp_BFu0ll_BFu7s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu7s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0ll_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0ll_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu7s, Vp_BFu0ll_BFu7s)
//============================================================================



static void Test_Vp_BFu0ll_BFu8c()
{
  {
    init_simple_test("Vp_BFu0ll_BFu8c");
    static STRUCT_IF_C Vp_BFu0ll_BFu8c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0ll_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0ll_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu8c, Vp_BFu0ll_BFu8c)
//============================================================================



static void Test_Vp_BFu0ll_BFu8i()
{
  {
    init_simple_test("Vp_BFu0ll_BFu8i");
    static STRUCT_IF_C Vp_BFu0ll_BFu8i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu8i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0ll_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0ll_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu8i, Vp_BFu0ll_BFu8i)
//============================================================================



static void Test_Vp_BFu0ll_BFu8ll()
{
  {
    init_simple_test("Vp_BFu0ll_BFu8ll");
    static STRUCT_IF_C Vp_BFu0ll_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0ll_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0ll_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu8ll, Vp_BFu0ll_BFu8ll)
//============================================================================



static void Test_Vp_BFu0ll_BFu8s()
{
  {
    init_simple_test("Vp_BFu0ll_BFu8s");
    static STRUCT_IF_C Vp_BFu0ll_BFu8s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_BFu8s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0ll_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0ll_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu8s, Vp_BFu0ll_BFu8s)
//============================================================================



static void Test_Vp_BFu0ll_BFu9i()
{
  {
    init_simple_test("Vp_BFu0ll_BFu9i");
    static STRUCT_IF_C Vp_BFu0ll_BFu9i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_BFu9i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0ll_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0ll_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu9i, Vp_BFu0ll_BFu9i)
//============================================================================



static void Test_Vp_BFu0ll_BFu9ll()
{
  {
    init_simple_test("Vp_BFu0ll_BFu9ll");
    static STRUCT_IF_C Vp_BFu0ll_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0ll_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0ll_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu9ll, Vp_BFu0ll_BFu9ll)
//============================================================================



static void Test_Vp_BFu0ll_BFu9s()
{
  {
    init_simple_test("Vp_BFu0ll_BFu9s");
    static STRUCT_IF_C Vp_BFu0ll_BFu9s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_BFu9s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0ll_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0ll_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_BFu9s, Vp_BFu0ll_BFu9s)
//============================================================================



static void Test_Vp_BFu0ll_C()
{
  {
    init_simple_test("Vp_BFu0ll_C");
    static STRUCT_IF_C Vp_BFu0ll_C lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_C)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_C, Vp_BFu0ll_C)
//============================================================================



static void Test_Vp_BFu0ll_D()
{
  {
    init_simple_test("Vp_BFu0ll_D");
    static STRUCT_IF_C Vp_BFu0ll_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0ll_D)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_D)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_D, Vp_BFu0ll_D)
//============================================================================



static void Test_Vp_BFu0ll_F()
{
  {
    init_simple_test("Vp_BFu0ll_F");
    static STRUCT_IF_C Vp_BFu0ll_F lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0ll_F)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_F)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_F, Vp_BFu0ll_F)
//============================================================================



static void Test_Vp_BFu0ll_I()
{
  {
    init_simple_test("Vp_BFu0ll_I");
    static STRUCT_IF_C Vp_BFu0ll_I lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0ll_I)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_I)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_I, Vp_BFu0ll_I)
//============================================================================



static void Test_Vp_BFu0ll_Ip()
{
  {
    init_simple_test("Vp_BFu0ll_Ip");
    static STRUCT_IF_C Vp_BFu0ll_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu0ll_Ip)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_Ip)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_Ip, Vp_BFu0ll_Ip)
//============================================================================



static void Test_Vp_BFu0ll_L()
{
  {
    init_simple_test("Vp_BFu0ll_L");
    static STRUCT_IF_C Vp_BFu0ll_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0ll_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_L)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_L, Vp_BFu0ll_L)
//============================================================================



static void Test_Vp_BFu0ll_S()
{
  {
    init_simple_test("Vp_BFu0ll_S");
    static STRUCT_IF_C Vp_BFu0ll_S lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_S)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_S, Vp_BFu0ll_S)
//============================================================================



static void Test_Vp_BFu0ll_Uc()
{
  {
    init_simple_test("Vp_BFu0ll_Uc");
    static STRUCT_IF_C Vp_BFu0ll_Uc lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0ll_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_Uc)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_Uc, Vp_BFu0ll_Uc)
//============================================================================



static void Test_Vp_BFu0ll_Ui()
{
  {
    init_simple_test("Vp_BFu0ll_Ui");
    static STRUCT_IF_C Vp_BFu0ll_Ui lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0ll_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_Ui)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_Ui, Vp_BFu0ll_Ui)
//============================================================================



static void Test_Vp_BFu0ll_Ul()
{
  {
    init_simple_test("Vp_BFu0ll_Ul");
    static STRUCT_IF_C Vp_BFu0ll_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0ll_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_Ul)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_Ul, Vp_BFu0ll_Ul)
//============================================================================



static void Test_Vp_BFu0ll_Us()
{
  {
    init_simple_test("Vp_BFu0ll_Us");
    static STRUCT_IF_C Vp_BFu0ll_Us lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0ll_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_Us)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_Us, Vp_BFu0ll_Us)
//============================================================================



static void Test_Vp_BFu0ll_Vp()
{
  {
    init_simple_test("Vp_BFu0ll_Vp");
    static STRUCT_IF_C Vp_BFu0ll_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu0ll_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0ll_Vp)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_Vp, Vp_BFu0ll_Vp)
//============================================================================



static void Test_Vp_BFu0s()
{
  {
    init_simple_test("Vp_BFu0s");
    static STRUCT_IF_C Vp_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s, Vp_BFu0s)
//============================================================================



static void Test_Vp_BFu0s_BFu0c()
{
  {
    init_simple_test("Vp_BFu0s_BFu0c");
    static STRUCT_IF_C Vp_BFu0s_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0s_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu0c, Vp_BFu0s_BFu0c)
//============================================================================



static void Test_Vp_BFu0s_BFu0i()
{
  {
    init_simple_test("Vp_BFu0s_BFu0i");
    static STRUCT_IF_C Vp_BFu0s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu0i, Vp_BFu0s_BFu0i)
//============================================================================



static void Test_Vp_BFu0s_BFu0ll()
{
  {
    init_simple_test("Vp_BFu0s_BFu0ll");
    static STRUCT_IF_C Vp_BFu0s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu0ll, Vp_BFu0s_BFu0ll)
//============================================================================



static void Test_Vp_BFu0s_BFu0s()
{
  {
    init_simple_test("Vp_BFu0s_BFu0s");
    static STRUCT_IF_C Vp_BFu0s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu0s, Vp_BFu0s_BFu0s)
//============================================================================



static void Test_Vp_BFu0s_BFu15i()
{
  {
    init_simple_test("Vp_BFu0s_BFu15i");
    static STRUCT_IF_C Vp_BFu0s_BFu15i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_BFu15i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0s_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0s_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu15i, Vp_BFu0s_BFu15i)
//============================================================================



static void Test_Vp_BFu0s_BFu15ll()
{
  {
    init_simple_test("Vp_BFu0s_BFu15ll");
    static STRUCT_IF_C Vp_BFu0s_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0s_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0s_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu15ll, Vp_BFu0s_BFu15ll)
//============================================================================



static void Test_Vp_BFu0s_BFu15s()
{
  {
    init_simple_test("Vp_BFu0s_BFu15s");
    static STRUCT_IF_C Vp_BFu0s_BFu15s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_BFu15s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu0s_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu0s_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu15s, Vp_BFu0s_BFu15s)
//============================================================================



static void Test_Vp_BFu0s_BFu16i()
{
  {
    init_simple_test("Vp_BFu0s_BFu16i");
    static STRUCT_IF_C Vp_BFu0s_BFu16i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_BFu16i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0s_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0s_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu16i, Vp_BFu0s_BFu16i)
//============================================================================



static void Test_Vp_BFu0s_BFu16ll()
{
  {
    init_simple_test("Vp_BFu0s_BFu16ll");
    static STRUCT_IF_C Vp_BFu0s_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0s_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0s_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu16ll, Vp_BFu0s_BFu16ll)
//============================================================================



static void Test_Vp_BFu0s_BFu16s()
{
  {
    init_simple_test("Vp_BFu0s_BFu16s");
    static STRUCT_IF_C Vp_BFu0s_BFu16s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_BFu16s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu0s_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu0s_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu16s, Vp_BFu0s_BFu16s)
//============================================================================



static void Test_Vp_BFu0s_BFu17i()
{
  {
    init_simple_test("Vp_BFu0s_BFu17i");
    static STRUCT_IF_C Vp_BFu0s_BFu17i lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu0s_BFu17i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu0s_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu0s_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu17i, Vp_BFu0s_BFu17i)
//============================================================================



static void Test_Vp_BFu0s_BFu17ll()
{
  {
    init_simple_test("Vp_BFu0s_BFu17ll");
    static STRUCT_IF_C Vp_BFu0s_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu0s_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu0s_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu0s_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu17ll, Vp_BFu0s_BFu17ll)
//============================================================================



static void Test_Vp_BFu0s_BFu1c()
{
  {
    init_simple_test("Vp_BFu0s_BFu1c");
    static STRUCT_IF_C Vp_BFu0s_BFu1c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0s_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu1c, Vp_BFu0s_BFu1c)
//============================================================================



static void Test_Vp_BFu0s_BFu1i()
{
  {
    init_simple_test("Vp_BFu0s_BFu1i");
    static STRUCT_IF_C Vp_BFu0s_BFu1i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu1i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0s_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu1i, Vp_BFu0s_BFu1i)
//============================================================================



static void Test_Vp_BFu0s_BFu1ll()
{
  {
    init_simple_test("Vp_BFu0s_BFu1ll");
    static STRUCT_IF_C Vp_BFu0s_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0s_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu1ll, Vp_BFu0s_BFu1ll)
//============================================================================



static void Test_Vp_BFu0s_BFu1s()
{
  {
    init_simple_test("Vp_BFu0s_BFu1s");
    static STRUCT_IF_C Vp_BFu0s_BFu1s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu1s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu0s_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu1s, Vp_BFu0s_BFu1s)
//============================================================================



static void Test_Vp_BFu0s_BFu31i()
{
  {
    init_simple_test("Vp_BFu0s_BFu31i");
    static STRUCT_IF_C Vp_BFu0s_BFu31i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0s_BFu31i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu0s_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu0s_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu31i, Vp_BFu0s_BFu31i)
//============================================================================



static void Test_Vp_BFu0s_BFu31ll()
{
  {
    init_simple_test("Vp_BFu0s_BFu31ll");
    static STRUCT_IF_C Vp_BFu0s_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0s_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu0s_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu0s_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu31ll, Vp_BFu0s_BFu31ll)
//============================================================================



static void Test_Vp_BFu0s_BFu32i()
{
  {
    init_simple_test("Vp_BFu0s_BFu32i");
    static STRUCT_IF_C Vp_BFu0s_BFu32i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0s_BFu32i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu0s_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu0s_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu32i, Vp_BFu0s_BFu32i)
//============================================================================



static void Test_Vp_BFu0s_BFu32ll()
{
  {
    init_simple_test("Vp_BFu0s_BFu32ll");
    static STRUCT_IF_C Vp_BFu0s_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0s_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu0s_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu0s_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu32ll, Vp_BFu0s_BFu32ll)
//============================================================================



static void Test_Vp_BFu0s_BFu33()
{
  {
    init_simple_test("Vp_BFu0s_BFu33");
    static STRUCT_IF_C Vp_BFu0s_BFu33 lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_BFu0s_BFu33)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu0s_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu0s_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu33, Vp_BFu0s_BFu33)
//============================================================================



static void Test_Vp_BFu0s_BFu7c()
{
  {
    init_simple_test("Vp_BFu0s_BFu7c");
    static STRUCT_IF_C Vp_BFu0s_BFu7c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0s_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0s_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu7c, Vp_BFu0s_BFu7c)
//============================================================================



static void Test_Vp_BFu0s_BFu7i()
{
  {
    init_simple_test("Vp_BFu0s_BFu7i");
    static STRUCT_IF_C Vp_BFu0s_BFu7i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu7i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0s_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0s_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu7i, Vp_BFu0s_BFu7i)
//============================================================================



static void Test_Vp_BFu0s_BFu7ll()
{
  {
    init_simple_test("Vp_BFu0s_BFu7ll");
    static STRUCT_IF_C Vp_BFu0s_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0s_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0s_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu7ll, Vp_BFu0s_BFu7ll)
//============================================================================



static void Test_Vp_BFu0s_BFu7s()
{
  {
    init_simple_test("Vp_BFu0s_BFu7s");
    static STRUCT_IF_C Vp_BFu0s_BFu7s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu7s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu0s_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu0s_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu7s, Vp_BFu0s_BFu7s)
//============================================================================



static void Test_Vp_BFu0s_BFu8c()
{
  {
    init_simple_test("Vp_BFu0s_BFu8c");
    static STRUCT_IF_C Vp_BFu0s_BFu8c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0s_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0s_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu8c, Vp_BFu0s_BFu8c)
//============================================================================



static void Test_Vp_BFu0s_BFu8i()
{
  {
    init_simple_test("Vp_BFu0s_BFu8i");
    static STRUCT_IF_C Vp_BFu0s_BFu8i lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu8i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0s_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0s_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu8i, Vp_BFu0s_BFu8i)
//============================================================================



static void Test_Vp_BFu0s_BFu8ll()
{
  {
    init_simple_test("Vp_BFu0s_BFu8ll");
    static STRUCT_IF_C Vp_BFu0s_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0s_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0s_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu8ll, Vp_BFu0s_BFu8ll)
//============================================================================



static void Test_Vp_BFu0s_BFu8s()
{
  {
    init_simple_test("Vp_BFu0s_BFu8s");
    static STRUCT_IF_C Vp_BFu0s_BFu8s lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_BFu8s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu0s_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu0s_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu8s, Vp_BFu0s_BFu8s)
//============================================================================



static void Test_Vp_BFu0s_BFu9i()
{
  {
    init_simple_test("Vp_BFu0s_BFu9i");
    static STRUCT_IF_C Vp_BFu0s_BFu9i lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_BFu9i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0s_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0s_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu9i, Vp_BFu0s_BFu9i)
//============================================================================



static void Test_Vp_BFu0s_BFu9ll()
{
  {
    init_simple_test("Vp_BFu0s_BFu9ll");
    static STRUCT_IF_C Vp_BFu0s_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0s_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0s_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu9ll, Vp_BFu0s_BFu9ll)
//============================================================================



static void Test_Vp_BFu0s_BFu9s()
{
  {
    init_simple_test("Vp_BFu0s_BFu9s");
    static STRUCT_IF_C Vp_BFu0s_BFu9s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_BFu9s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu0s_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu0s_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_BFu9s, Vp_BFu0s_BFu9s)
//============================================================================



static void Test_Vp_BFu0s_C()
{
  {
    init_simple_test("Vp_BFu0s_C");
    static STRUCT_IF_C Vp_BFu0s_C lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_C)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_C, Vp_BFu0s_C)
//============================================================================



static void Test_Vp_BFu0s_D()
{
  {
    init_simple_test("Vp_BFu0s_D");
    static STRUCT_IF_C Vp_BFu0s_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0s_D)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_D)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_D, Vp_BFu0s_D)
//============================================================================



static void Test_Vp_BFu0s_F()
{
  {
    init_simple_test("Vp_BFu0s_F");
    static STRUCT_IF_C Vp_BFu0s_F lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0s_F)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_F)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_F, Vp_BFu0s_F)
//============================================================================



static void Test_Vp_BFu0s_I()
{
  {
    init_simple_test("Vp_BFu0s_I");
    static STRUCT_IF_C Vp_BFu0s_I lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0s_I)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_I)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_I, Vp_BFu0s_I)
//============================================================================



static void Test_Vp_BFu0s_Ip()
{
  {
    init_simple_test("Vp_BFu0s_Ip");
    static STRUCT_IF_C Vp_BFu0s_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu0s_Ip)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_Ip)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_Ip, Vp_BFu0s_Ip)
//============================================================================



static void Test_Vp_BFu0s_L()
{
  {
    init_simple_test("Vp_BFu0s_L");
    static STRUCT_IF_C Vp_BFu0s_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0s_L)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_L)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_L, Vp_BFu0s_L)
//============================================================================



static void Test_Vp_BFu0s_S()
{
  {
    init_simple_test("Vp_BFu0s_S");
    static STRUCT_IF_C Vp_BFu0s_S lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_S)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_S)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_S, Vp_BFu0s_S)
//============================================================================



static void Test_Vp_BFu0s_Uc()
{
  {
    init_simple_test("Vp_BFu0s_Uc");
    static STRUCT_IF_C Vp_BFu0s_Uc lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu0s_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_Uc)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_Uc, Vp_BFu0s_Uc)
//============================================================================



static void Test_Vp_BFu0s_Ui()
{
  {
    init_simple_test("Vp_BFu0s_Ui");
    static STRUCT_IF_C Vp_BFu0s_Ui lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu0s_Ui)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_Ui)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_Ui, Vp_BFu0s_Ui)
//============================================================================



static void Test_Vp_BFu0s_Ul()
{
  {
    init_simple_test("Vp_BFu0s_Ul");
    static STRUCT_IF_C Vp_BFu0s_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu0s_Ul)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_Ul)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_Ul, Vp_BFu0s_Ul)
//============================================================================



static void Test_Vp_BFu0s_Us()
{
  {
    init_simple_test("Vp_BFu0s_Us");
    static STRUCT_IF_C Vp_BFu0s_Us lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu0s_Us)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_Us)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_Us, Vp_BFu0s_Us)
//============================================================================



static void Test_Vp_BFu0s_Vp()
{
  {
    init_simple_test("Vp_BFu0s_Vp");
    static STRUCT_IF_C Vp_BFu0s_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu0s_Vp)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu0s_Vp)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_Vp, Vp_BFu0s_Vp)
//============================================================================



static void Test_Vp_BFu15i_BFu0c()
{
  {
    init_simple_test("Vp_BFu15i_BFu0c");
    static STRUCT_IF_C Vp_BFu15i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu15i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu15i_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu15i_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15i_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu15i_BFu0c, Vp_BFu15i_BFu0c)
//============================================================================



static void Test_Vp_BFu15i_BFu0i()
{
  {
    init_simple_test("Vp_BFu15i_BFu0i");
    static STRUCT_IF_C Vp_BFu15i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu15i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu15i_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu15i_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15i_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu15i_BFu0i, Vp_BFu15i_BFu0i)
//============================================================================



static void Test_Vp_BFu15i_BFu0ll()
{
  {
    init_simple_test("Vp_BFu15i_BFu0ll");
    static STRUCT_IF_C Vp_BFu15i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu15i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu15i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu15i_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15i_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu15i_BFu0ll, Vp_BFu15i_BFu0ll)
//============================================================================



static void Test_Vp_BFu15i_BFu0s()
{
  {
    init_simple_test("Vp_BFu15i_BFu0s");
    static STRUCT_IF_C Vp_BFu15i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu15i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu15i_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu15i_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15i_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu15i_BFu0s, Vp_BFu15i_BFu0s)
//============================================================================



static void Test_Vp_BFu15ll_BFu0c()
{
  {
    init_simple_test("Vp_BFu15ll_BFu0c");
    static STRUCT_IF_C Vp_BFu15ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu15ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu15ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu15ll_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15ll_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu15ll_BFu0c, Vp_BFu15ll_BFu0c)
//============================================================================



static void Test_Vp_BFu15ll_BFu0i()
{
  {
    init_simple_test("Vp_BFu15ll_BFu0i");
    static STRUCT_IF_C Vp_BFu15ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu15ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu15ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu15ll_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15ll_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu15ll_BFu0i, Vp_BFu15ll_BFu0i)
//============================================================================



static void Test_Vp_BFu15ll_BFu0ll()
{
  {
    init_simple_test("Vp_BFu15ll_BFu0ll");
    static STRUCT_IF_C Vp_BFu15ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu15ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu15ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu15ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15ll_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu15ll_BFu0ll, Vp_BFu15ll_BFu0ll)
//============================================================================



static void Test_Vp_BFu15ll_BFu0s()
{
  {
    init_simple_test("Vp_BFu15ll_BFu0s");
    static STRUCT_IF_C Vp_BFu15ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu15ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu15ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu15ll_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15ll_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu15ll_BFu0s, Vp_BFu15ll_BFu0s)
//============================================================================



static void Test_Vp_BFu15s_BFu0c()
{
  {
    init_simple_test("Vp_BFu15s_BFu0c");
    static STRUCT_IF_C Vp_BFu15s_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu15s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu15s_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu15s_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15s_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu15s_BFu0c, Vp_BFu15s_BFu0c)
//============================================================================



static void Test_Vp_BFu15s_BFu0i()
{
  {
    init_simple_test("Vp_BFu15s_BFu0i");
    static STRUCT_IF_C Vp_BFu15s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu15s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu15s_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu15s_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15s_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu15s_BFu0i, Vp_BFu15s_BFu0i)
//============================================================================



static void Test_Vp_BFu15s_BFu0ll()
{
  {
    init_simple_test("Vp_BFu15s_BFu0ll");
    static STRUCT_IF_C Vp_BFu15s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu15s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu15s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu15s_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15s_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu15s_BFu0ll, Vp_BFu15s_BFu0ll)
//============================================================================



static void Test_Vp_BFu15s_BFu0s()
{
  {
    init_simple_test("Vp_BFu15s_BFu0s");
    static STRUCT_IF_C Vp_BFu15s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu15s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu15s_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu15s_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "Vp_BFu15s_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "Vp_BFu15s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu15s_BFu0s, Vp_BFu15s_BFu0s)
//============================================================================



static void Test_Vp_BFu16i_BFu0c()
{
  {
    init_simple_test("Vp_BFu16i_BFu0c");
    static STRUCT_IF_C Vp_BFu16i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu16i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu16i_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu16i_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16i_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu16i_BFu0c, Vp_BFu16i_BFu0c)
//============================================================================



static void Test_Vp_BFu16i_BFu0i()
{
  {
    init_simple_test("Vp_BFu16i_BFu0i");
    static STRUCT_IF_C Vp_BFu16i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu16i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu16i_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu16i_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16i_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu16i_BFu0i, Vp_BFu16i_BFu0i)
//============================================================================



static void Test_Vp_BFu16i_BFu0ll()
{
  {
    init_simple_test("Vp_BFu16i_BFu0ll");
    static STRUCT_IF_C Vp_BFu16i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu16i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu16i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu16i_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16i_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu16i_BFu0ll, Vp_BFu16i_BFu0ll)
//============================================================================



static void Test_Vp_BFu16i_BFu0s()
{
  {
    init_simple_test("Vp_BFu16i_BFu0s");
    static STRUCT_IF_C Vp_BFu16i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu16i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu16i_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu16i_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16i_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu16i_BFu0s, Vp_BFu16i_BFu0s)
//============================================================================



static void Test_Vp_BFu16ll_BFu0c()
{
  {
    init_simple_test("Vp_BFu16ll_BFu0c");
    static STRUCT_IF_C Vp_BFu16ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu16ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu16ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu16ll_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16ll_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu16ll_BFu0c, Vp_BFu16ll_BFu0c)
//============================================================================



static void Test_Vp_BFu16ll_BFu0i()
{
  {
    init_simple_test("Vp_BFu16ll_BFu0i");
    static STRUCT_IF_C Vp_BFu16ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu16ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu16ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu16ll_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16ll_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu16ll_BFu0i, Vp_BFu16ll_BFu0i)
//============================================================================



static void Test_Vp_BFu16ll_BFu0ll()
{
  {
    init_simple_test("Vp_BFu16ll_BFu0ll");
    static STRUCT_IF_C Vp_BFu16ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu16ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu16ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu16ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16ll_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu16ll_BFu0ll, Vp_BFu16ll_BFu0ll)
//============================================================================



static void Test_Vp_BFu16ll_BFu0s()
{
  {
    init_simple_test("Vp_BFu16ll_BFu0s");
    static STRUCT_IF_C Vp_BFu16ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu16ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu16ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu16ll_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16ll_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu16ll_BFu0s, Vp_BFu16ll_BFu0s)
//============================================================================



static void Test_Vp_BFu16s_BFu0c()
{
  {
    init_simple_test("Vp_BFu16s_BFu0c");
    static STRUCT_IF_C Vp_BFu16s_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu16s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu16s_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu16s_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16s_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu16s_BFu0c, Vp_BFu16s_BFu0c)
//============================================================================



static void Test_Vp_BFu16s_BFu0i()
{
  {
    init_simple_test("Vp_BFu16s_BFu0i");
    static STRUCT_IF_C Vp_BFu16s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu16s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu16s_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu16s_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16s_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu16s_BFu0i, Vp_BFu16s_BFu0i)
//============================================================================



static void Test_Vp_BFu16s_BFu0ll()
{
  {
    init_simple_test("Vp_BFu16s_BFu0ll");
    static STRUCT_IF_C Vp_BFu16s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu16s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu16s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu16s_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16s_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu16s_BFu0ll, Vp_BFu16s_BFu0ll)
//============================================================================



static void Test_Vp_BFu16s_BFu0s()
{
  {
    init_simple_test("Vp_BFu16s_BFu0s");
    static STRUCT_IF_C Vp_BFu16s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu16s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu16s_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu16s_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "Vp_BFu16s_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "Vp_BFu16s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu16s_BFu0s, Vp_BFu16s_BFu0s)
//============================================================================



static void Test_Vp_BFu17i_BFu0c()
{
  {
    init_simple_test("Vp_BFu17i_BFu0c");
    static STRUCT_IF_C Vp_BFu17i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu17i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu17i_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu17i_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu17i_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu17i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu17i_BFu0c, Vp_BFu17i_BFu0c)
//============================================================================



static void Test_Vp_BFu17i_BFu0i()
{
  {
    init_simple_test("Vp_BFu17i_BFu0i");
    static STRUCT_IF_C Vp_BFu17i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu17i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu17i_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu17i_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu17i_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu17i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu17i_BFu0i, Vp_BFu17i_BFu0i)
//============================================================================



static void Test_Vp_BFu17i_BFu0ll()
{
  {
    init_simple_test("Vp_BFu17i_BFu0ll");
    static STRUCT_IF_C Vp_BFu17i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu17i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu17i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu17i_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu17i_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu17i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu17i_BFu0ll, Vp_BFu17i_BFu0ll)
//============================================================================



static void Test_Vp_BFu17i_BFu0s()
{
  {
    init_simple_test("Vp_BFu17i_BFu0s");
    static STRUCT_IF_C Vp_BFu17i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu17i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu17i_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu17i_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu17i_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu17i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu17i_BFu0s, Vp_BFu17i_BFu0s)
//============================================================================



static void Test_Vp_BFu17ll_BFu0c()
{
  {
    init_simple_test("Vp_BFu17ll_BFu0c");
    static STRUCT_IF_C Vp_BFu17ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(11,7), "sizeof(Vp_BFu17ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu17ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu17ll_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu17ll_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu17ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu17ll_BFu0c, Vp_BFu17ll_BFu0c)
//============================================================================



static void Test_Vp_BFu17ll_BFu0i()
{
  {
    init_simple_test("Vp_BFu17ll_BFu0i");
    static STRUCT_IF_C Vp_BFu17ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu17ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu17ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu17ll_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu17ll_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu17ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu17ll_BFu0i, Vp_BFu17ll_BFu0i)
//============================================================================



static void Test_Vp_BFu17ll_BFu0ll()
{
  {
    init_simple_test("Vp_BFu17ll_BFu0ll");
    static STRUCT_IF_C Vp_BFu17ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu17ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu17ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu17ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu17ll_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu17ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu17ll_BFu0ll, Vp_BFu17ll_BFu0ll)
//============================================================================



static void Test_Vp_BFu17ll_BFu0s()
{
  {
    init_simple_test("Vp_BFu17ll_BFu0s");
    static STRUCT_IF_C Vp_BFu17ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu17ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu17ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu17ll_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "Vp_BFu17ll_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "Vp_BFu17ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu17ll_BFu0s, Vp_BFu17ll_BFu0s)
//============================================================================



static void Test_Vp_BFu1c_BFu0c()
{
  {
    init_simple_test("Vp_BFu1c_BFu0c");
    static STRUCT_IF_C Vp_BFu1c_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu1c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu1c_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu1c_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1c_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu1c_BFu0c, Vp_BFu1c_BFu0c)
//============================================================================



static void Test_Vp_BFu1c_BFu0i()
{
  {
    init_simple_test("Vp_BFu1c_BFu0i");
    static STRUCT_IF_C Vp_BFu1c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu1c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1c_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu1c_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1c_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu1c_BFu0i, Vp_BFu1c_BFu0i)
//============================================================================



static void Test_Vp_BFu1c_BFu0ll()
{
  {
    init_simple_test("Vp_BFu1c_BFu0ll");
    static STRUCT_IF_C Vp_BFu1c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu1c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu1c_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1c_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu1c_BFu0ll, Vp_BFu1c_BFu0ll)
//============================================================================



static void Test_Vp_BFu1c_BFu0s()
{
  {
    init_simple_test("Vp_BFu1c_BFu0s");
    static STRUCT_IF_C Vp_BFu1c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu1c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1c_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu1c_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1c_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu1c_BFu0s, Vp_BFu1c_BFu0s)
//============================================================================



static void Test_Vp_BFu1i_BFu0c()
{
  {
    init_simple_test("Vp_BFu1i_BFu0c");
    static STRUCT_IF_C Vp_BFu1i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu1i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu1i_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu1i_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu1i_BFu0c, Vp_BFu1i_BFu0c)
//============================================================================



static void Test_Vp_BFu1i_BFu0i()
{
  {
    init_simple_test("Vp_BFu1i_BFu0i");
    static STRUCT_IF_C Vp_BFu1i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu1i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1i_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu1i_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu1i_BFu0i, Vp_BFu1i_BFu0i)
//============================================================================



static void Test_Vp_BFu1i_BFu0ll()
{
  {
    init_simple_test("Vp_BFu1i_BFu0ll");
    static STRUCT_IF_C Vp_BFu1i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu1i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu1i_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu1i_BFu0ll, Vp_BFu1i_BFu0ll)
//============================================================================



static void Test_Vp_BFu1i_BFu0s()
{
  {
    init_simple_test("Vp_BFu1i_BFu0s");
    static STRUCT_IF_C Vp_BFu1i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu1i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1i_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu1i_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu1i_BFu0s, Vp_BFu1i_BFu0s)
//============================================================================



static void Test_Vp_BFu1ll_BFu0c()
{
  {
    init_simple_test("Vp_BFu1ll_BFu0c");
    static STRUCT_IF_C Vp_BFu1ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu1ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu1ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu1ll_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu1ll_BFu0c, Vp_BFu1ll_BFu0c)
//============================================================================



static void Test_Vp_BFu1ll_BFu0i()
{
  {
    init_simple_test("Vp_BFu1ll_BFu0i");
    static STRUCT_IF_C Vp_BFu1ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu1ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu1ll_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu1ll_BFu0i, Vp_BFu1ll_BFu0i)
//============================================================================



static void Test_Vp_BFu1ll_BFu0ll()
{
  {
    init_simple_test("Vp_BFu1ll_BFu0ll");
    static STRUCT_IF_C Vp_BFu1ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu1ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu1ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu1ll_BFu0ll, Vp_BFu1ll_BFu0ll)
//============================================================================



static void Test_Vp_BFu1ll_BFu0s()
{
  {
    init_simple_test("Vp_BFu1ll_BFu0s");
    static STRUCT_IF_C Vp_BFu1ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu1ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu1ll_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu1ll_BFu0s, Vp_BFu1ll_BFu0s)
//============================================================================



static void Test_Vp_BFu1s_BFu0c()
{
  {
    init_simple_test("Vp_BFu1s_BFu0c");
    static STRUCT_IF_C Vp_BFu1s_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu1s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu1s_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu1s_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu1s_BFu0c, Vp_BFu1s_BFu0c)
//============================================================================



static void Test_Vp_BFu1s_BFu0i()
{
  {
    init_simple_test("Vp_BFu1s_BFu0i");
    static STRUCT_IF_C Vp_BFu1s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu1s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1s_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu1s_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu1s_BFu0i, Vp_BFu1s_BFu0i)
//============================================================================



static void Test_Vp_BFu1s_BFu0ll()
{
  {
    init_simple_test("Vp_BFu1s_BFu0ll");
    static STRUCT_IF_C Vp_BFu1s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu1s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu1s_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu1s_BFu0ll, Vp_BFu1s_BFu0ll)
//============================================================================



static void Test_Vp_BFu1s_BFu0s()
{
  {
    init_simple_test("Vp_BFu1s_BFu0s");
    static STRUCT_IF_C Vp_BFu1s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu1s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu1s_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu1s_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "Vp_BFu1s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu1s_BFu0s, Vp_BFu1s_BFu0s)
//============================================================================



static void Test_Vp_BFu31i_BFu0c()
{
  {
    init_simple_test("Vp_BFu31i_BFu0c");
    static STRUCT_IF_C Vp_BFu31i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu31i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu31i_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu31i_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu31i_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu31i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu31i_BFu0c, Vp_BFu31i_BFu0c)
//============================================================================



static void Test_Vp_BFu31i_BFu0i()
{
  {
    init_simple_test("Vp_BFu31i_BFu0i");
    static STRUCT_IF_C Vp_BFu31i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu31i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu31i_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu31i_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu31i_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu31i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu31i_BFu0i, Vp_BFu31i_BFu0i)
//============================================================================



static void Test_Vp_BFu31i_BFu0ll()
{
  {
    init_simple_test("Vp_BFu31i_BFu0ll");
    static STRUCT_IF_C Vp_BFu31i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu31i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu31i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu31i_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu31i_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu31i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu31i_BFu0ll, Vp_BFu31i_BFu0ll)
//============================================================================



static void Test_Vp_BFu31i_BFu0s()
{
  {
    init_simple_test("Vp_BFu31i_BFu0s");
    static STRUCT_IF_C Vp_BFu31i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu31i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu31i_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu31i_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu31i_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu31i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu31i_BFu0s, Vp_BFu31i_BFu0s)
//============================================================================



static void Test_Vp_BFu31ll_BFu0c()
{
  {
    init_simple_test("Vp_BFu31ll_BFu0c");
    static STRUCT_IF_C Vp_BFu31ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu31ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu31ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu31ll_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu31ll_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu31ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu31ll_BFu0c, Vp_BFu31ll_BFu0c)
//============================================================================



static void Test_Vp_BFu31ll_BFu0i()
{
  {
    init_simple_test("Vp_BFu31ll_BFu0i");
    static STRUCT_IF_C Vp_BFu31ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu31ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu31ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu31ll_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu31ll_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu31ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu31ll_BFu0i, Vp_BFu31ll_BFu0i)
//============================================================================



static void Test_Vp_BFu31ll_BFu0ll()
{
  {
    init_simple_test("Vp_BFu31ll_BFu0ll");
    static STRUCT_IF_C Vp_BFu31ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu31ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu31ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu31ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu31ll_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu31ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu31ll_BFu0ll, Vp_BFu31ll_BFu0ll)
//============================================================================



static void Test_Vp_BFu31ll_BFu0s()
{
  {
    init_simple_test("Vp_BFu31ll_BFu0s");
    static STRUCT_IF_C Vp_BFu31ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu31ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu31ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu31ll_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "Vp_BFu31ll_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "Vp_BFu31ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu31ll_BFu0s, Vp_BFu31ll_BFu0s)
//============================================================================



static void Test_Vp_BFu32i_BFu0c()
{
  {
    init_simple_test("Vp_BFu32i_BFu0c");
    static STRUCT_IF_C Vp_BFu32i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu32i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu32i_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu32i_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32i_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32i_BFu0c, Vp_BFu32i_BFu0c)
//============================================================================



static void Test_Vp_BFu32i_BFu0i()
{
  {
    init_simple_test("Vp_BFu32i_BFu0i");
    static STRUCT_IF_C Vp_BFu32i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu32i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu32i_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu32i_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32i_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32i_BFu0i, Vp_BFu32i_BFu0i)
//============================================================================



static void Test_Vp_BFu32i_BFu0ll()
{
  {
    init_simple_test("Vp_BFu32i_BFu0ll");
    static STRUCT_IF_C Vp_BFu32i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu32i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu32i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu32i_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32i_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32i_BFu0ll, Vp_BFu32i_BFu0ll)
//============================================================================



static void Test_Vp_BFu32i_BFu0s()
{
  {
    init_simple_test("Vp_BFu32i_BFu0s");
    static STRUCT_IF_C Vp_BFu32i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu32i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu32i_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu32i_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32i_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32i_BFu0s, Vp_BFu32i_BFu0s)
//============================================================================



static void Test_Vp_BFu32ll_BFu0c()
{
  {
    init_simple_test("Vp_BFu32ll_BFu0c");
    static STRUCT_IF_C Vp_BFu32ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu32ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu32ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_BFu0c, Vp_BFu32ll_BFu0c)
//============================================================================



static void Test_Vp_BFu32ll_BFu0i()
{
  {
    init_simple_test("Vp_BFu32ll_BFu0i");
    static STRUCT_IF_C Vp_BFu32ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu32ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu32ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_BFu0i, Vp_BFu32ll_BFu0i)
//============================================================================



static void Test_Vp_BFu32ll_BFu0ll()
{
  {
    init_simple_test("Vp_BFu32ll_BFu0ll");
    static STRUCT_IF_C Vp_BFu32ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu32ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu32ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_BFu0ll, Vp_BFu32ll_BFu0ll)
//============================================================================



static void Test_Vp_BFu32ll_BFu0s()
{
  {
    init_simple_test("Vp_BFu32ll_BFu0s");
    static STRUCT_IF_C Vp_BFu32ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu32ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu32ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_BFu0s, Vp_BFu32ll_BFu0s)
//============================================================================



static void Test_Vp_BFu33_BFu0c()
{
  {
    init_simple_test("Vp_BFu33_BFu0c");
    static STRUCT_IF_C Vp_BFu33_BFu0c lv;
    check2(sizeof(lv), ABISELECT(13,9), "sizeof(Vp_BFu33_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu33_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu0c, Vp_BFu33_BFu0c)
//============================================================================



static void Test_Vp_BFu33_BFu0i()
{
  {
    init_simple_test("Vp_BFu33_BFu0i");
    static STRUCT_IF_C Vp_BFu33_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu33_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu0i, Vp_BFu33_BFu0i)
//============================================================================



static void Test_Vp_BFu33_BFu0ll()
{
  {
    init_simple_test("Vp_BFu33_BFu0ll");
    static STRUCT_IF_C Vp_BFu33_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu33_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu0ll, Vp_BFu33_BFu0ll)
//============================================================================



static void Test_Vp_BFu33_BFu0s()
{
  {
    init_simple_test("Vp_BFu33_BFu0s");
    static STRUCT_IF_C Vp_BFu33_BFu0s lv;
    check2(sizeof(lv), ABISELECT(14,10), "sizeof(Vp_BFu33_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu33_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu0s, Vp_BFu33_BFu0s)
//============================================================================



static void Test_Vp_BFu7c_BFu0c()
{
  {
    init_simple_test("Vp_BFu7c_BFu0c");
    static STRUCT_IF_C Vp_BFu7c_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu7c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu7c_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu0c, Vp_BFu7c_BFu0c)
//============================================================================



static void Test_Vp_BFu7c_BFu0i()
{
  {
    init_simple_test("Vp_BFu7c_BFu0i");
    static STRUCT_IF_C Vp_BFu7c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu7c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7c_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu0i, Vp_BFu7c_BFu0i)
//============================================================================



static void Test_Vp_BFu7c_BFu0ll()
{
  {
    init_simple_test("Vp_BFu7c_BFu0ll");
    static STRUCT_IF_C Vp_BFu7c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu0ll, Vp_BFu7c_BFu0ll)
//============================================================================



static void Test_Vp_BFu7c_BFu0s()
{
  {
    init_simple_test("Vp_BFu7c_BFu0s");
    static STRUCT_IF_C Vp_BFu7c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu7c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7c_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu0s, Vp_BFu7c_BFu0s)
//============================================================================



static void Test_Vp_BFu7i_BFu0c()
{
  {
    init_simple_test("Vp_BFu7i_BFu0c");
    static STRUCT_IF_C Vp_BFu7i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu7i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu7i_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu0c, Vp_BFu7i_BFu0c)
//============================================================================



static void Test_Vp_BFu7i_BFu0i()
{
  {
    init_simple_test("Vp_BFu7i_BFu0i");
    static STRUCT_IF_C Vp_BFu7i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu7i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7i_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu0i, Vp_BFu7i_BFu0i)
//============================================================================



static void Test_Vp_BFu7i_BFu0ll()
{
  {
    init_simple_test("Vp_BFu7i_BFu0ll");
    static STRUCT_IF_C Vp_BFu7i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu0ll, Vp_BFu7i_BFu0ll)
//============================================================================



static void Test_Vp_BFu7i_BFu0s()
{
  {
    init_simple_test("Vp_BFu7i_BFu0s");
    static STRUCT_IF_C Vp_BFu7i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu7i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7i_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu0s, Vp_BFu7i_BFu0s)
//============================================================================



static void Test_Vp_BFu7ll_BFu0c()
{
  {
    init_simple_test("Vp_BFu7ll_BFu0c");
    static STRUCT_IF_C Vp_BFu7ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu7ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu7ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu0c, Vp_BFu7ll_BFu0c)
//============================================================================



static void Test_Vp_BFu7ll_BFu0i()
{
  {
    init_simple_test("Vp_BFu7ll_BFu0i");
    static STRUCT_IF_C Vp_BFu7ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu7ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu0i, Vp_BFu7ll_BFu0i)
//============================================================================



static void Test_Vp_BFu7ll_BFu0ll()
{
  {
    init_simple_test("Vp_BFu7ll_BFu0ll");
    static STRUCT_IF_C Vp_BFu7ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu0ll, Vp_BFu7ll_BFu0ll)
//============================================================================



static void Test_Vp_BFu7ll_BFu0s()
{
  {
    init_simple_test("Vp_BFu7ll_BFu0s");
    static STRUCT_IF_C Vp_BFu7ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu7ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu0s, Vp_BFu7ll_BFu0s)
//============================================================================



static void Test_Vp_BFu7s_BFu0c()
{
  {
    init_simple_test("Vp_BFu7s_BFu0c");
    static STRUCT_IF_C Vp_BFu7s_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu7s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu7s_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu0c, Vp_BFu7s_BFu0c)
//============================================================================



static void Test_Vp_BFu7s_BFu0i()
{
  {
    init_simple_test("Vp_BFu7s_BFu0i");
    static STRUCT_IF_C Vp_BFu7s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu7s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7s_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu0i, Vp_BFu7s_BFu0i)
//============================================================================



static void Test_Vp_BFu7s_BFu0ll()
{
  {
    init_simple_test("Vp_BFu7s_BFu0ll");
    static STRUCT_IF_C Vp_BFu7s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu0ll, Vp_BFu7s_BFu0ll)
//============================================================================



static void Test_Vp_BFu7s_BFu0s()
{
  {
    init_simple_test("Vp_BFu7s_BFu0s");
    static STRUCT_IF_C Vp_BFu7s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu7s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu7s_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu0s, Vp_BFu7s_BFu0s)
//============================================================================



static void Test_Vp_BFu8c_BFu0c()
{
  {
    init_simple_test("Vp_BFu8c_BFu0c");
    static STRUCT_IF_C Vp_BFu8c_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu8c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu8c_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu0c, Vp_BFu8c_BFu0c)
//============================================================================



static void Test_Vp_BFu8c_BFu0i()
{
  {
    init_simple_test("Vp_BFu8c_BFu0i");
    static STRUCT_IF_C Vp_BFu8c_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu8c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8c_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu0i, Vp_BFu8c_BFu0i)
//============================================================================



static void Test_Vp_BFu8c_BFu0ll()
{
  {
    init_simple_test("Vp_BFu8c_BFu0ll");
    static STRUCT_IF_C Vp_BFu8c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu0ll, Vp_BFu8c_BFu0ll)
//============================================================================



static void Test_Vp_BFu8c_BFu0s()
{
  {
    init_simple_test("Vp_BFu8c_BFu0s");
    static STRUCT_IF_C Vp_BFu8c_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu8c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8c_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu0s, Vp_BFu8c_BFu0s)
//============================================================================



static void Test_Vp_BFu8i_BFu0c()
{
  {
    init_simple_test("Vp_BFu8i_BFu0c");
    static STRUCT_IF_C Vp_BFu8i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu8i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu8i_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu0c, Vp_BFu8i_BFu0c)
//============================================================================



static void Test_Vp_BFu8i_BFu0i()
{
  {
    init_simple_test("Vp_BFu8i_BFu0i");
    static STRUCT_IF_C Vp_BFu8i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu8i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8i_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu0i, Vp_BFu8i_BFu0i)
//============================================================================



static void Test_Vp_BFu8i_BFu0ll()
{
  {
    init_simple_test("Vp_BFu8i_BFu0ll");
    static STRUCT_IF_C Vp_BFu8i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu0ll, Vp_BFu8i_BFu0ll)
//============================================================================



static void Test_Vp_BFu8i_BFu0s()
{
  {
    init_simple_test("Vp_BFu8i_BFu0s");
    static STRUCT_IF_C Vp_BFu8i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu8i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8i_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu0s, Vp_BFu8i_BFu0s)
//============================================================================



static void Test_Vp_BFu8ll_BFu0c()
{
  {
    init_simple_test("Vp_BFu8ll_BFu0c");
    static STRUCT_IF_C Vp_BFu8ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu8ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu8ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu0c, Vp_BFu8ll_BFu0c)
//============================================================================



static void Test_Vp_BFu8ll_BFu0i()
{
  {
    init_simple_test("Vp_BFu8ll_BFu0i");
    static STRUCT_IF_C Vp_BFu8ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu8ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu0i, Vp_BFu8ll_BFu0i)
//============================================================================



static void Test_Vp_BFu8ll_BFu0ll()
{
  {
    init_simple_test("Vp_BFu8ll_BFu0ll");
    static STRUCT_IF_C Vp_BFu8ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu0ll, Vp_BFu8ll_BFu0ll)
//============================================================================



static void Test_Vp_BFu8ll_BFu0s()
{
  {
    init_simple_test("Vp_BFu8ll_BFu0s");
    static STRUCT_IF_C Vp_BFu8ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu8ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu0s, Vp_BFu8ll_BFu0s)
//============================================================================



static void Test_Vp_BFu8s_BFu0c()
{
  {
    init_simple_test("Vp_BFu8s_BFu0c");
    static STRUCT_IF_C Vp_BFu8s_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_BFu8s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu8s_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu0c, Vp_BFu8s_BFu0c)
//============================================================================



static void Test_Vp_BFu8s_BFu0i()
{
  {
    init_simple_test("Vp_BFu8s_BFu0i");
    static STRUCT_IF_C Vp_BFu8s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu8s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8s_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu0i, Vp_BFu8s_BFu0i)
//============================================================================



static void Test_Vp_BFu8s_BFu0ll()
{
  {
    init_simple_test("Vp_BFu8s_BFu0ll");
    static STRUCT_IF_C Vp_BFu8s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu0ll, Vp_BFu8s_BFu0ll)
//============================================================================



static void Test_Vp_BFu8s_BFu0s()
{
  {
    init_simple_test("Vp_BFu8s_BFu0s");
    static STRUCT_IF_C Vp_BFu8s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu8s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu8s_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu0s, Vp_BFu8s_BFu0s)
//============================================================================



static void Test_Vp_BFu9i_BFu0c()
{
  {
    init_simple_test("Vp_BFu9i_BFu0c");
    static STRUCT_IF_C Vp_BFu9i_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu9i_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu9i_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu0c, Vp_BFu9i_BFu0c)
//============================================================================



static void Test_Vp_BFu9i_BFu0i()
{
  {
    init_simple_test("Vp_BFu9i_BFu0i");
    static STRUCT_IF_C Vp_BFu9i_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu9i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu9i_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu0i, Vp_BFu9i_BFu0i)
//============================================================================



static void Test_Vp_BFu9i_BFu0ll()
{
  {
    init_simple_test("Vp_BFu9i_BFu0ll");
    static STRUCT_IF_C Vp_BFu9i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu9i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu0ll, Vp_BFu9i_BFu0ll)
//============================================================================



static void Test_Vp_BFu9i_BFu0s()
{
  {
    init_simple_test("Vp_BFu9i_BFu0s");
    static STRUCT_IF_C Vp_BFu9i_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu9i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu9i_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu0s, Vp_BFu9i_BFu0s)
//============================================================================



static void Test_Vp_BFu9ll_BFu0c()
{
  {
    init_simple_test("Vp_BFu9ll_BFu0c");
    static STRUCT_IF_C Vp_BFu9ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu9ll_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu9ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu0c, Vp_BFu9ll_BFu0c)
//============================================================================



static void Test_Vp_BFu9ll_BFu0i()
{
  {
    init_simple_test("Vp_BFu9ll_BFu0i");
    static STRUCT_IF_C Vp_BFu9ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu9ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu9ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu0i, Vp_BFu9ll_BFu0i)
//============================================================================



static void Test_Vp_BFu9ll_BFu0ll()
{
  {
    init_simple_test("Vp_BFu9ll_BFu0ll");
    static STRUCT_IF_C Vp_BFu9ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu9ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu0ll, Vp_BFu9ll_BFu0ll)
//============================================================================



static void Test_Vp_BFu9ll_BFu0s()
{
  {
    init_simple_test("Vp_BFu9ll_BFu0s");
    static STRUCT_IF_C Vp_BFu9ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu9ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu9ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu0s, Vp_BFu9ll_BFu0s)
//============================================================================



static void Test_Vp_BFu9s_BFu0c()
{
  {
    init_simple_test("Vp_BFu9s_BFu0c");
    static STRUCT_IF_C Vp_BFu9s_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu9s_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_BFu9s_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu0c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu0c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu0c, Vp_BFu9s_BFu0c)
//============================================================================



static void Test_Vp_BFu9s_BFu0i()
{
  {
    init_simple_test("Vp_BFu9s_BFu0i");
    static STRUCT_IF_C Vp_BFu9s_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_BFu9s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu9s_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu0i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu0i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu0i, Vp_BFu9s_BFu0i)
//============================================================================



static void Test_Vp_BFu9s_BFu0ll()
{
  {
    init_simple_test("Vp_BFu9s_BFu0ll");
    static STRUCT_IF_C Vp_BFu9s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu9s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu0ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu0ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu0ll, Vp_BFu9s_BFu0ll)
//============================================================================



static void Test_Vp_BFu9s_BFu0s()
{
  {
    init_simple_test("Vp_BFu9s_BFu0s");
    static STRUCT_IF_C Vp_BFu9s_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_BFu9s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_BFu9s_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu0s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu0s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu0s, Vp_BFu9s_BFu0s)
//============================================================================



static void Test_Vp_C_BFu0c()
{
  {
    init_simple_test("Vp_C_BFu0c");
    static STRUCT_IF_C Vp_C_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_C_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_C_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu0c, Vp_C_BFu0c)
//============================================================================



static void Test_Vp_C_BFu0i()
{
  {
    init_simple_test("Vp_C_BFu0i");
    static STRUCT_IF_C Vp_C_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_C_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_C_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu0i, Vp_C_BFu0i)
//============================================================================



static void Test_Vp_C_BFu0ll()
{
  {
    init_simple_test("Vp_C_BFu0ll");
    static STRUCT_IF_C Vp_C_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_C_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu0ll, Vp_C_BFu0ll)
//============================================================================



static void Test_Vp_C_BFu0s()
{
  {
    init_simple_test("Vp_C_BFu0s");
    static STRUCT_IF_C Vp_C_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_C_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_C_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu0s, Vp_C_BFu0s)
//============================================================================



static void Test_Vp_D_BFu0c()
{
  {
    init_simple_test("Vp_D_BFu0c");
    static STRUCT_IF_C Vp_D_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_D_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_D_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu0c, Vp_D_BFu0c)
//============================================================================



static void Test_Vp_D_BFu0i()
{
  {
    init_simple_test("Vp_D_BFu0i");
    static STRUCT_IF_C Vp_D_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_D_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_D_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu0i, Vp_D_BFu0i)
//============================================================================



static void Test_Vp_D_BFu0ll()
{
  {
    init_simple_test("Vp_D_BFu0ll");
    static STRUCT_IF_C Vp_D_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_D_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_D_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu0ll, Vp_D_BFu0ll)
//============================================================================



static void Test_Vp_D_BFu0s()
{
  {
    init_simple_test("Vp_D_BFu0s");
    static STRUCT_IF_C Vp_D_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_D_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_D_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu0s, Vp_D_BFu0s)
//============================================================================



static void Test_Vp_F_BFu0c()
{
  {
    init_simple_test("Vp_F_BFu0c");
    static STRUCT_IF_C Vp_F_BFu0c lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_F_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_F_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu0c, Vp_F_BFu0c)
//============================================================================



static void Test_Vp_F_BFu0i()
{
  {
    init_simple_test("Vp_F_BFu0i");
    static STRUCT_IF_C Vp_F_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_F_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_F_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu0i, Vp_F_BFu0i)
//============================================================================



static void Test_Vp_F_BFu0ll()
{
  {
    init_simple_test("Vp_F_BFu0ll");
    static STRUCT_IF_C Vp_F_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_F_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_F_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu0ll, Vp_F_BFu0ll)
//============================================================================



static void Test_Vp_F_BFu0s()
{
  {
    init_simple_test("Vp_F_BFu0s");
    static STRUCT_IF_C Vp_F_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_F_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_F_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu0s, Vp_F_BFu0s)
//============================================================================



static void Test_Vp_I_BFu0c()
{
  {
    init_simple_test("Vp_I_BFu0c");
    static STRUCT_IF_C Vp_I_BFu0c lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_I_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_I_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu0c, Vp_I_BFu0c)
//============================================================================



static void Test_Vp_I_BFu0i()
{
  {
    init_simple_test("Vp_I_BFu0i");
    static STRUCT_IF_C Vp_I_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_I_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_I_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu0i, Vp_I_BFu0i)
//============================================================================



static void Test_Vp_I_BFu0ll()
{
  {
    init_simple_test("Vp_I_BFu0ll");
    static STRUCT_IF_C Vp_I_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_I_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_I_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu0ll, Vp_I_BFu0ll)
//============================================================================



static void Test_Vp_I_BFu0s()
{
  {
    init_simple_test("Vp_I_BFu0s");
    static STRUCT_IF_C Vp_I_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_I_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_I_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu0s, Vp_I_BFu0s)
//============================================================================



static void Test_Vp_Ip_BFu0c()
{
  {
    init_simple_test("Vp_Ip_BFu0c");
    static STRUCT_IF_C Vp_Ip_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Ip_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Ip_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu0c, Vp_Ip_BFu0c)
//============================================================================



static void Test_Vp_Ip_BFu0i()
{
  {
    init_simple_test("Vp_Ip_BFu0i");
    static STRUCT_IF_C Vp_Ip_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Ip_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Ip_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu0i, Vp_Ip_BFu0i)
//============================================================================



static void Test_Vp_Ip_BFu0ll()
{
  {
    init_simple_test("Vp_Ip_BFu0ll");
    static STRUCT_IF_C Vp_Ip_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Ip_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Ip_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu0ll, Vp_Ip_BFu0ll)
//============================================================================



static void Test_Vp_Ip_BFu0s()
{
  {
    init_simple_test("Vp_Ip_BFu0s");
    static STRUCT_IF_C Vp_Ip_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Ip_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Ip_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu0s, Vp_Ip_BFu0s)
//============================================================================



static void Test_Vp_L_BFu0c()
{
  {
    init_simple_test("Vp_L_BFu0c");
    static STRUCT_IF_C Vp_L_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_L_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_L_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu0c, Vp_L_BFu0c)
//============================================================================



static void Test_Vp_L_BFu0i()
{
  {
    init_simple_test("Vp_L_BFu0i");
    static STRUCT_IF_C Vp_L_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_L_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_L_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu0i, Vp_L_BFu0i)
//============================================================================



static void Test_Vp_L_BFu0ll()
{
  {
    init_simple_test("Vp_L_BFu0ll");
    static STRUCT_IF_C Vp_L_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_L_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_L_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu0ll, Vp_L_BFu0ll)
//============================================================================



static void Test_Vp_L_BFu0s()
{
  {
    init_simple_test("Vp_L_BFu0s");
    static STRUCT_IF_C Vp_L_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_L_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_L_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu0s, Vp_L_BFu0s)
//============================================================================



static void Test_Vp_S_BFu0c()
{
  {
    init_simple_test("Vp_S_BFu0c");
    static STRUCT_IF_C Vp_S_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_S_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_S_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu0c, Vp_S_BFu0c)
//============================================================================



static void Test_Vp_S_BFu0i()
{
  {
    init_simple_test("Vp_S_BFu0i");
    static STRUCT_IF_C Vp_S_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_S_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_S_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu0i, Vp_S_BFu0i)
//============================================================================



static void Test_Vp_S_BFu0ll()
{
  {
    init_simple_test("Vp_S_BFu0ll");
    static STRUCT_IF_C Vp_S_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_S_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu0ll, Vp_S_BFu0ll)
//============================================================================



static void Test_Vp_S_BFu0s()
{
  {
    init_simple_test("Vp_S_BFu0s");
    static STRUCT_IF_C Vp_S_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_S_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_S_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu0s, Vp_S_BFu0s)
//============================================================================



static void Test_Vp_Uc_BFu0c()
{
  {
    init_simple_test("Vp_Uc_BFu0c");
    static STRUCT_IF_C Vp_Uc_BFu0c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Vp_Uc_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Uc_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu0c, Vp_Uc_BFu0c)
//============================================================================



static void Test_Vp_Uc_BFu0i()
{
  {
    init_simple_test("Vp_Uc_BFu0i");
    static STRUCT_IF_C Vp_Uc_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_Uc_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Uc_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu0i, Vp_Uc_BFu0i)
//============================================================================



static void Test_Vp_Uc_BFu0ll()
{
  {
    init_simple_test("Vp_Uc_BFu0ll");
    static STRUCT_IF_C Vp_Uc_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Uc_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu0ll, Vp_Uc_BFu0ll)
//============================================================================



static void Test_Vp_Uc_BFu0s()
{
  {
    init_simple_test("Vp_Uc_BFu0s");
    static STRUCT_IF_C Vp_Uc_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_Uc_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Uc_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu0s, Vp_Uc_BFu0s)
//============================================================================



static void Test_Vp_Ui_BFu0c()
{
  {
    init_simple_test("Vp_Ui_BFu0c");
    static STRUCT_IF_C Vp_Ui_BFu0c lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_Ui_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Ui_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu0c, Vp_Ui_BFu0c)
//============================================================================



static void Test_Vp_Ui_BFu0i()
{
  {
    init_simple_test("Vp_Ui_BFu0i");
    static STRUCT_IF_C Vp_Ui_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_Ui_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Ui_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu0i, Vp_Ui_BFu0i)
//============================================================================



static void Test_Vp_Ui_BFu0ll()
{
  {
    init_simple_test("Vp_Ui_BFu0ll");
    static STRUCT_IF_C Vp_Ui_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Ui_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Ui_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu0ll, Vp_Ui_BFu0ll)
//============================================================================



static void Test_Vp_Ui_BFu0s()
{
  {
    init_simple_test("Vp_Ui_BFu0s");
    static STRUCT_IF_C Vp_Ui_BFu0s lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_Ui_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Ui_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu0s, Vp_Ui_BFu0s)
//============================================================================



static void Test_Vp_Ul_BFu0c()
{
  {
    init_simple_test("Vp_Ul_BFu0c");
    static STRUCT_IF_C Vp_Ul_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ul_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Ul_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu0c, Vp_Ul_BFu0c)
//============================================================================



static void Test_Vp_Ul_BFu0i()
{
  {
    init_simple_test("Vp_Ul_BFu0i");
    static STRUCT_IF_C Vp_Ul_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ul_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Ul_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu0i, Vp_Ul_BFu0i)
//============================================================================



static void Test_Vp_Ul_BFu0ll()
{
  {
    init_simple_test("Vp_Ul_BFu0ll");
    static STRUCT_IF_C Vp_Ul_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ul_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Ul_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu0ll, Vp_Ul_BFu0ll)
//============================================================================



static void Test_Vp_Ul_BFu0s()
{
  {
    init_simple_test("Vp_Ul_BFu0s");
    static STRUCT_IF_C Vp_Ul_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ul_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Ul_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu0s, Vp_Ul_BFu0s)
//============================================================================



static void Test_Vp_Us_BFu0c()
{
  {
    init_simple_test("Vp_Us_BFu0c");
    static STRUCT_IF_C Vp_Us_BFu0c lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_Us_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Us_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu0c, Vp_Us_BFu0c)
//============================================================================



static void Test_Vp_Us_BFu0i()
{
  {
    init_simple_test("Vp_Us_BFu0i");
    static STRUCT_IF_C Vp_Us_BFu0i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Vp_Us_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Us_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu0i, Vp_Us_BFu0i)
//============================================================================



static void Test_Vp_Us_BFu0ll()
{
  {
    init_simple_test("Vp_Us_BFu0ll");
    static STRUCT_IF_C Vp_Us_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Us_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu0ll, Vp_Us_BFu0ll)
//============================================================================



static void Test_Vp_Us_BFu0s()
{
  {
    init_simple_test("Vp_Us_BFu0s");
    static STRUCT_IF_C Vp_Us_BFu0s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Vp_Us_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Us_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu0s, Vp_Us_BFu0s)
//============================================================================



static void Test_Vp_Vp_BFu0c()
{
  {
    init_simple_test("Vp_Vp_BFu0c");
    static STRUCT_IF_C Vp_Vp_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Vp_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Vp_Vp_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu0c, Vp_Vp_BFu0c)
//============================================================================



static void Test_Vp_Vp_BFu0i()
{
  {
    init_simple_test("Vp_Vp_BFu0i");
    static STRUCT_IF_C Vp_Vp_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Vp_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Vp_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu0i, Vp_Vp_BFu0i)
//============================================================================



static void Test_Vp_Vp_BFu0ll()
{
  {
    init_simple_test("Vp_Vp_BFu0ll");
    static STRUCT_IF_C Vp_Vp_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Vp_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Vp_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu0ll, Vp_Vp_BFu0ll)
//============================================================================



static void Test_Vp_Vp_BFu0s()
{
  {
    init_simple_test("Vp_Vp_BFu0s");
    static STRUCT_IF_C Vp_Vp_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Vp_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Vp_Vp_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu0s, Vp_Vp_BFu0s)
//============================================================================

