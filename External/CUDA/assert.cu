#include <assert.h>
#include <stdio.h>

// Use fixed value for __FILE__ so assert message does not depend on
// the actual path to the file during compilation..
#define __FILE__ "assert.cu"

__global__ void kernel() {
  // Our reference output contains the line number of this assert() call; be
  // careful when modifying the parts of this file above this line.
  assert(false);
}

int main() {
  kernel<<<1,1>>>();
  cudaError_t err = cudaDeviceSynchronize();
  if (err != cudaErrorAssert)
    return err;
  return 0;
}
