#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int
main(int argc, char** argv)
{
  char  c1 = (argc >= 2)? atoi(argv[1]) : 100;  /* 100 = 'd' */
  short s1 = (argc >= 3)? atoi(argv[2]) : -769; /* 0xf7ff = -769 */
  
  unsigned char ubc0 = (unsigned char) c1;      /* 100 = 'd' */
  uint8_t  ubs0 = (uint8_t) s1;                 /* 0xff = 255 */
  int8_t   bs0  = (int8_t) s1;                  /* 0xff = -1 */
  
  unsigned char  uc2 = (unsigned char) c1;      /* 100 = 'd' */
  unsigned short us2 = (unsigned short) s1;     /* 0xf7ff = 64767 */
  
  int ic3 = (int) c1;                           /* 100 = 'd' */
  int is3 = (int) s1;                           /* 0xfffff7ff = -769 */
  
  unsigned int uic4 = (unsigned int) c1;        /*  100 = 'd' */
  unsigned int uis4 = (unsigned int) s1;        /* 0xfffff7ff = 4294966527 */
  
  printf("ubc0 = '%c'\n", ubc0);
  printf("ubs0 = %u\n",   ubs0);
  printf("bs0  = %d\n",   bs0);
  printf("c1   = '%c'\n", c1);
  printf("s1   = %d\n",   s1);
  printf("uc2  = '%c'\n", uc2);
  printf("us2  = %u\n",   us2);
  printf("ic3  = '%c'\n", ic3);
  printf("is3  = %d\n",   is3);
  printf("uic4 = '%c'\n", uic4);
  printf("uis4 = %u\n",   uis4);
  
  return 0;
}
