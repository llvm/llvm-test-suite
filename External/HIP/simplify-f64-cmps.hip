#include <iostream>

#include <hip/hip_runtime.h>

#define HIP_CHECK(r)                                                           \
  do {                                                                         \
    if (r != hipSuccess) {                                                     \
      std::cerr << hipGetErrorString(r) << '\n';                               \
      abort();                                                                 \
    }                                                                          \
  } while (0)

static constexpr size_t N = 1024 * 500;
static constexpr size_t Iterations = 4096;

__host__ __device__ void fold(uint8_t sel, double x, double *y) {
  double split = sel ? 1.0 : 4.0;
  double abs_y = fabs(*y);

  // lower 32 bits of split are always zero, so comparison can be reduced to an
  // integral comparison of upper 32 bits
  if (abs_y < split) {
    *y += x;
  } else {
    *y /= 2.;
  }
}

__global__ void f64_cmp_chain(const uint8_t *sel, const double *x, double *y) {
  size_t tid = blockIdx.x * blockDim.x + threadIdx.x;
  if (tid < N) {
    for (size_t it = 0; it < Iterations; ++it)
      fold(sel[tid], x[tid], &y[tid]);
  }
}

void f64_cmp_chain_host(const uint8_t *sel, const double *x, double *y) {
  for (size_t i = 0; i < N; ++i)
    for (size_t it = 0; it < Iterations; ++it)
      fold(sel[i], x[i], &y[i]);
}

int main(void) {
  uint8_t *sel = (uint8_t *)malloc(N * sizeof(uint8_t));
  double *x = (double *)malloc(N * sizeof(double));
  double *y = (double *)malloc(N * sizeof(double));

  // Initialize inputs
  for (size_t i = 0; i < N; ++i) {
    sel[i] = i & 8;
    x[i] = static_cast<double>(i);
    y[i] = static_cast<double>(i) * -2.;
  }

  uint8_t *d_sel;
  double *d_x;
  double *d_y;
  HIP_CHECK(hipMalloc((void **)&d_sel, N * sizeof(uint8_t)));
  HIP_CHECK(hipMemcpy(d_sel, sel, N * sizeof(uint8_t), hipMemcpyHostToDevice));
  HIP_CHECK(hipMalloc((void **)&d_x, N * sizeof(double)));
  HIP_CHECK(hipMemcpy(d_x, x, N * sizeof(double), hipMemcpyHostToDevice));
  HIP_CHECK(hipMalloc((void **)&d_y, N * sizeof(double)));
  HIP_CHECK(hipMemcpy(d_y, y, N * sizeof(double), hipMemcpyHostToDevice));

  // CPU implementation
  f64_cmp_chain_host(sel, x, y);

  // GPU implementation
  f64_cmp_chain<<<(N + 255) / 256, 256>>>(d_sel, d_x, d_y);

  // Copy GPU result
  double *h_y = (double *)malloc(N * sizeof(double));
  HIP_CHECK(hipDeviceSynchronize());
  HIP_CHECK(hipMemcpy(h_y, d_y, N * sizeof(double), hipMemcpyDeviceToHost));

  // Verify results
  int errs = 0;
  for (size_t i = 0; i < N; ++i)
    if (fabs(y[i] - h_y[i]) > fabs(y[i] * 0.0001))
      ++errs;

  if (errs != 0)
    std::cout << "FAILED (errors: " << errs << ")\n";
  else
    std::cout << "PASSED!\n";

  free(sel);
  free(x);
  free(y);
  free(h_y);
  HIP_CHECK(hipFree(d_sel));
  HIP_CHECK(hipFree(d_x));
  HIP_CHECK(hipFree(d_y));

  return errs;
}
