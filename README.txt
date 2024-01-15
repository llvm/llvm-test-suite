LLVM "test-suite" Repository
----------------------------

Please see the LLVM testing infrastructure guide:

  https://llvm.org/docs/TestSuiteGuide.html

for more information on the contents of this repository.

To run Valida tests:

 * Clone lita-xyz:llvm-valida into the parent directory of this repo
 * Follow the Valida build instructions in its README, up to and including compiling `DelendumEntryPoint.c`
 * From the parent directory of this repo, run `./llvm-test-suite/run-valida-tests.sh`
