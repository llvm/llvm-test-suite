#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# These tests use (currently) unsupported GNU extensions.
file(GLOB UNSUPPORTED_FILES CONFIGURE_DEPENDS
  intrinsic-unix-bessel.f  # bes(j|y)(0|1|n),
  intrinsic-unix-erf.f     # derf
)

# There are currently no unimplemented files.
set(UNIMPLEMENTED_FILES "")

# These tests are skipped because they cause flang to crash
file(GLOB SKIPPED_FILES CONFIGURE_DEPENDS
  # error: 64-bit code requested on a subtarget that doesn't support it!
  20010216-1.f

  # These tests fail because gfortran expects the compilation to succeed but
  # with a warning being issued. flang, however, fails to compile and issues an
  # error instead.
  12632.f
)

# These tests fail when they are expected to pass.
file(GLOB FAILING_FILES CONFIGURE_DEPENDS
  # These tests fail at runtime.
  complex_1.f

  # These tests are expected to fail to compile, but compilation succeeds.
  19990218-0.f
  970625-2.f
  980615-0.f

  # These tests are expected to compile, but compilation fails instead.
  20010519-1.f

  # This seems to be compiled in fixed-form even though -ffree-form is specified
  # as a DejaGNU directive. This indicates a bug in the processing of the
  # directives by the build system in llvm-test-suite, or a problem with flang
  # where it does not respect the -ffree-form directive.
  ffree-form-3.f

  # This has something to do with the -ffixed-line-length-none option. Once
  # again, it is possible that is just not being parsed correctly from the file.
  ffixed-line-length-none.f

  # This has something to do with the -ffixed-line-length-0 option. Once
  # again, it is possible that the directive is not being passed to flang
  # because of a bug in the directive parsing, or that flang does not respect
  # the flag.
  ffixed-line-length-0.f

  # This has something to do with the -ffixed-line-length-0 option. Once
  # again, it is possible that the directive is not being passed to flang
  # because of a bug in the directive parsing, or that flang does not respect
  # the flag.
  ffixed-line-length-132.f
)
