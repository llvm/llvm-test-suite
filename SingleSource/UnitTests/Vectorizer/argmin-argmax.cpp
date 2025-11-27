#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <memory>
#include <stdint.h>
#include <vector>

#include "common.h"

template <typename RetTy, typename Ty>
using Fn2Ty = std::function<RetTy(Ty *, Ty *, unsigned)>;
template <typename RetTy, typename Ty>
static void checkVectorFunction(Fn2Ty<RetTy, Ty> ScalarFn,
                                Fn2Ty<RetTy, Ty> VectorFn, const char *Name) {
  std::cout << "Checking " << Name << "\n";

  unsigned MaxN = 1024;
  std::unique_ptr<Ty[]> Src1(new Ty[MaxN]);
  std::unique_ptr<Ty[]> Src2(new Ty[MaxN]);

  // Test with different trip counts, including odd ones and powers of 2.
  unsigned TripCounts[] = {1, 7, 15, 16, 31, 127, 128, 999, 1000, 1023};
  for (unsigned N : TripCounts) {
    auto runTest = [&](const char *Desc) {
      auto Reference = ScalarFn(&Src1[0], &Src2[0], N);
      auto ToCheck = VectorFn(&Src1[0], &Src2[0], N);
      if (Reference != ToCheck) {
        std::cerr << "Miscompare for N=" << N << " (" << Desc << ")\n";
        exit(1);
      }
    };

    // Check with random inputs.
    init_data(Src1, N);
    init_data(Src2, N);
    runTest("random");

    // Check with sorted inputs.
    std::sort(&Src1[0], &Src1[N]);
    std::sort(&Src2[0], &Src2[N]);
    runTest("sorted");

    // Check with reverse sorted inputs.
    std::sort(&Src1[0], &Src1[N], std::greater<Ty>());
    std::sort(&Src2[0], &Src2[N], std::greater<Ty>());
    runTest("reverse sorted");

    // Check with all max values.
    for (unsigned I = 0; I != N; ++I) {
      Src1[I] = std::numeric_limits<Ty>::max();
      Src2[I] = std::numeric_limits<Ty>::max();
    }
    runTest("all max");

    // Check with all min values.
    for (unsigned I = 0; I != N; ++I) {
      Src1[I] = std::numeric_limits<Ty>::lowest();
      Src2[I] = std::numeric_limits<Ty>::lowest();
    }
    runTest("all min");

    // Check with all zeros.
    for (unsigned I = 0; I != N; ++I) {
      Src1[I] = 0;
      Src2[I] = 0;
    }
    runTest("all zero");

    // Check with alternating min/max pattern (interesting for ADD tests).
    for (unsigned I = 0; I != N; ++I) {
      Src1[I] = (I & 1) ? std::numeric_limits<Ty>::max()
                        : std::numeric_limits<Ty>::lowest();
      Src2[I] = (I & 1) ? std::numeric_limits<Ty>::lowest()
                        : std::numeric_limits<Ty>::max();
    }
    runTest("alternating");

    // Helper to test both min and max with specific target indices.
    auto testPattern = [&](Ty TargetVal, Ty FillVal,
                           const std::vector<unsigned> &Indices,
                           const char *Name) {
      for (unsigned I = 0; I != N; ++I) {
        Src1[I] = FillVal;
        Src2[I] = FillVal;
      }
      for (unsigned Idx : Indices) {
        if (Idx < N) {
          Src1[Idx] = TargetVal;
          Src2[Idx] = TargetVal;
        }
      }
      runTest(Name);
    };

    // Define test patterns with their index positions.
    struct Pattern {
      std::function<std::vector<unsigned>(unsigned)> GetIndices;
      const char *Name;
      unsigned MinN;
    };

    const Pattern Patterns[] = {
        {{[](unsigned N) { return std::vector<unsigned>{0}; }},
         "first element",
         1},
        {{[](unsigned N) { return std::vector<unsigned>{N - 1}; }},
         "last element",
         1},
        {{[](unsigned N) { return std::vector<unsigned>{0, N / 2, N - 1}; }},
         "duplicate",
         3},
        {{[](unsigned N) {
           // Mix of even and odd indices at different positions
           std::vector<unsigned> Indices = {0, 1};
           if (N >= 6) {
             unsigned MidEven = (N / 2) & ~1u;
             unsigned MidOdd = (N / 2) | 1;
             if (MidEven < N && MidEven != 0)
               Indices.push_back(MidEven);
             if (MidOdd < N && MidOdd != 1)
               Indices.push_back(MidOdd);
           }
           return Indices;
         }},
         "duplicate mixed even/odd indices",
         2},
        {{[](unsigned N) {
           std::vector<unsigned> Indices = {1};
           unsigned MidOdd = (N / 2) | 1;
           if (MidOdd < N)
             Indices.push_back(MidOdd);
           unsigned LastOdd = (N - 1) | 1;
           if (LastOdd < N && LastOdd != 1 && LastOdd != MidOdd)
             Indices.push_back(LastOdd);
           return Indices;
         }},
         "duplicate odd indices",
         4},
        {{[](unsigned N) {
           // Start at index 2 (even), avoiding 0 and 1
           std::vector<unsigned> Indices = {2};
           if (N >= 8) {
             unsigned MidEven = (N / 2) & ~1u;
             if (MidEven > 2 && MidEven < N)
               Indices.push_back(MidEven);
           }
           if (N >= 4) {
             unsigned LastEven = (N - 1) & ~1u;
             if (LastEven > 2 && LastEven < N)
               Indices.push_back(LastEven);
           }
           return Indices;
         }},
         "duplicate even indices skip 0",
         3},
        {{[](unsigned N) {
           // Start at index 3 (odd), avoiding 0 and 1
           std::vector<unsigned> Indices = {3};
           if (N >= 8) {
             unsigned MidOdd = (N / 2) | 1;
             if (MidOdd > 3 && MidOdd < N)
               Indices.push_back(MidOdd);
           }
           if (N >= 5) {
             unsigned LastOdd = (N - 1) | 1;
             if (LastOdd > 3 && LastOdd < N)
               Indices.push_back(LastOdd);
           }
           return Indices;
         }},
         "duplicate odd indices skip 1",
         4},
        {{[](unsigned N) {
           // Only indices in second half of array
           std::vector<unsigned> Indices;
           unsigned Start = N / 2;
           if (Start < 2)
             Start = 2;
           if (Start < N)
             Indices.push_back(Start);
           unsigned Mid = N / 2 + N / 4;
           if (Mid > Start && Mid < N)
             Indices.push_back(Mid);
           if (N - 1 > Start)
             Indices.push_back(N - 1);
           return Indices;
         }},
         "duplicate second half only",
         4},
    };

    // Run all patterns for both min and max.
    for (const auto &P : Patterns) {
      if (N >= P.MinN) {
        auto Indices = P.GetIndices(N);
        testPattern(std::numeric_limits<Ty>::lowest(),
                    std::numeric_limits<Ty>::max(), Indices,
                    (std::string(P.Name) + " min").c_str());
        testPattern(std::numeric_limits<Ty>::max(),
                    std::numeric_limits<Ty>::lowest(), Indices,
                    (std::string(P.Name) + " max").c_str());
        testPattern(-10,
                    20, Indices,
                    (std::string(P.Name) + " mixed1").c_str());
        testPattern(30,
                    -20, Indices,
                    (std::string(P.Name) + " mixed2").c_str());
      }
    }
  }
}

#define NAME(Op, MinTy, MinIdxTy, Suffix)                                      \
  "arg" Op "_" #MinTy "_" #MinIdxTy Suffix

// Generic test: Loop body is passed as macro parameter
#define TEST(Op, MinTy, MinIdxTy, Init, Loop, Suffix)                          \
  {                                                                            \
    DEFINE_SCALAR_AND_VECTOR_FN2(Init, Loop)                                   \
    checkVectorFunction<MinIdxTy, MinTy>(ScalarFn, VectorFn,                   \
                                         NAME(Op, MinTy, MinIdxTy, Suffix));   \
  }

// Test with explicit VF and interleave count
#define TEST_VF_IC(Op, MinTy, MinIdxTy, Init, Loop, VF, IC, Suffix)            \
  {                                                                            \
    DEFINE_SCALAR_AND_VECTOR_FN2_VF_INTERLEAVE(Init, Loop, VF, IC)             \
    checkVectorFunction<MinIdxTy, MinTy>(ScalarFn, VectorFn,                   \
                                         NAME(Op, MinTy, MinIdxTy, Suffix));   \
  }

// Predicate-parameterized tests
#define T_BASIC_P(Op, M, I, Start, Inc, InitVal, InitIdx, Pred, Suf)           \
  TEST(                                                                        \
      Op, M, I, M Min = InitVal; I MinIdx = InitIdx;                           \
      ,                                                                        \
      for (unsigned i = Start; i < TC; i += Inc) {                             \
        if (A[i] Pred Min) {                                                   \
          Min = A[i];                                                          \
          MinIdx = i;                                                          \
        }                                                                      \
      } return MinIdx;                                                         \
      , Suf)

#define T_ADD_P(Op, M, I, Start, Inc, InitVal, InitIdx, Pred, Suf)             \
  TEST(                                                                        \
      Op, M, I, M Min = InitVal; I MinIdx = InitIdx;                           \
      ,                                                                        \
      for (unsigned i = Start; i < TC; i += Inc) {                             \
        M D = A[i] + B[i];                                                     \
        if (D Pred Min) {                                                      \
          Min = D;                                                             \
          MinIdx = i;                                                          \
        }                                                                      \
      } return MinIdx;                                                         \
      , Suf)

#define T_SEP_P(Op, M, I, InitVal, Pred, Suf)                                  \
  TEST(                                                                        \
      Op, M, I, M Min = InitVal; I MinIdx = 0;                                 \
      ,                                                                        \
      for (unsigned i = 0; i < TC; i++) {                                      \
        if (B[i] Pred Min) {                                                   \
          MinIdx = i;                                                          \
        }                                                                      \
                                                                               \
        if (A[i] Pred Min) {                                                   \
          Min = A[i];                                                          \
        }                                                                      \
      } return MinIdx;                                                         \
      , Suf)

#define T_DIFF_P(Op, M, I, InitVal, Pred, Suf)                                 \
  TEST(                                                                        \
      Op, M, I, M Min = InitVal; I MinIdx = 0;                                 \
      ,                                                                        \
      for (unsigned i = 0; i < TC; i++) {                                      \
        if (B[i] Pred Min) {                                                   \
          MinIdx = i;                                                          \
        }                                                                      \
                                                                               \
        if (B[i] Pred Min) {                                                   \
          Min = A[i];                                                          \
        }                                                                      \
      } return MinIdx;                                                         \
      , Suf)

// Two-predicate tests (for mismatch patterns)
#define T_2PRED(Op, M, I, InitVal, Pred1, Pred2, Suf)                          \
  TEST(                                                                        \
      Op, M, I, M Min = InitVal; I MinIdx = 0;                                 \
      ,                                                                        \
      for (unsigned i = 0; i < TC; i++) {                                      \
        if (A[i] Pred1 Min) {                                                  \
          MinIdx = i;                                                          \
        }                                                                      \
                                                                               \
        if (A[i] Pred2 Min) {                                                  \
          Min = A[i];                                                          \
        }                                                                      \
      } return MinIdx;                                                         \
      , Suf)

#define T_2PRED_REV(Op, M, I, InitVal, Pred1, Pred2, Suf)                      \
  TEST(                                                                        \
      Op, M, I, M Min = InitVal; I MinIdx = 0;                                 \
      ,                                                                        \
      for (unsigned i = 0; i < TC; i++) {                                      \
        if (A[i] Pred1 Min) {                                                  \
          Min = A[i];                                                          \
        }                                                                      \
                                                                               \
        if (A[i] Pred2 Min) {                                                  \
          MinIdx = i;                                                          \
        }                                                                      \
      } return MinIdx;                                                         \
      , Suf)

#define T_TRUNC(Op, M, I, InitVal)                                             \
  TEST(                                                                        \
      Op, M, I, M Min = InitVal; I MinIdx = 0;                                 \
      ,                                                                        \
      for (uint64_t i = 0; i < TC; i++) {                                      \
        if (A[i] <= Min) {                                                     \
          Min = A[i];                                                          \
          MinIdx = i;                                                          \
        }                                                                      \
      } return MinIdx;                                                         \
      , "_with_trunc")

#define T_DEC(Op, M, I, InitVal)                                               \
  TEST(                                                                        \
      Op, M, I, M Min = InitVal; I MinIdx = 0;                                 \
      ,                                                                        \
      for (unsigned i = TC; i-- > 0;) {                                        \
        if (A[i] <= Min) {                                                     \
          Min = A[i];                                                          \
          MinIdx = i;                                                          \
        }                                                                      \
      } return MinIdx;                                                         \
      , "_induction_decrement")

// Variants with explicit VF and interleave count.
#define T_BASIC_VF_IC(Op, M, I, Start, Inc, InitVal, InitIdx, VF, IC, Suf)     \
  TEST_VF_IC(                                                                  \
      Op, M, I, M Min = InitVal; I MinIdx = InitIdx;                           \
      ,                                                                        \
      for (unsigned i = Start; i < TC; i += Inc) {                             \
        if (A[i] <= Min) {                                                     \
          Min = A[i];                                                          \
          MinIdx = i;                                                          \
        }                                                                      \
      } return MinIdx;                                                         \
      , VF, IC, Suf)

#define RUN_ALL_TESTS_FOR_TYPE(M, I)                                           \
  T_BASIC_P("min", M, I, 0, 1, std::numeric_limits<M>::max(), 0, <=,           \
            "_start_0")                                                        \
  T_ADD_P("min", M, I, 0, 2, std::numeric_limits<M>::max(), 0, <=,             \
          "_start_0_inc_2")                                                    \
  T_BASIC_P("min", M, I, 0, 1, std::numeric_limits<M>::max(), 2, <=,           \
            "_start_2")                                                        \
  T_BASIC_P("min", M, I, 0, 1, std::numeric_limits<M>::max(),                  \
            std::numeric_limits<I>::max(), <=, "_start_0_min_idx_neg1")        \
  T_BASIC_P("min", M, I, 3, 1, std::numeric_limits<M>::max(), 3, <=,           \
            "_start_3_min_idx_3")                                              \
  T_ADD_P("min", M, I, 3, 1, std::numeric_limits<M>::max(), 2, <=,             \
          "_start_3_min_idx_2")                                                \
  T_BASIC_P("min", M, I, 3, 1, std::numeric_limits<M>::max(), 4, <=,           \
            "_start_3_min_idx_4")                                              \
  T_SEP_P("min", M, I, std::numeric_limits<M>::max(), <=, "_separate_selects") \
  T_DIFF_P("min", M, I, std::numeric_limits<M>::max(), <=, "_different_selects")

// Run tests with different predicates for additional coverage
#define RUN_PRED_TESTS_FOR_TYPE(M, I)                                          \
  T_BASIC_P("min", M, I, 0, 1, std::numeric_limits<M>::max(), 0, <,            \
            "_start_0_lt")                                                     \
  T_BASIC_P("max", M, I, 0, 1, std::numeric_limits<M>::lowest(), 0, >=,        \
            "_start_0_ge")                                                     \
  T_BASIC_P("max", M, I, 0, 1, std::numeric_limits<M>::lowest(), 0, >,         \
            "_start_0_gt")                                                     \
  T_SEP_P("min", M, I, std::numeric_limits<M>::max(), <,                       \
          "_separate_selects_lt")                                              \
  T_SEP_P("max", M, I, std::numeric_limits<M>::lowest(), >,                    \
          "_separate_selects_gt")

// Run tests with explicit VF and interleave count
#define RUN_VF_IC_TESTS_FOR_TYPE(M, I)                                         \
  T_BASIC_VF_IC("min", M, I, 0, 1, std::numeric_limits<M>::max(), 0, 4, 1,     \
                "_start_0_vf4_ic1")                                            \
  T_BASIC_VF_IC("min", M, I, 0, 1, std::numeric_limits<M>::max(), 0, 2, 2,     \
                "_start_0_vf2_ic2")

#define RUN_TRUNC_TESTS_FOR_TYPE(M, I)                                         \
  T_TRUNC("min", M, I, std::numeric_limits<M>::max())                          \
  T_DEC("min", M, I, std::numeric_limits<M>::max())

int main(void) {
  rng = std::mt19937(15);

  // Run tests for unsigned 8-bit types
  RUN_ALL_TESTS_FOR_TYPE(uint8_t, uint8_t)
  RUN_PRED_TESTS_FOR_TYPE(uint8_t, uint8_t)

  // Run tests for unsigned 16-bit types
  RUN_ALL_TESTS_FOR_TYPE(uint16_t, uint16_t)
  RUN_PRED_TESTS_FOR_TYPE(uint16_t, uint16_t)

  // Run tests for unsigned 32-bit types
  RUN_ALL_TESTS_FOR_TYPE(uint32_t, uint32_t)
  RUN_PRED_TESTS_FOR_TYPE(uint32_t, uint32_t)
  RUN_VF_IC_TESTS_FOR_TYPE(uint32_t, uint32_t)

  // Run tests for unsigned 64-bit types
  RUN_ALL_TESTS_FOR_TYPE(uint64_t, uint64_t)
  RUN_PRED_TESTS_FOR_TYPE(uint64_t, uint64_t)
  RUN_VF_IC_TESTS_FOR_TYPE(uint64_t, uint64_t)

  // Run tests for signed 8-bit types
  RUN_ALL_TESTS_FOR_TYPE(int8_t, int8_t)
  RUN_PRED_TESTS_FOR_TYPE(int8_t, int8_t)

  // Run tests for signed 16-bit types
  RUN_ALL_TESTS_FOR_TYPE(int16_t, int16_t)
  RUN_PRED_TESTS_FOR_TYPE(int16_t, int16_t)

  // Run tests for signed 32-bit types
  RUN_ALL_TESTS_FOR_TYPE(int32_t, int32_t)
  RUN_PRED_TESTS_FOR_TYPE(int32_t, int32_t)
  RUN_VF_IC_TESTS_FOR_TYPE(int32_t, int32_t)

  // Run tests for signed 64-bit types
  RUN_ALL_TESTS_FOR_TYPE(int64_t, int64_t)
  RUN_PRED_TESTS_FOR_TYPE(int64_t, int64_t)

  // Run tests with mixed signedness (unsigned min, signed idx)
  RUN_ALL_TESTS_FOR_TYPE(uint8_t, int8_t)
  RUN_PRED_TESTS_FOR_TYPE(uint8_t, int8_t)

  RUN_ALL_TESTS_FOR_TYPE(uint16_t, int16_t)
  RUN_PRED_TESTS_FOR_TYPE(uint16_t, int16_t)

  RUN_ALL_TESTS_FOR_TYPE(uint32_t, int32_t)
  RUN_PRED_TESTS_FOR_TYPE(uint32_t, int32_t)

  RUN_ALL_TESTS_FOR_TYPE(uint64_t, int64_t)
  RUN_PRED_TESTS_FOR_TYPE(uint64_t, int64_t)

  // Run tests with mixed signedness (signed min, unsigned idx)
  RUN_ALL_TESTS_FOR_TYPE(int8_t, uint8_t)
  RUN_PRED_TESTS_FOR_TYPE(int8_t, uint8_t)

  RUN_ALL_TESTS_FOR_TYPE(int16_t, uint16_t)
  RUN_PRED_TESTS_FOR_TYPE(int16_t, uint16_t)

  RUN_ALL_TESTS_FOR_TYPE(int32_t, uint32_t)
  RUN_PRED_TESTS_FOR_TYPE(int32_t, uint32_t)

  RUN_ALL_TESTS_FOR_TYPE(int64_t, uint64_t)
  RUN_PRED_TESTS_FOR_TYPE(int64_t, uint64_t)

  // Run truncation tests with original type combination
  RUN_TRUNC_TESTS_FOR_TYPE(uint64_t, uint32_t)

  // Run mismatch tests only for uint64_t (matching original scope)
  T_2PRED("mixed", uint64_t, uint64_t, std::numeric_limits<uint64_t>::max(), >=,
          <=, "_predicate_mismatch_0")
  T_2PRED_REV("mixed", uint64_t, uint64_t, std::numeric_limits<uint64_t>::max(),
              <=, >=, "_predicate_mismatch_1")

  return 0;
}
