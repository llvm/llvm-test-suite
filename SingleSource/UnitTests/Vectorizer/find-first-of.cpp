
#include <functional>
#include <iostream>
#include <limits>
#include <memory>
#include <stdint.h>

#include "common.h"

template <typename Ty>
using Fn2Ty = std::function<Ty *(Ty *, Ty *, Ty *, Ty *)>;
template <typename Ty>
static void checkVectorFunction(Fn2Ty<Ty> ScalarFn, Fn2Ty<Ty> VectorFn,
                                const char *Name) {
  std::cout << "Checking " << Name << "\n";

  const unsigned A_n = 1000;
  const unsigned B_n = 64;
  std::unique_ptr<Ty[]> A(new Ty[A_n]);
  std::unique_ptr<Ty[]> B(new Ty[B_n]);
  init_data(A, A_n);
  init_data(B, B_n);

  // Test VectorFn with different input data.
  {
    // Check with random inputs.
    auto Reference = ScalarFn(A.get(), A.get() + A_n, B.get(), B.get() + B_n);
    auto ToCheck = VectorFn(A.get(), A.get() + A_n, B.get(), B.get() + B_n);
    if (Reference != ToCheck) {
      std::cerr << "Miscompare\n";
      exit(1);
    }
  }

  {
    // Check with A < B for all elements.
    for (unsigned i = 0; i < A_n; ++i) {
      A[i] = std::numeric_limits<Ty>::min();
    }
    for (unsigned i = 0; i < B_n; ++i) {
      B[i] = std::numeric_limits<Ty>::max();
    }
    auto Reference = ScalarFn(A.get(), A.get() + A_n, B.get(), B.get() + B_n);
    auto ToCheck = VectorFn(A.get(), A.get() + A_n, B.get(), B.get() + B_n);
    if (Reference != ToCheck) {
      std::cerr << "Miscompare\n";
      exit(1);
    }
  }

  {
    // Check with no match -> should return sentinel.
    for (unsigned i = 0; i < A_n; ++i) {
      A[i] = std::numeric_limits<Ty>::min();
    }
    for (unsigned i = 0; i < B_n; ++i) {
      B[i] = std::numeric_limits<Ty>::max();
    }
    auto Reference = ScalarFn(A.get(), A.get() + A_n, B.get(), B.get() + B_n);
    auto ToCheck = VectorFn(A.get(), A.get() + A_n, B.get(), B.get() + B_n);
    if (Reference != ToCheck) {
      std::cerr << "Miscompare\n";
      exit(1);
    }
  }

  {
    // Check with all matching -> should return first element.
    for (unsigned i = 0; i < A_n; ++i) {
      A[i] = std::numeric_limits<Ty>::min();
    }
    for (unsigned i = 0; i < B_n; ++i) {
      B[i] = std::numeric_limits<Ty>::min();
    }
    auto Reference = ScalarFn(A.get(), A.get() + A_n, B.get(), B.get() + B_n);
    auto ToCheck = VectorFn(A.get(), A.get() + A_n, B.get(), B.get() + B_n);
    if (Reference != ToCheck) {
      std::cerr << "Miscompare\n";
      exit(1);
    }
  }

  {
    // Check with only first element of A matching first element of B.
    for (unsigned i = 0; i < A_n; ++i) {
      A[i] = std::numeric_limits<Ty>::min();
    }
    for (unsigned i = 0; i < B_n; ++i) {
      B[i] = std::numeric_limits<Ty>::max();
    }
    A[0] = B[0] = std::numeric_limits<Ty>::min() + 1;

    auto Reference = ScalarFn(A.get(), A.get() + A_n, B.get(), B.get() + B_n);
    auto ToCheck = VectorFn(A.get(), A.get() + A_n, B.get(), B.get() + B_n);
    if (Reference != ToCheck) {
      std::cerr << "Miscompare\n";
      exit(1);
    }
  }

  {
    // Check with only first element of A matching last element of B.
    for (unsigned i = 0; i < A_n; ++i) {
      A[i] = std::numeric_limits<Ty>::min();
    }
    for (unsigned i = 0; i < B_n; ++i) {
      B[i] = std::numeric_limits<Ty>::max();
    }
    A[0] = B[B_n - 1] = std::numeric_limits<Ty>::min() + 1;

    auto Reference = ScalarFn(A.get(), A.get() + A_n, B.get(), B.get() + B_n);
    auto ToCheck = VectorFn(A.get(), A.get() + A_n, B.get(), B.get() + B_n);
    if (Reference != ToCheck) {
      std::cerr << "Miscompare\n";
      exit(1);
    }
  }

  {
    // Check multiple matches, first at index 7.
    for (unsigned i = 0; i < A_n; ++i) {
      A[i] = std::numeric_limits<Ty>::min();
    }
    for (unsigned i = 0; i < B_n; ++i) {
      B[i] = std::numeric_limits<Ty>::max();
    }
    A[7] = B[0] = std::numeric_limits<Ty>::min() + 1;
    A[19] = B[37] = std::numeric_limits<Ty>::min() + 2;
    A[450] = B[52] = std::numeric_limits<Ty>::min() + 3;

    auto Reference = ScalarFn(A.get(), A.get() + A_n, B.get(), B.get() + B_n);
    auto ToCheck = VectorFn(A.get(), A.get() + A_n, B.get(), B.get() + B_n);
    if (Reference != ToCheck) {
      std::cerr << "Miscompare\n";
      exit(1);
    }
  }

  {
    // Check multiple matches, first at A[0] matching B[N-1], second at A[1]
    // matching B[0].
    for (unsigned i = 0; i < A_n; ++i) {
      A[i] = std::numeric_limits<Ty>::min();
    }
    for (unsigned i = 0; i < B_n; ++i) {
      B[i] = std::numeric_limits<Ty>::max();
    }
    A[0] = B[B_n - 1] = std::numeric_limits<Ty>::min() + 1;
    A[1] = B[0] = std::numeric_limits<Ty>::min() + 2;

    auto Reference = ScalarFn(A.get(), A.get() + A_n, B.get(), B.get() + B_n);
    auto ToCheck = VectorFn(A.get(), A.get() + A_n, B.get(), B.get() + B_n);
    if (Reference != ToCheck) {
      std::cerr << "Miscompare\n";
      exit(1);
    }
  }
}

int main() {
  rng = std::mt19937(15);

#define DEFINE_FIND_FIRST_OF_LOOP_OUTER for (; FirstA != LastA; ++FirstA)
#define DEFINE_FIND_FIRST_OF_LOOP_INNER                                        \
  for (auto *It = FirstB; It != LastB; ++It)                                   \
    if (*FirstA == *It)                                                        \
      return FirstA;
#define DEFINE_FIND_FIRST_OF_RET return LastA;

  {
    DEFINE_NESTED_SCALAR_AND_VECTOR_FN4_PTR(DEFINE_FIND_FIRST_OF_LOOP_OUTER,
                                            DEFINE_FIND_FIRST_OF_LOOP_INNER,
                                            DEFINE_FIND_FIRST_OF_RET);

    checkVectorFunction<uint8_t>(ScalarFn, VectorFn, "find_first_of_u8");
  }

  {
    DEFINE_NESTED_SCALAR_AND_VECTOR_FN4_PTR(DEFINE_FIND_FIRST_OF_LOOP_OUTER,
                                            DEFINE_FIND_FIRST_OF_LOOP_INNER,
                                            DEFINE_FIND_FIRST_OF_RET);

    checkVectorFunction<uint16_t>(ScalarFn, VectorFn, "find_first_of_u16");
  }

  {
    DEFINE_NESTED_SCALAR_AND_VECTOR_FN4_PTR(DEFINE_FIND_FIRST_OF_LOOP_OUTER,
                                            DEFINE_FIND_FIRST_OF_LOOP_INNER,
                                            DEFINE_FIND_FIRST_OF_RET);

    checkVectorFunction<uint32_t>(ScalarFn, VectorFn, "find_first_of_u32");
  }

  {
    DEFINE_NESTED_SCALAR_AND_VECTOR_FN4_PTR(DEFINE_FIND_FIRST_OF_LOOP_OUTER,
                                            DEFINE_FIND_FIRST_OF_LOOP_INNER,
                                            DEFINE_FIND_FIRST_OF_RET);

    checkVectorFunction<uint64_t>(ScalarFn, VectorFn, "find_first_of_u64");
  }

  return 0;
}
