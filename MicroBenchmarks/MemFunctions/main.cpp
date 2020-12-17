//===- main.cc - Memory Functions Benchmarks ------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// Memory functions (memcmp, memcpy, ...) are typically recognized by the
// compiler and expanded to specific asm patterns when the size is known at
// compile time. THese microbenchmarks help catch potential CodeGen regressions.
//
// Note that these microbenchmarks do not represent a typical real-life
// situation. They are designed to test the LLVM CodeGen. In particular,
// real-life applications will typically be memory- rather than compute-bound
// when manipulating memory.
//
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

#include "benchmark/benchmark.h"

// This function prevents the compiler from interfering with `memcmp` and
// makes sure the function is called.
__attribute__((no_builtin("memcmp")))
int RealMemCmp(const char *p, const char *q, size_t s) {
  return memcmp(p, q, s);
}

// Benchmarks `memcmp(p, q, size) OP 0` where n is known at compile time and OP
// is defined by `Pred`. The compiler typically inlines the memcmp + comparion
// to loads and compares.
template <int kSize, typename Pred, typename Mod>
void BM_MemCmp(benchmark::State& state) {
  // The buffer size should be large enough that there are several elements in a
  // buffer, but small enough to fit in cache. Alsom the smaller the buffer
  // size, the more latency the benchmark framework has to adjust the number of
  // iterations to make benchmarking faster.
  static constexpr size_t kMaxBufSizeBytes = 4096;
  constexpr const size_t kNumElements = kMaxBufSizeBytes / kSize;

  std::vector<char> p_storage(kNumElements * kSize);
  std::vector<char> q_storage(kNumElements * kSize);
  char* p = p_storage.data();
  const char* q = q_storage.data();

  // We're comparing an all-zeros buffer (q) vs an all-zeros-but-one-element
  // buffer (p). The non-zero element is detemined by `Mod`.
  for (int i = 0; i < kNumElements; ++i)
    Mod().template Change<kSize>(p + i * kSize);

  // First check the validity of the results.
  if (Pred::Cmp(RealMemCmp(p, q, kSize)) != Pred::Cmp(memcmp(p, q, kSize))) {
    std::cerr << "invalid results for Pred=" << Pred::kDisplay
              << " Mod=" << Mod::kDisplay << " kSize=" << kSize << std::endl;
    std::exit(1);
  }

  benchmark::DoNotOptimize(p);
  benchmark::DoNotOptimize(q);

  for (auto _ : state) {
    benchmark::ClobberMemory();
    benchmark::ClobberMemory();

    for (int i = 0; i < kNumElements; ++i) {
      bool res = Pred::Cmp(memcmp(p + i * kSize, q + i * kSize, kSize));
      benchmark::DoNotOptimize(res);
    }
  }
  state.SetBytesProcessed(p_storage.size() * state.iterations());
}

// Predicates.
struct EqZero {
  static bool Cmp(int v) { return v == 0; }
  inline static constexpr const char kDisplay[] = "EqZero";
};
struct LessThanZero {
  static bool Cmp(int v) { return v < 0; }
  inline static constexpr const char kDisplay[] = "LessThanZero";
};
struct GreaterThanZero {
  static bool Cmp(int v) { return v > 0; }
  inline static constexpr const char kDisplay[] = "GreaterThanZero";
};

// Functors to change the first/mid/last or no value.
struct None {
  template <int kSize>
  void Change(char* const p) const {}
  inline static constexpr const char kDisplay[] = "None";
};
struct First {
  template <int kSize> void Change(char *const p) const { p[0] = 0xff; }
  inline static constexpr const char kDisplay[] = "First";
};
struct Mid {
  template <int kSize> void Change(char *const p) const { p[kSize / 2] = 0xff; }
  inline static constexpr const char kDisplay[] = "Mid";
};
struct Last {
  template <int kSize> void Change(char *const p) const { p[kSize - 1] = 0xff; }
  inline static constexpr const char kDisplay[] = "Last";
};

#define MEMCMP_BENCHMARK_PRED_CHANGE(size, pred, change) \
  BENCHMARK_TEMPLATE(BM_MemCmp, size, pred, change)      \
      ->Unit(benchmark::kNanosecond);

#define MEMCMP_BENCHMARK_PRED(size, pred)          \
  MEMCMP_BENCHMARK_PRED_CHANGE(size, pred, None);  \
  MEMCMP_BENCHMARK_PRED_CHANGE(size, pred, First); \
  MEMCMP_BENCHMARK_PRED_CHANGE(size, pred, Mid);   \
  MEMCMP_BENCHMARK_PRED_CHANGE(size, pred, Last);

#define MEMCMP_BENCHMARK(size)              \
  MEMCMP_BENCHMARK_PRED(size, EqZero)       \
  MEMCMP_BENCHMARK_PRED(size, LessThanZero) \
  MEMCMP_BENCHMARK_PRED(size, GreaterThanZero)

MEMCMP_BENCHMARK(1)
MEMCMP_BENCHMARK(2)
MEMCMP_BENCHMARK(3)
MEMCMP_BENCHMARK(4)
MEMCMP_BENCHMARK(5)
MEMCMP_BENCHMARK(6)
MEMCMP_BENCHMARK(7)
MEMCMP_BENCHMARK(8)
MEMCMP_BENCHMARK(15)
MEMCMP_BENCHMARK(16)
MEMCMP_BENCHMARK(31)
MEMCMP_BENCHMARK(32)
MEMCMP_BENCHMARK(63)
MEMCMP_BENCHMARK(64)

BENCHMARK_MAIN();
