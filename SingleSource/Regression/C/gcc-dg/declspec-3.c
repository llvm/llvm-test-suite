/* Test declaration specifiers.  Test diagnosis of storage class
   specifiers not at start.  */
/* Origin: Joseph Myers <jsm@polyomino.org.uk> */
/* { dg-do compile } */
/* { dg-options "-Wold-style-declaration" } */

static int x0;
int static x1; /* { dg-warning "not at beginning" } */

extern int x2;
int extern x3; /* { dg-warning "not at beginning" } */

typedef int x4;
int typedef x5; /* { dg-warning "not at beginning" } */

void g (int);

void
f (void)
{
  auto int x6 = 0;
  int auto x7 = 0; /* { dg-warning "not at beginning" } */
  register int x8 = 0;
  int register x9 = 0; /* { dg-warning "not at beginning" } */
  g (x6 + x7 + x8 + x9);
}

const static int x10; /* { dg-warning "not at beginning" } */

/* Attributes are OK before storage class specifiers, since some
   attributes are like such specifiers themselves.  */

__attribute__((format(printf, 1, 2))) static void h (const char *, ...);
__attribute__((format(printf, 1, 2))) void static i (const char *, ...); /* { dg-warning "not at beginning" } */
