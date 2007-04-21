
#include "bits.h"


int main(int argc, char ** argv)
{
  uint68 n;
  uint63 t1;
  uint3 t2;
  uint128 t3;
  unsigned long long t4;

  t4 = bit_concat((uint25) -1, (uint39)-1);
  printBits(t4);
  printf("\n");
  
  n = -1;
  t3 = bit_concat(n, (uint60)-1);
  printBits(t3);
  printf("\n");
  
  return 0;
}
