#include <functional>
#include <iostream>
#include <limits>
#include <memory>
#include <random>
#include <stdint.h>

// Tests for vectorizing loops with recurrences.

static std::mt19937 rng;

// Initialize arrays A with random numbers.
template <typename Ty>
static void init_data(const std::unique_ptr<Ty[]> &A, unsigned N) {
  std::uniform_int_distribution<uint64_t> distrib(
      std::numeric_limits<Ty>::min(), std::numeric_limits<Ty>::max());
  for (unsigned i = 0; i < N; i++)
    A[i] = distrib(rng);
}

template <typename Ty>
static void check(const std::unique_ptr<Ty[]> &Reference,
                  const std::unique_ptr<Ty[]> &Tmp, unsigned NumElements) {
  if (!std::equal(&Reference[0], &Reference[0] + NumElements, &Tmp[0])) {
    std::cerr << "Miscompare\n";
    exit(1);
  }
}

#define DEFINE_SCALAR_AND_VECTOR_FN2(Init, Loop)                               \
  auto ScalarFn = [](auto *A, auto *B, unsigned TC) {                          \
    Init _Pragma("clang loop vectorize(disable)") Loop                         \
  };                                                                           \
  auto VectorFn = [](auto *A, auto *B, unsigned TC) {                          \
    Init _Pragma("clang loop vectorize(enable)") Loop                          \
  };

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
