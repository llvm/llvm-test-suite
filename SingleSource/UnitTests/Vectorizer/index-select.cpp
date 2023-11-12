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
    // Check with sorted inputs.
    std::sort(&Src1[0], &Src1[N]);
    std::sort(&Src2[0], &Src2[N]);
    auto Reference = ScalarFn(&Src1[0], &Src2[0], N);
    auto ToCheck = VectorFn(&Src1[0], &Src2[0], N);
    if (Reference != ToCheck) {
      std::cerr << "Miscompare\n";
      exit(1);
    }
  }

  {
    // Check with all max values.
    for (unsigned I = 0; I != N; ++I) {
      Src1[I] = std::numeric_limits<Ty>::max();
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
    // Check with first input all zeros and second input -1.
    for (unsigned I = 0; I != N; ++I) {
      Src1[I] = 0;
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
    // Check with first input all max values and second input all zeros.
    for (unsigned I = 0; I != N; ++I) {
      Src1[I] = std::numeric_limits<Ty>::max();
      Src2[I] = 0;
    }
    auto Reference = ScalarFn(&Src1[0], &Src2[0], N);
    auto ToCheck = VectorFn(&Src1[0], &Src2[0], N);
    if (Reference != ToCheck) {
      std::cerr << "Miscompare\n";
      exit(1);
    }
  }

  {
    // Check with inputs all zero.
    for (unsigned I = 0; I != N; ++I) {
      Src1[I] = 0;
      Src2[I] = 0;
    }
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

  // Tests select-minimum-index loops, where the loop selects the minimum value
  // and the first index of that value.
  {
    // Check loop starting at index 0 and stepping by 1.
    DEFINE_SCALAR_AND_VECTOR_FN2(
        uint32_t Min = std::numeric_limits<uint32_t>::max();
        uint32_t MinIdx = 0;,
        for (unsigned I = 0; I < TC; I++) {
          uint32_t D = A[I] + B[I];
          if (D < Min) {
            Min = D;
            MinIdx = I;
          }
        }
        return MinIdx;
        );
    checkVectorFunction<uint32_t, uint32_t>(ScalarFn, VectorFn,
                                            "min_index_select_u32_u32_start_0");
  }

  {
    // Check loop starting at index 0 and stepping by 1.
    DEFINE_SCALAR_AND_VECTOR_FN2(
        uint32_t Min = std::numeric_limits<uint32_t>::max();
        uint32_t MinIdx = 0;,
        for (unsigned I = 0; I < TC / 2; I += 2) {
          uint32_t D = A[I] + B[I];
          if (D < Min) {
            Min = D;
            MinIdx = I;
          }
        }
        return MinIdx;
        );
    checkVectorFunction<uint32_t, uint32_t>(
        ScalarFn, VectorFn, "min_index_select_u32_u32_start_0_inc_2");
  }

  {
    // Check loop starting at index 0 and stepping by 1. MinIdx starting at 2.
    DEFINE_SCALAR_AND_VECTOR_FN2(
        uint32_t Min = std::numeric_limits<uint32_t>::max();
        uint32_t MinIdx = 2;,
        for (unsigned I = 0; I < TC; I++) {
          uint32_t D = A[I] + B[I];
          if (D < Min) {
            Min = D;
            MinIdx = I;
          }
        }
        return MinIdx;
        );
    checkVectorFunction<uint32_t, uint32_t>(ScalarFn, VectorFn,
                                            "min_index_select_u32_u32_start_2");
  }

  {
    // Index is truncated in the loop.
    DEFINE_SCALAR_AND_VECTOR_FN2(
        uint32_t Min = std::numeric_limits<uint32_t>::max();
        uint32_t MinIdx = 0;,
        for (uint64_t I = 0; I < TC; I++) {
          uint32_t D = A[I] + B[I];
          if (D < Min) {
            Min = D;
            MinIdx = I;
          }
        }
        return MinIdx;
        );
    checkVectorFunction<uint32_t, uint32_t>(
        ScalarFn, VectorFn, "min_index_select_u32_u32_with_trunc");
  }

  {
    // Check loop where induction is truncated.
    DEFINE_SCALAR_AND_VECTOR_FN2(
        uint32_t Min = std::numeric_limits<uint32_t>::max();
        uint32_t MinIdx = 0;,
        for (unsigned I = TC; I > 0; I--) {
          uint32_t D = A[I] + B[I];
          if (D < Min) {
            Min = D;
            MinIdx = I;
          }
        }
        return MinIdx;
        );
    checkVectorFunction<uint32_t, uint32_t>(
        ScalarFn, VectorFn, "min_index_select_u32_u32_induction_decrement");
  }

  {
    // Check loop where both Min and MinIdx starts at the maximum value.
    DEFINE_SCALAR_AND_VECTOR_FN2(
        uint32_t Min = std::numeric_limits<uint32_t>::max();
        uint32_t MinIdx = std::numeric_limits<uint32_t>::max();,
        for (unsigned I = 0; I < TC; I++) {
          uint32_t D = A[I] + B[I];
          if (D < Min) {
            Min = D;
            MinIdx = I;
          }
        }
        return MinIdx;
        );
    checkVectorFunction<uint32_t, uint32_t>(
        ScalarFn, VectorFn, "min_index_select_u32_u32_start_0_min_idx_neg1");
  }

  {
    // Check loop starting at index 3 and stepping by 1. MinIdx starts at 3.
    DEFINE_SCALAR_AND_VECTOR_FN2(
        uint32_t Min = std::numeric_limits<uint32_t>::max();
        uint32_t MinIdx = 3;,
        for (unsigned I = 3; I < TC; I++) {
          uint32_t D = A[I] + B[I];
          if (D < Min) {
            Min = D;
            MinIdx = I;
          }
        }
        return MinIdx;
        );
    checkVectorFunction<uint32_t, uint32_t>(
        ScalarFn, VectorFn, "min_index_select_u32_u32_start_3_min_idx_3");
  }

  {
    // Check loop starting at index 3 and stepping by 1. MinIdx starts at 2.
    DEFINE_SCALAR_AND_VECTOR_FN2(
        uint32_t Min = std::numeric_limits<uint32_t>::max();
        uint32_t MinIdx = 2;,
        for (unsigned I = 3; I < TC; I++) {
          uint32_t D = A[I] + B[I];
          if (D < Min) {
            Min = D;
            MinIdx = I;
          }
        }
        return MinIdx;
        );
    checkVectorFunction<uint32_t, uint32_t>(
        ScalarFn, VectorFn, "min_index_select_u32_u32_start_3_min_idx_2");
  }

  {
    // Check loop starting at index 3 and stepping by 1. MinIdx starts at 4.
    DEFINE_SCALAR_AND_VECTOR_FN2(
        uint32_t Min = std::numeric_limits<uint32_t>::max();
        uint32_t MinIdx = 4;,
        for (unsigned I = 3; I < TC; I++) {
          uint32_t D = A[I] + B[I];
          if (D < Min) {
            Min = D;
            MinIdx = I;
          }
        }
        return MinIdx;
        );
    checkVectorFunction<uint32_t, uint32_t>(
        ScalarFn, VectorFn, "min_index_select_u32_u32_start_3_min_idx_4");
  }

  return 0;
}
