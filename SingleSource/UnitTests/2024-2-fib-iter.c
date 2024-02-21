unsigned fib(unsigned n) {
  unsigned a = 1;
  unsigned b = 1;
  unsigned c;
  unsigned tmp;
  while (n > 1) {
    tmp = c;
    c = a + b;
    a = b;
    b = tmp;
    n--;
  }
  return c;
}

int main() {
  if (fib(2) == 0) {
    return 0;
  } else {
    while (1) {
    }
  }
}