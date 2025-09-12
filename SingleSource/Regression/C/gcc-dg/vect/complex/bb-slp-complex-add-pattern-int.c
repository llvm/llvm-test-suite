/* { dg-do compile } */
/* { dg-require-effective-target stdint_types } */
/* { dg-require-effective-target vect_int } */
/* { dg-add-options arm_v8_3a_complex_neon } */
/* { dg-additional-options "-fno-tree-loop-vectorize" } */

#define TYPE int32_t
#define N 16
#include <stdint.h>
#include "complex-add-pattern-template.c"

/* { dg-final { scan-tree-dump-times "stmt.*COMPLEX_ADD_ROT90" 1 "slp1" { target { vect_complex_add_byte } } } } */
/* { dg-final { scan-tree-dump-times "stmt.*COMPLEX_ADD_ROT270" 1 "slp1" { target { vect_complex_add_int } && ! target { aarch64_sve2 } } } } */
/* { dg-final { scan-tree-dump "Found COMPLEX_ADD_ROT270" "slp1" } } */
/* { dg-final { scan-tree-dump "Found COMPLEX_ADD_ROT90" "slp1" } } */
