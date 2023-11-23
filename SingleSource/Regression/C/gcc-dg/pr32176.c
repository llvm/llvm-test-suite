/* Contributed by Francois-Xavier Coudert  <fxcoudert@gcc.gnu.org>  */

/* { dg-do compile } */
/* { dg-options "-O2 -fprefetch-loop-arrays -w" } */
/* { dg-additional-options "-march=i686 -msse" { target { { i?86-*-* x86_64-*-* } && ia32 } } } */

extern void _gfortran_abort ();

void foo (void)
{
  int i, m;
  float xa[21];

  m = 0;
  while (1)
    {
      i = 0;
      while (1)
	{
	  if (xa[(long int)i] == xa[(long int)(i+m)])
	    _gfortran_abort ();
	  if (i == 10)
	    break;
	  i++;
	}
      if (m == 10)
	break;
      m++;
    }
}
