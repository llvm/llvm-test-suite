extern void *alloca(unsigned long sz);

int main() {
  int sz = 8;
  int *foo = (int *)alloca(sz);
  foo[1] = 4;
  if (foo[1] == 4) {
    return 0;
  } else {
    while (1) {}
  }
}
