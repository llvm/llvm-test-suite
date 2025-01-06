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

#define DEFINE_ANYOF_LOOP_BODY(TrueVal, FalseVal)                              \
  for (unsigned I = 0; I < TC; I++) {                                          \
    Rdx = A[I] > B[I] ? TrueVal : FalseVal;                                    \
  }                                                                            \
  return Rdx;

  {
    // Update 32-bits integer Rdx to 3 once any A[i] > B[i] is true.
    DEFINE_SCALAR_AND_VECTOR_FN2(
        int32_t Rdx = -1;
        , DEFINE_ANYOF_LOOP_BODY(/* TrueVal= */ 3, /* FalseVal= */ Rdx));
    checkVectorFunction<int32_t, int32_t>(ScalarFn, VectorFn,
                                          "anyof_icmp_s32_true_update");
    checkVectorFunction<int32_t, float>(ScalarFn, VectorFn,
                                        "anyof_fcmp_s32_true_update");
  }

  {
    // Update 16-bits integer Rdx to 3 once any A[i] > B[i] is true.
    DEFINE_SCALAR_AND_VECTOR_FN2(
        int16_t Rdx = -1;
        , DEFINE_ANYOF_LOOP_BODY(/* TrueVal= */ 3, /* FalseVal= */ Rdx));
    checkVectorFunction<int16_t, int16_t>(ScalarFn, VectorFn,
                                          "anyof_icmp_s16_true_update");
  }

  {
    // Update 32-bits integer Rdx to 3 once any A[i] > B[i] is false.
    DEFINE_SCALAR_AND_VECTOR_FN2(
        int32_t Rdx = -1;
        , DEFINE_ANYOF_LOOP_BODY(/* TrueVal= */ Rdx, /* FalseVal= */ 3));
    checkVectorFunction<int32_t, int32_t>(ScalarFn, VectorFn,
                                          "anyof_icmp_s32_false_update");
    checkVectorFunction<int32_t, float>(ScalarFn, VectorFn,
                                        "anyof_fcmp_s32_false_update");
  }

  {
    // Update 16-bits integer Rdx to 3 once any A[i] > B[i] is false.
    DEFINE_SCALAR_AND_VECTOR_FN2(
        int16_t Rdx = -1;
        , DEFINE_ANYOF_LOOP_BODY(/* TrueVal= */ Rdx, /* FalseVal= */ 3));
    checkVectorFunction<int16_t, int16_t>(ScalarFn, VectorFn,
                                          "anyof_icmp_s16_false_update");
  }

  {
    // 32-bits integer Rdx starts from TC, and will be updated to 3 once any
    // A[i] > B[i] is true.
    DEFINE_SCALAR_AND_VECTOR_FN2(
        uint32_t Rdx = TC;
        , DEFINE_ANYOF_LOOP_BODY(/* TrueVal= */ 3, /* FalseVal= */ Rdx));
    checkVectorFunction<uint32_t, uint32_t>(ScalarFn, VectorFn,
                                            "anyof_icmp_u32_start_TC");
    checkVectorFunction<uint32_t, float>(ScalarFn, VectorFn,
                                         "anyof_fcmp_u32_start_TC");
  }

  {
    // 16-bits integer Rdx starts from TC, and will be updated to 3 once any
    // A[i] > B[i] is true.
    DEFINE_SCALAR_AND_VECTOR_FN2(
        uint16_t Rdx = TC;
        , DEFINE_ANYOF_LOOP_BODY(/* TrueVal= */ 3, /* FalseVal= */ Rdx));
    checkVectorFunction<uint16_t, uint16_t>(ScalarFn, VectorFn,
                                            "anyof_icmp_u16_start_TC");
  }

  {
    // 32-bits integer Rdx starts from 3, and will be updated to TC once any
    // A[i] > B[i] is true.
    DEFINE_SCALAR_AND_VECTOR_FN2(
        uint32_t Rdx = 3;
        , DEFINE_ANYOF_LOOP_BODY(/* TrueVal= */ TC, /* FalseVal= */ Rdx));
    checkVectorFunction<uint32_t, uint32_t>(ScalarFn, VectorFn,
                                            "anyof_icmp_u32_update_by_TC");
    checkVectorFunction<uint32_t, float>(ScalarFn, VectorFn,
                                         "anyof_fcmp_u32_update_by_TC");
  }

  {
    // 16-bits integer Rdx starts from 3, and will be updated to TC once any
    // A[i] > B[i] is true.
    DEFINE_SCALAR_AND_VECTOR_FN2(
        uint16_t Rdx = 3;
        , DEFINE_ANYOF_LOOP_BODY(/* TrueVal= */ TC, /* FalseVal= */ Rdx));
    checkVectorFunction<uint16_t, uint16_t>(ScalarFn, VectorFn,
                                            "anyof_icmp_u16_update_by_TC");
  }

  return 0;
}
