# Fortran Tests

This directory contains test suites such as those of
[gfortran](https://github.com/llvm/llvm-test-suite/tree/main/Fortran/gfortran)
and [NIST](https://github.com/llvm/llvm-test-suite/tree/main/Fortran/UnitTests/fcvs21_f95),
end-to-end tests of functions with runtime support as well as some proxy
applications such as
[SNAP](https://github.com/llvm/llvm-test-suite/tree/main/Fortran/SNAP).
When the test suite is configured with `-DTEST_SUITE_SUBDIRS=Fortran`, in most
cases, all tests in this directory will be run. The exception is where certain
tests/test-suites are disabled on certain platforms. For instance, the gfortran
tests are not run on RISC-V.

## Setting NO_STOP_MESSAGE in the environment

By default, flang prints a stop message in certain circumstances, typically
when the `STOP` statement is executed. This breaks the NIST tests. Setting
`NO_STOP_MESSAGE=1` in the environment disables this behavior. If
`NO_STOP_MESSAGE` is not set in the environment when running the tests, it will
be set automatically. See
[Fortran/lit.local.cfg](https://github.com/llvm/llvm-test-suite/tree/main/Fortran/lit.local.cfg)
for details.

If adding a subdirectory with tests that need to check the `STOP` message,
add a `lit.local.cfg` file in that subdirectory with code to unset the
variable. For instance, something like this

```python
config["NO_STOP_MESSAGE"] = ""
```

## Building and running a specific test suite

It is possible to configure the llvm-test-suite to run only a subset of the
tests here. This can be done by specifying an appropriate subdirectory of
`Fortran/`. For instance, to build and run only the gfortran tests, the add
the following when running cmake:

```
-DTEST_SUITE_SUBDIRS=Fortran/gfortran
```

Keep in mind that when doing so the `lit.local.cfg` files from any parent
directories will not be processed. This may result in test failures if the tests
expect certain configuration options to have been set, and those are only set
in the `lit.local.cfg` file in a parent directory.

This case can be seen when one attempts to run only the NIST tests by setting
`-DTEST_SUITE_SUBDIRS=Fortran/UnitTests/fcvs21_f95`. Since
[Fortran/lit.local.cfg](https://github.com/llvm/llvm-test-suite/tree/main/Fortran/lit.local.cfg)
will not be processed in this case, `NO_STOP_MESSAGE=1` will not be added to
the environment automatically and several tests will fail. In this case,
`NO_STOP_MESSAGE=1` must be set explicitly when running the tests. One way of
doing this is shown below.

```shell
NO_STOP_MESSAGE=1 /path/to/llvm-lit -s .
```
