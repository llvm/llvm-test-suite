#include <cstring>
#include <iostream>
#include <memory>
#include <random>

#include "benchmark/benchmark.h"

#define ITERATIONS 100000
#define BUCKETS 10000

template <typename IdxT, typename DataT>
using HistFn = DataT (*)(IdxT *, DataT * __restrict, DataT * __restrict);

#define INIT_BLOCK
#define EXIT_BLOCK

#define _Args(...) __VA_ARGS__
#define _STRIP_PARENS(X) X
#define STRIP_PARENS(X) _STRIP_PARENS(_Args X)

#define DEF_HIST_LOOP_FN(name, init, loop, result)                             \
  template <typename IdxT, typename DataT>                                     \
  __attribute__((noinline)) static DataT                                       \
run_##name##_autovec(IdxT *A, DataT * __restrict B, DataT * __restrict C) {    \
    STRIP_PARENS(init);                                                        \
    STRIP_PARENS(loop);                                                        \
    result;                                                                    \
  }                                                                            \
  template <typename IdxT, typename DataT>                                     \
  __attribute__((noinline)) static DataT                                       \
run_##name##_novec(IdxT *A, DataT * __restrict B, DataT * __restrict C) {      \
    STRIP_PARENS(init);                                                        \
    _Pragma("clang loop vectorize(disable) interleave(disable)")               \
        STRIP_PARENS(loop);                                                    \
    result;                                                                    \
  }

#define DEF_HIST_LOOP(name, loop)                                              \
  DEF_HIST_LOOP_FN(name,                                                       \
               (DataT Result{};),                                              \
               loop, ({ return Result; }));

// Compute the histogram of values in A using buckets in B
DEF_HIST_LOOP(single_hist_only,
                    (for (unsigned i = 0; i < ITERATIONS; i++) {
                      B[A[i]]++;
                    } Result = B[0];));

// Compute the histogram of values in A using buckets in B and C
DEF_HIST_LOOP(multi_hist_only,
                    (for (unsigned i = 0; i < ITERATIONS; i++) {
                      B[A[i]]++;
                      C[A[i]]++;
                    } Result = C[0];));

// Compute the histogram of values in A using buckets in B, along with some
// extra arithmetic
DEF_HIST_LOOP(single_hist_with_arith,
                    (for (unsigned i = 0; i < ITERATIONS; i++) {
                      B[A[i]]++;
                      Result += DataT(A[i]) * 3 + 17;
                    }));

// Initialize array A with random numbers within the range of available buckets.
template <typename T> static void init_data(T *A) {
  std::uniform_int_distribution<T> dist(0, BUCKETS - 1);
  std::mt19937 rng(12345);
  for (unsigned i = 0; i < ITERATIONS; i++)
    A[i] = dist(rng);
}

// Benchmark auto-vectorized version.
template <typename IdxT, typename DataT>
static void __attribute__((always_inline))
bench_hist_autovec(benchmark::State &state, HistFn<IdxT, DataT> VecFn,
                   HistFn<IdxT, DataT> NoVecFn) {
  std::unique_ptr<IdxT[]> A(new IdxT[ITERATIONS]);
  std::unique_ptr<DataT[]> B(new DataT[BUCKETS]);
  std::unique_ptr<DataT[]> C(new DataT[BUCKETS]);
  init_data(&A[0]);
  std::memset(&B[0], 0, BUCKETS * sizeof(DataT));
  std::memset(&C[0], 0, BUCKETS * sizeof(DataT));

#ifdef BENCH_AND_VERIFY
  std::unique_ptr<DataT[]> BNoVec(new DataT[BUCKETS]);
  std::unique_ptr<DataT[]> CNoVec(new DataT[BUCKETS]);
  std::memset(&BNoVec[0], 0, BUCKETS * sizeof(DataT));
  std::memset(&CNoVec[0], 0, BUCKETS * sizeof(DataT));
  // Verify the vectorized and un-vectorized versions produce the same results.
  {
    DataT VecRes = VecFn(&A[0], &B[0], &C[0]);
    DataT NoVecRes = NoVecFn(&A[0], &BNoVec[0], &CNoVec[0]);
    if (VecRes != NoVecRes) {
      std::cerr << "ERROR: autovec result different to scalar result " <<
                   VecRes << " != " << NoVecRes << "\n";
      exit(1);
    }
    for (unsigned i = 0; i < BUCKETS; i++) {
      if (B[i] != BNoVec[i]) {
        std::cerr << "ERROR: autovec B array different to scalar " << B[i]
                  << " != " << BNoVec[i] << " at index " << i << "\n";
        exit(1);
      }
      if (C[i] != CNoVec[i]) {
        std::cerr << "ERROR: autovec C array different to scalar " << C[i]
                  << " != " << CNoVec[i] << " at index " << i << "\n";
        exit(1);
      }
    }
  }
#endif

  for (auto _ : state) {
    VecFn(&A[0], &B[0], &C[0]);
    benchmark::DoNotOptimize(A);
    benchmark::DoNotOptimize(B);
    benchmark::DoNotOptimize(C);
    benchmark::ClobberMemory();
  }
}

// Benchmark version with vectorization disabled.
template <typename IdxT, typename DataT>
static void __attribute__((always_inline))
bench_hist_novec(benchmark::State &state, HistFn<IdxT, DataT> NoVecFn) {
  std::unique_ptr<IdxT[]> A(new IdxT[ITERATIONS]);
  std::unique_ptr<DataT[]> B(new DataT[BUCKETS]);
  std::unique_ptr<DataT[]> C(new DataT[BUCKETS]);
  init_data(&A[0]);
  std::memset(&B[0], 0, BUCKETS * sizeof(DataT));
  std::memset(&C[0], 0, BUCKETS * sizeof(DataT));

  for (auto _ : state) {
    NoVecFn(&A[0], &B[0], &C[0]);
    benchmark::DoNotOptimize(A);
    benchmark::DoNotOptimize(B);
    benchmark::DoNotOptimize(C);
    benchmark::ClobberMemory();
  }
}

#define BENCHMARK_CASE(name, IdxT, DataT)                                      \
  void BENCHMARK_##name##_autovec_##IdxT##_##DataT##_(benchmark::State &state){\
    bench_hist_autovec<IdxT, DataT>(state, run_##name##_autovec,               \
                                    run_##name##_novec);                       \
  }                                                                            \
  BENCHMARK(BENCHMARK_##name##_autovec_##IdxT##_##DataT##_)->Unit(             \
                                                      benchmark::kNanosecond); \
                                                                               \
  void BENCHMARK_##name##_novec_##IdxT##_##DataT##_(benchmark::State &state) { \
    bench_hist_novec<IdxT, DataT>(state, run_##name##_novec);                  \
  }                                                                            \
  BENCHMARK(BENCHMARK_##name##_novec_##IdxT##_##DataT##_)->Unit(               \
                                                        benchmark::kNanosecond);


#define ADD_BENCHMARK(IdxT, DataT)                                             \
  BENCHMARK_CASE(single_hist_only, IdxT, DataT)                                \
  BENCHMARK_CASE(multi_hist_only, IdxT, DataT)                                 \
  BENCHMARK_CASE(single_hist_with_arith, IdxT, DataT)

ADD_BENCHMARK(uint8_t, uint8_t)
ADD_BENCHMARK(uint32_t, uint8_t)
ADD_BENCHMARK(uint32_t, uint16_t)
ADD_BENCHMARK(uint32_t, int32_t)
ADD_BENCHMARK(int64_t, int64_t)
