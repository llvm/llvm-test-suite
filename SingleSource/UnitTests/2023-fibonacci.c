int fib(int n) {
	if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fib(n-1) + fib(n-2);
  }
}

int main () {
  // TODO: make this work when n != 0
	if (fib(0) == 0)  {
		return 0;
	} else {
		while (1) {}
	}
}
