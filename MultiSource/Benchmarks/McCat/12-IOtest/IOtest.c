
/****
    Copyright (C) 1996 McGill University.
    Copyright (C) 1996 McCAT System Group.
    Copyright (C) 1996 ACAPS Benchmark Administrator
                       benadmin@acaps.cs.mcgill.ca

    This program is free software; you can redistribute it and/or modify
    it provided this copyright notice is maintained.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
****/

#include "IOtest.h"
#include <stdlib.h>

#define IOTEST_SIZE (53681*50) /* prime number */ /* 53681 19170419 67108933 */

char_t *testarray;
unsigned long array_count;

unsigned long getac(void)
/* {{{  */

{
  return array_count;
}

/* }}} */

void setac(unsigned long i)
{
  array_count=(i % IOTEST_SIZE);
}

void initarray(void)
{
  unsigned long i;
  i=0; 
  while(i<IOTEST_SIZE)
    {
      testarray[i]= i % 255;
      i++;
    }
}

char_t array(unsigned long i)
{
  return testarray[i];
}

char_t min(char_t a, char_t b)
{
  return (a>b)? a : b ;
}

char_t max(char_t a, char_t b)
{
  return (a>b) ? b : a ;
}

char_t add(char_t a, char_t b)
{
  return a+b;
}

char_t mult(char_t a, char_t b)
{
  return a*b;
}

void loop( void (*init)(void *) , void (*step)(void *) ,void *result) 
{
  unsigned long i;
  i=0;
  init(result);
  
  while(i<IOTEST_SIZE)
    {
      step(result);
      i++;
    }
}

extern void testA(void), testB(void), testC(void);
int main() {
	testarray = (char_t*)malloc(IOTEST_SIZE);
	testA(); testB(); testC();
	return 0;
}
   
