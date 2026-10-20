# beman.execution

A test from [beman.execution](https://github.com/bemanproject/execution), an
implementation of C++26 `std::execution` (P2300, senders and receivers)
(Apache-2.0 WITH LLVM-exception, see `LICENSE`), at commit
`8e358c01f4f4435e06b0691de433f4b2a07367be`.

The library is built on concepts and coroutines. Most of the compile time is
spent in the frontend.

* `exec-with-awaitable-senders.cpp` is
  `tests/beman/execution/exec-with-awaitable-senders.test.cpp`. It checks its
  results with `assert`; the test harness undefines `NDEBUG`.
* `include/beman` holds the headers from `include/beman` that the test needs.
* `include/test/execution.hpp` is from `tests/beman/execution/include/test`.

The files are unmodified. The test is built as C++23.

To update, check out a new upstream commit, copy the test, and collect the
headers it includes with `-MM`.
