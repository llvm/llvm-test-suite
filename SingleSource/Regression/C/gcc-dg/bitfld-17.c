/* { dg-do compile } */
/* { dg-options "" } */
/* { dg-options "-mno-ms-bitfields -Wno-packed-bitfield-compat" { target { i?86-*-mingw* x86_64-*-mingw* } } } */

struct t
{
  char a:4;
  char b:8 __attribute__ ((packed));
  char c:4;
}; /* { dg-message "note: offset of packed bit-field 'b' has changed in GCC 4.4" "" { target pcc_bitfield_type_matters } } */

int assrt[sizeof (struct t) == 2 ? 1 : -1];
