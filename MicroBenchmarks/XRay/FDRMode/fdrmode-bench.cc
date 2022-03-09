//===- fdrmode-bench.cc - XRay Instrumentation Benchmarks -----------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// Define benchmarks for measuring the cost of XRay instrumentation when using
// flight data recorder mode.
//
//===----------------------------------------------------------------------===//

#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include "benchmark/benchmark.h"
#include "xray/xray_interface.h"
#include "xray/xray_log_interface.h"

namespace {

// This needs to be a global value so that the compiler doesn't end up writing
// to data on the stack. We also mark it volatile to preserve all the loads and
// stores performed on this variable.
volatile int val = 0;

}  // namespace

// We define a multi-threaded benchmark which measures the overall costs
// introduced by the XRay handlers upstream. This will exercise a tight loop
// calling a single function that practically does nothing.
[[clang::xray_always_instrument]] __attribute__((noinline))
__attribute__((weak)) int
EmptyFunction() {
  return 0;
}

volatile bool log_initialized = false;

// Force installation of the FDR logging implementation upstream, with the
// caveat that we're writing the log out to /dev/null.
[[clang::xray_never_instrument]] void SetUpXRayFDRMultiThreaded(
    benchmark::State& state) {
  if (!log_initialized) {
    if (__xray_log_select_mode("xray-fdr") !=
        XRayLogRegisterStatus::XRAY_REGISTRATION_OK)
      std::abort();

    std::string flags = "no_file_flush=true:buffer_size=";
    flags += std::to_string(getpagesize()) + ":buffer_max=";
    flags += std::to_string(1 << 16);
    __xray_log_init_mode("xray-fdr", flags.c_str());
    __xray_remove_customevent_handler();
    __xray_patch();
    log_initialized = true;
  }
}

[[clang::xray_never_instrument]] void TearDownXRayFDRMultiThreaded(
    benchmark::State& state) {
  if (log_initialized) {
    log_initialized = false;
    __xray_log_finalize();
    __xray_log_flushLog();
    __xray_unpatch();
  }
}

[[clang::xray_never_instrument]] static void BM_XRayFDRMultiThreaded(
    benchmark::State& state) {
  if (state.thread_index() == 0) {
    SetUpXRayFDRMultiThreaded(state);
  }
  for (auto _ : state) {
    val = EmptyFunction();
    benchmark::DoNotOptimize(val);
  }
  if (state.thread_index() == 0) {
    TearDownXRayFDRMultiThreaded(state);
  }
}

BENCHMARK(BM_XRayFDRMultiThreaded)->ThreadRange(1, 32);  // Number of threads

BENCHMARK_MAIN();
