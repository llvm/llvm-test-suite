extern int printf(const char *, ...);

void testL(long Arg) {
  printf("%ld\n", Arg / (1LL << 4));
  printf("%ld\n", Arg / (1LL << 46));
}

void test(int Arg) {
  printf("%d\n", Arg / (1 << 0));
  printf("%d\n", Arg / (1 << 4));
  printf("%d\n", Arg / (1 << 18));
  printf("%d\n", Arg / (1 << 30));
}

int main() {
  int B20 = - (1 << 20);
  long B53 = - (1LL << 53);

  test(B20 + 32);
  test(B20 + 33);

  testL(B53 + 64);
  testL(B53 + 65);

  return 0;
}
