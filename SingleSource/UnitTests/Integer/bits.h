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

typedef unsigned int __attribute__((bitwidth(1))) Int1;
typedef unsigned int __attribute__((bitwidth(2))) Int2;
typedef unsigned int __attribute__((bitwidth(3))) Int3;
typedef unsigned int __attribute__((bitwidth(4))) Int4;
typedef unsigned int __attribute__((bitwidth(5))) Int5;
typedef unsigned int __attribute__((bitwidth(6))) Int6;
typedef unsigned int __attribute__((bitwidth(7))) Int7;
typedef unsigned int __attribute__((bitwidth(8))) Int8;
typedef unsigned int __attribute__((bitwidth(16))) Int16;
typedef unsigned int __attribute__((bitwidth(17))) Int17;
typedef unsigned int __attribute__((bitwidth(19))) Int19;
typedef unsigned int __attribute__((bitwidth(17))) Int32;
typedef unsigned int __attribute__((bitwidth(36))) Int36;
typedef unsigned int __attribute__((bitwidth(47))) Int47;
typedef unsigned int __attribute__((bitwidth(48))) Int48;
typedef unsigned int __attribute__((bitwidth(64))) Int64;
typedef unsigned int __attribute__((bitwidth(65))) Int65;
typedef unsigned int __attribute__((bitwidth(128))) Int128;
/*typedef unsigned int __attribute__((bitwidth(256))) Int256; */

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
  __builtin_bit_set(&Result, &Val2, &Repl, Bit); \
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

