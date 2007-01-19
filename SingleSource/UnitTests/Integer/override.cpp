#include <stdio.h>
typedef int __attribute__ ((bitwidth(31))) int31;
typedef int __attribute__ ((bitwidth(32))) int32;

void func(int32 i)
{
    printf("call func with int32");
}

void func(int31 s)
{
    printf("call func with int31\n");
}

int main()
{
    func( (int31) 1);
    return 0;
}
