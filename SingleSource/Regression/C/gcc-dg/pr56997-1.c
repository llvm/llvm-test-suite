/* Test volatile access to unaligned field.  */
/* { dg-do run } */
/* { dg-options "-fstrict-volatile-bitfields" } */

extern void abort (void);

#define test_type unsigned short
#define MAGIC (unsigned short)0x102u

typedef struct s{
 unsigned char Prefix;
 test_type Type;
}__attribute((__packed__)) ss;

volatile ss v;
ss g;

void __attribute__((noinline))
foo (test_type u)
{
  v.Type = u;
}

test_type __attribute__((noinline))
bar (void)
{
  return v.Type;
}

int main()
{
  test_type temp;
  foo(MAGIC);
  __builtin_memcpy(&g, (void *)&v, sizeof(g));
  if (g.Type != MAGIC)
    abort ();

  g.Type = MAGIC;
  __builtin_memcpy((void *)&v, &g, sizeof(v));
  temp = bar();
  if (temp != MAGIC)
    abort ();
  return 0;
}
