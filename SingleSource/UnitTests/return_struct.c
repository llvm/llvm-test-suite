struct S {
  int a;
  int b;
};

struct S func(int i) {
  struct S s;
  s.a = i + 1;
  s.b = i + 2;

  return s;
}

int main() {
  struct S s = func((int)'a');
  __builtin_delendum_write(s.b);
  return 0;
}
