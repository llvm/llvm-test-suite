#include "bits.h"

uint68 test_part_set(uint68 x, uint60 y)
{
    return part_set(x, y, 0, (bitwidthof(y)-1));
}

uint1 test_reduce(uint68 x)
{
    return reduce(or, x);
}

int main(int argc, char** argv) {
  uint68 A = 0xF0F0F0F0F0F0F0F0ULL;
  uint60 B = 0x0F0F0F0F0F0F0F0FULL;
  uint68 X = test_part_set(A, B);
  uint1 Y = test_reduce(X);
  return (int) Y;
}
