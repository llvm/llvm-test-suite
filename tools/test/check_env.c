#include <stdlib.h>

int main(int argc, char* argv[]) {
  // SET_IN_PARENT will have been set in by the driver, test_not.sh.
  // NOT_IN_PARENT will not have been set. Calling getenv with the former will
  // return non-NULL, the latter will return NULL. If both conditions are true,
  // this will return non-zero (which is an "error" code). This is intentional
  // because this will be passed to not which expects an error code.

  return getenv("SET_IN_PARENT") && !getenv("NOT_IN_PARENT");
}
