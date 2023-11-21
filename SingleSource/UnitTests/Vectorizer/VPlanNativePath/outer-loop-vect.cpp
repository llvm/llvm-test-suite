#include <cstddef>
#include <cstdint>
#include <iostream>
#include <memory>

#include "../common.h"

// Tests for outer-loop vectorization in LLVM's VPlan-native path.

#define DEFINE_SCALAR_AND_VECTOR_FN_FOR_OLV(Args, Loop)                       \
  auto ScalarFn = [] Args {                                                   \
    _Pragma("clang loop vectorize(disable) interleave_count(1)") Loop         \
  };                                                                          \
  auto VectorFn = [] Args {                                                   \
    _Pragma("clang loop vectorize(enable)") Loop                              \
  };

#define DEFINE_SCALAR_AND_VECTOR_FN_FOR_NESTED_OLV(Args, Loop)                \
  auto ScalarFn = [] Args {                                                   \
    for (size_t I = 0; I < N; I++) {                                          \
      _Pragma("clang loop vectorize(disable) interleave_count(1)") Loop       \
    }                                                                         \
  };                                                                          \
  auto VectorFn = [] Args {                                                   \
    for (size_t I = 0; I < N; I++) {                                          \
      _Pragma("clang loop vectorize(enable)") Loop                            \
    }                                                                         \
  };

int main() {
  rng = std::mt19937(15);

  {
    // A matrix-multiplication where the second loop of the triple loop nest
    // is vectorized (the macro adds the outer-most loop).
    DEFINE_SCALAR_AND_VECTOR_FN_FOR_NESTED_OLV(
      (size_t N, size_t M, size_t L,
       int32_t *__restrict__ A, const int32_t *B, const int32_t *C),
      for (size_t J = 0; J < L; J++) {
        int32_t X = 0;
        for (size_t K = 0; K < M; K++)
          X += B[I * M + K] * C[K * L + J];
        A[I * L + J] = X;
      });

    std::cout << "Checking matrix-multiplication\n";

    size_t N = 100, M = 100, L = 100;
    std::unique_ptr<int32_t[]> A_Reference(new int32_t[N * L]);
    std::unique_ptr<int32_t[]> A_ToCheck(new int32_t[N * L]);
    std::unique_ptr<int32_t[]> B(new int32_t[N * M]);
    std::unique_ptr<int32_t[]> C(new int32_t[M * L]);
    init_data(B, N * M);
    init_data(C, M * L);

    ScalarFn(N, M, L, &A_Reference[0], &B[0], &C[0]);
    VectorFn(N, M, L, &A_ToCheck[0], &B[0], &C[0]);
    check(A_Reference, A_ToCheck, N*L);
  }

  {
    // A test where the vectorized loop itself has an auxiliary IV.
    DEFINE_SCALAR_AND_VECTOR_FN_FOR_OLV(
      (size_t N, int32_t *__restrict__ A, const int32_t *B),
      for (size_t I = 0, AuxIV = 333; I < N; I++, AuxIV += 12) {
        int32_t X = B[I];
        for (size_t J = 0; J < N; J++) {
          X += AuxIV * B[J];
        }
        A[I] = AuxIV + X;
      });

    std::cout << "Checking loop with auxiliary IV\n";

    size_t N = 123;
    std::unique_ptr<int32_t[]> A_Reference(new int32_t[N]);
    std::unique_ptr<int32_t[]> A_ToCheck(new int32_t[N]);
    std::unique_ptr<int32_t[]> B(new int32_t[N]);
    init_data(B, N);

    ScalarFn(N, &A_Reference[0], &B[0]);
    VectorFn(N, &A_ToCheck[0], &B[0]);
    check(A_Reference, A_ToCheck, N);
  }

  {
    // A test for irregular memory accesses patterns.
    DEFINE_SCALAR_AND_VECTOR_FN_FOR_OLV(
      (size_t N, size_t M,
       int32_t *__restrict__ A, const int32_t *B, const int32_t *C),
      for (size_t I = 0; I < N; I++) {
        int32_t X = 0;
        for (size_t J = 0; J < M / 2; J++) {
          int32_t Idx = C[J * 2];
          X += B[Idx % N];
        }
        A[I] = X;
      })

    std::cout << "Checking loop with indirect memory accesses\n";

    size_t N = 123, M = 456;
    std::unique_ptr<int32_t[]> A_Reference(new int32_t[N]);
    std::unique_ptr<int32_t[]> A_ToCheck(new int32_t[N]);
    std::unique_ptr<int32_t[]> B(new int32_t[N]);
    std::unique_ptr<int32_t[]> C(new int32_t[M]);
    init_data(B, N);
    init_data(C, M);

    ScalarFn(N, M, &A_Reference[0], &B[0], &C[0]);
    VectorFn(N, M, &A_ToCheck[0], &B[0], &C[0]);
    check(A_Reference, A_ToCheck, N);
  }

  {
    // A test where the vectorized loop contains a loop which contains
    // another loop itself.
    DEFINE_SCALAR_AND_VECTOR_FN_FOR_OLV(
      (size_t N, size_t M, size_t L, int32_t *__restrict__ A),
      for (size_t I = 0; I < N; I++) {
        for (size_t J = 0; J < M; J++) {
          for (size_t K = 0; K < L; K++) {
            A[I * (M * L) + J * L + K] = I * J * K;
          }
        }
      });

    std::cout << "Checking triple-loop-nest\n";

    size_t N = 123, M = 45, L = 67;
    std::unique_ptr<int32_t[]> A_Reference(new int32_t[N * M * L]);
    std::unique_ptr<int32_t[]> A_ToCheck(new int32_t[N * M * L]);

    ScalarFn(N, M, L, &A_Reference[0]);
    VectorFn(N, M, L, &A_ToCheck[0]);
    check(A_Reference, A_ToCheck, N * M * L);
  }

}
