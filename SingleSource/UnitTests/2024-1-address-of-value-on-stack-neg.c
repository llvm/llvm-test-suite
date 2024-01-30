int main() {
  int foo = 5;
  int *foo_ptr = &foo;
  if (foo_ptr == 0) {
    while (1) {}
  } else {
    return 0;
  }
}
