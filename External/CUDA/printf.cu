__global__ void kernel(char a, short b, int c, float d, double e) {
  const char* f = "abcdefg";
  printf("kernel_printf %c %d %d %f %f %s\n", a, b, c, d, e, f);
}

int main(int argc, char* argv[]) {
  kernel<<<2, 8>>>('a', 2, 3, 4, 5);
  cudaDeviceSynchronize();
  cudaDeviceReset();
  return 0;
}
