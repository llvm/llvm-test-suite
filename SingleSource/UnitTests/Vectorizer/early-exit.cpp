#include <algorithm>
#include <functional>
#include <iostream>

/// N is divisible by common VFs. Used to test vector code path without the
/// scalar epilogue.
#define N 512

/// N_ODD is not divisible by common VFs (4, 8, 16) to test scalar epilogue.
#define N_ODD 511

/// N_SMALL is a small trip count divisible by common VFs
#define N_SMALL 64

template <typename Ty>
using TestFnTy = std::function<unsigned(std::function<void(Ty *)>)>;

// Helper to call \p f with \p args and acts as optimization barrier for \p f.
template <typename F, typename... Args>
__attribute__((optnone)) static auto callThroughOptnone(F &&f, Args &&...args) {
  return f(std::forward<Args>(args)...);
}

template <typename Ty>
static void
checkVectorFunction(TestFnTy<Ty> ScalarFn, TestFnTy<Ty> VectorFn,
                    TestFnTy<Ty> ForcedVectorFn, TestFnTy<Ty> InterleavedFn,
                    TestFnTy<Ty> InterleavedOnlyFn, const char *Name) {
  std::cout << "Checking " << Name << "\n";

  std::array Tests = {std::make_pair(VectorFn, "autovec"),
                      std::make_pair(ForcedVectorFn, "vector-forced"),
                      std::make_pair(InterleavedFn, "interleave-forced"),
                      std::make_pair(InterleavedOnlyFn, "interleave-only")};

  // Check finding the target element at all indices between 0 and N.
  for (unsigned IdxToFind = 0; IdxToFind < N; ++IdxToFind) {
    // Lambda to initialize all array elements to one, except the one to look
    // for to zero.
    auto Init1 = [IdxToFind](Ty *Arr) {
      std::fill_n(Arr, N, 1);
      if (IdxToFind < N)
        Arr[IdxToFind] = 0;
    };

    // Lambda to initialize all array elements to one, except the one to look
    // for and the IdxToFind + 3 to zero.
    auto Init2 = [IdxToFind](Ty *Arr) {
      std::fill_n(Arr, N, 1);
      if (IdxToFind < N)
        Arr[IdxToFind] = 0;
      if (IdxToFind + 3 < N)
        Arr[IdxToFind + 3] = 0;
    };

    auto Reference1 = ScalarFn(Init1);
    auto Reference2 = ScalarFn(Init2);
    // Run vector functions and check against the scalar result.
    for (const auto &[Fn, Name] : Tests) {
      auto ToCheck1 = callThroughOptnone(Fn, Init1);
      if (Reference1 != ToCheck1) {
        std::cerr << "Miscompare for " << Name << ": " << Reference1
                  << " != " << ToCheck1 << "\n";
        exit(1);
      }
      auto ToCheck2 = callThroughOptnone(Fn, Init2);
      if (Reference2 != ToCheck2) {
        std::cerr << "Miscompare for " << Name << ": " << Reference2
                  << " != " << ToCheck2 << "\n";
        exit(1);
      }
    }
  }
}

// Test function type for three arrays
template <typename Ty>
using TestFnTy3 =
    std::function<unsigned(std::function<void(Ty *, Ty *, Ty *)>)>;

// Unified check function for multiple early exits
template <typename Ty, unsigned NumExits, unsigned TripCount, unsigned Stride1,
          unsigned Stride2, unsigned Stride3>
static void
checkVectorFunctionMulti(TestFnTy3<Ty> ScalarFn, TestFnTy3<Ty> VectorFn,
                         TestFnTy3<Ty> ForcedVectorFn,
                         TestFnTy3<Ty> InterleavedFn,
                         TestFnTy3<Ty> InterleavedOnlyFn, const char *Name) {
  static_assert(NumExits == 2 || NumExits == 3, "NumExits must be 2 or 3");
  std::cout << "Checking " << Name << "\n";

  std::array Tests = {std::make_pair(VectorFn, "autovec"),
                      std::make_pair(ForcedVectorFn, "vector-forced"),
                      std::make_pair(InterleavedFn, "interleave-forced"),
                      std::make_pair(InterleavedOnlyFn, "interleave-only")};

  // Test all combinations of exit positions
  // Use stride to reduce test count while still covering important cases
  for (unsigned Exit1Idx = 0; Exit1Idx <= TripCount; Exit1Idx += Stride1) {
    for (unsigned Exit2Idx = 0; Exit2Idx <= TripCount; Exit2Idx += Stride2) {
      for (unsigned Exit3Idx = 0; Exit3Idx <= TripCount; Exit3Idx += Stride3) {
        auto Init = [Exit1Idx, Exit2Idx, Exit3Idx](Ty *A, Ty *B, Ty *C) {
          // Fill arrays with different values
          for (unsigned I = 0; I < TripCount; I++) {
            A[I] = I + 1;
            B[I] = I + TripCount;
            C[I] = I + 2 * TripCount;
          }
          // Set up first exit condition: A[Exit1Idx] == 0
          if (Exit1Idx < TripCount)
            A[Exit1Idx] = 0;
          // Set up second exit condition: A[Exit2Idx] == B[Exit2Idx]
          if (Exit2Idx < TripCount)
            B[Exit2Idx] = A[Exit2Idx];
          // Set up third exit condition: B[Exit3Idx] == C[Exit3Idx]
          if (Exit3Idx < TripCount)
            C[Exit3Idx] = B[Exit3Idx];
        };

        auto Reference = ScalarFn(Init);
        for (const auto &[Fn, FnName] : Tests) {
          auto ToCheck = callThroughOptnone(Fn, Init);
          if (Reference != ToCheck) {
            if constexpr (NumExits == 2) {
              std::cerr << "Miscompare for " << FnName
                        << " at Exit1Idx=" << Exit1Idx
                        << ", Exit2Idx=" << Exit2Idx << ": " << Reference
                        << " != " << ToCheck << "\n";
            } else {
              std::cerr << "Miscompare for " << FnName
                        << " at Exit1Idx=" << Exit1Idx
                        << ", Exit2Idx=" << Exit2Idx
                        << ", Exit3Idx=" << Exit3Idx << ": " << Reference
                        << " != " << ToCheck << "\n";
            }
            exit(1);
          }
        }
      }
    }
  }

  // Explicit test for regular exit (no early exit taken)
  // All ExitIdx = TripCount means no early exit condition is triggered
  auto InitNoExit = [](Ty *A, Ty *B, Ty *C) {
    for (unsigned I = 0; I < TripCount; I++) {
      A[I] = I + 1;
      B[I] = I + TripCount;
      C[I] = I + 2 * TripCount;
    }
  };
  auto Reference = callThroughOptnone(ScalarFn, InitNoExit);
  for (const auto &[Fn, FnName] : Tests) {
    auto ToCheck = callThroughOptnone(Fn, InitNoExit);
    if (Reference != ToCheck) {
      std::cerr << "Miscompare for " << FnName
                << " at regular exit (no early exit taken): " << Reference
                << " != " << ToCheck << "\n";
      exit(1);
    }
  }
}

/// Define 3 test functions
/// * one with vectorization and interleaving disabled,
/// * one with auto-vectorization w/o any pragmas
/// * one where VF is picked automatically and interleaving is forced.
#define DEFINE_SCALAR_AND_VECTOR_EARLY_EXIT(Init, Src, Loop)                   \
  auto ScalarFn = [](std::function<void(int *)> II) -> unsigned {              \
    Init;                                                                      \
    II(Src);                                                                   \
    _Pragma("clang loop vectorize(disable) interleave_count(1)") Loop          \
  };                                                                           \
  auto VectorFn = [](std::function<void(int *)> II) -> unsigned {              \
    Init;                                                                      \
    II(Src);                                                                   \
    _Pragma("clang loop vectorize(enable)") Loop                               \
  };                                                                           \
  auto ForcedVectorFn = [](std::function<void(int *)> II) -> unsigned {        \
    Init;                                                                      \
    II(Src);                                                                   \
    _Pragma("clang loop vectorize_width(8) interleave_count(1)") Loop          \
  };                                                                           \
  auto InterleavedFn = [](std::function<void(int *)> II) -> unsigned {         \
    Init;                                                                      \
    II(Src);                                                                   \
    _Pragma("clang loop vectorize(enable) interleave_count(4)") Loop           \
  };                                                                           \
  auto InterleavedOnlyFn = [](std::function<void(int *)> II) -> unsigned {     \
    Init;                                                                      \
    II(Src);                                                                   \
    _Pragma("clang loop vectorize_width(1) interleave_count(4)") Loop          \
  };

/// Define test functions for two early exits (uses 3 arrays, third is unused).
#define DEFINE_SCALAR_AND_VECTOR_EARLY_EXIT_2(Init, Src1, Src2, Src3, Loop)    \
  auto ScalarFn =                                                              \
      [](std::function<void(int *, int *, int *)> II) -> unsigned {            \
    Init II(Src1, Src2, Src3);                                                 \
    _Pragma("clang loop vectorize(disable) interleave_count(1)") Loop          \
  };                                                                           \
  auto VectorFn =                                                              \
      [](std::function<void(int *, int *, int *)> II) -> unsigned {            \
    Init II(Src1, Src2, Src3);                                                 \
    _Pragma("clang loop vectorize(enable)") Loop                               \
  };                                                                           \
  auto ForcedVectorFn =                                                        \
      [](std::function<void(int *, int *, int *)> II) -> unsigned {            \
    Init II(Src1, Src2, Src3);                                                 \
    _Pragma("clang loop vectorize_width(8) interleave_count(1)") Loop          \
  };                                                                           \
  auto InterleavedFn =                                                         \
      [](std::function<void(int *, int *, int *)> II) -> unsigned {            \
    Init II(Src1, Src2, Src3);                                                 \
    _Pragma("clang loop vectorize(enable) interleave_count(4)") Loop           \
  };                                                                           \
  auto InterleavedOnlyFn =                                                     \
      [](std::function<void(int *, int *, int *)> II) -> unsigned {            \
    Init II(Src1, Src2, Src3);                                                 \
    _Pragma("clang loop vectorize_width(1) interleave_count(4)") Loop          \
  };

/// Define test functions for three arrays (for three early exits)
#define DEFINE_SCALAR_AND_VECTOR_EARLY_EXIT_3(Init, Src1, Src2, Src3, Loop)    \
  auto ScalarFn =                                                              \
      [](std::function<void(int *, int *, int *)> II) -> unsigned {            \
    Init II(Src1, Src2, Src3);                                                 \
    _Pragma("clang loop vectorize(disable) interleave_count(1)") Loop          \
  };                                                                           \
  auto VectorFn =                                                              \
      [](std::function<void(int *, int *, int *)> II) -> unsigned {            \
    Init II(Src1, Src2, Src3);                                                 \
    _Pragma("clang loop vectorize(enable)") Loop                               \
  };                                                                           \
  auto ForcedVectorFn =                                                        \
      [](std::function<void(int *, int *, int *)> II) -> unsigned {            \
    Init II(Src1, Src2, Src3);                                                 \
    _Pragma("clang loop vectorize_width(8) interleave_count(1)") Loop          \
  };                                                                           \
  auto InterleavedFn =                                                         \
      [](std::function<void(int *, int *, int *)> II) -> unsigned {            \
    Init II(Src1, Src2, Src3);                                                 \
    _Pragma("clang loop vectorize(enable) interleave_count(4)") Loop           \
  };                                                                           \
  auto InterleavedOnlyFn =                                                     \
      [](std::function<void(int *, int *, int *)> II) -> unsigned {            \
    Init II(Src1, Src2, Src3);                                                 \
    _Pragma("clang loop vectorize_width(1) interleave_count(4)") Loop          \
  };

int main(void) {
  {
    DEFINE_SCALAR_AND_VECTOR_EARLY_EXIT(
        int A[N];, A, for (unsigned I = 0; I < N; I++) {
          if (A[I] == 0)
            return I;
        } return -1;);
    checkVectorFunction<int>(ScalarFn, VectorFn, ForcedVectorFn, InterleavedFn,
                             InterleavedOnlyFn, "early_exit_find_step_1");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_EARLY_EXIT(
        int A[N]; unsigned J = 2;, A, for (unsigned I = 0; I < N; I++) {
          if (A[I] == 0)
            return J;
          J += 3;
        } return -1;);
    checkVectorFunction<int>(ScalarFn, VectorFn, ForcedVectorFn, InterleavedFn,
                             InterleavedOnlyFn, "early_exit_find_step_3");
  }

  // Test: Two early exits to the same exit block.
  // First exit: A[I] == 0
  // Second exit: A[I] == B[I]
  // This tests that exits are checked in the correct program order.
  {
    DEFINE_SCALAR_AND_VECTOR_EARLY_EXIT_2(
        int A[N]; int B[N]; int C[N];
        , A, B, C, for (unsigned I = 0; I < N; I++) {
          if (A[I] == 0)
            return I;
          if (A[I] == B[I])
            return I + 1000;
        } return -1;);
    checkVectorFunctionMulti<int, 2, N, 3, 3, N + 1>(
        ScalarFn, VectorFn, ForcedVectorFn, InterleavedFn, InterleavedOnlyFn,
        "two_early_exits_same_block");
  }

  // Test: Two early exits with different return values.
  // First exit: A[I] == 0 -> return I
  // Second exit: A[I] == B[I] -> return I * 2
  // Latch exit: return -1
  {
    DEFINE_SCALAR_AND_VECTOR_EARLY_EXIT_2(
        int A[N]; int B[N]; int C[N];
        , A, B, C, for (unsigned I = 0; I < N; I++) {
          if (A[I] == 0)
            return I;
          if (A[I] == B[I])
            return I * 2;
        } return -1;);
    checkVectorFunctionMulti<int, 2, N, 3, 3, N + 1>(
        ScalarFn, VectorFn, ForcedVectorFn, InterleavedFn, InterleavedOnlyFn,
        "two_early_exits_different_values");
  }

  // Test: Two early exits with different comparison types.
  // First exit: A[I] == 0
  // Second exit: A[I] == B[I]
  // Both use equality checks that checkVectorFunctionMulti can set up.
  {
    DEFINE_SCALAR_AND_VECTOR_EARLY_EXIT_2(
        int A[N]; int B[N]; int C[N];
        , A, B, C, for (unsigned I = 0; I < N; I++) {
          if (A[I] == 0)
            return I + 500;
          if (A[I] == B[I])
            return I;
        } return -1;);
    checkVectorFunctionMulti<int, 2, N, 3, 3, N + 1>(
        ScalarFn, VectorFn, ForcedVectorFn, InterleavedFn, InterleavedOnlyFn,
        "two_early_exits_swapped_returns");
  }

  // Test: Three early exits to the same exit block.
  // First exit: A[I] == 0
  // Second exit: A[I] == B[I]
  // Third exit: B[I] == C[I]
  {
    DEFINE_SCALAR_AND_VECTOR_EARLY_EXIT_3(
        int A[N]; int B[N]; int C[N];
        , A, B, C, for (unsigned I = 0; I < N; I++) {
          if (A[I] == 0)
            return I;
          if (A[I] == B[I])
            return I + 1000;
          if (B[I] == C[I])
            return I + 2000;
        } return -1;);
    checkVectorFunctionMulti<int, 3, N, 17, 17, 17>(
        ScalarFn, VectorFn, ForcedVectorFn, InterleavedFn, InterleavedOnlyFn,
        "three_early_exits_same_block");
  }

  // Test: Three early exits with different return expressions.
  {
    DEFINE_SCALAR_AND_VECTOR_EARLY_EXIT_3(
        int A[N]; int B[N]; int C[N];
        , A, B, C, for (unsigned I = 0; I < N; I++) {
          if (A[I] == 0)
            return I;
          if (A[I] == B[I])
            return I * 2;
          if (B[I] == C[I])
            return I * 3;
        } return -1;);
    checkVectorFunctionMulti<int, 3, N, 17, 17, 17>(
        ScalarFn, VectorFn, ForcedVectorFn, InterleavedFn, InterleavedOnlyFn,
        "three_early_exits_different_values");
  }

  // Test: Two early exits with odd trip count (tests scalar epilogue).
  {
    DEFINE_SCALAR_AND_VECTOR_EARLY_EXIT_2(
        int A[N_ODD]; int B[N_ODD]; int C[N_ODD];
        , A, B, C, for (unsigned I = 0; I < N_ODD; I++) {
          if (A[I] == 0)
            return I;
          if (A[I] == B[I])
            return I + 1000;
        } return -1;);
    checkVectorFunctionMulti<int, 2, N_ODD, 3, 3, N_ODD + 1>(
        ScalarFn, VectorFn, ForcedVectorFn, InterleavedFn, InterleavedOnlyFn,
        "two_early_exits_odd_trip_count");
  }

  // Test: Two early exits with odd trip count and different return values.
  {
    DEFINE_SCALAR_AND_VECTOR_EARLY_EXIT_2(
        int A[N_ODD]; int B[N_ODD]; int C[N_ODD];
        , A, B, C, for (unsigned I = 0; I < N_ODD; I++) {
          if (A[I] == 0)
            return I;
          if (A[I] == B[I])
            return I * 2;
        } return -1;);
    checkVectorFunctionMulti<int, 2, N_ODD, 3, 3, N_ODD + 1>(
        ScalarFn, VectorFn, ForcedVectorFn, InterleavedFn, InterleavedOnlyFn,
        "two_early_exits_odd_different_values");
  }
  // Test: Three early exits with odd trip count.
  {
    DEFINE_SCALAR_AND_VECTOR_EARLY_EXIT_3(
        int A[N_ODD]; int B[N_ODD]; int C[N_ODD];
        , A, B, C, for (unsigned I = 0; I < N_ODD; I++) {
          if (A[I] == 0)
            return I;
          if (A[I] == B[I])
            return I + 1000;
          if (B[I] == C[I])
            return I + 2000;
        } return -1;);
    checkVectorFunctionMulti<int, 3, N_ODD, 17, 17, 17>(
        ScalarFn, VectorFn, ForcedVectorFn, InterleavedFn, InterleavedOnlyFn,
        "three_early_exits_odd_trip_count");
  }

  // Test: Two early exits with small known trip count (no scalar remainder).
  {
    DEFINE_SCALAR_AND_VECTOR_EARLY_EXIT_2(
        int A[N_SMALL]; int B[N_SMALL]; int C[N_SMALL];
        , A, B, C, for (unsigned I = 0; I < N_SMALL; I++) {
          if (A[I] == 0)
            return I;
          if (A[I] == B[I])
            return I + 1000;
        } return -1;);
    checkVectorFunctionMulti<int, 2, N_SMALL, 3, 3, N_SMALL + 1>(
        ScalarFn, VectorFn, ForcedVectorFn, InterleavedFn, InterleavedOnlyFn,
        "two_early_exits_small_known_tc");
  }

  // Test: Three early exits with small known trip count (no scalar remainder).
  {
    DEFINE_SCALAR_AND_VECTOR_EARLY_EXIT_3(
        int A[N_SMALL]; int B[N_SMALL]; int C[N_SMALL];
        , A, B, C, for (unsigned I = 0; I < N_SMALL; I++) {
          if (A[I] == 0)
            return I;
          if (A[I] == B[I])
            return I + 1000;
          if (B[I] == C[I])
            return I + 2000;
        } return -1;);
    checkVectorFunctionMulti<int, 3, N_SMALL, 7, 7, 7>(
        ScalarFn, VectorFn, ForcedVectorFn, InterleavedFn, InterleavedOnlyFn,
        "three_early_exits_small_known_tc");
  }

  // Test: Two early exits with small known trip count and different returns.
  {
    DEFINE_SCALAR_AND_VECTOR_EARLY_EXIT_2(
        int A[N_SMALL]; int B[N_SMALL]; int C[N_SMALL];
        , A, B, C, for (unsigned I = 0; I < N_SMALL; I++) {
          if (A[I] == 0)
            return I;
          if (A[I] == B[I])
            return I * 2;
        } return -1;);
    checkVectorFunctionMulti<int, 2, N_SMALL, 3, 3, N_SMALL + 1>(
        ScalarFn, VectorFn, ForcedVectorFn, InterleavedFn, InterleavedOnlyFn,
        "two_early_exits_small_different_values");
  }

  return 0;
}
