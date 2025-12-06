#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <stdint.h>

#define N 512

template <typename Ty>
using TestFnTy = std::function<unsigned(std::function<void(Ty *)>)>;

template <typename Ty>
static void checkVectorFunction(TestFnTy<Ty> ScalarFn, TestFnTy<Ty> VectorFn,
                                TestFnTy<Ty> InterleavedFn, const char *Name) {
  std::cout << "Checking " << Name << "\n";

  std::array Tests = {std::make_pair(VectorFn, "autovec"),
                      std::make_pair(InterleavedFn, "interleave-forced")};

  // Check finding the target element at all indices between 0 and 512.
  for (unsigned IdxToFind = 0; IdxToFind < 512; ++IdxToFind) {
    // Labmda to initialize all array elements to one, except the one to look
    // for to zero.
    auto Init1 = [IdxToFind](int *Arr) {
      std::fill_n(Arr, N, 1);
      if (IdxToFind < N)
        Arr[IdxToFind] = 0;
    };

    // Labmda to initialize all array elements to one, except the one to look
    // for and the IdxToFind + 3 to zero.
    auto Init2 = [IdxToFind](int *Arr) {
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
      auto ToCheck1 = Fn(Init1);
      if (Reference1 != ToCheck1) {
        std::cerr << "Miscompare for " << Name << ": " << Reference1
                  << " != " << ToCheck1 << "\n";
        exit(1);
      }
      auto ToCheck2 = Fn(Init2);
      if (Reference2 != ToCheck2) {
        std::cerr << "Miscompare for " << Name << ": " << Reference1
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
    Init II(Src);                                                              \
    _Pragma("clang loop vectorize(disable) interleave_count(1)") Loop          \
  };                                                                           \
  auto VectorFn = [](std::function<void(int *)> II) -> unsigned {              \
    Init II(Src);                                                              \
    _Pragma("clang loop vectorize(enable)") Loop                               \
  };                                                                           \
  auto InterleavedFn = [](std::function<void(int *)> II) -> unsigned {         \
    Init II(Src);                                                              \
    _Pragma("clang loop vectorize(enable) interleave_count(4)") Loop           \
  };

int main(void) {
  {
    DEFINE_SCALAR_AND_VECTOR_EARLY_EXIT(
        int A[N];, A, for (unsigned I = 0; I < N; I++) {
          if (A[I] == 0)
            return I;
        } return -1;);
    checkVectorFunction<int>(ScalarFn, VectorFn, InterleavedFn,
                             "early_exit_find_step_1");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_EARLY_EXIT(
        int A[N]; unsigned J = 2;, A, for (unsigned I = 0; I < N; I++) {
          if (A[I] == 0)
            return J;
          J += 3;
        } return -1;);
    checkVectorFunction<int>(ScalarFn, VectorFn, InterleavedFn,
                             "early_exit_find_step_3");
  }
  return 0;
}
