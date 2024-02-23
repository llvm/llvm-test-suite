unsigned fib(unsigned n) {
  unsigned a = 0;
  unsigned b = 0;
  unsigned c = 1;
  while (n > 1) {
    a = b;
    b = c;
    c = a + b;
    n--;
  }
  return c;
}

int main() {
  if (fib(3) == 2) {
    return 0;
  } else {
    while (1) {
    }
  }
}