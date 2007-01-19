
// Date: Fri Jan 12 17:25:23 CST 2007
#include "bigint.h"

typedef enum bool{false=0, true=1} bool;

const uint10 bnd = 1023;


int169 x = 0xffffffff;

int169 y = -0xabcdefde;
// Module | Test
// Thread: int my_test();
int my_test(){
{
  uint10 i = 0;
  int169 result;
  int32 l_result;
  long long rem;
  long long rem2;
  {
  ;/*NULL statement*/
  for ( ; ; ) {
  bool ssdm_tmp_1 = (i < bnd);
  if (!ssdm_tmp_1) break;
    if (i % 2 == 0
        x = x + 1;
     else 
         y = y - x;
    
  ++i;
  }
  }
  result = x*y;
  l_result = result % 0x37015; 
  rem = l_result;
  printf("rem = %lld\n", rem);

  l_result = result % -198721;
  rem2 = l_result;
  printf("rem2 = %lld\n", rem2);
  return 0;
}
}

int main()
{
    my_test();
    return 0;
}


// End of Module | Test
