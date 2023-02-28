#include <memory>
#include <random>

#define DEFINE_SCALAR_AND_VECTOR_FN2(Init, Loop)                               \
  auto ScalarFn = [](auto *A, auto *B, unsigned TC) {                          \
    Init _Pragma("clang loop vectorize(disable) interleave_count(1)") Loop     \
  };                                                                           \
  auto VectorFn = [](auto *A, auto *B, unsigned TC) {                          \
    Init _Pragma("clang loop vectorize(enable)") Loop                          \
  };

#define DEFINE_SCALAR_AND_VECTOR_FN3(Loop)                                     \
  auto ScalarFn = [](auto *A, auto *B, auto *C, unsigned TC) {                 \
    _Pragma("clang loop vectorize(disable) interleave_count(1)") Loop          \
  };                                                                           \
  auto VectorFn = [](auto *A, auto *B, auto *C, unsigned TC) {                 \
    _Pragma("clang loop vectorize(enable)") Loop                               \
  };

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
