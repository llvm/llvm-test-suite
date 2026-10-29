//===- VectorMulI8Bench.cpp - Benchmark vXi8 multiply optimization -------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This benchmark measures the performance of the vXi8 splat multiply
// optimization that decomposes 8-bit vector multiplies by constants into
// shift-add-sub sequences.
//
// The optimization transforms `vXi8 * splat_constant` operations where the
// constant can be expressed as:
// - Sum of two powers of 2: 2^a + 2^b (e.g., 6 = 4 + 2, 10 = 8 + 2)
// - Difference of two powers of 2: 2^a - 2^b (e.g., 6 = 8 - 2, 12 = 16 - 4)
//
//===----------------------------------------------------------------------===//

#include "benchmark/benchmark.h"
#include <cstdint>

typedef int8_t v16i8 __attribute__((vector_size(16)));  // SSE2: 128-bit
typedef int8_t v32i8 __attribute__((vector_size(32)));  // AVX2: 256-bit
typedef int8_t v64i8 __attribute__((vector_size(64)));  // AVX-512: 512-bit

// Initialize vectors with varying values to prevent constant folding
static v16i8 initV16i8() {
  return v16i8{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
}

static v32i8 initV32i8() {
  return v32i8{1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16,
               17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32};
}

static v64i8 initV64i8() {
  return v64i8{1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16,
               17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
               33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48,
               49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64};
}

//===----------------------------------------------------------------------===//
// v16i8 benchmarks (SSE2) - 128-bit vectors
//
// These test constants that decompose as sums of two powers of 2:
// 6 = 4 + 2, 10 = 8 + 2, 12 = 8 + 4, 18 = 16 + 2, 20 = 16 + 4,
// 24 = 16 + 8, 34 = 32 + 2, 36 = 32 + 4, 40 = 32 + 8
//===----------------------------------------------------------------------===//

// 6 = 4 + 2 = 2^2 + 2^1
static void BM_v16i8_Mul6(benchmark::State &State) {
  v16i8 input = initV16i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);  // Prevent constant folding of input
    v16i8 result = input * 6;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v16i8_Mul6);

// 10 = 8 + 2 = 2^3 + 2^1
static void BM_v16i8_Mul10(benchmark::State &State) {
  v16i8 input = initV16i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v16i8 result = input * 10;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v16i8_Mul10);

// 12 = 8 + 4 = 2^3 + 2^2
static void BM_v16i8_Mul12(benchmark::State &State) {
  v16i8 input = initV16i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v16i8 result = input * 12;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v16i8_Mul12);

// 18 = 16 + 2 = 2^4 + 2^1
static void BM_v16i8_Mul18(benchmark::State &State) {
  v16i8 input = initV16i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v16i8 result = input * 18;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v16i8_Mul18);

// 20 = 16 + 4 = 2^4 + 2^2
static void BM_v16i8_Mul20(benchmark::State &State) {
  v16i8 input = initV16i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v16i8 result = input * 20;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v16i8_Mul20);

// 24 = 16 + 8 = 2^4 + 2^3
static void BM_v16i8_Mul24(benchmark::State &State) {
  v16i8 input = initV16i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v16i8 result = input * 24;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v16i8_Mul24);

// 34 = 32 + 2 = 2^5 + 2^1
static void BM_v16i8_Mul34(benchmark::State &State) {
  v16i8 input = initV16i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v16i8 result = input * 34;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v16i8_Mul34);

// 36 = 32 + 4 = 2^5 + 2^2
static void BM_v16i8_Mul36(benchmark::State &State) {
  v16i8 input = initV16i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v16i8 result = input * 36;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v16i8_Mul36);

// 40 = 32 + 8 = 2^5 + 2^3
static void BM_v16i8_Mul40(benchmark::State &State) {
  v16i8 input = initV16i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v16i8 result = input * 40;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v16i8_Mul40);

// Negative constants: -6 = -(4 + 2)
static void BM_v16i8_MulNeg6(benchmark::State &State) {
  v16i8 input = initV16i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v16i8 result = input * -6;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v16i8_MulNeg6);

// -12 = -(8 + 4)
static void BM_v16i8_MulNeg12(benchmark::State &State) {
  v16i8 input = initV16i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v16i8 result = input * -12;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v16i8_MulNeg12);

//===----------------------------------------------------------------------===//
// v32i8 benchmarks (AVX2) - 256-bit vectors
//===----------------------------------------------------------------------===//

// 6 = 4 + 2 = 2^2 + 2^1
static void BM_v32i8_Mul6(benchmark::State &State) {
  v32i8 input = initV32i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v32i8 result = input * 6;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v32i8_Mul6);

// 10 = 8 + 2 = 2^3 + 2^1
static void BM_v32i8_Mul10(benchmark::State &State) {
  v32i8 input = initV32i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v32i8 result = input * 10;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v32i8_Mul10);

// 12 = 8 + 4 = 2^3 + 2^2
static void BM_v32i8_Mul12(benchmark::State &State) {
  v32i8 input = initV32i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v32i8 result = input * 12;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v32i8_Mul12);

// 18 = 16 + 2 = 2^4 + 2^1
static void BM_v32i8_Mul18(benchmark::State &State) {
  v32i8 input = initV32i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v32i8 result = input * 18;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v32i8_Mul18);

// 20 = 16 + 4 = 2^4 + 2^2
static void BM_v32i8_Mul20(benchmark::State &State) {
  v32i8 input = initV32i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v32i8 result = input * 20;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v32i8_Mul20);

// 24 = 16 + 8 = 2^4 + 2^3
static void BM_v32i8_Mul24(benchmark::State &State) {
  v32i8 input = initV32i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v32i8 result = input * 24;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v32i8_Mul24);

// 34 = 32 + 2 = 2^5 + 2^1
static void BM_v32i8_Mul34(benchmark::State &State) {
  v32i8 input = initV32i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v32i8 result = input * 34;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v32i8_Mul34);

// 36 = 32 + 4 = 2^5 + 2^2
static void BM_v32i8_Mul36(benchmark::State &State) {
  v32i8 input = initV32i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v32i8 result = input * 36;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v32i8_Mul36);

// 40 = 32 + 8 = 2^5 + 2^3
static void BM_v32i8_Mul40(benchmark::State &State) {
  v32i8 input = initV32i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v32i8 result = input * 40;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v32i8_Mul40);

// Negative constants
static void BM_v32i8_MulNeg6(benchmark::State &State) {
  v32i8 input = initV32i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v32i8 result = input * -6;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v32i8_MulNeg6);

static void BM_v32i8_MulNeg12(benchmark::State &State) {
  v32i8 input = initV32i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v32i8 result = input * -12;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v32i8_MulNeg12);

//===----------------------------------------------------------------------===//
// v64i8 benchmarks (AVX-512BW) - 512-bit vectors
// Note: These require AVX-512BW support at runtime
//===----------------------------------------------------------------------===//

// 6 = 4 + 2 = 2^2 + 2^1
static void BM_v64i8_Mul6(benchmark::State &State) {
  v64i8 input = initV64i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v64i8 result = input * 6;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v64i8_Mul6);

// 10 = 8 + 2 = 2^3 + 2^1
static void BM_v64i8_Mul10(benchmark::State &State) {
  v64i8 input = initV64i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v64i8 result = input * 10;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v64i8_Mul10);

// 12 = 8 + 4 = 2^3 + 2^2
static void BM_v64i8_Mul12(benchmark::State &State) {
  v64i8 input = initV64i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v64i8 result = input * 12;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v64i8_Mul12);

// 18 = 16 + 2 = 2^4 + 2^1
static void BM_v64i8_Mul18(benchmark::State &State) {
  v64i8 input = initV64i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v64i8 result = input * 18;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v64i8_Mul18);

// 20 = 16 + 4 = 2^4 + 2^2
static void BM_v64i8_Mul20(benchmark::State &State) {
  v64i8 input = initV64i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v64i8 result = input * 20;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v64i8_Mul20);

// 24 = 16 + 8 = 2^4 + 2^3
static void BM_v64i8_Mul24(benchmark::State &State) {
  v64i8 input = initV64i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v64i8 result = input * 24;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v64i8_Mul24);

// 34 = 32 + 2 = 2^5 + 2^1
static void BM_v64i8_Mul34(benchmark::State &State) {
  v64i8 input = initV64i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v64i8 result = input * 34;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v64i8_Mul34);

// 36 = 32 + 4 = 2^5 + 2^2
static void BM_v64i8_Mul36(benchmark::State &State) {
  v64i8 input = initV64i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v64i8 result = input * 36;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v64i8_Mul36);

// 40 = 32 + 8 = 2^5 + 2^3
static void BM_v64i8_Mul40(benchmark::State &State) {
  v64i8 input = initV64i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v64i8 result = input * 40;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v64i8_Mul40);

// Negative constants
static void BM_v64i8_MulNeg6(benchmark::State &State) {
  v64i8 input = initV64i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v64i8 result = input * -6;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v64i8_MulNeg6);

static void BM_v64i8_MulNeg12(benchmark::State &State) {
  v64i8 input = initV64i8();
  for (auto _ : State) {
    benchmark::DoNotOptimize(input);
    v64i8 result = input * -12;
    benchmark::DoNotOptimize(result);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(BM_v64i8_MulNeg12);

BENCHMARK_MAIN();
