#include <algorithm>
#include <cstdint>
#include <limits>
#include <random>
#include <ranges>
#include <vector>

#if __has_include(<simd/simd.h>)
#define HAS_SIMD_HEADER 1
#include <simd/simd.h>
#else
#define HAS_SIMD_HEADER 0
#endif

#include "benchmark/benchmark.h"
#include <iostream>

namespace {

using m44 = double __attribute__((matrix_type(4, 4)));

class MatrixMult4x4Benchmark : public benchmark::Fixture {
public:
  void SetUp(const benchmark::State &) override {
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(-10.0, 10.0);

    mats.clear();
    mats_res.clear();
    for (unsigned X = 0; X < kDataSize; ++X) {
      m44 M;
      for (unsigned J = 0; J < 4; ++J)
        for (unsigned I = 0; I < 4; ++I)
          M[J][I] = distribution(generator);
      mats.push_back(M);
      mats_res.push_back(M);
    }

#ifdef HAS_SIMD_HEADER
    mats_simd_res.clear();
    mats_simd.clear();
    for (auto &m : mats) {
      simd_double4x4 s;
      s.columns[0] = {m[0][0], m[1][0], m[2][0], m[3][0]};
      s.columns[1] = {m[0][1], m[1][1], m[2][1], m[3][1]};
      s.columns[2] = {m[0][2], m[1][2], m[2][2], m[3][2]};
      s.columns[3] = {m[0][3], m[1][3], m[2][3], m[3][3]};
      mats_simd.push_back(s);
      mats_simd_res.push_back(s);
    }
#endif
  }

protected:
  static constexpr size_t kDataSize = 1024;
  std::vector<m44> mats;
  std::vector<m44> mats_res;
#ifdef HAS_SIMD_HEADER
  std::vector<simd_double4x4> mats_simd;
  std::vector<simd_double4x4> mats_simd_res;
#endif
};

BENCHMARK_F(MatrixMult4x4Benchmark, MatrixTypeAB)(benchmark::State &state) {
  while (state.KeepRunning()) {
    size_t N = mats.size();
    for (size_t i = 0u; i < N; ++i) {
      const m44 a = mats[i];
      const m44 b = mats[(i + 1) % N];
      const m44 prod = a * b;
      mats_res[i] = prod;
    }
    benchmark::ClobberMemory();
  }
}

#ifdef HAS_SIMD_HEADER
BENCHMARK_F(MatrixMult4x4Benchmark, SIMDMatrixAB)(benchmark::State &state) {
  while (state.KeepRunning()) {
    size_t N = mats.size();
    for (size_t i = 0u; i < N; ++i) {
      const simd_double4x4 a = mats_simd[i];
      const simd_double4x4 b = mats_simd[(i + 1) % N];
      const simd_double4x4 prod = matrix_multiply(a, b);
      mats_simd_res[i] = prod;
    }
    benchmark::ClobberMemory();
  }
}
#endif

BENCHMARK_F(MatrixMult4x4Benchmark, MatrixTypeAtB)(benchmark::State &state) {
  while (state.KeepRunning()) {
    size_t N = mats.size();
    for (size_t i = 0u; i < N; ++i) {
      const m44 a = mats[i];
      const m44 b = mats[(i + 1) % N];
      const m44 prod = __builtin_matrix_transpose(a) * b;
      benchmark::DoNotOptimize(prod);
    }
  }
}

#ifdef HAS_SIMD_HEADER
BENCHMARK_F(MatrixMult4x4Benchmark, SIMDMatrixAtB)(benchmark::State &state) {
  while (state.KeepRunning()) {
    size_t N = mats.size();
    for (size_t i = 0u; i < N; ++i) {
      const simd_double4x4 a = mats_simd[i];
      const simd_double4x4 b = mats_simd[(i + 1) % N];
      const simd_double4x4 prod = matrix_multiply(simd_transpose(a), b);
      benchmark::DoNotOptimize(prod);
    }
  }
}
#endif

BENCHMARK_F(MatrixMult4x4Benchmark,
            MatrixTypeAtBStoreRes)(benchmark::State &state) {
  while (state.KeepRunning()) {
    size_t N = mats.size();
    for (size_t i = 0u; i < N; ++i) {
      const m44 a = mats[i];
      const m44 b = mats[(i + 1) % N];
      const m44 prod = __builtin_matrix_transpose(a) * b;
      mats[i] = prod;
    }
    benchmark::ClobberMemory();
  }
}

#ifdef HAS_SIMD_HEADER
BENCHMARK_F(MatrixMult4x4Benchmark,
            SIMDMatrixAtBStoreRes)(benchmark::State &state) {
  while (state.KeepRunning()) {
    size_t N = mats.size();
    for (size_t i = 0u; i < N; ++i) {
      const simd_double4x4 a = mats_simd[i];
      const simd_double4x4 b = mats_simd[(i + 1) % N];
      const simd_double4x4 prod = matrix_multiply(simd_transpose(a), b);
      mats_simd[i] = prod;
    }
    benchmark::ClobberMemory();
  }
}
#endif
} // namespace

BENCHMARK_MAIN();
