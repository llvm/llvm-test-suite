#include <stdio.h>

int main(int argc) {
   switch (argc) {
   default:
     printf("GOOD\n");
     return 0;
   case 100: 
   case 101:
   case 1023:
     printf("BAD\n");
     return 1;
   }
}
