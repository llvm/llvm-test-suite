#include <memory>
#include <random>

// Helper macros for stringification in _Pragma
#define XSTR(s) STR(s)
#define STR(s) #s
#define PRAGMA_VF(VF) _Pragma(STR(clang loop vectorize_width(VF)))
#define PRAGMA_IC(IC) _Pragma(STR(clang loop interleave_count(IC)))

#define DEFINE_SCALAR_AND_VECTOR_FN1_TYPE(Init, Loop, Type)                    \
  auto ScalarFn = [](auto *A, Type TC) -> Type {                               \
    Init _Pragma("clang loop vectorize(disable) interleave_count(1)") Loop     \
  };                                                                           \
  auto VectorFn = [](auto *A, Type TC) -> Type {                               \
    Init _Pragma("clang loop vectorize(enable)") Loop                          \
  };

#define DEFINE_SCALAR_AND_VECTOR_FN2(Init, Loop)                               \
  auto ScalarFn = [](auto *A, auto *B, unsigned TC) {                          \
    Init _Pragma("clang loop vectorize(disable) interleave_count(1)") Loop     \
  };                                                                           \
  auto VectorFn = [](auto *A, auto *B, unsigned TC) {                          \
    Init _Pragma("clang loop vectorize(enable)") Loop                          \
  };

// Macro with explicit VF and interleave count control
#define DEFINE_SCALAR_AND_VECTOR_FN2_VF_INTERLEAVE(Init, Loop, VF, IC)         \
  auto ScalarFn = [](auto *A, auto *B, unsigned TC) {                          \
    Init _Pragma("clang loop vectorize(disable) interleave_count(1)") Loop     \
  };                                                                           \
  auto VectorFn = [](auto *A, auto *B, unsigned TC) {                          \
    Init PRAGMA_VF(VF) PRAGMA_IC(IC) Loop                                      \
  };

#define DEFINE_SCALAR_AND_VECTOR_FN2_TYPE(Init, Loop, Type)                    \
  auto ScalarFn = [](auto *A, auto *B, Type TC) -> Type {                      \
    Init _Pragma("clang loop vectorize(disable) interleave_count(1)") Loop     \
  };                                                                           \
  auto VectorFn = [](auto *A, auto *B, Type TC) -> Type {                      \
    Init _Pragma("clang loop vectorize(enable)") Loop                          \
  };

#define DEFINE_SCALAR_AND_VECTOR_FN3(Loop)                                     \
  auto ScalarFn = [](auto *A, auto *B, auto *C, unsigned TC) {                 \
    _Pragma("clang loop vectorize(disable) interleave_count(1)") Loop          \
  };                                                                           \
  auto VectorFn = [](auto *A, auto *B, auto *C, unsigned TC) {                 \
    _Pragma("clang loop vectorize(enable)") Loop                               \
  };

#define DEFINE_NESTED_SCALAR_AND_VECTOR_FN4(InnerLoopCode)                     \
  auto ScalarFn = [](auto *A, auto *B, unsigned OuterTC, unsigned InnerTC) {   \
    for (unsigned long i = 0; i < OuterTC; i++) {                              \
      _Pragma("clang loop vectorize(disable) interleave_count(1)") for (       \
          unsigned long j = 0; j < InnerTC; j++) {                             \
        InnerLoopCode                                                          \
      }                                                                        \
    }                                                                          \
  };                                                                           \
  auto VectorFn = [](auto *A, auto *B, unsigned OuterTC, unsigned InnerTC) {   \
    for (unsigned long i = 0; i < OuterTC; i++) {                              \
      _Pragma("clang loop vectorize(enable)") for (unsigned long j = 0;        \
                                                   j < InnerTC; j++) {         \
        InnerLoopCode                                                          \
      }                                                                        \
    }                                                                          \
  };

#define DEFINE_NESTED_SCALAR_AND_VECTOR_FN5(InnerLoopCode)                     \
  auto ScalarFn = [](auto *A, auto *B, unsigned OuterTC, unsigned InnerTC) {   \
    for (long i = OuterTC - 1; i >= 0; i--) {                                  \
      _Pragma("clang loop vectorize(disable) interleave_count(1)") for (       \
          unsigned long j = 0; j < InnerTC; j++) {                             \
        InnerLoopCode                                                          \
      }                                                                        \
    }                                                                          \
  };                                                                           \
  auto VectorFn = [](auto *A, auto *B, unsigned OuterTC, unsigned InnerTC) {   \
    for (long i = OuterTC - 1; i >= 0; i--) {                                  \
      _Pragma("clang loop vectorize(enable)") for (unsigned long j = 0;        \
                                                   j < InnerTC; j++) {         \
        InnerLoopCode                                                          \
      }                                                                        \
    }                                                                          \
  };

static std::mt19937 rng;

// Initialize arrays A with random numbers.
template <typename Ty>
static void init_data(const std::unique_ptr<Ty[]> &A, unsigned N) {
  if constexpr (std::is_floating_point_v<Ty>) {
    std::uniform_real_distribution<Ty> distrib(
        std::numeric_limits<Ty>::min(), std::numeric_limits<Ty>::max());
    for (unsigned i = 0; i < N; i++)
      A[i] = distrib(rng);
  } else {
    std::uniform_int_distribution<Ty> distrib(
        std::numeric_limits<Ty>::min(), std::numeric_limits<Ty>::max());
    for (unsigned i = 0; i < N; i++)
      A[i] = distrib(rng);
  }
}

template <typename Ty>
static void check(const std::unique_ptr<Ty[]> &Reference,
                  const std::unique_ptr<Ty[]> &Tmp, unsigned NumElements) {
  if (!std::equal(&Reference[0], &Reference[0] + NumElements, &Tmp[0])) {
    std::cerr << "Miscompare\n";
    exit(1);
  }
}
