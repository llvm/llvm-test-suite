#include <stdio.h>

typedef int __attribute__ ((bitwidth(31))) int31;

struct Blend_Map_Entry {
  union {
   float Colour[5];
   double Point_Slope[2];
   int31  weight[5];
  } Vals;
};

void test(struct Blend_Map_Entry* Foo)
{
}

int main()
{
    if( sizeof(struct Blend_Map_Entry) == 5 * sizeof(int) )
        printf("error: %d\n", sizeof(struct Blend_Map_Entry));
    return 0;
}
