#include <cstdio>
#include <cstring>

class Cleanup {
  char name[10];
public:
  Cleanup(const char* n) {
    strcpy(name, n);
  }
  ~Cleanup() {
    printf("Cleanup for %s!\n", name);
  }
};

static void foo() {
  Cleanup C("num");
  throw 3;
}

int main(void) {
  try {
    foo();
  } catch (int i) {
    printf("Caught %d!\n", i);
  }
  try {
    Cleanup a("a");
    throw Cleanup("c");
    Cleanup b("b");
  } catch (Cleanup &c) {
    printf("Caught cleanup!\n");
  }
  try {
    Cleanup a("ap");
    throw new Cleanup("cp");
    Cleanup b("bp");
  } catch (Cleanup *c) {
    printf("Caught cleanup!\n");
    delete c;
  }
  return 0;
}
