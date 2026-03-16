#include <hip/hip_runtime.h>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define HIP_CHECK(call)                                                        \
  do {                                                                         \
    hipError_t err = call;                                                     \
    if (err != hipSuccess) {                                                   \
      fprintf(stderr, "HIP error: %s at %s:%d\n", hipGetErrorString(err),      \
              __FILE__, __LINE__);                                             \
      exit(1);                                                                 \
    }                                                                          \
  } while (0)

static uint64_t ulp_distance(double a, double b) {
  if (std::isnan(a) && std::isnan(b))
    return 0;
  if (std::isnan(a) || std::isnan(b))
    return UINT64_MAX;
  if (a == b)
    return 0;
  int64_t ai, bi;
  memcpy(&ai, &a, sizeof(double));
  memcpy(&bi, &b, sizeof(double));
  if ((ai < 0) != (bi < 0))
    return UINT64_MAX;
  return (uint64_t)llabs(ai - bi);
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
                     int max_ulp) {
  size_t sz = n * sizeof(double);
  double *d_in, *d_out;
  HIP_CHECK(hipMalloc(&d_in, sz));
  HIP_CHECK(hipMalloc(&d_out, sz));
  HIP_CHECK(hipMemcpy(d_in, inputs, sz, hipMemcpyHostToDevice));

  int threads = 256;
  int blocks = (n + threads - 1) / threads;
  compute_exp<<<blocks, threads>>>(d_in, d_out, n, fn);
  HIP_CHECK(hipDeviceSynchronize());

  double *h_out = (double *)malloc(sz);
  HIP_CHECK(hipMemcpy(h_out, d_out, sz, hipMemcpyDeviceToHost));

  int errs = 0;
  uint64_t worst_ulp = 0;
  for (int i = 0; i < n; i++) {
    double expected = host_fn(inputs[i]);
    uint64_t ulp = ulp_distance(h_out[i], expected);
    if (ulp > worst_ulp)
      worst_ulp = ulp;
    if (ulp > (uint64_t)max_ulp) {
      if (errs < 10)
        printf("  FAIL %s(%a) = %a, expected %a, ulp = %llu\n", name,
               inputs[i], h_out[i], expected, (unsigned long long)ulp);
      errs++;
    }
  }
  printf("  %s: %d/%d passed (worst ulp = %llu)\n", name, n - errs, n,
         (unsigned long long)worst_ulp);

  free(h_out);
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
  double *inputs = (double *)malloc(total * sizeof(double));
  memcpy(inputs, special, N_SPECIAL * sizeof(double));
  memcpy(inputs + N_SPECIAL, range, N_RANGE * sizeof(double));
  memcpy(inputs + N_SPECIAL + N_RANGE, small, N_SMALL * sizeof(double));

  int errs = 0;
  int max_ulp = 1;
  printf("Testing f64 math accuracy (max %d ULP):\n", max_ulp);
  errs += test_func("exp", FN_EXP, exp, inputs, total, max_ulp);
  errs += test_func("exp2", FN_EXP2, exp2, inputs, total, max_ulp);
  errs += test_func("exp10", FN_EXP10, host_exp10, inputs, total, max_ulp);

  if (errs)
    printf("%d total errors\n", errs);
  else
    printf("PASSED!\n");

  free(inputs);
  return errs;
}
