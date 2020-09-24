__global__ void kernel() {
  // Verify that *Idx/*Dim can be assigned to uint3/dim3.
  uint3 thread_idx = threadIdx;
  uint3 block_idx = blockIdx;
  dim3 block_dim = blockDim;
  dim3 grid_dim = gridDim;

  // And that they can be converted to uint3/dim3
  dim3 thread_idx_dim = threadIdx;
  dim3 block_idx_dim = blockIdx;
  uint3 block_dim_uint = blockDim;
  uint3 grid_dim_uint = gridDim;
}

int main(int argc, char* argv[]) {
  kernel<<<2, 2>>>();
  cudaDeviceSynchronize();
  cudaDeviceReset();
  return 0;
}
