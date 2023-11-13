Finalization Unit Tests
=======================

This suite of tests was created  originally by Wileam Phan, Damian Rouson,
and Brad Richardson as part of the
[[ https://github.com/sourceryinstitute/smart-pointers | Smart-Pointers ]]
library's test suite.
All compilers, except for NAG, did not initially have a working/correct
implmentation of finalization.
An all-in-one reproducer test was created to share with compiler
teams that was easy to run (just compile a single file and run it).
This is ideal for reporting bugs to compiler teams,
but not appropriate for inclusion in a compiler test suite.

The original adaptation for inclusion in the llvm-test-suite can be found here:

* https://github.com/BerkeleyLab/llvm-test-suite/tree/damians-fortran-type-finalization
  SHA: `0268bcf0048e67cd1280f9ef65aebd2aa402130b`
* https://github.com/BerkeleyLab/llvm-test-suite/tree/berkely-lab-damian-v0.1
  SHA: `0268bcf0048e67cd1280f9ef65aebd2aa402130b`

The test suite was then adapted to be made appropriate for inclusion
in a compiler test suite by Izaak Beekman.
Broadly, this required:

- Each test should be broken into in individual file.
- Each test should have a corresponding expected output.
- Use the compilers build system rather than a custom fortran driver program
  (relying) on `execute_command_line`.
- The tests should be incorporated following the conventions adopted by the
  compiler project.
- The README/documentation should be updated and made appropriate for keeping
  in the compiler project's test suite repository.
  - e.g., Describe the tests and how to use them
  - Don't keep information about what version of which compiler works since
    it will get stale quickly and be a maintainance headache.

To run these finalization tests, and only these tests,
first you must build a recent version of llvm flang.
LLVM version d585a8afdf2f70159759dccb11d775cdf432aba4,
from Fri Apr 7 18:12:12 2023 +0000 is known to work.
Newer versions should work as well unless a regression is introduced.

You can setup your directory structure as follows:

```
llvm-project           # llvm-project/llvm source code
├── build              # Build directory for llvm-project/flang
├── test-suite         # llvm-project/llvm-test-suite source code
└── test-suite-build   # Build directory for test-suite
```

Flang is built in the `build` subdirectory.
The test-suite-build directory is created by the user
and is initially empty until running CMake for the test-suite.
To configure, build and run the tests once llvm/flang has been built,
a command similar to the following can be used from within test-suite-build:

``` shell
cmake -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_Fortran_COMPILER:FILEPATH=/home/users/<you>/llvm-project/build/bin/flang-new \
  -DTEST_SUITE_FORTRAN:BOOL=On \
  -DTEST_SUITE_SUBDIRS=Fortran/UnitTests/finalization \
  ../llvm-test-suite
make -j 4
../build/bin/llvm-lit Fortran/UnitTests/finalization
```

Summary of Tests
----------------

* [`allocatable_component.f90`]
  * Finalizes an allocatable component object on deallocation of an intent out dymmy argument
  * Test conformance with Fortran 2018 clause 7.5.6.3, para. 2 ("allocatable entity is deallocated")
    + 9.7.3.2, para. 6 ("INTENT(OUT) allocatable dummy argument is deallocated")
* [`allocated_allocatable_lhs.f90`]
  * Finalizes an allocated allocatable LHS of an intrinsic assignment
  * Test conformance with Fortran 2018 clause 7.5.6.3, paragraph 1 behavior:
    "allocated allocatable variable"
* [`block_end.f90`]
  * Finalizes a non-pointer non-allocatable object at the end of a block construct
  * Test conformance with Fortran 2018 clause  7.5.6.3, paragraph 4:
    "termination of the BLOCK construct"
* [`finalize_on_deallocate.f90`]
  * Finalizes an object upon explicit deallocation
  * Test conformance with Fortran 2018 clause 7.5.6.3, paragraph 2:
    "allocatable entity is deallocated"
* [`finalize_on_end.f90`]
  * finalizes a non-pointer non-allocatable object at the END statement
  * Test conformance with Fortran 2018 clause 7.5.6.3, paragraph 3:
    "before return or END statement"
* [`intent_out.f90`]
  * Finalizes an intent(out) derived type dummy argument
  * Test conformance with Fortran 2018 standard clause 7.5.6.3, paragraph 7:
    "nonpointer, nonallocatable, INTENT (OUT) dummy argument"
* [`lhs_object.f90`]
  * Finalizes a non-allocatable object on the LHS of an intrinsic assignment
  * Test conformance with Fortran 2018 clause 7.5.6.3, paragraph 1 behavior:
    "not an unallocated allocatable variable"
* [`rhs_function_reference.f90`]
  * Finalizes a function reference on the RHS of an intrinsic assignment
  * Test conformance with Fortran 2018 clause 7.5.6.3, paragraph 5 behavior:
    "nonpointer function result"
* [`specification_expression_finalization.f90`]
  * Finalizes a function result in a specification expression
  * Test compiler conformance with clause 7.5.6.3, paragraph 6 in the Fortran
    Interpretation Document (https://j3-fortran.org/doc/year/18/18-007r1.pdf):
    "If a specification expression in a scoping unit references
    a function, the result is finalized before execution of the executable
    constructs in the scoping unit."  (The same statement appears in clause
    4.5.5.2, paragraph 5 of the Fortran 2003 standard.) In such a scenario,
    the final subroutine must be pure.  The only way to observe output from
    a pure final subroutine is for the subroutine to execute an error stop
    statement.  A correct execution of this test will error-terminate and ouput
    the text "finalize: intentional error termination to verify finalization".
* [`target_deallocation.f90`]
  * Finalizes a target when the associated pointer is deallocated
  * Test conformance with Fortran 2018 clause 7.5.6.3, paragraph 2 behavior:
    "pointer is deallocated"


Common Code
-----------

* [`object_type_m.f90`]
  * To reduce code duplication, yet allow each test to be treated by
    CMake as a single source file, a small amount of common code is
    `include`d from this file by each test file.
  * Due to the way CMake handles `.mod` module files, it is important
    that each of the test files uses unique module names, otherwise
    CMake will encounter a race condition when building in parallel
    wherein it might clobber a `.mod` module file or corresponding
    timestamp when multiple `.mod` files are being created with the
    same name.
  * This file contains the main derived type object for testing and the
    corresponding final subroutine, `count_finalizations` to verify that
    finalization took pace (by counting finalizations in a public module
    variable)

[`allocatable_component.f90`]: ./allocatable_component.f90
[`allocated_allocatable_lhs.f90`]: ./allocated_allocatable_lhs.f90
[`block_end.f90`]: ./block_end.f90
[`finalize_on_deallocate.f90`]: ./finalize_on_deallocate.f90
[`finalize_on_end.f90`]: ./finalize_on_end.f90
[`intent_out.f90`]: ./intent_out.f90
[`lhs_object.f90`]: ./lhs_object.f90
[`rhs_function_reference.f90`]: ./rhs_function_reference.f90
[`specification_expression_finalization.f90`]: ./specification_expression_finalization.f90
[`target_deallocation.f90`]: ./target_deallocation.f90
[`object_type_m.f90`]: ./object_type_m.f90
