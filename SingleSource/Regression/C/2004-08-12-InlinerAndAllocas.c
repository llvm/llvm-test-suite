// A compiler cannot inline Callee into main unless it is prepared to reclaim
// the stack memory allocated in it.

#include <alloca.h>
#include <stdio.h>

static int Callee(int i) {
  if (i != 0) {
    char *X = alloca(1000);
    sprintf(X, "%d\n", i);
    return X[0];
  }
  return 0;
}

int main() {
  int i, j = 0;
  for (i = 0; i < 10000; ++i)
    j += Callee(i);
  printf("%d\n", j);
}
