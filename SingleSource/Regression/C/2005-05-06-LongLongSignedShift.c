extern int printf(const char *str, ...);

int main(int argc, char **argv) {
  printf("%lld\n", (argc-100LL) >> 38);

  return 0;
}
