#include <stdio.h>

int foo(volatile *mem, int val, int c) {
  int oldval = __sync_fetch_and_add(mem, val);
  return oldval + c;
}

volatile int x = 0;
int main() {
  long long test = 0;
  int i;
  int y = foo(&x, 1, 2);
  printf("%d, %d\n", y, x);
  y = __sync_val_compare_and_swap(&x, 1, 2);
  printf("%d, %d\n", y, x);
  y = __sync_lock_test_and_set(&x, 1);
  printf("%d, %d\n", y, x);

  for (i = 0; i < 5; i++) {
    __sync_add_and_fetch(&test, 1);
    printf("test = %d\n", (int)test);
  }

  for (i = 0; i < 5; i++) {
    __sync_fetch_and_sub(&test,1);
    printf("test = %d\n", (int)test);
  }

  return 0;
}
