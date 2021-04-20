// Runtime tests to ensure the Matrix Type extension implementation matches the
// specification.

// Only build the tests if the proper extensions is available.
#if __has_extension(matrix_types)

#include <iostream>
#include <random>
#include <stdlib.h>

#define ABSTOL 0.000001
#define RELTOL 0.00001
bool fpcmp(double V1, double V2, double AbsTolerance, double RelTolerance) {
  // Check to see if these are inside the absolute tolerance
  if (AbsTolerance < fabs(V1 - V2)) {
    // Nope, check the relative tolerance...
    double Diff;
    if (V2)
      Diff = fabs(V1 / V2 - 1.0);
    else if (V1)
      Diff = fabs(V2 / V1 - 1.0);
    else
      Diff = 0; // Both zero.
    if (Diff > RelTolerance) {
      return true;
    }
  }
  return false;
}

template <typename ElementTy, typename std::enable_if<
                                  std::is_integral<ElementTy>::value, int>::type = 0>
void expectMatrixEQ(ElementTy *A, ElementTy *B, unsigned R, unsigned C) {
  do {
    for (unsigned r = 0; r < R; r++)
      for (unsigned c = 0; c < C; c++)
        if (A[r + c * R] != B[r + c * R]) {
          std::cerr << "mismatch at " << r << ":" << c << "\n";
          exit(1);
        }
  } while (false);
}

template <typename ElementTy,
          typename std::enable_if<std::is_floating_point<ElementTy>::value,
                                    int>::type = 0>
void expectMatrixEQ(ElementTy *A, ElementTy *B, unsigned R,
                      unsigned C) {
  do {
    for (unsigned r = 0; r < R; r++)
      for (unsigned c = 0; c < C; c++)
        if (fpcmp(A[r + c * R], B[r + c * R], ABSTOL, RELTOL)) {
          std::cerr << "mismatch at " << r << ":" << c << "\n";
          exit(1);
        }
  } while (false);
}


template <typename EltTy>
void zeroMatrix(EltTy *M, unsigned Rows, unsigned Cols) {
  for (unsigned r = 0; r < Rows; r++)
    for (unsigned c = 0; c < Cols; c++)
      M[r + c * Rows] = 0;
}

template <typename EltTy> void print(EltTy *X, unsigned Rows, unsigned Cols) {
  for (int r = 0; r < Rows; r++) {
    for (int c = 0; c < Cols; c++)
      std::cout << X[r + c * Rows] << ", ";
    std::cout << "\n";
  }
}

template <typename ElementTy,
          typename std::enable_if<std::is_floating_point<ElementTy>::value,
                                    int>::type = 0>
void initRandom(ElementTy *A, unsigned Rows, unsigned Cols) {
  std::default_random_engine generator;
  std::uniform_real_distribution<ElementTy> distribution(-10.0, 10.0);

  for (unsigned i = 0; i < Rows * Cols; i++)
    A[i] = distribution(generator);
}

template <typename ElementTy, typename std::enable_if<
                                  std::is_integral<ElementTy>::value, int>::type = 0>
void initRandom(ElementTy *A, unsigned Rows, unsigned Cols) {
  std::default_random_engine generator;
  std::uniform_int_distribution<ElementTy> distribution(-10, 10);

  for (unsigned i = 0; i < Rows * Cols; i++)
    A[i] = distribution(generator);
}

template <typename EltTy, unsigned R, unsigned C>
void transposeBuiltin(EltTy *ResPtr, EltTy *SrcPtr) {
  auto M = __builtin_matrix_column_major_load(SrcPtr, R, C, R);
  __builtin_matrix_column_major_store(__builtin_matrix_transpose(M), ResPtr, C);
}

template <typename EltTy, unsigned R, unsigned C>
void transposeSpec(EltTy *ResPtr, EltTy *SrcPtr) {
  using matrix_trans_t = EltTy __attribute__((matrix_type(C, R)));
  auto M = __builtin_matrix_column_major_load(SrcPtr, R, C, R);
  matrix_trans_t Res;
  for (int c = 0; c < C; ++c)
    for (int r = 0; r < R; ++r)
      Res[c][r] = M[r][c];
  __builtin_matrix_column_major_store(Res, ResPtr, C);
}

template <typename Ty>
static void transposeBase(Ty *Res, Ty *Src, unsigned R0, unsigned C0) {
  for (unsigned r = 0; r < R0; r++) {
    for (unsigned c = 0; c < C0; c++)
      Res[c + r * C0] = Src[r + c * R0];
  }
}

template <typename EltTy, unsigned R0, unsigned C0> void testTranspose() {
  EltTy X[R0 * C0];
  EltTy ResBase[R0 * C0];
  EltTy ResSpec[R0 * C0];
  EltTy ResBuiltin[R0 * C0];

  initRandom(X, R0, C0);
  zeroMatrix(ResBase, C0, R0);
  zeroMatrix(ResSpec, C0, R0);
  zeroMatrix(ResBuiltin, C0, R0);

  transposeBase(ResBase, X, R0, C0);
  transposeSpec<EltTy, R0, C0>(ResSpec, X);
  transposeBuiltin<EltTy, R0, C0>(ResBuiltin, X);

  expectMatrixEQ(ResBase, ResBuiltin, R0, C0);
  expectMatrixEQ(ResBase, ResSpec, C0, R0);
}

template <typename EltTy, unsigned R0, unsigned C0, unsigned C1>
void multiplyBuiltin(EltTy *Res, EltTy *Matrix1, EltTy *Matrix2) {
  using res_t = EltTy __attribute__((matrix_type(R0, C1)));

  auto A = __builtin_matrix_column_major_load(Matrix1, R0, C0, R0);
  auto B = __builtin_matrix_column_major_load(Matrix2, C0, C1, C0);
  res_t C = A * B;
  __builtin_matrix_column_major_store(C, Res, R0);
}

template <typename EltTy, unsigned R0, unsigned C0, unsigned C1>
void multiplySpec(EltTy *Res, EltTy *Matrix1, EltTy *Matrix2) {
  using res_t = EltTy __attribute__((matrix_type(R0, C1)));

  auto A = __builtin_matrix_column_major_load(Matrix1, R0, C0, R0);
  auto B = __builtin_matrix_column_major_load(Matrix2, C0, C1, C0);
  res_t ResM;
  for (int C = 0; C < C1; ++C) {
    for (int R = 0; R < R0; ++R) {
      EltTy Elt = 0;
      for (int K = 0; K < C0; K++)
        Elt += A[R][K] * B[K][C];
      ResM[R][C] = Elt;
    }
  }
  __builtin_matrix_column_major_store(ResM, Res, R0);
}

template <typename Ty>
static void BaseMatrixMult(Ty *A, Ty *B, Ty *C, unsigned R0, unsigned C0,
                           unsigned R1, unsigned C1) {
  for (unsigned i = 0; i < R0; i++)
    for (unsigned j = 0; j < C1; j++)
      for (unsigned c = 0; c < C0; c++)
        C[i + j * R0] += A[i + c * R0] * B[c + j * R1];
}

template <typename EltTy, unsigned R0, unsigned C0, unsigned C1>
static void multiplyBase(EltTy *C, EltTy *A, EltTy *B) {
  for (unsigned i = 0; i < R0; i++)
    for (unsigned j = 0; j < C1; j++)
      for (unsigned c = 0; c < C0; c++) {
        C[i + j * R0] += A[i + c * R0] * B[c + j * C0];
      }
}

template <typename EltTy, unsigned R0, unsigned C0, unsigned C1>
void testMultiply() {
  EltTy X[R0 * C0];
  EltTy Y[C0 * C1];
  EltTy ResBase[R0 * C1];
  EltTy ResSpec[R0 * C1];
  EltTy ResBuiltin[R0 * C1];

  initRandom(X, R0, C0);
  initRandom(Y, C0, C1);
  zeroMatrix(ResBase, R0, C1);
  zeroMatrix(ResSpec, R0, C1);
  zeroMatrix(ResBuiltin, R0, C1);

  multiplyBase<EltTy, R0, C0, C1>(ResBase, X, Y);
  multiplySpec<EltTy, R0, C0, C1>(ResSpec, X, Y);
  multiplyBuiltin<EltTy, R0, C0, C1>(ResBuiltin, X, Y);

  expectMatrixEQ(ResSpec, ResBuiltin, R0, C1);
  expectMatrixEQ(ResBase, ResBuiltin, R0, C1);
  expectMatrixEQ(ResBase, ResSpec, R0, C1);
}

int main(void) {
  testTranspose<double, 3, 3>();
  testTranspose<double, 3, 10>();
  testTranspose<double, 4, 3>();
  testTranspose<float, 31, 17>();
  testTranspose<unsigned, 8, 7>();

  testMultiply<double, 3, 3, 3>();
  testMultiply<double, 10, 21, 23>();
  testMultiply<double, 25, 19, 11>();

  return 0;
}

#else
int main(void) {
  return 0;
}
#endif
