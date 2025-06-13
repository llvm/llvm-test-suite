#include <memory>
#include <random>
#include <type_traits>

#define DEFINE_SCALAR_AND_VECTOR_FN2(Init, Loop)                               \
  auto ScalarFn = [](auto *A, auto *B, unsigned TC) {                          \
    Init _Pragma("clang loop vectorize(disable) interleave_count(1)") Loop     \
  };                                                                           \
  auto VectorFn = [](auto *A, auto *B, unsigned TC) {                          \
    Init _Pragma("clang loop vectorize(enable)") Loop                          \
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

#define DEFINE_SCALAR_AND_VECTOR_FN4(Init, Loop)                               \
  auto ScalarFn = [](auto *cond0, auto *cond1, auto *data0, auto *data1,       \
                     unsigned N, int x) {                                      \
    Init _Pragma("clang loop vectorize(disable)") Loop                         \
  };                                                                           \
  auto VectorFn = [](auto *cond0, auto *cond1, auto *data0, auto *data1,       \
                     unsigned N, int x) {                                      \
    Init _Pragma("clang loop vectorize(enable)") Loop                          \
  };

#define DEFINE_NESTED_SCALAR_AND_VECTOR_FN4(InnerLoopCode)                     \
  auto ScalarFn = [](auto *A, auto *B, unsigned OuterTC, unsigned InnerTC) {   \
    for (unsigned long i = 0; i < OuterTC; i++) {                              \
      _Pragma("clang loop vectorize(disable) interleave_count(1)")             \
      for (unsigned long j = 0; j < InnerTC; j++) {                            \
        InnerLoopCode                                                          \
      }                                                                        \
    }                                                                          \
  };                                                                           \
  auto VectorFn = [](auto *A, auto *B, unsigned OuterTC, unsigned InnerTC) {   \
    for (unsigned long i = 0; i < OuterTC; i++) {                              \
      _Pragma("clang loop vectorize(enable)")                                  \
      for (unsigned long j = 0; j < InnerTC; j++) {                            \
        InnerLoopCode                                                          \
      }                                                                        \
    }                                                                          \
  };

#define DEFINE_NESTED_SCALAR_AND_VECTOR_FN5(InnerLoopCode)                            \
  auto ScalarFn = [](auto *A, auto *B, unsigned OuterTC, unsigned InnerTC) {   \
    for (long i = OuterTC - 1; i >= 0; i--) {                         \
      _Pragma("clang loop vectorize(disable) interleave_count(1)")             \
      for (unsigned long j = 0; j < InnerTC; j++) {                            \
        InnerLoopCode                                                          \
      }                                                                        \
    }                                                                          \
  };                                                                           \
  auto VectorFn = [](auto *A, auto *B, unsigned OuterTC, unsigned InnerTC) {   \
    for (long i = OuterTC - 1; i >= 0; i--) {                         \
      _Pragma("clang loop vectorize(enable)")                                  \
      for (unsigned long j = 0; j < InnerTC; j++) {                            \
        InnerLoopCode                                                          \
      }                                                                        \
    }                                                                          \
  };

static std::mt19937 rng;

// Initialize arrays A with random integers.
template <typename Int,
          std::enable_if_t<std::is_integral<Int>::value, bool> = true>
static void init_data(const std::unique_ptr<Int[]> &A, unsigned N) {
  std::uniform_int_distribution<uint64_t> distrib(
      std::numeric_limits<Int>::min(), std::numeric_limits<Int>::max());
  for (unsigned i = 0; i < N; i++)
    A[i] = distrib(rng);
}

// Initialize arrays A with random floating points.
template <typename Float,
          std::enable_if_t<std::is_floating_point<Float>::value, bool> = true>
static void init_data(const std::unique_ptr<Float[]> &A, unsigned N) {
  std::uniform_real_distribution<float> distrib(
      std::numeric_limits<Float>::min(), std::numeric_limits<Float>::max());
  for (unsigned i = 0; i < N; i++)
    A[i] = distrib(rng);
}

template <typename Ptr,
          std::enable_if_t<std::is_pointer<Ptr>::value, bool> = true>
static void init_data(const std::unique_ptr<Ptr[]> &A, unsigned N) {
  for (unsigned i = 0; i < N; i++)
    A[i] = nullptr;
}

// Initialize arrays A with random booleans.
static void init_cond(const std::unique_ptr<bool[]> &A, unsigned N) {
  std::uniform_int_distribution<uint64_t> distrib(0, 1);
  for (unsigned i = 0; i < N; i++)
    A[i] = !!distrib(rng);
}

template <typename Ty>
static void check(const std::unique_ptr<Ty[]> &Reference,
                  const std::unique_ptr<Ty[]> &Tmp, unsigned NumElements) {
  if (!std::equal(&Reference[0], &Reference[0] + NumElements, &Tmp[0])) {
    std::cerr << "Miscompare\n";
    exit(1);
  }
}

template <typename Ty>
static void check(const Ty Reference, const Ty ToCheck, unsigned NumElements) {
  if (Reference != ToCheck) {
    std::cerr << "Miscompare\n";
    exit(1);
  }
}
