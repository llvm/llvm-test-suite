LLVM "test-suite" Repository
----------------------------

Please see the LLVM testing infrastructure guide:

  https://llvm.org/docs/TestSuiteGuide.html

for more information on the contents of this repository.

To run Valida tests:

 * Clone lita-xyz:llvm-valida into the parent directory of this repo
 * Follow the Valida build instructions in its README, up to and including compiling `DelendumEntryPoint.c`
 * From the parent directory of this repo, run `./llvm-test-suite/run-valida-tests.sh`


There is also a `valida_test` script that will automatically run a single test or all the tests inside a folder.
* To run a single test, specify with `--file`:
```
./llvm-test-suite/valida_test --file ./llvm-test-suite/correctness/read.c
```
* To run all the test files in a folder, specify with `--folder`:
```
./llvm-test-suite/valida_test --folder ./llvm-test-suite/correctness
```

A test file must be:
* a `.c` file
* has a set of inputs and outputs specified with prefixes: `INPUT-` and `CHECK-`. For example, a pair of test input and expected output can be written as:
```
// INPUT-same: 1234, 1234
// CHECK-same: 2468
```

  * The above forms a single test case named `same`, with two inputs, 1234 and 1234, each is encoded as 32bit unsigned integer.
  * The expected output is a single 32bit unsigned integer, with value 2468.
  * a single file can consist of multiple test cases. 


