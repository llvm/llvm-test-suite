int main() {
  while (1) {
    int byte = __builtin_delendum_read_advice();
    __builtin_delendum_write(byte + 'a' - 'A'); // turns caps to small
  }
  return 0;
}
