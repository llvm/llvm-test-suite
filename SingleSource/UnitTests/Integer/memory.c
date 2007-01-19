#include <stdio.h>
#include <stdlib.h>

typedef int __attribute__ ((bitwidth(31))) int31;
typedef int __attribute__ ((bitwidth(3))) int3;

typedef struct myStruct{int31 x; int3 y;} myStruct;

void mem_test(int31 num)
{
    int inum = num;
    unsigned int i = 0;
    
    int31* array = malloc(sizeof(int3) * inum);
    for(i=0; i< num; ++i)
    {
        array[i] = i;
    }
    
    free(array);
}

void mem_test2()
{
    myStruct* ptr = malloc(sizeof(myStruct));
    ptr->y = 8; // constant 0
    if(ptr->y != 0)
        printf("error\n");
    ptr->x = ++(ptr->y);
    ptr->x *= 2;
    if(ptr->x - ptr->y != 1)
        printf("error\n");
    free(ptr);
}

int main()
{
    mem_test(0xff);
    mem_test2();
    return 0;
}
