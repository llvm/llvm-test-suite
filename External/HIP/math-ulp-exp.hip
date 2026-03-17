#include <hip/hip_runtime.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

static double ulp_distance(double a, double b) {
  if (std::isnan(a) && std::isnan(b))
    return 0.0;
  if (std::isnan(a) || std::isnan(b))
    return INFINITY;
  if (a == b)
    return 0.0;
  int64_t ai, bi;
  memcpy(&ai, &a, sizeof(double));
  memcpy(&bi, &b, sizeof(double));
  if ((ai < 0) != (bi < 0))
    return INFINITY;
  return (double)llabs(ai - bi);
}

enum MathFunc { FN_EXP, FN_EXP2, FN_EXP10 };

__global__ void compute_exp(const double *in, double *out, int n,
                            MathFunc fn) {
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

static double host_exp10(double x) { return pow(10.0, x); }

static int test_func(const char *name, MathFunc fn,
                     double (*host_fn)(double), const double *inputs, int n,
                     double max_ulp) {
  size_t sz = n * sizeof(double);
  double *d_in, *d_out;
  HIP_CHECK(hipMalloc(&d_in, sz));
  HIP_CHECK(hipMalloc(&d_out, sz));
  HIP_CHECK(hipMemcpy(d_in, inputs, sz, hipMemcpyHostToDevice));

  int threads = 256;
  int blocks = (n + threads - 1) / threads;
  compute_exp<<<blocks, threads>>>(d_in, d_out, n, fn);
  HIP_CHECK(hipDeviceSynchronize());

  auto h_out = std::make_unique<double[]>(n);
  HIP_CHECK(hipMemcpy(h_out.get(), d_out, sz, hipMemcpyDeviceToHost));

  int errs = 0;
  double worst_ulp = 0.0;
  for (int i = 0; i < n; i++) {
    double expected = host_fn(inputs[i]);
    double ulp = ulp_distance(h_out[i], expected);
    if (ulp > worst_ulp)
      worst_ulp = ulp;
    if (ulp > max_ulp) {
      if (errs < 10)
        printf("  FAIL %s(%a) = %a, expected %a, ulp = %.0f\n", name,
               inputs[i], h_out[i], expected, ulp);
      errs++;
    }
  }
  printf("  %s: %d/%d passed (worst ulp = %.0f)\n", name, n - errs, n,
         worst_ulp);

  HIP_CHECK(hipFree(d_in));
  HIP_CHECK(hipFree(d_out));
  return errs;
}

int main() {
  const int N_SPECIAL = 12;
  double special[] = {0.0,  -0.0, 1.0,  -1.0,  0.5,   -0.5,
                      1e-15, -1e-15, 700.0, -700.0, 1e-300, -1e-300};

  const int N_RANGE = 2048;
  double range[N_RANGE];
  for (int i = 0; i < N_RANGE; i++)
    range[i] = -700.0 + 1400.0 * i / (N_RANGE - 1);

  const int N_SMALL = 256;
  double small[N_SMALL];
  for (int i = 0; i < N_SMALL; i++)
    small[i] = -1.0 + 2.0 * i / (N_SMALL - 1);

  int total = N_SPECIAL + N_RANGE + N_SMALL;
  auto inputs = std::make_unique<double[]>(total);
  memcpy(inputs.get(), special, N_SPECIAL * sizeof(double));
  memcpy(inputs.get() + N_SPECIAL, range, N_RANGE * sizeof(double));
  memcpy(inputs.get() + N_SPECIAL + N_RANGE, small, N_SMALL * sizeof(double));

  int errs = 0;
  double max_ulp = 1.0;
  printf("Testing f64 math accuracy (max %.0f ULP):\n", max_ulp);
  errs += test_func("exp", FN_EXP, exp, inputs.get(), total, max_ulp);
  errs += test_func("exp2", FN_EXP2, exp2, inputs.get(), total, max_ulp);
  errs += test_func("exp10", FN_EXP10, host_exp10, inputs.get(), total, max_ulp);

  if (errs)
    printf("%d total errors\n", errs);
  else
    printf("PASSED!\n");

  return errs;
}
