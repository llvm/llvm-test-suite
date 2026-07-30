# Fortran Test (F2008)

## Overview
This directory contains RIKEN's Fortran conformance tests (mainly F2008
features). They are wired into the test-suite's normal CMake + lit build,
the same way as `Fortran/cray` and `Fortran/UnitTests`: each test source
file is compiled at build time with `CMAKE_Fortran_COMPILER`, run at test
time, and its combined stdout/stderr is compared against a
`.reference_output` file.

---

## Directory Structure
```
F2008-Tests/
├── CMakeLists.txt                     # add_subdirectory() for every test dir below
├── 06_maximumRank/
│   ├── CMakeLists.txt                 # llvm_singlesource() for this dir
│   ├── lit.local.cfg                  # traditional_output/single_source flags
│   ├── 06_maximumRank_001.f90         # _NNN: normal test case
│   ├── 06_maximumRank_001.reference_output
│   ├── 06_maximumRank_c001.f90        # _cNNN: negative/error test case
│   └── ...
└── ...
```

## Naming convention
- `_NNN` (e.g. `_001.f90`): a normal test that is expected to build and run
  successfully; its expected combined stdout+stderr (plus the process exit
  status, as `exit N`) is recorded in the matching `.reference_output` file.
- `_cNNN` (e.g. `_c001.f90`): a negative/error test that is expected to fail
  to compile. **These are currently excluded from the build** (filtered out
  in each directory's `CMakeLists.txt` via
  `list(FILTER _sources EXCLUDE REGEX "_c[0-9]+\\.f90$")`), because
  `llvm_singlesource()` only supports build-and-run tests. Wiring these up
  needs a "compile is expected to fail" helper, along the lines of
  `gfortran_add_compile_test()` in `Fortran/gfortran/CMakeLists.txt`.

## Status
This has now been validated end-to-end against both gfortran and a real
`flang` (Homebrew flang 22.1.8, arm64 macOS): 176 of the 194 `_NNN` sources
build, run, and produce stable output matching their `.reference_output`
with `CMAKE_Fortran_COMPILER=flang`. The remaining 18 are excluded (see the
`list(REMOVE_ITEM ...)` / `if(NOT RIKEN_HAS_REAL128)` lines with comments in
the affected `CMakeLists.txt`), for the reasons below.

### Confirmed real flang issues (worth an upstream report)
These were re-tested directly against flang, not just inferred from
gfortran, so these are real findings rather than open questions:
- `01_submodule_001.f90`: link fails with undefined symbols for the
  submodule procedures (`__QMalphaPsecond`/`__QMalphaPthird`) when the
  module, both submodules, and the main program all live in one source
  file. Looks like a flang codegen/linking bug specific to single-file
  submodules.
- `28_constants_003.f90`: link fails with an undefined symbol for
  `iso_fortran_env`'s `CHARACTER_KINDS` array
  (`__QMiso_fortran_envECcharacter_kinds`). Looks like a gap in flang's
  `iso_fortran_env` implementation.
- `28_selectedRealKind_001.f90` / `28_ieeeSelectedRealKind_001.f90`: flang
  rejects `SELECTED_REAL_KIND()` / `IEEE_SELECTED_REAL_KIND()` called with
  zero arguments ("missing mandatory 'p=' argument"); gfortran accepts it
  (returns the default real kind).
- `28_bitProcesssing_007.f90`: `MASKL(I, KIND)` with `I` greater than
  `BIT_SIZE(KIND)` is genuinely non-deterministic across repeated runs of
  the *same* flang-built binary (verified by running it several times in a
  row - the affected line prints a different garbage value each time).
  Looks like flang reads uninitialized memory for this out-of-range case.
- `35_genericResolution_005.f90`: both gfortran *and* flang reject this as
  an ambiguous generic interface (distinguishing by `ALLOCATABLE`/`POINTER`
  dummy attribute). Since both compilers agree, this looks like a shared
  conformance gap (or the test's expectation of the F2008 C1215 rule is
  wrong) rather than a flang-specific quirk - worth a closer look either way.

### Platform-specific (not expected to reproduce on Linux)
- `28_bessel_001.f90`: link fails with undefined symbols `_j0f`/`_j1f`/
  `_jnf`/`_y0f`. flang's `BESSEL_*` runtime for `REAL(4)` arguments calls the
  single-precision (`*f`-suffixed) libm entry points, which exist in glibc
  but not in macOS's libm/libSystem. Likely fine on Linux.
- `13_typeStatementForIntrinsicTypes_003.f90` / `28_constants_002.f90`: need
  `REAL(16)`/`REAL128`, which this flang build does not support on
  arm64 macOS. Gated behind the `RIKEN_HAS_REAL128` CMake cache variable
  (probed once in `Fortran/riken/CMakeLists.txt` via
  `CheckFortranSourceCompiles`), so they build automatically wherever the
  configured compiler does support it.

### Structural gaps (not compiler-specific)
- `24_recursiveInputOutput_001/002.f90`: reference a fixture file
  (`input2.dat`) that is missing from the checked-in test data.
- `24_recursiveInputOutput_003/004/005/006.f90` and
  `28_executeCommandLine_001/002.f90`: verify a side-effect file the program
  writes (or its existence), not just stdout; this needs a custom
  `llvm_test_verify()` step beyond what `llvm_singlesource()` provides.
- `28_addModProc_001.f90`: asserts the text of `COMPILER_OPTIONS()` /
  `COMPILER_VERSION()`, which is inherently tied to the exact compiler
  invocation used to build it and isn't a portable, pinnable expectation.
- `_cNNN` sources (220 files): negative/error tests expecting a compile-time
  diagnostic; `llvm_singlesource()` only supports build-and-run tests (see
  the Naming convention section above).

Separately, `27_stopExt`'s `CMakeLists.txt` conditionally adds
`-fno-backtrace` (only for `CMAKE_Fortran_COMPILER_ID STREQUAL "GNU"`)
because gfortran's runtime prints a non-deterministic address backtrace on
`ERROR STOP` unless told not to; flang has no such behavior so this does not
affect a real flang build. All 5 `27_stopExt` `_NNN` tests are confirmed
passing against real flang.

Also worth noting: `22_g0EditDescriptor_001.reference_output` was originally
hand-transcribed from the test's `! FLANG:`-prefixed `CHECK` comments (see
below), but running it against real flang turned up one place where that
transcription (i.e. the original test author's own assumption about flang's
behavior) didn't match reality - `nan(f0.0)` actually prints `NaN` on this
flang, not empty. The `.reference_output` now reflects the real, verified
flang output.

## Running the tests
Configure the test-suite with Fortran enabled and point
`CMAKE_Fortran_COMPILER` at flang, then build and run lit as usual, e.g.:

```bash
cmake -G Ninja <path-to-test-suite> \
  -DTEST_SUITE_SUBDIRS=Fortran \
  -DCMAKE_Fortran_COMPILER=flang
ninja
llvm-lit Fortran/riken
```
