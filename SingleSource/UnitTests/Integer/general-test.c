/* This test just tries out a few bitwidth attribute constructs and 
 * generates some output based on the them.
 */

#include <stdio.h>
#include <stdlib.h>

#define ATTR_BITS(N) __attribute__((bitwidth(N))) 

typedef int ATTR_BITS( 4) My04BitInt;
typedef int ATTR_BITS(16) My16BitInt;
typedef int ATTR_BITS(17) My17BitInt;
typedef int ATTR_BITS(37) My37BitInt;
typedef int ATTR_BITS(65) My65BitInt;

struct MyStruct {
  My04BitInt i4Field;
  short ATTR_BITS(12) i12Field;
  long ATTR_BITS(17) i17Field;
  My37BitInt i37Field;
};

My37BitInt getSizes( short ATTR_BITS(23) num) {
  My17BitInt i;
  struct MyStruct strct;
  int __attribute__((bitwidth(9))) j;
  int result;
  printf("sizeof(MyStruct) == %d\n", sizeof(struct MyStruct));
  printf("sizeof(My17BitInt) == %d\n", sizeof(My17BitInt));
  printf("sizeof(j) == %d\n", sizeof(j));
  result = sizeof(My17BitInt) + sizeof(j) + sizeof(struct MyStruct);
  strct.i17Field = result;
  j = 257;
  printf("j = %d\n", j);
  printf("size sum is %d\n", result);
  return result;
}

int
main ( int argc, char** argv)
{
  srand(0);
  int r = rand() + argc + 31415926;
  char ATTR_BITS(23) X = r;
  printf("X is %d\n", X);
  return ((int ATTR_BITS(32)) getSizes(X)) & 1;
}
