#include "bits.h"

int main(int argc, char **argv) {
  typedef uint256 BitType;

  BitType X = rand() % bitwidthof(BitType);

  return 0;
}
