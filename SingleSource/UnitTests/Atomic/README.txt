Atomic runtime library tests

========

These tests aim to capture real-world multithreaded use cases of atomic
builtins. Each test focuses on a single atomic operation. Those using multiple
operations can be compared with other tests using the same operations to isolate
bugs to a single atomic operation.

Each test consists of a "looper" body and a test script. The test script
instantiates 10 threads, each running the looper. The loopers contend the same
memory address, performing atomic operations on it. Each looper executes
10^6 times for a total of 10^7 operations. The resultant value in the contended
pointer is compared against a closed-form solution. It's expected that the two
values equate.

For example, a looper that increments the shared pointer is expected to end up
with a value of 10^7. If its final value is not that, the test fails.

Each test is performed on all relevant types.

========

Future test writers should be aware that the set of all tests that appear to
test atomicity is not the set of all tests that test atomicity. In fact, tests
that may test atomicity on one processor may not test atomicity on a different
processor.

As such, test writers are encouraged to write nonatomic variants of their tests,
and verify that they pass in a variety of scenarios.
