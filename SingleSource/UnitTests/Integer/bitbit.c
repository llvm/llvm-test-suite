// Date: Fri Jan 12 17:28:32 CST 2007
#include "bitbit.h"

// Module | Test
// Thread: int my_test();
int my_test(){
{
  int21 x = 0x1fffff;
  int21 y = 0x0fffff;
  int21 result;
  int i_result;
  result = ~x;
  i_result = result;
  printf("i_result = %x\n", i_result);
  result = x ^ y;
  i_result = result;
  printf("i_result = %x\n", i_result);
  result = x & y;
  if (result == y/*CPPASTBinaryExpression*/) 
    printf("ok\n");
   else 
    printf("fail\n");
  
  result = x | y;
  if (result == x/*CPPASTBinaryExpression*/) 
    printf("ok\n");
   else 
    printf("fail\n");
  
  result = x;
  result &= y;
  if (result == y/*CPPASTBinaryExpression*/) 
    printf("ok\n");
   else 
    printf("fail\n");
  
  result = x;
  result |= y;
  if (result == x/*CPPASTBinaryExpression*/) 
    printf("ok\n");
   else 
    printf("fail\n");
  
  result = x >> 20;
  i_result = result;
  printf("i_result = %x\n", i_result);
  {
    result = y << 1;
    result += 1;
    if (result != x/*CPPASTBinaryExpression*/) 
      printf("fail\n");
     else 
      printf("ok\n");
    
    result = y;
    result <<= 1;
    ++result;
    
    if (result != x/*CPPASTBinaryExpression*/) 
      printf("fail\n");
     else 
      printf("ok\n");
    
  }
  return 0;
}
}

int main()
{
    my_test();
    return 0;
}
// End of Module | Test
