/* Test diagnostics for array references.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */
/* { dg-do compile } */
/* { dg-options "-std=gnu89" } */

struct s { char c[1]; };
struct s f (void);
_Bool b;
char c;
enum e { E } e;
extern int a[];
int *p;
void *pv;
void (*fp)(void);
struct si *sip;

void
g (void)
{
  a[b];
  a[c];
  a[e];
  p[b];
  p[c];
  p[e];
  b[a];
  c[a];
  e[a];
  b[p];
  c[p];
  e[p];
  /* These two should be treated the same.  In particular, a "neither
     array nor pointer" bogus warning used to be given for the
     second.  */
  f().c[0];
  0[f().c];
  /* Various invalid cases.  */
  c[c]; /* { dg-error "subscripted value is neither array nor pointer nor vector" } */
  p[1.0]; /* { dg-error "array subscript is not an integer" } */
  1.0[a]; /* { dg-error "array subscript is not an integer" } */
  fp[0]; /* { dg-error "subscripted value is pointer to function" } */
  0[fp]; /* { dg-error "subscripted value is pointer to function" } */
  pv[0]; /* { dg-warning "dereferencing 'void \\*' pointer" } */
  0[pv]; /* { dg-warning "dereferencing 'void \\*' pointer" } */
  sip[0]; /* { dg-error "invalid use of undefined type 'struct si'" } */
  0[sip]; /* { dg-error "invalid use of undefined type 'struct si'" } */
}
