// Test that we can compile a simple class with members in a custom section.

struct A {
  static int foo() __attribute__((section("section")));
  static void bar() __attribute__((section("section")));
};

int A::foo() { return 0; }
void A::bar() {}

int main() {
  A::bar();
  return A::foo();
}
