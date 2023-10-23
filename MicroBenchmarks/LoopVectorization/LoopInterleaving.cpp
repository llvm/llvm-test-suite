// This program tests performance impact of Interleaving Count with varying loop
// iteration count for different types of loops, such as loops with or
// without reductions inside it, loops with different vectorization widths.
#include <iostream>
#include <memory>
#include <random>

#include "benchmark/benchmark.h"

#define ELEMENTS 2048
#define ALIGNED16 __attribute__((aligned(16)))

static std::mt19937 rng;
unsigned int g_sum = 0;

int A[ELEMENTS] ALIGNED16;
int B[ELEMENTS] ALIGNED16;
int C[ELEMENTS] ALIGNED16;

// Initialize arrays with random numbers.
static void init_data(unsigned N) {
  std::uniform_int_distribution<int> distrib(std::numeric_limits<int>::min(),
                                             std::numeric_limits<int>::max());
  for (unsigned I = 0; I < N; I++) {
    A[I] = distrib(rng);
    B[I] = distrib(rng);
    C[I] = distrib(rng);
  }
}

/* Loops without Reduction with different vectorization configurations */

static int __attribute__((noinline)) loopWithoutVecHint(int Iterations) {
  for (int J = 0; J < Iterations; J++) {
    A[J] = B[J] + C[J];
  }
  return 0;
}

static int __attribute__((noinline)) loopWithVW4IC1(int Iterations) {
#pragma clang loop vectorize_width(4) interleave(disable)
  for (int J = 0; J < Iterations; J++) {
    A[J] = B[J] + C[J];
  }
  return 0;
}

static int __attribute__((noinline)) loopWithVW4IC2(int Iterations) {
#pragma clang loop vectorize_width(4) interleave_count(2)
  for (int J = 0; J < Iterations; J++) {
    A[J] = B[J] + C[J];
  }
  return 0;
}

static int __attribute__((noinline)) loopWithVW4IC4(int Iterations) {
#pragma clang loop vectorize_width(4) interleave_count(4)
  for (int J = 0; J < Iterations; J++) {
    A[J] = B[J] + C[J];
  }
  return 0;
}

/* Loops with Reduction with different vectorization configurations */

static int __attribute__((noinline))
loopWithReductionWithoutVecHint(int Iterations) {
  unsigned sum = 0;
  for (int J = 0; J < Iterations; J++) {
    sum += A[J];
  }
  return sum;
}

static int __attribute__((noinline))
loopWithReductionWithVW4IC1(int Iterations) {
  unsigned sum = 0;
#pragma clang loop vectorize_width(4) interleave(disable)
  for (int J = 0; J < Iterations; J++) {
    sum += A[J];
  }
  return sum;
}

static int __attribute__((noinline))
loopWithReductionWithVW4IC2(int Iterations) {
  unsigned sum = 0;
#pragma clang loop vectorize_width(4) interleave_count(2)
  for (int J = 0; J < Iterations; J++) {
    sum += A[J];
  }
  return sum;
}

static int __attribute__((noinline))
loopWithReductionWithVW4IC4(int Iterations) {
  unsigned sum = 0;
#pragma clang loop vectorize_width(4) interleave_count(4)
  for (int J = 0; J < Iterations; J++) {
    sum += A[J];
  }
  return sum;
}

static int __attribute__((noinline))
loopWithReductionWithVW1IC1(int Iterations) {
  unsigned sum = 0;
#pragma clang loop vectorize_width(1) interleave_count(1)
  for (int J = 0; J < Iterations; J++) {
    sum += A[J];
  }
  return sum;
}

static int __attribute__((noinline))
loopWithReductionWithVW1IC2(int Iterations) {
  unsigned sum = 0;
#pragma clang loop vectorize_width(1) interleave_count(2)
  for (int J = 0; J < Iterations; J++) {
    sum += A[J];
  }
  return sum;
}

static int __attribute__((noinline))
loopWithReductionWithVW1IC4(int Iterations) {
  unsigned sum = 0;
#pragma clang loop vectorize_width(1) interleave_count(4)
  for (int J = 0; J < Iterations; J++) {
    sum += A[J];
  }
  return sum;
}

static void __attribute__((always_inline))
benchForLoopInterleaving(benchmark::State &state, int (*Fn)(int),
                         int Iterations) {
  std::uniform_int_distribution<int> distrib(std::numeric_limits<int>::min(),
                                             std::numeric_limits<int>::max());
  init_data(ELEMENTS);
  for (auto _ : state) {
    benchmark::DoNotOptimize(A);
    benchmark::DoNotOptimize(B);
    benchmark::DoNotOptimize(C);
    benchmark::ClobberMemory();
    g_sum += Fn(Iterations);
  }
}

// We are evaluating 2 types of loops for different vectorization configurations
// 1) Loops without reductions
// 2) Loops with reductions
// For each, we are evaluating the following vectorization configurations of
// vectorization width (VW), interleaving count (IC):
// 1) automatically selected by the compiler
// 2) VW=4, IC=1
// 3) VW=4, IC=2
// 4) VW=4, IC=4
// 5) VW=1, IC=1
// 6) VW=1, IC=2
// 7) VW=1, IC=4
// Of these, configurations 5-7 are skipped for loop type 1).
#define ADD_BENCHMARK(Itr)                                                     \
  void benchWithoutVecHintForTC##Itr(benchmark::State &state) {                \
    benchForLoopInterleaving(state, &loopWithoutVecHint, Itr);                 \
  }                                                                            \
  BENCHMARK(benchWithoutVecHintForTC##Itr);                                    \
  void benchForIC1VW4LoopTC##Itr(benchmark::State &state) {                    \
    benchForLoopInterleaving(state, &loopWithVW4IC1, Itr);                     \
  }                                                                            \
  BENCHMARK(benchForIC1VW4LoopTC##Itr);                                        \
  void benchForIC2VW4LoopTC##Itr(benchmark::State &state) {                    \
    benchForLoopInterleaving(state, &loopWithVW4IC2, Itr);                     \
  }                                                                            \
  BENCHMARK(benchForIC2VW4LoopTC##Itr);                                        \
  void benchForIC4VW4LoopTC##Itr(benchmark::State &state) {                    \
    benchForLoopInterleaving(state, &loopWithVW4IC4, Itr);                     \
  }                                                                            \
  BENCHMARK(benchForIC4VW4LoopTC##Itr);                                        \
  void benchForLoopWithReductionWithoutVecHintTC##Itr(                         \
      benchmark::State &state) {                                               \
    benchForLoopInterleaving(state, &loopWithReductionWithoutVecHint, Itr);    \
  }                                                                            \
  BENCHMARK(benchForLoopWithReductionWithoutVecHintTC##Itr);                   \
  void benchForIC1VW4LoopWithReductionTC##Itr(benchmark::State &state) {       \
    benchForLoopInterleaving(state, &loopWithReductionWithVW4IC1, Itr);        \
  }                                                                            \
  BENCHMARK(benchForIC1VW4LoopWithReductionTC##Itr);                           \
  void benchForIC2VW4LoopWithReductionTC##Itr(benchmark::State &state) {       \
    benchForLoopInterleaving(state, &loopWithReductionWithVW4IC2, Itr);        \
  }                                                                            \
  BENCHMARK(benchForIC2VW4LoopWithReductionTC##Itr);                           \
  void benchForIC4VW4LoopWithReductionTC##Itr(benchmark::State &state) {       \
    benchForLoopInterleaving(state, &loopWithReductionWithVW4IC4, Itr);        \
  }                                                                            \
  BENCHMARK(benchForIC4VW4LoopWithReductionTC##Itr);                           \
  void benchForIC1VW1LoopWithReductionTC##Itr(benchmark::State &state) {       \
    benchForLoopInterleaving(state, &loopWithReductionWithVW1IC1, Itr);        \
  }                                                                            \
  BENCHMARK(benchForIC1VW1LoopWithReductionTC##Itr);                           \
  void benchForIC2VW1LoopWithReductionTC##Itr(benchmark::State &state) {       \
    benchForLoopInterleaving(state, &loopWithReductionWithVW1IC2, Itr);        \
  }                                                                            \
  BENCHMARK(benchForIC2VW1LoopWithReductionTC##Itr);                           \
  void benchForIC4VW1LoopWithReductionTC##Itr(benchmark::State &state) {       \
    benchForLoopInterleaving(state, &loopWithReductionWithVW1IC4, Itr);        \
  }                                                                            \
  BENCHMARK(benchForIC4VW1LoopWithReductionTC##Itr);

ADD_BENCHMARK(1)
ADD_BENCHMARK(2)
ADD_BENCHMARK(3)
ADD_BENCHMARK(4)
ADD_BENCHMARK(5)
ADD_BENCHMARK(6)
ADD_BENCHMARK(7)
ADD_BENCHMARK(8)
ADD_BENCHMARK(9)
ADD_BENCHMARK(10)
ADD_BENCHMARK(11)
ADD_BENCHMARK(12)
ADD_BENCHMARK(13)
ADD_BENCHMARK(14)
ADD_BENCHMARK(15)
ADD_BENCHMARK(16)
ADD_BENCHMARK(17)
ADD_BENCHMARK(18)
ADD_BENCHMARK(19)
ADD_BENCHMARK(20)
ADD_BENCHMARK(21)
ADD_BENCHMARK(22)
ADD_BENCHMARK(23)
ADD_BENCHMARK(24)
ADD_BENCHMARK(25)
ADD_BENCHMARK(26)
ADD_BENCHMARK(27)
ADD_BENCHMARK(28)
ADD_BENCHMARK(29)
ADD_BENCHMARK(30)
ADD_BENCHMARK(31)
ADD_BENCHMARK(32)
ADD_BENCHMARK(33)
ADD_BENCHMARK(34)
ADD_BENCHMARK(35)
ADD_BENCHMARK(36)
ADD_BENCHMARK(37)
ADD_BENCHMARK(38)
ADD_BENCHMARK(39)
ADD_BENCHMARK(40)
ADD_BENCHMARK(41)
ADD_BENCHMARK(42)
ADD_BENCHMARK(43)
ADD_BENCHMARK(44)
ADD_BENCHMARK(45)
ADD_BENCHMARK(46)
ADD_BENCHMARK(47)
ADD_BENCHMARK(48)
ADD_BENCHMARK(49)
ADD_BENCHMARK(50)
ADD_BENCHMARK(51)
ADD_BENCHMARK(52)
ADD_BENCHMARK(53)
ADD_BENCHMARK(54)
ADD_BENCHMARK(55)
ADD_BENCHMARK(56)
ADD_BENCHMARK(57)
ADD_BENCHMARK(58)
ADD_BENCHMARK(59)
ADD_BENCHMARK(60)
ADD_BENCHMARK(61)
ADD_BENCHMARK(62)
ADD_BENCHMARK(63)
ADD_BENCHMARK(64)
ADD_BENCHMARK(65)
ADD_BENCHMARK(66)
ADD_BENCHMARK(67)
ADD_BENCHMARK(68)
ADD_BENCHMARK(69)
ADD_BENCHMARK(70)
ADD_BENCHMARK(71)
ADD_BENCHMARK(72)
ADD_BENCHMARK(73)
ADD_BENCHMARK(74)
ADD_BENCHMARK(75)
ADD_BENCHMARK(76)
ADD_BENCHMARK(77)
ADD_BENCHMARK(78)
ADD_BENCHMARK(79)
ADD_BENCHMARK(80)
ADD_BENCHMARK(81)
ADD_BENCHMARK(82)
ADD_BENCHMARK(83)
ADD_BENCHMARK(84)
ADD_BENCHMARK(85)
ADD_BENCHMARK(86)
ADD_BENCHMARK(87)
ADD_BENCHMARK(88)
ADD_BENCHMARK(89)
ADD_BENCHMARK(90)
ADD_BENCHMARK(91)
ADD_BENCHMARK(92)
ADD_BENCHMARK(93)
ADD_BENCHMARK(94)
ADD_BENCHMARK(95)
ADD_BENCHMARK(96)
ADD_BENCHMARK(97)
ADD_BENCHMARK(98)
ADD_BENCHMARK(99)
ADD_BENCHMARK(100)
ADD_BENCHMARK(101)
ADD_BENCHMARK(102)
ADD_BENCHMARK(103)
ADD_BENCHMARK(104)
ADD_BENCHMARK(105)
ADD_BENCHMARK(106)
ADD_BENCHMARK(107)
ADD_BENCHMARK(108)
ADD_BENCHMARK(109)
ADD_BENCHMARK(110)
ADD_BENCHMARK(111)
ADD_BENCHMARK(112)
ADD_BENCHMARK(113)
ADD_BENCHMARK(114)
ADD_BENCHMARK(115)
ADD_BENCHMARK(116)
ADD_BENCHMARK(117)
ADD_BENCHMARK(118)
ADD_BENCHMARK(119)
ADD_BENCHMARK(120)
ADD_BENCHMARK(121)
ADD_BENCHMARK(122)
ADD_BENCHMARK(123)
ADD_BENCHMARK(124)
ADD_BENCHMARK(125)
ADD_BENCHMARK(126)
ADD_BENCHMARK(127)
ADD_BENCHMARK(128)
