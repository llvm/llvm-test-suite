#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <memory>
#include <stdint.h>

#include "common.h"

template <typename RetTy, typename Ty>
using Fn2Ty = std::function<RetTy(Ty *, Ty *, unsigned)>;
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
    // Update Rdx to 3 once any A[i] > B[i] is true.
    DEFINE_SCALAR_AND_VECTOR_FN2(
        uint32_t Rdx = -1;,
        for (unsigned I = 0; I < TC; I++) {
          Rdx = A[I] > B[I] ? 3 : Rdx;
        }
        return Rdx;
        );
    checkVectorFunction<uint32_t, int32_t>(ScalarFn, VectorFn,
                                           "anyof_icmp_true_update");
    checkVectorFunction<uint32_t, float>(ScalarFn, VectorFn,
                                         "anyof_fcmp_true_update");
  }

  {
    // Update Rdx to 3 once any A[i] > B[i] is false.
    DEFINE_SCALAR_AND_VECTOR_FN2(
        uint32_t Rdx = -1;,
        for (unsigned I = 0; I < TC; I++) {
          Rdx = A[I] > B[I] ? Rdx : 3;
        }
        return Rdx;
        );
    checkVectorFunction<uint32_t, int32_t>(ScalarFn, VectorFn,
                                           "anyof_icmp_false_update");
    checkVectorFunction<uint32_t, float>(ScalarFn, VectorFn,
                                         "anyof_fcmp_false_update");
  }

  {
    // Rdx starts from TC, and will be updated to 3 once any A[i] > B[i] is
    // true.
    DEFINE_SCALAR_AND_VECTOR_FN2(
        uint32_t Rdx = TC;,
        for (unsigned I = 0; I < TC; I++) {
          Rdx = A[I] > B[I] ? Rdx : 3;
        }
        return Rdx;
        );
    checkVectorFunction<uint32_t, int32_t>(ScalarFn, VectorFn,
                                           "anyof_icmp_start_TC");
    checkVectorFunction<uint32_t, float>(ScalarFn, VectorFn,
                                         "anyof_fcmp_start_TC");
  }

  {
    // Rdx starts from -1, and will be updated to TC once any A[i] > B[i] is
    // true.
    DEFINE_SCALAR_AND_VECTOR_FN2(
        int32_t Rdx = -1;,
        for (unsigned I = 0; I < TC; I++) {
          Rdx = A[I] > B[I] ? TC : Rdx;
        }
        return Rdx;
        );
    checkVectorFunction<uint32_t, int32_t>(ScalarFn, VectorFn,
                                           "anyof_icmp_update_by_TC");
    checkVectorFunction<uint32_t, float>(ScalarFn, VectorFn,
                                         "anyof_fcmp_update_by_TC");
  }

  return 0;
}
