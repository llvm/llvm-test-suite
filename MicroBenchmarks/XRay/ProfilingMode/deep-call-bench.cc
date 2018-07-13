//===- deep-call-bench.cc - XRay Profiling Mode Benchmarks ----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// These benchmarks measure the cost of XRay profiling mode when enabled.
//
//===----------------------------------------------------------------------===//

#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>
#include "benchmark/benchmark.h"
#include "xray/xray_log_interface.h"

namespace {

std::atomic<int> some_global{1};

std::atomic<int> some_temporary{0};

[[clang::xray_never_instrument]] static void profiling_setup() {
  if (__xray_log_select_mode("xray-profiling") != XRAY_REGISTRATION_OK) {
    std::cerr << "Failed selecting 'xray-profiling' mode. Aborting.\n";
    std::abort();
  }

  if (__xray_log_init_mode("xray-profiling", "no_flush=true") !=
      XRAY_LOG_INITIALIZED) {
    std::cerr << "Failed initializing xray-profiling mode. Aborting.\n";
    std::abort();
  };

  __xray_patch();
}

[[clang::xray_never_instrument]] static void profiling_teardown() {
  if (__xray_log_finalize() != XRAY_LOG_FINALIZED) {
    std::cerr << "Failed to finalize xray-profiling mode. Aborting.\n";
    std::abort();
  }

  if (__xray_log_flushLog() != XRAY_LOG_FLUSHED) {
    std::cerr << "Failed to flush xray-profiling mode. Aborting.\n";
    std::abort();
  }
}

}  // namespace

[[clang::xray_always_instrument]] __attribute__((weak))
__attribute__((noinline)) int
deep(int depth) {
  if (depth == 0) return some_global.load(std::memory_order_acquire);
  return some_global.load(std::memory_order_acquire) + deep(depth - 1);
}

// This benchmark measures the cost of XRay instrumentation in deep function
// call stacks, where each function has been instrumented. We use function call
// recursion to control the depth of the recursion as an input. We make the
// recursion function a combination of: no-inline, have weak symbol binding, and
// force instrumentation with XRay. Each iteration of the benchmark will
// initialize the XRay profiling runtime, and then tear it down afterwards.
//
// We also run the benchmark on multiple threads, to track and identify
// whether/where the contention and scalability issues are in the implementation
// of the profiling runtime.
[[clang::xray_never_instrument]] static void BM_XRayProfilingDeepCallStack(
    benchmark::State &state) {
  if (state.thread_index == 0) profiling_setup();

  benchmark::DoNotOptimize(some_temporary = deep(state.range(0)));

  for (auto _ : state)
    benchmark::DoNotOptimize(some_temporary = deep(state.range(0)));

  if (state.thread_index == 0) profiling_teardown();
}
BENCHMARK(BM_XRayProfilingDeepCallStack)
    ->ThreadRange(1, 32)
    ->RangeMultiplier(2)
    ->Range(1, 64)
    ->UseRealTime();

BENCHMARK_MAIN();
