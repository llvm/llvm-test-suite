// Example testcase that illustrates testing with
// outputs that differ depending on the compile options.

#include <hip/hip_runtime.h>
#include <cstdio>

int main() {
  printf("%s\n",MSG);
  return 0;
}
