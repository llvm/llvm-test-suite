/* PR c++/34198 */
/* { dg-do compile } */
/* { dg-options "-O2 -Wconversion" } */

signed char sc;
unsigned char uc;
short int ss;
unsigned short int us;
int si;
unsigned int ui;

void test1 (void)
{
  int a = uc & 0xff;
  int b = sc & 0x7f;
  int c = 0xff & uc;
  int d = 0x7f & sc;
  int e = uc & sc;
  unsigned char f = (int) uc;
  signed char g = (int) sc;
  unsigned char h = (unsigned int) (short int) uc;
  signed char i = (int) (unsigned short int) sc;	/* { dg-warning "conversion from .int. to .signed char. may change value" "" { target { int32plus } } } */
  unsigned char j = (unsigned int) (short int) us;	/* { dg-warning "may change value" } */
  signed char k = (int) (unsigned short int) ss;	/* { dg-warning "may change value" } */
}

void test2 (void)
{
  signed char a = (unsigned char) sc;		/* { dg-warning "may change the sign" } */
  unsigned char b = (signed char) uc;		/* { dg-warning "may change the sign" } */
  signed char c = (int) (unsigned char) sc;	/* { dg-warning "may change the sign" } */
  unsigned char d = (int) (signed char) uc;	/* { dg-warning "may change the sign" } */
  int e = (unsigned int) si;			/* { dg-warning "may change the sign" } */
  unsigned int f = (int) ui;			/* { dg-warning "may change the sign" } */
}
