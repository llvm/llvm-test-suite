#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <stdint.h>

#define N 512

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
                      std::make_pair(ForcedVectorFn, "vector-forced")};
  // TODO: Re-enabled forced interleaving tests once
  // AArch64 SVE lowering issue has been fixed.
  // std::make_pair(InterleavedFn, "interleave-forced"),
  // std::make_pair(InterleavedOnlyFn, "interleave-only")};

  // Check finding the target element at all indices between 0 and 512.
  for (unsigned IdxToFind = 0; IdxToFind < 512; ++IdxToFind) {
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

/// Define 3 test functions
/// * one with vectorization and interleaving disabled,
/// * one with auto-vectorization w/o any pargmas
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
  return 0;
}
