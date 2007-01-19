#include <stdio.h>
typedef unsigned int __attribute__ ((bitwidth(7))) int7;
typedef unsigned int __attribute__ ((bitwidth(17))) int17;
typedef unsigned int __attribute__ ((bitwidth(32))) int32;
typedef unsigned int __attribute__ ((bitwidth(8))) int8;

class myStruct{
    public:
    int i;
    unsigned char c :7;
    int s: 17;
    char c2;
};

class myStruct2{
    public:
    int32 i;
    int7 c;
    int17 s;
    int8 c2;
};

int main()
{
    myStruct x;
    myStruct2 y;

    char* ptrc, *ptrc1, *ptrc2, *ptrc3;
    unsigned int offset, offset1;

    ptrc = (char*)&(x.i);
    ptrc1 = (char*)&(x.c2);

    

    ptrc2 = (char*)&(y.i);
    ptrc3 = (char*)&(y.c2);

    offset = ptrc1 - ptrc;
    offset1 = ptrc3 - ptrc2;

    
    if(offset != offset1 || sizeof(myStruct) != sizeof(myStruct2))
        printf("error\n");

    return 0;
}
