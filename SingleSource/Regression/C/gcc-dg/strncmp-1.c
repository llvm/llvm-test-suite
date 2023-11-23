/* Test strncmp builtin expansion for compilation and proper execution.  */
/* { dg-do run } */
/* { dg-options "-O2" } */
/* { dg-require-effective-target ptr32plus } */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RUN_TEST(SZ, ALIGN) test_strncmp_ ## SZ ## _ ## ALIGN ()

#define DEF_TEST(SZ, ALIGN)                                                 \
static void test_strncmp_ ## SZ ## _ ## ALIGN (void) {     		    \
  char one[3 * (SZ > 10 ? SZ : 10)];					    \
  char two[3 * (SZ > 10 ? SZ : 10)];					    \
  char three[8192] __attribute__ ((aligned (4096)));       		    \
  char four[8192] __attribute__ ((aligned (4096)));        		    \
  int i,j;                                                                  \
  memset(one,0,sizeof(one));				   		    \
  memset(two,0,sizeof(two));				   		    \
  memset(three,0,sizeof(three));			   		    \
  memset(four,0,sizeof(four));				   		    \
  for (i = 0 ; i < SZ ; i++)			   		            \
    {							   		    \
      int r1;					           		    \
      char *a = one + (i & 1) * ALIGN;			   		    \
      char *b = two + (i & 1) * ALIGN;			   		    \
      memset(a, '-', SZ);					   	    \
      memset(b, '-', SZ);					   	    \
      a[i] = '1';					   		    \
      b[i] = '2';					   		    \
      a[SZ] = 0;							    \
      b[SZ] = 0;					   		    \
      if (!((r1 = strncmp (b, a, SZ)) > 0))   		   		    \
	abort ();							    \
      if (!((r1 = strncmp (a, b, SZ)) < 0))			   	    \
	abort ();							    \
      b[i] = '1';					   		    \
      if (!((r1 = strncmp (a, b, SZ)) == 0))		   		    \
	abort ();							    \
      for(j = i; j < SZ ; j++)			   		            \
	{						   		    \
	  a[j] = '1';            			   		    \
	  b[j] = '2';			                   		    \
	}						   		    \
      if (!((r1 = strncmp (b, a, SZ)) > 0))		   		    \
	abort ();							    \
      if (!((r1 = strncmp (a, b, SZ)) < 0))		   		    \
	abort ();							    \
      for(j = 0; j < i ; j++)						    \
        {								    \
	  memset(a, '-', SZ);						    \
	  memset(b, '-', SZ);						    \
	  a[j] = '\0';							    \
	  a[j+1] = '1';							    \
	  b[j] = '\0';							    \
	  b[j+1] = '2';							    \
	  if ((r1 = strncmp (b, a, SZ)) != 0)				    \
	    abort ();							    \
	}                                                                   \
      a = three + 4096 - (SZ / 2 + (i & 1) * ALIGN);		   	    \
      b = four + 4096 - (SZ / 2 + (i & 1) * ALIGN);		   	    \
      memset(a, '-', SZ);					   	    \
      memset(b, '-', SZ);					   	    \
      a[i] = '1';					   		    \
      b[i] = '2';					   		    \
      a[SZ] = 0;							    \
      b[SZ] = 0;					   		    \
      if (!((r1 = strncmp(b, a, SZ)) > 0))   		   		    \
	abort ();							    \
      if (!((r1 = strncmp(a, b, SZ)) < 0))			   	    \
	abort ();							    \
      b[i] = '1';					   		    \
      if (!((r1 = strncmp(a, b, SZ)) == 0))		   		    \
	abort ();							    \
    }							                    \
}                                                                

#ifdef TEST_ALL
DEF_TEST(1,1)
DEF_TEST(1,2)
DEF_TEST(1,4)
DEF_TEST(1,8)
DEF_TEST(1,16)
DEF_TEST(2,1)
DEF_TEST(2,2)
DEF_TEST(2,4)
DEF_TEST(2,8)
DEF_TEST(2,16)
DEF_TEST(3,1)
DEF_TEST(3,2)
DEF_TEST(3,4)
DEF_TEST(3,8)
DEF_TEST(3,16)
DEF_TEST(4,1)
DEF_TEST(4,2)
DEF_TEST(4,4)
DEF_TEST(4,8)
DEF_TEST(4,16)
DEF_TEST(5,1)
DEF_TEST(5,2)
DEF_TEST(5,4)
DEF_TEST(5,8)
DEF_TEST(5,16)
DEF_TEST(6,1)
DEF_TEST(6,2)
DEF_TEST(6,4)
DEF_TEST(6,8)
DEF_TEST(6,16)
DEF_TEST(7,1)
DEF_TEST(7,2)
DEF_TEST(7,4)
DEF_TEST(7,8)
DEF_TEST(7,16)
DEF_TEST(8,1)
DEF_TEST(8,2)
DEF_TEST(8,4)
DEF_TEST(8,8)
DEF_TEST(8,16)
DEF_TEST(9,1)
DEF_TEST(9,2)
DEF_TEST(9,4)
DEF_TEST(9,8)
DEF_TEST(9,16)
DEF_TEST(10,1)
DEF_TEST(10,2)
DEF_TEST(10,4)
DEF_TEST(10,8)
DEF_TEST(10,16)
DEF_TEST(11,1)
DEF_TEST(11,2)
DEF_TEST(11,4)
DEF_TEST(11,8)
DEF_TEST(11,16)
DEF_TEST(12,1)
DEF_TEST(12,2)
DEF_TEST(12,4)
DEF_TEST(12,8)
DEF_TEST(12,16)
DEF_TEST(13,1)
DEF_TEST(13,2)
DEF_TEST(13,4)
DEF_TEST(13,8)
DEF_TEST(13,16)
DEF_TEST(14,1)
DEF_TEST(14,2)
DEF_TEST(14,4)
DEF_TEST(14,8)
DEF_TEST(14,16)
DEF_TEST(15,1)
DEF_TEST(15,2)
DEF_TEST(15,4)
DEF_TEST(15,8)
DEF_TEST(15,16)
DEF_TEST(16,1)
DEF_TEST(16,2)
DEF_TEST(16,4)
DEF_TEST(16,8)
DEF_TEST(16,16)
DEF_TEST(17,1)
DEF_TEST(17,2)
DEF_TEST(17,4)
DEF_TEST(17,8)
DEF_TEST(17,16)
DEF_TEST(18,1)
DEF_TEST(18,2)
DEF_TEST(18,4)
DEF_TEST(18,8)
DEF_TEST(18,16)
DEF_TEST(19,1)
DEF_TEST(19,2)
DEF_TEST(19,4)
DEF_TEST(19,8)
DEF_TEST(19,16)
DEF_TEST(20,1)
DEF_TEST(20,2)
DEF_TEST(20,4)
DEF_TEST(20,8)
DEF_TEST(20,16)
DEF_TEST(21,1)
DEF_TEST(21,2)
DEF_TEST(21,4)
DEF_TEST(21,8)
DEF_TEST(21,16)
DEF_TEST(22,1)
DEF_TEST(22,2)
DEF_TEST(22,4)
DEF_TEST(22,8)
DEF_TEST(22,16)
DEF_TEST(23,1)
DEF_TEST(23,2)
DEF_TEST(23,4)
DEF_TEST(23,8)
DEF_TEST(23,16)
DEF_TEST(24,1)
DEF_TEST(24,2)
DEF_TEST(24,4)
DEF_TEST(24,8)
DEF_TEST(24,16)
DEF_TEST(25,1)
DEF_TEST(25,2)
DEF_TEST(25,4)
DEF_TEST(25,8)
DEF_TEST(25,16)
DEF_TEST(26,1)
DEF_TEST(26,2)
DEF_TEST(26,4)
DEF_TEST(26,8)
DEF_TEST(26,16)
DEF_TEST(27,1)
DEF_TEST(27,2)
DEF_TEST(27,4)
DEF_TEST(27,8)
DEF_TEST(27,16)
DEF_TEST(28,1)
DEF_TEST(28,2)
DEF_TEST(28,4)
DEF_TEST(28,8)
DEF_TEST(28,16)
DEF_TEST(29,1)
DEF_TEST(29,2)
DEF_TEST(29,4)
DEF_TEST(29,8)
DEF_TEST(29,16)
DEF_TEST(30,1)
DEF_TEST(30,2)
DEF_TEST(30,4)
DEF_TEST(30,8)
DEF_TEST(30,16)
DEF_TEST(31,1)
DEF_TEST(31,2)
DEF_TEST(31,4)
DEF_TEST(31,8)
DEF_TEST(31,16)
DEF_TEST(32,1)
DEF_TEST(32,2)
DEF_TEST(32,4)
DEF_TEST(32,8)
DEF_TEST(32,16)
DEF_TEST(33,1)
DEF_TEST(33,2)
DEF_TEST(33,4)
DEF_TEST(33,8)
DEF_TEST(33,16)
DEF_TEST(34,1)
DEF_TEST(34,2)
DEF_TEST(34,4)
DEF_TEST(34,8)
DEF_TEST(34,16)
DEF_TEST(35,1)
DEF_TEST(35,2)
DEF_TEST(35,4)
DEF_TEST(35,8)
DEF_TEST(35,16)
DEF_TEST(36,1)
DEF_TEST(36,2)
DEF_TEST(36,4)
DEF_TEST(36,8)
DEF_TEST(36,16)
DEF_TEST(37,1)
DEF_TEST(37,2)
DEF_TEST(37,4)
DEF_TEST(37,8)
DEF_TEST(37,16)
DEF_TEST(38,1)
DEF_TEST(38,2)
DEF_TEST(38,4)
DEF_TEST(38,8)
DEF_TEST(38,16)
DEF_TEST(39,1)
DEF_TEST(39,2)
DEF_TEST(39,4)
DEF_TEST(39,8)
DEF_TEST(39,16)
DEF_TEST(40,1)
DEF_TEST(40,2)
DEF_TEST(40,4)
DEF_TEST(40,8)
DEF_TEST(40,16)
DEF_TEST(41,1)
DEF_TEST(41,2)
DEF_TEST(41,4)
DEF_TEST(41,8)
DEF_TEST(41,16)
DEF_TEST(42,1)
DEF_TEST(42,2)
DEF_TEST(42,4)
DEF_TEST(42,8)
DEF_TEST(42,16)
DEF_TEST(43,1)
DEF_TEST(43,2)
DEF_TEST(43,4)
DEF_TEST(43,8)
DEF_TEST(43,16)
DEF_TEST(44,1)
DEF_TEST(44,2)
DEF_TEST(44,4)
DEF_TEST(44,8)
DEF_TEST(44,16)
DEF_TEST(45,1)
DEF_TEST(45,2)
DEF_TEST(45,4)
DEF_TEST(45,8)
DEF_TEST(45,16)
DEF_TEST(46,1)
DEF_TEST(46,2)
DEF_TEST(46,4)
DEF_TEST(46,8)
DEF_TEST(46,16)
DEF_TEST(47,1)
DEF_TEST(47,2)
DEF_TEST(47,4)
DEF_TEST(47,8)
DEF_TEST(47,16)
DEF_TEST(48,1)
DEF_TEST(48,2)
DEF_TEST(48,4)
DEF_TEST(48,8)
DEF_TEST(48,16)
DEF_TEST(49,1)
DEF_TEST(49,2)
DEF_TEST(49,4)
DEF_TEST(49,8)
DEF_TEST(49,16)
DEF_TEST(100,1)
DEF_TEST(100,2)
DEF_TEST(100,4)
DEF_TEST(100,8)
DEF_TEST(100,16)
#else
DEF_TEST(3,1)
DEF_TEST(4,1)
DEF_TEST(4,2)
DEF_TEST(4,4)
DEF_TEST(5,1)
DEF_TEST(6,1)
DEF_TEST(7,1)
DEF_TEST(8,1)
DEF_TEST(8,2)
DEF_TEST(8,4)
DEF_TEST(8,8)
DEF_TEST(9,1)
DEF_TEST(16,1)
DEF_TEST(16,2)
DEF_TEST(16,4)
DEF_TEST(16,8)
DEF_TEST(16,16)
DEF_TEST(32,1)
DEF_TEST(32,2)
DEF_TEST(32,4)
DEF_TEST(32,8)
DEF_TEST(32,16)
DEF_TEST(100,1)
DEF_TEST(100,2)
DEF_TEST(100,4)
DEF_TEST(100,8)
DEF_TEST(100,16)
#endif

int
main(int argc, char **argv)
{

#ifdef TEST_ALL
  RUN_TEST(1,1);
  RUN_TEST(1,2);
  RUN_TEST(1,4);
  RUN_TEST(1,8);
  RUN_TEST(1,16);
  RUN_TEST(2,1);
  RUN_TEST(2,2);
  RUN_TEST(2,4);
  RUN_TEST(2,8);
  RUN_TEST(2,16);
  RUN_TEST(3,1);
  RUN_TEST(3,2);
  RUN_TEST(3,4);
  RUN_TEST(3,8);
  RUN_TEST(3,16);
  RUN_TEST(4,1);
  RUN_TEST(4,2);
  RUN_TEST(4,4);
  RUN_TEST(4,8);
  RUN_TEST(4,16);
  RUN_TEST(5,1);
  RUN_TEST(5,2);
  RUN_TEST(5,4);
  RUN_TEST(5,8);
  RUN_TEST(5,16);
  RUN_TEST(6,1);
  RUN_TEST(6,2);
  RUN_TEST(6,4);
  RUN_TEST(6,8);
  RUN_TEST(6,16);
  RUN_TEST(7,1);
  RUN_TEST(7,2);
  RUN_TEST(7,4);
  RUN_TEST(7,8);
  RUN_TEST(7,16);
  RUN_TEST(8,1);
  RUN_TEST(8,2);
  RUN_TEST(8,4);
  RUN_TEST(8,8);
  RUN_TEST(8,16);
  RUN_TEST(9,1);
  RUN_TEST(9,2);
  RUN_TEST(9,4);
  RUN_TEST(9,8);
  RUN_TEST(9,16);
  RUN_TEST(10,1);
  RUN_TEST(10,2);
  RUN_TEST(10,4);
  RUN_TEST(10,8);
  RUN_TEST(10,16);
  RUN_TEST(11,1);
  RUN_TEST(11,2);
  RUN_TEST(11,4);
  RUN_TEST(11,8);
  RUN_TEST(11,16);
  RUN_TEST(12,1);
  RUN_TEST(12,2);
  RUN_TEST(12,4);
  RUN_TEST(12,8);
  RUN_TEST(12,16);
  RUN_TEST(13,1);
  RUN_TEST(13,2);
  RUN_TEST(13,4);
  RUN_TEST(13,8);
  RUN_TEST(13,16);
  RUN_TEST(14,1);
  RUN_TEST(14,2);
  RUN_TEST(14,4);
  RUN_TEST(14,8);
  RUN_TEST(14,16);
  RUN_TEST(15,1);
  RUN_TEST(15,2);
  RUN_TEST(15,4);
  RUN_TEST(15,8);
  RUN_TEST(15,16);
  RUN_TEST(16,1);
  RUN_TEST(16,2);
  RUN_TEST(16,4);
  RUN_TEST(16,8);
  RUN_TEST(16,16);
  RUN_TEST(17,1);
  RUN_TEST(17,2);
  RUN_TEST(17,4);
  RUN_TEST(17,8);
  RUN_TEST(17,16);
  RUN_TEST(18,1);
  RUN_TEST(18,2);
  RUN_TEST(18,4);
  RUN_TEST(18,8);
  RUN_TEST(18,16);
  RUN_TEST(19,1);
  RUN_TEST(19,2);
  RUN_TEST(19,4);
  RUN_TEST(19,8);
  RUN_TEST(19,16);
  RUN_TEST(20,1);
  RUN_TEST(20,2);
  RUN_TEST(20,4);
  RUN_TEST(20,8);
  RUN_TEST(20,16);
  RUN_TEST(21,1);
  RUN_TEST(21,2);
  RUN_TEST(21,4);
  RUN_TEST(21,8);
  RUN_TEST(21,16);
  RUN_TEST(22,1);
  RUN_TEST(22,2);
  RUN_TEST(22,4);
  RUN_TEST(22,8);
  RUN_TEST(22,16);
  RUN_TEST(23,1);
  RUN_TEST(23,2);
  RUN_TEST(23,4);
  RUN_TEST(23,8);
  RUN_TEST(23,16);
  RUN_TEST(24,1);
  RUN_TEST(24,2);
  RUN_TEST(24,4);
  RUN_TEST(24,8);
  RUN_TEST(24,16);
  RUN_TEST(25,1);
  RUN_TEST(25,2);
  RUN_TEST(25,4);
  RUN_TEST(25,8);
  RUN_TEST(25,16);
  RUN_TEST(26,1);
  RUN_TEST(26,2);
  RUN_TEST(26,4);
  RUN_TEST(26,8);
  RUN_TEST(26,16);
  RUN_TEST(27,1);
  RUN_TEST(27,2);
  RUN_TEST(27,4);
  RUN_TEST(27,8);
  RUN_TEST(27,16);
  RUN_TEST(28,1);
  RUN_TEST(28,2);
  RUN_TEST(28,4);
  RUN_TEST(28,8);
  RUN_TEST(28,16);
  RUN_TEST(29,1);
  RUN_TEST(29,2);
  RUN_TEST(29,4);
  RUN_TEST(29,8);
  RUN_TEST(29,16);
  RUN_TEST(30,1);
  RUN_TEST(30,2);
  RUN_TEST(30,4);
  RUN_TEST(30,8);
  RUN_TEST(30,16);
  RUN_TEST(31,1);
  RUN_TEST(31,2);
  RUN_TEST(31,4);
  RUN_TEST(31,8);
  RUN_TEST(31,16);
  RUN_TEST(32,1);
  RUN_TEST(32,2);
  RUN_TEST(32,4);
  RUN_TEST(32,8);
  RUN_TEST(32,16);
  RUN_TEST(33,1);
  RUN_TEST(33,2);
  RUN_TEST(33,4);
  RUN_TEST(33,8);
  RUN_TEST(33,16);
  RUN_TEST(34,1);
  RUN_TEST(34,2);
  RUN_TEST(34,4);
  RUN_TEST(34,8);
  RUN_TEST(34,16);
  RUN_TEST(35,1);
  RUN_TEST(35,2);
  RUN_TEST(35,4);
  RUN_TEST(35,8);
  RUN_TEST(35,16);
  RUN_TEST(36,1);
  RUN_TEST(36,2);
  RUN_TEST(36,4);
  RUN_TEST(36,8);
  RUN_TEST(36,16);
  RUN_TEST(37,1);
  RUN_TEST(37,2);
  RUN_TEST(37,4);
  RUN_TEST(37,8);
  RUN_TEST(37,16);
  RUN_TEST(38,1);
  RUN_TEST(38,2);
  RUN_TEST(38,4);
  RUN_TEST(38,8);
  RUN_TEST(38,16);
  RUN_TEST(39,1);
  RUN_TEST(39,2);
  RUN_TEST(39,4);
  RUN_TEST(39,8);
  RUN_TEST(39,16);
  RUN_TEST(40,1);
  RUN_TEST(40,2);
  RUN_TEST(40,4);
  RUN_TEST(40,8);
  RUN_TEST(40,16);
  RUN_TEST(41,1);
  RUN_TEST(41,2);
  RUN_TEST(41,4);
  RUN_TEST(41,8);
  RUN_TEST(41,16);
  RUN_TEST(42,1);
  RUN_TEST(42,2);
  RUN_TEST(42,4);
  RUN_TEST(42,8);
  RUN_TEST(42,16);
  RUN_TEST(43,1);
  RUN_TEST(43,2);
  RUN_TEST(43,4);
  RUN_TEST(43,8);
  RUN_TEST(43,16);
  RUN_TEST(44,1);
  RUN_TEST(44,2);
  RUN_TEST(44,4);
  RUN_TEST(44,8);
  RUN_TEST(44,16);
  RUN_TEST(45,1);
  RUN_TEST(45,2);
  RUN_TEST(45,4);
  RUN_TEST(45,8);
  RUN_TEST(45,16);
  RUN_TEST(46,1);
  RUN_TEST(46,2);
  RUN_TEST(46,4);
  RUN_TEST(46,8);
  RUN_TEST(46,16);
  RUN_TEST(47,1);
  RUN_TEST(47,2);
  RUN_TEST(47,4);
  RUN_TEST(47,8);
  RUN_TEST(47,16);
  RUN_TEST(48,1);
  RUN_TEST(48,2);
  RUN_TEST(48,4);
  RUN_TEST(48,8);
  RUN_TEST(48,16);
  RUN_TEST(49,1);
  RUN_TEST(49,2);
  RUN_TEST(49,4);
  RUN_TEST(49,8);
  RUN_TEST(49,16);
#else
  RUN_TEST(3,1);
  RUN_TEST(4,1);
  RUN_TEST(4,2);
  RUN_TEST(4,4);
  RUN_TEST(5,1);
  RUN_TEST(6,1);
  RUN_TEST(7,1);
  RUN_TEST(8,1);
  RUN_TEST(8,2);
  RUN_TEST(8,4);
  RUN_TEST(8,8);
  RUN_TEST(9,1);
  RUN_TEST(16,1);
  RUN_TEST(16,2);
  RUN_TEST(16,4);
  RUN_TEST(16,8);
  RUN_TEST(16,16);
  RUN_TEST(32,1);
  RUN_TEST(32,2);
  RUN_TEST(32,4);
  RUN_TEST(32,8);
  RUN_TEST(32,16);
#endif
  return 0;
}
