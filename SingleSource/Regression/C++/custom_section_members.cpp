// Test that we can compile a simple class with members in a custom section.
#if defined(__APPLE__)
#define SECTNAME "__TEXT,__section"
#else
#define SECTNAME "section"
#endif

struct A {
  static int foo() __attribute__((section(SECTNAME)));
  static void bar() __attribute__((section(SECTNAME)));
};

int A::foo() { return 0; }
void A::bar() {}

int main() {
  A::bar();
  return A::foo();
}
