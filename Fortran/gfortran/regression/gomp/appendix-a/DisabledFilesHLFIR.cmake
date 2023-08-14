#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

file(GLOB SKIPPED_FILES CONFIGURE_DEPENDS
  #
  # These tests fail when they should pass.
  #

  # (hlfir+omp): builder.create<DeclareOp>() assertion failure
  a.17.1.f90
  a.17.2.f90
  a.17.3.f90

  # (hlfir+omp): Fortran::lower::genThreadprivateOp assertion failure
  a.22.1.f90
)
