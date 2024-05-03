#ifndef __DELENDUM__
#error "This file should only be included in Delendum programs"
#endif

// utils
unsigned read_unsigned();
void write_unsigned(unsigned x);

unsigned read_unsigned() {
  unsigned x1 = __builtin_delendum_read_advice();
  unsigned x2 = __builtin_delendum_read_advice();
  unsigned x3 = __builtin_delendum_read_advice();
  unsigned x4 = __builtin_delendum_read_advice();
  return (x1 << 0) | (x2 << 8) | (x3 << 16) | (x4 << 24);
}

void write_unsigned(unsigned x) {
  __builtin_delendum_write((x >> 24) & 0xff);
  __builtin_delendum_write((x >> 16) & 0xff);
  __builtin_delendum_write((x >> 8) & 0xff);
  __builtin_delendum_write((x >> 0) & 0xff);
}

