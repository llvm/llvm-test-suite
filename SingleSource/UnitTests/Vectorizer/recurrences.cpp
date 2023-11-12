#include <functional>
#include <iostream>
#include <limits>
#include <memory>
#include <stdint.h>

#include "common.h"

// Tests for vectorizing loops with recurrences.

template <typename Ty> using Fn2Ty = std::function<void(Ty *, Ty *, unsigned)>;
template <typename Ty>
static void checkVectorFunction(Fn2Ty<Ty> ScalarFn, Fn2Ty<Ty> VectorFn,
                                const char *Name) {
  std::cout << "Checking " << Name << "\n";

  unsigned N = 1000;
  std::unique_ptr<Ty[]> Src1(new Ty[N]);
  init_data(Src1, N);
  std::unique_ptr<Ty[]> Src2(new Ty[N]);
  for (unsigned I = 0; I < N; ++I)
    Src2[I] = Src1[I];
  std::unique_ptr<Ty[]> Reference(new Ty[N]);
  std::unique_ptr<Ty[]> ToCheck(new Ty[N]);

  ScalarFn(&Src1[0], &Reference[0], N);
  VectorFn(&Src2[0], &ToCheck[0], N);
  check(Reference, ToCheck, N);
}

int main(void) {
  rng = std::mt19937(15);

  {
    DEFINE_SCALAR_AND_VECTOR_FN2(
        int for1 = 33;,
        for (unsigned I = 0; I < TC; I++) {
          B[I] = for1 + I;
          for1 = I;
        });
    checkVectorFunction<uint32_t>(ScalarFn, VectorFn, "first_order_recurrence");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN2(
        int for2 = 22; int for1 = 33;,
        for (unsigned I = 0; I < TC; I++) {
          int t1 = for1;
          int t2 = for2;
          for2 = for1;
          for1 = A[I];
          B[I] = t1 + t2;
        });

    checkVectorFunction<uint32_t>(ScalarFn, VectorFn,
                                  "second_order_recurrence");
  }

  {
    DEFINE_SCALAR_AND_VECTOR_FN2(
        int for1 = 33; int for2 = 22; int for3 = 11;,
        for (unsigned I = 0; I < TC; I++) {
          int t1 = for1;
          int t2 = for2;
          int t3 = for3;
          for3 = for2;
          for2 = for1;
          for1 = A[I];
          B[I] = t1 + t2 + t3;
        });

    checkVectorFunction<uint32_t>(ScalarFn, VectorFn, "third_order_recurrence");
  }
  return 0;
}
