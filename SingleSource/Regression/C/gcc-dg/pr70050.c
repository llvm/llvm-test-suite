/* PR middle-end/70050 */
/* { dg-do compile } */
/* { dg-options "-w -Wno-psabi" } */

typedef int v8si __attribute__ ((vector_size (32)));

v8si
foo (v8si v)
{
  return v %= -v;
}
