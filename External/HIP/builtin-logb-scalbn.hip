#include <hip/hip_runtime.h>
#include <cmath>
#include <cstdio>
#include <iostream>

// Simple error check macro
#define HIP_CHECK(call)                                                         \
    do {                                                                        \
        hipError_t err = call;                                                  \
        if (err != hipSuccess) {                                                \
            std::cerr << "HIP error: " << hipGetErrorString(err)               \
                      << " at " << __FILE__ << ":" << __LINE__ << std::endl;    \
            std::exit(EXIT_FAILURE);                                            \
        }                                                                       \
    } while (0)

__global__ void my_kernel(float a[], int alen, int exp[], int explen, float *t_res) {
  for (int i = 0; i < alen; i++) {
    t_res[4*i] = logbf(a[i]);
    t_res[4*i + 1] = logb(a[i]);
    t_res[4*i + 2] = __builtin_logbf(a[i]);
    t_res[4*i + 3] = __builtin_logb(a[i]);
  }

  for (int i = 0; i < alen; i++) {
    for (int j = 0; j < explen; j++) {
      t_res[4*alen + explen*i + 4*j] = scalbnf(a[i], exp[j]);
      t_res[4*alen + explen*i + 4*j + 1] = scalbn(a[i], exp[j]);
      t_res[4*alen + explen*i + 4*j + 2] = __builtin_scalbnf(a[i], exp[j]);
      t_res[4*alen + explen*i + 4*j + 3] = __builtin_scalbn(a[i], exp[j]);
    }
  }
}

void __attribute__((noinline)) test(float a[], int alen, int exp[], int explen, float *h_res) {
  for (int i = 0; i < alen; i++) {
    h_res[4*i] = logbf(a[i]);
    h_res[4*i + 1] = logb(a[i]);
    h_res[4*i + 2] = __builtin_logbf(a[i]);
    h_res[4*i + 3] = __builtin_logb(a[i]);
  }

  for (int i = 0; i < alen; i++) {
    for (int j = 0; j < explen; j++) {
      h_res[4*alen + explen*i + 4*j] = scalbnf(a[i], exp[j]);
      h_res[4*alen + explen*i + 4*j + 1] = scalbn(a[i], exp[j]);
      h_res[4*alen + explen*i + 4*j + 2] = __builtin_scalbnf(a[i], exp[j]);
      h_res[4*alen + explen*i + 4*j + 3] = __builtin_scalbn(a[i], exp[j]);
    }
  }
}

int main(int argc, char **argv) {
  // Init input data
  float a[] = {16.0f, 3.14f, 0.0f, -0.0f, INFINITY, NAN};
  int alen = sizeof(a) / sizeof(a[0]);
  int exp[] = {10, 0, -5};
  int explen = sizeof(exp) / sizeof(exp[0]);

  // Compute on CPU
  int res_len = 4 * alen + 4 * alen * explen; // logb + scalbn
  int res_bsize = sizeof(float) * res_len;
  float *h_res = (float *)malloc(res_bsize);
  test(a, alen, exp, explen, h_res);

  // Make a copy for GPU
  float *d_a;
  int *d_exp;
  float *t_res;
  HIP_CHECK(hipMalloc((void**)&d_a, sizeof(a)));
  HIP_CHECK(hipMalloc((void**)&d_exp, sizeof(exp)));
  HIP_CHECK(hipMalloc((void**)&t_res, res_bsize));
  HIP_CHECK(hipMemcpy(d_a, a, sizeof(a), hipMemcpyHostToDevice));
  HIP_CHECK(hipMemcpy(d_exp, exp, sizeof(exp), hipMemcpyHostToDevice));
  HIP_CHECK(hipMemset(t_res, 0, res_bsize));

  // Launch a GPU kernel
  my_kernel<<<1,1>>>(d_a, alen, d_exp, explen, t_res);

  // Copy the device results to host
  float *d_res = (float *)malloc(res_bsize);
  HIP_CHECK(hipDeviceSynchronize());
  HIP_CHECK(hipMemcpy(d_res, t_res, res_bsize, hipMemcpyDeviceToHost));

  // Verify the results match CPU.
  int errs = 0;
  for(int i = 0; i < res_len; i++) {
    if (fabs(h_res[i] - d_res[i]) > fabs(h_res[i] * 0.0001f)) {
      //printf("found error i=%i h=%f d=%f\n", i, h_res[i], d_res[i]);
      errs++;
    }
  }
  if (errs != 0)
    printf("%i errors\n", errs);
  else
    printf("PASSED!\n");

  free(h_res);
  HIP_CHECK(hipFree(d_a));
  HIP_CHECK(hipFree(d_exp));
  HIP_CHECK(hipFree(t_res));
  free(d_res);
  return errs;
}

