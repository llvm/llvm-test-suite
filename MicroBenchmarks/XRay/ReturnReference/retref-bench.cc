//===- retref-bench.cc - XRay Instrumentation Benchmarks ------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// Define benchmarks for measuring the cost of XRay instrumentation (the sleds,
// the trampolines).
//
//===----------------------------------------------------------------------===//

#include <x86intrin.h>

#include "benchmark/benchmark.h"
#include "xray/xray_interface.h"

[[clang::xray_never_instrument]] __attribute__((noinline)) int
neverInstrumented() {
  benchmark::ClobberMemory();
  return 0;
}

[[clang::xray_never_instrument]] static void BM_ReturnNeverInstrumented(
    benchmark::State& state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(neverInstrumented());
  }
}

BENCHMARK(BM_ReturnNeverInstrumented);

[[clang::xray_always_instrument]] __attribute__((noinline)) int
alwaysInstrumented() {
  benchmark::ClobberMemory();
  return 0;
}

[[clang::xray_never_instrument]] static void BM_ReturnInstrumentedUnPatched(
    benchmark::State& state) {
  __xray_unpatch();
  for (auto _ : state) {
    int x;
    benchmark::DoNotOptimize(x = alwaysInstrumented());
    benchmark::ClobberMemory();
  }
}

BENCHMARK(BM_ReturnInstrumentedUnPatched);


[[clang::xray_never_instrument]] static void BM_ReturnInstrumentedPatchedThenUnpatched(
    benchmark::State& state) {
  __xray_patch();
  __xray_unpatch();
  for (auto _ : state) {
    int x;
    benchmark::DoNotOptimize(x = alwaysInstrumented());
    benchmark::ClobberMemory();
  }
}

BENCHMARK(BM_ReturnInstrumentedPatchedThenUnpatched);


[[clang::xray_never_instrument]] static void BM_ReturnInstrumentedPatched(
    benchmark::State& state) {
  __xray_patch();
  for (auto _ : state) {
    int x;
    benchmark::DoNotOptimize(alwaysInstrumented());
    benchmark::ClobberMemory();
  }
}

BENCHMARK(BM_ReturnInstrumentedPatched);

[[clang::xray_never_instrument]] static void BM_RDTSCP_Cost(
    benchmark::State& state) {
  for (auto _ : state) {
    unsigned cpu;
    unsigned tsc;
    benchmark::DoNotOptimize(tsc = __rdtscp(&cpu));
    benchmark::ClobberMemory();
  }
}

volatile unsigned global_cpu;
volatile unsigned tsc;
[[clang::xray_never_instrument]] void benchmark_handler(int32_t,
                                                        XRayEntryType) {
  unsigned cpu;
  benchmark::DoNotOptimize(tsc = __rdtscp(&cpu));
  global_cpu = cpu;
  benchmark::ClobberMemory();
}

BENCHMARK(BM_RDTSCP_Cost);

[[clang::xray_never_instrument]] static void
BM_ReturnInstrumentedPatchedWithLogHandler(benchmark::State& state) {
  __xray_set_handler(benchmark_handler);
  __xray_patch();
  benchmark::ClobberMemory();
  for (auto _ : state) {
    int x;
    benchmark::DoNotOptimize(x = alwaysInstrumented());
    benchmark::ClobberMemory();
  }
  __xray_remove_handler();
}

BENCHMARK(BM_ReturnInstrumentedPatchedWithLogHandler);

BENCHMARK_MAIN();
