//===--- bits.h --- Test The bit_select builtin ---------------------------===//
//
// This file was developed by Reid Spencer and is distributed under the 
// University of Illinois Open Source License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains some type and macro definitiosn useful for working
// with bit accurate types and the bitwise builtins
//
//===----------------------------------------------------------------------===//

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int __attribute__((bitwidth(1))) uint1;
typedef unsigned int __attribute__((bitwidth(2))) uint2;
typedef unsigned int __attribute__((bitwidth(3))) uint3;
typedef unsigned int __attribute__((bitwidth(4))) uint4;
typedef unsigned int __attribute__((bitwidth(5))) uint5;
typedef unsigned int __attribute__((bitwidth(6))) uint6;
typedef unsigned int __attribute__((bitwidth(7))) uint7;
typedef unsigned int __attribute__((bitwidth(8))) uint8;
typedef unsigned int __attribute__((bitwidth(9))) uint9;
typedef unsigned int __attribute__((bitwidth(10))) uint10;
typedef unsigned int __attribute__((bitwidth(16))) uint16;
typedef unsigned int __attribute__((bitwidth(17))) uint17;
typedef unsigned int __attribute__((bitwidth(19))) uint19;
typedef unsigned int __attribute__((bitwidth(21))) uint21;
typedef unsigned int __attribute__((bitwidth(17))) uint32;
typedef unsigned int __attribute__((bitwidth(36))) uint36;
typedef unsigned int __attribute__((bitwidth(47))) uint47;
typedef unsigned int __attribute__((bitwidth(48))) uint48;
typedef unsigned int __attribute__((bitwidth(64))) uint64;
typedef unsigned int __attribute__((bitwidth(65))) uint65;
typedef unsigned int __attribute__((bitwidth(128))) uint128;

typedef int __attribute__ ((bitwidth(9))) int9;
typedef int __attribute__((bitwidth(10))) int10;
typedef int __attribute__((bitwidth(21))) int21;
typedef int __attribute__((bitwidth(24))) int24;
typedef int __attribute__((bitwidth(32))) int32;
typedef int __attribute__((bitwidth(33))) int33;

typedef int __attribute__((bitwidth(169))) int169;
typedef unsigned int __attribute__((bitwidth(250))) Int250;
typedef unsigned int __attribute__((bitwidth(256))) Int256;

#define bitwidthof(TORV) (__bitwidthof__(typeof(TORV)))

#define bit_concat(X, Y) ({ \
  unsigned int __attribute__((bitwidth(__bitwidthof__(X)+__bitwidthof__(Y)))) R; \
  typeof(X) X2 = X; \
  typeof(Y) Y2 = Y; \
  __builtin_bit_concat(&R, &X2, &Y2); \
  R; \
})

#define bit_select(Val, Bit) ({ \
  typeof(Val) Val2 = Val; \
  __builtin_bit_select(&Val2, Bit); \
})

#define bit_set(Val, Repl, Bit) ({ \
  typeof(Val) Result = 0; \
  typeof(Val) Val2 = Val; \
  typeof(Repl) Repl2 = Repl; \
  __builtin_bit_set(&Result, &Val2, &Repl2, Bit); \
  Result; \
})


#define part_select(Val, Lo, Hi) ({ \
  typeof(Val) Result = 0; \
  typeof(Val) Val2 = Val; \
  __builtin_bit_part_select(&Result, &Val2, Lo, Hi); \
  Result; \
})

#define part_set(Val, Repl, Lo, Hi) ({ \
  typeof(Val) Result = 0; \
  typeof(Val) Val2 = Val; \
  typeof(Repl) Repl2 = Repl; \
  __builtin_bit_part_set(&Result, &Val2, &Repl2, Lo, Hi); \
  Result; \
})

#define reduce(how, what) { \
  typeof(what) what2 = what; \
  __bulitin_bit_reduce_ ## how(&what2); \
}

#define printBits(val) { \
  int bit = bitwidthof(val); \
  for ( ; bit > 0; --bit) { \
    if (bit_select(val, bit-1)) \
      putchar('1'); \
    else \
      putchar('0'); \
  } \
} 

#define bitsFromString(str,bits) ({ \
  int __attribute__((bitwidth(bits))) Result; \
  __builtin_bit_from_string(&Result, str, 10); \
  Result; \
})
