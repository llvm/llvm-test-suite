int main() {
  int byte;
  while ((byte = __builtin_delendum_read_advice()) != -1) {
    __builtin_delendum_write(byte);
  }
  return 0;
}
