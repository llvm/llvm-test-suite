#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <memory>
#include <stdint.h>

#include "common.h"

template <typename RetTy, typename Ty>
using Fn2Ty = std::function<RetTy(Ty *, Ty *, RetTy)>;
template <typename RetTy, typename Ty>
static void checkVectorFunction(Fn2Ty<RetTy, Ty> ScalarFn,
                                Fn2Ty<RetTy, Ty> VectorFn, const char *Name) {
  std::cout << "Checking " << Name << "\n";

  unsigned N = 1000;
  std::unique_ptr<Ty[]> Src1(new Ty[N]);
  std::unique_ptr<Ty[]> Src2(new Ty[N]);
  init_data(Src1, N);
  init_data(Src2, N);

  // Test VectorFn with different input data.
  {
    // Check with random inputs.
    auto Reference = ScalarFn(&Src1[0], &Src2[0], N);
    auto ToCheck = VectorFn(&Src1[0], &Src2[0], N);
    if (Reference != ToCheck) {
      std::cerr << "Miscompare\n";
      exit(1);
    }
  }

  {
    // Check with Src1 > Src2 for all elements.
    for (unsigned I = 0; I != N; ++I) {
      Src1[I] = std::numeric_limits<Ty>::max();
      Src2[I] = std::numeric_limits<Ty>::min();
    }
    auto Reference = ScalarFn(&Src1[0], &Src2[0], N);
    auto ToCheck = VectorFn(&Src1[0], &Src2[0], N);
    if (Reference != ToCheck) {
      std::cerr << "Miscompare\n";
      exit(1);
    }
  }

  {
    // Check with Src1 < Src2 for all elements.
    for (unsigned I = 0; I != N; ++I) {
      Src1[I] = std::numeric_limits<Ty>::min();
      Src2[I] = std::numeric_limits<Ty>::max();
    }
    auto Reference = ScalarFn(&Src1[0], &Src2[0], N);
    auto ToCheck = VectorFn(&Src1[0], &Src2[0], N);
    if (Reference != ToCheck) {
      std::cerr << "Miscompare\n";
      exit(1);
    }
  }

  {
    // Check with only Src1[998] > Src2[998].
    for (unsigned I = 0; I != N; ++I)
      Src1[I] = Src2[I] = std::numeric_limits<Ty>::min();
    Src1[998] = std::numeric_limits<Ty>::max();
    auto Reference = ScalarFn(&Src1[0], &Src2[0], N);
    auto ToCheck = VectorFn(&Src1[0], &Src2[0], N);
    if (Reference != ToCheck) {
      std::cerr << "Miscompare\n";
      exit(1);
    }
  }

  {
    // Check with only Src1[0] > Src2[0].
    for (unsigned I = 0; I != N; ++I)
      Src1[I] = Src2[I] = std::numeric_limits<Ty>::min();
    Src1[0] = std::numeric_limits<Ty>::max();
    auto Reference = ScalarFn(&Src1[0], &Src2[0], N);
    auto ToCheck = VectorFn(&Src1[0], &Src2[0], N);
    if (Reference != ToCheck) {
      std::cerr << "Miscompare\n";
      exit(1);
    }
  }

  {
    // Check with only Src1[N - 1] > Src2[N - 1].
    for (unsigned I = 0; I != N; ++I)
      Src1[I] = Src2[I] = std::numeric_limits<Ty>::min();
    Src1[N - 1] = std::numeric_limits<Ty>::max();
    auto Reference = ScalarFn(&Src1[0], &Src2[0], N);
    auto ToCheck = VectorFn(&Src1[0], &Src2[0], N);
    if (Reference != ToCheck) {
      std::cerr << "Miscompare\n";
      exit(1);
    }
  }

  {
    // Check with only Src1[0] > Src2[0] and Src1[N - 1] > Src2[N - 1].
    for (unsigned I = 0; I != N; ++I)
      Src1[I] = Src2[I] = std::numeric_limits<Ty>::min();
    Src1[0] = Src1[N - 1] = std::numeric_limits<Ty>::max();
    auto Reference = ScalarFn(&Src1[0], &Src2[0], N);
    auto ToCheck = VectorFn(&Src1[0], &Src2[0], N);
    if (Reference != ToCheck) {
      std::cerr << "Miscompare\n";
      exit(1);
    }
  }
}

int main(void) {
  rng = std::mt19937(15);

  {
    // Find the last index where A[I] > B[I] and update Rdx when the condition
    // is true.
    DEFINE_SCALAR_AND_VECTOR_FN2_TYPE(
        int32_t Rdx = -1;,
        for (int32_t I = 0; I < TC; I++) {
          Rdx = A[I] > B[I] ? I : Rdx;
        }
        return Rdx;,
        int32_t
        );
    checkVectorFunction<int32_t, int32_t>(ScalarFn, VectorFn,
                                          "findlast_true_update");
  }

  {
    // Update Rdx when the condition A[I] > B[I] is false.
    DEFINE_SCALAR_AND_VECTOR_FN2_TYPE(
        int32_t Rdx = -1;,
        for (int32_t I = 0; I < TC; I++) {
          Rdx = A[I] > B[I] ? Rdx : I;
        }
        return Rdx;,
        int32_t
        );
    checkVectorFunction<int32_t, int32_t>(ScalarFn, VectorFn,
                                          "findlast_false_update");
  }

  {
    // Find the last index with the start value TC.
    DEFINE_SCALAR_AND_VECTOR_FN2_TYPE(
        int32_t Rdx = TC;,
        for (int32_t I = 0; I < TC; I++) {
          Rdx = A[I] > B[I] ? I : Rdx;
        }
        return Rdx;,
        int32_t
        );
    checkVectorFunction<int32_t, int32_t>(ScalarFn, VectorFn,
                                          "findlast_start_TC");
  }

  {
    // Increment the induction variable by 2.
    DEFINE_SCALAR_AND_VECTOR_FN2_TYPE(
        int32_t Rdx = -1;,
        for (int32_t I = 0; I < TC; I += 2) {
          Rdx = A[I] > B[I] ? I : Rdx;
        }
        return Rdx;,
        int32_t
        );
    checkVectorFunction<int32_t, int32_t>(ScalarFn, VectorFn,
                                          "findlast_inc_2");
  }

  {
    // Check with decreasing induction variable.
    DEFINE_SCALAR_AND_VECTOR_FN2_TYPE(
        int32_t Rdx = -1;,
        for (int32_t I = TC; I > 0; I--) {
          Rdx = A[I] > B[I] ? I : Rdx;
        }
        return Rdx;,
        int32_t
        );
    checkVectorFunction<int32_t, int32_t>(
        ScalarFn, VectorFn, "findlast_start_decreasing_induction");
  }

  {
    // Check with the induction variable starts from 3.
    DEFINE_SCALAR_AND_VECTOR_FN2_TYPE(
        int32_t Rdx = -1;,
        for (int32_t I = 3; I < TC; I++) {
          Rdx = A[I] > B[I] ? I : Rdx;
        }
        return Rdx;,
        int32_t
        );
    checkVectorFunction<int32_t, int32_t>(ScalarFn, VectorFn,
                                          "findlast_iv_start_3");
  }

  {
    // Check with start value of 3 and induction variable starts at 3.
    DEFINE_SCALAR_AND_VECTOR_FN2_TYPE(
        int32_t Rdx = 3;,
        for (int32_t I = 3; I < TC; I++) {
          Rdx = A[I] > B[I] ? I : Rdx;
        }
        return Rdx;,
        int32_t
        );
    checkVectorFunction<int32_t, int32_t>(ScalarFn, VectorFn,
                                          "findlast_start_3_iv_start_3");
  }

  {
    // Check with start value of 2 and induction variable starts at 3.
    DEFINE_SCALAR_AND_VECTOR_FN2_TYPE(
        int32_t Rdx = 2;,
        for (int32_t I = 3; I < TC; I++) {
          Rdx = A[I] > B[I] ? I : Rdx;
        }
        return Rdx;,
        int32_t
        );
    checkVectorFunction<int32_t, int32_t>(ScalarFn, VectorFn,
                                          "findlast_start_2_iv_start_3");
  }

  {
    // Check with start value of 4 and induction variable starts at 3.
    DEFINE_SCALAR_AND_VECTOR_FN2_TYPE(
        int32_t Rdx = 4;,
        for (int32_t I = 3; I < TC; I++) {
          Rdx = A[I] > B[I] ? I : Rdx;
        }
        return Rdx;,
        int32_t
        );
    checkVectorFunction<int32_t, int32_t>(ScalarFn, VectorFn,
                                          "findlast_start_4_iv_start_3");
  }

  return 0;
}
