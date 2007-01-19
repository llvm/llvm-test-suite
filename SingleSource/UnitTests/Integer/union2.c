#include <stdio.h>
typedef int __attribute__ ((bitwidth(9))) int9;
typedef int __attribute__ ((bitwidth(31))) int31;
typedef union {short i; int9 i9; int31 i31;} myUnion;
typedef struct myStruct {int9* ptr; short i;} myStruct;

myStruct test(myUnion u)
{
    myStruct x;

    u.i31 = 0;
    u.i = 0xffff;
    int9* ptr = &(u.i9);
    *ptr= 0x00;

    x.ptr = ptr;
    x.i = u.i;

    return x;
    
}

static myUnion uu;

int main()
{
    myStruct s = test(uu);
    if(s.i == 0x0)
        printf("error: s.i=%x\n", s.i);
    return 0;
}
