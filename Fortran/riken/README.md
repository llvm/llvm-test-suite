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
  `llvm_singlesource()` only supports build-and-run tests. See
  "Error-case (`_cNNN`) tests: prior art and future plan" below for how this
  should be wired up when someone picks it up.

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
  the Naming convention section above, and the dedicated section below).

Separately, `27_stopExt`'s `CMakeLists.txt` conditionally adds
`-fno-backtrace` (only for `CMAKE_Fortran_COMPILER_ID STREQUAL "GNU"`)
because gfortran's runtime prints a non-deterministic address backtrace on
`ERROR STOP` unless told not to; flang has no such behavior so this does not
affect a real flang build. All 5 `27_stopExt` `_NNN` tests are confirmed
passing against real flang under `llvm-lit` (see the `NO_STOP_MESSAGE` note
below - that's the environment they need to pass in).

`27_stopExt_004.reference_output` needed a fix after it was independently
verified end-to-end via `llvm-lit`: `Fortran/lit.local.cfg` sets
`config.environment["NO_STOP_MESSAGE"] = "1"` for everything under
`Fortran/` (see `Fortran/Readme.txt` for the rationale), and flang's runtime
only honors that variable for a plain `STOP '<character message>'` - it
drops the `Fortran STOP: ` prefix in that one case, but still prints it for
`STOP <integer code>` and for `ERROR STOP` (character or integer). The
original reference_output for `27_stopExt_004.f90` (`stop msg` with a
character stop-code) was captured by running the built binary directly,
bypassing lit's environment, so it recorded `Fortran STOP: Err999` instead
of the `Err999` that actually appears once `NO_STOP_MESSAGE=1` is in effect.
The other four `27_stopExt` tests (`_001`/`_002`: integer `STOP`; `_003`:
integer `ERROR STOP`; `_005`: character `ERROR STOP`) are unaffected, since
`NO_STOP_MESSAGE` doesn't change their output. Lesson: for anything that
touches `STOP`/`ERROR STOP` message text, generate and verify
`.reference_output` by actually running the test through `llvm-lit`, not by
executing the built binary standalone - the lit environment (here,
`NO_STOP_MESSAGE`) can change the output.

Also worth noting: `22_g0EditDescriptor_001.reference_output` was originally
hand-transcribed from the test's `! FLANG:`-prefixed `CHECK` comments (see
below), but running it against real flang turned up one place where that
transcription (i.e. the original test author's own assumption about flang's
behavior) didn't match reality - `nan(f0.0)` actually prints `NaN` on this
flang, not empty. The `.reference_output` now reflects the real, verified
flang output.

### Error-case (`_cNNN`) tests: prior art and future plan
Before designing a "compile is expected to fail" helper for the 220 `_cNNN`
sources, it's worth looking at how `Fortran/gfortran` itself resolved the
exact same question when it was first integrated -
[discourse.llvm.org/t/add-gfortran-tests-to-llvm-test-suite/69408](https://discourse.llvm.org/t/add-gfortran-tests-to-llvm-test-suite/69408).
That thread is directly relevant, not just a loose analogy: it's the design
discussion for the very `gfortran_add_compile_test()` helper this README
already points to.

Key takeaways from that thread:
- gfortran's own "compile" tests (i.e. tests that check the compiler's
  diagnostic output, as opposed to "execute" tests that check runtime
  behavior) were **deliberately left out** of the initial integration, and
  as of this writing (the thread is from 2023) still are - only "execute"
  tests were ever wired up. lenary (who did the equivalent GCC C torture
  suite integration): *"For C, we did not, because the test suite is really
  about compilation+execution. We did say we'd revisit this and never got
  around to it."*
- Precise diagnostic-message checking was considered and consciously
  deferred, not because it's impossible, but because it wasn't judged worth
  the effort relative to execute tests: *"I think it's fine we don't check
  error messages, to be honest ... Maybe this is something for later, and
  it's best to start with just the execution tests which have a clearer
  path to pass/fail."*
- The actual `gfortran_add_compile_test()` that got merged reflects this: it
  does **not** use `FileCheck` or match diagnostic text at all. It only
  checks whether the compiler's diagnostic output is empty or non-empty
  (`llvm_test_verify(%b/not ${DIFFPROG} <empty-file> <captured-diagnostics>)`
  for the `expect_error` case) - i.e. "did *some* error get reported", not
  "did the *right* error get reported".
- lenary also noted a structural limitation of this test-suite: *"LLVM test
  suite isn't set up to differentiate between 'compile failure' and
  'execute failure'"* - both just show up as a failed lit test either way.

**Implication for `_cNNN`**: the current "skip these for now" stance in this
integration isn't an ad hoc shortcut - it reproduces the same conclusion the
authors of `Fortran/gfortran` itself reached when they hit the identical
question. When this is picked up, the recommended approach is:
1. Reuse the `gfortran_add_compile_test()` pattern as-is (build-time
   compile via `add_custom_command`, a shared dummy executable as the "thing
   lit runs", `llvm_test_verify()` diffing the captured diagnostics against
   an empty reference). Don't build a new FileCheck-based, exact-message
   verifier - that was explicitly weighed and passed over upstream, and it
   also matches this integration's own earlier decision not to do dual
   `%flang`/`%gfortran` checking.
2. The original `! RUN:`/`! CHECK-FLANG:`/`! CHECK-GFORT:` lines in `_cNNN`
   sources can be stripped the same way they already were for `_NNN`
   sources when wiring them into CMake - they're lit/FileCheck-era
   directives that a `gfortran_add_compile_test()`-style helper doesn't
   consume, and (unlike the GCC/gfortran torture suites, which are
   GPL-licensed upstream sources lenary was careful not to modify) these are
   RIKEN's own test sources, so there's no license reason to keep them
   byte-for-byte identical to the original.
3. When actually building each `_cNNN` file against real flang, sort the
   result into the same two buckets this README already uses for `_NNN`:
   flang produces *some* diagnostic (wire it up as a normal expect-error
   pass), or flang unexpectedly *accepts* the code (a real conformance gap -
   file it alongside the "Confirmed real flang issues" entries above rather
   than silently treating it as a pass).

This is not urgent: the upstream `Fortran/gfortran` "compile tests" work has
sat untouched for the ~2+ years since that thread, suggesting execute-only
coverage is considered acceptable in practice. Revisit `_cNNN` opportunistically,
not as a blocker for the rest of this integration.

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
