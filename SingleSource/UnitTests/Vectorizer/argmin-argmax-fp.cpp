#include "argmin-argmax-common.h"

// Test using std::fmin for floating point argmin.
#define T_FMIN(Op, M, I, Start, Inc, InitVal, InitIdx, Suf)                    \
  TEST(                                                                        \
      Op, M, I, M Min = InitVal; I MinIdx = InitIdx;                           \
      ,                                                                        \
      for (unsigned i = Start; i < TC; i += Inc) {                             \
        M NewMin = std::fmin(A[i], Min);                                       \
        if (NewMin != Min) {                                                   \
          Min = NewMin;                                                        \
          MinIdx = i;                                                          \
        }                                                                      \
      } return MinIdx;                                                         \
      , Suf)

// Test using std::fmax for floating point argmax.
#define T_FMAX(Op, M, I, Start, Inc, InitVal, InitIdx, Suf)                    \
  TEST(                                                                        \
      Op, M, I, M Max = InitVal; I MaxIdx = InitIdx;                           \
      ,                                                                        \
      for (unsigned i = Start; i < TC; i += Inc) {                             \
        M NewMax = std::fmax(A[i], Max);                                       \
        if (NewMax != Max) {                                                   \
          Max = NewMax;                                                        \
          MaxIdx = i;                                                          \
        }                                                                      \
      } return MaxIdx;                                                         \
      , Suf)

// Test using std::fmin with A[i]+B[i] for floating point argmin.
#define T_FMIN_ADD(Op, M, I, Start, Inc, InitVal, InitIdx, Suf)                \
  TEST(                                                                        \
      Op, M, I, M Min = InitVal; I MinIdx = InitIdx;                           \
      ,                                                                        \
      for (unsigned i = Start; i < TC; i += Inc) {                             \
        M D = A[i] + B[i];                                                     \
        M NewMin = std::fmin(D, Min);                                          \
        if (NewMin != Min) {                                                   \
          Min = NewMin;                                                        \
          MinIdx = i;                                                          \
        }                                                                      \
      } return MinIdx;                                                         \
      , Suf)

// Test using std::fmax with A[i]+B[i] for floating point argmax.
#define T_FMAX_ADD(Op, M, I, Start, Inc, InitVal, InitIdx, Suf)                \
  TEST(                                                                        \
      Op, M, I, M Max = InitVal; I MaxIdx = InitIdx;                           \
      ,                                                                        \
      for (unsigned i = Start; i < TC; i += Inc) {                             \
        M D = A[i] + B[i];                                                     \
        M NewMax = std::fmax(D, Max);                                          \
        if (NewMax != Max) {                                                   \
          Max = NewMax;                                                        \
          MaxIdx = i;                                                          \
        }                                                                      \
      } return MaxIdx;                                                         \
      , Suf)

// Test using fminimum for floating point argmin.
#define T_FMINIMUM(Op, M, I, Start, Inc, InitVal, InitIdx, Suf)                \
  TEST(                                                                        \
      Op, M, I, M Min = InitVal; I MinIdx = InitIdx;                           \
      ,                                                                        \
      for (unsigned i = Start; i < TC; i += Inc) {                             \
        M NewMin = fminimum(A[i], Min);                                        \
        if (NewMin != Min) {                                                   \
          Min = NewMin;                                                        \
          MinIdx = i;                                                          \
        }                                                                      \
      } return MinIdx;                                                         \
      , Suf)

// Test using fmaximum for floating point argmax.
#define T_FMAXIMUM(Op, M, I, Start, Inc, InitVal, InitIdx, Suf)                \
  TEST(                                                                        \
      Op, M, I, M Max = InitVal; I MaxIdx = InitIdx;                           \
      ,                                                                        \
      for (unsigned i = Start; i < TC; i += Inc) {                             \
        M NewMax = fmaximum(A[i], Max);                                        \
        if (NewMax != Max) {                                                   \
          Max = NewMax;                                                        \
          MaxIdx = i;                                                          \
        }                                                                      \
      } return MaxIdx;                                                         \
      , Suf)

// Test using fminimum_num for floating point argmin.
#define T_FMINIMUMNUM(Op, M, I, Start, Inc, InitVal, InitIdx, Suf)             \
  TEST(                                                                        \
      Op, M, I, M Min = InitVal; I MinIdx = InitIdx;                           \
      ,                                                                        \
      for (unsigned i = Start; i < TC; i += Inc) {                             \
        M NewMin = fminimum_num(A[i], Min);                                    \
        if (NewMin != Min) {                                                   \
          Min = NewMin;                                                        \
          MinIdx = i;                                                          \
        }                                                                      \
      } return MinIdx;                                                         \
      , Suf)

// Test using fmaximum_num for floating point argmax.
#define T_FMAXIMUMNUM(Op, M, I, Start, Inc, InitVal, InitIdx, Suf)             \
  TEST(                                                                        \
      Op, M, I, M Max = InitVal; I MaxIdx = InitIdx;                           \
      ,                                                                        \
      for (unsigned i = Start; i < TC; i += Inc) {                             \
        M NewMax = fmaximum_num(A[i], Max);                                    \
        if (NewMax != Max) {                                                   \
          Max = NewMax;                                                        \
          MaxIdx = i;                                                          \
        }                                                                      \
      } return MaxIdx;                                                         \
      , Suf)

// Run tests using std::fmin/std::fmax for floating point types.
#define RUN_FMIN_FMAX_TESTS_FOR_TYPE(M, I)                                     \
  T_FMIN("min", M, I, 0, 1, std::numeric_limits<M>::max(), 0, "_fmin_start_0") \
  T_FMIN("min", M, I, 0, 1, std::numeric_limits<M>::infinity(), 0,             \
         "_fmin_start_inf")                                                    \
  T_FMIN("min", M, I, 0, 1, std::numeric_limits<M>::quiet_NaN(), 0,            \
         "_fmin_start_nan")                                                    \
  T_FMIN("min", M, I, 0, 1, M(-0.0), 0, "_fmin_start_neg_zero")                \
  T_FMIN("min", M, I, 0, 1, M(0.0), 0, "_fmin_start_pos_zero")                 \
  T_FMIN("min", M, I, 0, 2, std::numeric_limits<M>::max(), 0,                  \
         "_fmin_start_0_inc_2")                                                \
  T_FMIN("min", M, I, 3, 1, std::numeric_limits<M>::max(), 3, "_fmin_start_3") \
  T_FMIN_ADD("min", M, I, 0, 1, std::numeric_limits<M>::max(), 0,              \
             "_fmin_add_start_0")                                              \
  T_FMIN_ADD("min", M, I, 0, 2, std::numeric_limits<M>::max(), 0,              \
             "_fmin_add_start_0_inc_2")                                        \
  T_FMAX("max", M, I, 0, 1, std::numeric_limits<M>::lowest(), 0,               \
         "_fmax_start_0")                                                      \
  T_FMAX("max", M, I, 0, 1, -std::numeric_limits<M>::infinity(), 0,            \
         "_fmax_start_neg_inf")                                                \
  T_FMAX("max", M, I, 0, 1, std::numeric_limits<M>::quiet_NaN(), 0,            \
         "_fmax_start_nan")                                                    \
  T_FMAX("max", M, I, 0, 1, M(-0.0), 0, "_fmax_start_neg_zero")                \
  T_FMAX("max", M, I, 0, 1, M(0.0), 0, "_fmax_start_pos_zero")                 \
  T_FMAX("max", M, I, 0, 2, std::numeric_limits<M>::lowest(), 0,               \
         "_fmax_start_0_inc_2")                                                \
  T_FMAX("max", M, I, 3, 1, std::numeric_limits<M>::lowest(), 3,               \
         "_fmax_start_3")                                                      \
  T_FMAX_ADD("max", M, I, 0, 1, std::numeric_limits<M>::lowest(), 0,           \
             "_fmax_add_start_0")                                              \
  T_FMAX_ADD("max", M, I, 0, 2, std::numeric_limits<M>::lowest(), 0,           \
             "_fmax_add_start_0_inc_2")                                        \
  T_FMINIMUM("minimum", M, I, 0, 1, std::numeric_limits<M>::max(), 0,          \
             "_fminimum_start_0")                                              \
  T_FMINIMUM("minimum", M, I, 0, 1, std::numeric_limits<M>::infinity(), 0,     \
             "_fminimum_start_inf")                                            \
  T_FMINIMUM("minimum", M, I, 0, 1, M(-0.0), 0, "_fminimum_start_neg_zero")    \
  T_FMINIMUM("minimum", M, I, 0, 1, M(0.0), 0, "_fminimum_start_pos_zero")     \
  T_FMINIMUM("minimum", M, I, 0, 2, std::numeric_limits<M>::max(), 0,          \
             "_fminimum_start_0_inc_2")                                        \
  T_FMINIMUM("minimum", M, I, 3, 1, std::numeric_limits<M>::max(), 3,          \
             "_fminimum_start_3")                                              \
  T_FMAXIMUM("maximum", M, I, 0, 1, std::numeric_limits<M>::lowest(), 0,       \
             "_fmaximum_start_0")                                              \
  T_FMAXIMUM("maximum", M, I, 0, 1, -std::numeric_limits<M>::infinity(), 0,    \
             "_fmaximum_start_neg_inf")                                        \
  T_FMAXIMUM("maximum", M, I, 0, 1, M(-0.0), 0, "_fmaximum_start_neg_zero")    \
  T_FMAXIMUM("maximum", M, I, 0, 1, M(0.0), 0, "_fmaximum_start_pos_zero")     \
  T_FMAXIMUM("maximum", M, I, 0, 2, std::numeric_limits<M>::lowest(), 0,       \
             "_fmaximum_start_0_inc_2")                                        \
  T_FMAXIMUM("maximum", M, I, 3, 1, std::numeric_limits<M>::lowest(), 3,       \
             "_fmaximum_start_3")                                              \
  T_FMINIMUMNUM("minimumnum", M, I, 0, 1, std::numeric_limits<M>::max(), 0,    \
                "_fminimumnum_start_0")                                        \
  T_FMINIMUMNUM("minimumnum", M, I, 0, 1, std::numeric_limits<M>::infinity(),  \
                0, "_fminimumnum_start_inf")                                   \
  T_FMINIMUMNUM("minimumnum", M, I, 0, 1, std::numeric_limits<M>::quiet_NaN(), \
                0, "_fminimumnum_start_nan")                                   \
  T_FMINIMUMNUM("minimumnum", M, I, 0, 1, M(-0.0), 0,                          \
                "_fminimumnum_start_neg_zero")                                 \
  T_FMINIMUMNUM("minimumnum", M, I, 0, 1, M(0.0), 0,                           \
                "_fminimumnum_start_pos_zero")                                 \
  T_FMINIMUMNUM("minimumnum", M, I, 0, 2, std::numeric_limits<M>::max(), 0,    \
                "_fminimumnum_start_0_inc_2")                                  \
  T_FMINIMUMNUM("minimumnum", M, I, 3, 1, std::numeric_limits<M>::max(), 3,    \
                "_fminimumnum_start_3")                                        \
  T_FMAXIMUMNUM("maximumnum", M, I, 0, 1, std::numeric_limits<M>::lowest(), 0, \
                "_fmaximumnum_start_0")                                        \
  T_FMAXIMUMNUM("maximumnum", M, I, 0, 1, -std::numeric_limits<M>::infinity(), \
                0, "_fmaximumnum_start_neg_inf")                               \
  T_FMAXIMUMNUM("maximumnum", M, I, 0, 1, std::numeric_limits<M>::quiet_NaN(), \
                0, "_fmaximumnum_start_nan")                                   \
  T_FMAXIMUMNUM("maximumnum", M, I, 0, 1, M(-0.0), 0,                          \
                "_fmaximumnum_start_neg_zero")                                 \
  T_FMAXIMUMNUM("maximumnum", M, I, 0, 1, M(0.0), 0,                           \
                "_fmaximumnum_start_pos_zero")                                 \
  T_FMAXIMUMNUM("maximumnum", M, I, 0, 2, std::numeric_limits<M>::lowest(), 0, \
                "_fmaximumnum_start_0_inc_2")                                  \
  T_FMAXIMUMNUM("maximumnum", M, I, 3, 1, std::numeric_limits<M>::lowest(), 3, \
                "_fmaximumnum_start_3")

int main(void) {
  rng = std::mt19937(15);

  // Run tests for float types
  RUN_ALL_TESTS_FOR_TYPE(float, uint32_t)
  RUN_PRED_TESTS_FOR_TYPE(float, uint32_t)
  RUN_VF_IC_TESTS_FOR_TYPE(float, uint32_t)
  RUN_FMIN_FMAX_TESTS_FOR_TYPE(float, uint32_t)

  RUN_ALL_TESTS_FOR_TYPE(float, int32_t)
  RUN_PRED_TESTS_FOR_TYPE(float, int32_t)
  RUN_FMIN_FMAX_TESTS_FOR_TYPE(float, int32_t)

  // Run tests for double types
  RUN_ALL_TESTS_FOR_TYPE(double, uint64_t)
  RUN_PRED_TESTS_FOR_TYPE(double, uint64_t)
  RUN_VF_IC_TESTS_FOR_TYPE(double, uint64_t)
  RUN_FMIN_FMAX_TESTS_FOR_TYPE(double, uint64_t)

  RUN_ALL_TESTS_FOR_TYPE(double, int64_t)
  RUN_PRED_TESTS_FOR_TYPE(double, int64_t)
  RUN_FMIN_FMAX_TESTS_FOR_TYPE(double, int64_t)

  RUN_ALL_TESTS_FOR_TYPE(double, uint32_t)
  RUN_PRED_TESTS_FOR_TYPE(double, uint32_t)
  RUN_FMIN_FMAX_TESTS_FOR_TYPE(double, uint32_t)

  RUN_ALL_TESTS_FOR_TYPE(double, int32_t)
  RUN_PRED_TESTS_FOR_TYPE(double, int32_t)
  RUN_FMIN_FMAX_TESTS_FOR_TYPE(double, int32_t)

  return 0;
}
