#include <hip/hip_runtime.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <memory>

#define HIP_CHECK(call)                                                        \
  do {                                                                         \
    hipError_t err = call;                                                     \
    if (err != hipSuccess) {                                                   \
      fprintf(stderr, "HIP error: %s at %s:%d\n", hipGetErrorString(err),      \
              __FILE__, __LINE__);                                             \
      exit(1);                                                                 \
    }                                                                          \
  } while (0)

template <typename T> struct IntRep;
template <> struct IntRep<double> { using type = int64_t; };
template <> struct IntRep<float> { using type = int32_t; };

// Compute ULP distance by reinterpreting same-sign IEEE 754 values as
// integers and taking the absolute difference. This gives the ULP
// distance directly: equal values differ by 0, adjacent values by 1.
// See: https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
template <typename T> static double ulp_distance(T a, T b) {
  double da = static_cast<double>(a), db = static_cast<double>(b);
  if (std::isnan(da) && std::isnan(db))
    return 0.0;
  if (std::isnan(da) || std::isnan(db))
    return INFINITY;
  if (a == b)
    return 0.0;
  using I = typename IntRep<T>::type;
  I ai, bi;
  memcpy(&ai, &a, sizeof(T));
  memcpy(&bi, &b, sizeof(T));
  if ((ai < 0) != (bi < 0))
    return INFINITY;
  int64_t diff = static_cast<int64_t>(ai) - static_cast<int64_t>(bi);
  return static_cast<double>(diff < 0 ? -diff : diff);
}

enum MathFunc { FN_EXP, FN_EXP2, FN_EXP10 };

template <typename T>
__global__ void compute_exp(const T *in, T *out, int n, MathFunc fn) {
  int i = blockIdx.x * blockDim.x + threadIdx.x;
  if (i >= n)
    return;
  switch (fn) {
  case FN_EXP:
    out[i] = exp(in[i]);
    break;
  case FN_EXP2:
    out[i] = exp2(in[i]);
    break;
  case FN_EXP10:
    out[i] = exp10(in[i]);
    break;
  }
}

static double host_exp(double x) { return ::exp(x); }
static double host_exp2(double x) { return ::exp2(x); }
static double host_exp10(double x) { return ::pow(10.0, x); }

template <typename T>
static int test_func(const char *name, MathFunc fn,
                     double (*host_fn)(double), const T *inputs, int n,
                     double max_ulp) {
  size_t sz = n * sizeof(T);
  T *d_in, *d_out;
  HIP_CHECK(hipMalloc(&d_in, sz));
  HIP_CHECK(hipMalloc(&d_out, sz));
  HIP_CHECK(hipMemcpy(d_in, inputs, sz, hipMemcpyHostToDevice));

  int threads = 256;
  int blocks = (n + threads - 1) / threads;
  compute_exp<<<blocks, threads>>>(d_in, d_out, n, fn);
  HIP_CHECK(hipDeviceSynchronize());

  auto h_out = std::make_unique<T[]>(n);
  HIP_CHECK(hipMemcpy(h_out.get(), d_out, sz, hipMemcpyDeviceToHost));

  int errs = 0;
  double worst_ulp = 0.0;
  for (int i = 0; i < n; i++) {
    T expected = static_cast<T>(host_fn(static_cast<double>(inputs[i])));
    double ulp = ulp_distance(h_out[i], expected);
    if (ulp > worst_ulp)
      worst_ulp = ulp;
    if (ulp > max_ulp) {
      if (errs < 10)
        printf("  FAIL %s(%a) = %a, expected %a, ulp = %.0f\n", name,
               (double)inputs[i], (double)h_out[i], (double)expected, ulp);
      errs++;
    }
  }
  printf("  %s: %d/%d passed (worst ulp = %.0f)\n", name, n - errs, n,
         worst_ulp);

  HIP_CHECK(hipFree(d_in));
  HIP_CHECK(hipFree(d_out));
  return errs;
}

template <typename T>
static int test_type(const char *type_name, double max_ulp, double range_lo,
                     double range_hi) {
  T special[] = {
      T(0.0),  T(-0.0), T(1.0),  T(-1.0), T(0.5), T(-0.5), T(1e-5), T(-1e-5),
      std::numeric_limits<T>::infinity(),
      -std::numeric_limits<T>::infinity(),
      std::numeric_limits<T>::quiet_NaN(),
      std::numeric_limits<T>::denorm_min(),
      -std::numeric_limits<T>::denorm_min(),
      std::numeric_limits<T>::min(),
      std::numeric_limits<T>::max(),
  };
  const int N_SPECIAL = sizeof(special) / sizeof(special[0]);

  const int N_RANGE = 2048;
  auto range = std::make_unique<T[]>(N_RANGE);
  for (int i = 0; i < N_RANGE; i++)
    range[i] =
        static_cast<T>(range_lo + (range_hi - range_lo) * i / (N_RANGE - 1));

  const int N_SMALL = 256;
  auto small_vals = std::make_unique<T[]>(N_SMALL);
  for (int i = 0; i < N_SMALL; i++)
    small_vals[i] = static_cast<T>(-1.0 + 2.0 * i / (N_SMALL - 1));

  int total = N_SPECIAL + N_RANGE + N_SMALL;
  auto inputs = std::make_unique<T[]>(total);
  std::copy(special, special + N_SPECIAL, inputs.get());
  std::copy(range.get(), range.get() + N_RANGE, inputs.get() + N_SPECIAL);
  std::copy(small_vals.get(), small_vals.get() + N_SMALL,
            inputs.get() + N_SPECIAL + N_RANGE);

  printf("Testing %s math accuracy (max %.0f ULP, %d values):\n", type_name,
         max_ulp, total);
  int errs = 0;
  errs += test_func("exp", FN_EXP, host_exp, inputs.get(), total, max_ulp);
  errs += test_func("exp2", FN_EXP2, host_exp2, inputs.get(), total, max_ulp);
  errs +=
      test_func("exp10", FN_EXP10, host_exp10, inputs.get(), total, max_ulp);
  return errs;
}

int main() {
  int errs = 0;
  errs += test_type<float>("f32", 1.0, -87.0, 87.0);
  errs += test_type<double>("f64", 1.0, -700.0, 700.0);

  if (errs)
    printf("%d total errors\n", errs);
  else
    printf("PASSED!\n");

  return errs;
}
