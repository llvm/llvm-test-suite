## Tests from the gfortran test suite ##

This is the top-level directory for tests imported from
[GCC](https://github.com/gcc-mirror/gcc). The test files are contained within
two subdirectories:

- `regression`: Contains the gfortran [tests](https://github.com/gcc-mirror/gcc/tree/master/gcc/testsuite/gfortran.dg).
- `torture`: Contains the gfortran [torture tests](https://github.com/gcc-mirror/gcc/tree/master/gcc/testsuite/gfortran.fortran-torture).

The tests in both `regression` (and its subdirectories) and `torture` can be
classified roughly as _compile_ tests and _execute_ tests. The _compile_ tests
generally check the compiler's error/warning messages and, in some cases,
optimization logs. The _execute_ tests are end-to-end tests that check the
behavior of the binary produced by the compiler.

Currently, only the _execute_ tests are supported in `regression`. Both
`compile` and `execute` tests have been enabled in `torture`.

Of the supported tests, a number of tests have been disabled. These are listed
in the `DisabledFiles.cmake` files that can be found in the various
subdirectories of `Fortran/gfortran`. There are four
categories of such tests:

- *Unsupported*: These are tests that use non-standard extensions/intrinsics
that are not currently supported by flang. Unless those non-standard
features are supported in the future, these tests will never be enabled.

- *Unimplemented*: These tests hit a "not yet implemented" assertion within
flang.

- *Skipped*: These tests cause some form of compiler error. Some trigger an
assertion within the compiler. Others are legal Fortran programs, but
nevertheless cause a semantic error, most likely due to unimplemented
features.

- *Failing*: These tests fail at test-time.

- For "execute" tests, some crash on execution, others produce
incorrect/unexpected output. This could be a result of a bug in the
compiler/code generator or the runtime.

- For "compile" tests, this could be because the compilation succeeds when it
is expected to fail, or vice versa.

Over time, the number of tests in the *unimplemented*, *skipped*, and *failing*
categories should decrease. Eventually, only the *unsupported* category should
remain.


### _Compile_ tests ###

The _compile_ tests are "built" when the whole test suite is built at which
time a compilation log is saved. At testing time, the log is checked to
determine whether the test should pass or fail. If the test is expected to pass,
but the compilation log contains errors, the test will be deemed to have failed
and vice versa. The _compile_ test are supported in `torture`, but not in
`regression`.


### _Execute tests_ ###

The _execute_ tests are built when the whole test suite is built and executed
when the tests are run. The *unsupported*, *unimplemented*, and *skipped* tests
fail to build for the reasons described above. The *failing* tests do build.


### Usage ###

By default, the *unsupported*, *unimplemented*, *skipped*, and *failing* tests
are not run. The intention is that all tests in the test suite should pass by
default.

In order to enable the disabled tests, one or more of the following options can
be passed to `cmake`:

- `TEST_SUITE_FORTRAN_FORCE_ALL_TESTS`: Enable all disabled tests.
- `TEST_SUITE_FORTRAN_FORCE_UNSUPPORTED_TESTS`: Enable only the *unsupported* tests.
- `TEST_SUITE_FORTRAN_FORCE_UNIMPLEMENTED_TESTS`: Enable only the *unimplemented* tests.
- `TEST_SUITE_FORTRAN_FORCE_SKIPPED_TESTS`: Enable only the *skipped* tests.
- `TEST_SUITE_FORTRAN_FORCE_FAILING_TESTS`: Enable only the *failing* tests.
- `TEST_SUITE_FORTRAN_FEATURES`: see the features section below

Some of the tests require the `ISO_Fortran_binding.h` header file. `cmake` will
look for this file in the `include` directory of the `flang` installation
prefix. When running the test from a build directory, the file will probably
not be found. In that case, the `TEST_SUITE_FORTRAN_ISO_C_HEADER_DIR` flag
can be passed to `cmake` with the value being the directory containing the
`ISO_Fortran_binding.h` file to use.

A `cmake` command that would only run the Fortran tests in the test-suite is
shown below

```
cmake -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_C_COMPILER=/path/to/clang \
      -DCMAKE_CXX_COMPILER=/path/to/clang++ \
      -DCMAKE_Fortran_COMPILER=/path/to/flang-new \
      -DTEST_SUITE_FORTRAN=On \
      -DTEST_SUITE_SUBDIRS=Fortran \
      -DTEST_SUITE_FORTRAN_ISO_C_HEADER_DIR=/path/to/dir/containing/header \
      /path/to/source/of/llvm-test-suite/
```

The tests can be run as shown from the `llvm-test-suite` build directory:

```
/path/to/llvm-lit -v -o report.json .
```

It may be necessary to set the `NO_STOP_MESSAGE` environment variable to
avoid tests failures in `llvm-test-suite/Fortran/UnitTests/fcvs21_f95`. These
are unrelated to the gfortran tests here.


### Testing non-standard features/flags

Additional denylists for a particular feature can be included by creating
`DisabledFiles_FEATURE.cmake` files (in the same format as those for the default
denylists, `DisabledFiles.cmake`), and adding FEATURE to
`TEST_SUITE_FORTRAN_FEATURES`. Additional compiler flags can be added using
`CMAKE_Fortran_FLAGS`.

For example, to test feature, FOO, one could use

```
cmake -DTEST_SUITE_FORTRAN_FEATURES=FOO \
      -DCMAKE_Fortran_FLAGS=-some-foo-specific-flag-if-required \
      <other cmake flags>
```

`DisabledFiles_FOO.cmake` files can be created in the appropriate subdirectories
if enabling the feature/flag results in the failure of tests that otherwise pass.
Conversely, the feature/flag may cause some disabled tests to pass. These can be
added to an allowlist file, `EnabledFiles_FOO.cmake` in the corresponding
directory. The file must contain a single variable named `ENABLED_FILES` with
the file names of the tests that should be enabled (in the case of multi-file
tests, this should be the name of the "main" file). An example of such a list is
below.

```
file(GLOB ENABLED_FILES CONFIGURE_DEPENDS
  test_1.f90
  multifile-main.f03
)

```

### Notes for developers/maintainers ###

Since `flang` is under active development, it is expected that features will be
implemented at a steady pace. The relevant tests in this directory should be
enabled. This would involve building the test suite with one of the
`TEST_SUITE_FORTRAN_*` flags described above.

The build system uses static test configuration files named `tests.cmake` to be
found in the various subdirectories of the test suite. These are generated by
`utils/update-test-config.py`. The configuration files are the result of parsing
the relevant DejaGNU annotations from the test files and are used by the various
`CMakeLists.txt` files to set up the tests. These configuration files *must not*
be edited by hand - any edits will be overwritten when `update-test-config.py`
is run.

The test configuration files consist of comment and non-comment lines. Comment
lines start with a `#`. Each non-comment line represents a single test. The line
consists of semicolon-separated fields as shown below:

```<kind>;<sources>;<xfail>;<options>;<enabled-on>;<disabled-on>```

Each field is described in the table below:

| Field          | Description
| :--------------|:----------------------------------------------------------
| `<kind>`       | Must be one of 'preprocess', 'assemble', 'compile', 'link' or 'run'.
| `<sources>`    | A space separated list of sources files that comprise the test. The first file is the "main" file. The rest of the files must be specified in program compilation order
| `<xfail>`      | If present, must be 'xfail' which indicates that the test is expected to trigger a compile-time or runtime error.
| `<options>`    | A space separated list of options to be passed to the compiler when building the test.
| `<enabled-on>` | A space-separated list of targets on which the test is enabled. Each element of the list will be a regular expression that is expected to match an LLVM target triple. If no targets are provided, the test is enabled on all targets.
| `<disabled-on>`| A space-separated list of targets on which the test is disabled. Each element of the list will be a regular expression that is expected to match an LLVM target triple.

The test `kind`'s generally reflect what is being tested. For instance,
`preprocess` tests only run the preprocessor, `assemble` tests generate assembly
but no object code, the `compile` tests generate object code but do not invoke
the linker while the `link` tests do invoke the linker. The `run` tests are
"end-to-end" in that the code is compiled, linked and executed. These tests
generally examine the output of the execution to ensure that the behavior of the
generated executable is as expected.

The test files should be kept in sync with gfortran. This has to be done
manually. When performing this update, the test configuration files must be
regenerated. This can be done by running `update-test-config.py` in the root of
the test suite. The `-h` switch can be provided to the script for additional
options.

The test files in `regression` and `torture` *must not* be modified.

### Overriding DejaGNU annotations ###

In some cases, it may be necessary to override the DejaGNU annotations. Some of
these include:

- To invert the xfail status of a test (which is usually needed when there is
a difference in behavior between gfortran and flang)

- To selectively enable/disable a test on a particular platform.

- In cases where a warning is expected, to override the gfortran-specific
warning message with a flang-specific one.

For now, only limited forms of overriding are supported. In particular, we
do not support overriding warning messages, but that might be supported in the 
future.

In order to override annotations for tests in a given directory, create a
file named `override.yaml` in that directory. The format of the file is
described below. After the file has been populated, the static test 
configuration files must be updated by running `update-test-config.py` as shown
below. This will update all the `tests.cmake` files in the test suite.

```
$ cd /path/to/llvm-test-suite/Fortran/gfortran
$ ./utils/update-test-config.py
```

#### override.yaml ####

The `override.yaml` file can only be used to override attributes of tests 
contained within the directory containing `override.yaml`. In order to override
attributes of tests in subdirectories, an `override.yaml` file must be created
in the subdirectory. This file only needs to be created if necessary. Unlike 
the `DisabledFiles.cmake` files, it does not need to be present if test 
attributes do not need to be overridden. At a high level, the format of the 
file is as follows:

```
---
"file1":
  attr-name-1: attr-val-1
  attr-name-2: attr-val-2
  ...

"file2":
  attr-name-1: attr-val-2
  ...

...

```

Here each "fileN" is the full file name (including the extension) of the test.
In the case of multi-file tests, this must be the name of the main test file.
This must not contain paths (relative or absolute).

The following attributes are currently supported.

#### `disabled_on` ###

The value must be a list of strings. Each string describes a platform on which
the test must be disabled. This will usually be a target triple, and may be a
regex. 

This can be used to disable tests on platforms on which they have been
explicitly enabled (this usually occurs when tests are restricted to run only 
on certain platforms). In such cases, the string that is used to specify the 
platform must exactly match the string that was used in a DejaGNU annotation. 
For instance, the test `regression/simd-builtins-1.f90` is explicitly enabled 
on certain Linux platforms only. This is done in the following annotation:

```
! { dg-do compile { target i?86-*-linux* x86_64-*-linux* aarch64*-*-linux* } }
```

In order to disable this test on AArch64-based Linux systems, the following 
should be added to `regression/override.yaml`:

```
"simd_builtins-1.f90":
    disabled_on: ["aarch64*-*-linux*"]
```

Note that the string in the `disabled_on` list exactly matches that in the 
DejaGNU annotation. If you are not sure which string to use, check the 
`enabled_on` column in the entry for the test in the static test configuration
file, `tests.cmake`, which will be present in the directory containing the test.

If the `enabled_on` column for the test in `tests.cmake` is empty, the test is 
run on all platforms. In this case, overriding the `disabled_on` attribute is
perfectly safe and will result in the test being executed on all platforms
_except_ those in the `disabled_on list`.

*WARNING*: However, if any of the strings in the `disabled_on` list is the sole
entry in the `enabled_on` column for the test in `tests.cmake`, the test will 
end up being enabled on _all_ platforms _except_ those in `disabled_on` list. 
This is a known issue. There is no timeline for a fix for this.

#### `enabled_on` ####

The value must be a list of strings. Each string describes a platform on which
the test must be enabled. This will usually be a target triple, and may be a
regex. 

This attribute will nearly always be used to override DejaGNU annotations that
disable the test on certain platforms. In such cases, the string *must* exactly
match the string that is present in the test file. For instance, the test
`regression/chmod_1.f90` is disabled on cygwin using the following annotation:

```
! { dg-do run { target { ! { *-*-mingw* *-*-cygwin* } } } }
```
    
In order to enable this test on cygwin, the following must be added to
`regression/override.yaml`:
    
```
"chmod_1.f90":
    enabled_on: ["*-*-cygwin*"]
```

Note that the string in the value of `enabled_on` exactly matches the string 
in the `regression/chmod_1.f90`. If you are not sure which string to add to 
the `override.yaml` file, check the `disabled_on` column in the entry for the
test in the static test configuration file, `tests.cmake`, which will be 
present in the directory containing the test.

*WARNING*: If this is used on a test that is not disabled on any platform, it
will result in the test being enabled _only_ on the platforms specified in the 
`enabled_on` list.

#### `xfail` ####

The value must be a boolean, i.e. `true` or `false`. If `true`, the test will
be expected to fail, and if `false`, the test will be expected to pass. If 
the `xfail` column in the entry for the test in `tests.cmake` is the same as 
the overridden value provided here, there will be no change in the behavior 
of the test.


### TODO's ###

If some of the items listed here are implemented, even in part, it should
allows us to make better use of the test-suite.

Several DejaGNU directives from the test files are either ignored or only
partially supported - i.e. only a subset of the options specified by the
directive are handled correctly. In some
cases, those directives check that the language feature/optimization being
exercised by the tests is actually handled correctly. By ignoring them, we are
simply checking that `flang` (or the code produced by it) does not crash at
build/test time. In the case of the _compile_ tests where this is the case, we
could have situations where the test passes because the compilation succeeded,
not because the compiler actually did the right thing - for instance, the tests
in `gfortran/regression/vect` check if the code was correctly vectorized. We
could pass those tests just by failing to crash - not because `flang` actually
vectorized the code.

It is not clear how much effort would be involved in correctly handling all the
DejaGNU  directives.

#### `dg-error` directive ####

The `dg-error` directive indicates that the test should fail to compile with a
particular error. Obviously, this is a `gfortran`-specific error. `flang` may
not have a direct equivalent i.e. it may produce a more general error message
(or maybe even a more specific one if `gfortran` is the one with the more
general error message). For now, when a`dg-error` is encountered, the test is
marked as `expect-error`. At test time, we only check if "some" error (that was
not a crash) occurred. This can cause false-negatives, particularly in the
OpenMP (and perhaps even OpenACC) tests. This is where some directives/clauses
are currently not implemented which results in a parse error (as opposed to the
triggering of a "not-yet-implemented" assertion) which is also deemed an "error",
thereby causing the test to pass.

#### `dg-warning` directive ####

Currently, the `dg-warning` directive is ignored. It ought to be possible to
treat this in a manner similar to `dg-error`.

#### `scan-tree-dump` directive ####

In the _compile_ tests, the `dg-final { scan-tree-dump* ...}` directives are
ignored. The `scan-tree-dump*` checks GCC's internal tree structure to ensure
that the specific language feature/optimization the test was meant to exercise
was handled correctly (see, for example, `regression/volatile_7.f90`).

The tests instruct GCC to write out the internal representation to file and scan
the file for the presence or absence of certain text. To capture the same
behavior here, we would need to parse and translate the internal representation
of GCC to an equivalent representation in LLVM IR.

#### `target` directive ####

The `target` directive is used to restrict tests to run on certain platforms
and/or systems. The directive can be fairly complex. While in most cases the
directive simply consists of a triple specifying the platform on which the
test is enabled (or disabled), negations, logical `and` and `or` operations are
also permitted. The directives can appear in several places within
a test file. In addition to "top-level" directives which control whether or
not the entire test is enabled, a `target` directive can also be used to
conditionally emit or suppress an error or a warning on certain platforms.
Currently, there is limited support for these directives.

- Logical operators on `target` directives are not supported. Directives
containing these operators are ignored entirely.

- Only "top-level" directives are handled. `target` directives that appear
inside other directives such as `dg-error` or `dg-warning` are ignored.

#### Platform-specific disabling of tests ####

Some tests fail on certain platforms but not on others. It is possible to 
disable such tests on the failing platforms and/or enable them selectively
only on certain platforms. See the [Overriding
DejaGNU annotations](#Overriding-DejaGNU-Annotations) section for details on
how this can be done.
