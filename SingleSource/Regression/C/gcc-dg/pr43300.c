/* { dg-do compile } */
/* { dg-options "-Os -w" } */
/* { dg-options "-Os -w -Wno-psabi" { target { i?86-*-* x86_64-*-* } } } */

typedef float V2SF __attribute__ ((vector_size (128)));

V2SF
foo (int x, V2SF a)
{
  V2SF b;
  if (x & 42)
    b = a;
  else
    b = a + (V2SF) {1.0f/0.0f - 1.0f/0.0f, 1.0f/0.0f - 1.0f/0.0f};
  while (x--)
    a += b;
      
  return a;
}
