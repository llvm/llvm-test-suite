#include <csetjmp>
#include <cstdio>

class C {
  const char *name;
public:
  C(const char *n) : name(n) {}
  ~C() { printf("Destroying C object in %s\n", name); }
};

void bar(jmp_buf buf)
{
  printf("Inside bar\n");
  longjmp(buf, 37);
}

void foo(jmp_buf buf)
{
  C Obj("foo");
  bar(buf);
}

int main()
{
  C Obj("main");
  jmp_buf buf;
  int ret;

  printf("Inside main\n");

  if ((ret = setjmp(buf)) != 0) {
    printf("ret == %d\n", ret);
  } else {
    foo(buf);
  }
}
