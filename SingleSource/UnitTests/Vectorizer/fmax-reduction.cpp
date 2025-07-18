#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <memory>
#include <stdint.h>

#include "common.h"

static bool isEqual(float A, float B) {
  if (std::isnan(A) || std::isnan(B))
    return std::isnan(A) && std::isnan(B);

  if (A == 0.0f)
    return B == 0.0f && std::signbit(A) == std::signbit(B);

  return A == B;
}

template <typename Ty> using Fn1Ty = std::function<Ty(Ty *, unsigned)>;

template <typename Ty>
static void check(Fn1Ty<Ty> ScalarFn, Fn1Ty<Ty> VectorFn, float *Src,
                  unsigned N, const char *Type) {
  auto Reference = ScalarFn(Src, N);
  auto ToCheck = VectorFn(Src, N);
  if (!isEqual(Reference, ToCheck)) {
    std::cerr << "Miscompare " << Type << ": " << Reference << " != " << ToCheck
              << "\n";
    exit(1);
  }
}

template <typename Ty>
static void checkVectorFunction(Fn1Ty<Ty> ScalarFn, Fn1Ty<Ty> VectorFn,
                                const char *Name) {
  std::cout << "Checking " << Name << "\n";

  unsigned N = 1024;
  std::unique_ptr<Ty[]> Src1(new Ty[N]);
  init_data(Src1, N);

  // Check with random inputs.

  // Check with sorted inputs.
  std::sort(&Src1[0], &Src1[N]);
  check(ScalarFn, VectorFn, &Src1[0], N, "sorted");

  // Check with reverse sorted inputs.
  std::reverse(&Src1[0], &Src1[N]);
  check(ScalarFn, VectorFn, &Src1[0], N, "reverse-sorted");

  // Check with all max values.
  for (unsigned I = 0; I != N; ++I)
    Src1[I] = std::numeric_limits<Ty>::max();
  check(ScalarFn, VectorFn, &Src1[0], N, "all-max");

  // Check with all min values.
  for (unsigned I = 0; I != N; ++I)
    Src1[I] = std::numeric_limits<Ty>::min();
  check(ScalarFn, VectorFn, &Src1[0], N, "all-min");

  // Check with various denormals.
  Src1[0] = std::numeric_limits<Ty>::denorm_min();
  for (unsigned I = 1; I != N; ++I)
    Src1[I] = std::numeric_limits<Ty>::denorm_min() / I;
  check(ScalarFn, VectorFn, &Src1[0], N, "denormals");

  // Check with inputs all zero.
  for (unsigned I = 0; I != N; ++I)
    Src1[I] = 0.0;
  check(ScalarFn, VectorFn, &Src1[0], N, "all-zeros");

  // Check with NaN at different indices.
  for (unsigned NaNIdx = 3; NaNIdx != 32; NaNIdx++) {
    for (unsigned I = 0; I != N; ++I)
      Src1[I] = 100;
    Src1[NaNIdx] = std::numeric_limits<Ty>::quiet_NaN();

    check(ScalarFn, VectorFn, &Src1[0], N, "NaN");
  }

  // Check with multiple signed-zeros at different positions.
  for (unsigned Idx = 0; Idx != 64; ++Idx) {
    for (unsigned I = 0; I != N; ++I)
      Src1[I] = -1.0;

    for (unsigned Offset = 1; Offset != 32; ++Offset) {
      Src1[Idx] = -0.0;
      Src1[Idx + Offset] = +0.0;

      check(ScalarFn, VectorFn, &Src1[0], N, "signed-zeros");
    }
  }

  for (unsigned Idx = 0; Idx != 64; ++Idx) {
    for (unsigned I = 0; I != N; ++I)
      Src1[I] = -1.0;

    for (unsigned Offset = 1; Offset != 32; ++Offset) {
      Src1[Idx] = +0.0;
      Src1[Idx + Offset] = -0.0;

      check(ScalarFn, VectorFn, &Src1[0], N, "signed-zeros");
    }
  }

  // Check with max value at all possible indices.
  for (unsigned Idx = 0; Idx != N; ++Idx) {
    for (unsigned I = 0; I != N; ++I)
      Src1[I] = I;

    Src1[Idx] = N + 1;

    check(ScalarFn, VectorFn, &Src1[0], N, "full");

    for (unsigned Offset = 1; Offset != 16; ++Offset) {
      if (Idx + Offset < N)
        Src1[Idx + Offset] = N + 1;

      check(ScalarFn, VectorFn, &Src1[0], N, "full");
    }
  }

  // Check with NaN value at all possible indices.
  for (unsigned Idx = 0; Idx != N; ++Idx) {
    for (unsigned I = 0; I != N; ++I)
      Src1[I] = I;

    Src1[Idx] = std::numeric_limits<float>::quiet_NaN();
    check(ScalarFn, VectorFn, &Src1[0], N, "full-with-nan");

    // Check with multiple NaNs at different offsets.
    for (unsigned Offset = 1; Offset != 16; ++Offset) {
      if (Idx + Offset < N)
        Src1[Idx + Offset] = std::numeric_limits<float>::quiet_NaN();

      check(ScalarFn, VectorFn, &Src1[0], N, "full-with-multiple-nan");
    }
  }

  // Check with multiple infinity values at different positions.
  for (unsigned Idx = 0; Idx != 64; ++Idx) {
    for (unsigned I = 0; I != N; ++I)
      Src1[I] = -1.0;

    for (unsigned Offset = 1; Offset != 16; ++Offset) {
      Src1[Idx] = -std::numeric_limits<float>::infinity();
      Src1[Idx + Offset] = std::numeric_limits<float>::infinity();

      check(ScalarFn, VectorFn, &Src1[0], N, "infinity");
    }
  }
}

int main(void) {
  rng = std::mt19937(15);

  {
    DEFINE_SCALAR_AND_VECTOR_FN1_TYPE(
        float Max = -2.0;, for (unsigned I = 0; I < 1024;
                                I++) { Max = std::fmax(Max, A[I]); } return Max;
        , float);
    checkVectorFunction<float>(ScalarFn, VectorFn, "fmaxnum_start_neg_2");
  }
  {
    DEFINE_SCALAR_AND_VECTOR_FN1_TYPE(
        float Max = std::numeric_limits<float>::min();
        , for (unsigned I = 0; I < 1024;
               I++) { Max = std::fmax(Max, A[I]); } return Max;
        , float);
    checkVectorFunction<float>(ScalarFn, VectorFn, "fmaxnum_start_min");
  }
  {
    DEFINE_SCALAR_AND_VECTOR_FN1_TYPE(
        float Max = std::numeric_limits<float>::denorm_min();
        , for (unsigned I = 0; I < 1024;
               I++) { Max = std::fmax(Max, A[I]); } return Max;
        , float);
    checkVectorFunction<float>(ScalarFn, VectorFn, "fmaxnum_start_denorm_min");
  }
  {
    DEFINE_SCALAR_AND_VECTOR_FN1_TYPE(
        float Max = std::numeric_limits<float>::quiet_NaN();
        , for (unsigned I = 0; I < 1024;
               I++) { Max = std::fmax(Max, A[I]); } return Max;
        , float);
    checkVectorFunction<float>(ScalarFn, VectorFn, "fmaxnum_start_is_nan");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN1_TYPE(
        float Max = -2.0;
        , for (unsigned I = 0; I < 1024;
               I++) { Max = A[I] > Max ? A[I] : Max; } return Max;
        , float);
    checkVectorFunction<float>(ScalarFn, VectorFn, "fmax_strict_start_neg_2");
  }
  {
    DEFINE_SCALAR_AND_VECTOR_FN1_TYPE(
        float Max = std::numeric_limits<float>::min();
        , for (unsigned I = 0; I < 1024;
               I++) { Max = A[I] > Max ? A[I] : Max; } return Max;
        , float);
    checkVectorFunction<float>(ScalarFn, VectorFn, "fmax_strict_start_min");
  }
  {
    DEFINE_SCALAR_AND_VECTOR_FN1_TYPE(
        float Max = std::numeric_limits<float>::denorm_min();
        , for (unsigned I = 0; I < 1025;
               I++) { Max = A[I] > Max ? A[I] : Max; } return Max;
        , float);
    checkVectorFunction<float>(ScalarFn, VectorFn,
                               "fmax_strict_start_denorm_min");
  }
  {
    DEFINE_SCALAR_AND_VECTOR_FN1_TYPE(
        float Max = std::numeric_limits<float>::quiet_NaN();
        , for (unsigned I = 0; I < 1025;
               I++) { Max = A[I] > Max ? A[I] : Max; } return Max;
        , float);
    checkVectorFunction<float>(ScalarFn, VectorFn, "fmax_strict_start_nan");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN1_TYPE(
        float Max = -2.0;
        , for (unsigned I = 0; I < 1024;
               I++) { Max = Max >= A[I] ? Max : A[I]; } return Max;
        , float);
    checkVectorFunction<float>(ScalarFn, VectorFn,
                               "fmax_non_strict_start_neg_2");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN1_TYPE(
        float Max = -2.0;
        , for (unsigned I = 0; I < 1024;
               I++) { Max = Max > A[I] ? Max : A[I]; } return Max;
        , float);
    checkVectorFunction<float>(ScalarFn, VectorFn,
                               "fmax_cmp_max_gt_start_neg_2");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN1_TYPE(
        float Max = -2.0;
        , for (unsigned I = 0; I < 1024;
               I++) { Max = Max < A[I] ? A[I] : Max; } return Max;
        , float);
    checkVectorFunction<float>(ScalarFn, VectorFn,
                               "fmax_cmp_max_lt_start_neg_2");
  }
  {
    DEFINE_SCALAR_AND_VECTOR_FN1_TYPE(
        float Max = std::numeric_limits<float>::denorm_min();
        , for (unsigned I = 0; I < 1024;
               I++) { Max = Max < A[I] ? A[I] : Max; } return Max;
        , float);
    checkVectorFunction<float>(ScalarFn, VectorFn,
                               "fmax_cmp_max_lt_start_denorm_min");
  }
  {
    DEFINE_SCALAR_AND_VECTOR_FN1_TYPE(
        float Max = std::numeric_limits<float>::quiet_NaN();
        , for (unsigned I = 0; I < 1024;
               I++) { Max = Max < A[I] ? A[I] : Max; } return Max;
        , float);
    checkVectorFunction<float>(ScalarFn, VectorFn,
                               "fmax_cmp_max_lt_start_neg_nan");
  }

  return 0;
}
