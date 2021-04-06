#include <iostream>

#include <hip/hip_runtime.h>

#define N  (1024 * 500)

__global__ void saxpy(float a, float* x, float* y) {
    size_t tid = blockIdx.x * blockDim.x + threadIdx.x;
    if (tid < N) y[tid] = a * x[tid] + y[tid];
}

int main() {

  const float a = 100.0f;
  float* x = (float*)malloc(N * sizeof(float));
  float* y = (float*)malloc(N * sizeof(float));

  // Initialize the input data.
  for (size_t i = 0; i < N; ++i) {
    x[i] = static_cast<float>(i);
    y[i] = static_cast<float>(i * 2);
  }

  // Make a copy for the GPU implementation.
  float* d_x;
  float* d_y;
  hipMalloc((void**)&d_x, N * sizeof(float));
  hipMalloc((void**)&d_y, N * sizeof(float));
  hipMemcpy(d_x, x, N * sizeof(float), hipMemcpyHostToDevice);
  hipMemcpy(d_y, y, N * sizeof(float), hipMemcpyHostToDevice);

  // CPU implementation of saxpy.
  for (int i = 0; i < N; i++) {
    y[i] = a * x[i] + y[i];
  }

  // Launch a GPU kernel to compute the saxpy.
  saxpy<<<(N+255)/256, 256>>>(a, d_x, d_y);

  // Copy the device results to host.
  float* h_y = (float*)malloc(N * sizeof(float));
  hipDeviceSynchronize();
  hipMemcpy(h_y, d_y, N * sizeof(float), hipMemcpyDeviceToHost);

  // Verify the results match CPU.
  int errors = 0;
  for (int i = 0; i < N; i++) {
    if (fabs(y[i] - h_y[i]) > fabs(y[i] * 0.0001f))
      errors++;
  }
  if (errors != 0)
    std::cout << errors << " errors" << std::endl;
  else
    std::cout << "PASSED!" << std::endl;

  free(h_y);
  free(x);
  free(y);
  hipFree(d_x);
  hipFree(d_y);
  return errors;
}
