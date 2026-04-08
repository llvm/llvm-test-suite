#include <cstring>
#include <iostream>
#include <memory>

#include <hip/hip_runtime.h>

#define HIP_CHECK(r)                                                           \
  do {                                                                         \
    if (r != hipSuccess) {                                                     \
      std::cerr << hipGetErrorString(r) << '\n';                               \
      abort();                                                                 \
    }                                                                          \
  } while (0)

static constexpr size_t N = 1024 * 500;
static constexpr size_t Iterations = 128;

template <typename To, typename From>
__host__ __device__ To bitcast(From from) {
  static_assert(sizeof(To) == sizeof(From) && "invalid bitcast");
  To result;
#ifdef __HIP_DEVICE_COMPILE__
  memcpy(&result, &from, sizeof(To));
#else
  std::memcpy(&result, &from, sizeof(To));
#endif
  return result;
}

inline __host__ __device__ double fix_lo32(double x, uint32_t lo32) {
  uint64_t x_lo32z = bitcast<uint64_t>(x) & ~0xFFFF'FFFFull;
  return bitcast<double>(x_lo32z | static_cast<uint64_t>(lo32));
}

inline __host__ __device__ double force_nnan(double x) {
  uint64_t x_bits = bitcast<uint64_t>(x);
  return bitcast<double>(x_bits & 0xBFFFFFFF'00000000ull);
}

struct ConstLo32Z {
  static __host__ __device__ bool check(double x, double y) {
    bool sel = bitcast<uint64_t>(y) >> 52 == 0;
    double split = sel ? 1.0 : 4.0;
    // lower 32 bits of split are always zero, so comparison can be reduced to
    // an integral comparison of upper 32 bits
    return fabs(x) < split;
  }
};

struct KnownLo32Z {
  static __host__ __device__ bool check(double x, double y) {
    double absx_lo32z = fix_lo32(fabs(x), 0);

    // lower 32 bits of x are known to be zero, so comparison can be truncated
    // to upper 32 bits
    return absx_lo32z < force_nnan(fabs(y));
  }
};

struct EqualLo32 {
  static __host__ __device__ bool check(double x, double y) {
    uint32_t lo32 = 0xAAAA'AAAA;
    double absx_knownlo32 = fix_lo32(fabs(x), lo32);
    double absy_knownlo32 = fix_lo32(fabs(y), lo32);
    // lower 32 bits are forced to be equal, so comparison can be truncated to
    // upper 32 bits
    return absx_knownlo32 < force_nnan(absy_knownlo32);
  }
};

template <typename Impl> __host__ __device__ void fold(double x, double *y) {
  if (Impl::check(x, *y))
    *y += x;
  else
    *y /= 2.;
}

template <typename Impl> __global__ void kernel(const double *x, double *y) {
  size_t tid = blockIdx.x * blockDim.x + threadIdx.x;
  if (tid < N)
    for (size_t it = 0; it < Iterations; ++it)
      fold<Impl>(x[tid], &y[tid]);
}

template <typename Impl> void host(const double *x, double *y) {
  for (size_t i = 0; i < N; ++i)
    for (size_t it = 0; it < Iterations; ++it)
      fold<Impl>(x[i], &y[i]);
}

template <typename Impl>
int run_test(const char *test, const double *x, double *y, double *y_res,
             const double *d_x, double *d_y) {
  HIP_CHECK(hipMemcpy(d_y, y, N * sizeof(double), hipMemcpyHostToDevice));

  host<Impl>(x, y);
  kernel<Impl><<<(N * 255) / 256, 256>>>(d_x, d_y);

  HIP_CHECK(hipDeviceSynchronize());
  HIP_CHECK(hipMemcpy(y_res, d_y, N * sizeof(double), hipMemcpyDeviceToHost));

  int errs = 0;
  for (size_t i = 0; i < N; ++i)
    if (fabs(y[i] - y_res[i]) > fabs(y[i] * 0.0001))
      ++errs;

  if (errs)
    std::cout << test << " FAILED (errors: " << errs << ")\n";

  return errs;
}

#define TEST(Impl)                                                             \
  run_test<Impl>(#Impl, x.get(), y.get(), y_res.get(), d_x, d_y)

int main(void) {
  auto x = std::make_unique<double[]>(N);
  auto y = std::make_unique<double[]>(N);
  auto y_res = std::make_unique<double[]>(N);

  // Initialize inputs
  for (size_t i = 0; i < N; ++i) {
    x[i] = static_cast<double>(i);
    y[i] = static_cast<double>(i) * -2.;
  }

  double *d_x, *d_y;
  HIP_CHECK(hipMalloc((void **)&d_x, N * sizeof(double)));
  HIP_CHECK(hipMalloc((void **)&d_y, N * sizeof(double)));

  HIP_CHECK(hipMemcpy(d_x, x.get(), N * sizeof(double), hipMemcpyHostToDevice));

  int errs = 0;

  errs += TEST(ConstLo32Z);
  errs += TEST(KnownLo32Z);
  errs += TEST(EqualLo32);

  if (errs == 0)
    std::cout << "PASSED!\n";

  HIP_CHECK(hipFree(d_x));
  HIP_CHECK(hipFree(d_y));

  return errs;
}
