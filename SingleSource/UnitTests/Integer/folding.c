#include <stdio.h>
typedef int __attribute__ ((bitwidth(7))) int7;
typedef int __attribute__ ((bitwidth(15))) int15;

const int7 myConst = 1;
const int15 myConst2 = 0x7fff;

int main()
{
    int7 x;
    int7 y;
    int15 z;
    
    x = myConst << 3; // constant 8
    y = x + myConst;  // constant 9
    if(y -x != 1)
        printf("error\n");

    x = myConst << 7; // constant 0
    if(y -x != 9)
        printf("error\n");

    z = (int15) y;
    z &= myConst2;
    if(z != 0x9)
        printf("error\n");
    return 0;
}
