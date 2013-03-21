// Testcase for <rdar://problem/13360379> / PR15555
#include <cstdlib>

bool thrown = false;
bool caught = false;

class TestException {
public:
    TestException() {}
};

struct Z {
  Z() {}
  ~Z() {}
};

void thr(int n) {
  if( --n <= 0 ) {
    thrown = true;
    throw TestException();
    abort();
  }

  Z z;
  thr(n - 1);
}

__attribute__((noinline))
void run() {
  try {
    thr(10);
    abort();
  } catch(const TestException &e) {
    caught = true;
  }
}

int main(int argc, char* argv[]) {
  try {
    run();
  } catch(...) {
    abort();
  }

  if (thrown && caught)
    return EXIT_SUCCESS;

  return EXIT_FAILURE;
}
