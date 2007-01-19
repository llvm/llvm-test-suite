#include <stdio.h>


typedef int __attribute__ ((bitwidth(33))) int33;

struct foo A;

struct foo {
  int33 x;
  double D;
};

int main()
{
    A.D = -3.141593;
    A.x = -1;
    printf("%f\n", A.D);
    
    return 0;
}
