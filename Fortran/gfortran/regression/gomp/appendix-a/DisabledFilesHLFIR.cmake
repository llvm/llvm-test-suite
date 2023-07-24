#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

file(GLOB UNIMPLEMENTED_FILES CONFIGURE_DEPENDS
  # (hlfir+omp): unimplemented: Common block in privatization clause
  a.23.4.f90
)

file(GLOB SKIPPED_FILES CONFIGURE_DEPENDS
  #
  # These tests fail when they should pass.
  #

  # (hlfir+omp): operand#0 does not dominate this use
  a.1.1.f90
  a.6.1.f90
  a.8.1.f90
  a.12.1.f90
  a.21.2.f90
  a.21.3.f90
  a.26.2.f90
  a.30.1.f90
  a.31.1.f90
  a.31.2.f90
  a.34.1.f90
  a.34.2.f90
  a.35.2.f90
  a.37.1.f90

  # (hlfir+omp): builder.create<DeclareOp>() assertion failure
  a.17.1.f90
  a.17.2.f90
  a.17.3.f90

  # (hlfir+omp): Fortran::lower::genThreadprivateOp assertion failure
  a.22.1.f90

  # (hlfir+omp): "the thread private operation not created" assertion failure
  a.32.1.f90
)
