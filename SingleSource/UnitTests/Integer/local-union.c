#include <stdio.h>

typedef int __attribute__ ((bitwidth(33))) int33;

union foo { int X; int33 Y;};

double test(union foo* F) {
  {
    union foo { float X; int33 Y;} A;
    A.Y = 0x1ffffffff;
    return A.X;
  }
}

int main()
{
    union foo F;
    
    printf("return  = %f\n", test(&F));

    return 0;
}
