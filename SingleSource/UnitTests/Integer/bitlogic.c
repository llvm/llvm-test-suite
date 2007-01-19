// Date: Fri Jan 12 17:40:34 CST 2007
#include "bitlogic.h"
#include <stdio.h>

// Module | Test
// Thread: int my_test();
int my_test(){
{
  uint1 x = 0x1;
  uint1 y;
  int9 z = 0x1ff;
  uint9 uz = 0x1ff;
  uint9 temp;
  y = x;
  y -= 1;
  if (!y/*CPPASTUnaryExpression*/) 
    printf("ok\n");
   else 
    printf("fail\n");
  
  if (y > x/*CPPASTBinaryExpression*/) 
    printf("fail\n");
   else 
    printf("ok\n");
  
  if (z != uz/*CPPASTBinaryExpression*/) 
    printf("ok\n");
   else 
    printf("fail\n");
  
  temp = z;
  if (temp <= uz/*CPPASTBinaryExpression*/) 
    printf("ok\n");
   else 
    printf("fail\n");
  
  return 0;
}
}

int main()
{
    my_test();
    return 0;
}
// End of Module | Test
